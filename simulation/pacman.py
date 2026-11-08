import math
import queue
import threading
import time

from maze import heading_of

SECONDS_BETWEEN_ACTIONS=0.01

class Pacman:
  """
  Player-controlled robot that drives along the maze tape.

  W = start moving, S = turn around on the spot (works anywhere on the tape),
  A/D = turn 90 deg left/right at the next intersection. A turn pressed
  between intersections is remembered and done at the next one; if there is
  no tape that way it is dropped. Once moving, Pac-Man keeps going and waits
  at an intersection with no tape ahead until the player turns.
  The GUI sends keyboard press commands to Pacman (self.commands)
  """

  def __init__(self, x, y, theta, maze, speed=100.0, id="pacman"):
    self.id = id
    self.color = "dark red"
    self.speed = speed
    self.commands = queue.Queue()

    self._x, self._y, self._theta = x, y, theta
    self._start_pose = (x, y, theta)
    self._moving = False
    self._halted = False
    self._pending_turn = None   # "left" / "right" waiting for an intersection
    self.maze = maze
    self._lock = threading.Lock()
    self._thread = None
    self.lastCommand = None
    self.validCommands = ["up", "down", "left", "right"]

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

  def _rotate_back(self):
    with self._lock:
      self._theta = (self._theta + (math.pi)) % (2 * math.pi)

  def _forward(self, d):
    """Drive along the tape; stops on the next intersection if reached."""
    with self._lock:
      self._x, self._y, _ = self.maze.advance(self._x, self._y,
                                              heading_of(self._theta), d)

  def halt(self):
    """Stop for good (game over)."""
    self._halted = True

  def reset(self):
    """Back to the start, stopped, with no queued keys (R in the GUI)."""
    while True:
      try:
        self.commands.get_nowait()
      except queue.Empty:
        break
    with self._lock:
      self._x, self._y, self._theta = self._start_pose
      self._moving = False
      self._pending_turn = None
      self.lastCommand = None
      self._halted = False

  def _step(self):
    if self._halted:
      return
    # apply every command received since the last step
    while True:
      try:
        cmd = self.commands.get_nowait()
      except queue.Empty:
        break
      if cmd not in self.validCommands:
        continue
      self.lastCommand = cmd
      self._moving = True
      match cmd:
        case "up":    pass
        case "down":  self._rotate_back()          # U-turn: always possible
        case "left" | "right": self._pending_turn = cmd

    x, y, theta = self.pose()
    node = self.maze.node_at(x, y)
    if node is not None and self._pending_turn is not None:
      turn = -90 if self._pending_turn == "left" else 90
      if self.maze.has_tape(node, heading_of(theta) + turn):
        (self._rotate_left if turn < 0 else self._rotate_right)()
      self._pending_turn = None                    # done, or no tape: drop it

    if self._moving:
      x, y, theta = self.pose()
      if node is not None and not self.maze.has_tape(node, heading_of(theta)):
        return                                     # end of tape: wait here
      self._forward(self.speed * SECONDS_BETWEEN_ACTIONS)

  # --- thread -----------------------------------------------------------

  def start(self):
    self._thread = threading.Thread(target=self._run, daemon=True)
    self._thread.start()

  def _run(self):
    while True:
      self._step()
      time.sleep(SECONDS_BETWEEN_ACTIONS)


def make_pacman(maze):
  x, y = maze.node_pos(maze.pacman_start)
  return Pacman(x, y, 0.0, maze, speed=100)
