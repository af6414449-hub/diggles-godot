
undefined4
CTclGlobalMethods__VectorMul(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  float *pfVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined8 uVar11;
  int local_4c;
  undefined1 local_3c [12];
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  float local_24;
  float local_20;
  float fStack_1c;
  undefined4 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d31d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6f60) &&
     (FUN_006cebf4(&DAT_00ca6f60,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca6f60 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca6f64 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::VectorMul()";
    *(int *)(&DAT_00773650 + iVar8) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6f60);
  }
  iVar8 = DAT_00ca6f64;
  local_18 = &DAT_00ca6f64;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6f64 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar1;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar5 == 0) {
    uVar11 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  uVar4 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (param_3 < 3) {
    FUN_006bc8f0(2);
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_004297b0(0);
    if (local_30 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  local_8._0_1_ = uVar4;
  if (local_28 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_30;
    }
  }
  else {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_30 + 1;
  }
  piVar2 = (int *)*puVar9;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_14 = piVar2;
  if (local_28 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_30;
    }
  }
  else {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_30 + 2;
  }
  piVar3 = (int *)*puVar9;
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
    iVar5 = Tcl_GetDoubleFromObj(0,piVar3,&local_20);
    if (iVar5 != 1) {
      piVar10 = (int *)(float)(double)CONCAT44(fStack_1c,local_20);
      goto LAB_006385ca;
    }
  }
  piVar10 = (int *)0x0;
LAB_006385ca:
  pfVar6 = (float *)FUN_006bafe0(local_3c);
  local_24 = (float)piVar10 * *pfVar6;
  local_20 = pfVar6[1] * (float)piVar10;
  fStack_1c = pfVar6[2] * (float)piVar10;
  piVar7 = (int *)FUN_006badc0(&local_24);
  if (local_4c != 0) {
    if (*piVar7 == 0) {
      Tcl_ResetResult(local_4c);
    }
    else {
      Tcl_SetObjResult(local_4c,*piVar7);
    }
  }
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
    TclFreeObj(piVar10);
  }
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
    TclFreeObj(piVar3);
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

