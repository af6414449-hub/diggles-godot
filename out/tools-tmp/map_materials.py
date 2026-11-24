#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Рисует план материалов карты главы (по правилу оригинала или по сейву).

Запуск: python out/tools-tmp/map_materials.py [out.png]
"""
import json
import os
import sys

from PIL import Image, ImageDraw

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
MODELS = os.path.join(ROOT, "godot", "models")
W, H = 512, 640

COLORS = {
    0: (120, 118, 112),   # камень (гранит)
    1: (196, 176, 120),   # песок
    2: (110, 84, 58),     # земля
    3: (70, 66, 60),      # порода главы
}
NO_GROUND = (24, 24, 28)


def rle(path, mask=False):
    data = json.load(open(path, encoding="utf-8"))
    out = bytearray(W * H)
    idx = 0
    for value, count in data["runs"]:
        v = int(value) & (255 if mask else 3)
        for _ in range(int(count)):
            if idx >= len(out):
                break
            out[idx] = v
            idx += 1
    return out


def main() -> int:
    ground = rle(os.path.join(MODELS, "native_campaign_ground_mask.json"), mask=True)
    state = rle(os.path.join(MODELS, "native_campaign_ground_material.json"))
    image = Image.new("RGB", (W, H), NO_GROUND)
    draw = ImageDraw.Draw(image)
    for y in range(H):
        for x in range(W):
            if ground[y * W + x] == 0:
                continue
            draw.point((x, y), COLORS.get(state[y * W + x], (200, 0, 200)))
    # контур острова
    for y in range(H):
        for x in range(W):
            if ground[y * W + x] != 0:
                continue
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nx, ny = x + dx, y + dy
                if 0 <= nx < W and 0 <= ny < H and ground[ny * W + nx] != 0:
                    draw.point((x, y), (240, 240, 40))
                    break
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "out", "campaign-shots", "zz-map-materials.png")
    image.save(out)
    print("wrote", out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
