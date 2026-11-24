
undefined4
CTclGlobalMethods__GetAngleNum4
          (undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  float *pfVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  float fVar8;
  undefined8 uVar9;
  int local_50;
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
  puStack_c = &LAB_0070dd35;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca70d8) &&
     (FUN_006cebf4(&DAT_00ca70d8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca70d8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca70dc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::GetAngleNum4()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca70d8);
  }
  iVar5 = DAT_00ca70dc;
  local_28 = &DAT_00ca70dc;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca70dc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  if (param_3 == 4.2039e-45) {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_34;
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_34 + 1;
    }
    piVar4 = (int *)*puVar7;
    if (piVar4 == (int *)0x0) {
      pfVar3 = (float *)FUN_006bafe0(&local_40);
      param_3 = *pfVar3;
      local_14 = pfVar3[1];
      local_18 = pfVar3[2];
    }
    else {
      *piVar4 = *piVar4 + 1;
      pfVar3 = (float *)FUN_006bafe0(&local_40);
      param_3 = *pfVar3;
      local_14 = pfVar3[1];
      local_18 = pfVar3[2];
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
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
    piVar4 = (int *)*puVar7;
    local_24 = piVar4;
    if (piVar4 == (int *)0x0) {
      pfVar3 = (float *)FUN_006bafe0(&local_40);
      local_1c = *pfVar3;
      local_20 = pfVar3[1];
      local_24 = (int *)pfVar3[2];
    }
    else {
      *piVar4 = *piVar4 + 1;
      pfVar3 = (float *)FUN_006bafe0(&local_40);
      local_1c = *pfVar3;
      local_20 = pfVar3[1];
      local_24 = (int *)pfVar3[2];
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
    local_20 = local_20 - local_14;
    local_1c = local_1c - param_3;
    local_24 = (int *)((float)local_24 - local_18);
    fVar8 = local_20 * local_20 + local_1c * local_1c + (float)local_24 * (float)local_24;
    FUN_0040b7e0();
    if (fVar8 <= 0.0) {
      local_38 = 0.0;
      local_3c = 0.0;
      local_40 = 0.0;
    }
    else {
      local_3c = local_20 / fVar8;
      local_40 = local_1c / fVar8;
      fVar8 = (float)local_24 / fVar8;
      local_38 = fVar8;
    }
    FUN_0040b700();
    uVar6 = 0x3fU - (int)(((fVar8 - 2.3561945) + 31.415928) / -1.5707964) & 0x80000003;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
    }
    piVar4 = (int *)Tcl_NewIntObj(uVar6);
    *piVar4 = *piVar4 + 1;
    iVar2 = *piVar4;
    if (local_50 != 0) {
      Tcl_SetObjResult(local_50,piVar4);
      iVar2 = *piVar4;
    }
    *piVar4 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar4);
    }
    local_8._0_1_ = 4;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_004297b0(0);
    if (local_34 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

