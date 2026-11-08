import argparse

from gui import GUI
from ghost import UWB_MAX_RANGE, make_ghosts
from maze import Maze
from pacman import make_pacman


def main():
  parser = argparse.ArgumentParser(description="Pacman maze simulation")
  parser.add_argument("--uwb-mode", choices=["angle", "range"],
                      default="angle",
                      help="angle: UWB gives distance and angle to Pac-Man; "
                           "range: distance only (default %(default)s)")
  parser.add_argument("--uwb-range", type=float, default=UWB_MAX_RANGE,
                      help="UWB max range in pixels (default %(default)s)")
  args = parser.parse_args()

  maze = Maze()
  pacman = make_pacman(maze)
  ghosts = make_ghosts(pacman, maze, uwb_mode=args.uwb_mode,
                       max_range=args.uwb_range)
  for robot in ghosts + [pacman]:
    robot.start()

  gui = GUI([pacman, *ghosts], maze)
  gui.register_pacman_controls(pacman)
  gui.run()


if __name__ == "__main__":
  main()
