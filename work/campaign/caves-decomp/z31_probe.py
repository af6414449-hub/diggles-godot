# -*- coding: utf-8 -*-
"""З31: разбор 8 функций применения техники + реестра техник."""
import os, re, sys, io

DEC = r'C:\diggles-ghidra\out\decomp'
OUT = r'C:\Users\frant\OneDrive\Документы\MiniMax\Diggles\work\campaign\caves-decomp\z31_probe.txt'

TARGETS = ['FUN_004899b0','FUN_0048a240','FUN_0048aa60','FUN_0048b290',
           'FUN_0048ba80','FUN_0048c3f0','FUN_0048d490','FUN_0048dce0']

PAT = re.compile(r'0x850|0x854|0x6c|param_1\[2\]|param_1\[3\]|param_1\[4\]|FUN_0045fd00|0x1058|0x105c|0x48\b')

def find(fname):
    for n in os.listdir(DEC):
        if n.startswith(fname) and n.endswith('.c'):
            return os.path.join(DEC, n)
    return None

buf = io.StringIO()
for t in TARGETS:
    p = find(t)
    if not p:
        buf.write('MISSING %s\n\n' % t); continue
    lines = io.open(p, 'r', encoding='utf-8', errors='replace').read().split('\n')
    buf.write('='*70 + '\n=== %s  (%s)  lines=%d\n' % (t, os.path.basename(p), len(lines)))
    # signature
    for i, l in enumerate(lines[:80]):
        if re.search(r'^\s*(undefined|int|void|float|uint|char|long|byte|short|double)\b.*FUN_', l):
            buf.write('SIG: %s\n' % l.strip()); break
    for i, l in enumerate(lines):
        if PAT.search(l):
            buf.write('%4d: %s\n' % (i+1, l.rstrip()))
    buf.write('\n')

io.open(OUT, 'w', encoding='utf-8').write(buf.getvalue())
print('wrote', OUT, len(buf.getvalue()))
