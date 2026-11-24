"""The walls of the cliffs, v4: one wall per step, full width, floor to surface.

The module of the walls builds a vertical face on the lower edge of every ramp of
the export. One ramp triangle gives one face, so a step that the exporter split
into several triangles gives several narrow plates with gaps between them: a row
of separate panels, and on the slopes of the rock of the map a field of pickets.

This script builds the faces the v4 way:

  1. the lower edges of the ramps are grouped by the plane they stand in, so a
     step is one group and not one face per triangle;
  2. the covered intervals of the plane are merged into one continuous wall,
     which is split only where the height of the crest changes;
  3. a step is a cliff when its foot is at the floor of the excavation and its
     crest is at the surface of the map: the slopes of the rock of the map are
     not excavations and get no wall;
  4. the threshold of the engine (a drop of 2.0 cells inside the cell) belongs
     to the step and not to a part of it, so a step that reaches it is drawn as
     a whole and has no gap.

Usage:
    python work/campaign/walls/cliff_v4.py
"""
import json
import pathlib
from collections import Counter, defaultdict

ROOT = pathlib.Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
EPS = 1e-4
CLIFF_HEIGHT = 2.0
MIN_WALL_HEIGHT = 0.25


def main() -> int:
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    meshes = chapter["meshes"]
    cells = chapter["cells"]

    groups = defaultdict(list)
    level_cells = defaultdict(set)
    skipped_border = 0
    for entry in cells:
        cell = (int(entry["x"]), int(entry["y"]))
        for part in meshes.get(str(int(entry["block"])), []):
            values = part["vertices"]
            indices = part["indices"]
            for start in range(0, len(indices), 3):
                points = []
                for corner in range(3):
                    offset = int(indices[start + corner]) * 5
                    points.append((float(values[offset]), float(values[offset + 1]),
                                   float(values[offset + 2])))
                low = min(p[2] for p in points)
                high = max(p[2] for p in points)
                if high - low <= EPS:
                    level_cells[round(low, 2)].add(cell)
                flat_x = all(abs(p[0] - points[0][0]) <= EPS for p in points)
                flat_y = all(abs(p[1] - points[0][1]) <= EPS for p in points)
                if flat_x or flat_y or high - low < EPS:
                    continue
                edge = None
                for corner in range(3):
                    a = points[corner]
                    b = points[(corner + 1) % 3]
                    if abs(a[2] - b[2]) > EPS or a[2] > low + EPS:
                        continue
                    edge = (a, b)
                    break
                if edge is None:
                    continue
                first, second = edge
                if abs(first[0] - second[0]) > EPS and abs(first[1] - second[1]) > EPS:
                    continue
                apex = [p for p in points if p is not first and p is not second][0]
                along_x = abs(first[1] - second[1]) <= EPS
                if along_x:
                    orientation, position = "y", first[1]
                    t0, t1 = min(first[0], second[0]), max(first[0], second[0])
                    sign = 1.0 if apex[1] > position else -1.0
                else:
                    orientation, position = "x", first[0]
                    t0, t1 = min(first[1], second[1]), max(first[1], second[1])
                    sign = 1.0 if apex[0] > position else -1.0
                if abs(position) <= EPS or abs(position - 1.0) <= EPS:
                    skipped_border += 1
                    continue
                if t1 - t0 <= EPS:
                    continue
                groups[(cell, orientation, round(position, 4), sign)].append(
                    (t0, t1, low, high))

    surface = max(level_cells)
    floor = max((level for level in level_cells if level < surface - EPS),
                key=lambda level: len(level_cells[level]))
    print("surface of the map: %.1f (%d cells)" % (surface, len(level_cells[surface])))
    print("floor of the excavation: %.1f (%d cells)" % (floor, len(level_cells[floor])))

    quads = []
    dropped_low = 0
    dropped_not_excavation = 0
    for key, items in groups.items():
        cell, orientation, position, sign = key
        step_drop = max(high - low for _, _, low, high in items)
        step_lower = min(low for _, _, low, high in items)
        step_upper = max(high for _, _, low, high in items)
        if step_drop < CLIFF_HEIGHT:
            dropped_low += 1
            continue
        if abs(step_lower - floor) > EPS or abs(step_upper - surface) > EPS:
            dropped_not_excavation += 1
            continue
        breaks = sorted(set([v for item in items for v in (item[0], item[1])]))
        for index in range(len(breaks) - 1):
            a, b = breaks[index], breaks[index + 1]
            if b - a <= EPS:
                continue
            middle = (a + b) * 0.5
            cover = [i for i in items if i[0] - EPS <= middle <= i[1] + EPS]
            if not cover:
                continue
            lower = min(i[2] for i in cover)
            upper = max(i[3] for i in cover)
            if upper - lower < MIN_WALL_HEIGHT:
                continue
            quads.append((cell, orientation, position, a, b, lower, upper))

    print()
    print("steps of the ramps: %d" % len(groups))
    print("feet on the border of the cell (the neighbour builds them): %d" % skipped_border)
    print("steps below the threshold of 2.0: %d" % dropped_low)
    print("steps that are not an edge of the excavation: %d" % dropped_not_excavation)
    print("faces of the v4 module: %d" % len(quads))
    print("cells with a face: %d" % len(set(q[0] for q in quads)))
    print()
    print("width of the face -> count: %s" % sorted(
        Counter(round(q[4] - q[3], 3) for q in quads).items()))
    print("drop of the face -> count: %s" % sorted(
        Counter(round(q[6] - q[5], 3) for q in quads).items()))
    narrow_tall = [q for q in quads
                   if (q[4] - q[3]) <= 0.25 + EPS and (q[6] - q[5]) >= 2.0 - EPS]
    print("narrow and tall faces (the pickets): %d" % len(narrow_tall))

    # the gaps that are left inside the wall of a step
    gaps = 0
    gap_length = 0.0
    for key, items in groups.items():
        cell, orientation, position, sign = key
        step_drop = max(high - low for _, _, low, high in items)
        step_lower = min(low for _, _, low, high in items)
        step_upper = max(high for _, _, low, high in items)
        if step_drop < CLIFF_HEIGHT:
            continue
        if abs(step_lower - floor) > EPS or abs(step_upper - surface) > EPS:
            continue
        breaks = sorted(set([v for item in items for v in (item[0], item[1])]))
        covered = []
        for index in range(len(breaks) - 1):
            a, b = breaks[index], breaks[index + 1]
            if b - a <= EPS:
                continue
            middle = (a + b) * 0.5
            cover = [i for i in items if i[0] - EPS <= middle <= i[1] + EPS]
            if not cover:
                continue
            lower = min(i[2] for i in cover)
            upper = max(i[3] for i in cover)
            if upper - lower < MIN_WALL_HEIGHT:
                continue
            covered.append((a, b))
        covered.sort()
        for index in range(len(covered) - 1):
            hole = covered[index + 1][0] - covered[index][1]
            if hole > EPS:
                gaps += 1
                gap_length += hole
    print("gaps inside the wall of a step: %d, total length %.3f cells" % (gaps, gap_length))

    # --- the same measure for the module before the fix ----------------------
    old = []
    for key, items in groups.items():
        cell, orientation, position, sign = key
        for t0, t1, low, high in items:
            if high - low < CLIFF_HEIGHT:
                continue
            old.append((cell, orientation, position, t0, t1, low, high))
    old_walls = defaultdict(list)
    for cell, orientation, position, t0, t1, low, high in old:
        old_walls[(cell, orientation, position)].append((t0, t1))
    old_gaps = 0
    old_gap_length = 0.0
    for key, spans in old_walls.items():
        spans.sort()
        for index in range(len(spans) - 1):
            hole = spans[index + 1][0] - spans[index][1]
            if hole > EPS:
                old_gaps += 1
                old_gap_length += hole
    print()
    print("the module before the fix:")
    print("   faces: %d" % len(old))
    print("   widths: %s" % sorted(Counter(round(f[4] - f[3], 3) for f in old).items()))
    print("   drops: %s" % sorted(Counter(round(f[6] - f[5], 3) for f in old).items()))
    print("   narrow and tall faces (the pickets): %d" % len(
        [f for f in old if (f[4] - f[3]) <= 0.25 + EPS and (f[6] - f[5]) >= 2.0 - EPS]))
    print("   gaps in the wall of a step: %d, total length %.3f cells" % (old_gaps, old_gap_length))
    print("   faces on the rock of the map: %d" % len(
        [f for f in old if abs(f[5] - floor) > EPS]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
