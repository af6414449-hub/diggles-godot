
undefined4 __thiscall FUN_00406630(CAct *this)

{
  int *piVar1;
  int in_stack_00000008;
  int *in_stack_0000000c;
  int *in_stack_00000010;
  int *in_stack_00000014;
  
  piVar1 = *(int **)&this->field_0x8;
  *(int **)&this->field_0x8 = in_stack_00000014;
  if (in_stack_00000014 != (int *)0x0) {
    *in_stack_00000014 = *in_stack_00000014 + 1;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  this->i_0c = in_stack_00000008;
  piVar1 = *(int **)(this + 1);
  *(int **)(this + 1) = in_stack_0000000c;
  if (in_stack_0000000c != (int *)0x0) {
    *in_stack_0000000c = *in_stack_0000000c + 1;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  piVar1 = *(int **)&this[1].field_0x4;
  *(int **)&this[1].field_0x4 = in_stack_00000010;
  if (in_stack_00000010 != (int *)0x0) {
    *in_stack_00000010 = *in_stack_00000010 + 1;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  if (in_stack_0000000c != (int *)0x0) {
    *in_stack_0000000c = *in_stack_0000000c + -1;
    if (*in_stack_0000000c < 1) {
      TclFreeObj(in_stack_0000000c);
    }
  }
  if (in_stack_00000010 != (int *)0x0) {
    *in_stack_00000010 = *in_stack_00000010 + -1;
    if (*in_stack_00000010 < 1) {
      TclFreeObj(in_stack_00000010);
    }
  }
  if (in_stack_00000014 != (int *)0x0) {
    *in_stack_00000014 = *in_stack_00000014 + -1;
    if (*in_stack_00000014 < 1) {
      TclFreeObj(in_stack_00000014);
    }
  }
  return 1;
}

