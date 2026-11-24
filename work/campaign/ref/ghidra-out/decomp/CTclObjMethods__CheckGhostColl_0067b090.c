
undefined4
CTclObjMethods__CheckGhostColl
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  undefined **ppuVar5;
  int *piVar6;
  byte *pbVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  uint uVar13;
  int *piVar14;
  byte *pbVar15;
  bool bVar16;
  undefined8 uVar17;
  int local_100;
  int local_f0;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  int local_5c;
  float local_4c;
  int *local_48;
  float local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  float local_34;
  int *local_30;
  float local_2c;
  int *local_28;
  int *local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710f63;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7570) &&
     (FUN_006cebf4(&DAT_00ca7570,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7570 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca7574 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclObjMethods::CheckGhostColl()";
    *(int *)(&DAT_00773650 + iVar9) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7570);
  }
  iVar9 = DAT_00ca7574;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7574 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar4 == 0) {
    uVar17 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar17;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_3c = (int *)FUN_005c71c0(param_4,4,2);
  if (local_3c == (int *)0x0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  else {
    local_14 = (int *)FUN_005c71c0(param_4,4,3);
    if (local_14 != (int *)0x0) {
      if (local_18 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar12 = local_20;
        if (local_1c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar12 = local_20;
        }
      }
      else {
        if (local_1c < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar12 = local_20 + 1;
      }
      piVar6 = (int *)*puVar12;
      if (piVar6 != (int *)0x0) {
        *piVar6 = *piVar6 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,7);
      local_40 = piVar6;
      if (piVar6 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
        piVar14 = (int *)0x0;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar6,0);
        piVar14 = piVar6;
      }
      FUN_006b8fb0(ppuVar5);
      if ((piVar14 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
        TclFreeObj(piVar6);
      }
      uVar13 = 0;
      if (0 < *(int *)(DAT_0076a338 + 0xf5)) {
        local_34 = 0.0;
        piVar6 = local_14;
        iVar4 = DAT_0076a338;
        do {
          local_28 = (int *)(iVar4 + 0xf1);
          if (*(uint *)(iVar4 + 0xf5) <= uVar13) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = local_14;
            iVar4 = DAT_0076a338;
          }
          if (*(int *)((int)local_34 + *local_28) == *(int *)((int)piVar6 + 0xdc)) {
            if (uVar13 != 0xffffffff) {
              if (*(uint *)(iVar4 + 0xf5) <= uVar13) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              piVar6 = local_24;
              iVar4 = *(int *)(iVar4 + 0xf1);
              local_38 = (int *)0x0;
              local_2c = *(float *)(iVar4 + 4 + uVar13 * 0x24);
              local_60 = *(float *)(iVar4 + 0xc + uVar13 * 0x24);
              local_48 = *(int **)(iVar4 + 0x10 + uVar13 * 0x24);
              local_44 = *(float *)(iVar4 + 0x14 + uVar13 * 0x24);
              local_30 = *(int **)(iVar4 + 8 + uVar13 * 0x24);
              local_8._0_1_ = 0xd;
              pcVar10 = "objects";
              pbVar15 = (byte *)(local_24 + 3);
              pbVar7 = pbVar15;
              goto LAB_0067b410;
            }
            break;
          }
          uVar13 = uVar13 + 1;
          local_34 = (float)((int)local_34 + 0x24);
        } while ((int)uVar13 < *(int *)(iVar4 + 0xf5));
      }
      piVar6 = (int *)Tcl_NewBooleanObj(0);
      *piVar6 = *piVar6 + 1;
      iVar4 = *piVar6;
      if (local_5c != 0) {
        Tcl_SetObjResult(local_5c,piVar6);
        iVar4 = *piVar6;
      }
      *piVar6 = iVar4 + -1;
      if (iVar4 + -1 < 1) {
        TclFreeObj(piVar6);
      }
      local_8._0_1_ = 10;
      if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0xb;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,0xc);
      goto LAB_0067b347;
    }
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
  }
LAB_0067b17d:
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
  while( true ) {
    bVar1 = pbVar7[1];
    bVar16 = bVar1 < ((byte *)pcVar10)[1];
    if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_0067b430;
    pbVar7 = pbVar7 + 2;
    pcVar10 = (char *)((byte *)pcVar10 + 2);
    if (bVar1 == 0) break;
LAB_0067b410:
    bVar1 = *pbVar7;
    bVar16 = bVar1 < (byte)*pcVar10;
    if (bVar1 != *pcVar10) {
LAB_0067b430:
      uVar13 = -(uint)bVar16 | 1;
      goto LAB_0067b435;
    }
    if (bVar1 == 0) break;
  }
  uVar13 = 0;
LAB_0067b435:
  local_4c = local_60;
  local_34 = local_44;
  local_28 = local_48;
  if (uVar13 == 0) {
    piVar14 = (int *)(DAT_00772400 + 0x5c8);
    if ((uint)local_2c < 0x100) {
      piVar14 = piVar14 + (int)local_2c;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar2 = local_30;
    local_24 = (int *)(*piVar14 + 0x34);
    if (((int)local_30 < 0) || (*(int *)(*piVar14 + 0x38) <= (int)local_30)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_24 = (int *)(DAT_00772400 + 0x5c8);
    if ((uint)local_2c < 0x100) {
      local_24 = local_24 + (int)local_2c;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar4 = *local_24;
    local_24 = (int *)(iVar4 + 0x34);
    if (((int)piVar2 < 0) || (*(int *)(iVar4 + 0x38) <= (int)piVar2)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar4 = *local_24;
    }
    else {
      iVar4 = (int)piVar2 * 0xe8 + *local_24;
    }
    local_78 = *(undefined4 *)(iVar4 + 0x50);
    local_74 = *(undefined4 *)(iVar4 + 0x54);
    local_70 = *(undefined4 *)(iVar4 + 0x58);
    uVar3 = FUN_005e6be0(&local_78,*(undefined4 *)((int)local_14 + 0xdc),local_3c[0x37],
                         local_3c[0xdb],iVar4);
    piVar14 = (int *)Tcl_NewBooleanObj(uVar3);
    *piVar14 = *piVar14 + 1;
    iVar4 = *piVar14;
    if (local_5c != 0) {
      Tcl_SetObjResult(local_5c,piVar14);
      iVar4 = *piVar14;
    }
    *piVar14 = iVar4 + -1;
    if (iVar4 + -1 < 1) {
      TclFreeObj(piVar14);
    }
    local_8._0_1_ = 0xe;
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0xf;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,0x10);
    goto LAB_0067b347;
  }
  pcVar10 = "gnomes";
  pbVar7 = pbVar15;
  do {
    bVar1 = *pbVar7;
    bVar16 = bVar1 < (byte)*pcVar10;
    if (bVar1 != *pcVar10) {
LAB_0067b5e0:
      uVar13 = -(uint)bVar16 | 1;
      goto LAB_0067b5e5;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar7[1];
    bVar16 = bVar1 < ((byte *)pcVar10)[1];
    if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_0067b5e0;
    pbVar7 = pbVar7 + 2;
    pcVar10 = (char *)((byte *)pcVar10 + 2);
  } while (bVar1 != 0);
  uVar13 = 0;
LAB_0067b5e5:
  if (uVar13 != 0) {
    pbVar11 = &DAT_007330f0;
    pbVar7 = pbVar15;
    do {
      bVar1 = *pbVar7;
      bVar16 = bVar1 < *pbVar11;
      if (bVar1 != *pbVar11) {
LAB_0067b614:
        uVar13 = -(uint)bVar16 | 1;
        goto LAB_0067b619;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar7[1];
      bVar16 = bVar1 < pbVar11[1];
      if (bVar1 != pbVar11[1]) goto LAB_0067b614;
      pbVar7 = pbVar7 + 2;
      pbVar11 = pbVar11 + 2;
    } while (bVar1 != 0);
    uVar13 = 0;
LAB_0067b619:
    if (uVar13 != 0) {
      if (pbVar15 == (byte *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)Tcl_NewStringObj(pbVar15,0xffffffff,pbVar11);
        *piVar6 = *piVar6 + 1;
      }
      FUN_006bc6a0("invalid param:",piVar6);
      local_8._0_1_ = 0x1b;
      if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0x1c;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,0x1d);
      goto LAB_0067b17d;
    }
  }
  local_14 = (int *)(DAT_00772400 + 0x5c8);
  if ((uint)local_2c < 0x100) {
    local_14 = local_14 + (int)local_2c;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar4 = *local_14;
  local_14 = (int *)(iVar4 + 0x34);
  if (((int)local_30 < 0) || (*(int *)(iVar4 + 0x38) <= (int)local_30)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar4 = *local_14;
  }
  else {
    iVar4 = (int)local_30 * 0xe8 + *local_14;
  }
  local_68 = *(float *)(iVar4 + 0x48) * 0.005;
  local_14 = (int *)(DAT_00772400 + 0x5c8);
  local_64 = *(float *)(iVar4 + 0x44) * 0.005;
  local_6c = *(float *)(iVar4 + 0x4c) * 0.01;
  if ((uint)local_2c < 0x100) {
    local_14 = local_14 + (int)local_2c;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar4 = *local_14;
  local_14 = (int *)(iVar4 + 0x34);
  if (((int)local_30 < 0) || (*(int *)(iVar4 + 0x38) <= (int)local_30)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar4 = *local_14;
  }
  else {
    iVar4 = (int)local_30 * 0xe8 + *local_14;
  }
  pbVar7 = &DAT_007330f0;
  local_2c = *(float *)(iVar4 + 0x54) * 0.005 + 0.6;
  local_40 = (int *)(*(float *)(iVar4 + 0x58) * 0.01 + 0.0);
  local_14 = (int *)(*(float *)(iVar4 + 0x50) * 0.005 + 0.0);
  do {
    bVar1 = *pbVar15;
    bVar16 = bVar1 < *pbVar7;
    if (bVar1 != *pbVar7) {
LAB_0067b7d0:
      uVar13 = -(uint)bVar16 | 1;
      goto LAB_0067b7d5;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar15[1];
    bVar16 = bVar1 < pbVar7[1];
    if (bVar1 != pbVar7[1]) goto LAB_0067b7d0;
    pbVar15 = pbVar15 + 2;
    pbVar7 = pbVar7 + 2;
  } while (bVar1 != 0);
  uVar13 = 0;
LAB_0067b7d5:
  if (uVar13 != 0) {
    FUN_005ddd60();
    local_8 = CONCAT31(local_8._1_3_,0x14);
    iVar4 = FUN_005de0c0(local_3c,0);
    uVar13 = *(uint *)(iVar4 + 0x1c);
    if (uVar13 == 0xffffffff) {
      uVar13 = 0;
    }
    *(uint *)(iVar4 + 0x1c) = uVar13 | 0x20000;
    if (local_100 == -2) {
      FUN_005e12a0();
    }
    if (local_f0 < 1) {
      piVar14 = (int *)Tcl_NewBooleanObj(0);
      *piVar14 = *piVar14 + 1;
      local_40 = piVar14;
      FUN_006bc670(&local_40);
      *piVar14 = *piVar14 + -1;
      if (*piVar14 < 1) {
        TclFreeObj(piVar14);
      }
      FUN_005ddfc0();
      local_8._0_1_ = 0x18;
      if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0x19;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,0x1a);
    }
    else {
      while( true ) {
        if (local_100 == -2) {
          FUN_005e12a0();
        }
        piVar14 = local_38;
        local_100 = local_100 + 1;
        if (local_f0 <= local_100) break;
        if ((local_100 < 0) || (local_f0 <= local_100)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar4 = FUN_005caf90();
        if (iVar4 == 0) {
          piVar14 = (int *)0x0;
        }
        else {
          piVar14 = (int *)Tcl_NewStringObj(iVar4,0xffffffff);
          *piVar14 = *piVar14 + 1;
        }
        local_3c = piVar14;
        FUN_006bb930(&local_3c);
        if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
          TclFreeObj(piVar14);
        }
      }
      if (local_5c != 0) {
        if (local_38 == (int *)0x0) {
          Tcl_ResetResult(local_5c);
        }
        else {
          Tcl_SetObjResult(local_5c,local_38);
        }
      }
      FUN_005ddfc0();
      if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
        TclFreeObj(piVar14);
      }
      local_8._0_1_ = 0x15;
      if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0x16;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,0x17);
    }
    goto LAB_0067b347;
  }
  local_4c = local_64 + local_60;
  local_48 = (int *)(local_68 + (float)local_28);
  local_44 = local_34 + local_6c;
  uVar8 = FUN_006badc0(&local_4c);
  FUN_006bb930(uVar8);
  if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 < 1)) {
    TclFreeObj(local_30);
  }
  local_4c = local_60 + (float)local_14;
  local_48 = (int *)((float)local_28 + local_2c);
  local_44 = local_34 + (float)local_40;
  uVar8 = FUN_006badc0(&local_4c);
  FUN_006bb930(uVar8);
  if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 < 1)) {
    TclFreeObj(local_28);
  }
  piVar14 = local_38;
  if (local_5c == 0) {
LAB_0067b8bf:
    if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
      TclFreeObj(piVar14);
    }
  }
  else {
    if (local_38 != (int *)0x0) {
      Tcl_SetObjResult(local_5c,local_38);
      goto LAB_0067b8bf;
    }
    Tcl_ResetResult(local_5c);
  }
  local_8._0_1_ = 0x11;
  if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x12;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x13);
LAB_0067b347:
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

