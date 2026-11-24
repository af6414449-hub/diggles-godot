
undefined4
CTclGlobalMethods__LGSetTemplateGroupValue
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  undefined8 uVar11;
  undefined4 *local_4c;
  uint local_48;
  int local_44;
  double local_40;
  int *local_38;
  int *local_34;
  undefined4 *local_30;
  int *local_2c;
  int *local_28;
  uint local_24;
  int *local_20;
  uint local_1c;
  int local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e455;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca71b8) &&
     (FUN_006cebf4(&DAT_00ca71b8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca71b8 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca71bc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::LGSetTemplateGroupValue()";
    *(int *)(&DAT_00773650 + iVar6) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca71b8);
  }
  iVar6 = DAT_00ca71bc;
  local_30 = &DAT_00ca71bc;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca71bc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar2 == 0) {
    uVar11 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_18 = FUN_0058a820();
  if (param_3 == 3) {
    if (local_44 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_4c + 1;
    }
    piVar9 = (int *)*puVar8;
    if (piVar9 != (int *)0x0) {
      *piVar9 = *piVar9 + 1;
    }
    local_34 = piVar9;
    local_28 = piVar9;
    if (local_44 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_4c + 2;
    }
    piVar10 = (int *)*puVar8;
    if (piVar10 != (int *)0x0) {
      *piVar10 = *piVar10 + 1;
    }
    local_8._0_1_ = 4;
    local_38 = piVar10;
    local_2c = piVar10;
    if (piVar9 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar9,0);
    }
    FUN_006b8fb0(ppuVar3);
    local_8 = CONCAT31(local_8._1_3_,5);
    if (piVar10 == (int *)0x0) {
      local_14 = 0.0;
    }
    else {
      iVar2 = Tcl_GetDoubleFromObj(0,piVar10,&local_40);
      if (iVar2 == 1) {
        local_14 = 0.0;
      }
      else {
        local_14 = (float)local_40;
      }
    }
    local_1c = FUN_00583450(&local_20);
    iVar2 = local_18;
    if (local_1c == 0xffffffff) {
      bVar1 = true;
    }
    else {
      uVar4 = local_1c * 0xc;
      param_3 = 0;
      local_24 = uVar4;
      while( true ) {
        if (*(uint *)(iVar2 + 0x3c) <= local_1c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_18 = *(int *)(iVar2 + 0x38);
        if (*(int *)(local_18 + 8 + uVar4) <= (int)param_3) break;
        if (*(uint *)(iVar2 + 0x3c) <= local_1c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_18 = *(int *)(iVar2 + 0x38);
        }
        if (*(uint *)(uVar4 + 8 + local_18) <= param_3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_24 = *(uint *)(*(int *)(uVar4 + 4 + local_18) + param_3 * 4);
        if (*(uint *)(iVar2 + 0x1a8) <= local_24) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        param_3 = param_3 + 1;
        *(float *)(local_24 * 0x54 + 0x3c + *(int *)(iVar2 + 0x1a4)) = local_14;
      }
      bVar1 = false;
      piVar9 = local_28;
      piVar10 = local_2c;
    }
    local_8._0_1_ = 6;
    if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (bVar1) {
      if (piVar9 != (int *)0x0) {
        *piVar9 = *piVar9 + 1;
      }
      FUN_006bc6a0("invalid TemplateSet",piVar9);
      uVar7 = 1;
    }
    else {
      uVar7 = 0;
    }
    pcVar5 = TclFreeObj_exref;
    if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
      TclFreeObj(piVar10);
      pcVar5 = TclFreeObj_exref;
    }
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
      (*pcVar5)(piVar9);
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar7 = 1;
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_4c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

