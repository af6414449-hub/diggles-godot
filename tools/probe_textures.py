# -*- coding: utf-8 -*-
"""Alpha statistics of the dwarf textures (the shader discards a < 0.35)."""
import collections, io, os, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from build_dwarf_life_page import read_tga, TEXTURES

for name in ["ZMann_Koerper_unten.tga", "ZMann_Koerper_oben.tga", "ZMann_Haare.tga",
             "ZMann_Gesicht_normal.tga", "ZMann_Augen_normal.tga"]:
    w, h, rgba = read_tga(os.path.join(TEXTURES, name))
    hist = collections.Counter()
    for i in range(0, len(rgba), 4):
        hist[rgba[i + 3]] += 1
    total = w * h
    opaque = sum(v for k, v in hist.items() if k >= 90)
    print("%-26s %dx%d  alpha==0: %5.1f%%  alpha>=90: %5.1f%%  distinct=%d" %
          (name, w, h, 100.0 * hist[0] / total, 100.0 * opaque / total, len(hist)))
    print("    top alpha values:", hist.most_common(6))
