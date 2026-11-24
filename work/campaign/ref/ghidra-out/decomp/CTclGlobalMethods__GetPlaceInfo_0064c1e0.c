
undefined4
CTclGlobalMethods__GetPlaceInfo
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined8 uVar5;
  int local_38;
  int local_28;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e0a5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7160) &&
     (FUN_006cebf4(&DAT_00ca7160,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7160 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7164 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::GetPlaceInfo()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7160);
  }
  iVar4 = DAT_00ca7164;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7164 * 0x40);
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
  FUN_004298b0(param_3,param_4);
  local_14 = (int *)0x0;
  piVar3 = (int *)Tcl_NewListObj(0,0);
  if ((piVar3 != (int *)0x0) && (iVar2 = *piVar3, *piVar3 = iVar2, iVar2 < 1)) {
    TclFreeObj(piVar3);
  }
  piVar3 = (int *)Tcl_NewBooleanObj(*(undefined1 *)(DAT_00772400 + 0xa3e0));
  *piVar3 = *piVar3 + 1;
  local_18 = piVar3;
  FUN_006bb930(&local_18);
  *piVar3 = *piVar3 + -1;
  if (*piVar3 < 1) {
    TclFreeObj(piVar3);
  }
  piVar3 = (int *)Tcl_NewBooleanObj(*(undefined1 *)(DAT_00772400 + 0xa3e2));
  *piVar3 = *piVar3 + 1;
  local_18 = piVar3;
  FUN_006bb930(&local_18);
  *piVar3 = *piVar3 + -1;
  if (*piVar3 < 1) {
    TclFreeObj(piVar3);
  }
  piVar3 = (int *)Tcl_NewBooleanObj(*(undefined1 *)(DAT_00772400 + 0xa3e1));
  *piVar3 = *piVar3 + 1;
  local_18 = piVar3;
  FUN_006bb930(&local_18);
  *piVar3 = *piVar3 + -1;
  if (*piVar3 < 1) {
    TclFreeObj(piVar3);
  }
  piVar3 = local_14;
  if (local_38 != 0) {
    if (local_14 == (int *)0x0) {
      Tcl_ResetResult(local_38);
      goto LAB_0064c398;
    }
    Tcl_SetObjResult(local_38,local_14);
  }
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
    TclFreeObj(piVar3);
  }
LAB_0064c398:
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_28 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

