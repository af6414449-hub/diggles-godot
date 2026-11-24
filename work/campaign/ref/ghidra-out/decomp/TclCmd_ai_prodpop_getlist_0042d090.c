
undefined4 TclCmd_ai_prodpop_getlist(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int local_38;
  int *local_28;
  uint local_24;
  int local_20;
  uint local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fac55;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  iVar2 = param_3;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (iVar2 == 2) {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar4 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar4 = local_28 + 1;
    }
    if (*piVar4 == 0) {
      uVar1 = 0;
LAB_0042d169:
      piVar4 = param_1;
      if ((int)uVar1 <= param_1[0xe]) {
        if ((uint)param_1[0xe] <= uVar1) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        param_3 = piVar4[0xd] + uVar1 * 0x14;
        local_14 = (int *)Tcl_NewListObj(0,0);
        if (local_14 != (int *)0x0) {
          *local_14 = *local_14 + 1;
        }
        uVar1 = 0;
        iVar2 = *(int *)(param_3 + 0x10);
        if (0 < iVar2) {
          do {
            if (*(uint *)(param_3 + 0x10) <= uVar1) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar3 = FUN_005caf90();
            if (iVar3 == 0) {
              piVar4 = (int *)0x0;
            }
            else {
              piVar4 = (int *)Tcl_NewStringObj(iVar3,0xffffffff);
              *piVar4 = *piVar4 + 1;
            }
            param_1 = piVar4;
            FUN_006bb930(&param_1);
            if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
              TclFreeObj(piVar4);
            }
            uVar1 = uVar1 + 1;
          } while ((int)uVar1 < iVar2);
        }
        piVar4 = local_14;
        if (local_38 != 0) {
          if (local_14 == (int *)0x0) {
            Tcl_ResetResult(local_38);
            uVar5 = 0;
            goto LAB_0042d2c1;
          }
          Tcl_SetObjResult(local_38,local_14);
        }
        uVar5 = 0;
        if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
          TclFreeObj(piVar4);
        }
        goto LAB_0042d2c1;
      }
    }
    else {
      iVar2 = Tcl_GetIntFromObj(0,*piVar4,&local_18,uVar1);
      if (iVar2 == 1) {
        uVar1 = 0;
        goto LAB_0042d169;
      }
      uVar1 = local_18;
      if (-1 < (int)local_18) goto LAB_0042d169;
    }
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar4 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar4 = local_28 + 1;
    }
    piVar4 = (int *)*piVar4;
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    FUN_006bc6a0("invalid index",piVar4);
  }
  else {
    FUN_006bc8f0(1);
  }
  uVar5 = 1;
LAB_0042d2c1:
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_28 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  return uVar5;
}

