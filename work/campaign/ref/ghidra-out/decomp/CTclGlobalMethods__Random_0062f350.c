
undefined4
CTclGlobalMethods__Random(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  code *pcVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  int local_58;
  undefined4 *local_48;
  uint local_44;
  int local_40;
  double local_3c;
  double local_34;
  double local_2c;
  double local_24;
  undefined4 *local_1c;
  undefined8 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070cad5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e08) &&
     (FUN_006cebf4(&DAT_00ca6e08,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6e08 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6e0c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::Random()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e08);
  }
  iVar6 = DAT_00ca6e0c;
  local_1c = &DAT_00ca6e0c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e0c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_006bc170(param_2);
  uVar4 = FUN_0049c670();
  pcVar7 = TclFreeObj_exref;
  local_24 = (double)(uVar4 & 0x7fffffff) / 2147483647.0;
  if (param_3 == (int *)0x2) {
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_48 + 1;
    }
    piVar5 = (int *)*puVar8;
    if (piVar5 == (int *)0x0) goto LAB_0062f603;
    *piVar5 = *piVar5 + 1;
    iVar3 = Tcl_GetDoubleFromObj(0,piVar5,&local_18);
    if (iVar3 == 1) {
      local_18 = local_24 * 0.0;
    }
    else {
      local_18 = (double)(float)local_18 * local_24;
    }
  }
  else {
    if (param_3 != (int *)0x3) goto LAB_0062f603;
    if (local_40 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_48 + 2;
    }
    piVar5 = (int *)*puVar8;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_48 + 1;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_18._4_4_ = 0.0;
    if (piVar5 == (int *)0x0) {
      param_3 = (int *)0x0;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,piVar5,&local_2c);
      if (iVar3 == 1) {
        param_3 = (int *)0x0;
      }
      else {
        param_3 = (int *)(float)local_2c;
      }
    }
    if (piVar2 == (int *)0x0) {
      local_18 = (double)((float)param_3 - 0.0) * local_24 + 0.0;
      pcVar7 = TclFreeObj_exref;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_34);
      if (iVar3 != 1) {
        local_18._4_4_ = (float)local_34;
      }
      iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_3c);
      local_18 = (double)((float)param_3 - local_18._4_4_) * local_24;
      if (iVar3 == 1) {
        local_18 = local_18 + 0.0;
      }
      else {
        local_18 = local_18 + (double)(float)local_3c;
      }
      *piVar2 = *piVar2 + -1;
      pcVar7 = TclFreeObj_exref;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (piVar5 == (int *)0x0) goto LAB_0062f603;
  }
  *piVar5 = *piVar5 + -1;
  if (*piVar5 < 1) {
    (*pcVar7)(piVar5);
  }
LAB_0062f603:
  piVar5 = (int *)FUN_006bad90();
  if (local_58 != 0) {
    if (*piVar5 == 0) {
      Tcl_ResetResult(local_58);
    }
    else {
      Tcl_SetObjResult(local_58,*piVar5);
    }
  }
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    (*pcVar7)(param_3);
  }
  FUN_006bc0d0();
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_48 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

