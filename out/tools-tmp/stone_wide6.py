# -*- coding: utf-8 -*-
"""The place of the stream, with the shape of the first phase as a variable.

The first phase of the stone is one of the three bands of the border.  The
stride of the cells in the stream is the height of the band, and the order of
the cells is the outer loop over x and the inner loop over y.
"""
import pathlib
import sys
import time

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT
LIMIT = 3000000


def band_cells(states, kind):
    """The informative cells of a band of the border, with their place."""
    cells = []
    if kind == "top":
        x1, y1, x2, y2 = 0, 0, W - 1, 32
        strength, flags = 3.0, 1
        stride = 31
        cy = 16
        cx = 256
    elif kind == "left":
        x1, y1, x2, y2 = 0, 0, 32, H + 4
        strength, flags = 1.0, 4
        stride = 639
        cy = 320
        cx = 16
    else:
        x1, y1, x2, y2 = W - 32, 0, W, H + 4
        strength, flags = 1.0, 8
        stride = 639
        cy = 320
        cx = W - 16
    falloff = strength / (min(x2 - x1, y2 - y1) * 0.2)
    for x in range(x1, x2 - 1):
        for y in range(y1, y2 - 1):
            index = y * W + x
            if (states[index] & 0x80) != 0:
                continue
            probability = 1.0
            if (flags & 4) and x > cx:
                d = float(cx - x)
                probability = 1.0 - ((d / (x2 - x1)) * d / (x2 - x1)) / falloff
            if (flags & 8) and x < cx:
                d = float(cx - x)
                probability -= ((d / (x2 - x1)) * d / (x2 - x1)) / falloff
            if (flags & 1) and y > cy:
                d = float(cy - y)
                probability -= ((d / (y2 - y1)) * d / (y2 - y1)) / falloff
            if probability >= 0.95 or probability <= 0.05:
                continue
            cells.append((x * stride + y, index, probability))
    return cells


def main():
    states = stone_gen.save_states()
    rng = stone_gen.DigglesRandom(variant="canonical")
    numbers = []
    for _ in range(LIMIT + 20000):
        numbers.append(rng.next_u32())

    for kind in ("top", "left", "right"):
        cells = band_cells(states, kind)
        cells.sort(key=lambda item: abs(item[2] - 0.5))
        picked = cells[:40]
        offsets = [item[0] for item in picked]
        thresholds = [item[2] * 32768.0 for item in picked]
        decisions = [(states[item[1]] & 3) == 0 for item in picked]
        count = len(picked)
        best = (0, -1)
        start_time = time.time()
        for start in range(0, LIMIT - max(offsets) - 2):
            agree = 0
            for step in range(count):
                value = numbers[start + offsets[step]] & 0x7FFF
                if (value <= thresholds[step]) == decisions[step]:
                    agree += 1
                else:
                    break
            if agree > best[0]:
                best = (agree, start)
                if agree == count:
                    break
        print("%-6s cells %4d  best %3d of %d at %d  (%.0f s)" % (
            kind, len(cells), best[0], count, best[1], time.time() - start_time))


if __name__ == "__main__":
    main()
