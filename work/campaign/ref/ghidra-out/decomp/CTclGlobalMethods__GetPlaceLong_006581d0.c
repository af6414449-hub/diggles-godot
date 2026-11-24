
undefined4
CTclGlobalMethods__GetPlaceLong
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  double dVar9;
  undefined8 uVar10;
  int local_5c;
  undefined4 *local_4c;
  uint local_48;
  int local_44;
  undefined1 local_3c [4];
  undefined4 local_38;
  int *piStack_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  float local_20;
  int *local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar3 = (uint)param_3;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ec0d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca72b0) &&
     (FUN_006cebf4(&DAT_00ca72b0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca72b0 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca72b4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::GetPlaceLong()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca72b0);
  }
  iVar7 = DAT_00ca72b4;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca72b4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if (2 < (int)param_3 - 3U) {
    FUN_006bc8f0(2);
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_004297b0(0);
    if (local_4c != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  if (local_44 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_4c;
    if (local_48 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_48 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_4c + 1;
  }
  piVar6 = (int *)*puVar5;
  dVar9 = 0.0;
  local_20 = 0.0;
  if (piVar6 == (int *)0x0) {
LAB_006583ba:
    local_14 = 0.0;
    local_18 = 0.0;
  }
  else {
    iVar4 = *piVar6;
    *piVar6 = iVar4 + 1;
    if (iVar4 + 1 < 1) {
      TclFreeObj(piVar6);
    }
    iVar4 = Tcl_ListObjIndex(0,piVar6,0,&local_2c);
    if (((iVar4 != 0) || (iVar4 = Tcl_ListObjIndex(0,piVar6,1,&local_30), iVar4 != 0)) ||
       (iVar4 = Tcl_ListObjIndex(0,piVar6,2,&piStack_34), iVar4 != 0)) goto LAB_006583ba;
    local_28 = local_2c;
    if (local_2c != (int *)0x0) {
      *local_2c = *local_2c + 1;
    }
    local_24 = local_30;
    if (local_30 != (int *)0x0) {
      *local_30 = *local_30 + 1;
    }
    local_1c = piStack_34;
    if (piStack_34 != (int *)0x0) {
      *piStack_34 = *piStack_34 + 1;
    }
    FUN_006baf40();
    local_18 = (float)dVar9;
    dVar9 = (double)CONCAT44((int)((ulonglong)dVar9 >> 0x20),local_18);
    FUN_006baf40();
    local_14 = (float)dVar9;
    FUN_006baf40();
    FUN_006bad60();
    FUN_006bad60();
    FUN_006bad60();
  }
  if (local_44 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_4c;
    if (local_48 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_48 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_4c + 2;
  }
  piVar8 = (int *)*puVar5;
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + 1, piVar8 != (int *)0x0)) {
    *piVar8 = *piVar8 + 1;
  }
  if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
    TclFreeObj(piVar6);
  }
  if (piVar8 == (int *)0x0) {
    local_20 = 0.0;
  }
  else {
    *piVar8 = *piVar8 + -1;
    if (*piVar8 < 1) {
      TclFreeObj(piVar8);
    }
    iVar4 = Tcl_GetDoubleFromObj(0,piVar8,&local_38);
    if (iVar4 != 1) {
      local_20 = (float)(double)CONCAT44(piStack_34,local_38);
    }
  }
  local_1c = (int *)((uint)local_1c & 0xffffff00);
  piVar6 = piVar8;
  if (3 < (int)param_3) {
    puVar5 = (undefined4 *)FUN_004295e0(3);
    piVar6 = (int *)*puVar5;
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + 1, piVar6 != (int *)0x0)) {
      *piVar6 = *piVar6 + 1;
    }
    if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
      TclFreeObj(piVar8);
    }
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      *piVar6 = *piVar6 + -1;
      if (*piVar6 < 1) {
        TclFreeObj(piVar6);
      }
      iVar4 = Tcl_GetBooleanFromObj(0,piVar6,&piStack_34);
      if (iVar4 != 1) {
        local_1c = (int *)CONCAT31(local_1c._1_3_,piStack_34 != (int *)0x0);
        goto LAB_006584d3;
      }
    }
    local_1c = (int *)((uint)local_1c & 0xffffff00);
  }
LAB_006584d3:
  uVar2 = (uint)param_3 >> 8;
  param_3 = (int *)(uVar2 << 8);
  piVar8 = piVar6;
  if (4 < (int)uVar3) {
    puVar5 = (undefined4 *)FUN_004295e0(4);
    piVar8 = (int *)*puVar5;
    if (piVar8 != (int *)0x0) {
      *piVar8 = *piVar8 + 2;
    }
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
      TclFreeObj(piVar6);
    }
    if (piVar8 == (int *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      *piVar8 = *piVar8 + -1;
      if (*piVar8 < 1) {
        TclFreeObj(piVar8);
      }
      iVar4 = Tcl_GetBooleanFromObj(0,piVar8,&piStack_34);
      if (iVar4 != 1) {
        param_3 = (int *)CONCAT31(SUB43(uVar3,1),piStack_34 != (int *)0x0);
        goto LAB_00658538;
      }
    }
    param_3 = (int *)(uVar2 << 8);
  }
LAB_00658538:
  CPlaceFinder__FindPlaceLongRange(local_3c,(int)local_18,(int)local_14,local_1c,param_3);
  piVar6 = (int *)FUN_006badc0(local_3c);
  if (local_5c != 0) {
    if (*piVar6 == 0) {
      Tcl_ResetResult(local_5c);
    }
    else {
      Tcl_SetObjResult(local_5c,*piVar6);
    }
  }
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    TclFreeObj(param_3);
  }
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    TclFreeObj(piVar8);
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_4c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

