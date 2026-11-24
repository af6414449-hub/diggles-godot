
undefined1 __thiscall FUN_0054c610(ViWinTechTree *this)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 *in_stack_00000004;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00701abd;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((in_stack_00000004[2] == DAT_00772388) && (in_stack_00000004[6] == this->i_54)) {
    this->c_2d = '\x01';
    iVar2 = FUN_00501450(uVar1);
    if ((*(ViWinTechTree **)(iVar2 + 0x81a0) != (ViWinTechTree *)0x0) &&
       (*(ViWinTechTree **)(iVar2 + 0x81a0) == this)) {
      iVar2 = FUN_00501450();
      uVar3 = 1;
      *(undefined4 *)(iVar2 + 0x81a0) = 0;
      goto LAB_0054c6e2;
    }
  }
  else {
    if ((in_stack_00000004[2] != DAT_007723e8) || ((ViWinTechTree *)in_stack_00000004[6] != this)) {
      uVar3 = 0;
      goto LAB_0054c6e2;
    }
    if (this->i_50 != 0) {
      local_18 = (this->i_14 - this->i_0c) + -10;
      local_14 = (this->i_18 - this->i_10) + -10;
      FUN_00504ba0(&local_18);
      local_18 = (this->i_14 - this->i_0c) + 0x3c;
      local_14 = 0x12;
      FUN_00504ba0(&local_18);
    }
  }
  uVar3 = 1;
LAB_0054c6e2:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    iVar2 = in_stack_00000004[1] + -1;
    in_stack_00000004[1] = iVar2;
    UNLOCK();
    if ((iVar2 == 0) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar3;
}

