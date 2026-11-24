#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Dump PE import/export tables with names and thunks.

Usage:
  python pe_imports_exports.py <file.exe> [--only DLLNAME] [--exports]
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path


def u16(d: bytes, o: int) -> int:
    return struct.unpack_from("<H", d, o)[0]


def u32(d: bytes, o: int) -> int:
    return struct.unpack_from("<I", d, o)[0]


class PE:
    def __init__(self, path: str):
        self.data = Path(path).read_bytes()
        d = self.data
        self.pe = u32(d, 0x3C)
        opt = self.pe + 24
        self.magic = u16(d, opt)
        self.opt = opt
        self.nsec = u16(d, self.pe + 6)
        optsz = u16(d, self.pe + 20)
        sec_off = opt + optsz
        self.sections = []
        for i in range(self.nsec):
            b = sec_off + 40 * i
            name = d[b:b + 8].rstrip(b"\x00").decode("latin-1")
            vsize, va, rsize, ptr = struct.unpack_from("<IIII", d, b + 8)
            self.sections.append({"name": name, "va": va, "vsize": vsize,
                                  "raw_size": rsize, "raw_ptr": ptr})
        if self.magic == 0x10B:
            self.image_base = u32(d, opt + 28)
            self.dd = opt + 96
        else:
            self.image_base = struct.unpack_from("<Q", d, opt + 24)[0]
            self.dd = opt + 112

    def va_to_off(self, va: int) -> int | None:
        rva = va - self.image_base
        for s in self.sections:
            if s["va"] <= rva < s["va"] + max(s["vsize"], s["raw_size"]):
                return s["raw_ptr"] + (rva - s["va"])
        return None

    def rva_to_off(self, rva: int) -> int | None:
        for s in self.sections:
            if s["va"] <= rva < s["va"] + max(s["vsize"], s["raw_size"]):
                return s["raw_ptr"] + (rva - s["va"])
        return None

    def cstr(self, off: int) -> str:
        end = self.data.find(b"\x00", off)
        return self.data[off:end].decode("latin-1")

    def imports(self):
        d = self.data
        imp_rva = u32(d, self.dd + 8)
        off = self.rva_to_off(imp_rva)
        if off is None:
            return
        i = 0
        while True:
            base = off + i * 20
            oft = u32(d, base)          # original first thunk
            name_rva = u32(d, base + 12)
            ft = u32(d, base + 16)      # first thunk (IAT)
            if name_rva == 0:
                break
            dll = self.cstr(self.rva_to_off(name_rva))
            thunk_rva = oft or ft
            toff = self.rva_to_off(thunk_rva)
            iat_off = self.rva_to_off(ft)
            funcs = []
            j = 0
            while toff is not None:
                val = u32(d, toff + j * 4)
                if val == 0:
                    break
                if val & 0x80000000:
                    funcs.append((f"ordinal_{val & 0xFFFF}", ft + j * 4))
                else:
                    no = self.rva_to_off(val)
                    hint = u16(d, no) if no is not None else 0
                    nm = self.cstr(no + 2) if no is not None else "?"
                    funcs.append((nm, ft + j * 4))
                j += 1
            yield dll, funcs
            i += 1

    def exports(self):
        d = self.data
        exp_rva = u32(d, self.dd)
        off = self.rva_to_off(exp_rva)
        if off is None:
            return []
        nfun = u32(d, off + 20)
        nnames = u32(d, off + 24)
        afun = u32(d, off + 28)
        anames = u32(d, off + 32)
        aords = u32(d, off + 36)
        funoff = self.rva_to_off(afun)
        nameoff = self.rva_to_off(anames)
        ordoff = self.rva_to_off(aords)
        res = []
        for i in range(nnames):
            nrva = u32(d, nameoff + i * 4)
            noff = self.rva_to_off(nrva)
            name = self.cstr(noff) if noff is not None else "?"
            ordv = u16(d, ordoff + i * 2)
            frva = u32(d, funoff + ordv * 4)
            res.append((name, ordv, frva))
        return res


def main() -> int:
    path = sys.argv[1]
    only = None
    if "--only" in sys.argv:
        only = sys.argv[sys.argv.index("--only") + 1].lower()
    pe = PE(path)
    print(f"=== {path}")
    print(f"image_base 0x{pe.image_base:08X}")
    if "--exports" not in sys.argv:
        print("--- IMPORTS ---")
        for dll, funcs in pe.imports():
            if only and only not in dll.lower():
                continue
            print(f"[{dll}] {len(funcs)} imports")
            for nm, iat in funcs:
                print(f"    0x{pe.image_base + iat:08X}  {nm}")
    if "--exports" in sys.argv:
        print("--- EXPORTS ---")
        ex = pe.exports()
        print(f"total {len(ex)}")
        for nm, ordv, rva in sorted(ex, key=lambda t: t[2]):
            print(f"    ord={ordv:<4} RVA=0x{rva:08X} VA=0x{pe.image_base + rva:08X}  {nm}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
