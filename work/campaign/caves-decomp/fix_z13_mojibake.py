import os
f = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp\report.md"
raw = open(f, "rb").read()
bom = raw.startswith(b"\xef\xbb\xbf")
text = raw.decode("utf-8-sig")
bad = "(вари" + "\ufffd" * 2 + "ция)"
assert text.count(bad) == 1, text.count(bad)
text = text.replace(bad, "(вариация)")
assert "\ufffd" not in text
out = text.encode("utf-8")
if bom:
    out = b"\xef\xbb\xbf" + out
open(f, "wb").write(out)
print("fixed")
