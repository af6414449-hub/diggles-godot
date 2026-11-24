Disassembly of C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe  VA 0x006BC340 - 0x006BC420

0x006BC340  or       byte ptr [edx], dh
0x006BC342  ror      byte ptr [ebx - 0x769b0bb3], 0xd
0x006BC349  add      byte ptr [eax], al
0x006BC34B  add      byte ptr [eax], al
0x006BC34D  pop      ecx
0x006BC34E  pop      edi
0x006BC34F  pop      esi
0x006BC350  pop      ebx
0x006BC351  mov      esp, ebp
0x006BC353  pop      ebp
0x006BC354  ret      4
0x006BC357  mov      ecx, dword ptr [ebp + 8]
0x006BC35A  cmp      dword ptr [ecx], 0
0x006BC35D  jne      0x6bc3b9
0x006BC35F  push     0x7366b8
0x006BC364  lea      ecx, [ebx + 8]
0x006BC367  call     0x6b9200
0x006BC36C  mov      ecx, dword ptr [esi]
0x006BC36E  mov      edi, eax
0x006BC370  mov      edx, dword ptr [edi]
0x006BC372  mov      dword ptr [esi], edx
0x006BC374  test     edx, edx
0x006BC376  je       0x6bc37a
0x006BC378  inc      dword ptr [edx]
0x006BC37A  test     ecx, ecx
0x006BC37C  je       0x6bc388
0x006BC37E  add      dword ptr [ecx], -1
0x006BC381  jne      0x6bc388
0x006BC383  call     0x6ba940
0x006BC388  mov      eax, dword ptr [edi]
0x006BC38A  mov      ecx, dword ptr [esi]
0x006BC38C  push     0
0x006BC38E  push     0
0x006BC390  mov      eax, dword ptr [eax + 8]
0x006BC393  push     1
0x006BC395  push     0xc000008c
0x006BC39A  mov      dword ptr [ecx + 8], eax
0x006BC39D  call     dword ptr [0x715340]
0x006BC3A3  xor      al, al
0x006BC3A5  mov      ecx, dword ptr [ebp - 0xc]
0x006BC3A8  mov      dword ptr fs:[0], ecx
0x006BC3AF  pop      ecx
0x006BC3B0  pop      edi
0x006BC3B1  pop      esi
0x006BC3B2  pop      ebx
0x006BC3B3  mov      esp, ebp
0x006BC3B5  pop      ebp
0x006BC3B6  ret      4
0x006BC3B9  call     dword ptr [0x7152f4]
0x006BC3BF  mov      edi, dword ptr [ebp + 8]
0x006BC3C2  mov      ecx, edi
0x006BC3C4  inc      dword ptr [0x772dc0]
0x006BC3CA  mov      dword ptr [ebp - 0x1c], eax
0x006BC3CD  call     0x6bbab0
0x006BC3D2  test     al, al
0x006BC3D4  je       0x6bc3dc
0x006BC3D6  inc      dword ptr [0x772dc4]
0x006BC3DC  push     0
0x006BC3DE  push     dword ptr [edi]
0x006BC3E0  push     dword ptr [ebx]
0x006BC3E2  call     dword ptr [0x715530]
0x006BC3E8  add      esp, 0xc
0x006BC3EB  cmp      eax, 1
0x006BC3EE  jne      0x6bc63e
0x006BC3F4  push     dword ptr [ebx]
0x006BC3F6  call     dword ptr [0x715580]
0x006BC3FC  mov      edi, eax
0x006BC3FE  add      esp, 4
0x006BC401  mov      dword ptr [ebp - 0x2c], edi
0x006BC404  test     edi, edi
0x006BC406  je       0x6bc40a
0x006BC408  inc      dword ptr [edi]
0x006BC40A  mov      dword ptr [ebp - 4], 0
0x006BC411  push     dword ptr [ebx]
0x006BC413  call     dword ptr [0x71556c]
0x006BC419  add      esp, 4
0x006BC41C  lea      ecx, [ebp - 0x10]
0x006BC41F  push     eax
