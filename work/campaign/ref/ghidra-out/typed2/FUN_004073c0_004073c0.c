
CActWalk * __thiscall FUN_004073c0(CActWalk *this)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  CActWalk *pCVar4;
  byte in_stack_00000004;
  
  *(undefined ***)this = CActWalk::vftable;
  if (this->i_24 == 2) {
    pcVar2 = (code *)swi(3);
    pCVar4 = (CActWalk *)(*pcVar2)();
    return pCVar4;
  }
  if ((undefined4 *)this->i_20 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)this->i_20)(1);
    this->i_20 = 0;
  }
  puVar1 = (undefined4 *)this->i_1c;
  if (puVar1 != (undefined4 *)0x0) {
    LOCK();
    iVar3 = puVar1[1] + -1;
    puVar1[1] = iVar3;
    UNLOCK();
    if (iVar3 == 0) {
      (**(code **)*puVar1)(1);
    }
  }
  FUN_004065c0();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x28);
  }
  return this;
}

