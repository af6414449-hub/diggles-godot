#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The pixel structure of the dark rim under the wall of a dig.

Prints an ASCII map of the luminance of the capture around the point of the
dark line, the row profile through the line and the row profile of a column,
so that the width and the depth of the dark band can be read off.

Usage:
    python rim_ascii.py FRAME.png [--box x0,y0,x1,y1] [--at x,y] [--radius 24]

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
    parser.add_argument("image")
    parser.add_argument("--box", default="")
    parser.add_argument("--at", default="")
    parser.add_argument("--radius", type=int, default=24)
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.image):
        print("missing: %s" % arguments.image)
        return 1
    tone = np.asarray(Image.open(arguments.image).convert("L")).astype(np.float32)
    if arguments.box:
        x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
    elif arguments.at:
        cx, cy = (int(part) for part in arguments.at.split(","))
        x0, y0 = cx - arguments.radius, cy - arguments.radius
        x1, y1 = cx + arguments.radius, cy + arguments.radius
    else:
        print("need --box or --at")
        return 1
    x0 = max(0, x0)
    y0 = max(0, y0)
    x1 = min(tone.shape[1], x1)
    y1 = min(tone.shape[0], y1)
    patch = tone[y0:y1, x0:x1]
    print("%s region=%d,%d..%d,%d size=%dx%d" % (os.path.basename(arguments.image),
                                                 x0, y0, x1, y1,
                                                 patch.shape[1], patch.shape[0]))
    print()
    header = "     " + "".join(str((x // 10) % 10) for x in range(x0, x1))
    header2 = "     " + "".join(str(x % 10) for x in range(x0, x1))
    print(header)
    print(header2)
    for row in range(patch.shape[0]):
        line = "".join(RAMP[min(9, int(value / 25.6))] for value in patch[row])
        print("%4d %s" % (y0 + row, line))
    print()
    print("row profile (mean per row):")
    for row in range(patch.shape[0]):
        values = patch[row]
        print("   y=%4d  min=%6.2f  mean=%6.2f  max=%6.2f" %
              (y0 + row, values.min(), values.mean(), values.max()))
    print()
    print("column profile (mean per column):")
    for col in range(patch.shape[1]):
        values = patch[:, col]
        print("   x=%4d  min=%6.2f  mean=%6.2f  max=%6.2f" %
              (x0 + col, values.min(), values.mean(), values.max()))
    return 0


if __name__ == "__main__":
    sys.exit(main())
