
ViWinFinder * __thiscall FUN_0050f090(ViWinFinder *this)

{
  byte in_stack_00000004;
  
  *(undefined ***)this = ViWinFinder::vftable;
  if (*(int *)&this->field_0x50 != 0) {
    FUN_004f4d00(*(int *)&this->field_0x50);
  }
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x5c);
  }
  return this;
}

