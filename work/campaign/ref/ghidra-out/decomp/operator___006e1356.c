
/* Library Function - Single Match
    public: int __thiscall <lambda_22ebabd17bc4fa466a2aca6d8deb888d>::operator()(void)const 
   
   Library: Visual Studio 2019 Release */

int __thiscall
<lambda_22ebabd17bc4fa466a2aca6d8deb888d>::operator()
          (<lambda_22ebabd17bc4fa466a2aca6d8deb888d> *this)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  
  puVar5 = (uint *)**(int **)this;
  if (puVar5 == (uint *)0x0) {
LAB_006e1477:
    iVar3 = -1;
  }
  else {
    bVar4 = (byte)DAT_0076700c & 0x1f;
    puVar10 = (uint *)((puVar5[1] ^ DAT_0076700c) >> bVar4 |
                      (puVar5[1] ^ DAT_0076700c) << 0x20 - bVar4);
    puVar8 = (uint *)((puVar5[2] ^ DAT_0076700c) >> bVar4 |
                     (puVar5[2] ^ DAT_0076700c) << 0x20 - bVar4);
    uVar7 = (*puVar5 ^ DAT_0076700c) >> bVar4 | (*puVar5 ^ DAT_0076700c) << 0x20 - bVar4;
    uVar1 = uVar7;
    if (puVar10 == puVar8) {
      uVar9 = (int)((int)puVar8 - uVar7) >> 2;
      uVar6 = 0x200;
      if (uVar9 < 0x201) {
        uVar6 = uVar9;
      }
      uVar6 = uVar6 + uVar9;
      if (uVar6 == 0) {
        uVar6 = 0x20;
      }
      if (uVar6 < uVar9) {
LAB_006e13d3:
        uVar6 = uVar9 + 4;
        uVar1 = __recalloc_base(uVar7,uVar6,4);
        FID_conflict__free((void *)0x0);
        if (uVar1 == 0) goto LAB_006e1477;
      }
      else {
        uVar1 = __recalloc_base(uVar7,uVar6,4);
        FID_conflict__free((void *)0x0);
        if (uVar1 == 0) goto LAB_006e13d3;
      }
      uVar7 = DAT_0076700c;
      puVar10 = (uint *)(uVar1 + uVar9 * 4);
      puVar8 = (uint *)(uVar1 + uVar6 * 4);
      uVar6 = ~-(uint)(puVar8 < puVar10) & (uint)((int)puVar8 + (3 - (int)puVar10)) >> 2;
      if (uVar6 != 0) {
        uVar9 = 0;
        puVar5 = puVar10;
        do {
          uVar9 = uVar9 + 1;
          *puVar5 = uVar7;
          puVar5 = puVar5 + 1;
        } while (uVar9 != uVar6);
      }
    }
    uVar7 = __crt_fast_encode_pointer<>(**(undefined4 **)(this + 4));
    *puVar10 = uVar7;
    uVar2 = __crt_fast_encode_pointer<>(uVar1);
    *(undefined4 *)**(undefined4 **)this = uVar2;
    uVar2 = __crt_fast_encode_pointer<>(puVar10 + 1);
    *(undefined4 *)(**(int **)this + 4) = uVar2;
    uVar2 = __crt_fast_encode_pointer<>(puVar8);
    *(undefined4 *)(**(int **)this + 8) = uVar2;
    iVar3 = 0;
  }
  return iVar3;
}

