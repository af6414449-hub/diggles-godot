#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Probe the address layout of the exe corpus: where does game code end
and CRT begin?  Samples function names across the .text range and reports
contiguous runs of CRT-looking vs game-looking names.

Usage: python layout_probe.py [--samples 120]
"""
from __future__ import annotations

import re
from pathlib import Path

EXE = Path(r"C:\diggles-ghidra\out\decomp")
PORT = Path(r"C:\diggles-ghidra\out_port\decomp")

# names produced by the statically linked Universal CRT
CRT_PAT = re.compile(
    r"^(common_|__acrt|_?acrt_|_nolock|_stat$|_nolock_|_l_|_l_stat|"
    r"__lc_|__acrt|operator_|_onexit|_cexit|_amsg_exit|_initterm|"
    r"_initterm_e|_crt_|_seh_|__security_|_except_|_controlfp|"
    r"configure_text_mode|construct_ptd|compute_|convert_decimal|"
    r"_ctype|_locale|_wcs|__wcs|_mbs|__mb|_mb|_str|_wstr|_mem|"
    r"__lc|_callnewh|_Xcvt|_amsg|__p__|_ftime|_ftime64|_time64|"
    r"_cexit|_onexit|_exit|_matherr|_setjmp|__setjmp|"
    r"invalid_parameter|__report|_invalid|terminate|__clean_type|"
    r"_seh|_except|_abnormal|_purecall|_RTC_|__debug|_CxxThrow|"
    r"__CxxFrame|__EH_|_alloca_probe|__chkesp|__ftol|__cintrindisp|"
    r"_invalid_parameter|_purecall|_controlfp_s|_set_error|"
    r"_except_handler|_local_unwind|_global_unwind)",
    re.IGNORECASE,
)


def load(root: Path):
    fns = []
    for f in root.glob("*.c"):
        m = re.match(r"^(.*?)_([0-9a-fA-F]{8})$", f.stem)
        if not m:
            continue
        fns.append((int(m.group(2), 16), m.group(1)))
    fns.sort()
    return fns


def main() -> None:
    for tag, root in (("EXE", EXE), ("PORT", PORT)):
        fns = load(root)
        if not fns:
            continue
        print(f"=== {tag}: {len(fns)} functions, "
              f"0x{fns[0][0]:08X}..0x{fns[-1][0]:08X}")
        n = len(fns)
        step = max(1, n // 60)
        for i in range(0, n, step):
            addr, name = fns[i]
            kind = "CRT" if CRT_PAT.match(name) else (
                "game" if not name.startswith("FUN_") else "fun?")
            print(f"   0x{addr:08X}  {kind:<5} {name}")
        # contiguous runs of CRT-style names
        runs = []
        start = None
        prev = None
        for addr, name in fns:
            is_crt = bool(CRT_PAT.match(name))
            if is_crt and start is None:
                start = addr
            if not is_crt and start is not None:
                runs.append((start, prev))
                start = None
            prev = addr
        if start is not None:
            runs.append((start, prev))
        runs.sort(key=lambda r: -(r[1] - r[0]))
        print("  -- biggest CRT-style runs --")
        for a, b in runs[:6]:
            print(f"     0x{a:08X}..0x{b:08X}  ({(b - a) // 16 + 1} fn)")
        print()


if __name__ == "__main__":
    main()
