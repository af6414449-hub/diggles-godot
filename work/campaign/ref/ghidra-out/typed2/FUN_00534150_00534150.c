
undefined1 __thiscall FUN_00534150(ViWinScrollField *this)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 *in_stack_00000004;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00701abd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (in_stack_00000004[2] == DAT_007723e8) {
    if ((in_stack_00000004[6] == this->i_50) || (in_stack_00000004[6] == this->i_4c)) {
      FUN_005340b0(DAT_0076700c ^ (uint)&stack0xfffffffc);
      FUN_00533bb0();
    }
    if ((ViWinScrollField *)in_stack_00000004[6] == this) {
      FUN_00533d10();
      uVar2 = 1;
      goto LAB_00534212;
    }
  }
  else {
    if (in_stack_00000004[2] != DAT_007723ac) {
LAB_00534210:
      uVar2 = 0;
      goto LAB_00534212;
    }
    iVar1 = this->i_44;
    if ((in_stack_00000004[6] == iVar1) && (iVar1 != 0)) {
      local_18 = -*(int *)(iVar1 + 100);
      local_14 = *(int *)(this->i_50 + 0x10);
    }
    else {
      iVar1 = this->i_48;
      if ((in_stack_00000004[6] != iVar1) || (iVar1 == 0)) goto LAB_00534210;
      local_18 = *(int *)(this->i_50 + 0xc);
      local_14 = -*(int *)(iVar1 + 0x68);
    }
    FUN_00504a70(&local_18);
  }
  uVar2 = 1;
LAB_00534212:
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

