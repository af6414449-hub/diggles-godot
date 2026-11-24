  0x0067beb0: push     ebp
  0x0067beb1: mov      ebp, esp
  0x0067beb3: push     -1
  0x0067beb5: push     0x710ad5
  0x0067beba: mov      eax, dword ptr fs:[0]
  0x0067bec0: push     eax
  0x0067bec1: sub      esp, 0x28
  0x0067bec4: push     ebx
  0x0067bec5: push     esi
  0x0067bec6: push     edi
  0x0067bec7: mov      eax, dword ptr [0x76700c]
  0x0067becc: xor      eax, ebp
  0x0067bece: push     eax
  0x0067becf: lea      eax, [ebp - 0xc]
  0x0067bed2: mov      dword ptr fs:[0], eax
  0x0067bed8: mov      eax, dword ptr fs:[0x2c]
  0x0067bede: mov      ecx, dword ptr [eax]
  0x0067bee0: mov      eax, dword ptr [0xca7588]
  0x0067bee5: cmp      eax, dword ptr [ecx + 4]
  0x0067beeb: jg       0x67c0e4
  0x0067bef1: mov      edi, dword ptr [0xca758c]
  0x0067bef7: shl      edi, 6
  0x0067befa: mov      dword ptr [ebp - 0x14], 0xca758c
  0x0067bf01: mov      esi, dword ptr [edi + 0x773650]
  0x0067bf07: call     0x43fcc0
  0x0067bf0c: mov      ecx, dword ptr [eax + 0x8000]
  0x0067bf12: mov      dword ptr [eax + ecx*4], esi
  0x0067bf15: inc      dword ptr [eax + 0x8000]
  0x0067bf1b: mov      eax, dword ptr [edi + 0x773654]
  0x0067bf21: test     eax, eax
  0x0067bf23: jne      0x67bf3c
  0x0067bf25: call     0x6bd180
  0x0067bf2a: mov      dword ptr [edi + 0x773658], eax
  0x0067bf30: mov      eax, dword ptr [edi + 0x773654]
  0x0067bf36: mov      dword ptr [edi + 0x77365c], edx
  0x0067bf3c: inc      eax
  0x0067bf3d: mov      dword ptr [edi + 0x773654], eax
  0x0067bf43: mov      edi, dword ptr [ebp + 0xc]
  0x0067bf46: lea      ecx, [ebp - 0x34]
  0x0067bf49: push     edi
  0x0067bf4a: mov      dword ptr [ebp - 4], 0
  0x0067bf51: call     0x6bc170
  0x0067bf56: mov      esi, dword ptr [ebp + 0x14]
  0x0067bf59: lea      ecx, [ebp - 0x24]
  0x0067bf5c: mov      ebx, dword ptr [ebp + 0x10]
  0x0067bf5f: push     esi
  0x0067bf60: push     ebx
  0x0067bf61: mov      byte ptr [ebp - 4], 1
  0x0067bf65: call     0x4298b0
  0x0067bf6a: push     1
  0x0067bf6c: push     2
  0x0067bf6e: push     esi
  0x0067bf6f: mov      edx, ebx
  0x0067bf71: mov      byte ptr [ebp - 4], 2
  0x0067bf75: mov      ecx, edi
  0x0067bf77: call     0x5c71c0
  0x0067bf7c: mov      ebx, eax
  0x0067bf7e: add      esp, 0xc
  0x0067bf81: test     ebx, ebx
  0x0067bf83: jne      0x67bf8d
  0x0067bf85: lea      esi, [eax + 1]
  0x0067bf88: jmp      0x67c08c  ; "j"
  0x0067bf8d: xor      edi, edi
  0x0067bf8f: cmp      dword ptr [ebp + 0x10], 3
  0x0067bf93: jne      0x67c03c
  0x0067bf99: cmp      dword ptr [ebp - 0x1c], 2
  0x0067bf9d: jg       0x67bfc5
  0x0067bf9f: mov      esi, dword ptr [0x715340]
  0x0067bfa5: push     edi
  0x0067bfa6: push     edi
  0x0067bfa7: push     1
  0x0067bfa9: push     0xc000008c
  0x0067bfae: call     esi
  0x0067bfb0: cmp      dword ptr [ebp - 0x20], edi
  0x0067bfb3: ja       0x67bfc0
  0x0067bfb5: push     edi
  0x0067bfb6: push     edi
  0x0067bfb7: push     1
  0x0067bfb9: push     0xc000008c
  0x0067bfbe: call     esi
  0x0067bfc0: mov      esi, dword ptr [ebp - 0x24]
  0x0067bfc3: jmp      0x67bfe2
  0x0067bfc5: cmp      dword ptr [ebp - 0x20], 2
  0x0067bfc9: ja       0x67bfdc
  0x0067bfcb: push     0
  0x0067bfcd: push     0
  0x0067bfcf: push     1
  0x0067bfd1: push     0xc000008c
  0x0067bfd6: call     dword ptr [0x715340]
  0x0067bfdc: mov      esi, dword ptr [ebp - 0x24]
  0x0067bfdf: add      esi, 8
  0x0067bfe2: mov      esi, dword ptr [esi]
  0x0067bfe4: mov      dword ptr [ebp - 0x18], esi
  0x0067bfe7: test     esi, esi
  0x0067bfe9: je       0x67bfed
  0x0067bfeb: inc      dword ptr [esi]
  0x0067bfed: mov      byte ptr [ebp - 4], 3
  0x0067bff1: test     esi, esi
  0x0067bff3: jne      0x67c001
  0x0067bff5: push     esi
  0x0067bff6: mov      ecx, ebx
  0x0067bff8: call     0x5cb3a0
  0x0067bffd: mov      edi, eax
  0x0067bfff: jmp      0x67c053
  0x0067c001: lea      eax, [ebp - 0x10]
  0x0067c004: push     eax
  0x0067c005: push     esi
  0x0067c006: push     0
  0x0067c008: call     dword ptr [0x715574]  ; "d\6"
  0x0067c00e: add      esp, 0xc
  0x0067c011: cmp      eax, 1
  0x0067c014: jne      0x67c01a
  0x0067c016: xor      eax, eax
  0x0067c018: jmp      0x67c01d
  0x0067c01a: mov      eax, dword ptr [ebp - 0x10]
  0x0067c01d: push     eax
  0x0067c01e: mov      ecx, ebx
  0x0067c020: call     0x5cb3a0
  0x0067c025: dec      dword ptr [esi]
  0x0067c027: mov      edi, eax
  0x0067c029: cmp      dword ptr [esi], 0
  0x0067c02c: jg       0x67c053
  0x0067c02e: mov      ebx, dword ptr [0x715540]  ; "|[6"
  0x0067c034: push     esi
  0x0067c035: call     ebx
  0x0067c037: add      esp, 4
  0x0067c03a: jmp      0x67c059
  0x0067c03c: xor      esi, esi
  0x0067c03e: nop      
  0x0067c040: push     esi
  0x0067c041: mov      ecx, ebx
  0x0067c043: call     0x5cb3a0
  0x0067c048: cmp      edi, eax
  0x0067c04a: cmovl    edi, eax
  0x0067c04d: inc      esi
  0x0067c04e: cmp      esi, 8
  0x0067c051: jl       0x67c040
  0x0067c053: mov      ebx, dword ptr [0x715540]  ; "|[6"
  0x0067c059: push     edi
  0x0067c05a: call     dword ptr [0x715568]  ; "&\6"
  0x0067c060: mov      esi, eax
  0x0067c062: add      esp, 4
  0x0067c065: inc      dword ptr [esi]
  0x0067c067: mov      ecx, dword ptr [ebp - 0x34]
  0x0067c06a: mov      eax, dword ptr [esi]
  0x0067c06c: test     ecx, ecx
  0x0067c06e: je       0x67c07d
  0x0067c070: push     esi
  0x0067c071: push     ecx
  0x0067c072: call     dword ptr [0x7155b8]
  0x0067c078: mov      eax, dword ptr [esi]
  0x0067c07a: add      esp, 8
  0x0067c07d: dec      eax
  0x0067c07e: mov      dword ptr [esi], eax
  0x0067c080: test     eax, eax
  0x0067c082: jg       0x67c08a
  0x0067c084: push     esi
  0x0067c085: call     ebx
  0x0067c087: add      esp, 4
  0x0067c08a: xor      esi, esi
  0x0067c08c: push     0
  0x0067c08e: lea      ecx, [ebp - 0x24]
  0x0067c091: mov      byte ptr [ebp - 4], 4
  0x0067c095: call     0x4297b0
  0x0067c09a: push     0
  0x0067c09c: lea      ecx, [ebp - 0x24]
  0x0067c09f: mov      byte ptr [ebp - 4], 5
  0x0067c0a3: call     0x4297b0
  0x0067c0a8: mov      ecx, dword ptr [ebp - 0x24]
  0x0067c0ab: test     ecx, ecx
  0x0067c0ad: je       0x67c0b4
  0x0067c0af: call     0x6ba940
  0x0067c0b4: lea      ecx, [ebp - 0x34]
  0x0067c0b7: call     0x6bc0d0
  0x0067c0bc: mov      ecx, dword ptr [0xca758c]
  0x0067c0c2: shl      ecx, 6
  0x0067c0c5: add      ecx, 0x773650
  0x0067c0cb: call     0x43fd30
