#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Audit of the sub-cell map (8x8 per cell) carried by the RLE tail of a .pmp file.

Layout of the file (FUN_005992b0, see work/campaign/caves-decomp/z11-pmp-vs-beautifier.md):

    int32  w, int32 h
    uint8  shape[w*h]      material codes 0..5, bit 7 = flag
    uint32 block[w*h]      block id -> cell+0x00
    uint32 rle_count
    uint16 rle[rle_count]  value & 3 = byte of the sub-cell, value >> 2 = length
                           (length 0 -> 0x4000)
    uint8  extra[w*h]      -> cell+0x07

The decoded RLE buffer is 8*w x 8*h bytes: one byte per sub-cell of the cell.
Byte values (the beautifier FUN_005a6b40 writes exactly 0, 1 and 3):
    0 = no ground, 1 = ground, 3 = ground + step.

The port reads the header, shape, block ids and the trailing byte array, but never
the RLE block: the sub-cell ground/step mask of the original is therefore unknown
to the port. This tool decodes it and reports what the port is missing.

Usage:
    python tools/audit_pmp_subcell.py hol_001.pmp hol_014.pmp
    python tools/audit_pmp_subcell.py --data "<Diggles data>" --png out/subcell.png gng_001.pmp
"""
from __future__ import annotations

import argparse
import json
import struct
import sys
from collections import Counter
from pathlib import Path

DEFAULT_DATA = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data")
SUBCELL = 8

GLYPH = {0: ".", 1: "-", 2: ":", 3: "#"}


def parse_pmp(path: Path) -> dict:
    data = path.read_bytes()
    if len(data) < 12:
        raise ValueError("%s: header is truncated" % path.name)
    width, height = struct.unpack_from("<II", data, 0)
    cells = width * height
    offset = 8
    shape = data[offset:offset + cells]
    offset += cells
    block = struct.unpack_from("<%dI" % cells, data, offset) if cells else ()
    offset += 4 * cells
    (count,) = struct.unpack_from("<I", data, offset)
    offset += 4
    rle = struct.unpack_from("<%dH" % count, data, offset) if count else ()
    offset += 2 * count
    extra = data[offset:offset + cells]
    offset += cells
    return {
        "path": path,
        "size": len(data),
        "w": width,
        "h": height,
        "shape": shape,
        "block": block,
        "rle": rle,
        "extra": extra,
        "tail": len(data) - offset,
    }


def decode_subcells(parsed: dict) -> bytearray:
    """The RLE block decoded into the 8*w x 8*h sub-cell grid of the template."""
    out = bytearray()
    for word in parsed["rle"]:
        length = word >> 2
        if length == 0:
            length = 0x4000
        out.extend(bytes([word & 3]) * length)
    return out


def cell_codes(grid: bytearray, width: int, height: int, cx: int, cy: int) -> list:
    """The 8x8 codes of one cell, row by row (row 0 = north edge)."""
    rows = []
    for sy in range(SUBCELL):
        row = []
        for sx in range(SUBCELL):
            index = (cy * SUBCELL + sy) * (width * SUBCELL) + cx * SUBCELL + sx
            row.append(grid[index] if index < len(grid) else -1)
        rows.append(row)
    return rows


def resolve(name: str, data_dir: Path) -> Path:
    candidate = Path(name)
    if candidate.is_file():
        return candidate
    for folder in ("Templates/pmp", "Templates", "Templates/pmp/split"):
        probe = data_dir / folder / name
        if probe.is_file():
            return probe
    return candidate


def describe(parsed: dict, grid: bytearray, max_cells: int) -> None:
    width, height = parsed["w"], parsed["h"]
    print("=" * 78)
    print("%s  size=%d  %dx%d cells  rle=%d words  tail=%d bytes"
          % (parsed["path"].name, parsed["size"], width, height,
             len(parsed["rle"]), parsed["tail"]))
    expected = 64 * width * height
    counts = Counter(grid)
    print("  sub-cell bytes: %d of %d expected%s"
          % (len(grid), expected, "" if len(grid) == expected else "  (MISMATCH)"))
    print("  codes: %s" % ", ".join("%d=%d" % (k, counts.get(k, 0)) for k in (0, 1, 2, 3)))
    step_cells = 0
    ground_cells = 0
    filled_cells = 0
    shown = 0
    for cy in range(height):
        for cx in range(width):
            codes = cell_codes(grid, width, height, cx, cy)
            flat = [c for row in codes for c in row]
            if any(c for c in flat):
                filled_cells += 1
            if 3 in flat:
                step_cells += 1
            if 1 in flat and 3 not in flat:
                ground_cells += 1
            if any(c for c in flat) and shown < max_cells:
                shown += 1
                print("  cell (%2d,%2d) block=%-5s" % (cx, cy, parsed["block"][cy * width + cx]))
                for row in codes:
                    print("      " + "".join(GLYPH.get(c, "?") for c in row))
    print("  cells with any ground: %d of %d" % (filled_cells, width * height))
    print("  cells with a step (3): %d, cells with plain ground only (1): %d"
          % (step_cells, ground_cells))
    steps = sum(1 for c in grid if c == 3)
    print("  sub-cells with a step: %d of %d (%.2f%% of the grid)"
          % (steps, len(grid), 100.0 * steps / max(1, len(grid))))


def write_png(parsed: dict, grid: bytearray, out: Path) -> None:
    from PIL import Image

    width, height = parsed["w"], parsed["h"]
    image = Image.new("RGB", (width * SUBCELL, height * SUBCELL))
    pixels = image.load()
    for y in range(height * SUBCELL):
        for x in range(width * SUBCELL):
            code = grid[y * width * SUBCELL + x] if y * width * SUBCELL + x < len(grid) else 0
            pixels[x, y] = {0: (250, 250, 250), 1: (90, 170, 90), 2: (240, 210, 90),
                            3: (200, 60, 60)}.get(code, (0, 0, 0))
    out.parent.mkdir(parents=True, exist_ok=True)
    image.save(out)
    print("  png written: %s" % out)


def export_chapter(chapter_path: Path, data_dir: Path, out_dir: Path) -> None:
    """Export the sub-cell map of every template of a chapter with its placements.

    The chapter model of the port keeps the template name, the source .pmp and the
    placement of every template on the map. The sub-cell map of the original is
    decoded here the way the loader of the engine does it (FUN_005992b0:549-565
    writes the decoded bytes into the map of the cells at the sub-cell
    coordinates {x0*8, y0*8, x1*8, y1*8}), so the consumer only has to place the
    bytes of a template at the offset of its placement.
    """
    import base64

    chapter = json.loads(chapter_path.read_text(encoding="utf-8"))
    out_dir.mkdir(parents=True, exist_ok=True)
    manifest = []
    for entry in chapter.get("templates", []):
        name = Path(str(entry.get("pmp") or "")).name
        if not name:
            continue
        path = resolve(name, data_dir)
        record = {
            "template": entry.get("template"),
            "pmp": name,
            "width": entry.get("width"),
            "height": entry.get("height"),
            "placements": entry.get("placements", []),
        }
        if not path.is_file():
            record["status"] = "missing"
            manifest.append(record)
            continue
        parsed = parse_pmp(path)
        grid = decode_subcells(parsed)
        counts = Counter(grid)
        record.update({
            "status": "ok",
            "samples": len(grid),
            "codes": {"0": counts.get(0, 0), "1": counts.get(1, 0),
                      "2": counts.get(2, 0), "3": counts.get(3, 0)},
            "cells_with_step": sum(1 for cy in range(parsed["h"])
                                   for cx in range(parsed["w"])
                                   if 3 in [value for row in cell_codes(grid, parsed["w"], parsed["h"], cx, cy)
                                            for value in row]),
        })
        payload = {
            "schema": "diggles.pmp_subcell_map.v1",
            "template": entry.get("template"),
            "pmp": name,
            "width": parsed["w"],
            "height": parsed["h"],
            "placements": entry.get("placements", []),
            "storage": "flat image (W*8)x(H*8), row-major: the sample (sx,sy) of the "
                       "cell (cx,cy) is at (cy*8+sy)*(W*8)+cx*8+sx; the 64 samples of a "
                       "cell are NOT 64 consecutive bytes. The engine stores them "
                       "cell-major in the cell (cell+0x3c); the port keeps the flat order "
                       "(godot/scripts/native_walkmap.gd:141).",
            "codes": record["codes"],
            "flags_b64": base64.b64encode(bytes(grid)).decode("ascii"),
        }
        (out_dir / (name.replace(".pmp", "") + ".json")).write_text(
            json.dumps(payload), encoding="utf-8")
        write_png(parsed, grid, out_dir / (name.replace(".pmp", "") + ".png"))
        manifest.append(record)
    (out_dir / "manifest.json").write_text(json.dumps(manifest, indent=1), encoding="utf-8")
    ok = [r for r in manifest if r.get("status") == "ok"]
    print("templates exported: %d of %d -> %s" % (len(ok), len(manifest), out_dir))
    for record in ok:
        print("  %-28s %sx%s cells=%d samples=%d codes=%s cells_with_step=%d"
              % (record["template"], record["width"], record["height"],
                 record["width"] * record["height"], record["samples"],
                 record["codes"], record["cells_with_step"]))
    missing = [r["template"] for r in manifest if r.get("status") != "ok"]
    if missing:
        print("  missing: %s" % ", ".join(str(name) for name in missing))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("files", nargs="*", help="names of .pmp files")
    parser.add_argument("--chapter", default=None,
                        help="chapter model of the port: export the sub-cell map of every template")
    parser.add_argument("--out-dir", default=None, help="target directory of the export")
    parser.add_argument("--data", default=str(DEFAULT_DATA), help="root of the original data")
    parser.add_argument("--max-cells", type=int, default=4,
                        help="how many non-empty cells to print per file")
    parser.add_argument("--png", default=None, help="write the sub-cell map of the last file as png")
    args = parser.parse_args()

    data_dir = Path(args.data)
    if args.chapter:
        out_dir = Path(args.out_dir) if args.out_dir else Path("out/mine-2026-11-21/pmp-subcell")
        export_chapter(Path(args.chapter), data_dir, out_dir)
        return 0
    if not args.files:
        parser.error("no .pmp files and no --chapter")
    for name in args.files:
        path = resolve(name, data_dir)
        if not path.is_file():
            print("!! no file: %s" % name)
            continue
        parsed = parse_pmp(path)
        grid = decode_subcells(parsed)
        describe(parsed, grid, args.max_cells)
        if args.png:
            write_png(parsed, grid, Path(args.png))
    return 0


if __name__ == "__main__":
    sys.exit(main())
