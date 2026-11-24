
undefined4
CTclGlobalMethods__GetPointInDirection
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  code *pcVar7;
  undefined4 *puVar8;
  float fVar9;
  undefined8 uVar10;
  int local_50;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  float local_34;
  float local_30;
  float fStack_2c;
  undefined4 *local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  float fStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070fb2d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7450) &&
     (FUN_006cebf4(&DAT_00ca7450,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7450 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7454 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::GetPointInDirection()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7450);
  }
  iVar6 = DAT_00ca7454;
  local_28 = &DAT_00ca7454;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7454 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar10 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  pcVar7 = TclFreeObj_exref;
  local_8._0_1_ = 2;
  if (param_3 == (int *)0x4) {
    if (local_38 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_40 + 1;
    }
    piVar5 = (int *)*puVar8;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
    pfVar4 = (float *)FUN_006bafe0(&local_34);
    local_1c = *pfVar4;
    local_20 = pfVar4[1];
    local_24 = pfVar4[2];
    if (local_38 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_40 + 2;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 == (int *)0x0) {
      fStack_14 = 0.0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_18);
      fVar9 = 0.0;
      if (iVar3 != 1) {
        fVar9 = (float)(double)CONCAT44(fStack_14,local_18);
      }
      *piVar2 = *piVar2 + -1;
      fStack_14 = fVar9;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    param_3 = (int *)0x0;
    if (local_38 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_40 + 3;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 == (int *)0x0) {
      param_3 = (int *)0x0;
      pcVar7 = TclFreeObj_exref;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_30);
      if (iVar3 != 1) {
        param_3 = (int *)(float)(double)CONCAT44(fStack_2c,local_30);
      }
      *piVar2 = *piVar2 + -1;
      pcVar7 = TclFreeObj_exref;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (piVar5 == (int *)0x0) goto LAB_0066a25d;
  }
  else {
    iVar3 = FUN_005c71c0(param_4,3,1);
    if (iVar3 == 0) {
      local_8._0_1_ = 5;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_004297b0(0);
      if (local_40 != (undefined4 *)0x0) {
        FUN_006ba940();
      }
      FUN_006bc0d0();
      FUN_0043fd30();
      ExceptionList = local_10;
      return 1;
    }
    local_1c = *(float *)(iVar3 + 0xc);
    local_20 = *(float *)(iVar3 + 0x10);
    local_24 = *(float *)(iVar3 + 0x14);
    fStack_14 = *(float *)(iVar3 + 0x44);
    if (local_38 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_40 + 2;
    }
    piVar5 = (int *)*puVar8;
    if (piVar5 == (int *)0x0) {
      param_3 = (int *)0x0;
      goto LAB_0066a25d;
    }
    *piVar5 = *piVar5 + 1;
    iVar3 = Tcl_GetDoubleFromObj(0,piVar5,&local_30);
    if (iVar3 == 1) {
      param_3 = (int *)0x0;
    }
    else {
      param_3 = (int *)(float)(double)CONCAT44(fStack_2c,local_30);
    }
  }
  *piVar5 = *piVar5 + -1;
  if (*piVar5 < 1) {
    (*pcVar7)(piVar5);
  }
LAB_0066a25d:
  fVar9 = fStack_14;
  FUN_004089d0();
  local_34 = local_1c - fVar9 * (float)param_3;
  local_30 = local_20;
  fVar9 = fStack_14;
  FUN_004089f0();
  fStack_2c = fVar9 * (float)param_3 + fVar9 * (float)param_3 + local_24;
  piVar5 = (int *)FUN_006badc0(&local_34);
  if (local_50 != 0) {
    if (*piVar5 == 0) {
      Tcl_ResetResult(local_50);
    }
    else {
      Tcl_SetObjResult(local_50,*piVar5);
    }
  }
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    (*pcVar7)(param_3);
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_40 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

