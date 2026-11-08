"""Tape maze: intersections on a grid joined by straight tape segments.

Matches the physical maze: robots follow black tape and only choose a new
direction at intersections.

Layout format (ASCII). Intersections sit at even columns of even lines:
  '+'  intersection
  'P'  intersection where Pac-Man starts
  'G'  intersection where a ghost starts
  '-'  tape to the next intersection on the right (odd column, even line)
  '|'  tape to the next intersection below (even column, odd line)
  ' '  no tape

Headings are in degrees in screen coordinates (y points down):
0 = right (+x), 90 = down (+y), 180 = left, 270 = up.
"""

import math

SPACING = 80   # pixels between neighbouring intersections
MARGIN = 40    # pixels from the canvas edge to the first intersection

DEFAULT_LAYOUT = """
+-+-+-+-+-+-+
|   |   |   |
+-+-+-G-+-+-+
| |   |   | |
+-+ +-+-+ +-+
|   |   |   |
+-+-+-P-+-+-+
  |       |
+-+-+   +-+-+
"""

HEADING_STEP = {0: (1, 0), 90: (0, 1), 180: (-1, 0), 270: (0, -1)}


class Maze:
  def __init__(self, layout=DEFAULT_LAYOUT, spacing=SPACING, margin=MARGIN):
    self.spacing = spacing
    self.margin = margin
    lines = layout.strip("\n").splitlines()
    self.nodes = set()
    self.edges = set()          # frozenset({node_a, node_b})
    self.pacman_start = None
    self.ghost_starts = []

    for row, line in enumerate(lines):
      for col, ch in enumerate(line):
        if row % 2 == 0 and col % 2 == 0 and ch in "+PG":
          node = (col // 2, row // 2)
          self.nodes.add(node)
          if ch == "P":
            self.pacman_start = node
          elif ch == "G":
            self.ghost_starts.append(node)
        elif row % 2 == 0 and col % 2 == 1 and ch == "-":
          self.edges.add(frozenset({(col // 2, row // 2),
                                    (col // 2 + 1, row // 2)}))
        elif row % 2 == 1 and col % 2 == 0 and ch == "|":
          self.edges.add(frozenset({(col // 2, row // 2),
                                    (col // 2, row // 2 + 1)}))
    for edge in self.edges:
      if not edge <= self.nodes:
        raise ValueError(f"tape {sorted(edge)} does not join two intersections")

    self.cols = max(i for i, _ in self.nodes) + 1
    self.rows = max(j for _, j in self.nodes) + 1
    self.width = 2 * margin + (self.cols - 1) * spacing
    self.height = 2 * margin + (self.rows - 1) * spacing

  # --- geometry ---------------------------------------------------------

  def node_pos(self, node):
    i, j = node
    return self.margin + i * self.spacing, self.margin + j * self.spacing

  def node_at(self, x, y, tol=1e-6):
    """The intersection at (x, y), or None if (x, y) is between intersections."""
    fi = (x - self.margin) / self.spacing
    fj = (y - self.margin) / self.spacing
    i, j = round(fi), round(fj)
    if (abs(fi - i) * self.spacing <= tol and abs(fj - j) * self.spacing <= tol
        and (i, j) in self.nodes):
      return (i, j)
    return None

  def has_tape(self, node, heading_deg):
    di, dj = HEADING_STEP[heading_deg % 360]
    return frozenset({node, (node[0] + di, node[1] + dj)}) in self.edges

  def tape_headings(self, node):
    """World headings (deg) that have tape leaving this intersection."""
    return {h for h in HEADING_STEP if self.has_tape(node, h)}

  def advance(self, x, y, heading_deg, d):
    """Move up to d pixels along the tape from (x, y).

    Stops exactly on the next intersection if it is reached, so the robot can
    make its decision there. Returns (new_x, new_y, reached_intersection).
    """
    dx, dy = HEADING_STEP[heading_deg % 360]
    along = (x - self.margin) * dx + (y - self.margin) * dy  # signed position
    k = along / self.spacing
    next_k = math.floor(k + 1e-9) + 1                      # next grid line ahead
    to_next = next_k * self.spacing - along
    if d >= to_next - 1e-9:
      return x + dx * to_next, y + dy * to_next, True
    return x + dx * d, y + dy * d, False


def heading_of(theta):
  """Snap an angle in radians to the nearest of 0/90/180/270 degrees."""
  return int(round(math.degrees(theta) / 90.0)) % 4 * 90
