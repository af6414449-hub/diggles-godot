# -*- coding: utf-8 -*-
"""Переставить раздел З9.6 в конец report.md (после раздела З9)."""
import io

P = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp\report.md"
txt = io.open(P, encoding="utf-8").read()

start = txt.index(u"\n---\n\n## З9.6 ")
end = txt.index(u"\n---\n\n## З9. Грузится ли для главы")
block = txt[start:end]
rest = txt[:start] + txt[end:]
rest = rest.rstrip("\n") + "\n" + block.strip("\n") + "\n"
io.open(P, "w", encoding="utf-8", newline="\n").write(rest)
print("OK, %d символов" % len(rest))
for i, line in enumerate(rest.split("\n"), 1):
    if line.startswith("## "):
        print("  %d: %s" % (i, line))
