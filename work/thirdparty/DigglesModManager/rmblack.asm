==============================================================================
func FUN_0066aec0 entry=0x0066aec0 size=1273
==============================================================================
0x0066aec0  push     ebp
0x0066aec1  mov      ebp, esp
0x0066aec3  push     -1
0x0066aec5  push     0x70fbf5
0x0066aeca  mov      eax, dword ptr fs:[0]
0x0066aed0  push     eax
0x0066aed1  sub      esp, 0x5c
0x0066aed4  push     esi
0x0066aed5  push     edi
0x0066aed6  mov      eax, dword ptr [0x76700c]
0x0066aedb  xor      eax, ebp
0x0066aedd  push     eax
0x0066aede  lea      eax, [ebp - 0xc]
0x0066aee1  mov      dword ptr fs:[0], eax
0x0066aee7  push     dword ptr [ebp + 0xc]
0x0066aeea  lea      ecx, [ebp - 0x68]
0x0066aeed  call     0x6bc170
0x0066aef2  push     dword ptr [ebp + 0x14]
0x0066aef5  mov      esi, dword ptr [ebp + 0x10]
0x0066aef8  lea      ecx, [ebp - 0x48]
0x0066aefb  push     esi
0x0066aefc  mov      dword ptr [ebp - 4], 0
0x0066af03  call     0x4298b0
0x0066af08  mov      byte ptr [ebp - 4], 1
0x0066af0c  cmp      esi, 6
0x0066af0f  je       0x66af25
0x0066af11  push     5
0x0066af13  lea      ecx, [ebp - 0x68]
0x0066af16  call     0x6bc8f0
0x0066af1b  mov      esi, 1
0x0066af20  jmp      0x66b376
0x0066af25  cmp      dword ptr [ebp - 0x40], 1
0x0066af29  jg       0x66af56
0x0066af2b  mov      esi, dword ptr [0x715340]
0x0066af31  push     0
0x0066af33  push     0
0x0066af35  push     1
0x0066af37  push     0xc000008c
0x0066af3c  call     esi
0x0066af3e  cmp      dword ptr [ebp - 0x44], 0
0x0066af42  ja       0x66af51
0x0066af44  push     0
0x0066af46  push     0
0x0066af48  push     1
0x0066af4a  push     0xc000008c
0x0066af4f  call     esi
0x0066af51  mov      esi, dword ptr [ebp - 0x48]
0x0066af54  jmp      0x66af73
0x0066af56  cmp      dword ptr [ebp - 0x44], 1
0x0066af5a  ja       0x66af6d
0x0066af5c  push     0
0x0066af5e  push     0
0x0066af60  push     1
0x0066af62  push     0xc000008c
0x0066af67  call     dword ptr [0x715340]
0x0066af6d  mov      esi, dword ptr [ebp - 0x48]
0x0066af70  add      esi, 4
0x0066af73  mov      esi, dword ptr [esi]
0x0066af75  test     esi, esi
0x0066af77  je       0x66afab
0x0066af79  inc      dword ptr [esi]
0x0066af7b  lea      eax, [ebp - 0x24]
0x0066af7e  push     eax
0x0066af7f  push     esi
0x0066af80  push     0
0x0066af82  call     dword ptr [0x715574]
0x0066af88  add      esp, 0xc
0x0066af8b  lea      edi, [eax - 1]
0x0066af8e  neg      edi
0x0066af90  sbb      edi, edi
0x0066af92  dec      dword ptr [esi]
0x0066af94  and      edi, dword ptr [ebp - 0x24]
0x0066af97  cmp      dword ptr [esi], 0
0x0066af9a  mov      dword ptr [ebp - 0x18], edi
0x0066af9d  jg       0x66afb0
0x0066af9f  push     esi
0x0066afa0  call     dword ptr [0x715540]
0x0066afa6  add      esp, 4
0x0066afa9  jmp      0x66afb0
0x0066afab  xor      edi, edi
0x0066afad  mov      dword ptr [ebp - 0x18], edi
0x0066afb0  cmp      dword ptr [ebp - 0x40], 2
0x0066afb4  jg       0x66afe1
0x0066afb6  mov      esi, dword ptr [0x715340]
0x0066afbc  push     0
0x0066afbe  push     0
0x0066afc0  push     1
0x0066afc2  push     0xc000008c
0x0066afc7  call     esi
0x0066afc9  cmp      dword ptr [ebp - 0x44], 0
0x0066afcd  ja       0x66afdc
0x0066afcf  push     0
0x0066afd1  push     0
0x0066afd3  push     1
0x0066afd5  push     0xc000008c
0x0066afda  call     esi
0x0066afdc  mov      esi, dword ptr [ebp - 0x48]
0x0066afdf  jmp      0x66affe
0x0066afe1  cmp      dword ptr [ebp - 0x44], 2
0x0066afe5  ja       0x66aff8
0x0066afe7  push     0
0x0066afe9  push     0
0x0066afeb  push     1
0x0066afed  push     0xc000008c
0x0066aff2  call     dword ptr [0x715340]
0x0066aff8  mov      esi, dword ptr [ebp - 0x48]
0x0066affb  add      esi, 8
0x0066affe  mov      esi, dword ptr [esi]
0x0066b000  test     esi, esi
0x0066b002  je       0x66b034
0x0066b004  inc      dword ptr [esi]
0x0066b006  lea      eax, [ebp - 0x28]
0x0066b009  push     eax
0x0066b00a  push     esi
0x0066b00b  push     0
0x0066b00d  call     dword ptr [0x715574]
0x0066b013  dec      eax
0x0066b014  add      esp, 0xc
0x0066b017  neg      eax
0x0066b019  sbb      eax, eax
0x0066b01b  dec      dword ptr [esi]
0x0066b01d  and      eax, dword ptr [ebp - 0x28]
0x0066b020  cmp      dword ptr [esi], 0
0x0066b023  mov      dword ptr [ebp + 0x10], eax
0x0066b026  jg       0x66b03b
0x0066b028  push     esi
0x0066b029  call     dword ptr [0x715540]
0x0066b02f  add      esp, 4
0x0066b032  jmp      0x66b03b
0x0066b034  mov      dword ptr [ebp + 0x10], 0
0x0066b03b  cmp      dword ptr [ebp - 0x40], 3
0x0066b03f  jg       0x66b06c
0x0066b041  mov      esi, dword ptr [0x715340]
0x0066b047  push     0
0x0066b049  push     0
0x0066b04b  push     1
0x0066b04d  push     0xc000008c
0x0066b052  call     esi
0x0066b054  cmp      dword ptr [ebp - 0x44], 0
0x0066b058  ja       0x66b067
0x0066b05a  push     0
0x0066b05c  push     0
0x0066b05e  push     1
0x0066b060  push     0xc000008c
0x0066b065  call     esi
0x0066b067  mov      esi, dword ptr [ebp - 0x48]
0x0066b06a  jmp      0x66b089
0x0066b06c  cmp      dword ptr [ebp - 0x44], 3
0x0066b070  ja       0x66b083
0x0066b072  push     0
0x0066b074  push     0
0x0066b076  push     1
0x0066b078  push     0xc000008c
0x0066b07d  call     dword ptr [0x715340]
0x0066b083  mov      esi, dword ptr [ebp - 0x48]
0x0066b086  add      esi, 0xc
0x0066b089  mov      esi, dword ptr [esi]
0x0066b08b  test     esi, esi
0x0066b08d  je       0x66b0bf
0x0066b08f  inc      dword ptr [esi]
0x0066b091  lea      eax, [ebp - 0x2c]
0x0066b094  push     eax
0x0066b095  push     esi
0x0066b096  push     0
0x0066b098  call     dword ptr [0x715574]
0x0066b09e  dec      eax
0x0066b09f  add      esp, 0xc
0x0066b0a2  neg      eax
0x0066b0a4  sbb      eax, eax
0x0066b0a6  dec      dword ptr [esi]
0x0066b0a8  and      eax, dword ptr [ebp - 0x2c]
0x0066b0ab  cmp      dword ptr [esi], 0
0x0066b0ae  mov      dword ptr [ebp - 0x10], eax
0x0066b0b1  jg       0x66b0c6
0x0066b0b3  push     esi
0x0066b0b4  call     dword ptr [0x715540]
0x0066b0ba  add      esp, 4
0x0066b0bd  jmp      0x66b0c6
0x0066b0bf  mov      dword ptr [ebp - 0x10], 0
0x0066b0c6  cmp      dword ptr [ebp - 0x40], 4
0x0066b0ca  jg       0x66b0f7
0x0066b0cc  mov      esi, dword ptr [0x715340]
0x0066b0d2  push     0
0x0066b0d4  push     0
0x0066b0d6  push     1
0x0066b0d8  push     0xc000008c
0x0066b0dd  call     esi
0x0066b0df  cmp      dword ptr [ebp - 0x44], 0
0x0066b0e3  ja       0x66b0f2
0x0066b0e5  push     0
0x0066b0e7  push     0
0x0066b0e9  push     1
0x0066b0eb  push     0xc000008c
0x0066b0f0  call     esi
0x0066b0f2  mov      esi, dword ptr [ebp - 0x48]
0x0066b0f5  jmp      0x66b114
0x0066b0f7  cmp      dword ptr [ebp - 0x44], 4
0x0066b0fb  ja       0x66b10e
0x0066b0fd  push     0
0x0066b0ff  push     0
0x0066b101  push     1
0x0066b103  push     0xc000008c
0x0066b108  call     dword ptr [0x715340]
0x0066b10e  mov      esi, dword ptr [ebp - 0x48]
0x0066b111  add      esi, 0x10
0x0066b114  mov      esi, dword ptr [esi]
0x0066b116  test     esi, esi
0x0066b118  je       0x66b14a
0x0066b11a  inc      dword ptr [esi]
0x0066b11c  lea      eax, [ebp - 0x30]
0x0066b11f  push     eax
0x0066b120  push     esi
0x0066b121  push     0
0x0066b123  call     dword ptr [0x715574]
0x0066b129  dec      eax
0x0066b12a  add      esp, 0xc
0x0066b12d  neg      eax
0x0066b12f  sbb      eax, eax
0x0066b131  dec      dword ptr [esi]
0x0066b133  and      eax, dword ptr [ebp - 0x30]
0x0066b136  cmp      dword ptr [esi], 0
0x0066b139  mov      dword ptr [ebp - 0x14], eax
0x0066b13c  jg       0x66b151
0x0066b13e  push     esi
0x0066b13f  call     dword ptr [0x715540]
0x0066b145  add      esp, 4
0x0066b148  jmp      0x66b151
0x0066b14a  mov      dword ptr [ebp - 0x14], 0
0x0066b151  cmp      dword ptr [ebp - 0x40], 5
0x0066b155  jg       0x66b182
0x0066b157  mov      esi, dword ptr [0x715340]
0x0066b15d  push     0
0x0066b15f  push     0
0x0066b161  push     1
0x0066b163  push     0xc000008c
0x0066b168  call     esi
0x0066b16a  cmp      dword ptr [ebp - 0x44], 0
0x0066b16e  ja       0x66b17d
0x0066b170  push     0
0x0066b172  push     0
0x0066b174  push     1
0x0066b176  push     0xc000008c
0x0066b17b  call     esi
0x0066b17d  mov      esi, dword ptr [ebp - 0x48]
0x0066b180  jmp      0x66b19f
0x0066b182  cmp      dword ptr [ebp - 0x44], 5
0x0066b186  ja       0x66b199
0x0066b188  push     0
0x0066b18a  push     0
0x0066b18c  push     1
0x0066b18e  push     0xc000008c
0x0066b193  call     dword ptr [0x715340]
0x0066b199  mov      esi, dword ptr [ebp - 0x48]
0x0066b19c  add      esi, 0x14
0x0066b19f  mov      esi, dword ptr [esi]
0x0066b1a1  test     esi, esi
0x0066b1a3  je       0x66b1da
0x0066b1a5  inc      dword ptr [esi]
0x0066b1a7  lea      eax, [ebp - 0x34]
0x0066b1aa  push     eax
0x0066b1ab  push     esi
0x0066b1ac  push     0
0x0066b1ae  call     dword ptr [0x715574]
0x0066b1b4  add      esp, 0xc
0x0066b1b7  lea      ecx, [eax - 1]
0x0066b1ba  neg      ecx
0x0066b1bc  sbb      ecx, ecx
0x0066b1be  dec      dword ptr [esi]
0x0066b1c0  and      ecx, dword ptr [ebp - 0x34]
0x0066b1c3  cmp      dword ptr [esi], 0
0x0066b1c6  mov      dword ptr [ebp - 0x20], ecx
0x0066b1c9  jg       0x66b1dc
0x0066b1cb  push     esi
0x0066b1cc  call     dword ptr [0x715540]
0x0066b1d2  mov      ecx, dword ptr [ebp - 0x20]
0x0066b1d5  add      esp, 4
0x0066b1d8  jmp      0x66b1dc
0x0066b1da  xor      ecx, ecx
0x0066b1dc  mov      eax, dword ptr [0x77241c]
0x0066b1e1  mov      esi, dword ptr [eax + 0x84]
0x0066b1e7  cmp      esi, dword ptr [ebp + 0x10]
0x0066b1ea  mov      edx, dword ptr [eax + 0x8c]
0x0066b1f0  cmovle   esi, dword ptr [ebp + 0x10]
0x0066b1f4  mov      dword ptr [ebp - 0x1c], esi
0x0066b1f7  mov      esi, dword ptr [eax + 0x88]
0x0066b1fd  cmp      esi, dword ptr [ebp - 0x10]
0x0066b200  cmovle   esi, dword ptr [ebp - 0x10]
0x0066b204  cmp      edx, dword ptr [ebp - 0x14]
0x0066b207  mov      dword ptr [ebp - 0x20], esi
0x0066b20a  cmovge   edx, dword ptr [ebp - 0x14]
0x0066b20e  mov      esi, dword ptr [eax + 0x90]
0x0066b214  cmp      esi, ecx
0x0066b216  mov      dword ptr [ebp - 0x38], edx
0x0066b219  cmovge   esi, ecx
0x0066b21c  mov      ecx, dword ptr [ebp - 0x20]
0x0066b21f  mov      dword ptr [ebp - 0x3c], esi
0x0066b222  mov      dword ptr [ebp + 0x10], ecx
0x0066b225  cmp      ecx, esi
0x0066b227  jge      0x66b32a
0x0066b22d  nop      dword ptr [eax]
0x0066b230  mov      eax, dword ptr [ebp - 0x1c]
0x0066b233  mov      dword ptr [ebp - 0x10], eax
0x0066b236  cmp      eax, edx
0x0066b238  jge      0x66b31e
0x0066b23e  nop      
0x0066b240  mov      edx, dword ptr [0x77241c]
0x0066b246  mov      dword ptr [ebp - 0x14], edx
0x0066b249  mov      edi, dword ptr [edx + 0x84]
0x0066b24f  cmp      eax, edi
0x0066b251  mov      ecx, dword ptr [edx + 0x88]
0x0066b257  mov      esi, dword ptr [edx + 0x8c]
0x0066b25d  cmovge   edi, eax
0x0066b260  mov      eax, dword ptr [edx + 0x90]
0x0066b266  cmp      dword ptr [ebp + 0x10], ecx
0x0066b269  cmovge   ecx, dword ptr [ebp + 0x10]
0x0066b26d  cmp      ecx, eax
0x0066b26f  lea      edx, [eax - 1]
0x0066b272  lea      eax, [esi - 1]
0x0066b275  cmovl    edx, ecx
0x0066b278  mov      ecx, dword ptr [ebp - 0x14]
0x0066b27b  imul     edx, dword ptr [ecx + 0x44]
0x0066b27f  cmp      edi, esi
0x0066b281  cmovl    eax, edi
0x0066b284  add      eax, edx
0x0066b286  cdq      
0x0066b287  idiv     dword ptr [ecx + 0x4c]
0x0066b28a  test     edx, edx
0x0066b28c  js       0x66b29b
0x0066b28e  cmp      edx, dword ptr [ecx + 0x18]
0x0066b291  jge      0x66b29b
0x0066b293  imul     esi, edx, 0x7c
0x0066b296  add      esi, dword ptr [ecx + 0x14]
0x0066b299  jmp      0x66b2b2
0x0066b29b  push     0
0x0066b29d  push     0
0x0066b29f  push     1
0x0066b2a1  push     0xc000008c
0x0066b2a6  call     dword ptr [0x715340]
0x0066b2ac  mov      esi, dword ptr [ebp - 0x14]
0x0066b2af  mov      esi, dword ptr [esi + 0x14]
0x0066b2b2  mov      edi, dword ptr [ebp - 0x18]
0x0066b2b5  cmp      edi, 7
0x0066b2b8  ja       0x66b2be
0x0066b2ba  add      esi, edi
0x0066b2bc  jmp      0x66b2cf
0x0066b2be  push     0
0x0066b2c0  push     0
0x0066b2c2  push     1
0x0066b2c4  push     0xc000008c
0x0066b2c9  call     dword ptr [0x715340]
0x0066b2cf  cmp      byte ptr [esi + 0x34], 0
0x0066b2d3  jne      0x66b306
0x0066b2d5  push     dword ptr [ebp + 0x10]
0x0066b2d8  mov      ecx, dword ptr [0x77241c]
0x0066b2de  push     dword ptr [ebp - 0x10]
0x0066b2e1  call     0x592f10
0x0066b2e6  lea      esi, [eax + 0x34]
0x0066b2e9  cmp      edi, 7
0x0066b2ec  ja       0x66b2f2
0x0066b2ee  add      esi, edi
0x0066b2f0  jmp      0x66b303
0x0066b2f2  push     0
0x0066b2f4  push     0
0x0066b2f6  push     1
0x0066b2f8  push     0xc000008c
0x0066b2fd  call     dword ptr [0x715340]
0x0066b303  mov      byte ptr [esi], 1
0x0066b306  mov      eax, dword ptr [ebp - 0x10]
0x0066b309  mov      edx, dword ptr [ebp - 0x38]
0x0066b30c  inc      eax
0x0066b30d  mov      dword ptr [ebp - 0x10], eax
0x0066b310  cmp      eax, edx
0x0066b312  jl       0x66b240
0x0066b318  mov      ecx, dword ptr [ebp + 0x10]
0x0066b31b  mov      esi, dword ptr [ebp - 0x3c]
0x0066b31e  inc      ecx
0x0066b31f  mov      dword ptr [ebp + 0x10], ecx
0x0066b322  cmp      ecx, esi
0x0066b324  jl       0x66b230
0x0066b32a  mov      eax, dword ptr [0x772400]
0x0066b32f  cmp      edi, dword ptr [eax + 0x64]
0x0066b332  jne      0x66b374
0x0066b334  mov      eax, dword ptr [ebp - 0x1c]
0x0066b337  shl      eax, 3
0x0066b33a  mov      dword ptr [ebp - 0x58], eax
0x0066b33d  mov      eax, dword ptr [ebp - 0x20]
0x0066b340  shl      eax, 3
0x0066b343  mov      dword ptr [ebp - 0x54], eax
0x0066b346  lea      eax, [edx*8]
0x0066b34d  mov      dword ptr [ebp - 0x50], eax
0x0066b350  lea      eax, [esi*8]
0x0066b357  push     0x10
0x0066b359  mov      dword ptr [ebp - 0x4c], eax
0x0066b35c  sub      esp, 0x10
0x0066b35f  movups   xmm0, xmmword ptr [ebp - 0x58]
0x0066b363  mov      eax, esp
0x0066b365  movups   xmmword ptr [eax], xmm0
0x0066b368  call     0x5a3dd0
0x0066b36d  mov      ecx, eax
0x0066b36f  call     0x5a3fd0
0x0066b374  xor      esi, esi
0x0066b376  push     0
0x0066b378  lea      ecx, [ebp - 0x48]
0x0066b37b  mov      byte ptr [ebp - 4], 2
0x0066b37f  call     0x4297b0
0x0066b384  push     0
0x0066b386  lea      ecx, [ebp - 0x48]
0x0066b389  mov      byte ptr [ebp - 4], 3
0x0066b38d  call     0x4297b0
0x0066b392  mov      ecx, dword ptr [ebp - 0x48]
0x0066b395  test     ecx, ecx
0x0066b397  je       0x66b39e
0x0066b399  call     0x6ba940
0x0066b39e  lea      ecx, [ebp - 0x68]
0x0066b3a1  call     0x6bc0d0
0x0066b3a6  mov      eax, esi
0x0066b3a8  mov      ecx, dword ptr [ebp - 0xc]
0x0066b3ab  mov      dword ptr fs:[0], ecx
0x0066b3b2  pop      ecx
0x0066b3b3  pop      edi
0x0066b3b4  pop      esi
0x0066b3b5  mov      esp, ebp
0x0066b3b7  pop      ebp
0x0066b3b8  ret      
