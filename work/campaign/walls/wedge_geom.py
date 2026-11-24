"""The geometry of the wedges of the chapter: what they are, in fact.

A wedge is a slanted triangle whose lower edge is diagonal in the plan: both ends
of the edge differ in x and in y. Earlier this was read as the corner of an
excavation - a slanted panel where the original draws two vertical planes. That
reading was wrong, and this script measures the real geometry:

  - is the lower edge the diagonal of the cell (a chamfer of the cell corner) or
    a diagonal edge inside the cell;
  - how high the apex stands above the lower edge;
  - at which level the lower edge lies;
  - which part of the block carries it;
  - which way the wedge faces: to the excavated neighbour or into the rock.

The blocks of the chapter are read by the exporter from BlockDB2.BDB of the
original game (tools/export_campaign_chapter.py:514), so a wedge is the geometry
of the game itself and not an artifact of the port.

Usage:
    python work/campaign/walls/wedge_geom.py [chapter.json]
"""

import json
import os
import sys
from collections import Counter

EPS = 1e-6
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))))
CHAPTER = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")


def triangles_of(meshes, block):
    for part in meshes.get(str(block), []):
        values = part["vertices"]
        indices = part["indices"]
        for start in range(0, len(indices), 3):
            points = []
            for corner in range(3):
                offset = int(indices[start + corner]) * 5
                points.append((float(values[offset]), float(values[offset + 1]),
                               float(values[offset + 2])))
            yield part, points


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else CHAPTER
    with open(path, encoding="utf-8") as handle:
        data = json.load(handle)
    meshes = data["meshes"]
    materials = data.get("materials", {})

    total = 0
    on_diagonal = 0
    inside_cell = 0
    parts = Counter()
    apex_heights = Counter()
    lower_levels = Counter()
    faces_out = 0
    faces_in = 0
    lower_edge_on_border = 0
    lower_edge_inside = 0
    samples = []
    chapter_cells = {(int(c["x"]), int(c["y"])) for c in data["cells"]}

    for entry in data["cells"]:
        cx, cy = int(entry["x"]), int(entry["y"])
        corners = {(cx, cy), (cx + 1, cy), (cx, cy + 1), (cx + 1, cy + 1)}
        for part, points in triangles_of(meshes, int(entry["block"])):
            heights = [point[2] for point in points]
            if max(heights) - min(heights) <= EPS:
                continue
            flat_x = all(abs(point[0] - points[0][0]) <= EPS for point in points)
            flat_y = all(abs(point[1] - points[0][1]) <= EPS for point in points)
            if flat_x or flat_y:
                # A vertical face of the export, not a wedge.
                continue
            low = min(heights)
            low_points = [point for point in points if abs(point[2] - low) <= EPS]
            if len(low_points) != 2:
                continue
            a, b = low_points
            if abs(a[0] - b[0]) <= EPS or abs(a[1] - b[1]) <= EPS:
                # A cardinal lower edge: a ramp of the height field.
                continue
            # A wedge.
            total += 1
            parts[int(part.get("part", -1))] += 1
            edge = {(round(a[0], 4), round(a[1], 4)), (round(b[0], 4), round(b[1], 4))}
            if edge <= corners:
                on_diagonal += 1
            else:
                inside_cell += 1
            apex = max(points, key=lambda point: point[2])
            apex_heights[round(apex[2] - low, 3)] += 1
            lower_levels[round(low, 2)] += 1
            # Is the lower edge on the border of the cell or inside it?
            on_border = (abs(a[0] - b[0]) <= EPS and abs(a[0]) <= EPS) \
                or (abs(a[0] - b[0]) <= EPS and abs(a[0] - 1.0) <= EPS) \
                or (abs(a[1] - b[1]) <= EPS and abs(a[1]) <= EPS) \
                or (abs(a[1] - b[1]) <= EPS and abs(a[1] - 1.0) <= EPS)
            if on_border:
                lower_edge_on_border += 1
            else:
                lower_edge_inside += 1
            # Which way does the wedge face?
            middle = ((a[0] + b[0]) * 0.5, (a[1] + b[1]) * 0.5)
            dx, dy = apex[0] - middle[0], apex[1] - middle[1]
            step_x = 0 if abs(dx) <= EPS else (1 if dx > 0 else -1)
            step_y = 0 if abs(dy) <= EPS else (1 if dy > 0 else -1)
            neighbour = (cx + step_x, cy + step_y)
            material = materials.get("%d,%d" % neighbour)
            excavated = neighbour in chapter_cells \
                and material is not None and int(material) == 3
            if excavated:
                faces_out += 1
            else:
                faces_in += 1
            if len(samples) < 6:
                samples.append((cx, cy, int(part.get("part", -1)),
                                [(round(p[0], 3), round(p[1], 3), round(p[2], 3))
                                 for p in points],
                                (step_x, step_y), neighbour, material))

    print("=== the wedges of the chapter ===")
    print("wedges:", total)
    print("by the part of the block:", dict(parts))
    print()
    print("=== where the lower edge lies ===")
    print("the diagonal of the cell:", on_diagonal)
    print("a diagonal edge inside the cell:", inside_cell)
    print("the lower edge on the border of the cell:", lower_edge_on_border)
    print("the lower edge inside the cell:", lower_edge_inside)
    print()
    print("=== the height of the apex above the lower edge ===")
    for height, count in sorted(apex_heights.items()):
        print("  %5.2f : %d" % (height, count))
    print()
    print("=== the level of the lower edge ===")
    for level, count in sorted(lower_levels.items())[:12]:
        print("  %6.2f : %d" % (level, count))
    print("  ... всего уровней:", len(lower_levels))
    print()
    print("=== which way the wedge faces ===")
    print("to the excavated neighbour (visible in the original):", faces_out)
    print("into the rock (closed in the original):", faces_in)
    print()
    print("=== samples ===")
    for sample in samples:
        print(" ", sample)


if __name__ == "__main__":
    main()
