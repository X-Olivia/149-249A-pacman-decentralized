import math
import tkinter as tk


class Robot:
  def __init__(self, x, y, theta, color):
    self.x, self.y, self.theta, self.color = x, y, theta, color

  def rotate(self, dtheta):
    self.theta += dtheta

  def forward(self, d):
    self.x += d * math.cos(self.theta)
    self.y += d * math.sin(self.theta)

  def draw(self, canvas, r=15):
    canvas.create_oval(self.x - r, self.y - r, self.x +
                       r, self.y + r, fill=self.color)
    # heading line so you can see orientation
    canvas.create_line(self.x, self.y,
                       self.x + r * math.cos(self.theta),
                       self.y + r * math.sin(self.theta), width=3)


root = tk.Tk()
canvas = tk.Canvas(root, width=800, height=600, bg="gray")
canvas.pack()
robots = [Robot(200, 300, 0, "yellow"), Robot(600, 300, math.pi, "red")]


def tick():
  for r in robots:
    r.rotate(0.03)
    r.forward(2)
  canvas.delete("all")
  for r in robots:
    r.draw(canvas)
  root.after(16, tick)   # ~60 FPS


tick()
root.mainloop()
