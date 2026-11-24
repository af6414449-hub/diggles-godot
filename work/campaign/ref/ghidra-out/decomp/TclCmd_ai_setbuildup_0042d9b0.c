
undefined4
TclCmd_ai_setbuildup(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined1 local_30 [12];
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fad1d;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar4 = FUN_005c71c0(param_4,3,1,uVar3);
  if (iVar4 == 0) {
    uVar6 = 1;
  }
  else {
    if (local_1c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_24;
      }
    }
    else {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_24 + 2;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    local_14 = piVar1;
    if (*(int *)(iVar4 + 0x3e0) == 0) {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar5 = local_24;
        }
      }
      else {
        if (local_20 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_24 + 1;
      }
      piVar2 = (int *)*puVar5;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      FUN_006bc6a0("no prod-site",piVar2);
      uVar6 = 1;
    }
    else {
      puVar5 = (undefined4 *)FUN_006bafe0(local_30);
      iVar4 = *(int *)(iVar4 + 0x3e0);
      uVar6 = 0;
      *(undefined2 *)(iVar4 + 0x2c) = 0;
      *(undefined2 *)(iVar4 + 0x28) = 1;
      *(undefined1 *)(iVar4 + 0x2b) = 1;
      *(undefined2 *)(iVar4 + 0x3d) = 0x100;
      *(undefined4 *)(iVar4 + 0x30) = *puVar5;
      *(undefined4 *)(iVar4 + 0x34) = puVar5[1];
      *(undefined4 *)(iVar4 + 0x38) = puVar5[2];
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  return uVar6;
}

