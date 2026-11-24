
undefined4
CTclGlobalMethods__Get_EventEnabled
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  int local_3c;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c8cd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6dd8) &&
     (FUN_006cebf4(&DAT_00ca6dd8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6dd8 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6ddc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::Get_EventEnabled()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6dd8);
  }
  iVar6 = DAT_00ca6ddc;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6ddc * 0x40);
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
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar1 < 3) {
    FUN_006bc8f0(2);
    uVar7 = 1;
  }
  else {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_2c + 1;
    }
    piVar1 = (int *)*puVar8;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_24 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_2c + 2;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8._0_1_ = 4;
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar4);
    uVar5 = FUN_005ba5b0(&param_3);
    local_8 = CONCAT31(local_8._1_3_,5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    if (uVar5 != 0xffffffff) {
      if (piVar2 != (int *)0x0) {
        Tcl_GetIntFromObj(0,piVar2,&param_3);
      }
      if ((uVar5 < 0x81) && (((int)uVar5 < 0 || (0x7f < (int)uVar5)))) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    param_3 = (int *)Tcl_NewBooleanObj(0);
    *param_3 = *param_3 + 1;
    iVar3 = *param_3;
    if (local_3c != 0) {
      Tcl_SetObjResult(local_3c,param_3);
      iVar3 = *param_3;
    }
    *param_3 = iVar3 + -1;
    if (iVar3 + -1 < 1) {
      TclFreeObj(param_3);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar7 = 0;
  }
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

