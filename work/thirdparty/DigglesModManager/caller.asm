==============================================================================
func FUN_006b5a20 entry=0x006b5a20 size=133
==============================================================================
0x006b5a20  push     ebp
0x006b5a21  mov      ebp, esp
0x006b5a23  push     esi
0x006b5a24  mov      esi, ecx
0x006b5a26  mov      ecx, dword ptr [0x772400]
0x006b5a2c  push     edi
0x006b5a2d  mov      edi, dword ptr [ebp + 8]
0x006b5a30  push     edi
0x006b5a31  lea      ecx, [ecx + 0x368]
0x006b5a37  call     0x54e470
0x006b5a3c  test     al, al
0x006b5a3e  jne      0x6b5a9d
0x006b5a40  mov      eax, dword ptr [edi]
0x006b5a42  sub      eax, 0x401
0x006b5a47  je       0x6b5a6d
0x006b5a49  sub      eax, 1
0x006b5a4c  jne      0x6b5a8b
0x006b5a4e  movzx    eax, byte ptr [edi + 0x10]
0x006b5a52  sub      eax, 1
0x006b5a55  je       0x6b5a64
0x006b5a57  sub      eax, 2
0x006b5a5a  jne      0x6b5a8b
0x006b5a5c  mov      byte ptr [esi + 0xe9], al
0x006b5a62  jmp      0x6b5a8b
0x006b5a64  mov      byte ptr [esi + 0xe8], 0
0x006b5a6b  jmp      0x6b5a8b
0x006b5a6d  movzx    eax, byte ptr [edi + 0x10]
0x006b5a71  sub      eax, 1
0x006b5a74  je       0x6b5a84
0x006b5a76  sub      eax, 2
0x006b5a79  jne      0x6b5a8b
0x006b5a7b  mov      byte ptr [esi + 0xe9], 1
0x006b5a82  jmp      0x6b5a8b
0x006b5a84  mov      byte ptr [esi + 0xe8], 1
0x006b5a8b  call     0x4e4550
0x006b5a90  push     edi
0x006b5a91  call     0x501450
0x006b5a96  mov      ecx, eax
0x006b5a98  call     0x503420
0x006b5a9d  pop      edi
0x006b5a9e  mov      al, 1
0x006b5aa0  pop      esi
0x006b5aa1  pop      ebp
0x006b5aa2  ret      4
