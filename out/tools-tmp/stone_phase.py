# -*- coding: utf-8 -*-
"""Which phase of the engine decided every cell that differs."""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402
import stone_verify  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT


def phases():
    """The rectangles of the engine, in the order of the calls."""
    calls = [("top", (0, 0, W, 32), 1, 3.0),
             ("left", (0, 0, 32, H + 4), 4, 1.0),
             ("right", (W - 32, 0, W, H + 4), 8, 1.0)]
    band_width = 2 * (W // 4) - 20
    band_y = 16
    while band_width > 0:
        calls.append(("funnel-right-%d" % band_y, (W - band_width, band_y, W, band_y + 6), 8, 1.0))
        calls.append(("funnel-left-%d" % band_y, (0, band_y, band_width, band_y + 6), 4, 1.0))
        band_width -= 8
        band_y += 4
    return calls


def main():
    states = stone_gen.save_states()
    rng = stone_gen.DigglesRandom(variant="canonical")
    for _ in range(stone_verify.OFFSET):
        rng.next_u32()
    materials = bytearray(W * H)
    for index in range(W * H):
        materials[index] = 2
    stone_verify.stone_phase(rng, materials)

    calls = phases()
    last = {}
    for order, (name, rect, flags, strength) in enumerate(calls):
        x1 = max(rect[0], 0)
        y1 = max(rect[1], 0)
        x2 = min(rect[2], W)
        y2 = min(rect[3], H)
        for x in range(x1, x2 - 1):
            for y in range(y1, y2 - 1):
                last[y * W + x] = order

    counts = {}
    for index in range(W * H):
        generated = materials[index] == 0
        saved = (states[index] & 3) == 0
        if generated == saved:
            continue
        name = calls[last.get(index, 0)][0]
        key = (name, generated, saved)
        counts[key] = counts.get(key, 0) + 1
    print("the cells that differ, by the phase that decided them:")
    for key in sorted(counts):
        print("   %-20s generated %-5s saved %-5s : %d"
              % (key[0], key[1], key[2], counts[key]))

    print()
    print("the top band of the border, row by row, the cells of the funnel gap:")
    for y in range(16, 34):
        cells = [x for x in range(269, 301)]
        agree = sum(1 for x in cells
                    if (materials[y * W + x] == 0) == ((states[y * W + x] & 3) == 0))
        print("   y=%2d  agree %2d of %d" % (y, agree, len(cells)))


if __name__ == "__main__":
    main()
