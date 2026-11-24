
undefined4
TclCmd_ai_prodpop_getcount(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int local_2c;
  int *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fabd5;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  uVar5 = param_3;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (uVar5 == 2) {
    if (local_14 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_18 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_1c + 1;
    }
    if (*piVar3 == 0) {
      uVar5 = 0;
LAB_0042cd95:
      if ((int)uVar5 <= (int)*(uint *)(param_1 + 0x38)) {
        if (*(uint *)(param_1 + 0x38) <= uVar5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar3 = (int *)Tcl_NewIntObj(*(undefined4 *)
                                       (*(int *)(param_1 + 0x34) + 0x10 + uVar5 * 0x14));
        *piVar3 = *piVar3 + 1;
        iVar2 = *piVar3;
        if (local_2c != 0) {
          Tcl_SetObjResult(local_2c,piVar3);
          iVar2 = *piVar3;
        }
        *piVar3 = iVar2 + -1;
        if (iVar2 + -1 < 1) {
          TclFreeObj(piVar3);
        }
        uVar4 = 0;
        goto LAB_0042ce51;
      }
    }
    else {
      iVar2 = Tcl_GetIntFromObj(0,*piVar3,&param_3,uVar1);
      if (iVar2 == 1) {
        uVar5 = 0;
        goto LAB_0042cd95;
      }
      uVar5 = param_3;
      if (-1 < (int)param_3) goto LAB_0042cd95;
    }
    if (local_14 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_18 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_1c + 1;
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
LAB_0042ce51:
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_1c != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  return uVar4;
}

