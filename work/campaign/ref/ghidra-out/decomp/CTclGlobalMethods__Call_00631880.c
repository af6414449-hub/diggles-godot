
undefined4
CTclGlobalMethods__Call(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  undefined **ppuVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  int *piVar11;
  int *piVar12;
  undefined8 uVar13;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070cc7d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e68) &&
     (FUN_006cebf4(&DAT_00ca6e68,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca6e68 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca6e6c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclGlobalMethods::Call()";
    *(int *)(&DAT_00773650 + iVar9) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e68);
  }
  iVar9 = DAT_00ca6e6c;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e6c * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar10;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar5 == 0) {
    uVar13 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar1 < 2) {
    FUN_006bc8f0(1);
    uVar10 = 1;
    goto LAB_00631bc9;
  }
  if (local_28 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar8 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar8 = local_30 + 1;
  }
  piVar1 = (int *)*puVar8;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8._0_1_ = 3;
  if (piVar1 == (int *)0x0) {
    ppuVar6 = &PTR_0071ce50;
  }
  else {
    ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  FUN_006b8fb0(ppuVar6);
  piVar11 = param_3;
  local_8._0_1_ = 4;
  piVar12 = param_3 + 3;
  iVar5 = __strnicmp((char *)piVar12,"scripts/",8);
  if (iVar5 == 0) {
    piVar7 = (int *)FUN_006b95d0(&param_3);
    local_8._0_1_ = 5;
    piVar12 = (int *)*piVar7;
    if (piVar12 != (int *)0x0) {
      *piVar12 = *piVar12 + 1;
    }
    param_3 = piVar12;
    if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
      FUN_006ba940();
    }
    piVar12[2] = *(int *)(*piVar7 + 8);
    local_8 = CONCAT31(local_8._1_3_,6);
LAB_00631a88:
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 4;
    piVar11 = piVar12;
  }
  else {
    iVar5 = __strnicmp((char *)piVar12,"templates/",10);
    if (iVar5 == 0) {
      piVar7 = (int *)FUN_006b95d0(&param_3);
      local_8._0_1_ = 7;
      piVar12 = (int *)*piVar7;
      if (piVar12 != (int *)0x0) {
        *piVar12 = *piVar12 + 1;
      }
      param_3 = piVar12;
      if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
        FUN_006ba940();
      }
      piVar12[2] = *(int *)(*piVar7 + 8);
      local_8 = CONCAT31(local_8._1_3_,8);
      goto LAB_00631a88;
    }
  }
  FUN_006bb140();
  local_8._0_1_ = 9;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 9;
  piVar12 = piVar11;
  if (local_14 == (int *)0x0) {
    piVar7 = (int *)FUN_004402c0();
    local_8._0_1_ = 10;
    piVar12 = (int *)*piVar7;
    if (piVar12 != (int *)0x0) {
      *piVar12 = *piVar12 + 1;
    }
    param_3 = piVar12;
    if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
      FUN_006ba940();
    }
    piVar12[2] = *(int *)(*piVar7 + 8);
    local_8._0_1_ = 0xb;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 9;
    puVar8 = (undefined4 *)FUN_006bb140();
    piVar2 = local_14;
    piVar11 = (int *)*puVar8;
    if (piVar11 != (int *)0x0) {
      *piVar11 = *piVar11 + 1;
    }
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
      local_14 = piVar11;
      TclFreeObj(piVar2);
      piVar11 = local_14;
    }
    local_14 = piVar11;
    if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
      TclFreeObj(piVar7);
    }
    uVar3 = (undefined1)local_8;
    if (local_14 != (int *)0x0) goto LAB_00631c21;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("file not found.",piVar1);
LAB_00631b7c:
    uVar10 = 0;
  }
  else {
LAB_00631c21:
    local_8._0_1_ = uVar3;
    cVar4 = FUN_00555a00(&local_14);
    if (cVar4 != '\0') goto LAB_00631b7c;
    uVar10 = 1;
  }
  if (local_14 != (int *)0x0) {
    *local_14 = *local_14 + -1;
    if (*local_14 < 1) {
      TclFreeObj(local_14);
    }
    local_14 = (int *)0x0;
  }
  local_8 = CONCAT31(local_8._1_3_,0xe);
  if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 == 0)) {
    FUN_006ba940();
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_00631bc9:
  local_8._0_1_ = 0xf;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x10);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

