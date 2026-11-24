#!/usr/bin/env python3
"""Copy the test fixtures that live outside the Godot project into the agent
trees.

Several self-tests read their fixtures from ../docs/reverse-engineering next to
the project root. A copy of the project alone does not contain them, and the
affected suites then abort before quit() and hang.
"""
from __future__ import annotations

import shutil
from pathlib import Path

LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles")
ROOTS = [
    Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"),
    Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\baseline"),
]
FIXTURES = [
    "docs/reverse-engineering/minimax-battle-world-2026-11-19.json",
    "docs/reverse-engineering/minimax-battle-world-2026-11-19.py",
    "docs/reverse-engineering/native-worker-group-2026-11-17.json",
    "docs/reverse-engineering/native-walk-flags-2026-11-17.json",
    "docs/reverse-engineering/native-terrain-strike-2026-11-17.json",
    "docs/reverse-engineering/native-surface-walk-2026-11-17.json",
    "docs/reverse-engineering/native-fix-dig-2026-11-17.json",
    "docs/reverse-engineering/native-dig-next-2026-11-17.json",
]


def main() -> None:
    for root in ROOTS:
        for rel in FIXTURES:
            source = LIVE / rel
            target = root / rel
            if not source.is_file():
                print(f"missing in live: {rel}")
                continue
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(source, target)
            print(f"{root.name}: {rel} ({target.stat().st_size} B)")


if __name__ == "__main__":
    main()
