import struct, sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
EXE = r'C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe'
data = open(EXE,'rb').read()
IAT = 0x00715530
pat = b'\xFF\x15' + struct.pack('<I', IAT)
md = Cs(CS_ARCH_X86, CS_MODE_32); md.skipdata=True
i=0; n=0
while True:
    i = data.find(pat, i)
    if i < 0: break
    i+=1
    va = 0x400000 + 0x1000 + (i-0x400)
    lo = max(0, i-120); chunk = data[lo:i+40]
    ins = list(md.disasm(chunk, va-(i-lo)))
    txt = '\n'.join('%08X %s %s'%(x.address,x.mnemonic,x.op_str) for x in ins)
    flag = 'GLOB' if '0x772400' in txt else ''
    print('call site VA 0x%08X  %s' % (va, flag))
    n+=1
print('total call sites:', n)
