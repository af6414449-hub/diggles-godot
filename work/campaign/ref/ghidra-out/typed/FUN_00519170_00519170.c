
ViWinNewsTicker * __thiscall FUN_00519170(ViWinNewsTicker *this)

{
  uint uVar1;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fbb60;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ViWinNewsTicker::vftable;
  local_8 = 0;
  FUN_0051bc40(0);
  if (this->i_74 != 0) {
    FUN_006ba940(uVar1);
  }
  local_8 = 1;
  FUN_0051bcb0(0);
  if (this->i_60 != 0) {
    FUN_006ba940(uVar1);
  }
  local_8 = 2;
  FUN_0051bfb0(0);
  if (this->i_58 != 0) {
    FUN_006ba940();
  }
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x8c);
  }
  ExceptionList = local_10;
  return this;
}

