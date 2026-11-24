#!/usr/bin/env python3
"""Assemble the final report from its parts and place it in the live project.

The live project is only written to for the single deliverable file that the
task asks for: docs/reverse-engineering/agent-result-hamster-integration-2026-11-19.md
"""
from __future__ import annotations

import shutil
from pathlib import Path

REPORT_DIR = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\report")
LIVE = Path(r"C:\Users\frant\OneDrive\Документы\ChatGPT\Diggles")
TARGET = LIVE / "docs" / "reverse-engineering" / "agent-result-hamster-integration-2026-11-19.md"

PARTS = [
    "agent-result-hamster-integration-2026-11-19.md",
    "part2.md",
    "part5.md",
    "part3.md",
]


def main() -> None:
    chunks = []
    for name in PARTS:
        text = (REPORT_DIR / name).read_text(encoding="utf-8")
        chunks.append(text.rstrip("\n"))
    body = "\n\n".join(chunks)
    body += (
        "\n\nINTEGRATION_HANDOFF: docs/reverse-engineering/"
        "agent-result-hamster-integration-2026-11-19.md\n"
    )
    TARGET.parent.mkdir(parents=True, exist_ok=True)
    TARGET.write_text(body, encoding="utf-8", newline="\n")
    shutil.copy2(TARGET, REPORT_DIR / "final.md")
    print(f"written: {TARGET}")
    print(f"bytes: {TARGET.stat().st_size}")
    print(f"lines: {len(TARGET.read_text(encoding='utf-8').splitlines())}")


if __name__ == "__main__":
    main()
