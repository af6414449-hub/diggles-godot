
undefined4
CTclGlobalMethods__Sel(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined **ppuVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  undefined8 uVar9;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bd0d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ca0) &&
     (FUN_006cebf4(&DAT_00ca6ca0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6ca0 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca6ca4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::Sel()";
    *(int *)(&DAT_00773650 + iVar8) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6ca0);
  }
  iVar8 = DAT_00ca6ca4;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6ca4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar9;
  }
  piVar6 = param_3;
  (&DAT_00773654)[iVar8 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar1 = piVar3 + 3;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)piVar1 = 0;
  piVar3[1] = 0x14;
  *piVar1 = 0x73696874;
  *(undefined1 *)(piVar3 + 4) = 0;
  piVar3[2] = 4;
  *piVar3 = 1;
  if (local_38 == 0) {
    iVar8 = 0;
    iVar2 = 1;
  }
  else {
    iVar8 = Tcl_GetAssocData(local_38,piVar1,0);
    iVar2 = *piVar3;
  }
  local_8._0_1_ = 3;
  *piVar3 = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar6 < 2) {
    FUN_006bc8f0(1);
  }
  else if (iVar8 != 0) {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_28 + 1;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 4;
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
      piVar6 = (int *)0x0;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
      piVar6 = piVar1;
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 5;
    iVar2 = FUN_006055d0(local_38,iVar8,&param_3);
    local_8._0_1_ = 6;
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if ((piVar6 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    if (iVar2 != 0) {
      *(int *)(iVar8 + 0xd0) = iVar2;
      uVar7 = 0;
      goto LAB_00623652;
    }
    puVar5 = (undefined4 *)FUN_004295e0(1);
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("couldn\'t resolve Path",piVar1);
  }
  uVar7 = 1;
LAB_00623652:
  FUN_006bc0d0();
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

