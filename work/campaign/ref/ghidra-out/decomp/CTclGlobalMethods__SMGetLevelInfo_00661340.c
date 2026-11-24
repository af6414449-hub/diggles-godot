
undefined4
CTclGlobalMethods__SMGetLevelInfo
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  code *pcVar7;
  undefined8 uVar8;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f245;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca73b0) &&
     (FUN_006cebf4(&DAT_00ca73b0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca73b0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca73b4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::SMGetLevelInfo()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca73b0);
  }
  iVar3 = DAT_00ca73b4;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca73b4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar4;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  if (param_3 != (int *)0x3) {
    FUN_006bc8f0(2);
    uVar4 = 1;
    goto LAB_0066163e;
  }
  FUN_004298b0(3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  param_3 = (int *)FUN_005f8080();
  if (local_28 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_30 + 2;
  }
  piVar1 = (int *)*puVar5;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if (local_28 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_30 + 1;
  }
  piVar6 = (int *)*puVar5;
  if (piVar6 != (int *)0x0) {
    *piVar6 = *piVar6 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  if (piVar1 == (int *)0x0) {
    local_14 = 0;
  }
  else {
    iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_14);
    local_14 = -(uint)(iVar2 != 1) & local_14;
  }
  iVar2 = (int)param_3;
  if (piVar6 == (int *)0x0) {
    FUN_005fac90(0,local_14);
    pcVar7 = TclFreeObj_exref;
  }
  else {
    iVar2 = Tcl_GetIntFromObj(0,piVar6,&local_18);
    if (iVar2 == 1) {
      local_18 = 0;
    }
    FUN_005fac90(local_18,local_14);
    *piVar6 = *piVar6 + -1;
    pcVar7 = TclFreeObj_exref;
    iVar2 = (int)param_3;
    if (*piVar6 < 1) {
      TclFreeObj(piVar6);
      iVar2 = (int)param_3;
    }
  }
  local_8._0_1_ = 2;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar7)(piVar1);
  }
  param_3 = (int *)FUN_006ba810(0x19);
  param_3[1] = 0x14;
  param_3[2] = -1;
  *(undefined1 *)(param_3 + 3) = 0;
  *param_3 = 1;
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_006b9040(&param_3,"%i %i %i %i %s",*(undefined4 *)(iVar2 + 0x40),*(undefined4 *)(iVar2 + 0x44)
               ,*(undefined4 *)(iVar2 + 0x38),*(undefined4 *)(iVar2 + 0x3c),
               *(int *)(iVar2 + 0x50) + 0xc);
  piVar1 = param_3;
  if (param_3 + 3 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)Tcl_NewStringObj(param_3 + 3,0xffffffff);
    *piVar6 = *piVar6 + 1;
  }
  if (local_40 == 0) {
    if (piVar6 != (int *)0x0) goto LAB_006615ef;
  }
  else if (piVar6 == (int *)0x0) {
    Tcl_ResetResult(local_40);
  }
  else {
    Tcl_SetObjResult(local_40,piVar6);
LAB_006615ef:
    *piVar6 = *piVar6 + -1;
    if (*piVar6 < 1) {
      TclFreeObj(piVar6);
    }
  }
  uVar4 = 0;
  local_8._0_1_ = 6;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
LAB_0066163e:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

