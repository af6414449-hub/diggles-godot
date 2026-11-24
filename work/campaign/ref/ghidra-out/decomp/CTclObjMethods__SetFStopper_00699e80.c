
undefined4
CTclObjMethods__SetFStopper(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  int *piVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  undefined4 *local_48;
  uint local_44;
  int local_40;
  double local_3c;
  int *local_34;
  int *local_30;
  undefined4 *local_2c;
  int local_28;
  int *local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711d1d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7aa8) &&
     (FUN_006cebf4(&DAT_00ca7aa8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7aa8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7aac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::SetFStopper()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7aa8);
  }
  iVar5 = DAT_00ca7aac;
  local_2c = &DAT_00ca7aac;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7aac * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
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
  uVar6 = param_4;
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar1 != (int *)&DAT_00000005) {
    FUN_006bc8f0(4);
    uVar6 = 1;
    goto LAB_0069a2d7;
  }
  local_28 = FUN_005c71c0(uVar6,5,1);
  if (local_28 == 0) {
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_48 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("invalid object",piVar1);
    uVar6 = 1;
    goto LAB_0069a2d7;
  }
  if (local_40 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_48;
    if (local_44 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_44 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_48 + 2;
  }
  piVar1 = (int *)*puVar4;
  local_30 = piVar1;
  if (piVar1 == (int *)0x0) {
LAB_0069a088:
    local_20 = 0;
    if (piVar1 != (int *)0x0) goto LAB_0069a093;
LAB_0069a0e0:
    local_1c = 0;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar3 = Tcl_ListObjIndex(0,piVar1,0,&param_3);
    piVar2 = param_3;
    if ((iVar3 != 0) || (param_3 == (int *)0x0)) goto LAB_0069a088;
    *param_3 = *param_3 + 1;
    iVar3 = Tcl_GetIntFromObj(0,param_3,&param_3);
    *piVar2 = *piVar2 + -1;
    local_20 = -(uint)(iVar3 != 1) & (uint)param_3;
    if (*piVar2 < 1) {
      TclFreeObj(piVar2);
    }
LAB_0069a093:
    iVar3 = Tcl_ListObjIndex(0,piVar1,1,&param_3);
    piVar2 = param_3;
    if ((iVar3 != 0) || (param_3 == (int *)0x0)) goto LAB_0069a0e0;
    *param_3 = *param_3 + 1;
    iVar3 = Tcl_GetIntFromObj(0,param_3,&param_3);
    *piVar2 = *piVar2 + -1;
    local_1c = -(uint)(iVar3 != 1) & (uint)param_3;
    if (*piVar2 < 1) {
      TclFreeObj(piVar2);
    }
  }
  if (local_40 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_48;
    if (local_44 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_44 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_48 + 3;
  }
  piVar2 = (int *)*puVar4;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  local_34 = piVar2;
  if (((piVar2 == (int *)0x0) || (iVar3 = Tcl_ListObjIndex(0,piVar2,0,&param_3), iVar3 != 0)) ||
     (local_14 = param_3, param_3 == (int *)0x0)) {
    local_18 = 0;
    if (piVar2 != (int *)0x0) goto LAB_0069a19c;
LAB_0069a1ef:
    local_14 = (int *)0x0;
  }
  else {
    *param_3 = *param_3 + 1;
    iVar3 = Tcl_GetIntFromObj(0,param_3,&param_3);
    local_18 = -(uint)(iVar3 != 1) & (uint)param_3;
    *local_14 = *local_14 + -1;
    if (*local_14 < 1) {
      TclFreeObj(local_14);
    }
LAB_0069a19c:
    iVar3 = Tcl_ListObjIndex(0,piVar2,1,&param_3);
    if ((iVar3 != 0) || (local_24 = param_3, param_3 == (int *)0x0)) goto LAB_0069a1ef;
    *param_3 = *param_3 + 1;
    iVar3 = Tcl_GetIntFromObj(0,param_3,&param_3);
    local_14 = (int *)(-(uint)(iVar3 != 1) & (uint)param_3);
    *local_24 = *local_24 + -1;
    if (*local_24 < 1) {
      TclFreeObj(local_24);
    }
  }
  if (local_40 < 5) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_48;
    if (local_44 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_44 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_48 + 4;
  }
  local_24 = (int *)*puVar4;
  if (local_24 == (int *)0x0) {
    pcVar7 = TclFreeObj_exref;
    piVar8 = (int *)0x0;
  }
  else {
    *local_24 = *local_24 + 1;
    iVar3 = Tcl_GetDoubleFromObj(0,local_24,&local_3c);
    pcVar7 = TclFreeObj_exref;
    if (iVar3 == 1) {
      param_3 = (int *)0x0;
    }
    else {
      param_3 = (int *)(float)local_3c;
    }
    *local_24 = *local_24 + -1;
    piVar8 = param_3;
    if (*local_24 < 1) {
      TclFreeObj(local_24);
      piVar8 = param_3;
    }
  }
  uVar6 = *(undefined4 *)(local_28 + 0xdc);
  uVar10 = local_20;
  uVar11 = local_1c;
  uVar12 = local_18;
  piVar13 = local_14;
  FUN_0057d980(uVar6,local_20,local_1c,local_18,local_14,piVar8);
  FUN_0057bfb0(uVar6,uVar10,uVar11,uVar12,piVar13,piVar8);
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    (*pcVar7)(piVar2);
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar7)(piVar1);
  }
  uVar6 = 0;
LAB_0069a2d7:
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_48 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

