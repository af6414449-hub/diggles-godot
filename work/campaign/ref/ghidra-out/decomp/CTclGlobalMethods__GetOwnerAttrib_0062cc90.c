
undefined4
CTclGlobalMethods__GetOwnerAttrib
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  code *pcVar8;
  undefined8 uVar9;
  int local_48;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  int local_1c;
  int *local_18;
  undefined **local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c7ad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6db0) &&
     (FUN_006cebf4(&DAT_00ca6db0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6db0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6db4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::GetOwnerAttrib()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6db0);
  }
  iVar5 = DAT_00ca6db4;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6db4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 3) {
    FUN_006bc8f0(2);
    uVar7 = 1;
    goto LAB_0062cf87;
  }
  if (local_30 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_38;
    if (local_34 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_34 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_38 + 1;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if (local_30 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_38;
    if (local_34 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_34 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_38 + 2;
  }
  piVar2 = (int *)*puVar6;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  if (piVar1 == (int *)0x0) {
    param_3 = 0;
LAB_0062ce4c:
    if (piVar2 == (int *)0x0) {
      local_14 = &PTR_0071ce50;
    }
    else {
      local_14 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
    }
    if (8 < param_3 + 1U) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_005da900(local_14);
    piVar4 = (int *)FUN_006bad90();
    if (local_48 != 0) {
      if (*piVar4 == 0) {
        Tcl_ResetResult(local_48);
      }
      else {
        Tcl_SetObjResult(local_48,*piVar4);
      }
    }
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
      TclFreeObj(local_18);
    }
    uVar7 = 0;
  }
  else {
    iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_1c);
    if (iVar3 == 1) {
      param_3 = 0;
      goto LAB_0062ce4c;
    }
    param_3 = local_1c;
    if ((-2 < local_1c) && (local_1c < 8)) goto LAB_0062ce4c;
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_38 + 1;
    }
    piVar4 = (int *)*puVar6;
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    FUN_006bc6a0("invalid owner id",piVar4);
    uVar7 = 1;
  }
  pcVar8 = TclFreeObj_exref;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, pcVar8 = TclFreeObj_exref, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar8)(piVar1);
  }
LAB_0062cf87:
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

