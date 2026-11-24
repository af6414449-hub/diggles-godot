
ViWinListCtrl * __thiscall FUN_00517e40(ViWinListCtrl *this)

{
  int iVar1;
  uint uVar2;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9360;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ViWinListCtrl::vftable;
  local_8 = 0;
  iVar1 = this->i_50;
  if (iVar1 < 0) {
    FUN_0042fc20(-iVar1);
  }
  else if (0 < iVar1) {
    FUN_00463b00(iVar1);
  }
  if (this->i_4c != 0) {
    FUN_006ba940(uVar2);
  }
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x58);
  }
  ExceptionList = local_10;
  return this;
}

