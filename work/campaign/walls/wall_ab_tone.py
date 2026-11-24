#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The tone of the vertical faces of the excavation against the ground near them.

Two captures of the same view are needed: one with the vertical faces and one
without them.  The pixels that changed are the vertical faces themselves, so
the tone of the faces can be measured in the first capture and the tone of the
ground around them in the same capture, without picking the regions by hand.

Usage:
    python wall_ab_tone.py WITH.png WITHOUT.png [--threshold 6] [--ring 12]
        [--box x0,y0,x1,y1]

Read-only: it only reads PNG files.
"""
import argparse
import os
import sys

import numpy as np
from PIL import Image
from scipy import ndimage


def tone_stats(region: np.ndarray) -> dict:
    if region.ndim == 3 and region.shape[0] != region.shape[-1]:
        region = region.reshape(-1, region.shape[-1])
    red = region[:, 0]
    green = region[:, 1]
    blue = region[:, 2]
    luminance = 0.299 * red + 0.587 * green + 0.114 * blue
    warmth = red - blue
    return {
        "pixels": int(region.shape[0] * region.shape[1]),
        "lum": float(luminance.mean()),
        "lum_std": float(luminance.std()),
        "rb": float(warmth.mean()),
        "rb_std": float(warmth.std()),
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("with_frame")
    parser.add_argument("without_frame")
    parser.add_argument("--threshold", type=int, default=6)
    parser.add_argument("--ring", type=int, default=12)
    parser.add_argument("--box", default="")
    parser.add_argument("--save-diff", default="")
    arguments = parser.parse_args()
    if not os.path.isfile(arguments.with_frame) or not os.path.isfile(arguments.without_frame):
        print("missing frame")
        return 1
    first = np.asarray(Image.open(arguments.with_frame).convert("RGB")).astype(np.float32)
    second = np.asarray(Image.open(arguments.without_frame).convert("RGB")).astype(np.float32)
    if first.shape != second.shape:
        print("different size: %s vs %s" % (first.shape, second.shape))
        return 1
    if arguments.box:
        x0, y0, x1, y1 = (int(part) for part in arguments.box.split(","))
        first = first[y0:y1, x0:x1]
        second = second[y0:y1, x0:x1]
    difference = np.abs(first - second).max(axis=2)
    faces = difference > arguments.threshold
    labels, count = ndimage.label(faces, structure=np.ones((3, 3), dtype=int))
    sizes = ndimage.sum(faces, labels, index=range(1, count + 1))
    kernel = np.ones((3, 3), dtype=int)
    near = ndimage.binary_dilation(faces, kernel, iterations=max(1, arguments.ring)) & ~faces
    outer = ndimage.binary_dilation(faces, kernel, iterations=max(1, arguments.ring * 3))
    ground = outer & ~ndimage.binary_dilation(faces, kernel, iterations=max(1, arguments.ring))
    print("%s  vs  %s" % (os.path.basename(arguments.with_frame),
                          os.path.basename(arguments.without_frame)))
    print("frame %dx%d, threshold %d, ring %d px" % (first.shape[1], first.shape[0],
                                                     arguments.threshold, arguments.ring))
    print("changed pixels: %d (%.2f %% of the frame) in %d patches" %
          (int(faces.sum()), 100.0 * faces.mean(), count))
    if count:
        ordered = np.sort(sizes)[::-1]
        print("largest patches: %s px" % ", ".join(str(int(value)) for value in ordered[:10]))
    if faces.any() and ground.any():
        face_stats = tone_stats(first[faces])
        ground_stats = tone_stats(first[ground])
        hidden_stats = tone_stats(second[faces])
        near_stats = tone_stats(first[near]) if near.any() else None
        print("vertical faces   : px=%-8d lum=%6.2f (sd %5.2f)  R-B=%+6.2f (sd %5.2f)" %
              (face_stats["pixels"], face_stats["lum"], face_stats["lum_std"],
               face_stats["rb"], face_stats["rb_std"]))
        print("ground around    : px=%-8d lum=%6.2f (sd %5.2f)  R-B=%+6.2f (sd %5.2f)" %
              (ground_stats["pixels"], ground_stats["lum"], ground_stats["lum_std"],
               ground_stats["rb"], ground_stats["rb_std"]))
        if near_stats:
            print("edge of the face : px=%-8d lum=%6.2f (sd %5.2f)  R-B=%+6.2f (sd %5.2f)" %
                  (near_stats["pixels"], near_stats["lum"], near_stats["lum_std"],
                   near_stats["rb"], near_stats["rb_std"]))
        print("behind the faces : px=%-8d lum=%6.2f (sd %5.2f)  R-B=%+6.2f (sd %5.2f)" %
              (hidden_stats["pixels"], hidden_stats["lum"], hidden_stats["lum_std"],
               hidden_stats["rb"], hidden_stats["rb_std"]))
        print("face minus ground: dLum=%+6.2f  dR-B=%+6.2f  ratioLum=%.3f" %
              (face_stats["lum"] - ground_stats["lum"], face_stats["rb"] - ground_stats["rb"],
               face_stats["lum"] / max(ground_stats["lum"], 1e-6)))
    if arguments.save_diff:
        picture = np.asarray(Image.open(arguments.with_frame).convert("RGB")).astype(np.int16).copy()
        picture[faces, 0] = 255
        picture[faces, 1] = picture[faces, 1] // 4
        picture[faces, 2] = picture[faces, 2] // 4
        Image.fromarray(picture.astype(np.uint8)).save(arguments.save_diff)
        print("saved %s" % arguments.save_diff)
    return 0


if __name__ == "__main__":
    sys.exit(main())
