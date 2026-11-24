# -*- coding: utf-8 -*-
"""Which random stream is the original one?

The cells with p < 1 are decided by the random number of the engine, so they
are the fingerprint of the stream.  The cells with p == 1 are stone in every
variant, so they say nothing about the stream.
"""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT


def generate_with_probability(systeminit=True, variant="mapgen"):
    """The same as stone_gen.generate, but it keeps the probability of a cell."""
    rng = stone_gen.DigglesRandom(variant="canonical")
    materials = bytearray(W * H)
    variations = bytearray(W * H)
    probability = [1.0] * (W * H)

    def mapgen(width, height):
        for y in range(height):
            row = y * width
            for x in range(width):
                value = rng.next_u32()
                materials[row + x] = 2
                variations[row + x] = ((value >> 18) ^ value) & 0xFF

    if systeminit:
        rng.variant = variant
        mapgen(64, 64)
    rng.variant = variant
    mapgen(W, H)
    rng.variant = "canonical"

    def draw(rect, flags, strength):
        x1 = max(rect[0], 0)
        y1 = max(rect[1], 0)
        x2 = min(rect[2], W)
        y2 = min(rect[3], H)
        if x1 >= x2 or y1 >= y2:
            return
        span_x = x2 - x1
        span_y = y2 - y1
        falloff = stone_gen.f32(strength / stone_gen.f32(min(span_x, span_y) * 0.2))
        centre_x = x1 + span_x // 2
        centre_y = y1 + span_y // 2
        for x in range(x1, x2 - 1):
            for y in range(y1, y2 - 1):
                p = 1.0
                if (flags & 4) and x > centre_x:
                    d = stone_gen.f32(centre_x - x)
                    p = stone_gen.f32(1.0 - stone_gen.f32(stone_gen.f32(
                        stone_gen.f32(d / span_x) * d) / span_x) / falloff)
                if (flags & 8) and x < centre_x:
                    d = stone_gen.f32(centre_x - x)
                    p = stone_gen.f32(p - stone_gen.f32(stone_gen.f32(
                        stone_gen.f32(d / span_x) * d) / span_x) / falloff)
                if (flags & 1) and y > centre_y:
                    d = stone_gen.f32(centre_y - y)
                    p = stone_gen.f32(p - stone_gen.f32(stone_gen.f32(
                        stone_gen.f32(d / span_y) * d) / span_y) / falloff)
                if (flags & 2) and y < centre_y:
                    d = stone_gen.f32(centre_y - y)
                    p = stone_gen.f32(p - stone_gen.f32(stone_gen.f32(
                        stone_gen.f32(d / span_y) * d) / span_y) / falloff)
                index = y * W + x
                if materials[index] != 1 and materials[index] != 2:
                    continue
                probability[index] = p
                number = rng.next_u32() & 0x7FFF
                if float(number) <= p * 32768.0:
                    materials[index] = 0

    draw((0, 0, W, 32), 1, 3.0)
    draw((0, 0, 32, H + 4), 4, 1.0)
    draw((W - 32, 0, W, H + 4), 8, 1.0)
    band_width = 2 * (W // 4) - 20
    band_y = 16
    while band_width > 0:
        draw((W - band_width, band_y, W, band_y + 6), 8, 1.0)
        draw((0, band_y, band_width, band_y + 6), 4, 1.0)
        band_width -= 8
        band_y += 4
    return materials, probability


def main():
    states = stone_gen.save_states()
    # The cells of the template of the chapter are not the map: they carry the
    # rock of the template (0x80) and they are dug out by it.
    def is_map_cell(index):
        return (states[index] & 0x80) == 0

    candidates = {}
    for systeminit in (True, False):
        for variant in ("mapgen", "canonical"):
            candidates["init=%s variant=%s" % (systeminit, variant)] = \
                generate_with_probability(systeminit, variant)

    for label, (materials, probability) in candidates.items():
        random_cells = 0
        agree = 0
        for index in range(W * H):
            if probability[index] >= 1.0:
                continue
            if not is_map_cell(index):
                continue
            random_cells += 1
            saved_stone = (states[index] & 3) == 0
            if saved_stone == (materials[index] == 0):
                agree += 1
        print("%-28s random cells %6d  agree %6d  %5.1f%%"
              % (label, random_cells, agree, 100.0 * agree / max(1, random_cells)))


if __name__ == "__main__":
    main()
