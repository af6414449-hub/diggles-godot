
undefined4
CFightActionMgr__Tcl_FightMapClass2DB
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  undefined **ppuVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  code *pcVar11;
  undefined8 uVar12;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  undefined **local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007081cd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6610) &&
     (FUN_006cebf4(&DAT_00ca6610,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca6610 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6614 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CFightActionMgr::Tcl_FightMapClass2DB()";
    *(int *)(&DAT_00773650 + iVar7) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6610);
  }
  iVar7 = DAT_00ca6614;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6614 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar9;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar5 == 0) {
    uVar12 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar3 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (uVar3 == 3) {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_34 + 1;
    }
    piVar1 = (int *)*puVar10;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (piVar1 == (int *)0x0) {
      ppuVar6 = &PTR_0071ce50;
    }
    else {
      ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar6);
    iVar5 = DAT_00772478;
    cVar4 = FUN_006037d0(&local_14,&param_3);
    if (cVar4 == '\0') {
      iVar5 = 0;
    }
    else {
      if (*(uint *)(iVar5 + 0x801c) <= param_3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar5 = *(int *)(*(int *)(iVar5 + 0x8018) + param_3 * 4);
    }
    local_8._0_1_ = 4;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    pcVar11 = TclFreeObj_exref;
    local_8 = CONCAT31(local_8._1_3_,3);
    if (iVar5 == 0) {
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("Invalid Class",piVar1);
      uVar9 = 1;
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar10 = local_34;
        if (local_30 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_30 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar10 = local_34 + 2;
      }
      piVar2 = (int *)*puVar10;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,5);
      param_3 = FUN_005bbb20();
      FUN_005c6500(1);
      piVar8 = *(int **)(param_3 + 0x2c);
      local_14 = (int *)((int)piVar8 + -1);
      if (piVar1 == (int *)0x0) {
        local_18 = &PTR_0071ce50;
      }
      else {
        local_18 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
        piVar8 = *(int **)(param_3 + 0x2c);
      }
      if (piVar8 <= local_14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_006b9200(local_18);
      if (piVar2 == (int *)0x0) {
        local_18 = &PTR_0071ce50;
      }
      else {
        local_18 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
      }
      if (*(int **)(param_3 + 0x2c) <= local_14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_006b9200(local_18);
      uVar9 = 0;
      pcVar11 = TclFreeObj_exref;
      if ((piVar2 != (int *)0x0) &&
         (*piVar2 = *piVar2 + -1, pcVar11 = TclFreeObj_exref, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar11)(piVar1);
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar9 = 1;
  }
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

