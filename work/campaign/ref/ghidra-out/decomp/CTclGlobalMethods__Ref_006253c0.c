
undefined4
CTclGlobalMethods__Ref(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bf25;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6cd0) &&
     (FUN_006cebf4(&DAT_00ca6cd0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca6cd0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6cd4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::Ref()";
    *(int *)(&DAT_00773650 + iVar5) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6cd0);
  }
  iVar5 = DAT_00ca6cd4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6cd4 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar6;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar1 == 0) {
    uVar8 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar3 = piVar2 + 3;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)piVar3 = 0;
  piVar2[1] = 0x14;
  *piVar3 = 0x73696874;
  *(undefined1 *)(piVar2 + 4) = 0;
  piVar2[2] = 4;
  *piVar2 = 1;
  if (local_40 == 0) {
    iVar1 = 1;
    local_14 = 0;
  }
  else {
    local_14 = Tcl_GetAssocData(local_40,piVar3,0);
    iVar1 = *piVar2;
  }
  iVar5 = local_14;
  local_8 = CONCAT31(local_8._1_3_,3);
  *piVar2 = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    FUN_006ba940();
  }
  if (iVar5 == 0) {
    uVar6 = 1;
    goto LAB_00625689;
  }
  if (param_3 == 1) {
    iVar1 = FUN_005caf90();
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar3 = (int *)Tcl_NewStringObj(iVar1,0xffffffff);
      iVar1 = *piVar3 + 1;
      *piVar3 = iVar1;
      piVar2 = piVar3;
joined_r0x0062564a:
      if (iVar1 < 1) {
        TclFreeObj(piVar3);
      }
    }
  }
  else {
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_30 + 1;
    }
    piVar3 = (int *)*puVar7;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8._0_1_ = 5;
    if (piVar3 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 6;
    iVar1 = FUN_006055d0(param_2,local_14,&local_18);
    local_8 = CONCAT31(local_8._1_3_,7);
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    if (iVar1 == 0) {
      piVar2 = (int *)Tcl_NewIntObj(0xffffffff);
LAB_00625630:
      iVar1 = *piVar2;
      *piVar2 = iVar1 + 1;
      if (iVar1 + 1 < 1) {
        TclFreeObj(piVar2);
      }
    }
    else {
      iVar1 = FUN_005caf90();
      if (iVar1 != 0) {
        piVar2 = (int *)Tcl_NewStringObj(iVar1,0xffffffff);
        goto LAB_00625630;
      }
      piVar2 = (int *)0x0;
    }
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + -1;
      iVar1 = *piVar3;
      goto joined_r0x0062564a;
    }
  }
  if (local_40 == 0) {
    uVar6 = 0;
    if (piVar2 == (int *)0x0) goto LAB_00625689;
LAB_00625679:
    *piVar2 = *piVar2 + -1;
    uVar6 = 0;
    if (0 < *piVar2) goto LAB_00625689;
    TclFreeObj(piVar2);
  }
  else {
    if (piVar2 != (int *)0x0) {
      Tcl_SetObjResult(local_40,piVar2);
      goto LAB_00625679;
    }
    Tcl_ResetResult(local_40);
  }
  uVar6 = 0;
LAB_00625689:
  FUN_006bc0d0();
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

