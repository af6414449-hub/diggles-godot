#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The world points of a capture and the tone of the frame at their place.

The camera of a capture is known from its flags, so a point of the map can be
placed on the screen and the tone of the picture at that place can be read.
This is the way to find what is drawn at a given cell of the map.

Usage:
    python point_at.py --image FRAME.png --region x0,y0,x1,y1 [--distance 42.25]
        [--chapter CHAPTER.json] [--wide]
        --points x,y,z[,x,y,z ...] [--box 0,0,0,0]

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import wall_screen  # noqa: E402


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--image", required=True)
    parser.add_argument("--region", default="")
    parser.add_argument("--distance", type=float, default=42.25)
    parser.add_argument("--tilt", type=float, default=0.29)
    parser.add_argument("--yaw", type=float, default=0.05)
    parser.add_argument("--chapter", default="")
    parser.add_argument("--wide", action="store_true")
    parser.add_argument("--points", required=True,
                        help="x,y,z of the points of the map, separated by semicolons")
    parser.add_argument("--box", default="", help="x0,y0,x1,y1 of the map to measure")
    arguments = parser.parse_args()

    picture = Image.open(arguments.image).convert("RGB")
    size = picture.size
    array = np.asarray(picture).astype(np.float32)
    luminance = 0.299 * array[:, :, 0] + 0.587 * array[:, :, 1] + 0.114 * array[:, :, 2]

    if arguments.wide:
        framing = wall_screen.wide_camera(arguments.chapter, size, arguments.tilt)
        focus_map = framing["focus_map"]
        distance = framing["distance"]
        yaw = framing["yaw"]
    else:
        x0, y0, x1, y1 = (int(part) for part in arguments.region.split(","))
        focus_map = ((x0 + x1) * 0.5, (y0 + y1) * 0.5)
        distance = arguments.distance
        yaw = arguments.yaw
    position, forward, axis_x, axis_y = wall_screen.camera(
        focus_map, distance, arguments.tilt, yaw)
    print("camera: focus=(%.1f, %.1f) distance=%.2f tilt=%.3f yaw=%.3f" %
          (focus_map[0], focus_map[1], distance, arguments.tilt, yaw))

    for item in arguments.points.split(";"):
        if not item.strip():
            continue
        px, py, pz = (float(part) for part in item.split(","))
        world = (px, -py, pz)
        screen = wall_screen.to_screen(position, forward, axis_x, axis_y, world, size)
        if screen is None:
            print("map (%.2f, %.2f, %.2f): behind the camera" % (px, py, pz))
            continue
        row = int(round(screen[1]))
        column = int(round(screen[0]))
        if 0 <= row < size[1] and 0 <= column < size[0]:
            tone = float(luminance[row, column])
        else:
            tone = float("nan")
        print("map (%.2f, %.2f, %.2f) -> screen (%6.1f, %6.1f)  lum %s" %
              (px, py, pz, screen[0], screen[1],
               ("%6.2f" % tone) if tone == tone else "off frame"))

    if arguments.box:
        bx0, by0, bx1, by1 = (int(part) for part in arguments.box.split(","))
        corners = []
        for px in (bx0, bx1):
            for py in (by0, by1):
                for pz in (12.5, 14.5):
                    screen = wall_screen.to_screen(position, forward, axis_x, axis_y,
                                                  (px, -py, pz), size)
                    if screen:
                        corners.append(screen)
        if corners:
            left = min(point[0] for point in corners)
            right = max(point[0] for point in corners)
            top = min(point[1] for point in corners)
            bottom = max(point[1] for point in corners)
            region = luminance[int(top):int(bottom) + 1, int(left):int(right) + 1]
            print("the box of the map %s -> screen x %.1f..%.1f, y %.1f..%.1f" %
                  ((bx0, by0, bx1, by1), left, right, top, bottom))
            if region.size:
                print("   tone of the frame there: mean %.2f, min %.2f, max %.2f" %
                      (float(region.mean()), float(region.min()), float(region.max())))
    return 0


if __name__ == "__main__":
    sys.exit(main())
