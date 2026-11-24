#!/usr/bin/env python3
"""ASCII height map of the exported campaign chapter.

Prints the level of every exported cell as a character grid so the shape of
the chapter (surface plateaus, tunnels, borders) can be read without a render.

Usage:
  python tools/probe_campaign_levels.py [--full]
"""
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CHAPTER = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")

SYMBOLS = {
    14.5: "#",   # untouched rock surface
    12.5: "-",   # step
    7.0: ".",    # tunnel floor
}


def dominant_level(entry, meshes):
    """The level of the largest patch of a cell, in native units."""
    parts = meshes.get(str(entry["block"]), [])
    areas = {}
    for part in parts:
        values = part["vertices"]
        indices = part["indices"]
        for start in range(0, len(indices), 3):
            pts = []
            for corner in range(3):
                offset = int(indices[start + corner]) * 5
                pts.append((float(values[offset]), float(values[offset + 1]),
                            float(values[offset + 2])))
            ax, ay, _ = pts[0]
            bx, by, _ = pts[1]
            cx, cy, _ = pts[2]
            area = abs((bx - ax) * (cy - ay) - (by - ay) * (cx - ax)) * 0.5
            if area <= 0.0001:
                continue
            key = round(pts[0][2], 2)
            areas[key] = areas.get(key, 0.0) + area
    if not areas:
        return None
    return max(areas.items(), key=lambda item: item[1])[0]


def main():
    with open(CHAPTER, "r", encoding="utf-8") as handle:
        chapter = json.load(handle)
    meshes = chapter["meshes"]
    cells = chapter["cells"]
    size = chapter["map_size"]
    width, height = int(size["width"]), int(size["height"])

    levels = {}
    all_levels = {}
    for entry in cells:
        level = dominant_level(entry, meshes)
        levels[(int(entry["x"]), int(entry["y"]))] = level
        all_levels[level] = all_levels.get(level, 0) + 1

    xs = [key[0] for key in levels]
    ys = [key[1] for key in levels]
    box = (min(xs), min(ys), max(xs), max(ys))
    print("map %dx%d  cells %d  bbox x %d..%d y %d..%d" %
          (width, height, len(cells), box[0], box[2], box[1], box[3]))
    print("levels (level: cells):")
    for level in sorted(all_levels, reverse=True):
        print("  %8.2f : %d" % (level, all_levels[level]))

    # how many cells of the chapter touch a free cell (no exported neighbour)
    free_neighbours = 0
    for (cx, cy) in levels:
        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            if (cx + dx, cy + dy) not in levels:
                free_neighbours += 1
                break
    print("cells with a free neighbour: %d of %d" % (free_neighbours, len(levels)))

    print()
    print("ASCII map (one char per cell, # surface, - step, . tunnel, space free):")
    for y in range(box[1], box[3] + 1):
        row = []
        for x in range(box[0], box[2] + 1):
            level = levels.get((x, y))
            if level is None:
                row.append(" ")
            else:
                row.append(SYMBOLS.get(round(level, 2), "?"))
        print("%4d |%s|" % (y, "".join(row)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
