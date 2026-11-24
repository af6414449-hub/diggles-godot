# -*- coding: utf-8 -*-
"""The first phase alone: the top band of the border.

In that phase every cell of the rectangle takes a number, so the place of the
cell in the stream is known exactly.  The agreement of that phase tells whether
the place of the stream is the right one.
"""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402
import stone_wide3  # noqa: E402

W = stone_gen.MAP_WIDTH


def phase_agreement(numbers, start, states, cells):
    agree = 0
    for offset, index, probability in cells:
        value = numbers[start + offset] & 0x7FFF
        saved = (states[index] & 3) == 0
        if saved == (value <= probability * 32768.0):
            agree += 1
    return agree


def main():
    states = stone_gen.save_states()
    cells = stone_wide3.top_band_cells(states)
    print("the informative cells of the top band: %d" % len(cells))

    rng = stone_gen.DigglesRandom(variant="canonical")
    numbers = []
    for _ in range(2400000):
        numbers.append(rng.next_u32())

    for start in (2158435, 3833300, 1313069, 1141528, 1000, 200000, 2399000):
        if start + 16000 >= len(numbers):
            continue
        agree = phase_agreement(numbers, start, states, cells)
        print("  at %8d : %4d of %d" % (start, agree, len(cells)))


if __name__ == "__main__":
    main()
