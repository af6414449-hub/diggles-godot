#!/usr/bin/env python3
"""Copy the live Diggles Godot project into the agent working tree.

Read-only on the source; the destination is the agent workspace. The ``out``
directory of the live project holds build artifacts and is skipped.
"""
from __future__ import annotations

import filecmp
import shutil
import sys
from pathlib import Path

SOURCE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles\godot")
DEST = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\godot")
SKIP_DIRS = {"out"}


def main() -> int:
    if not SOURCE.is_dir():
        print(f"source missing: {SOURCE}")
        return 1
    copied = 0
    skipped = 0
    for path in sorted(SOURCE.rglob("*")):
        rel = path.relative_to(SOURCE)
        if any(part in SKIP_DIRS for part in rel.parts):
            continue
        target = DEST / rel
        if path.is_dir():
            target.mkdir(parents=True, exist_ok=True)
            continue
        target.parent.mkdir(parents=True, exist_ok=True)
        if target.exists() and filecmp.cmp(path, target, shallow=False):
            skipped += 1
            continue
        shutil.copy2(path, target)
        copied += 1
    print(f"copied={copied} identical={skipped}")
    total = sum(1 for p in DEST.rglob("*") if p.is_file())
    size = sum(p.stat().st_size for p in DEST.rglob("*") if p.is_file())
    print(f"destination files={total} MB={size / 1024 / 1024:.1f}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
