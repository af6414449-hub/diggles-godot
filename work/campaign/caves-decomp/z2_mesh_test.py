#!/usr/bin/env python3
"""З2 — финальный тест шкалы z объекта по геометрии клетки главы.

Формат вершин в экспорте: плоский список по 5 float на вершину (x, y, z, u, v).
z вершин — уже world-Z (диапазон 7.0 .. 14.5).

Гипотезы:
    A) литерал из шаблона = world-Z          -> z_world = literal
    B) литерал из шаблона = уровень шкалы    -> z_world = 7.0 + 0.5 * literal

Метрика: объект, стоящий на земле, должен совпасть с одной из вершин меша
своей клетки (уступ/пол). Поэтому считаем расстояние до БЛИЖАЙШЕЙ вершины
и долю объектов, попавших в +-0.25 от вершины.

Только чтение. Ничего вне work/campaign/caves-decomp/ не пишется.
"""
from __future__ import annotations

import json
import statistics
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"

# классы, которые по своей природе стоят на земле
GROUNDED = {
    "Zwerg", "Pilz", "Grillpilz", "Schatztonne", "Hamster", "Grillhamster",
    "Troll", "Raupe", "Kohle", "Farm", "Stein", "Pilzstamm", "Baum",
    "Schatz", "Truhe", "Kiste", "Fass", "Sack", "Knochen",
}

# надземный (Oberwelt) декор: отдельная система координат
OBERWELT_MARK = ("Dummy_Urw_", "Dummy_Kris_", "Dummy_Lav_", "Dummy_Met_",
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


def nearest(zs, value):
    return min(abs(z - value) for z in zs)


def stats(rows, conv):
    errs = sorted(nearest(zs, conv(lit)) for _, zs, lit, _ in rows)
    n = len(rows)
    hit = sum(1 for e in errs if e <= 0.25)
    return statistics.median(errs), sum(errs) / n, hit / n, errs[int(n * 0.9)]


def main() -> int:
    d = json.loads(CHAPTER.read_text(encoding="utf-8"))
    cells = {(c["x"], c["y"]): c for c in d["cells"]}
    meshes = d["meshes"]

    rows = []
    skipped = 0
    for o in d["objects"]:
        x, y, z = o.get("x"), o.get("y"), o.get("z")
        if not all(isinstance(v, (int, float)) for v in (x, y, z)):
            continue
        c = cells.get((int(x), int(y)))
        if c is None:
            skipped += 1
            continue
        zs = cell_zs(meshes, c.get("block"))
        if not zs:
            skipped += 1
            continue
        rows.append((str(o.get("class")), zs, float(z), (int(x), int(y))))

    print(f"объектов с клеткой и мешем: {len(rows)}  (пропущено {skipped})")

    groups = [("ВСЕ", rows)]
    g = [r for r in rows if r[0] in GROUNDED]
    if g:
        groups.append(("ЗАЗЕМЛЁННЫЕ КЛАССЫ", g))
    ow = [r for r in rows if r[0].startswith(OBERWELT_MARK)]
    if ow:
        groups.append(("OBERWELT-ДЕКОР", ow))
    un = [r for r in rows if not r[0].startswith(OBERWELT_MARK)]
    groups.append(("БЕЗ OBERWELT", un))

    for name, rs in groups:
        if not rs:
            continue
        mA, aA, hA, pA = stats(rs, lambda z: z)
        mB, aB, hB, pB = stats(rs, lambda z: 7.0 + 0.5 * z)
        print(f"\n{name} (n={len(rs)})")
        print(f"  A) литерал = world-Z : median={mA:6.3f} mean={aA:6.3f} "
              f"p90={pA:6.3f} доля в +-0.25 от вершины={hA:6.1%}")
        print(f"  B) литерал = уровень : median={mB:6.3f} mean={aB:6.3f} "
              f"p90={pB:6.3f} доля в +-0.25 от вершины={hB:6.1%}")

    # сколько объектов каждой группы реально «стоят на вершине» под B
    print("\n--- примеры: ближайшая вершина клетки ---")
    for cls, zs, z, xy in rows:
        if cls != "Zwerg":
            continue
        zb = 7.0 + 0.5 * z
        print(f"  Zwerg xy={xy} литерал={z:7.2f} -> A={z:7.2f} B={zb:7.2f} | "
              f"вершины клетки={sorted(set(round(v,2) for v in zs))}")

    # распределение литералов по классам-надземникам
    print("\n--- классы с отрицательным литералом (Oberwelt) ---")
    cnt = Counter(r[0] for r in rows if r[2] < 0)
    for name, n in cnt.most_common(12):
        lits = [r[2] for r in rows if r[0] == name]
        print(f"  {name:30s} n={n:4d} z: {min(lits):8.2f} .. {max(lits):8.2f}")

    # сколько объектов главы имеют литерал < 0 (т.е. уровень < 0)
    neg = [r for r in rows if r[2] < 0 and not r[0].startswith(OBERWELT_MARK)]
    print(f"\nобъектов главы с литералом < 0 и не Oberwelt: {len(neg)}")
    for cls, zs, z, xy in neg[:20]:
        print(f"   {cls:28s} xy={xy} литерал={z:8.2f} -> worldZ={7.0+0.5*z:8.2f}")

    low = [r for r in rows if 7.0 + 0.5 * r[2] < 7.0]
    print(f"\nобъектов с world-Z < 7.0 (ниже низа породы) под B: {len(low)}")
    for cls, zs, z, xy in low[:20]:
        print(f"   {cls:28s} xy={xy} литерал={z:8.2f} -> worldZ={7.0+0.5*z:8.2f}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
