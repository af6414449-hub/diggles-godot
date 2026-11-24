
undefined4
CTclGlobalMethods__IsUnderWater
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  int local_3c;
  undefined1 local_2c [12];
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f315;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca73c8) &&
     (FUN_006cebf4(&DAT_00ca73c8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca73c8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca73cc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::IsUnderWater()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca73c8);
  }
  iVar5 = DAT_00ca73cc;
  local_14 = &DAT_00ca73cc;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca73cc * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar7 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 2) {
    FUN_004298b0(2,param_4);
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_20;
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_20 + 1;
    }
    piVar4 = (int *)*puVar6;
    if (piVar4 == (int *)0x0) {
      FUN_006bafe0(local_2c);
    }
    else {
      *piVar4 = *piVar4 + 1;
      FUN_006bafe0(local_2c);
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
    uVar2 = FUN_0057a940();
    piVar4 = (int *)Tcl_NewBooleanObj(uVar2);
    *piVar4 = *piVar4 + 1;
    iVar3 = *piVar4;
    if (local_3c != 0) {
      Tcl_SetObjResult(local_3c,piVar4);
      iVar3 = *piVar4;
    }
    *piVar4 = iVar3 + -1;
    if (iVar3 + -1 < 1) {
      TclFreeObj(piVar4);
    }
    local_8._0_1_ = 2;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,3);
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
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

