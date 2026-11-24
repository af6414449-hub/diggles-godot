# -*- coding: utf-8 -*-
"""Пересборка z24.md: head (З24.1–З24.4) + z24_5.md + z24_6.md, без дублей."""
import io
import os

BASE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.join(BASE, "z24.md")

MARK = "\n---\n\n## З24.5"

with io.open(TARGET, encoding="utf-8") as f:
    cur = f.read()

i = cur.find(MARK)
if i == -1:
    head = cur
else:
    head = cur[:i]

parts = [head]
for name in ("z24_5.md", "z24_6.md"):
    p = os.path.join(BASE, name)
    with io.open(p, encoding="utf-8") as f:
        parts.append(f.read())

out = "\n".join(parts)
with io.open(TARGET, "w", encoding="utf-8", newline="") as f:
    f.write(out)

print("z24.md:", len(out.encode("utf-8")), "bytes,", len(out), "chars, U+FFFD =", out.count("\ufffd"))
for line in out.splitlines():
    if line.startswith("## З24"):
        print("  ", line)
