
undefined4
CTclObjMethods__TaskListAdd
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined **ppuVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071207d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7bf0) &&
     (FUN_006cebf4(&DAT_00ca7bf0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca7bf0 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7bf4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::TaskListAdd()";
    *(int *)(&DAT_00773650 + iVar7) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7bf0);
  }
  iVar7 = DAT_00ca7bf4;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7bf4 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar9;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar5 == 0) {
    uVar10 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar5 = FUN_005c71c0(param_4,3,1);
  if (iVar5 == 0) {
    uVar9 = 1;
  }
  else {
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
    piVar3 = (int *)*puVar8;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar3 == (int *)0x0) {
      ppuVar6 = &PTR_0071ce50;
    }
    else {
      ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
    }
    FUN_006b8fb0(ppuVar6);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_005d9a70(1);
    uVar1 = *(uint *)(iVar5 + 100) - 1;
    if (*(uint *)(iVar5 + 100) <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar2 = (int *)(*(int *)(iVar5 + 0x60) + uVar1 * 4);
    piVar4 = (int *)*piVar2;
    *piVar2 = (int)local_18;
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + 1;
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*piVar2 + 8) = local_18[2];
    local_8 = CONCAT31(local_8._1_3_,5);
    *local_18 = *local_18 + -1;
    if (*local_18 == 0) {
      FUN_006ba940();
    }
    uVar9 = 0;
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
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
  return uVar9;
}

