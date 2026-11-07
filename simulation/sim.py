from gui import GUI
from ghost import make_ghosts
from pacman import make_pacman


def main():
  pacman = make_pacman()
  ghosts = make_ghosts(pacman)
  for robot in ghosts + [pacman]:
    robot.start()

  gui = GUI([pacman, *ghosts])
  gui.register_pacman_controls(pacman)
  gui.run()


if __name__ == "__main__":
  main()
