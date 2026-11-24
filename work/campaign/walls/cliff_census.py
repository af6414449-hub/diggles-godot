"""The census of the faces that the walls module builds on the ramps.

The module builds a vertical face on the lower edge of every ramp of the export.
This script sorts those faces by the drop of the ramp and by the length of the
lower edge, and it separates the faces whose lower edge spans the whole side of
the cell (a clean step of the terrain) from the fragments of an irregular slope
(the rock of the map).

Usage:
    python work/campaign/walls/cliff_census.py
"""
import json
import pathlib
from collections import Counter, defaultdict

ROOT = pathlib.Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
EPS = 1e-4
CLIFF_HEIGHT = 2.0


def main() -> int:
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    meshes = chapter["meshes"]
    cells = chapter["cells"]

    faces = []
    for entry in cells:
        cell = (int(entry["x"]), int(entry["y"]))
        for part in meshes.get(str(int(entry["block"])), []):
            values = part["vertices"]
            indices = part["indices"]
            for start in range(0, len(indices), 3):
                points = []
                for corner in range(3):
                    offset = int(indices[start + corner]) * 5
                    points.append((float(values[offset]), float(values[offset + 1]),
                                   float(values[offset + 2])))
                low = min(p[2] for p in points)
                high = max(p[2] for p in points)
                if high - low < CLIFF_HEIGHT:
                    continue
                flat_x = all(abs(p[0] - points[0][0]) <= EPS for p in points)
                flat_y = all(abs(p[1] - points[0][1]) <= EPS for p in points)
                if flat_x or flat_y:
                    continue
                edge = None
                for corner in range(3):
                    a = points[corner]
                    b = points[(corner + 1) % 3]
                    if abs(a[2] - b[2]) > EPS or a[2] > low + EPS:
                        continue
                    edge = (a, b)
                    break
                if edge is None:
                    continue
                first, second = edge
                if abs(first[0] - second[0]) > EPS and abs(first[1] - second[1]) > EPS:
                    continue
                on_border = (
                    (abs(first[0]) <= EPS and abs(second[0]) <= EPS)
                    or (abs(first[0] - 1.0) <= EPS and abs(second[1 - 1] - 1.0) <= EPS)
                    or (abs(first[1]) <= EPS and abs(second[1]) <= EPS)
                    or (abs(first[1] - 1.0) <= EPS and abs(second[1] - 1.0) <= EPS))
                if on_border:
                    continue
                width = abs(second[0] - first[0]) + abs(second[1] - first[1])
                faces.append((round(high - low, 3), round(width, 3), cell, low, high))

    print("faces on the lower edge of a ramp: %d" % len(faces))
    by_drop = defaultdict(list)
    for drop, width, cell, low, high in faces:
        by_drop[drop].append(width)

    print()
    print("drop | count | widths of the lower edge")
    for drop in sorted(by_drop):
        widths = Counter(by_drop[drop])
        summary = " ".join("%s:%d" % (w, n) for w, n in sorted(widths.items()))
        print("%4.1f | %5d | %s" % (drop, len(by_drop[drop]), summary))

    full = [f for f in faces if abs(f[1] - 1.0) <= EPS]
    print()
    print("faces whose lower edge spans the whole side of the cell: %d" % len(full))
    print("   their drops: %s" % sorted(Counter(f[0] for f in full).items()))
    narrow = [f for f in faces if abs(f[1] - 1.0) > EPS]
    print("fragments: %d" % len(narrow))
    print("   their drops: %s" % sorted(Counter(f[0] for f in narrow).items()))
    print("   their widths: %s" % sorted(Counter(f[1] for f in narrow).items()))

    print()
    print("the levels of the faces with a fragment:")
    levels = Counter((f[3], f[4]) for f in narrow)
    for (low, high), n in sorted(levels.items(), key=lambda kv: -kv[1]):
        print("   %.1f -> %.1f : %d" % (low, high, n))
    print()
    print("the levels of the faces with a whole side:")
    levels = Counter((f[3], f[4]) for f in full)
    for (low, high), n in sorted(levels.items(), key=lambda kv: -kv[1]):
        print("   %.1f -> %.1f : %d" % (low, high, n))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
