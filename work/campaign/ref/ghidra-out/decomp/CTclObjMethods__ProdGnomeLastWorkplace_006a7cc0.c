
undefined4
CTclObjMethods__ProdGnomeLastWorkplace
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071242d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c90) &&
     (FUN_006cebf4(&DAT_00ca7c90,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7c90 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7c94 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::ProdGnomeLastWorkplace()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c90);
  }
  iVar4 = DAT_00ca7c94;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c94 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,2,1);
  if (iVar2 != 0) {
    iVar4 = *(int *)(iVar2 + 0x3e4);
    if (iVar4 != 0) {
      iVar3 = 0;
      if (param_3 == 3) {
        iVar3 = FUN_005c71c0(param_4,3,2);
        iVar4 = *(int *)(iVar2 + 0x3e4);
      }
      *(undefined4 *)(iVar4 + 0x3c) = 0xffffffff;
      if (iVar3 != 0) {
        *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(iVar3 + 0xdc);
      }
      if (*(char *)(iVar4 + 0x44) == '\0') {
        *(undefined1 *)(iVar4 + 0x44) = 1;
        FUN_00432390();
      }
      uVar6 = 0;
      goto LAB_006a7e0e;
    }
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_24 + 1;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("no gnome",piVar1);
  }
  uVar6 = 1;
LAB_006a7e0e:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

