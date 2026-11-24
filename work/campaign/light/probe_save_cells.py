#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Which byte of the saved cell record is the native light of the cell?

The save holds a 512x640 map grid of 53 byte records (export_campaign_ground_mask.py).
Byte 27 is the layer-2 byte, byte 28 is the ground state/material. The engine keeps
the light of a cell in cell+0x07 (C+7) and recomputes it from the height grid
(FUN_005906a0, value 0..20). If the save keeps that byte, the port can import the
native light of the whole map instead of inventing one.
"""
import collections
import gzip
import pathlib

SAVE = pathlib.Path(r"C:\Program Files (x86)\Steam\steamapps\common"
                     r"\Diggles The Myth of Fenris\data\Gamesave\save_15-11-2026.sav")
GRID_OFFSET = 0xC2
RECORD_SIZE = 53
WIDTH = 512
HEIGHT = 640
CELLS = WIDTH * HEIGHT


def main():
    body = gzip.decompress(SAVE.read_bytes())
    print("body %d bytes" % len(body))
    grid = body[GRID_OFFSET:GRID_OFFSET + CELLS * RECORD_SIZE]
    print("grid %d bytes" % len(grid))

    states = [grid[index * RECORD_SIZE + 28] for index in range(CELLS)]
    print("state histogram (byte 28):",
          [(hex(value), count) for value, count in
           sorted(collections.Counter(states).items())[:8]])

    surface = [index for index in range(CELLS) if states[index] == 0x00]
    rock = [index for index in range(CELLS) if states[index] == 0x02]
    print("air cells %d, free rock cells %d" % (len(surface), len(rock)))

    print()
    print("slot  histogram (top 8)                       air-state mean / rock-state mean")
    for slot in range(RECORD_SIZE):
        values = [grid[index * RECORD_SIZE + slot] for index in range(CELLS)]
        counter = collections.Counter(values)
        top = counter.most_common(8)
        air_mean = sum(values[index] for index in surface) / max(1, len(surface))
        rock_mean = sum(values[index] for index in rock) / max(1, len(rock))
        print("%4d  %-40s %8.2f / %8.2f" % (
            slot,
            " ".join("%d:%d" % (value, count) for value, count in top),
            air_mean, rock_mean))

    # The bytes of one record of three cells: air, free rock, template rock.
    print()
    print("raw records:")
    shown = 0
    for index in range(CELLS):
        if states[index] == 0x02 and shown < 2:
            record = grid[index * RECORD_SIZE:(index + 1) * RECORD_SIZE]
            print("  x=%3d y=%3d state=0x%02X %s" % (
                index % WIDTH, index // WIDTH, states[index], list(record)))
            shown += 1
    for index in range(CELLS):
        if states[index] == 0x00:
            record = grid[index * RECORD_SIZE:(index + 1) * RECORD_SIZE]
            print("  x=%3d y=%3d state=0x%02X %s" % (
                index % WIDTH, index // WIDTH, states[index], list(record)))
            break


if __name__ == "__main__":
    main()
