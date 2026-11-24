# -*- coding: utf-8 -*-
"""The wide search of the place of the stream, over a million positions."""
import pathlib
import sys
import time

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402
import stone_search  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT
LIMIT = 4000000


def build_stream(count, switch_at):
    rng = stone_gen.DigglesRandom(variant="mapgen")
    numbers = []
    append = numbers.append
    for index in range(count):
        if index == switch_at:
            rng.variant = "canonical"
        append(rng.next_u32())
    return numbers


def main():
    states = stone_gen.save_states()
    events = stone_search.build_events()
    funnel_cells = set()
    for name, rect, flags, strength in stone_search.CALLS:
        if not name.startswith("funnel"):
            continue
        x1 = max(rect[0], 0)
        y1 = max(rect[1], 0)
        x2 = min(rect[2], W)
        y2 = min(rect[3], H)
        for x in range(x1, x2 - 1):
            for y in range(y1, y2 - 1):
                funnel_cells.add(y * W + x)

    picked = []
    for offset, (index, p, name) in enumerate(events):
        if p >= 0.95 or p <= 0.05:
            continue
        if (states[index] & 0x80) != 0:
            continue
        if name.startswith("border") and index in funnel_cells:
            continue
        picked.append((offset, p))
    picked.sort(key=lambda item: abs(item[1] - 0.5))
    picked = picked[:24]
    print("the fingerprint: %d cells, offsets %s" % (
        len(picked), [offset for offset, _ in picked[:8]]))

    thresholds = [p * 32768.0 for _, p in picked]
    decisions = [(states[events[offset][0]] & 3) == 0 for offset, _ in picked]

    for label, switch in (("canonical", LIMIT), ("mapgen+canonical", 4096 + W * H)):
        start_time = time.time()
        numbers = build_stream(LIMIT, switch)
        best = (0, -1)
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
        print("%-16s best %d of %d at %d  (%.0f s)" % (
            label, best[0], len(picked), best[1], time.time() - start_time))


if __name__ == "__main__":
    main()
