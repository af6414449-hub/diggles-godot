# -*- coding: utf-8 -*-
"""Where the stone of the generator and the stone of the save differ."""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402

try:
    from PIL import Image
except ImportError:
    Image = None

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT


def build(systeminit=True, variant="mapgen"):
    materials, variations = stone_gen.generate(systeminit=systeminit,
                                                mapgen_variant=variant)
    states = stone_gen.save_states()
    buckets = {}
    image = Image.new("RGB", (W, H), (0, 0, 0)) if Image else None
    pixels = image.load() if image else None
    for index in range(W * H):
        x = index % W
        y = index // W
        generated = materials[index] == 0
        saved = (states[index] & 3) == 0
        template = (states[index] & 0x80) != 0
        if generated and saved:
            colour = (220, 220, 220)
            key = "both"
        elif saved and not generated:
            colour = (255, 40, 40)
            key = "save only"
        elif generated and not saved:
            colour = (40, 220, 60)
            key = "gen only"
        else:
            colour = (20, 20, 30)
            key = "earth"
        if template and not generated:
            colour = (60, 90, 255)
            key = "template"
        if pixels is not None:
            pixels[x, y] = colour
        if y < 160:
            region = "top"
        elif y < 640:
            region = "middle"
        else:
            region = "bottom"
        buckets.setdefault((region, key), 0)
        buckets[(region, key)] += 1
    return image, buckets


def main():
    for systeminit in (True, False):
        for variant in ("mapgen", "canonical"):
            image, buckets = build(systeminit, variant)
            print("=== init=%s variant=%s" % (systeminit, variant))
            for region in ("top", "middle", "bottom"):
                parts = ["%s=%d" % (key, count) for (reg, key), count in
                         sorted(buckets.items()) if reg == region]
                print("  %-7s %s" % (region, "  ".join(parts)))
            if image is not None:
                name = "zz-gen-%s-%s.png" % (systeminit, variant)
                image.save(pathlib.Path(__file__).resolve().parent / name)
                print("  written %s" % name)


if __name__ == "__main__":
    main()
