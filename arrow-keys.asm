

======== candidate 0x00443EA0 - 0x00444360 ========
0x00443EA0  dec      eax
0x00443EA1  mov      dword ptr [ebp - 0x401c], eax
0x00443EA7  mov      eax, dword ptr [edi + 8]
0x00443EAA  mov      dword ptr [ebp - 0x402c], eax
0x00443EB0  cmp      eax, -1
0x00443EB3  jne      0x443ed2
0x00443EB5  lea      edx, [edi + 0xc]
0x00443EB8  lea      ecx, [edx + 1]
0x00443EBB  nop      dword ptr [eax + eax]
0x00443EC0  mov      al, byte ptr [edx]
0x00443EC2  inc      edx
0x00443EC3  test     al, al
0x00443EC5  jne      0x443ec0
0x00443EC7  sub      edx, ecx
0x00443EC9  mov      dword ptr [ebp - 0x402c], edx
0x00443ECF  mov      dword ptr [edi + 8], edx
0x00443ED2  xor      ebx, ebx
0x00443ED4  mov      edx, 0x7364b0
0x00443ED9  push     0x19
0x00443EDB  mov      dword ptr [ebp - 0x4034], ebx
0x00443EE1  lea      ecx, [ebx + 0x10]
0x00443EE4  call     0x6ba810
0x00443EE9  mov      esi, eax
0x00443EEB  add      esp, 4
0x00443EEE  mov      dword ptr [ebp - 0x4024], esi
0x00443EF4  mov      dword ptr [esi + 4], 4
0x00443EFB  mov      byte ptr [esi + 0xc], bl
0x00443EFE  mov      dword ptr [esi + 8], ebx
0x00443F01  mov      dword ptr [esi], 1
0x00443F07  mov      ecx, dword ptr [ebp - 0x402c]
0x00443F0D  mov      byte ptr [ebp - 4], 6
0x00443F11  test     ecx, ecx
0x00443F13  jle      0x4440b7
0x00443F19  nop      dword ptr [eax]
0x00443F20  cmp      byte ptr [ebx + edi + 0xc], 0x25   <<< LEFT
0x00443F25  jne      0x4440a8
0x00443F2B  lea      eax, [ecx - 1]
0x00443F2E  cmp      ebx, eax
0x00443F30  je       0x443f3d
0x00443F32  cmp      byte ptr [ebx + edi + 0xd], 0x25   <<< LEFT
0x00443F37  je       0x4440a8
0x00443F3D  mov      ecx, dword ptr [esi + 8]
0x00443F40  mov      dword ptr [ebp - 0x4028], ecx
0x00443F46  cmp      ecx, -1
0x00443F49  jne      0x443f63
0x00443F4B  lea      ecx, [esi + 0xc]
0x00443F4E  lea      edx, [ecx + 1]
0x00443F51  mov      al, byte ptr [ecx]
0x00443F53  inc      ecx
0x00443F54  test     al, al
0x00443F56  jne      0x443f51
0x00443F58  sub      ecx, edx
0x00443F5A  mov      dword ptr [ebp - 0x4028], ecx
0x00443F60  mov      dword ptr [esi + 8], ecx
0x00443F63  lea      ebx, [ecx + 1]
0x00443F66  lea      eax, [ebx + 1]
0x00443F69  push     eax
0x00443F6A  push     esi
0x00443F6B  call     0x6b8df0
0x00443F70  mov      esi, eax
0x00443F72  mov      ecx, 0x25
0x00443F77  mov      eax, dword ptr [ebp - 0x4028]
0x00443F7D  mov      dword ptr [ebp - 0x4024], esi
0x00443F83  mov      word ptr [eax + esi + 0xc], cx
0x00443F88  mov      eax, dword ptr [ebp - 0x4034]
0x00443F8E  mov      ecx, dword ptr [ebp - 0x402c]
0x00443F94  inc      eax
0x00443F95  dec      ecx
0x00443F96  mov      dword ptr [esi + 8], ebx
0x00443F99  mov      dword ptr [ebp - 0x4034], eax
0x00443F9F  cmp      eax, ecx
0x00443FA1  jg       0x444049
0x00443FA7  lea      ebx, [eax + 0xc]
0x00443FAA  add      ebx, edi
0x00443FAC  mov      edi, eax
0x00443FAE  mov      dword ptr [ebp - 0x4028], ebx
0x00443FB4  movsx    eax, byte ptr [ebx]
0x00443FB7  push     eax
0x00443FB8  call     0x6d9927
0x00443FBD  add      esp, 4
0x00443FC0  test     eax, eax
0x00443FC2  jne      0x443fd2
0x00443FC4  mov      al, byte ptr [ebx]
0x00443FC6  cmp      al, 0x2d
0x00443FC8  je       0x443fd2
0x00443FCA  cmp      al, 0x2b
0x00443FCC  je       0x443fd2
0x00443FCE  cmp      al, 0x2e
0x00443FD0  jne      0x44403d
0x00443FD2  mov      al, byte ptr [ebx]
0x00443FD4  mov      byte ptr [ebp - 0x4015], al
0x00443FDA  test     al, al
0x00443FDC  je       0x444026
0x00443FDE  mov      ebx, dword ptr [esi + 8]
0x00443FE1  cmp      ebx, -1
0x00443FE4  jne      0x443ffc
0x00443FE6  lea      ebx, [esi + 0xc]
0x00443FE9  lea      ecx, [ebx + 1]
0x00443FEC  nop      dword ptr [eax]
0x00443FF0  mov      al, byte ptr [ebx]
0x00443FF2  inc      ebx
0x00443FF3  test     al, al
0x00443FF5  jne      0x443ff0
0x00443FF7  sub      ebx, ecx
0x00443FF9  mov      dword ptr [esi + 8], ebx
0x00443FFC  lea      eax, [ebx + 2]
0x00443FFF  push     eax
0x00444000  push     esi
0x00444001  call     0x6b8df0
0x00444006  mov      esi, eax
0x00444008  mov      al, byte ptr [ebp - 0x4015]
0x0044400E  mov      dword ptr [ebp - 0x4024], esi
0x00444014  mov      byte ptr [ebx + esi + 0xc], al
0x00444018  mov      byte ptr [ebx + esi + 0xd], 0
0x0044401D  inc      dword ptr [esi + 8]
0x00444020  mov      ebx, dword ptr [ebp - 0x4028]
0x00444026  mov      eax, dword ptr [ebp - 0x402c]
0x0044402C  inc      edi
0x0044402D  inc      ebx
0x0044402E  dec      eax
0x0044402F  mov      dword ptr [ebp - 0x4028], ebx
0x00444035  cmp      edi, eax
0x00444037  jle      0x443fb4
0x0044403D  mov      dword ptr [ebp - 0x4034], edi
0x00444043  mov      edi, dword ptr [ebp - 0x4030]
0x00444049  mov      ecx, dword ptr [esi + 8]
0x0044404C  mov      dword ptr [ebp - 0x4028], ecx
0x00444052  cmp      ecx, -1
0x00444055  jne      0x444072
0x00444057  lea      ecx, [esi + 0xc]
0x0044405A  lea      edx, [ecx + 1]
0x0044405D  nop      dword ptr [eax]
0x00444060  mov      al, byte ptr [ecx]
0x00444062  inc      ecx
0x00444063  test     al, al
0x00444065  jne      0x444060
0x00444067  sub      ecx, edx
0x00444069  mov      dword ptr [ebp - 0x4028], ecx
0x0044406F  mov      dword ptr [esi + 8], ecx
0x00444072  lea      ebx, [ecx + 1]
0x00444075  lea      eax, [ebx + 1]
0x00444078  push     eax
0x00444079  push     esi
0x0044407A  call     0x6b8df0
0x0044407F  mov      esi, eax
0x00444081  mov      ecx, 0xa7
0x00444086  mov      eax, dword ptr [ebp - 0x4028]
0x0044408C  mov      dword ptr [ebp - 0x4024], esi
0x00444092  mov      word ptr [eax + esi + 0xc], cx
0x00444097  mov      ecx, dword ptr [ebp - 0x402c]
0x0044409D  mov      dword ptr [esi + 8], ebx
0x004440A0  mov      ebx, dword ptr [ebp - 0x4034]
0x004440A6  jmp      0x4440af
0x004440A8  inc      ebx
0x004440A9  mov      dword ptr [ebp - 0x4034], ebx
0x004440AF  cmp      ebx, ecx
0x004440B1  jl       0x443f20
0x004440B7  mov      eax, dword ptr [ebp - 0x4020]
0x004440BD  mov      ebx, dword ptr [ebp - 0x401c]
0x004440C3  cmp      ebx, dword ptr [eax + 4]
0x004440C6  jb       0x4440df
0x004440C8  push     0
0x004440CA  push     0
0x004440CC  push     1
0x004440CE  push     0xc000008c
0x004440D3  call     dword ptr [0x715340]
0x004440D9  mov      eax, dword ptr [ebp - 0x4020]
0x004440DF  mov      eax, dword ptr [eax]
0x004440E1  lea      ebx, [ebx + ebx*2]
0x004440E4  shl      ebx, 3
0x004440E7  add      eax, 4
0x004440EA  add      eax, ebx
0x004440EC  mov      dword ptr [ebp - 0x4030], eax
0x004440F2  mov      ecx, dword ptr [eax]
0x004440F4  mov      dword ptr [eax], esi
0x004440F6  inc      dword ptr [esi]
0x004440F8  test     ecx, ecx
0x004440FA  je       0x44410c
0x004440FC  add      dword ptr [ecx], -1
0x004440FF  jne      0x44410c
0x00444101  call     0x6ba940
0x00444106  mov      eax, dword ptr [ebp - 0x4030]
0x0044410C  mov      ecx, dword ptr [eax]
0x0044410E  mov      eax, dword ptr [esi + 8]
0x00444111  mov      dword ptr [ecx + 8], eax
0x00444114  mov      eax, dword ptr [ebp - 0x4020]
0x0044411A  mov      ecx, dword ptr [ebp - 0x401c]
0x00444120  cmp      ecx, dword ptr [eax + 4]
0x00444123  jb       0x44413c
0x00444125  push     0
0x00444127  push     0
0x00444129  push     1
0x0044412B  push     0xc000008c
0x00444130  call     dword ptr [0x715340]
0x00444136  mov      eax, dword ptr [ebp - 0x4020]
0x0044413C  mov      eax, dword ptr [eax]
0x0044413E  lea      edx, [edi + 0xc]
0x00444141  xor      ecx, ecx
0x00444143  mov      byte ptr [ebx + eax], 0
0x00444147  mov      al, byte ptr [edx]
0x00444149  test     al, al
0x0044414B  je       0x444161
0x0044414D  nop      dword ptr [eax]
0x00444150  movsx    eax, al
0x00444153  lea      ecx, [ecx + ecx*8]
0x00444156  add      ecx, eax
0x00444158  lea      edx, [edx + 1]
0x0044415B  mov      al, byte ptr [edx]
0x0044415D  test     al, al
0x0044415F  jne      0x444150
0x00444161  movzx    eax, cl
0x00444164  mov      ecx, dword ptr [ebp - 0x405c]
0x0044416A  lea      ebx, [ecx + eax*8]
0x0044416D  lea      eax, [ebp - 0x404c]
0x00444173  mov      ecx, ebx
0x00444175  push     eax
0x00444176  call     0x4406f0
0x0044417B  mov      dword ptr [ebp - 0x4030], eax
0x00444181  cmp      eax, dword ptr [ebx + 4]
0x00444184  jb       0x444197
0x00444186  push     0
0x00444188  push     0
0x0044418A  push     1
0x0044418C  push     0xc000008c
0x00444191  call     dword ptr [0x715340]
0x00444197  mov      eax, dword ptr [ebx]
0x00444199  mov      ecx, dword ptr [ebp - 0x4030]
0x0044419F  mov      edx, dword ptr [ebp - 0x401c]
0x004441A5  mov      dword ptr [eax + ecx*8 + 4], edx
0x004441A9  mov      byte ptr [ebp - 4], 7
0x004441AD  jmp      0x444889
0x004441B2  mov      ecx, dword ptr [ebp - 0x4050]
0x004441B8  lea      eax, [ebp - 0x4044]
0x004441BE  nop      
0x004441C0  mov      dl, byte ptr [eax]
0x004441C2  cmp      dl, byte ptr [ecx]
0x004441C4  jne      0x4441e0
0x004441C6  test     dl, dl
0x004441C8  je       0x4441dc
0x004441CA  mov      dl, byte ptr [eax + 1]
0x004441CD  cmp      dl, byte ptr [ecx + 1]
0x004441D0  jne      0x4441e0
0x004441D2  add      eax, 2
0x004441D5  add      ecx, 2
0x004441D8  test     dl, dl
0x004441DA  jne      0x4441c0
0x004441DC  xor      eax, eax
0x004441DE  jmp      0x4441e5
0x004441E0  sbb      eax, eax
0x004441E2  or       eax, 1
0x004441E5  test     eax, eax
0x004441E7  jne      0x44489b
0x004441ED  mov      eax, dword ptr [ebp - 0x401c]
0x004441F3  cmp      eax, -1
0x004441F6  je       0x44489b
0x004441FC  cmp      eax, 0x284
0x00444201  jne      0x444210
0x00444203  push     0x721ed8
0x00444208  call     0x43ff70
0x0044420D  add      esp, 4
0x00444210  push     0x19
0x00444212  mov      edx, 0x7364b0
0x00444217  mov      byte ptr [ebp - 0x4015], 0
0x0044421E  mov      ecx, 0x10
0x00444223  call     0x6ba810
0x00444228  mov      esi, eax
0x0044422A  add      esp, 4
0x0044422D  mov      dword ptr [ebp - 0x4034], esi
0x00444233  mov      dword ptr [esi + 4], 4
0x0044423A  mov      byte ptr [esi + 0xc], 0
0x0044423E  mov      dword ptr [esi + 8], 0
0x00444245  mov      dword ptr [esi], 1
0x0044424B  mov      byte ptr [ebp - 4], 8
0x0044424F  mov      edx, dword ptr [edi + 8]
0x00444252  mov      dword ptr [ebp - 0x4028], edx
0x00444258  cmp      edx, -1
0x0044425B  jne      0x444275
0x0044425D  lea      edx, [edi + 0xc]
0x00444260  lea      ecx, [edx + 1]
0x00444263  mov      al, byte ptr [edx]
0x00444265  inc      edx
0x00444266  test     al, al
0x00444268  jne      0x444263
0x0044426A  sub      edx, ecx
0x0044426C  mov      dword ptr [ebp - 0x4028], edx
0x00444272  mov      dword ptr [edi + 8], edx
0x00444275  or       ecx, 0xffffffff
0x00444278  cmp      edx, ecx
0x0044427A  jle      0x4446e9
0x00444280  lea      eax, [edi + 0xb]
0x00444283  lea      ebx, [edi + 0xc]
0x00444286  mov      dword ptr [ebp - 0x4038], eax
0x0044428C  mov      edi, eax
0x0044428E  nop      
0x00444290  mov      al, byte ptr [edi + 1]
0x00444293  inc      edi
0x00444294  mov      dword ptr [ebp - 0x4060], ebx
0x0044429A  inc      ebx
0x0044429B  mov      dword ptr [ebp - 0x4064], ecx
0x004442A1  inc      ecx
0x004442A2  mov      dword ptr [ebp - 0x4024], ecx
0x004442A8  mov      dword ptr [ebp - 0x4038], ebx
0x004442AE  mov      byte ptr [ebp - 0x403d], al
0x004442B4  cmp      al, 0x25   <<< LEFT
0x004442B6  jne      0x444680
0x004442BC  lea      eax, [edx - 1]
0x004442BF  cmp      ecx, eax
0x004442C1  jge      0x444684
0x004442C7  movzx    eax, byte ptr [ebx]
0x004442CA  push     eax
0x004442CB  call     0x6d998f
0x004442D0  add      esp, 4
0x004442D3  test     eax, eax
0x004442D5  jne      0x4442e0
0x004442D7  cmp      byte ptr [ebx], 0x25   <<< LEFT
0x004442DA  jne      0x444684
0x004442E0  cmp      byte ptr [ebx], 0x25   <<< LEFT
0x004442E3  jne      0x444340
0x004442E5  mov      ebx, dword ptr [esi + 8]
0x004442E8  cmp      ebx, -1
0x004442EB  jne      0x4442ff
0x004442ED  lea      ebx, [esi + 0xc]
0x004442F0  lea      ecx, [ebx + 1]
0x004442F3  mov      al, byte ptr [ebx]
0x004442F5  inc      ebx
0x004442F6  test     al, al
0x004442F8  jne      0x4442f3
0x004442FA  sub      ebx, ecx
0x004442FC  mov      dword ptr [esi + 8], ebx
0x004442FF  lea      eax, [ebx + 2]
0x00444302  push     eax
0x00444303  push     esi
0x00444304  call     0x6b8df0
0x00444309  mov      ecx, dword ptr [ebp - 0x4064]
0x0044430F  mov      esi, eax
0x00444311  mov      edx, dword ptr [ebp - 0x4028]
0x00444317  inc      edi
0x00444318  mov      dword ptr [ebp - 0x4034], esi
0x0044431E  mov      byte ptr [ebp - 0x4015], 0
0x00444325  mov      word ptr [ebx + esi + 0xc], 0x25
0x0044432C  mov      ebx, dword ptr [ebp - 0x4060]
0x00444332  inc      dword ptr [esi + 8]
0x00444335  add      ebx, 2
0x00444338  add      ecx, 2
0x0044433B  jmp      0x4446db
0x00444340  cmp      byte ptr [ebp - 0x4015], 0
0x00444347  jne      0x444552
0x0044434D  mov      ecx, dword ptr [esi + 8]
0x00444350  cmp      ecx, -1
0x00444353  jne      0x44436c
0x00444355  lea      ecx, [esi + 0xc]
0x00444358  lea      edx, [ecx + 1]
0x0044435B  nop      dword ptr [eax + eax]


======== candidate 0x004CEBC6 - 0x004CF010 ========
0x004CEBC6  add      byte ptr [ecx - 0x1137b], cl
0x004CEBCC  dec      dword ptr [edi]
0x004CEBCE  pop      ds
0x004CEBCF  add      byte ptr [edi], cl
0x004CEBD1  mov      dh, 0x84
0x004CEBD3  add      eax, 0xfffffef0
0x004CEBD8  xor      edx, edx
0x004CEBDA  imul     eax, eax, 0x29
0x004CEBDD  xor      esi, esi
0x004CEBDF  mov      dword ptr [ebp - 0x130], edx
0x004CEBE5  mov      dword ptr [ebp - 0x12c], eax
0x004CEBEB  mov      byte ptr [eax + edi], 1
0x004CEBEF  inc      edi
0x004CEBF0  add      edi, eax
0x004CEBF2  nop      dword ptr [eax]
0x004CEBF6  nop      word ptr [eax + eax]
0x004CEC00  mov      ecx, dword ptr [ebp - 0x15c]
0x004CEC06  mov      eax, dword ptr [ebp - 0x148]
0x004CEC0C  imul     ecx, edx
0x004CEC0F  add      ecx, dword ptr [ebp - 0x114]
0x004CEC15  lea      edx, [eax + ecx*2]
0x004CEC18  add      edx, ecx
0x004CEC1A  mov      ecx, 5
0x004CEC1F  mov      dword ptr [ebp - 0x124], edx
0x004CEC25  mov      dword ptr [ebp - 0x118], ecx
0x004CEC2B  nop      dword ptr [eax + eax]
0x004CEC30  cmp      byte ptr [edx], 0
0x004CEC33  jne      0x4cec90
0x004CEC35  mov      edi, dword ptr [ebp - 0x120]
0x004CEC3B  mov      eax, dword ptr [ebp - 0x12c]
0x004CEC41  add      edi, 0x25
0x004CEC44  add      edi, eax
0x004CEC46  cmp      esi, 0x27   <<< RIGHT
0x004CEC49  ja       0x4cec5d
0x004CEC4B  add      edi, esi
0x004CEC4D  mov      byte ptr [edi], 1
0x004CEC50  mov      edi, dword ptr [ebp - 0x120]
0x004CEC56  add      edi, 0x25
0x004CEC59  add      edi, eax
0x004CEC5B  jmp      0x4cecbc
0x004CEC5D  push     0
0x004CEC5F  push     0
0x004CEC61  push     1
0x004CEC63  push     0xc000008c
0x004CEC68  call     dword ptr [0x715340]
0x004CEC6E  mov      eax, dword ptr [ebp - 0x12c]
0x004CEC74  mov      edx, dword ptr [ebp - 0x124]
0x004CEC7A  mov      ecx, dword ptr [ebp - 0x118]
0x004CEC80  mov      byte ptr [edi], 1
0x004CEC83  mov      edi, dword ptr [ebp - 0x120]
0x004CEC89  add      edi, 0x25
0x004CEC8C  add      edi, eax
0x004CEC8E  jmp      0x4cecbc
0x004CEC90  cmp      esi, 0x27   <<< RIGHT
0x004CEC93  ja       0x4cec9a
0x004CEC95  lea      eax, [edi + esi]
0x004CEC98  jmp      0x4cecb9
0x004CEC9A  push     0
0x004CEC9C  push     0
0x004CEC9E  push     1
0x004CECA0  push     0xc000008c
0x004CECA5  call     dword ptr [0x715340]
0x004CECAB  mov      edx, dword ptr [ebp - 0x124]
0x004CECB1  mov      eax, edi
0x004CECB3  mov      ecx, dword ptr [ebp - 0x118]
0x004CECB9  mov      byte ptr [eax], 0
0x004CECBC  add      edx, 3
0x004CECBF  inc      esi
0x004CECC0  sub      ecx, 1
0x004CECC3  mov      dword ptr [ebp - 0x124], edx
0x004CECC9  mov      dword ptr [ebp - 0x118], ecx
0x004CECCF  jne      0x4cec30
0x004CECD5  mov      edx, dword ptr [ebp - 0x130]
0x004CECDB  inc      edx
0x004CECDC  mov      dword ptr [ebp - 0x130], edx
0x004CECE2  cmp      edx, 8
0x004CECE5  jl       0x4cec00
0x004CECEB  mov      eax, dword ptr [ebp - 0x134]
0x004CECF1  add      dword ptr [ebp - 0x114], 6
0x004CECF8  inc      eax
0x004CECF9  mov      edi, dword ptr [ebp - 0x128]
0x004CECFF  mov      dword ptr [ebp - 0x134], eax
0x004CED05  cmp      eax, dword ptr [ebp - 0x11c]
0x004CED0B  jl       0x4cebd0
0x004CED11  mov      esi, dword ptr [0x715340]
0x004CED17  mov      dword ptr [ebp - 4], 1
0x004CED1E  cmp      dword ptr [0xc3c824], 0
0x004CED25  mov      edi, dword ptr [ebp - 0x148]
0x004CED2B  mov      dword ptr [ebp - 0x114], edi
0x004CED31  jne      0x4ced48
0x004CED33  push     0xc3c78c
0x004CED38  mov      dword ptr [0xc3c824], 1
0x004CED42  call     dword ptr [0x71530c]
0x004CED48  push     0xc3c78c
0x004CED4D  call     dword ptr [0x715304]
0x004CED53  test     edi, edi
0x004CED55  je       0x4cee71
0x004CED5B  lock inc dword ptr [0xc3c818]
0x004CED62  add      edi, -0x1c
0x004CED65  xor      edx, edx
0x004CED67  mov      ecx, edi
0x004CED69  call     0x6ba730
0x004CED6E  test     eax, eax
0x004CED70  jne      0x4ced93
0x004CED72  mov      eax, dword ptr [edi + 0x14]
0x004CED75  mov      ecx, edi
0x004CED77  mov      dword ptr [ebp - 0x128], eax
0x004CED7D  add      eax, 0x1c
0x004CED80  add      eax, edi
0x004CED82  mov      edx, eax
0x004CED84  mov      dword ptr [ebp - 0x11c], eax
0x004CED8A  call     0x6ba730
0x004CED8F  test     eax, eax
0x004CED91  je       0x4ceddc
0x004CED93  mov      ecx, dword ptr [0xc3c7d4]
0x004CED99  test     ecx, ecx
0x004CED9B  je       0x4cedbd
0x004CED9D  push     eax
0x004CED9E  push     dword ptr [ebp - 0x114]
0x004CEDA4  push     0x7365ac
0x004CEDA9  push     ecx
0x004CEDAA  call     0x405ab0
0x004CEDAF  push     dword ptr [0xc3c7d4]
0x004CEDB5  call     0x6de2c7
0x004CEDBA  add      esp, 0x14
0x004CEDBD  cmp      byte ptr [0xc3c828], 0
0x004CEDC4  je       0x4cee71
0x004CEDCA  push     0
0x004CEDCC  push     0
0x004CEDCE  push     1
0x004CEDD0  push     0xc000008c
0x004CEDD5  call     esi
0x004CEDD7  jmp      0x4cee71
0x004CEDDC  mov      ecx, dword ptr [edi + 8]
0x004CEDDF  test     ecx, ecx
0x004CEDE1  je       0x4cede9
0x004CEDE3  mov      eax, dword ptr [edi + 4]
0x004CEDE6  mov      dword ptr [ecx + 4], eax
0x004CEDE9  mov      ecx, dword ptr [edi + 4]
0x004CEDEC  test     ecx, ecx
0x004CEDEE  je       0x4cedf6
0x004CEDF0  mov      eax, dword ptr [edi + 8]
0x004CEDF3  mov      dword ptr [ecx + 8], eax
0x004CEDF6  cmp      edi, dword ptr [0xc3c81c]
0x004CEDFC  jne      0x4cee06
0x004CEDFE  mov      eax, dword ptr [edi + 4]
0x004CEE01  mov      dword ptr [0xc3c81c], eax
0x004CEE06  push     dword ptr [ebp - 0x128]
0x004CEE0C  push     0xdfdfdfdf
0x004CEE11  push     dword ptr [ebp - 0x114]
0x004CEE17  call     0x6d0560
0x004CEE1C  mov      eax, dword ptr [ebp - 0x11c]
0x004CEE22  add      esp, 0xc
0x004CEE25  cmp      byte ptr [0x77248f], 0
0x004CEE2C  mov      dword ptr [edi], 0xdfdfdfdf
0x004CEE32  mov      dword ptr [edi + 0x18], 0xdfdfdfdf
0x004CEE39  mov      dword ptr [eax], 0xdfdfdfdf
0x004CEE3F  je       0x4cee68
0x004CEE41  cmp      byte ptr [0xc1c788], 0
0x004CEE48  je       0x4cee68
0x004CEE4A  mov      ecx, dword ptr [0xc3c7cc]
0x004CEE50  cmp      ecx, edi
0x004CEE52  ja       0x4cee68
0x004CEE54  mov      eax, dword ptr [0xc3c7d0]
0x004CEE59  add      eax, ecx
0x004CEE5B  cmp      eax, edi
0x004CEE5D  jbe      0x4cee68
0x004CEE5F  mov      ecx, edi
0x004CEE61  call     0x6b8c20
0x004CEE66  jmp      0x4cee71
0x004CEE68  push     edi
0x004CEE69  call     0x6df631
0x004CEE6E  add      esp, 4
0x004CEE71  push     0xc3c78c
0x004CEE76  call     dword ptr [0x715300]
0x004CEE7C  mov      ecx, dword ptr [ebp - 0xc]
0x004CEE7F  mov      dword ptr fs:[0], ecx
0x004CEE86  pop      ecx
0x004CEE87  pop      edi
0x004CEE88  pop      esi
0x004CEE89  mov      ecx, dword ptr [ebp - 0x10]
0x004CEE8C  xor      ecx, ebp
0x004CEE8E  call     0x6ce927
0x004CEE93  mov      esp, ebp
0x004CEE95  pop      ebp
0x004CEE96  ret      
0x004CEE97  int3     
0x004CEE98  int3     
0x004CEE99  int3     
0x004CEE9A  int3     
0x004CEE9B  int3     
0x004CEE9C  int3     
0x004CEE9D  int3     
0x004CEE9E  int3     
0x004CEE9F  int3     
0x004CEEA0  push     ebp
0x004CEEA1  mov      ebp, esp
0x004CEEA3  push     ecx
0x004CEEA4  mov      eax, dword ptr [ebp + 8]
0x004CEEA7  push     ebx
0x004CEEA8  mov      ebx, ecx
0x004CEEAA  mov      ecx, dword ptr [ebp + 0xc]
0x004CEEAD  push     edi
0x004CEEAE  lea      edi, [eax + eax*2]
0x004CEEB1  mov      dword ptr [ebp - 4], ebx
0x004CEEB4  add      edi, edi
0x004CEEB6  mov      eax, dword ptr [ebx]
0x004CEEB8  lea      ecx, [ecx*8 + 8]
0x004CEEBF  imul     ecx, dword ptr [ebx + 4]
0x004CEEC3  add      ecx, edi
0x004CEEC5  lea      ecx, [eax + ecx*2]
0x004CEEC8  mov      eax, dword ptr [ebp + 0x10]
0x004CEECB  cmp      eax, -1
0x004CEECE  jne      0x4cef00
0x004CEED0  mov      eax, 0xffff
0x004CEED5  mov      word ptr [ecx + 4], ax
0x004CEED9  mov      word ptr [ecx + 0xe], ax
0x004CEEDD  mov      eax, dword ptr [ebx + 4]
0x004CEEE0  pop      edi
0x004CEEE1  pop      ebx
0x004CEEE2  mov      dword ptr [ecx + eax*2 + 4], 0xffffffff
0x004CEEEA  mov      dword ptr [ecx + eax*2 + 8], 0xffffffff
0x004CEEF2  mov      dword ptr [ecx + eax*2 + 0xc], 0xffffffff
0x004CEEFA  mov      esp, ebp
0x004CEEFC  pop      ebp
0x004CEEFD  ret      0xc
0x004CEF00  test     eax, eax
0x004CEF02  mov      edx, 0x3f
0x004CEF07  push     esi
0x004CEF08  mov      esi, dword ptr [0x715340]
0x004CEF0E  cmovns   edx, eax
0x004CEF11  add      ebx, 0x24
0x004CEF14  mov      dword ptr [ebp + 8], edx
0x004CEF17  cmp      edx, 0xff
0x004CEF1D  ja       0x4cef26
0x004CEF1F  imul     eax, edx, 0x29
0x004CEF22  add      ebx, eax
0x004CEF24  jmp      0x4cef36
0x004CEF26  push     0
0x004CEF28  push     0
0x004CEF2A  push     1
0x004CEF2C  push     0xc000008c
0x004CEF31  call     esi
0x004CEF33  mov      edx, dword ptr [ebp + 8]
0x004CEF36  cmp      byte ptr [ebx], 0
0x004CEF39  je       0x4cefde
0x004CEF3F  mov      eax, dword ptr [ebp + 0xc]
0x004CEF42  mov      dword ptr [ebp + 0x10], 8
0x004CEF49  lea      ecx, [eax*8 + 2]
0x004CEF50  mov      eax, dword ptr [ebp - 4]
0x004CEF53  imul     ecx, dword ptr [eax + 4]
0x004CEF57  mov      eax, dword ptr [eax]
0x004CEF59  add      ecx, edi
0x004CEF5B  lea      eax, [eax + ecx*2]
0x004CEF5E  add      eax, 4
0x004CEF61  xor      ebx, ebx
0x004CEF63  mov      dword ptr [ebp + 0xc], eax
0x004CEF66  xor      edi, edi
0x004CEF68  cmp      edx, 0xff
0x004CEF6E  ja       0x4cef7d
0x004CEF70  mov      ecx, dword ptr [ebp - 4]
0x004CEF73  imul     esi, edx, 0x29
0x004CEF76  add      ecx, 0x24
0x004CEF79  add      esi, ecx
0x004CEF7B  jmp      0x4cef90
0x004CEF7D  push     0
0x004CEF7F  push     0
0x004CEF81  push     1
0x004CEF83  push     0xc000008c
0x004CEF88  call     esi
0x004CEF8A  mov      esi, dword ptr [ebp - 4]
0x004CEF8D  add      esi, 0x24
0x004CEF90  cmp      ebx, 0x27   <<< RIGHT
0x004CEF93  ja       0x4cef99
0x004CEF95  add      esi, ebx
0x004CEF97  jmp      0x4cefaa
0x004CEF99  push     0
0x004CEF9B  push     0
0x004CEF9D  push     1
0x004CEF9F  push     0xc000008c
0x004CEFA4  call     dword ptr [0x715340]
0x004CEFAA  mov      ecx, dword ptr [ebp + 0xc]
0x004CEFAD  inc      ebx
0x004CEFAE  cmp      byte ptr [esi + 1], 0
0x004CEFB2  je       0x4cefbd
0x004CEFB4  mov      eax, 0xffff
0x004CEFB9  mov      word ptr [ecx + edi*2], ax
0x004CEFBD  mov      edx, dword ptr [ebp + 8]
0x004CEFC0  inc      edi
0x004CEFC1  mov      esi, dword ptr [0x715340]
0x004CEFC7  cmp      edi, 5
0x004CEFCA  jl       0x4cef68
0x004CEFCC  sub      dword ptr [ebp + 0x10], 1
0x004CEFD0  mov      eax, dword ptr [ebp - 4]
0x004CEFD3  mov      eax, dword ptr [eax + 4]
0x004CEFD6  lea      ecx, [ecx + eax*2]
0x004CEFD9  mov      dword ptr [ebp + 0xc], ecx
0x004CEFDC  jne      0x4cef66
0x004CEFDE  pop      esi
0x004CEFDF  pop      edi
0x004CEFE0  pop      ebx
0x004CEFE1  mov      esp, ebp
0x004CEFE3  pop      ebp
0x004CEFE4  ret      0xc
0x004CEFE7  int3     
0x004CEFE8  int3     
0x004CEFE9  int3     
0x004CEFEA  int3     
0x004CEFEB  int3     
0x004CEFEC  int3     
0x004CEFED  int3     
0x004CEFEE  int3     
0x004CEFEF  int3     
0x004CEFF0  push     ebp
0x004CEFF1  mov      ebp, esp
0x004CEFF3  push     -1
0x004CEFF5  push     0x6feccd
0x004CEFFA  mov      eax, dword ptr fs:[0]
0x004CF000  push     eax
0x004CF001  sub      esp, 0x88
0x004CF007  push     ebx
0x004CF008  push     esi
0x004CF009  push     edi
0x004CF00A  mov      eax, dword ptr [0x76700c]
0x004CF00F  .byte    0x33


======== candidate 0x004E0BF6 - 0x004E0F47 ========
0x004E0BF6  mov      al, byte ptr [edx]
0x004E0BF8  inc      edx
0x004E0BF9  test     al, al
0x004E0BFB  jne      0x4e0bf6
0x004E0BFD  sub      edx, ecx
0x004E0BFF  mov      dword ptr [ebp - 0x474], edx
0x004E0C05  test     edx, edx
0x004E0C07  jle      0x4e3b89
0x004E0C0D  mov      eax, edx
0x004E0C0F  nop      
0x004E0C10  xor      edx, edx
0x004E0C12  mov      dword ptr [ebp - 0x45c], edx
0x004E0C18  cmp      esi, eax
0x004E0C1A  jge      0x4e3aef
0x004E0C20  movzx    eax, byte ptr [edi + esi]
0x004E0C24  push     eax
0x004E0C25  call     0x6dba9d
0x004E0C2A  add      esp, 4
0x004E0C2D  test     eax, eax
0x004E0C2F  je       0x4e0c50
0x004E0C31  mov      eax, dword ptr [ebp - 0x474]
0x004E0C37  inc      esi
0x004E0C38  mov      dword ptr [ebp - 0x470], esi
0x004E0C3E  cmp      esi, eax
0x004E0C40  jl       0x4e0c20
0x004E0C42  jmp      0x4e3ae9
0x004E0C47  nop      word ptr [eax + eax]
0x004E0C50  movzx    eax, byte ptr [edi + esi]
0x004E0C54  push     eax
0x004E0C55  call     0x6dba9d
0x004E0C5A  add      esp, 4
0x004E0C5D  test     eax, eax
0x004E0C5F  jne      0x4e3ae3
0x004E0C65  mov      cl, byte ptr [edi + esi]
0x004E0C68  cmp      cl, 0x5c
0x004E0C6B  je       0x4e0c72
0x004E0C6D  cmp      cl, 0x2f
0x004E0C70  jne      0x4e0c7e
0x004E0C72  mov      al, byte ptr [edi + esi + 1]
0x004E0C76  cmp      al, 0x28   <<< DOWN
0x004E0C78  je       0x4e0c9e
0x004E0C7A  cmp      al, 0x70
0x004E0C7C  je       0x4e0c9e
0x004E0C7E  mov      edx, dword ptr [ebp - 0x45c]
0x004E0C84  mov      byte ptr [ebp + edx - 0x410], cl
0x004E0C8B  inc      edx
0x004E0C8C  inc      esi
0x004E0C8D  mov      dword ptr [ebp - 0x45c], edx
0x004E0C93  mov      dword ptr [ebp - 0x470], esi
0x004E0C99  jmp      0x4e3acd
0x004E0C9E  mov      edx, dword ptr [ebp - 0x45c]
0x004E0CA4  test     edx, edx
0x004E0CA6  jle      0x4e0ec7
0x004E0CAC  cmp      edx, 0x400
0x004E0CB2  jae      0x4e3c14
0x004E0CB8  mov      byte ptr [ebp + edx - 0x410], 0
0x004E0CC0  mov      ecx, 0x20
0x004E0CC5  push     0x19
0x004E0CC7  mov      edx, 0x7364b0
0x004E0CCC  call     0x6ba810
0x004E0CD1  xorps    xmm0, xmm0
0x004E0CD4  mov      dword ptr [ebp - 0x414], eax
0x004E0CDA  add      esp, 4
0x004E0CDD  mov      dword ptr [ebp - 0x428], eax
0x004E0CE3  movups   xmmword ptr [ebp - 0x440], xmm0
0x004E0CEA  mov      dword ptr [eax + 4], 0x14
0x004E0CF1  mov      dword ptr [eax + 8], 0xffffffff
0x004E0CF8  mov      byte ptr [eax + 0xc], 0
0x004E0CFC  mov      dword ptr [eax], 1
0x004E0D02  movups   xmmword ptr [ebp - 0x450], xmm0
0x004E0D09  mov      dword ptr [ebp - 0x424], 0
0x004E0D13  movsd    qword ptr [ebp - 0x458], xmm0
0x004E0D1B  mov      dword ptr [ebp - 0x420], 0
0x004E0D25  mov      dword ptr [ebp - 0x41c], 0
0x004E0D2F  lea      ecx, [ebp - 0x410]
0x004E0D35  mov      dword ptr [ebp - 4], 0
0x004E0D3C  lea      edx, [ecx + 1]
0x004E0D3F  nop      
0x004E0D40  mov      al, byte ptr [ecx]
0x004E0D42  inc      ecx
0x004E0D43  test     al, al
0x004E0D45  jne      0x4e0d40
0x004E0D47  sub      ecx, edx
0x004E0D49  mov      edx, 0x7364b0
0x004E0D4E  mov      dword ptr [ebp - 0x460], ecx
0x004E0D54  push     0x19
0x004E0D56  lea      edi, [ecx + 1]
0x004E0D59  mov      ecx, 4
0x004E0D5E  cmp      edi, 4
0x004E0D61  mov      esi, edi
0x004E0D63  cmovl    esi, ecx
0x004E0D66  add      esi, 0xb
0x004E0D69  and      esi, 0xfffffff0
0x004E0D6C  add      esi, ecx
0x004E0D6E  lea      ecx, [esi + 0xc]
0x004E0D71  call     0x6ba810
0x004E0D76  add      esp, 4
0x004E0D79  mov      dword ptr [ebp - 0x45c], eax
0x004E0D7F  mov      dword ptr [ebp - 0x488], eax
0x004E0D85  mov      byte ptr [eax + 0xc], 0
0x004E0D89  lea      ecx, [eax + 0xc]
0x004E0D8C  mov      dword ptr [eax + 4], esi
0x004E0D8F  mov      dword ptr [eax], 0
0x004E0D95  lea      eax, [ebp - 0x410]
0x004E0D9B  push     edi
0x004E0D9C  push     eax
0x004E0D9D  push     ecx
0x004E0D9E  call     0x6d2250
0x004E0DA3  mov      edi, dword ptr [ebp - 0x45c]
0x004E0DA9  add      esp, 0xc
0x004E0DAC  mov      eax, dword ptr [ebp - 0x460]
0x004E0DB2  mov      dword ptr [edi + 8], eax
0x004E0DB5  mov      ecx, dword ptr [ebp - 0x414]
0x004E0DBB  mov      byte ptr [ebp - 4], 1
0x004E0DBF  add      dword ptr [edi], 2
0x004E0DC2  mov      dword ptr [ebp - 0x428], edi
0x004E0DC8  add      dword ptr [ecx], -1
0x004E0DCB  jne      0x4e0dd2
0x004E0DCD  call     0x6ba940
0x004E0DD2  mov      byte ptr [ebp - 4], 2
0x004E0DD6  add      dword ptr [edi], -1
0x004E0DD9  jne      0x4e0de2
0x004E0DDB  mov      ecx, edi
0x004E0DDD  call     0x6ba940
0x004E0DE2  mov      byte ptr [ebp - 4], 0
0x004E0DE6  mov      ecx, ebx
0x004E0DE8  mov      eax, dword ptr [ebx + 0x60]
0x004E0DEB  mov      dword ptr [ebp - 0x460], eax
0x004E0DF1  mov      dword ptr [ebp - 0x420], eax
0x004E0DF7  mov      eax, dword ptr [ebx + 0x64]
0x004E0DFA  push     1
0x004E0DFC  mov      dword ptr [ebp - 0x424], 0
0x004E0E06  mov      dword ptr [ebp - 0x45c], eax
0x004E0E0C  mov      dword ptr [ebp - 0x41c], eax
0x004E0E12  call     0x4e3f70
0x004E0E17  mov      eax, dword ptr [ebx + 4]
0x004E0E1A  lea      esi, [eax - 1]
0x004E0E1D  cmp      esi, eax
0x004E0E1F  jb       0x4e0e32
0x004E0E21  push     0
0x004E0E23  push     0
0x004E0E25  push     1
0x004E0E27  push     0xc000008c
0x004E0E2C  call     dword ptr [0x715340]
0x004E0E32  shl      esi, 6
0x004E0E35  xorps    xmm0, xmm0
0x004E0E38  add      esi, dword ptr [ebx]
0x004E0E3A  movups   xmmword ptr [esi], xmm0
0x004E0E3D  movups   xmmword ptr [esi + 0x10], xmm0
0x004E0E41  movsd    qword ptr [esi + 0x20], xmm0
0x004E0E46  movsd    xmm0, qword ptr [ebp - 0x430]
0x004E0E4E  movsd    qword ptr [esi + 0x28], xmm0
0x004E0E53  mov      ecx, dword ptr [esi + 0x30]
0x004E0E56  mov      dword ptr [esi + 0x30], edi
0x004E0E59  inc      dword ptr [edi]
0x004E0E5B  test     ecx, ecx
0x004E0E5D  je       0x4e0e69
0x004E0E5F  add      dword ptr [ecx], -1
0x004E0E62  jne      0x4e0e69
0x004E0E64  call     0x6ba940
0x004E0E69  mov      ecx, dword ptr [esi + 0x30]
0x004E0E6C  xor      edx, edx
0x004E0E6E  mov      eax, dword ptr [edi + 8]
0x004E0E71  mov      dword ptr [ecx + 8], eax
0x004E0E74  mov      eax, dword ptr [ebp - 0x460]
0x004E0E7A  mov      dword ptr [esi + 0x38], eax
0x004E0E7D  mov      eax, dword ptr [ebp - 0x45c]
0x004E0E83  mov      dword ptr [esi + 0x34], 0
0x004E0E8A  mov      dword ptr [esi + 0x3c], eax
0x004E0E8D  mov      byte ptr [ebx + 0x78], 1
0x004E0E91  mov      dword ptr [ebp - 0x45c], edx
0x004E0E97  mov      dword ptr [ebp - 4], 3
0x004E0E9E  add      dword ptr [edi], -1
0x004E0EA1  jne      0x4e0eb0
0x004E0EA3  mov      ecx, edi
0x004E0EA5  call     0x6ba940
0x004E0EAA  mov      edx, dword ptr [ebp - 0x45c]
0x004E0EB0  mov      esi, dword ptr [ebp - 0x470]
0x004E0EB6  mov      edi, dword ptr [ebp - 0x47c]
0x004E0EBC  mov      dword ptr [ebp - 4], 0xffffffff
0x004E0EC3  mov      al, byte ptr [edi + esi + 1]
0x004E0EC7  cmp      al, 0x28   <<< DOWN
0x004E0EC9  jne      0x4e39ea
0x004E0ECF  add      esi, 2
0x004E0ED2  xor      dl, dl
0x004E0ED4  mov      al, byte ptr [edi + esi]
0x004E0ED7  xor      ecx, ecx
0x004E0ED9  cmp      al, 0x2c
0x004E0EDB  je       0x4e0ef3
0x004E0EDD  nop      dword ptr [eax]
0x004E0EE0  cmp      al, 0x29
0x004E0EE2  je       0x4e0ef3
0x004E0EE4  inc      esi
0x004E0EE5  mov      byte ptr [ecx + 0xc92ee0], al
0x004E0EEB  inc      ecx
0x004E0EEC  mov      al, byte ptr [edi + esi]
0x004E0EEF  cmp      al, 0x2c
0x004E0EF1  jne      0x4e0ee0
0x004E0EF3  cmp      byte ptr [edi + esi], 0x29
0x004E0EF7  mov      eax, 1
0x004E0EFC  movzx    edx, dl
0x004E0EFF  cmove    edx, eax
0x004E0F02  inc      esi
0x004E0F03  mov      dword ptr [ebp - 0x488], edx
0x004E0F09  mov      dword ptr [ebp - 0x470], esi
0x004E0F0F  cmp      ecx, 0x100
0x004E0F15  jae      0x4e3c14
0x004E0F1B  mov      byte ptr [ecx + 0xc92ee0], 0
0x004E0F22  xor      ecx, ecx
0x004E0F24  nop      dword ptr [eax]
0x004E0F28  nop      dword ptr [eax + eax]
0x004E0F30  mov      al, byte ptr [ecx + 0xc92ee2]
0x004E0F36  lea      ecx, [ecx + 1]
0x004E0F39  mov      byte ptr [ecx + 0xc92fdf], al
0x004E0F3F  test     al, al
0x004E0F41  jne      0x4e0f30
0x004E0F43  .byte    0x68
0x004E0F44  loopne   0x4e0f75
0x004E0F46  leave    


======== candidate 0x00511E80 - 0x005123C9 ========
0x00511E80  fmul     qword ptr [ecx + 0x4d89d44d]
0x00511E86  fsub     dword ptr [esi + 0xf]
0x00511E89  pop      ds
0x00511E8A  test     byte ptr [eax], al
0x00511E8C  add      byte ptr [eax], al
0x00511E8E  add      byte ptr [eax], al
0x00511E90  mov      eax, dword ptr [0x772478]
0x00511E95  add      eax, 0x10
0x00511E98  mov      dword ptr [ebp - 0x38], eax
0x00511E9B  cmp      ecx, 5
0x00511E9E  ja       0x511ea8
0x00511EA0  add      eax, dword ptr [ebp - 0x28]
0x00511EA3  lea      ecx, [edx + edi]
0x00511EA6  jmp      0x511ec7
0x00511EA8  push     0
0x00511EAA  push     0
0x00511EAC  push     1
0x00511EAE  push     0xc000008c
0x00511EB3  call     esi
0x00511EB5  push     0
0x00511EB7  push     0
0x00511EB9  push     1
0x00511EBB  push     0xc000008c
0x00511EC0  call     esi
0x00511EC2  mov      eax, dword ptr [ebp - 0x38]
0x00511EC5  mov      ecx, edi
0x00511EC7  push     dword ptr [eax + 4]
0x00511ECA  push     ecx
0x00511ECB  call     0x5119a0
0x00511ED0  mov      ecx, dword ptr [ebp - 0x2c]
0x00511ED3  mov      edx, dword ptr [ebp - 0x24]
0x00511ED6  inc      ecx
0x00511ED7  add      dword ptr [ebp - 0x28], 8
0x00511EDB  add      edx, 0x34
0x00511EDE  mov      dword ptr [ebp - 0x2c], ecx
0x00511EE1  mov      dword ptr [ebp - 0x24], edx
0x00511EE4  cmp      ecx, 6
0x00511EE7  jl       0x511e90
0x00511EE9  xor      ecx, ecx
0x00511EEB  xor      edx, edx
0x00511EED  mov      dword ptr [ebp - 0x20], ecx
0x00511EF0  mov      dword ptr [ebp - 0x1c], edx
0x00511EF3  xor      edi, edi
0x00511EF5  mov      eax, dword ptr [0x772478]
0x00511EFA  add      eax, 0x10
0x00511EFD  mov      dword ptr [ebp - 0x38], eax
0x00511F00  cmp      edx, 0x28   <<< DOWN
0x00511F03  ja       0x511f09
0x00511F05  add      eax, edx
0x00511F07  jmp      0x511f1f
0x00511F09  push     0
0x00511F0B  push     0
0x00511F0D  push     1
0x00511F0F  push     0xc000008c
0x00511F14  call     esi
0x00511F16  mov      eax, dword ptr [ebp - 0x38]
0x00511F19  mov      edx, dword ptr [ebp - 0x1c]
0x00511F1C  mov      ecx, dword ptr [ebp - 0x20]
0x00511F1F  cmp      edi, dword ptr [eax + 4]
0x00511F22  jge      0x5123b2
0x00511F28  cmp      edx, 0x28   <<< DOWN
0x00511F2B  ja       0x511f37
0x00511F2D  mov      eax, dword ptr [ebp - 0x18]
0x00511F30  add      eax, 0x44
0x00511F33  add      ecx, eax
0x00511F35  jmp      0x511f4c
0x00511F37  push     0
0x00511F39  push     0
0x00511F3B  push     1
0x00511F3D  push     0xc000008c
0x00511F42  call     esi
0x00511F44  mov      eax, dword ptr [ebp - 0x18]
0x00511F47  add      eax, 0x44
0x00511F4A  mov      ecx, eax
0x00511F4C  cmp      dword ptr [ecx], 0
0x00511F4F  mov      edx, dword ptr [ebp - 0x1c]
0x00511F52  je       0x512349
0x00511F58  cmp      edx, 0x28   <<< DOWN
0x00511F5B  ja       0x511f62
0x00511F5D  add      eax, dword ptr [ebp - 0x20]
0x00511F60  jmp      0x511f75
0x00511F62  push     0
0x00511F64  push     0
0x00511F66  push     1
0x00511F68  push     0xc000008c
0x00511F6D  call     esi
0x00511F6F  mov      eax, dword ptr [ebp - 0x18]
0x00511F72  add      eax, 0x44
0x00511F75  mov      dword ptr [ebp - 0x2c], eax
0x00511F78  test     edi, edi
0x00511F7A  js       0x511f89
0x00511F7C  cmp      edi, dword ptr [eax + 8]
0x00511F7F  jge      0x511f89
0x00511F81  mov      eax, dword ptr [eax + 4]
0x00511F84  lea      eax, [eax + edi*4]
0x00511F87  jmp      0x511f9c
0x00511F89  push     0
0x00511F8B  push     0
0x00511F8D  push     1
0x00511F8F  push     0xc000008c
0x00511F94  call     esi
0x00511F96  mov      eax, dword ptr [ebp - 0x2c]
0x00511F99  mov      eax, dword ptr [eax + 4]
0x00511F9C  mov      eax, dword ptr [eax]
0x00511F9E  mov      dword ptr [ebp - 0x2c], eax
0x00511FA1  test     eax, eax
0x00511FA3  je       0x512338
0x00511FA9  push     0x19
0x00511FAB  mov      edx, 0x7364b0
0x00511FB0  mov      ecx, 0x20
0x00511FB5  call     0x6ba810
0x00511FBA  add      esp, 4
0x00511FBD  mov      dword ptr [ebp - 0x28], eax
0x00511FC0  mov      dword ptr [eax + 4], 0x14
0x00511FC7  mov      dword ptr [eax + 8], 0xffffffff
0x00511FCE  mov      dword ptr [eax], 0
0x00511FD4  mov      byte ptr [eax + 0xc], 0
0x00511FD8  movups   xmm0, xmmword ptr [0x726788]
0x00511FDF  movups   xmmword ptr [eax + 0xc], xmm0
0x00511FE3  mov      dword ptr [eax + 8], 0xf
0x00511FEA  mov      dword ptr [eax], 1
0x00511FF0  mov      eax, dword ptr [ebp - 0x2c]
0x00511FF3  mov      dword ptr [ebp - 4], 0
0x00511FFA  push     dword ptr [eax + 0xdc]
0x00512000  call     0x46a9d0
0x00512005  test     al, al
0x00512007  je       0x512071
0x00512009  push     0x19
0x0051200B  mov      edx, 0x7364b0
0x00512010  mov      ecx, 0x20
0x00512015  call     0x6ba810
0x0051201A  mov      esi, eax
0x0051201C  add      esp, 4
0x0051201F  mov      dword ptr [ebp - 0x38], esi
0x00512022  mov      dword ptr [esi + 4], 0x14
0x00512029  mov      dword ptr [esi + 8], 0xffffffff
0x00512030  mov      dword ptr [esi], 0
0x00512036  mov      byte ptr [esi + 0xc], 0
0x0051203A  mov      ecx, dword ptr [0x726798]
0x00512040  mov      dword ptr [esi + 0xc], ecx
0x00512043  mov      al, byte ptr [0x72679c]
0x00512048  mov      byte ptr [esi + 0x10], al
0x0051204B  mov      dword ptr [esi + 8], 4
0x00512052  mov      dword ptr [esi], 1
0x00512058  lea      eax, [ebp - 0x38]
0x0051205B  mov      byte ptr [ebp - 4], 1
0x0051205F  push     eax
0x00512060  lea      ecx, [ebp - 0x28]
0x00512063  call     0x6b9290
0x00512068  mov      byte ptr [ebp - 4], 2
0x0051206C  jmp      0x51221e
0x00512071  mov      ecx, dword ptr [ebp - 0x18]
0x00512074  mov      eax, dword ptr [ecx + 0x44]
0x00512077  mov      ecx, 0xca65b0
0x0051207C  mov      dword ptr [ebp - 0x24], eax
0x0051207F  mov      eax, dword ptr [ebp - 0x2c]
0x00512082  mov      eax, dword ptr [eax + 0xd4]
0x00512088  mov      eax, dword ptr [eax + 0xc]
0x0051208B  add      eax, 0xc
0x0051208E  push     eax
0x0051208F  call     0x5be100
0x00512094  mov      dword ptr [ebp - 0x38], eax
0x00512097  cmp      eax, -1
0x0051209A  je       0x51222e
0x005120A0  cmp      dword ptr [ebp - 0x24], 0
0x005120A4  je       0x51222e
0x005120AA  test     eax, eax
0x005120AC  js       0x5121d6
0x005120B2  cmp      eax, dword ptr [0xca65bc]
0x005120B8  jge      0x5121d6
0x005120BE  jb       0x5120d0
0x005120C0  push     0
0x005120C2  push     0
0x005120C4  push     1
0x005120C6  push     0xc000008c
0x005120CB  call     esi
0x005120CD  mov      eax, dword ptr [ebp - 0x38]
0x005120D0  mov      ecx, eax
0x005120D2  mov      eax, dword ptr [0xca65b8]
0x005120D7  shl      ecx, 6
0x005120DA  mov      dword ptr [ebp - 0x40], ecx
0x005120DD  mov      eax, dword ptr [ecx + eax + 0x10]
0x005120E1  mov      ecx, dword ptr [ebp - 0x24]
0x005120E4  add      eax, 0xc
0x005120E7  mov      dword ptr [ebp - 0x3c], eax
0x005120EA  mov      ecx, dword ptr [ecx + 0x21c]
0x005120F0  test     ecx, ecx
0x005120F2  jne      0x51219a
0x005120F8  call     0x5da0f0
0x005120FD  push     dword ptr [ebp - 0x3c]
0x00512100  lea      ecx, [ebp - 0x30]
0x00512103  mov      dword ptr [ebp - 0x34], 0xffffffff
0x0051210A  mov      esi, eax
0x0051210C  call     0x6b8fb0
0x00512111  lea      eax, [ebp - 0x34]
0x00512114  push     eax
0x00512115  lea      eax, [ebp - 0x30]
0x00512118  push     eax
0x00512119  lea      ecx, [esi + 0x2804]
0x0051211F  call     0x444990
0x00512124  mov      byte ptr [ebp - 0x11], al
0x00512127  mov      byte ptr [ebp - 4], 3
0x0051212B  mov      ecx, dword ptr [ebp - 0x30]
0x0051212E  test     ecx, ecx
0x00512130  je       0x51213f
0x00512132  add      dword ptr [ecx], -1
0x00512135  jne      0x51213f
0x00512137  call     0x6ba940
0x0051213C  mov      al, byte ptr [ebp - 0x11]
0x0051213F  or       esi, 0xffffffff
0x00512142  mov      byte ptr [ebp - 4], 0
0x00512146  test     al, al
0x00512148  mov      eax, dword ptr [ebp - 0x24]
0x0051214B  cmovne   esi, dword ptr [ebp - 0x34]
0x0051214F  mov      eax, dword ptr [eax + 0x21c]
0x00512155  test     eax, eax
0x00512157  jne      0x51217a
0x00512159  cmp      esi, 0x1ff
0x0051215F  ja       0x51218f
0x00512161  call     0x5da0f0
0x00512166  movss    xmm0, dword ptr [eax + esi*4 + 0x1804]
0x0051216F  lea      eax, [eax + esi*4]
0x00512172  mov      esi, dword ptr [0x715340]
0x00512178  jmp      0x5121a0
0x0051217A  cmp      esi, 0x1ff
0x00512180  ja       0x51218f
0x00512182  movss    xmm0, dword ptr [eax + esi*4]
0x00512187  mov      esi, dword ptr [0x715340]
0x0051218D  jmp      0x5121a0
0x0051218F  mov      esi, dword ptr [0x715340]
0x00512195  xorps    xmm0, xmm0
0x00512198  jmp      0x5121a0
0x0051219A  push     eax
0x0051219B  call     0x5da900
0x005121A0  mov      eax, dword ptr [ebp - 0x38]
0x005121A3  movss    dword ptr [ebp - 0x24], xmm0
0x005121A8  cmp      eax, dword ptr [0xca65bc]
0x005121AE  jb       0x5121c2
0x005121B0  push     0
0x005121B2  push     0
0x005121B4  push     1
0x005121B6  push     0xc000008c
0x005121BB  call     esi
0x005121BD  movss    xmm0, dword ptr [ebp - 0x24]
0x005121C2  mov      eax, dword ptr [0xca65b8]
0x005121C7  mov      ecx, dword ptr [ebp - 0x40]
0x005121CA  comiss   xmm0, dword ptr [ecx + eax + 0x14]
0x005121CF  setae    al
0x005121D2  test     al, al
0x005121D4  jne      0x51222e
0x005121D6  push     0x19
0x005121D8  mov      edx, 0x7364b0
0x005121DD  mov      ecx, 0x10
0x005121E2  call     0x6ba810
0x005121E7  mov      esi, eax
0x005121E9  add      esp, 4
0x005121EC  mov      dword ptr [ebp - 0x40], esi
0x005121EF  mov      dword ptr [esi + 4], 4
0x005121F6  mov      dword ptr [esi + 0xc], 0x646552
0x005121FD  mov      dword ptr [esi + 8], 3
0x00512204  mov      dword ptr [esi], 1
0x0051220A  lea      eax, [ebp - 0x40]
0x0051220D  mov      byte ptr [ebp - 4], 4
0x00512211  push     eax
0x00512212  lea      ecx, [ebp - 0x28]
0x00512215  call     0x6b9290
0x0051221A  mov      byte ptr [ebp - 4], 5
0x0051221E  add      dword ptr [esi], -1
0x00512221  jne      0x51222a
0x00512223  mov      ecx, esi
0x00512225  call     0x6ba940
0x0051222A  mov      byte ptr [ebp - 4], 0
0x0051222E  mov      eax, dword ptr [ebp - 0x2c]
0x00512231  lea      ecx, [ebp - 0x28]
0x00512234  mov      eax, dword ptr [eax + 0xd4]
0x0051223A  add      eax, 0xc
0x0051223D  push     eax
0x0051223E  call     0x6b9290
0x00512243  cmp      dword ptr [ebp - 0x1c], 0x28   <<< DOWN
0x00512247  mov      esi, dword ptr [ebp - 0x28]
0x0051224A  ja       0x512257
0x0051224C  mov      eax, dword ptr [ebp - 0x18]
0x0051224F  add      eax, 0x44
0x00512252  add      eax, dword ptr [ebp - 0x20]
0x00512255  jmp      0x51226e
0x00512257  push     0
0x00512259  push     0
0x0051225B  push     1
0x0051225D  push     0xc000008c
0x00512262  call     dword ptr [0x715340]
0x00512268  mov      eax, dword ptr [ebp - 0x18]
0x0051226B  add      eax, 0x44
0x0051226E  mov      dword ptr [ebp - 0x38], eax
0x00512271  test     edi, edi
0x00512273  js       0x512282
0x00512275  cmp      edi, dword ptr [eax + 0x10]
0x00512278  jge      0x512282
0x0051227A  mov      eax, dword ptr [eax + 0xc]
0x0051227D  lea      ecx, [eax + edi*4]
0x00512280  jmp      0x512299
0x00512282  push     0
0x00512284  push     0
0x00512286  push     1
0x00512288  push     0xc000008c
0x0051228D  call     dword ptr [0x715340]
0x00512293  mov      eax, dword ptr [ebp - 0x38]
0x00512296  mov      ecx, dword ptr [eax + 0xc]
0x00512299  mov      ecx, dword ptr [ecx]
0x0051229B  lea      eax, [esi + 0xc]
0x0051229E  push     eax
0x0051229F  call     0x507d40
0x005122A4  cmp      dword ptr [ebp - 0x1c], 0x28   <<< DOWN
0x005122A8  ja       0x5122b5
0x005122AA  mov      eax, dword ptr [ebp - 0x18]
0x005122AD  add      eax, 0x44
0x005122B0  add      eax, dword ptr [ebp - 0x20]
0x005122B3  jmp      0x5122cc
0x005122B5  push     0
0x005122B7  push     0
0x005122B9  push     1
0x005122BB  push     0xc000008c
0x005122C0  call     dword ptr [0x715340]
0x005122C6  mov      eax, dword ptr [ebp - 0x18]
0x005122C9  add      eax, 0x44
0x005122CC  mov      dword ptr [ebp - 0x38], eax
0x005122CF  test     edi, edi
0x005122D1  js       0x5122e0
0x005122D3  cmp      edi, dword ptr [eax + 0x10]
0x005122D6  jge      0x5122e0
0x005122D8  mov      eax, dword ptr [eax + 0xc]
0x005122DB  lea      ecx, [eax + edi*4]
0x005122DE  jmp      0x5122f7
0x005122E0  push     0
0x005122E2  push     0
0x005122E4  push     1
0x005122E6  push     0xc000008c
0x005122EB  call     dword ptr [0x715340]
0x005122F1  mov      eax, dword ptr [ebp - 0x38]
0x005122F4  mov      ecx, dword ptr [eax + 0xc]
0x005122F7  mov      ecx, dword ptr [ecx]
0x005122F9  cmp      byte ptr [ecx + 0x1c], 1
0x005122FD  je       0x512308
0x005122FF  mov      byte ptr [ecx + 0x1c], 1
0x00512303  call     0x504ee0
0x00512308  mov      dword ptr [ebp - 4], 6
0x0051230F  test     esi, esi
0x00512311  je       0x51231f
0x00512313  add      dword ptr [esi], -1
0x00512316  jne      0x51231f
0x00512318  mov      ecx, esi
0x0051231A  call     0x6ba940
0x0051231F  mov      edx, dword ptr [ebp - 0x1c]
0x00512322  inc      edi
0x00512323  mov      ecx, dword ptr [ebp - 0x20]
0x00512326  mov      dword ptr [ebp - 4], 0xffffffff
0x0051232D  mov      esi, dword ptr [0x715340]
0x00512333  jmp      0x511ef5
0x00512338  cmp      dword ptr [ebp - 0x1c], 0x28   <<< DOWN
0x0051233C  ja       0x512353
0x0051233E  mov      eax, dword ptr [ebp - 0x18]
0x00512341  add      eax, 0x44
0x00512344  add      eax, dword ptr [ebp - 0x20]
0x00512347  jmp      0x512366
0x00512349  cmp      edx, 0x28   <<< DOWN
0x0051234C  ja       0x512353
0x0051234E  add      eax, dword ptr [ebp - 0x20]
0x00512351  jmp      0x512366
0x00512353  push     0
0x00512355  push     0
0x00512357  push     1
0x00512359  push     0xc000008c
0x0051235E  call     esi
0x00512360  mov      eax, dword ptr [ebp - 0x18]
0x00512363  add      eax, 0x44
0x00512366  mov      dword ptr [ebp - 0x38], eax
0x00512369  test     edi, edi
0x0051236B  js       0x51237a
0x0051236D  cmp      edi, dword ptr [eax + 0x10]
0x00512370  jge      0x51237a
0x00512372  mov      eax, dword ptr [eax + 0xc]
0x00512375  lea      eax, [eax + edi*4]
0x00512378  jmp      0x51238d
0x0051237A  push     0
0x0051237C  push     0
0x0051237E  push     1
0x00512380  push     0xc000008c
0x00512385  call     esi
0x00512387  mov      eax, dword ptr [ebp - 0x38]
0x0051238A  mov      eax, dword ptr [eax + 0xc]
0x0051238D  mov      eax, dword ptr [eax]
0x0051238F  mov      dword ptr [ebp - 0x40], eax
0x00512392  cmp      byte ptr [eax + 0x1c], 0
0x00512396  je       0x5123a6
0x00512398  mov      ecx, eax
0x0051239A  call     0x504ee0
0x0051239F  mov      eax, dword ptr [ebp - 0x40]
0x005123A2  mov      byte ptr [eax + 0x1c], 0
0x005123A6  mov      edx, dword ptr [ebp - 0x1c]
0x005123A9  inc      edi
0x005123AA  mov      ecx, dword ptr [ebp - 0x20]
0x005123AD  jmp      0x511ef5
0x005123B2  add      edx, 8
0x005123B5  add      ecx, 0x34
0x005123B8  mov      dword ptr [ebp - 0x1c], edx
0x005123BB  mov      dword ptr [ebp - 0x20], ecx
0x005123BE  cmp      edx, 0x30
0x005123C1  jl       0x511ef3
0x005123C7  .byte    0x8b
0x005123C8  dec      ebp


======== candidate 0x0054E5E9 - 0x0054E7B3 ========
0x0054E5E9  mov      edx, ecx
0x0054E5EB  cmp      ecx, 0x100
0x0054E5F1  je       0x54e5fb
0x0054E5F3  cmp      edx, 0x101
0x0054E5F9  jne      0x54e630
0x0054E5FB  cmp      byte ptr [edi + 0x61], 0
0x0054E5FF  movzx    ebx, ax
0x0054E602  jne      0x54e63b
0x0054E604  cmp      ebx, 0x91
0x0054E60A  jne      0x54e630
0x0054E60C  cmp      ecx, 0x101
0x0054E612  jne      0x54e630
0x0054E614  cmp      dword ptr [0x76a338], 0
0x0054E61B  je       0x54e62c
0x0054E61D  mov      eax, dword ptr [0x76a324]
0x0054E622  cmp      byte ptr [eax + 0x12], 1
0x0054E626  je       0x54e62c
0x0054E628  mov      byte ptr [eax + 0x12], 1
0x0054E62C  mov      byte ptr [edi + 0x61], 1
0x0054E630  xor      al, al
0x0054E632  pop      edi
0x0054E633  pop      esi
0x0054E634  pop      ebx
0x0054E635  mov      esp, ebp
0x0054E637  pop      ebp
0x0054E638  ret      4
0x0054E63B  cmp      ebx, 0x91
0x0054E641  jne      0x54e65d
0x0054E643  cmp      ecx, 0x101
0x0054E649  jne      0x54e65d
0x0054E64B  mov      ecx, edi
0x0054E64D  call     0x54dc70
0x0054E652  mov      al, 1
0x0054E654  pop      edi
0x0054E655  pop      esi
0x0054E656  pop      ebx
0x0054E657  mov      esp, ebp
0x0054E659  pop      ebp
0x0054E65A  ret      4
0x0054E65D  cmp      ecx, 0x100
0x0054E663  jne      0x54e824
0x0054E669  cmp      ebx, 0x25   <<< LEFT
0x0054E66C  jne      0x54e6ad
0x0054E66E  dec      dword ptr [edi + 8]
0x0054E671  lea      esi, [edi + 0x14]
0x0054E674  mov      eax, dword ptr [edi + 8]
0x0054E677  xor      ecx, ecx
0x0054E679  test     eax, eax
0x0054E67B  cmovle   eax, ecx
0x0054E67E  mov      ecx, esi
0x0054E680  mov      dword ptr [edi + 8], eax
0x0054E683  call     0x6b8f20
0x0054E688  mov      ecx, dword ptr [edi + 8]
0x0054E68B  cmp      ecx, eax
0x0054E68D  jl       0x54e698
0x0054E68F  mov      ecx, esi
0x0054E691  call     0x6b8f20
0x0054E696  mov      ecx, eax
0x0054E698  mov      dword ptr [edi + 8], ecx
0x0054E69B  mov      ecx, edi
0x0054E69D  call     0x54ddf0
0x0054E6A2  pop      edi
0x0054E6A3  pop      esi
0x0054E6A4  mov      al, 1
0x0054E6A6  pop      ebx
0x0054E6A7  mov      esp, ebp
0x0054E6A9  pop      ebp
0x0054E6AA  ret      4
0x0054E6AD  cmp      ebx, 0x27   <<< RIGHT
0x0054E6B0  jne      0x54e6b7
0x0054E6B2  inc      dword ptr [edi + 8]
0x0054E6B5  jmp      0x54e671
0x0054E6B7  cmp      ebx, 0x26   <<< UP
0x0054E6BA  jne      0x54e733
0x0054E6BC  mov      ecx, dword ptr [edi + 0x28]
0x0054E6BF  mov      esi, dword ptr [edi + 0x30]
0x0054E6C2  inc      ecx
0x0054E6C3  cmp      ecx, esi
0x0054E6C5  mov      eax, ecx
0x0054E6C7  cmovge   eax, esi
0x0054E6CA  test     eax, eax
0x0054E6CC  jns      0x54e6d2
0x0054E6CE  xor      eax, eax
0x0054E6D0  jmp      0x54e6d9
0x0054E6D2  cmp      ecx, esi
0x0054E6D4  mov      eax, esi
0x0054E6D6  cmovl    eax, ecx
0x0054E6D9  mov      ebx, esi
0x0054E6DB  mov      dword ptr [edi + 0x28], eax
0x0054E6DE  sub      ebx, eax
0x0054E6E0  lea      edx, [esi - 1]
0x0054E6E3  cmp      edx, ebx
0x0054E6E5  mov      ecx, 1
0x0054E6EA  cmovge   ecx, eax
0x0054E6ED  mov      eax, esi
0x0054E6EF  sub      eax, ecx
0x0054E6F1  jns      0x54e6f7
0x0054E6F3  xor      edx, edx
0x0054E6F5  jmp      0x54e700
0x0054E6F7  cmp      edx, ebx
0x0054E6F9  cmovge   edx, ebx
0x0054E6FC  test     edx, edx
0x0054E6FE  js       0x54e716
0x0054E700  cmp      edx, esi
0x0054E702  jge      0x54e716
0x0054E704  push     edx
0x0054E705  lea      ecx, [edi + 0x2c]
0x0054E708  call     0x40b900
0x0054E70D  push     eax
0x0054E70E  lea      ecx, [edi + 0x14]
0x0054E711  call     0x6b91c0
0x0054E716  lea      ecx, [edi + 0x14]
0x0054E719  call     0x6b8f20
0x0054E71E  mov      dword ptr [edi + 8], eax
0x0054E721  lea      ecx, [eax - 0x49]
0x0054E724  xor      eax, eax
0x0054E726  test     ecx, ecx
0x0054E728  cmovns   eax, ecx
0x0054E72B  mov      dword ptr [edi + 0xc], eax
0x0054E72E  jmp      0x54e671
0x0054E733  cmp      ebx, 0x28   <<< DOWN
0x0054E736  jne      0x54e7b2
0x0054E738  mov      eax, dword ptr [edi + 0x28]
0x0054E73B  xor      esi, esi
0x0054E73D  add      eax, -1
0x0054E740  mov      ecx, 1
0x0054E745  cmovns   esi, eax
0x0054E748  mov      eax, dword ptr [edi + 0x30]
0x0054E74B  mov      edx, eax
0x0054E74D  mov      dword ptr [edi + 0x28], esi
0x0054E750  sub      edx, esi
0x0054E752  lea      ebx, [eax - 1]
0x0054E755  cmp      ebx, edx
0x0054E757  cmovge   ecx, esi
0x0054E75A  sub      eax, ecx
0x0054E75C  jns      0x54e762
0x0054E75E  xor      edx, edx
0x0054E760  jmp      0x54e767
0x0054E762  cmp      ebx, edx
0x0054E764  cmovl    edx, ebx
0x0054E767  test     esi, esi
0x0054E769  je       0x54e787
0x0054E76B  cmp      dword ptr [edi + 0x30], 0
0x0054E76F  jle      0x54e787
0x0054E771  push     edx
0x0054E772  lea      ecx, [edi + 0x2c]
0x0054E775  lea      esi, [edi + 0x14]
0x0054E778  call     0x40b900
0x0054E77D  push     eax
0x0054E77E  mov      ecx, esi
0x0054E780  call     0x6b91c0
0x0054E785  jmp      0x54e796
0x0054E787  lea      esi, [edi + 0x14]
0x0054E78A  push     0x71ce50
0x0054E78F  mov      ecx, esi
0x0054E791  call     0x6b9200
0x0054E796  mov      ecx, esi
0x0054E798  call     0x6b8f20
0x0054E79D  mov      dword ptr [edi + 8], eax
0x0054E7A0  lea      ecx, [eax - 0x49]
0x0054E7A3  xor      eax, eax
0x0054E7A5  test     ecx, ecx
0x0054E7A7  cmovns   eax, ecx
0x0054E7AA  mov      dword ptr [edi + 0xc], eax
0x0054E7AD  jmp      0x54e674
0x0054E7B2  .byte    0x8d


======== candidate 0x005B37E5 - 0x005B3E82 ========
0x005B37E5  add      byte ptr [esi - 0x39], ah
0x005B37E8  inc      eax
0x005B37E9  sub      dword ptr [eax], eax
0x005B37EB  add      esi, eax
0x005B37ED  cmp      byte ptr [ecx], 0x28
0x005B37F0  add      byte ptr [eax], al
0x005B37F2  add      eax, ebp
0x005B37F4  push     0xe8fffa68
0x005B37F9  adc      edi, dword ptr [ebp - 6]
0x005B37FC  inc      dword ptr [ebx + 0x772dd03d]
0x005B3802  add      byte ptr [eax], al
0x005B3804  je       0x5b3813
0x005B3806  push     ecx
0x005B3807  push     esi
0x005B3808  lea      eax, [ebp - 0x10]
0x005B380B  push     eax
0x005B380C  call     0x6bbb00
0x005B3811  jmp      0x5b3823
0x005B3813  sub      esp, 8
0x005B3816  lea      ecx, [ebp - 0x10]
0x005B3819  mov      edx, esi
0x005B381B  call     0x6bb140
0x005B3820  add      esp, 8
0x005B3823  push     1
0x005B3825  mov      dword ptr [ebp - 4], 0
0x005B382C  mov      ecx, dword ptr [0x76a338]
0x005B3832  push     0
0x005B3834  call     0x479c10
0x005B3839  mov      ecx, dword ptr [0x772400]
0x005B383F  movsd    xmm0, qword ptr [0x7372a8]
0x005B3847  mov      byte ptr [ecx + 0x8f], 1
0x005B384E  mov      byte ptr [ecx + 0x8c], 0
0x005B3855  mov      byte ptr [ecx + 0x598], 0
0x005B385C  ucomisd  xmm0, qword ptr [ecx + 0xa090]
0x005B3864  lahf     
0x005B3865  test     ah, 0x44   <<< D
0x005B3868  jnp      0x5b3882
0x005B386A  movsd    qword ptr [ecx + 0xa090], xmm0
0x005B3872  cmp      byte ptr [ecx + 0xa098], 0
0x005B3879  je       0x5b3882
0x005B387B  mov      byte ptr [ecx + 0xa098], 1
0x005B3882  call     0x5f8080
0x005B3887  mov      ecx, eax
0x005B3889  call     0x5fa7c0
0x005B388E  call     0x4d1090
0x005B3893  push     0
0x005B3895  lea      ecx, [eax + 0x10]
0x005B3898  call     0x4d1d90
0x005B389D  mov      ecx, dword ptr [0x76a338]
0x005B38A3  push     0
0x005B38A5  lea      ecx, [ecx + 0x2868]
0x005B38AB  call     0x47de40
0x005B38B0  mov      ecx, dword ptr [0x772400]
0x005B38B6  lea      eax, [ebp - 0x10]
0x005B38B9  push     eax
0x005B38BA  lea      ecx, [ecx + 0x368]
0x005B38C0  call     0x54eb50
0x005B38C5  mov      ecx, dword ptr [0x76a338]
0x005B38CB  push     1
0x005B38CD  push     0
0x005B38CF  call     0x479c10
0x005B38D4  mov      edi, dword ptr [0x76a338]
0x005B38DA  mov      esi, dword ptr [edi + 0xfd]
0x005B38E0  test     esi, esi
0x005B38E2  jns      0x5b38f4
0x005B38E4  neg      esi
0x005B38E6  lea      ecx, [edi + 0xf9]
0x005B38EC  push     esi
0x005B38ED  call     0x47df80
0x005B38F2  jmp      0x5b3918
0x005B38F4  jle      0x5b3918
0x005B38F6  cmp      esi, 1
0x005B38F9  jne      0x5b3912
0x005B38FB  lea      eax, [esi - 1]
0x005B38FE  cmp      eax, esi
0x005B3900  jb       0x5b3912
0x005B3902  push     0
0x005B3904  push     0
0x005B3906  push     esi
0x005B3907  push     0xc000008c
0x005B390C  call     dword ptr [0x715340]
0x005B3912  sub      dword ptr [edi + 0xfd], esi
0x005B3918  call     0x501450
0x005B391D  cmp      dword ptr [eax + 0x81a8], 0
0x005B3924  je       0x5b392f
0x005B3926  push     0
0x005B3928  mov      ecx, eax
0x005B392A  call     0x504260
0x005B392F  mov      eax, dword ptr [0x772400]
0x005B3934  mov      byte ptr [eax + 0x8d], 0
0x005B393B  call     0x5b28d0
0x005B3940  push     ecx
0x005B3941  lea      ecx, [eax + 0x110]
0x005B3947  call     0x54a900
0x005B394C  mov      eax, dword ptr [ebp - 0x10]
0x005B394F  test     eax, eax
0x005B3951  je       0x5b3967
0x005B3953  dec      dword ptr [eax]
0x005B3955  mov      eax, dword ptr [ebp - 0x10]
0x005B3958  cmp      dword ptr [eax], 0
0x005B395B  jg       0x5b3967
0x005B395D  push     eax
0x005B395E  call     dword ptr [0x715540]
0x005B3964  add      esp, 4
0x005B3967  mov      ecx, dword ptr [ebp - 0xc]
0x005B396A  mov      dword ptr fs:[0], ecx
0x005B3971  pop      ecx
0x005B3972  pop      edi
0x005B3973  pop      esi
0x005B3974  mov      esp, ebp
0x005B3976  pop      ebp
0x005B3977  ret      
0x005B3978  int3     
0x005B3979  int3     
0x005B397A  int3     
0x005B397B  int3     
0x005B397C  int3     
0x005B397D  int3     
0x005B397E  int3     
0x005B397F  int3     
0x005B3980  push     ebp
0x005B3981  mov      ebp, esp
0x005B3983  push     -1
0x005B3985  push     0x7076bd
0x005B398A  mov      eax, dword ptr fs:[0]
0x005B3990  push     eax
0x005B3991  sub      esp, 0x3c
0x005B3994  push     esi
0x005B3995  push     edi
0x005B3996  mov      eax, dword ptr [0x76700c]
0x005B399B  xor      eax, ebp
0x005B399D  push     eax
0x005B399E  lea      eax, [ebp - 0xc]
0x005B39A1  mov      dword ptr fs:[0], eax
0x005B39A7  lea      eax, [ebp - 0x14]
0x005B39AA  mov      dword ptr [ebp - 4], 0
0x005B39B1  mov      ecx, dword ptr [ebp + 8]
0x005B39B4  push     eax
0x005B39B5  call     0x5acf80
0x005B39BA  mov      byte ptr [ebp - 4], 1
0x005B39BE  mov      edx, 0xca5570
0x005B39C3  mov      edi, dword ptr [ebp - 0x14]
0x005B39C6  lea      ecx, [edi + 0xc]
0x005B39C9  sub      edx, ecx
0x005B39CB  nop      dword ptr [eax + eax]
0x005B39D0  mov      al, byte ptr [ecx]
0x005B39D2  lea      ecx, [ecx + 1]
0x005B39D5  mov      byte ptr [edx + ecx - 1], al
0x005B39D9  test     al, al
0x005B39DB  jne      0x5b39d0
0x005B39DD  push     0x19
0x005B39DF  mov      edx, 0x7364b0
0x005B39E4  mov      ecx, 0x20
0x005B39E9  call     0x6ba810
0x005B39EE  mov      dword ptr [ebp - 0x2c], eax
0x005B39F1  mov      dword ptr [eax + 4], 0x14
0x005B39F8  mov      dword ptr [eax + 8], 0xffffffff
0x005B39FF  mov      byte ptr [eax + 0xc], 0
0x005B3A03  mov      dword ptr [eax], 1
0x005B3A09  mov      dword ptr [ebp - 0x48], 0
0x005B3A10  mov      dword ptr [ebp - 0x44], 0
0x005B3A17  push     0x726874
0x005B3A1C  push     0xca5570
0x005B3A21  mov      byte ptr [ebp - 4], 3
0x005B3A25  call     0x6d9a25
0x005B3A2A  add      esp, 0xc
0x005B3A2D  lea      ecx, [ebp - 0x2c]
0x005B3A30  push     eax
0x005B3A31  call     0x6b9200
0x005B3A36  push     0x726874
0x005B3A3B  push     0
0x005B3A3D  call     0x6d9a25
0x005B3A42  mov      esi, eax
0x005B3A44  add      esp, 8
0x005B3A47  mov      dword ptr [ebp - 0x28], esi
0x005B3A4A  test     esi, esi
0x005B3A4C  je       0x5b3b47
0x005B3A52  push     1
0x005B3A54  lea      ecx, [ebp - 0x48]
0x005B3A57  call     0x444ca0
0x005B3A5C  mov      edi, dword ptr [ebp - 0x44]
0x005B3A5F  lea      eax, [edi - 1]
0x005B3A62  mov      dword ptr [ebp - 0x38], eax
0x005B3A65  cmp      eax, edi
0x005B3A67  jb       0x5b3a7d
0x005B3A69  push     0
0x005B3A6B  push     0
0x005B3A6D  push     1
0x005B3A6F  push     0xc000008c
0x005B3A74  call     dword ptr [0x715340]
0x005B3A7A  mov      eax, dword ptr [ebp - 0x38]
0x005B3A7D  mov      ecx, dword ptr [ebp - 0x48]
0x005B3A80  lea      edi, [ecx + eax*4]
0x005B3A83  mov      ecx, esi
0x005B3A85  lea      edx, [ecx + 1]
0x005B3A88  mov      al, byte ptr [ecx]
0x005B3A8A  inc      ecx
0x005B3A8B  test     al, al
0x005B3A8D  jne      0x5b3a88
0x005B3A8F  sub      ecx, edx
0x005B3A91  mov      edx, 0x7364b0
0x005B3A96  mov      dword ptr [ebp - 0x38], ecx
0x005B3A99  inc      ecx
0x005B3A9A  mov      esi, ecx
0x005B3A9C  cmp      ecx, 4
0x005B3A9F  mov      ecx, 4
0x005B3AA4  cmovl    esi, ecx
0x005B3AA7  add      esi, 0xb
0x005B3AAA  and      esi, 0xfffffff0
0x005B3AAD  add      esi, ecx
0x005B3AAF  push     0x19
0x005B3AB1  lea      ecx, [esi + 0xc]
0x005B3AB4  call     0x6ba810
0x005B3AB9  mov      dword ptr [ebp - 0x30], eax
0x005B3ABC  mov      byte ptr [eax + 0xc], 0
0x005B3AC0  mov      dword ptr [ebp - 0x40], eax
0x005B3AC3  mov      dword ptr [eax + 4], esi
0x005B3AC6  lea      ecx, [eax + 0xc]
0x005B3AC9  mov      esi, dword ptr [ebp - 0x38]
0x005B3ACC  mov      dword ptr [eax + 8], 0xffffffff
0x005B3AD3  mov      dword ptr [eax], 0
0x005B3AD9  lea      edx, [esi + 1]
0x005B3ADC  push     edx
0x005B3ADD  push     dword ptr [ebp - 0x28]
0x005B3AE0  push     ecx
0x005B3AE1  call     0x6d2250
0x005B3AE6  mov      edx, dword ptr [ebp - 0x30]
0x005B3AE9  add      esp, 0x10
0x005B3AEC  mov      dword ptr [edx + 8], esi
0x005B3AEF  inc      dword ptr [edx]
0x005B3AF1  mov      byte ptr [ebp - 4], 4
0x005B3AF5  mov      ecx, dword ptr [edi]
0x005B3AF7  mov      dword ptr [edi], edx
0x005B3AF9  inc      dword ptr [edx]
0x005B3AFB  test     ecx, ecx
0x005B3AFD  je       0x5b3b0c
0x005B3AFF  add      dword ptr [ecx], -1
0x005B3B02  jne      0x5b3b0c
0x005B3B04  call     0x6ba940
0x005B3B09  mov      edx, dword ptr [ebp - 0x30]
0x005B3B0C  mov      ecx, dword ptr [edi]
0x005B3B0E  mov      eax, dword ptr [edx + 8]
0x005B3B11  mov      dword ptr [ecx + 8], eax
0x005B3B14  mov      byte ptr [ebp - 4], 5
0x005B3B18  add      dword ptr [edx], -1
0x005B3B1B  jne      0x5b3b24
0x005B3B1D  mov      ecx, edx
0x005B3B1F  call     0x6ba940
0x005B3B24  push     0x726874
0x005B3B29  push     0
0x005B3B2B  mov      byte ptr [ebp - 4], 3
0x005B3B2F  call     0x6d9a25
0x005B3B34  mov      esi, eax
0x005B3B36  mov      dword ptr [ebp - 0x28], eax
0x005B3B39  add      esp, 8
0x005B3B3C  test     esi, esi
0x005B3B3E  jne      0x5b3a52
0x005B3B44  mov      edi, dword ptr [ebp - 0x14]
0x005B3B47  mov      esi, dword ptr [ebp - 0x2c]
0x005B3B4A  mov      edx, 0x72b180
0x005B3B4F  lea      ecx, [esi + 0xc]
0x005B3B52  mov      al, byte ptr [ecx]
0x005B3B54  cmp      al, byte ptr [edx]
0x005B3B56  mov      byte ptr [ebp - 0xd], al
0x005B3B59  lea      eax, [esi + 0xc]
0x005B3B5C  jne      0x5b3b82
0x005B3B5E  cmp      byte ptr [ebp - 0xd], 0
0x005B3B62  je       0x5b3b7e
0x005B3B64  mov      al, byte ptr [ecx + 1]
0x005B3B67  cmp      al, byte ptr [edx + 1]
0x005B3B6A  mov      byte ptr [ebp - 0xd], al
0x005B3B6D  lea      eax, [esi + 0xc]
0x005B3B70  jne      0x5b3b82
0x005B3B72  add      ecx, 2
0x005B3B75  add      edx, 2
0x005B3B78  cmp      byte ptr [ebp - 0xd], 0
0x005B3B7C  jne      0x5b3b52
0x005B3B7E  xor      ecx, ecx
0x005B3B80  jmp      0x5b3b87
0x005B3B82  sbb      ecx, ecx
0x005B3B84  or       ecx, 1
0x005B3B87  test     ecx, ecx
0x005B3B89  jne      0x5b3bb1
0x005B3B8B  cmp      dword ptr [ebp - 0x44], ecx
0x005B3B8E  ja       0x5b3b9f
0x005B3B90  push     ecx
0x005B3B91  push     ecx
0x005B3B92  push     1
0x005B3B94  push     0xc000008c
0x005B3B99  call     dword ptr [0x715340]
0x005B3B9F  mov      eax, dword ptr [ebp - 0x48]
0x005B3BA2  mov      ecx, dword ptr [eax]
0x005B3BA4  add      ecx, 0xc
0x005B3BA7  call     0x5b3790
0x005B3BAC  jmp      0x5b4384
0x005B3BB1  mov      edx, 0x72b10c
0x005B3BB6  mov      ecx, eax
0x005B3BB8  mov      al, byte ptr [ecx]
0x005B3BBA  cmp      al, byte ptr [edx]
0x005B3BBC  mov      byte ptr [ebp - 0xd], al
0x005B3BBF  lea      eax, [esi + 0xc]
0x005B3BC2  jne      0x5b3be8
0x005B3BC4  cmp      byte ptr [ebp - 0xd], 0
0x005B3BC8  je       0x5b3be4
0x005B3BCA  mov      al, byte ptr [ecx + 1]
0x005B3BCD  cmp      al, byte ptr [edx + 1]
0x005B3BD0  mov      byte ptr [ebp - 0xd], al
0x005B3BD3  lea      eax, [esi + 0xc]
0x005B3BD6  jne      0x5b3be8
0x005B3BD8  add      ecx, 2
0x005B3BDB  add      edx, 2
0x005B3BDE  cmp      byte ptr [ebp - 0xd], 0
0x005B3BE2  jne      0x5b3bb8
0x005B3BE4  xor      ecx, ecx
0x005B3BE6  jmp      0x5b3bed
0x005B3BE8  sbb      ecx, ecx
0x005B3BEA  or       ecx, 1
0x005B3BED  test     ecx, ecx
0x005B3BEF  jne      0x5b3e86
0x005B3BF5  call     0x5b28d0
0x005B3BFA  cmp      dword ptr [ebp - 0x44], 0x28   <<< DOWN
0x005B3BFE  mov      dword ptr [ebp - 0x34], eax
0x005B3C01  jne      0x5b4384
0x005B3C07  mov      ecx, dword ptr [eax + 8]
0x005B3C0A  add      ecx, 0x42e8
0x005B3C10  call     0x5ad820
0x005B3C15  mov      esi, dword ptr [ebp - 0x48]
0x005B3C18  xor      ecx, ecx
0x005B3C1A  mov      edi, dword ptr [ebp - 0x14]
0x005B3C1D  add      esi, 8
0x005B3C20  xor      eax, eax
0x005B3C22  mov      dword ptr [ebp - 0x3c], esi
0x005B3C25  mov      edx, 2
0x005B3C2A  mov      dword ptr [ebp - 0x28], ecx
0x005B3C2D  mov      dword ptr [ebp - 0x24], eax
0x005B3C30  xor      esi, esi
0x005B3C32  mov      dword ptr [ebp - 0x20], edx
0x005B3C35  cmp      dword ptr [ebp + 0xc], 0
0x005B3C39  jne      0x5b3c76
0x005B3C3B  mov      edx, dword ptr [ebp - 0x34]
0x005B3C3E  mov      edx, dword ptr [edx + 8]
0x005B3C41  add      edx, 0x42e8
0x005B3C47  mov      dword ptr [ebp - 0x38], edx
0x005B3C4A  cmp      eax, 7
0x005B3C4D  ja       0x5b3c53
0x005B3C4F  add      edx, esi
0x005B3C51  jmp      0x5b3c6d
0x005B3C53  push     0
0x005B3C55  push     0
0x005B3C57  push     1
0x005B3C59  push     0xc000008c
0x005B3C5E  call     dword ptr [0x715340]
0x005B3C64  mov      eax, dword ptr [ebp - 0x24]
0x005B3C67  mov      ecx, dword ptr [ebp - 0x28]
0x005B3C6A  mov      edx, dword ptr [ebp - 0x38]
0x005B3C6D  cmp      byte ptr [edx + 0x58], 0
0x005B3C71  je       0x5b3c7f
0x005B3C73  mov      edx, dword ptr [ebp - 0x20]
0x005B3C76  cmp      eax, dword ptr [ebp + 0xc]
0x005B3C79  jne      0x5b3e62
0x005B3C7F  mov      eax, dword ptr [ebp - 0x20]
0x005B3C82  add      eax, -2
0x005B3C85  cmp      eax, 0x28   <<< DOWN
0x005B3C88  jb       0x5b3c9b
0x005B3C8A  push     0
0x005B3C8C  push     0
0x005B3C8E  push     1
0x005B3C90  push     0xc000008c
0x005B3C95  call     dword ptr [0x715340]
0x005B3C9B  mov      eax, dword ptr [ebp - 0x3c]
0x005B3C9E  mov      ecx, dword ptr [ebp - 0x28]
0x005B3CA1  add      eax, ecx
0x005B3CA3  mov      dword ptr [ebp - 0x30], eax
0x005B3CA6  mov      eax, dword ptr [eax - 8]
0x005B3CA9  add      eax, 0xc
0x005B3CAC  mov      dword ptr [ebp - 0x40], eax
0x005B3CAF  mov      eax, dword ptr [ebp - 0x34]
0x005B3CB2  add      eax, 0x44
0x005B3CB5  cmp      dword ptr [ebp - 0x24], 7
0x005B3CB9  mov      dword ptr [ebp - 0x18], eax
0x005B3CBC  ja       0x5b3cc5
0x005B3CBE  add      eax, ecx
0x005B3CC0  mov      dword ptr [ebp - 0x38], eax
0x005B3CC3  jmp      0x5b3cdc
0x005B3CC5  push     0
0x005B3CC7  push     0
0x005B3CC9  push     1
0x005B3CCB  push     0xc000008c
0x005B3CD0  call     dword ptr [0x715340]
0x005B3CD6  mov      ecx, dword ptr [ebp - 0x18]
0x005B3CD9  mov      dword ptr [ebp - 0x38], ecx
0x005B3CDC  push     dword ptr [ebp - 0x40]
0x005B3CDF  call     0x6db7d7
0x005B3CE4  mov      ecx, dword ptr [ebp - 0x38]
0x005B3CE7  add      esp, 4
0x005B3CEA  mov      dword ptr [ecx], eax
0x005B3CEC  mov      eax, dword ptr [ebp - 0x20]
0x005B3CEF  dec      eax
0x005B3CF0  cmp      eax, 0x28   <<< DOWN
0x005B3CF3  jb       0x5b3d06
0x005B3CF5  push     0
0x005B3CF7  push     0
0x005B3CF9  push     1
0x005B3CFB  push     0xc000008c
0x005B3D00  call     dword ptr [0x715340]
0x005B3D06  mov      eax, dword ptr [ebp - 0x30]
0x005B3D09  mov      eax, dword ptr [eax - 4]
0x005B3D0C  add      eax, 0xc
0x005B3D0F  cmp      dword ptr [ebp - 0x24], 7
0x005B3D13  mov      dword ptr [ebp - 0x40], eax
0x005B3D16  ja       0x5b3d20
0x005B3D18  mov      eax, dword ptr [ebp - 0x18]
0x005B3D1B  add      eax, dword ptr [ebp - 0x28]
0x005B3D1E  jmp      0x5b3d34
0x005B3D20  push     0
0x005B3D22  push     0
0x005B3D24  push     1
0x005B3D26  push     0xc000008c
0x005B3D2B  call     dword ptr [0x715340]
0x005B3D31  mov      eax, dword ptr [ebp - 0x18]
0x005B3D34  push     dword ptr [ebp - 0x40]
0x005B3D37  mov      dword ptr [ebp - 0x38], eax
0x005B3D3A  call     0x6db7d7
0x005B3D3F  mov      ecx, dword ptr [ebp - 0x38]
0x005B3D42  add      esp, 4
0x005B3D45  cmp      dword ptr [ebp - 0x20], 0x28   <<< DOWN
0x005B3D49  mov      dword ptr [ecx + 4], eax
0x005B3D4C  jb       0x5b3d5f
0x005B3D4E  push     0
0x005B3D50  push     0
0x005B3D52  push     1
0x005B3D54  push     0xc000008c
0x005B3D59  call     dword ptr [0x715340]
0x005B3D5F  mov      eax, dword ptr [ebp - 0x30]
0x005B3D62  mov      eax, dword ptr [eax]
0x005B3D64  add      eax, 0xc
0x005B3D67  cmp      dword ptr [ebp - 0x24], 7
0x005B3D6B  mov      dword ptr [ebp - 0x40], eax
0x005B3D6E  ja       0x5b3d78
0x005B3D70  mov      eax, dword ptr [ebp - 0x18]
0x005B3D73  add      eax, dword ptr [ebp - 0x28]
0x005B3D76  jmp      0x5b3d8c
0x005B3D78  push     0
0x005B3D7A  push     0
0x005B3D7C  push     1
0x005B3D7E  push     0xc000008c
0x005B3D83  call     dword ptr [0x715340]
0x005B3D89  mov      eax, dword ptr [ebp - 0x18]
0x005B3D8C  push     dword ptr [ebp - 0x40]
0x005B3D8F  mov      dword ptr [ebp - 0x38], eax
0x005B3D92  call     0x6db7d7
0x005B3D97  mov      ecx, dword ptr [ebp - 0x38]
0x005B3D9A  add      esp, 4
0x005B3D9D  mov      dword ptr [ecx + 8], eax
0x005B3DA0  mov      eax, dword ptr [ebp - 0x20]
0x005B3DA3  inc      eax
0x005B3DA4  cmp      eax, 0x28   <<< DOWN
0x005B3DA7  jb       0x5b3dba
0x005B3DA9  push     0
0x005B3DAB  push     0
0x005B3DAD  push     1
0x005B3DAF  push     0xc000008c
0x005B3DB4  call     dword ptr [0x715340]
0x005B3DBA  mov      eax, dword ptr [ebp - 0x30]
0x005B3DBD  mov      eax, dword ptr [eax + 4]
0x005B3DC0  add      eax, 0xc
0x005B3DC3  cmp      dword ptr [ebp - 0x24], 7
0x005B3DC7  mov      dword ptr [ebp - 0x40], eax
0x005B3DCA  ja       0x5b3dd4
0x005B3DCC  mov      eax, dword ptr [ebp - 0x18]
0x005B3DCF  add      eax, dword ptr [ebp - 0x28]
0x005B3DD2  jmp      0x5b3de8
0x005B3DD4  push     0
0x005B3DD6  push     0
0x005B3DD8  push     1
0x005B3DDA  push     0xc000008c
0x005B3DDF  call     dword ptr [0x715340]
0x005B3DE5  mov      eax, dword ptr [ebp - 0x18]
0x005B3DE8  push     dword ptr [ebp - 0x40]
0x005B3DEB  mov      dword ptr [ebp - 0x38], eax
0x005B3DEE  call     0x6db7d7
0x005B3DF3  mov      ecx, dword ptr [ebp - 0x38]
0x005B3DF6  add      esp, 4
0x005B3DF9  mov      dword ptr [ecx + 0xc], eax
0x005B3DFC  mov      eax, dword ptr [ebp - 0x20]
0x005B3DFF  add      eax, 2
0x005B3E02  cmp      eax, 0x28   <<< DOWN
0x005B3E05  jb       0x5b3e18
0x005B3E07  push     0
0x005B3E09  push     0
0x005B3E0B  push     1
0x005B3E0D  push     0xc000008c
0x005B3E12  call     dword ptr [0x715340]
0x005B3E18  mov      eax, dword ptr [ebp - 0x30]
0x005B3E1B  mov      eax, dword ptr [eax + 8]
0x005B3E1E  add      eax, 0xc
0x005B3E21  cmp      dword ptr [ebp - 0x24], 7
0x005B3E25  mov      dword ptr [ebp - 0x40], eax
0x005B3E28  ja       0x5b3e32
0x005B3E2A  mov      ecx, dword ptr [ebp - 0x28]
0x005B3E2D  add      dword ptr [ebp - 0x18], ecx
0x005B3E30  jmp      0x5b3e43
0x005B3E32  push     0
0x005B3E34  push     0
0x005B3E36  push     1
0x005B3E38  push     0xc000008c
0x005B3E3D  call     dword ptr [0x715340]
0x005B3E43  push     dword ptr [ebp - 0x40]
0x005B3E46  call     0x6db7d7
0x005B3E4B  mov      ecx, dword ptr [ebp - 0x18]
0x005B3E4E  add      esp, 4
0x005B3E51  mov      edx, dword ptr [ebp - 0x20]
0x005B3E54  test     eax, eax
0x005B3E56  setne    al
0x005B3E59  mov      byte ptr [ecx + 0x10], al
0x005B3E5C  mov      eax, dword ptr [ebp - 0x24]
0x005B3E5F  mov      ecx, dword ptr [ebp - 0x28]
0x005B3E62  inc      eax
0x005B3E63  add      edx, 5
0x005B3E66  add      ecx, 0x14
0x005B3E69  mov      dword ptr [ebp - 0x20], edx
0x005B3E6C  add      esi, 0x60
0x005B3E6F  mov      dword ptr [ebp - 0x24], eax
0x005B3E72  mov      dword ptr [ebp - 0x28], ecx
0x005B3E75  cmp      eax, 8
0x005B3E78  jl       0x5b3c35
0x005B3E7E  mov      esi, dword ptr [ebp - 0x2c]
0x005B3E81  .byte    0xe9


======== candidate 0x006BF9B2 - 0x006BFACE ========
0x006BF9B2  jb       0x6bf9b4
0x006BF9B4  push     ecx
0x006BF9B5  mov      byte ptr [0x772de0], 0
0x006BF9BC  mov      byte ptr [0x7733e0], 0
0x006BF9C3  mov      byte ptr [0x772fe0], 0
0x006BF9CA  call     0x6d9a25
0x006BF9CF  mov      ecx, eax
0x006BF9D1  add      esp, 8
0x006BF9D4  test     ecx, ecx
0x006BF9D6  je       0x6bfa6d
0x006BF9DC  mov      edx, 0x772fe0
0x006BF9E1  sub      edx, ecx
0x006BF9E3  mov      al, byte ptr [ecx]
0x006BF9E5  lea      ecx, [ecx + 1]
0x006BF9E8  mov      byte ptr [edx + ecx - 1], al
0x006BF9EC  test     al, al
0x006BF9EE  jne      0x6bf9e3
0x006BF9F0  push     0x72127c
0x006BF9F5  push     0
0x006BF9F7  call     0x6d9a25
0x006BF9FC  mov      ecx, eax
0x006BF9FE  add      esp, 8
0x006BFA01  test     ecx, ecx
0x006BFA03  je       0x6bfa6d
0x006BFA05  mov      edx, 0x7733e0
0x006BFA0A  sub      edx, ecx
0x006BFA0C  nop      dword ptr [eax]
0x006BFA10  mov      al, byte ptr [ecx]
0x006BFA12  lea      ecx, [ecx + 1]
0x006BFA15  mov      byte ptr [edx + ecx - 1], al
0x006BFA19  test     al, al
0x006BFA1B  jne      0x6bfa10
0x006BFA1D  push     0x71ce50
0x006BFA22  push     0
0x006BFA24  call     0x6d9a25
0x006BFA29  mov      ecx, eax
0x006BFA2B  add      esp, 8
0x006BFA2E  test     ecx, ecx
0x006BFA30  je       0x6bfa6d
0x006BFA32  cmp      byte ptr [ecx], 0x27   <<< RIGHT
0x006BFA35  jne      0x6bfa38
0x006BFA37  inc      ecx
0x006BFA38  mov      edx, ecx
0x006BFA3A  lea      esi, [edx + 1]
0x006BFA3D  nop      dword ptr [eax]
0x006BFA40  mov      al, byte ptr [edx]
0x006BFA42  inc      edx
0x006BFA43  test     al, al
0x006BFA45  jne      0x6bfa40
0x006BFA47  sub      edx, esi
0x006BFA49  dec      edx
0x006BFA4A  test     edx, edx
0x006BFA4C  jle      0x6bfa57
0x006BFA4E  cmp      byte ptr [ecx + edx], 0x27   <<< RIGHT
0x006BFA52  jne      0x6bfa57
0x006BFA54  mov      byte ptr [ecx + edx], al
0x006BFA57  mov      edx, 0x772de0
0x006BFA5C  sub      edx, ecx
0x006BFA5E  nop      
0x006BFA60  mov      al, byte ptr [ecx]
0x006BFA62  lea      ecx, [ecx + 1]
0x006BFA65  mov      byte ptr [edx + ecx - 1], al
0x006BFA69  test     al, al
0x006BFA6B  jne      0x6bfa60
0x006BFA6D  cmp      byte ptr [0x772fe0], 0x7d
0x006BFA74  jne      0x6bfa8c
0x006BFA76  xor      al, al
0x006BFA78  mov      ecx, dword ptr [ebp - 0xc]
0x006BFA7B  mov      dword ptr fs:[0], ecx
0x006BFA82  pop      ecx
0x006BFA83  pop      edi
0x006BFA84  pop      esi
0x006BFA85  pop      ebx
0x006BFA86  mov      esp, ebp
0x006BFA88  pop      ebp
0x006BFA89  ret      4
0x006BFA8C  push     0x772fe0
0x006BFA91  lea      ecx, [edi + 8]
0x006BFA94  call     0x6b9200
0x006BFA99  push     0x772de0
0x006BFA9E  lea      ecx, [edi + 0xc]
0x006BFAA1  call     0x6b9200
0x006BFAA6  cmp      byte ptr [0x7733e0], 0x7b
0x006BFAAD  jne      0x6bfb52
0x006BFAB3  nop      dword ptr [eax]
0x006BFAB7  nop      word ptr [eax + eax]
0x006BFAC0  push     0x291
0x006BFAC5  mov      edx, 0x736984
0x006BFACA  .byte    0xb9
0x006BFACB  adc      al, 0
0x006BFACD  .byte    0x00


======== candidate 0x006C014C - 0x006C0306 ========
0x006C014C  .byte    0xf0
0x006C014D  cmpsd    dword ptr [esi], dword ptr es:[edi]
0x006C014E  .byte    0xff
0x006C014F  dec      dword ptr [ebp + 0x4d8b0c47]
0x006C0155  hlt      
0x006C0156  mov      dword ptr fs:[0], ecx
0x006C015D  pop      ecx
0x006C015E  pop      edi
0x006C015F  pop      esi
0x006C0160  pop      ebx
0x006C0161  mov      ecx, dword ptr [ebp - 0x10]
0x006C0164  xor      ecx, ebp
0x006C0166  call     0x6ce927
0x006C016B  mov      esp, ebp
0x006C016D  pop      ebp
0x006C016E  ret      4
0x006C0171  call     0x6cf080
0x006C0176  int3     
0x006C0177  int3     
0x006C0178  int3     
0x006C0179  int3     
0x006C017A  int3     
0x006C017B  int3     
0x006C017C  int3     
0x006C017D  int3     
0x006C017E  int3     
0x006C017F  int3     
0x006C0180  push     ecx
0x006C0181  call     dword ptr [0x715308]
0x006C0187  ret      
0x006C0188  int3     
0x006C0189  int3     
0x006C018A  int3     
0x006C018B  int3     
0x006C018C  int3     
0x006C018D  int3     
0x006C018E  int3     
0x006C018F  int3     
0x006C0190  push     ebp
0x006C0191  mov      ebp, esp
0x006C0193  push     ebx
0x006C0194  push     esi
0x006C0195  mov      esi, ecx
0x006C0197  push     edi
0x006C0198  mov      edi, edx
0x006C019A  mov      bl, byte ptr [esi + 3]
0x006C019D  lea      eax, [ebx - 0x61]
0x006C01A0  cmp      al, 0x19
0x006C01A2  ja       0x6c01ac
0x006C01A4  movsx    edx, bl
0x006C01A7  sub      edx, 0x61
0x006C01AA  jmp      0x6c01d5
0x006C01AC  lea      eax, [ebx - 0x41]
0x006C01AF  cmp      al, 0x19
0x006C01B1  ja       0x6c01bb
0x006C01B3  movsx    edx, bl
0x006C01B6  sub      edx, 0x27
0x006C01B9  jmp      0x6c01d5
0x006C01BB  lea      eax, [ebx - 0x30]
0x006C01BE  cmp      al, 9
0x006C01C0  ja       0x6c01ca
0x006C01C2  movsx    edx, bl
0x006C01C5  add      edx, 4
0x006C01C8  jmp      0x6c01d5
0x006C01CA  xor      edx, edx
0x006C01CC  cmp      bl, 0x26   <<< UP
0x006C01CF  setne    dl
0x006C01D2  add      edx, 0x3e
0x006C01D5  mov      cl, byte ptr [esi + 2]
0x006C01D8  lea      eax, [ecx - 0x61]
0x006C01DB  cmp      al, 0x19
0x006C01DD  ja       0x6c01e7
0x006C01DF  movsx    eax, cl
0x006C01E2  sub      eax, 0x61
0x006C01E5  jmp      0x6c0210
0x006C01E7  lea      eax, [ecx - 0x41]
0x006C01EA  cmp      al, 0x19
0x006C01EC  ja       0x6c01f6
0x006C01EE  movsx    eax, cl
0x006C01F1  sub      eax, 0x27
0x006C01F4  jmp      0x6c0210
0x006C01F6  lea      eax, [ecx - 0x30]
0x006C01F9  cmp      al, 9
0x006C01FB  ja       0x6c0205
0x006C01FD  movsx    eax, cl
0x006C0200  add      eax, 4
0x006C0203  jmp      0x6c0210
0x006C0205  xor      eax, eax
0x006C0207  cmp      cl, 0x26   <<< UP
0x006C020A  setne    al
0x006C020D  add      eax, 0x3e
0x006C0210  mov      cl, byte ptr [esi + 1]
0x006C0213  shl      edx, 6
0x006C0216  or       edx, eax
0x006C0218  lea      eax, [ecx - 0x61]
0x006C021B  cmp      al, 0x19
0x006C021D  ja       0x6c0227
0x006C021F  movsx    eax, cl
0x006C0222  sub      eax, 0x61
0x006C0225  jmp      0x6c0250
0x006C0227  lea      eax, [ecx - 0x41]
0x006C022A  cmp      al, 0x19
0x006C022C  ja       0x6c0236
0x006C022E  movsx    eax, cl
0x006C0231  sub      eax, 0x27
0x006C0234  jmp      0x6c0250
0x006C0236  lea      eax, [ecx - 0x30]
0x006C0239  cmp      al, 9
0x006C023B  ja       0x6c0245
0x006C023D  movsx    eax, cl
0x006C0240  add      eax, 4
0x006C0243  jmp      0x6c0250
0x006C0245  xor      eax, eax
0x006C0247  cmp      cl, 0x26   <<< UP
0x006C024A  setne    al
0x006C024D  add      eax, 0x3e
0x006C0250  mov      cl, byte ptr [esi]
0x006C0252  shl      edx, 6
0x006C0255  or       edx, eax
0x006C0257  lea      eax, [ecx - 0x61]
0x006C025A  cmp      al, 0x19
0x006C025C  ja       0x6c0266
0x006C025E  movsx    eax, cl
0x006C0261  sub      eax, 0x61
0x006C0264  jmp      0x6c028f
0x006C0266  lea      eax, [ecx - 0x41]
0x006C0269  cmp      al, 0x19
0x006C026B  ja       0x6c0275
0x006C026D  movsx    eax, cl
0x006C0270  sub      eax, 0x27
0x006C0273  jmp      0x6c028f
0x006C0275  lea      eax, [ecx - 0x30]
0x006C0278  cmp      al, 9
0x006C027A  ja       0x6c0284
0x006C027C  movsx    eax, cl
0x006C027F  add      eax, 4
0x006C0282  jmp      0x6c028f
0x006C0284  xor      eax, eax
0x006C0286  cmp      cl, 0x26   <<< UP
0x006C0289  setne    al
0x006C028C  add      eax, 0x3e
0x006C028F  shl      edx, 6
0x006C0292  or       edx, eax
0x006C0294  mov      eax, dword ptr [ebp + 8]
0x006C0297  mov      ecx, edx
0x006C0299  mov      byte ptr [edi], dl
0x006C029B  shr      ecx, 8
0x006C029E  pop      edi
0x006C029F  mov      byte ptr [eax], cl
0x006C02A1  mov      eax, dword ptr [ebp + 0xc]
0x006C02A4  shr      edx, 0x10
0x006C02A7  pop      esi
0x006C02A8  pop      ebx
0x006C02A9  mov      byte ptr [eax], dl
0x006C02AB  pop      ebp
0x006C02AC  ret      
0x006C02AD  int3     
0x006C02AE  int3     
0x006C02AF  int3     
0x006C02B0  push     ebp
0x006C02B1  mov      ebp, esp
0x006C02B3  push     ecx
0x006C02B4  lea      eax, [ebp - 1]
0x006C02B7  push     eax
0x006C02B8  lea      eax, [ebp - 2]
0x006C02BB  push     eax
0x006C02BC  lea      edx, [ebp - 3]
0x006C02BF  call     0x6c0190
0x006C02C4  movzx    eax, byte ptr [ebp - 1]
0x006C02C8  add      esp, 8
0x006C02CB  movzx    ecx, byte ptr [ebp - 2]
0x006C02CF  shl      eax, 8
0x006C02D2  or       eax, ecx
0x006C02D4  movzx    ecx, byte ptr [ebp - 3]
0x006C02D8  shl      eax, 8
0x006C02DB  or       eax, ecx
0x006C02DD  mov      esp, ebp
0x006C02DF  pop      ebp
0x006C02E0  ret      
0x006C02E1  int3     
0x006C02E2  int3     
0x006C02E3  int3     
0x006C02E4  int3     
0x006C02E5  int3     
0x006C02E6  int3     
0x006C02E7  int3     
0x006C02E8  int3     
0x006C02E9  int3     
0x006C02EA  int3     
0x006C02EB  int3     
0x006C02EC  int3     
0x006C02ED  int3     
0x006C02EE  int3     
0x006C02EF  int3     
0x006C02F0  mov      dword ptr [ecx], 0
0x006C02F6  mov      eax, ecx
0x006C02F8  mov      dword ptr [ecx + 4], 0
0x006C02FF  mov      dword ptr [ecx + 0x10], 0


======== candidate 0x006D62B7 - 0x006D6446 ========
0x006D62B7  inc      esi
0x006D62B8  or       byte ptr [ebx + 0x470ff0e], cl
0x006D62BE  push     dword ptr [eax]
0x006D62C0  call     0x6d8ff8
0x006D62C5  pop      esi
0x006D62C6  ret      
0x006D62C7  mov      edi, edi
0x006D62C9  push     ebx
0x006D62CA  push     esi
0x006D62CB  mov      esi, ecx
0x006D62CD  xor      ebx, ebx
0x006D62CF  cmp      dword ptr [esi + 0xc], ebx
0x006D62D2  jne      0x6d62fd
0x006D62D4  mov      eax, dword ptr [esi + 8]
0x006D62D7  mov      dword ptr [esi + 0x10], ebx
0x006D62DA  mov      word ptr [esi + 0x14], bx
0x006D62DE  mov      byte ptr [esi + 0x16], bl
0x006D62E1  mov      dword ptr [esi + 0x18], ebx
0x006D62E4  mov      dword ptr [esi + 0x1c], ebx
0x006D62E7  mov      dword ptr [esi + 0x20], ebx
0x006D62EA  mov      byte ptr [esi + 0x24], bl
0x006D62ED  mov      dword ptr [esi + 0x28], ebx
0x006D62F0  mov      al, byte ptr [eax]
0x006D62F2  test     al, al
0x006D62F4  jne      0x6d6302
0x006D62F6  mov      dword ptr [esi + 0x10], 1
0x006D62FD  xor      al, al
0x006D62FF  pop      esi
0x006D6300  pop      ebx
0x006D6301  ret      
0x006D6302  movzx    eax, al
0x006D6305  push     eax
0x006D6306  call     0x6d99f4
0x006D630B  pop      ecx
0x006D630C  mov      ecx, dword ptr [esi + 8]
0x006D630F  test     eax, eax
0x006D6311  je       0x6d6337
0x006D6313  mov      dword ptr [esi + 0x10], 2
0x006D631A  movzx    eax, byte ptr [ecx]
0x006D631D  jmp      0x6d6328
0x006D631F  inc      dword ptr [esi + 8]
0x006D6322  mov      eax, dword ptr [esi + 8]
0x006D6325  movzx    eax, byte ptr [eax]
0x006D6328  push     eax
0x006D6329  call     0x6d99f4
0x006D632E  pop      ecx
0x006D632F  test     eax, eax
0x006D6331  jne      0x6d631f
0x006D6333  mov      al, 1
0x006D6335  jmp      0x6d62ff
0x006D6337  cmp      byte ptr [ecx], 0x25   <<< LEFT
0x006D633A  jne      0x6d63b8
0x006D633C  lea      eax, [ecx + 1]
0x006D633F  cmp      byte ptr [eax], 0x25   <<< LEFT
0x006D6342  je       0x6d63b8
0x006D6344  mov      dword ptr [esi + 0x10], 4
0x006D634B  mov      dword ptr [esi + 8], eax
0x006D634E  cmp      byte ptr [eax], 0x2a
0x006D6351  jne      0x6d635b
0x006D6353  inc      eax
0x006D6354  mov      byte ptr [esi + 0x16], 1
0x006D6358  mov      dword ptr [esi + 8], eax
0x006D635B  mov      ecx, esi
0x006D635D  call     0x6d918d
0x006D6362  test     al, al
0x006D6364  je       0x6d62fd
0x006D6366  mov      ecx, esi
0x006D6368  call     0x6d922a
0x006D636D  mov      ecx, esi
0x006D636F  call     0x6d938b
0x006D6374  mov      ecx, esi
0x006D6376  call     0x6d901d
0x006D637B  test     al, al
0x006D637D  je       0x6d62fd
0x006D6383  imul     ecx, dword ptr [esi + 0x28], 0xc
0x006D6387  mov      eax, dword ptr [esi + 0x20]
0x006D638A  cmp      byte ptr [ecx + eax + 0x716e28], bl
0x006D6391  jne      0x6d6333
0x006D6393  mov      dword ptr [esi + 0x10], ebx
0x006D6396  mov      word ptr [esi + 0x14], bx
0x006D639A  mov      byte ptr [esi + 0x16], bl
0x006D639D  mov      dword ptr [esi + 0x18], ebx
0x006D63A0  mov      dword ptr [esi + 0x1c], ebx
0x006D63A3  mov      dword ptr [esi + 0x20], ebx
0x006D63A6  mov      byte ptr [esi + 0x24], bl
0x006D63A9  mov      dword ptr [esi + 0x28], ebx
0x006D63AC  mov      dword ptr [esi + 0xc], 0x16
0x006D63B3  jmp      0x6d62fd
0x006D63B8  mov      dword ptr [esi + 0x10], 3
0x006D63BF  mov      al, byte ptr [ecx]
0x006D63C1  mov      byte ptr [esi + 0x14], al
0x006D63C4  xor      eax, eax
0x006D63C6  cmp      byte ptr [ecx], 0x25   <<< LEFT
0x006D63C9  push     ebx
0x006D63CA  sete     al
0x006D63CD  inc      ecx
0x006D63CE  add      eax, ecx
0x006D63D0  mov      ecx, esi
0x006D63D2  mov      dword ptr [esi + 8], eax
0x006D63D5  call     0x6d9339
0x006D63DA  jmp      0x6d62ff
0x006D63DF  cmp      byte ptr [ecx + 4], 0
0x006D63E3  je       0x6d63e8
0x006D63E5  mov      eax, dword ptr [ecx]
0x006D63E7  ret      
0x006D63E8  push     0
0x006D63EA  push     0x19f
0x006D63EF  push     0x716cd0
0x006D63F4  push     0x716d38
0x006D63F9  push     0x716d94
0x006D63FE  call     0x6e511d
0x006D6403  int3     
0x006D6404  cmp      byte ptr [ecx + 4], 0
0x006D6408  jne      0x6d640d
0x006D640A  mov      eax, dword ptr [ecx]
0x006D640C  ret      
0x006D640D  push     0
0x006D640F  push     0x1a5
0x006D6414  push     0x716cd0
0x006D6419  push     0x716db0
0x006D641E  push     0x716e0c
0x006D6423  call     0x6e511d
0x006D6428  int3     
0x006D6429  mov      edi, edi
0x006D642B  push     ebp
0x006D642C  mov      ebp, esp
0x006D642E  mov      ecx, dword ptr [ebp + 0xc]
0x006D6431  cmp      byte ptr [ecx + 4], 0
0x006D6435  je       0x6d6453
0x006D6437  call     0x6d63df
0x006D643C  mov      ecx, eax
0x006D643E  movzx    eax, byte ptr [ebp + 8]
0x006D6442  cdq      
0x006D6443  shl      eax, 0x1f


======== candidate 0x006EAC9B - 0x006EB099 ========
0x006EAC9B  mov      eax, dword ptr [ebx]
0x006EAC9D  test     eax, eax
0x006EAC9F  je       0x6eacb8
0x006EACA1  mov      ecx, dword ptr [esi]
0x006EACA3  mov      ax, word ptr [edi]
0x006EACA6  add      edi, 2
0x006EACA9  mov      word ptr [ecx], ax
0x006EACAC  add      dword ptr [esi], 2
0x006EACAF  dec      dword ptr [ebx]
0x006EACB1  dec      edx
0x006EACB2  mov      eax, dword ptr [ebx]
0x006EACB4  test     edx, edx
0x006EACB6  jg       0x6eac9d
0x006EACB8  mov      esi, dword ptr [ebp - 0x18]
0x006EACBB  push     esi
0x006EACBC  call     0x6e35c0
0x006EACC1  pop      ecx
0x006EACC2  mov      al, 1
0x006EACC4  lea      esp, [ebp - 0x3c]
0x006EACC7  pop      edi
0x006EACC8  pop      esi
0x006EACC9  pop      ebx
0x006EACCA  mov      ecx, dword ptr [ebp - 4]
0x006EACCD  xor      ecx, ebp
0x006EACCF  call     0x6ce927
0x006EACD4  leave    
0x006EACD5  ret      
0x006EACD6  push     0
0x006EACD8  call     0x6e35c0
0x006EACDD  pop      ecx
0x006EACDE  mov      ebx, dword ptr [ebp - 0x24]
0x006EACE1  jmp      0x6eaf59
0x006EACE6  mov      esi, dword ptr [ebx]
0x006EACE8  test     esi, esi
0x006EACEA  je       0x6eacc2
0x006EACEC  mov      byte ptr [ebp - 0x20], 0
0x006EACF0  xor      eax, eax
0x006EACF2  mov      dword ptr [ebp - 0x18], edi
0x006EACF5  mov      ebx, edi
0x006EACF7  movzx    ecx, dx
0x006EACFA  add      ebx, 2
0x006EACFD  inc      eax
0x006EACFE  cmp      word ptr [ebx], cx
0x006EAD01  je       0x6eacfa
0x006EAD03  movzx    ecx, dx
0x006EAD06  mov      dword ptr [ebp - 0x18], ebx
0x006EAD09  mov      ebx, dword ptr [ebp - 0x24]
0x006EAD0C  cmp      ecx, 0x64
0x006EAD0F  ja       0x6eae39
0x006EAD15  je       0x6eae08
0x006EAD1B  cmp      ecx, 0x27   <<< RIGHT
0x006EAD1E  je       0x6eadbe
0x006EAD24  cmp      ecx, 0x41   <<< A
0x006EAD27  je       0x6ead3c
0x006EAD29  cmp      ecx, 0x48
0x006EAD2C  je       0x6ead86
0x006EAD2E  cmp      ecx, 0x4d
0x006EAD31  je       0x6ead55
0x006EAD33  cmp      ecx, 0x61
0x006EAD36  jne      0x6eaf20
0x006EAD3C  push     0x7189e4
0x006EAD41  push     edi
0x006EAD42  call     0x6f1e18
0x006EAD47  pop      ecx
0x006EAD48  pop      ecx
0x006EAD49  test     eax, eax
0x006EAD4B  jne      0x6eada0
0x006EAD4D  lea      ecx, [edi + 0xa]
0x006EAD50  mov      dword ptr [ebp - 0x18], ecx
0x006EAD53  jmp      0x6eadb7
0x006EAD55  sub      eax, 1
0x006EAD58  je       0x6ead7b
0x006EAD5A  sub      eax, 1
0x006EAD5D  je       0x6ead7f
0x006EAD5F  sub      eax, 1
0x006EAD62  je       0x6ead74
0x006EAD64  sub      eax, 1
0x006EAD67  jne      0x6eaf20
0x006EAD6D  push     0x42
0x006EAD6F  jmp      0x6eaf38
0x006EAD74  push     0x62
0x006EAD76  jmp      0x6eaf38
0x006EAD7B  mov      byte ptr [ebp - 0x20], 1
0x006EAD7F  push     0x6d
0x006EAD81  jmp      0x6eaf38
0x006EAD86  sub      eax, 1
0x006EAD89  je       0x6ead95
0x006EAD8B  sub      eax, 1
0x006EAD8E  je       0x6ead99
0x006EAD90  jmp      0x6eaf20
0x006EAD95  mov      byte ptr [ebp - 0x20], 1
0x006EAD99  push     0x48
0x006EAD9B  jmp      0x6eaf38
0x006EADA0  push     0x7189f0
0x006EADA5  push     edi
0x006EADA6  call     0x6f1e18
0x006EADAB  pop      ecx
0x006EADAC  pop      ecx
0x006EADAD  test     eax, eax
0x006EADAF  jne      0x6eadb7
0x006EADB1  lea      eax, [edi + 6]
0x006EADB4  mov      dword ptr [ebp - 0x18], eax
0x006EADB7  push     0x70
0x006EADB9  jmp      0x6eaf38
0x006EADBE  lea      edi, [edi + eax*2]
0x006EADC1  test     al, 1
0x006EADC3  je       0x6eaf59
0x006EADC9  movzx    ecx, word ptr [edi]
0x006EADCC  test     cx, cx
0x006EADCF  je       0x6eacc2
0x006EADD5  mov      edx, dword ptr [ebp - 0x1c]
0x006EADD8  test     esi, esi
0x006EADDA  je       0x6eaf59
0x006EADE0  push     0x27
0x006EADE2  pop      eax
0x006EADE3  add      edi, 2
0x006EADE6  cmp      cx, ax
0x006EADE9  je       0x6eaf59
0x006EADEF  mov      eax, dword ptr [edx]
0x006EADF1  mov      word ptr [eax], cx
0x006EADF4  add      dword ptr [edx], 2
0x006EADF7  dec      dword ptr [ebx]
0x006EADF9  movzx    ecx, word ptr [edi]
0x006EADFC  mov      esi, dword ptr [ebx]
0x006EADFE  test     cx, cx
0x006EAE01  jne      0x6eadd8
0x006EAE03  jmp      0x6eaf59
0x006EAE08  sub      eax, 1
0x006EAE0B  je       0x6eae2e
0x006EAE0D  sub      eax, 1
0x006EAE10  je       0x6eae32
0x006EAE12  sub      eax, 1
0x006EAE15  je       0x6eae27
0x006EAE17  sub      eax, 1
0x006EAE1A  jne      0x6eaf20
0x006EAE20  push     0x41
0x006EAE22  jmp      0x6eaf38
0x006EAE27  push     0x61
0x006EAE29  jmp      0x6eaf38
0x006EAE2E  mov      byte ptr [ebp - 0x20], 1
0x006EAE32  push     0x64
0x006EAE34  jmp      0x6eaf38
0x006EAE39  sub      ecx, 0x68
0x006EAE3C  je       0x6eaf16
0x006EAE42  sub      ecx, 5
0x006EAE45  je       0x6eaf02
0x006EAE4B  sub      ecx, 6
0x006EAE4E  je       0x6eaeee
0x006EAE54  sub      ecx, 1
0x006EAE57  je       0x6eae80
0x006EAE59  sub      ecx, 5
0x006EAE5C  jne      0x6eaf20
0x006EAE62  dec      eax
0x006EAE63  sub      eax, 1
0x006EAE66  je       0x6eae79
0x006EAE68  dec      eax
0x006EAE69  sub      eax, 1
0x006EAE6C  jne      0x6eaf20
0x006EAE72  push     0x59
0x006EAE74  jmp      0x6eaf38
0x006EAE79  push     0x79
0x006EAE7B  jmp      0x6eaf38
0x006EAE80  mov      ecx, dword ptr [ebp - 0x2c]
0x006EAE83  cmp      dword ptr [ecx + 8], 0xb
0x006EAE87  mov      ecx, dword ptr [ebp - 0x28]
0x006EAE8A  jg       0x6eae94
0x006EAE8C  mov      edx, dword ptr [ecx + 0x14c]
0x006EAE92  jmp      0x6eae9a
0x006EAE94  mov      edx, dword ptr [ecx + 0x150]
0x006EAE9A  cmp      eax, 1
0x006EAE9D  jne      0x6eaebb
0x006EAE9F  test     esi, esi
0x006EAEA1  je       0x6eaebb
0x006EAEA3  mov      eax, dword ptr [ebp - 0x1c]
0x006EAEA6  mov      ecx, dword ptr [eax]
0x006EAEA8  mov      ax, word ptr [edx]
0x006EAEAB  mov      word ptr [ecx], ax
0x006EAEAE  mov      eax, dword ptr [ebp - 0x1c]
0x006EAEB1  add      dword ptr [eax], 2
0x006EAEB4  dec      dword ptr [ebx]
0x006EAEB6  jmp      0x6eaf56
0x006EAEBB  movzx    ecx, word ptr [edx]
0x006EAEBE  test     cx, cx
0x006EAEC1  je       0x6eaf56
0x006EAEC7  mov      eax, dword ptr [ebp - 0x1c]
0x006EAECA  test     esi, esi
0x006EAECC  je       0x6eaf56
0x006EAED2  mov      eax, dword ptr [eax]
0x006EAED4  add      edx, 2
0x006EAED7  mov      word ptr [eax], cx
0x006EAEDA  mov      eax, dword ptr [ebp - 0x1c]
0x006EAEDD  add      dword ptr [eax], 2
0x006EAEE0  dec      dword ptr [ebx]
0x006EAEE2  movzx    ecx, word ptr [edx]
0x006EAEE5  mov      esi, dword ptr [ebx]
0x006EAEE7  test     cx, cx
0x006EAEEA  jne      0x6eaeca
0x006EAEEC  jmp      0x6eaf56
0x006EAEEE  sub      eax, 1
0x006EAEF1  je       0x6eaefa
0x006EAEF3  sub      eax, 1
0x006EAEF6  je       0x6eaefe
0x006EAEF8  jmp      0x6eaf20
0x006EAEFA  mov      byte ptr [ebp - 0x20], 1
0x006EAEFE  push     0x53
0x006EAF00  jmp      0x6eaf38
0x006EAF02  sub      eax, 1
0x006EAF05  je       0x6eaf0e
0x006EAF07  sub      eax, 1
0x006EAF0A  je       0x6eaf12
0x006EAF0C  jmp      0x6eaf20
0x006EAF0E  mov      byte ptr [ebp - 0x20], 1
0x006EAF12  push     0x4d
0x006EAF14  jmp      0x6eaf38
0x006EAF16  sub      eax, 1
0x006EAF19  je       0x6eaf32
0x006EAF1B  sub      eax, 1
0x006EAF1E  je       0x6eaf36
0x006EAF20  mov      ecx, dword ptr [ebp - 0x1c]
0x006EAF23  add      edi, 2
0x006EAF26  mov      eax, dword ptr [ecx]
0x006EAF28  mov      word ptr [eax], dx
0x006EAF2B  add      dword ptr [ecx], 2
0x006EAF2E  dec      dword ptr [ebx]
0x006EAF30  jmp      0x6eaf59
0x006EAF32  mov      byte ptr [ebp - 0x20], 1
0x006EAF36  push     0x49
0x006EAF38  pop      eax
0x006EAF39  push     dword ptr [ebp - 0x20]
0x006EAF3C  push     dword ptr [ebp - 0x28]
0x006EAF3F  push     ebx
0x006EAF40  push     dword ptr [ebp - 0x1c]
0x006EAF43  push     dword ptr [ebp - 0x2c]
0x006EAF46  push     eax
0x006EAF47  push     dword ptr [ebp - 0x30]
0x006EAF4A  call     0x6e9fed
0x006EAF4F  add      esp, 0x1c
0x006EAF52  test     al, al
0x006EAF54  je       0x6eaf6a
0x006EAF56  mov      edi, dword ptr [ebp - 0x18]
0x006EAF59  movzx    edx, word ptr [edi]
0x006EAF5C  test     dx, dx
0x006EAF5F  jne      0x6eace6
0x006EAF65  jmp      0x6eacc2
0x006EAF6A  call     0x6e09e0
0x006EAF6F  mov      dword ptr [eax], 0x16
0x006EAF75  xor      al, al
0x006EAF77  jmp      0x6eacc4
0x006EAF7C  mov      edi, edi
0x006EAF7E  push     ebp
0x006EAF7F  mov      ebp, esp
0x006EAF81  sub      esp, 0x28
0x006EAF84  push     edi
0x006EAF85  mov      edi, dword ptr [ebp + 8]
0x006EAF88  test     edi, edi
0x006EAF8A  jne      0x6eafa3
0x006EAF8C  call     0x6e09e0
0x006EAF91  mov      dword ptr [eax], 0x16
0x006EAF97  call     0x6e510d
0x006EAF9C  xor      eax, eax
0x006EAF9E  jmp      0x6eb0fc
0x006EAFA3  cmp      dword ptr [ebp + 0xc], 0
0x006EAFA7  je       0x6eaf8c
0x006EAFA9  push     esi
0x006EAFAA  mov      esi, dword ptr [ebp + 0x10]
0x006EAFAD  xor      eax, eax
0x006EAFAF  mov      word ptr [edi], ax
0x006EAFB2  test     esi, esi
0x006EAFB4  jne      0x6eafcd
0x006EAFB6  call     0x6e09e0
0x006EAFBB  mov      dword ptr [eax], 0x16
0x006EAFC1  call     0x6e510d
0x006EAFC6  xor      eax, eax
0x006EAFC8  jmp      0x6eb0fb
0x006EAFCD  push     dword ptr [ebp + 0x1c]
0x006EAFD0  lea      ecx, [ebp - 0x28]
0x006EAFD3  call     0x6d2e4c
0x006EAFD8  mov      edx, dword ptr [ebp + 0x18]
0x006EAFDB  test     edx, edx
0x006EAFDD  jne      0x6eafeb
0x006EAFDF  mov      eax, dword ptr [ebp - 0x24]
0x006EAFE2  mov      edx, dword ptr [eax + 0x9c]
0x006EAFE8  mov      dword ptr [ebp + 0x18], edx
0x006EAFEB  mov      eax, dword ptr [ebp + 0xc]
0x006EAFEE  mov      ecx, edi
0x006EAFF0  push     ebx
0x006EAFF1  xor      ebx, ebx
0x006EAFF3  mov      dword ptr [ebp - 0xc], ecx
0x006EAFF6  mov      dword ptr [ebp - 8], eax
0x006EAFF9  test     eax, eax
0x006EAFFB  jbe      0x6eb0bc
0x006EB001  movzx    edi, word ptr [esi]
0x006EB004  mov      dword ptr [ebp - 0x14], edi
0x006EB007  test     di, di
0x006EB00A  mov      edi, dword ptr [ebp + 8]
0x006EB00D  mov      dword ptr [ebp - 0x18], esi
0x006EB010  je       0x6eb0a3
0x006EB016  mov      eax, dword ptr [ebp - 0x14]
0x006EB019  cmp      ax, 0x25   <<< LEFT
0x006EB01D  je       0x6eb034
0x006EB01F  mov      word ptr [ecx], ax
0x006EB022  mov      ecx, dword ptr [ebp - 0xc]
0x006EB025  mov      eax, dword ptr [ebp - 8]
0x006EB028  add      ecx, 2
0x006EB02B  dec      eax
0x006EB02C  mov      dword ptr [ebp - 0xc], ecx
0x006EB02F  mov      dword ptr [ebp - 8], eax
0x006EB032  jmp      0x6eb095
0x006EB034  cmp      dword ptr [ebp + 0x14], ebx
0x006EB037  je       0x6eb0d8
0x006EB03D  add      esi, 2
0x006EB040  mov      byte ptr [ebp - 0x10], bl
0x006EB043  movzx    eax, word ptr [esi]
0x006EB046  mov      ecx, eax
0x006EB048  cmp      eax, 0x23
0x006EB04B  jne      0x6eb05a
0x006EB04D  mov      esi, dword ptr [ebp - 0x18]
0x006EB050  add      esi, 4
0x006EB053  mov      byte ptr [ebp - 0x10], 1
0x006EB057  movzx    ecx, word ptr [esi]
0x006EB05A  cmp      cx, 0x45
0x006EB05E  je       0x6eb069
0x006EB060  movzx    eax, cx
0x006EB063  cmp      cx, 0x4f
0x006EB067  jne      0x6eb06f
0x006EB069  add      esi, 2
0x006EB06C  movzx    eax, word ptr [esi]
0x006EB06F  push     dword ptr [ebp - 0x10]
0x006EB072  lea      ecx, [ebp - 8]
0x006EB075  push     edx
0x006EB076  push     ecx
0x006EB077  lea      ecx, [ebp - 0xc]
0x006EB07A  push     ecx
0x006EB07B  push     dword ptr [ebp + 0x14]
0x006EB07E  push     eax
0x006EB07F  lea      eax, [ebp - 0x24]
0x006EB082  push     eax
0x006EB083  call     0x6e9fed
0x006EB088  add      esp, 0x1c
0x006EB08B  test     al, al
0x006EB08D  mov      eax, dword ptr [ebp - 8]
0x006EB090  je       0x6eb0b4
0x006EB092  mov      ecx, dword ptr [ebp - 0xc]
0x006EB095  mov      edx, dword ptr [ebp + 0x18]
0x006EB098  .byte    0x83
