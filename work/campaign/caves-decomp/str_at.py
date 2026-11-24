# -*- coding: utf-8 -*-
"""Извлечение ASCII-строк из Diggles.exe по виртуальному адресу (VA).

Использует pe_irandom.parse_sections / va_to_file_off из work/campaign/ref.
Пример:
    python str_at.py 0x72a898 0x72a8a0
    python str_at.py --scan 0x72a800 0x72a900     # все строки в диапазоне
"""
from __future__ import annotations

import io
import sys
from pathlib import Path

REF = Path(__file__).resolve().parents[1] / "ref"
sys.path.insert(0, str(REF))
from pe_irandom import parse_sections, va_to_file_off, file_off_to_va  # noqa: E402

EXE = Path(r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\Diggles.exe")


def cstr(data: bytes, off: int, limit: int = 200) -> str:
    end = data.find(b"\x00", off, off + limit)
    if end < 0:
        end = off + limit
    return data[off:end].decode("latin-1")


def main() -> int:
    data = EXE.read_bytes()
    sections, base = parse_sections(data)
    args = sys.argv[1:]
    if args and args[0] == "--scan":
        lo, hi = int(args[1], 0), int(args[2], 0)
        off = va_to_file_off(lo, sections, base)
        end = va_to_file_off(hi, sections, base)
        i = off
        while i < end:
            j = i
            while j < end and 32 <= data[j] < 127:
                j += 1
            if j - i >= 2:
                print("0x%08X %r" % (file_off_to_va(i, sections, base), data[i:j].decode("latin-1")))
                i = j
            else:
                i += 1
        return 0
    for a in args:
        va = int(a, 0)
        off = va_to_file_off(va, sections, base)
        if off is None:
            print("0x%08X -> cannot map" % va)
            continue
        print("0x%08X %r" % (va, cstr(data, off)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
