# -*- coding: utf-8 -*-
"""The material generator of the map of the original, by the decompilation.

FUN_004454d0  the seed of the state
FUN_00598f10   the mapgen of the map (the inline copy of the random)
FUN_0049c670  the random of the engine (the shared copy)
FUN_005fc9d0  the core of sm_draw_stone
"""
import gzip
import pathlib
import struct

MASK = 0xFFFFFFFF
MAP_WIDTH = 512
MAP_HEIGHT = 640
GRID_OFFSET = 0xC2
RECORD_SIZE = 53
MATERIAL_SLOT = 28
SAVE = pathlib.Path(r"C:\Program Files (x86)\Steam\steamapps\common"
                    r"\Diggles The Myth of Fenris\data\Gamesave\save_15-11-2026.sav")


class DigglesRandom:
    """The random stream of the engine.

    The state is 624 words, the seed is 0x1105, the tempering is the one of the
    engine (not the standard one of MT19937).  The twist of the mapgen
    (FUN_00598f10) and the twist of the shared random (FUN_0049c670) differ in
    the last word of the state, so the variant is a parameter.
    """

    def __init__(self, variant="canonical"):
        self.variant = variant
        self.state = [0] * 624
        self.index = 0x271  # the index of the engine in the .data is 0x271

    def seed(self, seed_value):
        state = []
        value = seed_value & MASK
        for _ in range(624):
            first = (value * 69069 + 1) & MASK
            state.append((value & 0xFFFF0000) | (first >> 16))
            value = (first * 69069 + 1) & MASK
        self.state = state
        self.index = 0x270

    def _twist(self):
        state = self.state
        for i in range(623):
            mixed = ((state[i] ^ state[i + 1]) & 0x7FFFFFFF) ^ state[i]
            value = state[(i + 397) % 624] ^ (mixed >> 1)
            if mixed & 1:
                value ^= 0x9908B0DF
            state[i] = value & MASK
        if self.variant == "mapgen":
            mixed = ((state[623] ^ state[0]) & 0x7FFFFFFF) ^ state[0]
        else:
            mixed = ((state[0] ^ state[623]) & 0x7FFFFFFF) ^ state[623]
        value = state[396] ^ (mixed >> 1)
        if mixed & 1:
            value ^= 0x9908B0DF
        state[623] = value & MASK

    def next_u32(self):
        if self.index >= 624:
            if self.index == 0x271:
                self.seed(0x1105)
            self._twist()
            self.index = 0
        value = self.state[self.index]
        self.index += 1
        value = (value ^ (value >> 11)) & MASK
        value = (value ^ ((value & 0xFF3A58AD) << 7)) & MASK
        value = (value ^ ((value & 0xFFFFDF8C) << 15)) & MASK
        value = (value ^ (value >> 18)) & MASK
        return value


def f32(value):
    """The float of the engine: a single."""
    return struct.unpack("f", struct.pack("f", value))[0]


def mapgen(rng, width, height, materials, variations):
    """FUN_00598f10: one random per cell, the material 2 and a variation byte."""
    for y in range(height):
        row = y * width
        for x in range(width):
            value = rng.next_u32()
            materials[row + x] = 2
            variations[row + x] = ((value >> 18) ^ value) & 0xFF


def draw_stone(rng, materials, width, height, rect, flags, strength):
    """FUN_005fc9d0: the stone in a rectangle of the map."""
    x1 = max(rect[0], 0)
    y1 = max(rect[1], 0)
    x2 = min(rect[2], width)
    y2 = min(rect[3], height)
    if x1 >= x2 or y1 >= y2:
        return
    span_x = x2 - x1
    span_y = y2 - y1
    falloff = f32(strength / f32(min(span_x, span_y) * 0.2))
    centre_x = x1 + span_x // 2
    centre_y = y1 + span_y // 2
    for x in range(x1, x2 - 1):
        for y in range(y1, y2 - 1):
            probability = 1.0
            if (flags & 4) and x > centre_x:
                distance = f32(centre_x - x)
                term = f32(f32(f32(distance / span_x) * distance) / span_x)
                probability = f32(1.0 - f32(term / falloff))
            if (flags & 8) and x < centre_x:
                distance = f32(centre_x - x)
                term = f32(f32(f32(distance / span_x) * distance) / span_x)
                probability = f32(probability - f32(term / falloff))
            if (flags & 1) and y > centre_y:
                distance = f32(centre_y - y)
                term = f32(f32(f32(distance / span_y) * distance) / span_y)
                probability = f32(probability - f32(term / falloff))
            if (flags & 2) and y < centre_y:
                distance = f32(centre_y - y)
                term = f32(f32(f32(distance / span_y) * distance) / span_y)
                probability = f32(probability - f32(term / falloff))
            index = y * width + x
            material = materials[index]
            if material != 1 and material != 2:
                continue
            number = rng.next_u32() & 0x7FFF
            if float(number) <= probability * 32768.0:
                materials[index] = 0


def generate(width=MAP_WIDTH, height=MAP_HEIGHT, systeminit=True,
             mapgen_variant="mapgen"):
    """The campaign map of the original, in the order of the scripts."""
    rng = DigglesRandom(variant="canonical")
    materials = bytearray(width * height)
    variations = bytearray(width * height)
    if systeminit:
        # data/systeminit.tcl:64  map create 64 64 {  }
        rng.variant = mapgen_variant
        mapgen(rng, 64, 64, bytearray(64 * 64), bytearray(64 * 64))
    rng.variant = mapgen_variant
    mapgen(rng, width, height, materials, variations)
    rng.variant = "canonical"
    # sm_draw_stone -border: the top band, the left band, the right band.
    draw_stone(rng, materials, width, height, (0, 0, width, 32), 1, 3.0)
    draw_stone(rng, materials, width, height, (0, 0, 32, height + 4), 4, 1.0)
    draw_stone(rng, materials, width, height, (width - 32, 0, width, height + 4),
               8, 1.0)
    # sm_draw_stone -funnel: thirty bands, the right wall first.
    band_width = 2 * (width // 4) - 20
    band_y = 16
    while band_width > 0:
        draw_stone(rng, materials, width, height,
                   (width - band_width, band_y, width, band_y + 6), 8, 1.0)
        draw_stone(rng, materials, width, height,
                   (0, band_y, band_width, band_y + 6), 4, 1.0)
        band_width -= 8
        band_y += 4
    return materials, variations


def save_states():
    body = gzip.decompress(SAVE.read_bytes())
    size = MAP_WIDTH * MAP_HEIGHT * RECORD_SIZE
    grid = body[GRID_OFFSET:GRID_OFFSET + size]
    states = bytearray(MAP_WIDTH * MAP_HEIGHT)
    for index in range(MAP_WIDTH * MAP_HEIGHT):
        states[index] = grid[index * RECORD_SIZE + MATERIAL_SLOT]
    return states


def compare(materials, states, label):
    stone = 0
    saved_zero = 0
    both = 0
    saved_zero_only = 0
    stone_only = 0
    for index in range(MAP_WIDTH * MAP_HEIGHT):
        generated = materials[index] == 0
        saved = (states[index] & 3) == 0
        if generated:
            stone += 1
        if saved:
            saved_zero += 1
        if generated and saved:
            both += 1
        elif saved:
            saved_zero_only += 1
        elif generated:
            stone_only += 1
    print("%-28s stone %6d  save0 %6d  both %6d  save0only %6d  stoneonly %6d"
          % (label, stone, saved_zero, both, saved_zero_only, stone_only))
    return both


def main():
    states = save_states()
    counts = {}
    for value in states:
        counts[value] = counts.get(value, 0) + 1
    print("states of the save:", sorted(counts.items()))
    for systeminit in (True, False):
        for variant in ("mapgen", "canonical"):
            materials, _ = generate(systeminit=systeminit, mapgen_variant=variant)
            compare(materials, states,
                    "init=%s variant=%s" % (systeminit, variant))


if __name__ == "__main__":
    main()
