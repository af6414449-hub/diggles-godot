# -*- coding: utf-8 -*-
"""Склейка кусков отчёта в один файл (без перекодировки, побайтно)."""
import os
import sys

BASE = os.path.dirname(os.path.abspath(__file__))

TARGET = os.path.join(BASE, "z24.md")
PARTS = [os.path.join(BASE, "z24_5.md")]

with open(TARGET, "rb") as f:
    data = f.read()
for p in PARTS:
    with open(p, "rb") as f:
        chunk = f.read()
    if not data.endswith(b"\n"):
        data += b"\n"
    data += chunk

with open(TARGET, "wb") as f:
    f.write(data)

txt = data.decode("utf-8")
print("z24.md:", len(data), "bytes,", len(txt), "chars, U+FFFD =", txt.count("\ufffd"))
