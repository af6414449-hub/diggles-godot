
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CTclGlobalMethods__RefSet(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int **ppiVar10;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bfe5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ce8) &&
     (FUN_006cebf4(), iVar4 = DAT_00783650, DAT_00ca6ce8 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6cec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::RefSet()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar7 = DAT_00ca6cec;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6cec * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar9 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0(param_3);
  local_8._0_1_ = 2;
  if (param_3 == 4) {
    piVar5 = (int *)FUN_006ba810();
    piVar1 = piVar5 + 3;
    piVar5[2] = -1;
    *piVar5 = 0;
    *(undefined1 *)piVar1 = 0;
    piVar5[1] = 0x14;
    *piVar1 = 0x73696874;
    *(undefined1 *)(piVar5 + 4) = 0;
    piVar5[2] = 4;
    *piVar5 = 1;
    if (local_40 == 0) {
      uVar8 = 0;
      iVar4 = 1;
    }
    else {
      uVar8 = Tcl_GetAssocData(local_40,piVar1);
      iVar4 = *piVar5;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar5 = iVar4 + -1;
    if (iVar4 + -1 == 0) {
      FUN_006ba940();
    }
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_30 + 1;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_30 + 2;
    }
    piVar5 = (int *)*puVar6;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
    local_18 = piVar5;
    if (local_28 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_30 + 3;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8._0_1_ = 6;
    local_14 = piVar2;
    if (piVar1 != (int *)0x0) {
      Tcl_GetStringFromObj(piVar1);
    }
    FUN_006b8fb0();
    local_8._0_1_ = 7;
    iVar4 = FUN_006055d0(param_2,uVar8);
    local_8._0_1_ = 8;
    _DAT_00000004 = _DAT_00000004 + -1;
    if (_DAT_00000004 == 0) {
      FUN_006ba940();
    }
    local_8._0_1_ = 6;
    if (iVar4 == 0) {
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("invalid reference");
      param_3 = 1;
    }
    else {
      ppiVar10 = &local_18;
      FUN_005c9cc0(ppiVar10);
      cVar3 = FUN_006bc9c0(ppiVar10);
      if (cVar3 == '\0') {
        local_8._0_1_ = 9;
        iVar4 = FUN_005c9cc0();
        local_8._0_1_ = 6;
        FUN_006bc6a0(*(int *)(iVar4 + 8) + 0xc);
        param_3 = 1;
      }
      else {
        param_3 = 0;
      }
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj();
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
      TclFreeObj();
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj();
    }
  }
  else {
    FUN_006bc8f0();
    param_3 = 1;
  }
  local_8._0_1_ = 10;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_004297b0();
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return param_3;
}

