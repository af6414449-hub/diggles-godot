#!/usr/bin/env python3
"""Проверка вертикальной текстурной координаты породы: v = z − 7.0?

Декомпиляция (З2, дополнение №2) утверждает: в оригинале вертикальная
координата текстуры породы отсчитывается от низа породы, то есть
    v = z − 7.0    (z — world-Z из экспорта, 7.0 — низ базовой карты).

Проверяем по экспорту главы: сколько вершин удовлетворяют равенству точно,
сколько имеют локальные UV в [0,1], и что получается при старом правиле порта
(ROCK_BOTTOM = 0.25).

Только чтение.
"""
from __future__ import annotations

import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"

ORIGIN_WORLD_Z = 7.0      # низ базовой карты (уровень 0)
PORT_ROCK_BOTTOM = 0.25   # константа порта (уровневая шкала, но используется как world-Z)


def main() -> int:
    data = json.loads(CHAPTER.read_text(encoding="utf-8"))
    meshes = data["meshes"]
    total = 0
    exact_origin = 0
    near_origin = 0
    local_uv = 0
    old_rule = 0
    other = 0
    samples = []
    for parts in meshes.values():
        for part in parts:
            values = part["vertices"]
            for i in range(len(values) // 5):
                z = float(values[i * 5 + 2])
                v = float(values[i * 5 + 4])
                total += 1
                if abs(v - (z - ORIGIN_WORLD_Z)) < 1e-4:
                    exact_origin += 1
                    if len(samples) < 6:
                        samples.append((z, v))
                elif abs(v - (z - PORT_ROCK_BOTTOM)) < 1e-4:
                    old_rule += 1
                elif 0.0 <= v <= 1.0:
                    local_uv += 1
                else:
                    other += 1
                    if len(samples) < 6:
                        samples.append(("?", z, v))

    print("вершин всего: %d" % total)
    print("  v == z − 7.0 (низ породы, правило оригинала): %d (%.1f %%)"
          % (exact_origin, 100.0 * exact_origin / max(total, 1)))
    print("  v == z − 0.25 (старое правило порта):            %d" % old_rule)
    print("  локальные UV в [0,1] (модельная текстура):       %d (%.1f %%)"
          % (local_uv, 100.0 * local_uv / max(total, 1)))
    print("  прочие:                                           %d" % other)
    print("примеры:", samples[:6])

    # сколько вершин попадает в оба правила с точностью 0.01
    both = 0
    for parts in meshes.values():
        for part in parts:
            values = part["vertices"]
            for i in range(len(values) // 5):
                z = float(values[i * 5 + 2])
                v = float(values[i * 5 + 4])
                if abs(v - (z - ORIGIN_WORLD_Z)) < 0.01 and abs(v - (z - PORT_ROCK_BOTTOM)) < 0.01:
                    both += 1
    print("совпадение обоих правил (в пределах 0.01): %d" % both)
    print("распределение v:", Counter(
        round(float(values[i * 5 + 4]), 3)
        for parts in meshes.values() for part in parts
        for values in [part["vertices"]] for i in range(len(values) // 5)
    ).most_common(6))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
