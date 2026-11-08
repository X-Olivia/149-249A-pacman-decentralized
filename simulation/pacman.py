import math
import queue
import threading
import time

SECONDS_BETWEEN_ACTIONS=0.01

class Pacman:
  """
  Player-controlled robot. W = drive forward (while held), A/D = turn 90 deg.
  The GUI sends keyboard press commands to Pacman (self.commands)
  """

  def __init__(self, x, y, theta, speed=100.0, id="pacman"):
    self.id = id
    self.color = "dark red"
    self.speed = speed
    self.commands = queue.Queue()

    self._x, self._y, self._theta = x, y, theta
    self._moving = False
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
    with self._lock:
      self._x += d * math.cos(self._theta)
      self._y += d * math.sin(self._theta)

  def _step(self):
    # apply every command received since the last step
    while True:
      try:
        cmd = self.commands.get_nowait()
        self.lastCommand = cmd
      except queue.Empty:
        break

      if self.lastCommand in self.validCommands:  
        self._moving = True
        match self.lastCommand:
          case "up":    break
          case "down":  self._rotate_back()
          case "left":  self._rotate_left()
          case "right": self._rotate_right()
      else:
        self._moving = False

    if self._moving:
      self._forward(self.speed * SECONDS_BETWEEN_ACTIONS)

  # --- thread -----------------------------------------------------------

  def start(self):
    self._thread = threading.Thread(target=self._run, daemon=True)
    self._thread.start()

  def _run(self):
    while True:
      self._step()
      time.sleep(SECONDS_BETWEEN_ACTIONS)


def make_pacman():
  return Pacman(400, 450, 0.0, speed=100)
