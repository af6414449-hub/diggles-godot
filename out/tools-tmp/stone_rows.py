# -*- coding: utf-8 -*-
"""The exact rows of the top of the map: the save against the generator."""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402

W = stone_gen.MAP_WIDTH


def runs(values):
    out = []
    current = values[0]
    start = 0
    for index in range(1, len(values) + 1):
        value = values[index] if index < len(values) else None
        if value != current:
            out.append((start, index - 1, current))
            current = value
            start = index
    return out


def main():
    states = stone_gen.save_states()
    materials, _ = stone_gen.generate(systeminit=True, mapgen_variant="mapgen")
    for y in list(range(0, 46)):
        saved = [states[y * W + x] for x in range(W)]
        generated = [0 if materials[y * W + x] == 0 else 2 for x in range(W)]
        stone_runs = [(a, b) for a, b, v in runs(generated) if v == 0]
        saved_runs = [(a, b) for a, b, v in runs(saved) if (v & 3) == 0]
        print("y=%2d  gen stone: %s" % (y, stone_runs))
        print("      save stone: %s" % (saved_runs,))
    print()
    print("--- the state of the save in the top rows, column by column ---")
    for y in range(0, 46, 2):
        row = " ".join("%02X" % states[y * W + x] for x in range(180, 320, 2))
        print("y=%2d %s" % (y, row))


if __name__ == "__main__":
    main()
