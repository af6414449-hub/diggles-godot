import os
rp = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp\report.md"
raw = open(rp, "rb").read()
bom = raw.startswith(b"\xef\xbb\xbf")
text = raw.decode("utf-8-sig")

bad = "---\n\n---\n\n## З11.2."
good = "---\n\n## З11.2."
assert text.count(bad) == 1, text.count(bad)
text = text.replace(bad, good)

out = text.encode("utf-8")
if bom:
    out = b"\xef\xbb\xbf" + out
open(rp, "wb").write(out)
print("fixed, bytes:", len(out))
