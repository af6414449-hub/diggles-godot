Disassembly of C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe  VA 0x004E4CF0 - 0x004E4EA0

0x004E4CF0  push     ebp
0x004E4CF1  mov      ebp, esp
0x004E4CF3  mov      eax, dword ptr [ebp + 0xc]
0x004E4CF6  mov      ecx, eax
0x004E4CF8  push     ebx
0x004E4CF9  push     esi
0x004E4CFA  sar      ecx, 0x10
0x004E4CFD  cmp      eax, 0x200
0x004E4D02  push     edi
0x004E4D03  push     0x80
0x004E4D08  cmovle   ecx, eax
0x004E4D0B  push     0xc930f8
0x004E4D10  shl      ecx, 0x10
0x004E4D13  push     ecx
0x004E4D14  call     dword ptr [0x715428]
0x004E4D1A  mov      esi, 0xc930f8
0x004E4D1F  lea      ecx, [esi + 1]
0x004E4D22  mov      al, byte ptr [esi]
0x004E4D24  inc      esi
0x004E4D25  test     al, al
0x004E4D27  jne      0x4e4d22
0x004E4D29  sub      esi, ecx
0x004E4D2B  mov      edx, 4
0x004E4D30  push     0x19
0x004E4D32  lea      ecx, [esi + 1]
0x004E4D35  cmp      ecx, edx
0x004E4D37  mov      edi, ecx
0x004E4D39  cmovl    edi, edx
0x004E4D3C  add      edi, 0xb
0x004E4D3F  and      edi, 0xfffffff0
0x004E4D42  add      edi, edx
0x004E4D44  mov      edx, 0x7364b0
0x004E4D49  lea      ecx, [edi + 0xc]
0x004E4D4C  call     0x6ba810
0x004E4D51  mov      ebx, eax
0x004E4D53  lea      eax, [esi + 1]
0x004E4D56  push     eax
0x004E4D57  lea      ecx, [ebx + 0xc]
0x004E4D5A  mov      byte ptr [ecx], 0
0x004E4D5D  mov      dword ptr [ebx + 4], edi
0x004E4D60  mov      edi, dword ptr [ebp + 8]
0x004E4D63  push     0xc930f8
0x004E4D68  push     ecx
0x004E4D69  mov      dword ptr [ebx + 8], 0xffffffff
0x004E4D70  mov      dword ptr [ebx], 0
0x004E4D76  mov      dword ptr [edi], ebx
0x004E4D78  call     0x6d2250
0x004E4D7D  add      esp, 0x10
0x004E4D80  mov      dword ptr [ebx + 8], esi
0x004E4D83  inc      dword ptr [ebx]
0x004E4D85  mov      eax, edi
0x004E4D87  pop      edi
0x004E4D88  pop      esi
0x004E4D89  pop      ebx
0x004E4D8A  pop      ebp
0x004E4D8B  ret      8
0x004E4D8E  int3     
0x004E4D8F  int3     
0x004E4D90  push     ebp
0x004E4D91  mov      ebp, esp
0x004E4D93  push     -1
0x004E4D95  push     0x6fb5f0
0x004E4D9A  mov      eax, dword ptr fs:[0]
0x004E4DA0  push     eax
0x004E4DA1  push     ebx
0x004E4DA2  push     esi
0x004E4DA3  push     edi
0x004E4DA4  mov      eax, dword ptr [0x76700c]
0x004E4DA9  xor      eax, ebp
0x004E4DAB  push     eax
0x004E4DAC  lea      eax, [ebp - 0xc]
0x004E4DAF  mov      dword ptr fs:[0], eax
0x004E4DB5  mov      ebx, dword ptr [0x715428]
0x004E4DBB  xor      esi, esi
0x004E4DBD  nop      dword ptr [eax]
0x004E4DC0  push     0x80
0x004E4DC5  mov      eax, esi
0x004E4DC7  push     0xc93178
0x004E4DCC  shl      eax, 0x10
0x004E4DCF  push     eax
0x004E4DD0  call     ebx
0x004E4DD2  mov      edi, dword ptr [ebp + 8]
0x004E4DD5  mov      ecx, 0xc93178
0x004E4DDA  lea      eax, [edi + 0xc]
0x004E4DDD  nop      dword ptr [eax]
0x004E4DE0  mov      dl, byte ptr [ecx]
0x004E4DE2  cmp      dl, byte ptr [eax]
0x004E4DE4  jne      0x4e4e00
0x004E4DE6  test     dl, dl
0x004E4DE8  je       0x4e4dfc
0x004E4DEA  mov      dl, byte ptr [ecx + 1]
0x004E4DED  cmp      dl, byte ptr [eax + 1]
0x004E4DF0  jne      0x4e4e00
0x004E4DF2  add      ecx, 2
0x004E4DF5  add      eax, 2
0x004E4DF8  test     dl, dl
0x004E4DFA  jne      0x4e4de0
0x004E4DFC  xor      eax, eax
0x004E4DFE  jmp      0x4e4e05
0x004E4E00  sbb      eax, eax
0x004E4E02  or       eax, 1
0x004E4E05  test     eax, eax
0x004E4E07  je       0x4e4e15
0x004E4E09  inc      esi
0x004E4E0A  cmp      esi, 0x200
0x004E4E10  jl       0x4e4dc0
0x004E4E12  or       esi, 0xffffffff
0x004E4E15  mov      dword ptr [ebp - 4], 0
0x004E4E1C  test     edi, edi
0x004E4E1E  je       0x4e4e2c
0x004E4E20  add      dword ptr [edi], -1
0x004E4E23  jne      0x4e4e2c
0x004E4E25  mov      ecx, edi
0x004E4E27  call     0x6ba940
0x004E4E2C  mov      eax, esi
0x004E4E2E  mov      ecx, dword ptr [ebp - 0xc]
0x004E4E31  mov      dword ptr fs:[0], ecx
0x004E4E38  pop      ecx
0x004E4E39  pop      edi
0x004E4E3A  pop      esi
0x004E4E3B  pop      ebx
0x004E4E3C  mov      esp, ebp
0x004E4E3E  pop      ebp
0x004E4E3F  ret      4
0x004E4E42  int3     
0x004E4E43  int3     
0x004E4E44  int3     
0x004E4E45  int3     
0x004E4E46  int3     
0x004E4E47  int3     
0x004E4E48  int3     
0x004E4E49  int3     
0x004E4E4A  int3     
0x004E4E4B  int3     
0x004E4E4C  int3     
0x004E4E4D  int3     
0x004E4E4E  int3     
0x004E4E4F  int3     
0x004E4E50  push     ebp
0x004E4E51  mov      ebp, esp
0x004E4E53  push     -1
0x004E4E55  push     0x6faa20
0x004E4E5A  mov      eax, dword ptr fs:[0]
0x004E4E60  push     eax
0x004E4E61  push     ecx
0x004E4E62  push     ebx
0x004E4E63  push     esi
0x004E4E64  push     edi
0x004E4E65  mov      eax, dword ptr [0x76700c]
0x004E4E6A  xor      eax, ebp
0x004E4E6C  push     eax
0x004E4E6D  lea      eax, [ebp - 0xc]
0x004E4E70  mov      dword ptr fs:[0], eax
0x004E4E76  mov      edi, ecx
0x004E4E78  mov      esi, dword ptr [edi + 4]
0x004E4E7B  test     esi, esi
0x004E4E7D  jns      0x4e4e8c
0x004E4E7F  neg      esi
0x004E4E81  push     esi
0x004E4E82  call     0x4e4f40
0x004E4E87  jmp      0x4e4f13
0x004E4E8C  jle      0x4e4f13
0x004E4E92  cmp      esi, 1
0x004E4E95  jne      0x4e4ed4
0x004E4E97  lea      ebx, [esi - 1]
0x004E4E9A  cmp      ebx, esi
0x004E4E9C  jb       0x4e4eae
0x004E4E9E  push     0
