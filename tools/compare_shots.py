#!/usr/bin/env python3
"""Кроп «до/после» по одному региону главы.

Берёт два кадра одинакового размера, вырезает из них один и тот же прямоугольник
и склеивает в одну картинку (сверху — «до», снизу — «после»). Нужно для визуальной
приёмки: видно, что уехало по высоте и что исчезло.

Запуск:
    python tools/compare_shots.py before.png after.png out.png x0 y0 x1 y1 [масштаб]
"""
from __future__ import annotations

import sys
from pathlib import Path

from PIL import Image, ImageDraw


def main() -> int:
    before_path, after_path, out_path = sys.argv[1], sys.argv[2], sys.argv[3]
    x0, y0, x1, y1 = (int(v) for v in sys.argv[4:8])
    scale = float(sys.argv[8]) if len(sys.argv) > 8 else 1.0

    before = Image.open(before_path).convert("RGB")
    after = Image.open(after_path).convert("RGB")
    box = (x0, y0, x1, y1)
    left = before.crop(box)
    right = after.crop(box)
    if scale != 1.0:
        size = (int(left.width * scale), int(left.height * scale))
        left = left.resize(size, Image.LANCZOS)
        right = right.resize(size, Image.LANCZOS)

    header = 26
    canvas = Image.new("RGB", (left.width, left.height * 2 + header * 2), (16, 16, 16))
    draw = ImageDraw.Draw(canvas)
    draw.text((6, 6), "BEFORE: " + Path(before_path).name, fill=(255, 220, 120))
    canvas.paste(left, (0, header))
    draw.text((6, header + left.height + 6),
              "AFTER: " + Path(after_path).name, fill=(140, 230, 255))
    canvas.paste(right, (0, header * 2 + left.height))
    canvas.save(out_path)
    print(f"{out_path}: {canvas.width}x{canvas.height}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
