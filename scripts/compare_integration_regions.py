#!/usr/bin/env python3
"""Compare the integration regions of the patched trial with the working tree.

The live project kept being edited while the integration was prepared, so the
whole file cannot be identical. What has to be identical is the integration
itself: the five anchors and the host block.
"""
from __future__ import annotations

import hashlib
import sys
from pathlib import Path

ROOT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles")
TRIAL = ROOT / "trial" / "scripts" / "multiplayer_test.gd"
WORK = ROOT / "godot" / "scripts" / "multiplayer_test.gd"
LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot\scripts\multiplayer_test.gd")

REGIONS = [
    ("A1 constants", 'const WILD_HAMSTER: Script = preload("res://scripts/native_wild_hamster.gd")',
     "var wild_hamster_grids: Dictionary = {}"),
    ("A2 load_terrain", "\twild_hamster_ground = LEVEL_GROUND.new() as RefCounted",
     '\t(wild_hamster_ground as RefCounted).call("load_terrain", data)'),
    ("A3 hamster spawn", '\t\tif placement_class == "Hamster":',
     "\t\t\t_spawn_wild_hamster(placement, position_data, rotation_data)"),
    ("A4 food", '\t\tif placement_class == "Grillpilz":',
     '\t\t\t\t"position": instance_root.position, "node": instance_root})'),
    ("A5 host block", "## Spawn one wild hamster of the original level.",
     "\t\twild_hamster_food.erase(entry)"),
]


def region(text: str, start: str, end: str) -> str:
    i = text.find(start)
    if i < 0:
        return f"<<MISSING START {start!r}>>"
    j = text.find(end, i)
    if j < 0:
        return f"<<MISSING END {end!r}>>"
    return text[i : j + len(end)]


def digest(value: str) -> str:
    return hashlib.sha256(value.encode("utf-8")).hexdigest()[:16]


def main() -> int:
    trial = TRIAL.read_text(encoding="utf-8")
    work = WORK.read_text(encoding="utf-8")
    live = LIVE.read_text(encoding="utf-8")
    ok = True
    print(f"{'region':<18} {'trial':<18} {'work':<18} verdict")
    for name, start, end in REGIONS:
        a = region(trial, start, end)
        b = region(work, start, end)
        same = a == b
        ok = ok and same
        print(f"{name:<18} {digest(a):<18} {digest(b):<18} {'MATCH' if same else 'DIFFER'}")
        if not same:
            print(f"   trial: {a[:200]!r}")
            print(f"   work : {b[:200]!r}")
    print()
    print(f"live multiplayer_test.gd: {len(live.splitlines())} lines")
    print(f"trial (live + patch)    : {len(trial.splitlines())} lines")
    print(f"work (integration tree) : {len(work.splitlines())} lines")
    print()
    if ok:
        print("INTEGRATION REGIONS MATCH: the patch reproduces the verified integration exactly")
    else:
        print("INTEGRATION REGIONS DIFFER")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
