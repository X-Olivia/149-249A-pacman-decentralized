import math
import tkinter as tk

ONE_SECOND_IN_MS=1000

class GUI:
  def __init__(self, robots, width=800, height=600, hz=60, radius=15):
    self.robots = robots
    self.radius = radius
    self.interval_ms = round(ONE_SECOND_IN_MS / hz)

    self.root = tk.Tk()
    self.root.title("Simulation")
    self.canvas = tk.Canvas(self.root, width=width, height=height, bg="gray",
                            highlightthickness=0)
    self.canvas.pack()

    # creates the robot body, and the white line that shows its orientation
    self._items = {}
    for robot in robots:
      body = self.canvas.create_oval(0, 0, 0, 0, fill=robot.color)
      line_orientation = self.canvas.create_line(0, 0, 0, 0, width=3)
      self._items[robot] = (body, line_orientation)

  def _draw(self):
    r = self.radius
    for robot, (body, line_orientation) in self._items.items():
      x, y, theta = robot.pose()
      self.canvas.coords(body, x - r, y - r, x + r, y + r)
      self.canvas.coords(line_orientation, x, y,
                         x + r * math.cos(theta), y + r * math.sin(theta))

  def _tick(self):
    self._draw()
    self.root.after(self.interval_ms, self._tick)

  def run(self):
    self._tick()
    self.root.mainloop()
