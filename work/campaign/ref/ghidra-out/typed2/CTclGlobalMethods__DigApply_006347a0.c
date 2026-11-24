
undefined4
CTclGlobalMethods__DigApply(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  int iVar8;
  undefined4 uVar9;
  int local_48;
  float local_38;
  float local_34;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 *local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d005;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ed8) &&
     (FUN_006cebf4(&DAT_00ca6ed8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6ed8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6edc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::DigApply()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6ed8);
  }
  iVar4 = DAT_00ca6edc;
  local_18 = &DAT_00ca6edc;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6edc * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar9;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar7 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (param_3 < 2) {
    FUN_006bc8f0(1);
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  else {
    local_8._0_1_ = uVar2;
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_2c;
      }
    }
    else {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_2c + 1;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_006bafe0(&local_38);
    local_1c = (int)ROUND(local_34 + 0.5);
    local_14 = local_38 + 0.5;
    DAT_00772dd8 = (int)ROUND(local_14);
    local_20 = DAT_00772dd8;
    iVar3 = FUN_005c71c0(param_4,0,2);
    if (iVar3 != 0) {
      iVar4 = local_20;
      iVar8 = local_1c;
      FUN_005f8080(local_20,local_1c);
      FUN_005fd060(iVar4,iVar8);
      iVar4 = FUN_005b28d0();
      if (DAT_00772409 == '\0') {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x18);
      }
      if (*(int *)(DAT_00772400 + 100) == iVar4) {
        uVar9 = *(undefined4 *)(iVar3 + 0x36c);
        iVar4 = local_20;
        iVar8 = local_1c;
        FUN_0058a820(local_20,local_1c,uVar9);
        CMapBeautifier__ScanAtPos(iVar4,iVar8,uVar9);
      }
      uVar2 = FUN_00596b80(&local_20,iVar3);
      iVar4 = FUN_005b28d0();
      if (DAT_00772409 == '\0') {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x18);
      }
      if (*(int *)(DAT_00772400 + 100) == iVar4) {
        uVar9 = *(undefined4 *)(iVar3 + 0x36c);
        iVar3 = local_20;
        iVar4 = local_1c;
        FUN_0058a820(local_20,local_1c,uVar9);
        FUN_0058ba00(iVar3,iVar4,uVar9);
      }
      piVar5 = (int *)Tcl_NewBooleanObj(uVar2);
      *piVar5 = *piVar5 + 1;
      iVar3 = *piVar5;
      if (local_48 != 0) {
        Tcl_SetObjResult(local_48,piVar5);
        iVar3 = *piVar5;
      }
      *piVar5 = iVar3 + -1;
      if (iVar3 + -1 < 1) {
        TclFreeObj(piVar5);
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj(piVar1);
      }
      local_8._0_1_ = 8;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_004297b0(0);
      if (local_2c != (undefined4 *)0x0) {
        FUN_006ba940();
      }
      FUN_006bc0d0();
      FUN_0043fd30();
      ExceptionList = local_10;
      return 0;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,7);
  }
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

