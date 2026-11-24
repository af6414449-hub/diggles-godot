"""The levels of the terrain of the chapter and the pairs of the steps.

The chapter has a surface and a floor of the excavation, and the walls of the
excavations separate them. This script counts the levels of the flat patches of
the cells and the pairs of the levels of the steps, so the rule that separates
the wall of an excavation from the slope of the rock of the map can be checked
against the data instead of a guess.

Usage:
    python work/campaign/walls/level_census.py
"""
import json
import pathlib
from collections import Counter

ROOT = pathlib.Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
EPS = 1e-4


def main() -> int:
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    meshes = chapter["meshes"]
    cells = chapter["cells"]
    materials = chapter["materials"]

    levels = Counter()
    cell_levels = {}
    for entry in cells:
        cell = (int(entry["x"]), int(entry["y"]))
        found = set()
        for part in meshes.get(str(int(entry["block"])), []):
            values = part["vertices"]
            indices = part["indices"]
            for start in range(0, len(indices), 3):
                points = []
                for corner in range(3):
                    offset = int(indices[start + corner]) * 5
                    points.append((float(values[offset]), float(values[offset + 1]),
                                   float(values[offset + 2])))
                if max(p[2] for p in points) - min(p[2] for p in points) > EPS:
                    continue
                found.add(round(points[0][2], 3))
        cell_levels[cell] = found
        for value in found:
            levels[value] += 1

    print("cells: %d" % len(cells))
    print("levels of the flat patches of the cells -> count of cells:")
    for value, count in sorted(levels.items(), key=lambda kv: -kv[1]):
        print("   %5.1f : %6d" % (value, count))

    # the pairs of the levels of the steps of the ramps
    pairs = Counter()
    for entry in cells:
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
                if high - low < 2.0 - EPS:
                    continue
                flat_x = all(abs(p[0] - points[0][0]) <= EPS for p in points)
                flat_y = all(abs(p[1] - points[0][1]) <= EPS for p in points)
                if flat_x or flat_y:
                    continue
                pairs[(round(low, 2), round(high, 2))] += 1

    print()
    print("pairs of the levels of the steps with a drop of 2.0 or more:")
    for (low, high), count in sorted(pairs.items(), key=lambda kv: -kv[1]):
        print("   %5.1f -> %5.1f : %5d" % (low, high, count))

    # the material of the cells of the steps
    print()
    by_material = Counter()
    for entry in cells:
        cell = (int(entry["x"]), int(entry["y"]))
        material = materials.get("%d,%d" % cell)
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
                if high - low < 2.0 - EPS:
                    continue
                flat_x = all(abs(p[0] - points[0][0]) <= EPS for p in points)
                flat_y = all(abs(p[1] - points[0][1]) <= EPS for p in points)
                if flat_x or flat_y:
                    continue
                by_material[(material, round(low, 2), round(high, 2))] += 1
    print("the material of the cell, the pair of the levels of the step -> count:")
    for (material, low, high), count in sorted(by_material.items(), key=lambda kv: -kv[1])[:25]:
        print("   material %s : %5.1f -> %5.1f : %5d" % (material, low, high, count))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
