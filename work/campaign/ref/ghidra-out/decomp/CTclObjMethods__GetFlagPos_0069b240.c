
undefined4
CTclObjMethods__GetFlagPos
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined8 uVar5;
  int local_30;
  float local_20;
  float local_1c;
  float local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711d55;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7ae8) {
    FUN_006cebf4(&DAT_00ca7ae8,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca7ae8 == -1) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00ca7aec = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::GetFlagPos()";
      *(int *)(&DAT_00773650 + iVar4) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7ae8);
    }
  }
  iVar4 = DAT_00ca7aec;
  local_14 = &DAT_00ca7aec;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7aec * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar5 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar2 = FUN_005c71c0(param_4,2,1);
  if (iVar2 == 0) {
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  iVar4 = *(int *)(iVar2 + 0xd4);
  local_20 = *(float *)(iVar2 + 0xc) + *(float *)(iVar4 + 0xcec);
  local_1c = *(float *)(iVar4 + 0xcf0) + *(float *)(iVar2 + 0x10);
  local_18 = *(float *)(iVar4 + 0xcf4) + *(float *)(iVar2 + 0x14);
  piVar3 = (int *)FUN_006badc0(&local_20);
  if (local_30 != 0) {
    if (*piVar3 == 0) {
      Tcl_ResetResult(local_30);
    }
    else {
      Tcl_SetObjResult(local_30,*piVar3);
    }
  }
  if (local_14 != (int *)0x0) {
    *local_14 = *local_14 + -1;
    if (*local_14 < 1) {
      TclFreeObj(local_14);
    }
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

