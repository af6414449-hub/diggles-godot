
undefined4
CTclGlobalMethods__PlaceLockCheck
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  code *pcVar8;
  undefined8 uVar9;
  int local_48;
  undefined1 local_38 [12];
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  double local_20;
  undefined4 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ebcd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca72a8) &&
     (FUN_006cebf4(&DAT_00ca72a8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca72a8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca72ac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::PlaceLockCheck()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca72a8);
  }
  iVar5 = DAT_00ca72ac;
  local_18 = &DAT_00ca72ac;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca72ac * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  if ((param_3 != 3) && (param_3 != 4)) {
    FUN_006bc8f0(2);
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_24 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_2c;
    if (local_28 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_2c;
    }
  }
  else {
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_2c + 1;
  }
  piVar4 = (int *)*puVar7;
  local_14 = piVar4;
  if (piVar4 == (int *)0x0) {
    FUN_006bafe0(local_38);
  }
  else {
    *piVar4 = *piVar4 + 1;
    FUN_006bafe0(local_38);
    *piVar4 = *piVar4 + -1;
    if (*piVar4 < 1) {
      TclFreeObj(piVar4);
    }
  }
  if (local_24 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_2c;
    if (local_28 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_2c;
    }
  }
  else {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_2c + 2;
  }
  piVar4 = (int *)*puVar7;
  if (piVar4 == (int *)0x0) {
    local_14 = (int *)0x0;
  }
  else {
    *piVar4 = *piVar4 + 1;
    iVar3 = Tcl_GetDoubleFromObj(0,piVar4,&local_20);
    if (iVar3 == 1) {
      local_14 = (int *)0x0;
    }
    else {
      local_14 = (int *)(float)local_20;
    }
    *piVar4 = *piVar4 + -1;
    if (*piVar4 < 1) {
      TclFreeObj(piVar4);
    }
  }
  uVar6 = 0xfffffffe;
  pcVar8 = TclFreeObj_exref;
  if (param_3 == 4) {
    if (local_24 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_2c;
      }
    }
    else {
      if (local_28 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_2c + 3;
    }
    piVar4 = (int *)*puVar7;
    if (piVar4 == (int *)0x0) {
      uVar6 = 0;
      pcVar8 = TclFreeObj_exref;
    }
    else {
      *piVar4 = *piVar4 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar4,&param_3);
      pcVar8 = TclFreeObj_exref;
      *piVar4 = *piVar4 + -1;
      uVar6 = -(uint)(iVar3 != 1) & param_3;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
  }
  uVar2 = FUN_005aaaf0(local_38,uVar6);
  piVar4 = (int *)Tcl_NewBooleanObj(uVar2);
  *piVar4 = *piVar4 + 1;
  iVar3 = *piVar4;
  if (local_48 != 0) {
    Tcl_SetObjResult(local_48,piVar4);
    iVar3 = *piVar4;
  }
  *piVar4 = iVar3 + -1;
  if (iVar3 + -1 < 1) {
    (*pcVar8)(piVar4);
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

