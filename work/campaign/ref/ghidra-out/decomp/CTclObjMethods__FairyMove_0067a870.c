
undefined4
CTclObjMethods__FairyMove
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  undefined8 uVar8;
  float fVar9;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 *local_50;
  uint local_4c;
  int local_48;
  undefined4 *local_44;
  undefined4 local_40;
  float fStack_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  int *local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710efd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7568) &&
     (FUN_006cebf4(&DAT_00ca7568,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7568 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca756c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::FairyMove()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7568);
  }
  iVar4 = DAT_00ca756c;
  local_44 = &DAT_00ca756c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca756c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_14 = (float)FUN_005c71c0(param_4,7,1);
  if (local_14 != 0.0) {
    if (local_48 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_50;
      if (local_4c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_50;
      }
    }
    else {
      if (local_4c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_50 + 2;
    }
    piVar2 = (int *)*puVar5;
    local_28 = piVar2;
    if (piVar2 == (int *)0x0) {
      FUN_006bafe0(&local_5c);
    }
    else {
      *piVar2 = *piVar2 + 1;
      FUN_006bafe0(&local_5c);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_48 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_50;
      if (local_4c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_50;
      }
    }
    else {
      if (local_4c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_50 + 3;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 == (int *)0x0) {
      local_20 = 0.0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_40);
      if (iVar3 == 1) {
        local_20 = 0.0;
      }
      else {
        local_20 = (float)(double)CONCAT44(fStack_3c,local_40);
      }
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_48 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_50;
      if (local_4c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_50;
      }
    }
    else {
      if (local_4c < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_50 + 4;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 == (int *)0x0) {
      local_18 = 0.0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_40);
      if (iVar3 == 1) {
        local_18 = 0.0;
      }
      else {
        local_18 = (float)(double)CONCAT44(fStack_3c,local_40);
      }
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_48 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_50;
      if (local_4c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_50;
      }
    }
    else {
      if (local_4c < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_50 + 5;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 == (int *)0x0) {
      local_1c = 0.0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_40);
      if (iVar3 == 1) {
        local_1c = 0.0;
      }
      else {
        local_1c = (float)(double)CONCAT44(fStack_3c,local_40);
      }
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_48 < 7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_50;
      if (local_4c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_50;
      }
    }
    else {
      if (local_4c < 7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_50 + 6;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 == (int *)0x0) {
      local_24 = 0.0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar2,&local_40);
      if (iVar3 == 1) {
        local_24 = 0.0;
      }
      else {
        local_24 = (float)(double)CONCAT44(fStack_3c,local_40);
      }
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    fVar9 = local_14;
    local_28 = (int *)(*(float *)((int)local_14 + 0xc) - local_5c);
    local_30 = *(float *)((int)local_14 + 0x14) - local_54;
    fVar7 = local_1c;
    local_14 = *(float *)((int)local_14 + 0x10) - local_58;
    FUN_004089d0();
    fVar6 = local_1c;
    local_2c = fVar7;
    FUN_004089f0();
    fVar7 = (float)local_28 * local_2c;
    local_28 = (int *)(fVar6 * (float)local_28 + local_14 * local_2c);
    local_14 = fVar6 * local_14 - fVar7;
    fVar7 = local_18;
    FUN_004089d0();
    fVar6 = local_18;
    local_2c = fVar7;
    FUN_004089f0();
    local_38 = local_2c * local_30 + fVar6 * local_14;
    local_34 = fVar6 * local_30 - local_2c * local_14;
    fVar7 = local_34 * local_34 + local_38 * local_38 + (float)local_28 * (float)local_28;
    FUN_0040b7e0();
    fStack_3c = fVar7 * 0.9 + local_20 * 0.1;
    fVar6 = local_24;
    FUN_004089d0();
    fVar7 = local_24;
    local_2c = fVar6;
    FUN_004089f0();
    local_20 = fVar7;
    iVar3 = _rand();
    local_30 = (float)iVar3 * 3.0517578e-05 - 0.5;
    iVar3 = _rand();
    local_24 = (float)iVar3 * 3.0517578e-05 - 0.5;
    iVar3 = _rand();
    local_24 = local_24 * 1e-09 + local_38;
    local_14 = (local_20 * (float)local_28 - local_2c * local_34) + local_30 * 1e-09;
    local_20 = local_20 * local_34 + local_2c * (float)local_28 +
               ((float)iVar3 * 3.0517578e-05 - 0.5) * 1e-09;
    fVar7 = local_24 * local_24 + local_14 * local_14 + local_20 * local_20;
    FUN_0040b7e0();
    fVar6 = 0.0;
    if (fVar7 <= 0.0) {
      local_20 = 0.0;
      local_24 = 0.0;
    }
    else {
      fVar6 = local_14 / fVar7;
      local_24 = local_24 / fVar7;
      local_20 = local_20 / fVar7;
    }
    local_14 = fVar6 * fStack_3c;
    local_24 = local_24 * fStack_3c;
    fVar6 = -local_18;
    local_20 = local_20 * fStack_3c;
    local_18 = fVar6;
    FUN_004089d0();
    fVar7 = local_18;
    local_28 = (int *)fVar6;
    FUN_004089f0();
    local_38 = local_20 * (float)local_28 + local_24 * fVar7;
    fVar6 = -local_1c;
    local_34 = fVar7;
    local_1c = fVar6;
    FUN_004089d0();
    fVar7 = local_1c;
    fStack_3c = fVar6;
    FUN_004089f0();
    local_5c = fStack_3c * local_38 + local_14 * fVar7 + local_5c;
    local_58 = (fVar7 * local_38 - local_14 * fStack_3c) + local_58;
    local_54 = (local_20 * local_34 - local_24 * (float)local_28) + local_54;
    if ((((*(float *)((int)fVar9 + 0xc) != local_5c) || (*(float *)((int)fVar9 + 0x10) != local_58))
        || (*(float *)((int)fVar9 + 0x14) != local_54)) &&
       (FUN_005cd8e0(&local_5c), *(int *)((int)fVar9 + 0x238) == 0)) {
      FUN_005ebc90(fVar9);
      FUN_005eb470(fVar9);
    }
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_004297b0(0);
    if (local_50 != (undefined4 *)0x0) {
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
  if (local_50 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

