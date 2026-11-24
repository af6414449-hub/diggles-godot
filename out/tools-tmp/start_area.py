# -*- coding: utf-8 -*-
"""Does the export of the chapter cover the cells of the start area?"""
import json
import pathlib

ROOT = pathlib.Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles")
chapter = json.loads((ROOT / "godot" / "models" / "native_campaign_chapter.json")
                     .read_text(encoding="utf-8"))
materials = chapter.get("materials", {})
print("the cells of the export: %d" % len(materials))
cells = chapter.get("cells", [])
print("the cells of the export (blocks): %d" % len(cells))
block_cells = set()
for entry in cells:
    block_cells.add((int(entry["x"]), int(entry["y"])))
print()
print("the start area, rows 0..30, x 205..275:")
for y in range(0, 31, 2):
    row = []
    for x in range(205, 276):
        key = "%d,%d" % (x, y)
        if key in materials:
            row.append(str(materials[key]))
        elif (x, y) in block_cells:
            row.append("b")
        else:
            row.append(".")
    print("y=%2d %s" % (y, "".join(row)))
print()
print("legend: the digit is the material of the export, b is a block without a")
print("        material, . is a free cell of the map")
