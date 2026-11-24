  0x005cb3a0: push     ebp
  0x005cb3a1: mov      ebp, esp
  0x005cb3a3: and      esp, 0xfffffff8
  0x005cb3a6: sub      esp, 0x14
  0x005cb3a9: push     ebx
  0x005cb3aa: push     esi
  0x005cb3ab: push     edi
  0x005cb3ac: mov      edi, dword ptr [ebp + 8]
  0x005cb3af: mov      esi, ecx
  0x005cb3b1: test     edi, edi
  0x005cb3b3: js       0x5cb48a
  0x005cb3b9: mov      ebx, dword ptr [0x715340]
  0x005cb3bf: nop      
  0x005cb3c0: mov      ecx, dword ptr [esi + 0x278]
  0x005cb3c6: cmp      ecx, -1
  0x005cb3c9: je       0x5cb3fb
  0x005cb3cb: mov      edi, dword ptr [0x77244c]
  0x005cb3d1: add      edi, 0x488
  0x005cb3d7: cmp      ecx, 0x1fff
  0x005cb3dd: ja       0x5cb3e4  ; "j"
  0x005cb3df: lea      edi, [edi + ecx*4]
  0x005cb3e2: jmp      0x5cb3f1
  0x005cb3e4: push     0
  0x005cb3e6: push     0
  0x005cb3e8: push     1
  0x005cb3ea: push     0xc000008c
  0x005cb3ef: call     ebx
  0x005cb3f1: mov      eax, dword ptr [edi]
  0x005cb3f3: test     eax, eax
  0x005cb3f5: je       0x5cb3fb
  0x005cb3f7: mov      esi, eax
  0x005cb3f9: jmp      0x5cb3c0
  0x005cb3fb: mov      edi, dword ptr [ebp + 8]
  0x005cb3fe: cmp      edi, 0x10
  0x005cb401: jge      0x5cb408  ; "j"
  0x005cb403: lea      eax, [esi + edi*4]
  0x005cb406: jmp      0x5cb417
  0x005cb408: push     0
  0x005cb40a: push     0
  0x005cb40c: push     1
  0x005cb40e: push     0xc000008c
  0x005cb413: call     ebx
  0x005cb415: mov      eax, esi
  0x005cb417: cmp      dword ptr [eax + 0x6c], 0
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
  0x005cb4da: lea      esi, [esi + edx*4]
  0x005cb4dd: jmp      0x5cb4ec
  0x005cb4df: push     0
  0x005cb4e1: push     0
  0x005cb4e3: push     1
  0x005cb4e5: push     0xc000008c
  0x005cb4ea: call     edi
  0x005cb4ec: mov      eax, dword ptr [esi]
  0x005cb4ee: test     eax, eax
  0x005cb4f0: je       0x5cb503
  0x005cb4f2: cmp      dword ptr [eax + 0x278], -1
  0x005cb4f9: mov      edx, eax
  0x005cb4fb: mov      dword ptr [esp + 0x18], edx
  0x005cb4ff: jne      0x5cb4c0
  0x005cb501: jmp      0x5cb507
  0x005cb503: mov      edx, dword ptr [esp + 0x18]
  0x005cb507: xor      ecx, ecx
  0x005cb509: mov      dword ptr [esp + 0x2c], 0
  0x005cb511: mov      dword ptr [esp + 0x28], 0
  0x005cb519: lea      edi, [edx + 0x6c]
  0x005cb51c: mov      dword ptr [esp + 0x20], 0
  0x005cb524: xor      esi, esi
  0x005cb526: mov      dword ptr [esp + 0x24], 0xffffff85
  0x005cb52e: mov      dword ptr [esp + 0x14], ecx
  0x005cb532: cmp      esi, 0xf
  0x005cb535: ja       0x5cb53c  ; "j"
  0x005cb537: lea      eax, [ecx + edi]
  0x005cb53a: jmp      0x5cb553
  0x005cb53c: push     0
  0x005cb53e: push     0
  0x005cb540: push     1
  0x005cb542: push     0xc000008c
  0x005cb547: call     dword ptr [0x715340]
  0x005cb54d: mov      edx, dword ptr [esp + 0x18]
  0x005cb551: mov      eax, edi
  0x005cb553: cmp      dword ptr [eax], 0
  0x005cb556: jge      0x5cb5aa
  0x005cb558: cmp      dword ptr [esp + 0x24], -0x7b
  0x005cb55d: jne      0x5cb573
  0x005cb55f: lea      eax, [esp + 0x30]
  0x005cb563: mov      ecx, edx
  0x005cb565: push     eax
  0x005cb566: call     0x5cb250
  0x005cb56b: movups   xmm0, xmmword ptr [eax]
  0x005cb56e: movups   xmmword ptr [esp + 0x20], xmm0
  0x005cb573: cmp      esi, 0xf
  0x005cb576: ja       0x5cb584  ; "j"
  0x005cb578: mov      eax, dword ptr [esp + 0x14]
  0x005cb57c: add      eax, edi
  0x005cb57e: mov      dword ptr [esp + 0x1c], eax
  0x005cb582: jmp      0x5cb599
  0x005cb584: push     0
  0x005cb586: push     0
  0x005cb588: push     1
  0x005cb58a: push     0xc000008c
  0x005cb58f: call     dword ptr [0x715340]
  0x005cb595: mov      dword ptr [esp + 0x1c], edi
  0x005cb599: mov      edx, esi
  0x005cb59b: lea      ecx, [esp + 0x20]
  0x005cb59f: call     0x580ea0
  0x005cb5a4: mov      ecx, dword ptr [esp + 0x1c]
  0x005cb5a8: mov      dword ptr [ecx], eax
  0x005cb5aa: cmp      esi, 0xf
  0x005cb5ad: ja       0x5cb5b8  ; "j"
  0x005cb5af: mov      ecx, dword ptr [esp + 0x14]
  0x005cb5b3: lea      eax, [ecx + edi]
  0x005cb5b6: jmp      0x5cb5cf
  0x005cb5b8: push     0
  0x005cb5ba: push     0
  0x005cb5bc: push     1
  0x005cb5be: push     0xc000008c
  0x005cb5c3: call     dword ptr [0x715340]
  0x005cb5c9: mov      ecx, dword ptr [esp + 0x14]
  0x005cb5cd: mov      eax, edi
  0x005cb5cf: mov      edx, dword ptr [ebp + 8]
  0x005cb5d2: inc      esi
  0x005cb5d3: mov      eax, dword ptr [eax]
  0x005cb5d5: mov      dword ptr [ecx + edx], eax
  0x005cb5d8: add      ecx, 4
  0x005cb5db: mov      edx, dword ptr [esp + 0x18]
  0x005cb5df: mov      dword ptr [esp + 0x14], ecx
  0x005cb5e3: cmp      esi, 8
  0x005cb5e6: jl       0x5cb532
  0x005cb5ec: pop      edi
  0x005cb5ed: pop      esi
  0x005cb5ee: mov      esp, ebp
  0x005cb5f0: pop      ebp
  0x005cb5f1: ret      4
  0x005cb5f4: int3     
  0x005cb5f5: int3     
  0x005cb5f6: int3     
  0x005cb5f7: int3     
  0x005cb5f8: int3     
  0x005cb5f9: int3     
  0x005cb5fa: int3     
  0x005cb5fb: int3     
  0x005cb5fc: int3     
  0x005cb5fd: int3     
  0x005cb5fe: int3     
  0x005cb5ff: int3     
