# -*- coding: utf-8 -*-
"""Z38: locate functions containing the pool-string push sites."""
import csv, sys

IDX = r'C:\diggles-ghidra\out\index.tsv'
targets = [0x4563A7, 0x456662, 0x456768, 0x457555, 0x458FB4, 0x459396, 0x459795, 0x4598A7, 0x4599CF, 0x45A386]

rows = []
with open(IDX, 'r', encoding='utf-8', errors='replace') as f:
    r = csv.DictReader(f, delimiter='\t')
    for row in r:
        try:
            entry = int(row['entry'], 16)
            size = int(row['size'])
        except Exception:
            continue
        rows.append((entry, size, row['func'], row['file']))

rows.sort()
for t in targets:
    hit = None
    for entry, size, fn, fl in rows:
        if entry <= t < entry + size:
            hit = (entry, size, fn, fl)
            break
    if hit:
        print('0x%08X -> %s  entry=0x%08X size=%d  file=%s' % (t, hit[2], hit[0], hit[1], hit[3]))
    else:
        print('0x%08X -> ???' % t)
