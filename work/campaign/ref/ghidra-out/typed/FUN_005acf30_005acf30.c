
KNetMsg * __thiscall FUN_005acf30(KNetMsg *this)

{
  char cVar1;
  byte in_stack_00000004;
  
  cVar1 = this[2].c_02;
  *(undefined ***)this = KNetMsg::vftable;
  if (cVar1 != '\0') {
    thunk_FUN_0060fc30(*(undefined4 *)&this[0xd].field_0x1);
  }
  *(undefined4 *)&this[0xd].field_0x1 = 0;
  *(undefined4 *)(this + 0xc) = 0;
  this[2].c_02 = '\0';
  *(undefined ***)this = KRefCountedObj::vftable;
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x2c);
  }
  return this;
}

