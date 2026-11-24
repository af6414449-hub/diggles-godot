
undefined4
CTclGlobalMethods__SetFoWBegin
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a7dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7138) &&
     (FUN_006cebf4(&DAT_00ca7138,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7138 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca713c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::SetFoWBegin()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7138);
  }
  iVar4 = DAT_00ca713c;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca713c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar2 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  uVar7 = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (uVar2 != 2) {
    if (uVar2 != 3) {
      FUN_006bc8f0(2);
      uVar6 = 1;
      goto LAB_0064b570;
    }
    if (local_1c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_24 + 2;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 == (int *)0x0) {
      uVar7 = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&param_3);
      *piVar1 = *piVar1 + -1;
      uVar7 = -(uint)(iVar3 != 1) & param_3;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
  }
  if (local_1c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_24;
    if (local_20 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_24 + 1;
  }
  piVar1 = (int *)*puVar5;
  if (piVar1 == (int *)0x0) {
    local_14 = 0;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_14);
    *piVar1 = *piVar1 + -1;
    local_14 = -(uint)(iVar3 != 1) & local_14;
    if (*piVar1 < 1) {
      TclFreeObj(piVar1);
    }
  }
  if (uVar7 < 7) {
    FUN_00580610(local_14,uVar7);
  }
  uVar6 = 0;
LAB_0064b570:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

