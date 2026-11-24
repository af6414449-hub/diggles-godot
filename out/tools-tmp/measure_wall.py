#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The tone of the wall of a tunnel against the floor next to it."""
import os
import sys

import numpy as np
from PIL import Image

SHOTS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\campaign-shots"

BOXES = (
    ("wall band above the corridor", (600, 446, 900, 462)),
    ("corridor floor", (600, 480, 900, 500)),
    ("rock above the corridor", (600, 250, 900, 380)),
)


def main():
    for name in sys.argv[1:] or ("v100-mine.png", "v101-mine.png"):
        path = os.path.join(SHOTS, name)
        if not os.path.isfile(path):
            print("missing: %s" % name)
            continue
        image = np.asarray(Image.open(path).convert("RGB")).astype(np.float32)
        print(name)
        for label, (x0, y0, x1, y1) in BOXES:
            patch = image[y0:y1, x0:x1]
            print("   %-28s mean (%5.1f %5.1f %5.1f)  std %5.2f" %
                  (label, patch[:, :, 0].mean(), patch[:, :, 1].mean(),
                   patch[:, :, 2].mean(), patch.std()))
    return 0


if __name__ == "__main__":
    sys.exit(main())
