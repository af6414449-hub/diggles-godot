Disassembly of C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe  VA 0x0054E480 - 0x0054E5C8

0x0054E480  mov      edi, ecx
0x0054E482  je       0x54e630
0x0054E488  mov      ecx, dword ptr [ebp + 8]
0x0054E48B  mov      eax, dword ptr [ecx]
0x0054E48D  sub      eax, 0x300
0x0054E492  je       0x54e4af
0x0054E494  sub      eax, 1
0x0054E497  jne      0x54e630
0x0054E49D  movzx    eax, word ptr [ecx + 0x10]
0x0054E4A1  push     eax
0x0054E4A2  call     dword ptr [0x715038]
0x0054E4A8  mov      ecx, 0x101
0x0054E4AD  jmp      0x54e4bf
0x0054E4AF  movzx    eax, word ptr [ecx + 0x10]
0x0054E4B3  push     eax
0x0054E4B4  call     dword ptr [0x715038]
0x0054E4BA  mov      ecx, 0x100
0x0054E4BF  movzx    edx, ax
0x0054E4C2  mov      ebx, 0xfd
0x0054E4C7  add      esp, 4
0x0054E4CA  mov      dword ptr [ebp + 8], ecx
0x0054E4CD  movzx    esi, dx
0x0054E4D0  lea      eax, [edx - 1]
0x0054E4D3  cmp      ax, bx
0x0054E4D6  ja       0x54e5e7
0x0054E4DC  cmp      ecx, 0x100
0x0054E4E2  jne      0x54e5e7
0x0054E4E8  lea      eax, [edx - 0x41]
0x0054E4EB  movzx    eax, ax
0x0054E4EE  lea      ecx, [edx - 0x30]
0x0054E4F1  cmp      cx, 9
0x0054E4F5  mov      dword ptr [ebp - 4], eax
0x0054E4F8  lea      eax, [edx - 0x60]
0x0054E4FB  setbe    bh
0x0054E4FE  cmp      ax, 9
0x0054E502  ja       0x54e50a
0x0054E504  mov      bl, 1
0x0054E506  mov      bh, bl
0x0054E508  jmp      0x54e50c
0x0054E50A  xor      bl, bl
0x0054E50C  test     bl, bl
0x0054E50E  movzx    ecx, cx
0x0054E511  movzx    eax, dx
0x0054E514  cmove    ecx, eax
0x0054E517  movzx    esi, cx
0x0054E51A  cmp      esi, 0x6d
0x0054E51D  je       0x54e53c
0x0054E51F  cmp      esi, 0x6a
0x0054E522  je       0x54e53c
0x0054E524  mov      eax, 0x9a
0x0054E529  cmp      si, ax
0x0054E52C  je       0x54e53c
0x0054E52E  cmp      esi, 0x6f
0x0054E531  je       0x54e53c
0x0054E533  cmp      esi, 0x6b
0x0054E536  je       0x54e53c
0x0054E538  xor      dl, dl
0x0054E53A  jmp      0x54e53e
0x0054E53C  mov      dl, 1
0x0054E53E  mov      eax, 0x97
0x0054E543  cmp      si, ax
0x0054E546  je       0x54e556
0x0054E548  mov      eax, 0x98
0x0054E54D  cmp      si, ax
0x0054E550  je       0x54e556
0x0054E552  xor      cl, cl
0x0054E554  jmp      0x54e558
0x0054E556  mov      cl, 1
0x0054E558  mov      eax, 0xbc
0x0054E55D  cmp      si, ax
0x0054E560  je       0x54e5a2
0x0054E562  mov      eax, 0xbe
0x0054E567  cmp      si, ax
0x0054E56A  je       0x54e5a2
0x0054E56C  mov      eax, 0x9b
0x0054E571  cmp      si, ax
0x0054E574  je       0x54e5a2
0x0054E576  mov      eax, 0x9c
0x0054E57B  cmp      si, ax
0x0054E57E  je       0x54e5a2
0x0054E580  mov      eax, 0x9d
0x0054E585  cmp      si, ax
0x0054E588  je       0x54e5a2
0x0054E58A  mov      eax, 0x9e
0x0054E58F  cmp      si, ax
0x0054E592  je       0x54e5a2
0x0054E594  mov      eax, 0x99
0x0054E599  cmp      si, ax
0x0054E59C  je       0x54e5a2
0x0054E59E  xor      al, al
0x0054E5A0  jmp      0x54e5a4
0x0054E5A2  mov      al, 1
0x0054E5A4  cmp      word ptr [ebp - 4], 0x19
0x0054E5A9  jbe      0x54e5c7
0x0054E5AB  test     bh, bh
0x0054E5AD  jne      0x54e5c7
0x0054E5AF  test     dl, dl
0x0054E5B1  jne      0x54e5c7
0x0054E5B3  test     cl, cl
0x0054E5B5  jne      0x54e5c7
0x0054E5B7  cmp      esi, 0x20
0x0054E5BA  je       0x54e5c7
0x0054E5BC  test     al, al
0x0054E5BE  jne      0x54e5c7
0x0054E5C0  mov      ecx, dword ptr [ebp + 8]
0x0054E5C3  mov      eax, esi
0x0054E5C5  jmp      0x54e5fb
0x0054E5C7  .byte    0x6a
