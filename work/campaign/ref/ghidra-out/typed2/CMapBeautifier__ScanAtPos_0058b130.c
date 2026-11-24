
void CMapBeautifier__ScanAtPos(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  CMap *pCVar9;
  CMapCell *pCVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  int *piVar14;
  int *piVar15;
  code *pcVar16;
  CMap *pCVar17;
  undefined8 uVar18;
  undefined4 *local_58;
  int local_54;
  undefined4 *local_50;
  uint local_4c;
  uint local_48;
  int *local_44;
  uint local_40;
  int local_3c;
  CMap *local_38;
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
    iVar11 = DAT_00783650 * 0x40;
    DAT_00ca54cc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar11) = "CMapBeautifier::ScanAtPos()";
    *(int *)(&DAT_00773650 + iVar11) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54c8);
  }
  local_40 = DAT_00ca54cc * 0x40;
  local_50 = &DAT_00ca54cc;
  uVar8 = *(undefined4 *)(&DAT_00773650 + local_40);
  iVar4 = FUN_0043fcc0();
  uVar5 = local_40;
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = *(int *)((int)&DAT_00773654 + local_40);
  if (iVar4 == 0) {
    uVar18 = FUN_006bd180();
    iVar4 = *(int *)((int)&DAT_00773654 + uVar5);
    *(undefined8 *)((int)&DAT_00773658 + uVar5) = uVar18;
  }
  *(int *)((int)&DAT_00773654 + uVar5) = iVar4 + 1;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  local_30 = local_30 & 0xffffff00;
  local_24 = (int *)(PTR_0077241c->cellX0 + 4);
  if ((int)local_24 <= param_1 + -0x10) {
    local_24 = (int *)(param_1 + -0x10);
  }
  local_20 = PTR_0077241c->cellY0 + 4;
  if ((int)local_20 <= (int)(param_2 - 0x10U)) {
    local_20 = param_2 - 0x10U;
  }
  local_2c = (int *)(PTR_0077241c->cellX1 + -4);
  if (param_1 + 0x10 <= (int)local_2c) {
    local_2c = (int *)(param_1 + 0x10);
  }
  local_34 = PTR_0077241c->cellY1 - 4;
  if ((int)(param_2 + 0x10U) <= (int)local_34) {
    local_34 = param_2 + 0x10U;
  }
  iVar4 = FUN_00592f10(PTR_0077241c);
  pcVar16 = RaiseException_exref;
  uVar5 = *(uint *)(iVar4 + 8) >> ((char)param_3 * '\x04' & 0x1fU);
  if (((uVar5 & 8) == 0) && (local_30 = local_30 & 0xff, (uVar5 & 0xf) != 0)) {
    local_30 = 1;
  }
  local_28 = 0;
  local_18 = RaiseException_exref;
  local_38 = *(CMap **)(local_14 + 0x14);
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
      local_38 = *(CMap **)(local_14 + 0x14);
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
    piVar12 = local_2c;
    piVar15 = local_24;
    local_1c = local_58;
    if ((int)local_20 < (int)local_34) {
      do {
        piVar14 = piVar15;
        if ((int)piVar15 < (int)piVar12) {
          local_48 = (local_30 - local_20) * local_40 - (int)piVar15;
          do {
            pCVar9 = PTR_0077241c;
            local_38 = PTR_0077241c;
            local_28 = 0;
            local_44 = (int *)PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= (int)piVar15) {
              local_44 = piVar15;
            }
            uVar5 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= (int)local_30) {
              uVar5 = local_30;
            }
            uVar6 = PTR_0077241c->cellY1 - 1;
            if ((int)uVar5 < PTR_0077241c->cellY1) {
              uVar6 = uVar5;
            }
            piVar12 = (int *)(PTR_0077241c->cellX1 + -1);
            if ((int)local_44 < PTR_0077241c->cellX1) {
              piVar12 = local_44;
            }
            iVar4 = (int)(uVar6 * PTR_0077241c->mapWidth + (int)piVar12) %
                    PTR_0077241c->cellCountTotal;
            if ((iVar4 < 0) || (PTR_0077241c->cellCount <= iVar4)) {
              (*local_18)(0xc000008c,1,0,0);
              pCVar10 = pCVar9->cells;
            }
            else {
              pCVar10 = PTR_0077241c->cells + iVar4;
            }
            uVar6 = pCVar10->digMarks >> ((char)param_3 * '\x04' & 0x1fU);
            uVar5 = local_28;
            if (((uVar6 & 8) == 0) && ((uVar6 & 0xf) != 0)) {
              uVar5 = 1;
            }
            iVar4 = local_48 + (int)piVar15;
            if ((iVar4 < 0) || (local_3c <= iVar4)) {
              (*local_18)(0xc000008c,1,0,0);
              puVar7 = local_1c;
            }
            else {
              puVar7 = local_1c + iVar4;
            }
            piVar15 = (int *)((int)piVar15 + 1);
            *puVar7 = uVar5;
            piVar12 = local_2c;
            piVar14 = local_24;
          } while ((int)piVar15 < (int)local_2c);
        }
        local_30 = local_30 + 1;
        piVar15 = piVar14;
        pcVar16 = local_18;
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
      uVar8 = 0;
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
      uVar8 = FUN_005fcdf0(param_2);
    }
    uVar5 = FUN_0058a8b0(&local_58,local_40,local_4c,param_1 - (int)local_24,param_2 - local_20,
                         uVar8);
    if (uVar5 != 0xffffffff) {
      local_38 = (CMap *)((int)uVar5 >> 0x18 & 0xff);
      local_44 = (int *)((int)uVar5 >> 0x10 & 0xff);
      local_40 = uVar5 & 0xffff;
      uVar5 = *(uint *)(local_28 + 0x1a8);
      if (uVar5 <= local_40) {
        (*pcVar16)(0xc000008c,1,0,0);
        uVar5 = *(uint *)(local_28 + 0x1a8);
      }
      local_48 = *(int *)(local_28 + 0x1a4);
      local_3c = local_40 * 0x54;
      local_4c = local_48 + local_3c;
      if (uVar5 <= local_40) {
        (*pcVar16)(0xc000008c,1,0,0);
        local_48 = *(int *)(local_28 + 0x1a4);
      }
      iVar4 = (int)local_44 + 2;
      local_28 = *(int *)(local_4c + 0xc) + 2 + local_20 + (int)local_44 & 0xfffffffc;
      local_44 = (int *)((uint)((int)local_24 +
                               (int)(&local_38->field_0x2 + *(int *)(local_3c + 8 + local_48))) &
                        0xfffffffc);
      local_48 = local_20 + iVar4 & 0xfffffffc;
      local_4c = (uint)(&local_38->field_0x2 + (int)local_24) & 0xfffffffc;
      local_2c = (int *)(local_14 + 0x10);
      FUN_00590040(1);
      local_34 = local_2c[1] - 1;
      if ((uint)local_2c[1] <= local_34) {
        (*pcVar16)(0xc000008c,1,0,0);
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
      pcVar16 = local_18;
      *(uint *)(local_30 + 0x10 + *local_2c) = local_40;
      if ((uint)local_2c[1] <= local_34) {
        (*local_18)(0xc000008c,1,0,0);
      }
      *(undefined4 *)(local_30 + 0x14 + *local_2c) = param_3;
      FUN_0058c920(local_34,param_3);
    }
    thunk_FUN_0060fc30(local_1c);
    local_38 = *(CMap **)(local_14 + 0x14);
  }
  if (local_38 != (CMap *)0x0) {
    local_2c = (int *)(*(int *)(DAT_00772400 + 0x6c) % (int)local_38);
    if (*(int **)(local_14 + 0x14) <= local_2c) {
      (*pcVar16)(0xc000008c,1,0,0);
    }
    local_34 = (int)local_2c * 0x18;
    local_44 = (int *)(*(int *)(local_14 + 0x10) + local_34);
    uVar5 = PTR_0077241c->cellX0 + 4;
    local_48 = PTR_0077241c->cellY0 + 4;
    local_4c = *local_44 - 4;
    if ((int)local_48 <= (int)(local_44[1] - 4U)) {
      local_48 = local_44[1] - 4U;
    }
    local_3c = PTR_0077241c->cellX1 + -4;
    if (local_44[2] + 4 <= local_3c) {
      local_3c = local_44[2] + 4;
    }
    pCVar9 = (CMap *)(PTR_0077241c->cellY1 + -4);
    if (local_44[3] + 4 <= (int)pCVar9) {
      pCVar9 = (CMap *)(local_44[3] + 4);
    }
    if ((int)uVar5 <= (int)local_4c) {
      uVar5 = local_4c;
    }
    pCVar17 = PTR_0077241c;
    local_38 = pCVar9;
    if ((int)uVar5 < local_3c) {
      do {
        local_40 = local_48;
        if ((int)local_48 < (int)pCVar9) {
          do {
            uVar6 = pCVar17->cellX0;
            if (pCVar17->cellX0 <= (int)uVar5) {
              uVar6 = uVar5;
            }
            if (pCVar17->cellX1 <= (int)uVar6) {
              uVar6 = pCVar17->cellX1 - 1;
            }
            uVar13 = pCVar17->cellY0;
            if (pCVar17->cellY0 <= (int)local_40) {
              uVar13 = local_40;
            }
            if (pCVar17->cellY1 <= (int)uVar13) {
              uVar13 = pCVar17->cellY1 - 1;
            }
            iVar4 = (int)(pCVar17->mapWidth * uVar13 + uVar6) % pCVar17->cellCountTotal;
            if ((iVar4 < 0) || (pCVar17->cellCount <= iVar4)) {
              (*local_18)(0xc000008c,1,0,0);
              pCVar10 = pCVar17->cells;
              pCVar17 = PTR_0077241c;
            }
            else {
              pCVar10 = pCVar17->cells + iVar4;
            }
            if ((pCVar10->digMarks >> ((byte)(local_44[5] << 2) & 0x1f) & 0xf) != 0)
            goto LAB_0058b97c;
            local_40 = local_40 + 1;
            pCVar9 = local_38;
          } while ((int)local_40 < (int)local_38);
        }
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < local_3c);
    }
    pcVar16 = local_18;
    piVar12 = *(int **)(local_14 + 0x14);
    if (piVar12 <= local_2c) {
      (*local_18)(0xc000008c,1,0,0);
      piVar12 = *(int **)(local_14 + 0x14);
      if (piVar12 <= local_2c) {
        (*pcVar16)(0xc000008c,1,0,0);
        piVar12 = *(int **)(local_14 + 0x14);
      }
    }
    if ((int)local_2c < (int)piVar12 + -1) {
      iVar4 = *(int *)(local_14 + 0x10);
      iVar11 = *(int *)(local_14 + 0x14);
      puVar1 = (undefined4 *)(iVar4 + -0x18 + iVar11 * 0x18);
      uVar8 = puVar1[1];
      uVar2 = puVar1[2];
      uVar3 = puVar1[3];
      puVar7 = (undefined4 *)(iVar4 + local_34);
      *puVar7 = *puVar1;
      puVar7[1] = uVar8;
      puVar7[2] = uVar2;
      puVar7[3] = uVar3;
      *(undefined8 *)(iVar4 + 0x10 + local_34) = *(undefined8 *)(iVar4 + -8 + iVar11 * 0x18);
      piVar12 = *(int **)(local_14 + 0x14);
    }
    *(int *)(local_14 + 0x14) = (int)piVar12 + -1;
  }
LAB_0058b97c:
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

