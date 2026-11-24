#!/usr/bin/env python3
"""Diff the agent working tree against the baseline tree, file by file.

Both trees started from the same live project, but the live project kept being
edited while the work was going on. The baseline was taken later, so any
difference that is not part of the hamster integration comes from the live
project itself.
"""
from __future__ import annotations

import hashlib
from pathlib import Path

PATCHED = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot")
BASE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\baseline\godot")
LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot")

# Files that the hamster integration adds or patches.
INTEGRATION = {
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
    "models/native_hamster_clips.json",
    "models/native_hamster_animations.json",
    "models/native_tasklist_commands.json",
    "tools/native_wild_hamster_self_test.gd",
    "tools/native_hamster_actor_self_test.gd",
    "tools/native_hamster_ai_self_test.gd",
    "tools/hamster_texture_orientation_probe.gd",
    "tools/native_hamster_probe.gd",
    "scenes/native_hamster_demo.tscn",
    "scenes/native_wild_hamster_probe.tscn",
    "scripts/native_tasklist.gd",
    "scripts/multiplayer_test.gd",
}


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1 << 20), b""):
            digest.update(block)
    return digest.hexdigest()


def scan(root: Path) -> dict[str, str]:
    result = {}
    for path in root.rglob("*"):
        if not path.is_file():
            continue
        rel = path.relative_to(root).as_posix()
        if rel.startswith(".godot/") or rel.startswith("out/"):
            continue
        result[rel] = sha256(path)
    return result


def main() -> None:
    patched = scan(PATCHED)
    base = scan(BASE)
    live = scan(LIVE)

    only_patched = sorted(set(patched) - set(base))
    only_base = sorted(set(base) - set(patched))
    differing = sorted(rel for rel in set(patched) & set(base) if patched[rel] != base[rel])

    print("=== files only in the patched tree (integration additions)")
    for rel in only_patched:
        tag = "INTEGRATION" if rel in INTEGRATION else "OTHER"
        print(f"  [{tag}] {rel}")
    print("\n=== files only in the baseline tree")
    for rel in only_base:
        print(f"  {rel}")
    print("\n=== files that differ between the trees")
    for rel in differing:
        same_as_live = live.get(rel) == patched.get(rel)
        same_as_live_base = live.get(rel) == base.get(rel)
        tag = "INTEGRATION" if rel in INTEGRATION else "LIVE-DRIFT"
        print(f"  [{tag}] {rel}  patched==live:{same_as_live}  baseline==live:{same_as_live_base}")


if __name__ == "__main__":
    main()
