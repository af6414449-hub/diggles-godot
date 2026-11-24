
undefined4
CTclGlobalMethods__DBLoad(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ce7d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ea0) &&
     (FUN_006cebf4(&DAT_00ca6ea0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6ea0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6ea4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::DBLoad()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6ea0);
  }
  iVar5 = DAT_00ca6ea4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6ea4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar1 != (int *)0x2) {
    FUN_006bc8f0(1);
    uVar6 = 1;
    goto LAB_0063331f;
  }
  if (local_20 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_28;
    if (local_24 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_28 + 1;
  }
  piVar1 = (int *)*puVar7;
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
  piVar2 = param_3;
  local_8 = CONCAT31(local_8._1_3_,4);
  if (DAT_0076a338 == 0) {
    FUN_00460460(&param_3,0xffffffff);
LAB_006332f4:
    uVar6 = 0;
  }
  else {
    iVar3 = FUN_00460460(&param_3,0xffffffff);
    if (iVar3 != -1) {
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      FUN_00479340(iVar3,piVar2);
      goto LAB_006332f4;
    }
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("invalid 3DB",piVar1);
    uVar6 = 1;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_0063331f:
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

