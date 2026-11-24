
undefined4
CTclGlobalMethods__VectorSetX(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  float fVar11;
  undefined8 uVar12;
  int local_44;
  float local_34;
  float local_30;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  int *piStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d1dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6f28) &&
     (FUN_006cebf4(&DAT_00ca6f28,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca6f28 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6f2c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::VectorSetX()";
    *(int *)(&DAT_00773650 + iVar7) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6f28);
  }
  iVar7 = DAT_00ca6f2c;
  local_1c = &DAT_00ca6f2c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6f2c * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar1;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar5 == 0) {
    uVar12 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  uVar4 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (2 < param_3) {
    local_8._0_1_ = uVar4;
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_28;
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_28 + 1;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (local_20 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_28;
      }
    }
    else {
      if (local_24 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_28 + 2;
    }
    piVar3 = (int *)*puVar8;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bafe0(&local_34);
    if (piVar3 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      iVar5 = Tcl_GetDoubleFromObj(0,piVar3,&local_18);
      if (iVar5 == 1) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = (int *)(float)(double)CONCAT44(piStack_14,local_18);
      }
    }
    piVar6 = piVar9;
    FUN_004089d0();
    piVar10 = piVar9;
    piStack_14 = piVar6;
    FUN_004089f0();
    fVar11 = local_34 * (float)piStack_14;
    local_34 = local_30 * (float)piStack_14 + local_34 * (float)piVar10;
    local_30 = local_30 * (float)piVar10 - fVar11;
    piVar6 = (int *)FUN_006badc0(&local_34);
    if (local_44 != 0) {
      if (*piVar6 == 0) {
        Tcl_ResetResult(local_44);
      }
      else {
        Tcl_SetObjResult(local_44,*piVar6);
      }
    }
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
      TclFreeObj(piVar9);
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_004297b0(0);
    if (local_28 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  FUN_006bc8f0(2);
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

