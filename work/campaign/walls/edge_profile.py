"""Cross section of the chapter cells near the edge of the template area.

Question: the edge of the map in the port is a staircase of terraces with a
step of 0.5 that goes down into the void. The question is whose heights make
that staircase: the heights of the blocks of the templates (the .pmp of a
template names the 3D block of every cell) or the free rock of the map that
the engine draws with "sm_draw_stone -border" / "-funnel" (that one is not in
the export at all).

Fact (tools/export_campaign_chapter.py:546-582): the .pmp of a template holds
the block id of every cell (refs), the attributes and the flags of the cell.
So the height of a chapter cell is the height of its block mesh.

Usage:
    python work/campaign/walls/edge_profile.py [x0] [y0] [x1] [y1]
"""
import json
import pathlib
import sys

ROOT = pathlib.Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"


def main() -> int:
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    meshes = chapter["meshes"]
    materials = chapter["materials"]
    attributes = chapter["attributes"]

    x0, y0, x1, y1 = (int(v) for v in sys.argv[1:5]) if len(sys.argv) > 4 else (196, 0, 216, 14)

    heights = {}
    for cell in chapter["cells"]:
        x = int(cell["x"])
        y = int(cell["y"])
        if not (x0 <= x <= x1 and y0 <= y <= y1):
            continue
        parts = meshes.get(str(int(cell["block"])), [])
        top = None
        for part in parts:
            values = part["vertices"]
            for index in range(0, len(values), 5):
                z = values[index + 2]
                if top is None or z > top:
                    top = z
        heights[(x, y)] = (top, int(materials.get("%d,%d" % (x, y), -1)),
                           int(attributes.get("%d,%d" % (x, y), -1)))

    print("column profiles of the chapter cells, x=%d..%d y=%d..%d" % (x0, x1, y0, y1))
    for x in range(x0, x1 + 1):
        column = [(y, heights[(x, y)]) for y in range(y0, y1 + 1) if (x, y) in heights]
        if not column:
            continue
        line = "  x=%3d : " % x
        for y, (top, mat, attr) in column:
            line += "%s:%s/m%d/a%d " % (y, "-" if top is None else top, mat, attr)
        print(line)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
