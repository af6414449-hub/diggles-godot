# -*- coding: utf-8 -*-
"""Проверка формата .pmp по спецификации из exe (FUN_005992b0 / FUN_00596550).

Структура файла (ридер exe FUN_005992b0_005992b0.c:72-103):
    u32 width
    u32 height
    u8  flags[width*height]         # 7 бит — тип/материал (0..5), бит 7 — флаг «border»
    u32 cellblk[width*height]       # per-cell dword -> block+0x00
    u32 tail_count
    u16 tail[tail_count]            # RLE: run = word>>2 (0 => 16384), value = word & 3
    u8  tailbytes[width*height]     # -> block+0x07

FUN_00596550: раскладывает РАСПАКОВАННЫЙ RLE-массив (1 байт на клетку)
в 8x8 суб-клеток блока: block+0x3c + subX + subY*8.
"""
import os
import struct
from collections import Counter

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\Templates\pmp"
OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "pmp_format_probe.txt")

lines = []


def p(s=""):
    lines.append(str(s))


def analyze(path, verbose=False):
    data = open(path, "rb").read()
    w, h = struct.unpack_from("<II", data, 0)
    cells = w * h
    off = 8
    flags = data[off:off + cells]
    off += cells
    cellblk = struct.unpack_from("<%dI" % cells, data, off)
    off += 4 * cells
    tail_count = struct.unpack_from("<I", data, off)[0]
    off += 4
    tail = struct.unpack_from("<%dH" % tail_count, data, off)
    off += 2 * tail_count
    tailbytes = data[off:off + cells]
    rest = len(data) - off - cells

    # RLE-распаковка как в exe
    out = bytearray()
    runs = []
    for w16 in tail:
        run = w16 >> 2
        if run == 0:
            run = 0x4000
        val = w16 & 3
        runs.append((run, val))
        out += bytes([val]) * run

    p("=" * 76)
    p("FILE: %s" % os.path.basename(path))
    p("  size=%d  width=%d height=%d cells=%d" % (len(data), w, h, cells))
    p("  flags: distinct=%s" % (sorted(Counter(flags).items()),))
    p("  flags&0x7f distinct=%s" % (sorted(Counter(b & 0x7f for b in flags).items()),))
    p("  bit7 set: %d / %d" % (sum(1 for b in flags if b & 0x80), cells))
    p("  cellblk distinct=%d  sample=%s" % (len(set(cellblk)), cellblk[:8]))
    p("  tail_count=%d  total RLE bytes=%d  (cells=%d, delta=%+d)"
      % (tail_count, len(out), cells, len(out) - cells))
    p("  tailbytes distinct=%s" % (sorted(Counter(tailbytes).items()),))
    p("  leftover bytes after last section: %d" % rest)
    p("  RLE runs: %d, zero-run(0x4000) present: %s"
      % (len(runs), any(r == 0x4000 for r, v in runs)))
    p("  RLE value histogram: %s" % (sorted(Counter(v for r, v in runs).items()),))
    p("  RLE expanded histogram: %s" % (sorted(Counter(out).items()),))
    if verbose:
        # карта 8x8 суб-клеток первого блока
        p("  first 64 expanded bytes (block 0, sub-cell map):")
        for r in range(8):
            p("    " + " ".join("%d" % b for b in out[r * 8:r * 8 + 8]))
        p("  first 64 flags (block 0):")
        for r in range(8):
            p("    " + " ".join("%d" % b for b in flags[r * 8:r * 8 + 8]))
    p()
    return dict(w=w, h=h, cells=cells, tail_count=tail_count, rle_len=len(out),
                flags=flags, out=bytes(out), tailbytes=tailbytes)


def main():
    p("ПРОВЕРКА ФОРМАТА .pmp (спека из Diggles.exe)")
    p("=" * 76)
    p()
    names = sorted(n for n in os.listdir(GAME) if n.lower().endswith(".pmp"))
    p("всего .pmp: %d" % len(names))
    p()
    stats = []
    for n in names:
        try:
            s = analyze(os.path.join(GAME, n))
            stats.append((n, s))
        except Exception as e:
            p("!! %s: %s" % (n, e))
    p("=" * 76)
    p("СВОДКА")
    ok_rle = 0
    for n, s in stats:
        if s["rle_len"] == s["cells"]:
            ok_rle += 1
    p("файлов, где сумма RLE-прогонов == width*height: %d из %d" % (ok_rle, len(stats)))
    bad = [(n, s) for n, s in stats if s["rle_len"] != s["cells"]]
    p("несовпадения (первые 20):")
    for n, s in bad[:20]:
        p("   %-28s rle=%d cells=%d delta=%+d" % (n, s["rle_len"], s["cells"], s["rle_len"] - s["cells"]))
    p()
    # подробно на пещерных шаблонах
    for n in names:
        if n.startswith("hol_") or n.startswith("caves_"):
            analyze(os.path.join(GAME, n), verbose=True)

    with open(OUT, "w", encoding="utf-8") as f:
        f.write("\n".join(lines) + "\n")
    print("written:", OUT)


if __name__ == "__main__":
    main()
