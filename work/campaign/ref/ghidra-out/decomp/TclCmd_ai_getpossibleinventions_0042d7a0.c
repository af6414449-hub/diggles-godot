
undefined4
TclCmd_ai_getpossibleinventions
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int local_3c;
  char local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006facd5;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = *(int *)(param_1 + 0x14);
  iVar4 = FUN_00432390(uVar3);
  iVar4 = iVar4 + iVar1 * 0x3094;
  piVar5 = (int *)Tcl_NewListObj(0,0);
  if (piVar5 != (int *)0x0) {
    *piVar5 = *piVar5 + 1;
  }
  uVar3 = 0;
  local_14 = DAT_00772478;
  iVar1 = *(int *)(iVar4 + 0x48);
  if (0 < iVar1) {
    do {
      if (*(uint *)(iVar4 + 0x48) <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar2 = *(uint *)(*(int *)(iVar4 + 0x44) + uVar3 * 4);
      if (*(uint *)(local_14 + 0x801c) <= uVar2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar6 = *(int *)(*(int *)(*(int *)(local_14 + 0x8018) + uVar2 * 4) + 0xc) + 0xc;
      if (iVar6 == 0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)Tcl_NewStringObj(iVar6,0xffffffff);
        *piVar7 = *piVar7 + 1;
      }
      local_18 = piVar7;
      FUN_006bb930(&local_18);
      if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
        TclFreeObj(piVar7);
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < iVar1);
  }
  if (local_3c != 0) {
    if (piVar5 == (int *)0x0) {
      Tcl_ResetResult(local_3c);
      goto LAB_0042d903;
    }
    Tcl_SetObjResult(local_3c,piVar5);
  }
  if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
    TclFreeObj(piVar5);
  }
LAB_0042d903:
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_2c != 0) {
    FUN_006ba940();
  }
  if ((local_38 != '\0') && (local_3c != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_3c);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8 = 4;
  if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
    FUN_006ba940();
  }
  local_8 = 5;
  if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return 0;
}

