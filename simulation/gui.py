import math
import time
import tkinter as tk

ONE_SECOND_IN_MS=1000
CATCH_RADIUS=20  # px: a ghost this close to Pac-Man catches it
STATUS_HEIGHT=30

class GUI:
  def __init__(self, robots, maze, hz=60, radius=15, catch_radius=CATCH_RADIUS):
    self.robots = robots
    self.maze = maze
    self.radius = radius
    self.catch_radius = catch_radius
    self.interval_ms = round(ONE_SECOND_IN_MS / hz)
    self.pacman = next(r for r in robots if r.id == "pacman")
    self.ghosts = [r for r in robots if r is not self.pacman]
    self._start = time.monotonic()
    self._caught = None  # (ghost, seconds) once Pac-Man is caught

    self.root = tk.Tk()
    self.root.title("Simulation")
    self.canvas = tk.Canvas(self.root, width=maze.width,
                            height=maze.height + STATUS_HEIGHT, bg="gray",
                            highlightthickness=0)
    self.canvas.pack()

    # the black tape of the maze
    for edge in maze.edges:
      (x1, y1), (x2, y2) = (maze.node_pos(n) for n in edge)
      self.canvas.create_line(x1, y1, x2, y2, width=6, fill="black")
    self._status = self.canvas.create_text(8, maze.height + STATUS_HEIGHT / 2,
                                           anchor="w", fill="white")

    # creates the robot body, and the white line that shows its orientation
    self._items = {}
    for robot in robots:
      body = self.canvas.create_oval(0, 0, 0, 0, fill=robot.color)
      line_orientation = self.canvas.create_line(0, 0, 0, 0, width=3)
      self._items[robot] = (body, line_orientation)

  def register_pacman_controls(self, pacman):
    """W = go, S = turn around, A/D = turn 90° left/right at the next intersection."""
    bindings = {
      "<KeyPress-w>":   "up",
      "<KeyPress-s>": "down",
      "<KeyPress-a>":   "left",
      "<KeyPress-d>":   "right",
    }
    for event, cmd in bindings.items():
      self.root.bind(event, lambda e, cmd=cmd: pacman.commands.put(cmd))
    self.root.bind("<KeyPress-r>", lambda e: self.reset())

  def reset(self):
    """R: put every robot back at its start and restart the clock."""
    for robot in self.robots:
      robot.reset()
    self._start = time.monotonic()
    self._caught = None

  def _draw(self):
    r = self.radius
    for robot, (body, line_orientation) in self._items.items():
      x, y, theta = robot.pose()
      self.canvas.coords(body, x - r, y - r, x + r, y + r)
      self.canvas.coords(line_orientation, x, y,
                         x + r * math.cos(theta), y + r * math.sin(theta))

  def _check_caught(self):
    if self._caught is not None:
      return
    px, py, _ = self.pacman.pose()
    for ghost in self.ghosts:
      gx, gy, _ = ghost.pose()
      if math.hypot(gx - px, gy - py) < self.catch_radius:
        self._caught = (ghost, time.monotonic() - self._start)
        for robot in self.robots:
          robot.halt()
        return

  def _tick(self):
    self._check_caught()
    self._draw()
    if self._caught is None:
      text = f"{time.monotonic() - self._start:.1f}s   W go, S turn around, A/D turn, R restart"
    else:
      ghost, t = self._caught
      text = f"Caught by {ghost.id} after {t:.1f}s   R to restart"
    self.canvas.itemconfigure(self._status, text=text)
    self.root.after(self.interval_ms, self._tick)

  def run(self):
    self._tick()
    self.root.mainloop()
