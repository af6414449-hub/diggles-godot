
undefined4
CTclGlobalMethods__VectorFixDig
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  undefined8 uVar8;
  int local_54;
  undefined1 local_44 [12];
  undefined1 local_38 [12];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d0ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6f00) &&
     (FUN_006cebf4(&DAT_00ca6f00,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6f00 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6f04 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::VectorFixDig()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6f00);
  }
  iVar7 = DAT_00ca6f04;
  local_14 = &DAT_00ca6f04;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6f04 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar8 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (1 < param_3) {
    local_8._0_1_ = uVar3;
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_20;
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_20 + 1;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 == (int *)0x0) {
      FUN_006bafe0(&local_2c);
    }
    else {
      *piVar2 = *piVar2 + 1;
      FUN_006bafe0(&local_2c);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_18 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_20;
      }
    }
    else {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_20 + 2;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 == (int *)0x0) {
      FUN_006bafe0(local_38);
    }
    else {
      *piVar2 = *piVar2 + 1;
      FUN_006bafe0(local_38);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    puVar5 = (undefined4 *)FUN_00594e00(local_44,&local_2c,local_38);
    local_2c = *puVar5;
    local_28 = puVar5[1];
    local_24 = puVar5[2];
    piVar6 = (int *)FUN_006badc0(&local_2c);
    if (local_54 != 0) {
      if (*piVar6 == 0) {
        Tcl_ResetResult(local_54);
      }
      else {
        Tcl_SetObjResult(local_54,*piVar6);
      }
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_004297b0(0);
    if (local_20 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  FUN_006bc8f0(1);
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

