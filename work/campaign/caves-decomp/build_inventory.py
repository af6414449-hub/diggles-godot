#!/usr/bin/env python3
"""Инвентарь декомпиляции Diggles.exe — «полная расшифровка» в виде индекса.

Собирает из готовых артефактов Ghidra-разбора:
  * C:\\diggles-ghidra\\out\\decomp\\*.c      — по файлу на функцию (имя = <символ>_<va>)
  * work/campaign/ref/ghidra_funcs.tsv       — адрес -> класс (для FUN_* без имени)
  * work/campaign/ref/engine_symbols.tsv     — именованные символы движка (класс/метод/строка)
  * work/campaign/ref/method_map.tsv         — адрес функции -> реф. на строку RTTI/имени
  * work/campaign/ref/tcl_command_table.tsv  — команды Tcl -> обработчик
  * work/campaign/ref/struct_layouts.tsv     — разобранные поля структур
  * work/campaign/ref/callgraph_subsystems.tsv — граф вызовов по именованным функциям

Результат: work/campaign/caves-decomp/exe-inventory.md
Только чтение вне своей зоны.
"""
from __future__ import annotations

import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
DECOMP = Path(r"C:\diggles-ghidra\out\decomp")
REF = ROOT / "work" / "campaign" / "ref"
OUT = ROOT / "work" / "campaign" / "caves-decomp" / "exe-inventory.md"

VA_RE = re.compile(r"_([0-9a-fA-F]{6,8})\.c$")


def read_tsv(path: Path) -> list[dict]:
    if not path.exists():
        return []
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    if not lines:
        return []
    head = lines[0].split("\t")
    out = []
    for line in lines[1:]:
        parts = line.split("\t")
        parts += [""] * (len(head) - len(parts))
        out.append(dict(zip(head, parts)))
    return out


def collect_functions() -> dict:
    funcs = {}
    if not DECOMP.exists():
        return funcs
    for p in DECOMP.glob("*.c"):
        m = VA_RE.search(p.name)
        if not m:
            continue
        va = int(m.group(1), 16)
        stem = p.name[: m.start()]
        if stem.startswith("FUN_"):
            kind, cls, method = "fun", "", ""
        else:
            parts = stem.split("__")
            cls = parts[0]
            method = parts[1] if len(parts) > 1 else ""
            kind = "named"
        funcs[va] = {"va": va, "kind": kind, "cls": cls, "method": method,
                     "file": p.name}
    return funcs


def main() -> int:
    funcs = collect_functions()
    gfuncs = {int(r["address"], 16): r["class"] for r in read_tsv(REF / "ghidra_funcs.tsv")
              if r.get("address", "").startswith("0x")}
    for va, f in funcs.items():
        if not f["cls"] and va in gfuncs:
            f["cls"] = gfuncs[va]

    by_class = defaultdict(list)
    for va, f in funcs.items():
        by_class[f["cls"] or "(без класса)"].append(f)

    symbols = read_tsv(REF / "engine_symbols.tsv")
    method_map = read_tsv(REF / "method_map.tsv")
    tcl = read_tsv(REF / "tcl_command_table.tsv")
    structs = read_tsv(REF / "struct_layouts.tsv")
    gstructs = read_tsv(REF / "ghidra_structs.tsv")
    calls = read_tsv(REF / "callgraph_subsystems.tsv")

    L = []
    A = L.append
    A("# Инвентарь декомпиляции `Diggles.exe` — индекс «полной расшифровки»")
    A("")
    A("Дата: 2026-11-21. Источник: Ghidra-прогон `C:\\diggles-ghidra\\out\\decomp` "
      "(по файлу на функцию) + сводные таблицы `work/campaign/ref/*.tsv`.")
    A("")
    A(f"* функций в декомпиляции: **{len(funcs)}**")
    named = sum(1 for f in funcs.values() if f["kind"] == "named")
    A(f"* из них с восстановленным именем: **{named}** "
      f"({named / max(1, len(funcs)):.1%})")
    A(f"* именованных символов движка (строки RTTI/имён): **{len(symbols)}**")
    A(f"* привязок «функция → строка-имя»: **{len(method_map)}**")
    A(f"* команд Tcl с разобранным обработчиком: **{len(tcl)}**")
    A(f"* полей структур с типом: **{len(gstructs)}**")
    A(f"* записей разбора раскладки: **{len(structs)}**")
    A(f"* именованных вызывающих в графе вызовов: **{len(calls)}**")
    A("")
    A("## Как читать")
    A("")
    A("Имя файла в `out/decomp` = `<символ>_<VA в hex>.c`. Имена трёх видов:")
    A("")
    A("| вид | пример | что означает |")
    A("|---|---|---|")
    A("| `CLASS__Method_VA.c` | `CMap__Clear_00593ec0.c` | класс C++, метод восстановлен по RTTI/строкам |")
    A("| `FUN_VA_VA.c` | `FUN_004ca830_004ca830.c` | функция без имени; класс восстанавливается по `ghidra_funcs.tsv` |")
    A("| `CTclGlobalMethods__Map_006325f0.c` | — | обработчик команды Tcl `map` |")
    A("")

    A("## Подсистемы по классам")
    A("")
    A("| класс | функций | диапазон VA | именованных методов |")
    A("|---|---|---|---|")
    for cls, fs in sorted(by_class.items(), key=lambda kv: -len(kv[1])):
        vas = sorted(f["va"] for f in fs)
        nm = sum(1 for f in fs if f["kind"] == "named")
        A(f"| `{cls}` | {len(fs)} | 0x{vas[0]:06X}–0x{vas[-1]:06X} | {nm} |")
    A("")

    A("## Функции с восстановленными именами (полный список)")
    A("")
    A("| VA | класс | метод | файл |")
    A("|---|---|---|---|")
    for va, f in sorted(funcs.items()):
        if f["kind"] == "named":
            A(f"| 0x{va:06X} | `{f['cls']}` | `{f['method']}` | `{f['file']}` |")
    A("")

    A("## Функции без имени, отнесённые к классам")
    A("")
    A("| VA | класс | файл |")
    A("|---|---|---|")
    for va, f in sorted(funcs.items()):
        if f["kind"] == "fun" and f["cls"]:
            A(f"| 0x{va:06X} | `{f['cls']}` | `{f['file']}` |")
    A("")

    A("## Команды Tcl")
    A("")
    by_handler = defaultdict(list)
    for r in tcl:
        by_handler[r.get("handler_function", "")].append(r.get("tcl_command", ""))
    A("| обработчик | команды |")
    A("|---|---|")
    for h, cmds in sorted(by_handler.items()):
        A(f"| `{h}` | {', '.join('`%s`' % c for c in sorted(cmds))} |")
    A("")

    A("## Структуры и их раскладка")
    A("")
    by_struct = defaultdict(list)
    for r in gstructs:
        by_struct[r.get("class", "")].append(r)
    A("| класс | поле | смещение | тип |")
    A("|---|---|---|---|")
    for cls, rows in sorted(by_struct.items()):
        for r in sorted(rows, key=lambda x: int(x.get("offset", "0"), 16)):
            A(f"| `{cls}` | `{r.get('field','')}` | {r.get('offset','')} | `{r.get('type','')}` |")
    A("")

    A("## Граф вызовов (топ по числу вызываемых)")
    A("")
    A("| вызывающий | вызывает | callee-функций |")
    A("|---|---|---|")
    calls_fixed = []
    for r in calls:
        try:
            int(r.get("count", "0"))
            cnt, callees = r.get("count", ""), r.get("unnamed_callees", "")
        except ValueError:
            # в callgraph_subsystems.tsv фактический порядок: caller, count, callees
            cnt, callees = r.get("unnamed_callees", ""), r.get("count", "")
        calls_fixed.append((r.get("named_caller", ""), cnt, callees))
    for caller, cnt, callees in sorted(calls_fixed, key=lambda x: -int(x[1] or 0))[:120]:
        A(f"| `{caller}` | {cnt} | {callees[:200]}… |")
    A("")

    OUT.write_text("\n".join(L) + "\n", encoding="utf-8")
    print(f"записано: {OUT}  ({OUT.stat().st_size} байт, {len(L)} строк)")
    print(f"функций: {len(funcs)}, классов: {len(by_class)}, Tcl-команд: {len(tcl)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
