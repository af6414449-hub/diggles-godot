#!/usr/bin/env python3
"""Diff the shared modules that exist in both the snapshot and the live project."""
from __future__ import annotations

import difflib
from pathlib import Path

SNAP = Path(
    r"C:\Users\frant\.minimax\sessions\mvs_e213cb8b6788404489ad3b0b5c39827f"
    r"\workspace\Diggles-mcode\work\godot"
)
LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot")

TARGETS = [
    "scripts/source_animation_action.gd",
    "scripts/native_terrain_state.gd",
    "scripts/native_tasklist.gd",
]


def main() -> None:
    for rel in TARGETS:
        s = SNAP / rel
        l = LIVE / rel
        print(f"\n=== {rel}")
        if not s.is_file() or not l.is_file():
            print("  missing on one side")
            continue
        a = s.read_text(encoding="utf-8", errors="replace").splitlines()
        b = l.read_text(encoding="utf-8", errors="replace").splitlines()
        diff = list(difflib.unified_diff(a, b, "snapshot", "live", lineterm="", n=2))
        if not diff:
            print("  identical")
            continue
        for line in diff:
            print("  " + line)


if __name__ == "__main__":
    main()
