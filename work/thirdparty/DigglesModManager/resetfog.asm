  0x0057d980: push     ebp
  0x0057d981: mov      ebp, esp
  0x0057d983: push     -1
  0x0057d985: push     0x7060dc
  0x0057d98a: mov      eax, dword ptr fs:[0]
  0x0057d990: push     eax
  0x0057d991: sub      esp, 0xc
  0x0057d994: push     ebx
  0x0057d995: push     esi
  0x0057d996: push     edi
  0x0057d997: mov      eax, dword ptr [0x76700c]
  0x0057d99c: xor      eax, ebp
  0x0057d99e: push     eax
  0x0057d99f: lea      eax, [ebp - 0xc]
  0x0057d9a2: mov      dword ptr fs:[0], eax
  0x0057d9a8: mov      eax, dword ptr [0x772410]
  0x0057d9ad: test     eax, eax
  0x0057d9af: jne      0x57db0c
  0x0057d9b5: push     0xcee
  0x0057d9ba: mov      edx, 0x72a494  ; "C:\dev\wiggles\Wiggles\Wiggles\Map\Fluid.cpp"
  0x0057d9bf: mov      ecx, 0xcb8
  0x0057d9c4: call     0x6ba810
  0x0057d9c9: mov      esi, eax
  0x0057d9cb: add      esp, 4
  0x0057d9ce: mov      dword ptr [ebp - 0x10], esi
  0x0057d9d1: mov      dword ptr [ebp - 4], 0
  0x0057d9d8: test     esi, esi
  0x0057d9da: je       0x57db02
  0x0057d9e0: mov      dword ptr [esi], 0
  0x0057d9e6: mov      dword ptr [esi + 4], 0
  0x0057d9ed: mov      dword ptr [esi + 9], 0
  0x0057d9f4: mov      dword ptr [esi + 0xd], 0
  0x0057d9fb: mov      dword ptr [esi + 0x20], 0
  0x0057da02: mov      dword ptr [esi + 0x1c], 0
  0x0057da09: mov      dword ptr [esi + 0x18], 0
  0x0057da10: mov      dword ptr [esi + 0x14], 0
  0x0057da17: mov      dword ptr [esi + 0x24], 0
  0x0057da1e: mov      dword ptr [esi + 0x28], 0
  0x0057da25: push     0x40
  0x0057da27: lea      eax, [esi + 0xc2c]
  0x0057da2d: mov      byte ptr [ebp - 4], 3
  0x0057da31: push     0
  0x0057da33: push     eax
  0x0057da34: call     0x6d0560
  0x0057da39: add      esp, 0xc
  0x0057da3c: lea      eax, [esi + 0xc74]
  0x0057da42: mov      dword ptr [ebp - 0x14], eax
  0x0057da45: push     0x4487e0
  0x0057da4a: push     0x440550
  0x0057da4f: push     2
  0x0057da51: push     8
  0x0057da53: push     eax
  0x0057da54: call     0x6ce938
  0x0057da59: push     0x4487e0
  0x0057da5e: push     0x440550
  0x0057da63: push     2
  0x0057da65: lea      eax, [esi + 0xc84]
  0x0057da6b: mov      byte ptr [ebp - 4], 4
  0x0057da6f: push     8
  0x0057da71: push     eax
  0x0057da72: mov      dword ptr [ebp - 0x14], eax
  0x0057da75: call     0x6ce938
  0x0057da7a: mov      dword ptr [esi + 0xcad], 0
  0x0057da84: lea      edi, [esi + 0x42c]
  0x0057da8a: mov      dword ptr [esi + 0xcb1], 0
  0x0057da94: mov      ebx, 0x100
