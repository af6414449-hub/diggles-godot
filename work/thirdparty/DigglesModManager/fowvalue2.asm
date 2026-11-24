  0x005cb41b: jge      0x5cb45c
  0x005cb41d: lea      eax, [esp + 0x10]
  0x005cb421: mov      ecx, esi
  0x005cb423: push     eax
  0x005cb424: call     0x5cb250
  0x005cb429: lea      eax, [esi + 0x6c]
  0x005cb42c: mov      dword ptr [esp + 0xc], eax
  0x005cb430: cmp      edi, 0x10
  0x005cb433: jge      0x5cb43e  ; "j"
  0x005cb435: lea      eax, [eax + edi*4]
  0x005cb438: mov      dword ptr [esp + 0xc], eax
  0x005cb43c: jmp      0x5cb44b
  0x005cb43e: push     0
  0x005cb440: push     0
  0x005cb442: push     1
  0x005cb444: push     0xc000008c
  0x005cb449: call     ebx
  0x005cb44b: mov      edx, edi
  0x005cb44d: lea      ecx, [esp + 0x10]
  0x005cb451: call     0x580ea0
  0x005cb456: mov      ecx, dword ptr [esp + 0xc]
  0x005cb45a: mov      dword ptr [ecx], eax
  0x005cb45c: cmp      edi, 0x10
  0x005cb45f: jge      0x5cb471  ; "j"
  0x005cb461: mov      eax, dword ptr [esi + edi*4 + 0x6c]
  0x005cb465: lea      esi, [esi + edi*4]
  0x005cb468: pop      edi
  0x005cb469: pop      esi
  0x005cb46a: pop      ebx
  0x005cb46b: mov      esp, ebp
  0x005cb46d: pop      ebp
  0x005cb46e: ret      4
  0x005cb471: push     0
  0x005cb473: push     0
  0x005cb475: push     1
  0x005cb477: push     0xc000008c
  0x005cb47c: call     ebx
  0x005cb47e: mov      eax, dword ptr [esi + 0x6c]
  0x005cb481: pop      edi
  0x005cb482: pop      esi
  0x005cb483: pop      ebx
  0x005cb484: mov      esp, ebp
  0x005cb486: pop      ebp
  0x005cb487: ret      4
  0x005cb48a: pop      edi
  0x005cb48b: pop      esi
  0x005cb48c: mov      eax, 0xff
  0x005cb491: pop      ebx
  0x005cb492: mov      esp, ebp
  0x005cb494: pop      ebp
  0x005cb495: ret      4
  0x005cb498: int3     
  0x005cb499: int3     
  0x005cb49a: int3     
  0x005cb49b: int3     
  0x005cb49c: int3     
  0x005cb49d: int3     
  0x005cb49e: int3     
  0x005cb49f: int3     
  0x005cb4a0: push     ebp
  0x005cb4a1: mov      ebp, esp
  0x005cb4a3: and      esp, 0xfffffff0
  0x005cb4a6: sub      esp, 0x38
  0x005cb4a9: mov      edx, ecx
  0x005cb4ab: push     esi
  0x005cb4ac: push     edi
  0x005cb4ad: mov      dword ptr [esp + 0x18], edx
  0x005cb4b1: cmp      dword ptr [edx + 0x278], -1
  0x005cb4b8: je       0x5cb507
  0x005cb4ba: mov      edi, dword ptr [0x715340]
  0x005cb4c0: mov      esi, dword ptr [0x77244c]
  0x005cb4c6: mov      edx, dword ptr [edx + 0x278]
  0x005cb4cc: add      esi, 0x488
  0x005cb4d2: cmp      edx, 0x1fff
  0x005cb4d8: ja       0x5cb4df  ; "j"
