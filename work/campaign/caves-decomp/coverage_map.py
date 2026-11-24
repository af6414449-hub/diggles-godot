#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Build a subsystem + coverage map for the Diggles binaries.

Inputs
  EXE corpus : C:\\diggles-ghidra\\out\\decomp        (11 373 functions)
  PORT corpus: C:\\diggles-ghidra\\out_port\\decomp    ( 1 114 functions)
  Documents  : report.md, z24.md (+ any extra docs) -- what we already explained

Outputs
  coverage.tsv : one row per function  (module, addr, name, class, subsystem, documented)
  coverage.md  : summary tables

Usage:
  python coverage_map.py --out-dir <zone-dir> [--docs a.md b.md]
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
HEX_RE = re.compile(r"0x([0-9a-fA-F]{5,8})")
FUN_RE = re.compile(r"\bFUN_([0-9a-fA-F]{8})\b")
NAMED_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]{2,60})_([0-9a-fA-F]{8})\b")

SKIP_WORDS = {
    "if", "while", "for", "switch", "return", "sizeof", "defined", "else", "do",
    "case", "break", "continue", "goto", "typedef", "struct", "union", "enum",
    "static", "const", "void", "int", "char", "long", "short", "unsigned",
    "float", "double", "bool", "true", "false", "new", "delete", "this",
}

# class prefix -> subsystem
SUBSYSTEM = {
    # ---- world / terrain -------------------------------------------------
    "CMap": "world/terrain", "CFogOfWar": "world/terrain", "CProdPlanner": "world/terrain",
    "CPlaceFinder": "world/terrain", "CBlock": "world/terrain", "CBlockDB": "world/terrain",
    "CTile": "world/terrain", "CCell": "world/terrain", "CMapBuilder": "world/terrain",
    "CMapEditor": "world/terrain", "CMapLoader": "world/terrain", "CMapTemplate": "world/terrain",
    "CLG": "world/terrain", "CLGManager": "world/terrain", "CLevelGenerator": "world/terrain",
    "CTemplate": "world/terrain", "CRegion": "world/terrain", "CZone": "world/terrain",
    "CMaterial": "world/terrain", "CSurface": "world/terrain", "CHeightmap": "world/terrain",
    "CTerrain": "world/terrain", "CGround": "world/terrain", "CDig": "world/terrain",
    # ---- fluids -----------------------------------------------------------
    "CFluid": "fluids", "CWater": "fluids", "CLava": "fluids", "CParticle": "fluids",
    # ---- actors / AI ------------------------------------------------------
    "CObj": "objects/AI", "CAct": "objects/AI", "CFightActionMgr": "objects/AI",
    "CStoryMgr": "objects/AI", "CAi": "objects/AI", "CUnit": "objects/AI",
    "CWorker": "objects/AI", "CDwarf": "objects/AI", "CEnemy": "objects/AI",
    # ---- scripting --------------------------------------------------------
    "CTcl": "scripting/Tcl", "Tcl": "scripting/Tcl", "CTclGlobalMethods": "scripting/Tcl",
    "CTclObjMethods": "scripting/Tcl", "CTclActorMethods": "scripting/Tcl",
    "CTclPropMethods": "scripting/Tcl", "CTclCameraMethods": "scripting/Tcl",
    "CTclTerrainMethods": "scripting/Tcl", "CTclSoundMethods": "scripting/Tcl",
    "CTclFxMethods": "scripting/Tcl", "CTclUiMethods": "scripting/Tcl",
    "CTclMiscMethods": "scripting/Tcl", "CTclTriggersMethods": "scripting/Tcl",
    "CTclPlayerMethods": "scripting/Tcl", "CTclPartyMethods": "scripting/Tcl",
    "CTclAiMethods": "scripting/Tcl", "CTclWorldMethods": "scripting/Tcl",
    # ---- story / campaign -------------------------------------------------
    "CStory": "story/campaign", "CSequencer": "story/campaign", "CTrigger": "story/campaign",
    "CChapter": "story/campaign", "CCampaign": "story/campaign", "CQuest": "story/campaign",
    # ---- rendering --------------------------------------------------------
    "CModelRenderer": "rendering", "CMesh": "rendering", "CModel": "rendering",
    "CDecal": "rendering", "CTexture": "rendering", "CParticleRenderer": "rendering",
    "CRender": "rendering", "CCamera": "rendering/camera", "CLight": "rendering",
    "CFog": "rendering", "CSmoke": "rendering", "CWeather": "rendering",
    "CParticleFX": "rendering", "CScene": "rendering", "CSky": "rendering",
    # ---- ui / audio -------------------------------------------------------
    "CUI": "ui", "CGui": "ui", "CButton": "ui", "CMenu": "ui", "CHud": "ui",
    "CSound": "ui/audio", "CMusic": "ui/audio", "CAudio": "ui/audio",
    # ---- port layer (DigglesPort.dll) -------------------------------------
    "CSdl": "port/platform", "ScreenResolutionManager": "port/platform",
    "DisplayModeManager": "port/platform", "DisplayIndexManager": "port/platform",
    "PostProcessOptionManager": "port/platform", "GammaManager": "port/platform",
    "SoloudAudioPlayer": "port/platform", "CSdlManager": "port/platform",
    "CPlayer": "port/platform", "AchievementManager": "port/platform",
    "TimeManager": "port/platform", "GaLogger": "port/platform",
    "PStdUtils": "port/platform", "DX7DebugHelp": "port/platform",
    "IServicesManager": "port/platform", "CSteamServicesManager": "port/platform",
    "IDirect": "port/dx7-compat", "DirectDraw": "port/dx7-compat",
    "ChunkedTexture": "port/dx7-compat", "Mesa": "port/dx7-compat",
    # ---- misc engine services --------------------------------------------
    "CSoundManager": "engine/services", "CResource": "engine/services",
    "CFileSystem": "engine/services", "CLog": "engine/services",
    "CConfig": "engine/services", "CPhysics": "engine/services",
    "CRandom": "engine/services", "CTimer": "engine/services",
}

RUNTIME_HINTS = (
    "allocate", "free", "memcpy", "memset", "memmove", "strlen", "strcpy",
    "strncpy", "strcmp", "strcat", "strrchr", "strchr", "strstr", "sprintf",
    "vsprintf", "printf", "fprintf", "fopen", "fclose", "fread", "fwrite",
    "fseek", "ftell", "malloc", "calloc", "realloc", "_errno", "errno",
    "__acrt", "_nolock", "_common_", "write_", "read_", "close_", "open_",
    "terminate", "exception", "abort", "exit", "assert", "_wassert", "type_info",
    "bad_cast", "bad_typeid", "exception_", "yfl_", "_ctype", "_locale",
)


def strip_addr(stem: str) -> tuple[str, int]:
    m = re.match(r"^(.*?)_([0-9a-fA-F]{8})$", stem)
    if not m:
        return stem, -1
    return m.group(1), int(m.group(2), 16)


def class_of(name: str) -> str:
    if "__" in name:
        return name.split("__", 1)[0]
    m = re.match(r"^(C[A-Z][A-Za-z0-9_]*?)(?=[A-Z][a-z])", name)
    if m and name.startswith("C"):
        return m.group(1)
    return ""


def is_runtime(name: str) -> bool:
    ln = name.lower()
    if name.startswith("FUN_"):
        return False
    return any(h in ln for h in RUNTIME_HINTS)


def subsystem_for(cls: str, name: str) -> str:
    if cls:
        if cls in SUBSYSTEM:
            return SUBSYSTEM[cls]
        for k, v in SUBSYSTEM.items():
            if cls.startswith(k):
                return v
        return f"other:{cls}"
    if is_runtime(name):
        return "runtime/CRT"
    return "?"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out-dir", default=str(ZONE))
    ap.add_argument("--docs", nargs="*", default=None)
    args = ap.parse_args()
    out_dir = Path(args.out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    docs = [ZONE / "report.md", ZONE / "z24.md"]
    if args.docs:
        docs = [Path(d) for d in args.docs]

    doc_text = []
    for d in docs:
        if d.exists():
            doc_text.append(d.read_text(encoding="utf-8", errors="replace"))
    blob = "\n".join(doc_text)

    doc_funs = {m.lower() for m in FUN_RE.findall(blob)}
    doc_hex = set()
    for h in HEX_RE.findall(blob):
        try:
            doc_hex.add(int(h, 16))
        except ValueError:
            pass
    doc_named = {}
    for nm, hx in NAMED_RE.findall(blob):
        doc_named.setdefault(nm.lower(), set()).add(int(hx, 16))

    # ---- corpus scan ----------------------------------------------------
    rows = []
    callers: dict[str, set[str]] = defaultdict(set)
    file_cache: dict[str, str] = {}

    for module, root in (("exe", EXE_DIR), ("port", PORT_DIR)):
        if not root.exists():
            continue
        for f in sorted(root.glob("*.c")):
            stem = f.stem
            name, addr = strip_addr(stem)
            try:
                text = f.read_text(encoding="utf-8", errors="replace")
            except Exception:
                text = ""
            file_cache[name] = text
            for called in set(CALL_RE.findall(text)):
                if called in SKIP_WORDS or called == name:
                    continue
                callers[called].add(name)
            cls = class_of(name)
            rows.append({"module": module, "addr": addr, "name": name,
                         "cls": cls, "text": text})

    # ---- attribute unnamed functions to a subsystem via their callers -----
    def caller_subsystems(nm: str) -> Counter:
        c = Counter()
        for caller in callers.get(nm, ()):  # names
            ccls = class_of(caller)
            sub = subsystem_for(ccls, caller)
            if ccls:
                c[sub] += 1
        return c

    out_rows = []
    for r in rows:
        name, addr, cls = r["name"], r["addr"], r["cls"]
        sub = subsystem_for(cls, name)
        if not cls and not is_runtime(name):
            c = caller_subsystems(name)
            if c:
                sub = c.most_common(1)[0][0]
            else:
                sub = "unattributed"
        documented = False
        if addr >= 0:
            if f"{addr:08x}" in doc_funs:
                documented = True
            if addr in doc_hex:
                documented = True
            if name.lower() in doc_named and addr in doc_named[name.lower()]:
                documented = True
            if name.lower() in doc_named and not doc_named[name.lower()]:
                documented = True
        out_rows.append((r["module"], addr, name, cls, sub, 1 if documented else 0,
                         len(callers.get(name, ()))))

    tsv = out_dir / "coverage.tsv"
    with tsv.open("w", encoding="utf-8", newline="\n") as f:
        f.write("module\taddr\tname\tclass\tsubsystem\tdocumented\tcallers\n")
        for row in out_rows:
            f.write(f"{row[0]}\t0x{row[1]:08X}\t{row[2]}\t{row[3]}\t{row[4]}\t{row[5]}\t{row[6]}\n")

    # ---- summary ---------------------------------------------------------
    def summarize(module: str):
        sel = [r for r in out_rows if r[0] == module]
        total = len(sel)
        named = sum(1 for r in sel if not r[2].startswith("FUN_"))
        runtime = sum(1 for r in sel if r[4] == "runtime/CRT")
        unnamed = total - named - runtime
        doc = sum(1 for r in sel if r[5])
        by_sub = defaultdict(lambda: [0, 0])
        for r in sel:
            by_sub[r[4]][0] += 1
            by_sub[r[4]][1] += r[5]
        return total, named, runtime, unnamed, doc, by_sub

    md = []
    md.append("# Карта покрытия декомпиляции Diggles\n")
    md.append("Сгенерировано скриптом `coverage_map.py`.\n")
    md.append("`документировано` = функция упомянута в `report.md`/`z24.md` "
              "(по имени, по адресу `FUN_xxxxxxxx` или по hex-VA).\n")
    for module, title in (("exe", "Diggles.exe"), ("port", "DigglesPort.dll")):
        total, named, runtime, unnamed, doc, by_sub = summarize(module)
        md.append(f"\n## {title}\n")
        md.append(f"- функций в корпусе: **{total}**")
        md.append(f"- с восстановленным именем: **{named}**")
        md.append(f"- рантайм/CRT (не игровой код): **{runtime}**")
        md.append(f"- анонимных `FUN_*`: **{unnamed}**")
        md.append(f"- упомянуто в отчёте: **{doc}** "
                  f"({doc * 100.0 / total if total else 0:.1f} %)\n")
        md.append("| подсистема | функций | задокументировано | % |")
        md.append("|---|---:|---:|---:|")
        for sub, (n, d) in sorted(by_sub.items(), key=lambda kv: -kv[1][0]):
            md.append(f"| {sub} | {n} | {d} | {(d * 100.0 / n if n else 0):.1f} % |")

    (out_dir / "coverage.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print(f"rows: {len(out_rows)} -> {tsv}")
    for module in ("exe", "port"):
        total, named, runtime, unnamed, doc, by_sub = summarize(module)
        print(f"{module}: total={total} named={named} runtime={runtime} "
              f"unnamed={unnamed} documented={doc} ({doc*100.0/total if total else 0:.1f}%)")
        for sub, (n, d) in sorted(by_sub.items(), key=lambda kv: -kv[1][0])[:12]:
            print(f"    {sub:<26} {n:>6}  doc={d:>5}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
