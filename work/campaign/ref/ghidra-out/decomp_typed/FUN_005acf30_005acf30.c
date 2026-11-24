
void FUN_005acf30(byte param_1)

{
  undefined4 *this;
  
  *this = KNetMsg::vftable;
  if (this->c_02 != '\0') {
    thunk_FUN_0060fc30(this[10]);
  }
  this[10] = 0;
  this[9] = 0;
  this->c_02 = 0;
  *this = KRefCountedObj::vftable;
  if ((param_1 & 1) != 0) {
    FUN_006cecd8();
  }
  return;
}

