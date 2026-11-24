# -*- coding: utf-8 -*-
"""The search of the place of the stream, with the exact order of the draws.

The number of the engine is taken only for a cell of a loose ground, so the
cells that the border already made stone take no number.  The fingerprint is
the first phase alone (the top band of the border): there every cell of the
rectangle takes a number, so the place of a cell in the stream is known
exactly.
"""
import pathlib
import sys
import time

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT
LIMIT = 6000000


def top_band_cells(states):
    """The cells of the top band that the funnel does not write over."""
    cells = []
    for x in range(W - 1):
        for y in range(31):
            index = y * W + x
            if (states[index] & 0x80) != 0:
                continue
            covered = False
            band_width = 2 * (W // 4) - 20
            band_y = 16
            while band_width > 0:
                if y >= band_y and y < band_y + 6:
                    if x < band_width - 1 or x >= W - band_width:
                        covered = True
                        break
                band_width -= 8
                band_y += 4
            if covered:
                continue
            probability = 1.0
            if y > 16:
                falloff = 3.0 / (32 * 0.2)
                distance = float(16 - y)
                probability = 1.0 - ((distance / 32.0) * distance / 32.0) / falloff
            if probability >= 0.99 or probability <= 0.05:
                continue
            cells.append((x * 31 + y, index, probability))
    return cells


def main():
    states = stone_gen.save_states()
    cells = top_band_cells(states)
    print("the cells of the fingerprint: %d" % len(cells))
    if not cells:
        print("no cell")
        return
    # the cells with the probability nearest to one half
    cells.sort(key=lambda item: abs(item[2] - 0.5))
    picked = cells[:24]
    print("the offsets of the fingerprint: %s" % [item[0] for item in picked[:6]])
    thresholds = [item[2] * 32768.0 for item in picked]
    decisions = [(states[item[1]] & 3) == 0 for item in picked]

    rng = stone_gen.DigglesRandom(variant="canonical")
    numbers = []
    append = numbers.append
    for _ in range(LIMIT):
        append(rng.next_u32())
    print("the stream is ready")

    best = (0, -1)
    start_time = time.time()
    for start in range(0, LIMIT - len(picked) - 2):
        agree = 0
        for step in range(len(picked)):
            value = numbers[start + step] & 0x7FFF
            if (value <= thresholds[step]) == decisions[step]:
                agree += 1
            else:
                break
        if agree > best[0]:
            best = (agree, start)
            if agree == len(picked):
                break
    print("the best %d of %d at %d  (%.0f s)" % (
        best[0], len(picked), best[1], time.time() - start_time))


if __name__ == "__main__":
    main()
