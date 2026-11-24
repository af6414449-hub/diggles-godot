#!/usr/bin/env python3
"""Copy the hamster integration files from the MCode snapshot into the agent
working tree (copy as-is, no .uid sidecars).

The source is read-only. The destination is the agent workspace copy of the
live project.
"""
from __future__ import annotations

import hashlib
import shutil
import sys
from pathlib import Path

SNAP = Path(
    r"C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f"
    r"\workspace\Diggles-mcode\work\godot"
)
DEST = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot")

FILES = [
    # hamster modules
    "scripts/native_wild_hamster.gd",
    "scripts/native_hamster_actor.gd",
    "scripts/native_hamster_ai.gd",
    "scripts/native_hamster_animations.gd",
    "scripts/native_hamster_clips.gd",
    "scripts/native_level_ground.gd",
    # hamster dependencies
    "scripts/native_command_dispatcher.gd",
    "scripts/native_command_handlers.gd",
    # optional extras
    "scripts/native_hamster_actor_3d.gd",
    "scripts/native_hamster_demo.gd",
    "scripts/native_wild_hamster_probe.gd",
    # data
    "models/native_hamster_clips.json",
    "models/native_hamster_animations.json",
    "models/native_tasklist_commands.json",
    # self tests
    "tools/native_wild_hamster_self_test.gd",
    "tools/native_hamster_actor_self_test.gd",
    "tools/native_hamster_ai_self_test.gd",
    "tools/hamster_texture_orientation_probe.gd",
    "tools/native_hamster_probe.gd",
    # scenes
    "scenes/native_hamster_demo.tscn",
    "scenes/native_wild_hamster_probe.tscn",
]


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1 << 20), b""):
            digest.update(block)
    return digest.hexdigest()


def main() -> int:
    missing = [rel for rel in FILES if not (SNAP / rel).is_file()]
    if missing:
        print("missing in snapshot:", missing)
        return 1
    for rel in FILES:
        source = SNAP / rel
        target = DEST / rel
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, target)
        same = sha256(source) == sha256(target)
        print(f"{'OK ' if same else 'BAD'} {rel} {target.stat().st_size}B sha={sha256(target)[:16]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
