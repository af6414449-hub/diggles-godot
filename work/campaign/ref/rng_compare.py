#!/usr/bin/env python3
"""Compare the literal Diggles.exe RNG disassembly against standard MT19937.

`game` is a literal transcription of Diggles.exe 0x49c670 / 0x4454d0.
`mt` is the standard MT19937 formulation used by the project's diggles_rng.py.
"""
from __future__ import annotations

MASK = 0xFFFFFFFF
MAG01 = (0x00000000, 0x9908B0DF)
N = 624
M = 397


class GameRng:
    """Literal transcription of Diggles.exe 0x4454d0 (seed) + 0x49c670 (draw)."""

    def __init__(self, seed: int) -> None:
        self.state = [0] * N
        value = seed & MASK
        for i in range(N):
            # 0x4454e0: esi = eax; eax = eax * 69069; esi &= 0xffff0000
            hi = value & 0xFFFF0000
            nxt = (value * 69069) & MASK
            # 0x4454fb: edx = eax + 1  (== L_{k+1})
            # 0x445533: eax = edx >> 16 ; state[i] |= eax
            self.state[i] = hi | ((nxt + 1) >> 16)
            # 0x44553e: eax = edx * 69069 + 1
            value = ((nxt + 1) * 69069 + 1) & MASK
        self.counter = 0x270  # 0x44554f: [0x768350] = 0x270

    def _twist(self) -> None:
        st = self.state
        # First loop: i = 0..226, lag +397  (0x49c6b0)
        for i in range(0, 227):
            mixed = ((st[i] ^ st[i + 1]) & 0x7FFFFFFF) ^ st[i]
            mixed = (mixed >> 1) ^ MAG01[mixed & 1]
            st[i] = mixed ^ st[i + 397]
        # Second loop: i = 227..622, lag -227 (0x49c7a3)
        for i in range(227, 623):
            mixed = ((st[i] ^ st[i + 1]) & 0x7FFFFFFF) ^ st[i]
            mixed = (mixed >> 1) ^ MAG01[mixed & 1]
            st[i] = mixed ^ st[i - 227]
        # i = 623: the bounds guard falls back to state[0] (MT19937 wraparound).
        mixed = ((st[623] ^ st[0]) & 0x7FFFFFFF) ^ st[623]
        mixed = (mixed >> 1) ^ MAG01[mixed & 1]
        st[623] = mixed ^ st[396]
        # Post-twist block (0x49c87a): one more update of state[623].
        prev = st[623]
        mixed = ((st[0] ^ prev) & 0x7FFFFFFF) ^ prev
        mixed = (mixed >> 1) ^ MAG01[mixed & 1]
        st[623] = mixed ^ st[396]

    def next_u32(self) -> int:
        if self.counter >= N:
            if self.counter == 0x271:
                self.__init__(0x1105)
            self._twist()
            self.counter = 1
            value = self.state[0]
        else:
            value = self.state[self.counter]
            self.counter += 1
        # Tempering (0x49c8f2)
        value ^= value >> 11
        value ^= (value << 7) & 0x9D2C5680
        value ^= (value << 15) & 0xEFC60000
        value ^= value >> 18
        return value & MASK


class MtRng:
    """Standard MT19937 with the game's LCG seeding (project diggles_rng.py)."""

    def __init__(self, seed: int) -> None:
        self.state = []
        value = seed & MASK
        for _ in range(N):
            first = (value * 69069 + 1) & MASK
            self.state.append((value & 0xFFFF0000) | (first >> 16))
            value = (first * 69069 + 1) & MASK
        self.index = 624

    def next_u32(self) -> int:
        if self.index >= 624:
            for i in range(624):
                mixed = (self.state[i] & 0x80000000) | (self.state[(i + 1) % 624] & 0x7FFFFFFF)
                self.state[i] = self.state[(i + 397) % 624] ^ (mixed >> 1)
                if mixed & 1:
                    self.state[i] ^= 0x9908B0DF
            self.index = 0
        value = self.state[self.index]
        self.index += 1
        value ^= value >> 11
        value ^= (value << 7) & 0x9D2C5680
        value ^= (value << 15) & 0xEFC60000
        value ^= value >> 18
        return value & MASK


class MtRngNoExtra:
    """MT19937 variant without the extra post-twist state[623] update."""

    def __init__(self, seed: int) -> None:
        self.state = []
        value = seed & MASK
        for _ in range(N):
            first = (value * 69069 + 1) & MASK
            self.state.append((value & 0xFFFF0000) | (first >> 16))
            value = (first * 69069 + 1) & MASK
        self.index = 624

    def next_u32(self) -> int:
        if self.index >= 624:
            for i in range(624):
                mixed = (self.state[i] & 0x80000000) | (self.state[(i + 1) % 624] & 0x7FFFFFFF)
                self.state[i] = self.state[(i + 397) % 624] ^ (mixed >> 1)
                if mixed & 1:
                    self.state[i] ^= 0x9908B0DF
            self.index = 0
        value = self.state[self.index]
        self.index += 1
        value ^= value >> 11
        value ^= (value << 7) & 0x9D2C5680
        value ^= (value << 15) & 0xEFC60000
        value ^= value >> 18
        return value & MASK


def main() -> None:
    for seed in (0, 1, 4357, 0x1105, 123456789):
        g = GameRng(seed)
        m = MtRng(seed)
        n = MtRngNoExtra(seed)
        gs = [g.next_u32() for _ in range(8)]
        ms = [m.next_u32() for _ in range(8)]
        ns = [n.next_u32() for _ in range(8)]
        print(f"seed={seed}")
        print(f"  game(disasm) : {[hex(v) for v in gs]}")
        print(f"  mt(project)  : {[hex(v) for v in ms]}  equal={gs == ms}")
        print(f"  mt(no-extra) : {[hex(v) for v in ns]}  equal={gs == ns}")


if __name__ == "__main__":
    main()
