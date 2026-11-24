
undefined4
CTclGlobalMethods__PictureBox(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bb98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c60) &&
     (FUN_006cebf4(&DAT_00ca6c60,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6c60 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6c64 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::PictureBox()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c60);
  }
  iVar7 = DAT_00ca6c64;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c64 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    if (local_3c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_44 + 1;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 4;
    FUN_004e4550();
    iVar3 = FUN_00501450();
    if (*(int *)(iVar3 + 0x8194) != 0) {
      FUN_00501450();
      puVar5 = (undefined4 *)FUN_006ba810(0x13);
      local_8._0_1_ = 5;
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
        local_14 = (undefined4 *)0x0;
      }
      else {
        local_14 = puVar5;
        FUN_005044d0();
        *puVar5 = ViWinClickPicBox::vftable;
        puVar5[0x11] = 0;
      }
      local_8._0_1_ = 4;
      puVar6 = (undefined4 *)FUN_006ba810(0x14);
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        *puVar6 = 0;
        puVar6[1] = 0;
        puVar6[6] = 0;
        puVar6[4] = 0;
        puVar6[5] = 0;
        puVar6[3] = 0;
        puVar6[2] = 0;
      }
      puVar5[0x11] = puVar6;
      cVar2 = FUN_004fef30(local_18 + 3);
      if (cVar2 == '\0') {
        (**(code **)*puVar5)(1);
      }
      else {
        local_28 = *(int *)puVar5[0x11];
        local_20 = ((int *)puVar5[0x11])[1];
        local_24 = local_28;
        local_1c = local_20;
        FUN_00504ba0(&local_24);
        iVar3 = FUN_00501450();
        iVar3 = *(int *)(iVar3 + 0x8194);
        iVar7 = *(int *)(iVar3 + 0xc);
        local_20 = *(int *)(iVar3 + 0x14);
        iVar3 = (*(int *)(iVar3 + 0x18) - *(int *)(iVar3 + 0x10)) - local_1c;
        FUN_00501750(local_14);
        puVar5 = local_14;
        local_2c = ((local_20 - local_28) - iVar7) / 2;
        local_28 = iVar3 / 2;
        FUN_00504a70(&local_2c);
        FUN_00504ce0(puVar5);
        FUN_00505ed0();
      }
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    uVar8 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar8 = 1;
  }
  FUN_006bc0d0();
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

