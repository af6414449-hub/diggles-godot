
undefined4
CTclObjMethods__SMRegister
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071258d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7cd0) &&
     (FUN_006cebf4(&DAT_00ca7cd0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7cd0 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7cd4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::SMRegister()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7cd0);
  }
  iVar4 = DAT_00ca7cd4;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7cd4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
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
  iVar2 = FUN_005c71c0(param_4,3,1);
  if (iVar2 == 0) {
    uVar7 = 1;
  }
  else {
    FUN_004298b0(param_3,param_4);
    if (local_24 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_2c + 2;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar1 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
      piVar6 = (int *)0x0;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
      piVar6 = piVar1;
    }
    FUN_006b8fb0(ppuVar3);
    local_8 = CONCAT31(local_8._1_3_,5);
    if ((piVar6 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar7 = *(undefined4 *)(iVar2 + 0xdc);
    iVar2 = FUN_005f8080();
    *(undefined4 *)(iVar2 + 0x78) = uVar7;
    piVar1 = *(int **)(iVar2 + 0x74);
    *(int **)(iVar2 + 0x74) = local_18;
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + 1;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
      FUN_006ba940();
    }
    uVar7 = 0;
    *(int *)(*(int *)(iVar2 + 0x74) + 8) = local_18[2];
    local_8._0_1_ = 6;
    *local_18 = *local_18 + -1;
    if (*local_18 == 0) {
      FUN_006ba940();
    }
    local_8._0_1_ = 7;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_004297b0(0);
    if (local_2c != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

