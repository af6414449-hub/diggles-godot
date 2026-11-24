
undefined4 FUN_00667b20(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  CHeightBlockArray *pCVar1;
  uint uVar2;
  int iVar3;
  undefined **ppuVar4;
  int *piVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  float *pfVar8;
  int *piVar9;
  int iVar10;
  ushort *puVar11;
  code *pcVar12;
  int *piVar13;
  int *piVar14;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  undefined4 *local_5c;
  uint local_58;
  int local_54;
  int *local_50;
  float local_4c;
  float local_48;
  float local_44;
  int *local_40;
  uint local_3c;
  int *local_38;
  CHeightBlockArray *local_34;
  int *local_30;
  int local_2c;
  int *local_28;
  uint local_24;
  int *local_20;
  uint local_1c;
  uint local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f855;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004298b0(param_3,param_4);
  local_8 = 0;
  local_28 = (int *)FUN_006ba810(0x19,uVar2);
  local_28[1] = 0x14;
  local_28[2] = -1;
  *local_28 = 0;
  *(undefined1 *)(local_28 + 3) = 0;
  local_28[3] = 0x61666564;
  local_28[4] = 0x2e746c75;
  local_28[5] = 0x6a626f;
  local_28[2] = 0xb;
  *local_28 = 1;
  local_8._0_1_ = 1;
  local_20 = (int *)0x0;
  local_24 = 0x20;
  local_18 = 0;
  local_1c = 0x20;
  pcVar12 = TclFreeObj_exref;
  local_14 = local_28;
  if (param_3 < 2) goto LAB_00667deb;
  if (local_54 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_5c;
    if (local_58 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_5c;
    }
  }
  else {
    if (local_58 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_5c + 1;
  }
  piVar9 = (int *)*puVar6;
  if (piVar9 == (int *)0x0) {
LAB_00667d93:
    local_20 = (int *)0x0;
    if (piVar9 != (int *)0x0) goto LAB_00667c4f;
    local_20 = (int *)0x0;
LAB_00667da3:
    local_18 = 0;
    if (piVar9 != (int *)0x0) goto LAB_00667ca2;
    local_18 = 0;
LAB_00667db3:
    local_1c = 0;
    if (piVar9 != (int *)0x0) goto LAB_00667cf5;
    local_1c = 0;
LAB_00667dc5:
    local_24 = 0;
    pcVar12 = TclFreeObj_exref;
    if (piVar9 == (int *)0x0) goto LAB_00667deb;
  }
  else {
    *piVar9 = *piVar9 + 1;
    iVar3 = Tcl_ListObjIndex(0,piVar9,0,&local_40);
    piVar14 = local_40;
    if (iVar3 == 0) {
      if (local_40 == (int *)0x0) goto LAB_00667d93;
      *local_40 = *local_40 + 1;
      iVar3 = Tcl_GetIntFromObj(0,local_40,&local_40);
      *piVar14 = *piVar14 + -1;
      local_20 = (int *)(-(uint)(iVar3 != 1) & (uint)local_40);
      if (*piVar14 < 1) {
        TclFreeObj(piVar14);
      }
    }
    else {
      local_20 = (int *)0x0;
    }
LAB_00667c4f:
    iVar3 = Tcl_ListObjIndex(0,piVar9,1,&local_40);
    piVar14 = local_40;
    if ((iVar3 != 0) || (local_40 == (int *)0x0)) goto LAB_00667da3;
    *local_40 = *local_40 + 1;
    iVar3 = Tcl_GetIntFromObj(0,local_40,&local_40);
    *piVar14 = *piVar14 + -1;
    local_18 = -(uint)(iVar3 != 1) & (uint)local_40;
    if (*piVar14 < 1) {
      TclFreeObj(piVar14);
    }
LAB_00667ca2:
    iVar3 = Tcl_ListObjIndex(0,piVar9,2,&local_40);
    piVar14 = local_40;
    if ((iVar3 != 0) || (local_40 == (int *)0x0)) goto LAB_00667db3;
    *local_40 = *local_40 + 1;
    iVar3 = Tcl_GetIntFromObj(0,local_40,&local_40);
    *piVar14 = *piVar14 + -1;
    local_1c = -(uint)(iVar3 != 1) & (uint)local_40;
    if (*piVar14 < 1) {
      TclFreeObj(piVar14);
    }
LAB_00667cf5:
    iVar3 = Tcl_ListObjIndex(0,piVar9,3,&local_40);
    piVar14 = local_40;
    if ((iVar3 != 0) || (local_40 == (int *)0x0)) goto LAB_00667dc5;
    *local_40 = *local_40 + 1;
    iVar3 = Tcl_GetIntFromObj(0,local_40,&local_40);
    *piVar14 = *piVar14 + -1;
    pcVar12 = TclFreeObj_exref;
    local_24 = -(uint)(iVar3 != 1) & (uint)local_40;
    if (*piVar14 < 1) {
      TclFreeObj(piVar14);
    }
  }
  *piVar9 = *piVar9 + -1;
  if (*piVar9 < 1) {
    (*pcVar12)(piVar9);
  }
LAB_00667deb:
  piVar9 = local_28;
  if (2 < param_3) {
    if (local_54 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_5c;
      if (local_58 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_5c;
      }
    }
    else {
      if (local_58 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_5c + 2;
    }
    piVar14 = (int *)*puVar6;
    if (piVar14 != (int *)0x0) {
      *piVar14 = *piVar14 + 1;
    }
    local_8._0_1_ = 2;
    local_50 = piVar14;
    if (piVar14 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar14,0);
    }
    FUN_006b9200(ppuVar4);
    local_8._0_1_ = 1;
    if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
      (*pcVar12)(piVar14);
    }
    iVar3 = FUN_006b9f40(&DAT_007254e0);
    if (iVar3 == -1) {
      piVar5 = (int *)FUN_006b9500(&DAT_007254e0);
      local_8._0_1_ = 3;
      piVar9 = (int *)*piVar5;
      if (piVar9 != (int *)0x0) {
        *piVar9 = *piVar9 + 1;
      }
      local_28 = piVar9;
      piVar13 = piVar9;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        local_14 = piVar9;
        FUN_006ba940();
        piVar13 = local_14;
      }
      local_14 = piVar13;
      piVar9[2] = *(int *)(*piVar5 + 8);
      local_8._0_1_ = 4;
      if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 1;
    }
    else {
      local_28 = local_14;
      piVar9 = local_14;
    }
  }
  local_30 = (int *)FUN_006ba810(0x2bf6,uVar2);
  if (local_30 == (int *)0x0) {
    local_30 = (int *)0x0;
  }
  else {
    *local_30 = 0;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
  }
  piVar14 = local_30;
  iVar3 = local_30[1];
  if (iVar3 < 0) {
    FUN_00448980(-iVar3);
  }
  else if (0 < iVar3) {
    local_30[1] = 0;
  }
  iVar3 = piVar14[3];
  if (iVar3 < 0) {
    FUN_0066be30(-iVar3);
  }
  else if (0 < iVar3) {
    piVar14[3] = 0;
  }
  if ((int)local_18 < (int)local_24) {
    local_2c = 0;
    uVar2 = local_1c;
    piVar5 = local_20;
    do {
      piVar13 = piVar5;
      local_40 = piVar5;
      if ((int)piVar5 < (int)uVar2) {
        param_3 = 0;
        do {
          local_40 = piVar5;
          puVar6 = (undefined4 *)FUN_00592f10(PTR_0077241c);
          local_3c = 0;
          local_50 = (int *)*puVar6;
          do {
            uVar2 = local_3c;
            pCVar1 = PTR_0077241c->heightBlocks;
            if (((int)local_50 < 0) || (*(int *)&pCVar1->field_0x1c <= (int)local_50)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar9 = *(int **)&pCVar1->field_0x18;
            }
            else {
              piVar9 = (int *)(*(int *)&pCVar1->field_0x18 + (int)local_50 * 0xc);
            }
            if (uVar2 < 3) {
              piVar9 = piVar9 + uVar2;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar3 = *piVar9;
            iVar10 = *(int *)(iVar3 + 0x14);
            local_38 = (int *)&PTR_0077241c->heightBlocks[1].field_0xc;
            if ((iVar10 < 0) || ((int)PTR_0077241c->heightBlocks[1].data <= iVar10)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar10 = *(int *)(iVar3 + 0x14);
              local_38 = *(int **)(*local_38 + 4);
              local_34 = (CHeightBlockArray *)&PTR_0077241c->heightBlocks[1].field_0xc;
              if (-1 < iVar10) goto LAB_00668065;
LAB_00668071:
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar9 = *(int **)local_34;
            }
            else {
              local_38 = *(int **)(*local_38 + 4 + iVar10 * 8);
              local_34 = (CHeightBlockArray *)&PTR_0077241c->heightBlocks[1].field_0xc;
LAB_00668065:
              if (*(int *)((int)local_34 + 4) <= iVar10) goto LAB_00668071;
              piVar9 = (int *)(*(int *)local_34 + iVar10 * 8);
            }
            iVar10 = *piVar9;
            local_34 = PTR_0077241c->heightBlocks + 1;
            if ((iVar10 < 0) || (*(int *)&PTR_0077241c->heightBlocks[1].field_0x4 <= iVar10)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar10 = *(int *)local_34;
            }
            else {
              iVar10 = *(int *)local_34 + iVar10 * 2;
            }
            if (0 < (int)local_38) {
              puVar11 = (ushort *)(iVar10 + 4);
              local_38 = (int *)(((int)local_38 - 1U) / 3 + 1);
              do {
                if (*(int *)&PTR_0077241c->heightBlocks->field_0x1c < 1) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                if ((int)(uint)puVar11[-2] < *(int *)(iVar3 + 8)) {
                  puVar7 = (ushort *)(*(int *)(iVar3 + 4) + (uint)puVar11[-2] * 2);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar7 = *(ushort **)(iVar3 + 4);
                }
                if ((int)(uint)*puVar7 < DAT_00b836a8) {
                  pfVar8 = DAT_00b836a4 + (uint)*puVar7 * 5;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar8 = DAT_00b836a4;
                }
                local_34 = (CHeightBlockArray *)(*pfVar8 * 200.0);
                local_44 = pfVar8[1] * 200.0;
                local_78 = (14.5 - pfVar8[2]) * 200.0;
                if (*(int *)&PTR_0077241c->heightBlocks->field_0x1c < 1) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                if ((int)(uint)puVar11[-1] < *(int *)(iVar3 + 8)) {
                  puVar7 = (ushort *)(*(int *)(iVar3 + 4) + (uint)puVar11[-1] * 2);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar7 = *(ushort **)(iVar3 + 4);
                }
                if ((int)(uint)*puVar7 < DAT_00b836a8) {
                  pfVar8 = DAT_00b836a4 + (uint)*puVar7 * 5;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar8 = DAT_00b836a4;
                }
                local_48 = *pfVar8 * 200.0;
                local_4c = pfVar8[1] * 200.0;
                local_6c = (14.5 - pfVar8[2]) * 200.0;
                if (*(int *)&PTR_0077241c->heightBlocks->field_0x1c < 1) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                if ((int)(uint)*puVar11 < *(int *)(iVar3 + 8)) {
                  puVar7 = (ushort *)(*(int *)(iVar3 + 4) + (uint)*puVar11 * 2);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar7 = *(ushort **)(iVar3 + 4);
                }
                if ((int)(uint)*puVar7 < DAT_00b836a8) {
                  pfVar8 = DAT_00b836a4 + (uint)*puVar7 * 5;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar8 = DAT_00b836a4;
                }
                local_60 = (14.5 - pfVar8[2]) * 200.0;
                local_68 = (float)param_3;
                local_64 = (float)local_2c;
                local_80 = (float)local_34 + local_68;
                local_7c = local_44 + local_64;
                local_74 = local_68 + local_48;
                local_70 = local_64 + local_4c;
                local_68 = local_68 + *pfVar8 * 200.0;
                local_64 = local_64 + pfVar8[1] * 200.0;
                FUN_00617940(&local_80,&local_74,&local_68);
                puVar11 = puVar11 + 3;
                local_38 = (int *)((int)local_38 + -1);
              } while (local_38 != (int *)0x0);
              local_38 = (int *)0x0;
              uVar2 = local_3c;
            }
            local_3c = uVar2 + 1;
          } while ((int)local_3c < 3);
          param_3 = param_3 + 200;
          piVar5 = (int *)((int)local_40 + 1);
          uVar2 = local_1c;
          piVar13 = local_20;
          local_40 = piVar5;
        } while ((int)piVar5 < (int)local_1c);
      }
      local_18 = local_18 + 1;
      local_2c = local_2c + 200;
      piVar9 = local_28;
      piVar14 = local_30;
      piVar5 = piVar13;
    } while ((int)local_18 < (int)local_24);
  }
  FUN_0043ff70(&DAT_00721a8c);
  FUN_0043ff70("%d,%d\n",piVar14[1],piVar14[3]);
  FUN_00617c90(&local_14,&local_14);
  local_8 = CONCAT31(local_8._1_3_,9);
  iVar3 = piVar14[3];
  if (iVar3 < 0) {
    FUN_0066be30(-iVar3);
  }
  else if (0 < iVar3) {
    piVar14[3] = 0;
    FUN_0066be90(0);
  }
  if (piVar14[2] != 0) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,10);
  iVar3 = piVar14[1];
  if (iVar3 < 0) {
    FUN_00448980(-iVar3);
  }
  else if (0 < iVar3) {
    piVar14[1] = 0;
    FUN_00448a90(0);
  }
  if (*piVar14 != 0) {
    FUN_006ba940();
  }
  FUN_006cecd8(piVar14,0x10);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xc;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  FUN_004297b0(0);
  if (local_5c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return 0;
}

