"""Patch DigglesPort.dll: map WASD scancodes to the arrow-key VK codes.

The port DLL holds a std::map<scancode, vkcode> used by GetVKScanCode().
Entries are packed as (vk << 16) | scancode and live as immediates inside
GetVKScanCode() (RVA 0x11650 in DigglesPort.dll).

We replace the four letters so that the engine sees them as arrow keys:
    A (scancode 4)  -> VK_LEFT  (0x25)
    D (scancode 7)  -> VK_RIGHT (0x27)
    S (scancode 22) -> VK_DOWN  (0x28)
    W (scancode 26) -> VK_UP    (0x26)

Usage:  python patch-wasd-dll.py <path-to-DigglesPort.dll> [--revert]
"""
import struct
import shutil
import sys
import os

PATCHES = [
    (0x00410004, 0x00250004, "A -> VK_LEFT"),
    (0x00440007, 0x00270007, "D -> VK_RIGHT"),
    (0x00530016, 0x00280016, "S -> VK_DOWN"),
    (0x0057001A, 0x0026001A, "W -> VK_UP"),
]


def find_all(data: bytes, pat: bytes):
    out = []
    pos = 0
    while True:
        k = data.find(pat, pos)
        if k < 0:
            break
        out.append(k)
        pos = k + 1
    return out


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 1
    path = sys.argv[1]
    revert = "--revert" in sys.argv

    if not os.path.isfile(path):
        print("FAIL: not found:", path)
        return 2

    data = bytearray(open(path, "rb").read())
    orig = bytes(data)
    backup = path + ".orig"
    if not os.path.exists(backup):
        shutil.copy2(path, backup)
        print("backup created:", backup)

    changed, already, missing = 0, 0, 0
    for old, new, name in PATCHES:
        a, b = (new, old) if revert else (old, new)
        pat_a = struct.pack("<I", a)
        pat_b = struct.pack("<I", b)
        hits = find_all(orig, pat_a)
        if not hits:
            # already in the target state?
            if find_all(orig, pat_b):
                already += 1
                print("  [ok] %-14s already applied" % name)
                continue
            missing += 1
            print("  [!!] %-14s pattern not found" % name)
            continue
        if len(hits) != 1:
            missing += 1
            print("  [!!] %-14s %d matches, skipped" % (name, len(hits)))
            continue
        off = hits[0]
        data[off:off + 4] = pat_b
        changed += 1
        print("  [ok] %-14s 0x%08X -> 0x%08X at file offset 0x%06X"
              % (name, a, b, off))

    if changed:
        open(path, "wb").write(bytes(data))

    print("changed=%d already=%d missing=%d" % (changed, already, missing))
    print("size: %d -> %d" % (len(orig), len(data)))
    return 0 if missing == 0 else 3


if __name__ == "__main__":
    sys.exit(main())
