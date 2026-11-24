#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The level of the cells around a point of the map, and the faces of the module.

The module draws the vertical face of every step of the height field.  This
tool prints, for a window of cells of the map, the surface level of every cell
(the highest point of its block), the level of the floor of every cell (the
lowest point of its block) and the faces of the module that stand on them, so
a gap between the wall of the module and the floor of a cell can be seen.

Usage:
    python cell_levels.py --chapter CHAPTER.json --dump FACES.json
        --x 127 --y 84 [--w 3] [--h 3]

Read-only: it only reads JSON files.
"""
import argparse
import json
import sys


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--chapter", required=True)
    parser.add_argument("--dump", default="")
    parser.add_argument("--x", type=int, required=True)
    parser.add_argument("--y", type=int, required=True)
    parser.add_argument("--w", type=int, default=3)
    parser.add_argument("--h", type=int, default=3)
    arguments = parser.parse_args()

    with open(arguments.chapter, "r", encoding="utf-8") as handle:
        chapter = json.load(handle)
    blocks = {}
    for entry in chapter["cells"]:
        blocks[(int(entry["x"]), int(entry["y"]))] = int(entry["block"])
    levels = {}
    for (x, y), block in blocks.items():
        values = chapter["meshes"].get(str(block), [])
        high = None
        low = None
        for part in values:
            data = part["vertices"]
            for offset in range(2, len(data), 5):
                value = float(data[offset])
                high = value if high is None else max(high, value)
                low = value if low is None else min(low, value)
        levels[(x, y)] = (low, high)

    faces = {}
    if arguments.dump:
        with open(arguments.dump, "r", encoding="utf-8") as handle:
            dump = json.load(handle)
        for face in dump["faces"]:
            cell = face["cell"]
            faces.setdefault((cell[0], cell[1]), []).append(face)

    for y in range(arguments.y, arguments.y + arguments.h):
        for x in range(arguments.x, arguments.x + arguments.w):
            level = levels.get((x, y))
            if level is None:
                print("cell (%d,%d): free (no block in the export)" % (x, y))
            else:
                print("cell (%d,%d): block %d, floor z=%.2f, surface z=%.2f" %
                      (x, y, blocks[(x, y)], level[0], level[1]))
            for face in faces.get((x, y), []):
                heights = sorted({round(corner[2], 2) for corner in face["corners"]})
                print("      face side=%s  z=%s" % (face["side"], heights))
    return 0


if __name__ == "__main__":
    sys.exit(main())
