"""The holes of the wall of the chapter, measured on the raw export.

The module builds a face between two cells from their flat profiles: the flat
patches of the blocks. A cell whose mesh has no horizontal patch (a steep
slope inside one cell) has no flat profile, so the face against it cannot be
built. This script compares the surface of every pair of neighbours with the
faces the module can build, and lists the intervals that stay open.

Usage:
    python work/campaign/walls/port_holes.py [chapter.json]
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
    """The flat profile, the slope profile and the surface of every cell."""
    meshes = data["meshes"]
    flat = {}
    slope = {}
    surface = {}
    has_flat = {}
    for entry in data["cells"]:
        cell = (int(entry["x"]), int(entry["y"]))
        flat_sides = {side: [] for side in range(4)}
        slope_sides = {side: [] for side in range(4)}
        flat_here = False
        for points in triangles_of(meshes, int(entry["block"])):
            is_flat = flat_triangle(points)
            if is_flat:
                flat_here = True
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
                else:
                    slope_sides[side].append((t0, t1, z0, z1))
        flat[cell] = flat_sides
        slope[cell] = slope_sides
        surface[cell] = {side: slope_sides[side]
                          + [(t0, t1, z, z) for t0, t1, z in flat_sides[side]]
                          for side in range(4)}
        has_flat[cell] = flat_here
    return flat, slope, surface, has_flat


def neighbour(cell, side):
    x, y = cell
    return ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1))[side]


def opposite(side):
    return (SIDE_NEG_X, SIDE_POS_X, SIDE_NEG_Y, SIDE_POS_Y)[side]


def flat_level(segments, position):
    """The level of a flat profile: the highest patch wins."""
    level = None
    for t0, t1, z in segments:
        if position >= t0 - EPS and position <= t1 + EPS:
            if level is None or z > level:
                level = z
    return level


def surface_height(segments, position):
    """The height of the surface (flat patches and ramps) at a position."""
    best = None
    for t0, t1, z0, z1 in segments:
        if position < t0 - EPS or position > t1 + EPS:
            continue
        span = t1 - t0
        value = z0 if span <= EPS else z0 + (z1 - z0) * (position - t0) / span
        if best is None or value > best:
            best = value
    return best


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else CHAPTER
    with open(path, encoding="utf-8") as handle:
        data = json.load(handle)
    flat, slope, surface, has_flat = build(data)

    holes = []
    covered = 0
    for cell in surface:
        for side in range(4):
            other = neighbour(cell, side)
            if other not in surface:
                continue
            mine = surface[cell][side]
            theirs = surface[other][opposite(side)]
            flat_mine = flat[cell][side]
            flat_theirs = flat[other][opposite(side)]
            if not mine or not theirs:
                continue
            marks = sorted({round(value, 4)
                            for segment in mine + theirs + flat_mine + flat_theirs
                            for value in (segment[0], segment[1])})
            for index in range(len(marks) - 1):
                start, stop = marks[index], marks[index + 1]
                if stop - start <= EPS:
                    continue
                middle = (start + stop) * 0.5
                height_mine = surface_height(mine, middle)
                height_theirs = surface_height(theirs, middle)
                if height_mine is None or height_theirs is None:
                    continue
                gap = abs(height_mine - height_theirs)
                if gap < MIN_WALL_HEIGHT:
                    continue
                # The face the module can build: both flat profiles have to
                # cover the interval.
                level_mine = flat_level(flat_mine, middle)
                level_theirs = flat_level(flat_theirs, middle)
                if level_mine is not None and level_theirs is not None \
                        and abs(level_mine - level_theirs) >= MIN_WALL_HEIGHT:
                    covered += 1
                    continue
                holes.append((cell, side, other, start, stop,
                              height_mine, height_theirs, gap,
                              level_mine, level_theirs,
                              has_flat[cell], has_flat[other]))

    print("=== the intervals of a boundary with a gap ===")
    print("covered by the module:", covered)
    print("open (holes):", len(holes))
    print()
    kinds = Counter()
    for hole in holes:
        kinds[(hole[10], hole[11])] += 1
    print("=== the kinds of the open intervals (flat here, flat there) ===")
    for key, count in kinds.most_common():
        print("  flat %-5s flat %-5s : %d" % (key[0], key[1], count))
    print()
    print("=== the open intervals ===")
    for hole in holes:
        print("%-14s %s -> %-14s t %.3f..%.3f  surface %6.3f / %6.3f  gap %4.2f  "
              "flat %s / %s" % (
                  str(hole[0]), SIDE_NAMES[hole[1]], str(hole[2]), hole[3], hole[4],
                  hole[5], hole[6], hole[7],
                  "%.3f" % hole[8] if hole[8] is not None else "none",
                  "%.3f" % hole[9] if hole[9] is not None else "none"))
    print()
    cells = set()
    for hole in holes:
        cells.add(hole[0])
        cells.add(hole[2])
    print("cells that touch an open interval:", len(cells))


if __name__ == "__main__":
    main()
