#!/usr/bin/env python3
"""Collect the useful part of the Ghidra export into the repository.

The full dump (tens of thousands of .c files) stays outside the repo, on
C:\\diggles-ghidra\\out. Into the repo we take what the port actually reads:

  work/campaign/ref/ghidra-out/index.tsv      — every function, its address,
                                                size, line count and status
  work/campaign/ref/ghidra-out/decomp/*.c     — only the functions that carry
                                                a real name (610 engine methods
                                                from the assert strings + 23
                                                native Tcl commands)
  work/campaign/ref/ghidra-out/classes.txt    — RTTI classes Ghidra recovered
  work/campaign/ref/ghidra-out/strings.tsv    — the engine's string table

Usage: python collect_ghidra_out.py [ghidra-out-dir] [repo-ref-dir]
"""
from __future__ import annotations

import shutil
import sys
from pathlib import Path


def collect_dir(src: Path, dst: Path, pattern: str = "*", limit: int | None = None) -> None:
    dst.mkdir(parents=True, exist_ok=True)
    files = sorted(src.glob(pattern))
    if limit:
        files = files[:limit]
    copied = 0
    for f in files:
        target = dst / f.name
        if not target.exists() or target.stat().st_size != f.stat().st_size:
            shutil.copy2(f, target)
            copied += 1
    print(f"{src.name}: {len(files)} файлов (скопировано {copied}) -> {dst}")


def main() -> int:
    src = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(r"C:\diggles-ghidra\out")
    dst = Path(sys.argv[2]) if len(sys.argv) > 2 else \
        Path(__file__).resolve().parent / "ghidra-out"
    (dst / "decomp").mkdir(parents=True, exist_ok=True)

    for name in ("index.tsv", "classes.txt", "strings.tsv"):
        p = src / name
        if p.exists() and p.stat().st_size > 0:
            shutil.copy2(p, dst / name)
            print(f"copied {name}: {(dst / name).stat().st_size // 1024} KB")

    decomp = src / "decomp"
    named = [f for f in decomp.glob("*.c") if not f.name.startswith("FUN_")]
    copied = 0
    for f in named:
        target = dst / "decomp" / f.name
        if not target.exists() or target.stat().st_size != f.stat().st_size:
            shutil.copy2(f, target)
            copied += 1
    total = len(list((dst / "decomp").glob("*.c")))
    print(f"named decomp files: {len(named)} (copied/updated {copied}), in repo: {total}")

    # DigglesPort.dll (the SDL2 shim) and the typed pass
    port = Path(r"C:\diggles-ghidra\out_port")
    if port.exists():
        collect_dir(port / "decomp", dst / "port_decomp", "*.c")
        if (port / "index.tsv").exists():
            shutil.copy2(port / "index.tsv", dst / "index_port.tsv")
    typed = Path(r"C:\diggles-ghidra\out_typed")
    if typed.exists():
        collect_dir(typed, dst / "typed", "*.c")
        if (typed / "index_typed.tsv").exists():
            shutil.copy2(typed / "index_typed.tsv", dst / "index_typed.tsv")
    typed2 = Path(r"C:\diggles-ghidra\out_typed2")
    if typed2.exists():
        collect_dir(typed2, dst / "typed2", "*.c")
        if (typed2 / "index_typed2.tsv").exists():
            shutil.copy2(typed2 / "index_typed2.tsv", dst / "index_typed2.tsv")
    return 0


if __name__ == "__main__":
    sys.exit(main())
