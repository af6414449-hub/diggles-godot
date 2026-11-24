
undefined4
CTclClassDefMethods__ClassDefaultAnim
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  undefined4 local_24;
  int *local_20;
  uint local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a74d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6b78) &&
     (FUN_006cebf4(&DAT_00ca6b78,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6b78 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6b7c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclClassDefMethods::ClassDefaultAnim()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6b78);
  }
  iVar5 = DAT_00ca6b7c;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6b7c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = DAT_00772440;
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar6 = 1;
  }
  else if (param_3 < 2) {
    FUN_006bc8f0(1);
    uVar6 = 1;
  }
  else {
    uVar7 = 0;
    if (param_3 == 3) {
      puVar3 = (undefined4 *)FUN_004295e0(2);
      piVar1 = (int *)*puVar3;
      if (piVar1 == (int *)0x0) {
        uVar7 = 0;
      }
      else {
        *piVar1 = *piVar1 + 1;
        iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_1c);
        *piVar1 = *piVar1 + -1;
        uVar7 = -(uint)(iVar2 != 1) & local_1c;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
    }
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_38 + 1;
    }
    piVar1 = (int *)*puVar3;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 4;
    FUN_00460fc0(&local_18,&local_1c,&local_20,&local_24);
    local_8._0_1_ = 5;
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    local_20 = (int *)FUN_0040b580();
    local_18 = (int *)(*(int *)(local_14 + 4) + 0x10);
    if (*(int **)(*(int *)(local_14 + 4) + 0x14) <= local_20) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(uint *)(*local_18 + (int)local_20 * 4) = local_1c;
    local_18 = (int *)FUN_0040b580();
    local_20 = (int *)(*(int *)(local_14 + 4) + 0x18);
    if (*(int **)(*(int *)(local_14 + 4) + 0x1c) <= local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(undefined4 *)(*local_20 + (int)local_18 * 4) = local_24;
    *(uint *)(*(int *)(local_14 + 4) + 0x20) = uVar7;
    if (local_1c == 0xffffffff) {
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("unknown anim",piVar1);
      uVar6 = 1;
    }
    else {
      uVar6 = 0;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

