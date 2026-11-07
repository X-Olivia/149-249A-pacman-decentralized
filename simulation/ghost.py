import math
import random
import threading
import time

from sensor import UWB

SECONDS_BETWEEN_STEPS=0.01

class Ghost:
  """
  A ghost that only rotates in place or drives forward.
  """

  def __init__(self, id, x, y, theta, color, speed=60.0, target_id="pacman"):
    self.id = id
    self.color = color
    self.speed = speed
    self.target_id = target_id

    self._x, self._y, self._theta = x, y, theta
    self._lock = threading.Lock()
    self._thread = None

    self._uwb = None  # attached with register_uwb()
    self._last_distance = None

  # --- sensors ----------------------------------------------------------

  def register_uwb(self, others):
    assert self not in others
    self._uwb = UWB(self, others)

  # --- pose -------------------------------------------------------------

  def pose(self):
    with self._lock:
      return self._x, self._y, self._theta

  # --- behavior ---------------------------------------------------------

  def _rotate_left(self):
    with self._lock:
      self._theta = (self._theta - (math.pi / 2)) % (2 * math.pi)

  def _rotate_right(self):
    with self._lock:
      self._theta = (self._theta + (math.pi / 2)) % (2 * math.pi)

  def _forward(self, d):
    with self._lock:
      self._x += d * math.cos(self._theta)
      self._y += d * math.sin(self._theta)

  def _step(self):
    distance = self._uwb.sense().get(self.target_id)
    if (self._last_distance is not None and distance > self._last_distance):
      random.choice([self._rotate_left, self._rotate_right])()
    self._last_distance = distance

    self._forward(self.speed * SECONDS_BETWEEN_STEPS)

  # --- thread -----------------------------------------------------------

  def start(self):
    self._thread = threading.Thread(target=self._run, daemon=True)
    self._thread.start()

  def _run(self):
    while True:
      self._step()
      time.sleep(SECONDS_BETWEEN_STEPS)


def make_ghosts(pacman):
  ghost = Ghost("ghost1", 250, 300, 0.0, "orange", speed=60)
  ghost.register_uwb([pacman])
  return [ghost]
