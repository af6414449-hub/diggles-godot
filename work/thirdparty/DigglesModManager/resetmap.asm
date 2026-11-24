  0x0066a4f0: push     ebp
  0x0066a4f1: mov      ebp, esp
  0x0066a4f3: push     -1
  0x0066a4f5: push     0x70fb65
  0x0066a4fa: mov      eax, dword ptr fs:[0]
  0x0066a500: push     eax
  0x0066a501: sub      esp, 0x6c
  0x0066a504: mov      eax, dword ptr [0x76700c]
  0x0066a509: xor      eax, ebp
  0x0066a50b: mov      dword ptr [ebp - 0x10], eax
  0x0066a50e: push     esi
  0x0066a50f: push     edi
  0x0066a510: push     eax
  0x0066a511: lea      eax, [ebp - 0xc]
  0x0066a514: mov      dword ptr fs:[0], eax
  0x0066a51a: push     dword ptr [ebp + 0xc]
  0x0066a51d: lea      ecx, [ebp - 0x78]
  0x0066a520: call     0x6bc170
  0x0066a525: push     dword ptr [ebp + 0x14]
  0x0066a528: mov      esi, dword ptr [ebp + 0x10]
  0x0066a52b: lea      ecx, [ebp - 0x20]
  0x0066a52e: push     esi
  0x0066a52f: mov      dword ptr [ebp - 4], 0
  0x0066a536: call     0x4298b0
  0x0066a53b: mov      byte ptr [ebp - 4], 1
  0x0066a53f: cmp      esi, 5
  0x0066a542: je       0x66a558
  0x0066a544: push     4
  0x0066a546: lea      ecx, [ebp - 0x78]
  0x0066a549: call     0x6bc8f0
  0x0066a54e: mov      esi, 1
  0x0066a553: jmp      0x66a951  ; "j"
  0x0066a558: cmp      dword ptr [ebp - 0x18], 1
  0x0066a55c: mov      edi, dword ptr [0x715340]
  0x0066a562: jg       0x66a589
  0x0066a564: push     0
  0x0066a566: push     0
  0x0066a568: push     1
  0x0066a56a: push     0xc000008c
  0x0066a56f: call     edi
  0x0066a571: cmp      dword ptr [ebp - 0x1c], 0
  0x0066a575: ja       0x66a584
  0x0066a577: push     0
  0x0066a579: push     0
  0x0066a57b: push     1
  0x0066a57d: push     0xc000008c
  0x0066a582: call     edi
  0x0066a584: mov      esi, dword ptr [ebp - 0x20]
  0x0066a587: jmp      0x66a5a2
  0x0066a589: cmp      dword ptr [ebp - 0x1c], 1
  0x0066a58d: ja       0x66a59c
  0x0066a58f: push     0
  0x0066a591: push     0
  0x0066a593: push     1
  0x0066a595: push     0xc000008c
  0x0066a59a: call     edi
  0x0066a59c: mov      esi, dword ptr [ebp - 0x20]
  0x0066a59f: add      esi, 4
  0x0066a5a2: mov      esi, dword ptr [esi]
  0x0066a5a4: test     esi, esi
  0x0066a5a6: je       0x66a5db
  0x0066a5a8: inc      dword ptr [esi]
  0x0066a5aa: lea      eax, [ebp - 0x50]
  0x0066a5ad: push     eax
  0x0066a5ae: push     esi
  0x0066a5af: push     0
  0x0066a5b1: call     dword ptr [0x715574]  ; "d\6"
  0x0066a5b7: dec      eax
  0x0066a5b8: add      esp, 0xc
  0x0066a5bb: neg      eax
  0x0066a5bd: sbb      eax, eax
  0x0066a5bf: dec      dword ptr [esi]
  0x0066a5c1: and      eax, dword ptr [ebp - 0x50]
  0x0066a5c4: cmp      dword ptr [esi], 0
  0x0066a5c7: mov      dword ptr [ebp - 0x38], eax
  0x0066a5ca: mov      dword ptr [ebp - 0x14], eax
  0x0066a5cd: jg       0x66a5e9
  0x0066a5cf: push     esi
  0x0066a5d0: call     dword ptr [0x715540]  ; "|[6"
  0x0066a5d6: add      esp, 4
  0x0066a5d9: jmp      0x66a5e9
  0x0066a5db: mov      dword ptr [ebp - 0x38], 0
  0x0066a5e2: mov      dword ptr [ebp - 0x14], 0
  0x0066a5e9: cmp      dword ptr [ebp - 0x18], 2
  0x0066a5ed: jg       0x66a614
  0x0066a5ef: push     0
  0x0066a5f1: push     0
  0x0066a5f3: push     1
  0x0066a5f5: push     0xc000008c
  0x0066a5fa: call     edi
  0x0066a5fc: cmp      dword ptr [ebp - 0x1c], 0
  0x0066a600: ja       0x66a60f
  0x0066a602: push     0
  0x0066a604: push     0
  0x0066a606: push     1
  0x0066a608: push     0xc000008c
  0x0066a60d: call     edi
  0x0066a60f: mov      esi, dword ptr [ebp - 0x20]
  0x0066a612: jmp      0x66a62d
  0x0066a614: cmp      dword ptr [ebp - 0x1c], 2
  0x0066a618: ja       0x66a627
  0x0066a61a: push     0
  0x0066a61c: push     0
  0x0066a61e: push     1
  0x0066a620: push     0xc000008c
  0x0066a625: call     edi
  0x0066a627: mov      esi, dword ptr [ebp - 0x20]
  0x0066a62a: add      esi, 8
  0x0066a62d: mov      esi, dword ptr [esi]
  0x0066a62f: test     esi, esi
  0x0066a631: je       0x66a666
  0x0066a633: inc      dword ptr [esi]
  0x0066a635: lea      eax, [ebp - 0x54]
  0x0066a638: push     eax
  0x0066a639: push     esi
  0x0066a63a: push     0
  0x0066a63c: call     dword ptr [0x715574]  ; "d\6"
  0x0066a642: dec      eax
  0x0066a643: add      esp, 0xc
  0x0066a646: neg      eax
  0x0066a648: sbb      eax, eax
  0x0066a64a: dec      dword ptr [esi]
  0x0066a64c: and      eax, dword ptr [ebp - 0x54]
  0x0066a64f: cmp      dword ptr [esi], 0
  0x0066a652: mov      dword ptr [ebp - 0x3c], eax
  0x0066a655: mov      dword ptr [ebp - 0x24], eax
  0x0066a658: jg       0x66a674
  0x0066a65a: push     esi
  0x0066a65b: call     dword ptr [0x715540]  ; "|[6"
  0x0066a661: add      esp, 4
  0x0066a664: jmp      0x66a674
  0x0066a666: mov      dword ptr [ebp - 0x3c], 0
  0x0066a66d: mov      dword ptr [ebp - 0x24], 0
  0x0066a674: cmp      dword ptr [ebp - 0x18], 3
  0x0066a678: jg       0x66a69f
  0x0066a67a: push     0
  0x0066a67c: push     0
  0x0066a67e: push     1
  0x0066a680: push     0xc000008c
  0x0066a685: call     edi
  0x0066a687: cmp      dword ptr [ebp - 0x1c], 0
  0x0066a68b: ja       0x66a69a
  0x0066a68d: push     0
  0x0066a68f: push     0
  0x0066a691: push     1
  0x0066a693: push     0xc000008c
  0x0066a698: call     edi
  0x0066a69a: mov      esi, dword ptr [ebp - 0x20]
  0x0066a69d: jmp      0x66a6b8
  0x0066a69f: cmp      dword ptr [ebp - 0x1c], 3
  0x0066a6a3: ja       0x66a6b2
  0x0066a6a5: push     0
  0x0066a6a7: push     0
  0x0066a6a9: push     1
  0x0066a6ab: push     0xc000008c
  0x0066a6b0: call     edi
  0x0066a6b2: mov      esi, dword ptr [ebp - 0x20]
  0x0066a6b5: add      esi, 0xc
  0x0066a6b8: mov      esi, dword ptr [esi]
  0x0066a6ba: test     esi, esi
  0x0066a6bc: je       0x66a6f1
  0x0066a6be: inc      dword ptr [esi]
  0x0066a6c0: lea      eax, [ebp - 0x58]
  0x0066a6c3: push     eax
  0x0066a6c4: push     esi
  0x0066a6c5: push     0
  0x0066a6c7: call     dword ptr [0x715574]  ; "d\6"
  0x0066a6cd: dec      eax
  0x0066a6ce: add      esp, 0xc
  0x0066a6d1: neg      eax
  0x0066a6d3: sbb      eax, eax
  0x0066a6d5: dec      dword ptr [esi]
  0x0066a6d7: and      eax, dword ptr [ebp - 0x58]
  0x0066a6da: cmp      dword ptr [esi], 0
  0x0066a6dd: mov      dword ptr [ebp - 0x28], eax
  0x0066a6e0: mov      dword ptr [ebp - 0x2c], eax
  0x0066a6e3: jg       0x66a6ff
  0x0066a6e5: push     esi
  0x0066a6e6: call     dword ptr [0x715540]  ; "|[6"
  0x0066a6ec: add      esp, 4
  0x0066a6ef: jmp      0x66a6ff
  0x0066a6f1: mov      dword ptr [ebp - 0x28], 0
  0x0066a6f8: mov      dword ptr [ebp - 0x2c], 0
  0x0066a6ff: cmp      dword ptr [ebp - 0x18], 4
  0x0066a703: jg       0x66a72a
  0x0066a705: push     0
  0x0066a707: push     0
  0x0066a709: push     1
  0x0066a70b: push     0xc000008c
  0x0066a710: call     edi
  0x0066a712: cmp      dword ptr [ebp - 0x1c], 0
  0x0066a716: ja       0x66a725
  0x0066a718: push     0
  0x0066a71a: push     0
  0x0066a71c: push     1
  0x0066a71e: push     0xc000008c
  0x0066a723: call     edi
  0x0066a725: mov      esi, dword ptr [ebp - 0x20]
  0x0066a728: jmp      0x66a743
  0x0066a72a: cmp      dword ptr [ebp - 0x1c], 4
  0x0066a72e: ja       0x66a73d
  0x0066a730: push     0
  0x0066a732: push     0
  0x0066a734: push     1
  0x0066a736: push     0xc000008c
  0x0066a73b: call     edi
  0x0066a73d: mov      esi, dword ptr [ebp - 0x20]
  0x0066a740: add      esi, 0x10
  0x0066a743: mov      esi, dword ptr [esi]
  0x0066a745: test     esi, esi
  0x0066a747: je       0x66a77b
  0x0066a749: inc      dword ptr [esi]
  0x0066a74b: lea      eax, [ebp - 0x34]
  0x0066a74e: push     eax
  0x0066a74f: push     esi
  0x0066a750: push     0
  0x0066a752: call     dword ptr [0x715574]  ; "d\6"
  0x0066a758: add      esp, 0xc
  0x0066a75b: lea      edi, [eax - 1]
  0x0066a75e: neg      edi
  0x0066a760: sbb      edi, edi
  0x0066a762: dec      dword ptr [esi]
  0x0066a764: and      edi, dword ptr [ebp - 0x34]
  0x0066a767: cmp      dword ptr [esi], 0
  0x0066a76a: mov      dword ptr [ebp - 0x30], edi
  0x0066a76d: jg       0x66a780
  0x0066a76f: push     esi
  0x0066a770: call     dword ptr [0x715540]  ; "|[6"
  0x0066a776: add      esp, 4
  0x0066a779: jmp      0x66a780
  0x0066a77b: xor      edi, edi
  0x0066a77d: mov      dword ptr [ebp - 0x30], edi
  0x0066a780: mov      ecx, dword ptr [0x77241c]
  0x0066a786: mov      eax, dword ptr [ecx + 0x84]
  0x0066a78c: lea      edx, [ecx + 0x84]
  0x0066a792: cmp      eax, dword ptr [ebp - 0x38]
  0x0066a795: mov      esi, dword ptr [ebp - 0x14]
  0x0066a798: cmovg    esi, eax
  0x0066a79b: mov      eax, dword ptr [ecx + 0x88]
  0x0066a7a1: cmp      eax, dword ptr [ebp - 0x3c]
  0x0066a7a4: mov      dword ptr [ebp - 0x14], esi
  0x0066a7a7: mov      dword ptr [ebp - 0x4c], esi
  0x0066a7aa: mov      esi, dword ptr [ebp - 0x24]
  0x0066a7ad: cmovg    esi, eax
  0x0066a7b0: mov      eax, dword ptr [ecx + 0x8c]
  0x0066a7b6: cmp      eax, dword ptr [ebp - 0x28]
  0x0066a7b9: mov      dword ptr [ebp - 0x24], esi
  0x0066a7bc: mov      dword ptr [ebp - 0x48], esi
  0x0066a7bf: mov      esi, dword ptr [ebp - 0x2c]
  0x0066a7c2: cmovl    esi, eax
  0x0066a7c5: mov      eax, dword ptr [ecx + 0x90]
  0x0066a7cb: mov      ecx, dword ptr [ebp - 0x30]
  0x0066a7ce: cmp      eax, edi
  0x0066a7d0: mov      edi, dword ptr [ebp - 0x14]
  0x0066a7d3: cmovl    ecx, eax
  0x0066a7d6: mov      dword ptr [ebp - 0x44], esi
  0x0066a7d9: sub      esp, 0x10
  0x0066a7dc: mov      dword ptr [ebp - 0x40], ecx
  0x0066a7df: movups   xmm0, xmmword ptr [ebp - 0x4c]
  0x0066a7e3: lea      eax, [edi*8]
  0x0066a7ea: mov      dword ptr [ebp - 0x30], ecx
  0x0066a7ed: mov      dword ptr [ebp - 0x68], eax
  0x0066a7f0: mov      eax, dword ptr [ebp - 0x24]
  0x0066a7f3: shl      eax, 3
  0x0066a7f6: mov      dword ptr [ebp - 0x64], eax
  0x0066a7f9: lea      eax, [esi*8]
  0x0066a800: mov      dword ptr [ebp - 0x60], eax
  0x0066a803: lea      eax, [ecx*8]
  0x0066a80a: mov      ecx, dword ptr [0x77244c]
  0x0066a810: mov      dword ptr [ebp - 0x5c], eax
  0x0066a813: mov      eax, esp
  0x0066a815: push     8
  0x0066a817: push     edx
  0x0066a818: mov      dword ptr [ebp - 0x2c], esi
  0x0066a81b: movups   xmmword ptr [eax], xmm0
  0x0066a81e: call     0x5d57e0
  0x0066a823: call     0x5a3dd0
  0x0066a828: movups   xmm0, xmmword ptr [ebp - 0x68]
  0x0066a82c: push     0
  0x0066a82e: sub      esp, 0x10
  0x0066a831: mov      eax, esp
  0x0066a833: movups   xmmword ptr [eax], xmm0
  0x0066a836: call     0x5a77a0
  0x0066a83b: movups   xmm0, xmmword ptr [ebp - 0x4c]
  0x0066a83f: sub      esp, 0x10
  0x0066a842: mov      eax, esp
  0x0066a844: movups   xmmword ptr [eax], xmm0
  0x0066a847: call     0x5a9090
  0x0066a84c: lea      ecx, [eax + 0x5c]
  0x0066a84f: call     0x6c2340
  0x0066a854: lea      eax, [ebp - 0x4c]
  0x0066a857: push     eax
  0x0066a858: call     0x57d980
  0x0066a85d: mov      ecx, eax
  0x0066a85f: call     0x57d580
  0x0066a864: mov      ecx, dword ptr [0x77241c]
  0x0066a86a: lea      eax, [ebp - 0x4c]
  0x0066a86d: push     eax
  0x0066a86e: mov      ecx, dword ptr [ecx + 0x20]
  0x0066a871: call     0x580ae0
  0x0066a876: movups   xmm0, xmmword ptr [ebp - 0x4c]
  0x0066a87a: sub      esp, 0x10
  0x0066a87d: mov      eax, esp
  0x0066a87f: push     0
  0x0066a881: movups   xmmword ptr [eax], xmm0
  0x0066a884: call     0x592d70
  0x0066a889: mov      ecx, eax
  0x0066a88b: call     0x592840
  0x0066a890: movups   xmm0, xmmword ptr [ebp - 0x4c]
  0x0066a894: sub      esp, 0x10
  0x0066a897: mov      eax, esp
  0x0066a899: push     0
  0x0066a89b: movups   xmmword ptr [eax], xmm0
  0x0066a89e: call     0x492250
  0x0066a8a3: mov      ecx, eax
  0x0066a8a5: call     0x49bb70
  0x0066a8aa: mov      eax, dword ptr [0x76a338]
  0x0066a8af: xor      esi, esi
  0x0066a8b1: mov      dword ptr [ebp - 0x34], eax
  0x0066a8b4: cmp      dword ptr [eax + 0x286c], esi
  0x0066a8ba: jle      0x66a94f
  0x0066a8c0: movd     xmm0, edi
  0x0066a8c4: lea      ecx, [eax + 0x2868]
  0x0066a8ca: cvtdq2ps xmm0, xmm0
  0x0066a8cd: mov      dword ptr [ebp - 0x28], ecx
  0x0066a8d0: xor      edi, edi
  0x0066a8d2: movss    dword ptr [ebp - 0x14], xmm0
  0x0066a8d7: cmp      esi, dword ptr [ecx + 4]
  0x0066a8da: jb       0x66a8f5
  0x0066a8dc: push     0
  0x0066a8de: push     0
  0x0066a8e0: push     1
  0x0066a8e2: push     0xc000008c
  0x0066a8e7: call     dword ptr [0x715340]
  0x0066a8ed: movss    xmm0, dword ptr [ebp - 0x14]
  0x0066a8f2: mov      ecx, dword ptr [ebp - 0x28]
  0x0066a8f5: mov      eax, dword ptr [ecx]
  0x0066a8f7: movss    xmm1, dword ptr [eax + edi]
  0x0066a8fc: comiss   xmm1, xmm0
  0x0066a8ff: jb       0x66a940
  0x0066a901: movd     xmm0, dword ptr [ebp - 0x2c]
  0x0066a906: cvtdq2ps xmm0, xmm0
  0x0066a909: comiss   xmm0, xmm1
  0x0066a90c: jb       0x66a93b
  0x0066a90e: movd     xmm0, dword ptr [ebp - 0x24]
  0x0066a913: movss    xmm1, dword ptr [eax + edi + 4]
  0x0066a919: cvtdq2ps xmm0, xmm0
  0x0066a91c: comiss   xmm1, xmm0
  0x0066a91f: jb       0x66a93b
  0x0066a921: movd     xmm0, dword ptr [ebp - 0x30]
  0x0066a926: cvtdq2ps xmm0, xmm0
  0x0066a929: comiss   xmm0, xmm1
  0x0066a92c: jb       0x66a93b
  0x0066a92e: push     esi
  0x0066a92f: call     0x47d810
  0x0066a934: mov      ecx, dword ptr [ebp - 0x28]
  0x0066a937: dec      esi
  0x0066a938: sub      edi, 0x20
  0x0066a93b: movss    xmm0, dword ptr [ebp - 0x14]
  0x0066a940: mov      eax, dword ptr [ebp - 0x34]
  0x0066a943: inc      esi
  0x0066a944: add      edi, 0x20
  0x0066a947: cmp      esi, dword ptr [eax + 0x286c]
  0x0066a94d: jl       0x66a8d7
  0x0066a94f: xor      esi, esi
  0x0066a951: push     0
  0x0066a953: lea      ecx, [ebp - 0x20]
  0x0066a956: mov      byte ptr [ebp - 4], 2
  0x0066a95a: call     0x4297b0
  0x0066a95f: push     0
  0x0066a961: lea      ecx, [ebp - 0x20]
  0x0066a964: mov      byte ptr [ebp - 4], 3
  0x0066a968: call     0x4297b0
  0x0066a96d: mov      ecx, dword ptr [ebp - 0x20]
