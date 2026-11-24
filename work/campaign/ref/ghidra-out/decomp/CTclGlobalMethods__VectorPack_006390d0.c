
/* WARNING: Removing unreachable block (ram,0x00639406) */
/* WARNING: Removing unreachable block (ram,0x00639417) */
/* WARNING: Removing unreachable block (ram,0x0063941d) */

undefined4
CTclGlobalMethods__VectorPack(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined8 uVar7;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  undefined1 local_24 [8];
  undefined4 *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d35d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6f80) &&
     (FUN_006cebf4(&DAT_00ca6f80,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6f80 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6f84 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::VectorPack()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6f80);
  }
  iVar3 = DAT_00ca6f84;
  local_1c = &DAT_00ca6f84;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6f84 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 4) {
    FUN_006bc8f0(3);
    uVar5 = 1;
  }
  else {
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_30 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 == (int *)0x0) {
      local_18 = (int *)0x0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      Tcl_GetDoubleFromObj(0,piVar1,local_24);
      local_18 = piVar1;
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + -1;
      if (*local_14 < 1) {
        TclFreeObj(local_14);
      }
      local_14 = (int *)0x0;
    }
    if ((local_18 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_30 + 2;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 == (int *)0x0) {
      local_14 = (int *)0x0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      Tcl_GetDoubleFromObj(0,piVar1,local_24);
      local_14 = piVar1;
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + -1;
      if (*local_18 < 1) {
        TclFreeObj(local_18);
      }
      local_18 = (int *)0x0;
    }
    if ((local_14 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    if (local_28 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_30 + 3;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      Tcl_GetDoubleFromObj(0,piVar1,local_24);
      piVar6 = piVar1;
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + -1;
      if (*local_18 < 1) {
        TclFreeObj(local_18);
      }
      local_18 = (int *)0x0;
    }
    if ((piVar6 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    if (local_40 == 0) {
      uVar5 = 0;
    }
    else {
      Tcl_ResetResult(local_40);
      uVar5 = 0;
    }
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

