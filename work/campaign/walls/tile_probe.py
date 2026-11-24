"""Probe the native ground tiles that are already in the project.

Reports the size of every texture family in godot/textures/ground and the
seam strength between neighbouring tiles of the Gnd_A/B/C families.
"""
from __future__ import annotations

import glob
import os
from collections import defaultdict

from PIL import Image

GROUND = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\textures\ground"


def families() -> dict[str, list[str]]:
    out: dict[str, list[str]] = defaultdict(list)
    for path in sorted(glob.glob(os.path.join(GROUND, "*.tga"))):
        name = os.path.splitext(os.path.basename(path))[0]
        if name.startswith("Gnd_"):
            key = name[:5]
        elif name.startswith("Native_"):
            key = "Native"
        else:
            key = "other"
        out[key].append(path)
    return out


def mean_rgb(image: Image.Image) -> tuple[float, float, float]:
    rgb = image.convert("RGB")
    px = list(rgb.getdata())
    n = len(px)
    return (
        sum(p[0] for p in px) / n,
        sum(p[1] for p in px) / n,
        sum(p[2] for p in px) / n,
    )


def seam(edges: list[Image.Image]) -> float:
    """Mean absolute difference between the right edge of a tile and the left edge of the next."""
    total = 0.0
    count = 0
    for a, b in zip(edges, edges[1:]):
        ra = list(a.convert("RGB").getdata())
        rb = list(b.convert("RGB").getdata())
        w = a.width
        for y in range(a.height):
            pa = ra[y * w + (w - 1)]
            pb = rb[y * w + 0]
            total += sum(abs(pa[i] - pb[i]) for i in range(3)) / 3.0
            count += 1
    return total / max(count, 1)


def main() -> None:
    fams = families()
    for key in sorted(fams):
        sizes = set()
        for path in fams[key]:
            sizes.add(Image.open(path).size)
        print(f"{key:8s} files={len(fams[key]):3d} sizes={sorted(sizes)}")

    print()
    for key in ("Gnd_A", "Gnd_B", "Gnd_C"):
        paths = fams.get(key, [])
        if not paths:
            continue
        tiles = [Image.open(p) for p in paths]
        means = [mean_rgb(t) for t in tiles]
        lum = [0.299 * m[0] + 0.587 * m[1] + 0.114 * m[2] for m in means]
        inner = seam(tiles)
        print(
            f"{key}: tiles={len(tiles)} "
            f"luma min={min(lum):.1f} max={max(lum):.1f} mean={sum(lum)/len(lum):.1f} "
            f"| seam(next)={inner:.1f}"
        )
        # seam of a tile against itself as the noise floor
        same = seam([tiles[0]] * 2)
        print(f"       noise floor (self-seam) = {same:.1f}  ->  ratio = {inner / max(same, 0.01):.2f}")


if __name__ == "__main__":
    main()
