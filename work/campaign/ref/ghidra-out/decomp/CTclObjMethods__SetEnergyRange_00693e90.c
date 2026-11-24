
undefined4
CTclObjMethods__SetEnergyRange
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  double local_28;
  undefined4 *local_20;
  uint local_1c;
  int *local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007116fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca79a8) &&
     (FUN_006cebf4(&DAT_00ca79a8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca79a8 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca79ac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::SetEnergyRange()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca79a8);
  }
  iVar3 = DAT_00ca79ac;
  local_20 = &DAT_00ca79ac;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca79ac * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_1c = FUN_005c71c0(param_4,2,1);
  if (local_1c != 0) {
    if (*(int *)(local_1c + 0xe8) == 6) {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = local_34;
        if (local_30 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_30 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar4 = local_34 + 2;
      }
      piVar1 = (int *)*puVar4;
      if (piVar1 == (int *)0x0) {
        piVar5 = (int *)0x0;
LAB_006940ae:
        local_14 = 0.0;
      }
      else {
        *piVar1 = *piVar1 + 1;
        iVar2 = Tcl_GetDoubleFromObj(0,piVar1,&local_28);
        piVar5 = piVar1;
        if (iVar2 == 1) goto LAB_006940ae;
        local_14 = (float)local_28;
      }
      local_18 = (int *)FUN_005b9330();
      local_1c = FUN_005b9370(local_1c);
      if (local_1c != 0xffffffff) {
        if ((uint)local_18[1] <= local_1c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(float *)(*local_18 + 8 + local_1c * 0x14) = local_14;
      }
      if ((piVar5 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj(piVar1);
      }
      uVar6 = 0;
      goto LAB_00693fe0;
    }
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_34 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("object type is not energy",piVar1);
  }
  uVar6 = 1;
LAB_00693fe0:
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
  return uVar6;
}

