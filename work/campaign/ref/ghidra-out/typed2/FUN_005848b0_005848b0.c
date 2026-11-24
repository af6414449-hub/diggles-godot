
uint FUN_005848b0(uint param_1,uint param_2,uint param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int in_ECX;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  CMap *this;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int local_28;
  int *local_24;
  
  piVar2 = (int *)(param_2 | param_3);
  if (((uint)piVar2 & 3) == 0) {
    if (*(uint *)(in_ECX + 0x1a8) <= param_1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar5 = *(int *)(in_ECX + 0x50);
    iVar3 = param_1 * 0x54 + *(int *)(in_ECX + 0x1a4);
    iVar15 = *(int *)(iVar3 + 8);
    iVar3 = *(int *)(iVar3 + 0xc);
    piVar2 = (int *)(PTR_0077241c->cellX0 + 8);
    if ((int)piVar2 <= (int)(iVar5 + param_2)) {
      iVar9 = param_3 + *(int *)(in_ECX + 0x54);
      piVar2 = (int *)(PTR_0077241c->cellY0 + 8);
      if (((int)piVar2 <= iVar9) &&
         (piVar2 = (int *)(PTR_0077241c->cellX1 + -8),
         (int)(iVar5 + iVar15 + param_2) <= (int)piVar2)) {
        iVar10 = param_3 + *(int *)(in_ECX + 0x54) + iVar3;
        piVar2 = (int *)(PTR_0077241c->cellY1 + -8);
        if (iVar10 <= (int)piVar2) {
          iVar4 = *(int *)(in_ECX + 0x58) - iVar5;
          this = PTR_0077241c;
          if (iVar9 < iVar10) {
            do {
              iVar5 = *(int *)(in_ECX + 0x50);
              iVar10 = param_2 + iVar5;
              if (iVar10 < (int)(iVar15 + iVar5 + param_2)) {
                do {
                  piVar2 = (int *)FUN_00592f10(this);
                  if ((*(byte *)((int)piVar2 + 0x13) & 1) != 0) goto LAB_00584c3c;
                  iVar10 = iVar10 + 1;
                  iVar5 = *(int *)(in_ECX + 0x50);
                  this = PTR_0077241c;
                } while (iVar10 < (int)(iVar15 + iVar5 + param_2));
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < (int)(*(int *)(in_ECX + 0x54) + iVar3 + param_3));
          }
          uVar8 = 0;
          if (-1 < (int)param_3) {
            uVar8 = param_3;
          }
          uVar14 = 0;
          if (-1 < (int)param_2) {
            uVar14 = param_2;
          }
          iVar9 = *(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x54);
          if ((int)(iVar3 + param_3) <= iVar9) {
            iVar9 = iVar3 + param_3;
          }
          iVar5 = *(int *)(in_ECX + 0x58) - iVar5;
          iVar3 = iVar15 + param_2;
          if (iVar5 < (int)(iVar15 + param_2)) {
            iVar3 = iVar5;
          }
          if ((int)uVar8 < iVar9) {
            iVar5 = uVar8 * iVar4;
            uVar11 = uVar8;
            do {
              if ((int)uVar14 < iVar3) {
                iVar15 = iVar5 + uVar14;
                uVar13 = uVar14;
                do {
                  if ((iVar15 < 0) || (*(int *)(in_ECX + 0x88) <= iVar15)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar2 = *(int **)(in_ECX + 0x84);
                  }
                  else {
                    piVar2 = (int *)(*(int *)(in_ECX + 0x84) + iVar15 * 4);
                  }
                  if (*piVar2 != 0) goto LAB_00584c3c;
                  uVar13 = uVar13 + 1;
                  iVar15 = iVar15 + 1;
                } while ((int)uVar13 < iVar3);
              }
              iVar5 = iVar5 + iVar4;
              uVar11 = uVar11 + 1;
            } while ((int)uVar11 < iVar9);
            FUN_00583f60(param_1,param_2,param_3);
            iVar5 = uVar8 * iVar4;
            iVar15 = iVar9 - uVar8;
            do {
              if ((int)uVar14 < iVar3) {
                iVar10 = iVar5 + uVar14;
                iVar12 = iVar10 * 4;
                uVar11 = uVar14;
                do {
                  if ((iVar10 < 0) || (*(int *)(in_ECX + 0x88) <= iVar10)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar2 = *(int **)(in_ECX + 0x84);
                    iVar6 = iVar5 + uVar11;
                    local_24 = piVar2;
                  }
                  else {
                    piVar2 = (int *)((int)*(int **)(in_ECX + 0x84) + iVar12);
                    iVar6 = iVar10;
                    local_24 = *(int **)(in_ECX + 0x84);
                  }
                  if (*piVar2 == 0) {
                    if ((iVar6 < 0) || (*(int *)(in_ECX + 0x88) <= iVar6)) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      puVar7 = *(undefined4 **)(in_ECX + 0x84);
                    }
                    else {
                      puVar7 = (undefined4 *)((int)local_24 + iVar12);
                    }
                    *puVar7 = 2;
                  }
                  uVar11 = uVar11 + 1;
                  iVar12 = iVar12 + 4;
                  iVar10 = iVar10 + 1;
                } while ((int)uVar11 < iVar3);
              }
              iVar5 = iVar5 + iVar4;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
          }
          else {
            FUN_00583f60(param_1,param_2,param_3);
          }
          cVar1 = FUN_00584120();
          if (cVar1 != '\0') {
            piVar2 = (int *)(in_ECX + 0x184);
            *(int *)(in_ECX + 0xa0) = *(int *)(in_ECX + 0xa0) + (iVar3 - uVar14) * (iVar9 - uVar8);
            uVar8 = FUN_0058ef60();
            if (*(uint *)(in_ECX + 0x188) <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar5 = uVar8 * 0x10;
            *(uint *)(iVar5 + *piVar2) = param_1;
            if (*(uint *)(in_ECX + 0x188) <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(uint *)(iVar5 + 4 + *piVar2) = *(int *)(in_ECX + 0x50) + param_2;
            if (*(uint *)(in_ECX + 0x188) <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(uint *)(iVar5 + 8 + *piVar2) = *(int *)(in_ECX + 0x54) + param_3;
            if (*(uint *)(in_ECX + 0x188) <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar15 = *piVar2;
            *(undefined1 *)(iVar5 + 0xc + iVar15) = 1;
            return CONCAT31((int3)((uint)iVar15 >> 8),1);
          }
          if ((int)uVar8 < iVar9) {
            iVar5 = uVar8 * iVar4;
            iVar9 = iVar9 - uVar8;
            do {
              if ((int)uVar14 < iVar3) {
                iVar10 = uVar14 + iVar5;
                local_28 = iVar3 - uVar14;
                iVar15 = iVar10 * 4;
                do {
                  if ((iVar10 < 0) || (*(int *)(in_ECX + 0x88) <= iVar10)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    puVar7 = *(undefined4 **)(in_ECX + 0x84);
                  }
                  else {
                    puVar7 = (undefined4 *)(*(int *)(in_ECX + 0x84) + iVar15);
                  }
                  iVar15 = iVar15 + 4;
                  *puVar7 = 0;
                  iVar10 = iVar10 + 1;
                  local_28 = local_28 + -1;
                } while (local_28 != 0);
              }
              iVar5 = iVar5 + iVar4;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          piVar2 = (int *)FUN_00583f60(param_1,param_2,param_3);
        }
      }
    }
  }
LAB_00584c3c:
  return (uint)piVar2 & 0xffffff00;
}

