#!/usr/bin/env python3
"""З2 — decisive test: is the template z literal a LEVEL or a world-Z?

The engine converts object z to world-Z with the SAME formula it uses for cell
heights:  world_Z = 7.0 + 0.5 * level
(evidence: FUN_00496300:48, FUN_0052d170:613 for objects;
            FUN_004c8220:33/44 for cells).

Test: for every object in the port's chapter export, find the terrain surface
Z of the cell it stands on (from the port's own mesh data, vertices are already
in world-Z) and compare
    A) |literal          - terrain_Z|
    B) |7.0 + 0.5*literal - terrain_Z|
Whichever is systematically smaller wins.

Read-only.  Writes nothing outside work/campaign/caves-decomp/.
"""
from __future__ import annotations

import json
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"


def cell_surface_z(cells_by_xy, meshes, x, y):
    """Max world-Z of the mesh vertices of cell (x, y); None if no cell."""
    c = cells_by_xy.get((x, y))
    if c is None:
        return None
    blk = meshes.get(str(c.get("block")))
    if not blk:
        return None
    best = None
    for part in blk:
        vs = part.get("vertices") or []
        for i in range(2, len(vs), 3):
            z = vs[i]
            if best is None or z > best:
                best = z
    return best


def main() -> int:
    d = json.loads(CHAPTER.read_text(encoding="utf-8"))
    cells = d["cells"]
    meshes = d["meshes"]
    objects = d["objects"]

    cells_by_xy = {(c["x"], c["y"]): c for c in cells}
    print(f"cells {len(cells)}  objects {len(objects)}")

    # surface Z per cell
    surf = {}
    for (x, y) in cells_by_xy:
        z = cell_surface_z(cells_by_xy, meshes, x, y)
        if z is not None:
            surf[(x, y)] = z
    print(f"cells with mesh surface Z: {len(surf)}")
    if surf:
        vals = sorted(surf.values())
        print(f"  surface Z range {vals[0]:.3f} .. {vals[-1]:.3f}")

    # compare
    res = []
    for o in objects:
        x, y, z = o.get("x"), o.get("y"), o.get("z")
        if not isinstance(x, (int, float)) or not isinstance(y, (int, float)):
            continue
        if not isinstance(z, (int, float)):
            continue
        cz = surf.get((int(x // 1), int(y // 1)))
        if cz is None:
            # try neighbouring cells
            bx, by = int(x // 1), int(y // 1)
            cand = [surf.get((bx + dx, by + dy)) for dx in (-1, 0, 1) for dy in (-1, 0, 1)]
            cand = [c for c in cand if c is not None]
            if not cand:
                continue
            cz = max(cand)
        res.append((o.get("class"), z, cz))

    print(f"\nobjects with terrain reference: {len(res)}")
    if not res:
        return 0

    errA = [abs(z - cz) for _, z, cz in res]
    errB = [abs(7.0 + 0.5 * z - cz) for _, z, cz in res]
    n = len(res)

    def stat(err):
        s = sorted(err)
        return (s[n // 2], sum(err) / n, s[int(n * 0.9)])

    mA, aA, p90A = stat(errA)
    mB, aB, p90B = stat(errB)
    print(f"\nA) literal as world-Z   : median |err| = {mA:.3f}   mean = {aA:.3f}   p90 = {p90A:.3f}")
    print(f"B) literal as level     : median |err| = {mB:.3f}   mean = {aB:.3f}   p90 = {p90B:.3f}")
    print(f"\n=> better reading: {'A (world-Z)' if aA < aB else 'B (level 7+0.5z)'}")

    # split by class family: decor vs characters
    print("\n--- per class family (mean |err|) ---")
    fam = defaultdict(lambda: [0, 0.0, 0.0, 0])
    for cls, z, cz in res:
        key = cls.split("_")[0] if cls.startswith("Dummy_") else (
            "Dummy" if str(cls).startswith("Dummy") else "other")
        f = fam[key]
        f[0] += 1
        f[1] += abs(z - cz)
        f[2] += abs(7.0 + 0.5 * z - cz)
        f[3] = min(f[3], z) if f[3] != 0 else z
    for k, (cnt, sa, sb, mn) in sorted(fam.items(), key=lambda kv: -kv[1][0]):
        print(f"  {k:<10} n={cnt:<5} A(mean)={sa/cnt:7.3f}  B(mean)={sb/cnt:7.3f}")

    # show the worst offenders under the winning reading
    win = 0 if aA < aB else 1
    print(f"\n--- worst 15 under the WINNING reading ({'A world-Z' if win==0 else 'B level'}) ---")
    scored = []
    for cls, z, cz in res:
        e = abs(z - cz) if win == 0 else abs(7.0 + 0.5 * z - cz)
        scored.append((e, cls, z, cz))
    scored.sort(reverse=True)
    for e, cls, z, cz in scored[:15]:
        w = z if win == 0 else 7.0 + 0.5 * z
        print(f"  err={e:8.3f}  {str(cls):<28} literal={z:9.2f} -> world={w:9.2f}  terrain={cz:7.2f}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
