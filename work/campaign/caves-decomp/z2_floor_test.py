#!/usr/bin/env python3
"""З2 — decisive test with the FLOOR (not max) of each cell.

For every object in the port's chapter export we take the mesh of the cell it
stands on and extract the vertex heights.  An object that stands on the ground
must sit at (or just above) the cell's FLOOR = the lowest vertex of that cell.

Then compare three hypotheses:
    A) literal is world-Z            -> |literal - floor|
    B) literal is a level            -> |7.0 + 0.5*literal - floor|
    C) literal is a level, +7 offset -> |7.0 + 0.5*literal - floor| (same as B)

Read-only.  Writes nothing outside work/campaign/caves-decomp/.
"""
from __future__ import annotations

import json
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"

# classes that unambiguously stand on the ground
GROUNDED = ("Zwerg", "Pilz", "Grillpilz", "Schatztonne", "Hamster", "Grillhamster",
            "Troll", "Raupe", "Kohle", "Farm", "Stein", "Pilzstamm")


def cell_zs(meshes, block):
    blk = meshes.get(str(block))
    if not blk:
        return None
    zs = []
    for part in blk:
        vs = part.get("vertices") or []
        zs.extend(vs[i] for i in range(2, len(vs), 3))
    return zs


def main() -> int:
    d = json.loads(CHAPTER.read_text(encoding="utf-8"))
    cells = {(c["x"], c["y"]): c for c in d["cells"]}
    meshes = d["meshes"]
    objects = d["objects"]

    rows = []
    for o in objects:
        x, y, z = o.get("x"), o.get("y"), o.get("z")
        if not all(isinstance(v, (int, float)) for v in (x, y, z)):
            continue
        c = cells.get((int(x // 1), int(y // 1)))
        if c is None:
            continue
        zs = cell_zs(meshes, c.get("block"))
        if not zs:
            continue
        floor, top = min(zs), max(zs)
        rows.append((o.get("class"), z, floor, top, (int(x // 1), int(y // 1))))

    print(f"objects with cell mesh: {len(rows)}")
    n = len(rows)

    def stat(fn):
        errs = sorted(abs(fn(z, floor)) for _, z, floor, _, _ in rows)
        return errs[n // 2], sum(errs) / n, errs[int(n * 0.9)]

    mA, aA, pA = stat(lambda z, f: z - f)
    mB, aB, pB = stat(lambda z, f: (7.0 + 0.5 * z) - f)
    print(f"\nALL objects (n={n})")
    print(f"  A) literal = world-Z : median |err|={mA:6.3f}  mean={aA:6.3f}  p90={pA:6.3f}")
    print(f"  B) literal = level   : median |err|={mB:6.3f}  mean={aB:6.3f}  p90={pB:6.3f}")

    g = [r for r in rows if str(r[0]) in GROUNDED]
    if g:
        m = len(g)
        print(f"\nGROUNDED classes only (n={m}) — must stand on the floor")
        eA = sorted(abs(z - f) for _, z, f, _, _ in g)
        eB = sorted(abs(7.0 + 0.5 * z - f) for _, z, f, _, _ in g)
        print(f"  A) literal = world-Z : median |err|={eA[m//2]:6.3f}  mean={sum(eA)/m:6.3f}")
        print(f"  B) literal = level   : median |err|={eB[m//2]:6.3f}  mean={sum(eB)/m:6.3f}")
        print("\n  sample grounded objects:")
        for cls, z, f, t, xy in g[:18]:
            print(f"    {str(cls):<14} xy={xy} literal={z:8.2f} floor={f:6.2f} top={t:6.2f}"
                  f"  |A|={abs(z-f):6.2f} |B|={abs(7.0+0.5*z-f):6.2f}")

    # Do the literal values cluster on the "level" grid 0..15 ?
    print("\n--- literal distribution vs the engine level grid ---")
    lit = sorted(z for _, z, _, _, _ in rows)
    half = [abs(z * 2 - round(z * 2)) for z in lit]
    print(f"  literals: n={len(lit)} min={lit[0]:.2f} med={lit[len(lit)//2]:.2f} max={lit[-1]:.2f}")
    print(f"  fraction of literals that are exact multiples of 0.5 : "
          f"{sum(1 for h in half if h < 1e-6)/len(half):.3f}")
    print(f"  fraction of literals that are exact multiples of 0.01: "
          f"{sum(1 for z in lit if abs(z*100 - round(z*100)) < 1e-6)/len(lit):.3f}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
