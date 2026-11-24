# -*- coding: utf-8 -*-
"""The places of the stream that agree with the save the longest."""
import pathlib
import sys
import time

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402
import stone_wide3  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT
LIMIT = 4000000


def main():
    states = stone_gen.save_states()
    cells = stone_wide3.top_band_cells(states)
    offsets = [item[0] for item in cells]
    thresholds = [item[2] * 32768.0 for item in cells]
    decisions = [(states[item[1]] & 3) == 0 for item in cells]
    count = len(cells)
    print("the cells of the fingerprint: %d" % count)

    rng = stone_gen.DigglesRandom(variant="canonical")
    numbers = []
    for _ in range(LIMIT + 20000):
        numbers.append(rng.next_u32())

    best = []
    start_time = time.time()
    for start in range(0, LIMIT):
        agree = 0
        for step in range(count):
            value = numbers[start + offsets[step]] & 0x7FFF
            if (value <= thresholds[step]) == decisions[step]:
                agree += 1
            else:
                break
        if agree >= 20:
            best.append((agree, start))
    best.sort(reverse=True)
    print("the scan took %.0f s" % (time.time() - start_time))
    print("the places with twenty cells in a row and more:")
    for agree, start in best[:20]:
        print("   %4d of %d at %d" % (agree, count, start))

    # what breaks at the best place
    if best:
        agree, start = best[0]
        print()
        print("the cells of the fingerprint at the best place %d:" % start)
        broken = 0
        for step in range(count):
            value = numbers[start + offsets[step]] & 0x7FFF
            ok = (value <= thresholds[step]) == decisions[step]
            if not ok and broken < 12:
                x = offsets[step] // 31
                y = offsets[step] % 31
                print("   x=%3d y=%2d  p=%.3f  number %5d  threshold %6.0f  saved %s"
                      % (x, y, thresholds[step] / 32768.0, value,
                         thresholds[step], decisions[step]))
                broken += 1
            if not ok:
                break


if __name__ == "__main__":
    main()
