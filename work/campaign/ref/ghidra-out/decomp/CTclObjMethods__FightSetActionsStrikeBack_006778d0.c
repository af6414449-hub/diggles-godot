
undefined4
CTclObjMethods__FightSetActionsStrikeBack
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  code *pcVar7;
  undefined8 uVar8;
  int **ppiVar9;
  uint uVar10;
  int local_60;
  undefined1 local_50 [12];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  undefined4 *local_2c;
  int local_28;
  undefined4 local_24;
  int *piStack_20;
  int *local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710c4d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7510) &&
     (FUN_006cebf4(&DAT_00ca7510,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7510 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7514 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclObjMethods::FightSetActionsStrikeBack()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7510);
  }
  iVar6 = DAT_00ca7514;
  local_2c = &DAT_00ca7514;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7514 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_28 = FUN_005c71c0(param_4,3,1);
  if (local_28 != 0) {
    local_18 = 1.2;
    if (2 < param_3) {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = local_38;
        if (local_34 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar4 = local_38;
        }
      }
      else {
        if (local_34 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar4 = local_38 + 2;
      }
      piVar2 = (int *)*puVar4;
      if (piVar2 == (int *)0x0) {
        local_18 = 0.0;
      }
      else {
        *piVar2 = *piVar2 + 1;
        iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_24);
        if (iVar3 == 1) {
          local_18 = 0.0;
        }
        else {
          local_18 = (float)(double)CONCAT44(piStack_20,local_24);
        }
        *piVar2 = *piVar2 + -1;
        if (*piVar2 < 1) {
          TclFreeObj(piVar2);
        }
      }
    }
    local_14 = local_14 & 0xffffff00;
    if (3 < param_3) {
      if (local_30 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = local_38;
        if (local_34 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar4 = local_38;
        }
      }
      else {
        if (local_34 < 4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar4 = local_38 + 3;
      }
      piVar2 = (int *)*puVar4;
      if (piVar2 == (int *)0x0) {
        local_14 = local_14 & 0xffffff00;
      }
      else {
        *piVar2 = *piVar2 + 1;
        iVar3 = Tcl_GetBooleanFromObj(0,piVar2,&piStack_20);
        if (iVar3 == 1) {
          local_14 = (uint)local_14._1_3_ << 8;
        }
        else {
          local_14 = CONCAT31(local_14._1_3_,piStack_20 != (int *)0x0);
        }
        *piVar2 = *piVar2 + -1;
        if (*piVar2 < 1) {
          TclFreeObj(piVar2);
        }
      }
    }
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    pcVar7 = TclFreeObj_exref;
    if (4 < param_3) {
      if (local_30 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = local_38;
        if (local_34 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar4 = local_38;
        }
      }
      else {
        if (local_34 < 5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar4 = local_38 + 4;
      }
      piVar2 = (int *)*puVar4;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      piStack_20 = piVar2;
      puVar4 = (undefined4 *)FUN_006bafe0(local_50);
      pcVar7 = TclFreeObj_exref;
      local_44 = *puVar4;
      local_40 = puVar4[1];
      local_3c = puVar4[2];
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
    }
    piVar5 = (int *)FUN_006ba810(0x19);
    piVar2 = piVar5 + 3;
    piVar5[2] = -1;
    *piVar5 = 0;
    *(undefined1 *)piVar2 = 0;
    piVar5[1] = 0x14;
    *piVar2 = 0x73696874;
    *(undefined1 *)(piVar5 + 4) = 0;
    iVar3 = 1;
    piVar5[2] = 4;
    *piVar5 = 1;
    if (local_60 != 0) {
      Tcl_GetAssocData(local_60,piVar2,0);
      iVar3 = *piVar5;
    }
    local_8._0_1_ = 5;
    *piVar5 = iVar3 + -1;
    if (iVar3 + -1 == 0) {
      FUN_006ba940();
    }
    puVar4 = &local_44;
    local_8 = CONCAT31(local_8._1_3_,2);
    ppiVar9 = &local_1c;
    iVar3 = local_28;
    uVar10 = local_14;
    FUN_005bbb20(ppiVar9,local_28,local_14,puVar4);
    FUN_005c1140(ppiVar9,iVar3,uVar10,puVar4);
    if (local_60 != 0) {
      if (local_1c == (int *)0x0) {
        Tcl_ResetResult(local_60);
      }
      else {
        Tcl_SetObjResult(local_60,local_1c);
      }
    }
    if (local_1c != (int *)0x0) {
      *local_1c = *local_1c + -1;
      if (*local_1c < 1) {
        (*pcVar7)(local_1c);
      }
      local_1c = (int *)0x0;
    }
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_004297b0(0);
    if (local_38 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

