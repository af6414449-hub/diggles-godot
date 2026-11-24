
undefined4 FUN_00669900(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070fa9d;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  iVar3 = param_3;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (iVar3 == 2) {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_20 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if (piVar1 == (int *)0x0) {
      bVar6 = false;
    }
    else {
      iVar3 = Tcl_GetBooleanFromObj(0,piVar1,&param_3,uVar2);
      if (iVar3 == 1) {
        bVar6 = false;
      }
      else {
        bVar6 = param_3 != 0;
      }
    }
    uVar5 = 0x7ff;
    *(bool *)(DAT_0076a338 + 0x19f19) = bVar6;
    iVar3 = PTR_0077241c->x0_8;
    iVar7 = PTR_0077241c->y0_8;
    iVar8 = PTR_0077241c->x1_8;
    iVar9 = PTR_0077241c->y1_8;
    FUN_005a3dd0(iVar3,iVar7,iVar8,iVar9,0x7ff);
    FUN_005a3fd0(iVar3,iVar7,iVar8,iVar9,uVar5);
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
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  return uVar5;
}

