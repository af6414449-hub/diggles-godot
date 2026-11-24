#!/usr/bin/env python3
"""З2 — сколько объектов останется «над поверхностью»/«в породе» после конвертации.

Сравнивает мировую Z объекта (7.0 + 0.5*литерал) с поверхностью его клетки —
верхней вершиной меша клетки (экспорт: вершины плоским списком по 5 float x,y,z,u,v).

Печатает счётчики для:
  A) текущее поведение порта: world-Z = литерал
  B) поведение движка:          world-Z = 7.0 + 0.5*литерал

и перечисляет объекты, которые после перевода окажутся выше поверхности.
Только чтение.
"""
from __future__ import annotations

import json
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"

OBERWELT = ("Dummy_Urw_", "Dummy_Kris_", "Dummy_Lav_", "Dummy_Lava_", "Dummy_Met_",
            "Dummy_Swf_", "Dummy_Obw_", "Dummy_Brain_borg_")


def cell_zs(meshes, block):
    parts = meshes.get(str(block))
    if not parts:
        return None
    zs = []
    for part in parts:
        vs = part.get("vertices") or []
        for i in range(len(vs) // 5):
            zs.append(vs[i * 5 + 2])
    return zs


def main() -> int:
    d = json.loads(CHAPTER.read_text(encoding="utf-8"))
    cells = {(c["x"], c["y"]): c for c in d["cells"]}
    meshes = d["meshes"]

    rows = []
    for o in d["objects"]:
        x, y, z = o.get("x"), o.get("y"), o.get("z")
        if not all(isinstance(v, (int, float)) for v in (x, y, z)):
            continue
        c = cells.get((int(x), int(y)))
        if c is None:
            continue
        zs = cell_zs(meshes, c.get("block"))
        if not zs:
            continue
        rows.append((str(o.get("class")), float(z), max(zs), min(zs), (int(x), int(y))))

    print(f"объектов с клеткой и мешем: {len(rows)}")
    tol = 0.5
    for label, conv in (("A) порт сейчас: world-Z = литерал", lambda z: z),
                        ("B) движок:       world-Z = 7.0+0.5*z", lambda z: 7.0 + 0.5 * z)):
        above = [r for r in rows if conv(r[1]) > r[2] + tol]
        below = [r for r in rows if conv(r[1]) < 7.0]
        under = [r for r in rows if conv(r[1]) < r[3] - tol]
        print(f"\n{label}")
        print(f"  выше поверхности клетки на >{tol}: {len(above)}")
        print(f"  ниже низа породы (world-Z < 7.0)   : {len(below)}")
        print(f"  ниже пола клетки на >{tol}         : {len(under)}")
        c = Counter(r[0] for r in above)
        if c:
            print("  из них по классам:", ", ".join(f"{k}:{v}" for k, v in c.most_common(8)))

    print("\n--- после перевода (B): объекты выше поверхности ---")
    for cls, z, top, low, xy in rows:
        zb = 7.0 + 0.5 * z
        if zb > top + tol:
            tag = "OBERWELT" if cls.startswith(OBERWELT) else ""
            print(f"  {cls:28s} xy={xy} литерал={z:8.2f} -> world={zb:7.2f} "
                  f"поверхность клетки={top:6.2f} {tag}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
