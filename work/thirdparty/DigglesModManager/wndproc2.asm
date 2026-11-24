==============================================================================
func FUN_0054e470 entry=0x0054e470 size=1008
==============================================================================
0x0054e470  push     ebp
0x0054e471  mov      ebp, esp
0x0054e473  push     ecx
0x0054e474  mov      eax, dword ptr [0x772400]
0x0054e479  push     ebx
0x0054e47a  push     esi
0x0054e47b  push     edi
0x0054e47c  cmp      byte ptr [eax + 0x18], 0
0x0054e480  mov      edi, ecx
0x0054e482  je       0x54e630
0x0054e488  mov      ecx, dword ptr [ebp + 8]
0x0054e48b  mov      eax, dword ptr [ecx]
0x0054e48d  sub      eax, 0x300
0x0054e492  je       0x54e4af
0x0054e494  sub      eax, 1
0x0054e497  jne      0x54e630
0x0054e49d  movzx    eax, word ptr [ecx + 0x10]
0x0054e4a1  push     eax
0x0054e4a2  call     dword ptr [0x715038]
0x0054e4a8  mov      ecx, 0x101
0x0054e4ad  jmp      0x54e4bf
0x0054e4af  movzx    eax, word ptr [ecx + 0x10]
0x0054e4b3  push     eax
0x0054e4b4  call     dword ptr [0x715038]
0x0054e4ba  mov      ecx, 0x100
0x0054e4bf  movzx    edx, ax
0x0054e4c2  mov      ebx, 0xfd
0x0054e4c7  add      esp, 4
0x0054e4ca  mov      dword ptr [ebp + 8], ecx
0x0054e4cd  movzx    esi, dx
0x0054e4d0  lea      eax, [edx - 1]
0x0054e4d3  cmp      ax, bx
0x0054e4d6  ja       0x54e5e7
0x0054e4dc  cmp      ecx, 0x100
0x0054e4e2  jne      0x54e5e7
0x0054e4e8  lea      eax, [edx - 0x41]
0x0054e4eb  movzx    eax, ax
0x0054e4ee  lea      ecx, [edx - 0x30]
0x0054e4f1  cmp      cx, 9
0x0054e4f5  mov      dword ptr [ebp - 4], eax
0x0054e4f8  lea      eax, [edx - 0x60]
0x0054e4fb  setbe    bh
0x0054e4fe  cmp      ax, 9
0x0054e502  ja       0x54e50a
0x0054e504  mov      bl, 1
0x0054e506  mov      bh, bl
0x0054e508  jmp      0x54e50c
0x0054e50a  xor      bl, bl
0x0054e50c  test     bl, bl
0x0054e50e  movzx    ecx, cx
0x0054e511  movzx    eax, dx
0x0054e514  cmove    ecx, eax
0x0054e517  movzx    esi, cx
0x0054e51a  cmp      esi, 0x6d
0x0054e51d  je       0x54e53c
0x0054e51f  cmp      esi, 0x6a
0x0054e522  je       0x54e53c
0x0054e524  mov      eax, 0x9a
0x0054e529  cmp      si, ax
0x0054e52c  je       0x54e53c
0x0054e52e  cmp      esi, 0x6f
0x0054e531  je       0x54e53c
0x0054e533  cmp      esi, 0x6b
0x0054e536  je       0x54e53c
0x0054e538  xor      dl, dl
0x0054e53a  jmp      0x54e53e
0x0054e53c  mov      dl, 1
0x0054e53e  mov      eax, 0x97
0x0054e543  cmp      si, ax
0x0054e546  je       0x54e556
0x0054e548  mov      eax, 0x98
0x0054e54d  cmp      si, ax
0x0054e550  je       0x54e556
0x0054e552  xor      cl, cl
0x0054e554  jmp      0x54e558
0x0054e556  mov      cl, 1
0x0054e558  mov      eax, 0xbc
0x0054e55d  cmp      si, ax
0x0054e560  je       0x54e5a2
0x0054e562  mov      eax, 0xbe
0x0054e567  cmp      si, ax
0x0054e56a  je       0x54e5a2
0x0054e56c  mov      eax, 0x9b
0x0054e571  cmp      si, ax
0x0054e574  je       0x54e5a2
0x0054e576  mov      eax, 0x9c
0x0054e57b  cmp      si, ax
0x0054e57e  je       0x54e5a2
0x0054e580  mov      eax, 0x9d
0x0054e585  cmp      si, ax
0x0054e588  je       0x54e5a2
0x0054e58a  mov      eax, 0x9e
0x0054e58f  cmp      si, ax
0x0054e592  je       0x54e5a2
0x0054e594  mov      eax, 0x99
0x0054e599  cmp      si, ax
0x0054e59c  je       0x54e5a2
0x0054e59e  xor      al, al
0x0054e5a0  jmp      0x54e5a4
0x0054e5a2  mov      al, 1
0x0054e5a4  cmp      word ptr [ebp - 4], 0x19
0x0054e5a9  jbe      0x54e5c7
0x0054e5ab  test     bh, bh
0x0054e5ad  jne      0x54e5c7
0x0054e5af  test     dl, dl
0x0054e5b1  jne      0x54e5c7
0x0054e5b3  test     cl, cl
0x0054e5b5  jne      0x54e5c7
0x0054e5b7  cmp      esi, 0x20
0x0054e5ba  je       0x54e5c7
0x0054e5bc  test     al, al
0x0054e5be  jne      0x54e5c7
0x0054e5c0  mov      ecx, dword ptr [ebp + 8]
0x0054e5c3  mov      eax, esi
0x0054e5c5  jmp      0x54e5fb
0x0054e5c7  push     0x10
0x0054e5c9  call     dword ptr [0x715424]
0x0054e5cf  shr      eax, 0xf
0x0054e5d2  mov      ecx, esi
0x0054e5d4  and      al, 1
0x0054e5d6  mov      dl, al
0x0054e5d8  call     0x54e150
0x0054e5dd  movzx    eax, ax
0x0054e5e0  mov      ecx, 0x102
0x0054e5e5  jmp      0x54e5fb
0x0054e5e7  mov      eax, esi
0x0054e5e9  mov      edx, ecx
0x0054e5eb  cmp      ecx, 0x100
0x0054e5f1  je       0x54e5fb
0x0054e5f3  cmp      edx, 0x101
0x0054e5f9  jne      0x54e630
0x0054e5fb  cmp      byte ptr [edi + 0x61], 0
0x0054e5ff  movzx    ebx, ax
0x0054e602  jne      0x54e63b
0x0054e604  cmp      ebx, 0x91
0x0054e60a  jne      0x54e630
0x0054e60c  cmp      ecx, 0x101
0x0054e612  jne      0x54e630
0x0054e614  cmp      dword ptr [0x76a338], 0
0x0054e61b  je       0x54e62c
0x0054e61d  mov      eax, dword ptr [0x76a324]
0x0054e622  cmp      byte ptr [eax + 0x12], 1
0x0054e626  je       0x54e62c
0x0054e628  mov      byte ptr [eax + 0x12], 1
0x0054e62c  mov      byte ptr [edi + 0x61], 1
0x0054e630  xor      al, al
0x0054e632  pop      edi
0x0054e633  pop      esi
0x0054e634  pop      ebx
0x0054e635  mov      esp, ebp
0x0054e637  pop      ebp
0x0054e638  ret      4
0x0054e63b  cmp      ebx, 0x91
0x0054e641  jne      0x54e65d
0x0054e643  cmp      ecx, 0x101
0x0054e649  jne      0x54e65d
0x0054e64b  mov      ecx, edi
0x0054e64d  call     0x54dc70
0x0054e652  mov      al, 1
0x0054e654  pop      edi
0x0054e655  pop      esi
0x0054e656  pop      ebx
0x0054e657  mov      esp, ebp
0x0054e659  pop      ebp
0x0054e65a  ret      4
0x0054e65d  cmp      ecx, 0x100
0x0054e663  jne      0x54e824
0x0054e669  cmp      ebx, 0x25
0x0054e66c  jne      0x54e6ad
0x0054e66e  dec      dword ptr [edi + 8]
0x0054e671  lea      esi, [edi + 0x14]
0x0054e674  mov      eax, dword ptr [edi + 8]
0x0054e677  xor      ecx, ecx
0x0054e679  test     eax, eax
0x0054e67b  cmovle   eax, ecx
0x0054e67e  mov      ecx, esi
0x0054e680  mov      dword ptr [edi + 8], eax
0x0054e683  call     0x6b8f20
0x0054e688  mov      ecx, dword ptr [edi + 8]
0x0054e68b  cmp      ecx, eax
0x0054e68d  jl       0x54e698
0x0054e68f  mov      ecx, esi
0x0054e691  call     0x6b8f20
0x0054e696  mov      ecx, eax
0x0054e698  mov      dword ptr [edi + 8], ecx
0x0054e69b  mov      ecx, edi
0x0054e69d  call     0x54ddf0
0x0054e6a2  pop      edi
0x0054e6a3  pop      esi
0x0054e6a4  mov      al, 1
0x0054e6a6  pop      ebx
0x0054e6a7  mov      esp, ebp
0x0054e6a9  pop      ebp
0x0054e6aa  ret      4
0x0054e6ad  cmp      ebx, 0x27
0x0054e6b0  jne      0x54e6b7
0x0054e6b2  inc      dword ptr [edi + 8]
0x0054e6b5  jmp      0x54e671
0x0054e6b7  cmp      ebx, 0x26
0x0054e6ba  jne      0x54e733
0x0054e6bc  mov      ecx, dword ptr [edi + 0x28]
0x0054e6bf  mov      esi, dword ptr [edi + 0x30]
0x0054e6c2  inc      ecx
0x0054e6c3  cmp      ecx, esi
0x0054e6c5  mov      eax, ecx
0x0054e6c7  cmovge   eax, esi
0x0054e6ca  test     eax, eax
0x0054e6cc  jns      0x54e6d2
0x0054e6ce  xor      eax, eax
0x0054e6d0  jmp      0x54e6d9
0x0054e6d2  cmp      ecx, esi
0x0054e6d4  mov      eax, esi
0x0054e6d6  cmovl    eax, ecx
0x0054e6d9  mov      ebx, esi
0x0054e6db  mov      dword ptr [edi + 0x28], eax
0x0054e6de  sub      ebx, eax
0x0054e6e0  lea      edx, [esi - 1]
0x0054e6e3  cmp      edx, ebx
0x0054e6e5  mov      ecx, 1
0x0054e6ea  cmovge   ecx, eax
0x0054e6ed  mov      eax, esi
0x0054e6ef  sub      eax, ecx
0x0054e6f1  jns      0x54e6f7
0x0054e6f3  xor      edx, edx
0x0054e6f5  jmp      0x54e700
0x0054e6f7  cmp      edx, ebx
0x0054e6f9  cmovge   edx, ebx
0x0054e6fc  test     edx, edx
0x0054e6fe  js       0x54e716
0x0054e700  cmp      edx, esi
0x0054e702  jge      0x54e716
0x0054e704  push     edx
0x0054e705  lea      ecx, [edi + 0x2c]
0x0054e708  call     0x40b900
0x0054e70d  push     eax
0x0054e70e  lea      ecx, [edi + 0x14]
0x0054e711  call     0x6b91c0
0x0054e716  lea      ecx, [edi + 0x14]
0x0054e719  call     0x6b8f20
0x0054e71e  mov      dword ptr [edi + 8], eax
0x0054e721  lea      ecx, [eax - 0x49]
0x0054e724  xor      eax, eax
0x0054e726  test     ecx, ecx
0x0054e728  cmovns   eax, ecx
0x0054e72b  mov      dword ptr [edi + 0xc], eax
0x0054e72e  jmp      0x54e671
0x0054e733  cmp      ebx, 0x28
0x0054e736  jne      0x54e7b2
0x0054e738  mov      eax, dword ptr [edi + 0x28]
0x0054e73b  xor      esi, esi
0x0054e73d  add      eax, -1
0x0054e740  mov      ecx, 1
0x0054e745  cmovns   esi, eax
0x0054e748  mov      eax, dword ptr [edi + 0x30]
0x0054e74b  mov      edx, eax
0x0054e74d  mov      dword ptr [edi + 0x28], esi
0x0054e750  sub      edx, esi
0x0054e752  lea      ebx, [eax - 1]
0x0054e755  cmp      ebx, edx
0x0054e757  cmovge   ecx, esi
0x0054e75a  sub      eax, ecx
0x0054e75c  jns      0x54e762
0x0054e75e  xor      edx, edx
0x0054e760  jmp      0x54e767
0x0054e762  cmp      ebx, edx
0x0054e764  cmovl    edx, ebx
0x0054e767  test     esi, esi
0x0054e769  je       0x54e787
0x0054e76b  cmp      dword ptr [edi + 0x30], 0
0x0054e76f  jle      0x54e787
0x0054e771  push     edx
0x0054e772  lea      ecx, [edi + 0x2c]
0x0054e775  lea      esi, [edi + 0x14]
0x0054e778  call     0x40b900
0x0054e77d  push     eax
0x0054e77e  mov      ecx, esi
0x0054e780  call     0x6b91c0
0x0054e785  jmp      0x54e796
0x0054e787  lea      esi, [edi + 0x14]
0x0054e78a  push     0x71ce50
0x0054e78f  mov      ecx, esi
0x0054e791  call     0x6b9200
0x0054e796  mov      ecx, esi
0x0054e798  call     0x6b8f20
0x0054e79d  mov      dword ptr [edi + 8], eax
0x0054e7a0  lea      ecx, [eax - 0x49]
0x0054e7a3  xor      eax, eax
0x0054e7a5  test     ecx, ecx
0x0054e7a7  cmovns   eax, ecx
0x0054e7aa  mov      dword ptr [edi + 0xc], eax
0x0054e7ad  jmp      0x54e674
0x0054e7b2  lea      esi, [edi + 0x14]
0x0054e7b5  mov      ecx, esi
0x0054e7b7  mov      eax, esi
0x0054e7b9  cmp      ebx, 8
0x0054e7bc  jne      0x54e7d2
0x0054e7be  mov      eax, dword ptr [edi + 8]
0x0054e7c1  push     1
0x0054e7c3  dec      eax
0x0054e7c4  push     eax
0x0054e7c5  call     0x6ba2f0
0x0054e7ca  dec      dword ptr [edi + 8]
0x0054e7cd  jmp      0x54e674
0x0054e7d2  cmp      ebx, 0x2e
0x0054e7d5  jne      0x54e7e6
0x0054e7d7  push     1
0x0054e7d9  push     dword ptr [edi + 8]
0x0054e7dc  call     0x6ba2f0
0x0054e7e1  jmp      0x54e674
0x0054e7e6  cmp      ebx, 0xd
0x0054e7e9  jne      0x54e674
0x0054e7ef  mov      edx, dword ptr [ecx]
0x0054e7f1  push     ecx
0x0054e7f2  mov      eax, esp
0x0054e7f4  mov      dword ptr [eax], edx
0x0054e7f6  test     edx, edx
0x0054e7f8  je       0x54e7fc
0x0054e7fa  inc      dword ptr [edx]
0x0054e7fc  mov      ecx, edi
0x0054e7fe  call     0x54e860
0x0054e803  push     0x71ce50
0x0054e808  mov      ecx, esi
0x0054e80a  call     0x6b9200
0x0054e80f  mov      dword ptr [edi + 8], 0
0x0054e816  xor      eax, eax
0x0054e818  mov      dword ptr [edi + 0xc], 0
0x0054e81f  jmp      0x54e677
0x0054e824  cmp      ecx, 0x102
0x0054e82a  jne      0x54e6a2
0x0054e830  push     ebx
0x0054e831  call     0x6d99c0
0x0054e836  add      esp, 4
0x0054e839  test     eax, eax
0x0054e83b  jne      0x54e846
0x0054e83d  cmp      ebx, 0x7e
0x0054e840  jne      0x54e671
0x0054e846  mov      ecx, dword ptr [edi + 8]
0x0054e849  lea      esi, [edi + 0x14]
0x0054e84c  push     ebx
0x0054e84d  push     ecx
0x0054e84e  lea      eax, [ecx + 1]
0x0054e851  mov      ecx, esi
0x0054e853  mov      dword ptr [edi + 8], eax
0x0054e856  call     0x6ba240
0x0054e85b  jmp      0x54e674
