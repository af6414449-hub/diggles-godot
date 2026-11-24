"""Разбор .reloc exe Diggles + память из дампа (есть ли пещера в образе).

python relocinfo.py
"""
import os
import struct
import sys

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
EXE = os.path.join(GAME, "Diggles.exe")


def parse_reloc(path):
    import pefile
    pe = pefile.PE(path)
    ib = pe.OPTIONAL_HEADER.ImageBase
    sec = None
    for s in pe.sections:
        if s.Name.startswith(b".reloc"):
            sec = s
    raw = open(path, "rb").read()
    off = sec.PointerToRawData
    end = off + sec.SizeOfRawData
    print(".reloc raw %08X..%08X (VA %08X, VS %08X)"
          % (off, end, ib + sec.VirtualAddress, sec.Misc_VirtualSize))
    print("first 32 bytes:", raw[off:off + 32].hex(" "))
    i = off
    types = {}
    entries = []
    nblocks = 0
    while i + 8 <= end:
        page_rva, block_size = struct.unpack_from("<II", raw, i)
        if block_size == 0:
            break
        if block_size < 8 or i + block_size > end:
            print("BAD block at %08X: rva %08X size %08X" % (i, page_rva, block_size))
            break
        n = (block_size - 8) // 2
        for k in range(n):
            e = struct.unpack_from("<H", raw, i + 8 + k * 2)[0]
            typ = e >> 12
            rva = page_rva + (e & 0xFFF)
            types[typ] = types.get(typ, 0) + 1
            entries.append((rva, typ))
        nblocks += 1
        i += block_size
    print("blocks:", nblocks, "entries:", len(entries), "types:", types)
    targets = {
        "zoom lower op (0x2B696C)": 0x2B696C,
        "zoom upper op (0x2B6977)": 0x2B6977,
        "render zoom op (0x052BFD)": 0x052BFD,
        "hook operand (0x2B6A76)": 0x2B6A76,
        "pan mulss (0x129611)": 0x129611,
        "cave (0x31493A)": 0x31493A,
    }
    for label, rva in targets.items():
        found = [(r, t) for r, t in entries if r == rva]
        print("  %-26s rva %08X -> %s" % (label, rva, found if found else "нет записи"))
    # все записи рядом с хуком
    near = [(r, t) for r, t in entries if 0x2B6A00 <= r <= 0x2B6A90]
    print("  записи рядом с хуком:", sorted(near))
    # записи рядом с операндами клампа зума (0x6B6968 / 0x6B6973)
    nearz = sorted((r, t) for r, t in entries if 0x2B6950 <= r <= 0x2B6990)
    print("  записи рядом с клампом зума:", nearz)
    pe.close()


def dump_memory(path):
    import struct as st
    d = open(path, "rb").read()
    n = st.unpack_from("<I", d, 8)[0]
    dir_rva = st.unpack_from("<I", d, 12)[0]
    streams = {}
    for i in range(n):
        o = dir_rva + i * 12
        stt, size, rva = st.unpack_from("<III", d, o)
        streams.setdefault(stt, []).append((size, rva))
    # ExceptionStream
    size, rva = streams[6][0]
    ctx_size = st.unpack_from("<I", d, rva + 160)[0]
    ctx_rva = st.unpack_from("<I", d, rva + 164)[0]
    print("context rva %08X size %d" % (ctx_rva, ctx_size))
    print("context raw[0:0x60]:", d[ctx_rva:ctx_rva + 0x60].hex(" "))
    # MemoryList
    if 5 in streams:
        size, rva = streams[5][0]
        cnt = st.unpack_from("<I", d, rva)[0]
        print("memory regions:", cnt)
        for i in range(cnt):
            o = rva + 4 + i * 16
            start = st.unpack_from("<Q", d, o)[0]
            sz = st.unpack_from("<I", d, o + 8)[0]
            r2 = st.unpack_from("<I", d, o + 12)[0]
            tag = ""
            if start <= 0x0124A93A < start + sz:
                tag = "  <== CAVE"
            if start <= 0x01246A7A < start + sz:
                tag += "  <== HOOK"
            print("   %012X size %08X rva %08X%s" % (start, sz, r2, tag))
            if tag:
                off = r2 + (0x0124A93A - start)
                print("      cave bytes:", d[off:off + 16].hex(" "))


if __name__ == "__main__":
    parse_reloc(EXE)
    if len(sys.argv) > 1:
        dump_memory(sys.argv[1])
