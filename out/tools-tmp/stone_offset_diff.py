# -*- coding: utf-8 -*-
"""Where the generator with the found offset and the save still differ."""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402
import stone_verify  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT


def main():
    states = stone_gen.save_states()
    rng = stone_gen.DigglesRandom(variant="canonical")
    for _ in range(stone_verify.OFFSET):
        rng.next_u32()
    materials = bytearray(W * H)
    for index in range(W * H):
        materials[index] = 2
    stone_verify.stone_phase(rng, materials)

    from PIL import Image
    image = Image.new("RGB", (W, H), (0, 0, 0))
    pixels = image.load()
    rows = {}
    for index in range(W * H):
        x = index % W
        y = index // W
        generated = materials[index] == 0
        saved = (states[index] & 3) == 0
        template = (states[index] & 0x80) != 0
        if generated and saved:
            colour = (230, 230, 230)
        elif saved and not generated:
            colour = (255, 40, 40)
        elif generated and not saved:
            colour = (40, 220, 60)
        else:
            colour = (18, 18, 26)
        if template:
            colour = (60, 90, 255) if not generated else (150, 90, 255)
        pixels[x, y] = colour
        if colour in ((255, 40, 40), (40, 220, 60)):
            rows.setdefault(y, [0, 0])
            rows[y][0 if colour == (255, 40, 40) else 1] += 1
    out = pathlib.Path(__file__).resolve().parent / "zz-gen-offset.png"
    image.save(out)
    print("written %s" % out)
    print("the rows that differ (row: save only / generator only):")
    for y in sorted(rows):
        if rows[y][0] + rows[y][1] > 4:
            print("  y=%3d  %5d %5d" % (y, rows[y][0], rows[y][1]))
    print("the columns that differ (x: save only / generator only):")
    columns = {}
    for index in range(W * H):
        x = index % W
        y = index // W
        generated = materials[index] == 0
        saved = (states[index] & 3) == 0
        if generated == saved:
            continue
        columns.setdefault(x, [0, 0])
        columns[x][0 if saved else 1] += 1
    for x in sorted(columns):
        if columns[x][0] + columns[x][1] > 4:
            print("  x=%3d  %5d %5d" % (x, columns[x][0], columns[x][1]))


if __name__ == "__main__":
    main()
