#!/usr/bin/env python3
"""З2: does the template's z literal mean "level" (0.5*z+7.0) or world-Z?

We compare the z literals from the ORIGINAL game's template .tcl files against
the z values stored in the port's export, and against the engine's known
level scale (world-Z = 7.0 + 0.5*level, so level = (world_z - 7.0) * 2).

For every template object we know:
  * template z literal  (from data/Templates/*.tcl, installed game)
  * the port's exported z (godot/models/native_campaign_models.json)

If the engine treats the literal as a LEVEL, then the exported world-Z should
be about 7.0 + 0.5*literal.  If the literal is already a world-Z, the
exported z should equal the literal.

Read-only.  Writes nothing outside work/campaign/caves-decomp/.
"""
from __future__ import annotations

import json
import re
import sys
from collections import Counter
from pathlib import Path

GAME = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris")
TPL = GAME / "data" / "Templates"
PORT_MODELS = Path("godot/models/native_campaign_models.json")

# new <Class> "" "[expr {X + $xoffset}] [expr {Y + $yoffset}] Z" "rx ry rz"
RE_NEW = re.compile(
    r'new\s+(\S+)\s+""\s+"\[expr\s*\{([^}]+)\}\]\s+\[expr\s*\{([^}]+)\}\]\s+(-?[\d.eE+-]+)\s*"',
)


def template_objects() -> list[tuple[str, float, str]]:
    out = []
    for tcl in sorted(TPL.glob("*.tcl")):
        try:
            txt = tcl.read_text(encoding="latin-1", errors="replace")
        except OSError:
            continue
        for m in RE_NEW.finditer(txt):
            cls = m.group(1)
            try:
                z = float(m.group(4))
            except ValueError:
                continue
            out.append((cls, z, tcl.stem))
    return out


def main() -> int:
    tobs = template_objects()
    print(f"template objects parsed : {len(tobs)}")

    by_cls: dict[str, list[float]] = {}
    for cls, z, _ in tobs:
        by_cls.setdefault(cls, []).append(z)

    print("\n--- z literal statistics per class (top 25 by count) ---")
    counts = Counter(cls for cls, _, _ in tobs)
    for cls, n in counts.most_common(25):
        zs = sorted(by_cls[cls])
        neg = sum(1 for z in zs if z < 0)
        print(
            f"{cls:<28} n={n:<5} min={zs[0]:>10.3f} max={zs[-1]:>10.3f} "
            f"med={zs[len(zs)//2]:>9.3f} neg={neg}"
        )

    print("\n--- classes whose z literals are ALL negative ---")
    for cls, zs in sorted(by_cls.items()):
        if zs and all(z < 0 for z in zs):
            print(f"{cls:<28} n={len(zs):<4} range [{min(zs):.2f}, {max(zs):.2f}]")

    print("\n--- what would the LEVEL reading give (world-Z = 7.0 + 0.5*z)? ---")
    neg = [(c, z) for c, z, _ in tobs if z < 0]
    if neg:
        for cls, z in neg[:15]:
            print(f"  {cls:<26} literal z={z:>9.2f} -> level world-Z = {7.0 + 0.5 * z:>9.2f}")
        lv = [7.0 + 0.5 * z for _, z in neg]
        print(f"  negative-literal objects: n={len(neg)} "
              f"level-world-Z range [{min(lv):.2f}, {max(lv):.2f}]")
        print("  (rock bottom is world-Z 7.0 => level 0; a negative literal")
        print("   would put the object BELOW the bottom of the rock)")

    # ---- compare with the port export -------------------------------------
    if not PORT_MODELS.exists():
        print(f"\n(port export not found at {PORT_MODELS})")
        return 0
    data = json.loads(PORT_MODELS.read_text(encoding="utf-8", errors="replace"))
    items = data if isinstance(data, list) else data.get("objects") or data.get("items") or []
    print(f"\nport export entries      : {len(items)}")
    if items:
        print("sample entry keys        :", sorted(items[0].keys())[:14])

    zvals = [o.get("z") for o in items if isinstance(o.get("z"), (int, float))]
    if zvals:
        zvals_sorted = sorted(zvals)
        n = len(zvals_sorted)
        print(f"port z: min={zvals_sorted[0]:.2f} "
              f"p1={zvals_sorted[n//100]:.2f} p5={zvals_sorted[n//20]:.2f} "
              f"med={zvals_sorted[n//2]:.2f} p95={zvals_sorted[19*n//20]:.2f} "
              f"max={zvals_sorted[-1]:.2f}")

        # how many port z values would be "level" readings of the literals?
        lit = sorted(z for _, z, _ in tobs)
        print("\n--- overlap test: are port z values equal to literal, or to 7+0.5*literal? ---")
        exact = 0
        as_level = 0
        for o in items:
            z = o.get("z")
            if not isinstance(z, (int, float)):
                continue
            if any(abs(z - l) < 0.01 for l in lit):
                exact += 1
            if any(abs(z - (7.0 + 0.5 * l)) < 0.01 for l in lit):
                as_level += 1
        print(f"  port z matches a literal exactly          : {exact}")
        print(f"  port z matches 7.0+0.5*literal            : {as_level}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
