import math
import random
import threading
import time

from sensor import UWB

SECONDS_BETWEEN_STEPS=0.01
NUM_STEPS_BEFORE_ROTATE_ALLOWED=20

DIR_ORIG=0
DIR_RIGHT_ONCE=1
DIR_RIGHT_TWICE=2
DIR_RIGHT_THRICE=3

NUM_DIRS=4

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
    
    # for step alg
    self._last_distance = 0
    self._curr_dir = DIR_ORIG
    self._dir_to_dists = { 
      key: [] 
      for key in [DIR_ORIG, DIR_RIGHT_ONCE, DIR_RIGHT_TWICE, DIR_RIGHT_THRICE] 
    }


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
      self._curr_dir = (self._curr_dir - 1) % NUM_DIRS
      self._dir_to_dists[self._curr_dir] = []

  def _rotate_right(self):
    with self._lock:
      self._theta = (self._theta + (math.pi / 2)) % (2 * math.pi)
      self._curr_dir = (self._curr_dir + 1) % NUM_DIRS
      self._dir_to_dists[self._curr_dir] = []

  def _forward(self, d):
    with self._lock:
      self._x += d * math.cos(self._theta)
      self._y += d * math.sin(self._theta)

  def __reset_all_dists(self):
    for key in [DIR_ORIG, DIR_RIGHT_ONCE, DIR_RIGHT_TWICE, DIR_RIGHT_THRICE]:
      self._dir_to_dists[key] = []

  def __get_dist_roc(self, dir):
    assert dir >= 0 and dir < NUM_DIRS
    distances = self._dir_to_dists[dir]
    return sum(distances) / len(distances) if len(distances) > 0 else 0

  def _step(self):
    distance = self._uwb.sense().get(self.target_id)
    self._dir_to_dists[self._curr_dir].append(distance - self._last_distance)

    if (distance > self._last_distance 
        and len(self._dir_to_dists[self._curr_dir]) >= NUM_STEPS_BEFORE_ROTATE_ALLOWED):

      roc_curr_dir  = self.__get_dist_roc(self._curr_dir)
      roc_left_dir  = self.__get_dist_roc((self._curr_dir - 1) % NUM_DIRS)
      roc_right_dir = self.__get_dist_roc((self._curr_dir + 1) % NUM_DIRS)
      roc_right_twice_dir = self.__get_dist_roc((self._curr_dir + 2) % NUM_DIRS)

      # move in a new direction with a better average rate of change in distance
      if roc_left_dir < roc_curr_dir and roc_right_dir < roc_curr_dir:
        if roc_left_dir < roc_right_dir: self._rotate_left()
        else: self._rotate_right()
      elif roc_left_dir < roc_curr_dir:
        self._rotate_left()
      elif roc_right_dir < roc_curr_dir:
        self._rotate_right()
      elif roc_right_twice_dir < roc_curr_dir:
        self._rotate_right() # either rotation is fine (cannot 180 in one step)

      # every once in a while try a new path if dist increases for too long
      if len(self._dir_to_dists[self._curr_dir]) >= NUM_STEPS_BEFORE_ROTATE_ALLOWED * 10:
        self.__reset_all_dists()
        
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
