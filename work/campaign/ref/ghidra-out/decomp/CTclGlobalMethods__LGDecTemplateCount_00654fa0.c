
undefined4
CTclGlobalMethods__LGDecTemplateCount
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  undefined **ppuVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e9fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7258) &&
     (FUN_006cebf4(&DAT_00ca7258,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7258 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca725c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::LGDecTemplateCount()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7258);
  }
  iVar7 = DAT_00ca725c;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca725c * 0x40);
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
  if (param_3 == 2) {
    iVar4 = FUN_0058a820();
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_2c + 1;
    }
    piVar2 = (int *)*puVar9;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar2 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
    }
    FUN_006b8fb0(ppuVar5);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    uVar6 = FUN_00582fc0(local_14);
    if (uVar6 == 0xffffffff) {
      bVar3 = true;
    }
    else {
      if (*(uint *)(iVar4 + 0x1a8) <= uVar6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar7 = *(int *)(iVar4 + 0x1a4);
      if (*(int *)(iVar7 + 0x1c + uVar6 * 0x54) != 0) {
        if (*(uint *)(iVar4 + 0x1a8) <= uVar6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(iVar4 + 0x1a4);
        }
        piVar1 = (int *)(uVar6 * 0x54 + 0x1c + iVar7);
        *piVar1 = *piVar1 + -1;
      }
      bVar3 = false;
    }
    local_8._0_1_ = 5;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if (bVar3) {
      FUN_006bc6a0("invalid Template",0);
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar8 = 1;
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
  return uVar8;
}

