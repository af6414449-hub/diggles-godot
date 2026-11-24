#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Compare the ground and the barrier of the port with the frame of the owner.

The reference is the frame of the owner: the left upper quadrant is the ground
of the original, the right upper quadrant is the granite of the barrier.  The
crops of the port are taken at the same scale (a cell of the map is about 64
pixels there, as in the frame of the owner) and of the same size, so that the
numbers and the pictures can be compared directly.
"""
import os
import sys

import numpy as np
from PIL import Image

REF = r"C:\Users\frant\.minimax\v2\assets\2026\11\22\19-11-50-767-asset_20261122-191150-767_2dd8dfdb4050_08710dea-image.png"
SHOTS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"
OUT = os.path.join(SHOTS, "compare-ref-vs-mine-v96.png")

# The size of the crop of the reference: the reference is 276x283, so every
# quadrant is 138x141.
CROP_W = 138
CROP_H = 141
# The crop of the frames of the port: the same size, taken out of the middle
# of the frame, away from the text of the capture.
PORT_BOX = (560, 290, 560 + CROP_W, 290 + CROP_H)
# The rectangle of the wide frame, the same in the frame before the change and
# in the frame after it.
WIDE_BOX = (700, 300, 900, 420)


def load(path):
    return np.asarray(Image.open(path).convert("RGB")).astype(np.float32)


def crop(path, box):
    image = load(path)
    x0, y0, x1, y1 = box
    return image[y0:y1, x0:x1]


def stats(patch):
    flat = patch.reshape(-1, 3)
    gray = patch.mean(axis=2)
    dx = float(np.abs(np.diff(gray, axis=1)).mean())
    dy = float(np.abs(np.diff(gray, axis=0)).mean())
    mean = flat.mean(axis=0)
    std = flat.std(axis=0).mean()
    return mean, std, (dx + dy) * 0.5


def row(label, patch):
    mean, std, hf = stats(patch)
    print("%-22s mean (%5.1f %5.1f %5.1f)  std %5.2f  hf %5.2f  G-B %+5.1f" %
          (label, mean[0], mean[1], mean[2], std, hf, mean[1] - mean[2]))
    return patch


def wide(label, name):
    path = os.path.join(SHOTS, name)
    if not os.path.isfile(path):
        return None
    return row(label, crop(path, WIDE_BOX))


def main():
    tiles = []
    ref = load(REF)
    half_h = ref.shape[0] // 2
    half_w = ref.shape[1] // 2
    print("== the frame of the owner (a cell is about 64 px) ==")
    tiles.append(row("reference ground", ref[0:half_h, 0:half_w]))
    tiles.append(row("reference granite", ref[0:half_h, half_w:ref.shape[1]]))

    print("== the port, the same scale ==")
    for label, name in (("port earth before", "v95-ground-zoom.png"),
            ("port granite before", "v94-barrier-zoom.png"),
            ("port earth", "v96-ground-zoom.png"),
            ("port granite", "v96-barrier-zoom.png")):
        path = os.path.join(SHOTS, name)
        if os.path.isfile(path):
            tiles.append(row(label, crop(path, PORT_BOX)))

    print("== the wide frame, before and after the change ==")
    wide("wide before", "v89-wide.png")
    wide("wide after", "v95-wide.png")

    height = 260
    width = height
    sheet = np.zeros((height, width * len(tiles), 3), dtype=np.uint8)
    for index, patch in enumerate(tiles):
        image = Image.fromarray(patch.astype(np.uint8)).resize((width, height), Image.LANCZOS)
        sheet[0:height, index * width:(index + 1) * width] = np.asarray(image)
    Image.fromarray(sheet, "RGB").save(OUT)
    print("sheet=%s  (panels: %s)" % (OUT, ", ".join(
        ["reference ground", "reference granite", "port earth", "port granite"][:len(tiles)])))
    return 0


if __name__ == "__main__":
    sys.exit(main())
