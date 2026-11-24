
CActWalk_AutoRetry * __thiscall FUN_00407f30(CActWalk_AutoRetry *this)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  byte in_stack_00000004;
  
  *(undefined ***)this = CActWalk_AutoRetry::vftable;
  if ((undefined4 *)this->i_20 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)this->i_20)(1);
  }
  this->i_20 = 0;
  *(undefined ***)this = CSubWalk::vftable;
  puVar2 = *(undefined4 **)&this->field_0x10;
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    iVar3 = puVar2[1] + -1;
    puVar2[1] = iVar3;
    UNLOCK();
    if (iVar3 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  puVar2 = (undefined4 *)this->i_0c;
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = puVar2 + 1;
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      (**(code **)*puVar2)(1);
    }
  }
  *(undefined ***)this = CSubAction::vftable;
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x24);
  }
  return this;
}

