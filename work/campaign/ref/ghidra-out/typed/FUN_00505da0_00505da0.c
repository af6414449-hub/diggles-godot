
uint __thiscall FUN_00505da0(ViWin *this)

{
  uint *puVar1;
  uint uVar2;
  uint in_EAX;
  undefined4 *in_stack_00000004;
  
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    puVar1 = in_stack_00000004 + 1;
    uVar2 = *puVar1;
    in_EAX = *puVar1;
    *puVar1 = uVar2 - 1;
    UNLOCK();
    if ((uVar2 - 1 == 0) && (in_stack_00000004 != (undefined4 *)0x0)) {
      in_EAX = (**(code **)*in_stack_00000004)(1);
    }
  }
  return in_EAX & 0xffffff00;
}

