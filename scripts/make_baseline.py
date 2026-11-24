#!/usr/bin/env python3
"""Create a pristine baseline copy of the live project next to the patched tree.

The baseline is the live project as it is right now, without any hamster
integration. It is used to tell a pre-existing test failure apart from a
regression caused by the integration.
"""
from __future__ import annotations

import shutil
from pathlib import Path

LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles")
BASE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\baseline")
SKIP = {"out"}


def main() -> None:
    for rel in ["godot", "docs/reverse-engineering/minimax-battle-world-2026-11-19.json",
                "docs/reverse-engineering/minimax-battle-world-2026-11-19.py"]:
        source = LIVE / rel
        target = BASE / rel
        target.parent.mkdir(parents=True, exist_ok=True)
        if source.is_dir():
            shutil.copytree(source, target, dirs_exist_ok=True,
                            ignore=shutil.ignore_patterns(*SKIP))
        else:
            shutil.copy2(source, target)
        print(f"baseline <- {rel}")
    files = [p for p in (BASE / "godot").rglob("*") if p.is_file()]
    print(f"baseline godot/ files={len(files)}")


if __name__ == "__main__":
    main()
