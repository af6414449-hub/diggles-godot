#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Coverage map v2 for the Diggles binaries.

Classification
  pseudo   : SEH unwind stubs (Unwind_*), FID conflicts, Catch_All -- not code
  crt      : statically linked Universal CRT / MSVC runtime
  game     : everything else (the actual engine)

Coverage tiers (how well the report explains a function)
  tier 0   : not mentioned in the documents
  tier 1   : mentioned once (name or address)
  tier 2   : mentioned 2+ times (repeatedly cited)
  tier 3   : cited with a file:line reference  (name_xxyyyyyy.c:N-M)

Outputs
  coverage.tsv : module, addr, name, class, subsystem, kind, tier, mentions, callers
  coverage.md  : summary tables

Usage:
  python coverage_map2.py [--out-dir DIR] [--docs a.md b.md ...]
"""
from __future__ import annotations

import argparse
import re
from collections import Counter, defaultdict
from pathlib import Path

EXE_DIR = Path(r"C:\diggles-ghidra\out\decomp")
PORT_DIR = Path(r"C:\diggles-ghidra\out_port\decomp")
ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")

CALL_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]{2,60})\s*\(")
SKIP_WORDS = {
    "if", "while", "for", "switch", "return", "sizeof", "defined", "else", "do",
    "case", "break", "continue", "goto", "typedef", "struct", "union", "enum",
    "static", "const", "void", "int", "char", "long", "short", "unsigned",
    "float", "double", "bool", "true", "false", "new", "delete", "this",
}

# --- pseudo functions (not real code) -------------------------------------
PSEUDO_PAT = re.compile(r"^(Unwind_|FID_conflict|Catch_All|__CxxFrameHandler)")

# --- Universal CRT / MSVC runtime -----------------------------------------
CRT_PAT = re.compile(
    r"^(common_|__acrt|___acrt|_?acrt_|_nolock|_l_stat|__lc_|operator_|"
    r"_onexit|_cexit|_amsg_exit|_initterm|_crt_|_seh_|__security_|_except_4|"
    r"_controlfp|configure_text_mode|construct_ptd|compute_|convert_decimal|"
    r"_ctype|_locale|_wcs|__wcs|_mbs|__mb|_mb|_str|_wstr|_mem|"
    r"_callnewh|_Xcvt|_amsg|__p__|_ftime|_time64|"
    r"_matherr|_setjmp|__setjmp|invalid_parameter|__report|_invalid|"
    r"terminate|__clean_type|_seh|_except|_abnormal|_purecall|_RTC_|"
    r"__debug|_CxxThrow|__CxxFrame|__EH_|_alloca_probe|__chkesp|__ftol|"
    r"__cintrindisp|_controlfp_s|_set_error|_except_handler|"
    r"_local_unwind|_global_unwind|__wassert|_assert|__lconv|__wfind|"
    r"_wfind|_wcsicmp|_wcsnicmp|__acrt|__scrt_|__scrt|___scrt|"
    r"_seh_filter|_seh_|_libm_|__allmul|__aulldvrm|__alldiv|"
    r"libm_|__crt|_amsg_exit|_Xcvt|_matherr|__setusermatherr|"
    r"_wassert|__wgetmainargs|__winitenv|_initenv|__initterm|"
    r"_set_new_mode|_configthreadlocale|_cexit|_onexit|_fmode|"
    r"_commode|_pgmptr|_osplatform|_osver|_winmajor|_winminor|"
    r"_winver|_pctype|_mbctype|_isctype|_chvalidator|__mb_cur_max|"
    r"_getpid|__getmainargs|_seh|_controlfp|_except|__security|"
    r"_Xcvt|_crtDbgReport|_CrtDbgReport|__report|__acrt|_local_)"
)

# --- class prefix -> subsystem -------------------------------------------
SUBSYSTEM = {
    "CTclGlobalMethods": "scripting/Tcl (global cmds)",
    "CTclObjMethods": "scripting/Tcl (object cmds)",
    "CTclClassDefMethods": "scripting/Tcl (class defs)",
    "CTcl": "scripting/Tcl (core)",
    "CMap": "world/terrain", "CFogOfWar": "world/terrain",
    "CProdPlanner": "world/terrain", "CProdPlannerMgr": "world/terrain",
    "CPlaceFinder": "world/terrain", "CBlock": "world/terrain",
    "CLG": "world/terrain", "CLGManager": "world/terrain",
    "CTemplate": "world/terrain", "CRegion": "world/terrain",
    "CFluid": "fluids", "CLava": "fluids",
    "CObj": "objects/AI", "CAct": "objects/AI", "CAct_Lore": "objects/AI",
    "CFightActionMgr": "objects/AI", "CStoryMgr": "objects/AI",
    "CGameThread": "objects/AI", "CDwarf": "objects/AI",
    "CStory": "story/campaign", "CTrigger": "story/campaign",
    "CModelRenderer": "rendering", "CScapeRenderer": "rendering",
    "CDXSound": "audio", "CPlayer": "port/media",
    "CDisplay": "rendering/display", "CGameWindow": "rendering/display",
    "CDXExecBuf": "rendering/dxexec", "CDXRenderJob": "rendering/dxexec",
    "CSdl": "port/platform", "ScreenResolutionManager": "port/platform",
    "DisplayModeManager": "port/platform", "DisplayIndexManager": "port/platform",
    "PostProcessOptionManager": "port/platform", "GammaManager": "port/platform",
    "SoloudAudioPlayer": "port/audio", "CSdlManager": "port/platform",
    "AchievementManager": "port/steam", "TimeManager": "port/platform",
    "GaLogger": "port/logging", "PStdUtils": "port/platform",
    "DX7DebugHelp": "port/dx7-compat", "IDirect": "port/dx7-compat",
    "ChunkedTexture": "port/dx7-compat", "Image": "port/dx7-compat",
    "Mesa": "port/dx7-compat", "Texture": "port/dx7-compat",
    "CWigglesApp": "app/lifecycle",
}

# class prefix families that map to a subsystem by prefix match
PREFIX_FAMILY = [
    ("CTcl", "scripting/Tcl"),
    ("CMap", "world/terrain"),
    ("CFog", "world/terrain"),
    ("CProd", "world/terrain"),
    ("CPlace", "world/terrain"),
    ("CBlock", "world/terrain"),
    ("CLG", "world/terrain"),
    ("CTemplate", "world/terrain"),
    ("CFluid", "fluids"),
    ("CObj", "objects/AI"),
    ("CAct", "objects/AI"),
    ("CFight", "objects/AI"),
    ("CStory", "story/campaign"),
    ("CTrigger", "story/campaign"),
    ("CModel", "rendering"),
    ("CScape", "rendering"),
    ("CDX", "rendering/dxexec"),
    ("CDisplay", "rendering/display"),
    ("CGame", "app/lifecycle"),
    ("CSdl", "port/platform"),
    ("CTerrain", "world/terrain"),
    ("CCell", "world/terrain"),
    ("CProp", "objects/props"),
    ("CParticle", "rendering/particles"),
    ("CSound", "audio"),
]


def strip_addr(stem: str) -> tuple[str, int]:
    m = re.match(r"^(.*?)_([0-9a-fA-F]{8})$", stem)
    if not m:
        return stem, -1
    return m.group(1), int(m.group(2), 16)


def class_of(name: str) -> str:
    if "__" in name:
        return name.split("__", 1)[0]
    for sep in ("_",):
        if sep in name:
            head = name.split(sep, 1)[0]
            if head.startswith("C") and len(head) > 2 and head[1].isupper():
                return head
    return ""


def kind_of(name: str) -> str:
    if PSEUDO_PAT.match(name):
        return "pseudo"
    if name.startswith("FUN_"):
        return "game"
    if CRT_PAT.match(name):
        return "crt"
    if name.startswith("Unwind_"):
        return "pseudo"
    return "game"


def subsystem_for(cls: str, name: str, kind: str) -> str:
    if kind == "pseudo":
        return "pseudo/SEH-unwind"
    if kind == "crt":
        return "runtime/UCRT"
    if cls:
        if cls in SUBSYSTEM:
            return SUBSYSTEM[cls]
        for pref, sub in PREFIX_FAMILY:
            if cls.startswith(pref):
                return sub
        return f"other:{cls}"
    return "?"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out-dir", default=str(ZONE))
    ap.add_argument("--docs", nargs="*", default=None)
    args = ap.parse_args()
    out_dir = Path(args.out_dir)

    docs = [ZONE / "report.md", ZONE / "z24.md"]
    if args.docs:
        docs = [Path(d) for d in args.docs]
    blob = "\n".join(d.read_text(encoding="utf-8", errors="replace")
                     for d in docs if d.exists())

    # mentions: count how often each function name/address appears
    mention = Counter()
    for m in re.finditer(r"\bFUN_([0-9a-fA-F]{8})\b", blob):
        mention[f"FUN_{m.group(1).lower()}"] += 1
    for m in re.finditer(r"\b([A-Za-z_][A-Za-z0-9_]{2,60})_([0-9a-fA-F]{8})\b", blob):
        mention[m.group(1).lower()] += 1
    # "file.c:123" style citations
    cited = set()
    for m in re.finditer(r"([A-Za-z_][A-Za-z0-9_]{2,60})_([0-9a-fA-F]{8})\.c:(\d+)", blob):
        cited.add(m.group(1).lower())
        mention[m.group(1).lower()] += 1

    # ---- corpus ----------------------------------------------------------
    rows = []
    callers: dict[str, set[str]] = defaultdict(set)
    for module, root in (("exe", EXE_DIR), ("port", PORT_DIR)):
        if not root.exists():
            continue
        for f in sorted(root.glob("*.c")):
            name, addr = strip_addr(f.stem)
            try:
                text = f.read_text(encoding="utf-8", errors="replace")
            except Exception:
                text = ""
            for called in set(CALL_RE.findall(text)):
                if called in SKIP_WORDS or called == name:
                    continue
                callers[called].add(name)
            cls = class_of(name)
            kind = kind_of(name)
            rows.append({"module": module, "addr": addr, "name": name,
                         "cls": cls, "kind": kind, "text": text})

    # ---- subsystem attribution for unnamed game functions ----------------
    named_cls = {r["name"]: r["cls"] for r in rows if r["cls"]}
    def caller_subs(nm: str) -> Counter:
        c = Counter()
        for cr in callers.get(nm, ()):
            ccls = named_cls.get(cr)
            if ccls:
                s = subsystem_for(ccls, cr, kind_of(cr))
                if s not in ("?",) and not s.startswith("other:"):
                    c[s] += 1
        return c

    out_rows = []
    for r in rows:
        name, addr, cls, kind = r["name"], r["addr"], r["cls"], r["kind"]
        sub = subsystem_for(cls, name, kind)
        if sub == "?":
            c = caller_subs(name)
            sub = c.most_common(1)[0][0] if c else "unattributed"
        cnt = mention.get(name.lower(), 0)
        if name.lower() in cited and cnt < 3:
            cnt = 3
        tier = 0 if cnt == 0 else (1 if cnt == 1 else (2 if cnt < 3 else 3))
        out_rows.append((r["module"], addr, name, cls, sub, kind, tier, cnt,
                         len(callers.get(name, ()))))

    tsv = out_dir / "coverage.tsv"
    with tsv.open("w", encoding="utf-8", newline="\n") as f:
        f.write("module\taddr\tname\tclass\tsubsystem\tkind\ttier\tmentions\tcallers\n")
        for row in out_rows:
            f.write(f"{row[0]}\t0x{row[1]:08X}\t{row[2]}\t{row[3]}\t{row[4]}\t{row[5]}\t"
                    f"{row[6]}\t{row[7]}\t{row[8]}\n")

    md = ["# Карта покрытия декомпиляции Diggles (v2)\n",
          "Сгенерировано `coverage_map2.py`. Корпус: `C:\\diggles-ghidra\\out\\decomp` (exe) "
          "и `C:\\diggles-ghidra\\out_port\\decomp` (DigglesPort.dll).\n",
          "Типы: `pseudo` — псевдофункции раскрутки SEH (не код); `crt` — статически "
          "прилинкованный UCRT/MSVC-runtime; `game` — код игры.\n",
          "Тиры покрытия: 0 — не упомянута; 1 — упомянута один раз; 2 — 2 раза; "
          "3 — цитируется со ссылкой `файл:строка`.\n"]

    for module, title in (("exe", "Diggles.exe"), ("port", "DigglesPort.dll")):
        sel = [r for r in out_rows if r[0] == module]
        total = len(sel)
        by_kind = Counter(r[5] for r in sel)
        real = total - by_kind["pseudo"]
        by_tier = Counter(r[6] for r in sel)
        md.append(f"\n## {title}\n")
        md.append(f"- записей в корпусе: **{total}**")
        md.append(f"- псевдофункций SEH (`Unwind_*`): **{by_kind['pseudo']}**")
        md.append(f"- реальных функций: **{real}**")
        md.append(f"- из них UCRT/runtime: **{by_kind['crt']}**")
        md.append(f"- из них код игры: **{by_kind['game']}**")
        md.append(f"- покрыто отчётом (тир ≥ 1): **{total - by_tier[0]}** "
                  f"({(total - by_tier[0]) * 100.0 / total:.1f} % корпуса, "
                  f"{(total - by_tier[0]) * 100.0 / real:.1f} % реальных функций)")
        md.append(f"- тир 3 (разобрано детально, со ссылками): **{by_tier[3]}**\n")
        md.append("| подсистема | функций | тир0 | тир1 | тир2 | тир3 |")
        md.append("|---|---:|---:|---:|---:|---:|")
        by_sub = defaultdict(Counter)
        for r in sel:
            by_sub[r[4]][r[6]] += 1
            by_sub[r[4]]["n"] += 1
        for sub, c in sorted(by_sub.items(), key=lambda kv: -kv[1]["n"]):
            md.append(f"| {sub} | {c['n']} | {c[0]} | {c[1]} | {c[2]} | {c[3]} |")
        md.append("")
        md.append("| подсистема | объём (функций) | не разобрано (тир 0) | приоритет |")
        md.append("|---|---:|---:|---|")
        pr = sorted(by_sub.items(), key=lambda kv: -kv[1]["n"])
        for i, (sub, c) in enumerate(pr[:15], 1):
            md.append(f"| {sub} | {c['n']} | {c[0]} | {i} |")

    (out_dir / "coverage.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print(f"rows={len(out_rows)} -> {tsv}")
    for module in ("exe", "port"):
        sel = [r for r in out_rows if r[0] == module]
        bk = Counter(r[5] for r in sel)
        bt = Counter(r[6] for r in sel)
        print(f"{module}: total={len(sel)} pseudo={bk['pseudo']} crt={bk['crt']} "
              f"game={bk['game']} | tier0={bt[0]} tier1={bt[1]} tier2={bt[2]} tier3={bt[3]}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
