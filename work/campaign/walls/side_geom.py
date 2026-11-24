"""The geometry of one cell of the chapter: its triangles and its side profiles.

The module builds a vertical face on the lower edge of a ramp of the export. This
script prints, for one cell, every triangle of its block mesh (the flat patches,
the ramps and the vertical faces of the export) and the profile of each of its
four sides, so the relation between the ramp, the profile and the face of the
module is visible without a guess.

Usage:
    python work/campaign/walls/side_geom.py <x> <y> [<x> <y> ...]
"""
import json
import pathlib
import sys
from collections import defaultdict

ROOT = pathlib.Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
EPS = 1e-4


def classify(points):
    flat_x = all(abs(p[0] - points[0][0]) <= EPS for p in points)
    flat_y = all(abs(p[1] - points[0][1]) <= EPS for p in points)
    z = [p[2] for p in points]
    if max(z) - min(z) <= EPS:
        return "flat"
    if flat_x:
        return "vertical x=const"
    if flat_y:
        return "vertical y=const"
    return "ramp"


def load():
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    return chapter["meshes"], {(int(c["x"]), int(c["y"])): int(c["block"]) for c in chapter["cells"]}


def dump_cell(meshes, blocks, x, y):
    block = blocks.get((x, y))
    print("=== cell (%d, %d) block=%s" % (x, y, block))
    if block is None:
        print("   (the cell is not in the export)")
        return
    tris = []
    for part in meshes.get(str(block), []):
        values = part["vertices"]
        indices = part["indices"]
        for start in range(0, len(indices), 3):
            pts = []
            for corner in range(3):
                off = int(indices[start + corner]) * 5
                pts.append((float(values[off]), float(values[off + 1]), float(values[off + 2])))
            tris.append(pts)
    for pts in tris:
        kind = classify(pts)
        zs = sorted(set(round(p[2], 3) for p in pts))
        print("  %-16s z=%-18s %s" % (kind, zs,
              "  ".join("(%.3f,%.3f,%.2f)" % p for p in pts)))
    # the profile of each side: the flat patches only, as the module does
    for side, axis, fixed in (("pos_x", 1, 1.0), ("neg_x", 1, 0.0),
                              ("pos_y", 0, 1.0), ("neg_y", 0, 0.0)):
        segs = []
        for pts in tris:
            if classify(pts) != "flat":
                continue
            on_side = all(abs(p[axis] - fixed) <= EPS for p in pts)
            if not on_side:
                continue
            ts = sorted(p[1 - axis] for p in pts)
            segs.append((ts[0], ts[-1], pts[0][2]))
        segs.sort()
        print("  side %-6s profile: %s" % (side,
              " ".join("[%.2f..%.2f z=%.2f]" % s for s in segs)))


def main() -> int:
    meshes, blocks = load()
    args = [int(a) for a in sys.argv[1:]]
    if len(args) < 2 or len(args) % 2:
        print(__doc__)
        return 1
    for i in range(0, len(args), 2):
        dump_cell(meshes, blocks, args[i], args[i + 1])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
