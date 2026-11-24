
undefined1 __thiscall FUN_0054d3f0(ViWinTextWin *this)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 *in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fc57d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar1 = in_stack_00000004[2];
  if ((iVar1 != DAT_007723c4) && (iVar1 != DAT_007723cc)) {
    if (iVar1 != DAT_007723d0) {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        in_stack_00000004[1] = in_stack_00000004[1] + 1;
        UNLOCK();
      }
      uVar2 = FUN_005145b0((ViWinLayout *)this);
      goto LAB_0054d452;
    }
    if (this->c_1c != '\0') {
      FUN_00504ee0(DAT_0076700c ^ (uint)&stack0xfffffffc);
      this->c_1c = '\0';
    }
  }
  uVar2 = 1;
LAB_0054d452:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    iVar1 = in_stack_00000004[1] + -1;
    in_stack_00000004[1] = iVar1;
    UNLOCK();
    if ((iVar1 == 0) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar2;
}

