#!/usr/bin/env python3
"""Есть ли в выгрузке главы «настоящие» деревья стартовой площадки.

Спор: в референсе владельца на стартовой платформе стоят большие деревья.
Порт подставил вместо них 10 объектов надземного слоя (z < 0, world-Z < 7.0).
Проверяем по манифесту: есть ли в главе объекты-деревья с нормальным уровнем
(рядом с поверхностью своей клетки), и где именно стоят те, что есть.

Только чтение.
"""
from __future__ import annotations

import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "godot" / "models" / "native_campaign_models.json"

TREE_MARK = ("baum", "Baum", "tree", "Tree", "ficht", "Ficht", "tanne", "Tanne", "pine")


def world_z(level: float) -> float:
    return 7.0 + 0.5 * level


def main() -> int:
    data = json.loads(MANIFEST.read_text(encoding="utf-8"))
    placements = data["placements"]
    trees = [p for p in placements if any(mark in str(p.get("class", "")) for mark in TREE_MARK)]
    print("всего объектов: %d, из них с «деревом» в классе: %d" % (len(placements), len(trees)))
    print()
    print("деревья, отсортированные по уровню (по убыванию):")
    for p in sorted(trees, key=lambda q: -float(q["z"]))[:40]:
        level = float(p["z"])
        print("   %-26s z=%-9s world-Z=%7.2f  x=%7.2f y=%7.2f  шаблон=(%s,%s)" % (
            p["class"], p["z"], world_z(level), p["x"], p["y"],
            p.get("template_x"), p.get("template_y")))
    print()
    print("деревья в окрестностях старта (x 215..255, y 20..45):")
    for p in trees:
        if 215 <= float(p["x"]) <= 255 and 20 <= float(p["y"]) <= 45:
            level = float(p["z"])
            print("   %-26s z=%-9s world-Z=%7.2f  x=%7.2f y=%7.2f" % (
                p["class"], p["z"], world_z(level), p["x"], p["y"]))
    print()
    print("сколько всего объектов в окрестностях старта и как они распределены по уровню:")
    near = [p for p in placements if 215 <= float(p["x"]) <= 255 and 20 <= float(p["y"]) <= 45]
    levels = sorted(float(p["z"]) for p in near)
    print("   объектов: %d, уровни от %s до %s" % (len(near), levels[0], levels[-1]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
