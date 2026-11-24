
undefined1 __thiscall FUN_00505d60(ViWin *this)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 *in_stack_00000004;
  
  if ((in_stack_00000004[2] == DAT_007723ec) || (in_stack_00000004[2] == DAT_007723e8)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  LOCK();
  iVar1 = in_stack_00000004[1] + -1;
  in_stack_00000004[1] = iVar1;
  UNLOCK();
  if ((iVar1 == 0) && (in_stack_00000004 != (undefined4 *)0x0)) {
    (**(code **)*in_stack_00000004)(1);
  }
  return uVar2;
}

