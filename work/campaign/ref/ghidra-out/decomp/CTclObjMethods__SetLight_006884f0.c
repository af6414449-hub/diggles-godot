
undefined4
CTclObjMethods__SetLight
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710ad5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca77e0) &&
     (FUN_006cebf4(&DAT_00ca77e0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca77e0 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca77e4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::SetLight()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca77e0);
  }
  iVar4 = DAT_00ca77e4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca77e4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar7 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_005c71c0(param_4,3,1);
  if (iVar3 == 0) {
    uVar6 = 1;
  }
  else {
    if (local_20 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_28 + 2;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    piVar1 = (int *)(iVar3 + 0x28c);
    if (((piVar2 == (int *)0x0) || (iVar4 = Tcl_GetBooleanFromObj(0,piVar2,&local_14), iVar4 == 1))
       || (local_14 == 0)) {
      FUN_00592d70();
      FUN_00591860(*piVar1);
      *piVar1 = -1;
      uVar6 = 0;
      if (piVar2 == (int *)0x0) goto LAB_006886cc;
    }
    else if (*piVar1 == -1) {
      FUN_00592d70();
      FUN_00591480(piVar1,*(undefined4 *)(iVar3 + 0xdc),iVar3 + 0x280,*(undefined4 *)(iVar3 + 0x298)
                   ,*(undefined4 *)(iVar3 + 0x29c),*(undefined4 *)(iVar3 + 0x2a0),
                   *(undefined4 *)(iVar3 + 0x290),*(undefined4 *)(iVar3 + 0x294));
    }
    *piVar2 = *piVar2 + -1;
    uVar6 = 0;
    if (*piVar2 < 1) {
      TclFreeObj(piVar2);
    }
  }
LAB_006886cc:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

