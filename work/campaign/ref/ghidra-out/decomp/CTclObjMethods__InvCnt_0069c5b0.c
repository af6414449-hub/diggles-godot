
undefined4
CTclObjMethods__InvCnt(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined8 uVar5;
  int local_30;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070b7cd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b20) {
    FUN_006cebf4(&DAT_00ca7b20,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar1 = DAT_00783650;
    if (DAT_00ca7b20 == -1) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00ca7b24 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::InvCnt()";
      *(int *)(&DAT_00773650 + iVar4) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7b20);
    }
  }
  iVar4 = DAT_00ca7b24;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b24 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar2;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar1 == 0) {
    uVar5 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,2,1);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_005cf210();
    piVar3 = (int *)Tcl_NewIntObj(uVar2);
    *piVar3 = *piVar3 + 1;
    iVar1 = *piVar3;
    if (local_30 != 0) {
      Tcl_SetObjResult(local_30,piVar3);
      iVar1 = *piVar3;
    }
    *piVar3 = iVar1 + -1;
    if (iVar1 + -1 < 1) {
      TclFreeObj(piVar3);
    }
    uVar2 = 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar2;
}

