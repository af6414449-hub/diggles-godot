
undefined4 TclCmd_ai_getintrudergnomes(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int local_28;
  char local_24;
  int *local_20;
  int *local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fadd0;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  piVar4 = (int *)Tcl_NewListObj(0,0,uVar3);
  piVar2 = param_1;
  if (piVar4 != (int *)0x0) {
    *piVar4 = *piVar4 + 1;
  }
  uVar3 = 0;
  iVar1 = param_1[0x10];
  if (0 < iVar1) {
    do {
      if ((uint)piVar2[0x10] <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar5 = (int *)Tcl_NewIntObj(*(undefined4 *)(piVar2[0xf] + uVar3 * 4));
      *piVar5 = *piVar5 + 1;
      param_1 = piVar5;
      FUN_006bb930(&param_1);
      *piVar5 = *piVar5 + -1;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < iVar1);
  }
  if (local_28 != 0) {
    if (piVar4 == (int *)0x0) {
      Tcl_ResetResult(local_28);
      goto LAB_0042e428;
    }
    Tcl_SetObjResult(local_28,piVar4);
  }
  if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
    TclFreeObj(piVar4);
  }
LAB_0042e428:
  if ((local_24 != '\0') && (local_28 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_28);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8 = 0;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8 = 1;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return 0;
}

