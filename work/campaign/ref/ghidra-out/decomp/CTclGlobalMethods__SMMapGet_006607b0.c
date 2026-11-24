
undefined4
CTclGlobalMethods__SMMapGet(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  code *pcVar8;
  undefined8 uVar9;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f16d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7398) &&
     (FUN_006cebf4(&DAT_00ca7398,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7398 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca739c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::SMMapGet()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7398);
  }
  iVar4 = DAT_00ca739c;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca739c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 3) {
    FUN_004298b0(3,param_4);
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_30 + 2;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_30 + 1;
    }
    piVar2 = (int *)*puVar7;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (piVar1 == (int *)0x0) {
      uVar5 = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&param_3);
      uVar5 = -(uint)(iVar3 != 1) & param_3;
    }
    if (piVar2 == (int *)0x0) {
      FUN_005f8080();
      FUN_005fa640(0,uVar5);
      pcVar8 = TclFreeObj_exref;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_14);
      if (iVar3 == 1) {
        FUN_005f8080();
        local_14 = 0;
      }
      else {
        FUN_005f8080();
      }
      FUN_005fa640(local_14,uVar5);
      *piVar2 = *piVar2 + -1;
      pcVar8 = TclFreeObj_exref;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar8)(piVar1);
    }
    uVar6 = 0;
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_004297b0(0);
    if (local_30 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar6 = 1;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

