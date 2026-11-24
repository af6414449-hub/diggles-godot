#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Merge z25.md / z26.md into report.md and refresh the header + doc table.

Checks every replacement count so a silent mismatch cannot corrupt the report.
"""
from __future__ import annotations

import io
import sys
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")
REPORT = ZONE / "report.md"
Z25 = ZONE / "z25.md"
Z26 = ZONE / "z26.md"


def read(p: Path) -> str:
    return p.read_text(encoding="utf-8")


def write(p: Path, s: str) -> None:
    with io.open(p, "w", encoding="utf-8", newline="\n") as f:
        f.write(s)


def sub_once(text: str, old: str, new: str, what: str) -> str:
    n = text.count(old)
    if n != 1:
        raise SystemExit(f"FAIL {what}: found {n} occurrences of {old[:60]!r}")
    return text.replace(old, new, 1)


def main() -> int:
    rep = read(REPORT)

    # 1. title
    rep = sub_once(
        rep,
        "# Отчёт по декомпиляции `Diggles.exe` — пещеры главы Diggles: З1–З24",
        "# Отчёт по декомпиляции `Diggles.exe` — пещеры главы Diggles: З1–З26",
        "title",
    )

    # 2. header source line
    rep = sub_once(
        rep,
        "Источник: декомпиляция `Diggles.exe` (Ghidra, `C:\\diggles-ghidra\\out\\decomp`, "
        "11 373 функции, по файлу на функцию), дизассемблер `work/campaign/ref/disasm.py`, "
        "оригинальные данные игры, экспорт порта `godot/models/native_campaign_chapter.json`, "
        "собственные измерения в `work/campaign/caves-decomp/`.",
        "Источник: декомпиляция `Diggles.exe` (Ghidra, `C:\\diggles-ghidra\\out\\decomp`, "
        "11 373 записи = 5 268 реальных функций + 6 105 псевдофункций SEH) **и** "
        "`DigglesPort.dll` (`C:\\diggles-ghidra\\out_port\\decomp`, 1 114 записей), "
        "дизассемблер `work/campaign/ref/disasm.py`, PE-зонды `work/campaign/caves-decomp/"
        "pe_toolchain_probe.py` и `pe_imports_exports.py`, оригинальные данные игры, "
        "экспорт порта `godot/models/native_campaign_chapter.json`, собственные измерения "
        "в `work/campaign/caves-decomp/`.",
        "header source",
    )

    # 3. doc table: drop duplicated z24 row, add z25/z26 + artefacts
    dup = ("| `work/campaign/caves-decomp/z24.md` | З24 — проход 2026-11-22: rx/ry, зоны пещер, "
           "LG, `.pmp`, текстуры рельефа, камера |\n"
           "| `work/campaign/caves-decomp/z24.md` | З24 — проход 2026-11-22: rx/ry, зоны пещер, "
           "LG, `.pmp`, текстуры рельефа, камера |\n")
    if rep.count(dup) != 1:
        # tolerate the case where the two rows are not adjacent
        rows = [l for l in rep.splitlines(keepends=True)
                if l.startswith("| `work/campaign/caves-decomp/z24.md` |")]
        if len(rows) == 2:
            rep = rep.replace(rows[0], "", 1)
        else:
            raise SystemExit(f"FAIL doc table: z24 rows = {len(rows)}")
    else:
        rep = rep.replace(dup, rows_anchor := "| `work/campaign/caves-decomp/z24.md` | З24 — "
                           "проход 2026-11-22: rx/ry, зоны пещер, LG, `.pmp`, текстуры рельефа, "
                           "камера |\n", 1)

    anchor = "| `work/campaign/caves-decomp/exe-inventory.md` | индекс декомпиляции exe "\
             "(11 373 функции, 549 команд Tcl, граф вызовов) |\n"
    new_rows = ("| `work/campaign/caves-decomp/z25.md` | З25 — тулчейн, эпоха и модульная "
                "архитектура: exe + `DigglesPort.dll` |\n"
                "| `work/campaign/caves-decomp/z26.md` | З26 — карта покрытия: сколько кода "
                "реально разобрано и куда идти дальше |\n"
                "| `work/campaign/caves-decomp/coverage.md` | З26 — сводная таблица покрытия "
                "по подсистемам |\n"
                "| `work/campaign/caves-decomp/next_targets.md` | З26 — ранжированные кластеры "
                "неразобранных функций (следующие цели) |\n")
    rep = sub_once(rep, anchor, anchor + new_rows, "doc table anchor")

    # 4. append З25 / З26
    z25 = read(Z25)
    z26 = read(Z26)

    def to_section(txt: str, note: str) -> str:
        lines = txt.splitlines()
        # drop the leading H1 title and the following blank line
        assert lines[0].startswith("# "), lines[0][:40]
        title = lines[0][2:].strip()
        body = "\n".join(lines[1:]).strip("\n")
        body = body.replace("\n---\n", "\n", 1) if body.startswith("\n---\n") else body
        return f"## {title}\n\n*(2026-11-22; {note})*\n\n{body}\n"

    rep = rep.rstrip("\n") + "\n\n---\n\n"
    rep += to_section(z25, "проход по тулчейну и архитектуре модулей. "
                           "Полный текст — `work/campaign/caves-decomp/z25.md`")
    rep += "\n---\n\n"
    rep += to_section(z26, "проход по измерению покрытия кода. "
                           "Полный текст — `work/campaign/caves-decomp/z26.md`")
    rep = rep.rstrip("\n") + "\n"

    write(REPORT, rep)
    print(f"report.md: {len(rep.encode('utf-8'))} bytes, {len(rep.splitlines())} lines")
    return 0


if __name__ == "__main__":
    sys.exit(main())
