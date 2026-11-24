#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Which of the two sets of faces draws the dark lines along the excavations.

The chapter has two sets of vertical faces: the faces of the export (the
difference of a pair of captures with and without --hide-vertical) and the
faces of the walls module (projected from the dump of the module).  The thin
dark marks of the capture are detected as in dark_marks.py and every long mark
is classified against the two sets, so it is known whose edge draws the streaks.

Usage:
    python rim_owner.py --dump FACES.json --image FRAME.png --image2 FRAME_NOVERT.png
        --chapter CHAPTER.json [--box x0,y0,x1,y1] [--tilt 0.29] [--depth 6]
        [--min-aspect 3] [--min-area 4] [--long 8] [--save-out OUT.png]

Read-only: it only reads PNG files and the JSON dump of the module.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image
from scipy import ndimage

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import dark_marks  # noqa: E402
import edge_owner  # noqa: E402
import wall_screen  # noqa: E402


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--dump", required=True)
    parser.add_argument("--image", required=True)
    parser.add_argument("--image2", required=True)
    parser.add_argument("--chapter", required=True)
    parser.add_argument("--box", default="")
    parser.add_argument("--tilt", type=float, default=0.29)
    parser.add_argument("--depth", type=float, default=6.0)
    parser.add_argument("--min-aspect", type=float, default=3.0)
    parser.add_argument("--min-area", type=int, default=4)
    parser.add_argument("--long", type=int, default=8)
    parser.add_argument("--save-out", default="")
    arguments = parser.parse_args()

    first = Image.open(arguments.image).convert("RGB")
    second = Image.open(arguments.image2).convert("RGB")
    size = first.size
    array = np.asarray(first).astype(np.float32)
    other = np.asarray(second).astype(np.float32)
    export = np.abs(array - other).max(axis=2) > 6

    framing = wall_screen.wide_camera(arguments.chapter, size, arguments.tilt)
    module = wall_screen.wall_mask(arguments.dump, size, framing["focus_map"],
                                   framing["distance"], arguments.tilt, framing["yaw"])

    if arguments.box:
        x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
    else:
        x0, y0, x1, y1 = 0, 0, size[0], size[1]
    crop = array[y0:y1, x0:x1]
    walls = module[y0:y1, x0:x1]
    export_crop = export[y0:y1, x0:x1]
    mark_mask, found, labels = edge_owner.marks_labels(
        crop, arguments.depth, arguments.min_area, arguments.min_aspect)

    near_module = ndimage.binary_dilation(walls, np.ones((3, 3)), iterations=2)
    near_export = ndimage.binary_dilation(export_crop, np.ones((3, 3)), iterations=2)

    counts = {"on the module": 0, "on the export": 0, "on both": 0,
              "beside the module": 0, "beside the export": 0, "nowhere near": 0}
    lengths = {}
    for item in found:
        if item["length"] < arguments.long:
            continue
        slices = item["slices"]
        piece = labels[slices] == item["label"]
        on_module = bool((walls[slices] & piece).any())
        on_export = bool((export_crop[slices] & piece).any())
        if on_module and on_export:
            key = "on both"
        elif on_module:
            key = "on the module"
        elif on_export:
            key = "on the export"
        elif bool((near_module[slices] & piece).any()):
            key = "beside the module"
        elif bool((near_export[slices] & piece).any()):
            key = "beside the export"
        else:
            key = "nowhere near"
        counts[key] += 1
        lengths.setdefault(key, []).append(item["length"])

    total = sum(counts.values())
    print("region %s: %d marks, %d of them long (>= %d px)" %
          ((x0, y0, x1, y1), len(found), total, arguments.long))
    print("%-20s %6s %8s %10s" % ("where", "marks", "share", "length"))
    for key in ("on the module", "on the export", "on both", "beside the module",
                "beside the export", "nowhere near"):
        if counts[key] == 0:
            continue
        values = lengths[key]
        print("%-20s %6d %7.1f%% %10.1f" %
              (key, counts[key], 100.0 * counts[key] / max(total, 1),
               float(np.mean(values))))

    # the tone of both sets against the ground around them
    kernel = np.ones((3, 3), dtype=int)
    tone = dark_marks.tone(crop, "lum")
    for title, mask in (("the module", walls), ("the export", export_crop)):
        if not mask.any():
            continue
        around = ndimage.binary_dilation(mask, kernel, iterations=4) & ~mask & ~walls & ~export_crop
        print("tone of %s: %.2f, the ground around it: %.2f -> %.3f" %
              (title, float(tone[mask].mean()),
               float(tone[around].mean()) if around.any() else 0.0,
               float(tone[mask].mean()) / max(float(tone[around].mean()), 1e-6)))

    if arguments.save_out:
        out = array.astype(np.int16).copy()
        region = out[y0:y1, x0:x1]
        region[mark_mask, 0] = 255
        region[mark_mask, 1] = region[mark_mask, 1] // 3
        region[mark_mask, 2] = region[mark_mask, 2] // 3
        region[export_crop, 2] = 255
        region[export_crop, 0] = region[export_crop, 0] // 3
        region[export_crop, 1] = region[export_crop, 1] // 3
        region[walls, 1] = 255
        region[walls, 0] = region[walls, 0] // 3
        region[walls, 2] = region[walls, 2] // 3
        out[y0:y1, x0:x1] = region
        Image.fromarray(out.astype(np.uint8)).save(arguments.save_out)
        print("saved %s" % arguments.save_out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
