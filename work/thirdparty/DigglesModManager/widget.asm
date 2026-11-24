==============================================================================
func FUN_004ed820 entry=0x004ed820 size=254
==============================================================================
0x004ed820  push     ebp
0x004ed821  mov      ebp, esp
0x004ed823  push     -1
0x004ed825  push     0x6fc57d
0x004ed82a  mov      eax, dword ptr fs:[0]
0x004ed830  push     eax
0x004ed831  push     ecx
0x004ed832  push     ebx
0x004ed833  push     esi
0x004ed834  mov      eax, dword ptr [0x76700c]
0x004ed839  xor      eax, ebp
0x004ed83b  push     eax
0x004ed83c  lea      eax, [ebp - 0xc]
0x004ed83f  mov      dword ptr fs:[0], eax
0x004ed845  mov      esi, ecx
0x004ed847  mov      dword ptr [ebp - 4], 0
0x004ed84e  mov      ecx, dword ptr [esi + 4]
0x004ed851  lea      edx, [ecx + 0x10]
0x004ed854  lea      eax, [ecx + 0xf]
0x004ed857  and      edx, 0xfffffff0
0x004ed85a  and      eax, 0xfffffff0
0x004ed85d  cmp      edx, eax
0x004ed85f  je       0x4ed87d
0x004ed861  mov      ecx, dword ptr [esi]
0x004ed863  push     0x9b
0x004ed868  push     0x71ce9c
0x004ed86d  shl      edx, 2
0x004ed870  call     0x6baad0
0x004ed875  mov      ecx, dword ptr [esi + 4]
0x004ed878  add      esp, 8
0x004ed87b  mov      dword ptr [esi], eax
0x004ed87d  lea      eax, [ecx + 1]
0x004ed880  lea      ebx, [eax - 1]
0x004ed883  mov      dword ptr [esi + 4], eax
0x004ed886  cmp      ebx, eax
0x004ed888  jb       0x4ed89b
0x004ed88a  push     0
0x004ed88c  push     0
0x004ed88e  push     1
0x004ed890  push     0xc000008c
0x004ed895  call     dword ptr [0x715340]
0x004ed89b  mov      eax, dword ptr [esi]
0x004ed89d  mov      dword ptr [eax + ebx*4], 0
0x004ed8a4  mov      eax, dword ptr [esi + 4]
0x004ed8a7  lea      ebx, [eax - 1]
0x004ed8aa  cmp      ebx, eax
0x004ed8ac  jb       0x4ed8bf
0x004ed8ae  push     0
0x004ed8b0  push     0
0x004ed8b2  push     1
0x004ed8b4  push     0xc000008c
0x004ed8b9  call     dword ptr [0x715340]
0x004ed8bf  mov      eax, dword ptr [esi]
0x004ed8c1  mov      edx, dword ptr [eax + ebx*4]
0x004ed8c4  lea      ecx, [eax + ebx*4]
0x004ed8c7  mov      eax, dword ptr [ebp + 8]
0x004ed8ca  mov      dword ptr [ecx], eax
0x004ed8cc  mov      ecx, dword ptr [ebp + 8]
0x004ed8cf  test     ecx, ecx
0x004ed8d1  je       0x4ed8da
0x004ed8d3  lock inc dword ptr [ecx + 4]
0x004ed8d7  mov      ecx, dword ptr [ebp + 8]
0x004ed8da  or       esi, 0xffffffff
0x004ed8dd  test     edx, edx
0x004ed8df  je       0x4ed8f5
0x004ed8e1  mov      eax, esi
0x004ed8e3  lock xadd dword ptr [edx + 4], eax
0x004ed8e8  jne      0x4ed8f2
0x004ed8ea  mov      eax, dword ptr [edx]
0x004ed8ec  mov      ecx, edx
0x004ed8ee  push     1
0x004ed8f0  call     dword ptr [eax]
0x004ed8f2  mov      ecx, dword ptr [ebp + 8]
0x004ed8f5  test     ecx, ecx
0x004ed8f7  je       0x4ed90b
0x004ed8f9  lock xadd dword ptr [ecx + 4], esi
0x004ed8fe  dec      esi
0x004ed8ff  jne      0x4ed90b
0x004ed901  test     ecx, ecx
0x004ed903  je       0x4ed90b
0x004ed905  mov      eax, dword ptr [ecx]
0x004ed907  push     1
0x004ed909  call     dword ptr [eax]
0x004ed90b  mov      ecx, dword ptr [ebp - 0xc]
0x004ed90e  mov      dword ptr fs:[0], ecx
0x004ed915  pop      ecx
0x004ed916  pop      esi
0x004ed917  pop      ebx
0x004ed918  mov      esp, ebp
0x004ed91a  pop      ebp
0x004ed91b  ret      4
