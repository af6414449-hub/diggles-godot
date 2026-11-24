
undefined4
CTclGlobalMethods__HCeil(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  float10 fVar7;
  float fVar8;
  undefined8 uVar9;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  double local_1c;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a85d;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6fc0) &&
     (FUN_006cebf4(), iVar2 = DAT_00783650, DAT_00ca6fc0 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6fc4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::HCeil()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar4 = DAT_00ca6fc4;
  local_14 = &DAT_00ca6fc4;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6fc4 * 0x40);
  iVar2 = FUN_0043fcc0(uVar1);
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)param_3 < 2) {
    FUN_006bc8f0();
    uVar5 = 1;
  }
  else {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_28 + 1;
    }
    piVar3 = (int *)*puVar6;
    if (piVar3 == (int *)0x0) {
      local_1c = 0.0;
    }
    else {
      *piVar3 = *piVar3 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar3,&local_1c);
      if (iVar2 == 1) {
        fVar8 = 0.0;
      }
      else {
        fVar8 = (float)local_1c;
      }
      *piVar3 = *piVar3 + -1;
      local_1c = (double)fVar8;
      if (*piVar3 < 1) {
        TclFreeObj();
      }
    }
    fVar7 = (float10)FUN_006f26b0(local_1c);
    local_1c = (double)fVar7;
    piVar3 = (int *)FUN_006bad90();
    if (local_38 != 0) {
      if (*piVar3 == 0) {
        Tcl_ResetResult();
      }
      else {
        Tcl_SetObjResult(local_38,*piVar3);
      }
    }
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj();
    }
    uVar5 = 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0();
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

