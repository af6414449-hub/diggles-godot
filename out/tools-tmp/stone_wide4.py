# -*- coding: utf-8 -*-
"""The place of the stone phase in the stream of the engine.

The fingerprint is every informative cell of the top band of the border: in
that first phase every cell of the rectangle takes a number, so the place of a
cell in the stream is known exactly.  A wrong place disagrees with the first
cell of the fingerprint, so the search is cheap.
"""
import pathlib
import sys
import time

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402
import stone_wide3  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT
LIMIT = 4000000


def build_stream(count, switches):
    """The numbers of the engine: the twist of the mapgen up to the switches."""
    rng = stone_gen.DigglesRandom(variant="mapgen")
    numbers = []
    append = numbers.append
    switch = sorted(switches)
    for index in range(count):
        while switch and index == switch[0]:
            rng.variant = "canonical"
            switch.pop(0)
        append(rng.next_u32())
    return numbers


def main():
    states = stone_gen.save_states()
    cells = stone_wide3.top_band_cells(states)
    print("the cells of the fingerprint: %d" % len(cells))
    offsets = [item[0] for item in cells]
    thresholds = [item[2] * 32768.0 for item in cells]
    decisions = [(states[item[1]] & 3) == 0 for item in cells]
    count = len(cells)

    histories = (
        ("canonical", []),
        ("mapgen 4096", [4096]),
        ("mapgen 331776", [4096 + W * H]),
        ("mapgen 4096+327680", [4096 + W * H]),
    )
    for label, switches in histories[:3]:
        start_time = time.time()
        numbers = build_stream(LIMIT + 20000, list(switches))
        best = (0, -1)
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
                if agree == count:
                    break
        print("%-20s best %3d of %d at %d  (%.0f s)" % (
            label, best[0], count, best[1], time.time() - start_time))


if __name__ == "__main__":
    main()
