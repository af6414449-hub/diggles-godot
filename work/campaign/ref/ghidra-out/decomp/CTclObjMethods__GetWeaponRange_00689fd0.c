
undefined4
CTclObjMethods__GetWeaponRange
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  int local_3c;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f11d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7828) &&
     (FUN_006cebf4(&DAT_00ca7828,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7828 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca782c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::GetWeaponRange()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7828);
  }
  iVar5 = DAT_00ca782c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca782c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
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
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005c71c0(param_4,2,1);
  if (local_24 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_2c;
    if (local_28 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_2c + 1;
  }
  piVar4 = (int *)*puVar7;
  if (piVar4 == (int *)0x0) {
    local_18 = (int *)0x0;
    iVar2 = FUN_005bbb20();
    piVar3 = *(int **)(iVar2 + 0xc);
  }
  else {
    *piVar4 = *piVar4 + 1;
    iVar2 = Tcl_GetIntFromObj(0,piVar4,&local_14);
    if (iVar2 == 1) {
      local_18 = (int *)0x0;
    }
    else {
      local_18 = local_14;
    }
    iVar2 = FUN_005bbb20();
    local_14 = *(int **)(iVar2 + 0xc);
    *piVar4 = *piVar4 + -1;
    piVar3 = local_14;
    if (*piVar4 < 1) {
      TclFreeObj(piVar4);
      piVar3 = local_14;
    }
  }
  if ((int)local_18 < (int)piVar3) {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_2c + 1;
    }
    piVar4 = (int *)*puVar7;
    if (piVar4 == (int *)0x0) {
      uVar6 = 0;
    }
    else {
      *piVar4 = *piVar4 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar4,&local_14);
      uVar6 = -(uint)(iVar2 != 1) & (uint)local_14;
    }
    iVar2 = FUN_005bbb20();
    if (*(uint *)(iVar2 + 0xc) <= uVar6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar3 = (int *)FUN_006bad90();
    if (local_3c != 0) {
      if (*piVar3 == 0) {
        Tcl_ResetResult(local_3c);
      }
      else {
        Tcl_SetObjResult(local_3c,*piVar3);
      }
    }
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
      TclFreeObj(local_18);
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
  }
  else {
    piVar4 = (int *)FUN_006bad90();
    if (local_3c != 0) {
      if (*piVar4 == 0) {
        Tcl_ResetResult(local_3c);
      }
      else {
        Tcl_SetObjResult(local_3c,*piVar4);
      }
    }
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
      TclFreeObj(local_18);
    }
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

