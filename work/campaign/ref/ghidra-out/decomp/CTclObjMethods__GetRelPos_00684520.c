
undefined4
CTclObjMethods__GetRelPos
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int local_40;
  int local_30;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071132d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7750) {
    FUN_006cebf4(&DAT_00ca7750,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar1 = DAT_00783650;
    if (DAT_00ca7750 == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca7754 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::GetRelPos()";
      *(int *)(&DAT_00773650 + iVar3) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7750);
    }
  }
  iVar3 = DAT_00ca7754;
  local_18 = &DAT_00ca7754;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7754 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar5 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = (int *)FUN_005c71c0(param_4,3,1);
  if (local_14 != (int *)0x0) {
    iVar1 = FUN_005c71c0(param_4,3,2);
    if (iVar1 != 0) {
      local_24 = (float)local_14[3] - *(float *)(iVar1 + 0xc);
      local_20 = (float)local_14[4] - *(float *)(iVar1 + 0x10);
      local_1c = (float)local_14[5] - *(float *)(iVar1 + 0x14);
      piVar2 = (int *)FUN_006badc0(&local_24);
      if (local_40 != 0) {
        if (*piVar2 == 0) {
          Tcl_ResetResult(local_40);
        }
        else {
          Tcl_SetObjResult(local_40,*piVar2);
        }
      }
      if (local_14 != (int *)0x0) {
        *local_14 = *local_14 + -1;
        if (*local_14 < 1) {
          TclFreeObj(local_14);
        }
      }
      uVar4 = 0;
      goto LAB_00684693;
    }
  }
  uVar4 = 1;
LAB_00684693:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_30 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

