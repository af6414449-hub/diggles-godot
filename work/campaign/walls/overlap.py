"""Are the faces of the cliffs the same faces as the export carries?

The scene draws two sets of vertical faces: the ones that the export carries in
the meshes of the blocks (9851 in the chapter, all of them in the planes
y = const) and the ones that the walls module rebuilds on the steps of the
ramps. This script puts the two sets on one grid and counts how much they
overlap, so the attribution of the remaining panels is a measured fact and not
an opinion.

Usage:
    python work/campaign/walls/overlap.py
"""
import json
import pathlib
from collections import Counter

ROOT = pathlib.Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
EPS = 1e-4
CLIFF_HEIGHT = 2.0
MIN_WALL_HEIGHT = 0.25


def main() -> int:
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    meshes = chapter["meshes"]
    cells = chapter["cells"]

    exported = []       # (cell, orientation, position, t0, t1)
    feet = []           # the steps of the ramps
    level_cells = Counter()
    for entry in cells:
        cell = (int(entry["x"]), int(entry["y"]))
        cell_levels = set()
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
                    cell_levels.add(round(low, 2))
                    continue
                flat_x = all(abs(p[0] - points[0][0]) <= EPS for p in points)
                flat_y = all(abs(p[1] - points[0][1]) <= EPS for p in points)
                if flat_x or flat_y:
                    # a vertical face of the export: its plane and its extent
                    if flat_x:
                        position = points[0][0]
                        ts = [p[1] for p in points]
                    else:
                        position = points[0][1]
                        ts = [p[0] for p in points]
                    exported.append((cell, "x" if flat_x else "y", round(position, 4),
                                     min(ts), max(ts)))
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
                    position = first[1]
                    t0, t1 = min(first[0], second[0]), max(first[0], second[0])
                    sign = 1.0 if apex[1] > position else -1.0
                else:
                    position = first[0]
                    t0, t1 = min(first[1], second[1]), max(first[1], second[1])
                    sign = 1.0 if apex[0] > position else -1.0
                if abs(position) <= EPS or abs(position - 1.0) <= EPS:
                    continue
                if t1 - t0 <= EPS:
                    continue
                feet.append((cell, "y" if along_x else "x", round(position, 4), sign,
                             t0, t1, low, high))
        for value in cell_levels:
            level_cells[value] += 1

    surface = max(level_cells)
    floor = max((level for level in level_cells if level < surface - EPS),
                key=lambda level: level_cells[level])

    # the faces of the module v4
    groups = {}
    for cell, orientation, position, sign, t0, t1, low, high in feet:
        groups.setdefault((cell, orientation, position, sign), []).append((t0, t1, low, high))
    mine = []
    for (cell, orientation, position, sign), items in groups.items():
        step_drop = max(high - low for _, _, low, high in items)
        step_lower = min(low for _, _, low, high in items)
        if step_drop < CLIFF_HEIGHT or abs(step_lower - floor) > EPS:
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
            mine.append((cell, orientation, position, a, b))

    print("the vertical faces of the export: %d" % len(exported))
    print("   their planes: %s" % sorted(Counter(e[1] for e in exported).items()))
    print("the faces of the module v4: %d" % len(mine))
    print("   their planes: %s" % sorted(Counter(m[1] for m in mine).items()))

    # the same place: the same cell, the same plane, the same position
    exported_keys = Counter((e[0], e[1], e[2]) for e in exported)
    mine_keys = Counter((m[0], m[1], m[2]) for m in mine)
    shared = set(exported_keys) & set(mine_keys)
    print()
    print("the places where both sets stand: %d" % len(shared))
    same_place = sum(min(exported_keys[k], mine_keys[k]) for k in shared)
    print("   the faces that share the place: %d" % same_place)
    print("   the faces of the export that stand on the floor of the excavation: %d" % sum(
        1 for e in exported if abs(e[0][0]) >= 0))
    print("   the planes of the export at the floor of the excavation: %s" % sorted(
        Counter(e[1] for e in exported if e[2] in (0.25, 0.375, 0.5, 0.625, 0.75)).items()))

    # how many of the export's faces stand where the floor of the excavation is
    by_position = Counter(e[2] for e in exported)
    print("   the positions of the planes of the export (the 12 most common): %s" % sorted(
        by_position.items(), key=lambda kv: -kv[1])[:12])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
