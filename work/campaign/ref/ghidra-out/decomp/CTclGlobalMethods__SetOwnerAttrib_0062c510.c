
undefined4
CTclGlobalMethods__SetOwnerAttrib
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  code *pcVar8;
  undefined8 uVar9;
  int local_5c;
  undefined4 *local_4c;
  uint local_48;
  int local_44;
  double local_40;
  int *local_38;
  int *local_34;
  int *local_30;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int local_20;
  undefined **local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c705;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6da0) &&
     (FUN_006cebf4(&DAT_00ca6da0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6da0 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6da4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::SetOwnerAttrib()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6da0);
  }
  iVar6 = DAT_00ca6da4;
  local_2c = &DAT_00ca6da4;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6da4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 4) {
    FUN_006bc8f0(3);
    uVar7 = 1;
    goto LAB_0062c903;
  }
  if (local_44 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_4c;
    if (local_48 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_48 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_4c + 1;
  }
  piVar1 = (int *)*puVar4;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_30 = piVar1;
  if (local_44 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_4c;
    if (local_48 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_48 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_4c + 2;
  }
  piVar2 = (int *)*puVar4;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_34 = piVar2;
  if (local_44 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_4c;
    if (local_48 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_48 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_4c + 3;
  }
  local_38 = (int *)*puVar4;
  if (local_38 != (int *)0x0) {
    *local_38 = *local_38 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  local_18 = local_38;
  if (piVar1 == (int *)0x0) {
    param_3 = 0;
LAB_0062c71f:
    if (local_18 == (int *)0x0) {
      local_14 = (int *)0x0;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,local_18,&local_40);
      if (iVar3 == 1) {
        local_14 = (int *)0x0;
      }
      else {
        local_14 = (int *)(float)local_40;
      }
    }
    if (piVar2 == (int *)0x0) {
      local_1c = &PTR_0071ce50;
    }
    else {
      local_1c = (undefined **)Tcl_GetStringFromObj(piVar2,0);
    }
    local_24 = DAT_0077244c + 0x84e4;
    local_28 = param_3 + 1;
    if (8 < param_3 + 1U) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_005daad0(local_1c);
    if (piVar2 == (int *)0x0) {
      local_1c = &PTR_0071ce50;
    }
    else {
      local_1c = (undefined **)Tcl_GetStringFromObj(piVar2,0);
    }
    local_24 = DAT_0077244c + 0x84e4;
    if (8 < local_28) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_005da900(local_1c);
    piVar5 = (int *)FUN_006bad90();
    if (local_5c != 0) {
      if (*piVar5 == 0) {
        Tcl_ResetResult(local_5c);
      }
      else {
        Tcl_SetObjResult(local_5c,*piVar5);
      }
    }
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
      TclFreeObj(local_14);
    }
    uVar7 = 0;
  }
  else {
    iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_20);
    if (iVar3 == 1) {
      param_3 = 0;
      goto LAB_0062c71f;
    }
    param_3 = local_20;
    if ((-2 < local_20) && (local_20 < 8)) goto LAB_0062c71f;
    if (local_44 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_4c + 1;
    }
    piVar5 = (int *)*puVar4;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
    FUN_006bc6a0("invalid owner id",piVar5);
    uVar7 = 1;
  }
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
    TclFreeObj(local_18);
  }
  pcVar8 = TclFreeObj_exref;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, pcVar8 = TclFreeObj_exref, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar8)(piVar1);
  }
LAB_0062c903:
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_4c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

