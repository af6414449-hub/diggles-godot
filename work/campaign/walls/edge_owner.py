#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Whose edge is the dark line along the excavations of a capture?

The port draws long dark lines along the rim of the dug tunnels and shafts.
Two candidates can draw them: the vertical faces of the walls module (this
repository) and the cut of the ground plane of the map around the excavation
(the file of the scene).  The walls of the module are projected into the
capture the same way as in wall_screen.py, the thin dark marks are detected the
same way as in dark_marks.py, and every mark is measured against the walls:
the marks are grouped by their length, because the short ones are the seams of
the tiles of the ground and the long ones are the streaks along the rim.

Usage:
    python edge_owner.py --dump FACES.json --image FRAME.png --chapter CHAPTER.json
        [--box x0,y0,x1,y1] [--tilt 0.29] [--depth 6] [--min-aspect 3]
        [--min-area 4] [--long 8] [--save-out OUT.png]

Read-only: it only reads PNG files and the JSON dump of the module.
"""
import argparse
import json
import os
import sys

import numpy as np
from PIL import Image
from scipy import ndimage

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import dark_marks  # noqa: E402
import wall_screen  # noqa: E402


def marks_labels(array: np.ndarray, depth: float, min_area: int,
                 min_aspect: float) -> tuple:
    """The label map of the thin dark marks of a picture."""
    tone_map = dark_marks.tone(array, "lum")
    marks = dark_marks.high_pass(tone_map, 4.0, "median", 9)
    binary = marks >= depth
    labels, count = ndimage.label(binary, structure=np.ones((3, 3), dtype=int))
    found = []
    for index, slices in enumerate(ndimage.find_objects(labels), start=1):
        if slices is None:
            continue
        region = labels[slices] == index
        area = int(region.sum())
        if area < min_area:
            continue
        height = region.shape[0]
        width = region.shape[1]
        longest = max(height, width)
        shortest = min(height, width)
        if longest / float(max(shortest, 1)) < min_aspect:
            continue
        found.append({"label": index, "area": area, "length": longest,
                      "short": shortest, "slices": slices})
    keep = np.zeros(labels.shape, dtype=bool)
    for item in found:
        slices = item["slices"]
        keep[slices] |= labels[slices] == item["label"]
    return keep, found, labels


def group(items: list, walls: np.ndarray, distance: np.ndarray) -> None:
    """The marks of every group against the walls of the module."""
    print("%-26s %6s %8s %10s %10s %10s" %
          ("group", "marks", "length", "on walls", "within 2px", "median dist"))
    groups = [
        ("short (seams)", lambda item: item["length"] < 8),
        ("long (streaks)", lambda item: item["length"] >= 8),
    ]
    for title, rule in groups:
        chosen = [item for item in items if rule(item)]
        if not chosen:
            print("%-26s %6d" % (title, 0))
            continue
        on = 0
        near = 0
        distances = []
        for item in chosen:
            slices = item["slices"]
            patch = walls[slices]
            if patch.any():
                on += 1
            piece = distance[slices]
            values = piece[patch] if patch.any() else piece
            if patch.any():
                distances.append(float(np.median(values)))
                if float(values.min()) <= 2.0:
                    near += 1
        print("%-26s %6d %8.1f %9.1f%% %9.1f%% %10.2f" %
              (title, len(chosen),
               float(np.mean([item["length"] for item in chosen])),
               100.0 * on / len(chosen), 100.0 * near / len(chosen),
               float(np.median(distances)) if distances else -1.0))


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--dump", required=True)
    parser.add_argument("--image", required=True)
    parser.add_argument("--chapter", required=True)
    parser.add_argument("--box", default="")
    parser.add_argument("--region", default="", help="x0,y0,x1,y1 of the capture")
    parser.add_argument("--distance", type=float, default=42.25)
    parser.add_argument("--tilt", type=float, default=0.29)
    parser.add_argument("--yaw", type=float, default=0.05)
    parser.add_argument("--depth", type=float, default=6.0)
    parser.add_argument("--min-aspect", type=float, default=3.0)
    parser.add_argument("--min-area", type=int, default=4)
    parser.add_argument("--save-out", default="")
    arguments = parser.parse_args()

    picture = Image.open(arguments.image).convert("RGB")
    size = picture.size
    if arguments.region:
        x0, y0, x1, y1 = (int(part) for part in arguments.region.split(","))
        focus_map = ((x0 + x1) * 0.5, (y0 + y1) * 0.5)
        mask = wall_screen.wall_mask(arguments.dump, size, focus_map, arguments.distance,
                                     arguments.tilt, arguments.yaw)
    else:
        framing = wall_screen.wide_camera(arguments.chapter, size, arguments.tilt)
        mask = wall_screen.wall_mask(arguments.dump, size, framing["focus_map"],
                                      framing["distance"], arguments.tilt, framing["yaw"])
    array = np.asarray(picture).astype(np.float32)

    if arguments.box:
        x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
    else:
        x0, y0, x1, y1 = 0, 0, size[0], size[1]
    crop = array[y0:y1, x0:x1]
    walls = mask[y0:y1, x0:x1]
    mark_mask, found, labels = marks_labels(crop, arguments.depth, arguments.min_area,
                                            arguments.min_aspect)
    print("region %s: marks=%d px (%.2f %% of the region), walls=%d px (%.2f %%)" %
          ((x0, y0, x1, y1), int(mark_mask.sum()),
           100.0 * mark_mask.mean(), int(walls.sum()), 100.0 * walls.mean()))
    print("marks: %d components, length median %.1f px, p90 %.1f px" %
          (len(found),
           float(np.median([item["length"] for item in found])) if found else 0.0,
           float(np.percentile([item["length"] for item in found], 90)) if found else 0.0))

    if walls.any():
        distance = ndimage.distance_transform_edt(~walls)
        group(found, walls, distance)
        tone_map = dark_marks.tone(crop, "lum")
        print("tone: walls %.2f, ground around %.2f" %
              (float(tone_map[walls].mean()),
               float(tone_map[~ndimage.binary_dilation(walls, np.ones((3, 3)), iterations=3)].mean())))
        # the long marks that lie on the walls and the long marks that do not
        for item in found:
            if item["length"] < 8:
                continue
            slices = item["slices"]
            patch = walls[slices]
            piece = labels[slices] == item["label"]
            where = "on the walls" if patch.any() else "beside the walls"
            if patch.any():
                where += " (%.0f %% of the mark)" % (100.0 * float((patch & piece).sum())
                                                     / max(float(piece.sum()), 1.0))
            print("   long mark at (%d,%d) length %d: %s" %
                  (slices[1].start + x0, slices[0].start + y0, item["length"], where))

    if arguments.save_out:
        out = array.astype(np.int16).copy()
        region = out[y0:y1, x0:x1]
        region[mark_mask, 0] = 255
        region[mark_mask, 1] = region[mark_mask, 1] // 3
        region[mark_mask, 2] = region[mark_mask, 2] // 3
        region[walls, 2] = 255
        region[walls, 0] = region[walls, 0] // 3
        region[walls, 1] = region[walls, 1] // 3
        out[y0:y1, x0:x1] = region
        Image.fromarray(out.astype(np.uint8)).save(arguments.save_out)
        print("saved %s" % arguments.save_out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
