
undefined4
CTclObjMethods__FightSetActions
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  int **ppiVar9;
  int **ppiVar10;
  int **ppiVar11;
  uint uVar12;
  int local_4c;
  undefined4 *local_3c;
  uint local_38;
  int local_34;
  int *local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710c0d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7508) &&
     (FUN_006cebf4(&DAT_00ca7508,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7508 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca750c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclObjMethods::FightSetActions()";
    *(int *)(&DAT_00773650 + iVar6) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7508);
  }
  iVar6 = DAT_00ca750c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca750c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,5,1);
  if (iVar2 == 0) {
    uVar7 = 1;
  }
  else {
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
    if (local_4c == 0) {
      local_24 = local_4c;
      iVar2 = 1;
    }
    else {
      local_24 = Tcl_GetAssocData(local_4c,piVar1,0);
      iVar2 = *piVar3;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar3 = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      FUN_006ba940();
    }
    if (local_34 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_3c + 2;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_34 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_3c + 3;
    }
    local_20 = (int *)*puVar4;
    if (local_20 != (int *)0x0) {
      *local_20 = *local_20 + 1;
    }
    if (local_34 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_3c + 4;
    }
    local_1c = (int *)*puVar4;
    if (local_1c != (int *)0x0) {
      *local_1c = *local_1c + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    local_14 = local_14 & 0xffffff00;
    if (5 < param_3) {
      if (local_34 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = local_3c;
        if (local_38 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_38 < 6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar4 = local_3c + 5;
      }
      piVar3 = (int *)*puVar4;
      if (piVar3 == (int *)0x0) {
        local_14 = local_14 & 0xffffff00;
      }
      else {
        *piVar3 = *piVar3 + 1;
        iVar2 = Tcl_GetBooleanFromObj(0,piVar3,&local_28);
        if (iVar2 == 1) {
          local_14 = (uint)local_14._1_3_ << 8;
        }
        else {
          local_14 = CONCAT31(local_14._1_3_,local_28 != (int *)0x0);
        }
        *piVar3 = *piVar3 + -1;
        if (*piVar3 < 1) {
          TclFreeObj(piVar3);
        }
      }
    }
    if (piVar1 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar5);
    local_8._0_1_ = 7;
    iVar2 = FUN_006055d0(param_2,local_24,&local_28);
    local_8._0_1_ = 8;
    if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    if ((iVar2 == 0) || (iVar2 = CTclObjMethods__Base2Obj(), iVar2 == 0)) {
      uVar7 = 1;
    }
    else {
      ppiVar11 = &local_1c;
      ppiVar10 = &local_20;
      ppiVar9 = &local_18;
      iVar6 = local_24;
      uVar12 = local_14;
      FUN_005bbb20(ppiVar9,local_24,iVar2,ppiVar10,ppiVar11,local_14);
      CFightActionMgr__DoObjActions(ppiVar9,iVar6,iVar2,ppiVar10,ppiVar11,uVar12);
      if (local_4c != 0) {
        if (local_18 == (int *)0x0) {
          Tcl_ResetResult(local_4c);
        }
        else {
          Tcl_SetObjResult(local_4c,local_18);
        }
      }
      uVar7 = 0;
      if (local_18 != (int *)0x0) {
        *local_18 = *local_18 + -1;
        if (*local_18 < 1) {
          TclFreeObj(local_18);
        }
        local_18 = (int *)0x0;
      }
    }
    if (local_1c != (int *)0x0) {
      *local_1c = *local_1c + -1;
      if (*local_1c < 1) {
        TclFreeObj(local_1c);
      }
      local_1c = (int *)0x0;
    }
    if (local_20 != (int *)0x0) {
      *local_20 = *local_20 + -1;
      if (*local_20 < 1) {
        TclFreeObj(local_20);
      }
      local_20 = (int *)0x0;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_004297b0(0);
  if (local_3c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

