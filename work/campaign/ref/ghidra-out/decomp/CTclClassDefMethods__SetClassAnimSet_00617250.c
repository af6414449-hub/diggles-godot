
undefined4
CTclClassDefMethods__SetClassAnimSet
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  int *piStack_20;
  undefined4 *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070aaa5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6be0) &&
     (FUN_006cebf4(&DAT_00ca6be0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6be0 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6be4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclClassDefMethods::SetClassAnimSet()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6be0);
  }
  iVar4 = DAT_00ca6be4;
  local_1c = &DAT_00ca6be4;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6be4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  iVar2 = DAT_00772440;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar5 = 1;
  }
  else if (param_3 == 3) {
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_30 + 1;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    piStack_20 = piVar1;
    if (piVar1 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    local_18 = piVar1;
    FUN_006b8fb0(ppuVar3);
    uVar5 = FUN_00601f90(&local_14);
    *(undefined4 *)(*(int *)(iVar2 + 4) + 0xce4) = uVar5;
    local_8 = CONCAT31(local_8._1_3_,4);
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    if ((local_18 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_30 + 2;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 == (int *)0x0) {
      *(undefined4 *)(*(int *)(iVar2 + 4) + 0xce8) = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar4 = Tcl_GetDoubleFromObj(0,piVar1,&local_24);
      if (iVar4 == 1) {
        *(undefined4 *)(*(int *)(iVar2 + 4) + 0xce8) = 0;
      }
      else {
        *(float *)(*(int *)(iVar2 + 4) + 0xce8) = (float)(double)CONCAT44(piStack_20,local_24);
      }
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    uVar5 = 0;
  }
  else {
    FUN_006bc8f0(1);
    uVar5 = 1;
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

