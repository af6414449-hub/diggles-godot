
uint FUN_00584d10(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int in_ECX;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (*(uint *)(in_ECX + 0x188) <= param_1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar8 = param_1 * 0x10;
  uVar4 = *(uint *)(iVar8 + *(int *)(in_ECX + 0x184));
  if (*(uint *)(in_ECX + 0x1a8) <= uVar4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  uVar3 = *(uint *)(in_ECX + 0x188);
  iVar12 = uVar4 * 0x54 + *(int *)(in_ECX + 0x1a4);
  if (uVar3 <= param_1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    uVar3 = *(uint *)(in_ECX + 0x188);
  }
  iVar11 = *(int *)(in_ECX + 0x184);
  iVar1 = *(int *)(iVar11 + 4 + iVar8);
  if (uVar3 <= param_1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar11 = *(int *)(in_ECX + 0x184);
  }
  iVar11 = *(int *)(iVar8 + 8 + iVar11);
  uVar4 = PTR_0077241c->cellY0 + 8;
  if (((int)uVar4 <= iVar11) && (uVar4 = PTR_0077241c->cellX0 + 8, (int)uVar4 <= iVar1)) {
    iVar9 = iVar1 + *(int *)(iVar12 + 8);
    uVar4 = PTR_0077241c->cellX1 - 8;
    if (iVar9 <= (int)uVar4) {
      iVar12 = *(int *)(iVar12 + 0xc) + iVar11;
      uVar4 = PTR_0077241c->cellY1 - 8;
      if (iVar12 <= (int)uVar4) {
        iVar10 = *(int *)(in_ECX + 0x58) - *(int *)(in_ECX + 0x50);
        for (; iVar2 = iVar1, iVar11 < iVar12; iVar11 = iVar11 + 1) {
          for (; iVar2 < iVar9; iVar2 = iVar2 + 1) {
            iVar5 = ((iVar11 - *(int *)(in_ECX + 0x54)) * iVar10 - *(int *)(in_ECX + 0x50)) + iVar2;
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x88) <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar6 = *(int **)(in_ECX + 0x84);
              piVar7 = piVar6;
            }
            else {
              piVar6 = *(int **)(in_ECX + 0x84) + iVar5;
              piVar7 = *(int **)(in_ECX + 0x84);
            }
            if (*piVar6 != 0) {
              iVar5 = ((iVar11 - *(int *)(in_ECX + 0x54)) * iVar10 - *(int *)(in_ECX + 0x50)) +
                      iVar2;
              if ((iVar5 < 0) || (*(int *)(in_ECX + 0x88) <= iVar5)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar7 = *(int **)(in_ECX + 0x84);
              }
              else {
                piVar7 = piVar7 + iVar5;
              }
              *piVar7 = 0;
            }
          }
        }
        uVar4 = *(uint *)(in_ECX + 0x188);
        if (uVar4 <= param_1) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar4 = *(uint *)(in_ECX + 0x188);
          if (uVar4 <= param_1) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = *(uint *)(in_ECX + 0x188);
          }
        }
        if ((int)param_1 < (int)(uVar4 - 1)) {
          iVar8 = iVar8 + *(int *)(in_ECX + 0x184);
          FUN_006d1b90(iVar8,iVar8 + 0x10,(uVar4 - param_1) * 0x10 + -0x10);
          uVar4 = *(uint *)(in_ECX + 0x188);
        }
        *(uint *)(in_ECX + 0x188) = uVar4 - 1;
        return CONCAT31((int3)(uVar4 - 1 >> 8),1);
      }
    }
  }
  return uVar4 & 0xffffff00;
}

