from gui import GUI
from robot import make_robots


def main():
  robots = make_robots()
  for robot in robots:
    robot.start()
  GUI(robots).run()


if __name__ == "__main__":
  main()
