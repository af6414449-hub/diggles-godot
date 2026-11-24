
CAct_Slide * __thiscall FUN_004177c0(CAct_Slide *this)

{
  undefined4 *puVar1;
  int iVar2;
  byte in_stack_00000004;
  
  *(undefined ***)this = CAct_Slide::vftable;
  puVar1 = (undefined4 *)this->i_1c;
  if (puVar1 != (undefined4 *)0x0) {
    LOCK();
    iVar2 = puVar1[1] + -1;
    puVar1[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*puVar1)(1);
    }
  }
  FUN_004065c0();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x28);
  }
  return this;
}

