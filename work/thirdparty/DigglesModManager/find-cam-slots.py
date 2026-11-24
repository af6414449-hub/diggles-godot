#!/usr/bin/env python3
"""find-cam-slots.py — ищет записи в таблицу привязки камеры.

Таблица — глобальный массив вокруг 0x768340..0x768380 (обработчик camctrlmapping
обращается к 0x768354). Ищем инструкции вида
    mov dword ptr [0x7683xx], imm32      (C7 05 <addr> <imm32>)
и печатаем адрес+значение вместе с окружающим кодом.
"""
import struct
import sys

import capstone

EXE = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
LO, HI = 0x768300, 0x7683A0


def load(path):
    data = open(path, "rb").read()
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    opt = struct.unpack_from("<H", data, pe + 20)[0]
    base = struct.unpack_from("<I", data, pe + 24 + 28)[0]
    off = pe + 24 + opt
    secs = []
    for i in range(nsec):
        s = off + i * 40
        nm = data[s:s + 8].rstrip(b"\x00").decode("ascii", "replace")
        vs, va, rs, ro = struct.unpack_from("<IIII", data, s + 8)
        secs.append((nm, va, vs, ro, rs))
    return data, base, secs


def va2off(v, base, secs):
    rva = v - base
    for nm, va, vs, ro, rs in secs:
        if va <= rva < va + max(vs, rs):
            return ro + (rva - va)
    return None


def main():
    data, base, secs = load(EXE)
    text = next(s for s in secs if s[0] == ".text")
    _, tva, tvsize, troff, trsize = text
    blob = data[troff:troff + trsize]

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True

    print("=== mov dword ptr [0x7683xx], imm32 ===")
    i = 0
    while True:
        i = blob.find(b"\xc7\x05", i)
        if i < 0:
            break
        addr = struct.unpack_from("<I", blob, i + 2)[0]
        if LO <= addr <= HI:
            imm = struct.unpack_from("<I", blob, i + 6)[0]
            va = base + tva + i
            print(f"  {va:#010x}: mov dword ptr [{addr:#010x}], {imm:#x}  ({imm})")
        i += 1

    print()
    print("=== mov [0x7683xx], reg (записи из регистров) ===")
    i = 0
    seen = set()
    while True:
        i = blob.find(b"\x89", i)
        if i < 0:
            break
        # кодирование ModRM: mod=00, rm=101 (disp32) -> 8D
        if i + 1 < len(blob) and (blob[i + 1] & 0xC7) == 0x05:
            addr = struct.unpack_from("<I", blob, i + 2)[0]
            if LO <= addr <= HI:
                va = base + tva + i
                if va not in seen:
                    seen.add(va)
                    print(f"  {va:#010x}: mov [{addr:#010x}], reg   (modrm={blob[i+1]:#04x})")
        i += 1

    print()
    print("=== функции, пишущие в диапазон (первые 40 строк каждой) ===")
    for addr in sorted({0x768340, 0x768344, 0x768348, 0x76834c, 0x768350, 0x768354, 0x768358, 0x76835c}):
        pat = struct.pack("<I", addr)
        j = 0
        while True:
            j = blob.find(pat, j)
            if j < 0:
                break
            va = base + tva + j
            # печатаем окно инструкций вокруг
            o = va2off(va - 12, base, secs)
            print(f"--- ссылка на {addr:#010x} в {va:#010x} ---")
            for ins in md.disasm(data[o:o + 26], va - 12):
                print(f"    {ins.address:#010x}: {ins.mnemonic:8s} {ins.op_str}")
            j += 1
            break
    return 0


if __name__ == "__main__":
    sys.exit(main())
