
undefined4 TclCmd_ai_getownerid(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_18;
  
  FUN_006bc170(param_2);
  piVar1 = (int *)Tcl_NewIntObj(*(undefined4 *)(param_1 + 0x14));
  *piVar1 = *piVar1 + 1;
  iVar2 = *piVar1;
  if (local_18 != 0) {
    Tcl_SetObjResult(local_18,piVar1);
    iVar2 = *piVar1;
  }
  *piVar1 = iVar2 + -1;
  if (iVar2 + -1 < 1) {
    TclFreeObj(piVar1);
  }
  FUN_006bc0d0();
  return 0;
}

