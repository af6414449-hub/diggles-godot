
undefined4
CTclObjMethods__FightSetActionsBallistic
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  code *pcVar8;
  undefined8 uVar9;
  int **ppiVar10;
  int *piVar11;
  int **ppiVar12;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710cf5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7520) &&
     (FUN_006cebf4(&DAT_00ca7520,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7520 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7524 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::FightSetActionsBallistic()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7520);
  }
  iVar5 = DAT_00ca7524;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7524 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,4,1);
  if (iVar2 == 0) {
    uVar6 = 1;
    goto LAB_006783da;
  }
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar11 = piVar3 + 3;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)piVar11 = 0;
  piVar3[1] = 0x14;
  *piVar11 = 0x73696874;
  *(undefined1 *)(piVar3 + 4) = 0;
  piVar3[2] = 4;
  *piVar3 = 1;
  if (local_40 == 0) {
    iVar2 = 1;
    local_18 = (int *)0x0;
  }
  else {
    local_18 = (int *)Tcl_GetAssocData(local_40,piVar11,0);
    iVar2 = *piVar3;
  }
  piVar11 = local_18;
  local_8 = CONCAT31(local_8._1_3_,3);
  *piVar3 = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    FUN_006ba940();
  }
  if (local_28 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_30 + 2;
  }
  piVar3 = (int *)*puVar7;
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
  }
  if (local_28 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_30 + 3;
  }
  piVar1 = (int *)*puVar7;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8._0_1_ = 5;
  local_1c = piVar1;
  if (piVar3 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
  }
  FUN_006b8fb0(ppuVar4);
  local_8._0_1_ = 6;
  iVar2 = FUN_006055d0(param_2,piVar11,&local_14);
  local_8._0_1_ = 7;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  if ((iVar2 == 0) || (iVar2 = CTclObjMethods__Base2Obj(), iVar2 == 0)) {
    uVar6 = 1;
  }
  else {
    ppiVar12 = &local_1c;
    ppiVar10 = &local_18;
    piVar11 = local_18;
    FUN_005bbb20(ppiVar10,local_18,iVar2,ppiVar12);
    FUN_005c2910(ppiVar10,piVar11,iVar2,ppiVar12);
    if (local_40 != 0) {
      if (local_18 == (int *)0x0) {
        Tcl_ResetResult(local_40);
        uVar6 = 0;
        goto LAB_006783aa;
      }
      Tcl_SetObjResult(local_40,local_18);
    }
    uVar6 = 0;
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
      TclFreeObj(local_18);
    }
  }
LAB_006783aa:
  pcVar8 = TclFreeObj_exref;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, pcVar8 = TclFreeObj_exref, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
    (*pcVar8)(piVar3);
  }
LAB_006783da:
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

