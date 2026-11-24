# -*- coding: utf-8 -*-
"""The exact place of the random stream of the stone.

The shape of the falloff is confirmed by the save, so the model of the engine
is right.  What is left is the place of the stream: the search takes the state
of the mapgen, adds a gap of g numbers and compares the decision of the engine
with the stone of the save on the cells whose probability is below one.
"""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT
CALLS = [
    ("border-top", (0, 0, W, 32), 1, 3.0),
    ("border-left", (0, 0, 32, H + 4), 4, 1.0),
    ("border-right", (W - 32, 0, W, H + 4), 8, 1.0),
]
BAND_WIDTH = 2 * (W // 4) - 20
BAND_Y = 16
while BAND_WIDTH > 0:
    CALLS.append(("funnel-right-%d" % BAND_Y, (W - BAND_WIDTH, BAND_Y, W, BAND_Y + 6), 8, 1.0))
    CALLS.append(("funnel-left-%d" % BAND_Y, (0, BAND_Y, BAND_WIDTH, BAND_Y + 6), 4, 1.0))
    BAND_WIDTH -= 8
    BAND_Y += 4


def cell_probability(rect, flags, strength, x, y):
    x1 = max(rect[0], 0)
    y1 = max(rect[1], 0)
    x2 = min(rect[2], W)
    y2 = min(rect[3], H)
    span_x = x2 - x1
    span_y = y2 - y1
    falloff = stone_gen.f32(strength / stone_gen.f32(min(span_x, span_y) * 0.2))
    centre_x = x1 + span_x // 2
    centre_y = y1 + span_y // 2
    p = 1.0
    if (flags & 4) and x > centre_x:
        d = stone_gen.f32(centre_x - x)
        p = stone_gen.f32(1.0 - stone_gen.f32(stone_gen.f32(
            stone_gen.f32(d / span_x) * d) / span_x) / falloff)
    if (flags & 8) and x < centre_x:
        d = stone_gen.f32(centre_x - x)
        p = stone_gen.f32(p - stone_gen.f32(stone_gen.f32(
            stone_gen.f32(d / span_x) * d) / span_x) / falloff)
    if (flags & 1) and y > centre_y:
        d = stone_gen.f32(centre_y - y)
        p = stone_gen.f32(p - stone_gen.f32(stone_gen.f32(
            stone_gen.f32(d / span_y) * d) / span_y) / falloff)
    if (flags & 2) and y < centre_y:
        d = stone_gen.f32(centre_y - y)
        p = stone_gen.f32(p - stone_gen.f32(stone_gen.f32(
            stone_gen.f32(d / span_y) * d) / span_y) / falloff)
    return p


def build_events():
    """The cells of the stone, in the order of the engine, with their p."""
    events = []
    for name, rect, flags, strength in CALLS:
        x1 = max(rect[0], 0)
        y1 = max(rect[1], 0)
        x2 = min(rect[2], W)
        y2 = min(rect[3], H)
        if x1 >= x2 or y1 >= y2:
            continue
        for x in range(x1, x2 - 1):
            for y in range(y1, y2 - 1):
                events.append((y * W + x, cell_probability(rect, flags, strength, x, y), name))
    return events


def main():
    states = stone_gen.save_states()
    events = build_events()
    print("the stone phase takes %d numbers" % len(events))

    informative = []
    for index, p, name in events:
        if p >= 1.0:
            continue
        if (states[index] & 0x80) != 0:
            continue
        informative.append((index, p, name))
    print("the informative cells: %d" % len(informative))

    def score(rng, gap, gap_variant):
        rng.state = list(base_state)
        rng.index = base_index
        rng.variant = gap_variant
        for _ in range(gap):
            rng.next_u32()
        rng.variant = "canonical"
        number = 0
        agree = 0
        for index, p, name in events:
            value = rng.next_u32() & 0x7FFF
            if p >= 1.0 or (states[index] & 0x80) != 0:
                continue
            saved_stone = (states[index] & 3) == 0
            if saved_stone == (value <= p * 32768.0):
                agree += 1
        return agree

    for systeminit in (True, False):
        for variant in ("mapgen", "canonical"):
            rng = stone_gen.DigglesRandom(variant=variant)
            materials = bytearray(64 * 64)
            variations = bytearray(64 * 64)
            if systeminit:
                stone_gen.mapgen(rng, 64, 64, materials, variations)
            big = bytearray(W * H)
            bigv = bytearray(W * H)
            stone_gen.mapgen(rng, W, H, big, bigv)
            base_state = list(rng.state)
            base_index = rng.index
            best = []
            for gap in range(0, 40):
                for gap_variant in ("canonical", "mapgen"):
                    agree = score(rng, gap, gap_variant)
                    best.append((agree, gap, gap_variant))
            best.sort(reverse=True)
            print("init=%-5s mapgen=%-9s  best: %s" % (
                systeminit, variant,
                ", ".join("gap=%d/%s %d" % (g, v, a) for a, g, v in best[:4])))


if __name__ == "__main__":
    main()
