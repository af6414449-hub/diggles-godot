==============================================================================
func FUN_005c83f0 entry=0x005c83f0 size=2565
==============================================================================
0x005c83f0  push     ebp
0x005c83f1  mov      ebp, esp
0x005c83f3  push     -1
0x005c83f5  push     0x7085ee
0x005c83fa  mov      eax, dword ptr fs:[0]
0x005c8400  push     eax
0x005c8401  sub      esp, 0x28
0x005c8404  push     esi
0x005c8405  push     edi
0x005c8406  mov      eax, dword ptr [0x76700c]
0x005c840b  xor      eax, ebp
0x005c840d  push     eax
0x005c840e  lea      eax, [ebp - 0xc]
0x005c8411  mov      dword ptr fs:[0], eax
0x005c8417  mov      edi, ecx
0x005c8419  mov      dword ptr [ebp - 0x14], edi
0x005c841c  mov      dword ptr [edi + 4], 0
0x005c8423  mov      dword ptr [ebp - 4], 0
0x005c842a  mov      dword ptr [edi], 0x72bcb8
0x005c8430  mov      dword ptr [edi + 0x14], 0
0x005c8437  mov      dword ptr [edi + 0x10], 0
0x005c843e  mov      dword ptr [edi + 0xc], 0
0x005c8445  mov      dword ptr [edi + 0x20], 0
0x005c844c  mov      dword ptr [edi + 0x1c], 0
0x005c8453  mov      dword ptr [edi + 0x18], 0
0x005c845a  mov      dword ptr [edi + 0x30], 0
0x005c8461  mov      dword ptr [edi + 0x2c], 0
0x005c8468  mov      dword ptr [edi + 0x28], 0
0x005c846f  mov      dword ptr [edi + 0x3c], 0
0x005c8476  mov      dword ptr [edi + 0x38], 0
0x005c847d  mov      dword ptr [edi + 0x34], 0
0x005c8484  mov      dword ptr [edi + 0x48], 0
0x005c848b  mov      dword ptr [edi + 0x44], 0
0x005c8492  mov      dword ptr [edi + 0x40], 0
0x005c8499  mov      dword ptr [edi + 0x54], 0
0x005c84a0  mov      dword ptr [edi + 0x50], 0
0x005c84a7  mov      dword ptr [edi + 0x4c], 0
0x005c84ae  mov      dword ptr [edi + 0x58], 0
0x005c84b5  mov      dword ptr [edi + 0x5c], 0
0x005c84bc  mov      dword ptr [edi + 0x60], 0
0x005c84c3  mov      dword ptr [edi + 0x64], 0
0x005c84ca  mov      dword ptr [edi + 0xb0], 0
0x005c84d4  mov      dword ptr [edi + 0xb4], 0
0x005c84de  mov      dword ptr [edi + 0xac], 0
0x005c84e8  mov      dword ptr [edi + 0xb8], 0
0x005c84f2  mov      dword ptr [edi + 0xbc], 0
0x005c84fc  lea      ecx, [edi + 0xc0]
0x005c8502  mov      byte ptr [ebp - 4], 3
0x005c8506  mov      dword ptr [ebp - 0x20], ecx
0x005c8509  call     0x6bc020
0x005c850e  push     0x19
0x005c8510  mov      edx, 0x7364b0
0x005c8515  mov      byte ptr [ebp - 4], 4
0x005c8519  mov      ecx, 0x20
0x005c851e  call     0x6ba810
0x005c8523  add      esp, 4
0x005c8526  mov      dword ptr [eax + 4], 0x14
0x005c852d  mov      dword ptr [eax + 8], 0xffffffff
0x005c8534  mov      dword ptr [eax], 0
0x005c853a  mov      byte ptr [eax + 0xc], 0
0x005c853e  mov      dword ptr [edi + 0xd8], eax
0x005c8544  inc      dword ptr [eax]
0x005c8546  mov      dword ptr [edi + 0xe0], 0
0x005c8550  push     0x406f00
0x005c8555  push     0x453ef0
0x005c855a  push     0x40
0x005c855c  lea      esi, [edi + 0xec]
0x005c8562  mov      byte ptr [ebp - 4], 6
0x005c8566  push     4
0x005c8568  push     esi
0x005c8569  mov      dword ptr [ebp - 0x20], esi
0x005c856c  call     0x6ce938
0x005c8571  mov      dword ptr [esi + 0x108], 0
0x005c857b  mov      dword ptr [esi + 0x10c], 0
0x005c8585  mov      dword ptr [esi + 0x104], 0
0x005c858f  mov      dword ptr [esi + 0x100], 0
0x005c8599  mov      dword ptr [edi + 0x1fc], 0
0x005c85a3  mov      dword ptr [edi + 0x21c], 0
0x005c85ad  mov      dword ptr [edi + 0x23c], 0
0x005c85b7  mov      dword ptr [edi + 0x240], 0
0x005c85c1  mov      dword ptr [edi + 0x260], 0
0x005c85cb  mov      dword ptr [edi + 0x25c], 0
0x005c85d5  mov      dword ptr [edi + 0x258], 0
0x005c85df  mov      dword ptr [edi + 0x254], 0
0x005c85e9  mov      dword ptr [edi + 0x274], 0
0x005c85f3  mov      dword ptr [edi + 0x270], 0
0x005c85fd  mov      esi, dword ptr [0x715340]
0x005c8603  lea      eax, [edi + 0x308]
0x005c8609  xor      ecx, ecx
0x005c860b  mov      dword ptr [edi + 0x26c], 0
0x005c8615  mov      dword ptr [ebp - 0x20], eax
0x005c8618  lea      edx, [edi + 0x2f8]
0x005c861e  xor      eax, eax
0x005c8620  mov      dword ptr [edi + 0x288], 0
0x005c862a  mov      dword ptr [edi + 0x284], 0
0x005c8634  mov      dword ptr [edi + 0x280], 0
0x005c863e  mov      dword ptr [ebp - 0x1c], ecx
0x005c8641  mov      dword ptr [ebp - 0x18], eax
0x005c8644  cmp      eax, 0xf
0x005c8647  ja       0x5c8662
0x005c8649  mov      dword ptr [ecx + edi + 0x2b8], 0xffffffff
0x005c8654  mov      edi, dword ptr [ebp - 0x20]
0x005c8657  add      edi, ecx
0x005c8659  mov      byte ptr [eax + edx], 0
0x005c865d  mov      dword ptr [ebp - 0x10], edi
0x005c8660  jmp      0x5c86af
0x005c8662  push     0
0x005c8664  push     0
0x005c8666  push     1
0x005c8668  push     0xc000008c
0x005c866d  call     esi
0x005c866f  push     0
0x005c8671  push     0
0x005c8673  push     1
0x005c8675  push     0xc000008c
0x005c867a  mov      dword ptr [edi + 0x2b8], 0xffffffff
0x005c8684  call     esi
0x005c8686  push     0
0x005c8688  push     0
0x005c868a  push     1
0x005c868c  push     0xc000008c
0x005c8691  mov      byte ptr [edi + 0x2f8], 0
0x005c8698  call     esi
0x005c869a  mov      ecx, dword ptr [ebp - 0x1c]
0x005c869d  lea      eax, [edi + 0x308]
0x005c86a3  mov      dword ptr [ebp - 0x10], eax
0x005c86a6  lea      edx, [edi + 0x2f8]
0x005c86ac  mov      eax, dword ptr [ebp - 0x18]
0x005c86af  mov      edi, dword ptr [ebp - 0x10]
0x005c86b2  inc      eax
0x005c86b3  add      ecx, 4
0x005c86b6  mov      dword ptr [ebp - 0x18], eax
0x005c86b9  mov      dword ptr [ebp - 0x1c], ecx
0x005c86bc  mov      dword ptr [edi], 0xbf800000
0x005c86c2  mov      edi, dword ptr [ebp - 0x14]
0x005c86c5  cmp      eax, 0x10
0x005c86c8  jl       0x5c8644
0x005c86ce  mov      eax, 8
0x005c86d3  mov      dword ptr [ebp - 0x1c], eax
0x005c86d6  cmp      eax, 0xf
0x005c86d9  ja       0x5c86e0
0x005c86db  lea      ecx, [edx + eax]
0x005c86de  jmp      0x5c86f8
0x005c86e0  push     0
0x005c86e2  push     0
0x005c86e4  push     1
0x005c86e6  push     0xc000008c
0x005c86eb  call     esi
0x005c86ed  mov      eax, dword ptr [ebp - 0x1c]
0x005c86f0  lea      edx, [edi + 0x2f8]
0x005c86f6  mov      ecx, edx
0x005c86f8  inc      eax
0x005c86f9  mov      byte ptr [ecx], 1
0x005c86fc  mov      dword ptr [ebp - 0x1c], eax
0x005c86ff  cmp      eax, 0x10
0x005c8702  jl       0x5c86d6
0x005c8704  mov      word ptr [edi + 0x348], 0
0x005c870d  mov      dword ptr [edi + 0x34c], 0xf
0x005c8717  mov      byte ptr [ebp - 4], 0xb
0x005c871b  mov      edx, 0x7364b0
0x005c8720  mov      dword ptr [edi + 0x350], 0
0x005c872a  mov      ecx, 0x20
0x005c872f  mov      dword ptr [edi + 0x354], 0
0x005c8739  push     0x19
0x005c873b  mov      dword ptr [edi + 0x358], 0
0x005c8745  call     0x6ba810
0x005c874a  add      esp, 4
0x005c874d  mov      dword ptr [eax + 4], 0x14
0x005c8754  mov      dword ptr [eax + 8], 0xffffffff
0x005c875b  mov      dword ptr [eax], 0
0x005c8761  mov      byte ptr [eax + 0xc], 0
0x005c8765  mov      dword ptr [edi + 0x360], eax
0x005c876b  inc      dword ptr [eax]
0x005c876d  mov      dword ptr [edi + 0x370], 0
0x005c8777  mov      dword ptr [edi + 0x374], 0
0x005c8781  mov      dword ptr [edi + 0x3f8], 0
0x005c878b  mov      byte ptr [ebp - 4], 0xe
0x005c878f  mov      ecx, dword ptr [0x772400]
0x005c8795  mov      byte ptr [edi + 0x404], 0
0x005c879c  mov      word ptr [edi + 0x35d], 0
0x005c87a5  mov      dword ptr [edi + 8], 0x616e4f62
0x005c87ac  mov      dword ptr [edi + 0xd4], 0
0x005c87b6  mov      dword ptr [edi + 0xd0], edi
0x005c87bc  mov      dword ptr [edi + 0xdc], 0xffffffff
0x005c87c6  mov      dword ptr [edi + 0x3b8], 0xffffffff
0x005c87d0  mov      dword ptr [edi + 0x3e8], 0
0x005c87da  mov      dword ptr [edi + 0xe8], 0xffffffff
0x005c87e4  mov      dword ptr [edi + 0x204], 0xffffffff
0x005c87ee  mov      dword ptr [edi + 0x200], 0xffffffff
0x005c87f8  mov      dword ptr [edi + 0x208], 1
0x005c8802  mov      dword ptr [edi + 0x3dc], 0
0x005c880c  mov      dword ptr [edi + 0x210], 0
0x005c8816  mov      dword ptr [edi + 0x214], 0
0x005c8820  mov      dword ptr [edi + 0x218], 0
0x005c882a  mov      dword ptr [edi + 0xe4], 0
0x005c8834  mov      dword ptr [edi + 0x2a4], 0xffffffff
0x005c883e  mov      dword ptr [edi + 0x3e0], 0
0x005c8848  mov      dword ptr [edi + 0x28c], 0xffffffff
0x005c8852  mov      dword ptr [edi + 0x290], 0x40000000
0x005c885c  mov      dword ptr [edi + 0x298], 0x14
0x005c8866  mov      dword ptr [edi + 0x29c], 0x12
0x005c8870  mov      dword ptr [edi + 0x2a0], 0xa
0x005c887a  mov      dword ptr [edi + 0x280], 0
0x005c8884  mov      dword ptr [edi + 0x284], 0xbf19999a
0x005c888e  mov      dword ptr [edi + 0x288], 0xc0000000
0x005c8898  mov      byte ptr [edi + 0x35c], 0
0x005c889f  mov      dword ptr [edi + 0x3cc], 0
0x005c88a9  movsd    xmm0, qword ptr [ecx + 0xa088]
0x005c88b1  cvtpd2ps xmm0, xmm0
0x005c88b5  inc      dword ptr [0x772458]
0x005c88bb  inc      dword ptr [0x77245c]
0x005c88c1  divss    xmm0, dword ptr [0x737630]
0x005c88c9  movss    dword ptr [edi + 0x350], xmm0
0x005c88d1  mov      eax, dword ptr [edi + 0x2b8]
0x005c88d7  mov      dword ptr [ebp - 0x20], eax
0x005c88da  cmp      eax, -1
0x005c88dd  je       0x5c8920
0x005c88df  call     0x4c2b50
0x005c88e4  lea      ecx, [eax + 0x38]
0x005c88e7  mov      eax, dword ptr [ebp - 0x20]
0x005c88ea  mov      dword ptr [ebp - 0x1c], ecx
0x005c88ed  cmp      eax, 0x7f
0x005c88f0  ja       0x5c88f9
0x005c88f2  shl      eax, 5
0x005c88f5  add      eax, ecx
0x005c88f7  jmp      0x5c8909
0x005c88f9  push     0
0x005c88fb  push     0
0x005c88fd  push     1
0x005c88ff  push     0xc000008c
0x005c8904  call     esi
0x005c8906  mov      eax, dword ptr [ebp - 0x1c]
0x005c8909  mov      ecx, dword ptr [0x772400]
0x005c890f  mov      dword ptr [eax + 4], 0xffffffff
0x005c8916  mov      dword ptr [edi + 0x2b8], 0xffffffff
0x005c8920  mov      byte ptr [edi + 0x2f8], 1
0x005c8927  mov      eax, dword ptr [ecx + 0x64]
0x005c892a  lea      ecx, [edi + 0x37c]
0x005c8930  mov      dword ptr [edi + 0x378], eax
0x005c8936  mov      dword ptr [edi + 0x2b0], 0
0x005c8940  mov      dword ptr [edi + 0x364], 0xffffffff
0x005c894a  mov      dword ptr [edi + 0x368], 0xffffffff
0x005c8954  mov      dword ptr [edi + 0x36c], 0xffffffff
0x005c895e  mov      dword ptr [edi + 0xdc], 0xffffffff
0x005c8968  mov      dword ptr [edi + 0x3c], 0
0x005c896f  mov      dword ptr [edi + 0x38], 0
0x005c8976  mov      dword ptr [edi + 0x34], 0
0x005c897d  mov      dword ptr [edi + 0xc], 0
0x005c8984  mov      dword ptr [edi + 0x10], 0
0x005c898b  mov      dword ptr [edi + 0x14], 0
0x005c8992  mov      dword ptr [edi + 0x18], 0
0x005c8999  mov      eax, dword ptr [edi + 0x10]
0x005c899c  mov      dword ptr [edi + 0x1c], eax
0x005c899f  mov      eax, dword ptr [edi + 0x14]
0x005c89a2  mov      dword ptr [edi + 0x20], eax
0x005c89a5  mov      dword ptr [edi + 0x28], 0
0x005c89ac  mov      dword ptr [edi + 0x2c], 0
0x005c89b3  mov      dword ptr [edi + 0x30], 0
0x005c89ba  mov      dword ptr [edi + 0x40], 0
0x005c89c1  mov      dword ptr [edi + 0x44], 0
0x005c89c8  mov      dword ptr [edi + 0x48], 0
0x005c89cf  mov      dword ptr [edi + 0x4c], 0
0x005c89d6  mov      eax, dword ptr [edi + 0x44]
0x005c89d9  mov      dword ptr [edi + 0x50], eax
0x005c89dc  mov      eax, dword ptr [edi + 0x48]
0x005c89df  mov      dword ptr [edi + 0x54], eax
0x005c89e2  xor      eax, eax
0x005c89e4  mov      dword ptr [edi + 0x3a8], 0xffffffff
0x005c89ee  mov      dword ptr [edi + 0x3b0], 0xffffffff
0x005c89f8  mov      dword ptr [edi + 0x39c], 0xffffffff
0x005c8a02  mov      dword ptr [edi + 0x3ac], 0xffffffff
0x005c8a0c  mov      dword ptr [edi + 0x3a0], 0xffffffff
0x005c8a16  mov      dword ptr [edi + 0x278], 0xffffffff
0x005c8a20  mov      dword ptr [edi + 0x27c], 0xffffffff
0x005c8a2a  mov      dword ptr [edi + 0x3d4], 0x100100
0x005c8a34  mov      dword ptr [edi + 0x3d0], 0x1100101
0x005c8a3e  mov      byte ptr [edi + 0x3b4], 0
0x005c8a45  mov      dword ptr [edi + 0x20c], 0
0x005c8a4f  mov      edi, ecx
0x005c8a51  mov      dword ptr [ebp - 0x1c], eax
0x005c8a54  cmp      eax, 7
0x005c8a57  ja       0x5c8a5e
0x005c8a59  lea      ecx, [edi + eax*4]
0x005c8a5c  jmp      0x5c8a70
0x005c8a5e  push     0
0x005c8a60  push     0
0x005c8a62  push     1
0x005c8a64  push     0xc000008c
0x005c8a69  call     esi
0x005c8a6b  mov      eax, dword ptr [ebp - 0x1c]
0x005c8a6e  mov      ecx, edi
0x005c8a70  inc      eax
0x005c8a71  mov      dword ptr [ecx], 0xffffffff
0x005c8a77  mov      dword ptr [ebp - 0x1c], eax
0x005c8a7a  cmp      eax, 8
0x005c8a7d  jl       0x5c8a54
0x005c8a7f  mov      edi, dword ptr [ebp - 0x14]
0x005c8a82  mov      dword ptr [ebp - 0x30], 0
0x005c8a89  mov      dword ptr [ebp - 0x24], 0
0x005c8a90  mov      dword ptr [ebp - 0x2c], 0
0x005c8a97  mov      dword ptr [ebp - 0x28], 0
0x005c8a9e  movups   xmm0, xmmword ptr [ebp - 0x30]
0x005c8aa2  mov      dword ptr [edi + 0x26c], 0
0x005c8aac  mov      dword ptr [edi + 0x270], 0
0x005c8ab6  mov      dword ptr [edi + 0x274], 0
0x005c8ac0  movups   xmmword ptr [edi + 0x254], xmm0
0x005c8ac7  mov      dword ptr [edi + 0x264], 0
0x005c8ad1  mov      dword ptr [edi + 0x268], 0
0x005c8adb  mov      dword ptr [edi + 0x248], 1
0x005c8ae5  mov      dword ptr [edi + 0x3e4], 0
0x005c8aef  mov      dword ptr [edi + 0x3e0], 0
0x005c8af9  mov      dword ptr [edi + 0x3f0], 0
0x005c8b03  mov      dword ptr [edi + 0x3f4], 0
0x005c8b0d  mov      eax, dword ptr [edi + 0x240]
0x005c8b13  mov      dword ptr [ebp - 0x18], eax
0x005c8b16  test     eax, eax
0x005c8b18  jns      0x5c8d00
0x005c8b1e  add      eax, 3
0x005c8b21  test     eax, 0xfffffffc
0x005c8b26  je       0x5c8cf5
0x005c8b2c  cmp      dword ptr [0xc3c824], 0
0x005c8b33  mov      eax, dword ptr [edi + 0x23c]
0x005c8b39  mov      dword ptr [ebp - 0x10], eax
0x005c8b3c  jne      0x5c8b53
0x005c8b3e  push     0xc3c78c
0x005c8b43  mov      dword ptr [0xc3c824], 1
0x005c8b4d  call     dword ptr [0x71530c]
0x005c8b53  push     0xc3c78c
0x005c8b58  call     dword ptr [0x715304]
0x005c8b5e  cmp      dword ptr [ebp - 0x10], 0
0x005c8b62  mov      byte ptr [ebp - 4], 0xf
0x005c8b66  jne      0x5c8b9d
0x005c8b68  push     0x9b
0x005c8b6d  mov      edx, 0x71ce9c
0x005c8b72  xor      ecx, ecx
0x005c8b74  call     0x6ba810
0x005c8b79  add      esp, 4
0x005c8b7c  mov      esi, eax
0x005c8b7e  push     0xc3c78c
0x005c8b83  call     dword ptr [0x715300]
0x005c8b89  mov      eax, dword ptr [ebp - 0x18]
0x005c8b8c  sub      dword ptr [edi + 0x240], eax
0x005c8b92  mov      dword ptr [edi + 0x23c], esi
0x005c8b98  jmp      0x5c8d0c
0x005c8b9d  cmp      dword ptr [0xc3c824], 0
0x005c8ba4  jne      0x5c8bbb
0x005c8ba6  push     0xc3c78c
0x005c8bab  mov      dword ptr [0xc3c824], 1
0x005c8bb5  call     dword ptr [0x71530c]
0x005c8bbb  push     0xc3c78c
0x005c8bc0  call     dword ptr [0x715304]
0x005c8bc6  mov      byte ptr [ebp - 4], 0x10
0x005c8bca  lock inc dword ptr [0xc3c818]
0x005c8bd1  mov      ecx, dword ptr [ebp - 0x10]
0x005c8bd4  xor      edx, edx
0x005c8bd6  lea      ecx, [ecx - 0x1c]
0x005c8bd9  call     0x6ba730
0x005c8bde  test     eax, eax
0x005c8be0  jne      0x5c8c03
0x005c8be2  mov      eax, dword ptr [ebp - 0x10]
0x005c8be5  add      eax, -0x1c
0x005c8be8  mov      ecx, dword ptr [eax + 0x14]
0x005c8beb  mov      dword ptr [ebp - 0x20], ecx
0x005c8bee  add      ecx, 0x1c
0x005c8bf1  add      ecx, eax
0x005c8bf3  mov      dword ptr [ebp - 0x1c], ecx
0x005c8bf6  mov      edx, ecx
0x005c8bf8  mov      ecx, eax
0x005c8bfa  call     0x6ba730
0x005c8bff  test     eax, eax
0x005c8c01  je       0x5c8c49
0x005c8c03  mov      ecx, dword ptr [0xc3c7d4]
0x005c8c09  test     ecx, ecx
0x005c8c0b  je       0x5c8c2a
0x005c8c0d  push     eax
0x005c8c0e  push     dword ptr [ebp - 0x10]
0x005c8c11  push     0x7365ac
0x005c8c16  push     ecx
0x005c8c17  call     0x405ab0
0x005c8c1c  push     dword ptr [0xc3c7d4]
0x005c8c22  call     0x6de2c7
0x005c8c27  add      esp, 0x14
0x005c8c2a  cmp      byte ptr [0xc3c828], 0
0x005c8c31  je       0x5c8cd9
0x005c8c37  push     0
0x005c8c39  push     0
0x005c8c3b  push     1
0x005c8c3d  push     0xc000008c
0x005c8c42  call     esi
0x005c8c44  jmp      0x5c8cd9
0x005c8c49  mov      ecx, dword ptr [ebp - 0x10]
0x005c8c4c  mov      edx, dword ptr [ecx - 0x14]
0x005c8c4f  lea      esi, [ecx - 0x1c]
0x005c8c52  test     edx, edx
0x005c8c54  je       0x5c8c5c
0x005c8c56  mov      eax, dword ptr [esi + 4]
0x005c8c59  mov      dword ptr [edx + 4], eax
0x005c8c5c  mov      edx, dword ptr [esi + 4]
0x005c8c5f  test     edx, edx
0x005c8c61  je       0x5c8c69
0x005c8c63  mov      eax, dword ptr [esi + 8]
0x005c8c66  mov      dword ptr [edx + 8], eax
0x005c8c69  cmp      esi, dword ptr [0xc3c81c]
0x005c8c6f  jne      0x5c8c79
0x005c8c71  mov      eax, dword ptr [esi + 4]
0x005c8c74  mov      dword ptr [0xc3c81c], eax
0x005c8c79  push     dword ptr [ebp - 0x20]
0x005c8c7c  push     0xdfdfdfdf
0x005c8c81  push     ecx
0x005c8c82  call     0x6d0560
0x005c8c87  mov      eax, dword ptr [ebp - 0x1c]
0x005c8c8a  add      esp, 0xc
0x005c8c8d  cmp      byte ptr [0x77248f], 0
0x005c8c94  mov      dword ptr [esi], 0xdfdfdfdf
0x005c8c9a  mov      dword ptr [esi + 0x18], 0xdfdfdfdf
0x005c8ca1  mov      dword ptr [eax], 0xdfdfdfdf
0x005c8ca7  je       0x5c8cd0
0x005c8ca9  cmp      byte ptr [0xc1c788], 0
0x005c8cb0  je       0x5c8cd0
0x005c8cb2  mov      ecx, dword ptr [0xc3c7cc]
0x005c8cb8  cmp      ecx, esi
0x005c8cba  ja       0x5c8cd0
0x005c8cbc  mov      eax, dword ptr [0xc3c7d0]
0x005c8cc1  add      eax, ecx
0x005c8cc3  cmp      eax, esi
0x005c8cc5  jbe      0x5c8cd0
0x005c8cc7  mov      ecx, esi
0x005c8cc9  call     0x6b8c20
0x005c8cce  jmp      0x5c8cd9
0x005c8cd0  push     esi
0x005c8cd1  call     0x6df631
0x005c8cd6  add      esp, 4
0x005c8cd9  mov      esi, dword ptr [0x715300]
0x005c8cdf  push     0xc3c78c
0x005c8ce4  call     esi
0x005c8ce6  push     0xc3c78c
0x005c8ceb  call     esi
0x005c8ced  xor      esi, esi
0x005c8cef  mov      dword ptr [edi + 0x23c], esi
0x005c8cf5  mov      eax, dword ptr [ebp - 0x18]
0x005c8cf8  sub      dword ptr [edi + 0x240], eax
0x005c8cfe  jmp      0x5c8d0c
0x005c8d00  jle      0x5c8d0c
0x005c8d02  mov      dword ptr [edi + 0x240], 0
0x005c8d0c  lea      eax, [edi + 0x6c]
0x005c8d0f  mov      dword ptr [edi + 0x244], 0
0x005c8d19  xor      esi, esi
0x005c8d1b  mov      edi, eax
0x005c8d1d  nop      dword ptr [eax]
0x005c8d20  cmp      esi, 0xf
0x005c8d23  ja       0x5c8d2a
0x005c8d25  lea      eax, [edi + esi*4]
0x005c8d28  jmp      0x5c8d3d
0x005c8d2a  push     0
0x005c8d2c  push     0
0x005c8d2e  push     1
0x005c8d30  push     0xc000008c
0x005c8d35  call     dword ptr [0x715340]
0x005c8d3b  mov      eax, edi
0x005c8d3d  inc      esi
0x005c8d3e  mov      dword ptr [eax], 0xfffffc18
0x005c8d44  cmp      esi, 0x10
0x005c8d47  jl       0x5c8d20
0x005c8d49  mov      edi, dword ptr [ebp - 0x14]
0x005c8d4c  mov      eax, edi
0x005c8d4e  mov      dword ptr [edi + 0x220], 1
0x005c8d58  mov      dword ptr [edi + 0x224], 0
0x005c8d62  mov      dword ptr [edi + 0x228], 0
0x005c8d6c  mov      dword ptr [edi + 0x22c], 0
0x005c8d76  mov      dword ptr [edi + 0x3ec], 0
0x005c8d80  mov      dword ptr [edi + 0x250], 0xffffffff
0x005c8d8a  mov      dword ptr [edi + 0x2b4], 0
0x005c8d94  mov      dword ptr [edi + 0x2ac], 0
0x005c8d9e  mov      dword ptr [edi + 0x238], 0
0x005c8da8  mov      dword ptr [edi + 0x230], 0
0x005c8db2  mov      dword ptr [edi + 0x2a8], 2
0x005c8dbc  mov      dword ptr [edi + 0x234], 0
0x005c8dc6  mov      dword ptr [edi + 0x3fc], 0xffffffff
0x005c8dd0  mov      dword ptr [edi + 0x400], 0x10000
0x005c8dda  mov      dword ptr [edi + 0x408], 0xfffffffe
0x005c8de4  mov      ecx, dword ptr [ebp - 0xc]
0x005c8de7  mov      dword ptr fs:[0], ecx
0x005c8dee  pop      ecx
0x005c8def  pop      edi
0x005c8df0  pop      esi
0x005c8df1  mov      esp, ebp
0x005c8df3  pop      ebp
0x005c8df4  ret      
