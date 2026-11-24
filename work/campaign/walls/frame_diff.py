#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The difference between two captures inside one region.

Prints how many pixels of the region changed, how much the tone changed and
an ASCII map of the change, so that the feature that only one of the two
captures has can be seen at once.

Usage:
    python frame_diff.py A.png B.png [--box x0,y0,x1,y1] [--at x,y] [--radius 24]

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image

RAMP = "@%#*+=-:. "


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("first")
    parser.add_argument("second")
    parser.add_argument("--box", default="")
    parser.add_argument("--at", default="")
    parser.add_argument("--radius", type=int, default=24)
    arguments = parser.parse_args()
    for path in (arguments.first, arguments.second):
        if not os.path.isfile(path):
            print("missing: %s" % path)
            return 1
    first = np.asarray(Image.open(arguments.first).convert("L")).astype(np.float32)
    second = np.asarray(Image.open(arguments.second).convert("L")).astype(np.float32)
    if first.shape != second.shape:
        print("different sizes: %s vs %s" % (first.shape, second.shape))
        return 1
    if arguments.box:
        x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
    else:
        cx, cy = (int(part) for part in arguments.at.split(","))
        x0, y0 = cx - arguments.radius, cy - arguments.radius
        x1, y1 = cx + arguments.radius, cy + arguments.radius
    x0 = max(0, x0)
    y0 = max(0, y0)
    x1 = min(first.shape[1], x1)
    y1 = min(first.shape[0], y1)
    delta = second[y0:y1, x0:x1] - first[y0:y1, x0:x1]
    changed = np.abs(delta) > 3.0
    print("A=%s  B=%s  region=%d,%d..%d,%d" % (os.path.basename(arguments.first),
                                                os.path.basename(arguments.second),
                                                x0, y0, x1, y1))
    print("   changed pixels: %d of %d (%.1f %%)" %
          (int(changed.sum()), changed.size, 100.0 * changed.sum() / changed.size))
    print("   mean delta: %+.2f  min: %+.2f  max: %+.2f" %
          (delta.mean(), delta.min(), delta.max()))
    print()
    print("ASCII of the change (space = no change, else the tone of B):")
    print("     " + "".join(str((x // 10) % 10) for x in range(x0, x1)))
    print("     " + "".join(str(x % 10) for x in range(x0, x1)))
    tone = second[y0:y1, x0:x1]
    for row in range(tone.shape[0]):
        line = "".join(RAMP[min(9, int(value / 25.6))] if changed[row, col] else " "
                       for col, value in enumerate(tone[row]))
        print("%4d %s" % (y0 + row, line))
    return 0


if __name__ == "__main__":
    sys.exit(main())
