
undefined4 FUN_0058a510(undefined4 param_1,int param_2,int param_3)

{
  CMap *this;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  int in_ECX;
  int iVar8;
  uint uVar9;
  
  if (((((*(int *)(in_ECX + 0x54) != 0) || (*(int *)(in_ECX + 0x50) != 0)) ||
       (*(int *)(in_ECX + 0x5c) != 0)) || (*(int *)(in_ECX + 0x58) != 0)) &&
     (uVar2 = FUN_00583080(param_1), uVar2 != 0xffffffff)) {
    uVar9 = *(uint *)(in_ECX + 0x1a8);
    if (uVar9 <= uVar2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar9 = *(uint *)(in_ECX + 0x1a8);
    }
    iVar8 = *(int *)(in_ECX + 0x1a4);
    iVar4 = iVar8 + uVar2 * 0x54;
    if (uVar9 <= uVar2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar8 = *(int *)(in_ECX + 0x1a4);
    }
    uVar3 = param_2 + *(int *)(in_ECX + 0x50);
    iVar4 = *(int *)(iVar4 + 0xc) + *(int *)(in_ECX + 0x54) + param_3;
    uVar9 = *(int *)(in_ECX + 0x54) + param_3;
    iVar8 = *(int *)(uVar2 * 0x54 + 8 + iVar8) + *(int *)(in_ECX + 0x50) + param_2;
    if (((((uVar9 | uVar3) & 3) == 0) && (PTR_0077241c->cellX0 + 8 <= (int)uVar3)) &&
       ((PTR_0077241c->cellY0 + 8 <= (int)uVar9 &&
        ((iVar8 < PTR_0077241c->cellX1 + -8 &&
         (this = PTR_0077241c, iVar4 < PTR_0077241c->cellY1 + -8)))))) {
      do {
        uVar1 = uVar3;
        if (iVar4 <= (int)uVar9) {
          uVar6 = FUN_0058ef60();
          puVar7 = (uint *)FUN_0058ef30(uVar6);
          *puVar7 = uVar2;
          iVar4 = FUN_0058ef30(uVar6);
          *(int *)(iVar4 + 4) = param_2;
          iVar4 = FUN_0058ef30(uVar6);
          *(int *)(iVar4 + 8) = param_3;
          return 1;
        }
        for (; (int)uVar1 < iVar8; uVar1 = uVar1 + 1) {
          iVar5 = FUN_00592f10(this);
          if ((*(byte *)(iVar5 + 0x13) & 1) != 0) {
            return 0;
          }
          this = PTR_0077241c;
        }
        uVar9 = uVar9 + 1;
      } while( true );
    }
  }
  return 0;
}

