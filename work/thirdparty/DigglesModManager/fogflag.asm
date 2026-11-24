==============================================================================
func FUN_00464cc0 entry=0x00464cc0 size=152
==============================================================================
0x00464cc0  push     ebp
0x00464cc1  mov      ebp, esp
0x00464cc3  and      esp, 0xfffffff0
0x00464cc6  sub      esp, 0x18
0x00464cc9  push     esi
0x00464cca  mov      esi, dword ptr [0x76a338]
0x00464cd0  push     edi
0x00464cd1  push     1
0x00464cd3  mov      dword ptr [esp + 0x14], 0
0x00464cdb  lea      ecx, [esi + 0x5c]
0x00464cde  mov      dword ptr [esp + 0x20], 0
0x00464ce6  mov      dword ptr [esp + 0x18], 0
0x00464cee  mov      dword ptr [esp + 0x1c], 0
0x00464cf6  call     0x47e190
0x00464cfb  mov      eax, dword ptr [esi + 0x60]
0x00464cfe  mov      ecx, dword ptr [0x715340]
0x00464d04  lea      edx, [eax - 1]
0x00464d07  mov      dword ptr [esp + 0xc], edx
0x00464d0b  cmp      edx, eax
0x00464d0d  jb       0x464d26
0x00464d0f  push     0
0x00464d11  push     0
0x00464d13  push     1
0x00464d15  push     0xc000008c
0x00464d1a  call     ecx
0x00464d1c  mov      ecx, dword ptr [0x715340]
0x00464d22  mov      edx, dword ptr [esp + 0xc]
0x00464d26  mov      eax, dword ptr [esi + 0x5c]
0x00464d29  lea      edi, [edx + edx*4]
0x00464d2c  mov      dword ptr [eax + edi*4], 0
0x00464d33  cmp      edx, dword ptr [esi + 0x60]
0x00464d36  jb       0x464d45
0x00464d38  push     0
0x00464d3a  push     0
0x00464d3c  push     1
0x00464d3e  push     0xc000008c
0x00464d43  call     ecx
0x00464d45  mov      eax, dword ptr [esi + 0x5c]
0x00464d48  movups   xmm0, xmmword ptr [esp + 0x10]
0x00464d4d  movups   xmmword ptr [eax + edi*4 + 4], xmm0
0x00464d52  pop      edi
0x00464d53  pop      esi
0x00464d54  mov      esp, ebp
0x00464d56  pop      ebp
0x00464d57  ret      
