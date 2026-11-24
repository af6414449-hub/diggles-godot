
undefined4
CTclGlobalMethods__DigNext(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined8 uVar10;
  int local_50;
  undefined1 local_40 [12];
  undefined1 local_34 [12];
  undefined4 *local_28;
  uint local_24;
  int local_20;
  undefined4 *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar3 = (uint)param_3;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d055;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ee0) &&
     (FUN_006cebf4(&DAT_00ca6ee0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca6ee0 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca6ee4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclGlobalMethods::DigNext()";
    *(int *)(&DAT_00773650 + iVar9) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6ee0);
  }
  iVar9 = DAT_00ca6ee4;
  local_1c = &DAT_00ca6ee4;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6ee4 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar1;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar5 == 0) {
    uVar10 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if ((int)param_3 - 3U < 3) {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_28;
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_28 + 1;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    local_18 = piVar2;
    FUN_006bafe0(local_34);
    iVar5 = FUN_005c71c0(param_4,0,2);
    if (iVar5 != 0) {
      if (param_3 == (int *)0x4) {
        puVar6 = (undefined4 *)FUN_004295e0(3);
        param_3 = (int *)*puVar6;
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + 1;
        }
        iVar7 = FUN_006baee0();
        FUN_006bad60();
        param_3 = (int *)((uint)param_3 & 0xffffff00);
        iVar9 = 0;
        if (-1 < iVar7) {
          iVar9 = iVar7;
        }
      }
      else {
        param_3 = (int *)((uint)param_3 & 0xffffff00);
        iVar9 = 0;
        if (uVar3 == 5) {
          puVar6 = (undefined4 *)FUN_004295e0(4);
          local_14 = (int *)*puVar6;
          if (local_14 != (int *)0x0) {
            *local_14 = *local_14 + 1;
          }
          bVar4 = FUN_006baf10();
          param_3 = (int *)(uint)bVar4;
          FUN_006bad60();
          iVar9 = 0;
        }
      }
      FUN_00597b20(local_40,local_34,iVar5,iVar9 + 1,param_3);
      piVar8 = (int *)FUN_006badc0(local_40);
      if (local_50 != 0) {
        if (*piVar8 == 0) {
          Tcl_ResetResult(local_50);
        }
        else {
          Tcl_SetObjResult(local_50,*piVar8);
        }
      }
      if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
        TclFreeObj(param_3);
      }
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
      local_8._0_1_ = 8;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_004297b0(0);
      if (local_28 != (undefined4 *)0x0) {
        FUN_006ba940();
      }
      FUN_006bc0d0();
      FUN_0043fd30();
      ExceptionList = local_10;
      return 0;
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,7);
  }
  else {
    FUN_006bc8f0(2);
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

