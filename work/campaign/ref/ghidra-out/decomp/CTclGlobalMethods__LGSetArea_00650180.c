
undefined4
CTclGlobalMethods__LGSetArea(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  float fVar9;
  undefined8 uVar10;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  undefined4 *local_54;
  uint local_50;
  int local_4c;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  undefined4 *local_28;
  undefined4 local_24;
  int *local_20;
  float local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e61d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca71f0) &&
     (FUN_006cebf4(&DAT_00ca71f0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca71f0 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca71f4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::LGSetArea()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca71f0);
  }
  iVar6 = DAT_00ca71f4;
  local_28 = &DAT_00ca71f4;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca71f4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 5) {
    local_24 = FUN_0058a820();
    if (local_4c < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_54;
      if (local_50 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_54;
      }
    }
    else {
      if (local_50 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_54 + 4;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_4c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_54;
      if (local_50 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_54;
      }
    }
    else {
      if (local_50 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_54 + 3;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (local_4c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_54;
      if (local_50 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_54;
      }
    }
    else {
      if (local_50 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_54 + 2;
    }
    local_20 = (int *)*puVar5;
    if (local_20 != (int *)0x0) {
      *local_20 = *local_20 + 1;
    }
    if (local_4c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_54;
      if (local_50 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_54;
      }
    }
    else {
      if (local_50 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_54 + 1;
    }
    piVar3 = (int *)*puVar5;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    if (piVar1 == (int *)0x0) {
      local_14 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,piVar1,&local_30);
      if (iVar4 == 1) {
        local_14 = 0.0;
      }
      else {
        local_14 = (float)local_30;
      }
    }
    if (piVar2 == (int *)0x0) {
      local_1c = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,piVar2,&local_38);
      if (iVar4 == 1) {
        local_1c = 0.0;
      }
      else {
        local_1c = (float)local_38;
      }
    }
    local_18 = 0.0;
    if (local_20 != (int *)0x0) {
      iVar4 = Tcl_GetDoubleFromObj(0,local_20,&local_40);
      if (iVar4 == 1) {
        local_18 = 0.0;
      }
      else {
        local_18 = (float)local_40;
      }
    }
    if (piVar3 == (int *)0x0) {
      fVar9 = 0.0;
      piVar7 = (int *)0x0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,piVar3,&local_48);
      piVar7 = piVar3;
      if (iVar4 == 1) {
        fVar9 = 0.0;
      }
      else {
        fVar9 = (float)local_48;
      }
    }
    local_64 = (int)fVar9;
    local_58 = (int)local_14;
    local_60 = (int)local_18;
    local_5c = (int)local_1c;
    FUN_00583ac0(&local_64,1);
    if ((piVar7 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
    if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 < 1)) {
      TclFreeObj(local_20);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar8 = 0;
  }
  else {
    FUN_006bc8f0(4);
    uVar8 = 1;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_54 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

