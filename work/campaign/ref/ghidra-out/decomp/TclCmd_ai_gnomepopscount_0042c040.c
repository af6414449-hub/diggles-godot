
undefined4
TclCmd_ai_gnomepopscount(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int local_2c;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fab9d;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  piVar2 = (int *)Tcl_NewIntObj(*(undefined4 *)(param_1 + 0x30),uVar1);
  *piVar2 = *piVar2 + 1;
  iVar3 = *piVar2;
  if (local_2c != 0) {
    Tcl_SetObjResult(local_2c,piVar2);
    iVar3 = *piVar2;
  }
  *piVar2 = iVar3 + -1;
  if (iVar3 + -1 < 1) {
    TclFreeObj(piVar2);
  }
  local_8._0_1_ = 1;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004297b0(0);
  if (local_1c != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  return 0;
}

