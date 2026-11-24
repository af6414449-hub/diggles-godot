#!/usr/bin/env python3
"""Prepare a native patch that makes WASD drive the camera exactly like the
arrow keys.

The camera scroll handler (Diggles.exe VA 0x0054E65D) reacts to Windows
virtual-key codes: 0x25 LEFT, 0x27 RIGHT, 0x26 UP, 0x28 DOWN.
W/A/S/D are 0x57/0x41/0x53/0x44 and are unused by the game.

Patch plan: redirect the 5 bytes at VA 0x0054E65D ("cmp ecx,0x100 / jne")
into a code cave that remaps W/A/S/D to the arrow codes and jumps back.

Usage:
  python patch-wasd.py plan          -> print plan (caves, offsets)
  python patch-wasd.py apply         -> write the patched exe (backup kept)
"""
import os
import shutil
import struct
import sys

from capstone import Cs, CS_ARCH_X86, CS_MODE_32

EXE = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe"
BACKUP = EXE + ".orig"

IMAGE_BASE = 0x400000
HOOK_VA = 0x0054E65D        # "cmp ecx,0x100 / jne 0x54E824"
HOOK_LEN = 8                # 81 F9 00 01 00 00 | 75 xx
RESUME_VA = 0x0054E824      # where the original jne went
CONT_VA = 0x0054E669        # where the arrow comparisons start

# W A S D  ->  UP LEFT DOWN RIGHT
REMAP = [(0x57, 0x26), (0x41, 0x25), (0x53, 0x28), (0x44, 0x27)]


def sections(data):
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    off = pe + 24 + optsz
    res = []
    for i in range(nsec):
        o = off + 40 * i
        vsize, vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, o + 8)
        res.append((IMAGE_BASE + vaddr, vsize, rawptr, rawsize, o))
    return res


def va_to_off(secs, va):
    for sva, vsize, rawptr, rawsize, o in secs:
        if sva <= va < sva + vsize:
            return rawptr + (va - sva)
    return None


def find_caves(data, secs, need=64):
    """runs of INT3 padding inside .text, long enough for our stub"""
    out = []
    for sva, vsize, rawptr, rawsize, o in secs:
        if sva != 0x401000:
            continue
        blob = data[rawptr:rawptr + rawsize]
        i = 0
        while i < len(blob):
            if blob[i] == 0xCC:
                j = i
                while j < len(blob) and blob[j] == 0xCC:
                    j += 1
                if (j - i) >= need:
                    out.append((sva + i, j - i))
                i = j
            else:
                i += 1
    return out


def build_stub(caves, secs):
    """assemble the stub bytes and pick a cave"""
    # cmp ebx, imm8 ; jne +5 ; mov ebx, imm32  -> 83 FB xx 75 05 BB xx 00 00 00
    blob = b""
    for src, dst in REMAP:
        blob += bytes([0x83, 0xFB, src, 0x75, 0x05, 0xBB, dst, 0x00, 0x00, 0x00])
    # cmp ecx, 0x100 ; jne rel32 ; jmp rel32 (CONT_VA)
    blob += bytes([0x81, 0xF9, 0x00, 0x01, 0x00, 0x00])   # cmp ecx,0x100
    jne_pos = len(blob)
    blob += bytes([0x0F, 0x85, 0, 0, 0, 0])           # jne rel32
    jmp_pos = len(blob)
    blob += bytes([0xE9, 0, 0, 0, 0])                 # jmp rel32
    return blob, jne_pos, jmp_pos


def main():
    mode = sys.argv[1] if len(sys.argv) > 1 else "plan"
    data = bytearray(open(EXE, "rb").read())
    secs = sections(bytes(data))

    hook_off = va_to_off(secs, HOOK_VA)
    print("hook  VA 0x%08X -> file 0x%X" % (HOOK_VA, hook_off))
    print("hook bytes: " + " ".join("%02X" % b for b in data[hook_off:hook_off + HOOK_LEN]))
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    for ins in md.disasm(bytes(data[hook_off:hook_off + 16]), HOOK_VA):
        print("   0x%08X %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))

    caves = find_caves(bytes(data), secs)
    blob, jne_pos, jmp_pos = build_stub(caves, secs)
    print("stub size: %d bytes" % len(blob))
    if not caves:
        print("NO CODE CAVE FOUND")
        return
    cave_va, cave_len = caves[0]
    print("cave candidates: %d, first at VA 0x%08X (%d bytes)" % (len(caves), cave_va, cave_len))

    # relocate
    stub = bytearray(blob)
    after_jne = cave_va + jne_pos + 6
    rel = RESUME_VA - after_jne
    struct.pack_into("<i", stub, jne_pos + 2, rel)
    after_jmp = cave_va + jmp_pos + 5
    rel2 = CONT_VA - after_jmp
    struct.pack_into("<i", stub, jmp_pos + 1, rel2)
    # jmp from hook to cave (5 bytes) + 3 nops to fill the 8-byte hook area
    hook = bytearray([0xE9, 0, 0, 0, 0, 0x90, 0x90, 0x90])
    rel3 = cave_va - (HOOK_VA + 5)
    struct.pack_into("<i", hook, 1, rel3)

    print("\nstub at 0x%08X:" % cave_va)
    for ins in md.disasm(bytes(stub), cave_va):
        print("   0x%08X %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))
    print("hook bytes: " + " ".join("%02X" % b for b in hook))

    if mode == "apply":
        if not os.path.exists(BACKUP):
            shutil.copy2(EXE, BACKUP)
            print("backup written: " + BACKUP)
        else:
            print("backup already present: " + BACKUP)
        data[hook_off:hook_off + HOOK_LEN] = hook
        cave_off = va_to_off(secs, cave_va)
        data[cave_off:cave_off + len(stub)] = stub
        open(EXE, "wb").write(bytes(data))
        print("patched exe written")
        # verify
        chk = open(EXE, "rb").read()
        md2 = Cs(CS_ARCH_X86, CS_MODE_32)
        print("\nverify hook:")
        for ins in md2.disasm(chk[hook_off:hook_off + 16], HOOK_VA):
            print("   0x%08X %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))
        print("verify stub:")
        for ins in md2.disasm(chk[cave_off:cave_off + len(stub)], cave_va):
            print("   0x%08X %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))


if __name__ == "__main__":
    main()
