"""The cells of the chapter that have no flat patch.

A cell whose PMP has only diagonal corners filled carries no horizontal
surface: its mesh is a set of sloped triangles (a ridge). The wall module
cannot build a face against such a cell, because the profile of its side is
empty, so the four neighbours of every ridge cell keep a hole in their wall.

This script dumps the geometry of those cells and classifies them: one slope
with a diagonal base, or several different slopes.

Usage:
    python work/campaign/walls/ridge_cells.py [chapter.json]
"""

import json
import os
import sys
from collections import Counter

EPS = 1e-4
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))))
CHAPTER = os.path.join(ROOT, "godot", "models", "native_campaign_chapter.json")


def triangles_of(meshes, block):
    for part in meshes.get(str(block), []):
        values = part["vertices"]
        indices = part["indices"]
        for start in range(0, len(indices), 3):
            points = []
            for corner in range(3):
                offset = int(indices[start + corner]) * 5
                points.append((float(values[offset]), float(values[offset + 1]),
                               float(values[offset + 2])))
            yield points


def classify(points):
    """The kind of the sloped triangles of a cell."""
    heights = [point[2] for point in points]
    if max(heights) - min(heights) <= EPS:
        return "flat", None
    low = min(heights)
    high = max(heights)
    low_points = [point for point in points if abs(point[2] - low) <= EPS]
    if len(low_points) == 2:
        a, b = low_points
        if abs(a[0] - b[0]) > EPS and abs(a[1] - b[1]) > EPS:
            return "wedge", (low, high)
        return "ramp", (low, high)
    if len(low_points) == 1:
        return "peak", (low, high)
    return "other", (low, high)


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else CHAPTER
    with open(path, encoding="utf-8") as handle:
        data = json.load(handle)
    meshes = data["meshes"]

    kinds = Counter()
    ridge_cells = []
    signatures = Counter()
    for entry in data["cells"]:
        cell = (int(entry["x"]), int(entry["y"]))
        flat_levels = set()
        slope_levels = set()
        triangle_kinds = []
        for points in triangles_of(meshes, int(entry["block"])):
            kind, levels = classify(points)
            if kind == "flat":
                flat_levels.add(round(levels[0] if levels else points[0][2], 3))
            else:
                triangle_kinds.append(kind)
                slope_levels.add(round(points[0][2], 3))
        if flat_levels:
            continue
        ridge_cells.append(cell)
        kinds[tuple(sorted(Counter(triangle_kinds).items()))] += 1
        signatures[tuple(sorted(slope_levels))] += 1

    print("=== cells without a flat patch ===")
    print("count:", len(ridge_cells))
    print()
    print("=== the set of triangle kinds per cell ===")
    for signature, count in kinds.most_common():
        print("  %-60s %d" % (str(signature), count))
    print()
    print("=== the levels of the slopes per cell ===")
    for signature, count in signatures.most_common(12):
        print("  %-40s %d" % (str(signature), count))
    print()

    print("=== the geometry of the first six cells ===")
    for cell in ridge_cells[:6]:
        entry = next(item for item in data["cells"]
                     if int(item["x"]) == cell[0] and int(item["y"]) == cell[1])
        print("--- cell %s block %s ---" % (str(cell), entry["block"]))
        for points in triangles_of(meshes, int(entry["block"])):
            kind, levels = classify(points)
            text = "  %-8s" % kind
            for point in points:
                text += " (%5.3f, %5.3f, %6.3f)" % point
            print(text)


if __name__ == "__main__":
    main()
