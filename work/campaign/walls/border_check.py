"""The check of the new rule of the walls: no border of the chapter stays open.

The walls module builds the faces of the borders from the surface of the two
cells. This script is an independent implementation of the same rule and counts
the intervals of a border where the two surfaces differ and no face stands in
the gap. The number has to be zero: a border that differs and stays open is a
hole in the rock, and the scene shows the background of the map through it.

Usage:
    python work/campaign/walls/border_check.py [chapter.json]
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
MAP_WIDTH, MAP_HEIGHT = 512, 640


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
    """The flat profile and the surface profile of every cell and side."""
    meshes = data["meshes"]
    flat = {}
    surface = {}
    has_flat = set()
    for entry in data["cells"]:
        cell = (int(entry["x"]), int(entry["y"]))
        flat_sides = {side: [] for side in range(4)}
        surface_sides = {side: [] for side in range(4)}
        for points in triangles_of(meshes, int(entry["block"])):
            is_flat = flat_triangle(points)
            if is_flat:
                has_flat.add(cell)
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
        flat[cell] = flat_sides
        surface[cell] = surface_sides
    return flat, surface, has_flat


def neighbour(cell, side):
    x, y = cell
    return ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1))[side]


def opposite(side):
    return (SIDE_NEG_X, SIDE_POS_X, SIDE_NEG_Y, SIDE_POS_Y)[side]


def height_at(segments, position):
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
    flat, surface, has_flat = build(data)
    ground_level = max(
        max((segment[2] for segment in flat[cell][side]), default=-1.0)
        for cell in flat for side in range(4))

    inside = set(surface)
    # The faces of the module: the pair of the flat profiles and the new rule
    # of the borders. A border is closed when a face stands in its gap.
    faces = []
    for cell in surface:
        for side in range(4):
            other_cell = neighbour(cell, side)
            free = other_cell not in inside
            if free and not (0 <= other_cell[0] < MAP_WIDTH and 0 <= other_cell[1] < MAP_HEIGHT):
                continue
            here = surface[cell][side]
            if not here:
                continue
            if free:
                other = [(0.0, 1.0, ground_level, ground_level)]
                flat_other = [(0.0, 1.0, ground_level)]
            else:
                other = surface[other_cell][opposite(side)]
                flat_other = flat[other_cell][opposite(side)]
                if not other:
                    continue
            flat_here = flat[cell][side]
            marks = sorted({round(value, 4)
                            for segment in here + other + flat_here + flat_other
                            for value in (segment[0], segment[1])})
            for index in range(len(marks) - 1):
                start, stop = marks[index], marks[index + 1]
                if stop - start <= EPS:
                    continue
                middle = (start + stop) * 0.5
                level_here = height_at(here, middle)
                level_other = height_at(other, middle)
                if level_here is None or level_other is None:
                    continue
                if abs(level_here - level_other) < MIN_WALL_HEIGHT:
                    continue
                # The pair of the flat profiles builds the face where it can.
                flat_level_here = flat_level(flat_here, middle)
                flat_level_other = flat_level(flat_other, middle)
                if flat_level_here is not None and flat_level_other is not None \
                        and abs(flat_level_here - flat_level_other) >= MIN_WALL_HEIGHT:
                    faces.append((cell, side, start, stop))
                    continue
                if not free and level_here > level_other:
                    continue
                faces.append((cell, side, start, stop))

    # The borders that stay open: the two surfaces differ and no face stands
    # in the gap.
    open_intervals = []
    for cell in surface:
        for side in range(4):
            other_cell = neighbour(cell, side)
            free = other_cell not in inside
            if free and not (0 <= other_cell[0] < MAP_WIDTH and 0 <= other_cell[1] < MAP_HEIGHT):
                continue
            here = surface[cell][side]
            if not here:
                continue
            if free:
                other = [(0.0, 1.0, ground_level, ground_level)]
            else:
                other = surface[other_cell][opposite(side)]
                if not other:
                    continue
            marks = sorted({round(value, 4)
                            for segment in here + other for value in (segment[0], segment[1])})
            for index in range(len(marks) - 1):
                start, stop = marks[index], marks[index + 1]
                if stop - start <= EPS:
                    continue
                middle = (start + stop) * 0.5
                level_here = height_at(here, middle)
                level_other = height_at(other, middle)
                if level_here is None or level_other is None:
                    continue
                if abs(level_here - level_other) < MIN_WALL_HEIGHT:
                    continue
                covered = False
                for face_cell, face_side, face_start, face_stop in faces:
                    # The face belongs to the lower side of the border: it can
                    # stand on either side of it.
                    if face_cell == cell and face_side == side:
                        pass
                    elif (not free and face_cell == other_cell
                            and face_side == opposite(side)):
                        pass
                    else:
                        continue
                    if face_start - EPS <= middle and middle <= face_stop + EPS:
                        covered = True
                        break
                if not covered:
                    open_intervals.append((cell, side, other_cell, start, stop,
                                           level_here, level_other))

    print("=== the faces of the borders ===")
    print("faces:", len(faces))
    print()
    print("=== the borders that stay open ===")
    print("intervals:", len(open_intervals))
    heights = Counter()
    for item in open_intervals:
        heights[round(abs(item[5] - item[6]) * 2) / 2.0] += 1
    for gap, count in sorted(heights.items()):
        print("  gap %4.1f : %d intervals" % (gap, count))
    for item in open_intervals[:20]:
        print("%-14s %s -> %-14s t %.3f..%.3f  %6.3f / %6.3f" % (
            str(item[0]), SIDE_NAMES[item[1]], str(item[2]), item[3], item[4],
            item[5], item[6]))

    # --- the edges between a flat cell and a cell without a flat patch -------
    # The number of these edges is a property of the export, not of the module:
    # it stays the same after the fix. What changes is the number of them that
    # stay open, because the module builds the face of the border now.
    ridge = set(surface) - has_flat
    ridge_edges = []
    for cell in surface:
        if cell in ridge:
            continue
        for side in range(4):
            other_cell = neighbour(cell, side)
            if other_cell in ridge:
                ridge_edges.append((cell, side, other_cell))
    needed_edges = 0
    needed_intervals = 0
    open_on_them = 0
    for cell, side, other_cell in ridge_edges:
        here = surface[cell][side]
        other = surface[other_cell][opposite(side)]
        if not here or not other:
            continue
        marks = sorted({round(value, 4)
                        for segment in here + other
                        for value in (segment[0], segment[1])})
        gap_here = False
        for index in range(len(marks) - 1):
            start, stop = marks[index], marks[index + 1]
            if stop - start <= EPS:
                continue
            middle = (start + stop) * 0.5
            level_here = height_at(here, middle)
            level_other = height_at(other, middle)
            if level_here is None or level_other is None:
                continue
            if abs(level_here - level_other) < MIN_WALL_HEIGHT:
                continue
            gap_here = True
            needed_intervals += 1
        if gap_here:
            needed_edges += 1
    for item in open_intervals:
        if item[2] in ridge or item[0] in ridge:
            open_on_them += 1
    print()
    print("=== the edges between a flat cell and a cell without a flat patch ===")
    print("cells without a flat patch:", len(ridge))
    print("edges:", len(ridge_edges))
    print("of them the surfaces differ and a face is needed:", needed_edges)
    print("intervals that need a face:", needed_intervals)
    print("intervals that stay open:", open_on_them)


if __name__ == "__main__":
    main()
