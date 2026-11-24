#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""The outline of the free rock of the campaign map.

The original draws the rock of the map with the engine command
"sm_draw_stone -border" and "sm_draw_stone -funnel"
(data/Scripts/gameplay/Campaign.tcl:3-4). The command is C++ and its geometry is
not in the export of the chapter, so the port cannot rebuild it. The saved game
of the owner still holds the result of it: the map grid of the save keeps a
byte per cell that tells whether the cell carries rock of the map or not.

The layout of the save (verified against the file, see the report):

  - the file is gzip; the decompressed body starts with a 194 byte header;
  - at offset 0xC2 the body holds the map grid: 327680 records of 53 bytes,
    row major, x = index % 512, y = index // 512;
  - byte 28 of the record is the state of the ground of the cell:
      0x00 - the cell is empty: there was air there;
      0x02 - the cell carries the free rock of the map;
      0x80 / 0x83 - the cell carries the rock of a placed template.
  - byte 27 of the record is the byte of the second layer of the cell.

The tool writes the outline of the free rock of the map as a mask: white is
rock, black is air. The heights of the free rock are NOT in the save - the
engine regenerates them - so the mask carries the plan of the rock only.

Usage:
    python tools/export_campaign_ground_mask.py [--save PATH] [--output DIR]
"""
import argparse
import collections
import gzip
import json
import pathlib
import struct
import sys

from PIL import Image

ROOT = pathlib.Path(__file__).resolve().parent.parent
DEFAULT_SAVE = (r"C:\Program Files (x86)\Steam\steamapps\common"
                r"\Diggles The Myth of Fenris\data\Gamesave\save_15-11-2026.sav")
DEFAULT_OUTPUT = ROOT / "godot" / "models"

GRID_OFFSET = 0xC2
RECORD_SIZE = 53
MATERIAL_SLOT = 28
LAYER2_SLOT = 27
MAP_WIDTH = 512
MAP_HEIGHT = 640

# The states of the ground of a cell in the save.
STATE_AIR = 0x00
STATE_FREE_ROCK = 0x02
STATE_TEMPLATE_ROCK = 0x80


def read_grid(save_path: pathlib.Path) -> bytes:
    body = gzip.decompress(save_path.read_bytes())
    size = MAP_WIDTH * MAP_HEIGHT * RECORD_SIZE
    end = GRID_OFFSET + size
    if len(body) < end:
        raise ValueError("The save is too short for a %dx%d map grid" % (MAP_WIDTH, MAP_HEIGHT))
    return body[GRID_OFFSET:end]


def state_map(grid: bytes) -> bytearray:
    states = bytearray(MAP_WIDTH * MAP_HEIGHT)
    for index in range(MAP_WIDTH * MAP_HEIGHT):
        states[index] = grid[index * RECORD_SIZE + MATERIAL_SLOT]
    return states


def write_mask(states: bytearray, output: pathlib.Path) -> None:
    image = Image.new("L", (MAP_WIDTH, MAP_HEIGHT), 0)
    pixels = image.load()
    for index in range(MAP_WIDTH * MAP_HEIGHT):
        if states[index] == STATE_AIR:
            continue
        x = index % MAP_WIDTH
        y = index // MAP_WIDTH
        pixels[x, y] = 255
    output.parent.mkdir(parents=True, exist_ok=True)
    image.save(output)


def write_rle(states: bytearray, output: pathlib.Path) -> None:
    """The mask as a run length encoding: one run per change of the state.

    The port reads the mask from the project, and a run length list is exact,
    small and needs no import step.
    """
    runs = []
    current = -1
    count = 0
    for index in range(MAP_WIDTH * MAP_HEIGHT):
        value = 0 if states[index] == STATE_AIR else 1
        if value == current:
            count += 1
            continue
        if current >= 0:
            runs.append([current, count])
        current = value
        count = 1
    runs.append([current, count])
    report = {
        "schema": "diggles.campaign_ground_mask.v1",
        "source": "Gamesave/save_15-11-2026.sav, map grid at 0xC2, byte 28 of the record",
        "width": MAP_WIDTH,
        "height": MAP_HEIGHT,
        "rule": "one is the ground of the map that the engine did not reset, zero is the stone band of sm_draw_stone -border/-funnel",
        "runs": runs,
    }
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, ensure_ascii=False), encoding="utf-8")


def write_material_map(states: bytearray, output: pathlib.Path) -> None:
    """The material of every cell of the map, as a run length encoding.

    Byte 28 of the record of the save is the state of the ground of the cell:
    its low two bits are the code of the material (0 stone, 1 sand, 2 earth,
    3 untouched rock - data/Scripts/ai/std_ai.tcl:2991 and the cell record of
    the engine, +0x18), and bit 7 marks the cell of a placed template.

    The original draws the rock of the map with "sm_draw_stone -border" and
    "-funnel": the command resets the material of a band of cells at the edge
    of the map to stone, with a random falloff towards the edge. The band is
    therefore ground of another material, not a hole of the map.
    """
    runs = []
    current = -1
    count = 0
    for index in range(MAP_WIDTH * MAP_HEIGHT):
        value = int(states[index]) & 3
        if value == current:
            count += 1
            continue
        if current >= 0:
            runs.append([current, count])
        current = value
        count = 1
    runs.append([current, count])
    report = {
        "schema": "diggles.campaign_ground_material.v1",
        "source": "Gamesave/save_15-11-2026.sav, map grid at 0xC2, byte 28 of the record",
        "width": MAP_WIDTH,
        "height": MAP_HEIGHT,
        "rule": "the code of the material of the cell: 0 stone, 1 sand, 2 earth, 3 untouched rock",
        "runs": runs,
    }
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, ensure_ascii=False), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--save", default=DEFAULT_SAVE)
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT))
    arguments = parser.parse_args()

    save_path = pathlib.Path(arguments.save)
    output = pathlib.Path(arguments.output)

    grid = read_grid(save_path)
    states = state_map(grid)
    counts = collections.Counter(states)
    print("states of the ground of the map:")
    for value, count in sorted(counts.items()):
        print("  0x%02X : %d" % (value, count))

    # The upper edge of the free rock: the first row of the map that carries
    # the free rock of the map in every column.
    edge = []
    for x in range(MAP_WIDTH):
        top = -1
        for y in range(MAP_HEIGHT):
            if states[y * MAP_WIDTH + x] == STATE_FREE_ROCK:
                top = y
                break
        edge.append(top)
    present = [x for x in range(MAP_WIDTH) if edge[x] >= 0]
    print("columns with free rock: %d (%d..%d)" % (len(present), min(present), max(present)))
    sample = [x for x in range(0, MAP_WIDTH, 16) if edge[x] >= 0]
    print("upper edge of the rock (x : y):")
    print("  " + " ".join("%d:%d" % (x, edge[x]) for x in sample))

    mask_path = output / "native_campaign_ground_mask.png"
    write_mask(states, mask_path)
    print("written %s" % mask_path)
    rle_path = output / "native_campaign_ground_mask.json"
    write_rle(states, rle_path)
    print("written %s" % rle_path)
    material_path = output / "native_campaign_ground_material.json"
    write_material_map(states, material_path)
    print("written %s" % material_path)
    return 0


if __name__ == "__main__":
    sys.exit(main())

