
undefined4 __thiscall FUN_0041fe30(CActWalk_AutoRetry *this)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *in_stack_00000004;
  int in_stack_00000008;
  undefined4 *in_stack_0000000c;
  
  puVar2 = (undefined4 *)this->i_0c;
  this->i_0c = (int)in_stack_00000004;
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    in_stack_00000004[1] = in_stack_00000004[1] + 1;
    UNLOCK();
  }
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    iVar3 = puVar2[1] + -1;
    puVar2[1] = iVar3;
    UNLOCK();
    if (iVar3 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  this->i_04 = in_stack_00000008;
  puVar2 = *(undefined4 **)&this->field_0x10;
  *(undefined4 **)&this->field_0x10 = in_stack_0000000c;
  if (in_stack_0000000c != (undefined4 *)0x0) {
    LOCK();
    in_stack_0000000c[1] = in_stack_0000000c[1] + 1;
    UNLOCK();
  }
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    iVar3 = puVar2[1] + -1;
    puVar2[1] = iVar3;
    UNLOCK();
    if (iVar3 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    iVar3 = in_stack_00000004[1] + -1;
    in_stack_00000004[1] = iVar3;
    UNLOCK();
    if ((iVar3 == 0) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  if (in_stack_0000000c != (undefined4 *)0x0) {
    LOCK();
    piVar1 = in_stack_0000000c + 1;
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar3 == 1) && (in_stack_0000000c != (undefined4 *)0x0)) {
      (**(code **)*in_stack_0000000c)(1);
    }
  }
  return 1;
}

