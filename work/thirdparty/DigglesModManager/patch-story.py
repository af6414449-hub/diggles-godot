"""Diggles: вставка раскрытия тумана в игровой скрипт менеджера сюжета.

Зачем
----
Карта УРОВНЯ создаётся не в главном интерпретаторе Tcl, а в интерпретаторе
объекта StoryMgr (story.tcl -> method load_level -> call "scripts/gameplay/...").
Скрипт data/userinit.tcl грузится только в главный интерпретатор, поэтому
хуки на "map create" / "sm_create_map" никогда не срабатывают на карте
уровня - отсюда "туман не снимается".

Решение: вставить вызов set_fow_begin прямо в метод load_level / load_sandbox
того же story.tcl, т.е. в том интерпретаторе, где карта уровня и создаётся и
заполняется.

Что делает set_fow_begin
------------------------
FUN_00580610(y, owner): для всех ячеек с байтом 0 вызывает
CFogOfWar::NewVisibleBlock (ячейка становится видимой, снимается объём тумана)
и записывает байт состояния. В Diggles.exe этот байт заменён на 0x01
(см. patch-fogbyte.py), то есть ячейка становится "разведана, но максимально
темно" - обычная дымка, без чёрного тумана.

Запуск:
    python patch-story.py          # вставить (с бэкапом)
    python patch-story.py --revert # откатить
    python patch-story.py --check  # только проверить
"""
import hashlib
import os
import shutil
import sys

GAME = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris"
FILE = os.path.join(GAME, "data", "Scripts", "classes", "story", "story.tcl")
BAK = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\thirdparty\DigglesModManager\story.tcl.orig"

BLOCK = (
    b"\t\tcatch {set_fow_begin 999999 0} nofog_err\r\n"
    b"\t\tlog \"nofog: set_fow_begin -> $nofog_err\"\r\n"
)

# точка вставки: строка "sm_log" в методе load_level
ANCHOR_LEVEL = (
    b"\t\tcall \"scripts/gameplay/CampaignInit.tcl\"\r\n"
    b"\t\tcall \"scripts/gameplay/$level.tcl\"\r\n"
    b"\t\tsm_log\r\n"
)
REPL_LEVEL = (
    b"\t\tcall \"scripts/gameplay/CampaignInit.tcl\"\r\n"
    b"\t\tcall \"scripts/gameplay/$level.tcl\"\r\n"
    b"\t\tsm_log\r\n"
    + BLOCK
)

# точка вставки: строка "call .../$level.tcl" в методе load_sandbox
ANCHOR_SANDBOX = (
    b"\t\tnet initplayers\r\n"
    b"\t\tcall \"scripts/gameplay/SandboxInit.tcl\"\r\n"
    b"\t\tcall \"scripts/gameplay/$level.tcl\"\r\n"
)
REPL_SANDBOX = ANCHOR_SANDBOX + BLOCK

MARK = b"nofog: set_fow_begin"


def sha(b):
    return hashlib.sha256(b).hexdigest().upper()


def main():
    mode = sys.argv[1] if len(sys.argv) > 1 else "apply"
    if not os.path.exists(FILE):
        print("NOT FOUND:", FILE)
        return 2
    cur = open(FILE, "rb").read()

    if mode == "--check":
        print("size:", len(cur), "sha256:", sha(cur))
        print("patched:", cur.count(MARK), "marker(s)")
        print("backup :", os.path.exists(BAK), sha(open(BAK, "rb").read()) if os.path.exists(BAK) else "")
        return 0

    if mode == "--revert":
        if not os.path.exists(BAK):
            print("NO BACKUP:", BAK)
            return 2
        shutil.copyfile(BAK, FILE)
        print("reverted, sha256 =", sha(open(FILE, "rb").read()))
        return 0

    if MARK in cur:
        print("already patched (%d markers)" % cur.count(MARK))
        return 0

    if ANCHOR_LEVEL not in cur:
        print("ANCHOR_LEVEL not found - aborting, file untouched")
        return 3
    if ANCHOR_SANDBOX not in cur:
        print("ANCHOR_SANDBOX not found - aborting, file untouched")
        return 3

    if not os.path.exists(BAK):
        shutil.copyfile(FILE, BAK)
        print("backup created:", BAK, sha(open(BAK, "rb").read()))

    new = cur.replace(ANCHOR_LEVEL, REPL_LEVEL, 1)
    new = new.replace(ANCHOR_SANDBOX, REPL_SANDBOX, 1)
    open(FILE, "wb").write(new)

    chk = open(FILE, "rb").read()
    print("patched:", chk.count(MARK), "marker(s), size", len(chk))
    print("sha256:", sha(chk))
    return 0


if __name__ == "__main__":
    sys.exit(main())
