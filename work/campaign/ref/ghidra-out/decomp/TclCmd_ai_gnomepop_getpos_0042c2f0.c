
undefined4 TclCmd_ai_gnomepop_getpos(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int local_30;
  int *local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fac15;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 2) {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_20 + 1;
    }
    if (*piVar3 == 0) {
      uVar1 = 0;
LAB_0042c3c5:
      if ((int)uVar1 <= (int)*(uint *)(param_1 + 0x30)) {
        if (*(uint *)(param_1 + 0x30) <= uVar1) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar3 = (int *)FUN_006badc0(*(int *)(param_1 + 0x2c) + uVar1 * 0x14);
        if (local_30 != 0) {
          if (*piVar3 == 0) {
            Tcl_ResetResult(local_30);
          }
          else {
            Tcl_SetObjResult(local_30,*piVar3);
          }
        }
        iRam00000002 = iRam00000002 + -1;
        if (iRam00000002 < 1) {
          TclFreeObj(2);
        }
        uVar4 = 0;
        goto LAB_0042c494;
      }
    }
    else {
      iVar2 = Tcl_GetIntFromObj(0,*piVar3,&local_14,uVar1);
      if (iVar2 == 1) {
        uVar1 = 0;
        goto LAB_0042c3c5;
      }
      uVar1 = local_14;
      if (-1 < (int)local_14) goto LAB_0042c3c5;
    }
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_20 + 1;
    }
    piVar3 = (int *)*piVar3;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bc6a0("invalid index",piVar3);
  }
  else {
    FUN_006bc8f0(1);
  }
  uVar4 = 1;
LAB_0042c494:
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_20 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  return uVar4;
}

