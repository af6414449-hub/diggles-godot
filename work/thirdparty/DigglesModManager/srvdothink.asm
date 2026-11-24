  0x006b4a30: push     ebp
  0x006b4a31: mov      ebp, esp
  0x006b4a33: push     -1
  0x006b4a35: push     0x712e9e
  0x006b4a3a: mov      eax, dword ptr fs:[0]
  0x006b4a40: push     eax
  0x006b4a41: sub      esp, 0x34
  0x006b4a44: push     ebx
  0x006b4a45: push     esi
  0x006b4a46: push     edi
  0x006b4a47: mov      eax, dword ptr [0x76700c]
  0x006b4a4c: xor      eax, ebp
  0x006b4a4e: push     eax
  0x006b4a4f: lea      eax, [ebp - 0xc]
  0x006b4a52: mov      dword ptr fs:[0], eax
  0x006b4a58: mov      dword ptr [ebp - 0x1c], ecx
  0x006b4a5b: mov      eax, dword ptr fs:[0x2c]
  0x006b4a61: mov      ebx, dword ptr [eax]
  0x006b4a63: mov      eax, dword ptr [0xca7e44]
  0x006b4a68: mov      dword ptr [ebp - 0x28], ebx
  0x006b4a6b: cmp      eax, dword ptr [ebx + 4]
  0x006b4a71: jg       0x6b554a
  0x006b4a77: mov      edi, dword ptr [0xca7e48]
  0x006b4a7d: shl      edi, 6
  0x006b4a80: mov      dword ptr [ebp - 0x2c], 0xca7e48
  0x006b4a87: mov      esi, dword ptr [edi + 0x773650]
  0x006b4a8d: call     0x43fcc0
  0x006b4a92: mov      ecx, dword ptr [eax + 0x8000]
  0x006b4a98: mov      dword ptr [eax + ecx*4], esi
  0x006b4a9b: inc      dword ptr [eax + 0x8000]
  0x006b4aa1: mov      eax, dword ptr [edi + 0x773654]
  0x006b4aa7: test     eax, eax
  0x006b4aa9: jne      0x6b4ac2
  0x006b4aab: call     0x6bd180
  0x006b4ab0: mov      dword ptr [edi + 0x773658], eax
  0x006b4ab6: mov      eax, dword ptr [edi + 0x773654]
  0x006b4abc: mov      dword ptr [edi + 0x77365c], edx
  0x006b4ac2: inc      eax
  0x006b4ac3: mov      dword ptr [edi + 0x773654], eax
  0x006b4ac9: mov      dword ptr [ebp - 4], 0
  0x006b4ad0: mov      ecx, dword ptr [0x772400]
  0x006b4ad6: cmp      byte ptr [ecx + 0x8a], 0
  0x006b4add: movsd    xmm1, qword ptr [ecx + 0xa088]
  0x006b4ae5: movsd    qword ptr [ebp - 0x38], xmm1
  0x006b4aea: je       0x6b5524
  0x006b4af0: mov      esi, dword ptr [ebp - 0x1c]
  0x006b4af3: movsd    xmm0, qword ptr [esi + 0x80]
  0x006b4afb: comisd   xmm1, xmm0
  0x006b4aff: jb       0x6b4c2e
  0x006b4b05: mov      eax, dword ptr [0xca7e4c]
  0x006b4b0a: cmp      eax, dword ptr [ebx + 4]
  0x006b4b10: jg       0x6b559d
  0x006b4b16: push     0xca7e50
  0x006b4b1b: lea      ecx, [ebp - 0x20]
  0x006b4b1e: call     0x405af0
  0x006b4b23: mov      byte ptr [ebp - 4], 1
  0x006b4b27: mov      ecx, dword ptr [0x772400]
  0x006b4b2d: movsd    xmm0, qword ptr [esi + 0x80]
  0x006b4b35: movsd    qword ptr [ecx + 0xa0b0], xmm0
  0x006b4b3d: add      ecx, 0x368
  0x006b4b43: call     0x54df60
  0x006b4b48: mov      eax, dword ptr [0xca7e54]
  0x006b4b4d: cmp      eax, dword ptr [ebx + 4]
  0x006b4b53: jg       0x6b55f0
  0x006b4b59: push     0xca7e58
  0x006b4b5e: lea      ecx, [ebp - 0x24]
  0x006b4b61: call     0x405af0
  0x006b4b66: mov      eax, dword ptr [ebp - 0x24]
  0x006b4b69: mov      ecx, dword ptr [eax]
  0x006b4b6b: shl      ecx, 6
  0x006b4b6e: add      ecx, 0x773650
  0x006b4b74: call     0x43fd30
  0x006b4b79: mov      eax, dword ptr [0xca7e5c]
  0x006b4b7e: cmp      eax, dword ptr [ebx + 4]
  0x006b4b84: jg       0x6b5643
  0x006b4b8a: push     0xca7e60
  0x006b4b8f: lea      ecx, [ebp - 0x24]
  0x006b4b92: call     0x405af0
  0x006b4b97: mov      byte ptr [ebp - 4], 2
  0x006b4b9b: mov      ecx, dword ptr [0x77244c]
  0x006b4ba1: call     0x5d4250
  0x006b4ba6: mov      eax, dword ptr [ebp - 0x24]
  0x006b4ba9: mov      ecx, dword ptr [eax]
  0x006b4bab: shl      ecx, 6
  0x006b4bae: add      ecx, 0x773650
  0x006b4bb4: call     0x43fd30
  0x006b4bb9: mov      eax, dword ptr [0xca7e64]
  0x006b4bbe: cmp      eax, dword ptr [ebx + 4]
  0x006b4bc4: jg       0x6b5696
  0x006b4bca: push     0xca7e68
  0x006b4bcf: lea      ecx, [ebp - 0x24]
  0x006b4bd2: call     0x405af0
  0x006b4bd7: mov      byte ptr [ebp - 4], 3
  0x006b4bdb: call     0x4244e0
  0x006b4be0: call     0x424680
  0x006b4be5: call     0x4244e0
  0x006b4bea: mov      ecx, eax
  0x006b4bec: call     0x424560
  0x006b4bf1: mov      eax, dword ptr [ebp - 0x24]
  0x006b4bf4: mov      ecx, dword ptr [eax]
  0x006b4bf6: shl      ecx, 6
  0x006b4bf9: add      ecx, 0x773650
  0x006b4bff: call     0x43fd30
  0x006b4c04: mov      byte ptr [ebp - 4], 0
  0x006b4c08: mov      eax, dword ptr [ebp - 0x20]
  0x006b4c0b: mov      ecx, dword ptr [eax]
  0x006b4c0d: shl      ecx, 6
  0x006b4c10: add      ecx, 0x773650
  0x006b4c16: call     0x43fd30
  0x006b4c1b: movsd    xmm0, qword ptr [esi + 0x80]
  0x006b4c23: mov      ecx, dword ptr [0x772400]
  0x006b4c29: movsd    xmm1, qword ptr [ebp - 0x38]
  0x006b4c2e: comisd   xmm1, xmm0
  0x006b4c32: mov      edx, 0xa
  0x006b4c37: mov      dword ptr [ebp - 0x20], edx
  0x006b4c3a: jb       0x6b5506
  0x006b4c40: movsd    xmm1, qword ptr [0x7371a8]
  0x006b4c48: movsd    qword ptr [ebp - 0x40], xmm1
  0x006b4c4d: nop      dword ptr [eax]
  0x006b4c50: test     edx, edx
  0x006b4c52: jle      0x6b5506
  0x006b4c58: mov      edi, dword ptr [ecx + 0x38]
  0x006b4c5b: test     edi, edi
  0x006b4c5d: je       0x6b4c94
  0x006b4c5f: mov      esi, dword ptr [ecx + 0x4c]
  0x006b4c62: inc      esi
  0x006b4c63: add      dword ptr [ecx + 0x40], 1
  0x006b4c67: mov      dword ptr [ecx + 0x4c], esi
  0x006b4c6a: adc      dword ptr [ecx + 0x44], 0
  0x006b4c6e: cmp      esi, dword ptr [ecx + 0x48]
  0x006b4c71: jl       0x6b4c7c
  0x006b4c73: mov      dword ptr [ecx + 0x4c], 0
  0x006b4c7a: xor      esi, esi
  0x006b4c7c: call     0x6bd180
  0x006b4c81: mov      ecx, dword ptr [0x772400]
  0x006b4c87: mov      dword ptr [edi + esi*8 + 4], edx
  0x006b4c8b: mov      edx, dword ptr [ebp - 0x20]
  0x006b4c8e: mov      dword ptr [edi + esi*8], eax
  0x006b4c91: mov      esi, dword ptr [ebp - 0x1c]
  0x006b4c94: inc      dword ptr [ecx + 0x6c]
  0x006b4c97: dec      edx
  0x006b4c98: movsd    xmm0, qword ptr [esi + 0x80]
  0x006b4ca0: movsd    qword ptr [ecx + 0xa0b0], xmm0
  0x006b4ca8: movsd    xmm0, qword ptr [esi + 0x80]
  0x006b4cb0: addsd    xmm0, qword ptr [ebp - 0x40]
  0x006b4cb5: mov      dword ptr [ebp - 0x20], edx
  0x006b4cb8: movsd    qword ptr [esi + 0x80], xmm0
  0x006b4cc0: mov      eax, dword ptr [0xca7e6c]
  0x006b4cc5: cmp      eax, dword ptr [ebx + 4]
  0x006b4ccb: jg       0x6b56e9
  0x006b4cd1: mov      edi, dword ptr [0xca7e70]
  0x006b4cd7: mov      eax, dword ptr [0x767960]
  0x006b4cdc: shl      edi, 6
  0x006b4cdf: mov      dword ptr [ebp - 0x24], 0xca7e70
  0x006b4ce6: cmp      eax, -1
  0x006b4ce9: jne      0x6b4cf6
  0x006b4ceb: call     dword ptr [0x71533c]
  0x006b4cf1: mov      dword ptr [0x767960], eax
  0x006b4cf6: push     eax
  0x006b4cf7: call     dword ptr [0x715338]
  0x006b4cfd: mov      esi, eax
  0x006b4cff: test     esi, esi
  0x006b4d01: jne      0x6b4d38
  0x006b4d03: push     0x18
  0x006b4d05: mov      edx, 0x721a48  ; "C:\dev\wiggles\Wiggles\Wiggles\Basics\CallStat.cpp"
  0x006b4d0a: mov      ecx, 0x8004
  0x006b4d0f: call     0x6ba810
  0x006b4d14: mov      esi, eax
  0x006b4d16: add      esp, 4
  0x006b4d19: test     esi, esi
  0x006b4d1b: je       0x6b4d29
  0x006b4d1d: mov      dword ptr [esi + 0x8000], 0
  0x006b4d27: jmp      0x6b4d2b
  0x006b4d29: xor      esi, esi
  0x006b4d2b: push     esi
  0x006b4d2c: push     dword ptr [0x767960]
  0x006b4d32: call     dword ptr [0x715334]
  0x006b4d38: mov      eax, dword ptr [esi + 0x8000]
  0x006b4d3e: mov      ecx, dword ptr [edi + 0x773650]
  0x006b4d44: mov      dword ptr [esi + eax*4], ecx
  0x006b4d47: inc      dword ptr [esi + 0x8000]
  0x006b4d4d: mov      eax, dword ptr [edi + 0x773654]
  0x006b4d53: test     eax, eax
  0x006b4d55: jne      0x6b4d6e
  0x006b4d57: call     0x6bd180
  0x006b4d5c: mov      dword ptr [edi + 0x773658], eax
  0x006b4d62: mov      eax, dword ptr [edi + 0x773654]
  0x006b4d68: mov      dword ptr [edi + 0x77365c], edx
  0x006b4d6e: inc      eax
  0x006b4d6f: mov      dword ptr [edi + 0x773654], eax
  0x006b4d75: mov      byte ptr [ebp - 4], 7
  0x006b4d79: call     0x5ee9d0
  0x006b4d7e: mov      ecx, eax
  0x006b4d80: call     0x5eed70
  0x006b4d85: mov      byte ptr [ebp - 4], 0
  0x006b4d89: mov      ecx, dword ptr [0xca7e70]
  0x006b4d8f: shl      ecx, 6
  0x006b4d92: add      ecx, 0x773650
  0x006b4d98: call     0x43fd30
  0x006b4d9d: mov      ebx, dword ptr [0x772448]
  0x006b4da3: mov      dword ptr [ebp - 0x14], ebx
  0x006b4da6: test     ebx, ebx
  0x006b4da8: jne      0x6b4ddf
  0x006b4daa: push     0x1e
  0x006b4dac: mov      edx, 0x72b2ec  ; "C:\dev\wiggles\Wiggles\Wiggles\Objects\EnergyMgr.cpp"
  0x006b4db1: lea      ecx, [ebx + 8]
  0x006b4db4: call     0x6ba810
  0x006b4db9: mov      ebx, eax
  0x006b4dbb: mov      dword ptr [ebp - 0x14], eax
  0x006b4dbe: add      esp, 4
  0x006b4dc1: test     ebx, ebx
  0x006b4dc3: je       0x6b4dd4
  0x006b4dc5: mov      dword ptr [ebx], 0
  0x006b4dcb: mov      dword ptr [ebx + 4], 0
  0x006b4dd2: jmp      0x6b4dd9
  0x006b4dd4: xor      ebx, ebx
  0x006b4dd6: mov      dword ptr [ebp - 0x14], ebx
  0x006b4dd9: mov      dword ptr [0x772448], ebx
  0x006b4ddf: mov      eax, dword ptr [ebx + 4]
  0x006b4de2: xor      ecx, ecx
  0x006b4de4: mov      dword ptr [ebp - 0x18], ecx
  0x006b4de7: test     eax, eax
  0x006b4de9: jle      0x6b4f10
  0x006b4def: xor      edi, edi
  0x006b4df1: cmp      ecx, eax
  0x006b4df3: mov      dword ptr [ebp - 0x24], edi
  0x006b4df6: jb       0x6b4e0c
  0x006b4df8: push     0
  0x006b4dfa: push     0
  0x006b4dfc: push     1
  0x006b4dfe: push     0xc000008c
  0x006b4e03: call     dword ptr [0x715340]
  0x006b4e09: mov      ecx, dword ptr [ebp - 0x18]
  0x006b4e0c: mov      esi, dword ptr [ebx]
  0x006b4e0e: xorps    xmm0, xmm0
  0x006b4e11: add      esi, edi
  0x006b4e13: movss    dword ptr [ebp - 0x10], xmm0
  0x006b4e18: xor      edi, edi
  0x006b4e1a: cmp      dword ptr [esi + 0x10], edi
  0x006b4e1d: jle      0x6b4ee8
  0x006b4e23: xor      ebx, ebx
  0x006b4e25: cmp      edi, dword ptr [esi + 0x10]
  0x006b4e28: jb       0x6b4e3b
  0x006b4e2a: push     0
  0x006b4e2c: push     0
  0x006b4e2e: push     1
  0x006b4e30: push     0xc000008c
  0x006b4e35: call     dword ptr [0x715340]
  0x006b4e3b: mov      eax, dword ptr [esi + 0xc]
  0x006b4e3e: add      dword ptr [eax + ebx + 8], -1
  0x006b4e43: jne      0x6b4eac
  0x006b4e45: mov      edx, dword ptr [esi + 0x10]
  0x006b4e48: cmp      edi, edx
  0x006b4e4a: jb       0x6b4e78
  0x006b4e4c: push     0
  0x006b4e4e: push     0
  0x006b4e50: push     1
  0x006b4e52: push     0xc000008c
  0x006b4e57: call     dword ptr [0x715340]
  0x006b4e5d: mov      edx, dword ptr [esi + 0x10]
  0x006b4e60: cmp      edi, edx
  0x006b4e62: jb       0x6b4e78
  0x006b4e64: push     0
  0x006b4e66: push     0
  0x006b4e68: push     1
  0x006b4e6a: push     0xc000008c
  0x006b4e6f: call     dword ptr [0x715340]
  0x006b4e75: mov      edx, dword ptr [esi + 0x10]
  0x006b4e78: lea      eax, [edx - 1]
  0x006b4e7b: cmp      edi, eax
  0x006b4e7d: jge      0x6b4e9b
  0x006b4e7f: mov      ecx, dword ptr [esi + 0xc]
  0x006b4e82: lea      eax, [edx + edx*2]
  0x006b4e85: movq     xmm0, qword ptr [ecx + eax*4 - 0xc]
  0x006b4e8b: movq     qword ptr [ecx + ebx], xmm0
  0x006b4e90: mov      eax, dword ptr [ecx + eax*4 - 4]
  0x006b4e94: mov      dword ptr [ecx + ebx + 8], eax
  0x006b4e98: mov      edx, dword ptr [esi + 0x10]
  0x006b4e9b: movss    xmm0, dword ptr [ebp - 0x10]
  0x006b4ea0: lea      eax, [edx - 1]
  0x006b4ea3: dec      edi
  0x006b4ea4: mov      dword ptr [esi + 0x10], eax
  0x006b4ea7: sub      ebx, 0xc
  0x006b4eaa: jmp      0x6b4ed5
  0x006b4eac: cmp      edi, dword ptr [esi + 0x10]
  0x006b4eaf: jb       0x6b4ec2
  0x006b4eb1: push     0
  0x006b4eb3: push     0
  0x006b4eb5: push     1
  0x006b4eb7: push     0xc000008c
  0x006b4ebc: call     dword ptr [0x715340]
  0x006b4ec2: mov      eax, dword ptr [esi + 0xc]
  0x006b4ec5: movss    xmm0, dword ptr [eax + ebx + 4]
  0x006b4ecb: addss    xmm0, dword ptr [ebp - 0x10]
  0x006b4ed0: movss    dword ptr [ebp - 0x10], xmm0
  0x006b4ed5: inc      edi
  0x006b4ed6: add      ebx, 0xc
  0x006b4ed9: cmp      edi, dword ptr [esi + 0x10]
  0x006b4edc: jl       0x6b4e28
  0x006b4ee2: mov      ebx, dword ptr [ebp - 0x14]
  0x006b4ee5: mov      ecx, dword ptr [ebp - 0x18]
  0x006b4ee8: mov      eax, dword ptr [esi]
  0x006b4eea: inc      ecx
  0x006b4eeb: mov      edi, dword ptr [ebp - 0x24]
  0x006b4eee: add      edi, 0x14
  0x006b4ef1: mov      dword ptr [ebp - 0x18], ecx
  0x006b4ef4: mov      dword ptr [ebp - 0x24], edi
  0x006b4ef7: mov      eax, dword ptr [eax + 0x3e0]
  0x006b4efd: movss    dword ptr [eax + 0x13c], xmm0
  0x006b4f05: mov      eax, dword ptr [ebx + 4]
  0x006b4f08: cmp      ecx, eax
  0x006b4f0a: jl       0x6b4df6
  0x006b4f10: cmp      dword ptr [0x77241c], 0
  0x006b4f17: mov      ebx, dword ptr [ebp - 0x28]
  0x006b4f1a: je       0x6b4fa4
  0x006b4f20: mov      eax, dword ptr [0xca7e74]
  0x006b4f25: cmp      eax, dword ptr [ebx + 4]
  0x006b4f2b: jg       0x6b573c
  0x006b4f31: mov      edi, dword ptr [0xca7e78]
  0x006b4f37: shl      edi, 6
  0x006b4f3a: mov      dword ptr [ebp - 0x24], 0xca7e78
  0x006b4f41: mov      esi, dword ptr [edi + 0x773650]
  0x006b4f47: call     0x43fcc0
  0x006b4f4c: mov      ecx, dword ptr [eax + 0x8000]
  0x006b4f52: mov      dword ptr [eax + ecx*4], esi
  0x006b4f55: inc      dword ptr [eax + 0x8000]
  0x006b4f5b: mov      eax, dword ptr [edi + 0x773654]
  0x006b4f61: test     eax, eax
  0x006b4f63: jne      0x6b4f7c
  0x006b4f65: call     0x6bd180
  0x006b4f6a: mov      dword ptr [edi + 0x773658], eax
  0x006b4f70: mov      eax, dword ptr [edi + 0x773654]
  0x006b4f76: mov      dword ptr [edi + 0x77365c], edx
  0x006b4f7c: inc      eax
  0x006b4f7d: mov      dword ptr [edi + 0x773654], eax
  0x006b4f83: mov      byte ptr [ebp - 4], 8
  0x006b4f87: call     0x598920
  0x006b4f8c: mov      byte ptr [ebp - 4], 0
  0x006b4f90: mov      ecx, dword ptr [0xca7e78]
  0x006b4f96: shl      ecx, 6
  0x006b4f99: add      ecx, 0x773650
  0x006b4f9f: call     0x43fd30
  0x006b4fa4: mov      eax, dword ptr [0xca7e7c]
  0x006b4fa9: cmp      eax, dword ptr [ebx + 4]
  0x006b4faf: jg       0x6b578f
  0x006b4fb5: mov      edi, dword ptr [0xca7e80]
  0x006b4fbb: mov      eax, dword ptr [0x767960]
  0x006b4fc0: shl      edi, 6
  0x006b4fc3: mov      dword ptr [ebp - 0x24], 0xca7e80
  0x006b4fca: cmp      eax, -1
  0x006b4fcd: jne      0x6b4fda
  0x006b4fcf: call     dword ptr [0x71533c]
  0x006b4fd5: mov      dword ptr [0x767960], eax
  0x006b4fda: push     eax
  0x006b4fdb: call     dword ptr [0x715338]
  0x006b4fe1: mov      esi, eax
  0x006b4fe3: test     esi, esi
  0x006b4fe5: jne      0x6b501c
  0x006b4fe7: push     0x18
  0x006b4fe9: mov      edx, 0x721a48  ; "C:\dev\wiggles\Wiggles\Wiggles\Basics\CallStat.cpp"
  0x006b4fee: mov      ecx, 0x8004
  0x006b4ff3: call     0x6ba810
  0x006b4ff8: mov      esi, eax
  0x006b4ffa: add      esp, 4
  0x006b4ffd: test     esi, esi
  0x006b4fff: je       0x6b500d
  0x006b5001: mov      dword ptr [esi + 0x8000], 0
  0x006b500b: jmp      0x6b500f
  0x006b500d: xor      esi, esi
  0x006b500f: push     esi
  0x006b5010: push     dword ptr [0x767960]
  0x006b5016: call     dword ptr [0x715334]
  0x006b501c: mov      eax, dword ptr [esi + 0x8000]
  0x006b5022: mov      ecx, dword ptr [edi + 0x773650]
  0x006b5028: mov      dword ptr [esi + eax*4], ecx
  0x006b502b: inc      dword ptr [esi + 0x8000]
  0x006b5031: mov      eax, dword ptr [edi + 0x773654]
  0x006b5037: test     eax, eax
  0x006b5039: jne      0x6b5052
  0x006b503b: call     0x6bd180
  0x006b5040: mov      dword ptr [edi + 0x773658], eax
  0x006b5046: mov      eax, dword ptr [edi + 0x773654]
  0x006b504c: mov      dword ptr [edi + 0x77365c], edx
  0x006b5052: inc      eax
  0x006b5053: mov      dword ptr [edi + 0x773654], eax
  0x006b5059: mov      byte ptr [ebp - 4], 9
  0x006b505d: mov      esi, dword ptr [0x772468]
  0x006b5063: test     esi, esi
  0x006b5065: jne      0x6b50af
  0x006b5067: push     0x2f6
  0x006b506c: mov      edx, 0x72c004  ; "C:\dev\wiggles\Wiggles\Wiggles\Objects\Physic.cpp"
  0x006b5071: lea      ecx, [esi + 9]
  0x006b5074: call     0x6ba810
  0x006b5079: mov      esi, eax
  0x006b507b: add      esp, 4
  0x006b507e: mov      dword ptr [ebp - 0x30], esi
  0x006b5081: test     esi, esi
  0x006b5083: je       0x6b50a3
  0x006b5085: mov      dword ptr [esi + 1], 0
  0x006b508c: mov      dword ptr [esi + 5], 0
  0x006b5093: mov      byte ptr [ebp - 4], 0xb
  0x006b5097: mov      ecx, esi
  0x006b5099: mov      byte ptr [esi], 1
  0x006b509c: call     0x5ebb00
  0x006b50a1: jmp      0x6b50a5
  0x006b50a3: xor      esi, esi
  0x006b50a5: mov      byte ptr [ebp - 4], 9
  0x006b50a9: mov      dword ptr [0x772468], esi
  0x006b50af: mov      ecx, esi
  0x006b50b1: call     0x5eafd0
  0x006b50b6: mov      byte ptr [ebp - 4], 0
  0x006b50ba: mov      ecx, dword ptr [0xca7e80]
  0x006b50c0: shl      ecx, 6
  0x006b50c3: add      ecx, 0x773650
  0x006b50c9: call     0x43fd30
  0x006b50ce: mov      eax, dword ptr [0xca7e84]
  0x006b50d3: cmp      eax, dword ptr [ebx + 4]
  0x006b50d9: jg       0x6b57e2
  0x006b50df: mov      edi, dword ptr [0xca7e88]
  0x006b50e5: mov      eax, dword ptr [0x767960]
  0x006b50ea: shl      edi, 6
  0x006b50ed: mov      dword ptr [ebp - 0x24], 0xca7e88
  0x006b50f4: cmp      eax, -1
  0x006b50f7: jne      0x6b5104
  0x006b50f9: call     dword ptr [0x71533c]
  0x006b50ff: mov      dword ptr [0x767960], eax
  0x006b5104: push     eax
  0x006b5105: call     dword ptr [0x715338]
  0x006b510b: mov      esi, eax
  0x006b510d: test     esi, esi
  0x006b510f: jne      0x6b5146
  0x006b5111: push     0x18
  0x006b5113: mov      edx, 0x721a48  ; "C:\dev\wiggles\Wiggles\Wiggles\Basics\CallStat.cpp"
  0x006b5118: mov      ecx, 0x8004
  0x006b511d: call     0x6ba810
  0x006b5122: mov      esi, eax
  0x006b5124: add      esp, 4
  0x006b5127: test     esi, esi
  0x006b5129: je       0x6b5137
  0x006b512b: mov      dword ptr [esi + 0x8000], 0
  0x006b5135: jmp      0x6b5139
  0x006b5137: xor      esi, esi
  0x006b5139: push     esi
  0x006b513a: push     dword ptr [0x767960]
  0x006b5140: call     dword ptr [0x715334]
  0x006b5146: mov      eax, dword ptr [esi + 0x8000]
  0x006b514c: mov      ecx, dword ptr [edi + 0x773650]
  0x006b5152: mov      dword ptr [esi + eax*4], ecx
  0x006b5155: inc      dword ptr [esi + 0x8000]
  0x006b515b: mov      eax, dword ptr [edi + 0x773654]
  0x006b5161: test     eax, eax
  0x006b5163: jne      0x6b517c
  0x006b5165: call     0x6bd180
  0x006b516a: mov      dword ptr [edi + 0x773658], eax
  0x006b5170: mov      eax, dword ptr [edi + 0x773654]
  0x006b5176: mov      dword ptr [edi + 0x77365c], edx
  0x006b517c: inc      eax
  0x006b517d: mov      dword ptr [edi + 0x773654], eax
  0x006b5183: mov      byte ptr [ebp - 4], 0xc
  0x006b5187: mov      eax, dword ptr [0x772484]
  0x006b518c: test     eax, eax
  0x006b518e: jne      0x6b51c3
  0x006b5190: push     0x6d
  0x006b5192: mov      edx, 0x72c930  ; "C:\dev\wiggles\Wiggles\Wiggles\Objects\Trigger.cpp"
  0x006b5197: lea      ecx, [eax + 8]
  0x006b519a: call     0x6ba810
  0x006b519f: add      esp, 4
  0x006b51a2: mov      dword ptr [ebp - 0x18], eax
  0x006b51a5: test     eax, eax
  0x006b51a7: je       0x6b51b8
  0x006b51a9: mov      dword ptr [eax], 0
  0x006b51af: mov      dword ptr [eax + 4], 0
  0x006b51b6: jmp      0x6b51ba
  0x006b51b8: xor      eax, eax
  0x006b51ba: mov      byte ptr [ebp - 4], 0xc
  0x006b51be: mov      dword ptr [0x772484], eax
  0x006b51c3: mov      ecx, eax
  0x006b51c5: call     0x60df40
  0x006b51ca: mov      ecx, dword ptr [0xca7e88]
  0x006b51d0: shl      ecx, 6
  0x006b51d3: add      ecx, 0x773650
  0x006b51d9: call     0x43fd30
  0x006b51de: mov      eax, dword ptr [0x772400]
  0x006b51e3: mov      eax, dword ptr [eax + 0x6c]
  0x006b51e6: and      eax, 0x80000003
  0x006b51eb: jns      0x6b51f2
  0x006b51ed: dec      eax
  0x006b51ee: or       eax, 0xfffffffc
  0x006b51f1: inc      eax
  0x006b51f2: cmp      eax, 3
  0x006b51f5: jne      0x6b528e
  0x006b51fb: mov      eax, dword ptr [0xca7e8c]
  0x006b5200: cmp      eax, dword ptr [ebx + 4]
  0x006b5206: jg       0x6b5835
  0x006b520c: mov      edi, dword ptr [0xca7e90]
  0x006b5212: shl      edi, 6
  0x006b5215: mov      dword ptr [ebp - 0x24], 0xca7e90
  0x006b521c: mov      esi, dword ptr [edi + 0x773650]
  0x006b5222: call     0x43fcc0
  0x006b5227: mov      ecx, dword ptr [eax + 0x8000]
  0x006b522d: mov      dword ptr [eax + ecx*4], esi
  0x006b5230: inc      dword ptr [eax + 0x8000]
  0x006b5236: mov      eax, dword ptr [edi + 0x773654]
  0x006b523c: test     eax, eax
  0x006b523e: jne      0x6b5257
  0x006b5240: call     0x6bd180
  0x006b5245: mov      dword ptr [edi + 0x773658], eax
  0x006b524b: mov      eax, dword ptr [edi + 0x773654]
  0x006b5251: mov      dword ptr [edi + 0x77365c], edx
  0x006b5257: inc      eax
  0x006b5258: mov      dword ptr [edi + 0x773654], eax
  0x006b525e: mov      byte ptr [ebp - 4], 0x13
  0x006b5262: mov      ecx, dword ptr [0x77241c]
  0x006b5268: test     ecx, ecx
  0x006b526a: je       0x6b527a
  0x006b526c: cmp      byte ptr [ecx + 0x29], 0
  0x006b5270: je       0x6b527a
  0x006b5272: mov      ecx, dword ptr [ecx + 0x20]
  0x006b5275: call     0x57f5c0
  0x006b527a: mov      ecx, dword ptr [0xca7e90]
  0x006b5280: shl      ecx, 6
  0x006b5283: add      ecx, 0x773650
  0x006b5289: call     0x43fd30
  0x006b528e: mov      eax, dword ptr [0xca7e94]
  0x006b5293: cmp      eax, dword ptr [ebx + 4]
  0x006b5299: jg       0x6b5888
  0x006b529f: mov      edi, dword ptr [0xca7e98]
  0x006b52a5: shl      edi, 6
  0x006b52a8: mov      dword ptr [ebp - 0x24], 0xca7e98
  0x006b52af: mov      esi, dword ptr [edi + 0x773650]
  0x006b52b5: call     0x43fcc0
  0x006b52ba: mov      ecx, dword ptr [eax + 0x8000]
  0x006b52c0: mov      dword ptr [eax + ecx*4], esi
  0x006b52c3: inc      dword ptr [eax + 0x8000]
  0x006b52c9: mov      eax, dword ptr [edi + 0x773654]
  0x006b52cf: test     eax, eax
  0x006b52d1: jne      0x6b52ea
  0x006b52d3: call     0x6bd180
  0x006b52d8: mov      dword ptr [edi + 0x773658], eax
  0x006b52de: mov      eax, dword ptr [edi + 0x773654]
  0x006b52e4: mov      dword ptr [edi + 0x77365c], edx
  0x006b52ea: inc      eax
  0x006b52eb: mov      dword ptr [edi + 0x773654], eax
  0x006b52f1: push     0x7ff
  0x006b52f6: mov      byte ptr [ebp - 4], 0x14
  0x006b52fa: call     0x5a3dd0
  0x006b52ff: mov      ecx, eax
  0x006b5301: call     0x5a46d0
  0x006b5306: mov      ecx, dword ptr [0xca7e98]
  0x006b530c: shl      ecx, 6
  0x006b530f: add      ecx, 0x773650
  0x006b5315: call     0x43fd30
  0x006b531a: mov      eax, dword ptr [0xca7e9c]
  0x006b531f: cmp      eax, dword ptr [ebx + 4]
  0x006b5325: jg       0x6b58db
  0x006b532b: mov      edi, dword ptr [0xca7ea0]
  0x006b5331: shl      edi, 6
  0x006b5334: mov      dword ptr [ebp - 0x24], 0xca7ea0
  0x006b533b: mov      esi, dword ptr [edi + 0x773650]
  0x006b5341: call     0x43fcc0
  0x006b5346: mov      ecx, dword ptr [eax + 0x8000]
  0x006b534c: mov      dword ptr [eax + ecx*4], esi
  0x006b534f: inc      dword ptr [eax + 0x8000]
  0x006b5355: mov      eax, dword ptr [edi + 0x773654]
  0x006b535b: test     eax, eax
  0x006b535d: jne      0x6b5376
  0x006b535f: call     0x6bd180
  0x006b5364: mov      dword ptr [edi + 0x773658], eax
  0x006b536a: mov      eax, dword ptr [edi + 0x773654]
  0x006b5370: mov      dword ptr [edi + 0x77365c], edx
  0x006b5376: inc      eax
  0x006b5377: mov      dword ptr [edi + 0x773654], eax
  0x006b537d: mov      byte ptr [ebp - 4], 0x15
  0x006b5381: mov      ecx, dword ptr [0x77244c]
  0x006b5387: inc      dword ptr [0xc3c9e4]
  0x006b538d: call     0x5d38c0
  0x006b5392: mov      ecx, dword ptr [0xca7ea0]
  0x006b5398: shl      ecx, 6
  0x006b539b: add      ecx, 0x773650
  0x006b53a1: mov      dword ptr [0xc3c9e4], 0
  0x006b53ab: call     0x43fd30
  0x006b53b0: mov      eax, dword ptr [0xca7ea4]
  0x006b53b5: cmp      eax, dword ptr [ebx + 4]
  0x006b53bb: jg       0x6b592e
  0x006b53c1: mov      edi, dword ptr [0xca7ea8]
  0x006b53c7: shl      edi, 6
  0x006b53ca: mov      esi, dword ptr [edi + 0x773650]
  0x006b53d0: call     0x43fcc0
  0x006b53d5: mov      ecx, dword ptr [eax + 0x8000]
  0x006b53db: mov      dword ptr [eax + ecx*4], esi
  0x006b53de: inc      dword ptr [eax + 0x8000]
  0x006b53e4: mov      eax, dword ptr [edi + 0x773654]
  0x006b53ea: test     eax, eax
  0x006b53ec: jne      0x6b5405
  0x006b53ee: call     0x6bd180
  0x006b53f3: mov      dword ptr [edi + 0x773658], eax
  0x006b53f9: mov      eax, dword ptr [edi + 0x773654]
  0x006b53ff: mov      dword ptr [edi + 0x77365c], edx
  0x006b5405: mov      ecx, dword ptr [0x77244c]
  0x006b540b: inc      eax
  0x006b540c: mov      dword ptr [edi + 0x773654], eax
  0x006b5412: call     0x5d2720
  0x006b5417: mov      ecx, dword ptr [0xca7ea8]
  0x006b541d: shl      ecx, 6
  0x006b5420: add      ecx, 0x773650
  0x006b5426: call     0x43fd30
  0x006b542b: mov      eax, dword ptr [0xca7eac]
  0x006b5430: cmp      eax, dword ptr [ebx + 4]
  0x006b5436: jg       0x6b5981
  0x006b543c: mov      edi, dword ptr [0xca7eb0]
  0x006b5442: shl      edi, 6
  0x006b5445: mov      dword ptr [ebp - 0x24], 0xca7eb0
  0x006b544c: mov      esi, dword ptr [edi + 0x773650]
  0x006b5452: call     0x43fcc0
  0x006b5457: mov      ecx, dword ptr [eax + 0x8000]
  0x006b545d: mov      dword ptr [eax + ecx*4], esi
  0x006b5460: inc      dword ptr [eax + 0x8000]
  0x006b5466: mov      eax, dword ptr [edi + 0x773654]
  0x006b546c: test     eax, eax
  0x006b546e: jne      0x6b5487
  0x006b5470: call     0x6bd180
  0x006b5475: mov      dword ptr [edi + 0x773658], eax
  0x006b547b: mov      eax, dword ptr [edi + 0x773654]
  0x006b5481: mov      dword ptr [edi + 0x77365c], edx
  0x006b5487: inc      eax
  0x006b5488: mov      dword ptr [edi + 0x773654], eax
  0x006b548e: mov      byte ptr [ebp - 4], 0x16
  0x006b5492: mov      eax, dword ptr [0x772470]
  0x006b5497: test     eax, eax
  0x006b5499: jne      0x6b54b2
  0x006b549b: push     0x17
  0x006b549d: mov      edx, 0x72c284  ; "C:\dev\wiggles\Wiggles\Wiggles\Objects\SrvObjUpdateMgr.cpp"
  0x006b54a2: lea      ecx, [eax + 1]
  0x006b54a5: call     0x6ba810
  0x006b54aa: add      esp, 4
  0x006b54ad: mov      dword ptr [0x772470], eax
  0x006b54b2: mov      ecx, eax
  0x006b54b4: call     0x5f6a20
  0x006b54b9: mov      byte ptr [ebp - 4], 0
  0x006b54bd: mov      ecx, dword ptr [0xca7eb0]
  0x006b54c3: shl      ecx, 6
  0x006b54c6: add      ecx, 0x773650
  0x006b54cc: call     0x43fd30
  0x006b54d1: mov      ecx, dword ptr [0x772400]
  0x006b54d7: lea      ecx, [ecx + 0xa080]
  0x006b54dd: call     0x5653f0
  0x006b54e2: mov      esi, dword ptr [ebp - 0x1c]
  0x006b54e5: movsd    xmm1, qword ptr [ebp - 0x38]
  0x006b54ea: mov      ecx, dword ptr [0x772400]
  0x006b54f0: movsd    xmm0, qword ptr [esi + 0x80]
  0x006b54f8: comisd   xmm1, xmm0
  0x006b54fc: jb       0x6b5506
  0x006b54fe: mov      edx, dword ptr [ebp - 0x20]
  0x006b5501: jmp      0x6b4c50
  0x006b5506: movsd    xmm1, qword ptr [ecx + 0xa088]
  0x006b550e: addsd    xmm1, qword ptr [0x7370a0]
  0x006b5516: comisd   xmm1, xmm0
  0x006b551a: jb       0x6b5524
  0x006b551c: movsd    qword ptr [esi + 0x80], xmm1
  0x006b5524: mov      ecx, dword ptr [0xca7e48]
  0x006b552a: shl      ecx, 6
  0x006b552d: add      ecx, 0x773650
  0x006b5533: call     0x43fd30
  0x006b5538: mov      ecx, dword ptr [ebp - 0xc]
  0x006b553b: mov      dword ptr fs:[0], ecx
  0x006b5542: pop      ecx
  0x006b5543: pop      edi
  0x006b5544: pop      esi
  0x006b5545: pop      ebx
  0x006b5546: mov      esp, ebp
  0x006b5548: pop      ebp
  0x006b5549: ret      
