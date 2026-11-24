
undefined4 CTclGlobalMethods__DefTextures(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d82d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7060) &&
     (FUN_006cebf4(), iVar2 = DAT_00783650, DAT_00ca7060 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7064 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::DefTextures()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar4 = DAT_00ca7064;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7064 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0(param_3);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 2) {
    FUN_006bc8f0();
    uVar5 = 1;
  }
  else if (param_3 < 0x23) {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_2c + 1;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar1 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1);
    }
    FUN_006b8fb0(ppuVar3);
    local_8._0_1_ = 4;
    FUN_004dc6e0();
    local_8 = CONCAT31(local_8._1_3_,3);
    uVar5 = FUN_004dc7a0();
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj();
    }
    param_3 = param_3 + -2;
    if (0 < param_3) {
      uVar7 = 2;
      do {
        if (((int)uVar7 < 0) || (local_24 <= (int)uVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar6 = local_2c;
          if (local_28 == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        else {
          if (local_28 <= uVar7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar6 = local_2c + uVar7;
        }
        piVar1 = (int *)*puVar6;
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        local_8._0_1_ = 5;
        if (piVar1 == (int *)0x0) {
          ppuVar3 = &PTR_0071ce50;
        }
        else {
          ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1);
        }
        FUN_006b8fb0(ppuVar3);
        local_8._0_1_ = 6;
        uVar9 = uVar5;
        FUN_004dc6e0(uVar5);
        local_8 = CONCAT31(local_8._1_3_,5);
        FUN_004dc9d0(uVar9);
        if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
          TclFreeObj();
        }
        uVar7 = uVar7 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    uVar5 = 0;
  }
  else {
    FUN_006bc8f0();
    uVar5 = 1;
  }
  local_8._0_1_ = 7;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0();
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

