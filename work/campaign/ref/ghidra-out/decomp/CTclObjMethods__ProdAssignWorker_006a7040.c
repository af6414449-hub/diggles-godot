
undefined4
CTclObjMethods__ProdAssignWorker
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a7dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c80) {
    FUN_006cebf4(&DAT_00ca7c80,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca7c80 == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca7c84 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::ProdAssignWorker()";
      *(int *)(&DAT_00773650 + iVar3) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7c80);
    }
  }
  iVar3 = DAT_00ca7c84;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c84 * 0x40);
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
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,2,1);
  if (iVar2 != 0) {
    iVar3 = FUN_005c71c0(param_4,3,2);
    if (iVar3 != 0) {
      if (iVar3 == *(int *)(DAT_0077244c + 0x48c)) {
        uVar5 = 0;
      }
      else if (*(int *)(iVar3 + 0x3e0) == 0) {
        puVar4 = (undefined4 *)FUN_004295e0(1);
        piVar1 = (int *)*puVar4;
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        FUN_006bc6a0("no production",piVar1);
        uVar5 = 0;
      }
      else {
        FUN_005ede50(iVar2);
        uVar5 = 0;
      }
      goto LAB_006a7180;
    }
  }
  uVar5 = 1;
LAB_006a7180:
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

