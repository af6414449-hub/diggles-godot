
CAct_Move * __thiscall FUN_004166f0(CAct_Move *this)

{
  byte in_stack_00000004;
  
  *(undefined ***)this = CAct_Move::vftable;
  this->i_0c = 0;
  FUN_004065c0();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x44);
  }
  return this;
}

