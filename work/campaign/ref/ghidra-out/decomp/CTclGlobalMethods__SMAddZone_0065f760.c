
undefined4
CTclGlobalMethods__SMAddZone(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined **ppuVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f08d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7368) &&
     (FUN_006cebf4(&DAT_00ca7368,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7368 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca736c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::SMAddZone()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7368);
  }
  iVar7 = DAT_00ca736c;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca736c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 2) {
    FUN_004298b0(2,param_4);
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_30 + 1;
    }
    piVar2 = (int *)*puVar9;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar2 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
    }
    FUN_006b8fb0(ppuVar5);
    local_8 = CONCAT31(local_8._1_3_,4);
    iVar4 = FUN_005f8080();
    FUN_004c4160(1);
    uVar1 = *(uint *)(iVar4 + 0x70) - 1;
    if (*(uint *)(iVar4 + 0x70) <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar6 = (int *)(*(int *)(iVar4 + 0x6c) + uVar1 * 8);
    piVar3 = (int *)*piVar6;
    *piVar6 = (int)local_18;
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + 1;
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*piVar6 + 8) = local_18[2];
    if (*(uint *)(iVar4 + 0x70) <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(undefined4 *)(*(int *)(iVar4 + 0x6c) + 4 + uVar1 * 8) = 0xffffffff;
    local_8 = CONCAT31(local_8._1_3_,5);
    *local_18 = *local_18 + -1;
    if (*local_18 == 0) {
      FUN_006ba940();
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    uVar8 = 0;
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_004297b0(0);
    if (local_30 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar8 = 1;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

