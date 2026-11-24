#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Check the projection of the native view against a capture.

The chapter cells are projected with the camera of the native set_view command
and drawn over the capture. If the projection is right, the contour of the
chapter lands on the island of the frame.

Read-only: it only reads the chapter and a PNG.
"""
import argparse
import json
import math
import os
import sys

import numpy as np
from PIL import Image, ImageDraw

FOCUS_X = 246.7
FOCUS_Y = 28.8
ZOOM = 1.478
RX = -0.29
RY = 0.05
FOV_DEGREES = 38.0
VISIBLE_HEIGHT_AT_ZOOM_ONE = 43.0
GROUND_LEVEL = 14.5


def camera() -> tuple:
    visible_height = VISIBLE_HEIGHT_AT_ZOOM_ONE / ZOOM
    half_fov = math.radians(FOV_DEGREES) * 0.5
    distance = visible_height / (2.0 * math.tan(half_fov))
    tilt = -RX
    yaw = RY
    offset = (math.sin(yaw) * math.cos(tilt), math.sin(tilt),
              math.cos(yaw) * math.cos(tilt))
    position = (FOCUS_X + offset[0] * distance, -FOCUS_Y + offset[1] * distance,
                GROUND_LEVEL + offset[2] * distance)
    z = (position[0] - FOCUS_X, position[1] + FOCUS_Y, position[2] - GROUND_LEVEL)
    length = math.sqrt(sum(value * value for value in z))
    z = tuple(value / length for value in z)
    x = (z[2], 0.0, -z[0])
    length = math.hypot(x[0], x[2])
    x = (x[0] / length, 0.0, x[2] / length)
    y = (z[1] * x[2] - z[2] * x[1], z[2] * x[0] - z[0] * x[2], z[0] * x[1] - z[1] * x[0])
    forward = (-z[0], -z[1], -z[2])
    return position, forward, x, y


def project(position, forward, x_axis, y_axis, point, size):
    width, height = size
    half_fov = math.radians(FOV_DEGREES) * 0.5
    aspect = float(width) / float(height)
    direction = tuple(point[index] - position[index] for index in range(3))
    length = math.sqrt(sum(value * value for value in direction))
    direction = tuple(value / length for value in direction)
    # The components of the direction in the basis of the camera: the camera
    # looks along its forward axis, which is the -Z of the basis of Godot.
    cz = sum(direction[index] * forward[index] for index in range(3))
    cx = sum(direction[index] * x_axis[index] for index in range(3))
    cy = sum(direction[index] * y_axis[index] for index in range(3))
    if cz <= 1e-6:
        return None
    ndc_x = cx / cz / (aspect * math.tan(half_fov))
    ndc_y = cy / cz / math.tan(half_fov)
    return ((ndc_x + 1.0) * 0.5 * width, (1.0 - ndc_y) * 0.5 * height)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--chapter", required=True)
    parser.add_argument("--frame", required=True)
    parser.add_argument("--out", required=True)
    parser.add_argument("--cells", type=int, default=0, help="0 = all")
    arguments = parser.parse_args()
    with open(arguments.chapter, "r", encoding="utf-8") as handle:
        chapter = json.load(handle)
    meshes = chapter["meshes"]

    def top_level(entry) -> float:
        highest = -1e9
        for part in meshes.get(str(int(entry["block"])), []):
            values = part["vertices"]
            for index in range(2, len(values), 5):
                highest = max(highest, float(values[index]))
        return highest

    frame = Image.open(arguments.frame).convert("RGB")
    draw = ImageDraw.Draw(frame)
    position, forward, x_axis, y_axis = camera()
    size = frame.size
    entries = chapter["cells"]
    if arguments.cells:
        entries = entries[:arguments.cells]
    drawn = 0
    for entry in entries:
        cx = float(entry["x"])
        cy = float(entry["y"])
        level = top_level(entry)
        corners = [(cx, cy, level), (cx + 1.0, cy, level),
                   (cx + 1.0, cy + 1.0, level), (cx, cy + 1.0, level)]
        points = []
        for world_x, world_y, world_z in corners:
            screen = project(position, forward, x_axis, y_axis,
                             (world_x, -world_y, world_z), size)
            if screen is None:
                points = []
                break
            points.append(screen)
        if len(points) != 4:
            continue
        draw.polygon(points, outline=(255, 0, 0))
        drawn += 1
    frame.save(arguments.out)
    print("cells drawn: %d  ->  %s" % (drawn, arguments.out))
    return 0


if __name__ == "__main__":
    sys.exit(main())
