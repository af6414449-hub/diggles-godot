
undefined4
CTclGlobalMethods__LGSetTemplateValue
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  undefined **ppuVar5;
  int iVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  undefined4 *local_3c;
  uint local_38;
  int local_34;
  double local_30;
  int *local_28;
  int *local_24;
  undefined4 *local_20;
  uint local_1c;
  int *local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e4b5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca71c0) &&
     (FUN_006cebf4(&DAT_00ca71c0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca71c0 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca71c4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::LGSetTemplateValue()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca71c0);
  }
  iVar6 = DAT_00ca71c4;
  local_20 = &DAT_00ca71c4;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca71c4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
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
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar4 = FUN_0058a820();
  if (param_3 == 3) {
    if (local_34 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_3c + 1;
    }
    piVar1 = (int *)*puVar9;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_24 = piVar1;
    if (local_34 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_3c + 2;
    }
    piVar2 = (int *)*puVar9;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8._0_1_ = 4;
    local_28 = piVar2;
    if (piVar1 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar5);
    local_8 = CONCAT31(local_8._1_3_,5);
    if (piVar2 == (int *)0x0) {
      local_14 = 0.0;
    }
    else {
      iVar6 = Tcl_GetDoubleFromObj(0,piVar2,&local_30);
      if (iVar6 == 1) {
        local_14 = 0.0;
      }
      else {
        local_14 = (float)local_30;
      }
    }
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + 1;
    }
    local_1c = FUN_00582fc0(local_18);
    if (local_1c == 0xffffffff) {
      bVar3 = true;
    }
    else {
      if (*(uint *)(iVar4 + 0x1a8) <= local_1c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      bVar3 = false;
      *(float *)(local_1c * 0x54 + 0x3c + *(int *)(iVar4 + 0x1a4)) = local_14;
    }
    local_8._0_1_ = 6;
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (bVar3) {
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("invalid Template",piVar1);
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
    pcVar7 = TclFreeObj_exref;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
      pcVar7 = TclFreeObj_exref;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar7)(piVar1);
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar8 = 1;
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_3c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

