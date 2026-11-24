==============================================================================
func FUN_00440e00 entry=0x00440e00 size=139
==============================================================================
0x00440e00  push     ebp
0x00440e01  mov      ebp, esp
0x00440e03  cmp      dword ptr [ebp + 8], 0
0x00440e07  push     esi
0x00440e08  mov      esi, dword ptr [ebp + 0x10]
0x00440e0b  push     edi
0x00440e0c  jne      0x440e53
0x00440e0e  mov      edi, dword ptr [0x71544c]
0x00440e14  push     0x11
0x00440e16  call     edi
0x00440e18  cwde     
0x00440e19  sar      eax, 0xf
0x00440e1c  push     0x11
0x00440e1e  mov      dword ptr [ebp + 0x10], eax
0x00440e21  call     edi
0x00440e23  bt       ax, 0xf
0x00440e28  jae      0x440e40
0x00440e2a  push     0x12
0x00440e2c  call     edi
0x00440e2e  bt       ax, 0xf
0x00440e33  jae      0x440e40
0x00440e35  push     0x2e
0x00440e37  call     edi
0x00440e39  bt       ax, 0xf
0x00440e3e  jb       0x440e80
0x00440e40  mov      eax, dword ptr [esi]
0x00440e42  cmp      eax, 0x1b
0x00440e45  jne      0x440e6c
0x00440e47  cmp      dword ptr [ebp + 0x10], 0
0x00440e4b  jne      0x440e80
0x00440e4d  test     byte ptr [esi + 8], 0x20
0x00440e51  jne      0x440e80
0x00440e53  push     esi
0x00440e54  push     dword ptr [ebp + 0xc]
0x00440e57  push     dword ptr [ebp + 8]
0x00440e5a  push     dword ptr [0x76a284]
0x00440e60  call     dword ptr [0x715450]
0x00440e66  pop      edi
0x00440e67  pop      esi
0x00440e68  pop      ebp
0x00440e69  ret      0xc
0x00440e6c  cmp      eax, 9
0x00440e6f  je       0x440e4d
0x00440e71  cmp      eax, 0x5b
0x00440e74  je       0x440e80
0x00440e76  cmp      eax, 0x5c
0x00440e79  je       0x440e80
0x00440e7b  cmp      eax, 0x5d
0x00440e7e  jne      0x440e53
0x00440e80  pop      edi
0x00440e81  mov      eax, 1
0x00440e86  pop      esi
0x00440e87  pop      ebp
0x00440e88  ret      0xc
