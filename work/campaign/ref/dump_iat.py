#!/usr/bin/env python3
"""Dump the PE import address table (address -> dll!name).

All directory entries are RVAs; this script converts them consistently.
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, read_cstr  # noqa: E402


def main() -> int:
    path = Path(sys.argv[1])
    data = path.read_bytes()
    sections, image_base = parse_sections(data)

    def r2o(rva: int) -> int | None:
        for s in sections:
            if s["va"] <= rva < s["va"] + max(s["vsize"], s["raw_size"]):
                return s["raw_ptr"] + (rva - s["va"])
        return None

    pe = struct.unpack_from("<I", data, 0x3C)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    opt = pe + 24
    magic = struct.unpack_from("<H", data, opt)[0]
    ddoff = opt + (112 if magic == 0x20B else 96)
    imp_rva, _ = struct.unpack_from("<II", data, ddoff + 8)
    off = r2o(imp_rva)
    assert off is not None, "import directory unmapped"
    step = 8 if magic == 0x20B else 4
    while True:
        ilt, ts, fc, nm, fta = struct.unpack_from("<IIIII", data, off)
        if nm == 0 and ilt == 0 and fta == 0:
            break
        no = r2o(nm)
        dll = read_cstr(data, no) if no is not None else "?"
        t = r2o(ilt if ilt else fta)
        names = []
        while t is not None:
            try:
                v = struct.unpack_from("<Q" if magic == 0x20B else "<I", data, t)[0]
            except struct.error:
                break
            if v == 0:
                break
            if v & (1 << 63):
                names.append(f"#{v & 0xFFFF}")
            else:
                ho = r2o(v)
                names.append(read_cstr(data, ho + 2) if ho is not None else "?")
            t += step
        lo = image_base + fta
        print(f"{dll}: {len(names)} imports, IAT base 0x{lo:08X}")
        for k, nm2 in enumerate(names):
            print(f"   0x{lo + k * step:08X} {nm2}")
        off += 20
    return 0


if __name__ == "__main__":
    sys.exit(main())
