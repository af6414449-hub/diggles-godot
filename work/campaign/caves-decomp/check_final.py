#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Final integrity check of report.md / z24.md / z25.md / z26.md."""
from __future__ import annotations

import re
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")
FILES = ["report.md", "z24.md", "z25.md", "z26.md", "coverage.md", "next_targets.md"]

for name in FILES:
    p = ZONE / name
    if not p.exists():
        print(f"{name}: MISSING")
        continue
    raw = p.read_bytes()
    txt = raw.decode("utf-8", errors="replace")
    bad = txt.count("\ufffd")
    heads = re.findall(r"^## (.+)$", txt, flags=re.M)
    print(f"{name}: {len(raw)} B / {len(txt)} chars / lines={txt.count(chr(10))} / "
          f"U+FFFD={bad} / h2={len(heads)}")
    if name == "report.md":
        print(f"   first h2: {heads[0][:80]}")
        print(f"   last  h2: {heads[-1][:80]}")
        print(f"   З2x: {[h[:60] for h in heads if h.startswith(('З24', 'З25', 'З26'))]}")
        # duplicate headings?
        dup = {h for h in heads if heads.count(h) > 1}
        if dup:
            print(f"   DUPLICATE h2: {sorted(dup)}")
        # doc table sanity
        for line in txt.splitlines()[:40]:
            if "caves-decomp/z" in line:
                print("   doc row:", line[:110])
