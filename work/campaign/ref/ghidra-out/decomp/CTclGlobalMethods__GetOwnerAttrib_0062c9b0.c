
undefined4
CTclGlobalMethods__GetOwnerAttrib
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  code *pcVar9;
  undefined8 uVar10;
  int local_30;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c755;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6da8) &&
     (FUN_006cebf4(&DAT_00ca6da8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6da8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6dac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::GetOwnerAttrib()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6da8);
  }
  iVar5 = DAT_00ca6dac;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6dac * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar10 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 2) {
    FUN_006bc8f0(1);
    uVar6 = 1;
    goto LAB_0062cb79;
  }
  if (local_18 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_20 + 1;
  }
  piVar1 = (int *)*puVar7;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar2 = FUN_005da0f0();
  if (piVar1 == (int *)0x0) {
    ppuVar3 = &PTR_0071ce50;
  }
  else {
    ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  uVar4 = FUN_005da2f0(ppuVar3);
  if (uVar4 == 0xffffffff) {
    piVar8 = (int *)Tcl_NewStringObj(&DAT_00721a08,0xffffffff);
    *piVar8 = *piVar8 + 1;
    iVar2 = *piVar8;
    if (local_30 != 0) {
      Tcl_SetObjResult(local_30,piVar8);
      iVar2 = *piVar8;
    }
    iVar2 = iVar2 + -1;
    *piVar8 = iVar2;
LAB_0062cbeb:
    pcVar9 = TclFreeObj_exref;
    if (iVar2 < 1) {
      TclFreeObj(piVar8);
    }
  }
  else {
    if (uVar4 < 0x200) {
      iVar2 = iVar2 + uVar4 * 4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar2 = *(int *)(iVar2 + 0x2004) + 0xc;
    if (iVar2 == 0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)Tcl_NewStringObj(iVar2,0xffffffff);
      *piVar8 = *piVar8 + 1;
    }
    if (local_30 == 0) {
      pcVar9 = TclFreeObj_exref;
      if (piVar8 != (int *)0x0) goto LAB_0062cbe6;
    }
    else {
      if (piVar8 != (int *)0x0) {
        Tcl_SetObjResult(local_30,piVar8);
LAB_0062cbe6:
        *piVar8 = *piVar8 + -1;
        iVar2 = *piVar8;
        goto LAB_0062cbeb;
      }
      Tcl_ResetResult(local_30);
      pcVar9 = TclFreeObj_exref;
    }
  }
  uVar6 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar9)(piVar1);
  }
LAB_0062cb79:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

