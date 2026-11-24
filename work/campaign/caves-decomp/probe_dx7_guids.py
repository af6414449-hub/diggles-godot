import os, struct, sys
from pathlib import Path
HERE = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, HERE)
from pe_imports_exports import PE
pe = PE(r"C:\diggles-ghidra\DigglesPort.dll")
base = pe.image_base
def guid(va):
    off = pe.va_to_off(va)
    d1, d2, d3 = struct.unpack_from("<IHH", pe.data, off)
    d4 = pe.data[off+8:off+16]
    return "%08X-%04X-%04X-%s-%s" % (d1, d2, d3, d4[:2].hex().upper(), d4[2:].hex().upper())
def dwords(va, n):
    off = pe.va_to_off(va); out=[]
    for i in range(n):
        out.append(struct.unpack_from("<I", pe.data, off+i*4)[0])
    return out
names = {
 0x10043400:"DD7 QI GUID (factory)", 0x10043410:"surface QI GUID", 0x10043420:"clipper QI GUID",
 0x10044738:"ctx QI GUID", 0x10044760:"feature levels array", 0x10044788:"adapter1 GUID",
 0x100447c4:"DXGI GUID", 0x100447d4:"GUID@447d4", 0x100447e4:"GUID@447e4", 0x100447f4:"QI GUID@447f4",
 0x10044728:"GUID@44728", 0x10045680:"str",
}
for va, nm in sorted(names.items()):
    if nm == "feature levels array":
        print("0x%08X %s: %s" % (va, nm, [hex(x) for x in dwords(va, 7)]))
    else:
        try:
            print("0x%08X %-22s %s" % (va, nm, guid(va)))
        except Exception as e:
            print("0x%08X %s ERR %s" % (va, nm, e))
# exe side GUID used with DirectDrawCreateExPort
exe = PE(r"C:\diggles-ghidra\Diggles.exe")
off = exe.va_to_off(0x007156a0)
d1, d2, d3 = struct.unpack_from("<IHH", exe.data, off); d4 = exe.data[off+8:off+16]
print("EXE 0x007156a0 -> %08X-%04X-%04X-%s-%s" % (d1, d2, d3, d4[:2].hex().upper(), d4[2:].hex().upper()))
