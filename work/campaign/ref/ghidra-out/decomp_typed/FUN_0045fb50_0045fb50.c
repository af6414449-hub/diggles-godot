
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045fb50(byte param_1)

{
  uint uVar1;
  undefined4 *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9400;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *this = CVectorBuffer::vftable;
  if ((this[10] != 0) && (*(char *)((int)this + 9) == '\0')) {
    DAT_0076a2f0 = DAT_0076a2f0 + this[0xb] * -2;
    FUN_006ba940(uVar1);
  }
  FUN_0045fc60();
  _DAT_0076a2f4 = _DAT_0076a2f4 + -1;
  this[10] = 0;
  this[0xb] = 0;
  this->s_02 = 0;
  this[3] = 0;
  this[9] = 0;
  this[8] = 0x1c2;
  *this = KRefCountedObj::vftable;
  if ((param_1 & 1) != 0) {
    FUN_006cecd8();
  }
  ExceptionList = local_10;
  return;
}

