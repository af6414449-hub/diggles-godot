
undefined4 __thiscall FUN_0040c300(CAct_Crawl *this)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  int in_stack_00000008;
  int *in_stack_0000000c;
  int *in_stack_00000010;
  int *in_stack_00000014;
  double local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f982d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  this->i_0c = in_stack_00000008;
  FUN_0040c100();
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
  if (in_stack_00000014 == (int *)0x0) {
    fVar3 = 0.0;
  }
  else {
    iVar1 = Tcl_GetDoubleFromObj(0);
    if (iVar1 == 1) {
      fVar3 = 0.0;
    }
    else {
      fVar3 = (float)local_18;
    }
  }
  this->i_34 = (int)(fVar3 * 20.0);
  uVar2 = _rand();
  uVar2 = uVar2 & 0x80000003;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
  }
  this->f_38 = (float)(int)uVar2 * 1.5707964;
  FUN_006b49b0(in_stack_00000008,this->i_28,this->i_2c);
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

