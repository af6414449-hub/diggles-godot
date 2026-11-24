# -*- coding: utf-8 -*-
"""Восстановление содержимого z24.md (разделы З24.1–З24.4) из снимков сессии.

Ищет в JSONL-снимках вызовы инструмента write/edit с содержимым, относящимся к z24.md,
и сохраняет найденные куски в z24_recovered_head.md.
"""
from __future__ import annotations

import io
import json
import os
import re

SNAP = (r"C:\Users\frant\.minimax\v2\sessions\2026\11\21"
        r"\02-31-32-014-session_bXZzX2RlOTBmNGZhMWYxYTQ1ZjY5Mzc2NjQ0OWZmMTllMjgz\snapshots")
HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, "z24_recovered_head.md")


def walk(node, path=()):
    """Рекурсивный обход JSON с выдачей (путь, строковое значение)."""
    if isinstance(node, dict):
        for k, v in node.items():
            yield from walk(v, path + (k,))
    elif isinstance(node, list):
        for i, v in enumerate(node):
            yield from walk(v, path + (i,))
    elif isinstance(node, str):
        yield path, node


def main() -> int:
    files = sorted(f for f in os.listdir(SNAP) if f.endswith(".jsonl"))
    hits = []
    for fn in files:
        p = os.path.join(SNAP, fn)
        print("сканирую", fn, os.path.getsize(p))
        with io.open(p, encoding="utf-8", errors="replace") as f:
            for lineno, line in enumerate(f, 1):
                if "z24" not in line:
                    continue
                try:
                    obj = json.loads(line)
                except Exception:
                    continue
                for path, s in walk(obj):
                    if len(s) < 400:
                        continue
                    if "З24.1" not in s:
                        continue
                    # ищем самый длинный текст, начинающийся с заголовка/преамбулы
                    hits.append((fn, lineno, path, s))

    print("кандидатов:", len(hits))
    best = None
    for fn, lineno, path, s in hits:
        print("  %s:%d %s len=%d" % (fn, lineno, "/".join(str(x) for x in path), len(s)))
        if best is None or len(s) > len(best[3]):
            best = (fn, lineno, path, s)

    if not best:
        print("ничего не найдено")
        return 1

    fn, lineno, path, s = best
    # содержимое может быть JSON-экранированным внутри args
    try:
        obj = json.loads(s)
        if isinstance(obj, str) and "З24.1" in obj:
            s = obj
    except Exception:
        pass

    io.open(OUT, "w", encoding="utf-8", newline="\n").write(s)
    print("записан", OUT, len(s.encode("utf-8")), "байт; источник:", fn, lineno, "/".join(str(x) for x in path))
    for m in re.finditer(r"^## .*$", s, re.M):
        print("   ", m.group(0))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
