
undefined4
CTclGlobalMethods__IncPlayerDigMarkID
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ccbd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca72c0) &&
     (FUN_006cebf4(&DAT_00ca72c0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca72c0 == -1)) {
    iVar2 = DAT_00783650 * 0x40;
    DAT_00ca72c4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclGlobalMethods::IncPlayerDigMarkID()";
    *(int *)(&DAT_00773650 + iVar2) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca72c0);
  }
  iVar2 = DAT_00ca72c4;
  uVar3 = *(undefined4 *)(&DAT_00773650 + DAT_00ca72c4 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar3;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar7 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar6 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (uVar6 != 2) {
    FUN_006bc8f0(1);
    uVar3 = 1;
    goto LAB_00658dd6;
  }
  if (local_18 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_20 + 1;
  }
  piVar5 = (int *)*puVar4;
  if (piVar5 == (int *)0x0) {
    uVar6 = 0;
    iVar1 = FUN_00566460();
    piVar5 = (int *)(iVar1 + 0xb4);
LAB_00658dcf:
    piVar5 = piVar5 + uVar6;
  }
  else {
    *piVar5 = *piVar5 + 1;
    iVar1 = Tcl_GetIntFromObj(0,piVar5,&param_3);
    *piVar5 = *piVar5 + -1;
    uVar6 = -(uint)(iVar1 != 1) & param_3;
    if (*piVar5 < 1) {
      TclFreeObj(piVar5);
    }
    if (7 < (int)uVar6) {
      uVar6 = 7;
    }
    if ((int)uVar6 < 0) {
      uVar6 = 0;
    }
    iVar1 = FUN_00566460();
    piVar5 = (int *)(iVar1 + 0xb4);
    if (uVar6 < 8) goto LAB_00658dcf;
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *piVar5 = *piVar5 + 1;
  uVar3 = 0;
LAB_00658dd6:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar3;
}

