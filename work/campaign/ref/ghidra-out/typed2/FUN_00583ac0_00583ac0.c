
void FUN_00583ac0(int *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  iVar2 = PTR_0077241c->cellX0 + 8;
  iVar7 = *param_1;
  if (*param_1 < iVar2) {
    iVar7 = iVar2;
  }
  iVar3 = PTR_0077241c->cellY0 + 8;
  iVar2 = param_1[1];
  if (param_1[1] < iVar3) {
    iVar2 = iVar3;
  }
  uVar4 = PTR_0077241c->cellX1 - 8;
  uVar6 = param_1[2];
  if ((int)uVar4 < param_1[2]) {
    uVar6 = uVar4;
  }
  uVar5 = PTR_0077241c->cellY1 - 8;
  uVar4 = param_1[3];
  if ((int)uVar5 < param_1[3]) {
    uVar4 = uVar5;
  }
  uVar8 = iVar7 + 3U & 0xfffffffc;
  uVar5 = iVar2 + 3U & 0xfffffffc;
  if (param_2 == '\0') {
    iVar7 = *(int *)(in_ECX + 0x50);
    uVar9 = 0;
    iVar2 = *(int *)(in_ECX + 0x54);
    if (0 < *(int *)(in_ECX + 0x198)) {
      iVar3 = 0;
      bVar10 = *(int *)(in_ECX + 0x198) != 0;
      do {
        if (!bVar10) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar1 = (int *)(*(int *)(in_ECX + 0x194) + 4 + iVar3);
        *piVar1 = *piVar1 - (uVar8 - iVar7);
        if (*(uint *)(in_ECX + 0x198) <= uVar9) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        uVar9 = uVar9 + 1;
        piVar1 = (int *)(*(int *)(in_ECX + 0x194) + 8 + iVar3);
        *piVar1 = *piVar1 - (uVar5 - iVar2);
        iVar3 = iVar3 + 0x10;
        bVar10 = uVar9 < *(uint *)(in_ECX + 0x198);
      } while ((int)uVar9 < (int)*(uint *)(in_ECX + 0x198));
    }
  }
  *(uint *)(in_ECX + 0x50) = uVar8;
  *(uint *)(in_ECX + 0x54) = uVar5;
  *(uint *)(in_ECX + 0x58) = uVar6 & 0xfffffffc;
  *(uint *)(in_ECX + 0x5c) = uVar4 & 0xfffffffc;
  return;
}

