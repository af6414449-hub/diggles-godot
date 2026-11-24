#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The tone of the walls of the module in a capture of the scene.

The walls module builds the vertical faces of the excavations.  They are not
the faces of the export: the capture with --hide-vertical switches off the
faces of the export, so a difference of two captures measures those faces and
not the walls of the module.  To measure the walls of the module they are
projected into the capture instead: the module dumps its faces with
`campaign_wall_audit.gd --dump=PATH`, every face with its four corners in the
space of the cell, and the camera of the capture is known from its flags.

Usage:
    python wall_screen.py --dump FACES.json --image FRAME.png
        --region x0,y0,x1,y1 [--distance 42.25] [--size 1280x720]
        [--image2 FRAME2.png] [--ring 10] [--save-mask OUT.png]

Read-only: it only reads PNG files and the JSON dump of the module.
"""
import argparse
import json
import math
import os
import sys

import numpy as np
from PIL import Image, ImageDraw
from scipy import ndimage

FOV_DEGREES = 38.0
GROUND_LEVEL = 14.5
DEFAULT_TILT = 0.29
DEFAULT_YAW = 0.05


def camera(focus_map: tuple, distance: float, tilt: float, yaw: float) -> tuple:
    """The camera of a capture: the same model as native_campaign_camera.gd."""
    focus = (float(focus_map[0]), -float(focus_map[1]), GROUND_LEVEL)
    offset = (math.sin(yaw) * math.cos(tilt), math.sin(tilt),
              math.cos(yaw) * math.cos(tilt))
    position = tuple(focus[index] + offset[index] * distance for index in range(3))
    axis_z = tuple(position[index] - focus[index] for index in range(3))
    length = math.sqrt(sum(value * value for value in axis_z))
    axis_z = tuple(value / length for value in axis_z)
    axis_x = (axis_z[2], 0.0, -axis_z[0])
    length = math.hypot(axis_x[0], axis_x[2])
    axis_x = (axis_x[0] / length, 0.0, axis_x[2] / length)
    axis_y = (axis_z[1] * axis_x[2] - axis_z[2] * axis_x[1],
              axis_z[2] * axis_x[0] - axis_z[0] * axis_x[2],
              axis_z[0] * axis_x[1] - axis_z[1] * axis_x[0])
    forward = (-axis_z[0], -axis_z[1], -axis_z[2])
    return position, forward, axis_x, axis_y


def to_screen(position, forward, axis_x, axis_y, point, size) -> tuple:
    width, height = size
    half_fov = math.radians(FOV_DEGREES) * 0.5
    aspect = float(width) / float(height)
    direction = tuple(point[index] - position[index] for index in range(3))
    length = math.sqrt(sum(value * value for value in direction))
    direction = tuple(value / length for value in direction)
    cz = sum(direction[index] * forward[index] for index in range(3))
    cx = sum(direction[index] * axis_x[index] for index in range(3))
    cy = sum(direction[index] * axis_y[index] for index in range(3))
    if cz <= 1e-6:
        return None
    ndc_x = cx / cz / (aspect * math.tan(half_fov))
    ndc_y = cy / cz / math.tan(half_fov)
    return ((ndc_x + 1.0) * 0.5 * width, (1.0 - ndc_y) * 0.5 * height)


def chapter_depth_span(chapter: dict) -> float:
    """The range of the heights of the chapter, in native units.

    The same rule as native_campaign_first_level.gd:_chapter_depth_span: every
    vertex of every mesh of every block that carries a cell, with the stride of
    five values (x, y, z, u, v).
    """
    low = None
    high = None
    seen = set()
    for entry in chapter["cells"]:
        block = int(entry["block"])
        if block in seen:
            continue
        seen.add(block)
        for part in chapter["meshes"].get(str(block), []):
            values = part["vertices"]
            for offset in range(2, len(values), 5):
                value = float(values[offset])
                low = value if low is None else min(low, value)
                high = value if high is None else max(high, value)
    if low is None or high is None:
        return 0.0
    return high - low


def wide_camera(chapter_path: str, size: tuple, tilt: float) -> dict:
    """The camera of a capture of the whole chapter (--capture-wide).

    The same rule as native_campaign_first_level.gd:1299-1307 and
    native_campaign_camera.gd: the focus on the middle of the box of the cells
    of the chapter, the distance from the projected size of that box with a
    margin of 0.45.
    """
    with open(chapter_path, "r", encoding="utf-8") as handle:
        chapter = json.load(handle)
    view = chapter.get("initial_view", {})
    cells = chapter["cells"]
    xs = [int(entry["x"]) for entry in cells]
    ys = [int(entry["y"]) for entry in cells]
    box_min = (min(xs), min(ys))
    box_max = (max(xs), max(ys))
    depth_span = chapter_depth_span(chapter)
    content = (box_max[0] - box_min[0] + 1.0, box_max[1] - box_min[1] + 1.0)
    projected = (content[0], content[1] + abs(depth_span) * math.sin(abs(tilt)))
    aspect = float(size[0]) / float(size[1])
    visible_height = max(projected[1], projected[0] / max(aspect, 1e-6)) * 1.45
    half_fov = math.radians(FOV_DEGREES) * 0.5
    distance = visible_height / (2.0 * math.tan(half_fov))
    return {
        "focus_map": ((box_min[0] + box_max[0]) * 0.5, (box_min[1] + box_max[1]) * 0.5),
        "distance": distance,
        "yaw": float(view.get("ry", 0.0)),
        "tilt": tilt,
        "box": (box_min, box_max),
        "depth_span": depth_span,
        "visible_height": visible_height,
        "px_per_cell": float(size[1]) / visible_height,
    }


def wall_mask(dump_path: str, size: tuple, focus_map: tuple, distance: float,
              tilt: float, yaw: float) -> np.ndarray:
    """The pixels of the walls of the module in the capture."""
    with open(dump_path, "r", encoding="utf-8") as handle:
        dump = json.load(handle)
    position, forward, axis_x, axis_y = camera(focus_map, distance, tilt, yaw)
    picture = Image.new("L", size, 0)
    draw = ImageDraw.Draw(picture)
    drawn = 0
    for face in dump["faces"]:
        cell = face["cell"]
        points = []
        for corner in face["corners"]:
            world = (cell[0] + corner[0], -(cell[1] + corner[1]), corner[2])
            screen = to_screen(position, forward, axis_x, axis_y, world, size)
            if screen is None:
                points = []
                break
            points.append(screen)
        if len(points) < 3:
            continue
        draw.polygon(points, fill=255)
        drawn += 1
    mask = np.asarray(picture) > 127
    print("faces in the dump: %d, faces projected into the frame: %d" %
          (len(dump["faces"]), drawn))
    return mask


def tone_stats(region: np.ndarray) -> dict:
    if region.ndim == 3 and region.shape[0] != region.shape[-1]:
        region = region.reshape(-1, region.shape[-1])
    red = region[:, 0]
    green = region[:, 1]
    blue = region[:, 2]
    luminance = 0.299 * red + 0.587 * green + 0.114 * blue
    return {
        "pixels": int(region.shape[0]),
        "lum": float(luminance.mean()),
        "lum_median": float(np.median(luminance)),
        "lum_std": float(luminance.std()),
        "rb": float((red - blue).mean()),
        "rb_std": float((red - blue).std()),
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--dump", required=True)
    parser.add_argument("--image", required=True)
    parser.add_argument("--image2", default="")
    parser.add_argument("--region", default="", help="x0,y0,x1,y1 of the capture")
    parser.add_argument("--distance", type=float, default=42.25)
    parser.add_argument("--tilt", type=float, default=DEFAULT_TILT)
    parser.add_argument("--yaw", type=float, default=DEFAULT_YAW)
    parser.add_argument("--ring", type=int, default=10)
    parser.add_argument("--save-mask", default="")
    parser.add_argument("--save-changed", default="")
    parser.add_argument("--chapter", default="", help="chapter JSON of the scene")
    parser.add_argument("--wide", action="store_true",
                        help="the camera of a capture of the whole chapter")
    arguments = parser.parse_args()
    first = Image.open(arguments.image).convert("RGB")
    size = first.size
    distance = arguments.distance
    tilt = arguments.tilt
    yaw = arguments.yaw
    if arguments.wide:
        if not arguments.chapter:
            print("--wide needs --chapter")
            return 1
        framing = wide_camera(arguments.chapter, size, tilt)
        focus_map = framing["focus_map"]
        distance = framing["distance"]
        yaw = framing["yaw"]
        print("wide camera: focus=(%.1f, %.1f) distance=%.2f yaw=%.3f tilt=%.3f" %
              (focus_map[0], focus_map[1], distance, yaw, tilt))
        print("   box of the cells=%s depth span=%.2f visible height=%.2f -> %.3f px per cell" %
              (framing["box"], framing["depth_span"], framing["visible_height"],
               framing["px_per_cell"]))
    else:
        if not arguments.region:
            print("--region is needed without --wide")
            return 1
        x0, y0, x1, y1 = (int(part) for part in arguments.region.split(","))
        focus_map = ((x0 + x1) * 0.5, (y0 + y1) * 0.5)
    mask = wall_mask(arguments.dump, size, focus_map, distance,
                     tilt, yaw)
    array = np.asarray(first).astype(np.float32)
    kernel = np.ones((3, 3), dtype=int)
    near = ndimage.binary_dilation(mask, kernel, iterations=max(1, arguments.ring))
    ground = near & ~ndimage.binary_dilation(mask, kernel, iterations=1)
    print("wall pixels of the module in the frame: %d (%.2f %% of the frame)" %
          (int(mask.sum()), 100.0 * mask.mean()))
    if mask.any() and ground.any():
        wall = tone_stats(array[mask])
        around = tone_stats(array[ground])
        print("%-28s walls : lum=%6.2f (median %6.2f, sd %5.2f)  R-B=%+6.2f (sd %5.2f)" %
              (os.path.basename(arguments.image), wall["lum"], wall["lum_median"],
               wall["lum_std"], wall["rb"], wall["rb_std"]))
        print("%-28s around: lum=%6.2f (median %6.2f, sd %5.2f)  R-B=%+6.2f (sd %5.2f)" %
              ("", around["lum"], around["lum_median"], around["lum_std"],
               around["rb"], around["rb_std"]))
        print("%-28s wall minus around: dLum=%+6.2f  dR-B=%+6.2f  ratioLum=%.3f" %
              ("", wall["lum"] - around["lum"], wall["rb"] - around["rb"],
               wall["lum"] / max(around["lum"], 1e-6)))
    if arguments.image2:
        second = np.asarray(Image.open(arguments.image2).convert("RGB")).astype(np.float32)
        difference = np.abs(array - second).max(axis=2)
        changed = mask & (difference > 6)
        print("%s (before) walls: lum=%6.2f (median %6.2f)  R-B=%+6.2f" %
              (os.path.basename(arguments.image), tone_stats(array[mask])["lum"],
               tone_stats(array[mask])["lum_median"], tone_stats(array[mask])["rb"]))
        print("%s (after)  walls: lum=%6.2f (median %6.2f)  R-B=%+6.2f" %
              (os.path.basename(arguments.image2), tone_stats(second[mask])["lum"],
               tone_stats(second[mask])["lum_median"], tone_stats(second[mask])["rb"]))
        if changed.any():
            before = tone_stats(array[changed])
            after = tone_stats(second[changed])
            print("changed pixels on the walls of the module: %d (%.2f %% of the frame)" %
                  (int(changed.sum()), 100.0 * changed.mean()))
            print("   before: lum=%6.2f (median %6.2f)  R-B=%+6.2f" %
                  (before["lum"], before["lum_median"], before["rb"]))
            print("   after : lum=%6.2f (median %6.2f)  R-B=%+6.2f" %
                  (after["lum"], after["lum_median"], after["rb"]))
            print("   change: dLum=%+6.2f  dR-B=%+6.2f" %
                  (after["lum"] - before["lum"], after["rb"] - before["rb"]))
            near_changed = ndimage.binary_dilation(changed, kernel, iterations=max(1, arguments.ring))
            around_changed = near_changed & ~ndimage.binary_dilation(changed, kernel, iterations=1)
            if around_changed.any():
                around = tone_stats(second[around_changed])
                print("   around the changed walls (after): lum=%6.2f  R-B=%+6.2f -> ratio %.3f" %
                      (around["lum"], around["rb"], after["lum"] / max(around["lum"], 1e-6)))
            if arguments.save_changed:
                picture = np.asarray(Image.open(arguments.image2).convert("RGB")).astype(np.int16).copy()
                picture[changed, 1] = 255
                picture[changed, 0] = picture[changed, 0] // 4
                picture[changed, 2] = picture[changed, 2] // 4
                Image.fromarray(picture.astype(np.uint8)).save(arguments.save_changed)
                print("saved %s" % arguments.save_changed)
        same = mask & ~changed
        if same.any():
            kept_before = tone_stats(array[same])
            kept_after = tone_stats(second[same])
            near_same = ndimage.binary_dilation(same, kernel, iterations=max(1, arguments.ring))
            around_same = near_same & ~ndimage.binary_dilation(same, kernel, iterations=1)
            if around_same.any():
                around = tone_stats(second[around_same])
                print("walls that did not change: %d px, lum %.2f -> %.2f, R-B %+.2f -> %+.2f" %
                      (int(same.sum()), kept_before["lum"], kept_after["lum"],
                       kept_before["rb"], kept_after["rb"]))
                print("   around them (after): lum=%6.2f  R-B=%+6.2f -> ratio %.3f" %
                      (around["lum"], around["rb"], kept_after["lum"] / max(around["lum"], 1e-6)))
    if arguments.save_mask:
        picture = np.asarray(first).astype(np.int16).copy()
        picture[mask, 0] = 255
        picture[mask, 1] = picture[mask, 1] // 3
        picture[mask, 2] = picture[mask, 2] // 3
        Image.fromarray(picture.astype(np.uint8)).save(arguments.save_mask)
        print("saved %s" % arguments.save_mask)
    return 0


if __name__ == "__main__":
    sys.exit(main())
