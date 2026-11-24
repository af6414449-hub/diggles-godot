==============================================================================
func FUN_004ceff0 entry=0x004ceff0 size=1752
==============================================================================
0x004ceff0  push     ebp
0x004ceff1  mov      ebp, esp
0x004ceff3  push     -1
0x004ceff5  push     0x6feccd
0x004ceffa  mov      eax, dword ptr fs:[0]
0x004cf000  push     eax
0x004cf001  sub      esp, 0x88
0x004cf007  push     ebx
0x004cf008  push     esi
0x004cf009  push     edi
0x004cf00a  mov      eax, dword ptr [0x76700c]
0x004cf00f  xor      eax, ebp
0x004cf011  push     eax
0x004cf012  lea      eax, [ebp - 0xc]
0x004cf015  mov      dword ptr fs:[0], eax
0x004cf01b  mov      edi, dword ptr [0x76a324]
0x004cf021  mov      dword ptr [ebp - 0x14], edi
0x004cf024  mov      dword ptr [ebp - 0x24], 1
0x004cf02b  cmp      byte ptr [edi + 0x12], 0
0x004cf02f  je       0x4cf08a
0x004cf031  call     0x449080
0x004cf036  sub      eax, dword ptr [edi + 8]
0x004cf039  push     0
0x004cf03b  sbb      edx, dword ptr [edi + 0xc]
0x004cf03e  push     0x200
0x004cf043  push     edx
0x004cf044  push     eax
0x004cf045  call     0x6f3970
0x004cf04a  mov      ebx, dword ptr [ebp + 0xc]
0x004cf04d  and      eax, 1
0x004cf050  push     0x12c0
0x004cf055  mov      dword ptr [ebp - 0x24], eax
0x004cf058  lea      ecx, [ebx + 0x12c0]
0x004cf05e  push     ecx
0x004cf05f  push     ebx
0x004cf060  call     0x6d2250
0x004cf065  add      esp, 0xc
0x004cf068  cmp      byte ptr [ebx + 0x2580], 0
0x004cf06f  je       0x4cf08a
0x004cf071  mov      byte ptr [ebx + 0x2580], 0
0x004cf078  mov      dword ptr [ebp - 0x24], 0
0x004cf07f  call     0x449080
0x004cf084  mov      dword ptr [edi + 8], eax
0x004cf087  mov      dword ptr [edi + 0xc], edx
0x004cf08a  mov      esi, dword ptr [edi + 0x14]
0x004cf08d  test     esi, esi
0x004cf08f  jne      0x4cf0b2
0x004cf091  push     0x200
0x004cf096  push     0x200
0x004cf09b  push     1
0x004cf09d  call     0x44d010
0x004cf0a2  lea      ecx, [eax + 0x22c]
0x004cf0a8  call     0x44c240
0x004cf0ad  mov      esi, eax
0x004cf0af  mov      dword ptr [edi + 0x14], esi
0x004cf0b2  push     esi
0x004cf0b3  call     dword ptr [0x715304]
0x004cf0b9  mov      ebx, dword ptr [esi + 0x38]
0x004cf0bc  mov      dword ptr [ebp - 0x28], ebx
0x004cf0bf  push     esi
0x004cf0c0  test     ebx, ebx
0x004cf0c2  jne      0x4cf0d2
0x004cf0c4  mov      byte ptr [esi + 0x18], bl
0x004cf0c7  call     dword ptr [0x715300]
0x004cf0cd  mov      dword ptr [ebp - 0x28], ebx
0x004cf0d0  jmp      0x4cf0e2
0x004cf0d2  mov      word ptr [esi + 0x25], 0x101
0x004cf0d8  mov      byte ptr [esi + 0x18], 0
0x004cf0dc  call     dword ptr [0x715300]
0x004cf0e2  mov      ecx, dword ptr [ebx + 0x80]
0x004cf0e8  test     ecx, ecx
0x004cf0ea  je       0x4cf114
0x004cf0ec  lea      edx, [ebp - 0x94]
0x004cf0f2  mov      dword ptr [ebp - 0x94], 0x64
0x004cf0fc  push     edx
0x004cf0fd  push     0x1000400
0x004cf102  push     0
0x004cf104  mov      dword ptr [ebp - 0x44], 0
0x004cf10b  mov      eax, dword ptr [ecx]
0x004cf10d  push     0
0x004cf10f  push     0
0x004cf111  call     dword ptr [eax + 0x14]
0x004cf114  push     4
0x004cf116  lea      esi, [edi + 4]
0x004cf119  mov      ecx, ebx
0x004cf11b  push     esi
0x004cf11c  push     edi
0x004cf11d  call     0x44f440
0x004cf122  mov      ecx, dword ptr [ebp + 0xc]
0x004cf125  cmp      ecx, eax
0x004cf127  mov      ebx, dword ptr [0x715340]
0x004cf12d  cmovne   ecx, eax
0x004cf130  test     ecx, ecx
0x004cf132  js       0x4cf1fa
0x004cf138  mov      eax, dword ptr [esi]
0x004cf13a  mov      ecx, dword ptr [ebp + 0xc]
0x004cf13d  cdq      
0x004cf13e  sub      eax, edx
0x004cf140  xor      edx, edx
0x004cf142  sar      eax, 1
0x004cf144  mov      dword ptr [esi], eax
0x004cf146  xor      eax, eax
0x004cf148  add      ecx, 0x12c0
0x004cf14e  mov      dword ptr [ebp - 0x18], edx
0x004cf151  mov      dword ptr [ebp - 0x20], eax
0x004cf154  mov      dword ptr [ebp - 0x1c], ecx
0x004cf157  nop      word ptr [eax + eax]
0x004cf160  xor      esi, esi
0x004cf162  mov      edi, eax
0x004cf164  cmp      edi, 0x12bf
0x004cf16a  ja       0x4cf172
0x004cf16c  add      eax, ecx
0x004cf16e  add      eax, esi
0x004cf170  jmp      0x4cf185
0x004cf172  push     0
0x004cf174  push     0
0x004cf176  push     1
0x004cf178  push     0xc000008c
0x004cf17d  call     ebx
0x004cf17f  mov      eax, dword ptr [ebp - 0x1c]
0x004cf182  mov      edx, dword ptr [ebp - 0x18]
0x004cf185  movsx    eax, byte ptr [eax]
0x004cf188  mov      ecx, dword ptr [ebp - 0x14]
0x004cf18b  push     eax
0x004cf18c  push     edx
0x004cf18d  push     esi
0x004cf18e  call     0x4ceea0
0x004cf193  mov      eax, dword ptr [ebp - 0x20]
0x004cf196  inc      esi
0x004cf197  mov      ecx, dword ptr [ebp - 0x1c]
0x004cf19a  inc      edi
0x004cf19b  mov      edx, dword ptr [ebp - 0x18]
0x004cf19e  cmp      esi, 0x50
0x004cf1a1  jl       0x4cf164
0x004cf1a3  add      eax, 0x50
0x004cf1a6  inc      edx
0x004cf1a7  mov      dword ptr [ebp - 0x18], edx
0x004cf1aa  mov      dword ptr [ebp - 0x20], eax
0x004cf1ad  cmp      eax, 0x12c0
0x004cf1b2  jl       0x4cf160
0x004cf1b4  cmp      dword ptr [ebp - 0x24], 0
0x004cf1b8  jne      0x4cf1e3
0x004cf1ba  mov      ecx, dword ptr [ebp + 0xc]
0x004cf1bd  mov      eax, dword ptr [ecx + 0x2584]
0x004cf1c3  cmp      eax, 0x4f
0x004cf1c6  ja       0x4cf1e3
0x004cf1c8  mov      ecx, dword ptr [ecx + 0x2588]
0x004cf1ce  mov      edi, dword ptr [ebp - 0x14]
0x004cf1d1  cmp      ecx, 0x3b
0x004cf1d4  ja       0x4cf1e6
0x004cf1d6  push     -1
0x004cf1d8  push     ecx
0x004cf1d9  push     eax
0x004cf1da  mov      ecx, edi
0x004cf1dc  call     0x4ceea0
0x004cf1e1  jmp      0x4cf1e6
0x004cf1e3  mov      edi, dword ptr [ebp - 0x14]
0x004cf1e6  mov      ecx, dword ptr [ebp - 0x28]
0x004cf1e9  mov      ecx, dword ptr [ecx + 0x80]
0x004cf1ef  test     ecx, ecx
0x004cf1f1  je       0x4cf1fa
0x004cf1f3  mov      eax, dword ptr [ecx]
0x004cf1f5  push     0
0x004cf1f7  call     dword ptr [eax + 0x44]
0x004cf1fa  mov      esi, dword ptr [edi + 0x14]
0x004cf1fd  push     esi
0x004cf1fe  call     dword ptr [0x715304]
0x004cf204  mov      byte ptr [esi + 0x25], 0
0x004cf208  push     esi
0x004cf209  mov      byte ptr [esi + 0x18], 0
0x004cf20d  call     dword ptr [0x715300]
0x004cf213  mov      eax, dword ptr [0x76a338]
0x004cf218  mov      ecx, 1
0x004cf21d  push     0x724948
0x004cf222  mov      eax, dword ptr [eax + 0x2834]
0x004cf228  cdq      
0x004cf229  and      edx, 0x1ff
0x004cf22f  add      eax, edx
0x004cf231  and      eax, 0xfffffe00
0x004cf236  cmp      eax, ecx
0x004cf238  cmovl    eax, ecx
0x004cf23b  mov      dword ptr [ebp - 0x2c], eax
0x004cf23e  lea      eax, [ebp - 0x10]
0x004cf241  push     eax
0x004cf242  call     0x44d010
0x004cf247  mov      ecx, eax
0x004cf249  call     0x44d570
0x004cf24e  mov      dword ptr [ebp - 4], 0
0x004cf255  mov      eax, dword ptr [ebp - 0x10]
0x004cf258  test     eax, eax
0x004cf25a  je       0x4cf6b4
0x004cf260  mov      dword ptr [eax + 0xc], 4
0x004cf267  mov      edx, 0x724958
0x004cf26c  mov      eax, dword ptr [ebp - 0x10]
0x004cf26f  push     0x11b
0x004cf274  mov      dword ptr [eax + 8], 0xa0
0x004cf27b  mov      eax, dword ptr [ebp - 0x10]
0x004cf27e  mov      dword ptr [eax + 0x10], 1
0x004cf285  mov      eax, dword ptr [ebp - 0x10]
0x004cf288  mov      dword ptr [eax + 0x14], 0x8c
0x004cf28f  mov      ecx, dword ptr [ebp - 0x10]
0x004cf292  mov      eax, dword ptr [edi + 0x14]
0x004cf295  mov      dword ptr [ecx + 0x3c], eax
0x004cf298  mov      ecx, 0x38
0x004cf29d  mov      eax, dword ptr [ebp - 0x10]
0x004cf2a0  mov      dword ptr [eax + 0x38], 0
0x004cf2a7  mov      dword ptr [eax + 0x34], 0
0x004cf2ae  mov      dword ptr [eax + 0x30], 0
0x004cf2b5  mov      eax, dword ptr [ebp - 0x10]
0x004cf2b8  mov      dword ptr [eax + 0x2c], 0
0x004cf2bf  mov      dword ptr [eax + 0x28], 0
0x004cf2c6  mov      dword ptr [eax + 0x24], 0
0x004cf2cd  mov      eax, dword ptr [ebp - 0x10]
0x004cf2d0  mov      dword ptr [eax + 0x20], 0
0x004cf2d7  mov      dword ptr [eax + 0x1c], 0
0x004cf2de  mov      dword ptr [eax + 0x18], 0
0x004cf2e5  call     0x6ba810
0x004cf2ea  add      esp, 4
0x004cf2ed  mov      dword ptr [ebp + 0xc], eax
0x004cf2f0  test     eax, eax
0x004cf2f2  je       0x4cf30e
0x004cf2f4  mov      ecx, eax
0x004cf2f6  call     0x45fae0
0x004cf2fb  mov      ecx, dword ptr [ebp - 0x10]
0x004cf2fe  mov      edx, dword ptr [ecx + 0x44]
0x004cf301  mov      dword ptr [ecx + 0x44], eax
0x004cf304  test     eax, eax
0x004cf306  je       0x4cf31b
0x004cf308  lock inc dword ptr [eax + 4]
0x004cf30c  jmp      0x4cf31b
0x004cf30e  mov      eax, dword ptr [ebp - 0x10]
0x004cf311  mov      edx, dword ptr [eax + 0x44]
0x004cf314  mov      dword ptr [eax + 0x44], 0
0x004cf31b  test     edx, edx
0x004cf31d  je       0x4cf331
0x004cf31f  or       eax, 0xffffffff
0x004cf322  lock xadd dword ptr [edx + 4], eax
0x004cf327  jne      0x4cf331
0x004cf329  mov      eax, dword ptr [edx]
0x004cf32b  mov      ecx, edx
0x004cf32d  push     1
0x004cf32f  call     dword ptr [eax]
0x004cf331  mov      ecx, dword ptr [ebp - 0x10]
0x004cf334  push     0
0x004cf336  push     4
0x004cf338  push     0x1c4
0x004cf33d  mov      ecx, dword ptr [ecx + 0x44]
0x004cf340  call     0x45fd00
0x004cf345  mov      eax, dword ptr [ebp - 0x10]
0x004cf348  mov      esi, dword ptr [eax + 0x44]
0x004cf34b  mov      ecx, dword ptr [esi + 0x28]
0x004cf34e  test     ecx, ecx
0x004cf350  je       0x4cf35d
0x004cf352  cmp      byte ptr [esi + 9], 0
0x004cf356  jne      0x4cf35d
0x004cf358  call     0x6ba940
0x004cf35d  lea      eax, [edi + 0x18]
0x004cf360  mov      dword ptr [esi + 0x2c], 6
0x004cf367  mov      dword ptr [esi + 0x28], eax
0x004cf36a  mov      byte ptr [esi + 9], 1
0x004cf36e  mov      eax, dword ptr [ebp - 0x10]
0x004cf371  mov      esi, dword ptr [eax + 0x44]
0x004cf374  inc      dword ptr [esi + 0x10]
0x004cf377  cmp      dword ptr [esi + 0x10], 0
0x004cf37b  jle      0x4cf3b2
0x004cf37d  mov      ecx, dword ptr [esi + 0x14]
0x004cf380  test     ecx, ecx
0x004cf382  je       0x4cf3b2
0x004cf384  mov      ecx, dword ptr [ecx]
0x004cf386  test     ecx, ecx
0x004cf388  jne      0x4cf38e
0x004cf38a  xor      eax, eax
0x004cf38c  jmp      0x4cf3a8
0x004cf38e  push     0
0x004cf390  mov      dword ptr [ebp - 0x28], 0
0x004cf397  lea      edx, [ebp - 0x28]
0x004cf39a  mov      eax, dword ptr [ecx]
0x004cf39c  push     edx
0x004cf39d  push     0x1821
0x004cf3a2  call     dword ptr [eax + 0x10]
0x004cf3a5  mov      eax, dword ptr [ebp - 0x28]
0x004cf3a8  mov      dword ptr [esi + 0xc], eax
0x004cf3ab  mov      dword ptr [esi + 0x34], 0
0x004cf3b2  mov      edx, dword ptr [esi + 0xc]
0x004cf3b5  xor      eax, eax
0x004cf3b7  mov      ecx, dword ptr [esi + 0x24]
0x004cf3ba  xor      esi, esi
0x004cf3bc  movss    xmm1, dword ptr [0x737130]
0x004cf3c4  xor      edi, edi
0x004cf3c6  mov      dword ptr [ebp - 0x14], edx
0x004cf3c9  mov      dword ptr [ebp + 0xc], ecx
0x004cf3cc  mov      dword ptr [ebp - 0x30], eax
0x004cf3cf  mov      dword ptr [ebp - 0x20], edi
0x004cf3d2  movd     xmm0, eax
0x004cf3d6  mov      edi, esi
0x004cf3d8  cvtdq2ps xmm0, xmm0
0x004cf3db  shl      edi, 5
0x004cf3de  mov      dword ptr [ebp - 0x18], 0
0x004cf3e5  add      edi, edx
0x004cf3e7  mov      dword ptr [ebp - 0x1c], 0
0x004cf3ee  mulss    xmm0, xmm1
0x004cf3f2  movss    dword ptr [ebp - 0x24], xmm0
0x004cf3f7  test     esi, esi
0x004cf3f9  js       0x4cf42b
0x004cf3fb  cmp      esi, ecx
0x004cf3fd  jge      0x4cf42b
0x004cf3ff  movd     xmm0, dword ptr [ebp - 0x1c]
0x004cf404  cvtdq2ps xmm0, xmm0
0x004cf407  movss    dword ptr [edi], xmm0
0x004cf40b  movd     xmm0, dword ptr [ebp - 0x20]
0x004cf410  cvtdq2ps xmm0, xmm0
0x004cf413  movss    dword ptr [edi + 4], xmm0
0x004cf418  mov      dword ptr [edi + 8], 0x3f3fff58
0x004cf41f  mov      dword ptr [edi + 0xc], 0x3faaab40
0x004cf426  jmp      0x4cf4ec
0x004cf42b  push     0
0x004cf42d  push     0
0x004cf42f  push     1
0x004cf431  push     0xc000008c
0x004cf436  call     ebx
0x004cf438  movd     xmm0, dword ptr [ebp - 0x1c]
0x004cf43d  mov      edx, dword ptr [ebp - 0x14]
0x004cf440  cvtdq2ps xmm0, xmm0
0x004cf443  movss    dword ptr [edx], xmm0
0x004cf447  test     esi, esi
0x004cf449  js       0x4cf46d
0x004cf44b  cmp      esi, dword ptr [ebp + 0xc]
0x004cf44e  jge      0x4cf46d
0x004cf450  movd     xmm0, dword ptr [ebp - 0x20]
0x004cf455  cvtdq2ps xmm0, xmm0
0x004cf458  movss    dword ptr [edi + 4], xmm0
0x004cf45d  mov      dword ptr [edi + 8], 0x3f3fff58
0x004cf464  mov      dword ptr [edi + 0xc], 0x3faaab40
0x004cf46b  jmp      0x4cf4ec
0x004cf46d  push     0
0x004cf46f  push     0
0x004cf471  push     1
0x004cf473  push     0xc000008c
0x004cf478  call     ebx
0x004cf47a  movd     xmm0, dword ptr [ebp - 0x20]
0x004cf47f  mov      edx, dword ptr [ebp - 0x14]
0x004cf482  cvtdq2ps xmm0, xmm0
0x004cf485  movss    dword ptr [edx + 4], xmm0
0x004cf48a  test     esi, esi
0x004cf48c  js       0x4cf4a3
0x004cf48e  cmp      esi, dword ptr [ebp + 0xc]
0x004cf491  jge      0x4cf4a3
0x004cf493  mov      dword ptr [edi + 8], 0x3f3fff58
0x004cf49a  mov      dword ptr [edi + 0xc], 0x3faaab40
0x004cf4a1  jmp      0x4cf4ec
0x004cf4a3  push     0
0x004cf4a5  push     0
0x004cf4a7  push     1
0x004cf4a9  push     0xc000008c
0x004cf4ae  call     ebx
0x004cf4b0  mov      edx, dword ptr [ebp - 0x14]
0x004cf4b3  mov      dword ptr [edx + 8], 0x3f3fff58
0x004cf4ba  test     esi, esi
0x004cf4bc  js       0x4cf4cc
0x004cf4be  cmp      esi, dword ptr [ebp + 0xc]
0x004cf4c1  jge      0x4cf4cc
0x004cf4c3  mov      dword ptr [edi + 0xc], 0x3faaab40
0x004cf4ca  jmp      0x4cf4ec
0x004cf4cc  push     0
0x004cf4ce  push     0
0x004cf4d0  push     1
0x004cf4d2  push     0xc000008c
0x004cf4d7  call     ebx
0x004cf4d9  mov      edx, dword ptr [ebp - 0x14]
0x004cf4dc  mov      dword ptr [edx + 0xc], 0x3faaab40
0x004cf4e3  test     esi, esi
0x004cf4e5  js       0x4cf519
0x004cf4e7  cmp      esi, dword ptr [ebp + 0xc]
0x004cf4ea  jge      0x4cf519
0x004cf4ec  movd     xmm0, dword ptr [ebp - 0x18]
0x004cf4f1  mov      eax, edi
0x004cf4f3  cvtdq2ps xmm0, xmm0
0x004cf4f6  mulss    xmm0, dword ptr [0x737130]
0x004cf4fe  movss    dword ptr [edi + 0x18], xmm0
0x004cf503  movss    xmm0, dword ptr [ebp - 0x24]
0x004cf508  movss    dword ptr [edi + 0x1c], xmm0
0x004cf50d  mov      dword ptr [edi + 0x10], 0xffffffff
0x004cf514  jmp      0x4cf5e3
0x004cf519  push     0
0x004cf51b  push     0
0x004cf51d  push     1
0x004cf51f  push     0xc000008c
0x004cf524  call     ebx
0x004cf526  movd     xmm0, dword ptr [ebp - 0x18]
0x004cf52b  mov      edx, dword ptr [ebp - 0x14]
0x004cf52e  cvtdq2ps xmm0, xmm0
0x004cf531  mulss    xmm0, dword ptr [0x737130]
0x004cf539  movss    dword ptr [edx + 0x18], xmm0
0x004cf53e  test     esi, esi
0x004cf540  js       0x4cf55f
0x004cf542  cmp      esi, dword ptr [ebp + 0xc]
0x004cf545  jge      0x4cf55f
0x004cf547  movss    xmm0, dword ptr [ebp - 0x24]
0x004cf54c  mov      eax, edi
0x004cf54e  movss    dword ptr [edi + 0x1c], xmm0
0x004cf553  mov      dword ptr [edi + 0x10], 0xffffffff
0x004cf55a  jmp      0x4cf5e3
0x004cf55f  push     0
0x004cf561  push     0
0x004cf563  push     1
0x004cf565  push     0xc000008c
0x004cf56a  call     ebx
0x004cf56c  mov      edx, dword ptr [ebp - 0x14]
0x004cf56f  movss    xmm0, dword ptr [ebp - 0x24]
0x004cf574  movss    dword ptr [edx + 0x1c], xmm0
0x004cf579  test     esi, esi
0x004cf57b  js       0x4cf58d
0x004cf57d  cmp      esi, dword ptr [ebp + 0xc]
0x004cf580  jge      0x4cf58d
0x004cf582  mov      dword ptr [edi + 0x10], 0xffffffff
0x004cf589  mov      eax, edi
0x004cf58b  jmp      0x4cf5e3
0x004cf58d  push     0
0x004cf58f  push     0
0x004cf591  push     1
0x004cf593  push     0xc000008c
0x004cf598  call     ebx
0x004cf59a  mov      edx, dword ptr [ebp - 0x14]
0x004cf59d  mov      dword ptr [edx + 0x10], 0xffffffff
0x004cf5a4  test     esi, esi
0x004cf5a6  js       0x4cf5ad
0x004cf5a8  cmp      esi, dword ptr [ebp + 0xc]
0x004cf5ab  jl       0x4cf5cd
0x004cf5ad  push     0
0x004cf5af  push     0
0x004cf5b1  push     1
0x004cf5b3  push     0xc000008c
0x004cf5b8  call     ebx
0x004cf5ba  mov      edx, dword ptr [ebp - 0x14]
0x004cf5bd  mov      dword ptr [edx + 0x14], 0x64646464
0x004cf5c4  test     esi, esi
0x004cf5c6  js       0x4cf5d1
0x004cf5c8  cmp      esi, dword ptr [ebp + 0xc]
0x004cf5cb  jge      0x4cf5d1
0x004cf5cd  mov      eax, edi
0x004cf5cf  jmp      0x4cf5e3
0x004cf5d1  push     0
0x004cf5d3  push     0
0x004cf5d5  push     1
0x004cf5d7  push     0xc000008c
0x004cf5dc  call     ebx
0x004cf5de  mov      edx, dword ptr [ebp - 0x14]
0x004cf5e1  mov      eax, edx
0x004cf5e3  mov      ecx, dword ptr [ebp - 0x2c]
0x004cf5e6  inc      esi
0x004cf5e7  add      dword ptr [ebp - 0x1c], ecx
0x004cf5ea  add      edi, 0x20
0x004cf5ed  mov      ecx, dword ptr [ebp + 0xc]
0x004cf5f0  mov      dword ptr [eax + 0x14], 0
0x004cf5f7  mov      eax, dword ptr [ebp - 0x18]
0x004cf5fa  inc      eax
0x004cf5fb  mov      dword ptr [ebp - 0x18], eax
0x004cf5fe  cmp      eax, 2
0x004cf601  jl       0x4cf3f7
0x004cf607  mov      eax, dword ptr [ebp - 0x30]
0x004cf60a  mov      edi, dword ptr [ebp - 0x20]
0x004cf60d  inc      eax
0x004cf60e  add      edi, dword ptr [ebp - 0x2c]
0x004cf611  movss    xmm1, dword ptr [0x737130]
0x004cf619  mov      dword ptr [ebp - 0x30], eax
0x004cf61c  mov      dword ptr [ebp - 0x20], edi
0x004cf61f  cmp      eax, 2
0x004cf622  jl       0x4cf3d2
0x004cf628  mov      eax, dword ptr [ebp - 0x10]
0x004cf62b  mov      esi, dword ptr [eax + 0x44]
0x004cf62e  add      dword ptr [esi + 0x10], -1
0x004cf632  jne      0x4cf64d
0x004cf634  mov      ecx, dword ptr [esi + 0x14]
0x004cf637  test     ecx, ecx
0x004cf639  je       0x4cf64d
0x004cf63b  mov      ecx, dword ptr [ecx]
0x004cf63d  test     ecx, ecx
0x004cf63f  je       0x4cf646
0x004cf641  mov      eax, dword ptr [ecx]
0x004cf643  call     dword ptr [eax + 0x18]
0x004cf646  mov      dword ptr [esi + 0xc], 0
0x004cf64d  mov      esi, dword ptr [ebp - 0x10]
0x004cf650  mov      dword ptr [ebp + 0xc], esi
0x004cf653  test     esi, esi
0x004cf655  je       0x4cf65b
0x004cf657  lock inc dword ptr [esi + 4]
0x004cf65b  mov      byte ptr [ebp - 4], 1
0x004cf65f  call     0x44d010
0x004cf664  mov      byte ptr [ebp - 4], 2
0x004cf668  push     ecx
0x004cf669  mov      ecx, esp
0x004cf66b  mov      dword ptr [ecx], esi
0x004cf66d  test     esi, esi
0x004cf66f  je       0x4cf675
0x004cf671  lock inc dword ptr [esi + 4]
0x004cf675  mov      ecx, dword ptr [eax + 0x22e8]
0x004cf67b  call     0x450720
0x004cf680  or       edx, 0xffffffff
0x004cf683  test     esi, esi
0x004cf685  je       0x4cf69b
0x004cf687  mov      eax, edx
0x004cf689  lock xadd dword ptr [esi + 4], eax
0x004cf68e  jne      0x4cf69b
0x004cf690  mov      eax, dword ptr [esi]
0x004cf692  mov      ecx, esi
0x004cf694  push     1
0x004cf696  call     dword ptr [eax]
0x004cf698  or       edx, 0xffffffff
0x004cf69b  mov      ecx, dword ptr [ebp - 0x10]
0x004cf69e  test     ecx, ecx
0x004cf6a0  je       0x4cf6b4
0x004cf6a2  lock xadd dword ptr [ecx + 4], edx
0x004cf6a7  dec      edx
0x004cf6a8  jne      0x4cf6b4
0x004cf6aa  test     ecx, ecx
0x004cf6ac  je       0x4cf6b4
0x004cf6ae  mov      eax, dword ptr [ecx]
0x004cf6b0  push     1
0x004cf6b2  call     dword ptr [eax]
0x004cf6b4  mov      ecx, dword ptr [ebp - 0xc]
0x004cf6b7  mov      dword ptr fs:[0], ecx
0x004cf6be  pop      ecx
0x004cf6bf  pop      edi
0x004cf6c0  pop      esi
0x004cf6c1  pop      ebx
0x004cf6c2  mov      esp, ebp
0x004cf6c4  pop      ebp
0x004cf6c5  ret      8
