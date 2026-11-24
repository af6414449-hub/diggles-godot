# -*- coding: utf-8 -*-
"""Печать выбранных кусков отчёта (UTF-8-safe)."""
import io
import os
import sys

BASE = os.path.dirname(os.path.abspath(__file__))

name = sys.argv[1]
marker = sys.argv[2] if len(sys.argv) > 2 else None
count = int(sys.argv[3]) if len(sys.argv) > 3 else 80

p = os.path.join(BASE, name)
with io.open(p, encoding="utf-8") as f:
    lines = f.read().splitlines()

if marker:
    start = 0
    for i, l in enumerate(lines):
        if marker in l:
            start = i
            break
    lines = lines[start:]

for l in lines[:count]:
    print(l)
