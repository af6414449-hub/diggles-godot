"""Diggles: patч байта тумана в FUN_00580610 (ядро команды set_fow_begin).

Что делает патч
---------------
set_fow_begin -> FUN_00580610(y, owner) делает две вещи для каждой ячейки карты:

    if (byte[cell + 0x34 + owner] == 0)
        CFogOfWar::NewVisibleBlock(...)   // 0x0057DFC0 - ячейка становится ВИДИМОЙ
    byte[cell + 0x34 + owner] = 0xFF;    // "полностью освещено"

Инструкция `mov byte ptr [edi], 0xff` (VA 0x005807B2, файловое смещение
0x0017FBB2) пишет 0xFF в байт состояния ячейки:

    0 = неразведано (чёрный туман)
    1 = разведано, но максимально темно (обычная дымка)
    255 = освещено

Замена 0xFF -> 0x01 даёт ровно требуемое состояние: ячейка зарегистрирована
как видимая (NewVisibleBlock) и при этом остаётся тёмной - чёрный туман исчезает,
обычная дымка остаётся.

Побочный эффект: собственные вызовы set_fow_begin в игре
(story.tcl:589 - фронт разведки сюжета, Trigger_Lava.tcl:55) теперь раскрывают
область не "ярко", а "тускло" (байт 1 вместо 255).

Запуск:
    python patch-fogbyte.py            # наложить патч
    python patch-fogbyte.py --revert   # откатить
    python patch-fogbyte.py --check    # только проверить
"""
import hashlib
import os
import shutil
import sys

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
EXE = os.path.join(GAME, "Diggles.exe")
BAK = os.path.join(GAME, "Diggles.exe.fogbyte.orig")

PATCH_OFFSET = 0x0017FBB2
PATCH_VA = 0x005807B2
OLD = b"\xC6\x07\xFF"   # mov byte ptr [edi], 0xff
NEW = b"\xC6\x07\x01"   # mov byte ptr [edi], 0x01

ORIG_SHA256 = "58A01D3D80670A6042C66A82684397C98E39C503E00A6E2C2C511F338A30ED74"


def sha(data):
    return hashlib.sha256(data).hexdigest().upper()


def main():
    mode = sys.argv[1] if len(sys.argv) > 1 else "apply"
    if not os.path.exists(EXE):
        print("NOT FOUND:", EXE)
        return 2

    data = bytearray(open(EXE, "rb").read())
    cur = sha(data)

    if mode == "--check":
        chunk = bytes(data[PATCH_OFFSET:PATCH_OFFSET + 3])
        print("exe sha256 :", cur)
        print("at %08X  : %s" % (PATCH_OFFSET, chunk.hex(" ")))
        print("patched    :", chunk == NEW)
        print("original   :", chunk == OLD)
        print("backup     :", os.path.exists(BAK))
        return 0

    if mode == "--revert":
        if not os.path.exists(BAK):
            print("NO BACKUP:", BAK)
            return 2
        shutil.copyfile(BAK, EXE)
        d = open(EXE, "rb").read()
        print("reverted. sha256 =", sha(d))
        print("matches original:", sha(d) == ORIG_SHA256)
        return 0

    # apply
    chunk = bytes(data[PATCH_OFFSET:PATCH_OFFSET + 3])
    if chunk == NEW:
        print("already patched, nothing to do. sha256 =", cur)
        return 0
    if chunk != OLD:
        print("UNEXPECTED BYTES at %08X: %s" % (PATCH_OFFSET, chunk.hex(" ")))
        print("aborting, exe untouched")
        return 3
    if cur != ORIG_SHA256:
        print("WARNING: exe sha256 differs from the known original")
        print("  current :", cur)
        print("  expected:", ORIG_SHA256)
        print("the exe was modified by something else - aborting")
        return 3

    if not os.path.exists(BAK):
        shutil.copyfile(EXE, BAK)
        print("backup created:", BAK, sha(open(BAK, "rb").read()))

    data[PATCH_OFFSET:PATCH_OFFSET + 3] = NEW
    open(EXE, "wb").write(bytes(data))
    d = open(EXE, "rb").read()
    ok = d[PATCH_OFFSET:PATCH_OFFSET + 3] == NEW
    print("patched   :", ok, "sha256 =", sha(d))
    print("byte at %08X (VA 0x%08X): %s" % (PATCH_OFFSET, PATCH_VA,
                                            d[PATCH_OFFSET:PATCH_OFFSET + 3].hex(" ")))
    return 0 if ok else 4


if __name__ == "__main__":
    sys.exit(main())
