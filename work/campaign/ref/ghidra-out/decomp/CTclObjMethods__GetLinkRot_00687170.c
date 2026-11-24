
undefined4
CTclObjMethods__GetLinkRot
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 extraout_ECX;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int *local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711565;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca77c8) &&
     (FUN_006cebf4(&DAT_00ca77c8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca77c8 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca77cc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::GetLinkRot()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca77c8);
  }
  iVar3 = DAT_00ca77cc;
  local_18 = &DAT_00ca77cc;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca77cc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar4;
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
  local_8._0_1_ = 2;
  iVar2 = FUN_005c71c0(param_4,3,1);
  if (iVar2 == 0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
LAB_0068741b:
    FUN_004297b0(0);
    if (local_28 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  if (local_20 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_28;
    if (local_24 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_28;
    }
  }
  else {
    if (local_24 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_28 + 2;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  local_1c = piVar1;
  if (piVar1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_14);
    if (iVar3 == 1) {
      iVar3 = 0;
    }
    else if ((local_14 < 0) || (iVar3 = local_14, 0x1f < local_14)) {
      piVar5 = (int *)Tcl_NewIntObj(local_14,extraout_ECX);
      *piVar5 = *piVar5 + 1;
      FUN_006bc6a0("Invalid link-id :  %i",piVar5);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
      local_8._0_1_ = 6;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,7);
      goto LAB_0068741b;
    }
  }
  if ((*(int *)(iVar2 + 0x39c) == -1) || (*(int *)(iVar2 + 0x3a0) == -1)) {
    local_2c = 0;
    local_34 = 0;
    local_30 = 0;
  }
  else {
    iVar2 = FUN_004059a0(*(int *)(iVar2 + 0x3a0));
    iVar2 = FUN_00408920(*(undefined4 *)(iVar2 + 0x5c + iVar3 * 4));
    local_34 = *(undefined4 *)(iVar2 + 8);
    local_30 = *(undefined4 *)(iVar2 + 0xc);
    local_2c = *(undefined4 *)(iVar2 + 0x10);
  }
  uVar4 = FUN_006badc0(&local_34);
  FUN_006bc670(uVar4);
  FUN_006bad60();
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  FUN_00429650();
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

