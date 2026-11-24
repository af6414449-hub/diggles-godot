
undefined4
CTclObjMethods__GnomeStoppedWork
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710b1d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74e8) &&
     (FUN_006cebf4(&DAT_00ca74e8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca74e8 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca74ec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::GnomeStoppedWork";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca74e8);
  }
  iVar3 = DAT_00ca74ec;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74ec * 0x40);
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
    iVar2 = *(int *)(iVar2 + 0x3e4);
    if (iVar2 != 0) {
      FUN_005dc6a0(extraout_ECX);
      if (*(char *)(iVar2 + 0x44) != '\0') {
        *(undefined1 *)(iVar2 + 0x44) = 0;
      }
      iVar2 = *(int *)(iVar2 + 8);
      FUN_00432390();
      if (((*(char *)(DAT_00772400 + 0x590) == '\0') && (DAT_0076837a == '\0')) &&
         (*(int *)(iVar2 + 0x36c) != -1)) {
        FUN_0043a0c0(iVar2);
        *(undefined4 *)(*(int *)(iVar2 + 0x3e4) + 0x48) = 0x40a00000;
        iVar3 = FUN_0043a050(iVar2);
        if (iVar3 != -1) {
          FUN_0043d4b0(iVar3);
        }
        FUN_0043a0c0(iVar2);
        *(undefined1 *)(*(int *)(iVar2 + 0x3e4) + 4) = 1;
      }
      uVar5 = 0;
      goto LAB_0067664b;
    }
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_24 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("no prod control",piVar1);
  }
  uVar5 = 1;
LAB_0067664b:
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
  return uVar5;
}

