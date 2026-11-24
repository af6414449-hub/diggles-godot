# -*- coding: utf-8 -*-
"""Where does the stone phase of the original start in the random stream?

The fingerprint is the decision of the engine on the cells whose probability is
below one: those cells are decided by the random number of the engine alone.
The search walks the stream and stops at the first cell that disagrees, so a
wrong place costs two comparisons.
"""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402
import stone_search  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT


def stream_numbers(count, mapgen_count):
    """The numbers of the engine: the mapgen twist first, the shared twist after."""
    rng = stone_gen.DigglesRandom(variant="mapgen")
    numbers = []
    for index in range(count):
        if index == mapgen_count:
            rng.variant = "canonical"
        numbers.append(rng.next_u32())
    return numbers


def stream_numbers_canonical(count):
    rng = stone_gen.DigglesRandom(variant="canonical")
    return [rng.next_u32() for _ in range(count)]


def main():
    states = stone_gen.save_states()
    events = stone_search.build_events()

    # A cell of the border that the funnel writes later does not keep the
    # decision of the border.
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

    # The fingerprint: the informative cells, spread over the phases, with the
    # probability nearest to one half.
    picked = []
    for offset, (index, p, name) in enumerate(events):
        if p >= 0.98 or p <= 0.02:
            continue
        if (states[index] & 0x80) != 0:
            continue
        if name.startswith("border") and index in funnel_cells:
            continue
        picked.append((offset, p))
    picked.sort(key=lambda item: abs(item[1] - 0.5))
    picked = picked[:24]
    print("the fingerprint: %d cells" % len(picked))
    for offset, p in picked[:6]:
        print("   offset %6d  p %.3f" % (offset, p))

    def score(numbers, start):
        agree = 0
        for offset, p in picked:
            index = start + offset
            if index >= len(numbers):
                return -1
            value = numbers[index] & 0x7FFF
            saved_stone = (states[events[offset][0]] & 3) == 0
            if saved_stone == (value <= p * 32768.0):
                agree += 1
            else:
                return agree
        return agree

    # The baseline: a place of the stream that has nothing to do with the map.
    rng = stone_gen.DigglesRandom(variant="canonical")
    base = [rng.next_u32() for _ in range(len(picked) + 10)]
    print("the baseline of the agreement: %d of %d" % (score(base, 0), len(picked)))

    count = 400000
    for label, numbers in (
            ("canonical", stream_numbers_canonical(count)),
            ("mapgen+canonical", stream_numbers(count, 4096 + W * H)),
            ("mapgen-only", stream_numbers(count, count))):
        best = (0, -1)
        for start in range(0, count - len(picked) - 2):
            value = score(numbers, start)
            if value > best[0]:
                best = (value, start)
                if value >= len(picked):
                    break
        print("%-16s best %d of %d at %d" % (label, best[0], len(picked), best[1]))


if __name__ == "__main__":
    main()
