# -*- coding: utf-8 -*-
"""Check the V orientation of the dwarf UVs against the body atlas."""
import io, json, os, collections

BASE = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
TEX = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\models"

import sys
sys.path.insert(0, r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\tools")
from build_dwarf_life_page import read_tga

demo = json.load(io.open(os.path.join(BASE, "demo_start_models.json"), encoding="utf-8"))
clip = demo["objects"]["mann.3db::mann"]["locomotion"]["stand_anim_a"]
frame = clip["frames"][0]

atlas = {}
for name in ["ZMann_Koerper_unten.tga", "ZMann_Koerper_oben.tga", "ZMann_Haare.tga",
             "ZMann_Gesicht_normal.tga", "ZMann_Augen_normal.tga"]:
    w, h, rgba = read_tga(os.path.join(TEX, name))
    atlas[name] = (w, h, rgba)

def sample(tex, u, v, flip):
    w, h, rgba = tex
    x = min(w - 1, max(0, int(u * w)))
    y = min(h - 1, max(0, int(v * h)))
    if flip:
        y = h - 1 - y
    i = (y * w + x) * 4
    return rgba[i], rgba[i + 1], rgba[i + 2], rgba[i + 3]

for surface in frame["surfaces"]:
    tex = atlas[surface["texture"]]
    uvs = surface["uvs"]
    tris = surface["triangles"]
    bright = [0, 0, 0]
    dark = [0, 0, 0]
    for t in range(0, len(tris), 3):
        for k in range(3):
            u, v = uvs[tris[t + k]]
            r, g, b, a = sample(tex, u, v, False)
            bright[0] += r; bright[1] += g; bright[2] += b
            r2, g2, b2, a2 = sample(tex, u, v, True)
            dark[0] += r2; dark[1] += g2; dark[2] += b2
    n = len(tris)
    print("%-24s verts=%4d  as-is mean RGB %6.1f %6.1f %6.1f   flipped %6.1f %6.1f %6.1f" %
          (surface["texture"], len(uvs),
           bright[0] / n, bright[1] / n, bright[2] / n,
           dark[0] / n, dark[1] / n, dark[2] / n))
