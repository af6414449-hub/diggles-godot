  0x00592f10: push     ebp
  0x00592f11: mov      ebp, esp
  0x00592f13: mov      edx, dword ptr [ebp + 8]
  0x00592f16: push     esi
  0x00592f17: push     edi
  0x00592f18: mov      edi, ecx
  0x00592f1a: mov      eax, dword ptr [edi + 0x84]
  0x00592f20: cmp      edx, eax
  0x00592f22: mov      ecx, dword ptr [edi + 0x90]
  0x00592f28: cmovl    edx, eax
  0x00592f2b: mov      eax, dword ptr [edi + 0x8c]
  0x00592f31: cmp      edx, eax
  0x00592f33: lea      esi, [eax - 1]
  0x00592f36: mov      eax, dword ptr [edi + 0x88]
  0x00592f3c: cmovl    esi, edx
  0x00592f3f: mov      edx, dword ptr [ebp + 0xc]
  0x00592f42: cmp      edx, eax
  0x00592f44: cmovl    edx, eax
  0x00592f47: lea      eax, [ecx - 1]
  0x00592f4a: cmp      edx, ecx
  0x00592f4c: cmovl    eax, edx
  0x00592f4f: imul     eax, dword ptr [edi + 0x44]
  0x00592f53: add      eax, esi
  0x00592f55: cdq      
  0x00592f56: idiv     dword ptr [edi + 0x4c]
  0x00592f59: test     edx, edx
  0x00592f5b: js       0x592f6e  ; "j"
  0x00592f5d: cmp      edx, dword ptr [edi + 0x18]
  0x00592f60: jge      0x592f6e  ; "j"
  0x00592f62: imul     eax, edx, 0x7c
  0x00592f65: add      eax, dword ptr [edi + 0x14]
  0x00592f68: pop      edi
  0x00592f69: pop      esi
  0x00592f6a: pop      ebp
  0x00592f6b: ret      8
  0x00592f6e: push     0
  0x00592f70: push     0
  0x00592f72: push     1
  0x00592f74: push     0xc000008c
  0x00592f79: call     dword ptr [0x715340]
  0x00592f7f: mov      eax, dword ptr [edi + 0x14]
  0x00592f82: pop      edi
  0x00592f83: pop      esi
  0x00592f84: pop      ebp
  0x00592f85: ret      8
  0x00592f88: int3     
  0x00592f89: int3     
  0x00592f8a: int3     
  0x00592f8b: int3     
  0x00592f8c: int3     
  0x00592f8d: int3     
  0x00592f8e: int3     
  0x00592f8f: int3     
  0x00592f90: push     ebp
  0x00592f91: mov      ebp, esp
  0x00592f93: push     ebx
  0x00592f94: push     esi
  0x00592f95: push     edi
  0x00592f96: mov      edi, dword ptr [ebp + 8]
  0x00592f99: mov      esi, ecx
  0x00592f9b: push     esi
  0x00592f9c: mov      ecx, edi
  0x00592f9e: call     0x406f60
  0x00592fa3: lea      eax, [esi + 6]
  0x00592fa6: mov      ecx, edi
  0x00592fa8: push     eax
  0x00592fa9: call     0x409340
  0x00592fae: lea      eax, [esi + 8]
  0x00592fb1: mov      ecx, edi
  0x00592fb3: push     eax
  0x00592fb4: call     0x406f60
  0x00592fb9: lea      eax, [esi + 0xc]
  0x00592fbc: mov      ecx, edi
  0x00592fbe: push     eax
  0x00592fbf: call     0x406f60
  0x00592fc4: lea      eax, [esi + 0x12]
  0x00592fc7: mov      ecx, edi
  0x00592fc9: push     eax
  0x00592fca: call     0x409340
  0x00592fcf: lea      eax, [esi + 0x13]
  0x00592fd2: mov      ecx, edi
  0x00592fd4: push     eax
  0x00592fd5: call     0x409340
  0x00592fda: lea      eax, [esi + 0x14]
  0x00592fdd: mov      ecx, edi
  0x00592fdf: push     eax
  0x00592fe0: call     0x598e40
  0x00592fe5: mov      edx, dword ptr [edi]
  0x00592fe7: lea      ebx, [esi + 0x18]
  0x00592fea: mov      eax, edx
  0x00592fec: cmp      edx, 1
  0x00592fef: jne      0x593023
  0x00592ff1: mov      ecx, dword ptr [edi + 4]
  0x00592ff4: test     ecx, ecx
  0x00592ff6: je       0x593023
  0x00592ff8: cmp      dword ptr [ecx + 0x10], 0x1c4f
  0x00592fff: jne      0x593023
  0x00593001: mov      ebx, dword ptr [ecx + 0x5c]
  0x00593004: test     ebx, ebx
  0x00593006: je       0x59300d
  0x00593008: cmp      ebx, -5
  0x0059300b: jne      0x593020
  0x0059300d: lea      ebx, [esi + 0x18]
  0x00593010: push     0x24
  0x00593012: mov      edx, ebx
  0x00593014: call     0x6c6da0
  0x00593019: mov      eax, dword ptr [edi]
  0x0059301b: add      esp, 4
  0x0059301e: jmp      0x593023
  0x00593020: lea      ebx, [esi + 0x18]
  0x00593023: cmp      eax, 2
  0x00593026: jne      0x59304c
  0x00593028: mov      ecx, dword ptr [edi + 4]
  0x0059302b: test     ecx, ecx
  0x0059302d: je       0x593066
