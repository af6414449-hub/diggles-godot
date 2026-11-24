  0x0057dfc0: push     ebp
  0x0057dfc1: mov      ebp, esp
  0x0057dfc3: push     ecx
  0x0057dfc4: mov      eax, dword ptr fs:[0x2c]
  0x0057dfca: push     ebx
  0x0057dfcb: push     esi
  0x0057dfcc: push     edi
  0x0057dfcd: mov      ecx, dword ptr [eax]
  0x0057dfcf: mov      eax, dword ptr [0xca5478]
  0x0057dfd4: cmp      eax, dword ptr [ecx + 4]
  0x0057dfda: jg       0x57e0c7
  0x0057dfe0: mov      edi, dword ptr [0xca547c]
  0x0057dfe6: shl      edi, 6
  0x0057dfe9: mov      esi, dword ptr [edi + 0x773650]
  0x0057dfef: call     0x43fcc0
  0x0057dff4: mov      ecx, dword ptr [eax + 0x8000]
  0x0057dffa: mov      dword ptr [eax + ecx*4], esi
  0x0057dffd: inc      dword ptr [eax + 0x8000]
  0x0057e003: mov      eax, dword ptr [edi + 0x773654]
  0x0057e009: test     eax, eax
  0x0057e00b: jne      0x57e024
  0x0057e00d: call     0x6bd180
  0x0057e012: mov      dword ptr [edi + 0x773658], eax
  0x0057e018: mov      eax, dword ptr [edi + 0x773654]
  0x0057e01e: mov      dword ptr [edi + 0x77365c], edx
  0x0057e024: mov      ebx, dword ptr [ebp + 8]
  0x0057e027: inc      eax
  0x0057e028: mov      dword ptr [edi + 0x773654], eax
  0x0057e02e: mov      esi, 0xf
  0x0057e033: mov      edi, dword ptr [ebp + 0x14]
  0x0057e036: mov      edx, dword ptr [ebx]
  0x0057e038: mov      ax, word ptr [edx + 0x18]
  0x0057e03c: and      ax, 3
  0x0057e040: je       0x57e048
  0x0057e042: cmp      ax, 3
  0x0057e046: jne      0x57e05a
  0x0057e048: lea      ecx, [edi*4]
  0x0057e04f: mov      eax, esi
  0x0057e051: shl      eax, cl
  0x0057e053: not      eax
  0x0057e055: and      dword ptr [edx + 8], eax
  0x0057e058: mov      edx, dword ptr [ebx]
  0x0057e05a: mov      edx, dword ptr [edx + 8]
  0x0057e05d: lea      eax, [edi*4]
  0x0057e064: mov      ecx, eax
  0x0057e066: mov      dword ptr [ebp + 8], eax
  0x0057e069: shr      edx, cl
  0x0057e06b: and      edx, esi
  0x0057e06d: jne      0x57e073
  0x0057e06f: mov      edi, esi
  0x0057e071: jmp      0x57e090
  0x0057e073: test     dl, 8
  0x0057e076: jne      0x57e07f
  0x0057e078: mov      edi, 0xb
  0x0057e07d: jmp      0x57e090
  0x0057e07f: and      edx, 3
  0x0057e082: xor      edi, edi
  0x0057e084: shl      edx, 2
  0x0057e087: cmp      edx, 1
  0x0057e08a: lea      eax, [edx - 1]
  0x0057e08d: cmovae   edi, eax
  0x0057e090: push     dword ptr [ebp + 0x10]
  0x0057e093: push     dword ptr [ebp + 0xc]
  0x0057e096: call     0x597460
  0x0057e09b: cmp      edi, eax
  0x0057e09d: jl       0x57e0ab
  0x0057e09f: mov      eax, dword ptr [ebx]
  0x0057e0a1: mov      ecx, dword ptr [ebp + 8]
  0x0057e0a4: shl      esi, cl
  0x0057e0a6: not      esi
  0x0057e0a8: and      dword ptr [eax + 8], esi
  0x0057e0ab: mov      ecx, dword ptr [0xca547c]
  0x0057e0b1: shl      ecx, 6
  0x0057e0b4: add      ecx, 0x773650
  0x0057e0ba: call     0x43fd30
  0x0057e0bf: pop      edi
  0x0057e0c0: pop      esi
  0x0057e0c1: pop      ebx
  0x0057e0c2: pop      ecx
  0x0057e0c3: pop      ebp
  0x0057e0c4: ret      0x10
