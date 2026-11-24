"""Diggles.exe 32-bit irandom stream recovered from native code.

0x61afc8 registers irandom -> 0x62f780; that callback calls 0x49c670,
masks the result to 31 bits and takes remainder by the Tcl argument.
0x4454d0 initializes the 624-word generator state from a 32-bit seed.
"""

MASK = 0xFFFFFFFF


class DigglesRandom:
    def __init__(self, seed: int):
        state = []
        value = seed & MASK
        for _ in range(624):
            first = (value * 69069 + 1) & MASK
            state.append((value & 0xFFFF0000) | (first >> 16))
            value = (first * 69069 + 1) & MASK
        self.state = state
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

    def irandom(self, limit: int) -> int:
        if limit <= 0:
            raise ValueError("irandom limit must be positive")
        return (self.next_u32() & 0x7FFFFFFF) % limit

    def choice(self, values):
        return values[self.irandom(len(values))]
