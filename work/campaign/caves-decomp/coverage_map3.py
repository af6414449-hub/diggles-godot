#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Coverage map v3: BFS attribution of anonymous functions to subsystems.

For every anonymous (FUN_*) game function we walk *up* the call graph
(caller -> callee edges reversed) up to MAX_DEPTH steps, skipping CRT and
SEH-unwind nodes, and attribute the function to the class of the nearest
named function reached.  The anchor (nearest named caller) is kept as well:
it tells exactly which engine area owns the still-unexplained block.

Outputs
  coverage.tsv   module, addr, name, class, subsystem, kind, tier, anchor
  coverage.md    summary tables
  next_targets.md  ranked clusters of not-yet-explained functions
"""
from __future__ import annotations

import argparse
import re
from collections import Counter, defaultdict, deque
from pathlib import Path

EXE_DIR = Path(r"C:\diggles-ghidra\out\decomp")
PORT_DIR = Path(r"C:\diggles-ghidra\out_port\decomp")
ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")
MAX_DEPTH = 6

CALL_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]{2,60})\s*\(")
SKIP_WORDS = {
    "if", "while", "for", "switch", "return", "sizeof", "defined", "else", "do",
    "case", "break", "continue", "goto", "typedef", "struct", "union", "enum",
    "static", "const", "void", "int", "char", "long", "short", "unsigned",
    "float", "double", "bool", "true", "false", "new", "delete", "this",
}

PSEUDO_PAT = re.compile(r"^(Unwind_|FID_conflict|Catch_All)")

CRT_PAT = re.compile(
    r"^(common_|__acrt|___acrt|_?acrt_|_nolock|_l_stat|__lc_|operator_|"
    r"_onexit|_cexit|_amsg_exit|_initterm|_crt_|_seh_|__security_|_except_4|"
    r"_controlfp|configure_text_mode|construct_ptd|compute_|convert_decimal|"
    r"_ctype|_locale|_wcs|__wcs|_mbs|__mb|_mb|_str|_wstr|_mem|"
    r"_callnewh|_Xcvt|_amsg|__p__|_ftime|_time64|_matherr|_setjmp|__setjmp|"
    r"invalid_parameter|__report|_invalid|terminate|__clean_type|_seh|"
    r"_except|_abnormal|_purecall|_RTC_|__debug|_CxxThrow|__CxxFrame|__EH_|"
    r"_alloca_probe|__chkesp|__ftol|__cintrindisp|_controlfp_s|_set_error|"
    r"_except_handler|_local_unwind|_global_unwind|__wassert|_assert|__lconv|"
    r"__wfind|_wfind|_wcsicmp|_wcsnicmp|__scrt_|___scrt|_seh_filter|"
    r"_libm_|__allmul|__aulldvrm|__alldiv|libm_|_matherr|__setusermatherr|"
    r"__wgetmainargs|__winitenv|_initenv|_set_new_mode|_configthreadlocale|"
    r"_commode|_pgmptr|_osplatform|_osver|_winmajor|_winminor|_winver|"
    r"_pctype|_mbctype|_isctype|_chvalidator|__mb_cur_max|_getpid|"
    r"parse_|convert_|input_adapter|output_adapter|make_c_string|"
    r"skip_whitespace|type_case|TypeMatch|BuildCatch|CatchIt|"
    r"common_|uninitialize|initialize_|configure_|construct_|compute_|"
    r"write_multiple|copy_wide|is_overflow|find_first|find_next|"
    r"locale_|_wassert|__wcs_|_wcsdup|_wcsicmp|_wcsncpy|"
    r"__crt|_CrtDbgReport|_amsg_exit|_Xcvt)",
    re.IGNORECASE,
)

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
    "CGameThread": "app/lifecycle", "CDwarf": "objects/AI",
    "CStory": "story/campaign", "CTrigger": "story/campaign",
    "CModelRenderer": "rendering", "CScapeRenderer": "rendering",
    "CDXSound": "audio", "CPlayer": "port/media",
    "CDisplay": "rendering/display", "CWigglesApp": "app/lifecycle",
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
    "C3DDB": "world/3db", "CDummyObjMgr": "objects/AI",
}

PREFIX_FAMILY = [
    ("CTcl", "scripting/Tcl"),
    ("CMap", "world/terrain"), ("CFog", "world/terrain"),
    ("CProd", "world/terrain"), ("CPlace", "world/terrain"),
    ("CBlock", "world/terrain"), ("CLG", "world/terrain"),
    ("CTemplate", "world/terrain"), ("CFluid", "fluids"),
    ("CObj", "objects/AI"), ("CAct", "objects/AI"),
    ("CFight", "objects/AI"), ("CStory", "story/campaign"),
    ("CTrigger", "story/campaign"), ("CModel", "rendering"),
    ("CScape", "rendering"), ("CDX", "rendering/dxexec"),
    ("CDisplay", "rendering/display"), ("CGame", "app/lifecycle"),
    ("CSdl", "port/platform"), ("CTerrain", "world/terrain"),
    ("CCell", "world/terrain"), ("CProp", "objects/props"),
    ("CParticle", "rendering/particles"), ("CSound", "audio"),
    ("C3DDB", "world/3db"), ("CWiggles", "app/lifecycle"),
]


def strip_addr(stem):
    m = re.match(r"^(.*?)_([0-9a-fA-F]{8})$", stem)
    return (m.group(1), int(m.group(2), 16)) if m else (stem, -1)


def class_of(name):
    if "__" in name:
        return name.split("__", 1)[0]
    if "_" in name:
        head = name.split("_", 1)[0]
        if head.startswith("C") and len(head) > 2 and head[1].isupper():
            return head
    return ""


def kind_of(name):
    if PSEUDO_PAT.match(name):
        return "pseudo"
    if name.startswith("FUN_"):
        return "game"
    # Ghidra names every MSVC/UCRT helper with a leading underscore
    # (FID signature matching): _memset, ___dcrt_*, __alloca_probe, ...
    if name.startswith("_"):
        return "crt"
    if CRT_PAT.match(name):
        return "crt"
    return "game"


def subsystem_for(cls, name, kind):
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

    mention = Counter()
    cited = set()
    for m in re.finditer(r"\bFUN_([0-9a-fA-F]{8})\b", blob):
        mention[f"FUN_{m.group(1).lower()}"] += 1
    for m in re.finditer(r"\b([A-Za-z_][A-Za-z0-9_]{2,60})_([0-9a-fA-F]{8})\b", blob):
        mention[m.group(1).lower()] += 1
    for m in re.finditer(r"([A-Za-z_][A-Za-z0-9_]{2,60})_([0-9a-fA-F]{8})\.c:(\d+)", blob):
        cited.add(m.group(1).lower())
        mention[m.group(1).lower()] += 1

    # ---- corpus + graph --------------------------------------------------
    rows = []
    callers = defaultdict(set)      # callee -> {callers}
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
            rows.append({"module": module, "addr": addr, "name": name,
                         "cls": class_of(name), "kind": kind_of(name)})

    meta = {r["name"]: (r["cls"], r["kind"]) for r in rows}

    # ---- BFS attribution -------------------------------------------------
    def attribute(nm):
        seen = {nm}
        q = deque([(nm, 0)])
        hits = Counter()
        anchor = None
        while q:
            cur, depth = q.popleft()
            if depth >= MAX_DEPTH:
                continue
            for caller in callers.get(cur, ()):
                if caller in seen:
                    continue
                seen.add(caller)
                ccls, ckind = meta.get(caller, ("", "game"))
                if ckind in ("pseudo", "crt"):
                    continue
                if ccls:
                    sub = subsystem_for(ccls, caller, ckind)
                    hits[sub] += 1
                    if anchor is None:
                        anchor = caller
                q.append((caller, depth + 1))
        if not hits:
            return None, None
        return hits.most_common(1)[0][0], anchor

    out_rows = []
    for r in rows:
        name, cls, kind = r["name"], r["cls"], r["kind"]
        sub = subsystem_for(cls, name, kind)
        anchor = ""
        if sub == "?":
            sub, anchor = attribute(name)
            if sub is None:
                sub = "unattributed"
        cnt = mention.get(name.lower(), 0)
        if name.lower() in cited and cnt < 3:
            cnt = 3
        tier = 0 if cnt == 0 else (1 if cnt == 1 else (2 if cnt < 3 else 3))
        out_rows.append((r["module"], r["addr"], name, cls, sub, kind, tier, cnt,
                         anchor or "-"))

    with (out_dir / "coverage.tsv").open("w", encoding="utf-8", newline="\n") as f:
        f.write("module\taddr\tname\tclass\tsubsystem\tkind\ttier\tmentions\tanchor\n")
        for row in out_rows:
            f.write(f"{row[0]}\t0x{row[1]:08X}\t{row[2]}\t{row[3]}\t{row[4]}\t{row[5]}\t"
                    f"{row[6]}\t{row[7]}\t{row[8]}\n")

    # ---- next targets ----------------------------------------------------
    clusters = defaultdict(list)
    for row in out_rows:
        if row[6] == 0 and row[4] not in ("pseudo/SEH-unwind", "runtime/UCRT"):
            clusters[(row[4], row[8])].append(row[2])

    md = ["# Карта покрытия декомпиляции Diggles (v3)\n",
          "Сгенерировано `coverage_map3.py`. Корпус: `C:\\diggles-ghidra\\out\\decomp` "
          "(Diggles.exe) и `C:\\diggles-ghidra\\out_port\\decomp` (DigglesPort.dll).\n",
          "Типы: `pseudo` — псевдофункции раскрутки SEH (не код); `crt` — статически "
          "прилинкованный UCRT/MSVC-runtime; `game` — код игры.\n",
          "Атрибуция: BFS вверх по графу вызовов (до 6 уровней) до ближайшей именованной "
          "функции; `якорь` — эта функция.\n",
          "Тиры покрытия: 0 — не упомянута; 1 — упомянута один раз; 2 — 2 раза; "
          "3 — цитируется со ссылкой `файл:строка`.\n"]

    for module, title in (("exe", "Diggles.exe"), ("port", "DigglesPort.dll")):
        sel = [r for r in out_rows if r[0] == module]
        total = len(sel)
        bk = Counter(r[5] for r in sel)
        bt = Counter(r[6] for r in sel)
        real = total - bk["pseudo"]
        md.append(f"\n## {title}\n")
        md.append(f"- записей в корпусе: **{total}**")
        md.append(f"- псевдофункций SEH (`Unwind_*` и пр.): **{bk['pseudo']}**")
        md.append(f"- реальных функций: **{real}**")
        md.append(f"- из них распознано как UCRT/runtime: **{bk['crt']}**")
        md.append(f"- из них код игры: **{bk['game']}**")
        md.append(f"- покрыто отчётом (тир ≥ 1): **{total - bt[0]}** "
                  f"({(total - bt[0]) * 100.0 / total:.1f} % корпуса, "
                  f"{(total - bt[0]) * 100.0 / real:.1f} % реальных функций)")
        md.append(f"- тир 3 (разобрано детально, со ссылками): **{bt[3]}**\n")
        md.append("| подсистема | функций | тир0 | тир1 | тир2 | тир3 |")
        md.append("|---|---:|---:|---:|---:|---:|")
        by_sub = defaultdict(Counter)
        for r in sel:
            by_sub[r[4]][r[6]] += 1
            by_sub[r[4]]["n"] += 1
        for sub, c in sorted(by_sub.items(), key=lambda kv: -kv[1]["n"]):
            md.append(f"| {sub} | {c['n']} | {c[0]} | {c[1]} | {c[2]} | {c[3]} |")
        md.append("")

    (out_dir / "coverage.md").write_text("\n".join(md) + "\n", encoding="utf-8")

    nt = ["# Следующие цели декомпиляции (кластеры неразобранных функций)\n",
          "Каждая строка — подсистема и её «якорь» (ближайшая именованная функция-владелец), "
          "все неразобранные (`тир 0`) анонимные функции, вызываемые из него.\n"]
    ranked = sorted(clusters.items(), key=lambda kv: -len(kv[1]))
    nt.append("| # | подсистема | якорь | неразобранных | пример |")
    nt.append("|---:|---|---|---:|---|")
    for i, ((sub, anchor), names) in enumerate(ranked[:40], 1):
        nt.append(f"| {i} | {sub} | `{anchor}` | {len(names)} | "
                  f"`{names[0]}` |")
    nt.append("\n## Списки функций по кластерам (топ-20)\n")
    for i, ((sub, anchor), names) in enumerate(ranked[:20], 1):
        nt.append(f"\n### {i}. {sub} — якорь `{anchor}` ({len(names)} функций)\n")
        nt.append("```")
        nt.extend(sorted(names))
        nt.append("```")
    (out_dir / "next_targets.md").write_text("\n".join(nt) + "\n", encoding="utf-8")

    for module in ("exe", "port"):
        sel = [r for r in out_rows if r[0] == module]
        bk = Counter(r[5] for r in sel)
        bt = Counter(r[6] for r in sel)
        unattr = sum(1 for r in sel if r[4] == "unattributed")
        print(f"{module}: total={len(sel)} pseudo={bk['pseudo']} crt={bk['crt']} "
              f"game={bk['game']} unattributed={unattr} | tier0={bt[0]} tier1={bt[1]} "
              f"tier2={bt[2]} tier3={bt[3]}")
    print(f"clusters: {len(ranked)} (top: "
          + ", ".join(f"{key[1]}={len(names)}" for key, names in ranked[:5]) + ")")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
