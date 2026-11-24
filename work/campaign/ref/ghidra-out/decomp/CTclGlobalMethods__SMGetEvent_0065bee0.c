
undefined4
CTclGlobalMethods__SMGetEvent(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined **ppuVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int local_34;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ef3d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7320) &&
     (FUN_006cebf4(&DAT_00ca7320,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7320 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7324 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::SMGetEvent()";
    *(int *)(&DAT_00773650 + iVar5) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7320);
  }
  iVar5 = DAT_00ca7324;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7324 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar8;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar1 == 0) {
    uVar9 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 2) {
    FUN_004298b0(2,param_4);
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_24 + 1;
    }
    piVar3 = (int *)*puVar6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar3 == (int *)0x0) {
      ppuVar2 = &PTR_0071ce50;
      piVar7 = (int *)0x0;
    }
    else {
      ppuVar2 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
      piVar7 = piVar3;
    }
    FUN_006b8fb0(ppuVar2);
    local_8 = CONCAT31(local_8._1_3_,5);
    if ((piVar7 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
    piVar3 = (int *)FUN_005f8080();
    uVar4 = FUN_005f8a70(&local_14);
    if (uVar4 == 0xffffffff) {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_20 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar6 = local_24 + 1;
      }
      piVar3 = (int *)*puVar6;
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      FUN_006bc6a0("Story Event not found",piVar3);
      uVar8 = 1;
    }
    else {
      if ((uint)piVar3[1] <= uVar4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = (int *)Tcl_NewIntObj(*(char *)(*piVar3 + 0xc + uVar4 * 0x10) != '\0');
      *piVar3 = *piVar3 + 1;
      iVar1 = *piVar3;
      if (local_34 != 0) {
        Tcl_SetObjResult(local_34,piVar3);
        iVar1 = *piVar3;
      }
      *piVar3 = iVar1 + -1;
      if (iVar1 + -1 < 1) {
        TclFreeObj(piVar3);
      }
      uVar8 = 0;
    }
    local_8._0_1_ = 7;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 8;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,9);
    FUN_004297b0(0);
    if (local_24 != (undefined4 *)0x0) {
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

