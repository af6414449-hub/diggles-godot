
undefined4 __thiscall FUN_00416da0(CAct_Rotate *this)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  float fVar4;
  int *in_stack_00000008;
  int *in_stack_0000000c;
  int *in_stack_00000010;
  int *in_stack_00000014;
  undefined4 local_1c;
  undefined4 uStack_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9e5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  if (in_stack_00000014 != (int *)0x0) {
    *in_stack_00000014 = *in_stack_00000014 + 1;
  }
  if (in_stack_00000010 != (int *)0x0) {
    *in_stack_00000010 = *in_stack_00000010 + 1;
  }
  if (in_stack_0000000c != (int *)0x0) {
    *in_stack_0000000c = *in_stack_0000000c + 1;
  }
  FUN_00406630((CAct *)this);
  fVar4 = 0.0;
  if (in_stack_00000014 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = Tcl_ListObjIndex(0,in_stack_00000014);
    if (iVar1 == 0) {
      piVar2 = in_stack_00000008;
      if (in_stack_00000008 != (int *)0x0) {
        *in_stack_00000008 = *in_stack_00000008 + 1;
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
  if (((in_stack_00000014 == (int *)0x0) ||
      (iVar1 = Tcl_ListObjIndex(0,in_stack_00000014), iVar1 != 0)) ||
     (in_stack_00000008 == (int *)0x0)) {
    uVar3 = 0;
  }
  else {
    *in_stack_00000008 = *in_stack_00000008 + 1;
    iVar1 = Tcl_GetIntFromObj(0);
    *in_stack_00000008 = *in_stack_00000008 + -1;
    uVar3 = -(uint)(iVar1 != 1) & (uint)in_stack_00000008;
    if (*in_stack_00000008 < 1) {
      TclFreeObj();
    }
  }
  this->i_24 = uVar3;
  FUN_00417280();
  this->i_20 = 0;
  FUN_005cd840();
  FUN_00416c00();
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c < 1)) {
    TclFreeObj();
  }
  if ((in_stack_00000010 != (int *)0x0) &&
     (*in_stack_00000010 = *in_stack_00000010 + -1, *in_stack_00000010 < 1)) {
    TclFreeObj();
  }
  if ((in_stack_00000014 != (int *)0x0) &&
     (*in_stack_00000014 = *in_stack_00000014 + -1, *in_stack_00000014 < 1)) {
    TclFreeObj();
  }
  ExceptionList = local_10;
  return 1;
}

