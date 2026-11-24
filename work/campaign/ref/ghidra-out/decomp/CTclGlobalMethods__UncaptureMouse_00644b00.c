
undefined4
CTclGlobalMethods__UncaptureMouse
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bc55;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca70b0) {
    FUN_006cebf4(&DAT_00ca70b0,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca70b0 == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca70b4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::UncaptureMouse()";
      *(int *)(&DAT_00773650 + iVar3) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca70b0);
    }
  }
  iVar3 = DAT_00ca70b4;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca70b4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar4 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar4;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar2 = FUN_00501450();
  *(undefined4 *)(iVar2 + 0x81a4) = 0;
  iVar2 = *(int *)(iVar2 + 0xc);
  if (iVar2 < 0) {
    FUN_0042fc20(-iVar2);
  }
  else if (0 < iVar2) {
    FUN_00463b00(iVar2);
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_20 != 0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

