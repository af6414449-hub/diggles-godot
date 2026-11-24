#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Where on the map is a rectangle of the native view?

The native view of the port is fixed by the set_view command of the original
(Campaign.tcl:10: set_view 246.7 28.8 1.478 -0.29 0.05), so a rectangle of the
frame always lies on the same cells of the map. This script inverts the
projection of the scene:

    offset = Vector3(sin(yaw) * cos(tilt), sin(tilt), cos(yaw) * cos(tilt)) * distance
    camera.position = focus + offset
    camera.look_at(focus)

with focus = (246.7, -28.8, 14.5), yaw = 0.05, tilt = 0.29, the vertical FOV
38 degrees and the visible height of the native view 43 cells at zoom 1
(native_campaign_camera.gd:74-84, :37-38). The ray of a pixel is intersected
with the plane of the ground of the map (z = 14.5); the map y grows away from
the camera, so map_y = -world_y.

Read-only: it only computes.
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


def basis() -> tuple:
    visible_height = VISIBLE_HEIGHT_AT_ZOOM_ONE / ZOOM
    half_fov = math.radians(FOV_DEGREES) * 0.5
    distance = visible_height / (2.0 * math.tan(half_fov))
    tilt = -RX
    yaw = RY
    offset = (math.sin(yaw) * math.cos(tilt), math.sin(tilt),
              math.cos(yaw) * math.cos(tilt))
    position = (FOCUS_X + offset[0] * distance, -FOCUS_Y + offset[1] * distance,
                GROUND_LEVEL + offset[2] * distance)
    # The basis of Godot: -Z points at the target, X is right, Y is up.
    z = (position[0] - FOCUS_X, position[1] + FOCUS_Y, position[2] - GROUND_LEVEL)
    length = math.sqrt(sum(value * value for value in z))
    z = tuple(value / length for value in z)
    x = (z[2], 0.0, -z[0])
    length = math.hypot(x[0], x[2])
    x = (x[0] / length, 0.0, x[2] / length)
    y = (z[1] * x[2] - z[2] * x[1], z[2] * x[0] - z[0] * x[2], z[0] * x[1] - z[1] * x[0])
    forward = (-z[0], -z[1], -z[2])
    return position, forward, x, y, distance


def to_map(position: tuple, forward: tuple, x_axis: tuple, y_axis: tuple,
           pixel: tuple, size: tuple) -> tuple:
    width, height = size
    half_fov = math.radians(FOV_DEGREES) * 0.5
    aspect = float(width) / float(height)
    ndc_x = (2.0 * pixel[0] / width - 1.0) * aspect * math.tan(half_fov)
    ndc_y = (1.0 - 2.0 * pixel[1] / height) * math.tan(half_fov)
    direction = tuple(forward[index] + ndc_x * x_axis[index] + ndc_y * y_axis[index]
                      for index in range(3))
    if abs(direction[2]) < 1e-9:
        return None
    scale = (GROUND_LEVEL - position[2]) / direction[2]
    point = tuple(position[index] + direction[index] * scale for index in range(3))
    return point[0], -point[1]


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--box", required=True, help="x0,y0,x1,y1 of the frame, in pixels")
    parser.add_argument("--size", default="1280x720")
    arguments = parser.parse_args()
    x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
    width, height = (int(part) for part in arguments.size.split("x"))
    position, forward, x_axis, y_axis, distance = basis()
    print("camera position = (%.3f, %.3f, %.3f)  distance=%.3f  visible height=%.2f cells" %
          (position[0], position[1], position[2], distance, VISIBLE_HEIGHT_AT_ZOOM_ONE / ZOOM))
    corners = [(x0, y0), (x1, y0), (x1, y1), (x0, y1)]
    print("box %s of %dx%d:" % (arguments.box, width, height))
    for corner in corners:
        map_point = to_map(position, forward, x_axis, y_axis, corner, (width, height))
        if map_point is None:
            print("   %-12s -> the ray does not meet the plane of the map" % (corner,))
        else:
            print("   %-12s -> map x %.2f .. %.2f   y %.2f .. %.2f" %
                  (corner, map_point[0] - 0.5, map_point[0] + 0.5,
                   map_point[1] - 0.5, map_point[1] + 0.5))
    return 0


if __name__ == "__main__":
    sys.exit(main())
