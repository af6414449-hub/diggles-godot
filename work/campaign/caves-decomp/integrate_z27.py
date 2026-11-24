#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Append Z27 (render shaders / technique registry) to report.md.

Same guarded style as integrate_z25_z26.py: every replacement is counted.
"""
from __future__ import annotations

import io
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")
REPORT = ZONE / "report.md"
Z27 = ZONE / "z27.md"


def main() -> int:
    rep = REPORT.read_text(encoding="utf-8")

    old_title = "# Отчёт по декомпиляции `Diggles.exe` — пещеры главы Diggles: З1–З26"
    new_title = "# Отчёт по декомпиляции `Diggles.exe` — пещеры главы Diggles: З1–З27"
    if rep.count(old_title) != 1:
        raise SystemExit("FAIL title")
    rep = rep.replace(old_title, new_title, 1)

    anchor = ("| `work/campaign/caves-decomp/z26.md` | З26 — карта покрытия: сколько кода "
              "реально разобрано и куда идти дальше |\n")
    if rep.count(anchor) != 1:
        raise SystemExit("FAIL doc table anchor")
    rep = rep.replace(anchor, anchor +
                      "| `work/campaign/caves-decomp/z27.md` | З27 — исходники рендера оригинала: "
                      "HLSL-шейдеры из `data/Shaders/` и реестр из 37 техник |\n", 1)

    z27 = Z27.read_text(encoding="utf-8")
    lines = z27.splitlines()
    title = lines[0][2:].strip()
    body = "\n".join(lines[1:]).strip("\n")
    if body.startswith("\n---\n"):
        body = body[len("\n---\n"):]
    section = (f"## {title}\n\n"
               f"*(2026-11-22; проход по шейдерам и реестру техник. "
               f"Полный текст — `work/campaign/caves-decomp/z27.md`)*\n\n{body}\n")
    rep = rep.rstrip("\n") + "\n\n---\n\n" + section

    with io.open(REPORT, "w", encoding="utf-8", newline="\n") as f:
        f.write(rep)
    print(f"report.md: {len(rep.encode('utf-8'))} bytes, {len(rep.splitlines())} lines")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
