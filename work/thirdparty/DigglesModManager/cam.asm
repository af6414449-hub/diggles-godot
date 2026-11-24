==============================================================================
func FUN_00427e30 entry=0x00427e30 size=1665
==============================================================================
0x00427e30  push     ebp
0x00427e31  mov      ebp, esp
0x00427e33  sub      esp, 0x10
0x00427e36  push     esi
0x00427e37  mov      esi, ecx
0x00427e39  push     edi
0x00427e3a  cmp      byte ptr [esi + 0x21], 0
0x00427e3e  je       0x4284ab
0x00427e44  mov      ecx, dword ptr [esi + 0x4c]
0x00427e47  movss    xmm7, dword ptr [0x737010]
0x00427e4f  movss    xmm5, dword ptr [0x736ff0]
0x00427e57  movss    xmm6, dword ptr [0x737120]
0x00427e5f  movss    xmm4, dword ptr [0x737428]
0x00427e67  cmp      ecx, -1
0x00427e6a  je       0x427f6d
0x00427e70  mov      edi, dword ptr [0x77244c]
0x00427e76  add      edi, 0x488
0x00427e7c  cmp      ecx, 0x1fff
0x00427e82  ja       0x427e89
0x00427e84  lea      edi, [edi + ecx*4]
0x00427e87  jmp      0x427eba
0x00427e89  push     0
0x00427e8b  push     0
0x00427e8d  push     1
0x00427e8f  push     0xc000008c
0x00427e94  call     dword ptr [0x715340]
0x00427e9a  movss    xmm4, dword ptr [0x737428]
0x00427ea2  movss    xmm7, dword ptr [0x737010]
0x00427eaa  movss    xmm5, dword ptr [0x736ff0]
0x00427eb2  movss    xmm6, dword ptr [0x737120]
0x00427eba  mov      eax, dword ptr [edi]
0x00427ebc  xorps    xmm3, xmm3
0x00427ebf  test     eax, eax
0x00427ec1  jne      0x427ecf
0x00427ec3  mov      dword ptr [esi + 0x4c], 0xffffffff
0x00427eca  jmp      0x427fc6
0x00427ecf  movss    xmm2, dword ptr [esi + 0x50]
0x00427ed4  subss    xmm2, dword ptr [eax + 0xc]
0x00427ed9  movss    xmm1, dword ptr [esi + 0x54]
0x00427ede  subss    xmm1, dword ptr [eax + 0x10]
0x00427ee3  mulss    xmm2, dword ptr [0x737054]
0x00427eeb  xorps    xmm1, xmmword ptr [0x737970]
0x00427ef2  mulss    xmm1, dword ptr [0x737054]
0x00427efa  comiss   xmm3, xmm2
0x00427efd  jbe      0x427f09
0x00427eff  subss    xmm2, dword ptr [0x7373d8]
0x00427f07  jmp      0x427f1d
0x00427f09  comiss   xmm2, xmm3
0x00427f0c  jbe      0x427f1d
0x00427f0e  movss    xmm0, dword ptr [0x7373d8]
0x00427f16  subss    xmm0, xmm2
0x00427f1a  movaps   xmm2, xmm0
0x00427f1d  movss    xmm0, dword ptr [0x737748]
0x00427f25  maxss    xmm0, xmm1
0x00427f29  movss    xmm1, dword ptr [0x737228]
0x00427f31  minss    xmm1, xmm0
0x00427f35  movss    xmm0, dword ptr [esi + 0x5c]
0x00427f3a  mulss    xmm0, xmm6
0x00427f3e  mulss    xmm1, xmm5
0x00427f42  addss    xmm1, xmm0
0x00427f46  movss    xmm0, dword ptr [0x737780]
0x00427f4e  maxss    xmm0, xmm2
0x00427f52  movss    dword ptr [esi + 0x5c], xmm1
0x00427f57  movaps   xmm1, xmm4
0x00427f5a  minss    xmm1, xmm0
0x00427f5e  movss    xmm0, dword ptr [esi + 0x60]
0x00427f63  mulss    xmm0, xmm6
0x00427f67  mulss    xmm1, xmm5
0x00427f6b  jmp      0x427fbd
0x00427f6d  mov      ecx, dword ptr [0x772400]
0x00427f73  xorps    xmm3, xmm3
0x00427f76  movss    xmm0, dword ptr [esi + 0x5c]
0x00427f7b  mulss    xmm0, dword ptr [0x737114]
0x00427f83  mov      eax, dword ptr [ecx + 0x5a4]
0x00427f89  movss    xmm1, dword ptr [eax + 0x160]
0x00427f91  mulss    xmm1, xmm7
0x00427f95  addss    xmm1, xmm0
0x00427f99  movss    xmm0, dword ptr [esi + 0x60]
0x00427f9e  mulss    xmm0, dword ptr [0x737114]
0x00427fa6  movss    dword ptr [esi + 0x5c], xmm1
0x00427fab  mov      eax, dword ptr [ecx + 0x5a4]
0x00427fb1  movss    xmm1, dword ptr [eax + 0x164]
0x00427fb9  mulss    xmm1, xmm7
0x00427fbd  addss    xmm1, xmm0
0x00427fc1  movss    dword ptr [esi + 0x60], xmm1
0x00427fc6  mov      eax, dword ptr [esi + 0x74]
0x00427fc9  dec      eax
0x00427fca  cmp      eax, 4
0x00427fcd  ja       0x4282c5
0x00427fd3  jmp      dword ptr [eax*4 + 0x4284b4]
0x00427fda  movss    xmm2, dword ptr [esi + 0x68]
0x00427fdf  comiss   xmm3, xmm2
0x00427fe2  mov      ecx, dword ptr [0x76a338]
0x00427fe8  movss    xmm1, dword ptr [esi + 0x6c]
0x00427fed  movss    xmm4, dword ptr [esi + 0x70]
0x00427ff2  jbe      0x428003
0x00427ff4  movd     xmm0, dword ptr [ecx + 0x2830]
0x00427ffc  cvtdq2ps xmm0, xmm0
0x00427fff  addss    xmm2, xmm0
0x00428003  comiss   xmm3, xmm1
0x00428006  jbe      0x428017
0x00428008  movd     xmm0, dword ptr [ecx + 0x2834]
0x00428010  cvtdq2ps xmm0, xmm0
0x00428013  addss    xmm1, xmm0
0x00428017  comiss   xmm3, xmm4
0x0042801a  jbe      0x428052
0x0042801c  movd     xmm0, dword ptr [ecx + 0x2830]
0x00428024  cvtdq2ps xmm0, xmm0
0x00428027  mulss    xmm4, dword ptr [0x73773c]
0x0042802f  divss    xmm0, dword ptr [0x73768c]
0x00428037  mulss    xmm2, xmm0
0x0042803b  movd     xmm0, dword ptr [ecx + 0x2834]
0x00428043  cvtdq2ps xmm0, xmm0
0x00428046  divss    xmm0, dword ptr [0x737688]
0x0042804e  mulss    xmm1, xmm0
0x00428052  sub      esp, 0xc
0x00428055  movss    dword ptr [ebp - 0x10], xmm2
0x0042805a  mov      eax, esp
0x0042805c  movss    dword ptr [ebp - 0xc], xmm1
0x00428061  lea      edx, [ebp - 0x10]
0x00428064  movss    dword ptr [ebp - 8], xmm4
0x00428069  push     edx
0x0042806a  push     eax
0x0042806b  call     0x479150
0x00428070  mov      ecx, esi
0x00428072  call     0x428b80
0x00428077  jmp      0x4282c5
0x0042807c  movss    xmm3, dword ptr [esi + 0x68]
0x00428081  movss    xmm1, dword ptr [esi + 0x50]
0x00428086  movss    xmm2, dword ptr [esi + 0x54]
0x0042808b  subss    xmm1, xmm3
0x0042808f  subss    xmm2, dword ptr [esi + 0x6c]
0x00428094  movss    xmm0, dword ptr [esi + 0x58]
0x00428099  subss    xmm0, dword ptr [esi + 0x70]
0x0042809e  mulss    xmm1, xmm1
0x004280a2  mulss    xmm2, xmm2
0x004280a6  mulss    xmm0, xmm0
0x004280aa  addss    xmm2, xmm1
0x004280ae  addss    xmm2, xmm0
0x004280b2  movss    xmm0, dword ptr [0x73700c]
0x004280ba  comiss   xmm0, xmm2
0x004280bd  jbe      0x4280d2
0x004280bf  mov      ecx, esi
0x004280c1  mov      dword ptr [esi + 0x74], 0
0x004280c8  call     0x4279f0
0x004280cd  jmp      0x4282c5
0x004280d2  sub      esp, 0xc
0x004280d5  mov      ecx, esp
0x004280d7  movss    dword ptr [ecx], xmm3
0x004280db  mov      eax, dword ptr [esi + 0x6c]
0x004280de  mov      dword ptr [ecx + 4], eax
0x004280e1  mov      eax, dword ptr [esi + 0x70]
0x004280e4  mov      dword ptr [ecx + 8], eax
0x004280e7  mov      ecx, esi
0x004280e9  call     0x428b80
0x004280ee  jmp      0x4282c5
0x004280f3  push     0x190
0x004280f8  lea      eax, [esi + 0x50]
0x004280fb  push     eax
0x004280fc  call     0x428a70
0x00428101  test     al, al
0x00428103  jne      0x428120
0x00428105  mov      ecx, esi
0x00428107  mov      dword ptr [esi + 0x74], 0
0x0042810e  call     0x4279f0
0x00428113  push     0
0x00428115  mov      ecx, esi
0x00428117  call     0x427610
0x0042811c  mov      byte ptr [esi + 0x21], 0
0x00428120  sub      esp, 0xc
0x00428123  mov      ecx, esi
0x00428125  mov      eax, esp
0x00428127  mov      dword ptr [eax], 0
0x0042812d  mov      dword ptr [eax + 4], 0
0x00428134  mov      dword ptr [eax + 8], 0
0x0042813b  call     0x428b80
0x00428140  jmp      0x4282c5
0x00428145  movss    xmm0, dword ptr [esi + 0x6c]
0x0042814a  movss    xmm1, dword ptr [esi + 0x54]
0x0042814f  subss    xmm0, xmm4
0x00428153  comiss   xmm1, xmm0
0x00428156  jb       0x42817c
0x00428158  mov      eax, dword ptr [esi + 0x30]
0x0042815b  mov      ecx, 0x1a
0x00428160  dec      eax
0x00428161  mov      dword ptr [esi + 0x74], 0
0x00428168  cmp      eax, ecx
0x0042816a  cmovl    ecx, eax
0x0042816d  mov      dword ptr [esi + 0x3c], ecx
0x00428170  mov      ecx, esi
0x00428172  call     0x4279f0
0x00428177  jmp      0x4282c5
0x0042817c  movss    xmm4, dword ptr [esi + 0x6c]
0x00428181  comiss   xmm4, xmm1
0x00428184  movss    xmm5, dword ptr [esi + 0x68]
0x00428189  movss    xmm6, dword ptr [esi + 0x70]
0x0042818e  jbe      0x4282c5
0x00428194  mov      dword ptr [esi + 0x14], 0
0x0042819b  mov      dword ptr [esi + 0x18], 0x3d4ccccd
0x004281a2  mov      dword ptr [esi + 0x1c], 0
0x004281a9  movss    xmm0, dword ptr [esi + 0x54]
0x004281ae  movss    xmm1, dword ptr [esi + 0x50]
0x004281b3  addss    xmm0, xmm7
0x004281b7  movss    xmm2, dword ptr [esi + 0x58]
0x004281bc  addss    xmm1, xmm3
0x004281c0  addss    xmm2, xmm3
0x004281c4  comiss   xmm0, xmm4
0x004281c7  jbe      0x4281d2
0x004281c9  movaps   xmm1, xmm5
0x004281cc  movaps   xmm0, xmm4
0x004281cf  movaps   xmm2, xmm6
0x004281d2  mov      eax, dword ptr [esi + 0x30]
0x004281d5  mov      ecx, 0x19
0x004281da  dec      eax
0x004281db  cmp      eax, ecx
0x004281dd  cmovl    ecx, eax
0x004281e0  mov      dword ptr [esi + 0x3c], ecx
0x004281e3  movss    dword ptr [esi + 0x50], xmm1
0x004281e8  movss    dword ptr [esi + 0x54], xmm0
0x004281ed  movss    dword ptr [esi + 0x58], xmm2
0x004281f2  jmp      0x4282c5
0x004281f7  movss    xmm4, dword ptr [esi + 0x50]
0x004281fc  xor      ecx, ecx
0x004281fe  movss    xmm2, dword ptr [esi + 0x54]
0x00428203  movaps   xmm1, xmm4
0x00428206  subss    xmm2, dword ptr [esi + 0x6c]
0x0042820b  subss    xmm1, dword ptr [esi + 0x68]
0x00428210  movss    xmm0, dword ptr [esi + 0x58]
0x00428215  subss    xmm0, dword ptr [esi + 0x70]
0x0042821a  mulss    xmm2, xmm2
0x0042821e  mulss    xmm1, xmm1
0x00428222  mulss    xmm0, xmm0
0x00428226  addss    xmm2, xmm1
0x0042822a  addss    xmm2, xmm0
0x0042822e  movss    xmm0, dword ptr [0x73701c]
0x00428236  comiss   xmm0, xmm2
0x00428239  jbe      0x428253
0x0042823b  mov      eax, dword ptr [esi + 0x30]
0x0042823e  add      eax, -1
0x00428241  mov      dword ptr [esi + 0x74], ecx
0x00428244  cmovns   eax, ecx
0x00428247  mov      ecx, esi
0x00428249  mov      dword ptr [esi + 0x3c], eax
0x0042824c  call     0x4279f0
0x00428251  jmp      0x4282c5
0x00428253  addss    xmm4, dword ptr [esi + 0x14]
0x00428258  movss    dword ptr [esi + 0x50], xmm4
0x0042825d  movss    xmm0, dword ptr [esi + 0x18]
0x00428262  addss    xmm0, dword ptr [esi + 0x54]
0x00428267  movss    dword ptr [esi + 0x54], xmm0
0x0042826c  movss    xmm0, dword ptr [esi + 0x1c]
0x00428271  addss    xmm0, dword ptr [esi + 0x58]
0x00428276  movss    dword ptr [esi + 0x58], xmm0
0x0042827b  movss    xmm4, dword ptr [esi + 0x14]
0x00428280  movss    xmm5, dword ptr [esi + 0x18]
0x00428285  cvtps2pd xmm2, xmm4
0x00428288  cvtps2pd xmm0, xmm5
0x0042828b  andps    xmm2, xmmword ptr [0x737950]
0x00428292  mulsd    xmm2, qword ptr [0x7372f8]
0x0042829a  andps    xmm0, xmmword ptr [0x737950]
0x004282a1  comisd   xmm2, xmm0
0x004282a5  jbe      0x4282b2
0x004282a7  comiss   xmm4, xmm3
0x004282aa  seta     cl
0x004282ad  add      ecx, 3
0x004282b0  jmp      0x4282b9
0x004282b2  comiss   xmm5, xmm3
0x004282b5  seta     cl
0x004282b8  inc      ecx
0x004282b9  mov      eax, dword ptr [esi + 0x30]
0x004282bc  dec      eax
0x004282bd  cmp      eax, ecx
0x004282bf  cmovge   eax, ecx
0x004282c2  mov      dword ptr [esi + 0x3c], eax
0x004282c5  cmp      byte ptr [esi + 0x20], 0
0x004282c9  je       0x42836f
0x004282cf  mov      ecx, dword ptr [0x772400]
0x004282d5  movss    xmm1, dword ptr [esi + 0x50]
0x004282da  mulss    xmm1, dword ptr [0x736ff0]
0x004282e2  mov      eax, dword ptr [ecx + 0x5a4]
0x004282e8  movss    xmm0, dword ptr [eax + 0x154]
0x004282f0  mulss    xmm0, dword ptr [0x737120]
0x004282f8  addss    xmm1, xmm0
0x004282fc  movss    dword ptr [eax + 0x154], xmm1
0x00428304  mov      eax, dword ptr [ecx + 0x5a4]
0x0042830a  movss    xmm1, dword ptr [esi + 0x54]
0x0042830f  mulss    xmm1, dword ptr [0x736ff0]
0x00428317  movss    xmm0, dword ptr [eax + 0x158]
0x0042831f  mulss    xmm0, dword ptr [0x737120]
0x00428327  addss    xmm1, xmm0
0x0042832b  movss    dword ptr [eax + 0x158], xmm1
0x00428333  mov      eax, dword ptr [ecx + 0x5a4]
0x00428339  movss    xmm0, dword ptr [eax + 0x160]
0x00428341  mulss    xmm0, dword ptr [0x737108]
0x00428349  movss    dword ptr [eax + 0x160], xmm0
0x00428351  mov      eax, dword ptr [ecx + 0x5a4]
0x00428357  movss    xmm0, dword ptr [eax + 0x164]
0x0042835f  mulss    xmm0, dword ptr [0x737108]
0x00428367  movss    dword ptr [eax + 0x164], xmm0
0x0042836f  mov      ecx, esi
0x00428371  call     0x427a70
0x00428376  cmp      dword ptr [esi + 0x38], -1
0x0042837a  je       0x4284a4
0x00428380  mov      edx, dword ptr [esi + 4]
0x00428383  cmp      edx, -1
0x00428386  je       0x4284a4
0x0042838c  mov      edi, dword ptr [esi + 0x40]
0x0042838f  cmp      edi, 0xff
0x00428395  ja       0x4283a5
0x00428397  mov      eax, dword ptr [0x772400]
0x0042839c  mov      edi, dword ptr [eax + edi*4 + 0x5c8]
0x004283a3  jmp      0x4283a7
0x004283a5  xor      edi, edi
0x004283a7  test     edx, edx
0x004283a9  js       0x4283bf
0x004283ab  cmp      edx, dword ptr [edi + 0x50]
0x004283ae  jge      0x4283bf
0x004283b0  mov      eax, dword ptr [edi + 0x4c]
0x004283b3  mov      ecx, edx
0x004283b5  shl      ecx, 4
0x004283b8  sub      ecx, edx
0x004283ba  lea      edi, [eax + ecx*4]
0x004283bd  jmp      0x4283d3
0x004283bf  push     0
0x004283c1  push     0
0x004283c3  push     1
0x004283c5  push     0xc000008c
0x004283ca  call     dword ptr [0x715340]
0x004283d0  mov      edi, dword ptr [edi + 0x4c]
0x004283d3  movss    xmm0, dword ptr [esi + 0x48]
0x004283d8  addss    xmm0, dword ptr [0x737010]
0x004283e0  comiss   xmm0, dword ptr [0x737128]
0x004283e7  movss    dword ptr [esi + 0x48], xmm0
0x004283ec  jb       0x4283f8
0x004283ee  inc      dword ptr [esi + 8]
0x004283f1  mov      dword ptr [esi + 0x48], 0
0x004283f8  mov      ecx, dword ptr [esi + 8]
0x004283fb  cmp      ecx, dword ptr [edi + 4]
0x004283fe  cmovge   ecx, dword ptr [edi + 4]
0x00428402  mov      dword ptr [esi + 8], ecx
0x00428405  cmp      ecx, dword ptr [edi + 4]
0x00428408  jge      0x42849d
0x0042840e  push     ecx
0x0042840f  lea      ecx, [edi + 8]
0x00428412  call     0x405920
0x00428417  mov      eax, dword ptr [eax]
0x00428419  mov      dword ptr [esi + 0x44], eax
0x0042841c  mov      eax, dword ptr [edi + 4]
0x0042841f  dec      eax
0x00428420  cmp      dword ptr [esi + 8], eax
0x00428423  setl     al
0x00428426  cmp      dword ptr [esi + 0x38], 0
0x0042842a  mov      byte ptr [esi + 0x7d], al
0x0042842d  jne      0x4284ab
0x0042842f  movss    xmm0, dword ptr [0xc3c960]
0x00428437  addss    xmm0, dword ptr [0x737010]
0x0042843f  movss    dword ptr [ebp - 4], xmm0
0x00428444  movss    dword ptr [0xc3c960], xmm0
0x0042844c  mulss    xmm0, dword ptr [0x737038]
0x00428454  call     0x4089d0
0x00428459  mulss    xmm0, dword ptr [0x736fa8]
0x00428461  addss    xmm0, dword ptr [esi + 0x50]
0x00428466  movss    dword ptr [esi + 0x50], xmm0
0x0042846b  movss    xmm0, dword ptr [ebp - 4]
0x00428470  mulss    xmm0, dword ptr [0x737064]
0x00428478  addss    xmm0, dword ptr [0x737034]
0x00428480  call     0x4089d0
0x00428485  mulss    xmm0, dword ptr [0x736fb4]
0x0042848d  addss    xmm0, dword ptr [esi + 0x54]
0x00428492  movss    dword ptr [esi + 0x54], xmm0
0x00428497  pop      edi
0x00428498  pop      esi
0x00428499  mov      esp, ebp
0x0042849b  pop      ebp
0x0042849c  ret      
0x0042849d  mov      dword ptr [esi + 0x48], 0
0x004284a4  mov      ecx, esi
0x004284a6  call     0x428630
0x004284ab  pop      edi
0x004284ac  pop      esi
0x004284ad  mov      esp, ebp
0x004284af  pop      ebp
0x004284b0  ret      
