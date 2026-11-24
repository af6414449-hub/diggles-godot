
undefined4
CTclObjMethods__NTIDReset
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int local_28;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710fbd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7590) {
    FUN_006cebf4(&DAT_00ca7590,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca7590 == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca7594 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::NTIDReset";
      *(int *)(&DAT_00773650 + iVar3) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7590);
    }
  }
  iVar3 = DAT_00ca7594;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7594 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  iVar2 = FUN_005c71c0(param_4,2,1);
  if (iVar2 == 0) {
    uVar5 = 1;
  }
  else {
    if (-1 < *(int *)(iVar2 + 0x408)) {
      local_14 = (int *)FUN_006ba810(0x19);
      local_14[1] = 0x14;
      local_14[2] = -1;
      *(undefined1 *)(local_14 + 3) = 0;
      *local_14 = 1;
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_006b9040(&local_14,"newsticker delete %d",*(undefined4 *)(iVar2 + 0x408));
      piVar1 = local_14;
      if (local_14 + 3 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)Tcl_NewStringObj(local_14 + 3,0xffffffff);
        *piVar4 = *piVar4 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      local_18 = piVar4;
      FUN_00555a00(&local_18);
      if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
        TclFreeObj(piVar4);
      }
      local_8._0_1_ = 5;
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
        FUN_006ba940();
      }
    }
    *(undefined4 *)(iVar2 + 0x408) = 0xfffffffe;
    uVar5 = 0;
  }
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_28 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

