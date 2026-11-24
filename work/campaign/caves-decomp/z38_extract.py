# -*- coding: utf-8 -*-
"""Z38: extract registration order (id -> name) for textstages and techniques
from decompiled FUN_004564C0 (textstages) and FUN_00457B90 (techniques)."""
import re, sys

DEC = r'C:\diggles-ghidra\out\decomp'

RE_DWORD = re.compile(r'^\s*([A-Za-z_]\w*)\[(\d+)\]\s*=\s*0x([0-9A-Fa-f]{1,8});')
RE_WORD  = re.compile(r'^\s*\*\(undefined2 \*\)\(\(?(?:int\))?(\w+) \+ (\d+)\)\s*=\s*(0x[0-9A-Fa-f]{1,4}|\d+);')
RE_BYTE  = re.compile(r'^\s*\*\(undefined1 \*\)\(\(?(?:int\))?(\w+) \+ (\d+)\)\s*=\s*(0x[0-9A-Fa-f]{1,2}|\d+);')
RE_LEN   = re.compile(r'^\s*([A-Za-z_]\w*)\[2\]\s*=\s*(0x[0-9A-Fa-f]+|\d+);')
RE_TS    = re.compile(r'^\s*local_24\[(0x1[1-8]|\d+)\]\s*=\s*(0x[0-9A-Fa-f]+|-?\d+);')

def parse(path, reg_fn):
    """Return list of dicts: {id, name, ts:[...]}.  reg_fn = 'text'|'tech'."""
    out = []
    pend = []          # finalized strings awaiting registration
    cur = {}           # var -> {offset: bytes}
    rec = None
    counter = 0
    lines = open(path, 'r', encoding='utf-8', errors='replace').read().split('\n')
    for ln in lines:
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
            # idx == 2 is the length field -> handled by RE_LEN below
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
            off = (idx - 3) * 4
            cur.setdefault(var, {})[off] = bytes([val & 0xFF])
            continue
        m = RE_LEN.match(s)
        if m:
            var, ln_len = m.group(1), int(m.group(2), 0)
            d = cur.get(var, {})
            if not d:
                continue                      # not a string object (record field)
            buf = bytearray()
            for off in range(0, ln_len):
                b = d.get(off, b'\x00')
                buf += b if len(b) == 1 else b[:1]
            z = buf.find(b'\x00')
            if z >= 0:
                buf = buf[:z]
            pend.append((buf.decode('latin1'), ln_len))
            cur[var] = {}
            continue
        if reg_fn + '_CALL' in s:
            pass
        if ('FUN_0045a7b0' in s) or ('FUN_0045aa00' in s):
            name = pend.pop()[0] if pend else '???'
            rec = {'id': counter, 'name': name, 'ts': [None]*8}
            counter += 1
            out.append(rec)
            continue
        if rec is not None:
            m = RE_TS.match(s)
            if m:
                k = int(m.group(1), 0)
                v = int(m.group(2), 0)
                if 0x11 <= k <= 0x18:
                    rec['ts'][k-0x11] = v
    return out

txt = parse(DEC + r'\FUN_004564c0_004564c0.c', 'text')
print('=== TEXTSTAGES (FUN_004564C0) ===')
for r in txt:
    print('%3d  %-24s ts=%s' % (r['id'], r['name'], r['ts']))
print('total', len(txt))

tech = parse(DEC + r'\FUN_00457b90_00457b90.c', 'tech')
print()
print('=== TECHNIQUES (FUN_00457B90) ===')
for r in tech:
    print('%3d  %-26s ts=%s' % (r['id'], r['name'], r['ts']))
print('total', len(tech))
