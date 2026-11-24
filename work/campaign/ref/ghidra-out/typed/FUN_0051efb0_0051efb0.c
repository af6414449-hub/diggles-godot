
undefined1 __thiscall FUN_0051efb0(ViWinOverlayMsg *this)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 *in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0070150d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((in_stack_00000004[2] == DAT_007723b8) && (in_stack_00000004[0x10] == 1)) {
    FUN_0051ee20(DAT_0076700c ^ (uint)&stack0xfffffffc);
  }
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
      goto LAB_0051f05e;
    }
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      iVar2 = in_stack_00000004[1] + -1;
      in_stack_00000004[1] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)*in_stack_00000004)(1);
        uVar3 = 1;
        goto LAB_0051f05e;
      }
    }
  }
  uVar3 = 1;
LAB_0051f05e:
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
  ExceptionList = local_10;
  return uVar3;
}

