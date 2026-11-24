
undefined4
CTclGlobalMethods__SMGetTempPos
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  int local_3c;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070eb3d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca73a8) &&
     (FUN_006cebf4(&DAT_00ca73a8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca73a8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca73ac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::SMGetTempPos()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca73a8);
  }
  iVar5 = DAT_00ca73ac;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca73ac * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar1 != (int *)0x2) {
    FUN_006bc8f0(1);
    uVar7 = 1;
    goto LAB_0066128a;
  }
  if (local_24 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_2c;
    if (local_28 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_2c + 1;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8._0_1_ = 3;
  if (piVar1 == (int *)0x0) {
    ppuVar3 = &PTR_0071ce50;
  }
  else {
    ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  FUN_006b8fb0(ppuVar3);
  local_8 = CONCAT31(local_8._1_3_,4);
  iVar2 = FUN_005f8080();
  local_14 = 0;
  local_18 = (int *)FUN_005f93d0(&param_3);
  if (local_18 == (int *)0xffffffff) {
    uVar7 = 0;
  }
  else {
    if (*(int **)(iVar2 + 0xc) <= local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar7 = *(undefined4 *)((int)local_18 * 100 + 0xc + *(int *)(iVar2 + 8));
    local_14 = *(undefined4 *)((int)local_18 * 100 + 0x10 + *(int *)(iVar2 + 8));
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
    FUN_006ba940();
  }
  param_3 = (int *)0x0;
  piVar4 = (int *)Tcl_NewIntObj(uVar7);
  *piVar4 = *piVar4 + 1;
  local_18 = piVar4;
  FUN_006bb930(&local_18);
  *piVar4 = *piVar4 + -1;
  if (*piVar4 < 1) {
    TclFreeObj(piVar4);
  }
  piVar4 = (int *)Tcl_NewIntObj(local_14);
  *piVar4 = *piVar4 + 1;
  local_18 = piVar4;
  FUN_006bb930(&local_18);
  *piVar4 = *piVar4 + -1;
  if (*piVar4 < 1) {
    TclFreeObj(piVar4);
  }
  piVar4 = param_3;
  if (local_3c == 0) {
LAB_00661267:
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
  }
  else {
    if (param_3 != (int *)0x0) {
      Tcl_SetObjResult(local_3c,param_3);
      goto LAB_00661267;
    }
    Tcl_ResetResult(local_3c);
  }
  uVar7 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_0066128a:
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

