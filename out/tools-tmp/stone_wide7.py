# -*- coding: utf-8 -*-
"""The place of the stone phase in the stream of the engine, a wide search.

The fingerprint is every informative cell of the top band of the border: in
that first phase every cell of the rectangle takes a number, so the place of a
cell in the stream is known exactly.
"""
import pathlib
import sys
import time

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402
import stone_wide3  # noqa: E402

W = stone_gen.MAP_WIDTH
LIMIT = 30000000


def main():
    states = stone_gen.save_states()
    cells = stone_wide3.top_band_cells(states)
    print("the cells of the fingerprint: %d" % len(cells))
    offsets = [item[0] for item in cells]
    thresholds = [item[2] * 32768.0 for item in cells]
    decisions = [(states[item[1]] & 3) == 0 for item in cells]
    count = len(cells)

    rng = stone_gen.DigglesRandom(variant="canonical")
    numbers = []
    append = numbers.append
    for _ in range(LIMIT + 20000):
        append(rng.next_u32())
    print("the stream is ready: %d" % len(numbers))

    best = (0, -1)
    started = time.time()
    for start in range(0, LIMIT):
        agree = 0
        for step in range(count):
            value = numbers[start + offsets[step]] & 0x7FFF
            if (value <= thresholds[step]) == decisions[step]:
                agree += 1
            else:
                break
        if agree > best[0]:
            best = (agree, start)
            print("   %d of %d at %d  (%.0f s)" % (agree, count, start, time.time() - started))
            if agree == count:
                break
    print("the best: %d of %d at %d" % (best[0], count, best[1]))


if __name__ == "__main__":
    main()
