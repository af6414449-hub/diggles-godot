
undefined4
CTclObjMethods__LinkObj(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  void *lp;
  BOOL BVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711dad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b00) &&
     (FUN_006cebf4(&DAT_00ca7b00,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7b00 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7b04 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::LinkObj()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7b00);
  }
  iVar7 = DAT_00ca7b04;
  local_1c = &DAT_00ca7b04;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b04 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_005c71c0(param_4,2,1);
  if (iVar3 == 0) {
    uVar8 = 1;
    goto LAB_0069bad7;
  }
  if (param_3 == 2) {
    FUN_005cb700(0xffffffff,0);
    FUN_005ebc90(iVar3);
    FUN_005eb470(iVar3);
    uVar8 = 0;
    goto LAB_0069bad7;
  }
  if (local_24 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_2c;
    if (local_28 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_2c;
    }
  }
  else {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_2c + 2;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  local_20 = piVar1;
  FUN_006b8fb0(&DAT_007210c8);
  piVar2 = local_18;
  if (local_48 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = Tcl_GetAssocData(local_48,local_18 + 3,0);
  }
  local_8._0_1_ = 4;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 3;
  if (piVar1 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  FUN_006b8fb0(ppuVar4);
  local_8._0_1_ = 5;
  lp = (void *)FUN_006055d0(param_2,local_14,&local_18);
  local_8._0_1_ = 6;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (lp == (void *)0x0) {
    FUN_005cb700(0xffffffff,0);
    FUN_005ebc90(iVar3);
    FUN_005eb470(iVar3);
LAB_0069bac0:
    uVar8 = 0;
  }
  else {
    BVar5 = IsBadReadPtr(lp,0x10);
    if (((BVar5 == 0) && (*(int *)((int)lp + 8) == 0x616e4f62)) &&
       ((DAT_00768398 == '\0' || (*(int *)((int)lp + 0xdc) != 0)))) {
      if ((1 < *(int *)((int)lp + 0xdc)) && (1 < *(int *)(iVar3 + 0xdc))) {
        local_14 = 0;
        if (param_3 == 4) {
          puVar6 = (undefined4 *)FUN_004295e0(3);
          local_18 = (int *)*puVar6;
          if (local_18 != (int *)0x0) {
            *local_18 = *local_18 + 1;
          }
          local_14 = FUN_006baee0();
          FUN_006bad60();
        }
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        FUN_005cd7e0(&local_38);
        FUN_005cb700(*(undefined4 *)((int)lp + 0xdc),local_14);
        goto LAB_0069bac0;
      }
      FUN_006bc6a0("Illegal link CObj_World/CObj_DigTask ",0);
      uVar8 = 1;
    }
    else {
      puVar6 = (undefined4 *)FUN_004295e0(2);
      piVar2 = (int *)*puVar6;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      FUN_006bc6a0("invalid obj",piVar2);
      uVar8 = 1;
    }
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_0069bad7:
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

