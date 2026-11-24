
undefined4
CTclGlobalMethods__LoadInfo(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined **ppuVar3;
  DWORD DVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bcb5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c98) &&
     (FUN_006cebf4(&DAT_00ca6c98,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6c98 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6c9c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::LoadInfo()";
    *(int *)(&DAT_00773650 + iVar6) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c98);
  }
  iVar6 = DAT_00ca6c9c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c9c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar8;
  }
  piVar5 = param_3;
  (&DAT_00773654)[iVar6 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8._0_1_ = 3;
  if ((int)piVar5 < 2) {
    piVar5 = (int *)FUN_006ba810(0x19);
    piVar5[1] = 4;
    *(undefined1 *)(piVar5 + 3) = 0;
    piVar5[2] = 0;
    *piVar5 = 1;
    local_8._0_1_ = 6;
    param_3 = piVar5;
    FUN_0055a950(&param_3,1);
    local_8._0_1_ = 7;
    *piVar5 = *piVar5 + -1;
    if (*piVar5 == 0) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    DVar4 = GetTickCount();
    if (DAT_007687c0 == 0xffffffff) {
      DAT_007687c0 = DVar4;
    }
    if ((int)(DAT_007687c0 + 0xfa) <= (int)DVar4) {
      DAT_007687c0 = DVar4;
      FUN_00479c10(0,1);
      Sleep(1);
    }
  }
  else {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_24 + 1;
    }
    piVar5 = (int *)*puVar7;
    if (piVar5 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      *piVar5 = *piVar5 + 1;
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar5,0);
    }
    FUN_006b8fb0(ppuVar3);
    local_8._0_1_ = 4;
    FUN_0055a950(&param_3,1);
    local_8._0_1_ = 5;
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    DVar4 = GetTickCount();
    if (DAT_007687c0 == 0xffffffff) {
      DAT_007687c0 = DVar4;
    }
    if ((int)(DAT_007687c0 + 0xfa) <= (int)DVar4) {
      DAT_007687c0 = DVar4;
      FUN_00479c10(0,1);
      Sleep(1);
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
      TclFreeObj(piVar5);
    }
  }
  FUN_006bc0d0();
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

