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
