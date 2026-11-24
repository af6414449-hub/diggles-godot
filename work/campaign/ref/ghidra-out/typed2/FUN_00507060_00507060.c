
undefined1 __thiscall FUN_00507060(ViWinBar *this)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 *in_stack_00000004;
  
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    in_stack_00000004[1] = in_stack_00000004[1] + 1;
    UNLOCK();
  }
  if (in_stack_00000004[2] == DAT_007723ec) {
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      iVar2 = in_stack_00000004[1] + -1;
      in_stack_00000004[1] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)*in_stack_00000004)(1);
      }
    }
  }
  else {
    if (in_stack_00000004[2] != DAT_007723e8) {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar2 = in_stack_00000004[1] + -1;
        in_stack_00000004[1] = iVar2;
        UNLOCK();
        if (iVar2 == 0) {
          (**(code **)*in_stack_00000004)(1);
        }
      }
      uVar3 = 0;
      goto LAB_005070cb;
    }
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      iVar2 = in_stack_00000004[1] + -1;
      in_stack_00000004[1] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)*in_stack_00000004)(1);
        uVar3 = 1;
        goto LAB_005070cb;
      }
    }
  }
  uVar3 = 1;
LAB_005070cb:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = in_stack_00000004 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar2 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  return uVar3;
}

