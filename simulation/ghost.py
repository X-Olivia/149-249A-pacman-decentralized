import math
import random
import threading
import time

from maze import heading_of
from sensor import BACK, FRONT, IR, LEFT, RIGHT, UWB

SECONDS_BETWEEN_STEPS=0.01
SECONDS_BETWEEN_TURN=1
MAX_ENTRIES=5

# Default UWB model (pixels / degrees).
UWB_NOISE_DIST=5.0
UWB_NOISE_ANGLE_DEG=5.0
UWB_MAX_RANGE=3000.0

# "range" mode (distance only): Yacqub's rate-of-change algorithm.
NUM_DIRS=4
NUM_STEPS_BEFORE_RESET=200  # was NUM_STEPS_BEFORE_ROTATE_ALLOWED * 10

# Order used to break ties between equally good exits.
TIE_ORDER = (FRONT, LEFT, RIGHT, BACK)


class Ghost:
  """
  A ghost that follows the maze tape and only decides at intersections.

  It does not know where it is in the maze. At an intersection it senses:
    - which ways have tape (IR line sensors), relative to its heading, and
    - Pac-Man via UWB: distance + angle ("angle" mode) or distance only
      ("range" mode).
  It never turns around, except at a dead end.

  "range" mode is Yacqub's open-space algorithm moved onto the tape: every
  step it records how the distance changed in the direction it is driving
  (directions counted from its start heading by its own turns). At an
  intersection it keeps going if the distance is shrinking, otherwise it
  takes the exit whose direction has the lowest average change.
  """

  class Dist_arr:
    def __init__(self):
      self.dist = [0]*MAX_ENTRIES
      self.tail = 0
      self.size = 0
    def add_dist(self, dist):
      self.dist[self.tail] = dist
      self.tail = (self.tail + 1) % MAX_ENTRIES
      self.size = min(self.size + 1, MAX_ENTRIES)
    def reset_dist(self):
      for i in range(len(self.dist)):
        self.dist[i] = 0
      self.tail = 0
      self.size = 0
    def get_last(self):
      return self.dist[self.tail - 1]
    def get_average(self):
      return sum(self.dist) / self.size if self.size > 0 else 0

  def __init__(self, id, x, y, theta, color, maze, speed=60.0,
               target_id="pacman", uwb_mode="angle", rng=None):
    self.id = id
    self.color = color
    self.speed = speed
    self.target_id = target_id
    self.maze = maze
    self.uwb_mode = uwb_mode
    self.rng = rng or random.Random()
    self.time = 0 # might wrap around.....

    self._x, self._y, self._theta = x, y, theta
    self._start_pose = (x, y, theta)
    self._lock = threading.Lock()
    self._thread = None
    self._halted = False

    self._uwb = None  # attached with register_uwb()
    self._ir = IR(self, maze)
    self._decided_at = 0  # timestep last decided at
    self._random_at = 0

    # for "range" mode (as in the original step alg)
    self._last_distance = None
    self._curr_dir = 0  # 0..3: turns of 90 deg right since the start

    self._dir_to_dists = {key: self.Dist_arr() for key in range(NUM_DIRS)}

  # --- sensors ----------------------------------------------------------

  def register_uwb(self, others, noise_dist=UWB_NOISE_DIST,
                   noise_angle_deg=UWB_NOISE_ANGLE_DEG,
                   max_range=UWB_MAX_RANGE):
    assert self not in others
    self._uwb = UWB(self, others, return_angle=(self.uwb_mode == "angle"),
                    noise_dist=noise_dist, noise_angle_deg=noise_angle_deg,
                    max_range=max_range, rng=self.rng)

  # --- pose -------------------------------------------------------------

  def pose(self):
    with self._lock:
      return self._x, self._y, self._theta

  # --- behavior ---------------------------------------------------------

  def _turn(self, rel_deg):
    """Turn on the spot by a relative direction (FRONT/RIGHT/BACK/LEFT)."""
    with self._lock:
      # print("ROC:")
      # dists = ["RIGHT", "DOWN", "LEFT", "UP"]
      # print("Curr dir: ", self._curr_dir)
      # for i in range(4):
      #   print(dists[i], ": ", self.__get_dist_roc(i))
      self._theta = (self._theta + math.radians(rel_deg)) % (2 * math.pi)
      if rel_deg % 360 != FRONT:
        self._curr_dir = (self._curr_dir + rel_deg // 90) % NUM_DIRS
        self._dir_to_dists[self._curr_dir].reset_dist()

  def __reset_all_dists(self):
    for key in range(NUM_DIRS):
      self._dir_to_dists[key].reset_dist()

  def __get_dist_roc(self, dir):
    assert dir >= 0 and dir < NUM_DIRS
    # return self._dir_to_dists[dir].get_average()
    return self._dir_to_dists[dir].dist[-1] if self._dir_to_dists[dir].size > 0 else 0

  def _record_distance(self):
    """range mode, every step: log the distance change for the current dir."""
    distance = self._uwb.sense().get(self.target_id)
    if distance is None:  # out of range
      self._last_distance = None
      return
    if self._last_distance is not None:
      self._dir_to_dists[self._curr_dir].add_dist(self._last_distance - distance)
    self._last_distance = distance

  def _forward(self, d):
    """Drive along the tape; stops on the next intersection if reached."""
    with self._lock:
      self._x, self._y, _ = self.maze.advance(self._x, self._y,
                                              heading_of(self._theta), d)

  def halt(self):
    """Stop for good (game over)."""
    self._halted = True

  def unhalt(self):
    """Stop for good (game over)."""
    self._halted = False

  def reset(self):
    """Back to the start with all memory cleared (R in the GUI)."""
    with self._lock:
      self._x, self._y, self._theta = self._start_pose
      self._decided_at = 0
      self._last_distance = None
      self._curr_dir = 0
      self.__reset_all_dists()
      self._halted = False
      self.time = 0
      self._random_at = 0

  def _choose_exit(self, exits):
    """Pick one relative direction out of `exits` (BACK already removed
    unless this is a dead end)."""
    if self.uwb_mode == "range":
      reading = self._last_distance
    else:
      reading = self._uwb.sense().get(self.target_id)
    if reading is None:  # Pac-Man out of UWB range: keep going / wander
      return FRONT if FRONT in exits else self.rng.choice(sorted(exits))

    if self.uwb_mode == "angle":
      # Pac-Man's position in the ghost's own frame (x ahead, y to the right)
      distance, bearing = reading
      tx, ty = distance * math.cos(bearing), distance * math.sin(bearing)

      def cost(e):  # how far from Pac-Man one tape segment that way ends up
        a = math.radians(e)
        nx, ny = self.maze.spacing * math.cos(a), self.maze.spacing * math.sin(a)
        return math.hypot(tx - nx, ty - ny)

      return min((e for e in TIE_ORDER if e in exits), key=cost)

    # "range" mode
    roc = {e: self.__get_dist_roc((self._curr_dir + e // 90) % NUM_DIRS)
           for e in exits}
    last = self._dir_to_dists[self._curr_dir].get_last()
    if FRONT in exits and last < 0:
      choice = FRONT  # getting closer: keep going
    else:
      # move in the direction with the best average rate of change
      best = min(roc.values())
      choice = next(e for e in TIE_ORDER if e in exits and roc[e] == best)
    # every once in a while try a new path if dist increases for too long
    if (self.time - self._random_at) / SECONDS_BETWEEN_STEPS >= NUM_STEPS_BEFORE_RESET:
      self.__reset_all_dists()
      self._random_at = self.time
    return choice

  def _step(self):
    if self._halted:
      return
    if self.uwb_mode == "range":
      self._record_distance()
    if self._ir.at_intersection() and self.time >= self._decided_at + SECONDS_BETWEEN_TURN:
      exits = self._ir.exits()
      forward_exits = exits - {BACK}
      choice = self._choose_exit(forward_exits or exits)  # dead end: go back
      self._turn(choice)
      self._decided_at = self.time
    self._forward(self.speed * SECONDS_BETWEEN_STEPS)
    self.time += SECONDS_BETWEEN_STEPS

  # --- thread -----------------------------------------------------------

  def start(self):
    self._thread = threading.Thread(target=self._run, daemon=True)
    self._thread.start()

  def _run(self):
    while True:
      self._step()
      time.sleep(SECONDS_BETWEEN_STEPS)


def make_ghosts(pacman, maze, uwb_mode="angle", max_range=UWB_MAX_RANGE):
  x, y = maze.node_pos(maze.ghost_starts[0])
  ghost = Ghost("ghost1", x, y, 0.0, "orange", maze, speed=60,
                uwb_mode=uwb_mode)
  ghost.register_uwb([pacman], max_range=max_range)
  return [ghost]
