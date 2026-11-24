
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CVectorBuffer * __thiscall FUN_0045fb50(CVectorBuffer *this)

{
  uint uVar1;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9400;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *this = (CVectorBuffer)CVectorBuffer::vftable;
  if ((this[10] != (CVectorBuffer)0x0) && (this[2].field_0x1 == '\0')) {
    DAT_0076a2f0 = DAT_0076a2f0 + (int)this[0xb] * -2;
    FUN_006ba940(uVar1);
  }
  FUN_0045fc60();
  _DAT_0076a2f4 = _DAT_0076a2f4 + -1;
  this[10] = (CVectorBuffer)0x0;
  this[0xb] = (CVectorBuffer)0x0;
  *(undefined2 *)(this + 2) = 0;
  this[3] = (CVectorBuffer)0x0;
  this[9] = (CVectorBuffer)0x0;
  this[8] = (CVectorBuffer)0x1c2;
  *this = (CVectorBuffer)KRefCountedObj::vftable;
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x38);
  }
  ExceptionList = local_10;
  return this;
}

