"""The edges between a flat cell and a cell without a flat patch.

The wall module builds a face between two cells from their flat profiles. A
cell without a flat patch (a steep slope inside one cell) has no flat profile,
so the face against it cannot be built and the neighbour keeps a hole in its
wall. This script lists those edges with the geometry of both sides, so that
the shape of the missing face is known before it is built.

Usage:
    python work/campaign/walls/ridge_edges.py [chapter.json]
"""

import json
import os
import sys
from collections import Counter

EPS = 1e-4
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
    meshes = data["meshes"]
    flat = {}
    poly = {}
    ridge = set()
    for entry in data["cells"]:
        cell = (int(entry["x"]), int(entry["y"]))
        flat_sides = {side: [] for side in range(4)}
        poly_sides = {side: [] for side in range(4)}
        has_flat = False
        for points in triangles_of(meshes, int(entry["block"])):
            if flat_triangle(points):
                has_flat = True
                for corner in range(3):
                    a = points[corner]
                    b = points[(corner + 1) % 3]
                    side = side_of_edge(a, b)
                    if side < 0:
                        continue
                    along_x = side in (SIDE_POS_X, SIDE_NEG_X)
                    t0 = a[1] if along_x else a[0]
                    t1 = b[1] if along_x else b[0]
                    flat_sides[side].append((min(t0, t1), max(t0, t1), a[2]))
            else:
                for corner in range(3):
                    a = points[corner]
                    b = points[(corner + 1) % 3]
                    side = side_of_edge(a, b)
                    if side < 0:
                        continue
                    along_x = side in (SIDE_POS_X, SIDE_NEG_X)
                    t0 = a[1] if along_x else a[0]
                    t1 = b[1] if along_x else b[0]
                    z0, z1 = (a[2], b[2]) if t0 <= t1 else (b[2], a[2])
                    poly_sides[side].append((min(t0, t1), max(t0, t1), z0, z1))
        flat[cell] = flat_sides
        poly[cell] = poly_sides
        if not has_flat:
            ridge.add(cell)
    return flat, poly, ridge


def neighbour(cell, side):
    x, y = cell
    return ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1))[side]


def opposite(side):
    return (SIDE_NEG_X, SIDE_POS_X, SIDE_NEG_Y, SIDE_POS_Y)[side]


def poly_height(poly, position):
    """The height of the boundary polyline at a position."""
    best = None
    for t0, t1, z0, z1 in poly:
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
    flat, poly, ridge = build(data)

    edges = []
    for cell in flat:
        if cell in ridge:
            continue
        for side in range(4):
            other = neighbour(cell, side)
            if other in ridge:
                edges.append((cell, side, other))

    print("=== edges between a flat cell and a cell without a flat patch ===")
    print("edges:", len(edges))
    print()

    corner_match = Counter()
    steps = []
    covered = 0
    for cell, side, other in edges:
        here = flat[cell][side]
        theirs = poly[other][opposite(side)]
        level = here[0][2] if here else None
        # The ends of the boundary.
        low_end = poly_height(theirs, 0.0)
        high_end = poly_height(theirs, 1.0)
        if level is None:
            corner_match["no flat profile"] += 1
            continue
        if low_end is None or high_end is None:
            corner_match["no boundary"] += 1
            continue
        if abs(low_end - level) <= EPS and abs(high_end - level) <= EPS:
            corner_match["both ends equal"] += 1
        else:
            corner_match["an end differs"] += 1
        covered += 1
        steps.append((cell, side, other, level, low_end, high_end, theirs, here))

    print("=== the ends of the boundary against the flat level ===")
    for key, count in corner_match.most_common():
        print("  %-24s %d" % (key, count))
    print()

    print("=== the first fifteen edges ===")
    for cell, side, other, level, low_end, high_end, theirs, here in steps[:15]:
        print("%s %s -> ridge %s" % (str(cell), SIDE_NAMES[side], str(other)))
        print("    flat level of the cell : %.3f" % level)
        print("    flat profile            : %s" % (
            ", ".join("(%.3f..%.3f %.3f)" % segment for segment in here) or "none"))
        print("    slope of the ridge      : %s" % (
            ", ".join("(%.3f..%.3f %.3f->%.3f)" % segment for segment in theirs) or "none"))
        print("    ends of the boundary    : %.3f .. %.3f" % (low_end, high_end))
    print()

    # The vertical gap that has to be closed.
    gaps = Counter()
    for cell, side, other, level, low_end, high_end, theirs, here in steps:
        marks = set()
        for segment in theirs:
            marks.add(round(segment[0], 4))
            marks.add(round(segment[1], 4))
        for segment in here:
            marks.add(round(segment[0], 4))
            marks.add(round(segment[1], 4))
        marks = sorted(marks)
        for index in range(len(marks) - 1):
            start, stop = marks[index], marks[index + 1]
            if stop - start <= EPS:
                continue
            middle = (start + stop) * 0.5
            height = poly_height(theirs, middle)
            if height is None:
                continue
            gap = abs(height - level)
            gaps[round(gap * 2) / 2.0] += 1
    print("=== the vertical gap on the boundary (by the interval) ===")
    for gap, count in sorted(gaps.items()):
        print("  gap %4.1f : %d intervals" % (gap, count))


if __name__ == "__main__":
    main()
