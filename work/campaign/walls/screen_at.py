#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The place of the map that is drawn at a point of a capture.

The camera of a capture is known from its flags, so the ray of every pixel can
be turned back into the point of the map.  The tool prints the map coordinates
of the pixels that are named, for the levels of the ground and of the floor of
the excavations, and the tone of the frame at every one of them.

Usage:
    python screen_at.py --image FRAME.png --points x,y[;x,y ...] [--wide]
        [--chapter CHAPTER.json] [--region x0,y0,x1,y1] [--distance 42.25]
        [--tilt 0.29] [--yaw 0.05] [--levels 14.5,12.5]

Read-only: it only reads PNG files and the JSON of the chapter.
"""
import argparse
import math
import os
import sys

import numpy as np
from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import wall_screen  # noqa: E402


def ray(position, forward, axis_x, axis_y, screen, size) -> tuple:
    """The direction of the world for one pixel of the picture."""
    width, height = size
    half_fov = math.radians(wall_screen.FOV_DEGREES) * 0.5
    aspect = float(width) / float(height)
    ndc_x = (screen[0] / float(width)) * 2.0 - 1.0
    ndc_y = 1.0 - (screen[1] / float(height)) * 2.0
    cx = ndc_x * aspect * math.tan(half_fov)
    cy = ndc_y * math.tan(half_fov)
    return tuple(axis_x[index] * cx + axis_y[index] * cy + forward[index]
                 for index in range(3))


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--image", required=True)
    parser.add_argument("--points", required=True, help="x,y of the pixels of the picture")
    parser.add_argument("--chapter", default="")
    parser.add_argument("--region", default="")
    parser.add_argument("--distance", type=float, default=42.25)
    parser.add_argument("--tilt", type=float, default=wall_screen.DEFAULT_TILT)
    parser.add_argument("--yaw", type=float, default=wall_screen.DEFAULT_YAW)
    parser.add_argument("--wide", action="store_true")
    parser.add_argument("--levels", default="14.5,12.5")
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.image):
        print("missing: %s" % arguments.image)
        return 1
    picture = Image.open(arguments.image).convert("RGB")
    size = picture.size
    array = np.asarray(picture).astype(np.float32)
    luminance = 0.299 * array[:, :, 0] + 0.587 * array[:, :, 1] + 0.114 * array[:, :, 2]
    if arguments.wide:
        if not arguments.chapter:
            print("--wide needs --chapter")
            return 1
        framing = wall_screen.wide_camera(arguments.chapter, size, arguments.tilt)
        focus_map = framing["focus_map"]
        distance = framing["distance"]
        yaw = framing["yaw"]
        print("wide camera: focus=(%.1f, %.1f) distance=%.2f yaw=%.3f tilt=%.3f (%.3f px per cell)" %
              (focus_map[0], focus_map[1], distance, yaw, arguments.tilt, framing["px_per_cell"]))
    else:
        if not arguments.region:
            print("--region is needed without --wide")
            return 1
        x0, y0, x1, y1 = (int(part) for part in arguments.region.split(","))
        focus_map = ((x0 + x1) * 0.5, (y0 + y1) * 0.5)
        distance = arguments.distance
        yaw = arguments.yaw
        print("camera: focus=(%.1f, %.1f) distance=%.2f yaw=%.3f tilt=%.3f" %
              (focus_map[0], focus_map[1], distance, yaw, arguments.tilt))
    position, forward, axis_x, axis_y = wall_screen.camera(
        focus_map, distance, arguments.tilt, yaw)
    levels = [float(part) for part in arguments.levels.split(",")]
    for item in arguments.points.split(";"):
        if not item.strip():
            continue
        sx, sy = (float(part) for part in item.split(","))
        direction = ray(position, forward, axis_x, axis_y, (sx, sy), size)
        column = int(round(sx))
        row = int(round(sy))
        tone = float(luminance[row, column]) if (0 <= row < size[1] and 0 <= column < size[0]) else float("nan")
        print("screen (%6.1f, %6.1f)  lum %6.2f" % (sx, sy, tone))
        for level in levels:
            if abs(direction[2]) < 1e-9:
                print("   level %.2f: the ray is parallel to the plane" % level)
                continue
            step = (level - position[2]) / direction[2]
            if step <= 0.0:
                print("   level %.2f: behind the camera" % level)
                continue
            world_x = position[0] + step * direction[0]
            world_y = position[1] + step * direction[1]
            print("   level %5.2f -> map (%8.3f, %8.3f)" % (level, world_x, -world_y))
    return 0


if __name__ == "__main__":
    sys.exit(main())
