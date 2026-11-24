#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The surfaces of one block of the chapter.

The mesh of a block carries its parts with the stride of five values
(x, y, z, u, v) in the space of the cell.  This script prints every part of a
block with the range of its coordinates, so that the surfaces of a cell can be
read: the top, the slope and the bottom of a step.

Usage:
    python block_mesh.py --chapter CHAPTER.json --blocks 207;228;80

Read-only: it only reads the JSON of the chapter.
"""
import argparse
import json
import os
import sys


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--chapter", required=True)
    parser.add_argument("--blocks", required=True)
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.chapter):
        print("missing: %s" % arguments.chapter)
        return 1
    with open(arguments.chapter, "r", encoding="utf-8") as handle:
        chapter = json.load(handle)
    meshes = chapter.get("meshes", {})
    for item in arguments.blocks.split(";"):
        block = item.strip()
        parts = meshes.get(block, [])
        print("block %s: %d parts" % (block, len(parts)))
        for index, part in enumerate(parts):
            values = part["vertices"]
            count = len(values) // 5
            xs = [float(values[offset]) for offset in range(0, len(values), 5)]
            ys = [float(values[offset + 1]) for offset in range(0, len(values), 5)]
            zs = [float(values[offset + 2]) for offset in range(0, len(values), 5)]
            print("   part %d: %d vertices  x %.2f..%.2f  y %.2f..%.2f  z %.2f..%.2f" %
                  (index, count, min(xs), max(xs), min(ys), max(ys), min(zs), max(zs)))
            for row in range(count):
                start = row * 5
                print("      %8.3f %8.3f %8.3f   uv %8.3f %8.3f" %
                      (xs[row], ys[row], zs[row],
                       float(values[start + 3]), float(values[start + 4])))
        print()
    return 0


if __name__ == "__main__":
    sys.exit(main())
