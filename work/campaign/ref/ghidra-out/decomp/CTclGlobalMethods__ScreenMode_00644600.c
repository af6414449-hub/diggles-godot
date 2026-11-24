
undefined4
CTclGlobalMethods__ScreenMode(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  code *pcVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070dbc5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7098) &&
     (FUN_006cebf4(&DAT_00ca7098,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7098 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca709c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::ScreenMode()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7098);
  }
  iVar6 = DAT_00ca709c;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca709c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar9;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar7 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)uVar7 < 4) {
    FUN_006bc8f0(3);
    uVar9 = 1;
  }
  else {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_34 + 1;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_34 + 2;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (local_2c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_34 + 3;
    }
    piVar3 = (int *)*puVar5;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    if (piVar1 == (int *)0x0) {
      uVar7 = 0;
    }
    else {
      iVar4 = Tcl_GetIntFromObj(0,piVar1,&param_3);
      uVar7 = -(uint)(iVar4 != 1) & param_3;
    }
    if (piVar2 == (int *)0x0) {
      param_3 = 0;
    }
    else {
      iVar4 = Tcl_GetIntFromObj(0,piVar2,&param_3);
      param_3 = param_3 & -(uint)(iVar4 != 1);
    }
    if (piVar3 == (int *)0x0) {
      FUN_0044d010();
      FUN_0044d3e0(uVar7,param_3,0);
      pcVar8 = TclFreeObj_exref;
    }
    else {
      iVar4 = Tcl_GetBooleanFromObj(0,piVar3,&local_14);
      if (iVar4 == 1) {
        FUN_0044d010();
        local_14 = local_14 & 0xffffff00;
      }
      else {
        FUN_0044d010();
        local_14 = CONCAT31(local_14._1_3_,local_14 != 0);
      }
      FUN_0044d3e0(uVar7,param_3,local_14);
      *piVar3 = *piVar3 + -1;
      pcVar8 = TclFreeObj_exref;
      if (*piVar3 < 1) {
        TclFreeObj(piVar3);
      }
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      (*pcVar8)(piVar2);
    }
    uVar9 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar8)(piVar1);
    }
  }
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

