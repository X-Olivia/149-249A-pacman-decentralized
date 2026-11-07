import math
import queue
import threading
import time

SECONDS_BETWEEN_ACTIONS=0.01

class Pacman:
  """
  Player-controlled robot. W = drive forward (while held), A/D = turn 90°.
  Commands arrive on `self.commands` (filled by the GUI thread) and are
  applied by Pacman's own thread.
  """

  def __init__(self, x, y, theta, color="yellow", speed=100.0):
    self.color = color
    self.speed = speed
    self.commands = queue.Queue()

    self._x, self._y, self._theta = x, y, theta
    self._moving = False
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
    # apply every command received since the last step
    while True:
      try:
        cmd = self.commands.get_nowait()
      except queue.Empty:
        break
      if cmd == "go":
        self._moving = True
      elif cmd == "stop":
        self._moving = False
      elif cmd == "left":
        self.rotate_left()
      elif cmd == "right":
        self.rotate_right()

    if self._moving:
      self.forward(self.speed * SECONDS_BETWEEN_ACTIONS)

  # --- thread -----------------------------------------------------------

  def start(self):
    self._thread = threading.Thread(target=self._run, daemon=True)
    self._thread.start()

  def _run(self):
    while True:
      self.step()
      time.sleep(SECONDS_BETWEEN_ACTIONS)


def make_pacman():
  return Pacman(400, 450, 0.0, "black", speed=100)
