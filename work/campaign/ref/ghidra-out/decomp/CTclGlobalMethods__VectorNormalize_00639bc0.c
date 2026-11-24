
undefined4
CTclGlobalMethods__VectorNormalize
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  float *pfVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  float fVar8;
  undefined8 uVar9;
  int local_4c;
  undefined1 local_3c [12];
  float local_30;
  float local_2c;
  float local_28;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  undefined4 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d39d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6fa0) &&
     (FUN_006cebf4(&DAT_00ca6fa0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6fa0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6fa4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::VectorNormalize()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6fa0);
  }
  iVar5 = DAT_00ca6fa4;
  local_18 = &DAT_00ca6fa4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6fa4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)param_3 < 2) {
    FUN_006bc8f0(1);
    uVar6 = 1;
  }
  else {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_24;
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_24 + 1;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_14 = piVar1;
    pfVar3 = (float *)FUN_006bafe0(local_3c);
    fVar8 = *pfVar3 * *pfVar3 + pfVar3[1] * pfVar3[1] + pfVar3[2] * pfVar3[2];
    FUN_0040b7e0();
    if (fVar8 <= 0.0) {
      local_30 = 0.0;
      local_2c = 0.0;
      local_28 = 0.0;
    }
    else {
      local_30 = *pfVar3 / fVar8;
      local_2c = pfVar3[1] / fVar8;
      local_28 = pfVar3[2] / fVar8;
    }
    piVar4 = (int *)FUN_006badc0(&local_30);
    if (local_4c != 0) {
      if (*piVar4 == 0) {
        Tcl_ResetResult(local_4c);
      }
      else {
        Tcl_SetObjResult(local_4c,*piVar4);
      }
    }
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar6 = 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

