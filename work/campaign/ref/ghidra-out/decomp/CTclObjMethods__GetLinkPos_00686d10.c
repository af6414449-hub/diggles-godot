
undefined4
CTclObjMethods__GetLinkPos
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 extraout_ECX;
  undefined4 *puVar7;
  float fVar8;
  float fVar9;
  undefined8 uVar10;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  undefined4 *local_28;
  int *local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711515;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca77c0) &&
     (FUN_006cebf4(&DAT_00ca77c0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca77c0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca77c4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::GetLinkPos()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca77c0);
  }
  iVar5 = DAT_00ca77c4;
  local_28 = &DAT_00ca77c4;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca77c4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar4;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar10 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  iVar3 = FUN_005c71c0(param_4,3,1);
  if (iVar3 != 0) {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_34;
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_34 + 2;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    local_24 = piVar1;
    if (piVar1 == (int *)0x0) {
      fVar9 = 0.0;
    }
    else {
      iVar5 = Tcl_GetIntFromObj(0,piVar1,&local_18);
      if (iVar5 == 1) {
        fVar9 = 0.0;
      }
      else if (((int)local_18 < 0) || (fVar9 = local_18, 0x1f < (int)local_18)) {
        piVar6 = (int *)Tcl_NewIntObj(local_18,extraout_ECX);
        *piVar6 = *piVar6 + 1;
        FUN_006bc6a0("Invalid link-id :  %i",piVar6);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
        local_8._0_1_ = 6;
        FUN_004297b0(0);
        local_8 = CONCAT31(local_8._1_3_,7);
        goto LAB_006870ce;
      }
    }
    uVar2 = *(uint *)(iVar3 + 0x39c);
    if ((uVar2 == 0xffffffff) || (*(int *)(iVar3 + 0x3a0) == -1)) {
      local_40 = 0.0;
      local_3c = 0.0;
      local_38 = 0.0;
      uVar4 = FUN_006badc0(&local_40);
      FUN_006bc670(uVar4);
    }
    else {
      if (uVar2 < 0x100) {
        local_14 = *(float *)(DAT_00772400 + 0x5c8 + uVar2 * 4);
      }
      else {
        local_14 = 0.0;
      }
      iVar5 = FUN_004059a0(*(int *)(iVar3 + 0x3a0));
      FUN_00408920(*(undefined4 *)(iVar5 + 0x5c + (int)fVar9 * 4));
      FUN_00408a10();
      fVar9 = *(float *)(iVar3 + 0x48);
      FUN_004089d0();
      fVar8 = *(float *)(iVar3 + 0x48);
      local_18 = fVar9;
      FUN_004089f0();
      local_1c = local_3c * local_18 + local_40 * fVar8;
      fVar9 = *(float *)(iVar3 + 0x40);
      local_18 = local_3c * fVar8 - local_40 * local_18;
      FUN_004089d0();
      puVar7 = *(undefined4 **)(iVar3 + 0x40);
      local_14 = fVar9;
      FUN_004089f0();
      fVar9 = *(float *)(iVar3 + 0x44);
      local_24 = (int *)(local_38 * (float)puVar7 - local_18 * local_14);
      local_28 = puVar7;
      FUN_004089d0();
      fVar8 = *(float *)(iVar3 + 0x44);
      local_20 = fVar9;
      FUN_004089f0();
      local_40 = (fVar8 * local_1c - local_20 * (float)local_24) * 0.005;
      fVar9 = local_38 * local_14;
      local_38 = (local_20 * local_1c + fVar8 * (float)local_24) * 0.005;
      local_38 = local_38 + local_38;
      local_3c = (fVar9 + local_18 * (float)local_28) * 0.005;
      uVar4 = FUN_006badc0(&local_40);
      FUN_006bc670(uVar4);
    }
    FUN_006bad60();
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    FUN_00429650();
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
LAB_006870ce:
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

