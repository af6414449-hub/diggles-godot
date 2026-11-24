
undefined4 CTclGlobalMethods__SMScan(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined8 uVar5;
  int local_2c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f28d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca73b8) &&
     (FUN_006cebf4(&DAT_00ca73b8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca73b8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca73bc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::SMScan()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca73b8);
  }
  iVar4 = DAT_00ca73bc;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca73bc * 0x40);
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
  local_8._0_1_ = 1;
  iVar2 = FUN_005f8080();
  if ((((*(int *)(iVar2 + 0x88) == 0) || (*(int *)(iVar2 + 0x8c) == 0)) ||
      (*(int *)(iVar2 + 0x90) == 0)) || (*(char *)(iVar2 + 0x94) != '\0')) {
    piVar3 = (int *)Tcl_NewIntObj(0);
    *piVar3 = *piVar3 + 1;
    iVar2 = *piVar3;
    if (local_2c != 0) {
      Tcl_SetObjResult(local_2c,piVar3);
      iVar2 = *piVar3;
    }
    *piVar3 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar3);
    }
  }
  else {
    local_14 = (int *)0x0;
    local_8._0_1_ = 2;
    piVar3 = (int *)Tcl_NewListObj(0,0);
    if ((piVar3 != (int *)0x0) && (iVar2 = *piVar3, *piVar3 = iVar2, iVar2 < 1)) {
      TclFreeObj(piVar3);
    }
    iVar2 = FUN_005f8080();
    piVar3 = (int *)Tcl_NewIntObj((int)(*(int *)(iVar2 + 0x8c) +
                                       (*(int *)(iVar2 + 0x8c) >> 0x1f & 3U)) >> 2);
    *piVar3 = *piVar3 + 1;
    local_18 = piVar3;
    FUN_006bb930(&local_18);
    *piVar3 = *piVar3 + -1;
    if (*piVar3 < 1) {
      TclFreeObj(piVar3);
    }
    iVar2 = FUN_005f8080();
    piVar3 = (int *)Tcl_NewIntObj((int)(*(int *)(iVar2 + 0x90) +
                                       (*(int *)(iVar2 + 0x90) >> 0x1f & 3U)) >> 2);
    *piVar3 = *piVar3 + 1;
    local_18 = piVar3;
    FUN_006bb930(&local_18);
    *piVar3 = *piVar3 + -1;
    if (*piVar3 < 1) {
      TclFreeObj(piVar3);
    }
    piVar3 = local_14;
    if (local_2c != 0) {
      if (local_14 == (int *)0x0) {
        Tcl_ResetResult(local_2c);
      }
      else {
        Tcl_SetObjResult(local_2c,local_14);
      }
    }
    iVar2 = FUN_005f8080();
    *(undefined1 *)(iVar2 + 0x94) = 1;
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

