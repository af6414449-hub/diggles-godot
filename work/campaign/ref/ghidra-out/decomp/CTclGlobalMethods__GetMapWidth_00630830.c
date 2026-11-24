
undefined4
CTclGlobalMethods__GetMapWidth(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int local_30;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c965;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e38) {
    FUN_006cebf4(&DAT_00ca6e38,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar1 = DAT_00783650;
    if (DAT_00ca6e38 == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca6e3c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::GetMapWidth()";
      *(int *)(&DAT_00773650 + iVar3) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca6e38);
    }
  }
  iVar3 = DAT_00ca6e3c;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e3c * 0x40);
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
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004298b0(param_3,param_4);
  if (param_3 == 1) {
    if (*(char *)(DAT_0077241c + 0x29) == '\0') {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(DAT_0077241c + 0x9c) - *(int *)(DAT_0077241c + 0x94);
    }
    piVar2 = (int *)Tcl_NewIntObj(iVar1);
    *piVar2 = *piVar2 + 1;
    iVar1 = *piVar2;
    if (local_30 != 0) {
      Tcl_SetObjResult(local_30,piVar2);
      iVar1 = *piVar2;
    }
    *piVar2 = iVar1 + -1;
    if (iVar1 + -1 < 1) {
      TclFreeObj(piVar2);
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_20 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

