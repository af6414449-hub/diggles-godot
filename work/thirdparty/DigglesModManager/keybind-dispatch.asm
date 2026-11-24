Disassembly of C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe  VA 0x005AB7A0 - 0x005ABE00

0x005AB7A0  add      byte ptr [ecx], al
0x005AB7A2  je       0x5ab7bd
0x005AB7A4  mov      esi, dword ptr [0x7152e0]
0x005AB7AA  nop      word ptr [eax + eax]
0x005AB7B0  push     1
0x005AB7B2  call     esi
0x005AB7B4  cmp      dword ptr [edi + 0x174], 0
0x005AB7BB  jne      0x5ab7b0
0x005AB7BD  mov      eax, dword ptr [edi + 0x184]
0x005AB7C3  cmp      eax, -1
0x005AB7C6  je       0x5ab7d9
0x005AB7C8  push     eax
0x005AB7C9  call     dword ptr [0x7154d8]
0x005AB7CF  mov      dword ptr [edi + 0x184], 0xffffffff
0x005AB7D9  mov      eax, dword ptr [edi + 0x18c]
0x005AB7DF  test     eax, eax
0x005AB7E1  je       0x5ab7f4
0x005AB7E3  push     eax
0x005AB7E4  call     dword ptr [0x7154d4]
0x005AB7EA  mov      dword ptr [edi + 0x18c], 0
0x005AB7F4  xor      esi, esi
0x005AB7F6  push     esi
0x005AB7F7  mov      ecx, edi
0x005AB7F9  call     0x5abde0
0x005AB7FE  inc      esi
0x005AB7FF  cmp      esi, 0x40
0x005AB802  jl       0x5ab7f6
0x005AB804  mov      byte ptr [edi + 0x180], 0
0x005AB80B  pop      edi
0x005AB80C  pop      esi
0x005AB80D  ret      
0x005AB80E  int3     
0x005AB80F  int3     
0x005AB810  push     ebp
0x005AB811  mov      ebp, esp
0x005AB813  sub      esp, 0xc
0x005AB816  push     ebx
0x005AB817  push     esi
0x005AB818  push     edi
0x005AB819  mov      edi, ecx
0x005AB81B  lea      ebx, [edi + 0x150]
0x005AB821  push     ebx
0x005AB822  mov      dword ptr [ebp - 0xc], ebx
0x005AB825  call     dword ptr [0x715304]
0x005AB82B  mov      byte ptr [ebx + 0x18], 1
0x005AB82F  cmp      dword ptr [edi + 0x184], -1
0x005AB836  je       0x5ab858
0x005AB838  push     0
0x005AB83A  push     0
0x005AB83C  push     1
0x005AB83E  lea      eax, [edi + 0x18c]
0x005AB844  push     eax
0x005AB845  push     1
0x005AB847  call     dword ptr [0x7154fc]
0x005AB84D  test     eax, eax
0x005AB84F  jne      0x5ab858
0x005AB851  mov      ecx, edi
0x005AB853  call     0x5ab8e0
0x005AB858  mov      ebx, dword ptr [edi + 0x29c]
0x005AB85E  xor      esi, esi
0x005AB860  test     ebx, ebx
0x005AB862  jle      0x5ab8c7
0x005AB864  cmp      esi, dword ptr [edi + 0x29c]
0x005AB86A  jb       0x5ab87d
0x005AB86C  push     0
0x005AB86E  push     0
0x005AB870  push     1
0x005AB872  push     0xc000008c
0x005AB877  call     dword ptr [0x715340]
0x005AB87D  mov      eax, dword ptr [edi + 0x298]
0x005AB883  mov      eax, dword ptr [eax + esi*4]
0x005AB886  mov      dword ptr [ebp - 8], eax
0x005AB889  mov      eax, dword ptr [edi + eax*4 + 0x198]
0x005AB890  test     eax, eax
0x005AB892  je       0x5ab8c2
0x005AB894  mov      eax, dword ptr [eax + 8]
0x005AB897  cmp      eax, -1
0x005AB89A  je       0x5ab8b6
0x005AB89C  lea      ecx, [ebp - 4]
0x005AB89F  push     ecx
0x005AB8A0  push     0x4004667f
0x005AB8A5  push     eax
0x005AB8A6  call     dword ptr [0x71551c]
0x005AB8AC  test     eax, eax
0x005AB8AE  jne      0x5ab8b6
0x005AB8B0  cmp      dword ptr [ebp - 4], -1
0x005AB8B4  jne      0x5ab8c2
0x005AB8B6  push     dword ptr [ebp - 8]
0x005AB8B9  mov      ecx, edi
0x005AB8BB  call     0x5abde0
0x005AB8C0  dec      esi
0x005AB8C1  dec      ebx
0x005AB8C2  inc      esi
0x005AB8C3  cmp      esi, ebx
0x005AB8C5  jl       0x5ab864
0x005AB8C7  mov      eax, dword ptr [ebp - 0xc]
0x005AB8CA  push     eax
0x005AB8CB  mov      byte ptr [eax + 0x18], 0
0x005AB8CF  call     dword ptr [0x715300]
0x005AB8D5  pop      edi
0x005AB8D6  pop      esi
0x005AB8D7  pop      ebx
0x005AB8D8  mov      esp, ebp
0x005AB8DA  pop      ebp
0x005AB8DB  ret      
0x005AB8DC  int3     
0x005AB8DD  int3     
0x005AB8DE  int3     
0x005AB8DF  int3     
0x005AB8E0  push     ebp
0x005AB8E1  mov      ebp, esp
0x005AB8E3  push     -1
0x005AB8E5  push     0x706ec2
0x005AB8EA  mov      eax, dword ptr fs:[0]
0x005AB8F0  push     eax
0x005AB8F1  sub      esp, 0x194
0x005AB8F7  mov      eax, dword ptr [0x76700c]
0x005AB8FC  xor      eax, ebp
0x005AB8FE  mov      dword ptr [ebp - 0x10], eax
0x005AB901  push     ebx
0x005AB902  push     esi
0x005AB903  push     edi
0x005AB904  push     eax
0x005AB905  lea      eax, [ebp - 0xc]
0x005AB908  mov      dword ptr fs:[0], eax
0x005AB90E  mov      edi, ecx
0x005AB910  mov      dword ptr [ebp - 0x180], edi
0x005AB916  nop      word ptr [eax + eax]
0x005AB920  push     0xc1
0x005AB925  mov      edx, 0x72adb0
0x005AB92A  mov      ecx, 0x20034
0x005AB92F  call     0x6ba810
0x005AB934  mov      ebx, eax
0x005AB936  add      esp, 4
0x005AB939  mov      dword ptr [ebp - 0x194], ebx
0x005AB93F  mov      dword ptr [ebp - 4], 0
0x005AB946  test     ebx, ebx
0x005AB948  je       0x5ab994
0x005AB94A  lea      ecx, [ebx + 0x1c]
0x005AB94D  mov      dword ptr [ebx + 8], 0x100007f
0x005AB954  mov      dword ptr [ebx + 0x10], 0x100007f
0x005AB95B  mov      dword ptr [ebp - 0x198], ecx
0x005AB961  mov      dword ptr [ecx + 0x20010], 0
0x005AB96B  mov      dword ptr [ecx + 0x20014], 0
0x005AB975  mov      byte ptr [ebp - 4], 1
0x005AB979  call     0x5b1670
0x005AB97E  mov      dword ptr [ebx], 0xffffffff
0x005AB984  mov      dword ptr [ebx + 0x14], 0
0x005AB98B  mov      dword ptr [ebx + 0x18], 0
0x005AB992  jmp      0x5ab996
0x005AB994  xor      ebx, ebx
0x005AB996  mov      dword ptr [ebp - 4], 0xffffffff
0x005AB99D  cmp      dword ptr [edi + 0x184], -1
0x005AB9A4  je       0x5abd5a
0x005AB9AA  push     dword ptr [edi + 0x18c]
0x005AB9B0  call     dword ptr [0x715500]
0x005AB9B6  lea      eax, [ebp - 0x17c]
0x005AB9BC  mov      dword ptr [ebp - 0x17c], 0x10
0x005AB9C6  push     eax
0x005AB9C7  lea      eax, [ebp - 0x20]
0x005AB9CA  push     eax
0x005AB9CB  push     dword ptr [edi + 0x184]
0x005AB9D1  call     dword ptr [0x715504]
0x005AB9D7  cmp      eax, -1
0x005AB9DA  je       0x5abd5a
0x005AB9E0  movzx    ecx, word ptr [ebp - 0x1e]
0x005AB9E4  mov      dword ptr [ebx + 4], ecx
0x005AB9E7  mov      ecx, dword ptr [ebp - 0x1c]
0x005AB9EA  mov      dword ptr [ebx + 8], ecx
0x005AB9ED  lea      ecx, [ebp - 0x17c]
0x005AB9F3  push     ecx
0x005AB9F4  lea      ecx, [ebp - 0x20]
0x005AB9F7  mov      dword ptr [ebx], eax
0x005AB9F9  push     ecx
0x005AB9FA  push     eax
0x005AB9FB  mov      dword ptr [ebp - 0x17c], 0x10
0x005ABA05  call     dword ptr [0x7154c8]
0x005ABA0B  movzx    eax, word ptr [ebp - 0x1e]
0x005ABA0F  xor      esi, esi
0x005ABA11  mov      dword ptr [ebx + 0xc], eax
0x005ABA14  mov      eax, dword ptr [ebp - 0x1c]
0x005ABA17  mov      dword ptr [ebx + 0x10], eax
0x005ABA1A  nop      word ptr [eax + eax]
0x005ABA20  mov      eax, dword ptr [ebx]
0x005ABA22  cmp      eax, -1
0x005ABA25  je       0x5aba5d
0x005ABA27  lea      ecx, [ebp - 0x184]
0x005ABA2D  push     ecx
0x005ABA2E  push     0x4004667f
0x005ABA33  push     eax
0x005ABA34  call     dword ptr [0x71551c]
0x005ABA3A  test     eax, eax
0x005ABA3C  jne      0x5aba5d
0x005ABA3E  cmp      dword ptr [ebp - 0x184], 0x14c
0x005ABA48  jae      0x5aba5d
0x005ABA4A  push     2
0x005ABA4C  call     dword ptr [0x7152e0]
0x005ABA52  inc      esi
0x005ABA53  cmp      esi, 0x1e
0x005ABA56  jl       0x5aba20
0x005ABA58  jmp      0x5abd03
0x005ABA5D  mov      eax, dword ptr [ebx]
0x005ABA5F  mov      esi, edi
0x005ABA61  lea      edi, [ebp - 0x170]
0x005ABA67  mov      ecx, 0x53
0x005ABA6C  rep movsd dword ptr es:[edi], dword ptr [esi]
0x005ABA6E  cmp      eax, -1
0x005ABA71  je       0x5abb86
0x005ABA77  lea      ecx, [ebp - 0x19c]
0x005ABA7D  push     ecx
0x005ABA7E  push     0x4004667f
0x005ABA83  push     eax
0x005ABA84  call     dword ptr [0x71551c]
0x005ABA8A  xor      eax, eax
0x005ABA8C  mov      esi, 0x14c
0x005ABA91  mov      dword ptr [ebp - 0x178], eax
0x005ABA97  jmp      0x5abaa6
0x005ABA99  nop      dword ptr [eax]
0x005ABAA0  mov      eax, dword ptr [ebp - 0x178]
0x005ABAA6  push     0
0x005ABAA8  lea      ecx, [ebp - 0x170]
0x005ABAAE  push     esi
0x005ABAAF  add      eax, ecx
0x005ABAB1  push     eax
0x005ABAB2  push     dword ptr [ebx]
0x005ABAB4  call     dword ptr [0x7154e4]
0x005ABABA  mov      ecx, dword ptr [ebp - 0x178]
0x005ABAC0  mov      edi, eax
0x005ABAC2  add      ecx, edi
0x005ABAC4  sub      esi, edi
0x005ABAC6  mov      dword ptr [ebp - 0x178], ecx
0x005ABACC  cmp      edi, -1
0x005ABACF  je       0x5abb01
0x005ABAD1  test     esi, esi
0x005ABAD3  jle      0x5abb01
0x005ABAD5  mov      eax, dword ptr [ebx]
0x005ABAD7  cmp      eax, -1
0x005ABADA  je       0x5abb01
0x005ABADC  lea      ecx, [ebp - 0x188]
0x005ABAE2  push     ecx
0x005ABAE3  push     0x4004667f
0x005ABAE8  push     eax
0x005ABAE9  call     dword ptr [0x71551c]
0x005ABAEF  test     eax, eax
0x005ABAF1  jne      0x5abafb
0x005ABAF3  cmp      dword ptr [ebp - 0x188], esi
0x005ABAF9  jge      0x5abaa0
0x005ABAFB  mov      ecx, dword ptr [ebp - 0x178]
0x005ABB01  cmp      ecx, 0x14c
0x005ABB07  jne      0x5abb0e
0x005ABB09  cmp      edi, -1
0x005ABB0C  jne      0x5abb86
0x005ABB0E  cmp      edi, 0x14c
0x005ABB14  je       0x5abb86
0x005ABB16  lea      eax, [ebp - 0x18c]
0x005ABB1C  mov      dword ptr [ebp - 0x190], 0
0x005ABB26  push     eax
0x005ABB27  lea      eax, [ebp - 0x190]
0x005ABB2D  mov      dword ptr [ebp - 0x18c], 4
0x005ABB37  push     eax
0x005ABB38  push     0x1007
0x005ABB3D  push     0xffff
0x005ABB42  push     dword ptr [ebx]
0x005ABB44  call     dword ptr [0x7154f0]
0x005ABB4A  mov      eax, dword ptr [ebx + 0x14]
0x005ABB4D  mov      esi, dword ptr [0x7154d4]
0x005ABB53  test     eax, eax
0x005ABB55  je       0x5abb5a
0x005ABB57  push     eax
0x005ABB58  call     esi
0x005ABB5A  mov      eax, dword ptr [ebx + 0x18]
0x005ABB5D  test     eax, eax
0x005ABB5F  je       0x5abb64
0x005ABB61  push     eax
0x005ABB62  call     esi
0x005ABB64  mov      eax, dword ptr [ebx]
0x005ABB66  mov      dword ptr [ebx + 0x14], 0
0x005ABB6D  mov      dword ptr [ebx + 0x18], 0
0x005ABB74  cmp      eax, -1
0x005ABB77  je       0x5abb86
0x005ABB79  push     eax
0x005ABB7A  call     dword ptr [0x7154d8]
0x005ABB80  mov      dword ptr [ebx], 0xffffffff
0x005ABB86  mov      edi, dword ptr [ebp - 0x180]
0x005ABB8C  mov      eax, dword ptr [ebp - 0x170]
0x005ABB92  cmp      eax, dword ptr [edi]
0x005ABB94  jne      0x5abd03
0x005ABB9A  mov      eax, dword ptr [ebp - 0x16c]
0x005ABBA0  cmp      eax, dword ptr [edi + 4]
0x005ABBA3  jne      0x5abd03
0x005ABBA9  lea      edx, [edi + 8]
0x005ABBAC  mov      esi, 0x3c
0x005ABBB1  lea      ecx, [ebp - 0x168]
0x005ABBB7  mov      eax, dword ptr [ecx]
0x005ABBB9  cmp      eax, dword ptr [edx]
0x005ABBBB  jne      0x5abbcc
0x005ABBBD  add      ecx, 4
0x005ABBC0  add      edx, 4
0x005ABBC3  sub      esi, 4
0x005ABBC6  jae      0x5abbb7
0x005ABBC8  mov      al, 1
0x005ABBCA  jmp      0x5abbce
0x005ABBCC  xor      al, al
0x005ABBCE  test     al, al
0x005ABBD0  je       0x5abd03
0x005ABBD6  mov      eax, dword ptr [ebp - 0x128]
0x005ABBDC  xor      esi, esi
0x005ABBDE  mov      byte ptr [ebp - 0x171], 0
0x005ABBE5  cmp      eax, 3
0x005ABBE8  ja       0x5abc04
0x005ABBEA  jmp      dword ptr [eax*4 + 0x5abdcc]
0x005ABBF1  mov      esi, 1
0x005ABBF6  jmp      0x5abc04
0x005ABBF8  mov      esi, 3
0x005ABBFD  mov      byte ptr [ebp - 0x171], 1
0x005ABC04  mov      eax, dword ptr [edi + 0x14c]
0x005ABC0A  lea      ecx, [ebp - 0x170]
0x005ABC10  add      eax, 0xc
0x005ABC13  push     eax
0x005ABC14  mov      eax, dword ptr [edi + 0x190]
0x005ABC1A  add      eax, 0xc
0x005ABC1D  push     eax
0x005ABC1E  call     0x5ab590
0x005ABC23  cmp      dword ptr [ebx], -1
0x005ABC26  mov      dword ptr [ebp - 0x128], esi
0x005ABC2C  je       0x5abc43
0x005ABC2E  push     0
0x005ABC30  push     0x14c
0x005ABC35  lea      eax, [ebp - 0x170]
0x005ABC3B  mov      ecx, ebx
0x005ABC3D  push     eax
0x005ABC3E  call     0x5b1470
0x005ABC43  cmp      byte ptr [ebp - 0x171], 0
0x005ABC4A  je       0x5abd03
0x005ABC50  xor      esi, esi
0x005ABC52  cmp      dword ptr [edi + esi*4 + 0x198], 0
0x005ABC5A  je       0x5abc67
0x005ABC5C  inc      esi
0x005ABC5D  cmp      esi, 0x40
0x005ABC60  jl       0x5abc52
0x005ABC62  jmp      0x5abd03
0x005ABC67  push     0xd2
0x005ABC6C  mov      edx, 0x72adb0
0x005ABC71  mov      ecx, 0x2003c
0x005ABC76  call     0x6ba810
0x005ABC7B  add      esp, 4
0x005ABC7E  mov      dword ptr [ebp - 0x1a0], eax
0x005ABC84  mov      dword ptr [ebp - 4], 6
0x005ABC8B  test     eax, eax
0x005ABC8D  je       0x5abc99
0x005ABC8F  push     edi
0x005ABC90  mov      ecx, eax
0x005ABC92  call     0x5ab3b0
0x005ABC97  jmp      0x5abc9b
0x005ABC99  xor      eax, eax
0x005ABC9B  mov      dword ptr [ebp - 4], 0xffffffff
0x005ABCA2  mov      ecx, ebx
0x005ABCA4  mov      dword ptr [edi + esi*4 + 0x198], eax
0x005ABCAB  mov      dword ptr [eax], esi
0x005ABCAD  mov      eax, dword ptr [edi + esi*4 + 0x198]
0x005ABCB4  add      eax, 8
0x005ABCB7  push     eax
0x005ABCB8  call     0x5b1230
0x005ABCBD  push     1
0x005ABCBF  lea      ecx, [edi + 0x298]
0x005ABCC5  call     0x40b930
0x005ABCCA  mov      eax, dword ptr [edi + 0x29c]
0x005ABCD0  lea      ecx, [eax - 1]
0x005ABCD3  mov      dword ptr [ebp - 0x178], ecx
0x005ABCD9  cmp      ecx, eax
0x005ABCDB  jb       0x5abcf4
0x005ABCDD  push     0
0x005ABCDF  push     0
0x005ABCE1  push     1
0x005ABCE3  push     0xc000008c
0x005ABCE8  call     dword ptr [0x715340]
0x005ABCEE  mov      ecx, dword ptr [ebp - 0x178]
0x005ABCF4  mov      eax, dword ptr [edi + 0x298]
0x005ABCFA  mov      edi, dword ptr [ebp - 0x180]
0x005ABD00  mov      dword ptr [eax + ecx*4], esi
0x005ABD03  mov      eax, dword ptr [ebx + 0x14]
0x005ABD06  mov      esi, dword ptr [0x7154d4]
0x005ABD0C  test     eax, eax
0x005ABD0E  je       0x5abd13
0x005ABD10  push     eax
0x005ABD11  call     esi
0x005ABD13  mov      eax, dword ptr [ebx + 0x18]
0x005ABD16  test     eax, eax
0x005ABD18  je       0x5abd1d
0x005ABD1A  push     eax
0x005ABD1B  call     esi
0x005ABD1D  mov      eax, dword ptr [ebx]
0x005ABD1F  mov      dword ptr [ebx + 0x18], 0
0x005ABD26  mov      dword ptr [ebx + 0x14], 0
0x005ABD2D  cmp      eax, -1
0x005ABD30  je       0x5abd3f
0x005ABD32  push     eax
0x005ABD33  call     dword ptr [0x7154d8]
0x005ABD39  mov      dword ptr [ebx], 0xffffffff
0x005ABD3F  lea      ecx, [ebx + 0x1c]
0x005ABD42  call     0x5b15c0
0x005ABD47  push     0x20034
0x005ABD4C  push     ebx
0x005ABD4D  call     0x6cecd8
0x005ABD52  add      esp, 8
0x005ABD55  jmp      0x5ab920
0x005ABD5A  test     ebx, ebx
0x005ABD5C  je       0x5abdb0
0x005ABD5E  mov      eax, dword ptr [ebx + 0x14]
0x005ABD61  mov      esi, dword ptr [0x7154d4]
0x005ABD67  test     eax, eax
0x005ABD69  je       0x5abd6e
0x005ABD6B  push     eax
0x005ABD6C  call     esi
0x005ABD6E  mov      eax, dword ptr [ebx + 0x18]
0x005ABD71  test     eax, eax
0x005ABD73  je       0x5abd78
0x005ABD75  push     eax
0x005ABD76  call     esi
0x005ABD78  mov      eax, dword ptr [ebx]
0x005ABD7A  mov      dword ptr [ebx + 0x14], 0
0x005ABD81  mov      dword ptr [ebx + 0x18], 0
0x005ABD88  cmp      eax, -1
0x005ABD8B  je       0x5abd9a
0x005ABD8D  push     eax
0x005ABD8E  call     dword ptr [0x7154d8]
0x005ABD94  mov      dword ptr [ebx], 0xffffffff
0x005ABD9A  lea      ecx, [ebx + 0x1c]
0x005ABD9D  call     0x5b15c0
0x005ABDA2  push     0x20034
0x005ABDA7  push     ebx
0x005ABDA8  call     0x6cecd8
0x005ABDAD  add      esp, 8
0x005ABDB0  mov      ecx, dword ptr [ebp - 0xc]
0x005ABDB3  mov      dword ptr fs:[0], ecx
0x005ABDBA  pop      ecx
0x005ABDBB  pop      edi
0x005ABDBC  pop      esi
0x005ABDBD  pop      ebx
0x005ABDBE  mov      ecx, dword ptr [ebp - 0x10]
0x005ABDC1  xor      ecx, ebp
0x005ABDC3  call     0x6ce927
0x005ABDC8  mov      esp, ebp
0x005ABDCA  pop      ebp
0x005ABDCB  ret      
0x005ABDCC  int1     
0x005ABDCD  mov      ebx, 0xbd03005a
0x005ABDD2  pop      edx
0x005ABDD3  add      al, bh
0x005ABDD5  mov      ebx, 0xbd03005a
0x005ABDDA  pop      edx
0x005ABDDB  add      ah, cl
0x005ABDDD  int3     
0x005ABDDE  int3     
0x005ABDDF  int3     
0x005ABDE0  push     ebp
0x005ABDE1  mov      ebp, esp
0x005ABDE3  push     -1
0x005ABDE5  push     0x6fa9d0
0x005ABDEA  mov      eax, dword ptr fs:[0]
0x005ABDF0  push     eax
0x005ABDF1  sub      esp, 8
0x005ABDF4  push     ebx
0x005ABDF5  push     esi
0x005ABDF6  push     edi
0x005ABDF7  mov      eax, dword ptr [0x76700c]
0x005ABDFC  xor      eax, ebp
0x005ABDFE  push     eax
0x005ABDFF  .byte    0x8d
