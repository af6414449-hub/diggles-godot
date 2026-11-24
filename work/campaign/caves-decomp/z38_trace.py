# -*- coding: utf-8 -*-
"""Z38 v3: exact line-ordered trace of FUN_00457B90 (techniques) and FUN_004564C0 (textstages)."""
import re, sys

DEC = r'C:\diggles-ghidra\out\decomp'

RE_DWORD = re.compile(r'^\s*([A-Za-z_]\w*)\[(\d+)\]\s*=\s*0x([0-9A-Fa-f]{1,8});')
RE_WORD  = re.compile(r'^\s*\*\(undefined2 \*\)\(\(?(?:int\))?(\w+) \+ (\d+)\)\s*=\s*(0x[0-9A-Fa-f]{1,4}|\d+);')
RE_BYTE  = re.compile(r'^\s*\*\(undefined1 \*\)\(\(?(?:int\))?(\w+) \+ (\d+)\)\s*=\s*(0x[0-9A-Fa-f]{1,2}|\d+);')
RE_LEN   = re.compile(r'^\s*([A-Za-z_]\w*)\[2\]\s*=\s*(0x[0-9A-Fa-f]+|\d+);')
RE_AD    = re.compile(r'FUN_00455ad0\(([^)]*)\);')
RE_TMPL  = re.compile(r'FUN_004559a0\(([^)]*)\);')

def trace(path, reg_fn):
    cur, pend = {}, []
    out = []
    for no, ln in enumerate(open(path, 'r', encoding='utf-8', errors='replace'), 1):
        s = ln.strip()
        m = RE_DWORD.match(s)
        if m:
            var, idx, val = m.group(1), int(m.group(2)), int(m.group(3), 16)
            if idx >= 3:
                off = (idx - 3) * 4
                b = val.to_bytes(4, 'little')
                for k in range(4):
                    cur.setdefault(var, {})[off + k] = bytes([b[k]])
                continue
        m = RE_WORD.match(s)
        if m:
            var, idx, val = m.group(1), int(m.group(2)), int(m.group(3), 0)
            off = (idx - 3) * 4
            b = (val & 0xFFFF).to_bytes(2, 'little')
            for k in range(2):
                cur.setdefault(var, {})[off + k] = bytes([b[k]])
            continue
        m = RE_BYTE.match(s)
        if m:
            var, idx, val = m.group(1), int(m.group(2)), int(m.group(3), 0)
            cur.setdefault(var, {})[(idx - 3) * 4] = bytes([val & 0xFF])
            continue
        m = RE_LEN.match(s)
        if m:
            var, L = m.group(1), int(m.group(2), 0)
            d = cur.get(var, {})
            if d:
                buf = bytearray()
                for off in range(L):
                    buf += d.get(off, b'\x00')[:1]
                z = buf.find(b'\x00')
                if z >= 0:
                    buf = buf[:z]
                pend.append(buf.decode('latin1'))
                cur[var] = {}
            continue
        m = RE_AD.search(s)
        if m:
            out.append((no, 'AD', m.group(1).strip()))
            continue
        m = RE_TMPL.search(s)
        if m:
            out.append((no, 'TMPL', m.group(1).strip()))
            continue
        if reg_fn in s:
            name = pend.pop() if pend else '???'
            out.append((no, 'REG', name))
            continue
    return out

for path, fn, label in [
        (DEC + r'\FUN_00457b90_00457b90.c', 'FUN_0045aa00', 'TECHNIQUES'),
        (DEC + r'\FUN_004564c0_004564c0.c', 'FUN_0045a7b0', 'TEXTSTAGES')]:
    print('===== %s =====' % label)
    idx = 0
    for no, kind, val in trace(path, fn):
        if kind == 'REG':
            print('%6d  REG  id=%-3d %s' % (no, idx, val))
            idx += 1
        else:
            print('%6d  %-4s %s' % (no, kind, val))
    print()
