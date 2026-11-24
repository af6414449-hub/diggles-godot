#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The scale of the native view: pixels per cell, and the map area of a box.

The forward projection of the camera of the native set_view command is used to
find how many pixels one cell of the map takes on the screen, and the inverse
projection gives the area of the map that a rectangle of the frame covers.
"""
import argparse
import math
import sys

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
    return position, forward, x, y, distance


def to_screen(position, forward, x_axis, y_axis, point, size) -> tuple:
    width, height = size
    half_fov = math.radians(FOV_DEGREES) * 0.5
    aspect = float(width) / float(height)
    direction = tuple(point[index] - position[index] for index in range(3))
    length = math.sqrt(sum(value * value for value in direction))
    direction = tuple(value / length for value in direction)
    cz = sum(direction[index] * forward[index] for index in range(3))
    cx = sum(direction[index] * x_axis[index] for index in range(3))
    cy = sum(direction[index] * y_axis[index] for index in range(3))
    if cz <= 1e-6:
        return None
    ndc_x = cx / cz / (aspect * math.tan(half_fov))
    ndc_y = cy / cz / math.tan(half_fov)
    return ((ndc_x + 1.0) * 0.5 * width, (1.0 - ndc_y) * 0.5 * height)


def to_map(position, forward, x_axis, y_axis, pixel, size) -> tuple:
    width, height = size
    half_fov = math.radians(FOV_DEGREES) * 0.5
    aspect = float(width) / float(height)
    ndc_x = (2.0 * pixel[0] / width - 1.0) * aspect * math.tan(half_fov)
    ndc_y = (1.0 - 2.0 * pixel[1] / height) * math.tan(half_fov)
    direction = tuple(forward[index] + ndc_x * x_axis[index] + ndc_y * y_axis[index]
                      for index in range(3))
    scale = (GROUND_LEVEL - position[2]) / direction[2]
    point = tuple(position[index] + direction[index] * scale for index in range(3))
    return point[0], -point[1]


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--size", default="1280x720")
    parser.add_argument("--box", default="")
    arguments = parser.parse_args()
    width, height = (int(part) for part in arguments.size.split("x"))
    size = (width, height)
    position, forward, x_axis, y_axis, distance = camera()
    print("camera at (%.3f, %.3f, %.3f), distance %.3f cells" %
          (position[0], position[1], position[2], distance))
    print("focal length in pixels: %.1f -> %.2f px per cell at the focus" %
          ((height * 0.5) / math.tan(math.radians(FOV_DEGREES) * 0.5),
           (height * 0.5) / math.tan(math.radians(FOV_DEGREES) * 0.5) / distance))
    for map_x, map_y in ((246, 28), (247, 28), (246, 29), (200, 45), (290, 10)):
        screen = to_screen(position, forward, x_axis, y_axis,
                           (float(map_x), -float(map_y), GROUND_LEVEL), size)
        print("   map (%3d, %3d) -> screen %s" %
              (map_x, map_y, "(%.1f, %.1f)" % screen if screen else "behind the camera"))
    if arguments.box:
        x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
        for pixel in ((x0, y0), (x1, y0), (x1, y1), (x0, y1), (width // 2, height // 2)):
            map_point = to_map(position, forward, x_axis, y_axis, pixel, size)
            print("   screen %-12s -> map (%.2f, %.2f)" % (pixel, map_point[0], map_point[1]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
