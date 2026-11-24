
undefined4 FUN_00416da0(undefined4 param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int this;
  int *piVar2;
  uint uVar3;
  float fVar4;
  undefined4 local_1c;
  undefined4 uStack_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9e5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  if (param_5 != (int *)0x0) {
    *param_5 = *param_5 + 1;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = *param_4 + 1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + 1;
  }
  FUN_00406630(param_1,param_2,param_3);
  fVar4 = 0.0;
  if (param_5 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = Tcl_ListObjIndex(0,param_5);
    if (iVar1 == 0) {
      piVar2 = param_2;
      if (param_2 != (int *)0x0) {
        *param_2 = *param_2 + 1;
        iVar1 = Tcl_GetDoubleFromObj(0);
        if (iVar1 != 1) {
          fVar4 = (float)(double)CONCAT44(uStack_18,local_1c);
          goto LAB_00416e3b;
        }
      }
    }
    else {
      piVar2 = (int *)0x0;
    }
    fVar4 = 0.0;
  }
LAB_00416e3b:
  this->f_218 = fVar4;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    TclFreeObj();
  }
  if (((param_5 == (int *)0x0) || (iVar1 = Tcl_ListObjIndex(0,param_5), iVar1 != 0)) ||
     (param_2 == (int *)0x0)) {
    uVar3 = 0;
  }
  else {
    *param_2 = *param_2 + 1;
    iVar1 = Tcl_GetIntFromObj(0);
    *param_2 = *param_2 + -1;
    uVar3 = -(uint)(iVar1 != 1) & (uint)param_2;
    if (*param_2 < 1) {
      TclFreeObj();
    }
  }
  this->i_24 = uVar3;
  FUN_00417280();
  this->i_20 = 0;
  FUN_005cd840();
  FUN_00416c00();
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    TclFreeObj();
  }
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 < 1)) {
    TclFreeObj();
  }
  if ((param_5 != (int *)0x0) && (*param_5 = *param_5 + -1, *param_5 < 1)) {
    TclFreeObj();
  }
  ExceptionList = local_10;
  return 1;
}

