import math
import threading
import time

SECONDS_BETWEEN_ACTIONS=0.01

class Robot:
  """
  A robot that only rotates in place or drives forward.
  """

  def __init__(self, x, y, theta, color, speed=60.0, turn_rate=0.5):
    self.color = color
    self.speed = speed
    self.turn_rate = turn_rate

    self._x, self._y, self._theta = x, y, theta
    self._lock = threading.Lock()
    self._thread = None

  # --- pose -------------------------------------------------------------

  def pose(self):
    with self._lock:
      return self._x, self._y, self._theta

  # --- behavior ---------------------------------------------------------

  def rotate(self, dtheta):
    with self._lock:
      self._theta = (self._theta + dtheta) % (2 * math.pi)
  
  def forward(self, d):
    with self._lock:
      self._x += d * math.cos(self._theta)
      self._y += d * math.sin(self._theta)

  def step(self, dt):
    self.rotate(self.turn_rate * dt)
    self.forward(self.speed * dt)

  # --- thread -----------------------------------------------------------

  def start(self):
    self._thread = threading.Thread(target=self._run, daemon=True)
    self._thread.start()

  def _run(self):
    while True:
      self.step(SECONDS_BETWEEN_ACTIONS)
      time.sleep(SECONDS_BETWEEN_ACTIONS)


def make_robots():
  return [
    Robot(250, 300, 0.0, "orange", speed=60, turn_rate=0.6),
    Robot(550, 300, math.pi, "red", speed=80, turn_rate=-0.8),
  ]
