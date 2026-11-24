import os
from pathlib import Path
D = Path(r"C:\diggles-ghidra\out_port\decomp")
vas = ["10018450","10018520","10016f40","10019080","10018fe0","10019010","10018ca0","10018cc0",
       "100191d0","10019250","10019270","10019040","10018830","10018850","10018870","100188f0",
       "10018940","10018770","100188b0","100188d0","10019060","100189f0","10018ce0","10018de0",
       "10018fb0","10017550","10017ed0","10017f50","10017f70","10017d20","10017d30","10017e00","10017ea0","10017cf0",
       "100179e0","10017ab0","10017ad0","10016810","10016840","10016870","100168b0","100168f0",
       "10016e80","10016f10","10016f60","100171c0","10017260","10017340","10017410","100174e0","10017560","10017750","10017920",
       "100186b0","100185c0","100186f0","100191d0"]
lines = []
for va in vas:
    f = D / ("FUN_%s_%s.c" % (va, va))
    if not f.exists():
        lines.append("--- %s : MISSING" % va); continue
    txt = f.read_text(encoding="utf-8", errors="replace").splitlines()
    body = [l for l in txt if l.strip()][:16]
    lines.append("--- %s (%d lines total)" % (va, len(txt)))
    lines.extend(body)
Path(os.path.join(os.path.dirname(os.path.abspath(__file__)), "probe_dx7_snips.txt")).write_text("\n".join(lines), encoding="utf-8")
print("ok", len(lines))
