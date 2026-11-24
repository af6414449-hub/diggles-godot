# -*- coding: utf-8 -*-
"""The funnel: which order of the walls, and which shift of the stream."""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT
OFFSET = 3833300


def border(rng, materials):
    stone_gen.draw_stone(rng, materials, W, H, (0, 0, W, 32), 1, 3.0)
    stone_gen.draw_stone(rng, materials, W, H, (0, 0, 32, H + 4), 4, 1.0)
    stone_gen.draw_stone(rng, materials, W, H, (W - 32, 0, W, H + 4), 8, 1.0)


def funnel(rng, materials, right_first=True, shift=0):
    for _ in range(shift):
        rng.next_u32()
    band_width = 2 * (W // 4) - 20
    band_y = 16
    while band_width > 0:
        if right_first:
            stone_gen.draw_stone(rng, materials, W, H,
                                 (W - band_width, band_y, W, band_y + 6), 8, 1.0)
            stone_gen.draw_stone(rng, materials, W, H,
                                 (0, band_y, band_width, band_y + 6), 4, 1.0)
        else:
            stone_gen.draw_stone(rng, materials, W, H,
                                 (0, band_y, band_width, band_y + 6), 4, 1.0)
            stone_gen.draw_stone(rng, materials, W, H,
                                 (W - band_width, band_y, W, band_y + 6), 8, 1.0)
        band_width -= 8
        band_y += 4


def run(right_first=True, shift=0):
    rng = stone_gen.DigglesRandom(variant="canonical")
    for _ in range(OFFSET):
        rng.next_u32()
    materials = bytearray(W * H)
    for index in range(W * H):
        materials[index] = 2
    border(rng, materials)
    funnel(rng, materials, right_first, shift)
    return materials


def main():
    states = stone_gen.save_states()
    for right_first in (True, False):
        for shift in range(-3, 4):
            materials = run(right_first, shift)
            agree = 0
            total = 0
            for index in range(W * H):
                if (states[index] & 0x80) != 0:
                    continue
                generated = materials[index] == 0
                saved = (states[index] & 3) == 0
                total += 1
                if generated == saved:
                    agree += 1
            print("right_first=%-5s shift=%+d  agree %6d of %6d (%.3f%%)" % (
                right_first, shift, agree, total, 100.0 * agree / total))


if __name__ == "__main__":
    main()
