==============================================================================
func FUN_0061fe30 entry=0x0061fe30 size=832
==============================================================================
0x0061fe30  push     ebp
0x0061fe31  mov      ebp, esp
0x0061fe33  push     -1
0x0061fe35  push     0x70b8bd
0x0061fe3a  mov      eax, dword ptr fs:[0]
0x0061fe40  push     eax
0x0061fe41  sub      esp, 0x30
0x0061fe44  push     esi
0x0061fe45  push     edi
0x0061fe46  mov      eax, dword ptr [0x76700c]
0x0061fe4b  xor      eax, ebp
0x0061fe4d  push     eax
0x0061fe4e  lea      eax, [ebp - 0xc]
0x0061fe51  mov      dword ptr fs:[0], eax
0x0061fe57  push     dword ptr [ebp + 0xc]
0x0061fe5a  lea      ecx, [ebp - 0x3c]
0x0061fe5d  call     0x6bc170
0x0061fe62  mov      dword ptr [ebp - 4], 0
0x0061fe69  cmp      dword ptr [ebp + 0x10], 2
0x0061fe6d  mov      edi, dword ptr [0x715540]
0x0061fe73  jne      0x62011f
0x0061fe79  mov      esi, dword ptr [ebp + 0x14]
0x0061fe7c  mov      esi, dword ptr [esi + 4]
0x0061fe7f  mov      dword ptr [ebp - 0x2c], esi
0x0061fe82  test     esi, esi
0x0061fe84  je       0x61fe88
0x0061fe86  inc      dword ptr [esi]
0x0061fe88  mov      byte ptr [ebp - 4], 1
0x0061fe8c  test     esi, esi
0x0061fe8e  jne      0x61fe97
0x0061fe90  mov      eax, 0x71ce50
0x0061fe95  jmp      0x61fea3
0x0061fe97  push     0
0x0061fe99  push     esi
0x0061fe9a  call     dword ptr [0x715544]
0x0061fea0  add      esp, 8
0x0061fea3  push     0x72bed0
0x0061fea8  push     eax
0x0061fea9  call     0x6e31d5
0x0061feae  add      esp, 8
0x0061feb1  test     eax, eax
0x0061feb3  jne      0x6200d1
0x0061feb9  push     0x19
0x0061febb  mov      edx, 0x7364b0
0x0061fec0  lea      ecx, [eax + 0x20]
0x0061fec3  call     0x6ba810
0x0061fec8  mov      dword ptr [ebp - 0x14], eax
0x0061fecb  mov      dword ptr [eax + 4], 0x14
0x0061fed2  mov      dword ptr [eax + 8], 0xffffffff
0x0061fed9  mov      byte ptr [eax + 0xc], 0
0x0061fedd  mov      dword ptr [eax], 1
0x0061fee3  push     0x19
0x0061fee5  mov      edx, 0x7364b0
0x0061feea  mov      byte ptr [ebp - 4], 2
0x0061feee  mov      ecx, 0x20
0x0061fef3  call     0x6ba810
0x0061fef8  mov      dword ptr [ebp - 0x10], eax
0x0061fefb  mov      dword ptr [eax + 4], 0x14
0x0061ff02  mov      dword ptr [eax + 8], 0xffffffff
0x0061ff09  mov      byte ptr [eax + 0xc], 0
0x0061ff0d  mov      dword ptr [eax], 1
0x0061ff13  push     0x19
0x0061ff15  mov      edx, 0x7364b0
0x0061ff1a  mov      byte ptr [ebp - 4], 3
0x0061ff1e  mov      ecx, 0x20
0x0061ff23  call     0x6ba810
0x0061ff28  add      esp, 0xc
0x0061ff2b  mov      dword ptr [ebp + 0x10], eax
0x0061ff2e  mov      dword ptr [eax + 4], 0x14
0x0061ff35  mov      dword ptr [eax + 8], 0xffffffff
0x0061ff3c  mov      byte ptr [eax + 0xc], 0
0x0061ff40  mov      dword ptr [eax], 1
0x0061ff46  lea      eax, [ebp + 0x10]
0x0061ff49  mov      byte ptr [ebp - 4], 4
0x0061ff4d  push     eax
0x0061ff4e  lea      eax, [ebp - 0x10]
0x0061ff51  push     eax
0x0061ff52  lea      eax, [ebp - 0x14]
0x0061ff55  push     eax
0x0061ff56  call     0x4e4350
0x0061ff5b  lea      eax, [ebp - 0x14]
0x0061ff5e  mov      edx, 0x72e5f8
0x0061ff63  push     eax
0x0061ff64  lea      ecx, [ebp - 0x28]
0x0061ff67  call     0x6b95d0
0x0061ff6c  push     0x72e5f0
0x0061ff71  mov      edx, eax
0x0061ff73  mov      byte ptr [ebp - 4], 5
0x0061ff77  lea      ecx, [ebp - 0x24]
0x0061ff7a  call     0x6b9500
0x0061ff7f  lea      ecx, [ebp - 0x10]
0x0061ff82  mov      byte ptr [ebp - 4], 6
0x0061ff86  push     ecx
0x0061ff87  mov      edx, eax
0x0061ff89  lea      ecx, [ebp - 0x20]
0x0061ff8c  call     0x6b9410
0x0061ff91  push     0x72e5e8
0x0061ff96  mov      edx, eax
0x0061ff98  mov      byte ptr [ebp - 4], 7
0x0061ff9c  lea      ecx, [ebp - 0x1c]
0x0061ff9f  call     0x6b9500
0x0061ffa4  lea      ecx, [ebp + 0x10]
0x0061ffa7  mov      byte ptr [ebp - 4], 8
0x0061ffab  push     ecx
0x0061ffac  mov      edx, eax
0x0061ffae  lea      ecx, [ebp - 0x18]
0x0061ffb1  call     0x6b9410
0x0061ffb6  add      esp, 0x14
0x0061ffb9  mov      eax, dword ptr [eax]
0x0061ffbb  add      eax, 0xc
0x0061ffbe  jne      0x61ffc4
0x0061ffc0  xor      edi, edi
0x0061ffc2  jmp      0x61ffd4
0x0061ffc4  push     -1
0x0061ffc6  push     eax
0x0061ffc7  call     dword ptr [0x715564]
0x0061ffcd  mov      edi, eax
0x0061ffcf  add      esp, 8
0x0061ffd2  inc      dword ptr [edi]
0x0061ffd4  mov      eax, dword ptr [ebp - 0x3c]
0x0061ffd7  test     eax, eax
0x0061ffd9  je       0x61fff5
0x0061ffdb  test     edi, edi
0x0061ffdd  jne      0x61ffe8
0x0061ffdf  push     eax
0x0061ffe0  call     dword ptr [0x71555c]
0x0061ffe6  jmp      0x620007
0x0061ffe8  push     edi
0x0061ffe9  push     eax
0x0061ffea  call     dword ptr [0x7155b8]
0x0061fff0  add      esp, 8
0x0061fff3  jmp      0x61fff9
0x0061fff5  test     edi, edi
0x0061fff7  je       0x62000a
0x0061fff9  dec      dword ptr [edi]
0x0061fffb  cmp      dword ptr [edi], 0
0x0061fffe  jg       0x62000a
0x00620000  push     edi
0x00620001  call     dword ptr [0x715540]
0x00620007  add      esp, 4
0x0062000a  mov      byte ptr [ebp - 4], 9
0x0062000e  mov      ecx, dword ptr [ebp - 0x18]
0x00620011  test     ecx, ecx
0x00620013  je       0x62001f
0x00620015  add      dword ptr [ecx], -1
0x00620018  jne      0x62001f
0x0062001a  call     0x6ba940
0x0062001f  mov      byte ptr [ebp - 4], 0xa
0x00620023  mov      ecx, dword ptr [ebp - 0x1c]
0x00620026  test     ecx, ecx
0x00620028  je       0x620034
0x0062002a  add      dword ptr [ecx], -1
0x0062002d  jne      0x620034
0x0062002f  call     0x6ba940
0x00620034  mov      byte ptr [ebp - 4], 0xb
0x00620038  mov      ecx, dword ptr [ebp - 0x20]
0x0062003b  test     ecx, ecx
0x0062003d  je       0x620049
0x0062003f  add      dword ptr [ecx], -1
0x00620042  jne      0x620049
0x00620044  call     0x6ba940
0x00620049  mov      byte ptr [ebp - 4], 0xc
0x0062004d  mov      ecx, dword ptr [ebp - 0x24]
0x00620050  test     ecx, ecx
0x00620052  je       0x62005e
0x00620054  add      dword ptr [ecx], -1
0x00620057  jne      0x62005e
0x00620059  call     0x6ba940
0x0062005e  mov      byte ptr [ebp - 4], 0xd
0x00620062  mov      ecx, dword ptr [ebp - 0x28]
0x00620065  test     ecx, ecx
0x00620067  je       0x620073
0x00620069  add      dword ptr [ecx], -1
0x0062006c  jne      0x620073
0x0062006e  call     0x6ba940
0x00620073  mov      byte ptr [ebp - 4], 0xe
0x00620077  mov      ecx, dword ptr [ebp + 0x10]
0x0062007a  test     ecx, ecx
0x0062007c  je       0x620088
0x0062007e  add      dword ptr [ecx], -1
0x00620081  jne      0x620088
0x00620083  call     0x6ba940
0x00620088  mov      byte ptr [ebp - 4], 0xf
0x0062008c  mov      ecx, dword ptr [ebp - 0x10]
0x0062008f  test     ecx, ecx
0x00620091  je       0x62009d
0x00620093  add      dword ptr [ecx], -1
0x00620096  jne      0x62009d
0x00620098  call     0x6ba940
0x0062009d  mov      byte ptr [ebp - 4], 0x10
0x006200a1  mov      ecx, dword ptr [ebp - 0x14]
0x006200a4  test     ecx, ecx
0x006200a6  je       0x6200b2
0x006200a8  add      dword ptr [ecx], -1
0x006200ab  jne      0x6200b2
0x006200ad  call     0x6ba940
0x006200b2  test     esi, esi
0x006200b4  je       0x620155
0x006200ba  dec      dword ptr [esi]
0x006200bc  cmp      dword ptr [esi], 0
0x006200bf  jg       0x620155
0x006200c5  push     esi
0x006200c6  call     dword ptr [0x715540]
0x006200cc  jmp      0x620152
0x006200d1  test     esi, esi
0x006200d3  je       0x620107
0x006200d5  lea      eax, [ebp + 0x10]
0x006200d8  push     eax
0x006200d9  push     esi
0x006200da  push     0
0x006200dc  call     dword ptr [0x715574]
0x006200e2  add      esp, 0xc
0x006200e5  cmp      eax, 1
0x006200e8  je       0x620107
0x006200ea  mov      eax, dword ptr [ebp + 0x10]
0x006200ed  mov      ecx, 5
0x006200f2  cmp      eax, ecx
0x006200f4  cmovg    eax, ecx
0x006200f7  test     eax, eax
0x006200f9  jns      0x620109
0x006200fb  mov      dword ptr [0x768354], 0
0x00620105  jmp      0x620112
0x00620107  xor      eax, eax
0x00620109  mov      dword ptr [0x768354], eax
0x0062010e  test     esi, esi
0x00620110  je       0x62011f
0x00620112  dec      dword ptr [esi]
0x00620114  cmp      dword ptr [esi], 0
0x00620117  jg       0x62011f
0x00620119  push     esi
0x0062011a  call     edi
0x0062011c  add      esp, 4
0x0062011f  push     dword ptr [0x768354]
0x00620125  call     dword ptr [0x715568]
0x0062012b  mov      esi, eax
0x0062012d  add      esp, 4
0x00620130  inc      dword ptr [esi]
0x00620132  mov      ecx, dword ptr [ebp - 0x3c]
0x00620135  mov      eax, dword ptr [esi]
0x00620137  test     ecx, ecx
0x00620139  je       0x620148
0x0062013b  push     esi
0x0062013c  push     ecx
0x0062013d  call     dword ptr [0x7155b8]
0x00620143  mov      eax, dword ptr [esi]
0x00620145  add      esp, 8
0x00620148  dec      eax
0x00620149  mov      dword ptr [esi], eax
0x0062014b  test     eax, eax
0x0062014d  jg       0x620155
0x0062014f  push     esi
0x00620150  call     edi
0x00620152  add      esp, 4
0x00620155  lea      ecx, [ebp - 0x3c]
0x00620158  call     0x6bc0d0
0x0062015d  xor      eax, eax
0x0062015f  mov      ecx, dword ptr [ebp - 0xc]
0x00620162  mov      dword ptr fs:[0], ecx
0x00620169  pop      ecx
0x0062016a  pop      edi
0x0062016b  pop      esi
0x0062016c  mov      esp, ebp
0x0062016e  pop      ebp
0x0062016f  ret      
