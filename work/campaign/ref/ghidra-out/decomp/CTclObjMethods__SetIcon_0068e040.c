
undefined4
CTclObjMethods__SetIcon(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined4 *local_58;
  uint local_54;
  int local_50;
  double local_4c;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  undefined4 *local_34;
  int *local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int *local_1c;
  uint local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071188d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca78e8) &&
     (FUN_006cebf4(&DAT_00ca78e8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca78e8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca78ec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::SetIcon()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca78e8);
  }
  iVar5 = DAT_00ca78ec;
  local_34 = &DAT_00ca78ec;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca78ec * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_2c = FUN_005c71c0(param_4,6,1);
  if (local_2c == 0) {
    uVar7 = 1;
  }
  else {
    if (local_50 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_58 + 2;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_38 = piVar1;
    if (local_50 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_58 + 3;
    }
    piVar2 = (int *)*puVar4;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_3c = piVar2;
    if (local_50 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_58 + 4;
    }
    local_40 = (int *)*puVar4;
    if (local_40 != (int *)0x0) {
      *local_40 = *local_40 + 1;
    }
    local_1c = local_40;
    if (local_50 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_58 + 5;
    }
    local_44 = (int *)*puVar4;
    if (local_44 != (int *)0x0) {
      *local_44 = *local_44 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    local_30 = local_44;
    if (local_44 == (int *)0x0) {
      local_14 = 0.0;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,local_44,&local_4c);
      if (iVar3 == 1) {
        local_14 = 0.0;
      }
      else {
        local_14 = (float)local_4c;
      }
    }
    if (local_1c == (int *)0x0) {
      uVar6 = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,local_1c,&local_20);
      uVar6 = -(uint)(iVar3 != 1) & local_20;
    }
    if (piVar2 == (int *)0x0) {
      local_18 = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_24);
      local_18 = -(uint)(iVar3 != 1) & local_24;
    }
    if (piVar1 == (int *)0x0) {
      local_28 = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_28);
      local_28 = -(uint)(iVar3 != 1) & local_28;
    }
    FUN_005dc850(local_28,local_2c,local_18,uVar6,local_14);
    if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 < 1)) {
      TclFreeObj(local_30);
    }
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c < 1)) {
      TclFreeObj(local_1c);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar7 = 0;
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_58 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

