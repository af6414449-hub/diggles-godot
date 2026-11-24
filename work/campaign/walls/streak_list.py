#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The long dark streaks of a capture and where they are.

The thin dark lines of the ground are found with a high pass, the connected
components are measured, and the long ones are printed with their box, so that
one of them can be cut out of the picture afterwards.

Usage:
    python streak_list.py FRAME.png [--box x0,y0,x1,y1] [--depth 6] [--top 20]
        [--min-length 8] [--px-per-cell 2.276]

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image
from scipy import ndimage


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("image")
    parser.add_argument("--box", default="")
    parser.add_argument("--depth", type=float, default=6.0)
    parser.add_argument("--blur", type=float, default=4.0)
    parser.add_argument("--top", type=int, default=20)
    parser.add_argument("--min-length", type=float, default=8.0)
    parser.add_argument("--px-per-cell", type=float, default=0.0)
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.image):
        print("missing: %s" % arguments.image)
        return 1
    tone = np.asarray(Image.open(arguments.image).convert("L")).astype(np.float32)
    origin = (0, 0)
    if arguments.box:
        x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
        origin = (x0, y0)
        tone = tone[y0:y1, x0:x1]
    background = ndimage.median_filter(tone, size=9, mode="nearest")
    noise = float(np.abs(tone - background).mean())
    threshold = max(3.0, noise + 1.5 * arguments.depth)
    marks = background - tone
    mask = marks > threshold
    labels, count = ndimage.label(mask, structure=np.ones((3, 3)))
    objects = ndimage.find_objects(labels)
    found = []
    for index, window in enumerate(objects):
        if window is None:
            continue
        rows = window[0].stop - window[0].start
        cols = window[1].stop - window[1].start
        area = int((labels[window] == index + 1).sum())
        if max(rows, cols) < arguments.min_length:
            continue
        if area < 4:
            continue
        ys, xs = np.where(labels[window] == index + 1)
        cy = float(ys.mean()) + window[0].start
        cx = float(xs.mean()) + window[1].start
        deep = float(marks[window][labels[window] == index + 1].max())
        found.append((max(rows, cols), rows, cols, area, cx + origin[0], cy + origin[1], deep))
    found.sort(key=lambda item: -item[0])
    print("%s region=%s  threshold=%.2f  streaks=%d" %
          (os.path.basename(arguments.image), arguments.box or "full", threshold, len(found)))
    print("%6s %6s %6s %6s %9s %9s %8s" %
          ("len", "rows", "cols", "area", "center x", "center y", "depth"))
    for length, rows, cols, area, cx, cy, deep in found[:arguments.top]:
        print("%6d %6d %6d %6d %9.1f %9.1f %8.2f" % (length, rows, cols, area, cx, cy, deep))
    if arguments.px_per_cell > 0.0:
        print("   one cell = %.3f px" % arguments.px_per_cell)
    return 0


if __name__ == "__main__":
    sys.exit(main())
