# -*- coding: utf-8 -*-
"""The vertical profile of the reference of the original.

The screenshot of the owner (the campaign map of the original): the mean
colour of every row and the horizon, so the bands of the panorama can be
measured.
"""
import pathlib

from PIL import Image

ROOT = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles")
path = ROOT / "out" / "campaign-shots" / "owner-game-urwald-reference.png"
image = Image.open(path).convert("RGB")
width, height = image.size
print("the size: %dx%d" % (width, height))
pixels = image.load()
print("row : mean r,g,b   (the middle column and the full row)")
for y in range(0, height, 12):
    total = [0, 0, 0]
    for x in range(0, width, 4):
        colour = pixels[x, y]
        total[0] += colour[0]
        total[1] += colour[1]
        total[2] += colour[2]
    count = len(range(0, width, 4))
    middle = pixels[width // 2, y]
    print("y=%3d  %3d,%3d,%3d   middle %3d,%3d,%3d" % (
        y, total[0] // count, total[1] // count, total[2] // count,
        middle[0], middle[1], middle[2]))
