#!/usr/bin/env python3
"""findref.py — ищет в .text ссылки на VA (любой вид) и печатает содержащую функцию.

Использование:  python findref.py 0x00736155
"""
import struct
import sys

import pefile

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
IDX = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\ref\ghidra-out\index.tsv"

pe = pefile.PE(GAME + r"\Diggles.exe")
base = pe.OPTIONAL_HEADER.ImageBase
text = [s for s in pe.sections if s.Name.rstrip(b"\x00") == b".text"][0]
data = text.get_data()
textva = base + text.VirtualAddress

target = int(sys.argv[1], 16)
needle = struct.pack("<I", target)
hits = []
pos = 0
while True:
    k = data.find(needle, pos)
    if k < 0:
        break
    hits.append(textva + k)
    pos = k + 1

print("references to %#010x in .text:" % target)
for h in hits:
    print("  %#010x" % h)

funcs = []
for line in open(IDX, encoding="utf-8", errors="replace").read().splitlines()[1:]:
    p = line.split("\t")
    if len(p) < 3:
        continue
    try:
        entry = int(p[1], 16)
        size = int(p[2])
    except ValueError:
        continue
    funcs.append((entry, entry + size, p[0]))

print("\ncontaining functions:")
seen = set()
for h in hits:
    for a, b, name in funcs:
        if a <= h < b:
            if name in seen:
                break
            seen.add(name)
            print("  hit %#010x -> %s (%#010x..%#010x)" % (h, name, a, b))
            break
