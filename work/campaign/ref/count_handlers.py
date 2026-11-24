#!/usr/bin/env python3
"""Считает покрытие: зарегистрированные обработчики команд в порте."""
from pathlib import Path
import re

ROOT = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles")

pat = re.compile(r"\.register\(\s*[\"']([^\"']+)[\"']")
regs = set()
for f in (ROOT / "godot").rglob("*.gd"):
    t = f.read_text(encoding="utf-8", errors="ignore")
    regs |= set(pat.findall(t))

print("зарегистрированных обработчиков команд в порте:", len(regs))
print(sorted(regs))
