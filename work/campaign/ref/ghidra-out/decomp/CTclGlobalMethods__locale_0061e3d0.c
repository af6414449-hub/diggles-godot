
undefined4
CTclGlobalMethods__locale(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined8 uVar7;
  int local_30;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070b665;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c00) &&
     (FUN_006cebf4(&DAT_00ca6c00,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6c00 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6c04 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::locale()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c00);
  }
  iVar4 = DAT_00ca6c04;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c04 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_20 + 1;
    }
    piVar6 = (int *)*puVar5;
    if (piVar6 != (int *)0x0) {
      *piVar6 = *piVar6 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar6 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar6,0);
    }
    FUN_004435d0(ppuVar3);
    FUN_00443b40(ppuVar3);
    local_8 = CONCAT31(local_8._1_3_,2);
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
      TclFreeObj(piVar6);
    }
  }
  iVar2 = FUN_004435d0();
  iVar2 = *(int *)(iVar2 + 0x808) + 0xc;
  if (iVar2 == 0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)Tcl_NewStringObj(iVar2,0xffffffff);
    *piVar6 = *piVar6 + 1;
  }
  if (local_30 == 0) {
    if (piVar6 == (int *)0x0) goto LAB_0061e586;
  }
  else {
    if (piVar6 == (int *)0x0) {
      Tcl_ResetResult(local_30);
      goto LAB_0061e586;
    }
    Tcl_SetObjResult(local_30,piVar6);
  }
  *piVar6 = *piVar6 + -1;
  if (*piVar6 < 1) {
    TclFreeObj(piVar6);
  }
LAB_0061e586:
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
  return 0;
}

