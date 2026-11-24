
void CMapBeautifier__ScanAtPos(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  code *pcVar15;
  undefined8 uVar16;
  undefined4 *local_58;
  int local_54;
  undefined4 *local_50;
  uint local_4c;
  uint local_48;
  int *local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int *local_2c;
  uint local_28;
  int *local_24;
  uint local_20;
  undefined4 *local_1c;
  code *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007065d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca54c8) &&
     (FUN_006cebf4(&DAT_00ca54c8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca54c8 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca54cc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "CMapBeautifier::ScanAtPos()";
    *(int *)(&DAT_00773650 + iVar10) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54c8);
  }
  local_40 = DAT_00ca54cc * 0x40;
  local_50 = &DAT_00ca54cc;
  uVar9 = *(undefined4 *)(&DAT_00773650 + local_40);
  iVar4 = FUN_0043fcc0();
  uVar5 = local_40;
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar9;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = *(int *)((int)&DAT_00773654 + local_40);
  if (iVar4 == 0) {
    uVar16 = FUN_006bd180();
    iVar4 = *(int *)((int)&DAT_00773654 + uVar5);
    *(undefined8 *)((int)&DAT_00773658 + uVar5) = uVar16;
  }
  *(int *)((int)&DAT_00773654 + uVar5) = iVar4 + 1;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  local_30 = local_30 & 0xffffff00;
  local_24 = (int *)(*(int *)(DAT_0077241c + 0x84) + 4);
  if ((int)local_24 <= param_1 + -0x10) {
    local_24 = (int *)(param_1 + -0x10);
  }
  local_20 = *(int *)(DAT_0077241c + 0x88) + 4;
  if ((int)local_20 <= (int)(param_2 - 0x10U)) {
    local_20 = param_2 - 0x10U;
  }
  local_2c = (int *)(*(int *)(DAT_0077241c + 0x8c) + -4);
  if (param_1 + 0x10 <= (int)local_2c) {
    local_2c = (int *)(param_1 + 0x10);
  }
  local_34 = *(int *)(DAT_0077241c + 0x90) - 4;
  if ((int)(param_2 + 0x10U) <= (int)local_34) {
    local_34 = param_2 + 0x10U;
  }
  iVar4 = FUN_00592f10(param_1,param_2);
  pcVar15 = RaiseException_exref;
  uVar5 = *(uint *)(iVar4 + 8) >> ((char)param_3 * '\x04' & 0x1fU);
  if (((uVar5 & 8) == 0) && (local_30 = local_30 & 0xff, (uVar5 & 0xf) != 0)) {
    local_30 = 1;
  }
  local_28 = 0;
  local_18 = RaiseException_exref;
  local_38 = *(uint *)(local_14 + 0x14);
  if (0 < (int)local_38) {
    local_1c = (undefined4 *)0x0;
    do {
      if (*(uint *)(local_14 + 0x14) <= local_28) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = *(int *)(local_14 + 0x10);
      if (*(int *)((int)local_1c + iVar4) <= param_1) {
        if (*(uint *)(local_14 + 0x14) <= local_28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = *(int *)(local_14 + 0x10);
        }
        if (param_1 <= *(int *)((int)local_1c + iVar4 + 8)) {
          if (*(uint *)(local_14 + 0x14) <= local_28) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *(int *)(local_14 + 0x10);
          }
          if (*(int *)((int)local_1c + iVar4 + 4) <= param_2) {
            if (*(uint *)(local_14 + 0x14) <= local_28) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar4 = *(int *)(local_14 + 0x10);
            }
            if (param_2 <= *(int *)((int)local_1c + iVar4 + 0xc)) goto LAB_0058b97c;
          }
        }
      }
      local_28 = local_28 + 1;
      local_1c = local_1c + 6;
      local_38 = *(uint *)(local_14 + 0x14);
    } while ((int)local_28 < (int)local_38);
  }
  if ((char)local_30 != '\0') {
    local_58 = (undefined4 *)0x0;
    local_4c = local_34 - local_20;
    local_40 = (int)local_2c - (int)local_24;
    local_3c = local_4c * local_40;
    local_8._0_1_ = 1;
    thunk_FUN_0060fc30(0);
    local_54 = local_3c;
    local_58 = (undefined4 *)FUN_006ba810(0x5e);
    local_30 = local_20;
    piVar11 = local_2c;
    piVar14 = local_24;
    local_1c = local_58;
    if ((int)local_20 < (int)local_34) {
      do {
        piVar13 = piVar14;
        if ((int)piVar14 < (int)piVar11) {
          local_48 = (local_30 - local_20) * local_40 - (int)piVar14;
          do {
            uVar5 = DAT_0077241c;
            local_38 = DAT_0077241c;
            local_28 = 0;
            local_44 = *(int **)(DAT_0077241c + 0x84);
            if ((int)*(int **)(DAT_0077241c + 0x84) <= (int)piVar14) {
              local_44 = piVar14;
            }
            uVar7 = *(uint *)(DAT_0077241c + 0x88);
            if ((int)*(uint *)(DAT_0077241c + 0x88) <= (int)local_30) {
              uVar7 = local_30;
            }
            uVar6 = *(int *)(DAT_0077241c + 0x90) - 1;
            if ((int)uVar7 < *(int *)(DAT_0077241c + 0x90)) {
              uVar6 = uVar7;
            }
            piVar11 = (int *)(*(int *)(DAT_0077241c + 0x8c) + -1);
            if ((int)local_44 < *(int *)(DAT_0077241c + 0x8c)) {
              piVar11 = local_44;
            }
            iVar4 = (int)(uVar6 * *(int *)(DAT_0077241c + 0x44) + (int)piVar11) %
                    *(int *)(DAT_0077241c + 0x4c);
            if ((iVar4 < 0) || (*(int *)(DAT_0077241c + 0x18) <= iVar4)) {
              (*local_18)(0xc000008c,1,0,0);
              iVar4 = *(int *)(uVar5 + 0x14);
            }
            else {
              iVar4 = iVar4 * 0x7c + *(int *)(DAT_0077241c + 0x14);
            }
            uVar7 = *(uint *)(iVar4 + 8) >> ((char)param_3 * '\x04' & 0x1fU);
            uVar5 = local_28;
            if (((uVar7 & 8) == 0) && ((uVar7 & 0xf) != 0)) {
              uVar5 = 1;
            }
            iVar4 = local_48 + (int)piVar14;
            if ((iVar4 < 0) || (local_3c <= iVar4)) {
              (*local_18)(0xc000008c,1,0,0);
              puVar8 = local_1c;
            }
            else {
              puVar8 = local_1c + iVar4;
            }
            piVar14 = (int *)((int)piVar14 + 1);
            *puVar8 = uVar5;
            piVar11 = local_2c;
            piVar13 = local_24;
          } while ((int)piVar14 < (int)local_2c);
        }
        local_30 = local_30 + 1;
        piVar14 = piVar13;
        pcVar15 = local_18;
      } while ((int)local_30 < (int)local_34);
    }
    local_28 = DAT_00772414;
    if (DAT_00772414 == 0) {
      local_48 = FUN_006ba810(0xd03);
      local_8._0_1_ = 2;
      if (local_48 == 0) {
        DAT_00772414 = 0;
      }
      else {
        DAT_00772414 = FUN_00581470();
      }
      local_8._0_1_ = 1;
    }
    local_28 = DAT_00772414;
    if (DAT_00772474 == 0) {
      local_48 = FUN_006ba810(0x189);
      local_8._0_1_ = 3;
      if (local_48 == 0) {
        DAT_00772474 = 0;
      }
      else {
        DAT_00772474 = FUN_005f7ec0();
      }
      local_8._0_1_ = 1;
    }
    iVar4 = FUN_005fcdf0(param_2);
    if (iVar4 < 0) {
      uVar9 = 0;
    }
    else {
      if (DAT_00772474 == 0) {
        local_48 = FUN_006ba810(0x189);
        local_8._0_1_ = 4;
        if (local_48 == 0) {
          DAT_00772474 = 0;
        }
        else {
          DAT_00772474 = FUN_005f7ec0();
        }
        local_8._0_1_ = 1;
      }
      uVar9 = FUN_005fcdf0(param_2);
    }
    uVar5 = FUN_0058a8b0(&local_58,local_40,local_4c,param_1 - (int)local_24,param_2 - local_20,
                         uVar9);
    if (uVar5 != 0xffffffff) {
      local_38 = (int)uVar5 >> 0x18 & 0xff;
      local_44 = (int *)((int)uVar5 >> 0x10 & 0xff);
      local_40 = uVar5 & 0xffff;
      uVar5 = *(uint *)(local_28 + 0x1a8);
      if (uVar5 <= local_40) {
        (*pcVar15)(0xc000008c,1,0,0);
        uVar5 = *(uint *)(local_28 + 0x1a8);
      }
      local_48 = *(int *)(local_28 + 0x1a4);
      local_3c = local_40 * 0x54;
      local_4c = local_48 + local_3c;
      if (uVar5 <= local_40) {
        (*pcVar15)(0xc000008c,1,0,0);
        local_48 = *(int *)(local_28 + 0x1a4);
      }
      iVar4 = (int)local_44 + 2;
      local_28 = *(int *)(local_4c + 0xc) + 2 + local_20 + (int)local_44 & 0xfffffffc;
      local_44 = (int *)((int)local_24 + local_38 + *(int *)(local_3c + 8 + local_48) + 2 &
                        0xfffffffc);
      local_48 = local_20 + iVar4 & 0xfffffffc;
      local_4c = local_38 + 2 + (int)local_24 & 0xfffffffc;
      local_2c = (int *)(local_14 + 0x10);
      FUN_00590040(1);
      local_34 = local_2c[1] - 1;
      if ((uint)local_2c[1] <= local_34) {
        (*pcVar15)(0xc000008c,1,0,0);
      }
      local_30 = local_34 * 0x18;
      iVar4 = *local_2c;
      *(uint *)(local_30 + iVar4) = local_4c;
      *(uint *)(local_30 + 4 + iVar4) = local_48;
      *(int **)(local_30 + 8 + iVar4) = local_44;
      *(uint *)(local_30 + 0xc + iVar4) = local_28;
      if ((uint)local_2c[1] <= local_34) {
        (*local_18)(0xc000008c,1,0,0);
      }
      pcVar15 = local_18;
      *(uint *)(local_30 + 0x10 + *local_2c) = local_40;
      if ((uint)local_2c[1] <= local_34) {
        (*local_18)(0xc000008c,1,0,0);
      }
      *(undefined4 *)(local_30 + 0x14 + *local_2c) = param_3;
      FUN_0058c920(local_34,param_3);
    }
    thunk_FUN_0060fc30(local_1c);
    local_38 = *(uint *)(local_14 + 0x14);
  }
  if (local_38 != 0) {
    local_2c = (int *)(*(int *)(DAT_00772400 + 0x6c) % (int)local_38);
    if (*(int **)(local_14 + 0x14) <= local_2c) {
      (*pcVar15)(0xc000008c,1,0,0);
    }
    local_34 = (int)local_2c * 0x18;
    local_44 = (int *)(*(int *)(local_14 + 0x10) + local_34);
    uVar5 = *(int *)(DAT_0077241c + 0x84) + 4;
    local_48 = *(int *)(DAT_0077241c + 0x88) + 4;
    local_4c = *local_44 - 4;
    if ((int)local_48 <= (int)(local_44[1] - 4U)) {
      local_48 = local_44[1] - 4U;
    }
    local_3c = *(int *)(DAT_0077241c + 0x8c) + -4;
    if (local_44[2] + 4 <= local_3c) {
      local_3c = local_44[2] + 4;
    }
    uVar7 = *(int *)(DAT_0077241c + 0x90) - 4;
    if ((int)(local_44[3] + 4U) <= (int)uVar7) {
      uVar7 = local_44[3] + 4U;
    }
    if ((int)uVar5 <= (int)local_4c) {
      uVar5 = local_4c;
    }
    uVar6 = DAT_0077241c;
    local_38 = uVar7;
    if ((int)uVar5 < local_3c) {
      do {
        local_40 = local_48;
        if ((int)local_48 < (int)uVar7) {
          do {
            uVar7 = *(uint *)(uVar6 + 0x84);
            if ((int)*(uint *)(uVar6 + 0x84) <= (int)uVar5) {
              uVar7 = uVar5;
            }
            if (*(int *)(uVar6 + 0x8c) <= (int)uVar7) {
              uVar7 = *(int *)(uVar6 + 0x8c) - 1;
            }
            uVar12 = *(uint *)(uVar6 + 0x88);
            if ((int)*(uint *)(uVar6 + 0x88) <= (int)local_40) {
              uVar12 = local_40;
            }
            if (*(int *)(uVar6 + 0x90) <= (int)uVar12) {
              uVar12 = *(int *)(uVar6 + 0x90) - 1;
            }
            iVar4 = (int)(*(int *)(uVar6 + 0x44) * uVar12 + uVar7) % *(int *)(uVar6 + 0x4c);
            if ((iVar4 < 0) || (*(int *)(uVar6 + 0x18) <= iVar4)) {
              (*local_18)(0xc000008c,1,0,0);
              iVar4 = *(int *)(uVar6 + 0x14);
              uVar6 = DAT_0077241c;
            }
            else {
              iVar4 = iVar4 * 0x7c + *(int *)(uVar6 + 0x14);
            }
            if ((*(uint *)(iVar4 + 8) >> ((byte)(local_44[5] << 2) & 0x1f) & 0xf) != 0)
            goto LAB_0058b97c;
            local_40 = local_40 + 1;
            uVar7 = local_38;
          } while ((int)local_40 < (int)local_38);
        }
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < local_3c);
    }
    pcVar15 = local_18;
    piVar11 = *(int **)(local_14 + 0x14);
    if (piVar11 <= local_2c) {
      (*local_18)(0xc000008c,1,0,0);
      piVar11 = *(int **)(local_14 + 0x14);
      if (piVar11 <= local_2c) {
        (*pcVar15)(0xc000008c,1,0,0);
        piVar11 = *(int **)(local_14 + 0x14);
      }
    }
    if ((int)local_2c < (int)piVar11 + -1) {
      iVar4 = *(int *)(local_14 + 0x10);
      iVar10 = *(int *)(local_14 + 0x14);
      puVar1 = (undefined4 *)(iVar4 + -0x18 + iVar10 * 0x18);
      uVar9 = puVar1[1];
      uVar2 = puVar1[2];
      uVar3 = puVar1[3];
      puVar8 = (undefined4 *)(iVar4 + local_34);
      *puVar8 = *puVar1;
      puVar8[1] = uVar9;
      puVar8[2] = uVar2;
      puVar8[3] = uVar3;
      *(undefined8 *)(iVar4 + 0x10 + local_34) = *(undefined8 *)(iVar4 + -8 + iVar10 * 0x18);
      piVar11 = *(int **)(local_14 + 0x14);
    }
    *(int *)(local_14 + 0x14) = (int)piVar11 + -1;
  }
LAB_0058b97c:
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

