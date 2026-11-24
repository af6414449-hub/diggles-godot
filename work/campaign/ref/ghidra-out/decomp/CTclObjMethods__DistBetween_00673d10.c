
undefined4
CTclObjMethods__DistBetween
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int local_34;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a7dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74a0) {
    FUN_006cebf4(&DAT_00ca74a0,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar1 = DAT_00783650;
    if (DAT_00ca74a0 == -1) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00ca74a4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::DistBetween()";
      *(int *)(&DAT_00773650 + iVar4) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca74a0);
    }
  }
  iVar4 = DAT_00ca74a4;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74a4 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar5;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar1 == 0) {
    uVar6 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar2 = (int *)FUN_005c71c0(param_4,3,1);
  if (piVar2 != (int *)0x0) {
    iVar1 = FUN_005c71c0(param_4,3,2);
    if (iVar1 != 0) {
      FUN_0040b7e0();
      piVar3 = (int *)FUN_006bad90();
      if (local_34 != 0) {
        if (*piVar3 == 0) {
          Tcl_ResetResult(local_34);
        }
        else {
          Tcl_SetObjResult(local_34,*piVar3);
        }
      }
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + -1;
        if (*piVar2 < 1) {
          TclFreeObj(piVar2);
        }
      }
      uVar5 = 0;
      goto LAB_00673e91;
    }
  }
  uVar5 = 1;
LAB_00673e91:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

