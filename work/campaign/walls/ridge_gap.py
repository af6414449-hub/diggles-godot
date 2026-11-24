"""The real vertical gap on the boundaries of the chapter.

The wall module compares the flat profiles of two cells. A cell without a flat
patch (a steep slope inside one cell) has no flat profile, so the face against
it cannot be built. This script compares the full surface of both cells along
the shared boundary - the flat patches and the ramps - and measures the
vertical gap that no face covers.

Usage:
    python work/campaign/walls/ridge_gap.py [chapter.json]
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
    """The flat profile and the full surface profile of every cell and side."""
    meshes = data["meshes"]
    flat = {}
    surface = {}
    ridge = set()
    for entry in data["cells"]:
        cell = (int(entry["x"]), int(entry["y"]))
        flat_sides = {side: [] for side in range(4)}
        ramp_sides = {side: [] for side in range(4)}
        has_flat = False
        for points in triangles_of(meshes, int(entry["block"])):
            is_flat = flat_triangle(points)
            if is_flat:
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
                if t0 > t1:
                    a, b = b, a
                    t0, t1 = t1, t0
                if is_flat:
                    flat_sides[side].append((t0, t1, a[2], a[2]))
                else:
                    ramp_sides[side].append((t0, t1, a[2], b[2]))
        flat[cell] = flat_sides
        surface[cell] = {side: ramp_sides[side] + flat_sides[side] for side in range(4)}
        if not has_flat:
            ridge.add(cell)
    return flat, surface, ridge


def neighbour(cell, side):
    x, y = cell
    return ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1))[side]


def opposite(side):
    return (SIDE_NEG_X, SIDE_POS_X, SIDE_NEG_Y, SIDE_POS_Y)[side]


def height_at(segments, position):
    """The height of the surface at a position: the highest patch wins."""
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
    flat, surface, ridge = build(data)

    print("=== cells without a flat patch ===")
    print("count:", len(ridge))
    print()

    # Every boundary of the chapter, with the gap that no face covers.
    gaps = Counter()
    gap_edges = Counter()
    real_gaps = []
    for cell in surface:
        for side in range(4):
            other = neighbour(cell, side)
            if other not in surface:
                continue
            mine = surface[cell][side]
            theirs = surface[other][opposite(side)]
            if not mine or not theirs:
                continue
            marks = set()
            for segment in mine:
                marks.add(round(segment[0], 4))
                marks.add(round(segment[1], 4))
            for segment in theirs:
                marks.add(round(segment[0], 4))
                marks.add(round(segment[1], 4))
            marks = sorted(marks)
            for index in range(len(marks) - 1):
                start, stop = marks[index], marks[index + 1]
                if stop - start <= EPS:
                    continue
                middle = (start + stop) * 0.5
                height_mine = height_at(mine, middle)
                height_theirs = height_at(theirs, middle)
                if height_mine is None or height_theirs is None:
                    continue
                gap = abs(height_mine - height_theirs)
                if gap <= EPS:
                    continue
                gaps[round(gap * 2) / 2.0] += 1
                gap_edges[(cell, other, side)] += 1
                if gap >= 0.25:
                    real_gaps.append((cell, side, other, start, stop,
                                      height_mine, height_theirs, gap))

    print("=== the vertical gap on every boundary of the chapter ===")
    print("intervals with a gap:", sum(gaps.values()))
    for gap, count in sorted(gaps.items()):
        print("  gap %4.1f : %d intervals" % (gap, count))
    print()

    # Which of them are on the edges that the module cannot build.
    ridge_gaps = [item for item in real_gaps
                  if item[0] in ridge or item[2] in ridge]
    print("=== the gaps on the edges with a cell without a flat patch ===")
    print("intervals:", len(ridge_gaps))
    heights = Counter()
    for item in ridge_gaps:
        heights[round(item[7] * 2) / 2.0] += 1
    for gap, count in sorted(heights.items()):
        print("  gap %4.1f : %d intervals" % (gap, count))
    print()
    print("=== the first fifteen of them ===")
    for cell, side, other, start, stop, height_mine, height_theirs, gap in ridge_gaps[:15]:
        print("%s %s -> %s  t %.3f..%.3f  %.3f vs %.3f  gap %.3f" % (
            str(cell), SIDE_NAMES[side], str(other), start, stop,
            height_mine, height_theirs, gap))
    print()
    cells = set()
    for cell, side, other, *_ in ridge_gaps:
        cells.add(cell)
        cells.add(other)
    print("cells that touch such an edge:", len(cells))


if __name__ == "__main__":
    main()
