
undefined4
CTclObjMethods__TaskListRem
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  uint local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007120cd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c08) &&
     (FUN_006cebf4(&DAT_00ca7c08,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7c08 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7c0c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::TaskListRem()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c08);
  }
  iVar5 = DAT_00ca7c0c;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c0c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = FUN_005c71c0(param_4,3,1);
  if (local_14 == 0) {
    uVar8 = 1;
    goto LAB_006a1564;
  }
  if (local_28 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_30 + 2;
  }
  piVar2 = (int *)*puVar6;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (piVar2 == (int *)0x0) {
    uVar4 = 0;
  }
  else {
    iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_1c);
    uVar4 = -(uint)(iVar3 != 1) & local_1c;
  }
  FUN_005cdd80(&local_18,uVar4);
  if (piVar2 == (int *)0x0) {
    uVar4 = 0;
LAB_006a1461:
    if ((int)uVar4 < *(int *)(local_14 + 100)) {
      if ((*(uint *)(local_14 + 100) <= uVar4) &&
         (RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0), *(uint *)(local_14 + 100) <= uVar4)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar3 = local_14;
      local_8 = CONCAT31(local_8._1_3_,5);
      piVar7 = *(int **)(*(int *)(local_14 + 0x60) + uVar4 * 4);
      if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 == 0)) {
        FUN_006ba940();
      }
      iVar5 = *(int *)(iVar3 + 100);
      if ((int)uVar4 < iVar5 + -1) {
        iVar1 = *(int *)(iVar3 + 0x60) + uVar4 * 4;
        FUN_006d1b90(iVar1,iVar1 + 4,(iVar5 - uVar4) * 4 + -4);
        iVar5 = *(int *)(iVar3 + 100);
      }
      *(int *)(iVar3 + 100) = iVar5 + -1;
    }
  }
  else {
    iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_1c);
    if (iVar3 == 1) {
      uVar4 = 0;
      goto LAB_006a1461;
    }
    uVar4 = local_1c;
    if (-1 < (int)local_1c) goto LAB_006a1461;
  }
  if (local_18 + 3 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)Tcl_NewStringObj(local_18 + 3,0xffffffff);
    *piVar7 = *piVar7 + 1;
  }
  if (local_40 == 0) {
    if (piVar7 != (int *)0x0) goto LAB_006a152d;
  }
  else if (piVar7 == (int *)0x0) {
    Tcl_ResetResult(local_40);
  }
  else {
    Tcl_SetObjResult(local_40,piVar7);
LAB_006a152d:
    *piVar7 = *piVar7 + -1;
    if (*piVar7 < 1) {
      TclFreeObj(piVar7);
    }
  }
  uVar8 = 0;
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
LAB_006a1564:
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

