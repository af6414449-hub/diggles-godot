
CAct_Lore * __thiscall FUN_004127a0(CAct_Lore *this)

{
  uint uVar1;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9c40;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = CAct_Lore::vftable;
  local_8 = 0;
  FUN_00415250(0);
  if (*(int *)(this + 1) != 0) {
    FUN_006ba940(uVar1);
  }
  local_8 = 1;
  FUN_00415170(0);
  if (this->i_24 != 0) {
    FUN_006ba940(uVar1);
  }
  FUN_004065c0();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x34);
  }
  ExceptionList = local_10;
  return this;
}

