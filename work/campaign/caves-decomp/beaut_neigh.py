import re

f = r"C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp\beaut_disasm.txt"
raw = open(f, "rb").read()
text = raw.decode("utf-16")
lines = text.splitlines()

pat = re.compile(r"cmp\s+byte ptr \[eax\],\s*0xe")
idx = [i for i, l in enumerate(lines) if pat.search(l)]

rowpat = re.compile(r"add\s+(eax|ecx|edx|esi|edi),\s*(-?(?:0x)?[0-9a-fA-F]+)")
colpat = re.compile(r"lea\s+\w+,\s*\[(\w+)\s*([+-]\s*\w+)?\]")
decpat = re.compile(r"dec\s+(\w+)")

for n, i in enumerate(idx, 1):
    print(f"\n--- check #{n} @ {lines[i].split(':')[0].strip()} ---")
    rows, cols = [], []
    for j in range(max(0, i - 24), i):
        l = lines[j]
        m = rowpat.search(l)
        if m:
            v = m.group(2)
            try:
                iv = int(v, 16) if v.startswith("0x") or v.startswith("-0x") else int(v)
            except ValueError:
                iv = None
            if iv is not None and iv < 0:
                rows.append((m.group(1), iv))
        if "dec " in l and "dec e" in l:
            rows.append(("dec", -1))
        for cm in colpat.finditer(l):
            cols.append(cm.group(0))
        if "lea" in l and ("+ 7]" in l or "- 7]" in l or "+ 4]" in l or "- 4]" in l
                          or "+ 2]" in l or "- 2]" in l or "+ 0x" in l):
            cols.append(l.split(":", 1)[1].strip() if ":" in l else l)
    print("  row-offsets:", rows[-4:])
    print("  col-lea    :", cols[-3:])
