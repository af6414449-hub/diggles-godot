"""Light of the surface of the chapter: the attribute byte per level.

The port lights the terrain with the attribute byte of the cell
(native_terrain_illumination.base_byte). This script measures what byte the
surface of the chapter carries against the bytes of the underground, and how
many cells of the surface have no byte at all (attribute zero -> the mean 4).

Usage:
    python work/campaign/walls/surface_light.py
"""

import json
import os
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))))
CHAPTER = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")


def cell_levels(data):
    """The level (z) of every cell, taken from the vertices of its block."""
    meshes = data["meshes"]
    levels = {}
    for cell in data["cells"]:
        block = str(cell["block"])
        parts = meshes.get(block, [])
        values = []
        for part in parts:
            for index in range(0, len(part["vertices"]), 5):
                values.append(part["vertices"][index + 2])
        if values:
            levels[(cell["x"], cell["y"])] = max(values)
    return levels


def main():
    with open(CHAPTER, encoding="utf-8") as handle:
        data = json.load(handle)
    levels = cell_levels(data)
    attributes = data["attributes"]

    by_level = defaultdict(Counter)
    zero_by_level = Counter()
    for cell in data["cells"]:
        key = (cell["x"], cell["y"])
        level = levels.get(key)
        if level is None:
            continue
        value = cell.get("cell_attribute", 0)
        by_level[level][value] += 1
        if value == 0:
            zero_by_level[level] += 1

    print("=== attribute byte per level (level -> {byte: cells}) ===")
    for level in sorted(by_level, reverse=True):
        counter = by_level[level]
        total = sum(counter.values())
        zero = zero_by_level[level]
        top = ", ".join("%d:%d" % (byte, count)
                        for byte, count in counter.most_common(8))
        print("level %5.2f  cells=%5d  zero=%4d  %s" % (
            level, total, zero, top))

    print()
    print("=== cells with an attribute of their own (not zero) ===")
    have = sum(1 for cell in data["cells"] if cell.get("cell_attribute", 0) != 0)
    print("cells=%d  with byte=%d  zero=%d" % (
        len(data["cells"]), have, len(data["cells"]) - have))

    print()
    print("=== the bytes of the corner table (attributes) ===")
    counter = Counter()
    for key, value in attributes.items():
        counter[value] += 1
    for byte, count in counter.most_common(20):
        print("byte %3d : %5d cells" % (byte, count))

    print()
    print("=== surface cells (the most frequent level) ===")
    surface_level = Counter(levels.values()).most_common(1)[0][0]
    print("surface level =", surface_level)
    counter = by_level[surface_level]
    for byte, count in counter.most_common(20):
        print("byte %3d : %5d cells" % (byte, count))


if __name__ == "__main__":
    main()
