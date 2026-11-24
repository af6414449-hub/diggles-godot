"""Is there a 64 px tile grid on the ground in the original?

The port and the original disagree about the ground of the map:
  - the port draws one continuous field per family (tools/build_ground_field.py);
  - the original is said to draw one native 64 px tile per cell.

A tile grid leaves a periodic EDGE: the horizontal gradient of the image must
spike at x = 0 (mod 64) and the vertical gradient at y = 0 (mod 64). This tool
measures the gradient of the ground region as a function of the position inside
the 64 px period. A flat profile means no grid; a spike at the period boundary
means a grid.

Usage: python grid_detect.py <image> [x y w h]
"""
from __future__ import annotations

import sys

from PIL import Image


def profile(image: Image.Image, box: tuple[int, int, int, int]) -> tuple[list[float], list[float]]:
    crop = image.convert("RGB").crop(box)
    width, height = crop.size
    px = crop.load()

    # horizontal gradient per column phase, vertical gradient per row phase
    hsum = [0.0] * 64
    hcount = [0] * 64
    vsum = [0.0] * 64
    vcount = [0] * 64
    for x in range(width - 1):
        phase = x % 64
        for y in range(height):
            a = px[x, y]
            b = px[x + 1, y]
            hsum[phase] += sum(abs(a[i] - b[i]) for i in range(3)) / 3.0
            hcount[phase] += 1
    for y in range(height - 1):
        phase = y % 64
        for x in range(width):
            a = px[x, y]
            b = px[x, y + 1]
            vsum[phase] += sum(abs(a[i] - b[i]) for i in range(3)) / 3.0
            vcount[phase] += 1
    h = [hsum[i] / max(hcount[i], 1) for i in range(64)]
    v = [vsum[i] / max(vcount[i], 1) for i in range(64)]
    return h, v


def report(name: str, values: list[float], period: int = 64) -> None:
    mean = sum(values) / len(values)
    # the phase that carries the boundary of a cell: the last column of the
    # cell is at phase 63, the first of the next at phase 0
    edge = values[period - 1] + values[0]
    rest = [v for i, v in enumerate(values) if i not in (0, period - 1)]
    rest_mean = sum(rest) / len(rest)
    peak = max(values)
    peak_phase = values.index(peak)
    print(
        f"  {name}: mean={mean:.2f} | boundary phases(0,63)={edge / 2:.2f} "
        f"vs inside mean={rest_mean:.2f} -> boundary/inside = {edge / 2 / max(rest_mean, 0.01):.3f} "
        f"| peak phase={peak_phase} ({peak:.2f}, {peak / max(mean, 0.01):.2f}x)"
    )


def main() -> None:
    path = sys.argv[1]
    image = Image.open(path)
    if len(sys.argv) > 5:
        x, y, w, h = (int(v) for v in sys.argv[2:6])
        box = (x, y, x + w, y + h)
    else:
        box = (0, 0, image.size[0], image.size[1])
    print(f"{path} region={box} size={image.size}")
    hprof, vprof = profile(image, box)
    report("horizontal gradient by phase", hprof)
    report("vertical   gradient by phase", vprof)


if __name__ == "__main__":
    main()
