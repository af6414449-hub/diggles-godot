
undefined4
CTclGlobalMethods__Quit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined8 uVar6;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ce25;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e90) {
    FUN_006cebf4(&DAT_00ca6e90,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca6e90 == -1) {
      iVar5 = DAT_00783650 * 0x40;
      DAT_00ca6e94 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::Quit()";
      *(int *)(&DAT_00773650 + iVar5) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca6e90);
    }
  }
  iVar5 = DAT_00ca6e94;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e94 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar3 = (int *)FUN_006ba810(0x19,extraout_ECX);
  piVar3[1] = 0x14;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)(piVar3 + 3) = 0;
  piVar3[3] = 0x656d6147;
  *(undefined1 *)(piVar3 + 4) = 0;
  piVar3[2] = 4;
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
  }
  iVar2 = FUN_0055c470(piVar3);
  if (iVar2 != 0) {
    uVar1 = *(undefined4 *)(DAT_00772400 + 0x1b4);
    puVar4 = (undefined4 *)FUN_006ba810(0x42);
    *puVar4 = uVar1;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    FUN_00445180(puVar4);
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_24 != 0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

