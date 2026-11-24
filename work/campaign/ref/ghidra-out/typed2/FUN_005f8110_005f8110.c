
void FUN_005f8110(void)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *local_20;
  int *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00709ab5;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  if (0 < in_ECX[1]) {
    local_14 = 0;
    do {
      local_8 = 0xffffffff;
      piVar2 = (int *)FUN_006ba810(0x19,uVar1);
      piVar2[1] = 4;
      *(undefined2 *)(piVar2 + 3) = 0x6f;
      piVar2[2] = 1;
      *piVar2 = 1;
      local_8 = 0;
      if ((uint)in_ECX[1] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = piVar2;
      if (*(char *)(local_14 + 0xc + *in_ECX) != '\0') {
        piVar3 = (int *)FUN_006ba810(0x19,uVar1);
        piVar3[1] = 4;
        *(undefined2 *)(piVar3 + 3) = 0x78;
        piVar3[2] = 1;
        local_8._0_1_ = 1;
        *piVar3 = 2;
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
          FUN_006ba940();
        }
      }
      local_8 = 3;
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        FUN_006ba940();
      }
      local_14 = local_14 + 0x10;
      local_18 = local_18 + 1;
    } while ((int)local_18 < in_ECX[1]);
  }
  local_18 = 0;
  if (0 < in_ECX[3]) {
    local_14 = 0;
    do {
      local_8 = 0xffffffff;
      piVar2 = (int *)FUN_006ba810(0x19,uVar1);
      piVar2[1] = 4;
      *(undefined2 *)(piVar2 + 3) = 0x6f;
      piVar2[2] = 1;
      *piVar2 = 1;
      local_8 = 4;
      if ((uint)in_ECX[3] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = piVar2;
      if (*(char *)(local_14 + 0x14 + in_ECX[2]) != '\0') {
        piVar3 = (int *)FUN_006ba810(0x19,uVar1);
        piVar3[1] = 4;
        *(undefined2 *)(piVar3 + 3) = 0x78;
        piVar3[2] = 1;
        local_8._0_1_ = 5;
        *piVar3 = 2;
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,6);
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
          FUN_006ba940();
        }
      }
      local_8 = 7;
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        FUN_006ba940();
      }
      local_14 = local_14 + 100;
      local_18 = local_18 + 1;
    } while ((int)local_18 < in_ECX[3]);
  }
  iVar9 = (int)((PTR_0077241c->originX >> 0x1f & 3U) + PTR_0077241c->originX) >> 2;
  iVar4 = (int)(PTR_0077241c->originY + (PTR_0077241c->originY >> 0x1f & 3U)) >> 2;
  iVar6 = iVar4;
  if (iVar4 < in_ECX[0x20] + iVar4) {
    do {
      local_8 = 0xffffffff;
      local_18 = iVar6;
      piVar2 = (int *)FUN_006ba810(0x19,uVar1);
      piVar2[1] = 4;
      *(undefined1 *)(piVar2 + 3) = 0;
      piVar2[2] = 0;
      *piVar2 = 1;
      local_8._1_3_ = 0;
      uVar10 = iVar6;
      local_14 = iVar9;
      if (iVar9 < in_ECX[0x1f] + iVar9) {
        do {
          local_8._0_1_ = 8;
          piVar3 = (int *)FUN_006ba810(0x19);
          piVar3[1] = 4;
          *(undefined2 *)(piVar3 + 3) = 0x30;
          piVar3[2] = 1;
          *piVar3 = 1;
          local_8._0_1_ = 9;
          iVar6 = local_14 -
                  ((int)(PTR_0077241c->originX + (PTR_0077241c->originX >> 0x1f & 3U)) >> 2);
          iVar8 = local_18 -
                  ((int)(PTR_0077241c->originY + (PTR_0077241c->originY >> 0x1f & 3U)) >> 2);
          local_1c = piVar3;
          if ((((iVar6 < 0) || (iVar7 = in_ECX[0x1f], iVar7 <= iVar6)) || (iVar8 < 0)) ||
             (in_ECX[0x20] <= iVar8)) {
LAB_005f8586:
            piVar5 = (int *)FUN_006ba810(0x19);
            piVar5[1] = 4;
            *(undefined2 *)(piVar5 + 3) = 0x58;
            piVar5[2] = 1;
            local_8._0_1_ = 10;
            *piVar5 = 2;
            *piVar3 = *piVar3 + -1;
            local_1c = piVar5;
            if (*piVar3 == 0) {
              FUN_006ba940();
            }
            local_8 = CONCAT31(local_8._1_3_,0xb);
LAB_005f85d3:
            *piVar5 = *piVar5 + -1;
            if (*piVar5 == 0) {
              FUN_006ba940();
            }
            local_8._0_1_ = 9;
          }
          else {
            iVar6 = iVar7 * iVar8 + iVar6;
            if ((iVar6 < 0) || (in_ECX[0xd] <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar5 = (int *)in_ECX[0xc];
              iVar7 = in_ECX[0x1f];
              local_20 = piVar5;
            }
            else {
              piVar5 = (int *)in_ECX[0xc] + iVar6;
              local_20 = (int *)in_ECX[0xc];
            }
            if (*piVar5 == 1) goto LAB_005f8586;
            iVar6 = local_14 -
                    ((int)(PTR_0077241c->originX + (PTR_0077241c->originX >> 0x1f & 3U)) >> 2);
            iVar8 = local_18 -
                    ((int)(PTR_0077241c->originY + (PTR_0077241c->originY >> 0x1f & 3U)) >> 2);
            piVar5 = piVar3;
            if (((-1 < iVar6) && (iVar6 < iVar7)) && ((-1 < iVar8 && (iVar8 < in_ECX[0x20])))) {
              iVar6 = iVar7 * iVar8 + iVar6;
              if ((iVar6 < 0) || (in_ECX[0xd] <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_20 = (int *)in_ECX[0xc];
              }
              else {
                local_20 = local_20 + iVar6;
              }
              if (*local_20 != 2) goto LAB_005f85e3;
              piVar5 = (int *)FUN_006ba810(0x19);
              piVar5[1] = 4;
              *(undefined2 *)(piVar5 + 3) = 0x52;
              piVar5[2] = 1;
              local_8._0_1_ = 0xc;
              *piVar5 = 2;
              *piVar3 = *piVar3 + -1;
              local_1c = piVar5;
              if (*piVar3 == 0) {
                FUN_006ba940();
              }
              local_8 = CONCAT31(local_8._1_3_,0xd);
              goto LAB_005f85d3;
            }
          }
LAB_005f85e3:
          FUN_006b9290(&local_1c);
          local_8._0_1_ = 0xe;
          *piVar5 = *piVar5 + -1;
          if (*piVar5 == 0) {
            FUN_006ba940();
          }
          local_14 = local_14 + 1;
          uVar10 = local_18;
        } while (local_14 < in_ECX[0x1f] + iVar9);
      }
      local_8 = 0xf;
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
        FUN_006ba940();
      }
      iVar6 = uVar10 + 1;
    } while ((int)(uVar10 + 1) < in_ECX[0x20] + iVar4);
  }
  ExceptionList = local_10;
  return;
}

