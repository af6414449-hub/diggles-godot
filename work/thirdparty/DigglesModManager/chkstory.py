import tkinter, os
f = r"C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\data\Scripts\classes\story\story.tcl"
b = open(f, "rb").read()
print("bytes ok, len", len(b))
i = b.find(b"method load_level")
print(repr(b[i:i+260]))
j = b.find(b"method load_sandbox")
print(repr(b[j:j+240]))
# syntax check of the whole file
src = b.decode("cp1252")
t = tkinter.Tcl()
print("info complete:", t.eval("info complete {%s}" % src))
