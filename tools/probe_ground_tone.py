#!/usr/bin/env python
"""Меряет тон земли мира матки и тон грунта доски в кадре порта.

Задача: «земля мира» за краем острова в порту — растянутые нижние строки луга
оригинала, и в родном кадре они читаются кислотно жёлто-зелёными. Палитра
оригинала приглушённая (rock grey-brown, мшистый зелёный), поэтому тон надо
привести к тону грунта доски, который порт рисует родной текстурой земли.

Запуск: python tools/probe_ground_tone.py
"""
from __future__ import annotations

import os
import sys

from PIL import Image

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "out", "backdrop-2026-11-21")
MATTE = os.path.join(ROOT, "godot", "textures", "backdrop", "campaign_panorama.png")
FRAME = os.path.join(OUT, "i1-native-skybg.png")

# Окна кадра, которые меряются (левый верхний угол, правый нижний).
#  - world_ground: кусок «земли мира» матки в кадре порта (верх кадра);
#  - board_ground: свободный грунт доски (кирпичное поле) в том же кадре.
REGIONS_FRAME = {
    "world_ground": (40, 40, 200, 140),
    "board_ground": (900, 430, 1150, 560),
}


def mean_rgb(image: Image.Image, box: tuple[int, int, int, int]) -> tuple[int, int, int]:
    patch = image.convert("RGB").crop(box)
    pixels = list(patch.getdata())
    count = max(1, len(pixels))
    return tuple(sum(p[i] for p in pixels) // count for i in range(3))


def saturation(rgb: tuple[int, int, int]) -> float:
    high = max(rgb)
    low = min(rgb)
    return 0.0 if high == 0 else (high - low) / high


def main() -> int:
    if not os.path.isfile(FRAME) or not os.path.isfile(MATTE):
        print("no frame or no matte")
        return 1
    frame = Image.open(FRAME)
    print("frame %dx%d" % frame.size)
    measured = {}
    for name, box in REGIONS_FRAME.items():
        rgb = mean_rgb(frame, box)
        measured[name] = rgb
        print("  %-13s rgb=%s  saturation=%.3f" % (name, rgb, saturation(rgb)))
    matte = Image.open(MATTE)
    ground = mean_rgb(matte, (0, 432, 2048, 1152))
    print("  matte ground  rgb=%s  saturation=%.3f" % (ground, saturation(ground)))
    board = measured["board_ground"]
    print("difference of the tones: %s" % (
        tuple(ground[i] - board[i] for i in range(3)),))
    return 0


if __name__ == "__main__":
    sys.exit(main())
