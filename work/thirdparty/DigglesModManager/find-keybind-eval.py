#!/usr/bin/env python3
"""Find the keybind dispatcher: Tcl eval call sites that sit next to a
read of the keybind table (DAT_00772400 + 0x148 / +0x14c).

Parses the PE import table to get the IAT slot of the Tcl evaluation
functions, finds `call dword ptr [iat]` sites in .text and reports the ones
whose surrounding window touches the keybind table offsets.

Usage: python find-keybind-eval.py [exe] [out.asm]
"""
import sys
import struct

from capstone import Cs, CS_ARCH_X86, CS_MODE_32

EXE = sys.argv[1] if len(sys.argv) > 1 else (
    r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
)
OUT = sys.argv[2] if len(sys.argv) > 2 else "keybind-eval.asm"

IMAGE_BASE = 0x400000
GLOB = 0x00772400
WANTED = ("tcl_eval", "tcl_evalex", "tcl_evalobj", "tcl_evalscript")


def sections(data):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    off = pe + 24 + optsz
    res = []
    for i in range(nsec):
        o = off + 40 * i
        vsize, vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, o + 8)
        res.append((IMAGE_BASE + vaddr, vsize, rawptr, rawsize))
    return res


def rva_to_off(secs, rva):
    target = IMAGE_BASE + rva
    for va, vsize, rawptr, rawsize in secs:
        if va <= target < va + vsize:
            return rawptr + (target - va)
    return None


def imports(data, secs):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    magic = struct.unpack_from("<H", data, pe + 24)[0]
    dd = pe + 24 + (96 if magic == 0x10B else 112)
    imp_rva, imp_size = struct.unpack_from("<II", data, dd + 8)
    off = rva_to_off(secs, imp_rva)
    result = {}
    while True:
        ilt, ts, fc, name_rva, iat = struct.unpack_from("<IIIII", data, off)
        if ilt == 0 and name_rva == 0:
            break
        noff = rva_to_off(secs, name_rva)
        dll = data[noff:data.index(b"\x00", noff)].decode("ascii", "replace")
        thunk = ilt if ilt else iat
        toff = rva_to_off(secs, thunk)
        i = 0
        while True:
            val = struct.unpack_from("<I", data, toff + 4 * i)[0]
            if val == 0:
                break
            if val & 0x80000000:
                fn = "ordinal#%d" % (val & 0xFFFF)
            else:
                ho = rva_to_off(secs, val)
                fn = data[ho + 2:data.index(b"\x00", ho + 2)].decode("ascii", "replace")
            result[(dll.lower(), fn.lower())] = IMAGE_BASE + iat + 4 * i
            i += 1
        off += 20
    return result


def main():
    data = open(EXE, "rb").read()
    secs = sections(data)
    imp = imports(data, secs)
    evals = {k: v for k, v in imp.items() if any(w in k[1] for w in WANTED)}
    print("tcl eval imports:")
    for (dll, fn), addr in sorted(evals.items(), key=lambda kv: kv[1]):
        print("   %-12s %-20s IAT 0x%08X" % (dll, fn, addr))

    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.skipdata = True
    fh = open(OUT, "w", encoding="utf-8")
    for (dll, fn), addr in evals.items():
        pat = b"\xFF\x15" + struct.pack("<I", addr)
        i = 0
        while True:
            i = data.find(pat, i)
            if i < 0:
                break
            i += 1
            va = None
            for sva, vsize, rawptr, rawsize in secs:
                if rawptr <= i < rawptr + rawsize:
                    va = sva + (i - rawptr)
                    break
            if va is None:
                continue
            lo = max(0, i - 200)
            chunk = data[lo:i + 120]
            start_va = va - (i - lo)
            ins = list(md.disasm(chunk, start_va))
            txt = "\n".join("%08X %s %s" % (x.address, x.mnemonic, x.op_str) for x in ins)
            if "0x148" in txt or "0x14c" in txt:
                print("\n=== %s!%s call at VA 0x%08X (table access nearby) ===" % (dll, fn, va))
                fh.write("\n\n======== %s!%s call at VA 0x%08X ========\n" % (dll, fn, va))
                for x in ins:
                    mark = "   <<<" if x.address == va else ""
                    fh.write("0x%08X  %-8s %s%s\n" % (x.address, x.mnemonic, x.op_str, mark))
    fh.close()


if __name__ == "__main__":
    main()
