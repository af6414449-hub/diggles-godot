#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Append a z-section file (zNN.md) to report.md, updating title + doc table.

Usage: python integrate_section.py z28.md "проход ..." [--title "З1–З29"]
"""
from __future__ import annotations

import io
import re
import sys
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")
REPORT = ZONE / "report.md"


def main() -> int:
    src = ZONE / sys.argv[1]
    note = sys.argv[2]
    txt = REPORT.read_text(encoding="utf-8")

    # title refresh
    m = re.search(r"# Отчёт по декомпиляции `Diggles\.exe` — пещеры главы Diggles: З1–З(\d+)", txt)
    if not m:
        raise SystemExit("FAIL title pattern")
    new_max = max(int(m.group(1)), int(re.search(r"З(\d+)\b", src.read_text(encoding="utf-8").splitlines()[0]).group(1)))
    old_title = m.group(0)
    new_title = old_title.rsplit("З", 1)[0] + f"З{new_max}"
    if txt.count(old_title) != 1:
        raise SystemExit("FAIL title count")
    txt = txt.replace(old_title, new_title, 1)

    # doc table row
    rel = f"work/campaign/caves-decomp/{sys.argv[1]}"
    if rel not in txt:
        anchor = [l for l in txt.splitlines(keepends=True)
                  if l.startswith("| `work/campaign/caves-decomp/z") and l.endswith("|\n")]
        if not anchor:
            raise SystemExit("FAIL doc table")
        last = anchor[-1]
        title_txt = src.read_text(encoding="utf-8").splitlines()[0][2:].strip()
        row = f"| `{rel}` | {title_txt} |\n"
        txt = txt.replace(last, last + row, 1)

    body = src.read_text(encoding="utf-8")
    lines = body.splitlines()
    title = lines[0][2:].strip()
    rest = "\n".join(lines[1:]).strip("\n")
    if rest.startswith("\n---\n"):
        rest = rest[len("\n---\n"):]
    section = f"## {title}\n\n*(2026-11-22; {note})*\n\n{rest}\n"
    txt = txt.rstrip("\n") + "\n\n---\n\n" + section

    with io.open(REPORT, "w", encoding="utf-8", newline="\n") as f:
        f.write(txt)
    print(f"report.md: {len(txt.encode('utf-8'))} bytes, {len(txt.splitlines())} lines, "
          f"title -> {new_title}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
