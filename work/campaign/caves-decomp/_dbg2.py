import re
pat = r"\*\(undefined4 \*\)\(iVar1 \+(?:(0x[0-9a-fA-F]+|\d+) \+ )?[^*]*\* 0x48\) = (0x[0-9a-fA-F]+);"
s = '*(undefined4 *)(iVar1 + 0x10 + uVar4 * 0x48) = 0xb;'
m = re.search(pat, s)
print('pattern:', pat)
print('match:', m.groups() if m else None)
m2 = re.search(r"iVar1 \+(?:(0x[0-9a-fA-F]+|\d+) \+ )?[^*]*\* 0x48", s)
print('m2:', m2.groups() if m2 else None)
m3 = re.search(r"\+(?:(0x[0-9a-fA-F]+|\d+) \+ )?", s)
print('m3:', m3.groups() if m3 else None)
