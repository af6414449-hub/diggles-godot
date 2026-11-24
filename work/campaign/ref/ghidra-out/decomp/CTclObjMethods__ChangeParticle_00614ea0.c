
undefined4
CTclObjMethods__ChangeParticle(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 *local_48;
  uint local_44;
  int local_40;
  undefined1 local_38 [4];
  undefined4 local_34;
  int *piStack_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  uint local_20;
  int local_1c;
  int local_18;
  bool local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a8dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6bc0) &&
     (FUN_006cebf4(&DAT_00ca6bc0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6bc0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6bc4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::ChangeParticle()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6bc0);
  }
  iVar5 = DAT_00ca6bc4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6bc4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar7 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  iVar5 = DAT_00772440;
  local_8 = CONCAT31(local_8._1_3_,2);
  local_18 = DAT_00772440;
  iVar3 = *(int *)(DAT_00772440 + 4);
  if (iVar3 == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar6 = 1;
    goto LAB_006155a0;
  }
  if (param_3 != 9) {
    FUN_006bc8f0(8);
    uVar6 = 1;
    goto LAB_006155a0;
  }
  FUN_00604660(1);
  local_20 = *(int *)(iVar3 + 0xcd8) - 1;
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
  if (piVar1 == (int *)0x0) {
    local_28 = (int *)0x0;
LAB_00615034:
    local_24 = (int *)0x0;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_2c);
    local_28 = piVar1;
    if (iVar3 == 1) goto LAB_00615034;
    local_24 = local_2c;
  }
  iVar3 = *(int *)(iVar5 + 4);
  if (*(uint *)(iVar3 + 0xcd8) <= local_20) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  local_1c = local_20 * 0x30;
  *(int **)(local_1c + *(int *)(iVar3 + 0xcd4)) = local_24;
  if ((local_28 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
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
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  iVar3 = *(int *)(local_18 + 4);
  local_2c = piVar1;
  if (*(uint *)(iVar3 + 0xcd8) <= local_20) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar3 = *(int *)(iVar3 + 0xcd4) + local_1c;
  puVar4 = (undefined4 *)FUN_006bafe0(local_38);
  *(undefined4 *)(iVar3 + 4) = *puVar4;
  *(undefined4 *)(iVar3 + 8) = puVar4[1];
  *(undefined4 *)(iVar3 + 0xc) = puVar4[2];
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
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
  piVar1 = (int *)*puVar4;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  iVar3 = *(int *)(local_18 + 4);
  local_2c = piVar1;
  if (*(uint *)(iVar3 + 0xcd8) <= local_20) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar3 = *(int *)(iVar3 + 0xcd4) + local_1c;
  puVar4 = (undefined4 *)FUN_006bafe0(local_38);
  *(undefined4 *)(iVar3 + 0x10) = *puVar4;
  *(undefined4 *)(iVar3 + 0x14) = puVar4[1];
  *(undefined4 *)(iVar3 + 0x18) = puVar4[2];
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
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
  piVar1 = (int *)*puVar4;
  if (piVar1 == (int *)0x0) {
    local_24 = (int *)0x0;
LAB_00615248:
    local_28 = (int *)0x0;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_2c);
    local_24 = piVar1;
    if (iVar3 == 1) goto LAB_00615248;
    local_28 = local_2c;
  }
  uVar2 = local_20;
  piStack_30 = (int *)(*(int *)(local_18 + 4) + 0xcd4);
  if (*(uint *)(*(int *)(local_18 + 4) + 0xcd8) <= local_20) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(int **)(*piStack_30 + 0x1c + local_1c) = local_28;
  if ((local_24 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  if (local_40 < 6) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_48;
    if (local_44 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_44 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_48 + 5;
  }
  piVar1 = (int *)*puVar4;
  if (piVar1 == (int *)0x0) {
    local_24 = (int *)0x0;
LAB_0061530b:
    local_28 = (int *)0x0;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar3 = Tcl_GetIntFromObj(0,piVar1,&piStack_30);
    local_24 = piVar1;
    if (iVar3 == 1) goto LAB_0061530b;
    local_28 = piStack_30;
  }
  local_2c = (int *)(*(int *)(local_18 + 4) + 0xcd4);
  if (*(uint *)(*(int *)(local_18 + 4) + 0xcd8) <= uVar2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(int **)(local_1c + 0x20 + *local_2c) = local_28;
  if ((local_24 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  if (local_40 < 7) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_48;
    if (local_44 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_44 < 7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_48 + 6;
  }
  piVar1 = (int *)*puVar4;
  if (piVar1 == (int *)0x0) {
    local_28 = (int *)0x0;
LAB_006153cd:
    local_11 = false;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar3 = Tcl_GetBooleanFromObj(0,piVar1,&piStack_30);
    local_28 = piVar1;
    if (iVar3 == 1) goto LAB_006153cd;
    local_11 = piStack_30 != (int *)0x0;
  }
  local_2c = (int *)(*(int *)(local_18 + 4) + 0xcd4);
  if (*(uint *)(*(int *)(local_18 + 4) + 0xcd8) <= uVar2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(bool *)(*local_2c + 0x24 + local_1c) = local_11;
  if ((local_28 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  if (local_40 < 8) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_48;
    if (local_44 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_44 < 8) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_48 + 7;
  }
  piVar1 = (int *)*puVar4;
  if (piVar1 == (int *)0x0) {
    local_24 = (int *)0x0;
LAB_0061548a:
    local_28 = (int *)0x0;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar3 = Tcl_GetIntFromObj(0,piVar1,&piStack_30);
    local_24 = piVar1;
    if (iVar3 == 1) goto LAB_0061548a;
    local_28 = piStack_30;
  }
  local_2c = (int *)(*(int *)(local_18 + 4) + 0xcd4);
  if (*(uint *)(*(int *)(local_18 + 4) + 0xcd8) <= uVar2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(int **)(*local_2c + 0x28 + local_1c) = local_28;
  if ((local_24 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  if (local_40 < 9) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_48;
    if (local_44 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_44 < 9) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_48 + 8;
  }
  piVar1 = (int *)*puVar4;
  if (piVar1 == (int *)0x0) {
    local_24 = (int *)0x0;
LAB_0061554d:
    local_28 = (int *)0x0;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar3 = Tcl_GetDoubleFromObj(0,piVar1,&local_34);
    local_24 = piVar1;
    if (iVar3 == 1) goto LAB_0061554d;
    local_28 = (int *)(float)(double)CONCAT44(piStack_30,local_34);
  }
  iVar3 = *(int *)(local_18 + 4);
  if (*(uint *)(iVar3 + 0xcd8) <= local_20) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(int **)(*(int *)(iVar3 + 0xcd4) + 0x2c + local_1c) = local_28;
  if ((local_24 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  uVar6 = 0;
LAB_006155a0:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_48 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

