"""What does the chapter export carry for the tile choice of a cell?

The battle scene chooses the ground tile of a cell from two things:
  - the variant number 1..15 of the cell (entry["ground_variant"]);
  - the material of the four corners of the cell (terrain_render["materials"]),
    which gives the signature -> the mixed tile file.

The chapter export has no ground_variant, so this script measures what it does
carry: the per-cell material map, the block/part structure and whether a block
carries a material per corner.
"""
from __future__ import annotations

import json
import os
from collections import Counter

ROOT = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models"
CHAPTER = os.path.join(ROOT, "native_campaign_chapter.json")


def main() -> None:
    with open(CHAPTER, encoding="utf-8") as fh:
        chapter = json.load(fh)

    meshes = chapter["meshes"]
    keys = list(meshes)[:3]
    print("meshes:", len(meshes), "keys sample:", keys)
    for key in keys:
        block = meshes[key]
        print(f"\nblock {key}: type={type(block).__name__} len={len(block)}")
        if isinstance(block, list) and block:
            part = block[0]
            print("  part keys:", sorted(part.keys()))
            for field, value in part.items():
                if isinstance(value, list):
                    print(f"    {field}: list[{len(value)}] sample={value[:4]}")
                else:
                    print(f"    {field}: {value}")

    materials = chapter["materials"]
    values = Counter(int(v) for v in materials.values())
    print("\nmaterials per cell:", dict(sorted(values.items())))

    # how many neighbouring cells differ in material -> the chance of a mixed tile
    cells = chapter["cells"]
    diff = 0
    same = 0
    for cell in cells:
        x, y = int(cell["x"]), int(cell["y"])
        here = materials.get(f"{x},{y}")
        if here is None:
            continue
        for dx, dy in ((1, 0), (0, 1)):
            other = materials.get(f"{x + dx},{y + dy}")
            if other is None:
                continue
            if int(other) == 3:
                other = 0
            if int(here) == 3:
                here = 0
            if int(other) == int(here):
                same += 1
            else:
                diff += 1
    print(f"neighbour pairs: same family {same}, different family {diff} "
          f"-> mixed tiles needed on {diff / max(same + diff, 1) * 100:.1f} % of the edges")


if __name__ == "__main__":
    main()
