
bool CTclClassDefMethods__Obj_Init
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a55d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6b18) {
    FUN_006cebf4(&DAT_00ca6b18,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca6b18 == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca6b1c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclClassDefMethods::Obj_Init()";
      *(int *)(&DAT_00773650 + iVar3) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca6b18);
    }
  }
  iVar3 = DAT_00ca6b1c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6b1c * 0x40);
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
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8._0_1_ = 2;
  iVar2 = *(int *)(DAT_00772440 + 4);
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 0xcc0) = 0;
  }
  else {
    FUN_006bc6a0("no class defined.",0);
  }
  FUN_006bc0d0();
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != 0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return iVar2 == 0;
}

