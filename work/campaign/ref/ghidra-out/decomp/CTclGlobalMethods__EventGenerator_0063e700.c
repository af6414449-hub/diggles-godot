
undefined4
CTclGlobalMethods__EventGenerator
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined **ppuVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  int *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d6bd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7030) &&
     (FUN_006cebf4(&DAT_00ca7030,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca7030 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7034 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::EventGenerator()";
    *(int *)(&DAT_00773650 + iVar7) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7030);
  }
  iVar7 = DAT_00ca7034;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7034 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar1;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar5 == 0) {
    uVar9 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 3) {
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_38 + 1;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (local_30 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_38 + 2;
    }
    piVar3 = (int *)*puVar8;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (((piVar2 == (int *)0x0) || (iVar5 = Tcl_ListObjLength(0,piVar2,&local_14), iVar5 != 0)) ||
       (local_14 != 4)) {
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      FUN_006bc6a0("param list needs 4 names",piVar2);
      param_3 = 1;
    }
    else {
      piVar4 = *(int **)(DAT_0077244c + 0x8488);
      *(int **)(DAT_0077244c + 0x8488) = piVar3;
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
        TclFreeObj(piVar4);
      }
      iVar5 = Tcl_ListObjIndex(0,piVar2,0,&local_18);
      if (iVar5 == 0) {
        local_1c = local_18;
        if (local_18 != (int *)0x0) {
          *local_18 = *local_18 + 1;
        }
      }
      else {
        local_1c = (int *)0x0;
      }
      piVar4 = local_1c;
      local_8 = CONCAT31(local_8._1_3_,5);
      if (local_1c == (int *)0x0) {
        ppuVar6 = &PTR_0071ce50;
      }
      else {
        ppuVar6 = (undefined **)Tcl_GetStringFromObj(local_1c,0);
      }
      FUN_006b9200(ppuVar6);
      if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
        TclFreeObj(piVar4);
      }
      iVar5 = Tcl_ListObjIndex(0,piVar2,1,&local_1c);
      if (iVar5 == 0) {
        local_18 = local_1c;
        if (local_1c != (int *)0x0) {
          *local_1c = *local_1c + 1;
        }
      }
      else {
        local_18 = (int *)0x0;
      }
      piVar4 = local_18;
      local_8 = CONCAT31(local_8._1_3_,6);
      if (local_18 == (int *)0x0) {
        ppuVar6 = &PTR_0071ce50;
      }
      else {
        ppuVar6 = (undefined **)Tcl_GetStringFromObj(local_18,0);
      }
      FUN_006b9200(ppuVar6);
      if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
        TclFreeObj(piVar4);
      }
      iVar5 = Tcl_ListObjIndex(0,piVar2,2,&local_1c);
      if (iVar5 == 0) {
        local_18 = local_1c;
        if (local_1c != (int *)0x0) {
          *local_1c = *local_1c + 1;
        }
      }
      else {
        local_18 = (int *)0x0;
      }
      piVar4 = local_18;
      local_8 = CONCAT31(local_8._1_3_,7);
      if (local_18 == (int *)0x0) {
        ppuVar6 = &PTR_0071ce50;
      }
      else {
        ppuVar6 = (undefined **)Tcl_GetStringFromObj(local_18,0);
      }
      FUN_006b9200(ppuVar6);
      if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
        TclFreeObj(piVar4);
      }
      iVar5 = Tcl_ListObjIndex(0,piVar2,3,&local_1c);
      if (iVar5 == 0) {
        local_18 = local_1c;
        if (local_1c != (int *)0x0) {
          *local_1c = *local_1c + 1;
        }
      }
      else {
        local_18 = (int *)0x0;
      }
      piVar4 = local_18;
      local_8 = CONCAT31(local_8._1_3_,8);
      if (local_18 == (int *)0x0) {
        ppuVar6 = &PTR_0071ce50;
      }
      else {
        ppuVar6 = (undefined **)Tcl_GetStringFromObj(local_18,0);
      }
      FUN_006b9200(ppuVar6);
      if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
        TclFreeObj(piVar4);
      }
      param_3 = 0;
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
  }
  else {
    FUN_006bc8f0(2);
    param_3 = 1;
  }
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return param_3;
}

