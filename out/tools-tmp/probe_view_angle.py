#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Is the view of the owner the same as the view of the port?

A ground texture seen at a grazing angle is compressed vertically: the
autocorrelation along the rows dies faster than along the columns.  A view
almost straight down the normal of the board leaves the texture isotropic.
"""
import os
import sys

import numpy as np
from PIL import Image

REF = r"C:\Users\frant\.minimax\v2\assets\2026\11\22\19-11-50-767-asset_20261122-191150-767_2dd8dfdb4050_08710dea-image.png"
SHOTS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"


def load(path):
    return np.asarray(Image.open(path).convert("RGB")).astype(np.float32)


def anisotropy(patch, label):
    gray = patch.mean(axis=2)
    gray = gray - gray.mean()
    energy = float((gray * gray).mean())
    if energy <= 0.0:
        print("%-26s flat" % label)
        return 0.0
    horizontal = []
    vertical = []
    for lag in range(1, 9):
        left = gray[:, :-lag]
        right = gray[:, lag:]
        horizontal.append(float((left * right).mean() / energy))
        top = gray[:-lag, :]
        bottom = gray[lag:, :]
        vertical.append(float((top * bottom).mean() / energy))
    # The lag where the correlation along the rows falls to half.
    def half(values):
        for index, value in enumerate(values):
            if value < 0.5:
                return index + 1
        return len(values) + 1
    ratio = half(horizontal) / max(half(vertical), 1)
    print("%-26s corr along the columns: %s" % (label, " ".join("%.2f" % v for v in horizontal)))
    print("%-26s corr along the rows   : %s   -> the rows are %.1fx longer" %
          ("", " ".join("%.2f" % v for v in vertical), ratio))
    return ratio


def main():
    reference = load(REF)
    half_h = reference.shape[0] // 2
    half_w = reference.shape[1] // 2
    print("== the frame of the owner ==")
    anisotropy(reference[0:half_h, 0:half_w], "owner: ground")
    anisotropy(reference[0:half_h, half_w:reference.shape[1]], "owner: granite")
    print("== the port ==")
    for label, name, box in (
            ("port: ground (tilt 0.29)", "v96-ground-zoom.png", (300, 300, 556, 556)),
            ("port: granite (tilt 0.29)", "v96-barrier-zoom.png", (300, 300, 556, 556))):
        path = os.path.join(SHOTS, name)
        if not os.path.isfile(path):
            continue
        image = load(path)
        anisotropy(image[box[1]:box[3], box[0]:box[2]], label)
    return 0


if __name__ == "__main__":
    sys.exit(main())
