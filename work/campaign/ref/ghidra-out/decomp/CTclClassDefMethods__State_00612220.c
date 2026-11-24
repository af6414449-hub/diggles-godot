
undefined4
CTclClassDefMethods__State(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined **ppuVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  code *pcVar9;
  undefined8 uVar10;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  int *local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a65d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6b48) &&
     (FUN_006cebf4(&DAT_00ca6b48,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6b48 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6b4c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclClassDefMethods::State()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6b48);
  }
  iVar6 = DAT_00ca6b4c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6b4c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar7;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_18 = DAT_00772440;
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar7 = 1;
  }
  else if (param_3 == 3) {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_34 + 1;
    }
    piVar1 = (int *)*puVar8;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_34 + 2;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8._0_1_ = 4;
    local_20 = piVar2;
    if (piVar1 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar5);
    iVar4 = local_18;
    local_14 = FUN_00602170(&local_1c);
    local_8._0_1_ = 5;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (local_14 == 0xffffffff) {
      iVar4 = *(int *)(iVar4 + 4);
      FUN_00604760(1);
      local_14 = *(int *)(iVar4 + 0x8c) - 1;
      iVar4 = local_18;
    }
    local_1c = (int *)(*(int *)(iVar4 + 4) + 0x88);
    if (*(uint *)(*(int *)(iVar4 + 4) + 0x8c) <= local_14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar3 = *(int **)(*local_1c + local_14 * 0x50);
    *(int **)(*local_1c + local_14 * 0x50) = piVar1;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
    local_1c = (int *)(*(int *)(local_18 + 4) + 0x88);
    if (*(uint *)(*(int *)(local_18 + 4) + 0x8c) <= local_14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_0042fce0(&local_20);
    uVar7 = 0;
    *(undefined1 *)(*(int *)(local_18 + 4) + 0xcc0) = 1;
    pcVar9 = TclFreeObj_exref;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, pcVar9 = TclFreeObj_exref, *piVar2 < 1))
    {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar9)(piVar1);
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar7 = 1;
  }
  FUN_006bc0d0();
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

