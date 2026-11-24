
undefined4
CTclGlobalMethods__LGSetObjCount
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined4 *local_5c;
  uint local_58;
  int local_54;
  double local_50;
  double local_48;
  double local_40;
  int *local_38;
  undefined4 *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int local_24;
  float local_20;
  float local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e7d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7220) &&
     (FUN_006cebf4(&DAT_00ca7220,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7220 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7224 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::LGSetObjCount()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7220);
  }
  iVar7 = DAT_00ca7224;
  local_34 = &DAT_00ca7224;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7224 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 5) {
    iVar4 = FUN_0058a820();
    if (local_54 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_5c;
      if (local_58 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_58 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_5c + 1;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    local_38 = piVar1;
    if (piVar1 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar5);
    if (local_54 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_5c;
      if (local_58 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_58 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_5c + 4;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (local_54 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_5c;
      if (local_58 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_58 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_5c + 3;
    }
    local_2c = (int *)*puVar6;
    if (local_2c != (int *)0x0) {
      *local_2c = *local_2c + 1;
    }
    if (local_54 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_5c;
      if (local_58 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_58 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_5c + 2;
    }
    local_28 = (int *)*puVar6;
    if (local_28 != (int *)0x0) {
      *local_28 = *local_28 + 1;
    }
    local_18 = 0.0;
    if (piVar2 == (int *)0x0) {
      local_20 = 0.0;
    }
    else {
      iVar7 = Tcl_GetDoubleFromObj(0,piVar2,&local_40);
      if (iVar7 == 1) {
        local_20 = 0.0;
      }
      else {
        local_20 = (float)local_40;
      }
    }
    local_1c = 0.0;
    if (local_2c != (int *)0x0) {
      iVar7 = Tcl_GetDoubleFromObj(0,local_2c,&local_48);
      if (iVar7 == 1) {
        local_1c = 0.0;
      }
      else {
        local_1c = (float)local_48;
      }
    }
    if (local_28 != (int *)0x0) {
      iVar7 = Tcl_GetDoubleFromObj(0,local_28,&local_50);
      if (iVar7 == 1) {
        local_18 = 0.0;
      }
      else {
        local_18 = (float)local_50;
      }
    }
    local_14 = 0;
    if (0 < *(int *)(iVar4 + 0x1a0)) {
      bVar9 = *(int *)(iVar4 + 0x1a0) != 0;
      do {
        if (!bVar9) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar3 = FUN_006b97f0(&local_30);
        if (cVar3 != '\0') {
          if (*(uint *)(iVar4 + 0x6c) <= local_14) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_24 = local_14 * 0xc;
          *(float *)(local_24 + *(int *)(iVar4 + 0x68)) = local_18;
          if (*(uint *)(iVar4 + 0x6c) <= local_14) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(float *)(local_24 + 8 + *(int *)(iVar4 + 0x68)) = local_1c;
          if (*(uint *)(iVar4 + 0x6c) <= local_14) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          bVar9 = false;
          *(float *)(local_24 + 4 + *(int *)(iVar4 + 0x68)) = local_20;
          goto LAB_00652330;
        }
        local_14 = local_14 + 1;
        bVar9 = local_14 < *(uint *)(iVar4 + 0x1a0);
      } while ((int)local_14 < (int)*(uint *)(iVar4 + 0x1a0));
    }
    bVar9 = true;
LAB_00652330:
    if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 < 1)) {
      TclFreeObj(local_28);
    }
    if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c < 1)) {
      TclFreeObj(local_2c);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 4;
    if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    if (bVar9) {
      FUN_006bc6a0("invalid objfilter",0);
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
  }
  else {
    FUN_006bc8f0(4);
    uVar8 = 1;
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_5c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

