#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Where does the grid of the barrier come from: the tint of the cell or the
edges of the native tiles?"""
import os
import sys

import numpy as np
from PIL import Image

SHOTS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"


def load(name):
    return np.asarray(Image.open(os.path.join(SHOTS, name)).convert("RGB")).astype(np.float32)


def analyse(name):
    image = load(name)
    gray = image.mean(axis=2)
    block = gray[300:600, 200:1200]
    profile = block.mean(axis=0)
    profile = profile - profile.mean()
    print("%s" % name)
    print("   profile std %.3f  (amplitude of the cell steps)" % profile.std())
    best = []
    for lag in range(8, 80):
        left = profile[:-lag]
        right = profile[lag:]
        value = float(np.corrcoef(left, right)[0, 1])
        best.append((value, lag))
    best.sort(reverse=True)
    print("   best periods: %s" % ", ".join("%.2f@%d" % (c, l) for c, l in best[:4]))
    # The step of the tint of a cell: the difference of the mean of two halves
    # of a cell, against the difference inside a cell.
    for cell in (24, 32, 40, 48):
        if 200 + 2 * cell > 1200:
            continue
        means = []
        for index in range(0, 1000 - cell, cell):
            means.append(block[:, 200 + index:200 + index + cell].mean())
        means = np.asarray(means)
        if len(means) < 4:
            continue
        print("   cell %2d px: step between cells %.3f  inside a cell %.3f" %
              (cell, float(np.abs(np.diff(means)).mean()),
               float(np.abs(np.diff(block, axis=1)).mean())))


for name in ("v92-barrier-band.png", "v93-barrier-band.png"):
    if os.path.isfile(os.path.join(SHOTS, name)):
        analyse(name)
