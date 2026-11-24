
undefined4
CTclGlobalMethods__VectorAngle(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  int local_4c;
  undefined1 local_3c [12];
  float local_30;
  float local_2c;
  float local_28;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  undefined4 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d29d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6fa8) &&
     (FUN_006cebf4(&DAT_00ca6fa8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca6fa8 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca6fac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclGlobalMethods::VectorAngle()";
    *(int *)(&DAT_00773650 + iVar9) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6fa8);
  }
  iVar9 = DAT_00ca6fac;
  local_18 = &DAT_00ca6fac;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6fac * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar1;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar5 == 0) {
    uVar11 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  uVar4 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (2 < param_3) {
    local_8._0_1_ = uVar4;
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar10 = local_24;
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_24 + 1;
    }
    piVar2 = (int *)*puVar10;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_14 = piVar2;
    if (local_1c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar10 = local_24;
      }
    }
    else {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_24 + 2;
    }
    piVar3 = (int *)*puVar10;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    pfVar6 = (float *)FUN_006bafe0(&local_30);
    pfVar7 = (float *)FUN_006bafe0(local_3c);
    local_30 = *pfVar7 - *pfVar6;
    local_2c = pfVar7[1] - pfVar6[1];
    local_28 = pfVar7[2] - pfVar6[2];
    FUN_00410940();
    piVar8 = (int *)FUN_006bad90();
    if (local_4c != 0) {
      if (*piVar8 == 0) {
        Tcl_ResetResult(local_4c);
      }
      else {
        Tcl_SetObjResult(local_4c,*piVar8);
      }
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
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
    if (local_24 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  FUN_006bc8f0(2);
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

