
undefined4 CTclGlobalMethods__InitTechTree(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d5e5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7020) &&
     (FUN_006cebf4(), iVar2 = DAT_00783650, DAT_00ca7020 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7024 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::InitTechTree()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar3 = DAT_00ca7024;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7024 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar4;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0(param_3);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
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
    local_8._0_1_ = 3;
    if (piVar1 != (int *)0x0) {
      Tcl_GetStringFromObj(piVar1);
    }
    FUN_004402c0();
    iRam00000002 = iRam00000002 + 1;
    local_8._0_1_ = 5;
    if (DAT_0076a280 == (undefined4 *)0x0) {
      DAT_0076a280 = (undefined4 *)FUN_006ba810(0x76);
      if (DAT_0076a280 == (undefined4 *)0x0) {
        DAT_0076a280 = (undefined4 *)0x0;
      }
      else {
        *DAT_0076a280 = 0;
        DAT_0076a280[1] = 0;
      }
    }
    local_8._0_1_ = 4;
    FUN_0043e540();
    uVar4 = 0;
    local_8 = CONCAT31(local_8._1_3_,6);
    iRam00000002 = iRam00000002 + -1;
    if (iRam00000002 == 0) {
      FUN_006ba940();
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj();
    }
  }
  else {
    FUN_006bc8f0();
    uVar4 = 1;
  }
  local_8._0_1_ = 7;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0();
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

