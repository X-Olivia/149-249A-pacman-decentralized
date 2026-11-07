import math


class UWB:
  """ULTRA-WIDEBAND"""

  def __init__(self, owner, others):
    assert owner not in others
    self.owner = owner    # robot this sensor is mounted on.
    self.others = others  # all other robots.
    # TODO: add a noise parameter (i.e., how noisy is each reading).
    # TODO: add a max_range parameter to limit the distance sensed.
    # TODO: could also add a return_angle boolean parameter to allow sense()
    #       to return the angle as well.

  def sense(self):
    """Return the distance to every other robot as a map {robot_id: distance}."""
    x, y, _ = self.owner.pose()
    readings = {}
    for robot in self.others:
      ox, oy, _ = robot.pose()
      # basically ||<ox, oy> - <x, y>|| (euc distance between this and other robot)
      readings[robot.id] = math.hypot(ox - x, oy - y)
    return readings
