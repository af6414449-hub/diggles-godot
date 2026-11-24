Disassembly of C:\Program Files (x86)\Steam\steamapps\common\Diggles The Myth of Fenris\Diggles.exe  VA 0x0049C560 - 0x0049C800

0x0049C560  clc      
0x0049C561  add      byte ptr [eax], al
0x0049C563  add      byte ptr [eax], al
0x0049C565  sub      esi, 1
0x0049C568  jne      0x49c550
0x0049C56A  pop      edi
0x0049C56B  pop      esi
0x0049C56C  pop      ebx
0x0049C56D  pop      ebp
0x0049C56E  ret      4
0x0049C571  int3     
0x0049C572  int3     
0x0049C573  int3     
0x0049C574  int3     
0x0049C575  int3     
0x0049C576  int3     
0x0049C577  int3     
0x0049C578  int3     
0x0049C579  int3     
0x0049C57A  int3     
0x0049C57B  int3     
0x0049C57C  int3     
0x0049C57D  int3     
0x0049C57E  int3     
0x0049C57F  int3     
0x0049C580  push     ebp
0x0049C581  mov      ebp, esp
0x0049C583  push     ecx
0x0049C584  push     esi
0x0049C585  mov      esi, ecx
0x0049C587  push     edi
0x0049C588  mov      edi, dword ptr [ebp + 8]
0x0049C58B  mov      edx, dword ptr [esi + 4]
0x0049C58E  lea      ecx, [edi + 0xf]
0x0049C591  add      ecx, edx
0x0049C593  lea      eax, [edx + 0xf]
0x0049C596  and      ecx, 0xfffffff0
0x0049C599  and      eax, 0xfffffff0
0x0049C59C  cmp      ecx, eax
0x0049C59E  je       0x49c5bf
0x0049C5A0  imul     edx, ecx, 0x34814
0x0049C5A6  mov      ecx, dword ptr [esi]
0x0049C5A8  push     0x9b
0x0049C5AD  push     0x71ce9c
0x0049C5B2  call     0x6baad0
0x0049C5B7  mov      edx, dword ptr [esi + 4]
0x0049C5BA  add      esp, 8
0x0049C5BD  mov      dword ptr [esi], eax
0x0049C5BF  lea      eax, [edx + edi]
0x0049C5C2  mov      dword ptr [esi + 4], eax
0x0049C5C5  cmp      edi, 1
0x0049C5C8  jne      0x49c5d0
0x0049C5CA  cmp      edx, eax
0x0049C5CC  jb       0x49c5e5
0x0049C5CE  jmp      0x49c5d4
0x0049C5D0  test     edx, edx
0x0049C5D2  jns      0x49c5e5
0x0049C5D4  push     0
0x0049C5D6  push     0
0x0049C5D8  push     1
0x0049C5DA  push     0xc000008c
0x0049C5DF  call     dword ptr [0x715340]
0x0049C5E5  pop      edi
0x0049C5E6  pop      esi
0x0049C5E7  pop      ecx
0x0049C5E8  pop      ebp
0x0049C5E9  ret      4
0x0049C5EC  int3     
0x0049C5ED  int3     
0x0049C5EE  int3     
0x0049C5EF  int3     
0x0049C5F0  push     ebp
0x0049C5F1  mov      ebp, esp
0x0049C5F3  mov      eax, dword ptr [ebp + 8]
0x0049C5F6  push     ebx
0x0049C5F7  push     esi
0x0049C5F8  push     edi
0x0049C5F9  mov      edi, ecx
0x0049C5FB  mov      esi, dword ptr [edi + 4]
0x0049C5FE  cmp      esi, eax
0x0049C600  jge      0x49c63f
0x0049C602  mov      ebx, eax
0x0049C604  lea      edx, [eax + 0x7f]
0x0049C607  lea      eax, [esi + 0x7f]
0x0049C60A  and      edx, 0xffffff80
0x0049C60D  and      eax, 0xffffff80
0x0049C610  sub      ebx, esi
0x0049C612  cmp      edx, eax
0x0049C614  je       0x49c632
0x0049C616  mov      ecx, dword ptr [edi]
0x0049C618  push     0x9b
0x0049C61D  push     0x71ce9c
0x0049C622  shl      edx, 4
0x0049C625  call     0x6baad0
0x0049C62A  mov      esi, dword ptr [edi + 4]
0x0049C62D  add      esp, 8
0x0049C630  mov      dword ptr [edi], eax
0x0049C632  lea      eax, [esi + ebx]
0x0049C635  mov      dword ptr [edi + 4], eax
0x0049C638  pop      edi
0x0049C639  pop      esi
0x0049C63A  pop      ebx
0x0049C63B  pop      ebp
0x0049C63C  ret      4
0x0049C63F  jle      0x49c662
0x0049C641  mov      ebx, esi
0x0049C643  sub      ebx, eax
0x0049C645  cmp      esi, ebx
0x0049C647  jge      0x49c65d
0x0049C649  push     0
0x0049C64B  push     0
0x0049C64D  push     1
0x0049C64F  push     0xc000008c
0x0049C654  call     dword ptr [0x715340]
0x0049C65A  mov      esi, dword ptr [edi + 4]
0x0049C65D  sub      esi, ebx
0x0049C65F  mov      dword ptr [edi + 4], esi
0x0049C662  pop      edi
0x0049C663  pop      esi
0x0049C664  pop      ebx
0x0049C665  pop      ebp
0x0049C666  ret      4
0x0049C669  int3     
0x0049C66A  int3     
0x0049C66B  int3     
0x0049C66C  int3     
0x0049C66D  int3     
0x0049C66E  int3     
0x0049C66F  int3     
0x0049C670  push     ebp
0x0049C671  mov      ebp, esp
0x0049C673  mov      ecx, dword ptr [0x768350]
0x0049C679  sub      esp, 0x10
0x0049C67C  cmp      ecx, 0x270
0x0049C682  jl       0x49c8c3
0x0049C688  cmp      ecx, 0x271
0x0049C68E  jne      0x49c69a
0x0049C690  push     0x1105
0x0049C695  call     0x4454d0
0x0049C69A  push     esi
0x0049C69B  xor      esi, esi
0x0049C69D  mov      ecx, 0x767990
0x0049C6A2  push     edi
0x0049C6A3  mov      edi, dword ptr [0x715340]
0x0049C6A9  mov      dword ptr [ebp - 8], esi
0x0049C6AC  mov      dword ptr [ebp - 4], ecx
0x0049C6AF  nop      
0x0049C6B0  cmp      esi, 0x26f
0x0049C6B6  ja       0x49c6bd
0x0049C6B8  mov      dword ptr [ebp - 0xc], ecx
0x0049C6BB  jmp      0x49c6d4
0x0049C6BD  push     0
0x0049C6BF  push     0
0x0049C6C1  push     1
0x0049C6C3  push     0xc000008c
0x0049C6C8  call     edi
0x0049C6CA  mov      ecx, dword ptr [ebp - 4]
0x0049C6CD  mov      dword ptr [ebp - 0xc], 0x767990
0x0049C6D4  lea      eax, [esi + 0x18d]
0x0049C6DA  mov      dword ptr [ebp - 0x10], eax
0x0049C6DD  add      eax, 0xfffffe74
0x0049C6E2  cmp      eax, 0x26f
0x0049C6E7  ja       0x49c6ee
0x0049C6E9  lea      edx, [ecx + 4]
0x0049C6EC  jmp      0x49c703
0x0049C6EE  push     0
0x0049C6F0  push     0
0x0049C6F2  push     1
0x0049C6F4  push     0xc000008c
0x0049C6F9  call     edi
0x0049C6FB  mov      ecx, dword ptr [ebp - 4]
0x0049C6FE  mov      edx, 0x767990
0x0049C703  mov      eax, dword ptr [ebp - 0xc]
0x0049C706  mov      esi, dword ptr [eax]
0x0049C708  xor      esi, dword ptr [edx]
0x0049C70A  and      esi, 0x7fffffff
0x0049C710  xor      esi, dword ptr [eax]
0x0049C712  cmp      dword ptr [ebp - 0x10], 0x26f
0x0049C719  ja       0x49c726
0x0049C71B  lea      eax, [ecx + 0x634]
0x0049C721  mov      dword ptr [ebp - 0xc], eax
0x0049C724  jmp      0x49c73d
0x0049C726  push     0
0x0049C728  push     0
0x0049C72A  push     1
0x0049C72C  push     0xc000008c
0x0049C731  call     edi
0x0049C733  mov      ecx, dword ptr [ebp - 4]
0x0049C736  mov      dword ptr [ebp - 0xc], 0x767990
0x0049C73D  cmp      dword ptr [ebp - 8], 0x26f
0x0049C744  ja       0x49c74a
0x0049C746  mov      edx, ecx
0x0049C748  jmp      0x49c75f
0x0049C74A  push     0
0x0049C74C  push     0
0x0049C74E  push     1
0x0049C750  push     0xc000008c
0x0049C755  call     edi
0x0049C757  mov      ecx, dword ptr [ebp - 4]
0x0049C75A  mov      edx, 0x767990
0x0049C75F  mov      eax, esi
0x0049C761  add      ecx, 4
0x0049C764  and      eax, 1
0x0049C767  shr      esi, 1
0x0049C769  mov      dword ptr [ebp - 4], ecx
0x0049C76C  xor      esi, dword ptr [eax*4 + 0x724484]
0x0049C773  mov      eax, dword ptr [ebp - 0xc]
0x0049C776  xor      esi, dword ptr [eax]
0x0049C778  mov      dword ptr [edx], esi
0x0049C77A  mov      esi, dword ptr [ebp - 8]
0x0049C77D  inc      esi
0x0049C77E  mov      dword ptr [ebp - 8], esi
0x0049C781  cmp      esi, 0xe3
0x0049C787  jl       0x49c6b0
0x0049C78D  mov      esi, 0xe3
0x0049C792  mov      ecx, 0x767d1c
0x0049C797  mov      dword ptr [ebp - 8], esi
0x0049C79A  cmp      esi, 0x26f
0x0049C7A0  mov      dword ptr [ebp - 4], ecx
0x0049C7A3  ja       0x49c7aa
0x0049C7A5  mov      dword ptr [ebp - 0xc], ecx
0x0049C7A8  jmp      0x49c7c1
0x0049C7AA  push     0
0x0049C7AC  push     0
0x0049C7AE  push     1
0x0049C7B0  push     0xc000008c
0x0049C7B5  call     edi
0x0049C7B7  mov      ecx, dword ptr [ebp - 4]
0x0049C7BA  mov      dword ptr [ebp - 0xc], 0x767990
0x0049C7C1  lea      eax, [esi - 0xe3]
0x0049C7C7  mov      dword ptr [ebp - 0x10], eax
0x0049C7CA  add      eax, 0xe4
0x0049C7CF  cmp      eax, 0x26f
0x0049C7D4  ja       0x49c7db
0x0049C7D6  lea      edx, [ecx + 4]
0x0049C7D9  jmp      0x49c7f0
0x0049C7DB  push     0
0x0049C7DD  push     0
0x0049C7DF  push     1
0x0049C7E1  push     0xc000008c
0x0049C7E6  call     edi
0x0049C7E8  mov      ecx, dword ptr [ebp - 4]
0x0049C7EB  mov      edx, 0x767990
0x0049C7F0  mov      eax, dword ptr [ebp - 0xc]
0x0049C7F3  mov      esi, dword ptr [eax]
0x0049C7F5  xor      esi, dword ptr [edx]
0x0049C7F7  and      esi, 0x7fffffff
0x0049C7FD  xor      esi, dword ptr [eax]
0x0049C7FF  .byte    0x81
