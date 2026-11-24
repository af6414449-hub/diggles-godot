
undefined4 FUN_00669720(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  CMap *pCVar2;
  float *pfVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined1 local_34 [12];
  undefined4 *local_28;
  uint local_24;
  int local_20;
  float local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070fa5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 2) {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = local_28;
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_28 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    pfVar3 = (float *)FUN_006bafe0(local_34);
    local_14 = *pfVar3;
    local_18 = pfVar3[1];
    local_1c = pfVar3[2];
    fVar6 = local_14 * local_14 + local_18 * local_18 + local_1c * local_1c;
    FUN_0040b7e0();
    pCVar2 = PTR_0077241c;
    iVar10 = DAT_0076a338;
    fVar8 = 0.0;
    if (fVar6 <= 0.0) {
      fVar9 = 0.0;
      fVar7 = 0.0;
    }
    else {
      fVar9 = local_14 / fVar6;
      fVar7 = local_18 / fVar6;
      fVar8 = local_1c / fVar6;
    }
    uVar5 = 0x7ff;
    *(float *)(DAT_0076a338 + 0x19f1c) = fVar9;
    *(float *)(iVar10 + 0x19f20) = fVar7;
    *(float *)(iVar10 + 0x19f24) = fVar8;
    iVar10 = pCVar2->x0_8;
    iVar11 = pCVar2->y0_8;
    iVar12 = pCVar2->x1_8;
    iVar13 = pCVar2->y1_8;
    FUN_005a3dd0(iVar10,iVar11,iVar12,iVar13,0x7ff);
    FUN_005a3fd0(iVar10,iVar11,iVar12,iVar13,uVar5);
    uVar5 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar5 = 1;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  return uVar5;
}

