==============================================================================
func FUN_006b8f20 entry=0x006b8f20 size=41
==============================================================================
0x006b8f20  push     esi
0x006b8f21  mov      esi, dword ptr [ecx]
0x006b8f23  cmp      dword ptr [esi + 8], -1
0x006b8f27  jne      0x6b8f44
0x006b8f29  lea      edx, [esi + 0xc]
0x006b8f2c  push     edi
0x006b8f2d  lea      edi, [edx + 1]
0x006b8f30  mov      al, byte ptr [edx]
0x006b8f32  inc      edx
0x006b8f33  test     al, al
0x006b8f35  jne      0x6b8f30
0x006b8f37  sub      edx, edi
0x006b8f39  mov      dword ptr [esi + 8], edx
0x006b8f3c  mov      eax, dword ptr [ecx]
0x006b8f3e  pop      edi
0x006b8f3f  pop      esi
0x006b8f40  mov      eax, dword ptr [eax + 8]
0x006b8f43  ret      
0x006b8f44  mov      eax, dword ptr [esi + 8]
0x006b8f47  pop      esi
0x006b8f48  ret      
