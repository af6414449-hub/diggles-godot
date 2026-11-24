# -*- coding: utf-8 -*-
"""Z38 v2: full dump of technique records (0x6C) and shader records (0x48)."""
import re

DEC = r'C:\diggles-ghidra\out\decomp'

RE_DWORD = re.compile(r'^\s*([A-Za-z_]\w*)\[(\d+)\]\s*=\s*0x([0-9A-Fa-f]{1,8});')
RE_WORD  = re.compile(r'^\s*\*\(undefined2 \*\)\(\(?(?:int\))?(\w+) \+ (\d+)\)\s*=\s*(0x[0-9A-Fa-f]{1,4}|\d+);')
RE_BYTE  = re.compile(r'^\s*\*\(undefined1 \*\)\(\(?(?:int\))?(\w+) \+ (\d+)\)\s*=\s*(0x[0-9A-Fa-f]{1,2}|\d+);')
RE_LEN   = re.compile(r'^\s*([A-Za-z_]\w*)\[2\]\s*=\s*(0x[0-9A-Fa-f]+|\d+);')
RE_FIELD = re.compile(r'^\s*(?:local_24|\*local_24)\[?(\d+)?\]?\s*=\s*(0x[0-9A-Fa-f]+|-?\d+);')
RE_FIELD2= re.compile(r'^\s*\*\(undefined4 \*\)\((?:int \*)?\w+ \+ ([^)]*)\)\s*=\s*(0x[0-9A-Fa-f]+|-?\d+);')

FIELDNAMES = ['ZEnable','ZWriteEnable','ZFuncMode','AlphaEnable','AlphaTestEnable','AlphaFuncMode',
              'AlphaRefValue','SrcBlendMode','DestBlendMode','SpecularEnable','CullMode','Lighting',
              'GlowEnable','GlowSize','GlowColor','EnvMapEnable','Internal40',
              'TextStage0','TextStage1','TextStage2','TextStage3','TextStage4','TextStage5',
              'TextStage6','TextStage7','Name','ParentName']

def parse(path, reg_fn, base_reg):
    out = []
    pend, cur = [], {}
    rec = None
    counter = 0
    for ln in open(path, 'r', encoding='utf-8', errors='replace'):
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
                    b = d.get(off, b'\x00')
                    buf += b[:1]
                z = buf.find(b'\x00')
                if z >= 0:
                    buf = buf[:z]
                pend.append(buf.decode('latin1'))
                cur[var] = {}
            continue
        if reg_fn in s:
            name = pend.pop() if pend else '???'
            rec = {'id': counter, 'name': name, 'f': {}}
            counter += 1
            out.append(rec)
            continue
        if base_reg in s:
            # shader record written via *(undefined4 *)(iVar1 + off + id*0x48)
            m2 = RE_FIELD2.match(s)
            if m2 and rec is not None:
                mnum = re.match(r'\s*(0x[0-9A-Fa-f]+|\d+)', m2.group(1))
                off = int(mnum.group(1), 0) if mnum else 0
                rec['f'][off] = int(m2.group(2), 0)
            continue
        if rec is not None:
            m2 = RE_FIELD.match(s)
            if m2:
                idx = m2.group(1)
                if idx is None:
                    rec['f'][0] = int(m2.group(2), 0)
                else:
                    rec['f'][int(idx)] = int(m2.group(2), 0)
    return out

tech = parse(DEC + r'\FUN_00457b90_00457b90.c', 'FUN_0045aa00', 'FUN_0045aa00_never')
sh = parse(DEC + r'\FUN_0045a130_0045a130.c', 'FUN_0045ac70', 'FUN_0045ac70')

print('=== TECHNIQUES (%d) ===' % len(tech))
for r in tech:
    f = r['f']
    row = []
    for k in range(0, 27):
        if k in f:
            nm = FIELDNAMES[k] if k < len(FIELDNAMES) else 'f%d' % k
            row.append('%s=%s' % (nm, f[k]))
    print('%2d %-26s %s' % (r['id'], r['name'], '  '.join(row)))
print()
print('=== SHADERS (%d) ===' % len(sh))
for r in sh:
    f = r['f']
    print('%2d %-20s %s' % (r['id'], r['name'], ' '.join('%d:%d' % (k, f[k]) for k in sorted(f))))
