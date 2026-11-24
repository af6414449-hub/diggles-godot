"""Probe the exported campaign chapter: block parts, surface levels and walls.

Read-only: the exported chapter JSON of the first campaign level.
Prints what geometry is available, so the renderer can be judged against the
data instead of against a guess.
"""
from __future__ import annotations

import json
import os
import sys
from collections import Counter

CHAPTER = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot\models\native_campaign_chapter.json"


def main() -> None:
    path = sys.argv[1] if len(sys.argv) > 1 else CHAPTER
    with open(path, encoding="utf-8") as handle:
        data = json.load(handle)
    print("top keys:", sorted(data.keys()))
    cells = data["cells"]
    print("cells:", len(cells))
    print("cell sample:", json.dumps(cells[0], ensure_ascii=False)[:400])
    print("cell keys:", sorted(cells[0].keys()))
    heights = Counter()
    blocks = Counter()
    for cell in cells:
        heights[round(float(cell.get("z", 0.0)), 3)] += 1
        blocks[int(cell.get("block", -1))] += 1
    print("distinct z levels:", len(heights))
    print("z histogram (top 12):", heights.most_common(12))
    print("distinct blocks:", len(blocks), blocks.most_common(8))
    meshes = data["meshes"]
    print("mesh blocks:", len(meshes))
    key = sorted(meshes.keys(), key=lambda k: int(k))[0]
    parts = meshes[key]
    print("block", key, "parts:", len(parts))
    for part in parts:
        values = part["vertices"]
        count = len(values) // 5
        xs = [float(values[i * 5]) for i in range(count)]
        ys = [float(values[i * 5 + 1]) for i in range(count)]
        zs = [float(values[i * 5 + 2]) for i in range(count)]
        print("  part", part.get("part"), "verts", count,
              "x", round(min(xs), 3), round(max(xs), 3),
              "y", round(min(ys), 3), round(max(ys), 3),
              "z", round(min(zs), 3), round(max(zs), 3))
    part_counts = Counter(len(meshes[k]) for k in meshes)
    print("parts per block:", part_counts.most_common())
    for key in list(sorted(meshes.keys(), key=lambda k: int(k)))[:4]:
        block = meshes[key]
        print("block", key, "parts", len(block))
        for part in block:
            values = part["vertices"]
            count = len(values) // 5
            zs = [float(values[i * 5 + 2]) for i in range(count)]
            print("    part", part.get("part"), "verts", count,
                  "z", round(min(zs), 3), round(max(zs), 3))
    print("chapter summary:", json.dumps(data.get("summary", {}), ensure_ascii=False)[:400])
    print("initial_view:", json.dumps(data.get("initial_view", {}), ensure_ascii=False))
    print("map_size:", json.dumps(data.get("map_size", {}), ensure_ascii=False))
    print("atlas:", json.dumps(data.get("atlas", {}), ensure_ascii=False)[:300])


if __name__ == "__main__":
    main()
