

======== VA 0x004CEA14 (file 0xCDE14) ========
0x004CE99C  add      byte ptr [ebx + 0x7153400d], cl
0x004CE9A2  add      byte ptr [esi - 0x75], al
0x004CE9A5  inc      ebp
0x004CE9A6  hlt      
0x004CE9A7  inc      edi
0x004CE9A8  cmp      esi, 0x4f
0x004CE9AB  jle      0x4ce90d
0x004CE9B1  add      edx, 0x50
0x004CE9B4  inc      eax
0x004CE9B5  mov      dword ptr [ebp - 0xc], eax
0x004CE9B8  mov      dword ptr [ebp - 4], edx
0x004CE9BB  cmp      edx, 0x1220
0x004CE9C1  jle      0x4ce906
0x004CE9C7  mov      eax, dword ptr [ebp - 0x10]
0x004CE9CA  pop      edi
0x004CE9CB  pop      esi
0x004CE9CC  pop      ebx
0x004CE9CD  mov      byte ptr [eax + 0x2580], 1
0x004CE9D4  mov      esp, ebp
0x004CE9D6  pop      ebp
0x004CE9D7  ret      0x18
0x004CE9DA  int3     
0x004CE9DB  int3     
0x004CE9DC  int3     
0x004CE9DD  int3     
0x004CE9DE  int3     
0x004CE9DF  int3     
0x004CE9E0  push     ebp
0x004CE9E1  mov      ebp, esp
0x004CE9E3  push     -1
0x004CE9E5  push     0x6fec80
0x004CE9EA  mov      eax, dword ptr fs:[0]
0x004CE9F0  push     eax
0x004CE9F1  sub      esp, 0x150
0x004CE9F7  mov      eax, dword ptr [0x76700c]
0x004CE9FC  xor      eax, ebp
0x004CE9FE  mov      dword ptr [ebp - 0x10], eax
0x004CEA01  push     esi
0x004CEA02  push     edi
0x004CEA03  push     eax
0x004CEA04  lea      eax, [ebp - 0xc]
0x004CEA07  mov      dword ptr fs:[0], eax
0x004CEA0D  mov      ecx, dword ptr [0x76a324]
0x004CEA13  mov      eax, dword ptr [0x772400]
0x004CEA18  push     0x2900
0x004CEA1D  push     0
0x004CEA1F  lea      edi, [ecx + 0x24]
0x004CEA22  mov      dword ptr [ebp - 0x120], ecx
0x004CEA28  mov      al, byte ptr [eax + 0x3c9]
0x004CEA2E  push     edi
0x004CEA2F  mov      byte ptr [ecx + 0x12], al
0x004CEA32  mov      dword ptr [ebp - 0x128], edi
0x004CEA38  call     0x6d0560
0x004CEA3D  mov      esi, dword ptr [0x715340]
0x004CEA43  xor      ecx, ecx
0x004CEA45  add      esp, 0xc
0x004CEA48  mov      dword ptr [ebp - 0x114], ecx
0x004CEA4E  xor      eax, eax
0x004CEA50  mov      dword ptr [ebp - 0x118], eax
0x004CEA56  cmp      ecx, 0xff
0x004CEA5C  ja       0x4cea63
0x004CEA5E  lea      edx, [eax + edi]
0x004CEA61  jmp      0x4cea7e
0x004CEA63  push     0
0x004CEA65  push     0
0x004CEA67  push     1
0x004CEA69  push     0xc000008c
0x004CEA6E  call     esi
0x004CEA70  mov      eax, dword ptr [ebp - 0x118]
0x004CEA76  mov      edx, edi
0x004CEA78  mov      ecx, dword ptr [ebp - 0x114]
0x004CEA7E  add      eax, 0x29
0x004CEA81  mov      byte ptr [edx], 0
0x004CEA84  inc      ecx
0x004CEA85  mov      dword ptr [ebp - 0x118], eax
0x004CEA8B  mov      dword ptr [ebp - 0x114], ecx
0x004CEA91  cmp      eax, 0x2900
0x004CEA96  jl       0x4cea56
0x004CEA98  mov      dword ptr [ebp - 0x15c], 0
0x004CEAA2  mov      dword ptr [ebp - 0x158], 0
0x004CEAAC  mov      dword ptr [ebp - 0x14c], 0
0x004CEAB6  mov      dword ptr [ebp - 0x148], 0
0x004CEAC0  push     0x724918
0x004CEAC5  lea      ecx, [ebp - 0x15c]
0x004CEACB  mov      dword ptr [ebp - 4], 0
0x004CEAD2  call     0x6c0370
0x004CEAD7  test     al, al
0x004CEAD9  .byte    0x0f
0x004CEADA  test     byte ptr [eax], bh


======== VA 0x004F8212 (file 0xF7612) ========
0x004F819A  add      byte ptr [ebx + ecx - 0x75], dh
0x004F819E  into     
0x004F819F  call     0x504ee0
0x004F81A4  mov      byte ptr [esi + 0x1c], 0
0x004F81A8  mov      ecx, dword ptr [edi + 0x1ac]
0x004F81AE  cmp      byte ptr [ecx + 0x1c], 1
0x004F81B2  je       0x4f81c3
0x004F81B4  mov      byte ptr [ecx + 0x1c], 1
0x004F81B8  call     0x504ee0
0x004F81BD  mov      ecx, dword ptr [edi + 0x1ac]
0x004F81C3  call     0x505ed0
0x004F81C8  push     ecx
0x004F81C9  mov      esi, esp
0x004F81CB  mov      edx, 0x7364b0
0x004F81D0  push     0x19
0x004F81D2  mov      ecx, 0x10
0x004F81D7  call     0x6ba810
0x004F81DC  add      esp, 4
0x004F81DF  mov      dword ptr [eax + 4], 4
0x004F81E6  mov      dword ptr [eax + 8], 0xffffffff
0x004F81ED  mov      dword ptr [eax], 0
0x004F81F3  mov      dword ptr [esi], eax
0x004F81F5  mov      byte ptr [eax + 0xc], 0
0x004F81F9  mov      eax, dword ptr [esi]
0x004F81FB  mov      dword ptr [eax + 8], 0
0x004F8202  mov      eax, dword ptr [esi]
0x004F8204  test     eax, eax
0x004F8206  je       0x4f820a
0x004F8208  inc      dword ptr [eax]
0x004F820A  mov      ecx, edi
0x004F820C  call     0x4fa7e0
0x004F8211  mov      eax, dword ptr [0x772400]
0x004F8216  mov      byte ptr [eax + 0x591], 1
0x004F821D  mov      eax, dword ptr [ebp + 8]
0x004F8220  mov      eax, dword ptr [eax + 0x18]
0x004F8223  cmp      eax, dword ptr [edi + 0x134]
0x004F8229  jne      0x4f8241
0x004F822B  mov      ecx, dword ptr [0x772400]
0x004F8231  cmp      byte ptr [ecx + 0x99], 0
0x004F8238  sete     al
0x004F823B  mov      byte ptr [ecx + 0x99], al
0x004F8241  mov      eax, dword ptr [ebp + 8]
0x004F8244  mov      eax, dword ptr [eax + 0x18]
0x004F8247  cmp      eax, dword ptr [edi + 0x138]
0x004F824D  jne      0x4f825b
0x004F824F  call     0x57d980
0x004F8254  mov      ecx, eax
0x004F8256  call     0x57c6e0
0x004F825B  mov      eax, dword ptr [ebp + 8]
0x004F825E  mov      eax, dword ptr [eax + 0x18]
0x004F8261  cmp      eax, dword ptr [edi + 0x13c]
0x004F8267  jne      0x4f827f
0x004F8269  mov      ecx, dword ptr [0x772400]
0x004F826F  cmp      byte ptr [ecx + 0xa3e3], 0
0x004F8276  sete     al
0x004F8279  mov      byte ptr [ecx + 0xa3e3], al
0x004F827F  mov      eax, dword ptr [ebp + 8]
0x004F8282  mov      eax, dword ptr [eax + 0x18]
0x004F8285  cmp      eax, dword ptr [edi + 0x140]
0x004F828B  jne      0x4f82a3
0x004F828D  mov      ecx, dword ptr [0x772400]
0x004F8293  cmp      byte ptr [ecx + 0xa3e4], 0
0x004F829A  sete     al
0x004F829D  mov      byte ptr [ecx + 0xa3e4], al
0x004F82A3  mov      eax, dword ptr [ebp + 8]
0x004F82A6  mov      eax, dword ptr [eax + 0x18]
0x004F82A9  cmp      eax, dword ptr [edi + 0x144]
0x004F82AF  jne      0x4f82c7
0x004F82B1  mov      ecx, dword ptr [0x772400]
0x004F82B7  cmp      byte ptr [ecx + 0xa3e5], 0
0x004F82BE  sete     al
0x004F82C1  mov      byte ptr [ecx + 0xa3e5], al
0x004F82C7  mov      eax, dword ptr [ebp + 8]
0x004F82CA  mov      eax, dword ptr [eax + 0x18]
0x004F82CD  cmp      eax, dword ptr [edi + 0x148]
0x004F82D3  jne      0x4f830d
0x004F82D5  .byte    0x8b
0x004F82D6  .byte    0x0d
0x004F82D7  .byte    0x38
0x004F82D8  .byte    0xa3
0x004F82D9  .byte    0x76


======== VA 0x004F822D (file 0xF762D) ========
0x004F81B5  inc      ecx
0x004F81B6  sbb      al, 1
0x004F81B8  call     0x504ee0
0x004F81BD  mov      ecx, dword ptr [edi + 0x1ac]
0x004F81C3  call     0x505ed0
0x004F81C8  push     ecx
0x004F81C9  mov      esi, esp
0x004F81CB  mov      edx, 0x7364b0
0x004F81D0  push     0x19
0x004F81D2  mov      ecx, 0x10
0x004F81D7  call     0x6ba810
0x004F81DC  add      esp, 4
0x004F81DF  mov      dword ptr [eax + 4], 4
0x004F81E6  mov      dword ptr [eax + 8], 0xffffffff
0x004F81ED  mov      dword ptr [eax], 0
0x004F81F3  mov      dword ptr [esi], eax
0x004F81F5  mov      byte ptr [eax + 0xc], 0
0x004F81F9  mov      eax, dword ptr [esi]
0x004F81FB  mov      dword ptr [eax + 8], 0
0x004F8202  mov      eax, dword ptr [esi]
0x004F8204  test     eax, eax
0x004F8206  je       0x4f820a
0x004F8208  inc      dword ptr [eax]
0x004F820A  mov      ecx, edi
0x004F820C  call     0x4fa7e0
0x004F8211  mov      eax, dword ptr [0x772400]
0x004F8216  mov      byte ptr [eax + 0x591], 1
0x004F821D  mov      eax, dword ptr [ebp + 8]
0x004F8220  mov      eax, dword ptr [eax + 0x18]
0x004F8223  cmp      eax, dword ptr [edi + 0x134]
0x004F8229  jne      0x4f8241
0x004F822B  mov      ecx, dword ptr [0x772400]
0x004F8231  cmp      byte ptr [ecx + 0x99], 0
0x004F8238  sete     al
0x004F823B  mov      byte ptr [ecx + 0x99], al
0x004F8241  mov      eax, dword ptr [ebp + 8]
0x004F8244  mov      eax, dword ptr [eax + 0x18]
0x004F8247  cmp      eax, dword ptr [edi + 0x138]
0x004F824D  jne      0x4f825b
0x004F824F  call     0x57d980
0x004F8254  mov      ecx, eax
0x004F8256  call     0x57c6e0
0x004F825B  mov      eax, dword ptr [ebp + 8]
0x004F825E  mov      eax, dword ptr [eax + 0x18]
0x004F8261  cmp      eax, dword ptr [edi + 0x13c]
0x004F8267  jne      0x4f827f
0x004F8269  mov      ecx, dword ptr [0x772400]
0x004F826F  cmp      byte ptr [ecx + 0xa3e3], 0
0x004F8276  sete     al
0x004F8279  mov      byte ptr [ecx + 0xa3e3], al
0x004F827F  mov      eax, dword ptr [ebp + 8]
0x004F8282  mov      eax, dword ptr [eax + 0x18]
0x004F8285  cmp      eax, dword ptr [edi + 0x140]
0x004F828B  jne      0x4f82a3
0x004F828D  mov      ecx, dword ptr [0x772400]
0x004F8293  cmp      byte ptr [ecx + 0xa3e4], 0
0x004F829A  sete     al
0x004F829D  mov      byte ptr [ecx + 0xa3e4], al
0x004F82A3  mov      eax, dword ptr [ebp + 8]
0x004F82A6  mov      eax, dword ptr [eax + 0x18]
0x004F82A9  cmp      eax, dword ptr [edi + 0x144]
0x004F82AF  jne      0x4f82c7
0x004F82B1  mov      ecx, dword ptr [0x772400]
0x004F82B7  cmp      byte ptr [ecx + 0xa3e5], 0
0x004F82BE  sete     al
0x004F82C1  mov      byte ptr [ecx + 0xa3e5], al
0x004F82C7  mov      eax, dword ptr [ebp + 8]
0x004F82CA  mov      eax, dword ptr [eax + 0x18]
0x004F82CD  cmp      eax, dword ptr [edi + 0x148]
0x004F82D3  jne      0x4f830d
0x004F82D5  mov      ecx, dword ptr [0x76a338]
0x004F82DB  push     0x10
0x004F82DD  cmp      byte ptr [ecx + 0x38d8], 0
0x004F82E4  sete     al
0x004F82E7  sub      esp, 0x10
0x004F82EA  mov      byte ptr [ecx + 0x38d8], al
0x004F82F0  mov      eax, esp
0x004F82F2  .byte    0x8b
0x004F82F3  .byte    0x0d
0x004F82F4  .byte    0x1c


======== VA 0x004F826B (file 0xF766B) ========
0x004F81F3  mov      dword ptr [esi], eax
0x004F81F5  mov      byte ptr [eax + 0xc], 0
0x004F81F9  mov      eax, dword ptr [esi]
0x004F81FB  mov      dword ptr [eax + 8], 0
0x004F8202  mov      eax, dword ptr [esi]
0x004F8204  test     eax, eax
0x004F8206  je       0x4f820a
0x004F8208  inc      dword ptr [eax]
0x004F820A  mov      ecx, edi
0x004F820C  call     0x4fa7e0
0x004F8211  mov      eax, dword ptr [0x772400]
0x004F8216  mov      byte ptr [eax + 0x591], 1
0x004F821D  mov      eax, dword ptr [ebp + 8]
0x004F8220  mov      eax, dword ptr [eax + 0x18]
0x004F8223  cmp      eax, dword ptr [edi + 0x134]
0x004F8229  jne      0x4f8241
0x004F822B  mov      ecx, dword ptr [0x772400]
0x004F8231  cmp      byte ptr [ecx + 0x99], 0
0x004F8238  sete     al
0x004F823B  mov      byte ptr [ecx + 0x99], al
0x004F8241  mov      eax, dword ptr [ebp + 8]
0x004F8244  mov      eax, dword ptr [eax + 0x18]
0x004F8247  cmp      eax, dword ptr [edi + 0x138]
0x004F824D  jne      0x4f825b
0x004F824F  call     0x57d980
0x004F8254  mov      ecx, eax
0x004F8256  call     0x57c6e0
0x004F825B  mov      eax, dword ptr [ebp + 8]
0x004F825E  mov      eax, dword ptr [eax + 0x18]
0x004F8261  cmp      eax, dword ptr [edi + 0x13c]
0x004F8267  jne      0x4f827f
0x004F8269  mov      ecx, dword ptr [0x772400]
0x004F826F  cmp      byte ptr [ecx + 0xa3e3], 0
0x004F8276  sete     al
0x004F8279  mov      byte ptr [ecx + 0xa3e3], al
0x004F827F  mov      eax, dword ptr [ebp + 8]
0x004F8282  mov      eax, dword ptr [eax + 0x18]
0x004F8285  cmp      eax, dword ptr [edi + 0x140]
0x004F828B  jne      0x4f82a3
0x004F828D  mov      ecx, dword ptr [0x772400]
0x004F8293  cmp      byte ptr [ecx + 0xa3e4], 0
0x004F829A  sete     al
0x004F829D  mov      byte ptr [ecx + 0xa3e4], al
0x004F82A3  mov      eax, dword ptr [ebp + 8]
0x004F82A6  mov      eax, dword ptr [eax + 0x18]
0x004F82A9  cmp      eax, dword ptr [edi + 0x144]
0x004F82AF  jne      0x4f82c7
0x004F82B1  mov      ecx, dword ptr [0x772400]
0x004F82B7  cmp      byte ptr [ecx + 0xa3e5], 0
0x004F82BE  sete     al
0x004F82C1  mov      byte ptr [ecx + 0xa3e5], al
0x004F82C7  mov      eax, dword ptr [ebp + 8]
0x004F82CA  mov      eax, dword ptr [eax + 0x18]
0x004F82CD  cmp      eax, dword ptr [edi + 0x148]
0x004F82D3  jne      0x4f830d
0x004F82D5  mov      ecx, dword ptr [0x76a338]
0x004F82DB  push     0x10
0x004F82DD  cmp      byte ptr [ecx + 0x38d8], 0
0x004F82E4  sete     al
0x004F82E7  sub      esp, 0x10
0x004F82EA  mov      byte ptr [ecx + 0x38d8], al
0x004F82F0  mov      eax, esp
0x004F82F2  mov      ecx, dword ptr [0x77241c]
0x004F82F8  movups   xmm0, xmmword ptr [ecx + 0x94]
0x004F82FF  mov      ecx, dword ptr [0x772428]
0x004F8305  movups   xmmword ptr [eax], xmm0
0x004F8308  call     0x5a3fd0
0x004F830D  mov      eax, dword ptr [ebp + 8]
0x004F8310  mov      eax, dword ptr [eax + 0x18]
0x004F8313  cmp      eax, dword ptr [edi + 0x100]
0x004F8319  jne      0x4f847c
0x004F831F  mov      eax, dword ptr [edi + 0x104]
0x004F8325  xor      esi, esi
0x004F8327  mov      dword ptr [edi + 0x60], 0
0x004F832E  mov      dword ptr [ebp - 0x18], eax
0x004F8331  .byte    0x80
0x004F8332  .byte    0x78


======== VA 0x004F828F (file 0xF768F) ========
0x004F8217  adc      byte ptr [ecx + 0x1000005], 0x8b
0x004F821E  inc      ebp
0x004F821F  or       byte ptr [ebx - 0x78c4e7c0], cl
0x004F8225  xor      al, 1
0x004F8227  add      byte ptr [eax], al
0x004F8229  jne      0x4f8241
0x004F822B  mov      ecx, dword ptr [0x772400]
0x004F8231  cmp      byte ptr [ecx + 0x99], 0
0x004F8238  sete     al
0x004F823B  mov      byte ptr [ecx + 0x99], al
0x004F8241  mov      eax, dword ptr [ebp + 8]
0x004F8244  mov      eax, dword ptr [eax + 0x18]
0x004F8247  cmp      eax, dword ptr [edi + 0x138]
0x004F824D  jne      0x4f825b
0x004F824F  call     0x57d980
0x004F8254  mov      ecx, eax
0x004F8256  call     0x57c6e0
0x004F825B  mov      eax, dword ptr [ebp + 8]
0x004F825E  mov      eax, dword ptr [eax + 0x18]
0x004F8261  cmp      eax, dword ptr [edi + 0x13c]
0x004F8267  jne      0x4f827f
0x004F8269  mov      ecx, dword ptr [0x772400]
0x004F826F  cmp      byte ptr [ecx + 0xa3e3], 0
0x004F8276  sete     al
0x004F8279  mov      byte ptr [ecx + 0xa3e3], al
0x004F827F  mov      eax, dword ptr [ebp + 8]
0x004F8282  mov      eax, dword ptr [eax + 0x18]
0x004F8285  cmp      eax, dword ptr [edi + 0x140]
0x004F828B  jne      0x4f82a3
0x004F828D  mov      ecx, dword ptr [0x772400]
0x004F8293  cmp      byte ptr [ecx + 0xa3e4], 0
0x004F829A  sete     al
0x004F829D  mov      byte ptr [ecx + 0xa3e4], al
0x004F82A3  mov      eax, dword ptr [ebp + 8]
0x004F82A6  mov      eax, dword ptr [eax + 0x18]
0x004F82A9  cmp      eax, dword ptr [edi + 0x144]
0x004F82AF  jne      0x4f82c7
0x004F82B1  mov      ecx, dword ptr [0x772400]
0x004F82B7  cmp      byte ptr [ecx + 0xa3e5], 0
0x004F82BE  sete     al
0x004F82C1  mov      byte ptr [ecx + 0xa3e5], al
0x004F82C7  mov      eax, dword ptr [ebp + 8]
0x004F82CA  mov      eax, dword ptr [eax + 0x18]
0x004F82CD  cmp      eax, dword ptr [edi + 0x148]
0x004F82D3  jne      0x4f830d
0x004F82D5  mov      ecx, dword ptr [0x76a338]
0x004F82DB  push     0x10
0x004F82DD  cmp      byte ptr [ecx + 0x38d8], 0
0x004F82E4  sete     al
0x004F82E7  sub      esp, 0x10
0x004F82EA  mov      byte ptr [ecx + 0x38d8], al
0x004F82F0  mov      eax, esp
0x004F82F2  mov      ecx, dword ptr [0x77241c]
0x004F82F8  movups   xmm0, xmmword ptr [ecx + 0x94]
0x004F82FF  mov      ecx, dword ptr [0x772428]
0x004F8305  movups   xmmword ptr [eax], xmm0
0x004F8308  call     0x5a3fd0
0x004F830D  mov      eax, dword ptr [ebp + 8]
0x004F8310  mov      eax, dword ptr [eax + 0x18]
0x004F8313  cmp      eax, dword ptr [edi + 0x100]
0x004F8319  jne      0x4f847c
0x004F831F  mov      eax, dword ptr [edi + 0x104]
0x004F8325  xor      esi, esi
0x004F8327  mov      dword ptr [edi + 0x60], 0
0x004F832E  mov      dword ptr [ebp - 0x18], eax
0x004F8331  cmp      byte ptr [eax + 0x2c], 0
0x004F8335  je       0x4f8389
0x004F8337  call     0x501450
0x004F833C  mov      ecx, dword ptr [ebp - 0x18]
0x004F833F  cmp      dword ptr [eax + 0x8198], ecx
0x004F8345  jne      0x4f8369
0x004F8347  call     0x501450
0x004F834C  cmp      dword ptr [eax + 0x81a4], esi
0x004F8352  je       0x4f8364
0x004F8354  .byte    0xe8
0x004F8355  .byte    0xf7
0x004F8356  nop      


======== VA 0x004F82B3 (file 0xF76B3) ========
0x004F823B  mov      byte ptr [ecx + 0x99], al
0x004F8241  mov      eax, dword ptr [ebp + 8]
0x004F8244  mov      eax, dword ptr [eax + 0x18]
0x004F8247  cmp      eax, dword ptr [edi + 0x138]
0x004F824D  jne      0x4f825b
0x004F824F  call     0x57d980
0x004F8254  mov      ecx, eax
0x004F8256  call     0x57c6e0
0x004F825B  mov      eax, dword ptr [ebp + 8]
0x004F825E  mov      eax, dword ptr [eax + 0x18]
0x004F8261  cmp      eax, dword ptr [edi + 0x13c]
0x004F8267  jne      0x4f827f
0x004F8269  mov      ecx, dword ptr [0x772400]
0x004F826F  cmp      byte ptr [ecx + 0xa3e3], 0
0x004F8276  sete     al
0x004F8279  mov      byte ptr [ecx + 0xa3e3], al
0x004F827F  mov      eax, dword ptr [ebp + 8]
0x004F8282  mov      eax, dword ptr [eax + 0x18]
0x004F8285  cmp      eax, dword ptr [edi + 0x140]
0x004F828B  jne      0x4f82a3
0x004F828D  mov      ecx, dword ptr [0x772400]
0x004F8293  cmp      byte ptr [ecx + 0xa3e4], 0
0x004F829A  sete     al
0x004F829D  mov      byte ptr [ecx + 0xa3e4], al
0x004F82A3  mov      eax, dword ptr [ebp + 8]
0x004F82A6  mov      eax, dword ptr [eax + 0x18]
0x004F82A9  cmp      eax, dword ptr [edi + 0x144]
0x004F82AF  jne      0x4f82c7
0x004F82B1  mov      ecx, dword ptr [0x772400]
0x004F82B7  cmp      byte ptr [ecx + 0xa3e5], 0
0x004F82BE  sete     al
0x004F82C1  mov      byte ptr [ecx + 0xa3e5], al
0x004F82C7  mov      eax, dword ptr [ebp + 8]
0x004F82CA  mov      eax, dword ptr [eax + 0x18]
0x004F82CD  cmp      eax, dword ptr [edi + 0x148]
0x004F82D3  jne      0x4f830d
0x004F82D5  mov      ecx, dword ptr [0x76a338]
0x004F82DB  push     0x10
0x004F82DD  cmp      byte ptr [ecx + 0x38d8], 0
0x004F82E4  sete     al
0x004F82E7  sub      esp, 0x10
0x004F82EA  mov      byte ptr [ecx + 0x38d8], al
0x004F82F0  mov      eax, esp
0x004F82F2  mov      ecx, dword ptr [0x77241c]
0x004F82F8  movups   xmm0, xmmword ptr [ecx + 0x94]
0x004F82FF  mov      ecx, dword ptr [0x772428]
0x004F8305  movups   xmmword ptr [eax], xmm0
0x004F8308  call     0x5a3fd0
0x004F830D  mov      eax, dword ptr [ebp + 8]
0x004F8310  mov      eax, dword ptr [eax + 0x18]
0x004F8313  cmp      eax, dword ptr [edi + 0x100]
0x004F8319  jne      0x4f847c
0x004F831F  mov      eax, dword ptr [edi + 0x104]
0x004F8325  xor      esi, esi
0x004F8327  mov      dword ptr [edi + 0x60], 0
0x004F832E  mov      dword ptr [ebp - 0x18], eax
0x004F8331  cmp      byte ptr [eax + 0x2c], 0
0x004F8335  je       0x4f8389
0x004F8337  call     0x501450
0x004F833C  mov      ecx, dword ptr [ebp - 0x18]
0x004F833F  cmp      dword ptr [eax + 0x8198], ecx
0x004F8345  jne      0x4f8369
0x004F8347  call     0x501450
0x004F834C  cmp      dword ptr [eax + 0x81a4], esi
0x004F8352  je       0x4f8364
0x004F8354  call     0x501450
0x004F8359  mov      ecx, dword ptr [ebp - 0x18]
0x004F835C  cmp      dword ptr [eax + 0x81a4], ecx
0x004F8362  jne      0x4f8369
0x004F8364  mov      esi, 1
0x004F8369  call     0x501450
0x004F836E  mov      ecx, dword ptr [ebp - 0x18]
0x004F8371  cmp      dword ptr [eax + 0x819c], ecx
0x004F8377  je       0x4f8381
0x004F8379  xor      eax, eax


======== VA 0x0050332F (file 0x10272F) ========
0x005032B7  mov      eax, dword ptr [0x76700c]
0x005032BC  xor      eax, ebp
0x005032BE  push     eax
0x005032BF  lea      eax, [ebp - 0xc]
0x005032C2  mov      dword ptr fs:[0], eax
0x005032C8  mov      edi, ecx
0x005032CA  mov      dword ptr [ebp - 0x14], edi
0x005032CD  mov      ebx, dword ptr [ebp + 8]
0x005032D0  test     bx, bx
0x005032D3  je       0x503319
0x005032D5  cmp      bx, 0x7f
0x005032D9  jae      0x503319
0x005032DB  cmp      bl, 0x41
0x005032DE  jl       0x5032e5
0x005032E0  cmp      bl, 0x5a
0x005032E3  jle      0x5032fe
0x005032E5  cmp      bl, 0x30
0x005032E8  jl       0x5032ef
0x005032EA  cmp      bl, 0x39
0x005032ED  jle      0x5032fe
0x005032EF  cmp      bl, 0x6d
0x005032F2  je       0x5032fe
0x005032F4  cmp      bl, 0x20
0x005032F7  je       0x5032fe
0x005032F9  cmp      bl, 8
0x005032FC  jne      0x503319
0x005032FE  push     0x10
0x00503300  call     dword ptr [0x715424]
0x00503306  shr      eax, 0xf
0x00503309  mov      ecx, edi
0x0050330B  and      al, 1
0x0050330D  mov      byte ptr [ebp + 8], al
0x00503310  push     dword ptr [ebp + 8]
0x00503313  push     ebx
0x00503314  call     0x503190
0x00503319  call     0x4e4550
0x0050331E  push     0
0x00503320  push     0
0x00503322  push     0
0x00503324  mov      dword ptr [eax], 3
0x0050332A  lea      eax, [ebp + 8]
0x0050332D  mov      ecx, dword ptr [0x772400]
0x00503333  push     eax
0x00503334  lea      ecx, [ecx + 0x148]
0x0050333A  call     0x4e4c40
0x0050333F  mov      dword ptr [ebp - 4], 0
0x00503346  mov      esi, dword ptr [ebp + 8]
0x00503349  mov      ecx, dword ptr [esi + 8]
0x0050334C  cmp      ecx, -1
0x0050334F  jne      0x503363
0x00503351  lea      ecx, [esi + 0xc]
0x00503354  lea      edx, [ecx + 1]
0x00503357  mov      al, byte ptr [ecx]
0x00503359  inc      ecx
0x0050335A  test     al, al
0x0050335C  jne      0x503357
0x0050335E  sub      ecx, edx
0x00503360  mov      dword ptr [esi + 8], ecx
0x00503363  test     ecx, ecx
0x00503365  jle      0x50337f
0x00503367  push     ecx
0x00503368  mov      ecx, dword ptr [0x772400]
0x0050336E  mov      eax, esp
0x00503370  mov      dword ptr [eax], esi
0x00503372  lea      ecx, [ecx + 0x368]
0x00503378  inc      dword ptr [esi]
0x0050337A  call     0x54ea20
0x0050337F  push     dword ptr [0x772384]
0x00503385  mov      edx, dword ptr [edi + 0x8194]
0x0050338B  lea      ecx, [ebp - 0x10]
0x0050338E  call     0x4ed780
0x00503393  add      esp, 4
0x00503396  push     0x80
0x0050339B  push     0xc931f8
0x005033A0  push     0
0x005033A2  mov      byte ptr [ebp - 4], 1
0x005033A6  call     dword ptr [0x715428]
0x005033AC  mov      edi, dword ptr [ebp - 0x10]
0x005033AF  push     0xc931f8
0x005033B4  lea      ecx, [edi + 0x3c]
0x005033B7  call     0x6b9200
0x005033BC  movzx    eax, bx
0x005033BF  lea      ebx, [edi + 4]
0x005033C2  mov      dword ptr [edi + 0x40], eax
0x005033C5  push     ecx
0x005033C6  mov      eax, esp
0x005033C8  mov      dword ptr [edi + 0x44], 0
0x005033CF  mov      dword ptr [eax], edi
0x005033D1  lock inc dword ptr [ebx]
0x005033D4  mov      ecx, dword ptr [ebp - 0x14]
0x005033D7  call     0x4ed820
0x005033DC  or       eax, 0xffffffff
0x005033DF  lock xadd dword ptr [ebx], eax
0x005033E3  jne      0x5033ed
0x005033E5  mov      eax, dword ptr [edi]
0x005033E7  mov      ecx, edi
0x005033E9  push     1
0x005033EB  call     dword ptr [eax]
0x005033ED  mov      dword ptr [ebp - 4], 2
0x005033F4  add      dword ptr [esi], -1


======== VA 0x0050336A (file 0x10276A) ========
0x005032F2  je       0x5032fe
0x005032F4  cmp      bl, 0x20
0x005032F7  je       0x5032fe
0x005032F9  cmp      bl, 8
0x005032FC  jne      0x503319
0x005032FE  push     0x10
0x00503300  call     dword ptr [0x715424]
0x00503306  shr      eax, 0xf
0x00503309  mov      ecx, edi
0x0050330B  and      al, 1
0x0050330D  mov      byte ptr [ebp + 8], al
0x00503310  push     dword ptr [ebp + 8]
0x00503313  push     ebx
0x00503314  call     0x503190
0x00503319  call     0x4e4550
0x0050331E  push     0
0x00503320  push     0
0x00503322  push     0
0x00503324  mov      dword ptr [eax], 3
0x0050332A  lea      eax, [ebp + 8]
0x0050332D  mov      ecx, dword ptr [0x772400]
0x00503333  push     eax
0x00503334  lea      ecx, [ecx + 0x148]
0x0050333A  call     0x4e4c40
0x0050333F  mov      dword ptr [ebp - 4], 0
0x00503346  mov      esi, dword ptr [ebp + 8]
0x00503349  mov      ecx, dword ptr [esi + 8]
0x0050334C  cmp      ecx, -1
0x0050334F  jne      0x503363
0x00503351  lea      ecx, [esi + 0xc]
0x00503354  lea      edx, [ecx + 1]
0x00503357  mov      al, byte ptr [ecx]
0x00503359  inc      ecx
0x0050335A  test     al, al
0x0050335C  jne      0x503357
0x0050335E  sub      ecx, edx
0x00503360  mov      dword ptr [esi + 8], ecx
0x00503363  test     ecx, ecx
0x00503365  jle      0x50337f
0x00503367  push     ecx
0x00503368  mov      ecx, dword ptr [0x772400]
0x0050336E  mov      eax, esp
0x00503370  mov      dword ptr [eax], esi
0x00503372  lea      ecx, [ecx + 0x368]
0x00503378  inc      dword ptr [esi]
0x0050337A  call     0x54ea20
0x0050337F  push     dword ptr [0x772384]
0x00503385  mov      edx, dword ptr [edi + 0x8194]
0x0050338B  lea      ecx, [ebp - 0x10]
0x0050338E  call     0x4ed780
0x00503393  add      esp, 4
0x00503396  push     0x80
0x0050339B  push     0xc931f8
0x005033A0  push     0
0x005033A2  mov      byte ptr [ebp - 4], 1
0x005033A6  call     dword ptr [0x715428]
0x005033AC  mov      edi, dword ptr [ebp - 0x10]
0x005033AF  push     0xc931f8
0x005033B4  lea      ecx, [edi + 0x3c]
0x005033B7  call     0x6b9200
0x005033BC  movzx    eax, bx
0x005033BF  lea      ebx, [edi + 4]
0x005033C2  mov      dword ptr [edi + 0x40], eax
0x005033C5  push     ecx
0x005033C6  mov      eax, esp
0x005033C8  mov      dword ptr [edi + 0x44], 0
0x005033CF  mov      dword ptr [eax], edi
0x005033D1  lock inc dword ptr [ebx]
0x005033D4  mov      ecx, dword ptr [ebp - 0x14]
0x005033D7  call     0x4ed820
0x005033DC  or       eax, 0xffffffff
0x005033DF  lock xadd dword ptr [ebx], eax
0x005033E3  jne      0x5033ed
0x005033E5  mov      eax, dword ptr [edi]
0x005033E7  mov      ecx, edi
0x005033E9  push     1
0x005033EB  call     dword ptr [eax]
0x005033ED  mov      dword ptr [ebp - 4], 2
0x005033F4  add      dword ptr [esi], -1
0x005033F7  jne      0x503400
0x005033F9  mov      ecx, esi
0x005033FB  call     0x6ba940
0x00503400  mov      ecx, dword ptr [ebp - 0xc]
0x00503403  mov      dword ptr fs:[0], ecx
0x0050340A  pop      ecx
0x0050340B  pop      edi
0x0050340C  pop      esi
0x0050340D  pop      ebx
0x0050340E  mov      esp, ebp
0x00503410  pop      ebp
0x00503411  ret      8
0x00503414  int3     
0x00503415  int3     
0x00503416  int3     
0x00503417  int3     
0x00503418  int3     
0x00503419  int3     
0x0050341A  int3     
0x0050341B  int3     
0x0050341C  int3     
0x0050341D  int3     
0x0050341E  int3     
0x0050341F  int3     
0x00503420  push     ebp
0x00503421  mov      ebp, esp
0x00503423  push     -1
0x00503425  push     0x700b8d
0x0050342A  mov      eax, dword ptr fs:[0]
0x00503430  push     eax
0x00503431  .byte    0x83


======== VA 0x0050344E (file 0x10284E) ========
0x005033D6  in       al, dx
0x005033D7  call     0x4ed820
0x005033DC  or       eax, 0xffffffff
0x005033DF  lock xadd dword ptr [ebx], eax
0x005033E3  jne      0x5033ed
0x005033E5  mov      eax, dword ptr [edi]
0x005033E7  mov      ecx, edi
0x005033E9  push     1
0x005033EB  call     dword ptr [eax]
0x005033ED  mov      dword ptr [ebp - 4], 2
0x005033F4  add      dword ptr [esi], -1
0x005033F7  jne      0x503400
0x005033F9  mov      ecx, esi
0x005033FB  call     0x6ba940
0x00503400  mov      ecx, dword ptr [ebp - 0xc]
0x00503403  mov      dword ptr fs:[0], ecx
0x0050340A  pop      ecx
0x0050340B  pop      edi
0x0050340C  pop      esi
0x0050340D  pop      ebx
0x0050340E  mov      esp, ebp
0x00503410  pop      ebp
0x00503411  ret      8
0x00503414  int3     
0x00503415  int3     
0x00503416  int3     
0x00503417  int3     
0x00503418  int3     
0x00503419  int3     
0x0050341A  int3     
0x0050341B  int3     
0x0050341C  int3     
0x0050341D  int3     
0x0050341E  int3     
0x0050341F  int3     
0x00503420  push     ebp
0x00503421  mov      ebp, esp
0x00503423  push     -1
0x00503425  push     0x700b8d
0x0050342A  mov      eax, dword ptr fs:[0]
0x00503430  push     eax
0x00503431  sub      esp, 0xc
0x00503434  push     ebx
0x00503435  push     esi
0x00503436  push     edi
0x00503437  mov      eax, dword ptr [0x76700c]
0x0050343C  xor      eax, ebp
0x0050343E  push     eax
0x0050343F  lea      eax, [ebp - 0xc]
0x00503442  mov      dword ptr fs:[0], eax
0x00503448  mov      ebx, ecx
0x0050344A  mov      dword ptr [ebp - 0x18], ebx
0x0050344D  mov      eax, dword ptr [0x772400]
0x00503452  cmp      byte ptr [eax + 0x3c9], 0
0x00503459  jne      0x5039f7
0x0050345F  mov      ecx, dword ptr [ebp + 8]
0x00503462  mov      eax, dword ptr [ecx]
0x00503464  cmp      eax, 0x401
0x00503469  ja       0x5037bd
0x0050346F  je       0x503684
0x00503475  sub      eax, 0x300
0x0050347A  je       0x5035a4
0x00503480  sub      eax, 1
0x00503483  jne      0x5039f7
0x00503489  movzx    eax, word ptr [ecx + 0x10]
0x0050348D  push     eax
0x0050348E  call     dword ptr [0x715038]
0x00503494  add      esp, 4
0x00503497  movzx    eax, ax
0x0050349A  mov      dword ptr [ebp - 0x14], eax
0x0050349D  call     0x4e4550
0x005034A2  push     1
0x005034A4  push     0
0x005034A6  push     0
0x005034A8  mov      dword ptr [eax], 3
0x005034AE  lea      eax, [ebp + 8]
0x005034B1  mov      ecx, dword ptr [0x772400]
0x005034B7  push     eax
0x005034B8  lea      ecx, [ecx + 0x148]
0x005034BE  call     0x4e4c40
0x005034C3  mov      dword ptr [ebp - 4], 5
0x005034CA  mov      esi, dword ptr [ebp + 8]
0x005034CD  mov      ecx, dword ptr [esi + 8]
0x005034D0  cmp      ecx, -1
0x005034D3  jne      0x5034ec
0x005034D5  lea      ecx, [esi + 0xc]
0x005034D8  lea      edx, [ecx + 1]
0x005034DB  nop      dword ptr [eax + eax]
0x005034E0  mov      al, byte ptr [ecx]
0x005034E2  inc      ecx
0x005034E3  test     al, al
0x005034E5  jne      0x5034e0
0x005034E7  sub      ecx, edx
0x005034E9  mov      dword ptr [esi + 8], ecx
0x005034EC  test     ecx, ecx
0x005034EE  jle      0x503508
0x005034F0  push     ecx
0x005034F1  mov      ecx, dword ptr [0x772400]
0x005034F7  mov      eax, esp
0x005034F9  mov      dword ptr [eax], esi
0x005034FB  lea      ecx, [ecx + 0x368]
0x00503501  inc      dword ptr [esi]
0x00503503  call     0x54ea20
0x00503508  push     dword ptr [0x7723d8]
0x0050350E  mov      edx, dword ptr [ebx + 0x8194]
0x00503514  .byte    0x8d
0x00503515  dec      ebp


======== VA 0x005034B3 (file 0x1028B3) ========
0x0050343B  add      byte ptr [ebx], dh
0x0050343D  lds      edx, ptr [eax - 0x73]
0x00503440  inc      ebp
0x00503441  hlt      
0x00503442  mov      dword ptr fs:[0], eax
0x00503448  mov      ebx, ecx
0x0050344A  mov      dword ptr [ebp - 0x18], ebx
0x0050344D  mov      eax, dword ptr [0x772400]
0x00503452  cmp      byte ptr [eax + 0x3c9], 0
0x00503459  jne      0x5039f7
0x0050345F  mov      ecx, dword ptr [ebp + 8]
0x00503462  mov      eax, dword ptr [ecx]
0x00503464  cmp      eax, 0x401
0x00503469  ja       0x5037bd
0x0050346F  je       0x503684
0x00503475  sub      eax, 0x300
0x0050347A  je       0x5035a4
0x00503480  sub      eax, 1
0x00503483  jne      0x5039f7
0x00503489  movzx    eax, word ptr [ecx + 0x10]
0x0050348D  push     eax
0x0050348E  call     dword ptr [0x715038]
0x00503494  add      esp, 4
0x00503497  movzx    eax, ax
0x0050349A  mov      dword ptr [ebp - 0x14], eax
0x0050349D  call     0x4e4550
0x005034A2  push     1
0x005034A4  push     0
0x005034A6  push     0
0x005034A8  mov      dword ptr [eax], 3
0x005034AE  lea      eax, [ebp + 8]
0x005034B1  mov      ecx, dword ptr [0x772400]
0x005034B7  push     eax
0x005034B8  lea      ecx, [ecx + 0x148]
0x005034BE  call     0x4e4c40
0x005034C3  mov      dword ptr [ebp - 4], 5
0x005034CA  mov      esi, dword ptr [ebp + 8]
0x005034CD  mov      ecx, dword ptr [esi + 8]
0x005034D0  cmp      ecx, -1
0x005034D3  jne      0x5034ec
0x005034D5  lea      ecx, [esi + 0xc]
0x005034D8  lea      edx, [ecx + 1]
0x005034DB  nop      dword ptr [eax + eax]
0x005034E0  mov      al, byte ptr [ecx]
0x005034E2  inc      ecx
0x005034E3  test     al, al
0x005034E5  jne      0x5034e0
0x005034E7  sub      ecx, edx
0x005034E9  mov      dword ptr [esi + 8], ecx
0x005034EC  test     ecx, ecx
0x005034EE  jle      0x503508
0x005034F0  push     ecx
0x005034F1  mov      ecx, dword ptr [0x772400]
0x005034F7  mov      eax, esp
0x005034F9  mov      dword ptr [eax], esi
0x005034FB  lea      ecx, [ecx + 0x368]
0x00503501  inc      dword ptr [esi]
0x00503503  call     0x54ea20
0x00503508  push     dword ptr [0x7723d8]
0x0050350E  mov      edx, dword ptr [ebx + 0x8194]
0x00503514  lea      ecx, [ebp - 0x10]
0x00503517  call     0x4ed780
0x0050351C  add      esp, 4
0x0050351F  push     0x80
0x00503524  push     0xc932f8
0x00503529  push     0
0x0050352B  mov      byte ptr [ebp - 4], 6
0x0050352F  call     dword ptr [0x715428]
0x00503535  mov      edi, dword ptr [ebp - 0x10]
0x00503538  push     0xc932f8
0x0050353D  lea      ecx, [edi + 0x3c]
0x00503540  call     0x6b9200
0x00503545  mov      ecx, dword ptr [ebp - 0x14]
0x00503548  lea      ebx, [edi + 4]
0x0050354B  movzx    eax, cx
0x0050354E  mov      dword ptr [edi + 0x40], eax
0x00503551  push     ecx
0x00503552  mov      eax, esp
0x00503554  mov      dword ptr [edi + 0x44], 0
0x0050355B  mov      dword ptr [eax], edi
0x0050355D  lock inc dword ptr [ebx]
0x00503560  mov      ecx, dword ptr [ebp - 0x18]
0x00503563  call     0x4ed820
0x00503568  or       eax, 0xffffffff
0x0050356B  lock xadd dword ptr [ebx], eax
0x0050356F  jne      0x503579
0x00503571  mov      eax, dword ptr [edi]
0x00503573  mov      ecx, edi
0x00503575  push     1
0x00503577  call     dword ptr [eax]
0x00503579  .byte    0xc7
0x0050357A  inc      ebp


======== VA 0x005034F3 (file 0x1028F3) ========
0x0050347B  test     byte ptr [ecx + eax], ah
0x0050347E  add      byte ptr [eax], al
0x00503480  sub      eax, 1
0x00503483  jne      0x5039f7
0x00503489  movzx    eax, word ptr [ecx + 0x10]
0x0050348D  push     eax
0x0050348E  call     dword ptr [0x715038]
0x00503494  add      esp, 4
0x00503497  movzx    eax, ax
0x0050349A  mov      dword ptr [ebp - 0x14], eax
0x0050349D  call     0x4e4550
0x005034A2  push     1
0x005034A4  push     0
0x005034A6  push     0
0x005034A8  mov      dword ptr [eax], 3
0x005034AE  lea      eax, [ebp + 8]
0x005034B1  mov      ecx, dword ptr [0x772400]
0x005034B7  push     eax
0x005034B8  lea      ecx, [ecx + 0x148]
0x005034BE  call     0x4e4c40
0x005034C3  mov      dword ptr [ebp - 4], 5
0x005034CA  mov      esi, dword ptr [ebp + 8]
0x005034CD  mov      ecx, dword ptr [esi + 8]
0x005034D0  cmp      ecx, -1
0x005034D3  jne      0x5034ec
0x005034D5  lea      ecx, [esi + 0xc]
0x005034D8  lea      edx, [ecx + 1]
0x005034DB  nop      dword ptr [eax + eax]
0x005034E0  mov      al, byte ptr [ecx]
0x005034E2  inc      ecx
0x005034E3  test     al, al
0x005034E5  jne      0x5034e0
0x005034E7  sub      ecx, edx
0x005034E9  mov      dword ptr [esi + 8], ecx
0x005034EC  test     ecx, ecx
0x005034EE  jle      0x503508
0x005034F0  push     ecx
0x005034F1  mov      ecx, dword ptr [0x772400]
0x005034F7  mov      eax, esp
0x005034F9  mov      dword ptr [eax], esi
0x005034FB  lea      ecx, [ecx + 0x368]
0x00503501  inc      dword ptr [esi]
0x00503503  call     0x54ea20
0x00503508  push     dword ptr [0x7723d8]
0x0050350E  mov      edx, dword ptr [ebx + 0x8194]
0x00503514  lea      ecx, [ebp - 0x10]
0x00503517  call     0x4ed780
0x0050351C  add      esp, 4
0x0050351F  push     0x80
0x00503524  push     0xc932f8
0x00503529  push     0
0x0050352B  mov      byte ptr [ebp - 4], 6
0x0050352F  call     dword ptr [0x715428]
0x00503535  mov      edi, dword ptr [ebp - 0x10]
0x00503538  push     0xc932f8
0x0050353D  lea      ecx, [edi + 0x3c]
0x00503540  call     0x6b9200
0x00503545  mov      ecx, dword ptr [ebp - 0x14]
0x00503548  lea      ebx, [edi + 4]
0x0050354B  movzx    eax, cx
0x0050354E  mov      dword ptr [edi + 0x40], eax
0x00503551  push     ecx
0x00503552  mov      eax, esp
0x00503554  mov      dword ptr [edi + 0x44], 0
0x0050355B  mov      dword ptr [eax], edi
0x0050355D  lock inc dword ptr [ebx]
0x00503560  mov      ecx, dword ptr [ebp - 0x18]
0x00503563  call     0x4ed820
0x00503568  or       eax, 0xffffffff
0x0050356B  lock xadd dword ptr [ebx], eax
0x0050356F  jne      0x503579
0x00503571  mov      eax, dword ptr [edi]
0x00503573  mov      ecx, edi
0x00503575  push     1
0x00503577  call     dword ptr [eax]
0x00503579  mov      dword ptr [ebp - 4], 7
0x00503580  add      dword ptr [esi], -1
0x00503583  jne      0x5039f7
0x00503589  mov      ecx, esi
0x0050358B  call     0x6ba940
0x00503590  mov      ecx, dword ptr [ebp - 0xc]
0x00503593  mov      dword ptr fs:[0], ecx
0x0050359A  pop      ecx
0x0050359B  pop      edi
0x0050359C  pop      esi
0x0050359D  pop      ebx
0x0050359E  mov      esp, ebp
0x005035A0  pop      ebp
0x005035A1  ret      4
0x005035A4  cmp      byte ptr [ecx + 0xd], 0
0x005035A8  movzx    eax, word ptr [ecx + 0x10]
0x005035AC  jne      0x5035d8
0x005035AE  push     ecx
0x005035AF  push     eax
0x005035B0  call     dword ptr [0x715038]
0x005035B6  add      esp, 4
0x005035B9  .byte    0x0f
0x005035BA  .byte    0xb7


======== VA 0x0058273B (file 0x181B3B) ========
0x005826C3  ret      0xc
0x005826C6  int3     
0x005826C7  int3     
0x005826C8  int3     
0x005826C9  int3     
0x005826CA  int3     
0x005826CB  int3     
0x005826CC  int3     
0x005826CD  int3     
0x005826CE  int3     
0x005826CF  int3     
0x005826D0  push     ebp
0x005826D1  mov      ebp, esp
0x005826D3  push     -1
0x005826D5  push     0x70639d
0x005826DA  mov      eax, dword ptr fs:[0]
0x005826E0  push     eax
0x005826E1  sub      esp, 0x28
0x005826E4  push     ebx
0x005826E5  push     esi
0x005826E6  push     edi
0x005826E7  mov      eax, dword ptr [0x76700c]
0x005826EC  xor      eax, ebp
0x005826EE  push     eax
0x005826EF  lea      eax, [ebp - 0xc]
0x005826F2  mov      dword ptr fs:[0], eax
0x005826F8  mov      edi, ecx
0x005826FA  mov      dword ptr [ebp - 0x28], edi
0x005826FD  mov      esi, dword ptr [ebp + 8]
0x00582700  mov      ebx, dword ptr [0x715340]
0x00582706  cmp      esi, dword ptr [edi + 0xc]
0x00582709  jb       0x582718
0x0058270B  push     0
0x0058270D  push     0
0x0058270F  push     1
0x00582711  push     0xc000008c
0x00582716  call     ebx
0x00582718  imul     esi, esi, 0x54
0x0058271B  mov      edx, 0x72a7d0
0x00582720  push     0x148
0x00582725  mov      ecx, 0x400
0x0058272A  add      esi, dword ptr [edi + 8]
0x0058272D  mov      dword ptr [ebp - 0x14], esi
0x00582730  mov      byte ptr [esi + 0x2c], 1
0x00582734  call     0x6ba810
0x00582739  mov      edx, dword ptr [0x772400]
0x0058273F  lea      ecx, [ebp - 0x2c]
0x00582742  add      esp, 4
0x00582745  mov      dword ptr [ebp - 0x18], eax
0x00582748  lea      edx, [edx + 0xa3e8]
0x0058274E  push     esi
0x0058274F  call     0x6b9410
0x00582754  add      esp, 4
0x00582757  mov      ecx, dword ptr [eax]
0x00582759  add      ecx, 0xc
0x0058275C  push     0x721dd0
0x00582761  push     ecx
0x00582762  call     0x6d298f
0x00582767  add      esp, 8
0x0058276A  mov      dword ptr [ebp - 0x1c], eax
0x0058276D  mov      dword ptr [ebp - 4], 0
0x00582774  mov      ecx, dword ptr [ebp - 0x2c]
0x00582777  test     ecx, ecx
0x00582779  je       0x582788
0x0058277B  add      dword ptr [ecx], -1
0x0058277E  jne      0x582788
0x00582780  call     0x6ba940
0x00582785  mov      eax, dword ptr [ebp - 0x1c]
0x00582788  mov      dword ptr [ebp - 4], 0xffffffff
0x0058278F  test     eax, eax
0x00582791  je       0x582f91
0x00582797  push     dword ptr [edi + 4]
0x0058279A  lea      ecx, [esi + 0x34]
0x0058279D  call     0x40b980
0x005827A2  xor      edi, edi
0x005827A4  cmp      dword ptr [esi + 0x38], edi
0x005827A7  jle      0x5827cb
0x005827A9  cmp      edi, dword ptr [esi + 0x38]
0x005827AC  jb       0x5827bb
0x005827AE  push     0
0x005827B0  push     0
0x005827B2  push     1
0x005827B4  push     0xc000008c
0x005827B9  call     ebx
0x005827BB  mov      eax, dword ptr [esi + 0x34]
0x005827BE  mov      dword ptr [eax + edi*4], 0
0x005827C5  inc      edi
0x005827C6  cmp      edi, dword ptr [esi + 0x38]
0x005827C9  jl       0x5827ac
0x005827CB  push     0
0x005827CD  push     ecx
0x005827CE  mov      ecx, dword ptr [esi]
0x005827D0  mov      eax, esp
0x005827D2  mov      dword ptr [eax], ecx
0x005827D4  test     ecx, ecx
0x005827D6  je       0x5827da
0x005827D8  inc      dword ptr [ecx]
0x005827DA  push     dword ptr [ebp + 8]
0x005827DD  mov      ecx, dword ptr [ebp - 0x28]
0x005827E0  call     0x581d30
0x005827E5  push     dword ptr [ebp - 0x1c]
0x005827E8  mov      bl, al
0x005827EA  call     0x6d4666
0x005827EF  add      esp, 4
0x005827F2  test     bl, bl
0x005827F4  je       0x582f91
0x005827FA  cmp      byte ptr [esi + 0x40], 0
0x005827FE  .byte    0x0f
0x005827FF  test     dword ptr [eax + 1], eax
0x00582802  .byte    0x00


======== VA 0x00628A0C (file 0x227E0C) ========
0x00628994  add      bl, ch
0x00628997  or       byte ptr [ebx + 0xf00dc7d], al
0x0062899D  xchg     ebp, eax
0x0062899E  inc      ebp
0x0062899F  mov      eax, dword ptr [ebp - 0x1c]
0x006289A3  dec      dword ptr [eax]
0x006289A5  cmp      dword ptr [eax], 0
0x006289A8  jg       0x6289b4
0x006289AA  push     eax
0x006289AB  call     dword ptr [0x715540]
0x006289B1  add      esp, 4
0x006289B4  cmp      byte ptr [ebp - 0xe], 0
0x006289B8  mov      eax, dword ptr [ebp + 0x10]
0x006289BB  je       0x628a3a
0x006289BD  cmp      eax, 7
0x006289C0  jle      0x628a3a
0x006289C2  push     7
0x006289C4  lea      ecx, [ebp - 0x54]
0x006289C7  call     0x4295e0
0x006289CC  lea      ecx, [ebp - 0x24]
0x006289CF  mov      eax, dword ptr [eax]
0x006289D1  mov      dword ptr [ebp - 0x1c], eax
0x006289D4  mov      dword ptr [ebp - 0x24], eax
0x006289D7  test     eax, eax
0x006289D9  je       0x628a00
0x006289DB  inc      dword ptr [eax]
0x006289DD  call     0x6baf10
0x006289E2  mov      cl, al
0x006289E4  mov      eax, dword ptr [ebp - 0x1c]
0x006289E7  mov      byte ptr [ebp - 0xf], cl
0x006289EA  dec      dword ptr [eax]
0x006289EC  cmp      dword ptr [eax], 0
0x006289EF  jg       0x628a07
0x006289F1  push     eax
0x006289F2  call     dword ptr [0x715540]
0x006289F8  mov      cl, byte ptr [ebp - 0xf]
0x006289FB  add      esp, 4
0x006289FE  jmp      0x628a07
0x00628A00  call     0x6baf10
0x00628A05  mov      cl, al
0x00628A07  test     cl, cl
0x00628A09  je       0x628a37
0x00628A0B  mov      eax, dword ptr [0x772400]
0x00628A10  mov      byte ptr [eax + 0x8b], 1
0x00628A17  cmp      byte ptr [eax + 0xa098], 0
0x00628A1E  je       0x628a27
0x00628A20  mov      byte ptr [eax + 0xa098], 0
0x00628A27  mov      eax, dword ptr [ebp - 0x14]
0x00628A2A  mov      byte ptr [eax + 0x148], 1
0x00628A31  jmp      0x628a37
0x00628A33  mov      byte ptr [ebp - 0xe], 0
0x00628A37  mov      eax, dword ptr [ebp + 0x10]
0x00628A3A  cmp      eax, 8
0x00628A3D  jle      0x628adb
0x00628A43  cmp      dword ptr [ebp - 0x4c], 8
0x00628A47  jg       0x628a6e
0x00628A49  push     0
0x00628A4B  push     0
0x00628A4D  push     1
0x00628A4F  push     0xc000008c
0x00628A54  call     ebx
0x00628A56  cmp      dword ptr [ebp - 0x50], 0
0x00628A5A  ja       0x628a69
0x00628A5C  push     0
0x00628A5E  push     0
0x00628A60  push     1
0x00628A62  push     0xc000008c
0x00628A67  call     ebx
0x00628A69  mov      eax, dword ptr [ebp - 0x54]
0x00628A6C  jmp      0x628a87
0x00628A6E  cmp      dword ptr [ebp - 0x50], 8
0x00628A72  ja       0x628a81
0x00628A74  push     0
0x00628A76  push     0
0x00628A78  push     1
0x00628A7A  push     0xc000008c
0x00628A7F  call     ebx
0x00628A81  mov      eax, dword ptr [ebp - 0x54]
0x00628A84  add      eax, 0x20
0x00628A87  mov      eax, dword ptr [eax]
0x00628A89  mov      dword ptr [ebp - 0x24], eax
0x00628A8C  test     eax, eax
0x00628A8E  je       0x628ad0
0x00628A90  inc      dword ptr [eax]
0x00628A92  lea      ecx, [ebp - 0x20]
0x00628A95  push     ecx
0x00628A96  push     eax
0x00628A97  push     0
0x00628A99  call     dword ptr [0x715534]
0x00628A9F  add      esp, 0xc
0x00628AA2  cmp      eax, 1
0x00628AA5  jne      0x628aac
0x00628AA7  xorps    xmm0, xmm0
0x00628AAA  jmp      0x628ab5
0x00628AAC  movsd    xmm0, qword ptr [ebp - 0x20]
0x00628AB1  cvtpd2ps xmm0, xmm0
0x00628AB5  mov      eax, dword ptr [ebp - 0x24]
0x00628AB8  movss    dword ptr [ebp - 0x18], xmm0
0x00628ABD  dec      dword ptr [eax]
0x00628ABF  cmp      dword ptr [eax], 0
0x00628AC2  jg       0x628ad8
0x00628AC4  push     eax
0x00628AC5  call     dword ptr [0x715540]
0x00628ACB  add      esp, 4
0x00628ACE  jmp      0x628ad8
0x00628AD0  xorps    xmm0, xmm0
0x00628AD3  .byte    0xf3


======== VA 0x0062A71C (file 0x229B1C) ========
0x0062A6A4  call     0x6a701da9
0x0062A6A9  add      byte ptr [edx], ch
0x0062A6AC  push     1
0x0062A6AE  push     0xc000008c
0x0062A6B3  call     ebx
0x0062A6B5  mov      eax, dword ptr [ebp - 0x1c]
0x0062A6B8  jmp      0x62a6d3
0x0062A6BA  cmp      dword ptr [ebp - 0x18], 8
0x0062A6BE  ja       0x62a6cd
0x0062A6C0  push     0
0x0062A6C2  push     0
0x0062A6C4  push     1
0x0062A6C6  push     0xc000008c
0x0062A6CB  call     ebx
0x0062A6CD  mov      eax, dword ptr [ebp - 0x1c]
0x0062A6D0  add      eax, 0x20
0x0062A6D3  mov      eax, dword ptr [eax]
0x0062A6D5  mov      dword ptr [ebp - 0x28], eax
0x0062A6D8  test     eax, eax
0x0062A6DA  je       0x62a747
0x0062A6DC  inc      dword ptr [eax]
0x0062A6DE  lea      ecx, [ebp - 0x24]
0x0062A6E1  push     ecx
0x0062A6E2  push     eax
0x0062A6E3  push     0
0x0062A6E5  call     dword ptr [0x7155b0]
0x0062A6EB  add      esp, 0xc
0x0062A6EE  cmp      eax, 1
0x0062A6F1  jne      0x62a6f9
0x0062A6F3  mov      byte ptr [ebp - 0x1d], 0
0x0062A6F7  jmp      0x62a701
0x0062A6F9  cmp      dword ptr [ebp - 0x24], 0
0x0062A6FD  setne    byte ptr [ebp - 0x1d]
0x0062A701  mov      eax, dword ptr [ebp - 0x28]
0x0062A704  dec      dword ptr [eax]
0x0062A706  cmp      dword ptr [eax], 0
0x0062A709  jg       0x62a715
0x0062A70B  push     eax
0x0062A70C  call     dword ptr [0x715540]
0x0062A712  add      esp, 4
0x0062A715  cmp      byte ptr [ebp - 0x1d], 0
0x0062A719  je       0x62a747
0x0062A71B  mov      eax, dword ptr [0x772400]
0x0062A720  mov      byte ptr [eax + 0x8b], 1
0x0062A727  cmp      byte ptr [eax + 0xa098], 0
0x0062A72E  je       0x62a737
0x0062A730  mov      byte ptr [eax + 0xa098], 0
0x0062A737  mov      eax, dword ptr [ebp - 0x34]
0x0062A73A  mov      byte ptr [eax + 0x148], 1
0x0062A741  jmp      0x62a747
0x0062A743  mov      byte ptr [ebp - 0xd], 0
0x0062A747  mov      eax, dword ptr [ebp + 0x10]
0x0062A74A  movss    xmm0, dword ptr [0x737138]
0x0062A752  cmp      eax, 9
0x0062A755  jle      0x62a7f0
0x0062A75B  cmp      dword ptr [ebp - 0x14], 9
0x0062A75F  jg       0x62a786
0x0062A761  push     0
0x0062A763  push     0
0x0062A765  push     1
0x0062A767  push     0xc000008c
0x0062A76C  call     ebx
0x0062A76E  cmp      dword ptr [ebp - 0x18], 0
0x0062A772  ja       0x62a781
0x0062A774  push     0
0x0062A776  push     0
0x0062A778  push     1
0x0062A77A  push     0xc000008c
0x0062A77F  call     ebx
0x0062A781  mov      eax, dword ptr [ebp - 0x1c]
0x0062A784  jmp      0x62a79f
0x0062A786  cmp      dword ptr [ebp - 0x18], 9
0x0062A78A  ja       0x62a799
0x0062A78C  push     0
0x0062A78E  push     0
0x0062A790  push     1
0x0062A792  push     0xc000008c
0x0062A797  call     ebx
0x0062A799  mov      eax, dword ptr [ebp - 0x1c]
0x0062A79C  add      eax, 0x24
0x0062A79F  mov      eax, dword ptr [eax]
0x0062A7A1  mov      dword ptr [ebp - 0x50], eax
0x0062A7A4  test     eax, eax
0x0062A7A6  je       0x62a7ed
0x0062A7A8  inc      dword ptr [eax]
0x0062A7AA  lea      ecx, [ebp - 0x5c]
0x0062A7AD  push     ecx
0x0062A7AE  push     eax
0x0062A7AF  push     0
0x0062A7B1  call     dword ptr [0x715534]
0x0062A7B7  add      esp, 0xc
0x0062A7BA  cmp      eax, 1
0x0062A7BD  jne      0x62a7c4
0x0062A7BF  xorps    xmm0, xmm0
0x0062A7C2  jmp      0x62a7cd
0x0062A7C4  movsd    xmm0, qword ptr [ebp - 0x5c]
0x0062A7C9  cvtpd2ps xmm0, xmm0
0x0062A7CD  mov      eax, dword ptr [ebp - 0x50]
0x0062A7D0  movss    dword ptr [ebp - 0x24], xmm0
0x0062A7D5  dec      dword ptr [eax]
0x0062A7D7  cmp      dword ptr [eax], 0
0x0062A7DA  jg       0x62a7f0
0x0062A7DC  push     eax
0x0062A7DD  call     dword ptr [0x715540]
0x0062A7E3  .byte    0xf3


======== VA 0x0064134C (file 0x24074C) ========
0x006412D4  loope    0x6412dc
0x006412D6  add      ecx, 0x773650
0x006412DC  call     0x43fd30
0x006412E1  mov      eax, esi
0x006412E3  mov      ecx, dword ptr [ebp - 0xc]
0x006412E6  mov      dword ptr fs:[0], ecx
0x006412ED  pop      ecx
0x006412EE  pop      edi
0x006412EF  pop      esi
0x006412F0  pop      ebx
0x006412F1  mov      esp, ebp
0x006412F3  pop      ebp
0x006412F4  ret      
0x006412F5  test     eax, eax
0x006412F7  jne      0x641300
0x006412F9  mov      ecx, 0x71ce50
0x006412FE  jmp      0x64130d
0x00641300  push     0
0x00641302  push     eax
0x00641303  call     esi
0x00641305  mov      ecx, eax
0x00641307  add      esp, 8
0x0064130A  mov      eax, dword ptr [ebp - 0x18]
0x0064130D  mov      edx, 0x722be8
0x00641312  mov      bl, byte ptr [ecx]
0x00641314  cmp      bl, byte ptr [edx]
0x00641316  jne      0x641332
0x00641318  test     bl, bl
0x0064131A  je       0x64132e
0x0064131C  mov      bl, byte ptr [ecx + 1]
0x0064131F  cmp      bl, byte ptr [edx + 1]
0x00641322  jne      0x641332
0x00641324  add      ecx, 2
0x00641327  add      edx, 2
0x0064132A  test     bl, bl
0x0064132C  jne      0x641312
0x0064132E  xor      ecx, ecx
0x00641330  jmp      0x641337
0x00641332  sbb      ecx, ecx
0x00641334  or       ecx, 1
0x00641337  test     ecx, ecx
0x00641339  jne      0x641747
0x0064133F  xor      edi, edi
0x00641341  mov      dword ptr [ebp - 0x14], edi
0x00641344  mov      byte ptr [ebp - 4], 9
0x00641348  lea      ecx, [ebp - 0x10]
0x0064134B  mov      eax, dword ptr [0x772400]
0x00641350  mov      ebx, dword ptr [eax + 0x14c]
0x00641356  mov      dword ptr [ebp - 0x40], ebx
0x00641359  call     0x6b8f50
0x0064135E  test     ebx, ebx
0x00641360  jne      0x6413b2
0x00641362  push     ebx
0x00641363  push     ebx
0x00641364  call     dword ptr [0x71554c]
0x0064136A  add      esp, 8
0x0064136D  mov      dword ptr [ebp + 0x10], eax
0x00641370  test     eax, eax
0x00641372  je       0x641376
0x00641374  inc      dword ptr [eax]
0x00641376  lea      eax, [ebp + 0x10]
0x00641379  push     eax
0x0064137A  lea      ecx, [ebp - 0x14]
0x0064137D  call     0x6baea0
0x00641382  lea      ecx, [ebp + 0x10]
0x00641385  call     0x6bad60
0x0064138A  mov      edi, dword ptr [ebp - 0x14]
0x0064138D  mov      esi, dword ptr [ebp - 0x10]
0x00641390  mov      eax, dword ptr [ebp - 0x64]
0x00641393  test     eax, eax
0x00641395  je       0x64171a
0x0064139B  test     edi, edi
0x0064139D  jne      0x64170f
0x006413A3  push     eax
0x006413A4  call     dword ptr [0x71555c]
0x006413AA  add      esp, 4
0x006413AD  jmp      0x64171a
0x006413B2  xor      eax, eax
0x006413B4  mov      dword ptr [ebp - 0x1c], eax
0x006413B7  test     ebx, ebx
0x006413B9  jle      0x64138d
0x006413BB  mov      esi, dword ptr [ebp - 0x10]
0x006413BE  xor      ebx, ebx
0x006413C0  mov      dword ptr [ebp - 0x24], ebx
0x006413C3  nop      dword ptr [eax]
0x006413C7  nop      word ptr [eax + eax]
0x006413D0  mov      edi, dword ptr [0x772400]
0x006413D6  cmp      eax, dword ptr [edi + 0x14c]
0x006413DC  jb       0x6413ef
0x006413DE  push     0
0x006413E0  push     0
0x006413E2  push     1
0x006413E4  push     0xc000008c
0x006413E9  call     dword ptr [0x715340]
0x006413EF  mov      ecx, dword ptr [edi + 0x148]
0x006413F5  add      ecx, ebx
0x006413F7  mov      eax, dword ptr [ecx + 4]
0x006413FA  mov      edx, dword ptr [ecx]
0x006413FC  mov      dword ptr [ebp - 0x70], eax
0x006413FF  mov      al, byte ptr [ecx + 8]
0x00641402  mov      byte ptr [ebp + 0x13], al
0x00641405  mov      byte ptr [ebp - 0x6c], al
0x00641408  mov      eax, dword ptr [ecx + 0xc]
0x0064140B  mov      dword ptr [ebp - 0x74], edx
0x0064140E  mov      dword ptr [ebp - 0x3c], eax
0x00641411  mov      dword ptr [ebp - 0x68], eax


======== VA 0x006413D2 (file 0x2407D2) ========
0x0064135A  bnd jnp  0x641364
0x0064135D  add      byte ptr [ebp + 0x535075db], al
0x00641363  push     ebx
0x00641364  call     dword ptr [0x71554c]
0x0064136A  add      esp, 8
0x0064136D  mov      dword ptr [ebp + 0x10], eax
0x00641370  test     eax, eax
0x00641372  je       0x641376
0x00641374  inc      dword ptr [eax]
0x00641376  lea      eax, [ebp + 0x10]
0x00641379  push     eax
0x0064137A  lea      ecx, [ebp - 0x14]
0x0064137D  call     0x6baea0
0x00641382  lea      ecx, [ebp + 0x10]
0x00641385  call     0x6bad60
0x0064138A  mov      edi, dword ptr [ebp - 0x14]
0x0064138D  mov      esi, dword ptr [ebp - 0x10]
0x00641390  mov      eax, dword ptr [ebp - 0x64]
0x00641393  test     eax, eax
0x00641395  je       0x64171a
0x0064139B  test     edi, edi
0x0064139D  jne      0x64170f
0x006413A3  push     eax
0x006413A4  call     dword ptr [0x71555c]
0x006413AA  add      esp, 4
0x006413AD  jmp      0x64171a
0x006413B2  xor      eax, eax
0x006413B4  mov      dword ptr [ebp - 0x1c], eax
0x006413B7  test     ebx, ebx
0x006413B9  jle      0x64138d
0x006413BB  mov      esi, dword ptr [ebp - 0x10]
0x006413BE  xor      ebx, ebx
0x006413C0  mov      dword ptr [ebp - 0x24], ebx
0x006413C3  nop      dword ptr [eax]
0x006413C7  nop      word ptr [eax + eax]
0x006413D0  mov      edi, dword ptr [0x772400]
0x006413D6  cmp      eax, dword ptr [edi + 0x14c]
0x006413DC  jb       0x6413ef
0x006413DE  push     0
0x006413E0  push     0
0x006413E2  push     1
0x006413E4  push     0xc000008c
0x006413E9  call     dword ptr [0x715340]
0x006413EF  mov      ecx, dword ptr [edi + 0x148]
0x006413F5  add      ecx, ebx
0x006413F7  mov      eax, dword ptr [ecx + 4]
0x006413FA  mov      edx, dword ptr [ecx]
0x006413FC  mov      dword ptr [ebp - 0x70], eax
0x006413FF  mov      al, byte ptr [ecx + 8]
0x00641402  mov      byte ptr [ebp + 0x13], al
0x00641405  mov      byte ptr [ebp - 0x6c], al
0x00641408  mov      eax, dword ptr [ecx + 0xc]
0x0064140B  mov      dword ptr [ebp - 0x74], edx
0x0064140E  mov      dword ptr [ebp - 0x3c], eax
0x00641411  mov      dword ptr [ebp - 0x68], eax
0x00641414  test     eax, eax
0x00641416  je       0x64141a
0x00641418  inc      dword ptr [eax]
0x0064141A  push     edx
0x0064141B  lea      eax, [ebp - 0x30]
0x0064141E  mov      byte ptr [ebp - 4], 0xb
0x00641422  push     eax
0x00641423  call     0x4e4cf0
0x00641428  mov      ebx, eax
0x0064142A  mov      byte ptr [ebp - 4], 0xc
0x0064142E  mov      ecx, esi
0x00641430  mov      esi, dword ptr [ebx]
0x00641432  mov      edi, esi
0x00641434  mov      dword ptr [ebp - 0x10], esi
0x00641437  test     esi, esi
0x00641439  je       0x64143d
0x0064143B  inc      dword ptr [esi]
0x0064143D  test     ecx, ecx
0x0064143F  je       0x64144b
0x00641441  add      dword ptr [ecx], -1
0x00641444  jne      0x64144b
0x00641446  call     0x6ba940
0x0064144B  mov      eax, dword ptr [ebx]
0x0064144D  mov      eax, dword ptr [eax + 8]
0x00641450  mov      dword ptr [esi + 8], eax
0x00641453  mov      byte ptr [ebp - 4], 0xd
0x00641457  mov      ecx, dword ptr [ebp - 0x30]
0x0064145A  test     ecx, ecx
0x0064145C  je       0x641468
0x0064145E  add      dword ptr [ecx], -1
0x00641461  jne      0x641468
0x00641463  call     0x6ba940
0x00641468  mov      byte ptr [ebp - 4], 0xb
0x0064146C  mov      bl, byte ptr [ebp - 0x70]
0x0064146F  test     bl, 1
0x00641472  je       0x6414cc
0x00641474  push     0x72fc00
0x00641479  lea      edx, [ebp - 0x10]
0x0064147C  lea      ecx, [ebp - 0x2c]
0x0064147F  call     0x6b9500
0x00641484  add      esp, 4
0x00641487  mov      ebx, eax
0x00641489  mov      byte ptr [ebp - 4], 0xe
0x0064148D  mov      esi, dword ptr [ebx]
0x0064148F  mov      dword ptr [ebp - 0x10], esi
0x00641492  test     esi, esi
0x00641494  je       0x641498
0x00641496  inc      dword ptr [esi]
0x00641498  test     edi, edi


======== VA 0x006419F4 (file 0x240DF4) ========
0x0064197C  call     0x6bafc0
0x00641981  mov      esi, eax
0x00641983  movsx    ecx, byte ptr [esi]
0x00641986  push     ecx
0x00641987  call     0x6dba03
0x0064198C  add      esp, 4
0x0064198F  cmp      eax, 0x66
0x00641992  jne      0x6419ba
0x00641994  movsx    ecx, byte ptr [esi + 1]
0x00641998  push     ecx
0x00641999  call     0x6d998f
0x0064199E  add      esp, 4
0x006419A1  test     eax, eax
0x006419A3  je       0x6419ba
0x006419A5  movsx    eax, byte ptr [esi + 2]
0x006419A9  push     eax
0x006419AA  call     0x6d998f
0x006419AF  add      esp, 4
0x006419B2  test     eax, eax
0x006419B4  je       0x641b1a
0x006419BA  push     ebx
0x006419BB  lea      ecx, [ebp - 0x54]
0x006419BE  call     0x4295e0
0x006419C3  mov      esi, dword ptr [eax]
0x006419C5  mov      dword ptr [ebp - 0x3c], esi
0x006419C8  test     esi, esi
0x006419CA  je       0x6419ce
0x006419CC  inc      dword ptr [esi]
0x006419CE  mov      byte ptr [ebp - 4], 0x1b
0x006419D2  test     esi, esi
0x006419D4  jne      0x6419dd
0x006419D6  mov      eax, 0x71ce50
0x006419DB  jmp      0x6419e9
0x006419DD  push     0
0x006419DF  push     esi
0x006419E0  call     dword ptr [0x715544]
0x006419E6  add      esp, 8
0x006419E9  push     eax
0x006419EA  lea      ecx, [ebp - 0x20]
0x006419ED  call     0x6b8fb0
0x006419F2  mov      ebx, dword ptr [0x772400]
0x006419F8  add      ebx, 0x148
0x006419FE  mov      byte ptr [ebp - 4], 0x1c
0x00641A02  mov      ecx, ebx
0x00641A04  push     dword ptr [ebp - 0x2c]
0x00641A07  push     dword ptr [ebp - 0x14]
0x00641A0A  push     dword ptr [ebp - 0x30]
0x00641A0D  call     0x4e4b90
0x00641A12  mov      ecx, eax
0x00641A14  mov      dword ptr [ebp + 0x10], eax
0x00641A17  cmp      ecx, -1
0x00641A1A  jne      0x641aa7
0x00641A20  push     1
0x00641A22  mov      ecx, ebx
0x00641A24  call     0x4e4f40
0x00641A29  mov      eax, dword ptr [ebx + 4]
0x00641A2C  lea      ecx, [eax - 1]
0x00641A2F  mov      dword ptr [ebp + 0x10], ecx
0x00641A32  cmp      ecx, eax
0x00641A34  jb       0x641a4a
0x00641A36  push     0
0x00641A38  push     0
0x00641A3A  push     1
0x00641A3C  push     0xc000008c
0x00641A41  call     dword ptr [0x715340]
0x00641A47  mov      ecx, dword ptr [ebp + 0x10]
0x00641A4A  mov      eax, dword ptr [ebx]
0x00641A4C  mov      edx, ecx
0x00641A4E  mov      edi, dword ptr [ebp - 0x30]
0x00641A51  shl      edx, 4
0x00641A54  mov      dword ptr [ebp - 0x2c], edx
0x00641A57  mov      dword ptr [edx + eax], edi
0x00641A5A  cmp      ecx, dword ptr [ebx + 4]
0x00641A5D  jb       0x641a76
0x00641A5F  push     0
0x00641A61  push     0
0x00641A63  push     1
0x00641A65  push     0xc000008c
0x00641A6A  call     dword ptr [0x715340]
0x00641A70  mov      ecx, dword ptr [ebp + 0x10]
0x00641A73  mov      edx, dword ptr [ebp - 0x2c]
0x00641A76  mov      eax, dword ptr [ebx]
0x00641A78  mov      edi, dword ptr [ebp - 0x14]
0x00641A7B  mov      dword ptr [edx + eax + 4], edi
0x00641A7F  mov      edi, dword ptr [ebp - 0x10]
0x00641A82  cmp      ecx, dword ptr [ebx + 4]
0x00641A85  jb       0x641a9b
0x00641A87  push     0
0x00641A89  push     0
0x00641A8B  push     1
0x00641A8D  push     0xc000008c
0x00641A92  call     dword ptr [0x715340]
0x00641A98  mov      edx, dword ptr [ebp - 0x2c]
0x00641A9B  mov      eax, dword ptr [ebx]
0x00641A9D  mov      ecx, dword ptr [ebp - 0x1c]
0x00641AA0  mov      byte ptr [edx + eax + 8], cl
0x00641AA4  mov      ecx, dword ptr [ebp + 0x10]
0x00641AA7  cmp      ecx, dword ptr [ebx + 4]
0x00641AAA  jb       0x641ac0
0x00641AAC  push     0
0x00641AAE  push     0
0x00641AB0  push     1
0x00641AB2  push     0xc000008c
0x00641AB7  .byte    0xff
0x00641AB8  .byte    0x15
0x00641AB9  inc      eax
0x00641ABA  push     ebx
0x00641ABB  .byte    0x71


======== VA 0x00641D5D (file 0x24115D) ========
0x00641CE5  sbb      al, byte ptr [edx + edx*8 + 0x508a1274]
0x00641CEC  add      dword ptr [edx], edi
0x00641CEE  push     ecx
0x00641CEF  add      dword ptr [ebp + 0xe], esi
0x00641CF2  add      eax, 2
0x00641CF5  add      ecx, 2
0x00641CF8  test     dl, dl
0x00641CFA  jne      0x641ce0
0x00641CFC  xor      eax, eax
0x00641CFE  jmp      0x641d05
0x00641D00  sbb      eax, eax
0x00641D02  or       eax, 1
0x00641D05  mov      ebx, esi
0x00641D07  or       ebx, 2
0x00641D0A  test     eax, eax
0x00641D0C  mov      eax, 0x72fc48
0x00641D11  cmovne   ebx, esi
0x00641D14  mov      cl, byte ptr [edi]
0x00641D16  cmp      cl, byte ptr [eax]
0x00641D18  jne      0x641d34
0x00641D1A  test     cl, cl
0x00641D1C  je       0x641d30
0x00641D1E  mov      cl, byte ptr [edi + 1]
0x00641D21  cmp      cl, byte ptr [eax + 1]
0x00641D24  jne      0x641d34
0x00641D26  add      edi, 2
0x00641D29  add      eax, 2
0x00641D2C  test     cl, cl
0x00641D2E  jne      0x641d14
0x00641D30  xor      eax, eax
0x00641D32  jmp      0x641d39
0x00641D34  sbb      eax, eax
0x00641D36  or       eax, 1
0x00641D39  mov      ecx, dword ptr [ebp - 0x30]
0x00641D3C  xor      edx, edx
0x00641D3E  test     eax, eax
0x00641D40  movzx    ecx, cl
0x00641D43  cmove    ecx, edx
0x00641D46  mov      dword ptr [ebp - 0x30], ecx
0x00641D49  mov      al, cl
0x00641D4B  mov      ecx, dword ptr [ebp - 0x2c]
0x00641D4E  inc      ecx
0x00641D4F  mov      dword ptr [ebp - 0x2c], ecx
0x00641D52  cmp      ecx, dword ptr [ebp + 0x10]
0x00641D55  jl       0x641c35
0x00641D5B  mov      ecx, dword ptr [0x772400]
0x00641D61  push     eax
0x00641D62  push     ebx
0x00641D63  push     dword ptr [ebp - 0x40]
0x00641D66  lea      eax, [ebp + 0x10]
0x00641D69  push     eax
0x00641D6A  lea      ecx, [ecx + 0x148]
0x00641D70  call     0x4e4c40
0x00641D75  mov      edi, dword ptr [ebp + 0x10]
0x00641D78  lea      eax, [edi + 0xc]
0x00641D7B  test     eax, eax
0x00641D7D  jne      0x641d83
0x00641D7F  xor      esi, esi
0x00641D81  jmp      0x641d93
0x00641D83  push     -1
0x00641D85  push     eax
0x00641D86  call     dword ptr [0x715564]
0x00641D8C  mov      esi, eax
0x00641D8E  add      esp, 8
0x00641D91  inc      dword ptr [esi]
0x00641D93  lea      eax, [ebp + 0x10]
0x00641D96  mov      dword ptr [ebp + 0x10], esi
0x00641D99  push     eax
0x00641D9A  lea      ecx, [ebp - 0x64]
0x00641D9D  call     0x6bc670
0x00641DA2  test     esi, esi
0x00641DA4  je       0x641db7
0x00641DA6  dec      dword ptr [esi]
0x00641DA8  cmp      dword ptr [esi], 0
0x00641DAB  jg       0x641db7
0x00641DAD  push     esi
0x00641DAE  call     dword ptr [0x715540]
0x00641DB4  add      esp, 4
0x00641DB7  xor      esi, esi
0x00641DB9  mov      byte ptr [ebp - 4], 0x21
0x00641DBD  test     edi, edi
0x00641DBF  je       0x641dcd
0x00641DC1  add      dword ptr [edi], -1
0x00641DC4  jne      0x641dcd
0x00641DC6  mov      ecx, edi
0x00641DC8  call     0x6ba940
0x00641DCD  mov      byte ptr [ebp - 4], 0x22
0x00641DD1  mov      ecx, dword ptr [ebp - 0x3c]
0x00641DD4  test     ecx, ecx
0x00641DD6  je       0x641de2
0x00641DD8  add      dword ptr [ecx], -1
0x00641DDB  jne      0x641de2
0x00641DDD  call     0x6ba940
0x00641DE2  lea      ecx, [ebp - 0x28]
0x00641DE5  call     0x6bad60
0x00641DEA  jmp      0x641285
0x00641DEF  lea      ecx, [ebp - 0x44]
0x00641DF2  mov      esi, 0x72fc50
0x00641DF7  call     0x6bafc0
0x00641DFC  nop      dword ptr [eax]
0x00641E00  mov      cl, byte ptr [eax]
0x00641E02  cmp      cl, byte ptr [esi]
0x00641E04  jne      0x641e20
0x00641E06  test     cl, cl
0x00641E08  je       0x641e1c
0x00641E0A  mov      cl, byte ptr [eax + 1]
0x00641E0D  cmp      cl, byte ptr [esi + 1]
0x00641E10  jne      0x641e20
0x00641E12  add      eax, 2
0x00641E15  add      esi, 2
0x00641E18  test     cl, cl
0x00641E1A  jne      0x641e00
0x00641E1C  xor      eax, eax
0x00641E1E  jmp      0x641e25
0x00641E20  sbb      eax, eax
0x00641E22  or       eax, 1


======== VA 0x00641FEB (file 0x2413EB) ========
0x00641F73  adc      dword ptr [ebp + 0x1a], esi
0x00641F76  test     dl, dl
0x00641F78  je       0x641f8c
0x00641F7A  mov      dl, byte ptr [eax + 1]
0x00641F7D  cmp      dl, byte ptr [ecx + 1]
0x00641F80  jne      0x641f90
0x00641F82  add      eax, 2
0x00641F85  add      ecx, 2
0x00641F88  test     dl, dl
0x00641F8A  jne      0x641f70
0x00641F8C  xor      eax, eax
0x00641F8E  jmp      0x641f95
0x00641F90  sbb      eax, eax
0x00641F92  or       eax, 1
0x00641F95  mov      ebx, esi
0x00641F97  or       ebx, 2
0x00641F9A  test     eax, eax
0x00641F9C  mov      eax, 0x72fc48
0x00641FA1  cmovne   ebx, esi
0x00641FA4  mov      cl, byte ptr [edi]
0x00641FA6  cmp      cl, byte ptr [eax]
0x00641FA8  jne      0x641fc4
0x00641FAA  test     cl, cl
0x00641FAC  je       0x641fc0
0x00641FAE  mov      cl, byte ptr [edi + 1]
0x00641FB1  cmp      cl, byte ptr [eax + 1]
0x00641FB4  jne      0x641fc4
0x00641FB6  add      edi, 2
0x00641FB9  add      eax, 2
0x00641FBC  test     cl, cl
0x00641FBE  jne      0x641fa4
0x00641FC0  xor      eax, eax
0x00641FC2  jmp      0x641fc9
0x00641FC4  sbb      eax, eax
0x00641FC6  or       eax, 1
0x00641FC9  mov      ecx, dword ptr [ebp - 0x30]
0x00641FCC  xor      edx, edx
0x00641FCE  test     eax, eax
0x00641FD0  movzx    ecx, cl
0x00641FD3  mov      eax, dword ptr [ebp - 0x2c]
0x00641FD6  cmove    ecx, edx
0x00641FD9  inc      eax
0x00641FDA  mov      dword ptr [ebp - 0x30], ecx
0x00641FDD  mov      dword ptr [ebp - 0x2c], eax
0x00641FE0  cmp      eax, dword ptr [ebp + 0x10]
0x00641FE3  jl       0x641ec1
0x00641FE9  mov      esi, dword ptr [0x772400]
0x00641FEF  mov      eax, dword ptr [ebp - 0x40]
0x00641FF2  add      esi, 0x148
0x00641FF8  cmp      eax, 0x200
0x00641FFD  jle      0x642002
0x00641FFF  sar      eax, 0x10
0x00642002  push     ecx
0x00642003  push     ebx
0x00642004  push     eax
0x00642005  mov      ecx, esi
0x00642007  call     0x4e4b90
0x0064200C  mov      edi, eax
0x0064200E  cmp      edi, -1
0x00642011  je       0x64208b
0x00642013  mov      eax, dword ptr [esi + 4]
0x00642016  mov      ebx, dword ptr [0x715340]
0x0064201C  cmp      edi, eax
0x0064201E  jb       0x642041
0x00642020  push     0
0x00642022  push     0
0x00642024  push     1
0x00642026  push     0xc000008c
0x0064202B  call     ebx
0x0064202D  mov      eax, dword ptr [esi + 4]
0x00642030  cmp      edi, eax
0x00642032  jb       0x642041
0x00642034  push     0
0x00642036  push     0
0x00642038  push     1
0x0064203A  push     0xc000008c
0x0064203F  call     ebx
0x00642041  mov      eax, dword ptr [esi]
0x00642043  mov      ebx, edi
0x00642045  shl      ebx, 4
0x00642048  mov      byte ptr [ebp - 4], 0x25
0x0064204C  mov      ecx, dword ptr [eax + ebx + 0xc]
0x00642050  test     ecx, ecx
0x00642052  je       0x64205e
0x00642054  add      dword ptr [ecx], -1
0x00642057  jne      0x64205e
0x00642059  call     0x6ba940
0x0064205E  mov      edx, dword ptr [esi + 4]
0x00642061  lea      eax, [edx - 1]
0x00642064  cmp      edi, eax
0x00642066  jge      0x642085
0x00642068  mov      ecx, dword ptr [esi]
0x0064206A  sub      edx, edi
0x0064206C  add      ecx, ebx
0x0064206E  shl      edx, 4
0x00642071  sub      edx, 0x10
0x00642074  push     edx
0x00642075  lea      eax, [ecx + 0x10]
0x00642078  push     eax
0x00642079  push     ecx
0x0064207A  call     0x6d1b90
0x0064207F  mov      edx, dword ptr [esi + 4]
0x00642082  add      esp, 0xc
0x00642085  lea      eax, [edx - 1]
0x00642088  mov      dword ptr [esi + 4], eax
0x0064208B  xor      esi, esi
0x0064208D  mov      byte ptr [ebp - 4], 0x26
0x00642091  mov      ecx, dword ptr [ebp - 0x3c]
0x00642094  test     ecx, ecx
0x00642096  je       0x6420a2
0x00642098  add      dword ptr [ecx], -1
0x0064209B  jne      0x6420a2
0x0064209D  call     0x6ba940
0x006420A2  lea      ecx, [ebp - 0x28]
0x006420A5  call     0x6bad60
0x006420AA  jmp      0x641285
0x006420AF  .byte    0x68
0x006420B0  .byte    0x68
0x006420B1  jo       0x64207d


======== VA 0x006AEC0F (file 0x2AE00F) ========
0x006AEB97  out      6, eax
0x006AEB99  mov      dword ptr [ebp - 0x1b4], 0xca7d44
0x006AEBA3  mov      esi, dword ptr [edi + 0x773650]
0x006AEBA9  call     0x43fcc0
0x006AEBAE  mov      ecx, dword ptr [eax + 0x8000]
0x006AEBB4  mov      dword ptr [eax + ecx*4], esi
0x006AEBB7  inc      dword ptr [eax + 0x8000]
0x006AEBBD  mov      eax, dword ptr [edi + 0x773654]
0x006AEBC3  test     eax, eax
0x006AEBC5  jne      0x6aebde
0x006AEBC7  call     0x6bd180
0x006AEBCC  mov      dword ptr [edi + 0x773658], eax
0x006AEBD2  mov      eax, dword ptr [edi + 0x773654]
0x006AEBD8  mov      dword ptr [edi + 0x77365c], edx
0x006AEBDE  inc      eax
0x006AEBDF  mov      dword ptr [edi + 0x773654], eax
0x006AEBE5  push     0x735954
0x006AEBEA  mov      dword ptr [ebp - 4], 0
0x006AEBF1  call     dword ptr [0x7152b4]
0x006AEBF7  cmp      eax, -1
0x006AEBFA  je       0x6aec00
0x006AEBFC  test     al, 0x10
0x006AEBFE  jne      0x6aec0d
0x006AEC00  push     0
0x006AEC02  push     0x735954
0x006AEC07  call     dword ptr [0x7152b0]
0x006AEC0D  mov      ecx, dword ptr [0x772400]
0x006AEC13  push     0x735970
0x006AEC18  lea      ecx, [ecx + 0xa05c]
0x006AEC1E  call     0x6be780
0x006AEC23  lea      eax, [ebp - 0x114]
0x006AEC29  push     0x104
0x006AEC2E  push     eax
0x006AEC2F  call     0x6df1b5
0x006AEC34  lea      ecx, [ebp - 0x114]
0x006AEC3A  add      esp, 8
0x006AEC3D  lea      edx, [ecx + 1]
0x006AEC40  mov      al, byte ptr [ecx]
0x006AEC42  inc      ecx
0x006AEC43  test     al, al
0x006AEC45  jne      0x6aec40
0x006AEC47  sub      ecx, edx
0x006AEC49  mov      edx, 0x7364b0
0x006AEC4E  mov      dword ptr [ebp - 0x148], ecx
0x006AEC54  push     0x19
0x006AEC56  lea      edi, [ecx + 1]
0x006AEC59  mov      ecx, 4
0x006AEC5E  cmp      edi, ecx
0x006AEC60  mov      esi, edi
0x006AEC62  cmovl    esi, ecx
0x006AEC65  add      esi, 0xb
0x006AEC68  and      esi, 0xfffffff0
0x006AEC6B  add      esi, ecx
0x006AEC6D  lea      ecx, [esi + 0xc]
0x006AEC70  call     0x6ba810
0x006AEC75  mov      dword ptr [ebp - 0x16c], eax
0x006AEC7B  mov      dword ptr [ebp - 0x160], eax
0x006AEC81  push     edi
0x006AEC82  lea      ecx, [eax + 0xc]
0x006AEC85  mov      dword ptr [eax + 4], esi
0x006AEC88  mov      dword ptr [eax + 8], 0xffffffff
0x006AEC8F  mov      dword ptr [eax], 0
0x006AEC95  lea      eax, [ebp - 0x114]
0x006AEC9B  push     eax
0x006AEC9C  push     ecx
0x006AEC9D  mov      byte ptr [ecx], 0
0x006AECA0  call     0x6d2250
0x006AECA5  mov      edi, dword ptr [ebp - 0x16c]
0x006AECAB  mov      eax, dword ptr [ebp - 0x148]
0x006AECB1  mov      dword ptr [edi + 8], eax
0x006AECB4  inc      dword ptr [edi]
0x006AECB6  add      esp, 0xc
0x006AECB9  mov      byte ptr [ebp - 4], 1
0x006AECBD  mov      esi, esp
0x006AECBF  mov      edx, 0x7364b0
0x006AECC4  mov      ecx, 0x20
0x006AECC9  push     0x19
0x006AECCB  call     0x6ba810
0x006AECD0  mov      edx, eax
0x006AECD2  add      esp, 4
0x006AECD5  .byte    0xc7
0x006AECD6  inc      edx


======== VA 0x006AEEC0 (file 0x2AE2C0) ========
0x006AEE48  shr      byte ptr [0x46c70077], 1
0x006AEE4E  and      al, 0
0x006AEE50  add      byte ptr [eax], al
0x006AEE52  add      bh, al
0x006AEE54  inc      esi
0x006AEE55  sub      byte ptr [eax], al
0x006AEE57  add      byte ptr [eax], al
0x006AEE59  add      byte ptr [ecx - 0x75], dl
0x006AEE5C  hlt      
0x006AEE5D  mov      edx, 0x7364b0
0x006AEE62  push     0x19
0x006AEE64  mov      ecx, 0x20
0x006AEE69  call     0x6ba810
0x006AEE6E  mov      edx, eax
0x006AEE70  add      esp, 4
0x006AEE73  mov      dword ptr [edx + 4], 0x14
0x006AEE7A  mov      dword ptr [edx + 8], 0xffffffff
0x006AEE81  mov      dword ptr [edx], 0
0x006AEE87  mov      byte ptr [edx + 0xc], 0
0x006AEE8B  mov      dword ptr [esi], edx
0x006AEE8D  movq     xmm0, qword ptr [0x7359b8]
0x006AEE95  movq     qword ptr [edx + 0xc], xmm0
0x006AEE9A  mov      cx, word ptr [0x7359c0]
0x006AEEA1  mov      word ptr [edx + 0x14], cx
0x006AEEA5  mov      al, byte ptr [0x7359c2]
0x006AEEAA  mov      byte ptr [edx + 0x16], al
0x006AEEAD  mov      eax, dword ptr [esi]
0x006AEEAF  mov      dword ptr [eax + 8], 0xa
0x006AEEB6  mov      eax, dword ptr [esi]
0x006AEEB8  test     eax, eax
0x006AEEBA  je       0x6aeebe
0x006AEEBC  inc      dword ptr [eax]
0x006AEEBE  mov      ecx, dword ptr [0x772400]
0x006AEEC4  lea      ecx, [ecx + 0xa05c]
0x006AEECA  call     0x6bfec0
0x006AEECF  mov      eax, dword ptr [eax]
0x006AEED1  mov      dword ptr [ebp - 0x158], eax
0x006AEED7  test     eax, eax
0x006AEED9  je       0x6aeedd
0x006AEEDB  inc      dword ptr [eax]
0x006AEEDD  mov      byte ptr [ebp - 4], 5
0x006AEEE1  mov      edx, dword ptr [eax + 8]
0x006AEEE4  mov      dword ptr [ebp - 0x15c], edx
0x006AEEEA  cmp      edx, -1
0x006AEEED  jne      0x6aef0b
0x006AEEEF  lea      edx, [eax + 0xc]
0x006AEEF2  mov      edi, edx
0x006AEEF4  lea      esi, [edx + 1]
0x006AEEF7  mov      cl, byte ptr [edx]
0x006AEEF9  inc      edx
0x006AEEFA  test     cl, cl
0x006AEEFC  jne      0x6aeef7
0x006AEEFE  sub      edx, esi
0x006AEF00  mov      dword ptr [ebp - 0x15c], edx
0x006AEF06  mov      dword ptr [eax + 8], edx
0x006AEF09  jmp      0x6aef0e
0x006AEF0B  lea      edi, [eax + 0xc]
0x006AEF0E  mov      esi, edx
0x006AEF10  mov      dword ptr [ebp - 0x150], esi
0x006AEF16  cmp      edx, -1
0x006AEF19  jne      0x6aef32
0x006AEF1B  mov      esi, edi
0x006AEF1D  lea      edx, [esi + 1]
0x006AEF20  mov      cl, byte ptr [esi]
0x006AEF22  inc      esi
0x006AEF23  test     cl, cl
0x006AEF25  jne      0x6aef20
0x006AEF27  sub      esi, edx
0x006AEF29  mov      dword ptr [ebp - 0x150], esi
0x006AEF2F  mov      dword ptr [eax + 8], esi
0x006AEF32  inc      esi
0x006AEF33  lea      ecx, [esi + 1]
0x006AEF36  push     ecx
0x006AEF37  push     eax
0x006AEF38  call     0x6b8df0
0x006AEF3D  mov      edi, eax
0x006AEF3F  mov      ecx, 0x20
0x006AEF44  mov      eax, dword ptr [ebp - 0x150]
0x006AEF4A  mov      dword ptr [ebp - 0x158], edi
0x006AEF50  mov      word ptr [eax + edi + 0xc], cx
0x006AEF55  mov      eax, dword ptr [ebp - 0x15c]
0x006AEF5B  mov      dword ptr [edi + 8], esi
0x006AEF5E  test     eax, eax
0x006AEF60  jle      0x6af0ab
0x006AEF66  xor      edx, edx
0x006AEF68  mov      ecx, dword ptr [edi + 8]
0x006AEF6B  mov      esi, edx
0x006AEF6D  cmp      ecx, -1
0x006AEF70  jne      0x6aef96
0x006AEF72  lea      ecx, [edi + 0xc]
0x006AEF75  lea      eax, [ecx + 1]
0x006AEF78  mov      dword ptr [ebp - 0x148], eax
0x006AEF7E  nop      
0x006AEF80  mov      al, byte ptr [ecx]
0x006AEF82  inc      ecx
0x006AEF83  test     al, al
0x006AEF85  jne      0x6aef80
0x006AEF87  .byte    0x2b


======== VA 0x006AF5B6 (file 0x2AE9B6) ========
0x006AF53E  mov      al, 0xfe
0x006AF540  .byte    0xff
0x006AF541  inc      edi
0x006AF543  test     dword ptr [eax - 2], esi
0x006AF549  .byte    0xff
0x006AF54A  .byte    0xff
0x006AF54B  jmp      ptr [edx + 1]
0x006AF54E  push     4
0x006AF550  push     eax
0x006AF551  call     0x6d9efa
0x006AF556  push     dword ptr [0xc3ca14]
0x006AF55C  call     0x6d4666
0x006AF561  mov      eax, dword ptr [ebp - 0x150]
0x006AF567  add      esp, 0x14
0x006AF56A  mov      dword ptr [0xc3ca14], 0
0x006AF574  cmp      eax, 3
0x006AF577  ja       0x6af608
0x006AF57D  jmp      dword ptr [eax*4 + 0x6b1aec]
0x006AF584  mov      eax, 0x721eb8
0x006AF589  jmp      0x6af59e
0x006AF58B  mov      eax, 0x735938
0x006AF590  jmp      0x6af59e
0x006AF592  mov      eax, 0x73593c
0x006AF597  jmp      0x6af59e
0x006AF599  mov      eax, 0x721eb4
0x006AF59E  push     eax
0x006AF59F  lea      ecx, [ebp - 0x16c]
0x006AF5A5  call     0x6b8fb0
0x006AF5AA  mov      dword ptr [ebp - 0x148], eax
0x006AF5B0  mov      byte ptr [ebp - 4], 0x12
0x006AF5B4  mov      esi, dword ptr [0x772400]
0x006AF5BA  mov      edx, dword ptr [eax]
0x006AF5BC  mov      ecx, dword ptr [esi + 0xc]
0x006AF5BF  mov      dword ptr [esi + 0xc], edx
0x006AF5C2  test     edx, edx
0x006AF5C4  je       0x6af5c8
0x006AF5C6  inc      dword ptr [edx]
0x006AF5C8  test     ecx, ecx
0x006AF5CA  je       0x6af5dc
0x006AF5CC  add      dword ptr [ecx], -1
0x006AF5CF  jne      0x6af5dc
0x006AF5D1  call     0x6ba940
0x006AF5D6  mov      eax, dword ptr [ebp - 0x148]
0x006AF5DC  mov      eax, dword ptr [eax]
0x006AF5DE  mov      ecx, dword ptr [esi + 0xc]
0x006AF5E1  mov      eax, dword ptr [eax + 8]
0x006AF5E4  mov      dword ptr [ecx + 8], eax
0x006AF5E7  mov      byte ptr [ebp - 4], 0x13
0x006AF5EB  mov      ecx, dword ptr [ebp - 0x16c]
0x006AF5F1  test     ecx, ecx
0x006AF5F3  je       0x6af5ff
0x006AF5F5  add      dword ptr [ecx], -1
0x006AF5F8  jne      0x6af5ff
0x006AF5FA  call     0x6ba940
0x006AF5FF  mov      byte ptr [ebp - 4], 0x11
0x006AF603  jmp      0x6af6cd
0x006AF608  mov      eax, dword ptr [0x71515c]
0x006AF60D  mov      ecx, dword ptr [eax]
0x006AF60F  test     ecx, ecx
0x006AF611  je       0x6af676
0x006AF613  mov      eax, dword ptr [ecx]
0x006AF615  mov      eax, dword ptr [eax + 0x54]
0x006AF618  call     eax
0x006AF61A  test     eax, eax
0x006AF61C  je       0x6af676
0x006AF61E  push     eax
0x006AF61F  lea      ecx, [ebp - 0x150]
0x006AF625  call     0x6b8fb0
0x006AF62A  mov      dword ptr [ebp - 0x148], eax
0x006AF630  mov      byte ptr [ebp - 4], 0x14
0x006AF634  mov      esi, dword ptr [0x772400]
0x006AF63A  mov      edx, dword ptr [eax]
0x006AF63C  mov      ecx, dword ptr [esi + 0xc]
0x006AF63F  mov      dword ptr [esi + 0xc], edx
0x006AF642  test     edx, edx
0x006AF644  je       0x6af648
0x006AF646  inc      dword ptr [edx]
0x006AF648  test     ecx, ecx
0x006AF64A  je       0x6af65c
0x006AF64C  add      dword ptr [ecx], -1
0x006AF64F  jne      0x6af65c
0x006AF651  call     0x6ba940
0x006AF656  mov      eax, dword ptr [ebp - 0x148]
0x006AF65C  mov      eax, dword ptr [eax]
0x006AF65E  mov      ecx, dword ptr [esi + 0xc]
0x006AF661  mov      eax, dword ptr [eax + 8]
0x006AF664  mov      dword ptr [ecx + 8], eax
0x006AF667  mov      byte ptr [ebp - 4], 0x15
0x006AF66B  mov      ecx, dword ptr [ebp - 0x150]
0x006AF671  jmp      0x6af5f1
0x006AF676  push     ecx
0x006AF677  mov      ecx, esp
0x006AF679  push     0x735a00


======== VA 0x006AF636 (file 0x2AEA36) ========
0x006AF5BE  or       al, 0x89
0x006AF5C0  push     esi
0x006AF5C1  or       al, 0x85
0x006AF5C3  sal      byte ptr [edx + eax - 1], cl
0x006AF5C7  add      al, byte ptr [ebp - 0x7cef8b37]
0x006AF5CD  add      edi, edi
0x006AF5CF  jne      0x6af5dc
0x006AF5D1  call     0x6ba940
0x006AF5D6  mov      eax, dword ptr [ebp - 0x148]
0x006AF5DC  mov      eax, dword ptr [eax]
0x006AF5DE  mov      ecx, dword ptr [esi + 0xc]
0x006AF5E1  mov      eax, dword ptr [eax + 8]
0x006AF5E4  mov      dword ptr [ecx + 8], eax
0x006AF5E7  mov      byte ptr [ebp - 4], 0x13
0x006AF5EB  mov      ecx, dword ptr [ebp - 0x16c]
0x006AF5F1  test     ecx, ecx
0x006AF5F3  je       0x6af5ff
0x006AF5F5  add      dword ptr [ecx], -1
0x006AF5F8  jne      0x6af5ff
0x006AF5FA  call     0x6ba940
0x006AF5FF  mov      byte ptr [ebp - 4], 0x11
0x006AF603  jmp      0x6af6cd
0x006AF608  mov      eax, dword ptr [0x71515c]
0x006AF60D  mov      ecx, dword ptr [eax]
0x006AF60F  test     ecx, ecx
0x006AF611  je       0x6af676
0x006AF613  mov      eax, dword ptr [ecx]
0x006AF615  mov      eax, dword ptr [eax + 0x54]
0x006AF618  call     eax
0x006AF61A  test     eax, eax
0x006AF61C  je       0x6af676
0x006AF61E  push     eax
0x006AF61F  lea      ecx, [ebp - 0x150]
0x006AF625  call     0x6b8fb0
0x006AF62A  mov      dword ptr [ebp - 0x148], eax
0x006AF630  mov      byte ptr [ebp - 4], 0x14
0x006AF634  mov      esi, dword ptr [0x772400]
0x006AF63A  mov      edx, dword ptr [eax]
0x006AF63C  mov      ecx, dword ptr [esi + 0xc]
0x006AF63F  mov      dword ptr [esi + 0xc], edx
0x006AF642  test     edx, edx
0x006AF644  je       0x6af648
0x006AF646  inc      dword ptr [edx]
0x006AF648  test     ecx, ecx
0x006AF64A  je       0x6af65c
0x006AF64C  add      dword ptr [ecx], -1
0x006AF64F  jne      0x6af65c
0x006AF651  call     0x6ba940
0x006AF656  mov      eax, dword ptr [ebp - 0x148]
0x006AF65C  mov      eax, dword ptr [eax]
0x006AF65E  mov      ecx, dword ptr [esi + 0xc]
0x006AF661  mov      eax, dword ptr [eax + 8]
0x006AF664  mov      dword ptr [ecx + 8], eax
0x006AF667  mov      byte ptr [ebp - 4], 0x15
0x006AF66B  mov      ecx, dword ptr [ebp - 0x150]
0x006AF671  jmp      0x6af5f1
0x006AF676  push     ecx
0x006AF677  mov      ecx, esp
0x006AF679  push     0x735a00
0x006AF67E  call     0x6b8fb0
0x006AF683  mov      ecx, dword ptr [0x772400]
0x006AF689  lea      ecx, [ecx + 0xa05c]
0x006AF68F  call     0x6bfec0
0x006AF694  mov      esi, dword ptr [0x772400]
0x006AF69A  mov      dword ptr [ebp - 0x148], eax
0x006AF6A0  mov      edx, dword ptr [eax]
0x006AF6A2  mov      ecx, dword ptr [esi + 0xc]
0x006AF6A5  mov      dword ptr [esi + 0xc], edx
0x006AF6A8  test     edx, edx
0x006AF6AA  je       0x6af6ae
0x006AF6AC  inc      dword ptr [edx]
0x006AF6AE  test     ecx, ecx
0x006AF6B0  je       0x6af6c2
0x006AF6B2  add      dword ptr [ecx], -1
0x006AF6B5  jne      0x6af6c2
0x006AF6B7  call     0x6ba940
0x006AF6BC  mov      eax, dword ptr [ebp - 0x148]
0x006AF6C2  mov      eax, dword ptr [eax]
0x006AF6C4  mov      ecx, dword ptr [esi + 0xc]
0x006AF6C7  mov      eax, dword ptr [eax + 8]
0x006AF6CA  mov      dword ptr [ecx + 8], eax
0x006AF6CD  mov      edx, dword ptr [0x772400]
0x006AF6D3  mov      esi, dword ptr [edx + 0xc]
0x006AF6D6  cmp      dword ptr [esi + 8], -1
0x006AF6DA  jne      0x6af701
0x006AF6DC  lea      ecx, [esi + 0xc]
0x006AF6DF  lea      eax, [ecx + 1]
0x006AF6E2  mov      dword ptr [ebp - 0x148], eax
0x006AF6E8  mov      al, byte ptr [ecx]
0x006AF6EA  inc      ecx
0x006AF6EB  test     al, al
0x006AF6ED  jne      0x6af6e8
0x006AF6EF  sub      ecx, dword ptr [ebp - 0x148]
0x006AF6F5  mov      dword ptr [esi + 8], ecx
0x006AF6F8  mov      esi, dword ptr [edx + 0xc]
0x006AF6FB  .byte    0x8b
0x006AF6FC  .byte    0x15
0x006AF6FD  .byte    0x00


======== VA 0x006AF685 (file 0x2AEA85) ========
0x006AF60D  mov      ecx, dword ptr [eax]
0x006AF60F  test     ecx, ecx
0x006AF611  je       0x6af676
0x006AF613  mov      eax, dword ptr [ecx]
0x006AF615  mov      eax, dword ptr [eax + 0x54]
0x006AF618  call     eax
0x006AF61A  test     eax, eax
0x006AF61C  je       0x6af676
0x006AF61E  push     eax
0x006AF61F  lea      ecx, [ebp - 0x150]
0x006AF625  call     0x6b8fb0
0x006AF62A  mov      dword ptr [ebp - 0x148], eax
0x006AF630  mov      byte ptr [ebp - 4], 0x14
0x006AF634  mov      esi, dword ptr [0x772400]
0x006AF63A  mov      edx, dword ptr [eax]
0x006AF63C  mov      ecx, dword ptr [esi + 0xc]
0x006AF63F  mov      dword ptr [esi + 0xc], edx
0x006AF642  test     edx, edx
0x006AF644  je       0x6af648
0x006AF646  inc      dword ptr [edx]
0x006AF648  test     ecx, ecx
0x006AF64A  je       0x6af65c
0x006AF64C  add      dword ptr [ecx], -1
0x006AF64F  jne      0x6af65c
0x006AF651  call     0x6ba940
0x006AF656  mov      eax, dword ptr [ebp - 0x148]
0x006AF65C  mov      eax, dword ptr [eax]
0x006AF65E  mov      ecx, dword ptr [esi + 0xc]
0x006AF661  mov      eax, dword ptr [eax + 8]
0x006AF664  mov      dword ptr [ecx + 8], eax
0x006AF667  mov      byte ptr [ebp - 4], 0x15
0x006AF66B  mov      ecx, dword ptr [ebp - 0x150]
0x006AF671  jmp      0x6af5f1
0x006AF676  push     ecx
0x006AF677  mov      ecx, esp
0x006AF679  push     0x735a00
0x006AF67E  call     0x6b8fb0
0x006AF683  mov      ecx, dword ptr [0x772400]
0x006AF689  lea      ecx, [ecx + 0xa05c]
0x006AF68F  call     0x6bfec0
0x006AF694  mov      esi, dword ptr [0x772400]
0x006AF69A  mov      dword ptr [ebp - 0x148], eax
0x006AF6A0  mov      edx, dword ptr [eax]
0x006AF6A2  mov      ecx, dword ptr [esi + 0xc]
0x006AF6A5  mov      dword ptr [esi + 0xc], edx
0x006AF6A8  test     edx, edx
0x006AF6AA  je       0x6af6ae
0x006AF6AC  inc      dword ptr [edx]
0x006AF6AE  test     ecx, ecx
0x006AF6B0  je       0x6af6c2
0x006AF6B2  add      dword ptr [ecx], -1
0x006AF6B5  jne      0x6af6c2
0x006AF6B7  call     0x6ba940
0x006AF6BC  mov      eax, dword ptr [ebp - 0x148]
0x006AF6C2  mov      eax, dword ptr [eax]
0x006AF6C4  mov      ecx, dword ptr [esi + 0xc]
0x006AF6C7  mov      eax, dword ptr [eax + 8]
0x006AF6CA  mov      dword ptr [ecx + 8], eax
0x006AF6CD  mov      edx, dword ptr [0x772400]
0x006AF6D3  mov      esi, dword ptr [edx + 0xc]
0x006AF6D6  cmp      dword ptr [esi + 8], -1
0x006AF6DA  jne      0x6af701
0x006AF6DC  lea      ecx, [esi + 0xc]
0x006AF6DF  lea      eax, [ecx + 1]
0x006AF6E2  mov      dword ptr [ebp - 0x148], eax
0x006AF6E8  mov      al, byte ptr [ecx]
0x006AF6EA  inc      ecx
0x006AF6EB  test     al, al
0x006AF6ED  jne      0x6af6e8
0x006AF6EF  sub      ecx, dword ptr [ebp - 0x148]
0x006AF6F5  mov      dword ptr [esi + 8], ecx
0x006AF6F8  mov      esi, dword ptr [edx + 0xc]
0x006AF6FB  mov      edx, dword ptr [0x772400]
0x006AF701  cmp      dword ptr [esi + 8], 0
0x006AF705  jne      0x6af71a
0x006AF707  push     0x721eb8
0x006AF70C  lea      ecx, [edx + 0xc]
0x006AF70F  call     0x6b9200
0x006AF714  mov      edx, dword ptr [0x772400]
0x006AF71A  mov      eax, dword ptr [edx + 0xc]
0x006AF71D  lea      ecx, [ebp - 0x15c]
0x006AF723  add      eax, 0xc
0x006AF726  push     eax
0x006AF727  call     0x6b8fb0
0x006AF72C  push     ecx
0x006AF72D  mov      esi, esp
0x006AF72F  mov      byte ptr [ebp - 4], 0x16
0x006AF733  push     0x19
0x006AF735  mov      edx, 0x7364b0
0x006AF73A  mov      ecx, 0x20
0x006AF73F  call     0x6ba810
0x006AF744  add      esp, 4
0x006AF747  .byte    0xc7
0x006AF748  inc      eax
0x006AF749  add      al, 0x14
0x006AF74B  add      byte ptr [eax], al


======== VA 0x006AF696 (file 0x2AEA96) ========
0x006AF61E  push     eax
0x006AF61F  lea      ecx, [ebp - 0x150]
0x006AF625  call     0x6b8fb0
0x006AF62A  mov      dword ptr [ebp - 0x148], eax
0x006AF630  mov      byte ptr [ebp - 4], 0x14
0x006AF634  mov      esi, dword ptr [0x772400]
0x006AF63A  mov      edx, dword ptr [eax]
0x006AF63C  mov      ecx, dword ptr [esi + 0xc]
0x006AF63F  mov      dword ptr [esi + 0xc], edx
0x006AF642  test     edx, edx
0x006AF644  je       0x6af648
0x006AF646  inc      dword ptr [edx]
0x006AF648  test     ecx, ecx
0x006AF64A  je       0x6af65c
0x006AF64C  add      dword ptr [ecx], -1
0x006AF64F  jne      0x6af65c
0x006AF651  call     0x6ba940
0x006AF656  mov      eax, dword ptr [ebp - 0x148]
0x006AF65C  mov      eax, dword ptr [eax]
0x006AF65E  mov      ecx, dword ptr [esi + 0xc]
0x006AF661  mov      eax, dword ptr [eax + 8]
0x006AF664  mov      dword ptr [ecx + 8], eax
0x006AF667  mov      byte ptr [ebp - 4], 0x15
0x006AF66B  mov      ecx, dword ptr [ebp - 0x150]
0x006AF671  jmp      0x6af5f1
0x006AF676  push     ecx
0x006AF677  mov      ecx, esp
0x006AF679  push     0x735a00
0x006AF67E  call     0x6b8fb0
0x006AF683  mov      ecx, dword ptr [0x772400]
0x006AF689  lea      ecx, [ecx + 0xa05c]
0x006AF68F  call     0x6bfec0
0x006AF694  mov      esi, dword ptr [0x772400]
0x006AF69A  mov      dword ptr [ebp - 0x148], eax
0x006AF6A0  mov      edx, dword ptr [eax]
0x006AF6A2  mov      ecx, dword ptr [esi + 0xc]
0x006AF6A5  mov      dword ptr [esi + 0xc], edx
0x006AF6A8  test     edx, edx
0x006AF6AA  je       0x6af6ae
0x006AF6AC  inc      dword ptr [edx]
0x006AF6AE  test     ecx, ecx
0x006AF6B0  je       0x6af6c2
0x006AF6B2  add      dword ptr [ecx], -1
0x006AF6B5  jne      0x6af6c2
0x006AF6B7  call     0x6ba940
0x006AF6BC  mov      eax, dword ptr [ebp - 0x148]
0x006AF6C2  mov      eax, dword ptr [eax]
0x006AF6C4  mov      ecx, dword ptr [esi + 0xc]
0x006AF6C7  mov      eax, dword ptr [eax + 8]
0x006AF6CA  mov      dword ptr [ecx + 8], eax
0x006AF6CD  mov      edx, dword ptr [0x772400]
0x006AF6D3  mov      esi, dword ptr [edx + 0xc]
0x006AF6D6  cmp      dword ptr [esi + 8], -1
0x006AF6DA  jne      0x6af701
0x006AF6DC  lea      ecx, [esi + 0xc]
0x006AF6DF  lea      eax, [ecx + 1]
0x006AF6E2  mov      dword ptr [ebp - 0x148], eax
0x006AF6E8  mov      al, byte ptr [ecx]
0x006AF6EA  inc      ecx
0x006AF6EB  test     al, al
0x006AF6ED  jne      0x6af6e8
0x006AF6EF  sub      ecx, dword ptr [ebp - 0x148]
0x006AF6F5  mov      dword ptr [esi + 8], ecx
0x006AF6F8  mov      esi, dword ptr [edx + 0xc]
0x006AF6FB  mov      edx, dword ptr [0x772400]
0x006AF701  cmp      dword ptr [esi + 8], 0
0x006AF705  jne      0x6af71a
0x006AF707  push     0x721eb8
0x006AF70C  lea      ecx, [edx + 0xc]
0x006AF70F  call     0x6b9200
0x006AF714  mov      edx, dword ptr [0x772400]
0x006AF71A  mov      eax, dword ptr [edx + 0xc]
0x006AF71D  lea      ecx, [ebp - 0x15c]
0x006AF723  add      eax, 0xc
0x006AF726  push     eax
0x006AF727  call     0x6b8fb0
0x006AF72C  push     ecx
0x006AF72D  mov      esi, esp
0x006AF72F  mov      byte ptr [ebp - 4], 0x16
0x006AF733  push     0x19
0x006AF735  mov      edx, 0x7364b0
0x006AF73A  mov      ecx, 0x20
0x006AF73F  call     0x6ba810
0x006AF744  add      esp, 4
0x006AF747  mov      dword ptr [eax + 4], 0x14
0x006AF74E  mov      dword ptr [eax + 8], 0xffffffff
0x006AF755  mov      dword ptr [eax], 0
0x006AF75B  .byte    0xc6
0x006AF75C  inc      eax
0x006AF75D  .byte    0x0c


======== VA 0x006AF6CF (file 0x2AEACF) ========
0x006AF657  test     dword ptr [eax - 0x74000002], edi
0x006AF65D  add      byte ptr [ebx + 0x408b0c4e], cl
0x006AF663  or       byte ptr [ecx + 0x45c60841], cl
0x006AF669  cld      
0x006AF66A  adc      eax, 0xfeb08d8b
0x006AF66F  .byte    0xff
0x006AF670  .byte    0xff
0x006AF671  jmp      0x6af5f1
0x006AF676  push     ecx
0x006AF677  mov      ecx, esp
0x006AF679  push     0x735a00
0x006AF67E  call     0x6b8fb0
0x006AF683  mov      ecx, dword ptr [0x772400]
0x006AF689  lea      ecx, [ecx + 0xa05c]
0x006AF68F  call     0x6bfec0
0x006AF694  mov      esi, dword ptr [0x772400]
0x006AF69A  mov      dword ptr [ebp - 0x148], eax
0x006AF6A0  mov      edx, dword ptr [eax]
0x006AF6A2  mov      ecx, dword ptr [esi + 0xc]
0x006AF6A5  mov      dword ptr [esi + 0xc], edx
0x006AF6A8  test     edx, edx
0x006AF6AA  je       0x6af6ae
0x006AF6AC  inc      dword ptr [edx]
0x006AF6AE  test     ecx, ecx
0x006AF6B0  je       0x6af6c2
0x006AF6B2  add      dword ptr [ecx], -1
0x006AF6B5  jne      0x6af6c2
0x006AF6B7  call     0x6ba940
0x006AF6BC  mov      eax, dword ptr [ebp - 0x148]
0x006AF6C2  mov      eax, dword ptr [eax]
0x006AF6C4  mov      ecx, dword ptr [esi + 0xc]
0x006AF6C7  mov      eax, dword ptr [eax + 8]
0x006AF6CA  mov      dword ptr [ecx + 8], eax
0x006AF6CD  mov      edx, dword ptr [0x772400]
0x006AF6D3  mov      esi, dword ptr [edx + 0xc]
0x006AF6D6  cmp      dword ptr [esi + 8], -1
0x006AF6DA  jne      0x6af701
0x006AF6DC  lea      ecx, [esi + 0xc]
0x006AF6DF  lea      eax, [ecx + 1]
0x006AF6E2  mov      dword ptr [ebp - 0x148], eax
0x006AF6E8  mov      al, byte ptr [ecx]
0x006AF6EA  inc      ecx
0x006AF6EB  test     al, al
0x006AF6ED  jne      0x6af6e8
0x006AF6EF  sub      ecx, dword ptr [ebp - 0x148]
0x006AF6F5  mov      dword ptr [esi + 8], ecx
0x006AF6F8  mov      esi, dword ptr [edx + 0xc]
0x006AF6FB  mov      edx, dword ptr [0x772400]
0x006AF701  cmp      dword ptr [esi + 8], 0
0x006AF705  jne      0x6af71a
0x006AF707  push     0x721eb8
0x006AF70C  lea      ecx, [edx + 0xc]
0x006AF70F  call     0x6b9200
0x006AF714  mov      edx, dword ptr [0x772400]
0x006AF71A  mov      eax, dword ptr [edx + 0xc]
0x006AF71D  lea      ecx, [ebp - 0x15c]
0x006AF723  add      eax, 0xc
0x006AF726  push     eax
0x006AF727  call     0x6b8fb0
0x006AF72C  push     ecx
0x006AF72D  mov      esi, esp
0x006AF72F  mov      byte ptr [ebp - 4], 0x16
0x006AF733  push     0x19
0x006AF735  mov      edx, 0x7364b0
0x006AF73A  mov      ecx, 0x20
0x006AF73F  call     0x6ba810
0x006AF744  add      esp, 4
0x006AF747  mov      dword ptr [eax + 4], 0x14
0x006AF74E  mov      dword ptr [eax + 8], 0xffffffff
0x006AF755  mov      dword ptr [eax], 0
0x006AF75B  mov      byte ptr [eax + 0xc], 0
0x006AF75F  mov      dword ptr [esi], eax
0x006AF761  movq     xmm0, qword ptr [0x735a00]
0x006AF769  movq     qword ptr [eax + 0xc], xmm0
0x006AF76E  mov      cl, byte ptr [0x735a08]
0x006AF774  mov      byte ptr [eax + 0x14], cl
0x006AF777  mov      eax, dword ptr [esi]
0x006AF779  mov      dword ptr [eax + 8], 8
0x006AF780  mov      eax, dword ptr [esi]
0x006AF782  test     eax, eax
0x006AF784  je       0x6af788
0x006AF786  inc      dword ptr [eax]
0x006AF788  mov      ecx, dword ptr [0x772400]
0x006AF78E  lea      ecx, [ecx + 0xa05c]
0x006AF794  .byte    0xe8
0x006AF795  .byte    0x67
0x006AF796  .byte    0x04


======== VA 0x006AF6FD (file 0x2AEAFD) ========
0x006AF685  add      byte ptr [edi + esi*2], ah
0x006AF688  add      byte ptr [ebp + 0xa05c89], cl
0x006AF68E  add      al, ch
0x006AF690  sub      al, 8
0x006AF692  add      dword ptr [eax], eax
0x006AF694  mov      esi, dword ptr [0x772400]
0x006AF69A  mov      dword ptr [ebp - 0x148], eax
0x006AF6A0  mov      edx, dword ptr [eax]
0x006AF6A2  mov      ecx, dword ptr [esi + 0xc]
0x006AF6A5  mov      dword ptr [esi + 0xc], edx
0x006AF6A8  test     edx, edx
0x006AF6AA  je       0x6af6ae
0x006AF6AC  inc      dword ptr [edx]
0x006AF6AE  test     ecx, ecx
0x006AF6B0  je       0x6af6c2
0x006AF6B2  add      dword ptr [ecx], -1
0x006AF6B5  jne      0x6af6c2
0x006AF6B7  call     0x6ba940
0x006AF6BC  mov      eax, dword ptr [ebp - 0x148]
0x006AF6C2  mov      eax, dword ptr [eax]
0x006AF6C4  mov      ecx, dword ptr [esi + 0xc]
0x006AF6C7  mov      eax, dword ptr [eax + 8]
0x006AF6CA  mov      dword ptr [ecx + 8], eax
0x006AF6CD  mov      edx, dword ptr [0x772400]
0x006AF6D3  mov      esi, dword ptr [edx + 0xc]
0x006AF6D6  cmp      dword ptr [esi + 8], -1
0x006AF6DA  jne      0x6af701
0x006AF6DC  lea      ecx, [esi + 0xc]
0x006AF6DF  lea      eax, [ecx + 1]
0x006AF6E2  mov      dword ptr [ebp - 0x148], eax
0x006AF6E8  mov      al, byte ptr [ecx]
0x006AF6EA  inc      ecx
0x006AF6EB  test     al, al
0x006AF6ED  jne      0x6af6e8
0x006AF6EF  sub      ecx, dword ptr [ebp - 0x148]
0x006AF6F5  mov      dword ptr [esi + 8], ecx
0x006AF6F8  mov      esi, dword ptr [edx + 0xc]
0x006AF6FB  mov      edx, dword ptr [0x772400]
0x006AF701  cmp      dword ptr [esi + 8], 0
0x006AF705  jne      0x6af71a
0x006AF707  push     0x721eb8
0x006AF70C  lea      ecx, [edx + 0xc]
0x006AF70F  call     0x6b9200
0x006AF714  mov      edx, dword ptr [0x772400]
0x006AF71A  mov      eax, dword ptr [edx + 0xc]
0x006AF71D  lea      ecx, [ebp - 0x15c]
0x006AF723  add      eax, 0xc
0x006AF726  push     eax
0x006AF727  call     0x6b8fb0
0x006AF72C  push     ecx
0x006AF72D  mov      esi, esp
0x006AF72F  mov      byte ptr [ebp - 4], 0x16
0x006AF733  push     0x19
0x006AF735  mov      edx, 0x7364b0
0x006AF73A  mov      ecx, 0x20
0x006AF73F  call     0x6ba810
0x006AF744  add      esp, 4
0x006AF747  mov      dword ptr [eax + 4], 0x14
0x006AF74E  mov      dword ptr [eax + 8], 0xffffffff
0x006AF755  mov      dword ptr [eax], 0
0x006AF75B  mov      byte ptr [eax + 0xc], 0
0x006AF75F  mov      dword ptr [esi], eax
0x006AF761  movq     xmm0, qword ptr [0x735a00]
0x006AF769  movq     qword ptr [eax + 0xc], xmm0
0x006AF76E  mov      cl, byte ptr [0x735a08]
0x006AF774  mov      byte ptr [eax + 0x14], cl
0x006AF777  mov      eax, dword ptr [esi]
0x006AF779  mov      dword ptr [eax + 8], 8
0x006AF780  mov      eax, dword ptr [esi]
0x006AF782  test     eax, eax
0x006AF784  je       0x6af788
0x006AF786  inc      dword ptr [eax]
0x006AF788  mov      ecx, dword ptr [0x772400]
0x006AF78E  lea      ecx, [ecx + 0xa05c]
0x006AF794  call     0x6bfc00
0x006AF799  mov      esi, eax
0x006AF79B  mov      byte ptr [ebp - 4], 0x17
0x006AF79F  mov      ecx, dword ptr [ebp - 0x15c]
0x006AF7A5  mov      edx, dword ptr [esi + 0xc]
0x006AF7A8  mov      dword ptr [esi + 0xc], ecx
0x006AF7AB  mov      ecx, dword ptr [ebp - 0x15c]
0x006AF7B1  test     ecx, ecx
0x006AF7B3  je       0x6af7bd
0x006AF7B5  inc      dword ptr [ecx]
0x006AF7B7  mov      ecx, dword ptr [ebp - 0x15c]
0x006AF7BD  test     edx, edx
0x006AF7BF  je       0x6af7d3
0x006AF7C1  add      dword ptr [edx], -1
0x006AF7C4  .byte    0x75


======== VA 0x006AF716 (file 0x2AEB16) ========
0x006AF69E  .byte    0xff
0x006AF69F  dec      dword ptr [ebx + 0xc4e8b10]
0x006AF6A5  mov      dword ptr [esi + 0xc], edx
0x006AF6A8  test     edx, edx
0x006AF6AA  je       0x6af6ae
0x006AF6AC  inc      dword ptr [edx]
0x006AF6AE  test     ecx, ecx
0x006AF6B0  je       0x6af6c2
0x006AF6B2  add      dword ptr [ecx], -1
0x006AF6B5  jne      0x6af6c2
0x006AF6B7  call     0x6ba940
0x006AF6BC  mov      eax, dword ptr [ebp - 0x148]
0x006AF6C2  mov      eax, dword ptr [eax]
0x006AF6C4  mov      ecx, dword ptr [esi + 0xc]
0x006AF6C7  mov      eax, dword ptr [eax + 8]
0x006AF6CA  mov      dword ptr [ecx + 8], eax
0x006AF6CD  mov      edx, dword ptr [0x772400]
0x006AF6D3  mov      esi, dword ptr [edx + 0xc]
0x006AF6D6  cmp      dword ptr [esi + 8], -1
0x006AF6DA  jne      0x6af701
0x006AF6DC  lea      ecx, [esi + 0xc]
0x006AF6DF  lea      eax, [ecx + 1]
0x006AF6E2  mov      dword ptr [ebp - 0x148], eax
0x006AF6E8  mov      al, byte ptr [ecx]
0x006AF6EA  inc      ecx
0x006AF6EB  test     al, al
0x006AF6ED  jne      0x6af6e8
0x006AF6EF  sub      ecx, dword ptr [ebp - 0x148]
0x006AF6F5  mov      dword ptr [esi + 8], ecx
0x006AF6F8  mov      esi, dword ptr [edx + 0xc]
0x006AF6FB  mov      edx, dword ptr [0x772400]
0x006AF701  cmp      dword ptr [esi + 8], 0
0x006AF705  jne      0x6af71a
0x006AF707  push     0x721eb8
0x006AF70C  lea      ecx, [edx + 0xc]
0x006AF70F  call     0x6b9200
0x006AF714  mov      edx, dword ptr [0x772400]
0x006AF71A  mov      eax, dword ptr [edx + 0xc]
0x006AF71D  lea      ecx, [ebp - 0x15c]
0x006AF723  add      eax, 0xc
0x006AF726  push     eax
0x006AF727  call     0x6b8fb0
0x006AF72C  push     ecx
0x006AF72D  mov      esi, esp
0x006AF72F  mov      byte ptr [ebp - 4], 0x16
0x006AF733  push     0x19
0x006AF735  mov      edx, 0x7364b0
0x006AF73A  mov      ecx, 0x20
0x006AF73F  call     0x6ba810
0x006AF744  add      esp, 4
0x006AF747  mov      dword ptr [eax + 4], 0x14
0x006AF74E  mov      dword ptr [eax + 8], 0xffffffff
0x006AF755  mov      dword ptr [eax], 0
0x006AF75B  mov      byte ptr [eax + 0xc], 0
0x006AF75F  mov      dword ptr [esi], eax
0x006AF761  movq     xmm0, qword ptr [0x735a00]
0x006AF769  movq     qword ptr [eax + 0xc], xmm0
0x006AF76E  mov      cl, byte ptr [0x735a08]
0x006AF774  mov      byte ptr [eax + 0x14], cl
0x006AF777  mov      eax, dword ptr [esi]
0x006AF779  mov      dword ptr [eax + 8], 8
0x006AF780  mov      eax, dword ptr [esi]
0x006AF782  test     eax, eax
0x006AF784  je       0x6af788
0x006AF786  inc      dword ptr [eax]
0x006AF788  mov      ecx, dword ptr [0x772400]
0x006AF78E  lea      ecx, [ecx + 0xa05c]
0x006AF794  call     0x6bfc00
0x006AF799  mov      esi, eax
0x006AF79B  mov      byte ptr [ebp - 4], 0x17
0x006AF79F  mov      ecx, dword ptr [ebp - 0x15c]
0x006AF7A5  mov      edx, dword ptr [esi + 0xc]
0x006AF7A8  mov      dword ptr [esi + 0xc], ecx
0x006AF7AB  mov      ecx, dword ptr [ebp - 0x15c]
0x006AF7B1  test     ecx, ecx
0x006AF7B3  je       0x6af7bd
0x006AF7B5  inc      dword ptr [ecx]
0x006AF7B7  mov      ecx, dword ptr [ebp - 0x15c]
0x006AF7BD  test     edx, edx
0x006AF7BF  je       0x6af7d3
0x006AF7C1  add      dword ptr [edx], -1
0x006AF7C4  jne      0x6af7cd
0x006AF7C6  mov      ecx, edx
0x006AF7C8  call     0x6ba940
0x006AF7CD  mov      ecx, dword ptr [ebp - 0x15c]
0x006AF7D3  mov      edx, dword ptr [esi + 0xc]
0x006AF7D6  mov      eax, dword ptr [ecx + 8]
0x006AF7D9  mov      dword ptr [edx + 8], eax
0x006AF7DC  .byte    0xc6
0x006AF7DD  inc      ebp


======== VA 0x006AF931 (file 0x2AED31) ========
0x006AF8B9  add      byte ptr [eax], al
0x006AF8BB  mov      ecx, dword ptr [0x772400]
0x006AF8C1  lea      ecx, [ecx + 0xa05c]
0x006AF8C7  call     0x6bfc00
0x006AF8CC  movsd    xmm2, qword ptr [ebp - 0x188]
0x006AF8D4  mov      ecx, eax
0x006AF8D6  mov      byte ptr [ebp - 4], 0x11
0x006AF8DA  call     0x6bee00
0x006AF8DF  movsd    xmm1, qword ptr [ebp - 0x198]
0x006AF8E7  ucomisd  xmm1, xmm0
0x006AF8EB  lahf     
0x006AF8EC  test     ah, 0x44
0x006AF8EF  jnp      0x6af8f5
0x006AF8F1  mov      cl, 1
0x006AF8F3  jmp      0x6af8f7
0x006AF8F5  xor      cl, cl
0x006AF8F7  mov      eax, dword ptr [0x772400]
0x006AF8FC  mov      byte ptr [eax + 0x599], cl
0x006AF902  cmp      byte ptr [eax + 0x59a], 0
0x006AF909  je       0x6af976
0x006AF90B  push     ecx
0x006AF90C  mov      ecx, esp
0x006AF90E  mov      dword ptr [ebp - 0x14c], esp
0x006AF914  push     0x735a24
0x006AF919  call     0x6b8fb0
0x006AF91E  push     ecx
0x006AF91F  mov      ecx, esp
0x006AF921  mov      byte ptr [ebp - 4], 0x1a
0x006AF925  push     0x729590
0x006AF92A  call     0x6b8fb0
0x006AF92F  mov      ecx, dword ptr [0x772400]
0x006AF935  lea      ecx, [ecx + 0xa05c]
0x006AF93B  call     0x6bfc00
0x006AF940  movsd    xmm2, qword ptr [ebp - 0x188]
0x006AF948  mov      ecx, eax
0x006AF94A  mov      byte ptr [ebp - 4], 0x11
0x006AF94E  call     0x6bee00
0x006AF953  movsd    xmm1, qword ptr [ebp - 0x198]
0x006AF95B  ucomisd  xmm1, xmm0
0x006AF95F  lahf     
0x006AF960  test     ah, 0x44
0x006AF963  jnp      0x6af969
0x006AF965  mov      cl, 1
0x006AF967  jmp      0x6af96b
0x006AF969  xor      cl, cl
0x006AF96B  mov      eax, dword ptr [0x772400]
0x006AF970  mov      byte ptr [eax + 0x59a], cl
0x006AF976  movsd    xmm0, qword ptr [0x737500]
0x006AF97E  push     ecx
0x006AF97F  mov      ecx, esp
0x006AF981  mov      dword ptr [ebp - 0x14c], esp
0x006AF987  push     0x729598
0x006AF98C  movsd    qword ptr [ebp - 0x1a8], xmm0
0x006AF994  call     0x6b8fb0
0x006AF999  push     ecx
0x006AF99A  mov      ecx, esp
0x006AF99C  mov      byte ptr [ebp - 4], 0x1b
0x006AF9A0  push     0x729590
0x006AF9A5  call     0x6b8fb0
0x006AF9AA  mov      ecx, dword ptr [0x772400]
0x006AF9B0  lea      ecx, [ecx + 0xa05c]
0x006AF9B6  call     0x6bfc00
0x006AF9BB  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006AF9C3  mov      ecx, eax
0x006AF9C5  mov      byte ptr [ebp - 4], 0x11
0x006AF9C9  call     0x6bee00
0x006AF9CE  cvtsd2ss xmm0, xmm0
0x006AF9D2  movss    dword ptr [ebp - 0x148], xmm0
0x006AF9DA  fld      dword ptr [ebp - 0x148]
0x006AF9E0  lea      edx, [0x772dd8]
0x006AF9E6  fistp    dword ptr [edx]
0x006AF9E8  mov      ecx, dword ptr [0x772400]
0x006AF9EE  mov      eax, dword ptr [0x772dd8]
0x006AF9F3  .byte    0xf2
0x006AF9F4  .byte    0x0f
0x006AF9F5  .byte    0x10
0x006AF9F6  .byte    0x05
0x006AF9F7  mov      al, 0x74


======== VA 0x006AF96C (file 0x2AED6C) ========
0x006AF8F4  add      dh, byte ptr [edx]
0x006AF8F6  leave    
0x006AF8F7  mov      eax, dword ptr [0x772400]
0x006AF8FC  mov      byte ptr [eax + 0x599], cl
0x006AF902  cmp      byte ptr [eax + 0x59a], 0
0x006AF909  je       0x6af976
0x006AF90B  push     ecx
0x006AF90C  mov      ecx, esp
0x006AF90E  mov      dword ptr [ebp - 0x14c], esp
0x006AF914  push     0x735a24
0x006AF919  call     0x6b8fb0
0x006AF91E  push     ecx
0x006AF91F  mov      ecx, esp
0x006AF921  mov      byte ptr [ebp - 4], 0x1a
0x006AF925  push     0x729590
0x006AF92A  call     0x6b8fb0
0x006AF92F  mov      ecx, dword ptr [0x772400]
0x006AF935  lea      ecx, [ecx + 0xa05c]
0x006AF93B  call     0x6bfc00
0x006AF940  movsd    xmm2, qword ptr [ebp - 0x188]
0x006AF948  mov      ecx, eax
0x006AF94A  mov      byte ptr [ebp - 4], 0x11
0x006AF94E  call     0x6bee00
0x006AF953  movsd    xmm1, qword ptr [ebp - 0x198]
0x006AF95B  ucomisd  xmm1, xmm0
0x006AF95F  lahf     
0x006AF960  test     ah, 0x44
0x006AF963  jnp      0x6af969
0x006AF965  mov      cl, 1
0x006AF967  jmp      0x6af96b
0x006AF969  xor      cl, cl
0x006AF96B  mov      eax, dword ptr [0x772400]
0x006AF970  mov      byte ptr [eax + 0x59a], cl
0x006AF976  movsd    xmm0, qword ptr [0x737500]
0x006AF97E  push     ecx
0x006AF97F  mov      ecx, esp
0x006AF981  mov      dword ptr [ebp - 0x14c], esp
0x006AF987  push     0x729598
0x006AF98C  movsd    qword ptr [ebp - 0x1a8], xmm0
0x006AF994  call     0x6b8fb0
0x006AF999  push     ecx
0x006AF99A  mov      ecx, esp
0x006AF99C  mov      byte ptr [ebp - 4], 0x1b
0x006AF9A0  push     0x729590
0x006AF9A5  call     0x6b8fb0
0x006AF9AA  mov      ecx, dword ptr [0x772400]
0x006AF9B0  lea      ecx, [ecx + 0xa05c]
0x006AF9B6  call     0x6bfc00
0x006AF9BB  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006AF9C3  mov      ecx, eax
0x006AF9C5  mov      byte ptr [ebp - 4], 0x11
0x006AF9C9  call     0x6bee00
0x006AF9CE  cvtsd2ss xmm0, xmm0
0x006AF9D2  movss    dword ptr [ebp - 0x148], xmm0
0x006AF9DA  fld      dword ptr [ebp - 0x148]
0x006AF9E0  lea      edx, [0x772dd8]
0x006AF9E6  fistp    dword ptr [edx]
0x006AF9E8  mov      ecx, dword ptr [0x772400]
0x006AF9EE  mov      eax, dword ptr [0x772dd8]
0x006AF9F3  movsd    xmm0, qword ptr [0x7374b0]
0x006AF9FB  movsd    qword ptr [ebp - 0x170], xmm0
0x006AFA03  mov      dword ptr [ecx + 0x5bc], eax
0x006AFA09  lea      eax, [ebp - 0x165]
0x006AFA0F  push     eax
0x006AFA10  push     ecx
0x006AFA11  mov      ecx, esp
0x006AFA13  mov      dword ptr [ebp - 0x14c], esp
0x006AFA19  push     0x735a34
0x006AFA1E  call     0x6b8fb0
0x006AFA23  push     ecx
0x006AFA24  mov      ecx, esp
0x006AFA26  mov      byte ptr [ebp - 4], 0x1c
0x006AFA2A  push     0x735a2c
0x006AFA2F  call     0x6b8fb0


======== VA 0x006AF9AC (file 0x2AEDAC) ========
0x006AF934  add      byte ptr [ebp + 0xa05c89], cl
0x006AF93A  add      al, ch
0x006AF93C  rol      byte ptr [edx], 1
0x006AF93F  add      dl, dh
0x006AF941  movups   xmm2, xmmword ptr [ebp - 0x188]
0x006AF948  mov      ecx, eax
0x006AF94A  mov      byte ptr [ebp - 4], 0x11
0x006AF94E  call     0x6bee00
0x006AF953  movsd    xmm1, qword ptr [ebp - 0x198]
0x006AF95B  ucomisd  xmm1, xmm0
0x006AF95F  lahf     
0x006AF960  test     ah, 0x44
0x006AF963  jnp      0x6af969
0x006AF965  mov      cl, 1
0x006AF967  jmp      0x6af96b
0x006AF969  xor      cl, cl
0x006AF96B  mov      eax, dword ptr [0x772400]
0x006AF970  mov      byte ptr [eax + 0x59a], cl
0x006AF976  movsd    xmm0, qword ptr [0x737500]
0x006AF97E  push     ecx
0x006AF97F  mov      ecx, esp
0x006AF981  mov      dword ptr [ebp - 0x14c], esp
0x006AF987  push     0x729598
0x006AF98C  movsd    qword ptr [ebp - 0x1a8], xmm0
0x006AF994  call     0x6b8fb0
0x006AF999  push     ecx
0x006AF99A  mov      ecx, esp
0x006AF99C  mov      byte ptr [ebp - 4], 0x1b
0x006AF9A0  push     0x729590
0x006AF9A5  call     0x6b8fb0
0x006AF9AA  mov      ecx, dword ptr [0x772400]
0x006AF9B0  lea      ecx, [ecx + 0xa05c]
0x006AF9B6  call     0x6bfc00
0x006AF9BB  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006AF9C3  mov      ecx, eax
0x006AF9C5  mov      byte ptr [ebp - 4], 0x11
0x006AF9C9  call     0x6bee00
0x006AF9CE  cvtsd2ss xmm0, xmm0
0x006AF9D2  movss    dword ptr [ebp - 0x148], xmm0
0x006AF9DA  fld      dword ptr [ebp - 0x148]
0x006AF9E0  lea      edx, [0x772dd8]
0x006AF9E6  fistp    dword ptr [edx]
0x006AF9E8  mov      ecx, dword ptr [0x772400]
0x006AF9EE  mov      eax, dword ptr [0x772dd8]
0x006AF9F3  movsd    xmm0, qword ptr [0x7374b0]
0x006AF9FB  movsd    qword ptr [ebp - 0x170], xmm0
0x006AFA03  mov      dword ptr [ecx + 0x5bc], eax
0x006AFA09  lea      eax, [ebp - 0x165]
0x006AFA0F  push     eax
0x006AFA10  push     ecx
0x006AFA11  mov      ecx, esp
0x006AFA13  mov      dword ptr [ebp - 0x14c], esp
0x006AFA19  push     0x735a34
0x006AFA1E  call     0x6b8fb0
0x006AFA23  push     ecx
0x006AFA24  mov      ecx, esp
0x006AFA26  mov      byte ptr [ebp - 4], 0x1c
0x006AFA2A  push     0x735a2c
0x006AFA2F  call     0x6b8fb0
0x006AFA34  mov      ecx, dword ptr [0x772400]
0x006AFA3A  lea      ecx, [ecx + 0xa05c]
0x006AFA40  call     0x6bfc00
0x006AFA45  movsd    xmm2, qword ptr [ebp - 0x170]
0x006AFA4D  mov      ecx, eax
0x006AFA4F  mov      byte ptr [ebp - 4], 0x11
0x006AFA53  call     0x6bef50
0x006AFA58  cvtsd2ss xmm0, xmm0
0x006AFA5C  movss    dword ptr [ebp - 0x148], xmm0
0x006AFA64  fld      dword ptr [ebp - 0x148]
0x006AFA6A  lea      edx, [0x772dd8]
0x006AFA70  fistp    dword ptr [edx]
0x006AFA72  .byte    0x8b
0x006AFA73  .byte    0x0d


======== VA 0x006AF9EA (file 0x2AEDEA) ========
0x006AF972  lcall    0x100f, 0xf2000005
0x006AF979  add      eax, 0x737500
0x006AF97E  push     ecx
0x006AF97F  mov      ecx, esp
0x006AF981  mov      dword ptr [ebp - 0x14c], esp
0x006AF987  push     0x729598
0x006AF98C  movsd    qword ptr [ebp - 0x1a8], xmm0
0x006AF994  call     0x6b8fb0
0x006AF999  push     ecx
0x006AF99A  mov      ecx, esp
0x006AF99C  mov      byte ptr [ebp - 4], 0x1b
0x006AF9A0  push     0x729590
0x006AF9A5  call     0x6b8fb0
0x006AF9AA  mov      ecx, dword ptr [0x772400]
0x006AF9B0  lea      ecx, [ecx + 0xa05c]
0x006AF9B6  call     0x6bfc00
0x006AF9BB  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006AF9C3  mov      ecx, eax
0x006AF9C5  mov      byte ptr [ebp - 4], 0x11
0x006AF9C9  call     0x6bee00
0x006AF9CE  cvtsd2ss xmm0, xmm0
0x006AF9D2  movss    dword ptr [ebp - 0x148], xmm0
0x006AF9DA  fld      dword ptr [ebp - 0x148]
0x006AF9E0  lea      edx, [0x772dd8]
0x006AF9E6  fistp    dword ptr [edx]
0x006AF9E8  mov      ecx, dword ptr [0x772400]
0x006AF9EE  mov      eax, dword ptr [0x772dd8]
0x006AF9F3  movsd    xmm0, qword ptr [0x7374b0]
0x006AF9FB  movsd    qword ptr [ebp - 0x170], xmm0
0x006AFA03  mov      dword ptr [ecx + 0x5bc], eax
0x006AFA09  lea      eax, [ebp - 0x165]
0x006AFA0F  push     eax
0x006AFA10  push     ecx
0x006AFA11  mov      ecx, esp
0x006AFA13  mov      dword ptr [ebp - 0x14c], esp
0x006AFA19  push     0x735a34
0x006AFA1E  call     0x6b8fb0
0x006AFA23  push     ecx
0x006AFA24  mov      ecx, esp
0x006AFA26  mov      byte ptr [ebp - 4], 0x1c
0x006AFA2A  push     0x735a2c
0x006AFA2F  call     0x6b8fb0
0x006AFA34  mov      ecx, dword ptr [0x772400]
0x006AFA3A  lea      ecx, [ecx + 0xa05c]
0x006AFA40  call     0x6bfc00
0x006AFA45  movsd    xmm2, qword ptr [ebp - 0x170]
0x006AFA4D  mov      ecx, eax
0x006AFA4F  mov      byte ptr [ebp - 4], 0x11
0x006AFA53  call     0x6bef50
0x006AFA58  cvtsd2ss xmm0, xmm0
0x006AFA5C  movss    dword ptr [ebp - 0x148], xmm0
0x006AFA64  fld      dword ptr [ebp - 0x148]
0x006AFA6A  lea      edx, [0x772dd8]
0x006AFA70  fistp    dword ptr [edx]
0x006AFA72  mov      ecx, dword ptr [0x772400]
0x006AFA78  mov      eax, dword ptr [0x772dd8]
0x006AFA7D  movsd    xmm0, qword ptr [0x7374a8]
0x006AFA85  movsd    qword ptr [ebp - 0x1a8], xmm0
0x006AFA8D  mov      dword ptr [ecx + 0x170], eax
0x006AFA93  lea      eax, [ebp - 0x166]
0x006AFA99  push     eax
0x006AFA9A  push     ecx
0x006AFA9B  mov      ecx, esp
0x006AFA9D  mov      dword ptr [ebp - 0x14c], esp
0x006AFAA3  push     0x735a3c
0x006AFAA8  call     0x6b8fb0
0x006AFAAD  push     ecx
0x006AFAAE  mov      ecx, esp
0x006AFAB0  .byte    0xc6
0x006AFAB1  inc      ebp


======== VA 0x006AFA36 (file 0x2AEE36) ========
0x006AF9BE  xchg     ebp, eax
0x006AF9BF  pop      eax
0x006AF9C0  .byte    0xfe
0x006AF9C1  .byte    0xff
0x006AF9C2  dec      dword ptr [ebx - 0x3ba3938]
0x006AF9C8  adc      eax, ebp
0x006AF9CA  xor      dh, ah
0x006AF9CC  add      byte ptr [eax], al
0x006AF9CE  cvtsd2ss xmm0, xmm0
0x006AF9D2  movss    dword ptr [ebp - 0x148], xmm0
0x006AF9DA  fld      dword ptr [ebp - 0x148]
0x006AF9E0  lea      edx, [0x772dd8]
0x006AF9E6  fistp    dword ptr [edx]
0x006AF9E8  mov      ecx, dword ptr [0x772400]
0x006AF9EE  mov      eax, dword ptr [0x772dd8]
0x006AF9F3  movsd    xmm0, qword ptr [0x7374b0]
0x006AF9FB  movsd    qword ptr [ebp - 0x170], xmm0
0x006AFA03  mov      dword ptr [ecx + 0x5bc], eax
0x006AFA09  lea      eax, [ebp - 0x165]
0x006AFA0F  push     eax
0x006AFA10  push     ecx
0x006AFA11  mov      ecx, esp
0x006AFA13  mov      dword ptr [ebp - 0x14c], esp
0x006AFA19  push     0x735a34
0x006AFA1E  call     0x6b8fb0
0x006AFA23  push     ecx
0x006AFA24  mov      ecx, esp
0x006AFA26  mov      byte ptr [ebp - 4], 0x1c
0x006AFA2A  push     0x735a2c
0x006AFA2F  call     0x6b8fb0
0x006AFA34  mov      ecx, dword ptr [0x772400]
0x006AFA3A  lea      ecx, [ecx + 0xa05c]
0x006AFA40  call     0x6bfc00
0x006AFA45  movsd    xmm2, qword ptr [ebp - 0x170]
0x006AFA4D  mov      ecx, eax
0x006AFA4F  mov      byte ptr [ebp - 4], 0x11
0x006AFA53  call     0x6bef50
0x006AFA58  cvtsd2ss xmm0, xmm0
0x006AFA5C  movss    dword ptr [ebp - 0x148], xmm0
0x006AFA64  fld      dword ptr [ebp - 0x148]
0x006AFA6A  lea      edx, [0x772dd8]
0x006AFA70  fistp    dword ptr [edx]
0x006AFA72  mov      ecx, dword ptr [0x772400]
0x006AFA78  mov      eax, dword ptr [0x772dd8]
0x006AFA7D  movsd    xmm0, qword ptr [0x7374a8]
0x006AFA85  movsd    qword ptr [ebp - 0x1a8], xmm0
0x006AFA8D  mov      dword ptr [ecx + 0x170], eax
0x006AFA93  lea      eax, [ebp - 0x166]
0x006AFA99  push     eax
0x006AFA9A  push     ecx
0x006AFA9B  mov      ecx, esp
0x006AFA9D  mov      dword ptr [ebp - 0x14c], esp
0x006AFAA3  push     0x735a3c
0x006AFAA8  call     0x6b8fb0
0x006AFAAD  push     ecx
0x006AFAAE  mov      ecx, esp
0x006AFAB0  mov      byte ptr [ebp - 4], 0x1d
0x006AFAB4  push     0x735a2c
0x006AFAB9  call     0x6b8fb0
0x006AFABE  mov      ecx, dword ptr [0x772400]
0x006AFAC4  lea      ecx, [ecx + 0xa05c]
0x006AFACA  call     0x6bfc00
0x006AFACF  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006AFAD7  mov      ecx, eax
0x006AFAD9  mov      byte ptr [ebp - 4], 0x11
0x006AFADD  call     0x6bef50
0x006AFAE2  cvtsd2ss xmm0, xmm0
0x006AFAE6  movss    dword ptr [ebp - 0x148], xmm0
0x006AFAEE  fld      dword ptr [ebp - 0x148]
0x006AFAF4  lea      edx, [0x772dd8]
0x006AFAFA  fistp    dword ptr [edx]
0x006AFAFC  .byte    0x8b
0x006AFAFD  .byte    0x0d


======== VA 0x006AFA74 (file 0x2AEE74) ========
0x006AF9FC  movups   xmmword ptr [ebp - 0x170], xmm0
0x006AFA03  mov      dword ptr [ecx + 0x5bc], eax
0x006AFA09  lea      eax, [ebp - 0x165]
0x006AFA0F  push     eax
0x006AFA10  push     ecx
0x006AFA11  mov      ecx, esp
0x006AFA13  mov      dword ptr [ebp - 0x14c], esp
0x006AFA19  push     0x735a34
0x006AFA1E  call     0x6b8fb0
0x006AFA23  push     ecx
0x006AFA24  mov      ecx, esp
0x006AFA26  mov      byte ptr [ebp - 4], 0x1c
0x006AFA2A  push     0x735a2c
0x006AFA2F  call     0x6b8fb0
0x006AFA34  mov      ecx, dword ptr [0x772400]
0x006AFA3A  lea      ecx, [ecx + 0xa05c]
0x006AFA40  call     0x6bfc00
0x006AFA45  movsd    xmm2, qword ptr [ebp - 0x170]
0x006AFA4D  mov      ecx, eax
0x006AFA4F  mov      byte ptr [ebp - 4], 0x11
0x006AFA53  call     0x6bef50
0x006AFA58  cvtsd2ss xmm0, xmm0
0x006AFA5C  movss    dword ptr [ebp - 0x148], xmm0
0x006AFA64  fld      dword ptr [ebp - 0x148]
0x006AFA6A  lea      edx, [0x772dd8]
0x006AFA70  fistp    dword ptr [edx]
0x006AFA72  mov      ecx, dword ptr [0x772400]
0x006AFA78  mov      eax, dword ptr [0x772dd8]
0x006AFA7D  movsd    xmm0, qword ptr [0x7374a8]
0x006AFA85  movsd    qword ptr [ebp - 0x1a8], xmm0
0x006AFA8D  mov      dword ptr [ecx + 0x170], eax
0x006AFA93  lea      eax, [ebp - 0x166]
0x006AFA99  push     eax
0x006AFA9A  push     ecx
0x006AFA9B  mov      ecx, esp
0x006AFA9D  mov      dword ptr [ebp - 0x14c], esp
0x006AFAA3  push     0x735a3c
0x006AFAA8  call     0x6b8fb0
0x006AFAAD  push     ecx
0x006AFAAE  mov      ecx, esp
0x006AFAB0  mov      byte ptr [ebp - 4], 0x1d
0x006AFAB4  push     0x735a2c
0x006AFAB9  call     0x6b8fb0
0x006AFABE  mov      ecx, dword ptr [0x772400]
0x006AFAC4  lea      ecx, [ecx + 0xa05c]
0x006AFACA  call     0x6bfc00
0x006AFACF  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006AFAD7  mov      ecx, eax
0x006AFAD9  mov      byte ptr [ebp - 4], 0x11
0x006AFADD  call     0x6bef50
0x006AFAE2  cvtsd2ss xmm0, xmm0
0x006AFAE6  movss    dword ptr [ebp - 0x148], xmm0
0x006AFAEE  fld      dword ptr [ebp - 0x148]
0x006AFAF4  lea      edx, [0x772dd8]
0x006AFAFA  fistp    dword ptr [edx]
0x006AFAFC  mov      ecx, dword ptr [0x772400]
0x006AFB02  mov      eax, dword ptr [0x772dd8]
0x006AFB07  push     ecx
0x006AFB08  mov      dword ptr [ecx + 0x174], eax
0x006AFB0E  mov      ecx, esp
0x006AFB10  mov      dword ptr [ebp - 0x14c], esp
0x006AFB16  push     0x735a44
0x006AFB1B  call     0x6b8fb0
0x006AFB20  push     ecx
0x006AFB21  mov      ecx, esp
0x006AFB23  mov      byte ptr [ebp - 4], 0x1e
0x006AFB27  push     0x735a2c
0x006AFB2C  call     0x6b8fb0
0x006AFB31  mov      ecx, dword ptr [0x772400]
0x006AFB37  .byte    0x8d
0x006AFB38  mov      dword ptr [eax], ebx


======== VA 0x006AFAC0 (file 0x2AEEC0) ========
0x006AFA48  xchg     ebp, eax
0x006AFA49  nop      
0x006AFA4A  .byte    0xfe
0x006AFA4B  .byte    0xff
0x006AFA4C  dec      dword ptr [ebx - 0x3ba3938]
0x006AFA52  adc      eax, ebp
0x006AFA54  clc      
0x006AFA55  hlt      
0x006AFA56  add      byte ptr [eax], al
0x006AFA58  cvtsd2ss xmm0, xmm0
0x006AFA5C  movss    dword ptr [ebp - 0x148], xmm0
0x006AFA64  fld      dword ptr [ebp - 0x148]
0x006AFA6A  lea      edx, [0x772dd8]
0x006AFA70  fistp    dword ptr [edx]
0x006AFA72  mov      ecx, dword ptr [0x772400]
0x006AFA78  mov      eax, dword ptr [0x772dd8]
0x006AFA7D  movsd    xmm0, qword ptr [0x7374a8]
0x006AFA85  movsd    qword ptr [ebp - 0x1a8], xmm0
0x006AFA8D  mov      dword ptr [ecx + 0x170], eax
0x006AFA93  lea      eax, [ebp - 0x166]
0x006AFA99  push     eax
0x006AFA9A  push     ecx
0x006AFA9B  mov      ecx, esp
0x006AFA9D  mov      dword ptr [ebp - 0x14c], esp
0x006AFAA3  push     0x735a3c
0x006AFAA8  call     0x6b8fb0
0x006AFAAD  push     ecx
0x006AFAAE  mov      ecx, esp
0x006AFAB0  mov      byte ptr [ebp - 4], 0x1d
0x006AFAB4  push     0x735a2c
0x006AFAB9  call     0x6b8fb0
0x006AFABE  mov      ecx, dword ptr [0x772400]
0x006AFAC4  lea      ecx, [ecx + 0xa05c]
0x006AFACA  call     0x6bfc00
0x006AFACF  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006AFAD7  mov      ecx, eax
0x006AFAD9  mov      byte ptr [ebp - 4], 0x11
0x006AFADD  call     0x6bef50
0x006AFAE2  cvtsd2ss xmm0, xmm0
0x006AFAE6  movss    dword ptr [ebp - 0x148], xmm0
0x006AFAEE  fld      dword ptr [ebp - 0x148]
0x006AFAF4  lea      edx, [0x772dd8]
0x006AFAFA  fistp    dword ptr [edx]
0x006AFAFC  mov      ecx, dword ptr [0x772400]
0x006AFB02  mov      eax, dword ptr [0x772dd8]
0x006AFB07  push     ecx
0x006AFB08  mov      dword ptr [ecx + 0x174], eax
0x006AFB0E  mov      ecx, esp
0x006AFB10  mov      dword ptr [ebp - 0x14c], esp
0x006AFB16  push     0x735a44
0x006AFB1B  call     0x6b8fb0
0x006AFB20  push     ecx
0x006AFB21  mov      ecx, esp
0x006AFB23  mov      byte ptr [ebp - 4], 0x1e
0x006AFB27  push     0x735a2c
0x006AFB2C  call     0x6b8fb0
0x006AFB31  mov      ecx, dword ptr [0x772400]
0x006AFB37  lea      ecx, [ecx + 0xa05c]
0x006AFB3D  call     0x6bfc00
0x006AFB42  movsd    xmm2, qword ptr [ebp - 0x188]
0x006AFB4A  mov      ecx, eax
0x006AFB4C  mov      byte ptr [ebp - 4], 0x11
0x006AFB50  call     0x6bee00
0x006AFB55  movsd    xmm1, qword ptr [ebp - 0x198]
0x006AFB5D  ucomisd  xmm1, xmm0
0x006AFB61  lahf     
0x006AFB62  test     ah, 0x44
0x006AFB65  jnp      0x6afb6b
0x006AFB67  mov      cl, 1
0x006AFB69  jmp      0x6afb6d
0x006AFB6B  xor      cl, cl
0x006AFB6D  mov      eax, dword ptr [0x772400]
0x006AFB72  push     ecx
0x006AFB73  mov      dword ptr [ebp - 0x14c], esp
0x006AFB79  mov      byte ptr [eax + 0x178], cl
0x006AFB7F  mov      ecx, esp
0x006AFB81  push     0x735a50
0x006AFB86  .byte    0xe8
0x006AFB87  .byte    0x25


======== VA 0x006AFAFE (file 0x2AEEFE) ========
0x006AFA86  movups   xmmword ptr [ebp - 0x1a8], xmm0
0x006AFA8D  mov      dword ptr [ecx + 0x170], eax
0x006AFA93  lea      eax, [ebp - 0x166]
0x006AFA99  push     eax
0x006AFA9A  push     ecx
0x006AFA9B  mov      ecx, esp
0x006AFA9D  mov      dword ptr [ebp - 0x14c], esp
0x006AFAA3  push     0x735a3c
0x006AFAA8  call     0x6b8fb0
0x006AFAAD  push     ecx
0x006AFAAE  mov      ecx, esp
0x006AFAB0  mov      byte ptr [ebp - 4], 0x1d
0x006AFAB4  push     0x735a2c
0x006AFAB9  call     0x6b8fb0
0x006AFABE  mov      ecx, dword ptr [0x772400]
0x006AFAC4  lea      ecx, [ecx + 0xa05c]
0x006AFACA  call     0x6bfc00
0x006AFACF  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006AFAD7  mov      ecx, eax
0x006AFAD9  mov      byte ptr [ebp - 4], 0x11
0x006AFADD  call     0x6bef50
0x006AFAE2  cvtsd2ss xmm0, xmm0
0x006AFAE6  movss    dword ptr [ebp - 0x148], xmm0
0x006AFAEE  fld      dword ptr [ebp - 0x148]
0x006AFAF4  lea      edx, [0x772dd8]
0x006AFAFA  fistp    dword ptr [edx]
0x006AFAFC  mov      ecx, dword ptr [0x772400]
0x006AFB02  mov      eax, dword ptr [0x772dd8]
0x006AFB07  push     ecx
0x006AFB08  mov      dword ptr [ecx + 0x174], eax
0x006AFB0E  mov      ecx, esp
0x006AFB10  mov      dword ptr [ebp - 0x14c], esp
0x006AFB16  push     0x735a44
0x006AFB1B  call     0x6b8fb0
0x006AFB20  push     ecx
0x006AFB21  mov      ecx, esp
0x006AFB23  mov      byte ptr [ebp - 4], 0x1e
0x006AFB27  push     0x735a2c
0x006AFB2C  call     0x6b8fb0
0x006AFB31  mov      ecx, dword ptr [0x772400]
0x006AFB37  lea      ecx, [ecx + 0xa05c]
0x006AFB3D  call     0x6bfc00
0x006AFB42  movsd    xmm2, qword ptr [ebp - 0x188]
0x006AFB4A  mov      ecx, eax
0x006AFB4C  mov      byte ptr [ebp - 4], 0x11
0x006AFB50  call     0x6bee00
0x006AFB55  movsd    xmm1, qword ptr [ebp - 0x198]
0x006AFB5D  ucomisd  xmm1, xmm0
0x006AFB61  lahf     
0x006AFB62  test     ah, 0x44
0x006AFB65  jnp      0x6afb6b
0x006AFB67  mov      cl, 1
0x006AFB69  jmp      0x6afb6d
0x006AFB6B  xor      cl, cl
0x006AFB6D  mov      eax, dword ptr [0x772400]
0x006AFB72  push     ecx
0x006AFB73  mov      dword ptr [ebp - 0x14c], esp
0x006AFB79  mov      byte ptr [eax + 0x178], cl
0x006AFB7F  mov      ecx, esp
0x006AFB81  push     0x735a50
0x006AFB86  call     0x6b8fb0
0x006AFB8B  push     ecx
0x006AFB8C  mov      ecx, esp
0x006AFB8E  mov      byte ptr [ebp - 4], 0x1f
0x006AFB92  push     0x725104
0x006AFB97  call     0x6b8fb0
0x006AFB9C  mov      ecx, dword ptr [0x772400]
0x006AFBA2  lea      ecx, [ecx + 0xa05c]
0x006AFBA8  call     0x6bfc00
0x006AFBAD  movsd    xmm2, qword ptr [ebp - 0x188]
0x006AFBB5  mov      ecx, eax
0x006AFBB7  mov      byte ptr [ebp - 4], 0x11
0x006AFBBB  call     0x6bee00
0x006AFBC0  mov      eax, dword ptr [0x772400]
0x006AFBC5  .byte    0xf2


======== VA 0x006AFB33 (file 0x2AEF33) ========
0x006AFABB  xchg     esp, eax
0x006AFABC  add      byte ptr [eax], al
0x006AFABE  mov      ecx, dword ptr [0x772400]
0x006AFAC4  lea      ecx, [ecx + 0xa05c]
0x006AFACA  call     0x6bfc00
0x006AFACF  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006AFAD7  mov      ecx, eax
0x006AFAD9  mov      byte ptr [ebp - 4], 0x11
0x006AFADD  call     0x6bef50
0x006AFAE2  cvtsd2ss xmm0, xmm0
0x006AFAE6  movss    dword ptr [ebp - 0x148], xmm0
0x006AFAEE  fld      dword ptr [ebp - 0x148]
0x006AFAF4  lea      edx, [0x772dd8]
0x006AFAFA  fistp    dword ptr [edx]
0x006AFAFC  mov      ecx, dword ptr [0x772400]
0x006AFB02  mov      eax, dword ptr [0x772dd8]
0x006AFB07  push     ecx
0x006AFB08  mov      dword ptr [ecx + 0x174], eax
0x006AFB0E  mov      ecx, esp
0x006AFB10  mov      dword ptr [ebp - 0x14c], esp
0x006AFB16  push     0x735a44
0x006AFB1B  call     0x6b8fb0
0x006AFB20  push     ecx
0x006AFB21  mov      ecx, esp
0x006AFB23  mov      byte ptr [ebp - 4], 0x1e
0x006AFB27  push     0x735a2c
0x006AFB2C  call     0x6b8fb0
0x006AFB31  mov      ecx, dword ptr [0x772400]
0x006AFB37  lea      ecx, [ecx + 0xa05c]
0x006AFB3D  call     0x6bfc00
0x006AFB42  movsd    xmm2, qword ptr [ebp - 0x188]
0x006AFB4A  mov      ecx, eax
0x006AFB4C  mov      byte ptr [ebp - 4], 0x11
0x006AFB50  call     0x6bee00
0x006AFB55  movsd    xmm1, qword ptr [ebp - 0x198]
0x006AFB5D  ucomisd  xmm1, xmm0
0x006AFB61  lahf     
0x006AFB62  test     ah, 0x44
0x006AFB65  jnp      0x6afb6b
0x006AFB67  mov      cl, 1
0x006AFB69  jmp      0x6afb6d
0x006AFB6B  xor      cl, cl
0x006AFB6D  mov      eax, dword ptr [0x772400]
0x006AFB72  push     ecx
0x006AFB73  mov      dword ptr [ebp - 0x14c], esp
0x006AFB79  mov      byte ptr [eax + 0x178], cl
0x006AFB7F  mov      ecx, esp
0x006AFB81  push     0x735a50
0x006AFB86  call     0x6b8fb0
0x006AFB8B  push     ecx
0x006AFB8C  mov      ecx, esp
0x006AFB8E  mov      byte ptr [ebp - 4], 0x1f
0x006AFB92  push     0x725104
0x006AFB97  call     0x6b8fb0
0x006AFB9C  mov      ecx, dword ptr [0x772400]
0x006AFBA2  lea      ecx, [ecx + 0xa05c]
0x006AFBA8  call     0x6bfc00
0x006AFBAD  movsd    xmm2, qword ptr [ebp - 0x188]
0x006AFBB5  mov      ecx, eax
0x006AFBB7  mov      byte ptr [ebp - 4], 0x11
0x006AFBBB  call     0x6bee00
0x006AFBC0  mov      eax, dword ptr [0x772400]
0x006AFBC5  cvtsd2ss xmm0, xmm0
0x006AFBC9  push     ecx
0x006AFBCA  mov      ecx, esp
0x006AFBCC  mov      dword ptr [ebp - 0x14c], esp
0x006AFBD2  push     0x735a5c
0x006AFBD7  movss    dword ptr [eax + 0x18c], xmm0
0x006AFBDF  call     0x6b8fb0
0x006AFBE4  push     ecx
0x006AFBE5  mov      ecx, esp
0x006AFBE7  mov      byte ptr [ebp - 4], 0x20
0x006AFBEB  push     0x725104
0x006AFBF0  call     0x6b8fb0
0x006AFBF5  mov      ecx, dword ptr [0x772400]


======== VA 0x006AFDDB (file 0x2AF1DB) ========
0x006AFD63  add      al, ch
0x006AFD65  inc      edi
0x006AFD66  xchg     edx, eax
0x006AFD67  add      byte ptr [eax], al
0x006AFD69  mov      ecx, dword ptr [0x772400]
0x006AFD6F  lea      ecx, [ecx + 0xa05c]
0x006AFD75  call     0x6bfc00
0x006AFD7A  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFD82  mov      ecx, eax
0x006AFD84  mov      byte ptr [ebp - 4], 0x11
0x006AFD88  call     0x6bee00
0x006AFD8D  mov      eax, dword ptr [0x772400]
0x006AFD92  movss    xmm1, dword ptr [0x737330]
0x006AFD9A  cvtsd2ss xmm0, xmm0
0x006AFD9E  comiss   xmm1, xmm0
0x006AFDA1  movss    dword ptr [eax + 0x17c], xmm0
0x006AFDA9  jbe      0x6afdb5
0x006AFDAB  mov      dword ptr [eax + 0x17c], 0x42480000
0x006AFDB5  push     ecx
0x006AFDB6  mov      ecx, esp
0x006AFDB8  mov      dword ptr [ebp - 0x14c], esp
0x006AFDBE  push     0x7282a0
0x006AFDC3  call     0x6b8fb0
0x006AFDC8  push     ecx
0x006AFDC9  mov      ecx, esp
0x006AFDCB  mov      byte ptr [ebp - 4], 0x25
0x006AFDCF  push     0x735a2c
0x006AFDD4  call     0x6b8fb0
0x006AFDD9  mov      ecx, dword ptr [0x772400]
0x006AFDDF  lea      ecx, [ecx + 0xa05c]
0x006AFDE5  call     0x6bfc00
0x006AFDEA  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFDF2  mov      ecx, eax
0x006AFDF4  mov      byte ptr [ebp - 4], 0x11
0x006AFDF8  call     0x6bee00
0x006AFDFD  mov      eax, dword ptr [0x772400]
0x006AFE02  xorps    xmm1, xmm1
0x006AFE05  cvtsd2ss xmm1, xmm0
0x006AFE09  movss    xmm0, dword ptr [0x737428]
0x006AFE11  comiss   xmm0, xmm1
0x006AFE14  movss    dword ptr [eax + 0x180], xmm1
0x006AFE1C  jbe      0x6afe28
0x006AFE1E  mov      dword ptr [eax + 0x180], 0x42480000
0x006AFE28  movsd    xmm0, qword ptr [0x737458]
0x006AFE30  push     ecx
0x006AFE31  mov      ecx, esp
0x006AFE33  mov      dword ptr [ebp - 0x14c], esp
0x006AFE39  push     0x735a94
0x006AFE3E  movsd    qword ptr [ebp - 0x190], xmm0
0x006AFE46  call     0x6b8fb0
0x006AFE4B  push     ecx
0x006AFE4C  mov      ecx, esp
0x006AFE4E  mov      byte ptr [ebp - 4], 0x26
0x006AFE52  push     0x735a1c
0x006AFE57  call     0x6b8fb0
0x006AFE5C  mov      ecx, dword ptr [0x772400]
0x006AFE62  lea      ecx, [ecx + 0xa05c]
0x006AFE68  call     0x6bfc00
0x006AFE6D  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFE75  mov      ecx, eax
0x006AFE77  mov      byte ptr [ebp - 4], 0x11
0x006AFE7B  call     0x6bee00
0x006AFE80  cvtsd2ss xmm0, xmm0
0x006AFE84  movss    dword ptr [ebp - 0x148], xmm0
0x006AFE8C  fld      dword ptr [ebp - 0x148]
0x006AFE92  lea      edx, [0x772dd8]
0x006AFE98  fistp    dword ptr [edx]
0x006AFE9A  mov      ecx, dword ptr [0x772400]
0x006AFEA0  .byte    0xa1
0x006AFEA1  .byte    0xd8
0x006AFEA2  .byte    0x2d


======== VA 0x006AFDFE (file 0x2AF1FE) ========
0x006AFD86  cld      
0x006AFD87  adc      eax, ebp
0x006AFD89  jae      0x6afd7b
0x006AFD8B  add      byte ptr [eax], al
0x006AFD8D  mov      eax, dword ptr [0x772400]
0x006AFD92  movss    xmm1, dword ptr [0x737330]
0x006AFD9A  cvtsd2ss xmm0, xmm0
0x006AFD9E  comiss   xmm1, xmm0
0x006AFDA1  movss    dword ptr [eax + 0x17c], xmm0
0x006AFDA9  jbe      0x6afdb5
0x006AFDAB  mov      dword ptr [eax + 0x17c], 0x42480000
0x006AFDB5  push     ecx
0x006AFDB6  mov      ecx, esp
0x006AFDB8  mov      dword ptr [ebp - 0x14c], esp
0x006AFDBE  push     0x7282a0
0x006AFDC3  call     0x6b8fb0
0x006AFDC8  push     ecx
0x006AFDC9  mov      ecx, esp
0x006AFDCB  mov      byte ptr [ebp - 4], 0x25
0x006AFDCF  push     0x735a2c
0x006AFDD4  call     0x6b8fb0
0x006AFDD9  mov      ecx, dword ptr [0x772400]
0x006AFDDF  lea      ecx, [ecx + 0xa05c]
0x006AFDE5  call     0x6bfc00
0x006AFDEA  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFDF2  mov      ecx, eax
0x006AFDF4  mov      byte ptr [ebp - 4], 0x11
0x006AFDF8  call     0x6bee00
0x006AFDFD  mov      eax, dword ptr [0x772400]
0x006AFE02  xorps    xmm1, xmm1
0x006AFE05  cvtsd2ss xmm1, xmm0
0x006AFE09  movss    xmm0, dword ptr [0x737428]
0x006AFE11  comiss   xmm0, xmm1
0x006AFE14  movss    dword ptr [eax + 0x180], xmm1
0x006AFE1C  jbe      0x6afe28
0x006AFE1E  mov      dword ptr [eax + 0x180], 0x42480000
0x006AFE28  movsd    xmm0, qword ptr [0x737458]
0x006AFE30  push     ecx
0x006AFE31  mov      ecx, esp
0x006AFE33  mov      dword ptr [ebp - 0x14c], esp
0x006AFE39  push     0x735a94
0x006AFE3E  movsd    qword ptr [ebp - 0x190], xmm0
0x006AFE46  call     0x6b8fb0
0x006AFE4B  push     ecx
0x006AFE4C  mov      ecx, esp
0x006AFE4E  mov      byte ptr [ebp - 4], 0x26
0x006AFE52  push     0x735a1c
0x006AFE57  call     0x6b8fb0
0x006AFE5C  mov      ecx, dword ptr [0x772400]
0x006AFE62  lea      ecx, [ecx + 0xa05c]
0x006AFE68  call     0x6bfc00
0x006AFE6D  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFE75  mov      ecx, eax
0x006AFE77  mov      byte ptr [ebp - 4], 0x11
0x006AFE7B  call     0x6bee00
0x006AFE80  cvtsd2ss xmm0, xmm0
0x006AFE84  movss    dword ptr [ebp - 0x148], xmm0
0x006AFE8C  fld      dword ptr [ebp - 0x148]
0x006AFE92  lea      edx, [0x772dd8]
0x006AFE98  fistp    dword ptr [edx]
0x006AFE9A  mov      ecx, dword ptr [0x772400]
0x006AFEA0  mov      eax, dword ptr [0x772dd8]
0x006AFEA5  push     ecx
0x006AFEA6  mov      dword ptr [ebp - 0x14c], esp
0x006AFEAC  mov      dword ptr [ecx + 0x188], eax
0x006AFEB2  mov      ecx, esp
0x006AFEB4  push     0x735aa0
0x006AFEB9  call     0x6b8fb0
0x006AFEBE  push     ecx
0x006AFEBF  mov      ecx, esp
0x006AFEC1  mov      byte ptr [ebp - 4], 0x27
0x006AFEC5  .byte    0x68


======== VA 0x006AFE5E (file 0x2AF25E) ========
0x006AFDE6  push     ss
0x006AFDE7  inc      byte ptr [eax]
0x006AFDE9  add      dl, dh
0x006AFDEB  movups   xmm2, xmmword ptr [ebp - 0x190]
0x006AFDF2  mov      ecx, eax
0x006AFDF4  mov      byte ptr [ebp - 4], 0x11
0x006AFDF8  call     0x6bee00
0x006AFDFD  mov      eax, dword ptr [0x772400]
0x006AFE02  xorps    xmm1, xmm1
0x006AFE05  cvtsd2ss xmm1, xmm0
0x006AFE09  movss    xmm0, dword ptr [0x737428]
0x006AFE11  comiss   xmm0, xmm1
0x006AFE14  movss    dword ptr [eax + 0x180], xmm1
0x006AFE1C  jbe      0x6afe28
0x006AFE1E  mov      dword ptr [eax + 0x180], 0x42480000
0x006AFE28  movsd    xmm0, qword ptr [0x737458]
0x006AFE30  push     ecx
0x006AFE31  mov      ecx, esp
0x006AFE33  mov      dword ptr [ebp - 0x14c], esp
0x006AFE39  push     0x735a94
0x006AFE3E  movsd    qword ptr [ebp - 0x190], xmm0
0x006AFE46  call     0x6b8fb0
0x006AFE4B  push     ecx
0x006AFE4C  mov      ecx, esp
0x006AFE4E  mov      byte ptr [ebp - 4], 0x26
0x006AFE52  push     0x735a1c
0x006AFE57  call     0x6b8fb0
0x006AFE5C  mov      ecx, dword ptr [0x772400]
0x006AFE62  lea      ecx, [ecx + 0xa05c]
0x006AFE68  call     0x6bfc00
0x006AFE6D  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFE75  mov      ecx, eax
0x006AFE77  mov      byte ptr [ebp - 4], 0x11
0x006AFE7B  call     0x6bee00
0x006AFE80  cvtsd2ss xmm0, xmm0
0x006AFE84  movss    dword ptr [ebp - 0x148], xmm0
0x006AFE8C  fld      dword ptr [ebp - 0x148]
0x006AFE92  lea      edx, [0x772dd8]
0x006AFE98  fistp    dword ptr [edx]
0x006AFE9A  mov      ecx, dword ptr [0x772400]
0x006AFEA0  mov      eax, dword ptr [0x772dd8]
0x006AFEA5  push     ecx
0x006AFEA6  mov      dword ptr [ebp - 0x14c], esp
0x006AFEAC  mov      dword ptr [ecx + 0x188], eax
0x006AFEB2  mov      ecx, esp
0x006AFEB4  push     0x735aa0
0x006AFEB9  call     0x6b8fb0
0x006AFEBE  push     ecx
0x006AFEBF  mov      ecx, esp
0x006AFEC1  mov      byte ptr [ebp - 4], 0x27
0x006AFEC5  push     0x735a1c
0x006AFECA  call     0x6b8fb0
0x006AFECF  mov      ecx, dword ptr [0x772400]
0x006AFED5  lea      ecx, [ecx + 0xa05c]
0x006AFEDB  call     0x6bfc00
0x006AFEE0  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFEE8  mov      ecx, eax
0x006AFEEA  mov      byte ptr [ebp - 4], 0x11
0x006AFEEE  call     0x6bee00
0x006AFEF3  cvtsd2ss xmm0, xmm0
0x006AFEF7  movss    dword ptr [ebp - 0x148], xmm0
0x006AFEFF  fld      dword ptr [ebp - 0x148]
0x006AFF05  lea      edx, [0x772dd8]
0x006AFF0B  fistp    dword ptr [edx]
0x006AFF0D  mov      ecx, dword ptr [0x772400]
0x006AFF13  mov      edx, 0x7364b0
0x006AFF18  mov      eax, dword ptr [0x772dd8]
0x006AFF1D  push     0x19
0x006AFF1F  mov      dword ptr [ecx + 0x184], eax
0x006AFF25  .byte    0xb9


======== VA 0x006AFE9C (file 0x2AF29C) ========
0x006AFE24  add      byte ptr [eax], al
0x006AFE26  dec      eax
0x006AFE27  inc      edx
0x006AFE28  movsd    xmm0, qword ptr [0x737458]
0x006AFE30  push     ecx
0x006AFE31  mov      ecx, esp
0x006AFE33  mov      dword ptr [ebp - 0x14c], esp
0x006AFE39  push     0x735a94
0x006AFE3E  movsd    qword ptr [ebp - 0x190], xmm0
0x006AFE46  call     0x6b8fb0
0x006AFE4B  push     ecx
0x006AFE4C  mov      ecx, esp
0x006AFE4E  mov      byte ptr [ebp - 4], 0x26
0x006AFE52  push     0x735a1c
0x006AFE57  call     0x6b8fb0
0x006AFE5C  mov      ecx, dword ptr [0x772400]
0x006AFE62  lea      ecx, [ecx + 0xa05c]
0x006AFE68  call     0x6bfc00
0x006AFE6D  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFE75  mov      ecx, eax
0x006AFE77  mov      byte ptr [ebp - 4], 0x11
0x006AFE7B  call     0x6bee00
0x006AFE80  cvtsd2ss xmm0, xmm0
0x006AFE84  movss    dword ptr [ebp - 0x148], xmm0
0x006AFE8C  fld      dword ptr [ebp - 0x148]
0x006AFE92  lea      edx, [0x772dd8]
0x006AFE98  fistp    dword ptr [edx]
0x006AFE9A  mov      ecx, dword ptr [0x772400]
0x006AFEA0  mov      eax, dword ptr [0x772dd8]
0x006AFEA5  push     ecx
0x006AFEA6  mov      dword ptr [ebp - 0x14c], esp
0x006AFEAC  mov      dword ptr [ecx + 0x188], eax
0x006AFEB2  mov      ecx, esp
0x006AFEB4  push     0x735aa0
0x006AFEB9  call     0x6b8fb0
0x006AFEBE  push     ecx
0x006AFEBF  mov      ecx, esp
0x006AFEC1  mov      byte ptr [ebp - 4], 0x27
0x006AFEC5  push     0x735a1c
0x006AFECA  call     0x6b8fb0
0x006AFECF  mov      ecx, dword ptr [0x772400]
0x006AFED5  lea      ecx, [ecx + 0xa05c]
0x006AFEDB  call     0x6bfc00
0x006AFEE0  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFEE8  mov      ecx, eax
0x006AFEEA  mov      byte ptr [ebp - 4], 0x11
0x006AFEEE  call     0x6bee00
0x006AFEF3  cvtsd2ss xmm0, xmm0
0x006AFEF7  movss    dword ptr [ebp - 0x148], xmm0
0x006AFEFF  fld      dword ptr [ebp - 0x148]
0x006AFF05  lea      edx, [0x772dd8]
0x006AFF0B  fistp    dword ptr [edx]
0x006AFF0D  mov      ecx, dword ptr [0x772400]
0x006AFF13  mov      edx, 0x7364b0
0x006AFF18  mov      eax, dword ptr [0x772dd8]
0x006AFF1D  push     0x19
0x006AFF1F  mov      dword ptr [ecx + 0x184], eax
0x006AFF25  mov      ecx, 0x20
0x006AFF2A  call     0x6ba810
0x006AFF2F  add      esp, 4
0x006AFF32  mov      dword ptr [ebp - 0x150], eax
0x006AFF38  mov      dword ptr [eax + 4], 0x14
0x006AFF3F  mov      dword ptr [eax + 8], 0xffffffff
0x006AFF46  mov      byte ptr [eax + 0xc], 0
0x006AFF4A  mov      dword ptr [eax], 1
0x006AFF50  lea      eax, [ebp - 0x150]
0x006AFF56  mov      byte ptr [ebp - 4], 0x28
0x006AFF5A  push     eax
0x006AFF5B  push     ecx
0x006AFF5C  mov      ecx, esp
0x006AFF5E  mov      dword ptr [ebp - 0x14c], esp


======== VA 0x006AFED1 (file 0x2AF2D1) ========
0x006AFE59  xchg     ecx, eax
0x006AFE5A  add      byte ptr [eax], al
0x006AFE5C  mov      ecx, dword ptr [0x772400]
0x006AFE62  lea      ecx, [ecx + 0xa05c]
0x006AFE68  call     0x6bfc00
0x006AFE6D  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFE75  mov      ecx, eax
0x006AFE77  mov      byte ptr [ebp - 4], 0x11
0x006AFE7B  call     0x6bee00
0x006AFE80  cvtsd2ss xmm0, xmm0
0x006AFE84  movss    dword ptr [ebp - 0x148], xmm0
0x006AFE8C  fld      dword ptr [ebp - 0x148]
0x006AFE92  lea      edx, [0x772dd8]
0x006AFE98  fistp    dword ptr [edx]
0x006AFE9A  mov      ecx, dword ptr [0x772400]
0x006AFEA0  mov      eax, dword ptr [0x772dd8]
0x006AFEA5  push     ecx
0x006AFEA6  mov      dword ptr [ebp - 0x14c], esp
0x006AFEAC  mov      dword ptr [ecx + 0x188], eax
0x006AFEB2  mov      ecx, esp
0x006AFEB4  push     0x735aa0
0x006AFEB9  call     0x6b8fb0
0x006AFEBE  push     ecx
0x006AFEBF  mov      ecx, esp
0x006AFEC1  mov      byte ptr [ebp - 4], 0x27
0x006AFEC5  push     0x735a1c
0x006AFECA  call     0x6b8fb0
0x006AFECF  mov      ecx, dword ptr [0x772400]
0x006AFED5  lea      ecx, [ecx + 0xa05c]
0x006AFEDB  call     0x6bfc00
0x006AFEE0  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFEE8  mov      ecx, eax
0x006AFEEA  mov      byte ptr [ebp - 4], 0x11
0x006AFEEE  call     0x6bee00
0x006AFEF3  cvtsd2ss xmm0, xmm0
0x006AFEF7  movss    dword ptr [ebp - 0x148], xmm0
0x006AFEFF  fld      dword ptr [ebp - 0x148]
0x006AFF05  lea      edx, [0x772dd8]
0x006AFF0B  fistp    dword ptr [edx]
0x006AFF0D  mov      ecx, dword ptr [0x772400]
0x006AFF13  mov      edx, 0x7364b0
0x006AFF18  mov      eax, dword ptr [0x772dd8]
0x006AFF1D  push     0x19
0x006AFF1F  mov      dword ptr [ecx + 0x184], eax
0x006AFF25  mov      ecx, 0x20
0x006AFF2A  call     0x6ba810
0x006AFF2F  add      esp, 4
0x006AFF32  mov      dword ptr [ebp - 0x150], eax
0x006AFF38  mov      dword ptr [eax + 4], 0x14
0x006AFF3F  mov      dword ptr [eax + 8], 0xffffffff
0x006AFF46  mov      byte ptr [eax + 0xc], 0
0x006AFF4A  mov      dword ptr [eax], 1
0x006AFF50  lea      eax, [ebp - 0x150]
0x006AFF56  mov      byte ptr [ebp - 4], 0x28
0x006AFF5A  push     eax
0x006AFF5B  push     ecx
0x006AFF5C  mov      ecx, esp
0x006AFF5E  mov      dword ptr [ebp - 0x14c], esp
0x006AFF64  push     0x735aac
0x006AFF69  call     0x6b8fb0
0x006AFF6E  push     ecx
0x006AFF6F  mov      ecx, esp
0x006AFF71  mov      byte ptr [ebp - 4], 0x29
0x006AFF75  push     0x735a2c
0x006AFF7A  call     0x6b8fb0
0x006AFF7F  mov      ecx, dword ptr [0x772400]
0x006AFF85  lea      ecx, [ecx + 0xa05c]
0x006AFF8B  call     0x6bfc00
0x006AFF90  mov      ecx, eax
0x006AFF92  mov      byte ptr [ebp - 4], 0x28
0x006AFF96  .byte    0xe8
0x006AFF97  .byte    0x05
0x006AFF98  int1     


======== VA 0x006AFF0F (file 0x2AF30F) ========
0x006AFE97  add      bl, bl
0x006AFE99  sbb      cl, byte ptr [ebx + 0x7724000d]
0x006AFE9F  add      byte ptr [ecx + 0x772dd8], ah
0x006AFEA5  push     ecx
0x006AFEA6  mov      dword ptr [ebp - 0x14c], esp
0x006AFEAC  mov      dword ptr [ecx + 0x188], eax
0x006AFEB2  mov      ecx, esp
0x006AFEB4  push     0x735aa0
0x006AFEB9  call     0x6b8fb0
0x006AFEBE  push     ecx
0x006AFEBF  mov      ecx, esp
0x006AFEC1  mov      byte ptr [ebp - 4], 0x27
0x006AFEC5  push     0x735a1c
0x006AFECA  call     0x6b8fb0
0x006AFECF  mov      ecx, dword ptr [0x772400]
0x006AFED5  lea      ecx, [ecx + 0xa05c]
0x006AFEDB  call     0x6bfc00
0x006AFEE0  movsd    xmm2, qword ptr [ebp - 0x190]
0x006AFEE8  mov      ecx, eax
0x006AFEEA  mov      byte ptr [ebp - 4], 0x11
0x006AFEEE  call     0x6bee00
0x006AFEF3  cvtsd2ss xmm0, xmm0
0x006AFEF7  movss    dword ptr [ebp - 0x148], xmm0
0x006AFEFF  fld      dword ptr [ebp - 0x148]
0x006AFF05  lea      edx, [0x772dd8]
0x006AFF0B  fistp    dword ptr [edx]
0x006AFF0D  mov      ecx, dword ptr [0x772400]
0x006AFF13  mov      edx, 0x7364b0
0x006AFF18  mov      eax, dword ptr [0x772dd8]
0x006AFF1D  push     0x19
0x006AFF1F  mov      dword ptr [ecx + 0x184], eax
0x006AFF25  mov      ecx, 0x20
0x006AFF2A  call     0x6ba810
0x006AFF2F  add      esp, 4
0x006AFF32  mov      dword ptr [ebp - 0x150], eax
0x006AFF38  mov      dword ptr [eax + 4], 0x14
0x006AFF3F  mov      dword ptr [eax + 8], 0xffffffff
0x006AFF46  mov      byte ptr [eax + 0xc], 0
0x006AFF4A  mov      dword ptr [eax], 1
0x006AFF50  lea      eax, [ebp - 0x150]
0x006AFF56  mov      byte ptr [ebp - 4], 0x28
0x006AFF5A  push     eax
0x006AFF5B  push     ecx
0x006AFF5C  mov      ecx, esp
0x006AFF5E  mov      dword ptr [ebp - 0x14c], esp
0x006AFF64  push     0x735aac
0x006AFF69  call     0x6b8fb0
0x006AFF6E  push     ecx
0x006AFF6F  mov      ecx, esp
0x006AFF71  mov      byte ptr [ebp - 4], 0x29
0x006AFF75  push     0x735a2c
0x006AFF7A  call     0x6b8fb0
0x006AFF7F  mov      ecx, dword ptr [0x772400]
0x006AFF85  lea      ecx, [ecx + 0xa05c]
0x006AFF8B  call     0x6bfc00
0x006AFF90  mov      ecx, eax
0x006AFF92  mov      byte ptr [ebp - 4], 0x28
0x006AFF96  call     0x6bf0a0
0x006AFF9B  test     al, al
0x006AFF9D  je       0x6b009c
0x006AFFA3  lea      ecx, [ebp - 0x118]
0x006AFFA9  mov      eax, dword ptr [ebp - 0x150]
0x006AFFAF  push     ecx
0x006AFFB0  lea      ecx, [ebp - 0x11c]
0x006AFFB6  add      eax, 0xc
0x006AFFB9  push     ecx
0x006AFFBA  lea      ecx, [ebp - 0x120]
0x006AFFC0  push     ecx
0x006AFFC1  lea      ecx, [ebp - 0x124]
0x006AFFC7  push     ecx
0x006AFFC8  lea      ecx, [ebp - 0x128]
0x006AFFCE  push     ecx
0x006AFFCF  lea      ecx, [ebp - 0x12c]
0x006AFFD5  push     ecx
0x006AFFD6  .byte    0x8d


======== VA 0x006B0315 (file 0x2AF715) ========
0x006B029D  add      byte ptr [eax], al
0x006B029F  add      byte ptr [ebx + 0x76a29c], ah
0x006B02A5  call     0x6ba810
0x006B02AA  add      esp, 4
0x006B02AD  mov      dword ptr [ebp - 0x148], eax
0x006B02B3  test     eax, eax
0x006B02B5  je       0x6b02d8
0x006B02B7  push     eax
0x006B02B8  call     dword ptr [0x71530c]
0x006B02BE  mov      eax, dword ptr [ebp - 0x148]
0x006B02C4  mov      byte ptr [eax + 0x18], 0
0x006B02C8  mov      dword ptr [eax + 0x1c], 0
0x006B02CF  mov      dword ptr [eax + 0x20], 0
0x006B02D6  jmp      0x6b02da
0x006B02D8  xor      eax, eax
0x006B02DA  mov      dword ptr [0x772404], eax
0x006B02DF  mov      eax, dword ptr [ebp - 0x178]
0x006B02E5  add      eax, 0xc
0x006B02E8  push     eax
0x006B02E9  push     ecx
0x006B02EA  mov      ecx, esp
0x006B02EC  mov      dword ptr [ebp - 0x164], eax
0x006B02F2  push     0x72f314
0x006B02F7  call     0x6b8fb0
0x006B02FC  call     0x55c350
0x006B0301  push     ecx
0x006B0302  mov      ecx, esp
0x006B0304  push     0x735b14
0x006B0309  call     0x6b8fb0
0x006B030E  call     0x444fc0
0x006B0313  mov      ecx, dword ptr [0x772400]
0x006B0319  push     ecx
0x006B031A  mov      dword ptr [ecx + 0x1b4], eax
0x006B0320  mov      ecx, esp
0x006B0322  push     0x735b1c
0x006B0327  call     0x6b8fb0
0x006B032C  call     0x444fc0
0x006B0331  mov      ecx, dword ptr [0x772400]
0x006B0337  push     ecx
0x006B0338  mov      dword ptr [ecx + 0x1b8], eax
0x006B033E  mov      ecx, esp
0x006B0340  push     0x735b24
0x006B0345  call     0x6b8fb0
0x006B034A  call     0x444fc0
0x006B034F  mov      ecx, dword ptr [0x772400]
0x006B0355  mov      dword ptr [ecx + 0x1bc], eax
0x006B035B  mov      byte ptr [ecx + 0x59d], 1
0x006B0362  mov      byte ptr [ecx + 0x5c1], 0
0x006B0369  mov      byte ptr [ebp - 4], 0x2e
0x006B036D  test     esi, esi
0x006B036F  je       0x6b037d
0x006B0371  add      dword ptr [esi], -1
0x006B0374  jne      0x6b037d
0x006B0376  mov      ecx, esi
0x006B0378  call     0x6ba940
0x006B037D  mov      ecx, dword ptr [0xca7d5c]
0x006B0383  shl      ecx, 6
0x006B0386  add      ecx, 0x773650
0x006B038C  call     0x43fd30
0x006B0391  mov      eax, dword ptr [0xca7d60]
0x006B0396  cmp      eax, dword ptr [edi + 4]
0x006B039C  jg       0x6b1800
0x006B03A2  push     0xca7d64
0x006B03A7  lea      ecx, [ebp - 0x148]
0x006B03AD  call     0x405af0
0x006B03B2  mov      byte ptr [ebp - 4], 0x2f
0x006B03B6  call     dword ptr [0x715164]
0x006B03BC  mov      eax, dword ptr [ebp - 0x148]
0x006B03C2  mov      ecx, dword ptr [eax]
0x006B03C4  shl      ecx, 6
0x006B03C7  add      ecx, 0x773650
0x006B03CD  call     0x43fd30
0x006B03D2  push     0x7d0
0x006B03D7  call     dword ptr [0x7152e0]


======== VA 0x006B0333 (file 0x2AF733) ========
0x006B02BB  push     ebx
0x006B02BC  jno      0x6b02be
0x006B02BE  mov      eax, dword ptr [ebp - 0x148]
0x006B02C4  mov      byte ptr [eax + 0x18], 0
0x006B02C8  mov      dword ptr [eax + 0x1c], 0
0x006B02CF  mov      dword ptr [eax + 0x20], 0
0x006B02D6  jmp      0x6b02da
0x006B02D8  xor      eax, eax
0x006B02DA  mov      dword ptr [0x772404], eax
0x006B02DF  mov      eax, dword ptr [ebp - 0x178]
0x006B02E5  add      eax, 0xc
0x006B02E8  push     eax
0x006B02E9  push     ecx
0x006B02EA  mov      ecx, esp
0x006B02EC  mov      dword ptr [ebp - 0x164], eax
0x006B02F2  push     0x72f314
0x006B02F7  call     0x6b8fb0
0x006B02FC  call     0x55c350
0x006B0301  push     ecx
0x006B0302  mov      ecx, esp
0x006B0304  push     0x735b14
0x006B0309  call     0x6b8fb0
0x006B030E  call     0x444fc0
0x006B0313  mov      ecx, dword ptr [0x772400]
0x006B0319  push     ecx
0x006B031A  mov      dword ptr [ecx + 0x1b4], eax
0x006B0320  mov      ecx, esp
0x006B0322  push     0x735b1c
0x006B0327  call     0x6b8fb0
0x006B032C  call     0x444fc0
0x006B0331  mov      ecx, dword ptr [0x772400]
0x006B0337  push     ecx
0x006B0338  mov      dword ptr [ecx + 0x1b8], eax
0x006B033E  mov      ecx, esp
0x006B0340  push     0x735b24
0x006B0345  call     0x6b8fb0
0x006B034A  call     0x444fc0
0x006B034F  mov      ecx, dword ptr [0x772400]
0x006B0355  mov      dword ptr [ecx + 0x1bc], eax
0x006B035B  mov      byte ptr [ecx + 0x59d], 1
0x006B0362  mov      byte ptr [ecx + 0x5c1], 0
0x006B0369  mov      byte ptr [ebp - 4], 0x2e
0x006B036D  test     esi, esi
0x006B036F  je       0x6b037d
0x006B0371  add      dword ptr [esi], -1
0x006B0374  jne      0x6b037d
0x006B0376  mov      ecx, esi
0x006B0378  call     0x6ba940
0x006B037D  mov      ecx, dword ptr [0xca7d5c]
0x006B0383  shl      ecx, 6
0x006B0386  add      ecx, 0x773650
0x006B038C  call     0x43fd30
0x006B0391  mov      eax, dword ptr [0xca7d60]
0x006B0396  cmp      eax, dword ptr [edi + 4]
0x006B039C  jg       0x6b1800
0x006B03A2  push     0xca7d64
0x006B03A7  lea      ecx, [ebp - 0x148]
0x006B03AD  call     0x405af0
0x006B03B2  mov      byte ptr [ebp - 4], 0x2f
0x006B03B6  call     dword ptr [0x715164]
0x006B03BC  mov      eax, dword ptr [ebp - 0x148]
0x006B03C2  mov      ecx, dword ptr [eax]
0x006B03C4  shl      ecx, 6
0x006B03C7  add      ecx, 0x773650
0x006B03CD  call     0x43fd30
0x006B03D2  push     0x7d0
0x006B03D7  call     dword ptr [0x7152e0]
0x006B03DD  mov      eax, dword ptr [0xca7d68]
0x006B03E2  cmp      eax, dword ptr [edi + 4]
0x006B03E8  jg       0x6b1853
0x006B03EE  push     0xca7d6c
0x006B03F3  lea      ecx, [ebp - 0x15c]
0x006B03F9  .byte    0xe8
0x006B03FA  .byte    0xf2


======== VA 0x006B0351 (file 0x2AF751) ========
0x006B02D9  shl      byte ptr [ebx + 0x772404], 0x8b
0x006B02E0  test     dword ptr [eax - 0x7c000002], ecx
0x006B02E6  ror      byte ptr [eax + edx*2], 0x51
0x006B02EA  mov      ecx, esp
0x006B02EC  mov      dword ptr [ebp - 0x164], eax
0x006B02F2  push     0x72f314
0x006B02F7  call     0x6b8fb0
0x006B02FC  call     0x55c350
0x006B0301  push     ecx
0x006B0302  mov      ecx, esp
0x006B0304  push     0x735b14
0x006B0309  call     0x6b8fb0
0x006B030E  call     0x444fc0
0x006B0313  mov      ecx, dword ptr [0x772400]
0x006B0319  push     ecx
0x006B031A  mov      dword ptr [ecx + 0x1b4], eax
0x006B0320  mov      ecx, esp
0x006B0322  push     0x735b1c
0x006B0327  call     0x6b8fb0
0x006B032C  call     0x444fc0
0x006B0331  mov      ecx, dword ptr [0x772400]
0x006B0337  push     ecx
0x006B0338  mov      dword ptr [ecx + 0x1b8], eax
0x006B033E  mov      ecx, esp
0x006B0340  push     0x735b24
0x006B0345  call     0x6b8fb0
0x006B034A  call     0x444fc0
0x006B034F  mov      ecx, dword ptr [0x772400]
0x006B0355  mov      dword ptr [ecx + 0x1bc], eax
0x006B035B  mov      byte ptr [ecx + 0x59d], 1
0x006B0362  mov      byte ptr [ecx + 0x5c1], 0
0x006B0369  mov      byte ptr [ebp - 4], 0x2e
0x006B036D  test     esi, esi
0x006B036F  je       0x6b037d
0x006B0371  add      dword ptr [esi], -1
0x006B0374  jne      0x6b037d
0x006B0376  mov      ecx, esi
0x006B0378  call     0x6ba940
0x006B037D  mov      ecx, dword ptr [0xca7d5c]
0x006B0383  shl      ecx, 6
0x006B0386  add      ecx, 0x773650
0x006B038C  call     0x43fd30
0x006B0391  mov      eax, dword ptr [0xca7d60]
0x006B0396  cmp      eax, dword ptr [edi + 4]
0x006B039C  jg       0x6b1800
0x006B03A2  push     0xca7d64
0x006B03A7  lea      ecx, [ebp - 0x148]
0x006B03AD  call     0x405af0
0x006B03B2  mov      byte ptr [ebp - 4], 0x2f
0x006B03B6  call     dword ptr [0x715164]
0x006B03BC  mov      eax, dword ptr [ebp - 0x148]
0x006B03C2  mov      ecx, dword ptr [eax]
0x006B03C4  shl      ecx, 6
0x006B03C7  add      ecx, 0x773650
0x006B03CD  call     0x43fd30
0x006B03D2  push     0x7d0
0x006B03D7  call     dword ptr [0x7152e0]
0x006B03DD  mov      eax, dword ptr [0xca7d68]
0x006B03E2  cmp      eax, dword ptr [edi + 4]
0x006B03E8  jg       0x6b1853
0x006B03EE  push     0xca7d6c
0x006B03F3  lea      ecx, [ebp - 0x15c]
0x006B03F9  call     0x405af0
0x006B03FE  push     0x2aa
0x006B0403  mov      edx, 0x73580c
0x006B0408  mov      byte ptr [ebp - 4], 0x30
0x006B040C  mov      ecx, 0xb8
0x006B0411  call     0x6ba810
0x006B0416  mov      edi, eax
0x006B0418  .byte    0x83


======== VA 0x006B04FC (file 0x2AF8FC) ========
0x006B0484  add      eax, 0x858b0000
0x006B0489  mov      dh, bh
0x006B048B  .byte    0xff
0x006B048C  inc      dword ptr [eax + 0xa4b8]
0x006B0492  add      byte ptr [eax], al
0x006B0494  je       0x6b049d
0x006B0496  mov      eax, dword ptr [edi]
0x006B0498  mov      ecx, edi
0x006B049A  call     dword ptr [eax + 8]
0x006B049D  push     0x2b0
0x006B04A2  mov      edx, 0x73580c
0x006B04A7  mov      ecx, 0x19f30
0x006B04AC  call     0x6ba810
0x006B04B1  add      esp, 4
0x006B04B4  mov      dword ptr [ebp - 0x160], eax
0x006B04BA  mov      byte ptr [ebp - 4], 0x31
0x006B04BE  test     eax, eax
0x006B04C0  je       0x6b04cb
0x006B04C2  mov      ecx, eax
0x006B04C4  call     0x464780
0x006B04C9  jmp      0x6b04cd
0x006B04CB  xor      eax, eax
0x006B04CD  push     ecx
0x006B04CE  mov      byte ptr [ebp - 4], 0x30
0x006B04D2  mov      ecx, esp
0x006B04D4  mov      dword ptr [ebp - 0x160], esp
0x006B04DA  push     0x735a44
0x006B04DF  mov      dword ptr [0x76a338], eax
0x006B04E4  call     0x6b8fb0
0x006B04E9  push     ecx
0x006B04EA  mov      ecx, esp
0x006B04EC  mov      byte ptr [ebp - 4], 0x32
0x006B04F0  push     0x735a2c
0x006B04F5  call     0x6b8fb0
0x006B04FA  mov      ecx, dword ptr [0x772400]
0x006B0500  lea      ecx, [ecx + 0xa05c]
0x006B0506  call     0x6bfc00
0x006B050B  movsd    xmm2, qword ptr [ebp - 0x188]
0x006B0513  mov      ecx, eax
0x006B0515  mov      byte ptr [ebp - 4], 0x30
0x006B0519  call     0x6bee00
0x006B051E  cvttsd2si edi, xmm0
0x006B0522  cmp      edi, 1
0x006B0525  sete     byte ptr [ebp - 0x18c]
0x006B052C  call     dword ptr [0x7150d4]
0x006B0532  mov      esi, eax
0x006B0534  test     edi, edi
0x006B0536  mov      eax, 2
0x006B053B  mov      ecx, esi
0x006B053D  cmove    edi, eax
0x006B0540  push     edi
0x006B0541  mov      dword ptr [ebp - 0x154], edi
0x006B0547  call     dword ptr [0x715168]
0x006B054D  mov      ecx, esi
0x006B054F  call     dword ptr [0x7150ac]
0x006B0555  mov      ecx, esi
0x006B0557  call     dword ptr [0x715054]
0x006B055D  call     dword ptr [0x7150b0]
0x006B0563  push     ecx
0x006B0564  mov      ecx, esp
0x006B0566  mov      dword ptr [ebp - 0x160], esp
0x006B056C  push     0x735a34
0x006B0571  mov      dword ptr [ebp - 0x150], eax
0x006B0577  call     0x6b8fb0
0x006B057C  push     ecx
0x006B057D  mov      ecx, esp
0x006B057F  mov      byte ptr [ebp - 4], 0x33
0x006B0583  push     0x735a2c
0x006B0588  call     0x6b8fb0
0x006B058D  mov      ecx, dword ptr [0x772400]
0x006B0593  lea      ecx, [ecx + 0xa05c]
0x006B0599  call     0x6bfc00
0x006B059E  movsd    xmm2, qword ptr [ebp - 0x170]
0x006B05A6  mov      ecx, eax
0x006B05A8  mov      byte ptr [ebp - 4], 0x30
0x006B05AC  call     0x6bee00
0x006B05B1  cvtsd2ss xmm0, xmm0
0x006B05B5  movss    dword ptr [ebp - 0x148], xmm0
0x006B05BD  fld      dword ptr [ebp - 0x148]
0x006B05C3  .byte    0x8d


======== VA 0x006B058F (file 0x2AF98F) ========
0x006B0517  cld      
0x006B0518  xor      al, ch
0x006B051A  loop     0x6b0504
0x006B051C  add      byte ptr [eax], al
0x006B051E  cvttsd2si edi, xmm0
0x006B0522  cmp      edi, 1
0x006B0525  sete     byte ptr [ebp - 0x18c]
0x006B052C  call     dword ptr [0x7150d4]
0x006B0532  mov      esi, eax
0x006B0534  test     edi, edi
0x006B0536  mov      eax, 2
0x006B053B  mov      ecx, esi
0x006B053D  cmove    edi, eax
0x006B0540  push     edi
0x006B0541  mov      dword ptr [ebp - 0x154], edi
0x006B0547  call     dword ptr [0x715168]
0x006B054D  mov      ecx, esi
0x006B054F  call     dword ptr [0x7150ac]
0x006B0555  mov      ecx, esi
0x006B0557  call     dword ptr [0x715054]
0x006B055D  call     dword ptr [0x7150b0]
0x006B0563  push     ecx
0x006B0564  mov      ecx, esp
0x006B0566  mov      dword ptr [ebp - 0x160], esp
0x006B056C  push     0x735a34
0x006B0571  mov      dword ptr [ebp - 0x150], eax
0x006B0577  call     0x6b8fb0
0x006B057C  push     ecx
0x006B057D  mov      ecx, esp
0x006B057F  mov      byte ptr [ebp - 4], 0x33
0x006B0583  push     0x735a2c
0x006B0588  call     0x6b8fb0
0x006B058D  mov      ecx, dword ptr [0x772400]
0x006B0593  lea      ecx, [ecx + 0xa05c]
0x006B0599  call     0x6bfc00
0x006B059E  movsd    xmm2, qword ptr [ebp - 0x170]
0x006B05A6  mov      ecx, eax
0x006B05A8  mov      byte ptr [ebp - 4], 0x30
0x006B05AC  call     0x6bee00
0x006B05B1  cvtsd2ss xmm0, xmm0
0x006B05B5  movss    dword ptr [ebp - 0x148], xmm0
0x006B05BD  fld      dword ptr [ebp - 0x148]
0x006B05C3  lea      edx, [0x772dd8]
0x006B05C9  fistp    dword ptr [edx]
0x006B05CB  mov      eax, dword ptr [0x772dd8]
0x006B05D0  push     ecx
0x006B05D1  mov      ecx, esp
0x006B05D3  mov      dword ptr [ebp - 0x160], esp
0x006B05D9  push     0x735a3c
0x006B05DE  mov      dword ptr [ebp - 0x180], eax
0x006B05E4  call     0x6b8fb0
0x006B05E9  push     ecx
0x006B05EA  mov      ecx, esp
0x006B05EC  mov      byte ptr [ebp - 4], 0x34
0x006B05F0  push     0x735a2c
0x006B05F5  call     0x6b8fb0
0x006B05FA  mov      ecx, dword ptr [0x772400]
0x006B0600  lea      ecx, [ecx + 0xa05c]
0x006B0606  call     0x6bfc00
0x006B060B  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006B0613  mov      ecx, eax
0x006B0615  mov      byte ptr [ebp - 4], 0x30
0x006B0619  call     0x6bee00
0x006B061E  cvtsd2ss xmm0, xmm0
0x006B0622  movss    dword ptr [ebp - 0x148], xmm0
0x006B062A  fld      dword ptr [ebp - 0x148]
0x006B0630  lea      edx, [0x772dd8]
0x006B0636  fistp    dword ptr [edx]
0x006B0638  mov      eax, dword ptr [0x772dd8]
0x006B063D  push     ecx
0x006B063E  mov      ecx, esp
0x006B0640  mov      dword ptr [ebp - 0x160], esp
0x006B0646  push     0x735b70
0x006B064B  mov      dword ptr [ebp - 0x17c], eax
0x006B0651  call     0x6b8fb0
0x006B0656  push     ecx


======== VA 0x006B05FC (file 0x2AF9FC) ========
0x006B0584  sub      al, 0x5a
0x006B0586  jae      0x6b0588
0x006B0588  call     0x6b8fb0
0x006B058D  mov      ecx, dword ptr [0x772400]
0x006B0593  lea      ecx, [ecx + 0xa05c]
0x006B0599  call     0x6bfc00
0x006B059E  movsd    xmm2, qword ptr [ebp - 0x170]
0x006B05A6  mov      ecx, eax
0x006B05A8  mov      byte ptr [ebp - 4], 0x30
0x006B05AC  call     0x6bee00
0x006B05B1  cvtsd2ss xmm0, xmm0
0x006B05B5  movss    dword ptr [ebp - 0x148], xmm0
0x006B05BD  fld      dword ptr [ebp - 0x148]
0x006B05C3  lea      edx, [0x772dd8]
0x006B05C9  fistp    dword ptr [edx]
0x006B05CB  mov      eax, dword ptr [0x772dd8]
0x006B05D0  push     ecx
0x006B05D1  mov      ecx, esp
0x006B05D3  mov      dword ptr [ebp - 0x160], esp
0x006B05D9  push     0x735a3c
0x006B05DE  mov      dword ptr [ebp - 0x180], eax
0x006B05E4  call     0x6b8fb0
0x006B05E9  push     ecx
0x006B05EA  mov      ecx, esp
0x006B05EC  mov      byte ptr [ebp - 4], 0x34
0x006B05F0  push     0x735a2c
0x006B05F5  call     0x6b8fb0
0x006B05FA  mov      ecx, dword ptr [0x772400]
0x006B0600  lea      ecx, [ecx + 0xa05c]
0x006B0606  call     0x6bfc00
0x006B060B  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006B0613  mov      ecx, eax
0x006B0615  mov      byte ptr [ebp - 4], 0x30
0x006B0619  call     0x6bee00
0x006B061E  cvtsd2ss xmm0, xmm0
0x006B0622  movss    dword ptr [ebp - 0x148], xmm0
0x006B062A  fld      dword ptr [ebp - 0x148]
0x006B0630  lea      edx, [0x772dd8]
0x006B0636  fistp    dword ptr [edx]
0x006B0638  mov      eax, dword ptr [0x772dd8]
0x006B063D  push     ecx
0x006B063E  mov      ecx, esp
0x006B0640  mov      dword ptr [ebp - 0x160], esp
0x006B0646  push     0x735b70
0x006B064B  mov      dword ptr [ebp - 0x17c], eax
0x006B0651  call     0x6b8fb0
0x006B0656  push     ecx
0x006B0657  mov      ecx, esp
0x006B0659  mov      byte ptr [ebp - 4], 0x35
0x006B065D  push     0x735a2c
0x006B0662  call     0x6b8fb0
0x006B0667  mov      ecx, dword ptr [0x772400]
0x006B066D  lea      ecx, [ecx + 0xa05c]
0x006B0673  call     0x6bfc00
0x006B0678  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B0680  mov      ecx, eax
0x006B0682  mov      byte ptr [ebp - 4], 0x30
0x006B0686  call     0x6bee00
0x006B068B  cvtsd2ss xmm0, xmm0
0x006B068F  movss    dword ptr [ebp - 0x148], xmm0
0x006B0697  fld      dword ptr [ebp - 0x148]
0x006B069D  lea      edx, [0x772dd8]
0x006B06A3  fistp    dword ptr [edx]
0x006B06A5  mov      eax, dword ptr [0x772dd8]
0x006B06AA  push     ecx
0x006B06AB  mov      ecx, esp
0x006B06AD  mov      dword ptr [ebp - 0x160], esp
0x006B06B3  push     0x735b80
0x006B06B8  mov      dword ptr [ebp - 0x158], eax
0x006B06BE  call     0x6b8fb0
0x006B06C3  push     ecx


======== VA 0x006B0669 (file 0x2AFA69) ========
0x006B05F1  sub      al, 0x5a
0x006B05F3  jae      0x6b05f5
0x006B05F5  call     0x6b8fb0
0x006B05FA  mov      ecx, dword ptr [0x772400]
0x006B0600  lea      ecx, [ecx + 0xa05c]
0x006B0606  call     0x6bfc00
0x006B060B  movsd    xmm2, qword ptr [ebp - 0x1a8]
0x006B0613  mov      ecx, eax
0x006B0615  mov      byte ptr [ebp - 4], 0x30
0x006B0619  call     0x6bee00
0x006B061E  cvtsd2ss xmm0, xmm0
0x006B0622  movss    dword ptr [ebp - 0x148], xmm0
0x006B062A  fld      dword ptr [ebp - 0x148]
0x006B0630  lea      edx, [0x772dd8]
0x006B0636  fistp    dword ptr [edx]
0x006B0638  mov      eax, dword ptr [0x772dd8]
0x006B063D  push     ecx
0x006B063E  mov      ecx, esp
0x006B0640  mov      dword ptr [ebp - 0x160], esp
0x006B0646  push     0x735b70
0x006B064B  mov      dword ptr [ebp - 0x17c], eax
0x006B0651  call     0x6b8fb0
0x006B0656  push     ecx
0x006B0657  mov      ecx, esp
0x006B0659  mov      byte ptr [ebp - 4], 0x35
0x006B065D  push     0x735a2c
0x006B0662  call     0x6b8fb0
0x006B0667  mov      ecx, dword ptr [0x772400]
0x006B066D  lea      ecx, [ecx + 0xa05c]
0x006B0673  call     0x6bfc00
0x006B0678  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B0680  mov      ecx, eax
0x006B0682  mov      byte ptr [ebp - 4], 0x30
0x006B0686  call     0x6bee00
0x006B068B  cvtsd2ss xmm0, xmm0
0x006B068F  movss    dword ptr [ebp - 0x148], xmm0
0x006B0697  fld      dword ptr [ebp - 0x148]
0x006B069D  lea      edx, [0x772dd8]
0x006B06A3  fistp    dword ptr [edx]
0x006B06A5  mov      eax, dword ptr [0x772dd8]
0x006B06AA  push     ecx
0x006B06AB  mov      ecx, esp
0x006B06AD  mov      dword ptr [ebp - 0x160], esp
0x006B06B3  push     0x735b80
0x006B06B8  mov      dword ptr [ebp - 0x158], eax
0x006B06BE  call     0x6b8fb0
0x006B06C3  push     ecx
0x006B06C4  mov      ecx, esp
0x006B06C6  mov      byte ptr [ebp - 4], 0x36
0x006B06CA  push     0x735a2c
0x006B06CF  call     0x6b8fb0
0x006B06D4  mov      ecx, dword ptr [0x772400]
0x006B06DA  lea      ecx, [ecx + 0xa05c]
0x006B06E0  call     0x6bfc00
0x006B06E5  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B06ED  mov      ecx, eax
0x006B06EF  mov      byte ptr [ebp - 4], 0x30
0x006B06F3  call     0x6bee00
0x006B06F8  cvtsd2ss xmm0, xmm0
0x006B06FC  movss    dword ptr [ebp - 0x148], xmm0
0x006B0704  fld      dword ptr [ebp - 0x148]
0x006B070A  lea      edx, [0x772dd8]
0x006B0710  fistp    dword ptr [edx]
0x006B0712  mov      eax, dword ptr [0x772dd8]
0x006B0717  push     ecx
0x006B0718  mov      ecx, esp
0x006B071A  mov      dword ptr [ebp - 0x160], esp
0x006B0720  push     0x735b8c
0x006B0725  mov      dword ptr [ebp - 0x16c], eax
0x006B072B  call     0x6b8fb0
0x006B0730  push     ecx


======== VA 0x006B06D6 (file 0x2AFAD6) ========
0x006B065E  sub      al, 0x5a
0x006B0660  jae      0x6b0662
0x006B0662  call     0x6b8fb0
0x006B0667  mov      ecx, dword ptr [0x772400]
0x006B066D  lea      ecx, [ecx + 0xa05c]
0x006B0673  call     0x6bfc00
0x006B0678  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B0680  mov      ecx, eax
0x006B0682  mov      byte ptr [ebp - 4], 0x30
0x006B0686  call     0x6bee00
0x006B068B  cvtsd2ss xmm0, xmm0
0x006B068F  movss    dword ptr [ebp - 0x148], xmm0
0x006B0697  fld      dword ptr [ebp - 0x148]
0x006B069D  lea      edx, [0x772dd8]
0x006B06A3  fistp    dword ptr [edx]
0x006B06A5  mov      eax, dword ptr [0x772dd8]
0x006B06AA  push     ecx
0x006B06AB  mov      ecx, esp
0x006B06AD  mov      dword ptr [ebp - 0x160], esp
0x006B06B3  push     0x735b80
0x006B06B8  mov      dword ptr [ebp - 0x158], eax
0x006B06BE  call     0x6b8fb0
0x006B06C3  push     ecx
0x006B06C4  mov      ecx, esp
0x006B06C6  mov      byte ptr [ebp - 4], 0x36
0x006B06CA  push     0x735a2c
0x006B06CF  call     0x6b8fb0
0x006B06D4  mov      ecx, dword ptr [0x772400]
0x006B06DA  lea      ecx, [ecx + 0xa05c]
0x006B06E0  call     0x6bfc00
0x006B06E5  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B06ED  mov      ecx, eax
0x006B06EF  mov      byte ptr [ebp - 4], 0x30
0x006B06F3  call     0x6bee00
0x006B06F8  cvtsd2ss xmm0, xmm0
0x006B06FC  movss    dword ptr [ebp - 0x148], xmm0
0x006B0704  fld      dword ptr [ebp - 0x148]
0x006B070A  lea      edx, [0x772dd8]
0x006B0710  fistp    dword ptr [edx]
0x006B0712  mov      eax, dword ptr [0x772dd8]
0x006B0717  push     ecx
0x006B0718  mov      ecx, esp
0x006B071A  mov      dword ptr [ebp - 0x160], esp
0x006B0720  push     0x735b8c
0x006B0725  mov      dword ptr [ebp - 0x16c], eax
0x006B072B  call     0x6b8fb0
0x006B0730  push     ecx
0x006B0731  mov      ecx, esp
0x006B0733  mov      byte ptr [ebp - 4], 0x37
0x006B0737  push     0x735a2c
0x006B073C  call     0x6b8fb0
0x006B0741  mov      ecx, dword ptr [0x772400]
0x006B0747  lea      ecx, [ecx + 0xa05c]
0x006B074D  call     0x6bfc00
0x006B0752  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B075A  mov      ecx, eax
0x006B075C  mov      byte ptr [ebp - 4], 0x30
0x006B0760  call     0x6bee00
0x006B0765  cvtsd2ss xmm0, xmm0
0x006B0769  movss    dword ptr [ebp - 0x148], xmm0
0x006B0771  fld      dword ptr [ebp - 0x148]
0x006B0777  lea      edx, [0x772dd8]
0x006B077D  fistp    dword ptr [edx]
0x006B077F  mov      edi, dword ptr [0x772dd8]
0x006B0785  push     ecx
0x006B0786  mov      ecx, esp
0x006B0788  mov      dword ptr [ebp - 0x160], esp
0x006B078E  push     0x735b98
0x006B0793  call     0x6b8fb0
0x006B0798  push     ecx
0x006B0799  mov      ecx, esp
0x006B079B  .byte    0xc6
0x006B079C  inc      ebp
0x006B079D  cld      


======== VA 0x006B0743 (file 0x2AFB43) ========
0x006B06CB  sub      al, 0x5a
0x006B06CD  jae      0x6b06cf
0x006B06CF  call     0x6b8fb0
0x006B06D4  mov      ecx, dword ptr [0x772400]
0x006B06DA  lea      ecx, [ecx + 0xa05c]
0x006B06E0  call     0x6bfc00
0x006B06E5  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B06ED  mov      ecx, eax
0x006B06EF  mov      byte ptr [ebp - 4], 0x30
0x006B06F3  call     0x6bee00
0x006B06F8  cvtsd2ss xmm0, xmm0
0x006B06FC  movss    dword ptr [ebp - 0x148], xmm0
0x006B0704  fld      dword ptr [ebp - 0x148]
0x006B070A  lea      edx, [0x772dd8]
0x006B0710  fistp    dword ptr [edx]
0x006B0712  mov      eax, dword ptr [0x772dd8]
0x006B0717  push     ecx
0x006B0718  mov      ecx, esp
0x006B071A  mov      dword ptr [ebp - 0x160], esp
0x006B0720  push     0x735b8c
0x006B0725  mov      dword ptr [ebp - 0x16c], eax
0x006B072B  call     0x6b8fb0
0x006B0730  push     ecx
0x006B0731  mov      ecx, esp
0x006B0733  mov      byte ptr [ebp - 4], 0x37
0x006B0737  push     0x735a2c
0x006B073C  call     0x6b8fb0
0x006B0741  mov      ecx, dword ptr [0x772400]
0x006B0747  lea      ecx, [ecx + 0xa05c]
0x006B074D  call     0x6bfc00
0x006B0752  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B075A  mov      ecx, eax
0x006B075C  mov      byte ptr [ebp - 4], 0x30
0x006B0760  call     0x6bee00
0x006B0765  cvtsd2ss xmm0, xmm0
0x006B0769  movss    dword ptr [ebp - 0x148], xmm0
0x006B0771  fld      dword ptr [ebp - 0x148]
0x006B0777  lea      edx, [0x772dd8]
0x006B077D  fistp    dword ptr [edx]
0x006B077F  mov      edi, dword ptr [0x772dd8]
0x006B0785  push     ecx
0x006B0786  mov      ecx, esp
0x006B0788  mov      dword ptr [ebp - 0x160], esp
0x006B078E  push     0x735b98
0x006B0793  call     0x6b8fb0
0x006B0798  push     ecx
0x006B0799  mov      ecx, esp
0x006B079B  mov      byte ptr [ebp - 4], 0x38
0x006B079F  push     0x735a2c
0x006B07A4  call     0x6b8fb0
0x006B07A9  mov      ecx, dword ptr [0x772400]
0x006B07AF  lea      ecx, [ecx + 0xa05c]
0x006B07B5  call     0x6bfc00
0x006B07BA  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B07C2  mov      ecx, eax
0x006B07C4  mov      byte ptr [ebp - 4], 0x30
0x006B07C8  call     0x6bee00
0x006B07CD  cvtsd2ss xmm0, xmm0
0x006B07D1  movss    dword ptr [ebp - 0x148], xmm0
0x006B07D9  fld      dword ptr [ebp - 0x148]
0x006B07DF  lea      edx, [0x772dd8]
0x006B07E5  fistp    dword ptr [edx]
0x006B07E7  mov      esi, dword ptr [0x772dd8]
0x006B07ED  push     ecx
0x006B07EE  mov      ecx, esp
0x006B07F0  mov      dword ptr [ebp - 0x160], esp
0x006B07F6  push     0x735ba4
0x006B07FB  call     0x6b8fb0
0x006B0800  push     ecx
0x006B0801  mov      ecx, esp
0x006B0803  mov      byte ptr [ebp - 4], 0x39
0x006B0807  .byte    0x68
0x006B0808  sub      al, 0x5a
0x006B080A  .byte    0x73


======== VA 0x006B07AB (file 0x2AFBAB) ========
0x006B0733  mov      byte ptr [ebp - 4], 0x37
0x006B0737  push     0x735a2c
0x006B073C  call     0x6b8fb0
0x006B0741  mov      ecx, dword ptr [0x772400]
0x006B0747  lea      ecx, [ecx + 0xa05c]
0x006B074D  call     0x6bfc00
0x006B0752  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B075A  mov      ecx, eax
0x006B075C  mov      byte ptr [ebp - 4], 0x30
0x006B0760  call     0x6bee00
0x006B0765  cvtsd2ss xmm0, xmm0
0x006B0769  movss    dword ptr [ebp - 0x148], xmm0
0x006B0771  fld      dword ptr [ebp - 0x148]
0x006B0777  lea      edx, [0x772dd8]
0x006B077D  fistp    dword ptr [edx]
0x006B077F  mov      edi, dword ptr [0x772dd8]
0x006B0785  push     ecx
0x006B0786  mov      ecx, esp
0x006B0788  mov      dword ptr [ebp - 0x160], esp
0x006B078E  push     0x735b98
0x006B0793  call     0x6b8fb0
0x006B0798  push     ecx
0x006B0799  mov      ecx, esp
0x006B079B  mov      byte ptr [ebp - 4], 0x38
0x006B079F  push     0x735a2c
0x006B07A4  call     0x6b8fb0
0x006B07A9  mov      ecx, dword ptr [0x772400]
0x006B07AF  lea      ecx, [ecx + 0xa05c]
0x006B07B5  call     0x6bfc00
0x006B07BA  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B07C2  mov      ecx, eax
0x006B07C4  mov      byte ptr [ebp - 4], 0x30
0x006B07C8  call     0x6bee00
0x006B07CD  cvtsd2ss xmm0, xmm0
0x006B07D1  movss    dword ptr [ebp - 0x148], xmm0
0x006B07D9  fld      dword ptr [ebp - 0x148]
0x006B07DF  lea      edx, [0x772dd8]
0x006B07E5  fistp    dword ptr [edx]
0x006B07E7  mov      esi, dword ptr [0x772dd8]
0x006B07ED  push     ecx
0x006B07EE  mov      ecx, esp
0x006B07F0  mov      dword ptr [ebp - 0x160], esp
0x006B07F6  push     0x735ba4
0x006B07FB  call     0x6b8fb0
0x006B0800  push     ecx
0x006B0801  mov      ecx, esp
0x006B0803  mov      byte ptr [ebp - 4], 0x39
0x006B0807  push     0x735a2c
0x006B080C  call     0x6b8fb0
0x006B0811  mov      ecx, dword ptr [0x772400]
0x006B0817  lea      ecx, [ecx + 0xa05c]
0x006B081D  call     0x6bfc00
0x006B0822  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B082A  mov      ecx, eax
0x006B082C  mov      byte ptr [ebp - 4], 0x30
0x006B0830  call     0x6bee00
0x006B0835  cvtsd2ss xmm0, xmm0
0x006B0839  movss    dword ptr [ebp - 0x148], xmm0
0x006B0841  fld      dword ptr [ebp - 0x148]
0x006B0847  lea      edx, [0x772dd8]
0x006B084D  fistp    dword ptr [edx]
0x006B084F  mov      eax, dword ptr [ebp - 0x16c]
0x006B0855  mov      dword ptr [ebp - 0x1b0], eax
0x006B085B  add      eax, esi
0x006B085D  mov      esi, dword ptr [ebp - 0x158]
0x006B0863  push     esi
0x006B0864  mov      dword ptr [ebp - 0x1a8], eax
0x006B086A  mov      eax, dword ptr [0x772dd8]
0x006B086F  .byte    0x68
0x006B0870  mov      al, 0x5b
0x006B0872  .byte    0x73


======== VA 0x006B0813 (file 0x2AFC13) ========
0x006B079B  mov      byte ptr [ebp - 4], 0x38
0x006B079F  push     0x735a2c
0x006B07A4  call     0x6b8fb0
0x006B07A9  mov      ecx, dword ptr [0x772400]
0x006B07AF  lea      ecx, [ecx + 0xa05c]
0x006B07B5  call     0x6bfc00
0x006B07BA  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B07C2  mov      ecx, eax
0x006B07C4  mov      byte ptr [ebp - 4], 0x30
0x006B07C8  call     0x6bee00
0x006B07CD  cvtsd2ss xmm0, xmm0
0x006B07D1  movss    dword ptr [ebp - 0x148], xmm0
0x006B07D9  fld      dword ptr [ebp - 0x148]
0x006B07DF  lea      edx, [0x772dd8]
0x006B07E5  fistp    dword ptr [edx]
0x006B07E7  mov      esi, dword ptr [0x772dd8]
0x006B07ED  push     ecx
0x006B07EE  mov      ecx, esp
0x006B07F0  mov      dword ptr [ebp - 0x160], esp
0x006B07F6  push     0x735ba4
0x006B07FB  call     0x6b8fb0
0x006B0800  push     ecx
0x006B0801  mov      ecx, esp
0x006B0803  mov      byte ptr [ebp - 4], 0x39
0x006B0807  push     0x735a2c
0x006B080C  call     0x6b8fb0
0x006B0811  mov      ecx, dword ptr [0x772400]
0x006B0817  lea      ecx, [ecx + 0xa05c]
0x006B081D  call     0x6bfc00
0x006B0822  movsd    xmm2, qword ptr [ebp - 0x198]
0x006B082A  mov      ecx, eax
0x006B082C  mov      byte ptr [ebp - 4], 0x30
0x006B0830  call     0x6bee00
0x006B0835  cvtsd2ss xmm0, xmm0
0x006B0839  movss    dword ptr [ebp - 0x148], xmm0
0x006B0841  fld      dword ptr [ebp - 0x148]
0x006B0847  lea      edx, [0x772dd8]
0x006B084D  fistp    dword ptr [edx]
0x006B084F  mov      eax, dword ptr [ebp - 0x16c]
0x006B0855  mov      dword ptr [ebp - 0x1b0], eax
0x006B085B  add      eax, esi
0x006B085D  mov      esi, dword ptr [ebp - 0x158]
0x006B0863  push     esi
0x006B0864  mov      dword ptr [ebp - 0x1a8], eax
0x006B086A  mov      eax, dword ptr [0x772dd8]
0x006B086F  push     0x735bb0
0x006B0874  add      eax, edi
0x006B0876  mov      dword ptr [ebp - 0x1ac], edi
0x006B087C  push     0x40
0x006B087E  push     0xca7d70
0x006B0883  mov      dword ptr [ebp - 0x1a4], eax
0x006B0889  call     0x47eda0
0x006B088E  push     0xca7d70
0x006B0893  call     dword ptr [0x715194]
0x006B0899  movups   xmm0, xmmword ptr [ebp - 0x1b0]
0x006B08A0  add      esp, 4
0x006B08A3  mov      eax, esp
0x006B08A5  push     esi
0x006B08A6  movups   xmmword ptr [eax], xmm0
0x006B08A9  call     dword ptr [0x71516c]
0x006B08AF  mov      edi, eax
0x006B08B1  push     edi
0x006B08B2  push     0x735bc8
0x006B08B7  push     0x40
0x006B08B9  push     0xca7d70
0x006B08BE  call     0x47eda0
0x006B08C3  push     0xca7d70
0x006B08C8  call     dword ptr [0x715194]
0x006B08CE  call     dword ptr [0x715154]
0x006B08D4  push     edi
0x006B08D5  mov      esi, eax
0x006B08D7  .byte    0xff
0x006B08D8  .byte    0x15
0x006B08D9  cwde     
0x006B08DA  push     ecx


======== VA 0x006B0A40 (file 0x2AFE40) ========
0x006B09C8  push     eax
0x006B09C9  push     edi
0x006B09CA  call     dword ptr [0x715090]
0x006B09D0  push     dword ptr [ebp - 0x17c]
0x006B09D6  mov      ecx, esi
0x006B09D8  push     dword ptr [ebp - 0x180]
0x006B09DE  call     dword ptr [0x71519c]
0x006B09E4  push     dword ptr [ebp - 0x17c]
0x006B09EA  push     dword ptr [ebp - 0x180]
0x006B09F0  push     0x735c48
0x006B09F5  push     0x40
0x006B09F7  push     0xca7d70
0x006B09FC  call     0x47eda0
0x006B0A01  push     0xca7d70
0x006B0A06  call     dword ptr [0x715194]
0x006B0A0C  call     dword ptr [0x7150f4]
0x006B0A12  add      esp, 0x14
0x006B0A15  mov      dword ptr [ebp - 0x158], eax
0x006B0A1B  mov      ecx, esp
0x006B0A1D  mov      dword ptr [ebp - 0x160], esp
0x006B0A23  push     0x735c70
0x006B0A28  call     0x6b8fb0
0x006B0A2D  push     ecx
0x006B0A2E  mov      ecx, esp
0x006B0A30  mov      byte ptr [ebp - 4], 0x3a
0x006B0A34  push     0x735a2c
0x006B0A39  call     0x6b8fb0
0x006B0A3E  mov      ecx, dword ptr [0x772400]
0x006B0A44  lea      ecx, [ecx + 0xa05c]
0x006B0A4A  call     0x6bfc00
0x006B0A4F  movsd    xmm2, qword ptr [ebp - 0x188]
0x006B0A57  mov      ecx, eax
0x006B0A59  mov      byte ptr [ebp - 4], 0x30
0x006B0A5D  call     0x6bee00
0x006B0A62  cvtsd2ss xmm0, xmm0
0x006B0A66  movss    dword ptr [ebp - 0x148], xmm0
0x006B0A6E  fld      dword ptr [ebp - 0x148]
0x006B0A74  lea      edx, [0x772dd8]
0x006B0A7A  fistp    dword ptr [edx]
0x006B0A7C  mov      esi, dword ptr [0x772dd8]
0x006B0A82  push     ecx
0x006B0A83  mov      ecx, esp
0x006B0A85  mov      dword ptr [ebp - 0x160], esp
0x006B0A8B  push     0x735c80
0x006B0A90  call     0x6b8fb0
0x006B0A95  push     ecx
0x006B0A96  mov      ecx, esp
0x006B0A98  mov      byte ptr [ebp - 4], 0x3b
0x006B0A9C  push     0x735a2c
0x006B0AA1  call     0x6b8fb0
0x006B0AA6  mov      ecx, dword ptr [0x772400]
0x006B0AAC  lea      ecx, [ecx + 0xa05c]
0x006B0AB2  call     0x6bfc00
0x006B0AB7  movsd    xmm2, qword ptr [ebp - 0x188]
0x006B0ABF  mov      ecx, eax
0x006B0AC1  mov      byte ptr [ebp - 4], 0x30
0x006B0AC5  call     0x6bee00
0x006B0ACA  cvtsd2ss xmm0, xmm0
0x006B0ACE  movss    dword ptr [ebp - 0x148], xmm0
0x006B0AD6  fld      dword ptr [ebp - 0x148]
0x006B0ADC  lea      edx, [0x772dd8]
0x006B0AE2  fistp    dword ptr [edx]
0x006B0AE4  mov      ecx, dword ptr [ebp - 0x158]
0x006B0AEA  mov      edi, dword ptr [0x772dd8]
0x006B0AF0  push     esi
0x006B0AF1  mov      esi, dword ptr [0x7151a0]
0x006B0AF7  push     0
0x006B0AF9  call     esi
0x006B0AFB  push     edi
0x006B0AFC  mov      ecx, dword ptr [ebp - 0x158]
0x006B0B02  push     1
0x006B0B04  call     esi
0x006B0B06  .byte    0x8b
0x006B0B07  .byte    0x8d


======== VA 0x006B0AA8 (file 0x2AFEA8) ========
0x006B0A30  mov      byte ptr [ebp - 4], 0x3a
0x006B0A34  push     0x735a2c
0x006B0A39  call     0x6b8fb0
0x006B0A3E  mov      ecx, dword ptr [0x772400]
0x006B0A44  lea      ecx, [ecx + 0xa05c]
0x006B0A4A  call     0x6bfc00
0x006B0A4F  movsd    xmm2, qword ptr [ebp - 0x188]
0x006B0A57  mov      ecx, eax
0x006B0A59  mov      byte ptr [ebp - 4], 0x30
0x006B0A5D  call     0x6bee00
0x006B0A62  cvtsd2ss xmm0, xmm0
0x006B0A66  movss    dword ptr [ebp - 0x148], xmm0
0x006B0A6E  fld      dword ptr [ebp - 0x148]
0x006B0A74  lea      edx, [0x772dd8]
0x006B0A7A  fistp    dword ptr [edx]
0x006B0A7C  mov      esi, dword ptr [0x772dd8]
0x006B0A82  push     ecx
0x006B0A83  mov      ecx, esp
0x006B0A85  mov      dword ptr [ebp - 0x160], esp
0x006B0A8B  push     0x735c80
0x006B0A90  call     0x6b8fb0
0x006B0A95  push     ecx
0x006B0A96  mov      ecx, esp
0x006B0A98  mov      byte ptr [ebp - 4], 0x3b
0x006B0A9C  push     0x735a2c
0x006B0AA1  call     0x6b8fb0
0x006B0AA6  mov      ecx, dword ptr [0x772400]
0x006B0AAC  lea      ecx, [ecx + 0xa05c]
0x006B0AB2  call     0x6bfc00
0x006B0AB7  movsd    xmm2, qword ptr [ebp - 0x188]
0x006B0ABF  mov      ecx, eax
0x006B0AC1  mov      byte ptr [ebp - 4], 0x30
0x006B0AC5  call     0x6bee00
0x006B0ACA  cvtsd2ss xmm0, xmm0
0x006B0ACE  movss    dword ptr [ebp - 0x148], xmm0
0x006B0AD6  fld      dword ptr [ebp - 0x148]
0x006B0ADC  lea      edx, [0x772dd8]
0x006B0AE2  fistp    dword ptr [edx]
0x006B0AE4  mov      ecx, dword ptr [ebp - 0x158]
0x006B0AEA  mov      edi, dword ptr [0x772dd8]
0x006B0AF0  push     esi
0x006B0AF1  mov      esi, dword ptr [0x7151a0]
0x006B0AF7  push     0
0x006B0AF9  call     esi
0x006B0AFB  push     edi
0x006B0AFC  mov      ecx, dword ptr [ebp - 0x158]
0x006B0B02  push     1
0x006B0B04  call     esi
0x006B0B06  mov      ecx, dword ptr [ebp - 0x158]
0x006B0B0C  mov      edi, dword ptr [0x7150a4]
0x006B0B12  push     0
0x006B0B14  call     edi
0x006B0B16  mov      ecx, dword ptr [ebp - 0x158]
0x006B0B1C  mov      esi, dword ptr [0x715050]
0x006B0B22  push     0
0x006B0B24  call     esi
0x006B0B26  mov      ecx, dword ptr [ebp - 0x158]
0x006B0B2C  push     1
0x006B0B2E  call     edi
0x006B0B30  mov      ecx, dword ptr [ebp - 0x158]
0x006B0B36  push     1
0x006B0B38  call     esi
0x006B0B3A  mov      byte ptr [ebp - 4], 0
0x006B0B3E  mov      eax, dword ptr [ebp - 0x15c]
0x006B0B44  mov      ecx, dword ptr [eax]
0x006B0B46  shl      ecx, 6
0x006B0B49  add      ecx, 0x773650
0x006B0B4F  call     0x43fd30
0x006B0B54  push     0
0x006B0B56  push     0x6aeb10
0x006B0B5B  mov      byte ptr [0x77248e], 0
0x006B0B62  mov      byte ptr [0x77248d], 0
0x006B0B69  call     dword ptr [0x715444]
0x006B0B6F  .byte    0x85


======== VA 0x006B0E53 (file 0x2B0253) ========
0x006B0DDB  .byte    0xff
0x006B0DDC  call     dword ptr [ecx - 0x75]
0x006B0DDF  enter    0x1be8, 0x4c
0x006B0DE3  ljmp     0xfffe:0xb08d8bff
0x006B0DEA  inc      dword ptr [eax + eax*8 + 0xfc9b60f]
0x006B0DF1  inc      esp
0x006B0DF2  iretd    
0x006B0DF3  mov      dword ptr [ebp - 0x150], ecx
0x006B0DF9  mov      eax, dword ptr [ebp - 0x148]
0x006B0DFF  mov      ecx, dword ptr [eax]
0x006B0E01  shl      ecx, 6
0x006B0E04  add      ecx, 0x773650
0x006B0E0A  call     0x43fd30
0x006B0E0F  mov      eax, dword ptr [0xca7db8]
0x006B0E14  cmp      eax, dword ptr [esi + 4]
0x006B0E1A  jg       0x6b18f9
0x006B0E20  push     0xca7dbc
0x006B0E25  lea      ecx, [ebp - 0x148]
0x006B0E2B  call     0x405af0
0x006B0E30  lea      eax, [ebp - 0x1a0]
0x006B0E36  mov      byte ptr [ebp - 4], 0x46
0x006B0E3A  push     eax
0x006B0E3B  push     dword ptr [ebp - 0x18c]
0x006B0E41  push     dword ptr [ebp - 0x17c]
0x006B0E47  push     dword ptr [ebp - 0x180]
0x006B0E4D  call     0x464fb0
0x006B0E52  mov      eax, dword ptr [0x772400]
0x006B0E57  cmp      byte ptr [eax + 0x59a], 0
0x006B0E5E  je       0x6b0eb5
0x006B0E60  call     0x4cfea0
0x006B0E65  mov      esi, eax
0x006B0E67  push     0x724a04
0x006B0E6C  mov      ecx, esi
0x006B0E6E  call     0x4d0160
0x006B0E73  cmp      byte ptr [esi + 0x1c], 0
0x006B0E77  je       0x6b0e86
0x006B0E79  mov      ecx, dword ptr [esi + 0x18]
0x006B0E7C  mov      dword ptr [esi + 0x44], ecx
0x006B0E7F  mov      dword ptr [esi + 0x40], 1
0x006B0E86  push     0x724a04
0x006B0E8B  mov      ecx, esi
0x006B0E8D  call     0x4d02f0
0x006B0E92  mov      ecx, esi
0x006B0E94  call     0x4d03e0
0x006B0E99  mov      ecx, esi
0x006B0E9B  call     0x4d03e0
0x006B0EA0  mov      ecx, esi
0x006B0EA2  call     0x4d03e0
0x006B0EA7  mov      ecx, esi
0x006B0EA9  call     0x4d03e0
0x006B0EAE  mov      ecx, esi
0x006B0EB0  call     0x4d03e0
0x006B0EB5  call     0x4653d0
0x006B0EBA  mov      ecx, dword ptr [0x76a338]
0x006B0EC0  push     1
0x006B0EC2  push     0
0x006B0EC4  call     0x479c10
0x006B0EC9  mov      byte ptr [ebp - 4], 0x44
0x006B0ECD  mov      eax, dword ptr [ebp - 0x148]
0x006B0ED3  mov      ecx, dword ptr [eax]
0x006B0ED5  shl      ecx, 6
0x006B0ED8  add      ecx, 0x773650
0x006B0EDE  call     0x43fd30
0x006B0EE3  push     0x722354
0x006B0EE8  lea      ecx, [ebp - 0x16c]
0x006B0EEE  call     0x6b8fb0
0x006B0EF3  lea      eax, [ebp - 0x154]
0x006B0EF9  mov      byte ptr [ebp - 4], 0x47
0x006B0EFD  push     0x71ce50
0x006B0F02  push     eax
0x006B0F03  call     0x6b90d0
0x006B0F08  add      esp, 8
0x006B0F0B  lea      eax, [ebp - 0x154]
0x006B0F11  mov      byte ptr [ebp - 4], 0x48
0x006B0F15  push     eax
0x006B0F16  .byte    0x8d
0x006B0F17  .byte    0x8d
0x006B0F18  xchg     esp, eax
0x006B0F19  .byte    0xfe
0x006B0F1A  .byte    0xff


======== VA 0x006B136B (file 0x2B076B) ========
0x006B12F3  .byte    0xfe
0x006B12F4  .byte    0xff
0x006B12F5  call     dword ptr [eax - 0x18]
0x006B12F8  add      al, 0x47
0x006B12FA  ljmp     0xfffe:0xb0958bff
0x006B1301  inc      dword ptr [eax + eax*8 - 0x473549f1]
0x006B1308  add      dword ptr [eax], eax
0x006B130A  add      byte ptr [eax], al
0x006B130C  cmove    ecx, eax
0x006B130F  mov      eax, dword ptr [ebp - 0x164]
0x006B1315  mov      dword ptr [ebp - 0x150], ecx
0x006B131B  mov      ecx, dword ptr [eax]
0x006B131D  shl      ecx, 6
0x006B1320  add      ecx, 0x773650
0x006B1326  call     0x43fd30
0x006B132B  mov      eax, dword ptr [ebp - 0x18c]
0x006B1331  mov      ecx, dword ptr [eax]
0x006B1333  shl      ecx, 6
0x006B1336  add      ecx, 0x773650
0x006B133C  call     0x43fd30
0x006B1341  jmp      0x6b134a
0x006B1343  mov      byte ptr [ebp - 0x150], 1
0x006B134A  call     dword ptr [0x7152f4]
0x006B1350  mov      byte ptr [ebp - 4], 0x47
0x006B1354  mov      eax, dword ptr [ebp - 0x160]
0x006B135A  mov      ecx, dword ptr [eax]
0x006B135C  shl      ecx, 6
0x006B135F  add      ecx, 0x773650
0x006B1365  call     0x43fd30
0x006B136A  mov      eax, dword ptr [0x772400]
0x006B136F  mov      byte ptr [eax + 0x8a], 1
0x006B1376  call     dword ptr [0x7152f4]
0x006B137C  mov      ecx, dword ptr [ebp - 0x178]
0x006B1382  add      eax, 0x3e8
0x006B1387  mov      dword ptr [ecx + 0x9c], eax
0x006B138D  call     dword ptr [0x7152f4]
0x006B1393  mov      ecx, dword ptr [ebp - 0x178]
0x006B1399  add      eax, 0x32
0x006B139C  push     0x72bc38
0x006B13A1  mov      dword ptr [ecx + 0xa0], eax
0x006B13A7  lea      ecx, [ebp - 0x148]
0x006B13AD  call     0x6b8fb0
0x006B13B2  mov      byte ptr [ebp - 4], 0x4e
0x006B13B6  lea      eax, [ebp - 0x148]
0x006B13BC  mov      ecx, dword ptr [0x772400]
0x006B13C2  push     eax
0x006B13C3  lea      ecx, [ecx + 0x95dc]
0x006B13C9  call     0x5ba430
0x006B13CE  mov      byte ptr [ebp - 4], 0x4f
0x006B13D2  mov      ecx, dword ptr [ebp - 0x148]
0x006B13D8  test     ecx, ecx
0x006B13DA  je       0x6b13e6
0x006B13DC  add      dword ptr [ecx], -1
0x006B13DF  jne      0x6b13e6
0x006B13E1  call     0x6ba940
0x006B13E6  mov      byte ptr [ebp - 4], 0x47
0x006B13EA  call     0x55a800
0x006B13EF  mov      ecx, dword ptr [ebp - 0x174]
0x006B13F5  mov      eax, dword ptr [0xca7de0]
0x006B13FA  cmp      eax, dword ptr [ecx + 4]
0x006B1400  jg       0x6b1a98
0x006B1406  push     0xca7de4
0x006B140B  lea      ecx, [ebp - 0x14c]
0x006B1411  call     0x405af0
0x006B1416  mov      byte ptr [ebp - 4], 0x50
0x006B141A  cmp      dword ptr [0x76a274], 0
0x006B1421  jne      0x6b145f
0x006B1423  push     0x26
0x006B1425  mov      edx, 0x720cc8
0x006B142A  mov      ecx, 0x80
0x006B142F  .byte    0xe8
0x006B1430  .byte    0xdc
0x006B1431  xchg     ebx, eax
0x006B1432  .byte    0x00


======== VA 0x006B13BE (file 0x2B07BE) ========
0x006B1346  .byte    0xfe
0x006B1347  .byte    0xff
0x006B1348  inc      dword ptr [ecx]
0x006B134A  call     dword ptr [0x7152f4]
0x006B1350  mov      byte ptr [ebp - 4], 0x47
0x006B1354  mov      eax, dword ptr [ebp - 0x160]
0x006B135A  mov      ecx, dword ptr [eax]
0x006B135C  shl      ecx, 6
0x006B135F  add      ecx, 0x773650
0x006B1365  call     0x43fd30
0x006B136A  mov      eax, dword ptr [0x772400]
0x006B136F  mov      byte ptr [eax + 0x8a], 1
0x006B1376  call     dword ptr [0x7152f4]
0x006B137C  mov      ecx, dword ptr [ebp - 0x178]
0x006B1382  add      eax, 0x3e8
0x006B1387  mov      dword ptr [ecx + 0x9c], eax
0x006B138D  call     dword ptr [0x7152f4]
0x006B1393  mov      ecx, dword ptr [ebp - 0x178]
0x006B1399  add      eax, 0x32
0x006B139C  push     0x72bc38
0x006B13A1  mov      dword ptr [ecx + 0xa0], eax
0x006B13A7  lea      ecx, [ebp - 0x148]
0x006B13AD  call     0x6b8fb0
0x006B13B2  mov      byte ptr [ebp - 4], 0x4e
0x006B13B6  lea      eax, [ebp - 0x148]
0x006B13BC  mov      ecx, dword ptr [0x772400]
0x006B13C2  push     eax
0x006B13C3  lea      ecx, [ecx + 0x95dc]
0x006B13C9  call     0x5ba430
0x006B13CE  mov      byte ptr [ebp - 4], 0x4f
0x006B13D2  mov      ecx, dword ptr [ebp - 0x148]
0x006B13D8  test     ecx, ecx
0x006B13DA  je       0x6b13e6
0x006B13DC  add      dword ptr [ecx], -1
0x006B13DF  jne      0x6b13e6
0x006B13E1  call     0x6ba940
0x006B13E6  mov      byte ptr [ebp - 4], 0x47
0x006B13EA  call     0x55a800
0x006B13EF  mov      ecx, dword ptr [ebp - 0x174]
0x006B13F5  mov      eax, dword ptr [0xca7de0]
0x006B13FA  cmp      eax, dword ptr [ecx + 4]
0x006B1400  jg       0x6b1a98
0x006B1406  push     0xca7de4
0x006B140B  lea      ecx, [ebp - 0x14c]
0x006B1411  call     0x405af0
0x006B1416  mov      byte ptr [ebp - 4], 0x50
0x006B141A  cmp      dword ptr [0x76a274], 0
0x006B1421  jne      0x6b145f
0x006B1423  push     0x26
0x006B1425  mov      edx, 0x720cc8
0x006B142A  mov      ecx, 0x80
0x006B142F  call     0x6ba810
0x006B1434  add      esp, 4
0x006B1437  mov      dword ptr [ebp - 0x160], eax
0x006B143D  mov      byte ptr [ebp - 4], 0x51
0x006B1441  test     eax, eax
0x006B1443  je       0x6b1454
0x006B1445  mov      ecx, eax
0x006B1447  call     0x424cc0
0x006B144C  mov      eax, dword ptr [ebp - 0x160]
0x006B1452  jmp      0x6b1456
0x006B1454  xor      eax, eax
0x006B1456  mov      byte ptr [ebp - 4], 0x50
0x006B145A  mov      dword ptr [0x76a274], eax
0x006B145F  call     0x432390
0x006B1464  movss    xmm3, dword ptr [0x737330]
0x006B146C  mov      ecx, eax
0x006B146E  push     0x721474
0x006B1473  push     0x72147c
0x006B1478  mov      dword ptr [ebp - 0x154], eax
0x006B147E  call     0x432470
0x006B1483  .byte    0xf3
0x006B1484  .byte    0x0f
0x006B1485  .byte    0x10


======== VA 0x006B1619 (file 0x2B0A19) ========
0x006B15A1  add      byte ptr [ebp - 0x15f73], cl
0x006B15A7  inc      esi
0x006B15A9  inc      ebp
0x006B15AA  cld      
0x006B15AB  push     edx
0x006B15AC  call     0x6b8ed0
0x006B15B1  push     0x10
0x006B15B3  lea      ecx, [ebp - 0x148]
0x006B15B9  call     0x6b91b0
0x006B15BE  push     eax
0x006B15BF  push     0x735e10
0x006B15C4  push     0
0x006B15C6  call     dword ptr [0x71543c]
0x006B15CC  call     0x6b7a40
0x006B15D1  test     al, al
0x006B15D3  je       0x6b15fc
0x006B15D5  call     0x4cfea0
0x006B15DA  mov      esi, dword ptr [eax + 0x34]
0x006B15DD  test     esi, esi
0x006B15DF  je       0x6b15fc
0x006B15E1  mov      ecx, esi
0x006B15E3  call     0x4498b0
0x006B15E8  push     ecx
0x006B15E9  mov      ecx, esi
0x006B15EB  call     0x4cfe80
0x006B15F0  call     0x4cfea0
0x006B15F5  mov      dword ptr [eax + 0x34], 0
0x006B15FC  push     0
0x006B15FE  call     dword ptr [0x7152dc]
0x006B1604  push     0x735e44
0x006B1609  push     0x7724c0
0x006B160E  call     0x6d02c0
0x006B1613  add      esp, 8
0x006B1616  test     eax, eax
0x006B1618  mov      eax, dword ptr [0x772400]
0x006B161D  je       0x6b163b
0x006B161F  mov      ecx, dword ptr [0x77244c]
0x006B1625  mov      byte ptr [eax + 0x19], 0
0x006B1629  call     0x5c9cc0
0x006B162E  push     dword ptr [eax]
0x006B1630  call     dword ptr [0x7155bc]
0x006B1636  add      esp, 4
0x006B1639  jmp      0x6b163f
0x006B163B  mov      byte ptr [eax + 0x19], 1
0x006B163F  push     0x735e50
0x006B1644  push     0x7724c0
0x006B1649  call     0x6d02c0
0x006B164E  add      esp, 8
0x006B1651  test     eax, eax
0x006B1653  setne    byte ptr [0x767975]
0x006B165A  mov      byte ptr [ebp - 4], 0x54
0x006B165E  test     edi, edi
0x006B1660  je       0x6b166e
0x006B1662  add      dword ptr [edi], -1
0x006B1665  jne      0x6b166e
0x006B1667  mov      ecx, edi
0x006B1669  call     0x6ba940
0x006B166E  test     esi, esi
0x006B1670  je       0x6b1683
0x006B1672  dec      dword ptr [esi]
0x006B1674  cmp      dword ptr [esi], 0
0x006B1677  jg       0x6b1683
0x006B1679  push     esi
0x006B167A  call     dword ptr [0x715540]
0x006B1680  add      esp, 4
0x006B1683  mov      ecx, dword ptr [0xca7d44]
0x006B1689  shl      ecx, 6
0x006B168C  add      ecx, 0x773650
0x006B1692  call     0x43fd30
0x006B1697  mov      al, 1
0x006B1699  mov      ecx, dword ptr [ebp - 0xc]
0x006B169C  mov      dword ptr fs:[0], ecx
0x006B16A3  pop      ecx
0x006B16A4  pop      edi
0x006B16A5  pop      esi
0x006B16A6  mov      ecx, dword ptr [ebp - 0x10]
0x006B16A9  xor      ecx, ebp
0x006B16AB  call     0x6ce927
0x006B16B0  mov      esp, ebp
0x006B16B2  pop      ebp
0x006B16B3  ret      
0x006B16B4  push     0xca7d40
0x006B16B9  call     0x6cebf4
0x006B16BE  add      esp, 4
0x006B16C1  cmp      dword ptr [0xca7d40], -1
0x006B16C8  jne      0x6aeb90
0x006B16CE  mov      ecx, dword ptr [0x783650]
0x006B16D4  mov      eax, ecx
0x006B16D6  shl      eax, 6
0x006B16D9  push     0xca7d40
0x006B16DE  .byte    0x89
0x006B16DF  .byte    0x0d
0x006B16E0  inc      esp
