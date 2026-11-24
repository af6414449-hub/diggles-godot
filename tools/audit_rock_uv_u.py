#!/usr/bin/env python3
"""Как оригинал считает текстурные координаты породы: U и V.

Для вершин, у которых V точно равно z − 7.0 (правило оригинала по нижней
кромке породы), проверяем, чему равен U: локальной координате клетки, мировой
координате клетки, или чему-то ещё.

Только чтение.
"""
from __future__ import annotations

import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"

ORIGIN_WORLD_Z = 7.0


def main() -> int:
    data = json.loads(CHAPTER.read_text(encoding="utf-8"))
    meshes = data["meshes"]
    hits = 0
    u_is_x = 0
    u_is_y = 0
    u_is_x_plus_y = 0
    u_other = Counter()
    samples = []
    for parts in meshes.values():
        for part in parts:
            values = part["vertices"]
            for i in range(len(values) // 5):
                x = float(values[i * 5 + 0])
                y = float(values[i * 5 + 1])
                z = float(values[i * 5 + 2])
                u = float(values[i * 5 + 3])
                v = float(values[i * 5 + 4])
                if abs(v - (z - ORIGIN_WORLD_Z)) >= 1e-4:
                    continue
                hits += 1
                if abs(u - x) < 1e-4:
                    u_is_x += 1
                elif abs(u - y) < 1e-4:
                    u_is_y += 1
                elif abs(u - (x + y)) < 1e-4:
                    u_is_x_plus_y += 1
                else:
                    u_other[round(u, 3)] += 1
                if len(samples) < 8:
                    samples.append((round(x, 3), round(y, 3), round(z, 3), round(u, 3), round(v, 3)))

    print("вершин с V = z − 7.0: %d" % hits)
    print("  U == x (локальная клетка): %d" % u_is_x)
    print("  U == y:                     %d" % u_is_y)
    print("  U == x + y:                 %d" % u_is_x_plus_y)
    print("  прочие значения U (топ-8):  %s" % u_other.most_common(8))
    print("примеры (x, y, z, u, v):")
    for sample in samples:
        print("   ", sample)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
