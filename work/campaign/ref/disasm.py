#!/usr/bin/env python3
"""Disassemble Diggles.exe at a VA (or file offset) using capstone."""
from __future__ import annotations

import sys
from pathlib import Path

from capstone import Cs, CS_ARCH_X86, CS_MODE_32

sys.path.insert(0, str(Path(__file__).parent))
from pe_irandom import parse_sections, va_to_file_off  # noqa: E402


def main() -> int:
    path = Path(sys.argv[1])
    start = int(sys.argv[2], 0)
    count = int(sys.argv[3]) if len(sys.argv) > 3 else 60
    by_file = start > 0x400000 or (start < 0x10000 and start > 0)
    data = path.read_bytes()
    sections, image_base = parse_sections(data)
    if start >= 0x400000:
        off = va_to_file_off(start, sections, image_base)
        if off is None:
            raise SystemExit(f"cannot map va 0x{start:X}")
        va = start
    else:
        off = start
        va = image_base + sections[0]["va"] + (off - sections[0]["raw_ptr"])
    blob = data[off:off + 0x4000]
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    n = 0
    for ins in md.disasm(blob, va):
        raw = ins.bytes.hex()
        print(f"0x{ins.address:08X}: {raw:28s} {ins.mnemonic:8s} {ins.op_str}")
        n += 1
        if n >= count:
            break
    return 0


if __name__ == "__main__":
    sys.exit(main())
