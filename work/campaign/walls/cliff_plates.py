"""The cliffs of the walls module on the raw triangles of the chapter.

The module builds a vertical face on the lower edge of a ramp: the width of the
face is the length of that edge and the height is the whole drop of the ramp.
When the lower edge is short and the drop is high, the face is a thin tall
plate that sticks out of the relief. This script measures the plates: the
width, the height and the horizontal run of every ramp that the module turns
into a face, and it prints the worst cases with their exact vertices.

Usage:
    python work/campaign/walls/cliff_plates.py [worst]
"""
import json
import pathlib
import sys
from collections import Counter

ROOT = pathlib.Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
EPS = 1e-4
CLIFF_HEIGHT = 2.0


def main() -> int:
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    meshes = chapter["meshes"]
    cells = chapter["cells"]

    widths = Counter()
    plates = []
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
                height = high - low
                if height <= EPS:
                    continue
                flat_x = all(abs(p[0] - points[0][0]) <= EPS for p in points)
                flat_y = all(abs(p[1] - points[0][1]) <= EPS for p in points)
                if flat_x or flat_y:
                    continue
                # the lower edge: the edge whose two ends are at the lowest level
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
                    continue  # a diagonal edge is not a face of the engine
                on_border = any(
                    (abs(a[0]) <= EPS and abs(b[0]) <= EPS)
                    or (abs(a[0] - 1.0) <= EPS and abs(b[0] - 1.0) <= EPS)
                    or (abs(a[1]) <= EPS and abs(b[1]) <= EPS)
                    or (abs(a[1] - 1.0) <= EPS and abs(b[1] - 1.0) <= EPS)
                    for a, b in ((first, second),))
                if on_border:
                    continue
                width = abs(second[0] - first[0]) + abs(second[1] - first[1])
                if height < CLIFF_HEIGHT:
                    continue
                widths[round(width, 3)] += 1
                # the horizontal run of the ramp: the distance from the lower
                # edge to the apex of the triangle
                third = [p for p in points if p is not first and p is not second]
                apex = third[0] if third else points[0]
                run = abs(apex[0] - first[0]) + abs(apex[1] - first[1])
                plates.append((width, height, run, cell, points))

    plates.sort(key=lambda item: (item[0], -item[1]))
    print("ramps that the module turns into a face: %d" % len(plates))
    print("width of the lower edge -> count: %s" % sorted(widths.items()))
    narrow = [p for p in plates if p[0] < 0.5]
    print("of them narrower than 0.5 cells: %d" % len(narrow))
    print()
    limit = int(sys.argv[1]) if len(sys.argv) > 1 else 5
    for width, height, run, cell, points in plates[:limit]:
        print("cell %s width=%.3f height=%.1f run=%.3f" % (cell, width, height, run))
        for p in points:
            print("   vertex x=%.3f y=%.3f z=%.2f" % p)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
