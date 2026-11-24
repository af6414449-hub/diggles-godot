
undefined4
CTclObjMethods__SetAnim(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bc55;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7bd8) {
    FUN_006cebf4(&DAT_00ca7bd8,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar1 = DAT_00783650;
    if (DAT_00ca7bd8 == -1) {
      iVar2 = DAT_00783650 * 0x40;
      DAT_00ca7bdc = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclObjMethods::SetAnim()";
      *(int *)(&DAT_00773650 + iVar2) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7bd8);
    }
  }
  iVar2 = DAT_00ca7bdc;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7bdc * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar5 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = FUN_005c71c0(param_4,1,1);
  if (iVar1 == 0) {
    uVar4 = 1;
  }
  else {
    *(uint *)(iVar1 + 0x3d8) = *(uint *)(iVar1 + 0x3d8) | 8;
    iVar2 = *(int *)(iVar1 + 0x3c8);
    if ((*(int *)(iVar1 + 0x3a8) != iVar2) ||
       (iVar3 = *(int *)(iVar1 + 0x3bc), *(int *)(iVar1 + 0x39c) != iVar3)) {
      iVar3 = *(int *)(iVar1 + 0x3bc);
      *(undefined4 *)(iVar1 + 0x3dc) = 0;
      *(undefined1 *)(iVar1 + 0x3b4) = 1;
    }
    *(int *)(iVar1 + 0x39c) = iVar3;
    *(int *)(iVar1 + 0x3a8) = iVar2;
    *(undefined4 *)(iVar1 + 0x3ac) = *(undefined4 *)(iVar1 + 0x3c4);
    *(int *)(iVar1 + 0x3b0) = iVar2;
    FUN_00461b90(*(undefined4 *)(iVar1 + 0xdc),iVar3,iVar2,*(undefined4 *)(iVar1 + 0x3c4),iVar2);
    uVar4 = 0;
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
  return uVar4;
}

