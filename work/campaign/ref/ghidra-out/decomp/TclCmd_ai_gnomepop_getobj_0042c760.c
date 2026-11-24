
undefined4
TclCmd_ai_gnomepop_getobj(int *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
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
  uVar5 = param_3;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (uVar5 == 3) {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar2 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = local_20 + 1;
    }
    if (*piVar2 == 0) {
      uVar5 = 0;
LAB_0042c83b:
      if (param_1[0xc] < (int)uVar5) goto LAB_0042c90d;
      piVar2 = (int *)FUN_004295e0(2);
      if (*piVar2 == 0) {
        local_14 = 0;
      }
      else {
        iVar3 = Tcl_GetIntFromObj(0,*piVar2,&local_14);
        local_14 = -(uint)(iVar3 != 1) & local_14;
      }
      if ((uint)param_1[0xc] <= uVar5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if ((-1 < (int)local_14) && ((int)local_14 < *(int *)(param_1[0xb] + 0x10 + uVar5 * 0x14))) {
        FUN_0040b900(local_14);
        iVar3 = FUN_005caf90();
        if (iVar3 == 0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = (int *)Tcl_NewStringObj(iVar3,0xffffffff);
          *piVar2 = *piVar2 + 1;
        }
        param_1 = piVar2;
        FUN_006bc670(&param_1);
        if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
          TclFreeObj(piVar2);
        }
        uVar6 = 0;
        goto LAB_0042c970;
      }
      puVar4 = (undefined4 *)FUN_004295e0(2);
      piVar2 = (int *)*puVar4;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      pcVar7 = "invalid object index";
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,*piVar2,&param_3,uVar1);
      if (iVar3 == 1) {
        uVar5 = 0;
        goto LAB_0042c83b;
      }
      uVar5 = param_3;
      if (-1 < (int)param_3) goto LAB_0042c83b;
LAB_0042c90d:
      if (local_18 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar2 = local_20;
        if (local_1c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_1c < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar2 = local_20 + 1;
      }
      piVar2 = (int *)*piVar2;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      pcVar7 = "invalid population index";
    }
    FUN_006bc6a0(pcVar7,piVar2);
  }
  else {
    FUN_006bc8f0(2);
  }
  uVar6 = 1;
LAB_0042c970:
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_20 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  return uVar6;
}

