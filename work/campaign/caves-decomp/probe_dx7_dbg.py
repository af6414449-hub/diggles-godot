import os, struct, sys
from pathlib import Path
HERE = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, HERE)
from pe_imports_exports import PE
pe = PE(r"C:\diggles-ghidra\DigglesPort.dll")
base = pe.image_base
text = [s for s in pe.sections if s["name"].startswith(".text")][0]
tlo, thi = base+text["va"], base+text["va"]+max(text["vsize"], text["raw_size"])
print("text range 0x%08X-0x%08X" % (tlo, thi))
# count qwords anywhere pointing into .text
hits = []
for sec in pe.sections:
    data = pe.data[sec["raw_ptr"]:sec["raw_ptr"]+sec["raw_size"]]
    for i in range(0, len(data)-7):
        q = struct.unpack_from("<Q", data, i)[0]
        if tlo <= q < thi:
            hits.append((sec["name"], base+sec["va"]+i, q))
print("qwords into .text:", len(hits))
from collections import Counter
print(Counter(h[0] for h in hits))
for h in hits[:15]:
    print("  %s 0x%08X -> 0x%08X" % h)
# dump ctor bytes
off = pe.va_to_off(0x10009080)
b = pe.data[off:off+117]
print("ctor bytes:", b.hex())
