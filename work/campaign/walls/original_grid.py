"""Does the original show a 64 px tile grid on the ground of the map?

Two checks on the original screenshots:
  1. a periodicity scan along a scanline (autocorrelation) that would reveal
     a repeating grid of the native tile size;
  2. a zoom crop for visual inspection.

Usage: python original_grid.py <image> [x y w h]
"""
from __future__ import annotations

import sys

from PIL import Image

SHOTS = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\out\original-shots"


def periodicity(image: Image.Image, period: int = 64, span: int = 40) -> tuple[float, float]:
    """Mean absolute difference between columns i and i+period vs neighbouring columns."""
    rgb = image.convert("RGB")
    width, height = rgb.size
    px = rgb.load()
    step = max(1, period // 2)

    same = 0.0
    same_n = 0
    near = 0.0
    near_n = 0
    for x in range(0, width - period, step):
        for y in range(0, height, 3):
            a = px[x, y]
            b = px[x + period, y]
            c = px[x + 1, y]
            same += sum(abs(a[i] - b[i]) for i in range(3)) / 3.0
            same_n += 1
            near += sum(abs(a[i] - c[i]) for i in range(3)) / 3.0
            near_n += 1
    return (same / max(same_n, 1), near / max(near_n, 1))


def main() -> None:
    name = sys.argv[1] if len(sys.argv) > 1 else "steam_05_big.png"
    path = f"{SHOTS}\\{name}"
    image = Image.open(path)
    print(f"{name}: {image.size}")

    if len(sys.argv) > 5:
        x, y, w, h = (int(v) for v in sys.argv[2:6])
        crop = image.crop((x, y, x + w, y + h)).resize((w * 2, h * 2), Image.NEAREST)
        out = f"{SHOTS}\\{name.replace('.png', '')}_grid_zoom.png"
        crop.save(out)
        print("zoom saved:", out)

    for period in (32, 64, 128):
        same, near = periodicity(image, period)
        print(
            f"  period={period:4d}px: column(i) vs column(i+{period}) = {same:5.2f} | "
            f"column(i) vs column(i+1) = {near:5.2f} | ratio = {same / max(near, 0.01):.3f}"
        )


if __name__ == "__main__":
    main()
