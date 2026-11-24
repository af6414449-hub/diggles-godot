
undefined4
CTclObjMethods__TaskListAddFront
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
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
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7bf8) &&
     (FUN_006cebf4(&DAT_00ca7bf8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7bf8 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7bfc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::TaskListAddFront()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7bf8);
  }
  iVar7 = DAT_00ca7bfc;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7bfc * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar6;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar9 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar4 = FUN_005c71c0(param_4,3,1);
  if (iVar4 == 0) {
    uVar6 = 1;
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
    piVar1 = (int *)*puVar8;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar1 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar5);
    local_8 = CONCAT31(local_8._1_3_,4);
    iVar7 = *(int *)(iVar4 + 100);
    if ((iVar7 + 0x40U & 0xffffffc0) != (iVar7 + 0x3fU & 0xffffffc0)) {
      uVar6 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      *(undefined4 *)(iVar4 + 0x60) = uVar6;
      iVar7 = *(int *)(iVar4 + 100);
    }
    if (0 < iVar7) {
      FUN_006d1b90(*(int *)(iVar4 + 0x60) + 4,*(int *)(iVar4 + 0x60),iVar7 * 4);
      iVar7 = *(int *)(iVar4 + 100);
    }
    *(int *)(iVar4 + 100) = iVar7 + 1;
    FUN_005d9b40(0);
    if (*(int *)(iVar4 + 100) == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar2 = *(int **)(iVar4 + 0x60);
    piVar3 = (int *)*piVar2;
    *piVar2 = (int)local_18;
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + 1;
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*piVar2 + 8) = local_18[2];
    local_8 = CONCAT31(local_8._1_3_,5);
    *local_18 = *local_18 + -1;
    if (*local_18 == 0) {
      FUN_006ba940();
    }
    uVar6 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
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
  return uVar6;
}

