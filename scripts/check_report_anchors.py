#!/usr/bin/env python3
"""Check that the integration anchors of the report still exist verbatim in the
live project.

The live project is edited in parallel, so the line numbers of the report may
have moved; the text anchors must still match exactly.
"""
from __future__ import annotations

import sys
from pathlib import Path

LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot")
MP = LIVE / "scripts" / "multiplayer_test.gd"
TL = LIVE / "scripts" / "native_tasklist.gd"

ANCHORS = [
    ("A1", MP, 'const WORLD_MODEL_LIGHT: Script = preload("res://scripts/native_world_model_light.gd")'),
    ("A2", MP, '\t_build_geometry(data)'),
    ("A3a", MP, '\t\tposition_data = [float(position_data[0])+template_shift.x,'),
    ("A3b", MP, '\t\tvar rotation_data: Array = placement["rotation"]'),
    ("A3c", MP, '\t\tvar instance_root: Node3D = Node3D.new()'),
    ("A4", MP, '\t\tscene_root.add_child(instance_root)'),
    ("A5", MP, 'func _navigation_obstacle_radius(placement_class: String) -> float:'),
]

EXPECTED_ABSENT = [
    ("A1", MP, "const WILD_HAMSTER: Script"),
    ("A2", MP, "wild_hamster_ground = LEVEL_GROUND.new()"),
    ("A3", MP, 'if placement_class == "Hamster":'),
    ("A4", MP, 'if placement_class == "Grillpilz":'),
    ("A5", MP, "## Spawn one wild hamster of the original level."),
]


def main() -> int:
    mp_lines = MP.read_text(encoding="utf-8").split("\n")
    ok = True
    print("якорь  строка  совпадений  текст")
    for name, path, text in ANCHORS:
        hits = [i + 1 for i, line in enumerate(mp_lines) if line == text]
        state = "OK" if len(hits) == 1 else "ПРОБЛЕМА"
        ok = ok and len(hits) == 1
        print(f"{name:<6} {str(hits):<7} {len(hits):<11} {text[:58]}")
    print("\nпроверка, что интеграции в живом проекте ещё нет:")
    for name, path, text in EXPECTED_ABSENT:
        present = text in path.read_text(encoding="utf-8")
        state = "OK (нет)" if not present else "ПРОБЛЕМА (уже применено)"
        ok = ok and not present
        print(f"{name:<6} {state}")
    tl = TL.read_text(encoding="utf-8")
    has_cnt = "func cnt()" in tl
    print(f"\nnative_tasklist.gd: {len(tl.splitlines())} строк, func cnt(): {'есть' if has_cnt else 'нет'}")
    ok = ok and not has_cnt
    print(f"\nmultiplayer_test.gd: {len(mp_lines)} строк")
    print("\nИТОГ: " + ("отчёт применим к текущему живому проекту" if ok else "нужна перепроверка перед применением"))
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
