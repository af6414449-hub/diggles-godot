# -*- coding: utf-8 -*-
"""The map of the GDScript generator against the map of the Python model."""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import stone_gen  # noqa: E402

W = stone_gen.MAP_WIDTH
H = stone_gen.MAP_HEIGHT
OFFSET = 2158435
DUMP = pathlib.Path(r"C:\Users\frant\AppData\Roaming\Godot\app_userdata"
                    r"\Diggles Campaign Chapter\zz_material_dump.bin")


def main():
    data = DUMP.read_bytes()
    print("the dump: %d bytes" % len(data))
    godot_stone = sum(1 for value in data if value == 0)

    rng = stone_gen.DigglesRandom(variant="canonical")
    for _ in range(OFFSET):
        rng.next_u32()
    materials = bytearray(W * H)
    for index in range(W * H):
        materials[index] = 2
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
    python_stone = sum(1 for value in materials if value == 0)
    print("the stone of the GDScript: %d" % godot_stone)
    print("the stone of the Python:  %d" % python_stone)
    different = sum(1 for index in range(W * H)
                    if (data[index] == 0) != (materials[index] == 0))
    print("the cells that differ: %d" % different)
    if different:
        for index in range(W * H):
            if (data[index] == 0) != (materials[index] == 0):
                print("   the first one: x=%d y=%d  gdscript %d python %d" % (
                    index % W, index // W, data[index], materials[index]))
                break


if __name__ == "__main__":
    main()
