==============================================================================
func FUN_005032a0 entry=0x005032a0 size=372
==============================================================================
0x005032a0  push     ebp
0x005032a1  mov      ebp, esp
0x005032a3  push     -1
0x005032a5  push     0x700b25
0x005032aa  mov      eax, dword ptr fs:[0]
0x005032b0  push     eax
0x005032b1  sub      esp, 0xc
0x005032b4  push     ebx
0x005032b5  push     esi
0x005032b6  push     edi
0x005032b7  mov      eax, dword ptr [0x76700c]
0x005032bc  xor      eax, ebp
0x005032be  push     eax
0x005032bf  lea      eax, [ebp - 0xc]
0x005032c2  mov      dword ptr fs:[0], eax
0x005032c8  mov      edi, ecx
0x005032ca  mov      dword ptr [ebp - 0x14], edi
0x005032cd  mov      ebx, dword ptr [ebp + 8]
0x005032d0  test     bx, bx
0x005032d3  je       0x503319
0x005032d5  cmp      bx, 0x7f
0x005032d9  jae      0x503319
0x005032db  cmp      bl, 0x41
0x005032de  jl       0x5032e5
0x005032e0  cmp      bl, 0x5a
0x005032e3  jle      0x5032fe
0x005032e5  cmp      bl, 0x30
0x005032e8  jl       0x5032ef
0x005032ea  cmp      bl, 0x39
0x005032ed  jle      0x5032fe
0x005032ef  cmp      bl, 0x6d
0x005032f2  je       0x5032fe
0x005032f4  cmp      bl, 0x20
0x005032f7  je       0x5032fe
0x005032f9  cmp      bl, 8
0x005032fc  jne      0x503319
0x005032fe  push     0x10
0x00503300  call     dword ptr [0x715424]
0x00503306  shr      eax, 0xf
0x00503309  mov      ecx, edi
0x0050330b  and      al, 1
0x0050330d  mov      byte ptr [ebp + 8], al
0x00503310  push     dword ptr [ebp + 8]
0x00503313  push     ebx
0x00503314  call     0x503190
0x00503319  call     0x4e4550
0x0050331e  push     0
0x00503320  push     0
0x00503322  push     0
0x00503324  mov      dword ptr [eax], 3
0x0050332a  lea      eax, [ebp + 8]
0x0050332d  mov      ecx, dword ptr [0x772400]
0x00503333  push     eax
0x00503334  lea      ecx, [ecx + 0x148]
0x0050333a  call     0x4e4c40
0x0050333f  mov      dword ptr [ebp - 4], 0
0x00503346  mov      esi, dword ptr [ebp + 8]
0x00503349  mov      ecx, dword ptr [esi + 8]
0x0050334c  cmp      ecx, -1
0x0050334f  jne      0x503363
0x00503351  lea      ecx, [esi + 0xc]
0x00503354  lea      edx, [ecx + 1]
0x00503357  mov      al, byte ptr [ecx]
0x00503359  inc      ecx
0x0050335a  test     al, al
0x0050335c  jne      0x503357
0x0050335e  sub      ecx, edx
0x00503360  mov      dword ptr [esi + 8], ecx
0x00503363  test     ecx, ecx
0x00503365  jle      0x50337f
0x00503367  push     ecx
0x00503368  mov      ecx, dword ptr [0x772400]
0x0050336e  mov      eax, esp
0x00503370  mov      dword ptr [eax], esi
0x00503372  lea      ecx, [ecx + 0x368]
0x00503378  inc      dword ptr [esi]
0x0050337a  call     0x54ea20
0x0050337f  push     dword ptr [0x772384]
0x00503385  mov      edx, dword ptr [edi + 0x8194]
0x0050338b  lea      ecx, [ebp - 0x10]
0x0050338e  call     0x4ed780
0x00503393  add      esp, 4
0x00503396  push     0x80
0x0050339b  push     0xc931f8
0x005033a0  push     0
0x005033a2  mov      byte ptr [ebp - 4], 1
0x005033a6  call     dword ptr [0x715428]
0x005033ac  mov      edi, dword ptr [ebp - 0x10]
0x005033af  push     0xc931f8
0x005033b4  lea      ecx, [edi + 0x3c]
0x005033b7  call     0x6b9200
0x005033bc  movzx    eax, bx
0x005033bf  lea      ebx, [edi + 4]
0x005033c2  mov      dword ptr [edi + 0x40], eax
0x005033c5  push     ecx
0x005033c6  mov      eax, esp
0x005033c8  mov      dword ptr [edi + 0x44], 0
0x005033cf  mov      dword ptr [eax], edi
0x005033d1  lock inc dword ptr [ebx]
0x005033d4  mov      ecx, dword ptr [ebp - 0x14]
0x005033d7  call     0x4ed820
0x005033dc  or       eax, 0xffffffff
0x005033df  lock xadd dword ptr [ebx], eax
0x005033e3  jne      0x5033ed
0x005033e5  mov      eax, dword ptr [edi]
0x005033e7  mov      ecx, edi
0x005033e9  push     1
0x005033eb  call     dword ptr [eax]
0x005033ed  mov      dword ptr [ebp - 4], 2
0x005033f4  add      dword ptr [esi], -1
0x005033f7  jne      0x503400
0x005033f9  mov      ecx, esi
0x005033fb  call     0x6ba940
0x00503400  mov      ecx, dword ptr [ebp - 0xc]
0x00503403  mov      dword ptr fs:[0], ecx
0x0050340a  pop      ecx
0x0050340b  pop      edi
0x0050340c  pop      esi
0x0050340d  pop      ebx
0x0050340e  mov      esp, ebp
0x00503410  pop      ebp
0x00503411  ret      8
