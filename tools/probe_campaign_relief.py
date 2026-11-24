#!/usr/bin/env python3
"""Check the relief of one area of the chapter.

Prints the levels of the cells of an area, the level differences between
neighbours and the vertical faces the current algorithm builds, so the missing
geometry can be located in numbers instead of in a screenshot.

Usage:
  python tools/probe_campaign_relief.py 224 35 252 48
"""
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CHAPTER = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")
MIN_WALL_HEIGHT = 0.01


def dominant(entry, meshes):
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
    x0, y0, x1, y1 = (int(value) for value in sys.argv[1:5])
    with open(CHAPTER, "r", encoding="utf-8") as handle:
        chapter = json.load(handle)
    meshes = chapter["meshes"]
    levels = {}
    for entry in chapter["cells"]:
        levels[(int(entry["x"]), int(entry["y"]))] = dominant(entry, meshes)

    print("levels of the area (dominant level of every cell):")
    for y in range(y0, y1 + 1):
        row = []
        for x in range(x0, x1 + 1):
            value = levels.get((x, y))
            row.append("  --  " if value is None else "%5.1f " % value)
        print("%4d |%s|" % (y, "".join(row)))

    print()
    print("neighbour differences (right and down):")
    for y in range(y0, y1 + 1):
        for x in range(x0, x1 + 1):
            here = levels.get((x, y))
            if here is None:
                continue
            for dx, dy, name in ((1, 0, "E"), (0, 1, "S")):
                other = levels.get((x + dx, y + dy))
                if other is None:
                    print("  (%3d,%3d) %s -> free, face %5.1f .. %5.1f" % (x, y, name, here, 14.5))
                elif abs(other - here) >= MIN_WALL_HEIGHT:
                    print("  (%3d,%3d) %s  %5.1f -> %5.1f  face %5.1f" % (
                        x, y, name, here, other, abs(other - here)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
