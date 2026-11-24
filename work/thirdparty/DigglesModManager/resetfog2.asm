  0x0057d580: push     ebp
  0x0057d581: mov      ebp, esp
  0x0057d583: sub      esp, 8
  0x0057d586: push     ebx
  0x0057d587: push     esi
  0x0057d588: push     edi
  0x0057d589: lea      edi, [ecx + 0xc84]
  0x0057d58f: xor      ebx, ebx
  0x0057d591: mov      ecx, dword ptr [0x715340]
  0x0057d597: mov      dword ptr [ebp - 8], edi
  0x0057d59a: nop      word ptr [eax + eax]
  0x0057d5a0: xor      esi, esi
  0x0057d5a2: cmp      ebx, 8
  0x0057d5a5: ja       0x57d5ac  ; "j"
  0x0057d5a7: lea      eax, [ebx + edi]
  0x0057d5aa: jmp      0x57d5c1
  0x0057d5ac: push     0
  0x0057d5ae: push     0
  0x0057d5b0: push     1
  0x0057d5b2: push     0xc000008c
  0x0057d5b7: call     ecx
  0x0057d5b9: mov      ecx, dword ptr [0x715340]
  0x0057d5bf: mov      eax, edi
  0x0057d5c1: cmp      esi, dword ptr [eax + 4]
  0x0057d5c4: jge      0x57d6c8
  0x0057d5ca: cmp      ebx, 8
  0x0057d5cd: ja       0x57d5d6  ; "j"
  0x0057d5cf: lea      eax, [ebx + edi]
  0x0057d5d2: mov      edi, eax
  0x0057d5d4: jmp      0x57d5e7
  0x0057d5d6: push     0
  0x0057d5d8: push     0
  0x0057d5da: push     1
  0x0057d5dc: push     0xc000008c
  0x0057d5e1: call     ecx
  0x0057d5e3: mov      eax, edi
  0x0057d5e5: add      edi, ebx
  0x0057d5e7: mov      dword ptr [ebp - 4], eax
  0x0057d5ea: cmp      esi, dword ptr [eax + 4]
  0x0057d5ed: jb       0x57d603
  0x0057d5ef: push     0
  0x0057d5f1: push     0
  0x0057d5f3: push     1
  0x0057d5f5: push     0xc000008c
  0x0057d5fa: call     dword ptr [0x715340]
  0x0057d600: mov      eax, dword ptr [ebp - 4]
  0x0057d603: mov      ecx, dword ptr [eax]
  0x0057d605: lea      edx, [esi*8]
  0x0057d60c: mov      eax, dword ptr [ebp + 8]
  0x0057d60f: add      ecx, edx
  0x0057d611: mov      eax, dword ptr [eax]
  0x0057d613: mov      edx, dword ptr [ecx]
  0x0057d615: sub      eax, 4
  0x0057d618: cmp      eax, edx
  0x0057d61a: jg       0x57d6b9
  0x0057d620: mov      eax, dword ptr [ebp + 8]
  0x0057d623: mov      eax, dword ptr [eax + 8]
  0x0057d626: add      eax, 4
  0x0057d629: cmp      edx, eax
  0x0057d62b: jge      0x57d6b9
  0x0057d631: mov      edx, dword ptr [ebp + 8]
  0x0057d634: mov      ecx, dword ptr [ecx + 4]
  0x0057d637: mov      eax, dword ptr [edx + 4]
  0x0057d63a: sub      eax, 4
  0x0057d63d: cmp      eax, ecx
  0x0057d63f: jg       0x57d6b9
  0x0057d641: mov      eax, dword ptr [edx + 0xc]
  0x0057d644: add      eax, 4
  0x0057d647: cmp      ecx, eax
  0x0057d649: jge      0x57d6b9
  0x0057d64b: cmp      ebx, 8
  0x0057d64e: jbe      0x57d664
  0x0057d650: push     0
  0x0057d652: push     0
  0x0057d654: push     1
  0x0057d656: push     0xc000008c
  0x0057d65b: call     dword ptr [0x715340]
  0x0057d661: mov      edi, dword ptr [ebp - 8]
  0x0057d664: mov      ecx, dword ptr [edi + 4]
  0x0057d667: cmp      esi, ecx
  0x0057d669: jb       0x57d697
  0x0057d66b: push     0
  0x0057d66d: push     0
  0x0057d66f: push     1
  0x0057d671: push     0xc000008c
  0x0057d676: call     dword ptr [0x715340]
  0x0057d67c: mov      ecx, dword ptr [edi + 4]
  0x0057d67f: cmp      esi, ecx
  0x0057d681: jb       0x57d697
  0x0057d683: push     0
  0x0057d685: push     0
  0x0057d687: push     1
  0x0057d689: push     0xc000008c
  0x0057d68e: call     dword ptr [0x715340]
  0x0057d694: mov      ecx, dword ptr [edi + 4]
  0x0057d697: lea      eax, [ecx - 1]
  0x0057d69a: cmp      esi, eax
  0x0057d69c: jge      0x57d6b2
  0x0057d69e: mov      edx, dword ptr [edi]
  0x0057d6a0: mov      eax, dword ptr [edx + ecx*8 - 8]
  0x0057d6a4: mov      ecx, dword ptr [edx + ecx*8 - 4]
  0x0057d6a8: mov      dword ptr [edx + esi*8], eax
  0x0057d6ab: mov      dword ptr [edx + esi*8 + 4], ecx
  0x0057d6af: mov      ecx, dword ptr [edi + 4]
  0x0057d6b2: lea      eax, [ecx - 1]
  0x0057d6b5: dec      esi
  0x0057d6b6: mov      dword ptr [edi + 4], eax
  0x0057d6b9: mov      ecx, dword ptr [0x715340]
  0x0057d6bf: inc      esi
  0x0057d6c0: mov      edi, dword ptr [ebp - 8]
  0x0057d6c3: jmp      0x57d5a2
  0x0057d6c8: add      ebx, 8
  0x0057d6cb: cmp      ebx, 0x10
  0x0057d6ce: jl       0x57d5a0
  0x0057d6d4: pop      edi
  0x0057d6d5: pop      esi
  0x0057d6d6: pop      ebx
  0x0057d6d7: mov      esp, ebp
  0x0057d6d9: pop      ebp
  0x0057d6da: ret      4
  0x0057d6dd: int3     
  0x0057d6de: int3     
  0x0057d6df: int3     
  0x0057d6e0: push     ebx
  0x0057d6e1: mov      ebx, esp
  0x0057d6e3: sub      esp, 8
  0x0057d6e6: and      esp, 0xfffffff8
  0x0057d6e9: add      esp, 4
  0x0057d6ec: push     ebp
  0x0057d6ed: mov      ebp, dword ptr [ebx + 4]
