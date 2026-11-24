
CAct_Fall * __thiscall FUN_0040edb0(CAct_Fall *this)

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
  *(undefined ***)this = CAct_Fall::vftable;
  local_8 = 0;
  _eh_vector_destructor_iterator_(&this->field_0x40,4,3,FUN_006b8ed0);
  FUN_004065c0(uVar1);
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x68);
  }
  ExceptionList = local_10;
  return this;
}

