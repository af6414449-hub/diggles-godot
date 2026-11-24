# -*- coding: utf-8 -*-
"""The end to end check: the generator with the found place of the stream
against the material of the save of the owner, cell by cell."""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT
OFFSET = 2158435


def stone_phase(rng, materials):
    """The stone of the chapter, in the order of the scripts."""
    stone_gen.draw_stone(rng, materials, W, H, (0, 0, W, 32), 1, 3.0)
    stone_gen.draw_stone(rng, materials, W, H, (0, 0, 32, H + 4), 4, 1.0)
    stone_gen.draw_stone(rng, materials, W, H, (W - 32, 0, W, H + 4), 8, 1.0)
    band_width = 2 * (W // 4) - 20
    band_y = 16
    while band_width > 0:
        stone_gen.draw_stone(rng, materials, W, H,
                             (W - band_width, band_y, W, band_y + 6), 8, 1.0)
        stone_gen.draw_stone(rng, materials, W, H,
                             (0, band_y, band_width, band_y + 6), 4, 1.0)
        band_width -= 8
        band_y += 4


def main():
    states = stone_gen.save_states()
    rng = stone_gen.DigglesRandom(variant="canonical")
    for _ in range(OFFSET):
        rng.next_u32()
    materials = bytearray(W * H)
    for index in range(W * H):
        materials[index] = 2
    stone_phase(rng, materials)

    stone = 0
    saved_stone = 0
    same = 0
    different = []
    for index in range(W * H):
        generated = materials[index] == 0
        saved = (states[index] & 3) == 0
        template = (states[index] & 0x80) != 0
        if generated:
            stone += 1
        if saved:
            saved_stone += 1
        if generated == saved:
            same += 1
        else:
            different.append((index % W, index // W, generated, saved,
                              states[index], template))
    print("the stone of the generator: %d" % stone)
    print("the stone of the save:      %d" % saved_stone)
    print("the cells that agree:       %d of %d (%.4f%%)"
          % (same, W * H, 100.0 * same / (W * H)))
    print("the cells that differ:      %d" % len(different))
    by_state = {}
    for x, y, generated, saved, state, template in different:
        key = (state, generated, saved)
        by_state[key] = by_state.get(key, 0) + 1
    for key in sorted(by_state):
        print("   state 0x%02X  generated %s  saved %s : %d"
              % (key[0], key[1], key[2], by_state[key]))
    print("the first cells that differ:")
    for item in different[:20]:
        print("   x=%d y=%d  generated %s  saved %s  state 0x%02X"
              % (item[0], item[1], item[2], item[3], item[4]))


if __name__ == "__main__":
    main()
