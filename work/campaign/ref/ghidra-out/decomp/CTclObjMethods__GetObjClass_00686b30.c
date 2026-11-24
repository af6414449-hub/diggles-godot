
undefined4
CTclObjMethods__GetObjClass
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
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
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca77b8) &&
     (FUN_006cebf4(&DAT_00ca77b8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca77b8 == -1)) {
    iVar2 = DAT_00783650 * 0x40;
    DAT_00ca77bc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclObjMethods::GetObjClass()";
    *(int *)(&DAT_00773650 + iVar2) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca77b8);
  }
  iVar2 = DAT_00ca77bc;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca77bc * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar5 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,2,1);
  if (iVar1 == 0) {
    uVar4 = 1;
    goto LAB_00686c61;
  }
  iVar1 = *(int *)(*(int *)(iVar1 + 0xd4) + 0xc) + 0xc;
  if (iVar1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)Tcl_NewStringObj(iVar1,0xffffffff);
    *piVar3 = *piVar3 + 1;
  }
  if (local_30 == 0) {
    if (piVar3 != (int *)0x0) goto LAB_00686c4e;
  }
  else if (piVar3 == (int *)0x0) {
    Tcl_ResetResult(local_30);
  }
  else {
    Tcl_SetObjResult(local_30,piVar3);
LAB_00686c4e:
    *piVar3 = *piVar3 + -1;
    if (*piVar3 < 1) {
      TclFreeObj(piVar3);
    }
  }
  uVar4 = 0;
LAB_00686c61:
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
  return uVar4;
}

