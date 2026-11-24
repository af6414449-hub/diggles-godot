
undefined4
CTclObjMethods__GetRot(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  undefined8 uVar7;
  int local_40;
  float local_30;
  float local_2c;
  float local_28;
  int local_24;
  undefined4 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071147d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7790) {
    FUN_006cebf4(&DAT_00ca7790,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca7790 == -1) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00ca7794 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::GetRot()";
      *(int *)(&DAT_00773650 + iVar4) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7790);
    }
  }
  iVar4 = DAT_00ca7794;
  local_18 = &DAT_00ca7794;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7794 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  iVar2 = FUN_005c71c0(param_4,2,1);
  if (iVar2 == 0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_004297b0(0);
    if (local_24 != 0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  fVar6 = *(float *)(iVar2 + 0x40);
  FUN_0041a0d0();
  if (fVar6 < 0.0) {
    fVar6 = fVar6 + 6.2831855;
  }
  fVar5 = *(float *)(iVar2 + 0x44);
  local_30 = fVar6;
  FUN_0041a0d0();
  if (fVar5 < 0.0) {
    fVar5 = fVar5 + 6.2831855;
  }
  fVar6 = *(float *)(iVar2 + 0x48);
  local_2c = fVar5;
  FUN_0041a0d0();
  if (fVar6 < 0.0) {
    fVar6 = fVar6 + 6.2831855;
  }
  local_28 = fVar6;
  piVar3 = (int *)FUN_006badc0(&local_30);
  if (local_40 != 0) {
    if (*piVar3 == 0) {
      Tcl_ResetResult(local_40);
    }
    else {
      Tcl_SetObjResult(local_40,*piVar3);
    }
  }
  if (local_14 != (int *)0x0) {
    *local_14 = *local_14 + -1;
    if (*local_14 < 1) {
      TclFreeObj(local_14);
    }
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_24 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

