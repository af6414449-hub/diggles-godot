#!/usr/bin/env python3
"""Dependency and API analysis of the hamster modules.

Compares the snapshot hamster sources against the live project: every
preloaded resource, every res:// path mentioned, and the public API of the
shared modules the hamster relies on.
"""
from __future__ import annotations

import hashlib
import re
from pathlib import Path

SNAP = Path(
    r"C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f"
    r"\workspace\Diggles-mcode\work\godot"
)
LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot")

HAMSTER_SCRIPTS = [
    "scripts/native_wild_hamster.gd",
    "scripts/native_hamster_actor.gd",
    "scripts/native_hamster_ai.gd",
    "scripts/native_hamster_animations.gd",
    "scripts/native_hamster_clips.gd",
    "scripts/native_level_ground.gd",
    "scripts/native_command_dispatcher.gd",
    "scripts/native_command_handlers.gd",
    "scripts/native_hamster_actor_3d.gd",
    "scripts/native_hamster_demo.gd",
    "scripts/native_wild_hamster_probe.gd",
]
HAMSTER_DATA = [
    "models/native_hamster_clips.json",
    "models/native_hamster_animations.json",
    "models/native_tasklist_commands.json",
]
HAMSTER_TESTS = [
    "tools/native_wild_hamster_self_test.gd",
    "tools/native_hamster_actor_self_test.gd",
    "tools/native_hamster_ai_self_test.gd",
    "tools/hamster_texture_orientation_probe.gd",
    "tools/native_hamster_probe.gd",
]
HAMSTER_SCENES = [
    "scenes/native_hamster_demo.tscn",
    "scenes/native_wild_hamster_probe.tscn",
]
SHARED = [
    "scripts/native_tasklist.gd",
    "scripts/native_animation_aliases.gd",
    "scripts/native_terrain_state.gd",
    "scripts/source_animation_action.gd",
    "scripts/native_actor_tasks.gd",
    "scripts/native_command_dispatcher.gd",
    "scripts/native_command_handlers.gd",
    "scripts/native_task_eval.gd",
]

RES_RE = re.compile(r'res://[^\s"\'()]+')
PRELOAD_RE = re.compile(r'preload\(\s*"([^"]+)"')
FUNC_RE = re.compile(r"^(?:static\s+)?func\s+([A-Za-z_][A-Za-z0-9_]*)", re.MULTILINE)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1 << 20), b""):
            digest.update(block)
    return digest.hexdigest()


def table(title: str, relatives: list[str]) -> None:
    print(f"\n=== {title}")
    for rel in relatives:
        s = SNAP / rel
        l = LIVE / rel
        if not s.is_file():
            print(f"  {rel}: NOT IN SNAPSHOT")
            continue
        s_size = s.stat().st_size
        l_size = l.stat().st_size if l.is_file() else None
        same = l.is_file() and sha256(s) == sha256(l)
        status = "IDENTICAL" if same else ("DIFFERS" if l.is_file() else "ABSENT-IN-LIVE")
        print(f"  {rel}")
        print(f"    snapshot={s_size}B sha={sha256(s)[:16]}  live={l_size} -> {status}")


def main() -> None:
    table("HAMSTER MODULES", HAMSTER_SCRIPTS)
    table("HAMSTER DATA", HAMSTER_DATA)
    table("HAMSTER TESTS", HAMSTER_TESTS)
    table("HAMSTER SCENES", HAMSTER_SCENES)
    table("SHARED / DEPENDENCY MODULES", SHARED)

    print("\n=== res:// REFERENCES OF THE HAMSTER MODULES (snapshot)")
    referenced: dict[str, list[str]] = {}
    for rel in HAMSTER_SCRIPTS + HAMSTER_TESTS:
        path = SNAP / rel
        if not path.is_file():
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        for ref in set(RES_RE.findall(text)):
            referenced.setdefault(ref, []).append(rel)
    for ref in sorted(referenced):
        target = LIVE / ref[len("res://"):]
        exists = target.exists()
        print(f"  {'OK ' if exists else 'MISSING'} {ref}   <- {', '.join(sorted(referenced[ref]))}")

    print("\n=== API OF SHARED MODULES (live) vs SNAPSHOT")
    for rel in ["scripts/native_tasklist.gd", "scripts/native_animation_aliases.gd",
                "scripts/native_command_handlers.gd", "scripts/native_command_dispatcher.gd"]:
        s = SNAP / rel
        l = LIVE / rel
        s_funcs = FUNC_RE.findall(s.read_text(encoding="utf-8")) if s.is_file() else []
        l_funcs = FUNC_RE.findall(l.read_text(encoding="utf-8")) if l.is_file() else []
        only_snapshot = [f for f in s_funcs if f not in l_funcs]
        only_live = [f for f in l_funcs if f not in s_funcs]
        print(f"\n  {rel}")
        print(f"    snapshot funcs ({len(s_funcs)}): {s_funcs}")
        print(f"    live funcs     ({len(l_funcs)}): {l_funcs}")
        print(f"    missing in live: {only_snapshot}")
        print(f"    extra in live:   {only_live}")

    print("\n=== DYNAMIC _queue.call(...) IN HAMSTER ACTOR")
    actor = (SNAP / "scripts/native_hamster_actor.gd").read_text(encoding="utf-8")
    calls = sorted(set(re.findall(r'_queue\.call\(\s*"([^"]+)"', actor)))
    live_tasklist = LIVE / "scripts/native_tasklist.gd"
    live_text = live_tasklist.read_text(encoding="utf-8")
    live_funcs = set(FUNC_RE.findall(live_text))
    print(f"  calls: {calls}")
    for call in calls:
        print(f"    {call}: {'present in live tasklist' if call in live_funcs else 'MISSING in live tasklist'}")


if __name__ == "__main__":
    main()
