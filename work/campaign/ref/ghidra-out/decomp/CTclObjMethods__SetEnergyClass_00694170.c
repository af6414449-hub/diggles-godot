
undefined4
CTclObjMethods__SetEnergyClass
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  uint local_24;
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711bad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca79b0) &&
     (FUN_006cebf4(&DAT_00ca79b0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca79b0 == -1)) {
    iVar2 = DAT_00783650 * 0x40;
    DAT_00ca79b4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclObjMethods::SetEnergyClass()";
    *(int *)(&DAT_00773650 + iVar2) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca79b0);
  }
  iVar2 = DAT_00ca79b4;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca79b4 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar5;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar6 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,3,1);
  if (iVar1 == 0) {
    uVar5 = 1;
    goto LAB_006943ee;
  }
  if (*(int *)(iVar1 + 0xe8) == 6) {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_34 + 2;
    }
    piVar4 = (int *)*puVar3;
    if (piVar4 == (int *)0x0) {
      local_18 = (int *)0x0;
LAB_006942d5:
      local_14 = 0;
    }
    else {
      *piVar4 = *piVar4 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar4,&local_20);
      local_18 = piVar4;
      if (iVar2 == 1) goto LAB_006942d5;
      local_14 = local_20;
    }
    local_1c = (int *)FUN_005b9330();
    local_24 = FUN_005b9370(iVar1);
    if (local_24 != 0xffffffff) {
      if ((uint)local_1c[1] <= local_24) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)(*local_1c + 4 + local_24 * 0x14) = local_14;
    }
    if ((local_18 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar4 = (int *)*local_34;
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar4 = (int *)local_34[2];
    }
LAB_0069438d:
    if (piVar4 == (int *)0x0) {
      *(undefined4 *)(*(int *)(iVar1 + 0x3e0) + 300) = 0;
    }
    else {
      *piVar4 = *piVar4 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar4,&local_24);
      if (iVar2 == 1) {
        *(undefined4 *)(*(int *)(iVar1 + 0x3e0) + 300) = 0;
      }
      else {
        *(uint *)(*(int *)(iVar1 + 0x3e0) + 300) = local_24;
      }
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
  }
  else if (*(int *)(iVar1 + 0xe8) == 5) {
    puVar3 = (undefined4 *)FUN_004295e0(2);
    piVar4 = (int *)*puVar3;
    goto LAB_0069438d;
  }
  uVar5 = 0;
LAB_006943ee:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

