
undefined4
CTclObjMethods__TransferAttribs
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  int local_2c;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712668;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7d00) {
    FUN_006cebf4(&DAT_00ca7d00,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar1 = DAT_00783650;
    if (DAT_00ca7d00 == -1) {
      iVar2 = DAT_00783650 * 0x40;
      DAT_00ca7d04 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclObjMethods::TransferAttribs()";
      *(int *)(&DAT_00773650 + iVar2) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7d00);
    }
  }
  iVar2 = DAT_00ca7d04;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7d04 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar5;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar7 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  iVar1 = FUN_005c71c0(param_4,3,1);
  iVar2 = FUN_005c71c0(param_4,3,2);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    uVar5 = 1;
  }
  else if (*(int *)(iVar1 + 0x21c) == 0) {
    iVar1 = *(int *)(iVar2 + 0x21c);
    if (iVar1 != 0) {
      local_8._0_1_ = 3;
      FUN_0040b980(0);
      if (*(int *)(iVar1 + 0x800) != 0) {
        FUN_006ba940();
      }
      FUN_006cecd8(iVar1,0x808);
    }
    *(undefined4 *)(iVar2 + 0x21c) = 0;
    uVar5 = 0;
  }
  else {
    if (*(int *)(iVar2 + 0x21c) == 0) {
      iVar3 = FUN_006ba810(0x165);
      local_8._0_1_ = 4;
      if (iVar3 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_005da770();
      }
      local_8._0_1_ = 2;
      *(undefined4 *)(iVar2 + 0x21c) = uVar5;
    }
    iVar3 = 0;
    uVar6 = 0;
    do {
      local_18 = *(undefined4 **)(iVar1 + 0x21c);
      if (uVar6 < 0x200) {
        local_18 = (undefined4 *)((int)local_18 + iVar3);
        puVar4 = (undefined4 *)(*(int *)(iVar2 + 0x21c) + iVar3);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = *(undefined4 **)(iVar2 + 0x21c);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar6 = uVar6 + 1;
      iVar3 = iVar3 + 4;
      *puVar4 = *local_18;
    } while ((int)uVar6 < 0x200);
    iVar1 = *(int *)(iVar1 + 0x21c);
    puVar4 = (undefined4 *)(*(int *)(iVar2 + 0x21c) + 0x800);
    if (puVar4 != (undefined4 *)(iVar1 + 0x800)) {
      FUN_0040b980(*(undefined4 *)(iVar1 + 0x804));
      FUN_006d2250(*puVar4,*(undefined4 *)(iVar1 + 0x800),*(int *)(iVar1 + 0x804) << 2);
    }
    uVar5 = 0;
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_2c != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

