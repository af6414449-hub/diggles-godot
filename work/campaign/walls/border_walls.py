"""The walls at the borders of the cells, from the surface of both sides.

The export carries vertical faces in the planes y = const only: 880 of them on
the border of a cell and 8971 inside a cell, and not one in the planes
x = const. The wall module rebuilds the faces of the excavations from the
height field, so the borders where a slope runs down to the edge of a cell
have no face at all: the two sides of the border differ and the gap shows the
background of the scene.

This script builds the walls of the borders from the surface of both cells -
the flat patches and the ramps - and counts what is left open.

Usage:
    python work/campaign/walls/border_walls.py [chapter.json]
"""

import json
import os
import sys
from collections import Counter

EPS = 1e-4
MIN_WALL_HEIGHT = 0.25
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))))
CHAPTER = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")

SIDE_POS_X, SIDE_NEG_X, SIDE_POS_Y, SIDE_NEG_Y = 0, 1, 2, 3
SIDE_NAMES = ("+x", "-x", "+y", "-y")


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
            yield points


def flat_triangle(points):
    heights = [point[2] for point in points]
    return max(heights) - min(heights) <= EPS


def side_of_edge(a, b):
    if abs(a[1] - b[1]) <= EPS:
        if abs(a[1]) <= EPS:
            return SIDE_NEG_Y
        if abs(a[1] - 1.0) <= EPS:
            return SIDE_POS_Y
        return -1
    if abs(a[0] - b[0]) <= EPS:
        if abs(a[0]) <= EPS:
            return SIDE_NEG_X
        if abs(a[0] - 1.0) <= EPS:
            return SIDE_POS_X
        return -1
    return -1


def build(data):
    """The flat profile, the surface profile and the border faces."""
    meshes = data["meshes"]
    flat = {}
    surface = {}
    border_face = {}
    for entry in data["cells"]:
        cell = (int(entry["x"]), int(entry["y"]))
        flat_sides = {side: [] for side in range(4)}
        surface_sides = {side: [] for side in range(4)}
        faces = {side: False for side in range(4)}
        for points in triangles_of(meshes, int(entry["block"])):
            is_flat = flat_triangle(points)
            # A vertical triangle of the block is a face of the export.
            xs = {round(point[0], 4) for point in points}
            ys = {round(point[1], 4) for point in points}
            vertical = len(xs) == 1 or len(ys) == 1
            for corner in range(3):
                a = points[corner]
                b = points[(corner + 1) % 3]
                side = side_of_edge(a, b)
                if side < 0:
                    continue
                along_x = side in (SIDE_POS_X, SIDE_NEG_X)
                t0 = a[1] if along_x else a[0]
                t1 = b[1] if along_x else b[0]
                z0, z1 = a[2], b[2]
                if t0 > t1:
                    t0, t1 = t1, t0
                    z0, z1 = z1, z0
                if is_flat:
                    flat_sides[side].append((t0, t1, z0))
                    surface_sides[side].append((t0, t1, z0, z0))
                else:
                    surface_sides[side].append((t0, t1, z0, z1))
                    if vertical and abs(a[2] - b[2]) > EPS:
                        faces[side] = True
        flat[cell] = flat_sides
        surface[cell] = surface_sides
        border_face[cell] = faces
    return flat, surface, border_face


def neighbour(cell, side):
    x, y = cell
    return ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1))[side]


def opposite(side):
    return (SIDE_NEG_X, SIDE_POS_X, SIDE_NEG_Y, SIDE_POS_Y)[side]


def height_at(segments, position):
    """The height of a surface profile: the highest patch wins."""
    best = None
    for t0, t1, z0, z1 in segments:
        if position < t0 - EPS or position > t1 + EPS:
            continue
        span = t1 - t0
        value = z0 if span <= EPS else z0 + (z1 - z0) * (position - t0) / span
        if best is None or value > best:
            best = value
    return best


def flat_level(segments, position):
    level = None
    for t0, t1, z in segments:
        if position >= t0 - EPS and position <= t1 + EPS:
            if level is None or z > level:
                level = z
    return level


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else CHAPTER
    with open(path, encoding="utf-8") as handle:
        data = json.load(handle)
    flat, surface, border_face = build(data)

    # The walls of the module today: the flat profiles of the two cells.
    old_walls = 0
    old_holes = []
    new_walls = 0
    new_holes = []
    for cell in surface:
        for side in range(4):
            other = neighbour(cell, side)
            if other not in surface:
                continue
            here = surface[cell][side]
            theirs = surface[other][opposite(side)]
            flat_here = flat[cell][side]
            flat_theirs = flat[other][opposite(side)]
            if not here or not theirs:
                continue
            marks = sorted({round(value, 4)
                            for segment in here + theirs + flat_here + flat_theirs
                            for value in (segment[0], segment[1])})
            for index in range(len(marks) - 1):
                start, stop = marks[index], marks[index + 1]
                if stop - start <= EPS:
                    continue
                middle = (start + stop) * 0.5
                height_here = height_at(here, middle)
                height_theirs = height_at(theirs, middle)
                if height_here is None or height_theirs is None:
                    continue
                gap = abs(height_here - height_theirs)
                if gap < MIN_WALL_HEIGHT:
                    continue
                # The module today: the flat profiles of the two cells.
                level_here = flat_level(flat_here, middle)
                level_theirs = flat_level(flat_theirs, middle)
                built = (level_here is not None and level_theirs is not None
                         and abs(level_here - level_theirs) >= MIN_WALL_HEIGHT)
                if built:
                    old_walls += 1
                else:
                    old_holes.append((cell, side, other, start, stop,
                                      height_here, height_theirs, gap))
                # The new rule: the surface of both cells, unless the export
                # already carries a face on the border.
                if border_face[cell][side] or border_face[other][opposite(side)]:
                    continue
                new_walls += 1

    print("=== the walls of the borders ===")
    print("the module today builds %d faces, %d intervals stay open" % (
        old_walls, len(old_holes)))
    print("the new rule builds %d faces" % new_walls)
    print()
    print("=== the open intervals of the module today ===")
    heights = Counter()
    for hole in old_holes:
        heights[round(hole[7] * 2) / 2.0] += 1
    for gap, count in sorted(heights.items()):
        print("  gap %4.1f : %d intervals" % (gap, count))
    print()
    cells = set()
    for hole in old_holes:
        cells.add(hole[0])
        cells.add(hole[2])
    print("cells that touch an open interval:", len(cells))
    print()
    print("=== the first twenty open intervals ===")
    for hole in old_holes[:20]:
        print("%-14s %s -> %-14s t %.3f..%.3f  %6.3f / %6.3f  gap %4.2f" % (
            str(hole[0]), SIDE_NAMES[hole[1]], str(hole[2]), hole[3], hole[4],
            hole[5], hole[6], hole[7]))


if __name__ == "__main__":
    main()
