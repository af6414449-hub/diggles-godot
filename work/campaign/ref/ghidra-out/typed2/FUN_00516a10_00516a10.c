
undefined1 __thiscall FUN_00516a10(ViWinLayoutCC_Attribbar *this)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined4 *in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0070150d;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (in_stack_00000004[2] == DAT_007723b8) {
    FUN_00516730();
    uVar4 = 1;
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
            (**(code **)*in_stack_00000004)(1,uVar3);
          }
        }
        uVar4 = 0;
        goto LAB_00516ab2;
      }
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = iVar2 + -1;
        UNLOCK();
        if (iVar2 + -1 == 0) {
          (**(code **)*in_stack_00000004)(1);
          uVar4 = 1;
          goto LAB_00516ab2;
        }
      }
    }
    uVar4 = 1;
  }
LAB_00516ab2:
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
  return uVar4;
}

