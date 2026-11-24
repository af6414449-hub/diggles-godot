#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Cross-check: the steps marked by the original against the geometry of the port.

The RLE section of a .pmp carries the map of the sub-cells of the original
(8x8 bytes per cell, 0 = no ground, 1 = ground, 3 = ground + step).

LAYOUT (important). The decoded RLE is a flat image of (W*8) x (H*8) samples,
row-major: the sample of the sub-cell (sx,sy) of the cell (cx,cy) sits at
    (cy*8 + sy) * (W*8) + cx*8 + sx.
The 64 samples of one cell are therefore NOT 64 consecutive bytes. The engine
stores them cell-major in the cell (cell+0x3c), and the conversion is a
permutation of the 64-byte groups, not of the bytes inside a group.

The port keeps the flat order: its runtime addresses a sample by
`index = y * stride + x` (godot/scripts/native_walkmap.gd:141) and its imported
package `godot/models/multi_start_010_walkmap.json` is flat as well (it
matches the flat RLE byte for byte).

Order of the writes: `map_template` writes the whole rectangle of the
template, so a later template overwrites an earlier one - the last writer
wins, and a cell without a "3" clears the mark of an earlier template.

Usage:
    python tools/audit_step_geometry.py [--chapter godot/models/native_campaign_chapter.json]
"""
from __future__ import annotations

import argparse
import json
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from audit_pmp_subcell import cell_codes, decode_subcells, parse_pmp, resolve  # noqa: E402
from inspect_bdb import BdbDatabase, _METADATA_BYTES  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
DEFAULT_CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
DEFAULT_DATA = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data")


def mesh_levels(meshes: dict, block: int) -> list:
    """The distinct heights of the mesh of a block, rounded to a half level."""
    parts = meshes.get(str(int(block)), [])
    values = set()
    for part in parts:
        vertices = part.get("vertices", [])
        for index in range(2, len(vertices), 5):
            values.add(round(float(vertices[index]) * 2.0) / 2.0)
    return sorted(values)


def block_map(database: BdbDatabase, block: int) -> bytes:
    """The 8x8 map of the levels of a block (the first 64 bytes of its record)."""
    if block < 0 or block >= database.block_count:
        return b""
    offset = database.sections["opaque_block_metadata"]["offset"]
    start = offset + block * _METADATA_BYTES
    return bytes(database.data[start:start + 64])


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--chapter", default=str(DEFAULT_CHAPTER))
    parser.add_argument("--data", default=str(DEFAULT_DATA))
    parser.add_argument("--bdb", default="BlockDB2.BDB")
    args = parser.parse_args()

    chapter = json.loads(Path(args.chapter).read_text(encoding="utf-8"))
    data_dir = Path(args.data)
    meshes = chapter.get("meshes", {})

    database = None
    for folder in ("", "Templates"):
        probe = data_dir / folder / args.bdb
        if probe.is_file():
            database = BdbDatabase(probe)
            break

    # The marks of every template of the chapter, placed on the map.
    # The last template that covers a cell decides its state.
    step_mark: dict = {}
    ground_mark: dict = {}
    missing = []
    for entry in chapter.get("templates", []):
        name = Path(str(entry.get("pmp") or "")).name
        if not name:
            continue
        path = resolve(name, data_dir)
        if not path.is_file():
            missing.append(name)
            continue
        parsed = parse_pmp(path)
        grid = decode_subcells(parsed)
        width, height = parsed["w"], parsed["h"]
        for placement in entry.get("placements", []):
            offset_x = int(placement.get("x", 0))
            offset_y = int(placement.get("y", 0))
            for cy in range(height):
                for cx in range(width):
                    block = [value for row in cell_codes(grid, width, height, cx, cy)
                             for value in row]
                    key = (offset_x + cx, offset_y + cy)
                    step_mark[key] = 3 in block
                    ground_mark[key] = (1 in block) or (3 in block)

    cells = chapter.get("cells", [])
    table = Counter()
    uniform_table = Counter()
    marked_flat_in_port = []
    levels_by_cell = {}
    for cell in cells:
        key = (int(cell["x"]), int(cell["y"]))
        levels = mesh_levels(meshes, int(cell["block"]))
        levels_by_cell[key] = levels[-1] if levels else None
        stepped = len(levels) > 1
        marked = bool(step_mark.get(key, False))
        ground = bool(ground_mark.get(key, False))
        table[(marked, stepped)] += 1
        uniform = True
        if database is not None:
            meta = block_map(database, int(cell["block"]))
            uniform = bool(meta) and len(set(meta)) == 1
        uniform_table[(uniform, marked, ground)] += 1
        if marked and not stepped:
            marked_flat_in_port.append((key, int(cell["block"]), levels))

    total = len(cells)
    print("cells of the chapter: %d" % total)
    print("templates with a missing .pmp: %s" % (", ".join(missing) if missing else "none"))
    print("cells marked with a step by the RLE map: %d"
          % sum(1 for cell in cells if step_mark.get((int(cell["x"]), int(cell["y"])))))
    print("cells with any ground in the RLE map: %d"
          % sum(1 for cell in cells if ground_mark.get((int(cell["x"]), int(cell["y"])))))
    print()
    print("                         mesh with one level   mesh with several levels")
    print("  RLE marks a step   %14d %22d" % (table[(True, False)], table[(True, True)]))
    print("  RLE marks no step %14d %22d" % (table[(False, False)], table[(False, True)]))
    print()
    print("block map 8x8 uniform | RLE step | RLE ground | cells")
    for uniform in (False, True):
        for marked in (False, True):
            for ground in (False, True):
                count = uniform_table[(uniform, marked, ground)]
                if count:
                    print("  %-19s | %-8s | %-10s | %d"
                          % ("yes" if uniform else "no", "yes" if marked else "no",
                             "yes" if ground else "no", count))
    print()
    print("marked by the original, but flat in the port: %d" % len(marked_flat_in_port))
    boundary = 0
    for (key, block, levels) in marked_flat_in_port:
        print("   cell %s block %d levels %s" % (key, block, levels))
        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            neighbour = levels_by_cell.get((key[0] + dx, key[1] + dy))
            if neighbour is not None and levels and neighbour != levels[-1]:
                boundary += 1
                break
    print("   of them, the step lies on the border with a cell of another "
          "height: %d of %d" % (boundary, len(marked_flat_in_port)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
