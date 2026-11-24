"""Установка userinit.tcl в папку игры (из Bash/Write туда писать нельзя).

    python install-userinit.py            # установить и показать хэши
    python install-userinit.py --check     # только сравнить хэши
"""
import hashlib
import os
import shutil
import sys

SRC = (r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles"
       r"\work\thirdparty\DigglesModManager\userinit-nofog.tcl")
DST = (r"C:\Program Files (x86)\Steam\steamapps\common"
       r"\Diggles The Myth of Fenris\data\userinit.tcl")


def info(path):
    if not os.path.exists(path):
        return "MISSING"
    d = open(path, "rb").read()
    return "%d B  sha256=%s  bom=%s" % (len(d), hashlib.sha256(d).hexdigest().upper(),
                                       d[:3] == b"\xef\xbb\xbf")


def main():
    if "--check" in sys.argv:
        print("source :", info(SRC))
        print("game   :", info(DST))
        return 0
    shutil.copyfile(SRC, DST)
    print("installed")
    print("source :", info(SRC))
    print("game   :", info(DST))
    return 0


if __name__ == "__main__":
    sys.exit(main())
