#!/usr/bin/env python3
"""Structure probe of the exported campaign chapter cells.

For every cell the block model can carry several patches: a floor of a tunnel
and the surface of the rock above it. This probe prints the patch levels of
sample cells and three ASCII maps (min level, max level, number of patches)
so the rendered shape can be read without guessing.

Usage:
  python tools/probe_campaign_cells.py [--samples 12]
"""
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CHAPTER = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")


def part_levels(part):
    """(level, area) of every height of one patch."""
    values = part["vertices"]
    indices = part["indices"]
    areas = {}
    for start in range(0, len(indices), 3):
        pts = []
        for corner in range(3):
            offset = int(indices[start + corner]) * 5
            pts.append((float(values[offset]), float(values[offset + 1]),
                        float(values[offset + 2])))
        ax, ay, _ = pts[0]
        bx, by, _ = pts[1]
        cx, cy, _ = pts[2]
        area = abs((bx - ax) * (cy - ay) - (by - ay) * (cx - ax)) * 0.5
        if area <= 0.0001:
            continue
        key = round(pts[0][2], 2)
        areas[key] = areas.get(key, 0.0) + area
    return areas


def cell_patches(entry, meshes):
    """The patches of a cell as (level, area) pairs, biggest area first."""
    parts = meshes.get(str(entry["block"]), [])
    out = []
    for part in parts:
        for level, area in part_levels(part).items():
            out.append((level, area))
    out.sort(key=lambda item: -item[1])
    return out


def main():
    argv = sys.argv[1:]
    sample_count = 12
    if "--samples" in argv:
        sample_count = int(argv[argv.index("--samples") + 1])
    with open(CHAPTER, "r", encoding="utf-8") as handle:
        chapter = json.load(handle)
    meshes = chapter["meshes"]
    cells = chapter["cells"]

    blocks = sorted({int(entry["block"]) for entry in cells})
    print("blocks used by the chapter: %d -> %s" % (len(blocks), blocks[:24]))
    for block in blocks[:8]:
        parts = meshes.get(str(block), [])
        print("  block %d: %d patches" % (block, len(parts)))
        for index, part in enumerate(parts):
            levels = part_levels(part)
            total = sum(levels.values())
            summary = ", ".join("%s:%.3f" % (k, v) for k, v in sorted(levels.items()))
            print("    patch %d area=%.3f levels=[%s]" % (index, total, summary))

    # block -> patch count, used to classify the cells
    patch_count = {}
    for block in blocks:
        patch_count[block] = len(meshes.get(str(block), []))

    print()
    print("sample cells (x, y, block, ground_variant, patches):")
    step = max(1, len(cells) // max(1, sample_count))
    for entry in cells[::step][:sample_count]:
        patches = cell_patches(entry, meshes)
        text = " ".join("%s/%.2f" % (level, area) for level, area in patches[:6])
        print("  x=%3d y=%3d block=%3d v=%2d parts=%d  %s" % (
            int(entry["x"]), int(entry["y"]), int(entry["block"]),
            int(entry.get("ground_variant", 1)), patch_count[int(entry["block"])], text))

    mins = {}
    maxs = {}
    counts = {}
    for entry in cells:
        patches = cell_patches(entry, meshes)
        if not patches:
            continue
        key = (int(entry["x"]), int(entry["y"]))
        mins[key] = min(level for level, _ in patches)
        maxs[key] = max(level for level, _ in patches)
        counts[key] = len(patches)

    xs = [key[0] for key in mins]
    ys = [key[1] for key in mins]
    box = (min(xs), min(ys), max(xs), max(ys))

    def dump(title, table, symbol):
        print()
        print(title)
        for y in range(box[1], box[3] + 1):
            row = []
            for x in range(box[0], box[2] + 1):
                value = table.get((x, y))
                row.append(" " if value is None else symbol(value))
            print("%4d |%s|" % (y, "".join(row)))

    dump("min level map (the floor that is drawn):", mins,
         lambda value: " " if value >= 14.4 else ("." if value >= 11.0 else "o"))
    dump("max level map (the top of the cell):", maxs,
         lambda value: " " if value >= 14.4 else ("." if value >= 11.0 else "o"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
