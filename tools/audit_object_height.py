# -*- coding: utf-8 -*-
"""Проверка высоты размещения объектов главы кампании.

z в манифесте — это УРОВЕНЬ шкалы высот движка, а не мировая высота.
Движок переводит его в world-Z сам: world-Z = 7.0 + 0.5 * z
(CDisplay__DrawObjects_00473cc0.c:429,435; FUN_00496300:46-50;
FUN_0052d170:613; для высот клеток — тот же множитель, FUN_004c8220:33,44).
Тот же порядок записан в самом манифесте, поле coordinate_transform:
«Tcl logical position (x,y,z) -> Godot logical (x,-y,z), then render Z=7+z/2».

Поверхность главы = 14.5 (уровень 15), пол выработки = 12.5 (уровень 11),
низ породы = 7.0 (уровень 0). Объект с world-Z < 7.0 стоит ниже породы.
Отрицательный уровень невозможен (высота клетки — байт 0..15), поэтому
объекты с z < 0 — это надземный декор в чужой системе отсчёта: в оригинале
они лежат под картой и не видны.
"""
from __future__ import annotations

import collections
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DEFAULT = ROOT / "godot" / "models" / "native_campaign_models.json"

SURFACE = 14.5
ROCK_BOTTOM = 7.0
WORLD_OFFSET = 7.0
WORLD_SCALE = 0.5


def world_z(level: float) -> float:
    """Мировая высота объекта по уровню из шаблона (формула движка)."""
    return WORLD_OFFSET + WORLD_SCALE * level


def main() -> int:
    path = Path(sys.argv[1]) if len(sys.argv) > 1 else DEFAULT
    data = json.loads(path.read_text(encoding="utf-8"))
    placements = data.get("placements", [])
    heights = [float(p.get("z", 0.0)) for p in placements]
    ordered = sorted(heights)
    quantiles = [ordered[min(len(ordered) - 1, int(len(ordered) * q))]
                 for q in (0.0, 0.01, 0.05, 0.5, 0.95, 1.0)]

    print("=== высота объектов главы ===")
    print(f"объектов: {len(placements)}")
    print(f"уровень z: {min(heights)} .. {max(heights)}")
    print("квантили z (0%, 1%, 5%, 50%, 95%, 100%): " + ", ".join(f"{q:g}" for q in quantiles))
    print(f"шкала движка: world-Z = 7.0 + 0.5 * z; поверхность {SURFACE}, низ породы {ROCK_BOTTOM}")
    worlds = [world_z(h) for h in heights]
    print(f"world-Z по формуле движка: {min(worlds):.3f} .. {max(worlds):.3f}")

    below = [p for p in placements if world_z(float(p.get("z", 0.0))) < ROCK_BOTTOM]
    negative = [p for p in placements if float(p.get("z", 0.0)) < 0]
    print()
    print(f"=== объекты НИЖЕ низа породы (world-Z < {ROCK_BOTTOM}) ===")
    print(f"всего: {len(below)}")
    print(f"из них с отрицательным уровнем (надземный декор): {len(negative)}")
    counter = collections.Counter(str(p["class"]) for p in below)
    for name, count in counter.most_common():
        sample = min(float(p.get("z", 0.0)) for p in below if str(p["class"]) == name)
        print(f"  {count:4d}  {name:28s} минимальный z = {sample}")
    for p in below:
        level = float(p.get("z", 0.0))
        print(f"    {p['class']:28s} x={p['x']:8.2f} y={p['y']:8.2f} "
              f"z={p.get('z')} world-Z={world_z(level):.2f}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
