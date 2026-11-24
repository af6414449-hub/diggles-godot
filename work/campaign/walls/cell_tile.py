#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The tile of the ground of a cell of the chapter.

Prints the record of the chapter for a few cells: the parts of the cell, its
height levels and the tile of the ground that the atlas gives for it.

Usage:
    python cell_tile.py --chapter PATH [--cells 127,85;127,84;126,85] [--atlas]

Read-only: it only reads the JSON of the chapter.
"""
import argparse
import json
import os
import sys


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--chapter", required=True)
    parser.add_argument("--cells", default="127,85;127,84;126,85")
    parser.add_argument("--atlas", action="store_true")
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.chapter):
        print("missing: %s" % arguments.chapter)
        return 1
    with open(arguments.chapter, encoding="utf-8") as handle:
        chapter = json.load(handle)
    atlas = chapter.get("atlas", {})
    if arguments.atlas:
        print("atlas keys: %s" % list(atlas.keys()))
        for key, value in atlas.items():
            if isinstance(value, list):
                print("  %s: list of %d, first: %s" % (key, len(value), value[:3]))
            elif isinstance(value, dict):
                items = list(value.items())[:8]
                print("  %s: dict of %d, first: %s" % (key, len(value), items))
            else:
                print("  %s: %r" % (key, value))
        print()
    cells = chapter.get("cells", {})
    print("cells type: %s" % type(cells).__name__)
    wanted = []
    for pair in arguments.cells.split(";"):
        x, y = (int(part) for part in pair.split(","))
        wanted.append((x, y))
    if isinstance(cells, list):
        print("cells count: %d" % len(cells))
        print("first record: %s" % json.dumps(cells[0])[:600])
        for record in cells:
            if not isinstance(record, dict):
                continue
            x = record.get("x")
            y = record.get("y")
            if (x, y) in wanted:
                print("cell %d,%d -> %s" % (x, y, json.dumps(record)[:1200]))
        return 0
    keys = list(cells.keys())[:3]
    print("cells keys sample: %s" % keys)
    for key in keys:
        print("  %s -> %s" % (key, json.dumps(cells[key])[:400]))
    for pair in arguments.cells.split(";"):
        x, y = (int(part) for part in pair.split(","))
        found = None
        for key in ("%d,%d" % (x, y), "%d %d" % (x, y), "%d:%d" % (x, y),
                    str(x), str(y)):
            if key in cells:
                found = cells[key]
                break
        if found is None:
            print("cell %d,%d: not found by a direct key" % (x, y))
            continue
        print("cell %d,%d -> %s" % (x, y, json.dumps(found)[:900]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
