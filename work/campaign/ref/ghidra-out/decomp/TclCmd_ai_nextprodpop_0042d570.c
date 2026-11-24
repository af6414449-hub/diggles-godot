
undefined4 TclCmd_ai_nextprodpop(int param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  int local_44;
  float local_34;
  float local_30;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fac95;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  if (param_3 != 2.8026e-45) {
    FUN_006bc8f0(1);
    local_8._0_1_ = 2;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004297b0(0);
    if (local_28 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    ExceptionList = local_10;
    return 1;
  }
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
  piVar5 = (int *)*puVar4;
  if (piVar5 != (int *)0x0) {
    *piVar5 = *piVar5 + 1;
  }
  local_1c = piVar5;
  FUN_006bafe0(&local_34);
  uVar6 = 0;
  param_3 = 3.4028235e+38;
  local_18 = *(int *)(param_1 + 0x38);
  local_14 = 0xffffffff;
  if (0 < local_18) {
    do {
      if (*(uint *)(param_1 + 0x38) <= uVar6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      fVar7 = local_30 - *(float *)(*(int *)(param_1 + 0x34) + 4 + uVar6 * 0x14);
      fVar8 = local_34 - *(float *)(*(int *)(param_1 + 0x34) + uVar6 * 0x14);
      fVar7 = fVar7 * fVar7 + fVar8 * fVar8;
      FUN_0040b7e0();
      uVar1 = uVar6;
      if (param_3 <= fVar7) {
        uVar1 = local_14;
        fVar7 = param_3;
      }
      param_3 = fVar7;
      uVar6 = uVar6 + 1;
      piVar5 = local_1c;
      local_14 = uVar1;
    } while ((int)uVar6 < local_18);
  }
  piVar2 = (int *)Tcl_NewIntObj(local_14);
  *piVar2 = *piVar2 + 1;
  iVar3 = *piVar2;
  if (local_44 != 0) {
    Tcl_SetObjResult(local_44,piVar2);
    iVar3 = *piVar2;
  }
  *piVar2 = iVar3 + -1;
  if (iVar3 + -1 < 1) {
    TclFreeObj(piVar2);
  }
  if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
    TclFreeObj(piVar5);
  }
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  return 0;
}

