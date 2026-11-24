"""The wall against a cell without a flat patch.

A cell of the chapter whose mesh carries no horizontal patch (a steep slope
inside one cell) has no flat profile, so the wall module cannot build a face
against it and the four neighbours of such a cell keep a hole in their wall.

This script reads the geometry of those cells, takes the height of the slope
along the shared boundary from the triangles that touch the boundary, and
computes the faces that close the gap.

Usage:
    python work/campaign/walls/ridge_walls.py [chapter.json]
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
    """The side of the cell an edge lies on, or -1."""
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


def side_of_point(point, side):
    if side == SIDE_POS_X:
        return abs(point[0] - 1.0) <= EPS
    if side == SIDE_NEG_X:
        return abs(point[0]) <= EPS
    if side == SIDE_POS_Y:
        return abs(point[1] - 1.0) <= EPS
    return abs(point[1]) <= EPS


def build_profiles(data):
    """The flat profile and the boundary polyline of every cell and side."""
    meshes = data["meshes"]
    flat = {}
    poly = {}
    ridge = []
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
            ridge.append(cell)
    return flat, poly, ridge


def neighbour(cell, side):
    x, y = cell
    return ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1))[side]


def opposite(side):
    return (SIDE_NEG_X, SIDE_POS_X, SIDE_NEG_Y, SIDE_POS_Y)[side]


def level_at(segments, position):
    """The height of a profile at a position (the highest patch wins)."""
    level = None
    for segment in segments:
        t0, t1 = segment[0], segment[1]
        if position >= t0 - EPS and position <= t1 + EPS:
            value = segment[2]
            if level is None or value > level:
                level = value
    return level


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else CHAPTER
    with open(path, encoding="utf-8") as handle:
        data = json.load(handle)
    flat, poly, ridge = build_profiles(data)
    ridge_set = set(ridge)

    print("=== cells without a flat patch ===")
    print("count:", len(ridge))
    print()

    # The edges where a face cannot be built today.
    blocked = 0
    blocked_detail = Counter()
    for cell in flat:
        if cell in ridge_set:
            continue
        for side in range(4):
            other = neighbour(cell, side)
            if other not in flat or other in ridge_set:
                if other in ridge_set:
                    blocked += 1
                    blocked_detail[other] += 1
    print("=== edges without a face today ===")
    print("edges:", blocked, " source cells:", len(blocked_detail))
    print("most common:", ", ".join("%s=%d" % (c, n)
                                    for c, n in blocked_detail.most_common(5)))
    print()

    # The faces the fix would build.
    faces = 0
    segments_total = 0
    heights = Counter()
    ridge_neighbour_ridge = 0
    for cell in ridge:
        for side in range(4):
            other = neighbour(cell, side)
            if other not in flat:
                continue
            if other in ridge_set:
                ridge_neighbour_ridge += 1
                continue
            mine = poly[cell][side]
            theirs = flat[other][opposite(side)]
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
                level_mine = level_at(mine, middle)
                level_theirs = level_at(theirs, middle)
                if level_mine is None or level_theirs is None:
                    continue
                if abs(level_mine - level_theirs) < 0.25:
                    continue
                faces += 1
                segments_total += 1
                heights[round(abs(level_mine - level_theirs) * 2) / 2.0] += 1
    print("=== the faces the fix would build ===")
    print("faces:", faces)
    print("edges where both cells are ridges (still open):", ridge_neighbour_ridge)
    print("the height of the faces:", dict(sorted(heights.items())))
    print()

    print("=== the geometry of the first five ridge cells ===")
    for cell in ridge[:5]:
        print("--- cell %s ---" % (str(cell),))
        for side in range(4):
            other = neighbour(cell, side)
            mine = poly[cell][side]
            theirs = flat[other][opposite(side)] if other in flat else []
            print("  side %d neighbour %s" % (side, str(other)))
            print("    slope on the boundary : %s" % (
                ", ".join("(%.3f..%.3f %.3f->%.3f)" % segment for segment in mine) or "none"))
            print("    flat of the neighbour  : %s" % (
                ", ".join("(%.3f..%.3f %.3f)" % segment for segment in theirs) or "none"))


if __name__ == "__main__":
    main()
