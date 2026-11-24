#!/usr/bin/env python3
"""Аудит шкалы высот главы: в каких единицах z объектов и z вершин меша.

Вопрос: объект из шаблона стоит на уровне L. Движок (Diggles.exe) переводит
уровень в world-Z как 7.0 + 0.5 * L. Порт кладёт объект в сцену как
2*z - 14, а сцену пакует как world = 0.5 * BDB + 7, то есть получает
world-Z = литерал. Проверяем, какая из двух гипотез согласуется с геометрией
выгрузки: литерал = world-Z (A) или литерал = уровень (B).

Метрика: объект, стоящий на земле, должен попасть в одну из вершин меша своей
клетки. Считаем расстояние до ближайшей вершины по z и долю попаданий в +-0.25.

Только чтение. Пишет ничего.
"""
from __future__ import annotations

import json
import statistics
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MODELS = ROOT / "godot" / "models" / "native_campaign_models.json"
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"

GROUNDED = {
    "Zwerg", "Pilz", "Grillpilz", "Schatztonne", "Hamster", "Grillhamster",
    "Troll", "Raupe", "Kohle", "Farm", "Stein", "Pilzstamm", "Baum",
    "Schatz", "Truhe", "Kiste", "Fass", "Sack", "Knochen",
}


def q(values, part):
    if not values:
        return None
    ordered = sorted(values)
    return round(ordered[min(len(ordered) - 1, int(len(ordered) * part))], 4)


def main() -> int:
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    models = json.loads(MODELS.read_text(encoding="utf-8"))

    print("=== 1. Структура выгрузки главы ===")
    print("ключи главы:", list(chapter.keys()))
    cells = chapter.get("cells", [])
    if isinstance(cells, dict):
        cells = list(cells.values())
    print("клеток:", len(cells))
    if cells:
        print("поля клетки:", sorted(cells[0].keys()))
        print("пример клетки:", {k: v for k, v in list(cells[0].items())[:12] if not isinstance(v, (list, dict))})

    print()
    print("=== 2. z вершин меша (BDB-выгрузка) ===")
    meshes = chapter.get("meshes", {})
    zs = []
    for parts in meshes.values():
        for part in parts:
            verts = part.get("vertices") or []
            for i in range(len(verts) // 5):
                zs.append(float(verts[i * 5 + 2]))
    if zs:
        print("вершин: %d  min=%s  max=%s  p10=%s  median=%s  p90=%s" % (
            len(zs), round(min(zs), 3), round(max(zs), 3), q(zs, 0.1), q(zs, 0.5), q(zs, 0.9)))
        hist = Counter(round(v * 2) / 2 for v in zs)
        print("чаще всего (шаг 0.5):", hist.most_common(8))
    else:
        print("мешей нет")

    print()
    print("=== 3. Высоты клеток (поля level/height) ===")
    for key in ("level", "height", "z", "surface"):
        vals = [float(c[key]) for c in cells if isinstance(c.get(key), (int, float))]
        if vals:
            print("%-8s n=%d min=%s max=%s median=%s p90=%s" % (
                key, len(vals), round(min(vals), 3), round(max(vals), 3), q(vals, 0.5), q(vals, 0.9)))
            print("         чаще всего:", Counter(vals).most_common(6))

    print()
    print("=== 4. Размещения объектов (манифест моделей) ===")
    placements = models.get("placements", [])
    print("размещений:", len(placements))
    if placements:
        print("поля размещения:", sorted(placements[0].keys()))
    pz = [float(p["z"]) for p in placements if isinstance(p.get("z"), (int, float))]
    if pz:
        print("z: min=%s max=%s median=%s p10=%s p90=%s" % (
            round(min(pz), 3), round(max(pz), 3), q(pz, 0.5), q(pz, 0.1), q(pz, 0.9)))
        neg = [p for p in placements if float(p.get("z", 0)) < 0]
        print("с z < 0: %d, классы: %s" % (
            len(neg), sorted({p.get("class", "?") for p in neg})[:20]))

    print()
    print("=== 5. Гипотезы о шкале z объекта (по мешу своей клетки) ===")
    cell_index = {}
    for c in cells:
        if "x" in c and "y" in c:
            cell_index[(int(c["x"]), int(c["y"]))] = c

    def cell_zs(cell):
        block = cell.get("block")
        if block is None:
            return None
        parts = meshes.get(str(block))
        if not parts:
            return None
        out = []
        for part in parts:
            verts = part.get("vertices") or []
            for i in range(len(verts) // 5):
                out.append(float(verts[i * 5 + 2]))
        return out or None

    rows = []
    for p in placements:
        cls = str(p.get("class", ""))
        if cls not in GROUNDED:
            continue
        if p.get("story"):
            continue
        x = float(p.get("x", 0))
        y = float(p.get("y", 0))
        cell = cell_index.get((int(x // 1), int(y // 1)))
        if cell is None:
            continue
        zs_cell = cell_zs(cell)
        if not zs_cell:
            continue
        rows.append((cls, zs_cell, float(p["z"])))

    print("объектов с мехом своей клетки: %d" % len(rows))
    for name, conv in (
        ("A) литерал = world-Z (портовская текущая: world = z)", lambda v: v),
        ("B) литерал = уровень (движок: world = 7.0 + 0.5*z)", lambda v: 7.0 + 0.5 * v),
    ):
        errs = []
        for _cls, zs_cell, lit in rows:
            target = conv(lit)
            errs.append(min(abs(z - target) for z in zs_cell))
        if not errs:
            continue
        hit = sum(1 for e in errs if e <= 0.25)
        print("%-52s median=%s  mean=%s  hit<=0.25: %.1f%%  p90=%s" % (
            name, round(statistics.median(errs), 4), round(sum(errs) / len(errs), 4),
            100.0 * hit / len(errs), round(q(errs, 0.9), 4)))

    print()
    print("=== 6. То же, но по классам (B-гипотеза, выборка) ===")
    by_class = {}
    for cls, zs_cell, lit in rows:
        by_class.setdefault(cls, []).append(min(abs(z - (7.0 + 0.5 * lit)) for z in zs_cell))
    for cls, errs in sorted(by_class.items())[:12]:
        print("  %-14s n=%3d median=%s hit<=0.25: %.0f%%" % (
            cls, len(errs), round(statistics.median(errs), 4),
            100.0 * sum(1 for e in errs if e <= 0.25) / len(errs)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
