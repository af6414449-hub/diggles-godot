#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The faces of the module of the dump at the cells of a point.

The dump of the module carries every face with its four corners in the space
of its cell, so the place of a face in the map can be printed and compared
with the geometry of the chapter.

Usage:
    python dump_face.py --dump FACES.json --cells 175,93;175,94

Read-only: it only reads the JSON dump of the module.
"""
import argparse
import json
import os
import sys


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--dump", required=True)
    parser.add_argument("--cells", required=True)
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.dump):
        print("missing: %s" % arguments.dump)
        return 1
    with open(arguments.dump, "r", encoding="utf-8") as handle:
        dump = json.load(handle)
    wanted = []
    for pair in arguments.cells.split(";"):
        x, y = (int(part) for part in pair.split(","))
        wanted.append((x, y))
    for face in dump["faces"]:
        cell = face["cell"]
        if (cell[0], cell[1]) not in wanted:
            continue
        corners = face["corners"]
        ys = sorted(set(round(float(corner[1]), 3) for corner in corners))
        zs = sorted(set(round(float(corner[2]), 3) for corner in corners))
        print("cell %s side %s  corners: %s" %
              (cell, face.get("side", "?"),
               " ".join("(%s,%s,%s)" % (round(float(c[0]), 2), round(float(c[1]), 2),
                                       round(float(c[2]), 2)) for c in corners)))
        print("      y of the corners: %s   z of the corners: %s" % (ys, zs))
        print("      map y from %s to %s, map z from %s to %s" %
              (cell[1] + ys[0], cell[1] + ys[-1], zs[0], zs[-1]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
