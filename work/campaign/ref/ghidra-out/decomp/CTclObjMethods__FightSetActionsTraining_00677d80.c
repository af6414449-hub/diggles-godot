
undefined4
CTclObjMethods__FightSetActionsTraining
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  int **ppiVar8;
  int **ppiVar9;
  uint uVar10;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_20;
  int local_1c;
  uint local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710c95;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7518) &&
     (FUN_006cebf4(&DAT_00ca7518,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7518 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca751c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::FightSetActionsTraining()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7518);
  }
  iVar4 = DAT_00ca751c;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca751c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
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
  iVar2 = FUN_005c71c0(param_4,4,1);
  if (iVar2 == 0) {
    uVar6 = 1;
  }
  else {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_30 + 2;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 == (int *)0x0) {
      local_18 = local_18 & 0xffffff00;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar2 = Tcl_GetBooleanFromObj(0,piVar1,&local_1c);
      if (iVar2 == 1) {
        local_18 = (uint)local_18._1_3_ << 8;
      }
      else {
        local_18 = CONCAT31(local_18._1_3_,local_1c != 0);
      }
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar1 = piVar3 + 3;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)piVar1 = 0;
    piVar3[1] = 0x14;
    *piVar1 = 0x73696874;
    *(undefined1 *)(piVar3 + 4) = 0;
    piVar3[2] = 4;
    *piVar3 = 1;
    if (local_40 == 0) {
      local_1c = local_40;
      iVar2 = 1;
    }
    else {
      local_1c = Tcl_GetAssocData(local_40,piVar1,0);
      iVar2 = *piVar3;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar3 = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      FUN_006ba940();
    }
    if (local_28 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_30 + 3;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    ppiVar9 = &local_20;
    local_8 = CONCAT31(local_8._1_3_,4);
    ppiVar8 = &local_14;
    iVar2 = local_1c;
    uVar10 = local_18;
    local_20 = piVar1;
    FUN_005bbb20(ppiVar8,local_1c,ppiVar9,local_18);
    FUN_005c0ef0(ppiVar8,iVar2,ppiVar9,uVar10);
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    if (local_40 != 0) {
      if (local_14 == (int *)0x0) {
        Tcl_ResetResult(local_40);
      }
      else {
        Tcl_SetObjResult(local_40,local_14);
      }
    }
    uVar6 = 0;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + -1;
      if (*local_14 < 1) {
        TclFreeObj(local_14);
      }
      local_14 = (int *)0x0;
    }
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

