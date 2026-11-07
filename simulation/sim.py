from gui import GUI
from ghost import make_ghosts


def main():
  ghosts = make_ghosts()
  for ghost in ghosts:
    ghost.start()
  GUI(ghosts).run()


if __name__ == "__main__":
  main()
