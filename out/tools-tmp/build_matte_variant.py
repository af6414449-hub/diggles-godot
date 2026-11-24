#!/usr/bin/env python
"""Варианты заклейки фона главы кампании (панорама оригинала).

Та же логика, что в tools/build_panorama_backdrop.py, но с параметрами:
ширина куска панорамы и состав полос ландшафта. Пишет в out/, не трогает проект.
"""
from __future__ import annotations

import os
import sys

from PIL import Image
import numpy as np

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SOURCE = os.path.join(ROOT, "godot", "textures", "backdrop")
OUT = os.path.join(ROOT, "out", "campaign-shots")

WIDTH = 2048
HEIGHT = 1152
HORIZON_ROW = 320
GROUND_ROWS = 128
GROUND_TONE = (78, 70, 58)
ALPHA_THRESHOLD = 32


def load(index: int) -> Image.Image:
    return Image.open(os.path.join(SOURCE, "Panorama_layer_%d.tga" % index)).convert("RGBA")


def content_rows(image: Image.Image) -> int:
    width, height = image.size
    for y in range(height):
        row = [image.getpixel((x, y))[3] for x in range(0, width, 4)]
        if max(row) >= ALPHA_THRESHOLD:
            return y
    return height


def tone(image: Image.Image, target) -> Image.Image:
    array = np.asarray(image.convert("RGB"), dtype=np.float32)
    weights = np.array([0.299, 0.587, 0.114], dtype=np.float32)
    luma = array[:, :, 0] * weights[0] + array[:, :, 1] * weights[1] + array[:, :, 2] * weights[2]
    colour = np.array(target, dtype=np.float32)
    luma_target = float(colour @ weights)
    scale = (luma / max(luma_target, 1e-3))[:, :, None]
    out = np.clip(colour[None, None, :] * scale, 0, 255).astype(np.uint8)
    return Image.fromarray(out, "RGB")


def ground_tile(name: str = "Gnd_C01.tga") -> Image.Image:
    """Плитка земли карты (семейство C - земля): она бесшовная, в отличие от луга.

    У плиток земли альфа нулевая (движок берёт только цвет), поэтому она
    приводится к непрозрачной.
    """
    path = os.path.join(ROOT, "godot", "textures", "ground", name)
    image = Image.open(path).convert("RGBA")
    image.putalpha(255)
    return image


def build(slice_fraction: float, strips, name: str, ground_mode: str = "stretch",
          ground_source: str = "tile", ground_gain: float = 1.0) -> str:
    canvas = Image.new("RGBA", (WIDTH, HEIGHT), (215, 230, 252, 255))
    sky = load(0).resize((WIDTH, HEIGHT), Image.LANCZOS)
    canvas.alpha_composite(sky)
    meadow = load(5)
    ground_rows = GROUND_ROWS
    piece = meadow.crop((0, meadow.height - ground_rows, meadow.width, meadow.height))
    if ground_mode == "tile":
        # Земля мира за краем карты - плиткой земли карты: плитка бесшовная,
        # растянутый луг превращался в мыло.
        tile = ground_tile()
        tile = tile.resize((WIDTH, tile.size[1] * (WIDTH // tile.size[0])), Image.LANCZOS)
        target = HEIGHT - HORIZON_ROW
        ground = Image.new("RGB", (WIDTH, target))
        y = 0
        while y < target:
            ground.paste(tile.convert("RGB"), (0, y))
            y += tile.size[1]
        ground = ground.crop((0, 0, WIDTH, target))
    else:
        ground = piece.resize((WIDTH, HEIGHT - HORIZON_ROW), Image.LANCZOS)
    if ground_source == "meadow_tile":
        # Земля мира за краем карты - луг оригинала плиткой: террасы луга
        # остаются, а растяжения в 6.5 раза нет.
        block = piece.resize((WIDTH, GROUND_ROWS * (WIDTH // meadow.width)), Image.LANCZOS)
        target = HEIGHT - HORIZON_ROW
        ground = Image.new("RGB", (WIDTH, target))
        y = 0
        while y < target:
            ground.paste(block.convert("RGB"), (0, y))
            y += block.size[1]
        ground = ground.crop((0, 0, WIDTH, target))
    elif ground_source == "meadow":
        # Земля мира за краем карты - луг оригинала: в игре он яркий,
        # кислотно-желто-зеленый (до 213,192,47 в кадре владельца).
        array = np.asarray(ground.convert("RGB"), dtype=np.float32) * ground_gain
        ground = Image.fromarray(np.clip(array, 0, 255).astype(np.uint8), "RGB")
    else:
        ground = tone(ground, GROUND_TONE)
    canvas.alpha_composite(ground.convert("RGBA"), (0, HORIZON_ROW))
    for index, ridge in strips:
        strip = load(index)
        slice_width = max(1, int(strip.width * slice_fraction))
        left = (strip.width - slice_width) // 2
        piece = strip.crop((left, 0, left + slice_width, strip.height))
        first = content_rows(piece)
        share = 1.0 - float(first) / float(piece.height)
        height = int(round((HORIZON_ROW - ridge) / max(share, 0.0001)))
        piece = piece.resize((WIDTH, height), Image.LANCZOS)
        canvas.alpha_composite(piece, (0, HORIZON_ROW - height))
        print("  %s: layer %d ridge %d -> rows %d..%d (stretch %.1fx)"
              % (name, index, ridge, HORIZON_ROW - height, HORIZON_ROW,
                 WIDTH / float(slice_width)))
    path = os.path.join(OUT, name)
    canvas.convert("RGB").save(path)
    return path


def main() -> int:
    if not os.path.isdir(OUT):
        os.makedirs(OUT)
    # Вариант 1: текущий состав (3 полосы), но без растяжения по ширине.
    p1 = build(1.0, [(1, 92), (3, 132), (5, 252)], "zz-matte-A-fullslice.png")
    # Вариант 2: все шесть слоёв оригинала, широкий кусок.
    p2 = build(1.0, [(1, 92), (2, 140), (3, 190), (4, 250), (5, 272)], "zz-matte-B-alllayers.png")
    # Вариант 3: текущий состав и текущий кусок (эталон для сравнения).
    p3 = build(0.30, [(1, 92), (3, 132), (5, 252)], "zz-matte-C-current.png")
    # Вариант 4: по геометрии колец оригинала - над горизонтом облака, дымка,
    # горы и лес (лес стоит на горизонте), луг остаётся под горизонтом.
    p4 = build(1.0, [(1, 92), (2, 145), (3, 195), (4, 285)], "zz-matte-D-rings.png")
    # Вариант 5: то же, но без слоя дымки.
    p5 = build(1.0, [(1, 92), (3, 150), (4, 285)], "zz-matte-E-rings-nohaze.png")
    for path in (p1, p2, p3, p4, p5):
        print("wrote", path)
    return 0


if __name__ == "__main__":
    sys.exit(main())
