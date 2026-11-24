# -*- coding: utf-8 -*-
"""Пересборка z24.md из восстановленных частей (без дублей, с проверками).

Источники:
  z24_head.md        — восстановленная «голова» З24.1–З24.4 (из снимка сессии)
  z24_5.md           — З24.5
  z24_6.md           — З24.6
  z24_9.md           — З24.7 + З24.9
  z24_10.md          — З24.10
  z24_11.md          — З24.11
  z24_12.md          — З24.12 (+ З24.13 внутри)
"""
from __future__ import annotations

import io
import os
import re

BASE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.join(BASE, "z24.md")
BACKUP = os.path.join(BASE, "z24_prev_merge.md")

FILES = ["z24_head.md", "z24_5.md", "z24_6.md", "z24_7.md", "z24_8.md", "z24_9b.md",
         "z24_10.md", "z24_11.md", "z24_12.md"]

EXPECTED = [
    "З24.1", "З24.2", "З24.3", "З24.4", "З24.5", "З24.6",
    "З24.7", "З24.8", "З24.9", "З24.10", "З24.11", "З24.12",
]


def main() -> int:
    chunks = []
    for name in FILES:
        p = os.path.join(BASE, name)
        if not os.path.exists(p):
            print("НЕТ ФАЙЛА:", name)
            return 1
        txt = io.open(p, encoding="utf-8").read()
        chunks.append(txt.strip("\n"))
        print("%-16s %7d Б  %6d симв." % (name, len(txt.encode("utf-8")), len(txt)))

    out = "\n\n---\n\n".join(chunks) + "\n"

    # проверки до записи
    heads = re.findall(r"^## (З24\.\d+)", out, re.M)
    dup = sorted({h for h in heads if heads.count(h) > 1})
    missing = [h for h in EXPECTED if h not in heads]
    if dup:
        print("ДУБЛИ РАЗДЕЛОВ:", dup)
        return 1
    if missing:
        print("ПРОПУЩЕНЫ РАЗДЕЛЫ:", missing)
        return 1
    if "\ufffd" in out:
        print("ЕСТЬ U+FFFD:", out.count("\ufffd"))
        return 1

    if os.path.exists(TARGET):
        with io.open(TARGET, "rb") as f:
            prev = f.read()
        with io.open(BACKUP, "wb") as f:
            f.write(prev)
        print("предыдущий z24.md сохранён в", os.path.basename(BACKUP))

    with io.open(TARGET, "w", encoding="utf-8", newline="\n") as f:
        f.write(out)

    print("ИТОГ z24.md: %d Б, %d симв., U+FFFD = %d"
          % (len(out.encode("utf-8")), len(out), out.count("\ufffd")))
    for h in re.findall(r"^## .*$", out, re.M):
        print("   ", h)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
