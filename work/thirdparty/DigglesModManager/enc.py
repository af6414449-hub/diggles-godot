import shutil, os
f = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\Scripts\classes\story\story.tcl"
b = open(f, "rb").read()
print("size", len(b), "BOM", b[:3].hex(" "), "CRLF", b.count(b"\r\n"), "LF", b.count(b"\n"))
i = b.find(b"method load_level")
print("load_level at", i)
print(repr(b[i-40:i+220]))
print("--- utf8 ok?", end=" ")
try:
    b.decode("utf-8"); print("yes")
except Exception as e:
    print("no:", e)
