Disassembly of C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe  VA 0x0054E5C0 - 0x0054E7C0

0x0054E5C0  mov      ecx, dword ptr [ebp + 8]
0x0054E5C3  mov      eax, esi
0x0054E5C5  jmp      0x54e5fb
0x0054E5C7  push     0x10
0x0054E5C9  call     dword ptr [0x715424]
0x0054E5CF  shr      eax, 0xf
0x0054E5D2  mov      ecx, esi
0x0054E5D4  and      al, 1
0x0054E5D6  mov      dl, al
0x0054E5D8  call     0x54e150
0x0054E5DD  movzx    eax, ax
0x0054E5E0  mov      ecx, 0x102
0x0054E5E5  jmp      0x54e5fb
0x0054E5E7  mov      eax, esi
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
0x0054E669  cmp      ebx, 0x25
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
0x0054E6AD  cmp      ebx, 0x27
0x0054E6B0  jne      0x54e6b7
0x0054E6B2  inc      dword ptr [edi + 8]
0x0054E6B5  jmp      0x54e671
0x0054E6B7  cmp      ebx, 0x26
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
0x0054E733  cmp      ebx, 0x28
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
0x0054E7B2  lea      esi, [edi + 0x14]
0x0054E7B5  mov      ecx, esi
0x0054E7B7  mov      eax, esi
0x0054E7B9  cmp      ebx, 8
0x0054E7BC  jne      0x54e7d2
0x0054E7BE  .byte    0x8b
0x0054E7BF  inc      edi
