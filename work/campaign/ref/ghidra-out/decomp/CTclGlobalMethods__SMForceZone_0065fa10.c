
undefined4
CTclGlobalMethods__SMForceZone
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  int iVar4;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ea9d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7370) &&
     (FUN_006cebf4(&DAT_00ca7370,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7370 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7374 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::SMForceZone()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7370);
  }
  iVar4 = DAT_00ca7374;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7374 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == (int *)0x2) {
    FUN_004298b0(2,param_4);
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
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar1 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar3);
    local_8._0_1_ = 4;
    iVar2 = FUN_005f8080();
    iVar4 = FUN_005fcea0(&param_3);
    if (iVar4 != -1) {
      *(int *)(iVar2 + 0x84) = iVar4;
    }
    local_8._0_1_ = 5;
    piVar5 = param_3;
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
      piVar5 = extraout_ECX;
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
      piVar5 = extraout_ECX_00;
    }
    if (iVar4 == -1) {
      FUN_006b8fb0("Invalid Zone");
      FUN_0054dc90(piVar5);
    }
    uVar6 = 0;
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_004297b0(0);
    if (local_24 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar6 = 1;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

