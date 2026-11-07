import math
import random
import threading
import time

SECONDS_BETWEEN_ACTIONS=0.01

class Ghost:
  """
  A ghost that only rotates in place or drives forward.
  """

  def __init__(self, x, y, theta, color, speed=60.0, turn_prob=0.01):
    self.color = color
    self.speed = speed
    self.turn_prob = turn_prob  # chance of a 90° turn on each step

    self._x, self._y, self._theta = x, y, theta
    self._lock = threading.Lock()
    self._thread = None

  # --- pose -------------------------------------------------------------

  def pose(self):
    with self._lock:
      return self._x, self._y, self._theta

  # --- behavior ---------------------------------------------------------

  def rotate_left(self):
    with self._lock:
      self._theta = (self._theta - (math.pi / 2)) % (2 * math.pi)

  def rotate_right(self):
    with self._lock:
      self._theta = (self._theta + (math.pi / 2)) % (2 * math.pi)
  
  def forward(self, d):
    with self._lock:
      self._x += d * math.cos(self._theta)
      self._y += d * math.sin(self._theta)

  def step(self):
    # every once in a while turn 90 degrees, otherwise move forward
    if random.random() < self.turn_prob:
      if random.random() < 0.5:
        self.rotate_left()
      else:
        self.rotate_right()
    else:
      self.forward(self.speed * SECONDS_BETWEEN_ACTIONS)

  # --- thread -----------------------------------------------------------

  def start(self):
    self._thread = threading.Thread(target=self._run, daemon=True)
    self._thread.start()

  def _run(self):
    while True:
      self.step()
      time.sleep(SECONDS_BETWEEN_ACTIONS)


def make_ghosts():
  return [
    Ghost(250, 300, 0.0, "orange", speed=60),
    Ghost(550, 300, math.pi, "red", speed=80),
  ]
