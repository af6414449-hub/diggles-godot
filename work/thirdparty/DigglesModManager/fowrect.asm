  0x005cb250: push     ebp
  0x005cb251: mov      ebp, esp
  0x005cb253: sub      esp, 0x10
  0x005cb256: push     edi
  0x005cb257: mov      edi, ecx
  0x005cb259: xorps    xmm1, xmm1
  0x005cb25c: movss    xmm2, dword ptr [edi + 0xc]
  0x005cb261: comiss   xmm1, xmm2
  0x005cb264: movss    dword ptr [ebp - 4], xmm2
  0x005cb269: jae      0x5cb374
  0x005cb26f: movss    xmm0, dword ptr [edi + 0x10]
  0x005cb274: comiss   xmm1, xmm0
  0x005cb277: movss    dword ptr [ebp - 8], xmm0
  0x005cb27c: jae      0x5cb374
  0x005cb282: mov      eax, dword ptr [edi + 0x39c]
  0x005cb288: movaps   xmm1, xmm2
  0x005cb28b: movaps   xmm3, xmm0
  0x005cb28e: cmp      eax, -1
  0x005cb291: je       0x5cb34d
  0x005cb297: push     esi
  0x005cb298: mov      esi, dword ptr [edi + 0x3a0]
  0x005cb29e: cmp      esi, -1
  0x005cb2a1: je       0x5cb34c
  0x005cb2a7: mov      ecx, dword ptr [0x772400]
  0x005cb2ad: push     eax
  0x005cb2ae: lea      ecx, [ecx + 0x5c8]
  0x005cb2b4: call     0x40b550
  0x005cb2b9: push     esi
  0x005cb2ba: mov      ecx, dword ptr [eax]
  0x005cb2bc: add      ecx, 0x34
  0x005cb2bf: call     0x4059a0
  0x005cb2c4: mov      ecx, dword ptr [0x772400]
  0x005cb2ca: push     dword ptr [edi + 0x39c]
  0x005cb2d0: mov      esi, dword ptr [edi + 0x3a0]
  0x005cb2d6: movss    xmm1, dword ptr [eax + 0x44]
  0x005cb2db: mulss    xmm1, dword ptr [0x736fcc]
  0x005cb2e3: lea      ecx, [ecx + 0x5c8]
  0x005cb2e9: addss    xmm1, dword ptr [ebp - 4]
  0x005cb2ee: movss    dword ptr [ebp - 0xc], xmm1
  0x005cb2f3: movss    xmm1, dword ptr [eax + 0x48]
  0x005cb2f8: mulss    xmm1, dword ptr [0x736fcc]
