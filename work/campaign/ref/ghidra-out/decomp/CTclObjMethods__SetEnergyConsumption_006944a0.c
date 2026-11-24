
undefined4
CTclObjMethods__SetEnergyConsumption
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  double local_1c;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a85d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca79b8) &&
     (FUN_006cebf4(&DAT_00ca79b8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca79b8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca79bc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::SetEnergyConsumption()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca79b8);
  }
  iVar4 = DAT_00ca79bc;
  local_14 = &DAT_00ca79bc;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca79bc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,3,1);
  if (iVar2 != 0) {
    iVar4 = *(int *)(iVar2 + 0xe8);
    if (((iVar4 == 5) || (iVar4 == 10)) || (iVar4 == 6)) {
      if (*(int *)(iVar2 + 0x3e0) != 0) {
        if (local_20 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar3 = local_28;
          if (local_24 == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        else {
          if (local_24 < 3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar3 = local_28 + 2;
        }
        piVar1 = (int *)*puVar3;
        if (piVar1 == (int *)0x0) {
          *(undefined4 *)(*(int *)(iVar2 + 0x3e0) + 0x130) = 0;
        }
        else {
          *piVar1 = *piVar1 + 1;
          iVar4 = Tcl_GetDoubleFromObj(0,piVar1,&local_1c);
          if (iVar4 == 1) {
            *(undefined4 *)(*(int *)(iVar2 + 0x3e0) + 0x130) = 0;
          }
          else {
            *(float *)(*(int *)(iVar2 + 0x3e0) + 0x130) = (float)local_1c;
          }
          *piVar1 = *piVar1 + -1;
          if (*piVar1 < 1) {
            TclFreeObj(piVar1);
            uVar5 = 0;
            goto LAB_006945be;
          }
        }
      }
      uVar5 = 0;
      goto LAB_006945be;
    }
    puVar3 = (undefined4 *)FUN_004295e0(1);
    piVar1 = (int *)*puVar3;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("object type is not production or energy",piVar1);
  }
  uVar5 = 1;
LAB_006945be:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

