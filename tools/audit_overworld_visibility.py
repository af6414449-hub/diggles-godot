#!/usr/bin/env python3
"""Видны ли объекты надземного слоя (z < 0) в оригинале?

Движок объекты по z не отсекает: он рисует их на своей высоте
(world-Z = 7.0 + 0.5*z). Остров (меши блоков главы) закрывает всё, что под ним.
Значит объект надземного слоя ВИДЕН тогда и только тогда, когда его (x, y)
выходит за пределы острова — тогда он висит в пустоте у края, как деревья
на северной кромке главы (сравните с кадром оригинала у владельца).

Проверяем по выгрузке: клетка объекта (floor(x), floor(y)) есть в главе или нет.

Только чтение.
"""
from __future__ import annotations

import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CHAPTER = ROOT / "godot" / "models" / "native_campaign_chapter.json"
MANIFEST = ROOT / "godot" / "models" / "native_campaign_models.json"


def world_z(level: float) -> float:
    return 7.0 + 0.5 * level


def main() -> int:
    chapter = json.loads(CHAPTER.read_text(encoding="utf-8"))
    models = json.loads(MANIFEST.read_text(encoding="utf-8"))
    cells = {(int(c["x"]), int(c["y"])) for c in chapter["cells"]}
    xs = [x for x, _ in cells]
    ys = [y for _, y in cells]
    print("клеток главы: %d, прямоугольник: x %d..%d, y %d..%d"
          % (len(cells), min(xs), max(xs), min(ys), max(ys)))

    # клетки острова плюс их соседи: объект у самого края тоже может быть виден
    negative = [p for p in models["placements"] if float(p["z"]) < 0]
    print()
    print("объектов надземного слоя (z < 0): %d" % len(negative))
    inside = []
    outside = []
    for p in negative:
        cell = (int(float(p["x"]) // 1), int(float(p["y"]) // 1))
        (inside if cell in cells else outside).append((p, cell))

    print("  под островом (клетка главы) — в оригинале закрыты: %d" % len(inside))
    for p, cell in sorted(inside, key=lambda t: float(t[0]["z"])):
        print("     %-24s z=%-9s world-Z=%7.2f  x=%7.2f y=%7.2f  клетка=%s" % (
            p["class"], p["z"], world_z(float(p["z"])), p["x"], p["y"], cell))
    print()
    print("  ВНЕ острова — в оригинале висят у края, как деревья в референсе: %d" % len(outside))
    for p, cell in sorted(outside, key=lambda t: float(t[0]["z"])):
        print("     %-24s z=%-9s world-Z=%7.2f  x=%7.2f y=%7.2f  клетка=%s" % (
            p["class"], p["z"], world_z(float(p["z"])), p["x"], p["y"], cell))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
