
undefined4
CTclGlobalMethods__SMGetZone(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined8 uVar7;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f0d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7378) &&
     (FUN_006cebf4(&DAT_00ca7378,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7378 == -1)) {
    iVar2 = DAT_00783650 * 0x40;
    DAT_00ca737c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclGlobalMethods::SMGetZone()";
    *(int *)(&DAT_00773650 + iVar2) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7378);
  }
  iVar2 = DAT_00ca737c;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca737c * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar7 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  if (param_3 != 2) {
    FUN_006bc8f0(1);
    uVar4 = 1;
    goto LAB_0065ff1e;
  }
  FUN_004298b0(2,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005f8080();
  if (local_20 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_28;
    if (local_24 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_28 + 1;
  }
  piVar6 = (int *)*puVar5;
  if (piVar6 == (int *)0x0) {
    param_3 = FUN_005fcdf0(0);
  }
  else {
    *piVar6 = *piVar6 + 1;
    iVar2 = Tcl_GetIntFromObj(0,piVar6,&local_14);
    if (iVar2 == 1) {
      local_14 = 0;
    }
    param_3 = FUN_005fcdf0(local_14);
    *piVar6 = *piVar6 + -1;
    if (*piVar6 < 1) {
      TclFreeObj(piVar6);
    }
  }
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar3[1] = 0x14;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)(piVar3 + 3) = 0;
  piVar3[3] = 0x656e6f6e;
  *(undefined1 *)(piVar3 + 4) = 0;
  piVar3[2] = 4;
  *piVar3 = 1;
  local_8 = CONCAT31(local_8._1_3_,3);
  piVar6 = piVar3;
  if (param_3 != 0xffffffff) {
    if (*(uint *)(iVar1 + 0x70) <= param_3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar1 = *(int *)(iVar1 + 0x6c);
    piVar6 = *(int **)(iVar1 + param_3 * 8);
    if (piVar6 != (int *)0x0) {
      *piVar6 = *piVar6 + 1;
    }
    *piVar3 = *piVar3 + -1;
    if (*piVar3 == 0) {
      FUN_006ba940();
    }
    piVar6[2] = *(int *)(*(int *)(iVar1 + param_3 * 8) + 8);
  }
  if (piVar6 + 3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)Tcl_NewStringObj(piVar6 + 3,0xffffffff);
    *piVar3 = *piVar3 + 1;
  }
  if (local_38 == 0) {
    if (piVar3 != (int *)0x0) goto LAB_0065fed3;
  }
  else if (piVar3 == (int *)0x0) {
    Tcl_ResetResult(local_38);
  }
  else {
    Tcl_SetObjResult(local_38,piVar3);
LAB_0065fed3:
    *piVar3 = *piVar3 + -1;
    if (*piVar3 < 1) {
      TclFreeObj(piVar3);
    }
  }
  uVar4 = 0;
  local_8._0_1_ = 4;
  *piVar6 = *piVar6 + -1;
  if (*piVar6 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
LAB_0065ff1e:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

