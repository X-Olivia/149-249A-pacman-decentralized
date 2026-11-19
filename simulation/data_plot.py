import math
import os
import tkinter as tk

import ghost
import gui
from maze import Maze
from pacman import Pacman

import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

# TODO: From the graph, we can see that while the distance is ok, our current way of determining ROC is very inaccurate. We should do something like linear regression instead
# TODO: Or UWB_NOISE_DIST is 5.0, but what is that even? It is in pixels, but we never define what pixels is in m. Without this, we cannot accurately simulate
# TODO: We may need to try to smoothen noise out using a type of filter
# TODO: Implement more test cases (sine wave, random motion etc)


EMPTY_MAP = \
"""
+-+-+-+-+-+-+-+-+-+-+-+-+
|                       |
+                       +
|                       |
+   P               G   +
|                       |
+                       +
|                       |
+-+-+-+-+-+-+-+-+-+-+-+-+
"""

# True: graphs are packed next to the maze. False: graphs get their own window.
SIDE_BY_SIDE = True

# Graph class for drawing graphs related to the ghosts (if we want to use it for pacman, we need it to have internal time)
class Graph:

    def __init__(self, parent, title, value_fn):
        self.title = title
        self.value_fn = value_fn
        self.fig, self.ax = plt.subplots()
        self.canvas = FigureCanvasTkAgg(self.fig, master=parent)
        self.widget = self.canvas.get_tk_widget()
        self.history = {}
        self.clear()
        self.ax.grid(True)
        self.canvas.draw()

    def plot(self, robot):
        xs, ys = self.history.setdefault(robot.id, ([], []))
        xs.append(robot.time)
        ys.append(self.value_fn(robot))
        self.ax.plot(xs, ys, color=robot.color, marker="o")
        self.canvas.draw()

    def clear(self):
        self.history = {}
        self.ax.clear()
        self.ax.set_title(self.title)
        self.ax.grid(True)
        self.canvas.draw()


class Pacman_dummy(Pacman):
    def __init__(self, maze):
        x, y = maze.node_pos(maze.pacman_start)
        super().__init__(x, y, 0.0, maze)

    def _step(self):
        pass


class GUI(gui.GUI):
    def __init__(self, robots, maze, graphs, hz=60, radius=15, catch_radius=gui.CATCH_RADIUS):
        super().__init__(robots, maze, hz=60, radius=15, catch_radius=gui.CATCH_RADIUS)
        self.graphs = graphs
        self.isPaused = False
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)

    def register_pacman_controls(self, pacman):
        self.root.bind("<KeyPress-r>", lambda e: self.reset())
        self.root.bind("<KeyPress-p>", lambda e: self.pause())

    def _tick(self):
        self._check_caught()
        self._draw()
        text = "r to restart, p to pause/unpause"
        self.canvas.itemconfigure(self._status, text=text)
        self.root.after(self.interval_ms, self._tick)

    def on_closing(self):
        self.root.quit()
        self.root.destroy()
        os._exit(0)

    def pause(self):
        """P: pause / unpause"""
        if not self.isPaused:
            for robot in self.robots:
                robot.halt()
        else:
            for robot in self.robots:
                robot.unhalt()
        self.isPaused = not self.isPaused

    def reset(self):
        for graph in self.graphs:
            graph.clear()
        return super().reset()


class Ghost(ghost.Ghost):
    def __init__(self, id, x, y, theta, color, maze, graphs, speed=60.0,
                 target_id="pacman", uwb_mode="angle", rng=None):
        super().__init__(id, x, y, theta, color, maze, speed=speed,
                         target_id=target_id, uwb_mode=uwb_mode, rng=rng)
        self.graphs = graphs
        self.plot_period = .2
        self.last_plot = 0

    def roc(self):
        return self.__get_dist_roc(0)
    def dist(self):
        return self._last_distance

    def reset(self):
        self.last_plot = 0
        return super().reset()

    # Currently, it only goes forwards. However, as we add more test cases, we would ideally create separate functions and assign them to _step according to the test being executed

    def _step(self):
        if self._halted:
            return
        if self.time < 10:
            self._record_distance()
            self._forward(self.speed * ghost.SECONDS_BETWEEN_STEPS)
            self.time += ghost.SECONDS_BETWEEN_STEPS
            if self.last_plot + self.plot_period < self.time:
                for graph in self.graphs:
                    graph.plot(self)
                self.last_plot = self.time


def make_ghosts(pacman, maze, graphs, uwb_mode="range", max_range=ghost.UWB_MAX_RANGE):
    x, y = maze.node_pos(maze.ghost_starts[0])
    ghost_under_test = Ghost("ghost_under_test", x, y, math.pi, "orange", maze, graphs,
                             speed=60, uwb_mode=uwb_mode)
    ghost_ideal = Ghost("ghost_ideal", x, y, math.pi, "black", maze, graphs,
                        speed=60, uwb_mode=uwb_mode)
    ghost_under_test.register_uwb([pacman], max_range=max_range)
    ghost_ideal.register_uwb([pacman], max_range=max_range, noise_dist=0)
    return [ghost_ideal, ghost_under_test]


def add_graph(graphs, parent, title, value_fn):
    graph = Graph(parent, title, value_fn)
    graph.widget.pack(side=tk.RIGHT if SIDE_BY_SIDE else tk.TOP)
    graphs.append(graph)

# Could be good to add a parser for setting the test case
def main():
    maze = Maze(layout=EMPTY_MAP)
    pacman = Pacman_dummy(maze)
    graphs = []
    ghosts = make_ghosts(pacman, maze, graphs)
    gui = GUI([pacman] + ghosts, maze, graphs)
    gui.register_pacman_controls(pacman)

    if SIDE_BY_SIDE:
        parent = gui.root
    else:
        parent = tk.Toplevel(gui.root)
        parent.title("Graphs")
        parent.attributes('-topmost', True)

    add_graph(graphs, parent, "ROC vs time", lambda g: g.roc())
    add_graph(graphs, parent, "Distance vs time", lambda g: g.dist())

    for robot in ghosts + [pacman]:
        robot.start()
    gui.run()


if __name__ == "__main__":
    main()