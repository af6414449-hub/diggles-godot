
undefined4
CTclObjMethods__FindNextVisible
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  void *lp;
  BOOL BVar6;
  int *piVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 uVar8;
  undefined4 *puVar9;
  code *pcVar10;
  bool bVar11;
  bool bVar12;
  undefined8 uVar13;
  int local_44;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  double local_28;
  int *local_20;
  int *local_1c;
  undefined4 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071087d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7498) &&
     (FUN_006cebf4(&DAT_00ca7498,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7498 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca749c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::FindNextVisible()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7498);
  }
  iVar4 = DAT_00ca749c;
  local_18 = &DAT_00ca749c;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca749c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_005c71c0(param_4,4,1);
  if (iVar3 == 0) {
    uVar8 = 1;
    goto LAB_00673c56;
  }
  if (local_2c < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    uVar8 = extraout_ECX_00;
    puVar9 = local_34;
    if (local_30 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar8 = extraout_ECX_01;
    }
  }
  else {
    uVar8 = extraout_ECX;
    if (local_30 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar8 = extraout_ECX_02;
    }
    puVar9 = local_34 + 2;
  }
  piVar1 = (int *)*puVar9;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_1c = piVar1;
  if (local_2c < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    uVar8 = extraout_ECX_03;
    puVar9 = local_34;
    if (local_30 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar8 = extraout_ECX_04;
    }
  }
  else {
    if (local_30 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar8 = extraout_ECX_05;
    }
    puVar9 = local_34 + 3;
  }
  piVar2 = (int *)*puVar9;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  local_20 = piVar2;
  if (piVar2 == (int *)0x0) {
    local_14 = (int *)0x0;
  }
  else {
    iVar4 = Tcl_GetDoubleFromObj(0,piVar2,&local_28);
    uVar8 = extraout_ECX_06;
    if (iVar4 == 1) {
      local_14 = (int *)0x0;
    }
    else {
      local_14 = (int *)(float)local_28;
    }
  }
  if (piVar1 == (int *)0x0) {
    ppuVar5 = &PTR_0071ce50;
  }
  else {
    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    uVar8 = extraout_ECX_07;
  }
  FUN_006b8fb0(ppuVar5);
  lp = (void *)FUN_00580260(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x10),
                            *(undefined4 *)(iVar3 + 0x14),uVar8);
  if (lp == (void *)0x0) {
    local_14 = (int *)Tcl_NewIntObj(0);
    *local_14 = *local_14 + 1;
    iVar3 = *local_14;
    if (local_44 != 0) {
      Tcl_SetObjResult(local_44,local_14);
      iVar3 = *local_14;
    }
    iVar3 = iVar3 + -1;
    *local_14 = iVar3;
    bVar12 = iVar3 < 0;
    bVar11 = iVar3 == 0;
    goto LAB_00673c17;
  }
  BVar6 = IsBadReadPtr(lp,0x10);
  if (((BVar6 == 0) && (*(int *)((int)lp + 8) == 0x616e4f62)) &&
     ((DAT_00768398 == '\0' || (*(int *)((int)lp + 0xdc) != 0)))) {
    piVar7 = (int *)FUN_005caf90();
    if (piVar7 != (int *)0x0) {
      piVar7 = (int *)Tcl_NewStringObj(piVar7,0xffffffff);
      *piVar7 = *piVar7 + 1;
    }
    local_14 = piVar7;
    if (local_44 == 0) {
      if (piVar7 != (int *)0x0) {
        *piVar7 = *piVar7 + -1;
        bVar12 = *piVar7 < 0;
        bVar11 = *piVar7 == 0;
        goto LAB_00673c17;
      }
    }
    else if (piVar7 == (int *)0x0) {
      Tcl_ResetResult(local_44);
    }
    else {
      Tcl_SetObjResult(local_44,piVar7);
      *local_14 = *local_14 + -1;
      bVar12 = *local_14 < 0;
      bVar11 = *local_14 == 0;
LAB_00673c17:
      if (bVar11 || bVar12) {
        TclFreeObj(local_14);
      }
    }
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
  }
  pcVar10 = TclFreeObj_exref;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, pcVar10 = TclFreeObj_exref, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar10)(piVar1);
  }
LAB_00673c56:
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

