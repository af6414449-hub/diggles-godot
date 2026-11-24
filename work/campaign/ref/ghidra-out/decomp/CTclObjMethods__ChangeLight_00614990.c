
undefined4
CTclObjMethods__ChangeLight(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  code *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  float fVar9;
  undefined8 uVar10;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  undefined4 local_2c;
  int *piStack_28;
  undefined1 local_24 [4];
  undefined4 local_20;
  float fStack_1c;
  float local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a89d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6bb8) &&
     (FUN_006cebf4(&DAT_00ca6bb8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6bb8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6bbc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::ChangeLight()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6bb8);
  }
  iVar5 = DAT_00ca6bbc;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6bbc * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar10 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = DAT_00772440;
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar7 = 1;
    goto LAB_00614ded;
  }
  if (param_3 < 4) {
    FUN_006bc8f0(3);
    uVar7 = 1;
    goto LAB_00614ded;
  }
  if (local_38 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_40;
    if (local_3c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_3c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_40 + 1;
  }
  piVar1 = (int *)*puVar4;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  piStack_28 = piVar1;
  if (local_38 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_40;
    if (local_3c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_3c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_40 + 3;
  }
  piVar2 = (int *)*puVar4;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_18 = 356.0;
  if (param_3 == 5) {
    puVar4 = (undefined4 *)FUN_004295e0(4);
    piVar8 = (int *)*puVar4;
    if (piVar8 == (int *)0x0) {
      local_18 = 0.0;
    }
    else {
      *piVar8 = *piVar8 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar8,&local_20);
      if (iVar3 == 1) {
        local_18 = 0.0;
      }
      else {
        local_18 = (float)(double)CONCAT44(fStack_1c,local_20);
      }
      *piVar8 = *piVar8 + -1;
      if (*piVar8 < 1) {
        TclFreeObj(piVar8);
      }
    }
  }
  if (local_38 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_40;
    if (local_3c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_3c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_40 + 2;
  }
  piVar8 = (int *)*puVar4;
  if (piVar8 == (int *)0x0) {
    pcVar6 = TclFreeObj_exref;
    fVar9 = 0.0;
  }
  else {
    *piVar8 = *piVar8 + 1;
    iVar3 = Tcl_GetDoubleFromObj(0,piVar8,&local_20);
    if (iVar3 == 1) {
      fStack_1c = 0.0;
    }
    else {
      fStack_1c = (float)(double)CONCAT44(fStack_1c,local_20);
    }
    *piVar8 = *piVar8 + -1;
    pcVar6 = TclFreeObj_exref;
    fVar9 = fStack_1c;
    if (*piVar8 < 1) {
      TclFreeObj(piVar8);
      fVar9 = fStack_1c;
    }
  }
  iVar3 = local_14;
  *(float *)(*(int *)(local_14 + 4) + 0x4c) = fVar9;
  *(float *)(*(int *)(local_14 + 4) + 0x50) = local_18;
  puVar4 = (undefined4 *)FUN_006bafe0(local_24);
  iVar3 = *(int *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0x30) = *puVar4;
  *(undefined4 *)(iVar3 + 0x34) = puVar4[1];
  *(undefined4 *)(iVar3 + 0x38) = puVar4[2];
  if ((piVar2 == (int *)0x0) ||
     (iVar3 = Tcl_ListObjIndex(0,piVar2,0,&piStack_28), piVar8 = piStack_28, iVar3 != 0)) {
    piVar8 = (int *)0x0;
LAB_00614cb9:
    fVar9 = 0.0;
  }
  else {
    if (piStack_28 == (int *)0x0) goto LAB_00614cb9;
    *piStack_28 = *piStack_28 + 1;
    iVar3 = Tcl_GetDoubleFromObj(0,piStack_28,&local_2c);
    if (iVar3 == 1) goto LAB_00614cb9;
    fVar9 = (float)(double)CONCAT44(piStack_28,local_2c);
  }
  *(int *)(*(int *)(local_14 + 4) + 0x3c) = (int)(fVar9 * 31.0);
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    (*pcVar6)(piVar8);
  }
  if ((piVar2 == (int *)0x0) ||
     (iVar3 = Tcl_ListObjIndex(0,piVar2,1,&piStack_28), piVar8 = piStack_28, iVar3 != 0)) {
    piVar8 = (int *)0x0;
LAB_00614d27:
    fVar9 = 0.0;
  }
  else {
    if (piStack_28 == (int *)0x0) goto LAB_00614d27;
    *piStack_28 = *piStack_28 + 1;
    iVar3 = Tcl_GetDoubleFromObj(0,piStack_28,&local_2c);
    if (iVar3 == 1) goto LAB_00614d27;
    fVar9 = (float)(double)CONCAT44(piStack_28,local_2c);
  }
  *(int *)(*(int *)(local_14 + 4) + 0x40) = (int)(fVar9 * 31.0);
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    (*pcVar6)(piVar8);
  }
  if ((piVar2 == (int *)0x0) ||
     (iVar3 = Tcl_ListObjIndex(0,piVar2,2,&piStack_28), piVar8 = piStack_28, iVar3 != 0)) {
    piVar8 = (int *)0x0;
LAB_00614d95:
    fVar9 = 0.0;
  }
  else {
    if (piStack_28 == (int *)0x0) goto LAB_00614d95;
    *piStack_28 = *piStack_28 + 1;
    iVar3 = Tcl_GetDoubleFromObj(0,piStack_28,&local_2c);
    if (iVar3 == 1) goto LAB_00614d95;
    fVar9 = (float)(double)CONCAT44(piStack_28,local_2c);
  }
  *(int *)(*(int *)(local_14 + 4) + 0x44) = (int)(fVar9 * 31.0);
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    (*pcVar6)(piVar8);
  }
  uVar7 = 0;
  *(undefined1 *)(*(int *)(local_14 + 4) + 0x48) = 1;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    (*pcVar6)(piVar2);
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar6)(piVar1);
  }
LAB_00614ded:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_40 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

