#!/usr/bin/env python3
"""Sync the live-drift files into the patched tree and re-run the suites that
the drift affected.

The live project kept being edited while the hamster integration was being
prepared. The three files below changed in the live project between the copy
that the integration is based on and the later baseline copy. They are not part
of the integration, so they are taken from the live project as it is now.
"""
from __future__ import annotations

import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles")
LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot")
PATCHED = ROOT / "godot"
OUT = ROOT / "out" / "resync"

DRIFT = [
    "project.godot",
    "scripts/native_battle_world.gd",
    "tools/native_battle_world_self_test.gd",
]

# The suites that the drift could touch plus the hamster suites and the scene
# loading suites that run scripts/multiplayer_test.gd.
SUITES = [
    "native_battle_world_self_test",
    "native_hamster_ai_self_test",
    "native_hamster_actor_self_test",
    "native_wild_hamster_self_test",
    "native_scene_profile_self_test",
    "native_dig_queue_self_test",
    "excavated_walk_self_test",
    "native_dwarf_dig_self_test",
    "native_actor_tasks_self_test",
    "dwarf_task_runtime_self_test",
]

GODOT = Path(r"C:\Users\frant\OneDrive\Рабочий стол\godot\Godot_v4.7.2-stable_win64_console.exe")


def main() -> int:
    for rel in DRIFT:
        source = LIVE / rel
        target = PATCHED / rel
        shutil.copy2(source, target)
        print(f"synced {rel} ({target.stat().st_size} B)")
    OUT.mkdir(parents=True, exist_ok=True)
    for suite in SUITES:
        log = OUT / f"suite_{suite}.log"
        started = subprocess.run(
            [str(GODOT), "--headless", "--path", str(PATCHED), "--script", f"res://tools/{suite}.gd"],
            capture_output=True,
            timeout=600,
        )
        text = started.stdout.decode("utf-8", errors="replace")
        err = started.stderr.decode("utf-8", errors="replace")
        log.write_text(text, encoding="utf-8", newline="\n")
        log.with_suffix(".log.err").write_text(err, encoding="utf-8", newline="\n")
        summary = [
            line
            for line in text.splitlines()
            if "SELF_TEST" in line or "assertions=" in line or "failures=" in line
        ]
        fails = [line for line in err.splitlines() if line.startswith("ERROR:")]
        print(f"\n--- {suite} exit={started.returncode}")
        for line in summary[-2:]:
            print("   ", line)
        for line in fails[:2]:
            print("   ", line)
    return 0


if __name__ == "__main__":
    sys.exit(main())
