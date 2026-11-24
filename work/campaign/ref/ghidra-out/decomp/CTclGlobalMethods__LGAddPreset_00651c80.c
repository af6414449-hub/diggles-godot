
undefined4
CTclGlobalMethods__LGAddPreset
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined4 *puVar5;
  int iVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined4 *local_3c;
  uint local_38;
  int local_34;
  undefined4 local_20;
  uint local_1c;
  int *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e78d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7218) &&
     (FUN_006cebf4(&DAT_00ca7218,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7218 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca721c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::LGAddPreset()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7218);
  }
  iVar6 = DAT_00ca721c;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca721c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
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
  if (piVar1 == (int *)&DAT_00000004) {
    local_14 = FUN_0058a820();
    if (local_34 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_3c + 1;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar4);
    if (local_34 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_3c + 3;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (local_34 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_3c + 2;
    }
    local_18 = (int *)*puVar5;
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    if (piVar2 == (int *)0x0) {
      local_1c = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_1c);
      local_1c = -(uint)(iVar3 != 1) & local_1c;
    }
    if (local_18 == (int *)0x0) {
      FUN_0058a510(&param_3,0,local_1c);
      pcVar7 = TclFreeObj_exref;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,local_18,&local_20);
      if (iVar3 == 1) {
        local_20 = 0;
      }
      FUN_0058a510(&param_3,local_20,local_1c);
      *local_18 = *local_18 + -1;
      pcVar7 = TclFreeObj_exref;
      if (*local_18 < 1) {
        TclFreeObj(local_18);
      }
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      (*pcVar7)(piVar2);
    }
    local_8 = CONCAT31(local_8._1_3_,7);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar7)(piVar1);
    }
    uVar8 = 0;
  }
  else {
    FUN_006bc8f0(3);
    uVar8 = 1;
  }
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_004297b0(0);
  if (local_3c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

