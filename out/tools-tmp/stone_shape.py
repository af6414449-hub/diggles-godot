# -*- coding: utf-8 -*-
"""The shape of the falloff, from the save alone.

The funnel is drawn last, so the stone of its walls is the decision of the
engine itself.  The share of the stone cells of a wall against the position in
the wall is the falloff of the engine - without the random.
"""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT


def main():
    states = stone_gen.save_states()

    def saved_stone(x, y):
        return (states[y * W + x] & 3) == 0

    def is_template(x, y):
        return (states[y * W + x] & 0x80) != 0

    print("=== the left wall of the funnel, band 0 (y 16..21, w 236) ===")
    band_width = 236
    for band in (0, 5, 15, 29):
        band_width = 236 - 8 * band
        band_y = 16 + 4 * band
        span_x = band_width
        falloff = stone_gen.f32(1.0 / stone_gen.f32(min(span_x, 6) * 0.2))
        centre = span_x // 2
        print("--- band %d: y %d..%d, wall width %d, centre %d" % (
            band, band_y, band_y + 5, span_x, centre))
        for row in range(band_y, band_y + 6):
            parts = []
            for x in range(0, span_x - 1):
                if is_template(x, row):
                    continue
                p = 1.0
                if x > centre:
                    d = stone_gen.f32(centre - x)
                    p = stone_gen.f32(1.0 - stone_gen.f32(stone_gen.f32(
                        stone_gen.f32(d / span_x) * d) / span_x) / falloff)
                parts.append((x, p, saved_stone(x, row)))
            # the share of the stone against the share of the model
            count = len(parts)
            if not count:
                continue
            stone = sum(1 for _, _, s in parts if s)
            model = sum(p for _, p, _ in parts) / count
            print("  y=%d cells %4d  stone %5.1f%%  model %5.1f%%" % (
                row, count, 100.0 * stone / count, 100.0 * model))

    print()
    print("=== the top band of the border, rows 17..30, the cells that the")
    print("    funnel does not touch (x 269..300) ===")
    falloff = stone_gen.f32(3.0 / stone_gen.f32(32 * 0.2))
    for row in range(16, 32):
        p = 1.0
        if row > 16:
            d = stone_gen.f32(16 - row)
            p = stone_gen.f32(1.0 - stone_gen.f32(stone_gen.f32(
                stone_gen.f32(d / 32) * d) / 32) / falloff)
        cells = [(x, saved_stone(x, row)) for x in range(269, 301)
                 if not is_template(x, row)]
        stone = sum(1 for _, s in cells if s)
        print("  y=%d cells %3d  stone %5.1f%%  model %5.1f%%" % (
            row, len(cells), 100.0 * stone / max(1, len(cells)), 100.0 * p))


if __name__ == "__main__":
    main()
