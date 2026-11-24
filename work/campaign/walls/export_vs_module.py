#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The two sets of vertical faces of the chapter in one capture.

The chapter has two sets of vertical faces: the faces of the export (49
surfaces, switched off with --hide-vertical) and the faces of the walls module
(1556 faces, projected here from the dump of the module).  The difference of a
pair of captures with and without --hide-vertical gives the footprint of the
faces of the export; the module is projected into the frame the same way as in
wall_screen.py.  The report says where each set is, whether they cover each
other and how dark each of them is against the ground around it.

Usage:
    python export_vs_module.py --dump FACES.json --image FRAME.png
        --image2 FRAME_NOVERT.png --chapter CHAPTER.json [--tilt 0.29]
        [--save-out OUT.png]

Read-only: it only reads PNG files and the JSON dump of the module.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image
from scipy import ndimage

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import wall_screen  # noqa: E402


def tone_stats(region: np.ndarray) -> tuple:
    if region.ndim == 3:
        region = region.reshape(-1, region.shape[-1])
    red = region[:, 0]
    green = region[:, 1]
    blue = region[:, 2]
    luminance = 0.299 * red + 0.587 * green + 0.114 * blue
    return float(luminance.mean()), float((red - blue).mean()), int(region.shape[0])


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--dump", required=True)
    parser.add_argument("--image", required=True)
    parser.add_argument("--image2", required=True)
    parser.add_argument("--chapter", required=True)
    parser.add_argument("--tilt", type=float, default=0.29)
    parser.add_argument("--yaw", type=float, default=0.05)
    parser.add_argument("--region", default="", help="x0,y0,x1,y1 of the capture")
    parser.add_argument("--distance", type=float, default=42.25)
    parser.add_argument("--threshold", type=int, default=6)
    parser.add_argument("--save-out", default="")
    arguments = parser.parse_args()

    first = Image.open(arguments.image).convert("RGB")
    second = Image.open(arguments.image2).convert("RGB")
    size = first.size
    array = np.asarray(first).astype(np.float32)
    other = np.asarray(second).astype(np.float32)
    difference = np.abs(array - other).max(axis=2)
    export = difference > arguments.threshold

    if arguments.region:
        x0, y0, x1, y1 = (int(part) for part in arguments.region.split(","))
        focus_map = ((x0 + x1) * 0.5, (y0 + y1) * 0.5)
        module = wall_screen.wall_mask(arguments.dump, size, focus_map, arguments.distance,
                                       arguments.tilt, arguments.yaw)
    else:
        framing = wall_screen.wide_camera(arguments.chapter, size, arguments.tilt)
        module = wall_screen.wall_mask(arguments.dump, size, framing["focus_map"],
                                       framing["distance"], arguments.tilt, framing["yaw"])

    print("frames: %s and %s" % (os.path.basename(arguments.image),
                                 os.path.basename(arguments.image2)))
    print("faces of the export: %d px (%.3f %% of the frame)" %
          (int(export.sum()), 100.0 * export.mean()))
    print("faces of the module: %d px (%.3f %% of the frame)" %
          (int(module.sum()), 100.0 * module.mean()))
    if export.any():
        print("   of them on the faces of the module: %d px (%.1f %% of the export, %.1f %% of the module)" %
              (int((export & module).sum()),
               100.0 * float((export & module).sum()) / float(export.sum()),
               100.0 * float((export & module).sum()) / max(float(module.sum()), 1.0)))
        kernel = np.ones((3, 3), dtype=int)
        near_module = ndimage.binary_dilation(module, kernel, iterations=2)
        print("   of them within 2 px of the faces of the module: %d px (%.1f %%)" %
              (int((export & near_module).sum()),
               100.0 * float((export & near_module).sum()) / float(export.sum())))

    kernel = np.ones((3, 3), dtype=int)
    around_export = ndimage.binary_dilation(export, kernel, iterations=4) & ~export & ~module
    around_module = ndimage.binary_dilation(module, kernel, iterations=4) & ~module & ~export
    if export.any():
        lum, rb, count = tone_stats(array[export])
        print("tone of the faces of the export: lum %.2f, R-B %+.2f (%d px)" % (lum, rb, count))
        if around_export.any():
            lum, rb, count = tone_stats(array[around_export])
            print("   the ground around them: lum %.2f, R-B %+.2f -> ratio %.3f" %
                  (lum, rb, lum / max(1e-6, tone_stats(array[export])[0])))
    if module.any():
        lum, rb, count = tone_stats(array[module])
        print("tone of the faces of the module: lum %.2f, R-B %+.2f (%d px)" % (lum, rb, count))
        if around_module.any():
            lum, rb, count = tone_stats(array[around_module])
            print("   the ground around them: lum %.2f, R-B %+.2f" % (lum, rb))

    if arguments.save_out:
        out = array.astype(np.int16).copy()
        out[export, 0] = 255
        out[export, 1] = out[export, 1] // 3
        out[export, 2] = out[export, 2] // 3
        out[module, 2] = 255
        out[module, 0] = out[module, 0] // 3
        out[module, 1] = out[module, 1] // 3
        Image.fromarray(out.astype(np.uint8)).save(arguments.save_out)
        print("saved %s" % arguments.save_out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
