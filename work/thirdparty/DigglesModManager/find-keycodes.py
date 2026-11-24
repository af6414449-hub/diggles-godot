#!/usr/bin/env python3
"""find-keycodes.py — ищет в .text сравнения с непосредственными значениями,
похожими на внутренние коды клавиш (диапазон 0x260..0x2C0), и печатает их.

Внутренние коды клавиш движка (VK/скан-коды, приведённые порт-слоем
DigglesPort.dll через GetVKScanCode) сравниваются как обычные константы,
поэтому их видно в дизассемблировании.
"""
import struct
import sys

EXE = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
LO, HI = 0x260, 0x2C0


def main():
    d = open(EXE, "rb").read()
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    nsec = struct.unpack_from("<H", d, pe + 6)[0]
    opt = struct.unpack_from("<H", d, pe + 20)[0]
    base = struct.unpack_from("<I", d, pe + 24 + 28)[0]
    off = pe + 24 + opt
    secs = []
    for i in range(nsec):
        s = off + i * 40
        nm = d[s:s + 8].rstrip(b"\x00").decode("ascii", "replace")
        vs, va, rs, ro = struct.unpack_from("<IIII", d, s + 8)
        secs.append((nm, va, vs, ro, rs))
    text = next(s for s in secs if s[0] == ".text")
    blob = d[text[3]:text[3] + text[4]]

    hits = {}
    n = len(blob)
    for i in range(n - 6):
        imm = None
        if blob[i] == 0x3D:                                   # cmp eax, imm32
            imm = struct.unpack_from("<I", blob, i + 1)[0]
        elif blob[i] == 0x81 and 0xF8 <= blob[i + 1] <= 0xFF:  # cmp r32, imm32
            imm = struct.unpack_from("<I", blob, i + 2)[0]
        elif blob[i] == 0x3D + 1:                             # заглушка
            pass
        if imm is not None and LO <= imm <= HI:
            hits.setdefault(imm, []).append(base + text[1] + i)

    for imm in sorted(hits):
        v = hits[imm]
        print(f"  imm {imm:#x} ({imm}): {len(v)} ссылок  {[hex(x) for x in v[:8]]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
