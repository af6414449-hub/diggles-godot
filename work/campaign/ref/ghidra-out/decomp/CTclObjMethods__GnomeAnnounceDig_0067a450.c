
undefined4
CTclObjMethods__GnomeAnnounceDig
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined8 uVar6;
  float local_38;
  float fStack_34;
  undefined4 local_30;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  undefined4 *local_20;
  int local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710ec0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7560) &&
     (FUN_006cebf4(&DAT_00ca7560,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7560 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7564 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::GnomeAnnounceDig()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7560);
  }
  iVar5 = DAT_00ca7564;
  local_20 = &DAT_00ca7564;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7564 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar6 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  iVar3 = FUN_005c71c0(param_4,2,1);
  if (iVar3 != 0) {
    if (local_24 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = local_2c;
      }
    }
    else {
      if (local_28 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_2c + 2;
    }
    piVar2 = (int *)*puVar4;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_18 = piVar2;
    FUN_006bafe0(&local_38);
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 5;
    local_18 = (int *)FUN_005ee9d0();
    local_8._0_1_ = 2;
    if ((DAT_0076837a != '\0') && (iVar5 = *(int *)(iVar3 + 0x36c), -1 < iVar5)) {
      if (iVar5 < 8) {
        iVar5 = iVar5 * 0x70 + (int)local_18 + 0x10;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar5 = (int)local_18 + 0x10;
      }
      local_14 = FUN_00463a40();
      local_18 = (int *)local_38;
      DAT_00772dd8 = (int)ROUND(local_38);
      local_1c = DAT_00772dd8;
      if (*(uint *)(iVar5 + 0x2c) <= local_14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_18 = (int *)(local_14 * 0xc);
      *(int *)((int)local_18 + *(int *)(iVar5 + 0x28)) = local_1c;
      DAT_00772dd8 = (int)ROUND(fStack_34);
      local_1c = DAT_00772dd8;
      if (*(uint *)(iVar5 + 0x2c) <= local_14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(int *)((int)local_18 + 4 + *(int *)(iVar5 + 0x28)) = local_1c;
      if (*(uint *)(iVar5 + 0x2c) <= local_14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)((int)local_18 + 8 + *(int *)(iVar5 + 0x28)) = 0x32;
    }
    local_8._0_1_ = 6;
    if (DAT_0076a274 == 0) {
      iVar5 = FUN_006ba810(0x26);
      local_8._0_1_ = 7;
      local_1c = iVar5;
      if (iVar5 == 0) {
        DAT_0076a274 = 0;
      }
      else {
        FUN_00424cc0();
        DAT_0076a274 = iVar5;
      }
    }
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_00432390();
    if (((*(char *)(DAT_00772400 + 0x590) == '\0') && (DAT_0076837a == '\0')) &&
       (*(int *)(iVar3 + 0x36c) != -1)) {
      FUN_0043bc90(iVar3,local_38,fStack_34,local_30);
    }
    local_8._0_1_ = 9;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,10);
    FUN_004297b0(0);
    if (local_2c != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

