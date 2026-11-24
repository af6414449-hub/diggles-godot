# -*- coding: utf-8 -*-
"""Свести части З24 в единый z24.md.

Порядок разделов задаётся списком PARTS. Каждая часть — файл в своей зоне.
Скрипт идемпотентен: если в целевом файле уже есть такой заголовок — часть не дублируется.
"""
from __future__ import annotations

import io
import os

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.join(HERE, "z24.md")

# (заголовок раздела, файл-источник)
PARTS = [
    ("## З24.1", "z24.md"),
    ("## З24.2", "z24.md"),
    ("## З24.3", "z24.md"),
    ("## З24.4", "z24.md"),
    ("## З24.5", "z24.md"),
    ("## З24.6", "z24.md"),
    ("## З24.7", "z24_9.md"),
    ("## З24.9", "z24_9.md"),
    ("## З24.10", "z24_10.md"),
    ("## З24.11", "z24_11.md"),
    ("## З24.12", "z24_12.md"),
]

HEAD = """# З24 — Проход 2026-11-22: rx/ry, зоны пещер, cave*.tga, is_dig_marked, LG, .pmp, текстуры рельефа, камера

*(черновик; в `report.md` пока не влит — по указанию пользователя отчёты в сессию «Main Chat»
приостановлены, но вливание в `report.md` выполняется)*

"""

SEP = "\n\n---\n\n"


def split_parts(text: str):
    """Разрезает текст на (заголовок, тело) по строкам '## '."""
    out = []
    cur_head = None
    cur_lines = []
    for line in text.splitlines():
        if line.startswith("## "):
            if cur_head is not None:
                out.append((cur_head, "\n".join(cur_lines).strip("\n")))
            cur_head = line
            cur_lines = []
        else:
            if cur_head is not None:
                cur_lines.append(line)
    if cur_head is not None:
        out.append((cur_head, "\n".join(cur_lines).strip("\n")))
    return out


def main() -> int:
    target_text = ""
    if os.path.exists(TARGET):
        target_text = io.open(TARGET, encoding="utf-8").read()

    # собираем источники
    sources = {}
    for head, fname in PARTS:
        if fname == "z24.md":
            continue
        p = os.path.join(HERE, fname)
        if not os.path.exists(p):
            print("нет файла:", fname)
            continue
        sources[fname] = split_parts(io.open(p, encoding="utf-8").read())

    # существующие части z24.md
    existing = {h: b for h, b in split_parts(target_text)}

    merged = []
    for head, fname in PARTS:
        if fname == "z24.md":
            if head in existing:
                merged.append((head, existing[head]))
            else:
                print("НЕТ в z24.md:", head)
            continue
        found = None
        for h, b in sources.get(fname, []):
            if h.startswith(head):
                found = (h, b)
                break
        if found is None:
            print("НЕТ в", fname, ":", head)
            continue
        merged.append(found)

    # склейка
    pieces = [HEAD]
    for head, body in merged:
        pieces.append(head + "\n\n" + body.strip("\n"))
    out = "\n\n---\n\n".join(pieces) + "\n"

    io.open(TARGET, "w", encoding="utf-8", newline="\n").write(out)

    txt = io.open(TARGET, encoding="utf-8").read()
    print("z24.md: %d байт, %d символов, разделов: %d, U+FFFD: %d"
          % (len(txt.encode("utf-8")), len(txt), len(merged), txt.count("\ufffd")))
    for h, _ in merged:
        print("  ", h)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
