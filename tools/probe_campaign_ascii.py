#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""ASCII maps of the exported campaign chapter.

Two views over res://models/native_campaign_chapter.json:
  levels   - the top surface of every cell of the chapter
  family   - the ground family (A granite / B / C dirt) of every cell

Both views are printed over the chapter bounding box, so the shape of the
level can be compared with the original templates without a renderer.
"""
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
DEFAULT = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")


def load(path):
    with open(path, "r", encoding="utf-8") as handle:
        return json.load(handle)


def cell_top(entry, meshes):
    """The highest z of the block of a cell, in BDB depth units."""
    parts = meshes.get(str(entry["block"]), [])
    top = None
    for part in parts:
        values = part["vertices"]
        for index in range(0, len(values), 5):
            z = values[index + 2]
            if top is None or z > top:
                top = z
    return top


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else DEFAULT
    chapter = load(path)
    meshes = chapter["meshes"]
    cells = chapter["cells"]

    xs = [entry["x"] for entry in cells]
    ys = [entry["y"] for entry in cells]
    x0, x1 = min(xs), max(xs)
    y0, y1 = min(ys), max(ys)

    levels = {}
    families = {}
    for entry in cells:
        key = (entry["x"], entry["y"])
        levels[key] = cell_top(entry, meshes)
        families[key] = entry.get("ground_family", "?")

    print("chapter bbox x %d..%d y %d..%d cells %d" % (x0, x1, y0, y1, len(cells)))

    legend = {}
    order = []
    for key, value in levels.items():
        if value is None:
            continue
        if value not in legend:
            legend[value] = "0123456789abcdefghijklmnopqrstuvwxyz"[len(legend)]
            order.append(value)
    for value in sorted(order, reverse=True):
        print("  level %-6s -> %s" % (value, legend[value]))

    print()
    print("LEVELS")
    header = "     " + "".join(str((x // 10) % 10) for x in range(x0, x1 + 1))
    header += "\n     " + "".join(str(x % 10) for x in range(x0, x1 + 1))
    print(header)
    for y in range(y0, y1 + 1):
        row = []
        for x in range(x0, x1 + 1):
            value = levels.get((x, y))
            row.append("." if value is None else legend[value])
        print("%4d %s" % (y, "".join(row)))

    print()
    print("FAMILY (A granite, B, C dirt, ? no cell)")
    print(header)
    for y in range(y0, y1 + 1):
        row = []
        for x in range(x0, x1 + 1):
            row.append(families.get((x, y), "."))
        print("%4d %s" % (y, "".join(row)))

    print()
    counts = {}
    for key, value in families.items():
        counts[value] = counts.get(value, 0) + 1
    print("family counts: %s" % sorted(counts.items()))
    level_counts = {}
    for key, value in levels.items():
        level_counts[value] = level_counts.get(value, 0) + 1
    print("level counts: %s" % sorted(level_counts.items(), key=lambda kv: -kv[1]))


if __name__ == "__main__":
    main()
