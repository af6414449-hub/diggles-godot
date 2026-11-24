
undefined4
CTclObjMethods__CreateLadderLogic
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710df8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7540) {
    FUN_006cebf4(&DAT_00ca7540,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar1 = DAT_00783650;
    if (DAT_00ca7540 == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca7544 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::CreateLadderLogic()";
      *(int *)(&DAT_00773650 + iVar3) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7540);
    }
  }
  iVar3 = DAT_00ca7544;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7544 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar5 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    iVar1 = FUN_005c71c0(param_4,2,1);
    if (iVar1 == 0) {
      uVar4 = 1;
    }
    else {
      puVar2 = *(undefined4 **)(iVar1 + 0x3ec);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)FUN_006ba810(0x4d1);
        if (puVar2 == (undefined4 *)0x0) {
          puVar2 = (undefined4 *)0x0;
        }
        else {
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
        }
        *(undefined4 **)(iVar1 + 0x3ec) = puVar2;
      }
      if (puVar2[2] == 0) {
        *puVar2 = 1;
        iVar3 = FUN_006ba810(0x561);
        local_8._0_1_ = 3;
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_0060ad40();
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        *(int *)(iVar3 + 0x1c) = iVar1;
        *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar1 + 0xdc);
        FUN_0060bac0();
        *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(iVar1 + 0x3d0);
        *(int *)(*(int *)(iVar1 + 0x3ec) + 8) = iVar3;
      }
      uVar4 = 0;
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar4 = 1;
  }
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_20 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

