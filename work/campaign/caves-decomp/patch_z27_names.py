#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Mark the technique-name readings as name-based interpretation (z27.md + report.md)."""
from __future__ import annotations

import io
from pathlib import Path

ZONE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp")

OLD = ("4. **Техники рельефа и жидкостей в exe:** `scape_fow` (рельеф с туманом войны),")
NEW = ("4. **Техники рельефа и жидкостей в exe** (чтение имён — по названиям, а не по коду;\n"
       "   `scape` = рельеф, `fow` = туман войны, `water/lava/sulfur` = жидкости,\n"
       "   `mt` — вероятно «multi texture»): `scape_fow` (рельеф с туманом войны),")

for name in ("z27.md", "report.md"):
    p = ZONE / name
    txt = p.read_text(encoding="utf-8")
    n = txt.count(OLD)
    if n != 1:
        raise SystemExit(f"FAIL {name}: {n} occurrences")
    txt = txt.replace(OLD, NEW, 1)
    with io.open(p, "w", encoding="utf-8", newline="\n") as f:
        f.write(txt)
    print(f"{name}: patched, {len(txt.encode('utf-8'))} bytes")
