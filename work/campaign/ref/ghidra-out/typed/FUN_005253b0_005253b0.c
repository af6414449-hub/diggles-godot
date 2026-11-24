
ViWinProperties * __thiscall FUN_005253b0(ViWinProperties *this)

{
  int iVar1;
  byte in_stack_00000004;
  
  iVar1 = this->i_44;
  *(undefined ***)this = ViWinProperties::vftable;
  if (iVar1 != 0) {
    FUN_004eff10();
    FUN_006cecd8(iVar1,0x114);
  }
  FUN_005266f0();
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x60);
  }
  return this;
}

