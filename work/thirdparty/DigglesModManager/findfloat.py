"""Поиск float-констант в .rdata (кандидаты на нижнюю границу зума).

python findfloat.py [min] [max]
"""
import struct
import sys

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
EXE = GAME + r"\Diggles.exe"


def main():
    lo = float(sys.argv[1]) if len(sys.argv) > 1 else 0.01
    hi = float(sys.argv[2]) if len(sys.argv) > 2 else 0.6
    import pefile
    pe = pefile.PE(EXE)
    ib = pe.OPTIONAL_HEADER.ImageBase
    raw = open(EXE, "rb").read()
    sec = [s for s in pe.sections if s.Name.startswith(b".rdata")][0]
    base_va = ib + sec.VirtualAddress
    raw_off = sec.PointerToRawData
    size = sec.Misc_VirtualSize
    print(".rdata VA %08X raw %08X VS %08X" % (base_va, raw_off, size))

    # ищем ссылки из .text на найденные адреса (чтобы отсеять мусор)
    text = [s for s in pe.sections if s.Name.startswith(b".text")][0]
    t_off = text.PointerToRawData
    t_size = text.SizeOfRawData
    blob = raw[t_off:t_off + t_size]
    t_va = ib + text.VirtualAddress

    seen = {}
    for i in range(0, size - 4, 4):
        v = struct.unpack_from("<f", raw, raw_off + i)[0]
        if not (lo <= v <= hi) or v == 0.0:
            continue
        key = round(v, 6)
        va = base_va + i
        if key in seen:
            seen[key].append(va)
            continue
        # ссылка из .text: little-endian DWORD == va
        pat = struct.pack("<I", va)
        refs = []
        pos = 0
        while True:
            j = blob.find(pat, pos)
            if j < 0:
                break
            refs.append(t_va + j)
            pos = j + 1
        seen[key] = [va]
        seen.setdefault(("refs", key), refs)

    for key in sorted([k for k in seen if isinstance(k, float)]):
        vas = seen[key]
        refs = seen.get(("refs", key), [])
        print("%-12s VA %08X  ссылок из .text: %s" %
              (key, vas[0], ", ".join("%08X" % r for r in refs[:6]) or "-"))
    pe.close()


if __name__ == "__main__":
    main()
