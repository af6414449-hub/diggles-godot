#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Two diagnostics: the reddish streaks over the ground and the dark lines
along the corridors."""
import os
import sys

import numpy as np
from PIL import Image

OWNER1 = r"C:\Users\frant\.minimax\v2\assets\2026\11\22\20-38-07-060-asset_20261122-203807-060_1f9eeace77f8_44ea2e54-image.png"
OWNER2 = r"C:\Users\frant\.minimax\v2\assets\2026\11\22\20-38-07-079-asset_20261122-203807-079_1dc0ce01de3a_fe7bc1c6-image.png"
SHOTS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"


def load(path):
    return np.asarray(Image.open(path).convert("RGB")).astype(np.float32)


def crop(path, box, out, scale=2):
    image = Image.open(path).convert("RGB")
    piece = image.crop(box)
    piece = piece.resize((piece.width * scale, piece.height * scale), Image.LANCZOS)
    piece.save(out)
    print("saved %s (%dx%d)" % (out, piece.width, piece.height))


def streaks(name):
    path = os.path.join(SHOTS, name)
    if not os.path.isfile(path):
        return
    image = load(path)
    # The ground of the map on the left of the island: the rows of the map are
    # horizontal bands on the screen.
    block = image[140:640, 30:640]
    gray = block.mean(axis=2)
    profile = gray.mean(axis=1)
    profile = profile - profile.mean()
    # The amplitude of the row-to-row structure.
    step = float(np.abs(np.diff(profile)).mean())
    spread = float(profile.max() - profile.min())
    # The warm part: the red minus the blue of every row.
    warm = (block[:, :, 0] - block[:, :, 2]).mean(axis=1)
    warm = warm - warm.mean()
    warm_step = float(np.abs(np.diff(warm)).mean())
    warm_spread = float(warm.max() - warm.min())
    print("%-18s rows: step %.3f  spread %.2f | red-blue: step %.3f  spread %.2f" %
          (name, step, spread, warm_step, warm_spread))


def main():
    print("== the frames of the owner ==")
    for path in (OWNER1, OWNER2):
        image = Image.open(path)
        print("%s %s" % (os.path.basename(path), image.size))
    crop(OWNER2, (860, 200, 1600, 420), os.path.join(SHOTS, "owner-corridor-zoom.png"), 2)
    crop(OWNER1, (0, 180, 700, 520), os.path.join(SHOTS, "owner-streaks-zoom.png"), 2)
    print("== the wide frame of the port, before and after the run colour ==")
    streaks("v95-wide.png")
    streaks("v96-wide.png")
    return 0


if __name__ == "__main__":
    sys.exit(main())
