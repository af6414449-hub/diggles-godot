#!/usr/bin/env python3
"""Что остаётся в главе при порогах отсечения надземного декора.

Пороги:
  z < 0            — уровень отрицательный (world-Z < 7.0, правило движка: движок
                      объекты по z не отсекает, они висят под скальным дном острова)
  world-Z < 2.0    — СОГЛАСОВАННОЕ правило порта (OVERWORLD_GROUND_WORLD_Z = 2.0):
                      земля надземной сцены; объекты ниже неё уходят под остров

Согласование 21.11: у края острова (северная кромка главы, world-Z 2.5…6.86) стоят
деревья, дерн и грибы — они видны и в оригинале, и в референсе владельца, поэтому
их оставляем; режем 24 объекта, лежащих под островом.
"""
from __future__ import annotations

import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "godot" / "models" / "native_campaign_models.json"

OVERWORLD_GROUND_WORLD_Z = 2.0


def world_z(level: float) -> float:
    return 7.0 + 0.5 * level


def main() -> int:
    data = json.loads(MANIFEST.read_text(encoding="utf-8"))
    placements = data["placements"]
    by_level = [p for p in placements if float(p["z"]) < 0]
    by_world = [p for p in placements if world_z(float(p["z"])) < OVERWORLD_GROUND_WORLD_Z]
    kept = [p for p in placements
            if world_z(float(p["z"])) >= OVERWORLD_GROUND_WORLD_Z and float(p["z"]) < 0]

    print("размещений всего: %d" % len(placements))
    print("отсекается по z < 0 (world-Z < 7.0, правило движка): %d" % len(by_level))
    print("отсекается по world-Z < %.1f (правило порта): %d"
          % (OVERWORLD_GROUND_WORLD_Z, len(by_world)))
    print()
    print("ОСТАЮТСЯ (слой надземной сцены у края острова): %d" % len(kept))
    for p in sorted(kept, key=lambda q: float(q["z"])):
        print("   %-24s z=%-10s world-Z=%7.2f  x=%7.2f y=%7.2f  шаблон=(%s,%s)" % (
            p["class"], p["z"], world_z(float(p["z"])), p["x"], p["y"],
            p.get("template_x"), p.get("template_y")))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
