
undefined4 __thiscall FUN_00407430(CActWalk *this)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 in_stack_00000004;
  int in_stack_00000008;
  int *in_stack_0000000c;
  int *in_stack_00000010;
  int *in_stack_00000014;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9678;
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
  iVar2 = FUN_006ba810();
  local_8._0_1_ = 3;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00420520();
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  puVar1 = (undefined4 *)this->i_1c;
  this->i_1c = iVar2;
  if (iVar2 != 0) {
    LOCK();
    *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
    UNLOCK();
  }
  if (puVar1 != (undefined4 *)0x0) {
    LOCK();
    iVar2 = puVar1[1] + -1;
    puVar1[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*puVar1)();
    }
  }
  FUN_00420840(in_stack_00000004);
  iVar2 = this->i_1c;
  if (*(int *)(iVar2 + 0x7b4) != 0) {
    *(undefined4 *)(iVar2 + 0x7a4) = *(undefined4 *)(in_stack_00000008 + 0xc);
    *(undefined4 *)(iVar2 + 0x7a8) = *(undefined4 *)(in_stack_00000008 + 0x10);
    *(undefined4 *)(iVar2 + 0x7ac) = *(undefined4 *)(in_stack_00000008 + 0x14);
  }
  this->i_24 = 2;
  *(undefined4 *)(in_stack_00000008 + 0x248) = 2;
  *(undefined1 *)(in_stack_00000008 + 0x2b4) = 1;
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c < 1)) {
    TclFreeObj(in_stack_0000000c);
  }
  if ((in_stack_00000010 != (int *)0x0) &&
     (*in_stack_00000010 = *in_stack_00000010 + -1, *in_stack_00000010 < 1)) {
    TclFreeObj(in_stack_00000010);
  }
  if ((in_stack_00000014 != (int *)0x0) &&
     (*in_stack_00000014 = *in_stack_00000014 + -1, *in_stack_00000014 < 1)) {
    TclFreeObj(in_stack_00000014);
  }
  ExceptionList = local_10;
  return 1;
}

