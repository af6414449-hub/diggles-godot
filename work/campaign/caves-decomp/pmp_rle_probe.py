"""Проверка RLE-секции caves_*.pmp: слова, периодичность, совпадение между файлами."""
import os
import struct
import sys
from collections import Counter

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"


def parse_pmp(path):
    d = open(path, "rb").read()
    W, H = struct.unpack_from("<ii", d, 0)
    o = 8
    n = W * H
    mat = d[o:o + n]; o += n
    blocks = struct.unpack_from(f"<{n}i", d, o); o += 4 * n
    cnt = struct.unpack_from("<i", d, o)[0]; o += 4
    words = struct.unpack_from(f"<{cnt}H", d, o); o += 2 * cnt
    tail = d[o:o + n]
    out = bytearray()
    for v in words:
        ln = v >> 2
        if ln == 0:
            ln = 0x4000
        out.extend(bytes([v & 3]) * ln)
    return W, H, mat, blocks, words, bytes(out), tail


T = os.path.join(GAME, "Templates", "pmp")
data = {}
for name in ("caves_1.pmp", "caves_2.pmp", "caves_3.pmp", "caves_4.pmp"):
    p = os.path.join(T, name)
    if not os.path.exists(p):
        continue
    W, H, mat, blocks, words, dec, tail = parse_pmp(p)
    data[name] = (W, H, words, dec, tail)
    print(f"\n=== {name} {W}x{H} ===")
    print(f"  RLE-слов: {len(words)}, декодировано {len(dec)} байт (нужно {64*W*H})")
    print(f"  первые 24 слова: {[hex(w) for w in words[:24]]}")
    print(f"  распределение (len,val): {Counter((w >> 2 or 0x4000, w & 3) for w in words).most_common(12)}")
    print(f"  последние 8 слов: {[hex(w) for w in words[-8:]]}")
    print(f"  extra-секция (последние {W*H} байт): {sorted(Counter(tail).items())}")

if len(data) >= 2:
    names = list(data)
    for i in range(len(names)):
        for j in range(i + 1, len(names)):
            a, b = names[i], names[j]
            wa, da = data[a][2], data[a][3]
            wb, db = data[b][2], data[b][3]
            print(f"\n  {a} vs {b}: слова одинаковы={wa == wb}, "
                  f"декодировано одинаково={da == db}, "
                  f"общая длина слов min={min(len(wa), len(wb))}")

# периодичность карты caves_1
if "caves_1.pmp" in data:
    W, H, words, dec, tail = data["caves_1.pmp"]
    print("\n== периодичность caves_1 (по колонкам) ==")
    for period in (8, 16, 24, 32, 48):
        same = 0
        total = 0
        for r in range(H * 8):
            for c in range(W * 8 - period):
                a = dec[r * W * 8 + c]
                b = dec[r * W * 8 + c + period]
                total += 1
                if a == b:
                    same += 1
        print(f"  период {period}: совпадение {100.0*same/total:.1f}%")
