
undefined4
CTclGlobalMethods__CreateParticleSource(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  undefined8 uVar11;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f41d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca73e8) &&
     (FUN_006cebf4(), iVar7 = DAT_00783650, DAT_00ca73e8 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca73ec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclGlobalMethods::CreateParticleSource()";
    *(int *)(&DAT_00773650 + iVar9) = iVar7;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar9 = DAT_00ca73ec;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca73ec * 0x40);
  iVar7 = FUN_0043fcc0();
  *(undefined4 *)(iVar7 + *(int *)(iVar7 + 0x8000) * 4) = uVar1;
  *(int *)(iVar7 + 0x8000) = *(int *)(iVar7 + 0x8000) + 1;
  iVar7 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar7 == 0) {
    uVar11 = FUN_006bd180();
    iVar7 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar7 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 != 6) {
    FUN_006bc8f0();
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  FUN_004298b0();
  if (local_3c < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar8 = local_44;
    if (local_40 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_40 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar8 = local_44 + 2;
  }
  piVar2 = (int *)*puVar8;
  if (piVar2 == (int *)0x0) {
    FUN_006bafe0();
  }
  else {
    *piVar2 = *piVar2 + 1;
    FUN_006bafe0();
    *piVar2 = *piVar2 + -1;
    if (*piVar2 < 1) {
      TclFreeObj();
    }
  }
  cVar6 = FUN_004964c0();
  if (cVar6 != '\0') {
    if (local_3c < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_44 + 5;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
      Tcl_GetDoubleFromObj();
    }
    if (local_3c < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_44 + 4;
    }
    piVar3 = (int *)*puVar8;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
      Tcl_GetIntFromObj();
    }
    if (local_3c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_44 + 3;
    }
    piVar4 = (int *)*puVar8;
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    FUN_006bafe0();
    if (local_3c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_44 + 1;
    }
    piVar5 = (int *)*puVar8;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
    local_8._0_1_ = 8;
    if (piVar5 == (int *)0x0) {
      local_14 = 0;
      piVar10 = (int *)0x0;
    }
    else {
      iVar7 = Tcl_GetIntFromObj(0,piVar5,&local_14);
      piVar10 = piVar5;
      if (iVar7 == 1) {
        local_14 = 0;
      }
    }
    FUN_00492250(local_14);
    local_8 = CONCAT31(local_8._1_3_,9);
    FUN_00495ca0(local_14);
    if ((piVar10 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
      TclFreeObj();
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj();
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj();
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj();
    }
  }
  local_8._0_1_ = 10;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_004297b0();
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

