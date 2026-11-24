
undefined4
CTclGlobalMethods__Screen2World
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  float *pfVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  int local_48;
  undefined1 local_38 [12];
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e0ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7168) &&
     (FUN_006cebf4(&DAT_00ca7168,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7168 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca716c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::Screen2World()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7168);
  }
  iVar7 = DAT_00ca716c;
  local_14 = &DAT_00ca716c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca716c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
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
  local_8._0_1_ = 2;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (1 < param_3) {
    local_8._0_1_ = uVar3;
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_2c;
      }
    }
    else {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_2c + 1;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    FUN_006bafe0(&local_20);
    local_20 = (float)*(int *)(DAT_0076a338 + 0x2830) * local_20;
    local_1c = (float)*(int *)(DAT_0076a338 + 0x2834) * local_1c;
    local_18 = local_18 * 0.5 + 7.0;
    pfVar5 = (float *)FUN_00479150(local_38,&local_20);
    local_20 = *pfVar5;
    local_1c = pfVar5[1];
    local_18 = (pfVar5[2] - 7.0) + (pfVar5[2] - 7.0);
    piVar6 = (int *)FUN_006badc0(&local_20);
    if (local_48 != 0) {
      if (*piVar6 == 0) {
        Tcl_ResetResult(local_48);
      }
      else {
        Tcl_SetObjResult(local_48,*piVar6);
      }
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_004297b0(0);
    if (local_2c != (undefined4 *)0x0) {
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
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

