#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The surface level of the chapter cells as a map.

The level of a cell is the highest point of its block (the same rule as
_native_campaign_first_level.gd:_cell_surface_level). The picture is printed
as text, so the shape of the excavations can be compared with a capture.

Read-only: it only reads the chapter.
"""
import argparse
import json
import sys


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--chapter", required=True)
    parser.add_argument("--x", type=int, default=0)
    parser.add_argument("--y", type=int, default=0)
    parser.add_argument("--w", type=int, default=40)
    parser.add_argument("--h", type=int, default=30)
    arguments = parser.parse_args()
    with open(arguments.chapter, "r", encoding="utf-8") as handle:
        chapter = json.load(handle)
    meshes = chapter["meshes"]
    levels = {}
    for entry in chapter["cells"]:
        highest = -1e9
        for part in meshes.get(str(int(entry["block"])), []):
            values = part["vertices"]
            for index in range(2, len(values), 5):
                highest = max(highest, float(values[index]))
        levels[(int(entry["x"]), int(entry["y"]))] = highest
    print("x %d..%d  y %d..%d" % (arguments.x, arguments.x + arguments.w - 1,
                                  arguments.y, arguments.y + arguments.h - 1))
    print("     " + "".join(str((arguments.x + column) // 10 % 10) for column in range(arguments.w)))
    print("     " + "".join(str((arguments.x + column) % 10) for column in range(arguments.w)))
    for row in range(arguments.y, arguments.y + arguments.h):
        line = ""
        for column in range(arguments.x, arguments.x + arguments.w):
            level = levels.get((column, row))
            if level is None:
                line += "."
            elif level >= 21.0:
                line += "#"
            elif level >= 19.0:
                line += "+"
            elif level >= 17.0:
                line += "o"
            elif level >= 15.0:
                line += "-"
            else:
                line += "_"
        print("%4d %s" % (row, line))
    return 0


if __name__ == "__main__":
    sys.exit(main())
