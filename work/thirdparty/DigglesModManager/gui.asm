==============================================================================
func FUN_00503420 entry=0x00503420 size=1515
==============================================================================
0x00503420  push     ebp
0x00503421  mov      ebp, esp
0x00503423  push     -1
0x00503425  push     0x700b8d
0x0050342a  mov      eax, dword ptr fs:[0]
0x00503430  push     eax
0x00503431  sub      esp, 0xc
0x00503434  push     ebx
0x00503435  push     esi
0x00503436  push     edi
0x00503437  mov      eax, dword ptr [0x76700c]
0x0050343c  xor      eax, ebp
0x0050343e  push     eax
0x0050343f  lea      eax, [ebp - 0xc]
0x00503442  mov      dword ptr fs:[0], eax
0x00503448  mov      ebx, ecx
0x0050344a  mov      dword ptr [ebp - 0x18], ebx
0x0050344d  mov      eax, dword ptr [0x772400]
0x00503452  cmp      byte ptr [eax + 0x3c9], 0
0x00503459  jne      0x5039f7
0x0050345f  mov      ecx, dword ptr [ebp + 8]
0x00503462  mov      eax, dword ptr [ecx]
0x00503464  cmp      eax, 0x401
0x00503469  ja       0x5037bd
0x0050346f  je       0x503684
0x00503475  sub      eax, 0x300
0x0050347a  je       0x5035a4
0x00503480  sub      eax, 1
0x00503483  jne      0x5039f7
0x00503489  movzx    eax, word ptr [ecx + 0x10]
0x0050348d  push     eax
0x0050348e  call     dword ptr [0x715038]
0x00503494  add      esp, 4
0x00503497  movzx    eax, ax
0x0050349a  mov      dword ptr [ebp - 0x14], eax
0x0050349d  call     0x4e4550
0x005034a2  push     1
0x005034a4  push     0
0x005034a6  push     0
0x005034a8  mov      dword ptr [eax], 3
0x005034ae  lea      eax, [ebp + 8]
0x005034b1  mov      ecx, dword ptr [0x772400]
0x005034b7  push     eax
0x005034b8  lea      ecx, [ecx + 0x148]
0x005034be  call     0x4e4c40
0x005034c3  mov      dword ptr [ebp - 4], 5
0x005034ca  mov      esi, dword ptr [ebp + 8]
0x005034cd  mov      ecx, dword ptr [esi + 8]
0x005034d0  cmp      ecx, -1
0x005034d3  jne      0x5034ec
0x005034d5  lea      ecx, [esi + 0xc]
0x005034d8  lea      edx, [ecx + 1]
0x005034db  nop      dword ptr [eax + eax]
0x005034e0  mov      al, byte ptr [ecx]
0x005034e2  inc      ecx
0x005034e3  test     al, al
0x005034e5  jne      0x5034e0
0x005034e7  sub      ecx, edx
0x005034e9  mov      dword ptr [esi + 8], ecx
0x005034ec  test     ecx, ecx
0x005034ee  jle      0x503508
0x005034f0  push     ecx
0x005034f1  mov      ecx, dword ptr [0x772400]
0x005034f7  mov      eax, esp
0x005034f9  mov      dword ptr [eax], esi
0x005034fb  lea      ecx, [ecx + 0x368]
0x00503501  inc      dword ptr [esi]
0x00503503  call     0x54ea20
0x00503508  push     dword ptr [0x7723d8]
0x0050350e  mov      edx, dword ptr [ebx + 0x8194]
0x00503514  lea      ecx, [ebp - 0x10]
0x00503517  call     0x4ed780
0x0050351c  add      esp, 4
0x0050351f  push     0x80
0x00503524  push     0xc932f8
0x00503529  push     0
0x0050352b  mov      byte ptr [ebp - 4], 6
0x0050352f  call     dword ptr [0x715428]
0x00503535  mov      edi, dword ptr [ebp - 0x10]
0x00503538  push     0xc932f8
0x0050353d  lea      ecx, [edi + 0x3c]
0x00503540  call     0x6b9200
0x00503545  mov      ecx, dword ptr [ebp - 0x14]
0x00503548  lea      ebx, [edi + 4]
0x0050354b  movzx    eax, cx
0x0050354e  mov      dword ptr [edi + 0x40], eax
0x00503551  push     ecx
0x00503552  mov      eax, esp
0x00503554  mov      dword ptr [edi + 0x44], 0
0x0050355b  mov      dword ptr [eax], edi
0x0050355d  lock inc dword ptr [ebx]
0x00503560  mov      ecx, dword ptr [ebp - 0x18]
0x00503563  call     0x4ed820
0x00503568  or       eax, 0xffffffff
0x0050356b  lock xadd dword ptr [ebx], eax
0x0050356f  jne      0x503579
0x00503571  mov      eax, dword ptr [edi]
0x00503573  mov      ecx, edi
0x00503575  push     1
0x00503577  call     dword ptr [eax]
0x00503579  mov      dword ptr [ebp - 4], 7
0x00503580  add      dword ptr [esi], -1
0x00503583  jne      0x5039f7
0x00503589  mov      ecx, esi
0x0050358b  call     0x6ba940
0x00503590  mov      ecx, dword ptr [ebp - 0xc]
0x00503593  mov      dword ptr fs:[0], ecx
0x0050359a  pop      ecx
0x0050359b  pop      edi
0x0050359c  pop      esi
0x0050359d  pop      ebx
0x0050359e  mov      esp, ebp
0x005035a0  pop      ebp
0x005035a1  ret      4
0x005035a4  cmp      byte ptr [ecx + 0xd], 0
0x005035a8  movzx    eax, word ptr [ecx + 0x10]
0x005035ac  jne      0x5035d8
0x005035ae  push     ecx
0x005035af  push     eax
0x005035b0  call     dword ptr [0x715038]
0x005035b6  add      esp, 4
0x005035b9  movzx    eax, ax
0x005035bc  mov      ecx, ebx
0x005035be  push     eax
0x005035bf  call     0x5032a0
0x005035c4  mov      ecx, dword ptr [ebp - 0xc]
0x005035c7  mov      dword ptr fs:[0], ecx
0x005035ce  pop      ecx
0x005035cf  pop      edi
0x005035d0  pop      esi
0x005035d1  pop      ebx
0x005035d2  mov      esp, ebp
0x005035d4  pop      ebp
0x005035d5  ret      4
0x005035d8  push     eax
0x005035d9  call     dword ptr [0x715038]
0x005035df  movzx    eax, ax
0x005035e2  add      esp, 4
0x005035e5  mov      dword ptr [ebp + 8], eax
0x005035e8  test     ax, ax
0x005035eb  je       0x50362e
0x005035ed  cmp      eax, 0x7f
0x005035f0  jae      0x50362e
0x005035f2  cmp      al, 0x41
0x005035f4  jl       0x5035fa
0x005035f6  cmp      al, 0x5a
0x005035f8  jle      0x50360e
0x005035fa  cmp      al, 0x30
0x005035fc  jl       0x503602
0x005035fe  cmp      al, 0x39
0x00503600  jle      0x50360e
0x00503602  cmp      al, 0x6d
0x00503604  je       0x50360e
0x00503606  cmp      al, 0x20
0x00503608  je       0x50360e
0x0050360a  cmp      al, 8
0x0050360c  jne      0x50362e
0x0050360e  push     0x10
0x00503610  call     dword ptr [0x715424]
0x00503616  mov      edi, dword ptr [ebp + 8]
0x00503619  mov      ecx, ebx
0x0050361b  shr      eax, 0xf
0x0050361e  and      al, 1
0x00503620  mov      byte ptr [ebp - 0x18], al
0x00503623  push     dword ptr [ebp - 0x18]
0x00503626  push     edi
0x00503627  call     0x503190
0x0050362c  jmp      0x503631
0x0050362e  mov      edi, dword ptr [ebp + 8]
0x00503631  push     dword ptr [0x772380]
0x00503637  mov      edx, dword ptr [ebx + 0x8194]
0x0050363d  lea      ecx, [ebp + 8]
0x00503640  call     0x4ed780
0x00503645  add      esp, 4
0x00503648  push     0x80
0x0050364d  push     0xc93278
0x00503652  push     0
0x00503654  mov      dword ptr [ebp - 4], 4
0x0050365b  call     dword ptr [0x715428]
0x00503661  mov      esi, dword ptr [ebp + 8]
0x00503664  push     0xc93278
0x00503669  lea      ecx, [esi + 0x3c]
0x0050366c  call     0x6b9200
0x00503671  movzx    eax, di
0x00503674  mov      dword ptr [esi + 0x40], eax
0x00503677  mov      dword ptr [esi + 0x44], 0
0x0050367e  push     ecx
0x0050367f  jmp      0x503803
0x00503684  movzx    eax, byte ptr [ecx + 0x10]
0x00503688  sub      eax, 1
0x0050368b  je       0x5036d6
0x0050368d  sub      eax, 2
0x00503690  jne      0x5039f7
0x00503696  mov      edx, dword ptr [ecx + 0x18]
0x00503699  sub      esp, 8
0x0050369c  mov      ecx, dword ptr [ecx + 0x14]
0x0050369f  mov      eax, esp
0x005036a1  mov      dword ptr [eax], ecx
0x005036a3  mov      ecx, ebx
0x005036a5  mov      dword ptr [eax + 4], edx
0x005036a8  call     0x502e50
0x005036ad  push     1
0x005036af  mov      ecx, ebx
0x005036b1  call     0x503060
0x005036b6  call     0x4ecd40
0x005036bb  mov      byte ptr [eax + 0x219], 1
0x005036c2  mov      ecx, dword ptr [ebp - 0xc]
0x005036c5  mov      dword ptr fs:[0], ecx
0x005036cc  pop      ecx
0x005036cd  pop      edi
0x005036ce  pop      esi
0x005036cf  pop      ebx
0x005036d0  mov      esp, ebp
0x005036d2  pop      ebp
0x005036d3  ret      4
0x005036d6  cmp      byte ptr [ecx + 0x12], 2
0x005036da  jne      0x50377d
0x005036e0  call     0x4e4550
0x005036e5  mov      dword ptr [ebp + 8], 0
0x005036ec  mov      dword ptr [eax], 3
0x005036f2  mov      dword ptr [ebp - 4], 0
0x005036f9  lea      ecx, [ebp - 0x18]
0x005036fc  push     dword ptr [0x7723c0]
0x00503702  mov      edx, dword ptr [ebx + 0x8194]
0x00503708  call     0x4ed780
0x0050370d  add      esp, 4
0x00503710  mov      esi, dword ptr [eax]
0x00503712  mov      dword ptr [ebp + 8], esi
0x00503715  test     esi, esi
0x00503717  je       0x50371f
0x00503719  lea      eax, [esi + 4]
0x0050371c  lock inc dword ptr [eax]
0x0050371f  mov      ecx, dword ptr [ebp - 0x18]
0x00503722  or       edi, 0xffffffff
0x00503725  test     ecx, ecx
0x00503727  je       0x50373c
0x00503729  mov      eax, edi
0x0050372b  lock xadd dword ptr [ecx + 4], eax
0x00503730  jne      0x50373c
0x00503732  test     ecx, ecx
0x00503734  je       0x50373c
0x00503736  mov      eax, dword ptr [ecx]
0x00503738  push     1
0x0050373a  call     dword ptr [eax]
0x0050373c  mov      byte ptr [ebx + 0x10], 0
0x00503740  mov      ecx, dword ptr [ebx + 0x101d8]
0x00503746  mov      eax, dword ptr [ebx + 0x101d4]
0x0050374c  mov      dword ptr [esi + 0x24], eax
0x0050374f  mov      dword ptr [esi + 0x28], ecx
0x00503752  push     ecx
0x00503753  mov      eax, esp
0x00503755  mov      dword ptr [eax], esi
0x00503757  test     esi, esi
0x00503759  je       0x503761
0x0050375b  lea      eax, [esi + 4]
0x0050375e  lock inc dword ptr [eax]
0x00503761  mov      ecx, ebx
0x00503763  call     0x4ed820
0x00503768  test     esi, esi
0x0050376a  je       0x5039f7
0x00503770  lea      eax, [esi + 4]
0x00503773  lock xadd dword ptr [eax], edi
0x00503777  dec      edi
0x00503778  jmp      0x50381b
0x0050377d  mov      edx, dword ptr [ecx + 0x18]
0x00503780  sub      esp, 8
0x00503783  mov      ecx, dword ptr [ecx + 0x14]
0x00503786  mov      eax, esp
0x00503788  mov      dword ptr [eax], ecx
0x0050378a  mov      ecx, ebx
0x0050378c  mov      dword ptr [eax + 4], edx
0x0050378f  call     0x502e50
0x00503794  push     1
0x00503796  mov      ecx, ebx
0x00503798  call     0x502f20
0x0050379d  call     0x4ecd40
0x005037a2  mov      byte ptr [eax + 0x218], 1
0x005037a9  mov      ecx, dword ptr [ebp - 0xc]
0x005037ac  mov      dword ptr fs:[0], ecx
0x005037b3  pop      ecx
0x005037b4  pop      edi
0x005037b5  pop      esi
0x005037b6  pop      ebx
0x005037b7  mov      esp, ebp
0x005037b9  pop      ebp
0x005037ba  ret      4
0x005037bd  sub      eax, 0x402
0x005037c2  je       0x50383d
0x005037c4  sub      eax, 1
0x005037c7  jne      0x5039f7
0x005037cd  mov      edi, dword ptr [ecx + 0x14]
0x005037d0  lea      ecx, [ebp + 8]
0x005037d3  push     dword ptr [0x7723bc]
0x005037d9  mov      edx, dword ptr [ebx + 0x8194]
0x005037df  call     0x4ed780
0x005037e4  mov      dword ptr [ebp - 4], 3
0x005037eb  mov      esi, dword ptr [ebp + 8]
0x005037ee  mov      eax, dword ptr [ebx + 0x101d4]
0x005037f4  mov      ecx, dword ptr [ebx + 0x101d8]
0x005037fa  mov      dword ptr [esi + 0x24], eax
0x005037fd  mov      dword ptr [esi + 0x28], ecx
0x00503800  mov      dword ptr [esi + 0x40], edi
0x00503803  mov      eax, esp
0x00503805  lea      edi, [esi + 4]
0x00503808  mov      dword ptr [eax], esi
0x0050380a  lock inc dword ptr [edi]
0x0050380d  mov      ecx, ebx
0x0050380f  call     0x4ed820
0x00503814  or       eax, 0xffffffff
0x00503817  lock xadd dword ptr [edi], eax
0x0050381b  jne      0x5039f7
0x00503821  mov      eax, dword ptr [esi]
0x00503823  mov      ecx, esi
0x00503825  push     1
0x00503827  call     dword ptr [eax]
0x00503829  mov      ecx, dword ptr [ebp - 0xc]
0x0050382c  mov      dword ptr fs:[0], ecx
0x00503833  pop      ecx
0x00503834  pop      edi
0x00503835  pop      esi
0x00503836  pop      ebx
0x00503837  mov      esp, ebp
0x00503839  pop      ebp
0x0050383a  ret      4
0x0050383d  movzx    eax, byte ptr [ecx + 0x10]
0x00503841  sub      eax, 1
0x00503844  je       0x50392f
0x0050384a  sub      eax, 2
0x0050384d  jne      0x5039f7
0x00503853  mov      edx, dword ptr [ecx + 0x18]
0x00503856  sub      esp, 8
0x00503859  mov      ecx, dword ptr [ecx + 0x14]
0x0050385c  mov      eax, esp
0x0050385e  mov      dword ptr [eax], ecx
0x00503860  mov      ecx, ebx
0x00503862  mov      dword ptr [eax + 4], edx
0x00503865  call     0x502e50
0x0050386a  call     0x4e4550
0x0050386f  mov      dword ptr [ebp + 8], 0
0x00503876  mov      dword ptr [eax], 3
0x0050387c  mov      dword ptr [ebp - 4], 2
0x00503883  lea      ecx, [ebp - 0x18]
0x00503886  push     dword ptr [0x7723d0]
0x0050388c  mov      edx, dword ptr [ebx + 0x8194]
0x00503892  call     0x4ed780
0x00503897  add      esp, 4
0x0050389a  mov      esi, dword ptr [eax]
0x0050389c  mov      dword ptr [ebp + 8], esi
0x0050389f  test     esi, esi
0x005038a1  je       0x5038a9
0x005038a3  lea      eax, [esi + 4]
0x005038a6  lock inc dword ptr [eax]
0x005038a9  mov      ecx, dword ptr [ebp - 0x18]
0x005038ac  or       edi, 0xffffffff
0x005038af  test     ecx, ecx
0x005038b1  je       0x5038c6
0x005038b3  mov      eax, edi
0x005038b5  lock xadd dword ptr [ecx + 4], eax
0x005038ba  jne      0x5038c6
0x005038bc  test     ecx, ecx
0x005038be  je       0x5038c6
0x005038c0  mov      eax, dword ptr [ecx]
0x005038c2  push     1
0x005038c4  call     dword ptr [eax]
0x005038c6  mov      byte ptr [ebx + 0x11], 0
0x005038ca  mov      ecx, dword ptr [ebx + 0x101d8]
0x005038d0  mov      eax, dword ptr [ebx + 0x101d4]
0x005038d6  mov      dword ptr [esi + 0x24], eax
0x005038d9  mov      dword ptr [esi + 0x28], ecx
0x005038dc  push     ecx
0x005038dd  mov      eax, esp
0x005038df  mov      dword ptr [eax], esi
0x005038e1  test     esi, esi
0x005038e3  je       0x5038eb
0x005038e5  lea      eax, [esi + 4]
0x005038e8  lock inc dword ptr [eax]
0x005038eb  mov      ecx, ebx
0x005038ed  call     0x4ed820
0x005038f2  mov      dword ptr [ebp - 4], 0xffffffff
0x005038f9  test     esi, esi
0x005038fb  je       0x50390f
0x005038fd  lea      eax, [esi + 4]
0x00503900  lock xadd dword ptr [eax], edi
0x00503904  dec      edi
0x00503905  jne      0x50390f
0x00503907  mov      eax, dword ptr [esi]
0x00503909  mov      ecx, esi
0x0050390b  push     1
0x0050390d  call     dword ptr [eax]
0x0050390f  call     0x4ecd40
0x00503914  mov      byte ptr [eax + 0x319], 1
0x0050391b  mov      ecx, dword ptr [ebp - 0xc]
0x0050391e  mov      dword ptr fs:[0], ecx
0x00503925  pop      ecx
0x00503926  pop      edi
0x00503927  pop      esi
0x00503928  pop      ebx
0x00503929  mov      esp, ebp
0x0050392b  pop      ebp
0x0050392c  ret      4
0x0050392f  mov      edx, dword ptr [ecx + 0x18]
0x00503932  sub      esp, 8
0x00503935  mov      ecx, dword ptr [ecx + 0x14]
0x00503938  mov      eax, esp
0x0050393a  mov      dword ptr [eax], ecx
0x0050393c  mov      ecx, ebx
0x0050393e  mov      dword ptr [eax + 4], edx
0x00503941  call     0x502e50
0x00503946  call     0x4e4550
0x0050394b  mov      dword ptr [ebp + 8], 0
0x00503952  mov      dword ptr [eax], 3
0x00503958  mov      dword ptr [ebp - 4], 1
0x0050395f  lea      ecx, [ebp - 0x18]
0x00503962  push     dword ptr [0x7723c8]
0x00503968  mov      edx, dword ptr [ebx + 0x8194]
0x0050396e  call     0x4ed780
0x00503973  add      esp, 4
0x00503976  mov      esi, dword ptr [eax]
0x00503978  mov      dword ptr [ebp + 8], esi
0x0050397b  test     esi, esi
0x0050397d  je       0x503985
0x0050397f  lea      eax, [esi + 4]
0x00503982  lock inc dword ptr [eax]
0x00503985  mov      ecx, dword ptr [ebp - 0x18]
0x00503988  or       edi, 0xffffffff
0x0050398b  test     ecx, ecx
0x0050398d  je       0x5039a2
0x0050398f  mov      eax, edi
0x00503991  lock xadd dword ptr [ecx + 4], eax
0x00503996  jne      0x5039a2
0x00503998  test     ecx, ecx
0x0050399a  je       0x5039a2
0x0050399c  mov      eax, dword ptr [ecx]
0x0050399e  push     1
0x005039a0  call     dword ptr [eax]
0x005039a2  mov      byte ptr [ebx + 0x10], 0
0x005039a6  mov      ecx, dword ptr [ebx + 0x101d8]
0x005039ac  mov      eax, dword ptr [ebx + 0x101d4]
0x005039b2  mov      dword ptr [esi + 0x24], eax
0x005039b5  mov      dword ptr [esi + 0x28], ecx
0x005039b8  push     ecx
0x005039b9  mov      eax, esp
0x005039bb  mov      dword ptr [eax], esi
0x005039bd  test     esi, esi
0x005039bf  je       0x5039c7
0x005039c1  lea      eax, [esi + 4]
0x005039c4  lock inc dword ptr [eax]
0x005039c7  mov      ecx, ebx
0x005039c9  call     0x4ed820
0x005039ce  mov      dword ptr [ebp - 4], 0xffffffff
0x005039d5  test     esi, esi
0x005039d7  je       0x5039eb
0x005039d9  lea      eax, [esi + 4]
0x005039dc  lock xadd dword ptr [eax], edi
0x005039e0  dec      edi
0x005039e1  jne      0x5039eb
0x005039e3  mov      eax, dword ptr [esi]
0x005039e5  mov      ecx, esi
0x005039e7  push     1
0x005039e9  call     dword ptr [eax]
0x005039eb  call     0x4ecd40
0x005039f0  mov      byte ptr [eax + 0x318], 1
0x005039f7  mov      ecx, dword ptr [ebp - 0xc]
0x005039fa  mov      dword ptr fs:[0], ecx
0x00503a01  pop      ecx
0x00503a02  pop      edi
0x00503a03  pop      esi
0x00503a04  pop      ebx
0x00503a05  mov      esp, ebp
0x00503a07  pop      ebp
0x00503a08  ret      4
