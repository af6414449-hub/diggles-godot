
undefined4 CTclGlobalMethods__Path(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  byte *pbVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  code *pcVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined4 **ppuVar14;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  int *piStack_88;
  int local_64;
  undefined4 *local_48;
  uint local_44;
  int local_40;
  undefined4 *local_34;
  int *local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070dcfd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca70d0) &&
     (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00ca70d0 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca70d4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::Path()";
    *(int *)(&DAT_00773650 + iVar8) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar8 = DAT_00ca70d4;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca70d4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar2;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0();
  local_8._0_1_ = 2;
  local_2c = FUN_005c71c0();
  if (local_2c == 0) {
    local_8._0_1_ = 3;
    FUN_004297b0();
    local_8 = CONCAT31(local_8._1_3_,4);
LAB_00646a65:
    FUN_004297b0();
    if (local_48 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  if (param_3 == 4) {
    if (local_40 < 3) {
      piStack_88 = (int *)0x64645e;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_48;
      if (local_44 == 0) {
        piStack_88 = (int *)0x646471;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 3) {
        piStack_88 = (int *)0x646489;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_48 + 2;
    }
    piVar7 = (int *)*puVar4;
    local_30 = piVar7;
    if (piVar7 == (int *)0x0) {
      puVar4 = (undefined4 *)FUN_006bafe0();
      local_20 = *puVar4;
      local_24 = puVar4[1];
      local_28 = puVar4[2];
    }
    else {
      *piVar7 = *piVar7 + 1;
      puVar4 = (undefined4 *)FUN_006bafe0();
      local_20 = *puVar4;
      local_24 = puVar4[1];
      local_28 = puVar4[2];
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 1) {
        TclFreeObj();
      }
    }
    if (local_40 < 3) {
      piStack_88 = (int *)0x646524;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_48;
      if (local_44 == 0) {
        piStack_88 = (int *)0x646537;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 3) {
        piStack_88 = (int *)0x64654f;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_48 + 2;
    }
    piVar7 = (int *)*puVar4;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
    local_8._0_1_ = 5;
    if (piVar7 != (int *)0x0) {
      Tcl_GetStringFromObj();
    }
    local_30 = piVar7;
    piVar5 = (int *)FUN_006b8fb0();
    pbVar9 = &DAT_00730054;
    pbVar6 = (byte *)(*piVar5 + 0xc);
    do {
      bVar1 = *pbVar6;
      bVar12 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_006465b4:
        uVar10 = -(uint)bVar12 | 1;
        goto LAB_006465b9;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar6[1];
      bVar12 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_006465b4;
      pbVar6 = pbVar6 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    uVar10 = 0;
LAB_006465b9:
    local_8 = CONCAT31(local_8._1_3_,6);
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    if ((local_30 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
      TclFreeObj();
    }
    if (uVar10 == 0) {
      local_20 = *(undefined4 *)(local_2c + 0xc);
      local_24 = *(undefined4 *)(local_2c + 0x10);
      local_28 = *(undefined4 *)(local_2c + 0x14);
    }
    if (local_40 < 4) {
      piStack_88 = (int *)0x64661d;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_48;
      if (local_44 == 0) {
        piStack_88 = (int *)0x646630;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 4) {
        piStack_88 = (int *)0x646648;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_48 + 3;
    }
    piVar7 = (int *)*puVar4;
    local_30 = piVar7;
    if (piVar7 == (int *)0x0) {
      puVar4 = (undefined4 *)FUN_006bafe0();
      uStack_90 = *puVar4;
      uStack_8c = puVar4[1];
      piVar5 = (int *)puVar4[2];
    }
    else {
      *piVar7 = *piVar7 + 1;
      puVar4 = (undefined4 *)FUN_006bafe0();
      local_14 = *puVar4;
      local_18 = puVar4[1];
      local_1c = (int *)puVar4[2];
      *piVar7 = *piVar7 + -1;
      uStack_90 = local_14;
      uStack_8c = local_18;
      piVar5 = local_1c;
      if (*piVar7 < 1) {
        TclFreeObj();
        uStack_90 = local_14;
        uStack_8c = local_18;
        piVar5 = local_1c;
      }
    }
  }
  else {
    if (param_3 != 5) {
      local_8._0_1_ = 9;
      FUN_004297b0();
      local_8 = CONCAT31(local_8._1_3_,10);
      goto LAB_00646a65;
    }
    puVar4 = (undefined4 *)FUN_004295e0();
    piVar7 = (int *)*puVar4;
    local_30 = piVar7;
    if (piVar7 == (int *)0x0) {
      puVar4 = (undefined4 *)FUN_006bafe0();
      local_20 = *puVar4;
      local_24 = puVar4[1];
      local_28 = puVar4[2];
      pcVar11 = TclFreeObj_exref;
    }
    else {
      *piVar7 = *piVar7 + 1;
      puVar4 = (undefined4 *)FUN_006bafe0();
      pcVar11 = TclFreeObj_exref;
      local_20 = *puVar4;
      local_24 = puVar4[1];
      local_28 = puVar4[2];
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 1) {
        TclFreeObj();
      }
    }
    puVar4 = (undefined4 *)FUN_004295e0();
    piVar7 = (int *)*puVar4;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
    local_8._0_1_ = 7;
    if (piVar7 != (int *)0x0) {
      Tcl_GetStringFromObj();
    }
    local_30 = piVar7;
    piVar5 = (int *)FUN_006b8fb0();
    pbVar9 = &DAT_00730054;
    pbVar6 = (byte *)(*piVar5 + 0xc);
    do {
      bVar1 = *pbVar6;
      bVar12 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_00646800:
        uVar10 = -(uint)bVar12 | 1;
        goto LAB_00646805;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar6[1];
      bVar12 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_00646800;
      pbVar6 = pbVar6 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    uVar10 = 0;
LAB_00646805:
    local_8 = CONCAT31(local_8._1_3_,8);
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    if ((local_30 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
      (*pcVar11)();
    }
    iVar3 = local_2c;
    if (uVar10 == 0) {
      local_20 = *(undefined4 *)(local_2c + 0xc);
      local_24 = *(undefined4 *)(local_2c + 0x10);
      local_28 = *(undefined4 *)(local_2c + 0x14);
    }
    puVar4 = (undefined4 *)FUN_004295e0();
    piVar7 = (int *)*puVar4;
    local_30 = piVar7;
    if (piVar7 == (int *)0x0) {
      puVar4 = (undefined4 *)FUN_006bafe0();
      local_14 = *puVar4;
      local_18 = puVar4[1];
      local_1c = (int *)puVar4[2];
    }
    else {
      *piVar7 = *piVar7 + 1;
      puVar4 = (undefined4 *)FUN_006bafe0();
      local_14 = *puVar4;
      local_18 = puVar4[1];
      local_1c = (int *)puVar4[2];
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 1) {
        (*pcVar11)();
      }
    }
    local_30 = *(int **)(iVar3 + 0x36c);
    puVar4 = (undefined4 *)FUN_004295e0();
    piVar7 = (int *)*puVar4;
    uStack_90 = local_14;
    uStack_8c = local_18;
    piVar5 = local_1c;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
      Tcl_GetIntFromObj();
      *piVar7 = *piVar7 + -1;
      uStack_90 = local_14;
      uStack_8c = local_18;
      piVar5 = local_1c;
      if (*piVar7 < 1) {
        (*pcVar11)();
        uStack_90 = local_14;
        uStack_8c = local_18;
        piVar5 = local_1c;
      }
    }
  }
  local_30 = &uStack_9c;
  uStack_9c = local_20;
  uStack_98 = local_24;
  uStack_94 = local_28;
  ppuVar14 = &local_34;
  local_8._0_1_ = 0xc;
  piStack_88 = piVar5;
  FUN_0059a4b0(ppuVar14);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0059d440(ppuVar14);
  piVar7 = (int *)Tcl_NewIntObj();
  *piVar7 = *piVar7 + 1;
  iVar3 = *piVar7;
  if (local_64 != 0) {
    Tcl_SetObjResult();
    iVar3 = *piVar7;
  }
  *piVar7 = iVar3 + -1;
  if (iVar3 + -1 < 1) {
    TclFreeObj();
  }
  if (local_34 != (undefined4 *)0x0) {
    LOCK();
    iVar3 = local_34[1] + -1;
    local_34[1] = iVar3;
    UNLOCK();
    if ((iVar3 == 0) && (local_34 != (undefined4 *)0x0)) {
      (**(code **)*local_34)();
    }
  }
  local_8._0_1_ = 0xd;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,0xe);
  FUN_004297b0();
  if (local_48 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

