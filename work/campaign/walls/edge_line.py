#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Which edge of a wall of the module makes a thin dark line in a capture.

The module draws the vertical face of a cliff; the face has a top edge (at the
ground of the map) and a bottom edge (in the rock).  In a capture with a tilt
the two edges fall on different rows of the screen.  This tool projects the
faces of the module near a point of the screen and prints, for every one of
them, the rows of its top edge and of its bottom edge, so a thin dark line can
be attributed to one of them.  It also prints the tone of the frame with and
without the vertical faces of the export, so a line that survives --hide-vertical
is not drawn by the export.

Usage:
    python edge_line.py --dump FACES.json --image FRAME.png --image2 FRAME_NOVERT.png
        --chapter CHAPTER.json --x 530 --y 308 [--tilt 0.29] [--near 6]

Read-only: it only reads PNG files and the JSON dump of the module.
"""
import argparse
import json
import os
import sys

import numpy as np
from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import wall_screen  # noqa: E402


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--dump", required=True)
    parser.add_argument("--image", required=True)
    parser.add_argument("--image2", default="")
    parser.add_argument("--chapter", required=True)
    parser.add_argument("--x", type=int, required=True)
    parser.add_argument("--y", type=int, required=True)
    parser.add_argument("--tilt", type=float, default=0.29)
    parser.add_argument("--near", type=int, default=6)
    arguments = parser.parse_args()

    with open(arguments.dump, "r", encoding="utf-8") as handle:
        dump = json.load(handle)
    picture = Image.open(arguments.image).convert("RGB")
    size = picture.size
    array = np.asarray(picture).astype(np.float32)
    other = None
    if arguments.image2:
        other = np.asarray(Image.open(arguments.image2).convert("RGB")).astype(np.float32)

    framing = wall_screen.wide_camera(arguments.chapter, size, arguments.tilt)
    position, forward, axis_x, axis_y = wall_screen.camera(
        framing["focus_map"], framing["distance"], arguments.tilt, framing["yaw"])

    def screen_of(point):
        return wall_screen.to_screen(position, forward, axis_x, axis_y, point, size)

    print("point of the screen: (%d, %d)" % (arguments.x, arguments.y))
    if other is not None:
        export = np.abs(array - other).max(axis=2) > 6
        print("   the export draws a face there: %s" % bool(export[arguments.y, arguments.x]))

    close = []
    for face in dump["faces"]:
        cell = face["cell"]
        corners = face["corners"]
        points = []
        for corner in corners:
            world = (cell[0] + corner[0], -(cell[1] + corner[1]), corner[2])
            projected = screen_of(world)
            if projected is None:
                points = []
                break
            points.append(projected)
        if len(points) < 3:
            continue
        xs = [point[0] for point in points]
        ys = [point[1] for point in points]
        if not (min(xs) - arguments.near <= arguments.x <= max(xs) + arguments.near):
            continue
        if not (min(ys) - arguments.near <= arguments.y <= max(ys) + arguments.near):
            continue
        heights = [corner[2] for corner in corners]
        close.append((face, points, min(heights), max(heights)))
    print("faces of the module near that point: %d" % len(close))
    for face, points, low, high in close[:12]:
        top = [point for point, corner in zip(points, face["corners"]) if corner[2] == high]
        bottom = [point for point, corner in zip(points, face["corners"]) if corner[2] == low]
        top_y = float(np.mean([point[1] for point in top])) if top else float("nan")
        bottom_y = float(np.mean([point[1] for point in bottom])) if bottom else float("nan")
        print("   cell %s: top edge (z=%.2f) at rows %.1f..%.1f, bottom edge (z=%.2f) at rows %.1f..%.1f" %
              (face["cell"], high,
               min(point[1] for point in top) if top else -1,
               max(point[1] for point in top) if top else -1, low,
               min(point[1] for point in bottom) if bottom else -1,
               max(point[1] for point in bottom) if bottom else -1))

    luminance = 0.299 * array[:, :, 0] + 0.587 * array[:, :, 1] + 0.114 * array[:, :, 2]
    print("the column x=%d:" % arguments.x)
    for row in range(max(0, arguments.y - 8), min(size[1], arguments.y + 9)):
        line = "   y=%4d  lum %6.2f" % (row, float(luminance[row, arguments.x]))
        if other is not None:
            line += "   without the export %6.2f" % float(
                0.299 * other[row, arguments.x, 0] + 0.587 * other[row, arguments.x, 1]
                + 0.114 * other[row, arguments.x, 2])
        print(line)
    return 0


if __name__ == "__main__":
    sys.exit(main())
