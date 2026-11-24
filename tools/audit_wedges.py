#!/usr/bin/env python3
"""Что такое «клин угла выработки» (3625 шт.) — проверка на исходных данных.

Клин считается так же, как в tools/audit_caves.py: наклонный треугольник, у
которого нижнее ребро диагональное (оба конца ребра отличаются по x и y).

Проверяем:
  1. откуда геометрия: блоки читаются из BlockDB2.BDB (оригинальная игра);
  2. лежит ли диагональное нижнее ребро на главной диагонали клетки
     (т.е. это «скос угла» блока) или внутри клетки;
  3. смотрит ли клин наружу (в сторону выкопанного соседа) — тогда он виден
     в оригинале, — или внутрь породы (тогда в оригинале он закрыт);
  4. сколько частей (part 0/1/2) блока содержат клин.

Только чтение.
"""
from __future__ import annotations

import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
EPS = 1e-6


def triangles(part):
    values = part["vertices"]
    indices = part["indices"]
    for start in range(0, len(indices), 3):
        pts = []
        for corner in range(3):
            offset = int(indices[start + corner]) * 5
            pts.append((values[offset], values[offset + 1], values[offset + 2]))
        yield pts


def main() -> int:
    data = json.loads(CHAPTER.read_text(encoding="utf-8"))
    meshes = data["meshes"]
    cells = {(int(c["x"]), int(c["y"])): c for c in data["cells"]}
    materials = data.get("materials", {})

    part_wedges = Counter()
    diagonal_of_cell = 0
    inside_cell = 0
    outward = 0
    inward = 0
    samples = []

    for cell, entry in cells.items():
        cx, cy = cell
        for part in meshes[str(int(entry["block"]))]:
            for pts in triangles(part):
                heights = [p[2] for p in pts]
                if max(heights) - min(heights) <= EPS:
                    continue
                low = [p for p in pts if abs(p[2] - min(heights)) <= EPS]
                if len(low) != 2:
                    continue
                a, b = low
                if abs(a[0] - b[0]) <= EPS or abs(a[1] - b[1]) <= EPS:
                    continue
                # клин найден
                part_wedges[int(part.get("part", -1))] += 1
                # нижнее ребро: диагональ клетки?
                corners = {(cx, cy), (cx + 1, cy), (cx, cy + 1), (cx + 1, cy + 1)}
                edge = {(round(a[0], 4), round(a[1], 4)), (round(b[0], 4), round(b[1], 4))}
                if edge <= corners:
                    diagonal_of_cell += 1
                else:
                    inside_cell += 1
                # направление: третья (верхняя) вершина выше и с другой стороны?
                top = max(pts, key=lambda p: p[2])
                # вектор от центра нижнего ребра к верхней вершине
                mid = ((a[0] + b[0]) / 2.0, (a[1] + b[1]) / 2.0)
                dx, dy = top[0] - mid[0], top[1] - mid[1]
                # сторона клетки, к которой обращён клин
                sx = 0 if abs(dx) < EPS else (1 if dx > 0 else -1)
                sy = 0 if abs(dy) < EPS else (1 if dy > 0 else -1)
                # ближайший сосед в этом направлении
                nb = (cx + sx, cy + sy)
                nb_material = materials.get(f"{nb[0]},{nb[1]}")
                excavated = nb in cells and nb_material is not None and int(nb_material) == 3
                if excavated:
                    outward += 1
                else:
                    inward += 1
                if len(samples) < 8:
                    samples.append({
                        "cell": cell, "part": int(part.get("part", -1)),
                        "pts": [(round(p[0], 3), round(p[1], 3), round(p[2], 3)) for p in pts],
                        "направление": (sx, sy), "сосед": nb,
                        "материал соседа": nb_material, "выкопан": excavated,
                    })

    total = sum(part_wedges.values())
    print("клинов всего: %d" % total)
    print("по частям блока (part):", dict(part_wedges))
    print("нижнее ребро = диагональ клетки: %d, внутри клетки: %d" % (diagonal_of_cell, inside_cell))
    print("клин смотрит в выкопанного соседа (виден в оригинале): %d" % outward)
    print("клин смотрит в породу (в оригинале закрыт): %d" % inward)
    print()
    print("примеры:")
    for sample in samples:
        print(" ", sample)
    print()
    print("материалы: значения и сколько клеток:", Counter(materials.values()))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
