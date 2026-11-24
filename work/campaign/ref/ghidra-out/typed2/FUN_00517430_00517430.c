
undefined1 __thiscall FUN_00517430(ViWinLayoutCC_WorkClock *this)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 *in_stack_00000004;
  
  if (in_stack_00000004[2] == DAT_007723b8) {
    FUN_00517370();
    uVar3 = 1;
  }
  else {
    piVar1 = in_stack_00000004 + 1;
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (in_stack_00000004[2] == DAT_007723ec) {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = iVar2 + -1;
        UNLOCK();
        if (iVar2 + -1 == 0) {
          (**(code **)*in_stack_00000004)(1);
        }
      }
    }
    else {
      if (in_stack_00000004[2] != DAT_007723e8) {
        if (in_stack_00000004 != (undefined4 *)0x0) {
          LOCK();
          iVar2 = *piVar1;
          *piVar1 = iVar2 + -1;
          UNLOCK();
          if (iVar2 + -1 == 0) {
            (**(code **)*in_stack_00000004)(1);
          }
        }
        uVar3 = 0;
        goto LAB_005174ac;
      }
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = iVar2 + -1;
        UNLOCK();
        if (iVar2 + -1 == 0) {
          (**(code **)*in_stack_00000004)(1);
          uVar3 = 1;
          goto LAB_005174ac;
        }
      }
    }
    uVar3 = 1;
  }
LAB_005174ac:
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

