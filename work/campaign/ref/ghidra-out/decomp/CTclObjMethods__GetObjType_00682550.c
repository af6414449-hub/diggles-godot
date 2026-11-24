
undefined4
CTclObjMethods__GetObjType
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int local_34;
  int local_24;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007111bd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca76f0) &&
     (FUN_006cebf4(&DAT_00ca76f0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca76f0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca76f4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::GetObjType()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca76f0);
  }
  iVar3 = DAT_00ca76f4;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca76f4 * 0x40);
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
  iVar1 = FUN_005c71c0(param_4,2,1);
  if (iVar1 == 0) {
    uVar4 = 1;
    goto LAB_0068269d;
  }
  piVar2 = (int *)FUN_005ffe40();
  if (*piVar2 + 0xc == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)Tcl_NewStringObj(*piVar2 + 0xc,0xffffffff);
    *piVar2 = *piVar2 + 1;
  }
  if (local_34 == 0) {
    if (piVar2 != (int *)0x0) goto LAB_00682675;
  }
  else if (piVar2 == (int *)0x0) {
    Tcl_ResetResult(local_34);
  }
  else {
    Tcl_SetObjResult(local_34,piVar2);
LAB_00682675:
    *piVar2 = *piVar2 + -1;
    if (*piVar2 < 1) {
      TclFreeObj(piVar2);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  uVar4 = 0;
LAB_0068269d:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_24 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

