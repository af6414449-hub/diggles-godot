# -*- coding: utf-8 -*-
"""The start area before and after the change of the material."""
import pathlib

from PIL import Image, ImageDraw

ROOT = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles")
SHOTS = ROOT / "out" / "campaign-shots"
BOX = (300, 330, 980, 700)

pairs = [
    ("v175-rings-default.png", "before: the hash belt of the port"),
    ("v180-stone-default.png", "after: the material of the original"),
]
images = []
for name, label in pairs:
    image = Image.open(SHOTS / name).convert("RGB").crop(BOX)
    images.append((image, label))

width = images[0][0].width
height = images[0][0].height + 22
sheet = Image.new("RGB", (width, height * len(images)), (20, 20, 24))
draw = ImageDraw.Draw(sheet)
for index, (image, label) in enumerate(images):
    sheet.paste(image, (0, index * height + 22))
    draw.text((8, index * height + 6), label, fill=(240, 240, 240))
out = ROOT / "out" / "campaign-shots" / "zz-start-before-after.png"
sheet.save(out)
print("written %s" % out)
