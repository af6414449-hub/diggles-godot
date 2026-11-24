#!/usr/bin/env python3
"""General PE reconnaissance for Diggles.exe.

Reports: PE kind, image base, linker version, sections (with entropy),
Rich header (compiler/linker ids), debug directory (PDB path, PDB GUID),
exports, and a quick look at the read-only string density.

Usage: python pe_recon.py <path-to-exe>
"""
from __future__ import annotations

import math
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off, read_cstr  # noqa: E402


def entropy(blob: bytes) -> float:
    if not blob:
        return 0.0
    counts = [0] * 256
    for b in blob:
        counts[b] += 1
    n = len(blob)
    ent = 0.0
    for c in counts:
        if c:
            p = c / n
            ent -= p * math.log2(p)
    return ent


def parse_rich(data: bytes) -> list[tuple[int, int]]:
    """Return [(comp_id, count)] decoded from the Rich header, or []."""
    key_pos = data.find(b"Rich")
    if key_pos < 0:
        return []
    key = struct.unpack_from("<I", data, key_pos + 4)[0]
    # find DanS marker (decrypted)
    dans = None
    for i in range(0, key_pos, 4):
        val = struct.unpack_from("<I", data, i)[0] ^ key
        if val == 0x536E6144:  # "DanS"
            dans = i
            break
    if dans is None:
        return []
    best: list[tuple[int, int]] = []
    # The entry array starts after "DanS" + 3 padding dwords; try every
    # 4-byte alignment and keep the parse that yields plausible values.
    for align in range(0, 32, 4):
        out = []
        i = dans + 16 + align
        while i + 8 <= key_pos:
            comp_id, count = struct.unpack_from("<II", data, i)
            i += 8
            prod = comp_id >> 16
            if prod > 200 or count > 1_000_000:
                out = []
                break
            out.append((comp_id, count))
        if len(out) > len(best):
            best = out
    return best


RICH_PRODID = {
    0: "Unmarked", 1: "Import0", 2: "Linker", 3: "Cvtres", 4: "Linker", 5: "Utc1500_C",
    6: "Utc1500_CPP", 7: "Utc1600_C", 8: "Utc1600_CPP", 9: "Utc1700_C", 10: "Utc1700_CPP",
    11: "Utc1800_C", 12: "Utc1800_CPP", 13: "Utc1900_C", 14: "Utc1900_CPP",
    19: "Utc1200_C", 20: "Utc1200_CPP", 21: "Utc1400_C", 22: "Utc1400_CPP",
    25: "Utc1400_C", 28: "Utc1400_CPP", 40: "AliasObj", 83: "Utc1310_C", 84: "Utc1310_CPP",
    93: "Utc1400_C", 94: "Utc1400_CPP", 95: "Linker", 100: "Utc1600_C", 101: "Utc1600_CPP",
    102: "Utc1600_C", 103: "Utc1600_CPP", 104: "Utc1600_C", 105: "Utc1600_CPP",
    128: "Cvtres", 130: "Export", 131: "Utc1310_C", 132: "Utc1310_CPP",
    147: "Linker", 148: "Cvtres", 154: "Utc1500_C", 157: "Masm1010", 158: "Masm1010",
    170: "Linker", 171: "Export", 175: "Utc1600_C", 178: "Utc1600_CPP",
}


def rich_name(comp_id: int) -> str:
    prod = comp_id >> 16
    build = comp_id & 0xFFFF
    base = RICH_PRODID.get(prod, f"ProdId{prod}")
    return f"{base}.{build}"


def debug_directory(data: bytes, sections, image_base) -> None:
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    opt = pe + 24
    magic = struct.unpack_from("<H", data, opt)[0]
    ddoff = opt + (112 if magic == 0x20B else 96)
    dbg_rva, dbg_size = struct.unpack_from("<II", data, ddoff + 48)
    print(f"\n-- debug directory: rva=0x{dbg_rva:X} size={dbg_size}")
    if not dbg_rva:
        print("   (none)")
        return
    off = va_to_file_off(image_base + dbg_rva, sections, image_base)
    if off is None:
        print("   (unmapped)")
        return
    kinds = {0: "UNKNOWN", 1: "COFF", 2: "CODEVIEW", 3: "FPO", 4: "MISC",
             5: "EXCEPTION", 6: "FIXUP", 9: "BORLAND", 10: "BBT", 11: "CLSID",
             12: "VC_FEATURE", 13: "POGO", 14: "ILTCG", 16: "REPRO"}
    n = dbg_size // 28
    for i in range(n):
        b = off + 28 * i
        chars, ts, maj, minor, dtype, size, addr_rva, ptr = struct.unpack_from(
            "<IIHHIBII", data, b)
        print(f"   [{i}] type={kinds.get(dtype, dtype)} size={size} ptr=0x{ptr:X}")
        if dtype == 2:  # CODEVIEW
            cv = data[ptr:ptr + size]
            sig = cv[:4]
            print(f"       signature={sig!r}")
            if sig == b"RSDS":
                guid = cv[4:20]
                age = struct.unpack_from("<I", cv, 20)[0]
                pdb = cv[24:].split(b"\x00")[0].decode("latin-1", "replace")
                g = guid.hex()
                print(f"       GUID={g[:8]}-{g[8:12]}-{g[12:16]}-{g[16:20]}-{g[20:32]} age={age}")
                print(f"       PDB={pdb}")
            elif sig == b"NB10":
                off2, ts2, age = struct.unpack_from("<III", cv, 4)
                pdb = cv[16:].split(b"\x00")[0].decode("latin-1", "replace")
                print(f"       age={age} PDB={pdb}")


def exports(data: bytes, sections, image_base) -> None:
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    opt = pe + 24
    magic = struct.unpack_from("<H", data, opt)[0]
    ddoff = opt + (112 if magic == 0x20B else 96)
    exp_rva, exp_size = struct.unpack_from("<II", data, ddoff)
    print(f"\n-- exports: rva=0x{exp_rva:X} size={exp_size}")
    if not exp_rva:
        print("   (none)")
        return
    off = va_to_file_off(image_base + exp_rva, sections, image_base)
    if off is None:
        print("   (unmapped)")
        return
    nfun, nnam = struct.unpack_from("<II", data, off + 20)
    addr_rva, names_rva, ords_rva = struct.unpack_from("<III", data, off + 28)
    print(f"   functions={nfun} names={nnam}")
    noff = va_to_file_off(image_base + names_rva, sections, image_base)
    out_lines = []
    for i in range(min(nnam, 400)):
        rva = struct.unpack_from("<I", data, noff + 4 * i)[0]
        so = va_to_file_off(image_base + rva, sections, image_base)
        nm = read_cstr(data, so) if so is not None else "?"
        out_lines.append(f"{i:4d} {nm}")
        print(f"   {i:4d} {nm}")
    if "--out" in sys.argv:
        p = Path(sys.argv[sys.argv.index("--out") + 1])
        p.write_text("\n".join(out_lines) + "\n", encoding="utf-8")
        print(f"   written: {p}")


def main() -> int:
    path = Path(sys.argv[1])
    data = path.read_bytes()
    sections, image_base = parse_sections(data)

    pe = struct.unpack_from("<I", data, 0x3C)[0]
    machine = struct.unpack_from("<H", data, pe + 4)[0]
    timestamp = struct.unpack_from("<I", data, pe + 8)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    chars = struct.unpack_from("<H", data, pe + 22)[0]
    opt = pe + 24
    magic = struct.unpack_from("<H", data, opt)[0]
    linker_maj, linker_min = data[opt + 2], data[opt + 3]
    entry_rva = struct.unpack_from("<I", data, opt + 16)[0]

    import datetime
    print(f"file        : {path.name} ({len(data)} bytes)")
    print(f"machine     : 0x{machine:04X} ({'i386' if machine == 0x14C else 'other'})")
    print(f"PE kind     : {'PE32+' if magic == 0x20B else 'PE32'}")
    print(f"image base  : 0x{image_base:08X}")
    print(f"entry point : 0x{image_base + entry_rva:08X}")
    print(f"linker      : {linker_maj}.{linker_min}")
    print(f"timestamp   : 0x{timestamp:08X} ({datetime.datetime.utcfromtimestamp(timestamp)} UTC)")
    print(f"characteristics: 0x{chars:04X}")

    print("\n-- sections --")
    for s in sections:
        blob = data[s["raw_ptr"]:s["raw_ptr"] + s["raw_size"]]
        print(f"  {s['name']:10s} va=0x{s['va']:06X} vsize=0x{s['vsize']:06X} "
              f"raw=0x{s['raw_ptr']:06X} rsize=0x{s['raw_size']:06X} "
              f"entropy={entropy(blob):.2f} "
              f"{'EXEC' if s['va'] and False else ''}")

    print("\n-- rich header --")
    rich = parse_rich(data)
    if not rich:
        print("   (absent — no compiler stamp)")
    for comp_id, count in rich:
        print(f"   {rich_name(comp_id):24s} x{count}")

    debug_directory(data, sections, image_base)
    exports(data, sections, image_base)

    # rough string density per section
    print("\n-- printable strings (len>=5) per section --")
    for s in sections:
        blob = data[s["raw_ptr"]:s["raw_ptr"] + s["raw_size"]]
        n = 0
        cur = 0
        for b in blob:
            if 32 <= b < 127:
                cur += 1
            else:
                if cur >= 5:
                    n += 1
                cur = 0
        print(f"  {s['name']:10s} {n}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
