import math
import random

from maze import heading_of


class UWB:
  """ULTRA-WIDEBAND"""

  def __init__(self, owner, others, return_angle=False, noise_dist=0.0,
               noise_angle_deg=0.0, max_range=None, rng=None):
    assert owner not in others
    self.owner = owner    # robot this sensor is mounted on.
    self.others = others  # all other robots.
    self.return_angle = return_angle        # also measure angle of arrival
    self.noise_dist = noise_dist            # std dev of distance noise (px)
    self.noise_angle = math.radians(noise_angle_deg)  # std dev of angle noise
    self.max_range = max_range              # no reading beyond this (px)
    self.rng = rng or random.Random()

  def sense(self):
    """Return a reading for every other robot in range: {robot_id: reading}.

    reading = distance, or (distance, bearing) if return_angle. bearing is
    the angle to the other robot relative to the owner's heading, in radians
    in (-pi, pi]: 0 = straight ahead, + = to its right, - = to its left
    (screen coordinates, y down).
    """
    x, y, theta = self.owner.pose()
    readings = {}
    for robot in self.others:
      ox, oy, _ = robot.pose()
      # basically ||<ox, oy> - <x, y>|| (euc distance between this and other robot)
      distance = math.hypot(ox - x, oy - y)
      if self.max_range is not None and distance > self.max_range:
        continue
      distance = max(0.0, distance + self.rng.gauss(0.0, self.noise_dist))
      if not self.return_angle:
        readings[robot.id] = distance
        continue
      bearing = math.atan2(oy - y, ox - x) - theta
      bearing += self.rng.gauss(0.0, self.noise_angle)
      bearing = math.atan2(math.sin(bearing), math.cos(bearing))  # wrap
      readings[robot.id] = (distance, bearing)
    return readings


# Relative directions, in degrees clockwise from the robot's heading.
FRONT, RIGHT, BACK, LEFT = 0, 90, 180, 270


class IR:
  """Downward IR line sensors: at an intersection, which ways have tape.

  Returns directions relative to the robot (FRONT/RIGHT/BACK/LEFT), not
  world directions, since the robot doesn't know where it is in the maze.
  """

  def __init__(self, owner, maze):
    self.owner = owner
    self.maze = maze

  def at_intersection(self):
    x, y, _ = self.owner.pose()
    return self.maze.node_at(x, y) is not None

  def exits(self):
    """Set of relative directions with tape, or empty if not at an intersection."""
    x, y, theta = self.owner.pose()
    node = self.maze.node_at(x, y)
    if node is None:
      return set()
    heading = heading_of(theta)
    return {(h - heading) % 360 for h in self.maze.tape_headings(node)}
