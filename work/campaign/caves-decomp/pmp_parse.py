#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Разбор формата .pmp по коду FUN_005992b0 (0x5992b0).

Структура файла (в порядке чтения FUN_005992b0.c:72-103):
  int32  w            (local_18)
  int32  h            (local_30)
  uint8  shape[w*h]   (_DstBuf)     — коды материала 0..5, бит 7 = флаг
  uint32 block[w*h]   (_DstBuf_00)  — ID блока -> cell+0x00
  uint32 rle_count    (local_60)
  uint16 rle[count]   (_DstBuf_02)  — (значение&3) в младших 2 битах,
                                        длина = code>>2 (0 -> 0x4000)
  uint8  extra[w*h]   (_DstBuf_01)  -> cell+0x07
"""
import os
import struct
import sys
from collections import Counter

G = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data"
PMP = os.path.join(G, "Templates", "pmp")


def parse(path):
    with open(path, "rb") as f:
        data = f.read()
    off = 0
    (w,) = struct.unpack_from("<i", data, off); off += 4
    (h,) = struct.unpack_from("<i", data, off); off += 4
    n = w * h
    shape = data[off:off + n]; off += n
    block = list(struct.unpack_from("<%di" % n, data, off)) if n else []; off += 4 * n
    (cnt,) = struct.unpack_from("<i", data, off); off += 4
    rle = list(struct.unpack_from("<%dH" % cnt, data, off)) if cnt else []; off += 2 * cnt
    extra = data[off:off + n]; off += n
    tail = data[off:]
    # декодирование RLE
    heights = bytearray()
    for code in rle:
        ln = code >> 2
        if ln == 0:
            ln = 0x4000
        heights.extend(bytes([code & 3]) * ln)
    return dict(w=w, h=h, shape=shape, block=block, rle=rle, extra=extra,
                heights=heights, tail=tail, size=len(data))


def grid8(b, w, h):
    """Печать сетки 8x8 значений по строкам (w*8 x h*8)."""
    sw, sh = w * 8, h * 8
    rows = []
    for r in range(sh):
        rows.append("".join(str(b[r * sw + c]) for c in range(sw)))
    return rows


def main():
    names = sys.argv[1:] or ["leer1x1.pmp", "gng_022.pmp", "gng_001.pmp"]
    for name in names:
        p = os.path.join(PMP, name)
        if not os.path.exists(p):
            print("!! нет файла", p); continue
        d = parse(p)
        print("=" * 72)
        print("%s  size=%d  w=%d h=%d  rle_count=%d  tail=%d" %
              (name, d["size"], d["w"], d["h"], len(d["rle"]), len(d["tail"])))
        print("  shape :", " ".join("%02x" % b for b in d["shape"][:64]))
        print("  block :", " ".join(str(b) for b in d["block"][:64]))
        print("  extra :", " ".join("%02x" % b for b in d["extra"][:64]))
        print("  rle   :", " ".join("%04x" % c for c in d["rle"][:64]))
        print("  heights decoded len = %d (ожидается %d = 64*w*h)" %
              (len(d["heights"]), 64 * d["w"] * d["h"]))
        print("  heights values:", Counter(d["heights"]).most_common(8))
        if d["w"] and d["h"] and len(d["heights"]) >= 64 * d["w"] * d["h"]:
            rows = grid8(d["heights"], d["w"], d["h"])
            for i, r in enumerate(rows[:16]):
                print("   h[%2d] %s" % (i, r))
            if len(rows) > 16:
                print("   ... ещё %d строк" % (len(rows) - 16))


if __name__ == "__main__":
    main()
