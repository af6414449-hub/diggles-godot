"""Periodicity scan of a capture region at several candidate periods.

The grid visible on the ground can come from two sources:
  - the continuous ground field, whose canvas covers 16 cells and repeats;
  - the native tiles, one 64x64 tile per cell.

The two have different periods in pixels, so the gradient profile at several
periods tells them apart: a peak at the period boundary means a grid of that
period.

Usage: python period_scan.py <image> x y w h [period ...]
"""
from __future__ import annotations

import sys

from PIL import Image


def gradient_profile(image: Image.Image, box: tuple[int, int, int, int], period: int) -> tuple[list[float], list[float]]:
    crop = image.convert("RGB").crop(box)
    width, height = crop.size
    px = crop.load()
    hsum = [0.0] * period
    hcount = [0] * period
    vsum = [0.0] * period
    vcount = [0] * period
    for x in range(width - 1):
        phase = x % period
        for y in range(height):
            a = px[x, y]
            b = px[x + 1, y]
            hsum[phase] += sum(abs(a[i] - b[i]) for i in range(3)) / 3.0
            hcount[phase] += 1
    for y in range(height - 1):
        phase = y % period
        for x in range(width):
            a = px[x, y]
            b = px[x, y + 1]
            vsum[phase] += sum(abs(a[i] - b[i]) for i in range(3)) / 3.0
            vcount[phase] += 1
    h = [hsum[i] / max(hcount[i], 1) for i in range(period)]
    v = [vsum[i] / max(vcount[i], 1) for i in range(period)]
    return h, v


def report(label: str, values: list[float]) -> None:
    mean = sum(values) / len(values)
    boundary = (values[0] + values[-1]) / 2
    inside = [v for i, v in enumerate(values) if i not in (0, len(values) - 1)]
    inside_mean = sum(inside) / len(inside)
    peak = max(values)
    phase = values.index(peak)
    print(
        f"    {label}: mean={mean:.2f} boundary={boundary:.2f} inside={inside_mean:.2f} "
        f"-> boundary/inside={boundary / max(inside_mean, 0.01):.3f} "
        f"peak phase {phase} = {peak:.2f} ({peak / max(mean, 0.01):.2f}x)"
    )


def main() -> None:
    path = sys.argv[1]
    x, y, w, h = (int(v) for v in sys.argv[2:6])
    periods = [int(v) for v in sys.argv[6:]] or [16, 32, 40, 64, 128]
    image = Image.open(path)
    print(f"{path} region=({x},{y},{w},{h}) size={image.size}")
    for period in periods:
        print(f"  period {period} px")
        hprof, vprof = gradient_profile(image, (x, y, x + w, y + h), period)
        report("horizontal", hprof)
        report("vertical  ", vprof)


if __name__ == "__main__":
    main()
