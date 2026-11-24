import os, struct, sys
from pathlib import Path
HERE = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, HERE)
from pe_imports_exports import PE
pe = PE(r"C:\diggles-ghidra\DigglesPort.dll")
base = pe.image_base
for s in pe.sections:
    print("sec %-8s va=0x%08X vsize=0x%X raw_size=0x%X raw_ptr=0x%X" % (s["name"], base+s["va"], s["vsize"], s["raw_size"], s["raw_ptr"]))
off = pe.va_to_off(0x10045538)
print("offset of 0x10045538 =", off)
d = pe.data[off:off+8*40]
for i in range(0, len(d), 8):
    q = struct.unpack_from("<Q", d, i)[0]
    print("[%2d] 0x%08X -> 0x%016X" % (i//8, 0x10045538+i, q))
