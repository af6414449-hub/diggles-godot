Disassembly of C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe  VA 0x004F8000 - 0x004F8500

0x004F8000  mov      dword ptr [edi + 0x1a8], 0
0x004F800A  mov      dword ptr [edi + 0x1a0], 0
0x004F8014  push     0
0x004F8016  mov      dword ptr [eax + 0x48], 0
0x004F801D  mov      ecx, dword ptr [0x772400]
0x004F8023  lea      ecx, [ecx + 0xa0c4]
0x004F8029  call     0x40b980
0x004F802E  mov      ecx, dword ptr [0x76a338]
0x004F8034  add      ecx, 0x2868
0x004F803A  push     0
0x004F803C  call     0x47de40
0x004F8041  mov      eax, dword ptr [ebp + 8]
0x004F8044  mov      eax, dword ptr [eax + 0x18]
0x004F8047  cmp      eax, dword ptr [edi + 0xf8]
0x004F804D  jne      0x4f808f
0x004F804F  mov      esi, dword ptr [edi + 0xf0]
0x004F8055  mov      esi, dword ptr [esi + 0x20]
0x004F8058  mov      dword ptr [ebp - 0x28], esi
0x004F805B  test     esi, esi
0x004F805D  je       0x4f8061
0x004F805F  inc      dword ptr [esi]
0x004F8061  mov      byte ptr [ebp - 4], 1
0x004F8065  push     ecx
0x004F8066  mov      eax, esp
0x004F8068  mov      dword ptr [eax], esi
0x004F806A  test     esi, esi
0x004F806C  je       0x4f8070
0x004F806E  inc      dword ptr [esi]
0x004F8070  mov      ecx, edi
0x004F8072  call     0x4fbc90
0x004F8077  mov      byte ptr [ebp - 4], 2
0x004F807B  test     esi, esi
0x004F807D  je       0x4f808b
0x004F807F  add      dword ptr [esi], -1
0x004F8082  jne      0x4f808b
0x004F8084  mov      ecx, esi
0x004F8086  call     0x6ba940
0x004F808B  mov      byte ptr [ebp - 4], 0
0x004F808F  mov      eax, dword ptr [ebp + 8]
0x004F8092  mov      eax, dword ptr [eax + 0x18]
0x004F8095  cmp      eax, dword ptr [edi + 0xf4]
0x004F809B  jne      0x4f80dd
0x004F809D  mov      esi, dword ptr [edi + 0xf0]
0x004F80A3  mov      esi, dword ptr [esi + 0x20]
0x004F80A6  mov      dword ptr [ebp - 0x28], esi
0x004F80A9  test     esi, esi
0x004F80AB  je       0x4f80af
0x004F80AD  inc      dword ptr [esi]
0x004F80AF  mov      byte ptr [ebp - 4], 3
0x004F80B3  push     ecx
0x004F80B4  mov      eax, esp
0x004F80B6  mov      dword ptr [eax], esi
0x004F80B8  test     esi, esi
0x004F80BA  je       0x4f80be
0x004F80BC  inc      dword ptr [esi]
0x004F80BE  mov      ecx, edi
0x004F80C0  call     0x4faec0
0x004F80C5  mov      byte ptr [ebp - 4], 4
0x004F80C9  test     esi, esi
0x004F80CB  je       0x4f80d9
0x004F80CD  add      dword ptr [esi], -1
0x004F80D0  jne      0x4f80d9
0x004F80D2  mov      ecx, esi
0x004F80D4  call     0x6ba940
0x004F80D9  mov      byte ptr [ebp - 4], 0
0x004F80DD  mov      eax, dword ptr [ebp + 8]
0x004F80E0  mov      eax, dword ptr [eax + 0x18]
0x004F80E3  cmp      eax, dword ptr [edi + 0xec]
0x004F80E9  jne      0x4f8157
0x004F80EB  mov      esi, dword ptr [edi + 0xe8]
0x004F80F1  mov      esi, dword ptr [esi + 0x20]
0x004F80F4  mov      dword ptr [ebp - 0x28], esi
0x004F80F7  test     esi, esi
0x004F80F9  je       0x4f80fd
0x004F80FB  inc      dword ptr [esi]
0x004F80FD  mov      byte ptr [ebp - 4], 5
0x004F8101  push     ecx
0x004F8102  mov      eax, esp
0x004F8104  mov      dword ptr [eax], esi
0x004F8106  test     esi, esi
0x004F8108  je       0x4f810c
0x004F810A  inc      dword ptr [esi]
0x004F810C  mov      ecx, edi
0x004F810E  call     0x4faa70
0x004F8113  mov      edi, dword ptr [0x772400]
0x004F8119  xorps    xmm0, xmm0
0x004F811C  lea      ecx, [edi + 0xa099]
0x004F8122  movsd    qword ptr [edi + 0xa088], xmm0
0x004F812A  call     0x565850
0x004F812F  call     0x43e3c0
0x004F8134  movsd    qword ptr [edi + 0xa080], xmm0
0x004F813C  mov      byte ptr [ebp - 4], 6
0x004F8140  test     esi, esi
0x004F8142  je       0x4f8150
0x004F8144  add      dword ptr [esi], -1
0x004F8147  jne      0x4f8150
0x004F8149  mov      ecx, esi
0x004F814B  call     0x6ba940
0x004F8150  mov      byte ptr [ebp - 4], 0
0x004F8154  mov      edi, dword ptr [ebp - 0x1c]
0x004F8157  mov      eax, dword ptr [ebp + 8]
0x004F815A  mov      eax, dword ptr [eax + 0x18]
0x004F815D  cmp      eax, dword ptr [edi + 0x130]
0x004F8163  jne      0x4f821d
0x004F8169  cmp      byte ptr [edi + 0x1c], 0
0x004F816D  je       0x4f817a
0x004F816F  mov      ecx, edi
0x004F8171  call     0x504ee0
0x004F8176  mov      byte ptr [edi + 0x1c], 0
0x004F817A  mov      esi, dword ptr [edi + 0x1b0]
0x004F8180  cmp      byte ptr [esi + 0x1c], 0
0x004F8184  je       0x4f8191
0x004F8186  mov      ecx, esi
0x004F8188  call     0x504ee0
0x004F818D  mov      byte ptr [esi + 0x1c], 0
0x004F8191  mov      esi, dword ptr [edi + 0x1b4]
0x004F8197  cmp      byte ptr [esi + 0x1c], 0
0x004F819B  je       0x4f81a8
0x004F819D  mov      ecx, esi
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
0x004F837B  cmp      esi, 1
0x004F837E  cmove    esi, eax
0x004F8381  call     0x501450
0x004F8386  mov      eax, dword ptr [ebp - 0x18]
0x004F8389  cmp      esi, dword ptr [eax + 0x48]
0x004F838C  je       0x4f8398
0x004F838E  mov      ecx, eax
0x004F8390  mov      dword ptr [eax + 0x48], esi
0x004F8393  call     0x504ee0
0x004F8398  mov      eax, dword ptr [edi + 0x108]
0x004F839E  xor      esi, esi
0x004F83A0  mov      dword ptr [ebp - 0x18], eax
0x004F83A3  cmp      byte ptr [eax + 0x2c], 0
0x004F83A7  je       0x4f83fb
0x004F83A9  call     0x501450
0x004F83AE  mov      ecx, dword ptr [ebp - 0x18]
0x004F83B1  cmp      dword ptr [eax + 0x8198], ecx
0x004F83B7  jne      0x4f83db
0x004F83B9  call     0x501450
0x004F83BE  cmp      dword ptr [eax + 0x81a4], esi
0x004F83C4  je       0x4f83d6
0x004F83C6  call     0x501450
0x004F83CB  mov      ecx, dword ptr [ebp - 0x18]
0x004F83CE  cmp      dword ptr [eax + 0x81a4], ecx
0x004F83D4  jne      0x4f83db
0x004F83D6  mov      esi, 1
0x004F83DB  call     0x501450
0x004F83E0  mov      ecx, dword ptr [ebp - 0x18]
0x004F83E3  cmp      dword ptr [eax + 0x819c], ecx
0x004F83E9  je       0x4f83f3
0x004F83EB  xor      eax, eax
0x004F83ED  cmp      esi, 1
0x004F83F0  cmove    esi, eax
0x004F83F3  call     0x501450
0x004F83F8  mov      eax, dword ptr [ebp - 0x18]
0x004F83FB  cmp      esi, dword ptr [eax + 0x48]
0x004F83FE  je       0x4f840a
0x004F8400  mov      ecx, eax
0x004F8402  mov      dword ptr [eax + 0x48], esi
0x004F8405  call     0x504ee0
0x004F840A  mov      eax, dword ptr [edi + 0x10c]
0x004F8410  xor      esi, esi
0x004F8412  mov      dword ptr [ebp - 0x18], eax
0x004F8415  cmp      byte ptr [eax + 0x2c], 0
0x004F8419  je       0x4f846d
0x004F841B  call     0x501450
0x004F8420  mov      ecx, dword ptr [ebp - 0x18]
0x004F8423  cmp      dword ptr [eax + 0x8198], ecx
0x004F8429  jne      0x4f844d
0x004F842B  call     0x501450
0x004F8430  cmp      dword ptr [eax + 0x81a4], esi
0x004F8436  je       0x4f8448
0x004F8438  call     0x501450
0x004F843D  mov      ecx, dword ptr [ebp - 0x18]
0x004F8440  cmp      dword ptr [eax + 0x81a4], ecx
0x004F8446  jne      0x4f844d
0x004F8448  mov      esi, 1
0x004F844D  call     0x501450
0x004F8452  mov      ecx, dword ptr [ebp - 0x18]
0x004F8455  cmp      dword ptr [eax + 0x819c], ecx
0x004F845B  je       0x4f8465
0x004F845D  xor      eax, eax
0x004F845F  cmp      esi, 1
0x004F8462  cmove    esi, eax
0x004F8465  call     0x501450
0x004F846A  mov      eax, dword ptr [ebp - 0x18]
0x004F846D  cmp      esi, dword ptr [eax + 0x48]
0x004F8470  je       0x4f847c
0x004F8472  mov      ecx, eax
0x004F8474  mov      dword ptr [eax + 0x48], esi
0x004F8477  call     0x504ee0
0x004F847C  mov      eax, dword ptr [ebp + 8]
0x004F847F  mov      eax, dword ptr [eax + 0x18]
0x004F8482  cmp      eax, dword ptr [edi + 0x104]
0x004F8488  jne      0x4f85eb
0x004F848E  mov      eax, dword ptr [edi + 0x100]
0x004F8494  xor      esi, esi
0x004F8496  mov      dword ptr [ebp - 0x18], eax
0x004F8499  cmp      byte ptr [eax + 0x2c], 0
0x004F849D  je       0x4f84f1
0x004F849F  call     0x501450
0x004F84A4  mov      ecx, dword ptr [ebp - 0x18]
0x004F84A7  cmp      dword ptr [eax + 0x8198], ecx
0x004F84AD  jne      0x4f84d1
0x004F84AF  call     0x501450
0x004F84B4  cmp      dword ptr [eax + 0x81a4], esi
0x004F84BA  je       0x4f84cc
0x004F84BC  call     0x501450
0x004F84C1  mov      ecx, dword ptr [ebp - 0x18]
0x004F84C4  cmp      dword ptr [eax + 0x81a4], ecx
0x004F84CA  jne      0x4f84d1
0x004F84CC  mov      esi, 1
0x004F84D1  call     0x501450
0x004F84D6  mov      ecx, dword ptr [ebp - 0x18]
0x004F84D9  cmp      dword ptr [eax + 0x819c], ecx
0x004F84DF  je       0x4f84e9
0x004F84E1  xor      eax, eax
0x004F84E3  cmp      esi, 1
0x004F84E6  cmove    esi, eax
0x004F84E9  call     0x501450
0x004F84EE  mov      eax, dword ptr [ebp - 0x18]
0x004F84F1  cmp      esi, dword ptr [eax + 0x48]
0x004F84F4  je       0x4f8500
0x004F84F6  mov      ecx, eax
0x004F84F8  mov      dword ptr [eax + 0x48], esi
0x004F84FB  call     0x504ee0
