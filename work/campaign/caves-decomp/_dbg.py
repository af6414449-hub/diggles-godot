import re, io, os
p = r'C:\diggles-ghidra\out\decomp\FUN_0045a130_0045a130.c'
lines = io.open(p, 'r', encoding='utf-8', errors='replace').read().split('\n')
re_slot = re.compile(r"\*\(undefined4 \*\)\(iVar1 \+(?:(0x[0-9a-fA-F]+|\d+) \+ )?[^*]*\* 0x48\) = (0x[0-9a-fA-F]+);")
for i, ln in enumerate(lines):
    if '0x48)' in ln:
        m = re_slot.search(ln)
        print(i+1, repr(ln.strip())[:90], '->', m.groups() if m else None)
