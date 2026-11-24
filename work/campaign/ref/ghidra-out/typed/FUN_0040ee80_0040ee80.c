
undefined4 __thiscall FUN_0040ee80(CAct_Fall *this)

{
  int *piVar1;
  int in_stack_00000008;
  int *in_stack_0000000c;
  int *in_stack_00000010;
  int *in_stack_00000014;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9b0d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  this->i_0c = in_stack_00000008;
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
  piVar1 = (int *)FUN_006ba810();
  piVar1[1] = 4;
  piVar1[2] = -1;
  *piVar1 = 0;
  *(undefined1 *)(piVar1 + 3) = 0;
  piVar1[2] = 0;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  FUN_0040efc0();
  if ((this->i_1c != -1) && (this->i_20 != -1)) {
    FUN_006b49b0(this->i_0c,this->i_1c,this->i_20);
  }
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

