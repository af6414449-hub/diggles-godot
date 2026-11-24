#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The tone per row across a wall of the excavation.

The corridor of the original has three parts one under another: the vertical
face of the excavation, a dark strip at its base and the floor.  The profile of
the tone across the rows shows the three of them and the width of the dark
strip, so the picture of the original and the picture of the port can be
compared by the same numbers.

Usage:
    python row_profile.py FRAME.png --box x0,y0,x1,y1 [--from-row 0] [--to-row 0]

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("image")
    parser.add_argument("--box", required=True, help="x0,y0,x1,y1")
    parser.add_argument("--from-row", type=int, default=0)
    parser.add_argument("--to-row", type=int, default=0)
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.image):
        print("missing: %s" % arguments.image)
        return 1
    array = np.asarray(Image.open(arguments.image).convert("RGB")).astype(np.float32)
    x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
    region = array[y0:y1, x0:x1]
    luminance = 0.299 * region[:, :, 0] + 0.587 * region[:, :, 1] + 0.114 * region[:, :, 2]
    warmth = region[:, :, 0] - region[:, :, 2]
    rows = region.shape[0]
    first = arguments.from_row if arguments.from_row > 0 else 0
    last = arguments.to_row if arguments.to_row > 0 else rows
    first = max(0, min(first, rows - 1))
    last = max(first + 1, min(last, rows))
    print("%s region=%s rows %d..%d" % (os.path.basename(arguments.image), arguments.box,
                                         y0 + first, y0 + last))
    print("   row   lum     R-B     sd")
    for index in range(first, last):
        line = luminance[index]
        print("  %4d  %6.2f  %+6.2f  %5.2f" % (y0 + index, line.mean(),
                                                warmth[index].mean(), line.std()))
    return 0


if __name__ == "__main__":
    sys.exit(main())
