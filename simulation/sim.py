from gui import GUI
from ghost import make_ghosts
from pacman import make_pacman


def main():
  ghosts = make_ghosts()
  pacman = make_pacman()
  for robot in ghosts + [pacman]:
    robot.start()

  gui = GUI(ghosts + [pacman])
  gui.register_pacman_controls(pacman)
  gui.run()


if __name__ == "__main__":
  main()
