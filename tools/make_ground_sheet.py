"""Contact sheet of the ground textures of the original.

Shows which family is granite, so the base layer of the campaign map can use
the material of the chapter instead of a wrong default.

Usage:
    python tools/make_ground_sheet.py
"""

import pathlib

from PIL import Image

ROOT = pathlib.Path(__file__).resolve().parent.parent
GROUND = ROOT / "godot" / "textures" / "ground"
OUT = ROOT / "out" / "original-shots" / "ground-families.png"

NAMES = [
    "Gnd_A01.tga", "Gnd_A08.tga", "Gnd_A14.tga",
    "Gnd_C01.tga", "Gnd_C08.tga", "Gnd_C14.tga",
    "Native_0022.tga", "Native_2020.tga", "Native_2200.tga",
]


def main():
    tiles = []
    for name in NAMES:
        path = GROUND / name
        if not path.is_file():
            continue
        image = Image.open(path).convert("RGB")
        image = image.resize((220, 220), Image.NEAREST)
        tiles.append((name, image))
    if not tiles:
        raise SystemExit("no ground textures found")
    columns = 3
    rows = (len(tiles) + columns - 1) // columns
    sheet = Image.new("RGB", (columns * 224, rows * 224), (24, 24, 28))
    for index, (_, image) in enumerate(tiles):
        x = (index % columns) * 224 + 2
        y = (index // columns) * 224 + 2
        sheet.paste(image, (x, y))
    OUT.parent.mkdir(parents=True, exist_ok=True)
    sheet.save(OUT)
    print("saved", OUT)
    print("order:", [name for name, _ in tiles])


if __name__ == "__main__":
    main()
