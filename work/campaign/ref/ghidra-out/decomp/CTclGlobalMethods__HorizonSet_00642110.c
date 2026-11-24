
undefined4
CTclGlobalMethods__HorizonSet(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  float fVar9;
  float fVar10;
  undefined8 uVar11;
  undefined1 local_a8 [28];
  double local_8c;
  double local_84;
  double local_7c;
  double local_74;
  double local_6c;
  int *local_64;
  int *local_60;
  int *local_5c;
  int *local_58;
  int *local_54;
  undefined4 *local_50;
  int *local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  float local_3c;
  float local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 *local_28;
  int *local_24;
  int *local_20;
  undefined4 *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070da20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7070) &&
     (FUN_006cebf4(&DAT_00ca7070,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7070 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7074 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::HorizonSet()";
    *(int *)(&DAT_00773650 + iVar5) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7070);
  }
  iVar5 = DAT_00ca7074;
  local_50 = &DAT_00ca7074;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7074 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar4 == 0) {
    uVar11 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 7) {
    if (local_14 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_1c;
      }
    }
    else {
      if (local_18 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_1c + 1;
    }
    local_4c = (int *)*puVar6;
    if (local_4c != (int *)0x0) {
      *local_4c = *local_4c + 1;
    }
    local_20 = local_4c;
    if (local_14 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_1c;
      }
    }
    else {
      if (local_18 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_1c + 2;
    }
    local_54 = (int *)*puVar6;
    if (local_54 != (int *)0x0) {
      *local_54 = *local_54 + 1;
    }
    local_44 = local_54;
    if (local_14 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_1c;
      }
    }
    else {
      if (local_18 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_1c + 3;
    }
    local_58 = (int *)*puVar6;
    if (local_58 != (int *)0x0) {
      *local_58 = *local_58 + 1;
    }
    local_40 = local_58;
    if (local_14 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_1c;
      }
    }
    else {
      if (local_18 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_1c + 4;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_5c = piVar2;
    if (local_14 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_1c;
      }
    }
    else {
      if (local_18 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_1c + 5;
    }
    piVar3 = (int *)*puVar6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_60 = piVar3;
    if (local_14 < 7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_1c;
      }
    }
    else {
      if (local_18 < 7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_1c + 6;
    }
    local_64 = (int *)*puVar6;
    if (local_64 != (int *)0x0) {
      *local_64 = *local_64 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,8);
    local_48 = local_64;
    if (local_64 == (int *)0x0) {
      local_3c = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,local_64,&local_6c);
      if (iVar4 == 1) {
        local_3c = 0.0;
      }
      else {
        local_3c = (float)local_6c;
      }
    }
    if (piVar3 == (int *)0x0) {
      local_38 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,piVar3,&local_74);
      if (iVar4 == 1) {
        local_38 = 0.0;
      }
      else {
        local_38 = (float)local_74;
      }
    }
    if (piVar2 == (int *)0x0) {
      fVar10 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,piVar2,&local_7c);
      if (iVar4 == 1) {
        fVar10 = 0.0;
      }
      else {
        fVar10 = (float)local_7c;
      }
    }
    fVar9 = 0.0;
    DAT_00772dd8 = (int)ROUND(fVar10 * 256.0);
    local_34 = DAT_00772dd8;
    if (local_40 != (int *)0x0) {
      iVar4 = Tcl_GetDoubleFromObj(0,local_40,&local_84);
      if (iVar4 == 1) {
        fVar9 = 0.0;
      }
      else {
        fVar9 = (float)local_84;
      }
    }
    DAT_00772dd8 = (int)ROUND(fVar9 * 256.0);
    local_30 = DAT_00772dd8;
    if (local_44 == (int *)0x0) {
      fVar10 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,local_44,&local_8c);
      if (iVar4 == 1) {
        fVar10 = 0.0;
      }
      else {
        fVar10 = (float)local_8c;
      }
    }
    iVar4 = DAT_0076a338;
    DAT_00772dd8 = (int)ROUND(fVar10 * 256.0);
    local_2c = DAT_00772dd8;
    local_28 = (undefined4 *)FUN_006bafe0(local_a8);
    FUN_004755a0(local_28);
    if (0xff < local_2c) {
      local_2c = 0xff;
    }
    if (local_2c < 0) {
      local_2c = 0;
    }
    if (0xff < local_30) {
      local_30 = 0xff;
    }
    if (local_30 < 0) {
      local_30 = 0;
    }
    if (0xff < local_34) {
      local_34 = 0xff;
    }
    if (local_34 < 0) {
      local_34 = 0;
    }
    local_24 = (int *)(iVar4 + 0x2868);
    FUN_0047deb0(1);
    uVar1 = *(uint *)(iVar4 + 0x286c) - 1;
    piVar7 = (int *)(iVar4 + 0x2868);
    if (*(uint *)(iVar4 + 0x286c) <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = local_24;
    }
    local_20 = (int *)(uVar1 * 0x20);
    puVar6 = (undefined4 *)(*piVar7 + (int)local_20);
    *puVar6 = *local_28;
    puVar6[1] = local_28[1];
    puVar6[2] = local_28[2];
    if ((uint)piVar7[1] <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = local_24;
    }
    *(int *)(*piVar7 + 0xc + (int)local_20) = local_2c;
    if ((uint)piVar7[1] <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = local_24;
    }
    *(int *)(*piVar7 + 0x10 + (int)local_20) = local_30;
    if ((uint)piVar7[1] <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = local_24;
    }
    *(int *)(*piVar7 + 0x14 + (int)local_20) = local_34;
    if ((uint)piVar7[1] <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = local_24;
    }
    *(float *)(*piVar7 + 0x18 + (int)local_20) = local_38;
    if ((uint)piVar7[1] <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = local_24;
    }
    *(float *)((int)local_20 + 0x1c + *piVar7) = local_3c;
    if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 < 1)) {
      TclFreeObj(local_48);
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 < 1)) {
      TclFreeObj(local_40);
    }
    if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 < 1)) {
      TclFreeObj(local_44);
    }
    if ((local_4c != (int *)0x0) && (*local_4c = *local_4c + -1, *local_4c < 1)) {
      TclFreeObj(local_4c);
    }
    uVar8 = 0;
  }
  else {
    FUN_006bc8f0(6);
    uVar8 = 1;
  }
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_004297b0(0);
  if (local_1c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

