
ViWinSimpleFinder * __thiscall FUN_005342d0(ViWinSimpleFinder *this)

{
  uint uVar1;
  undefined4 extraout_ECX;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00702f00;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ViWinSimpleFinder::vftable;
  local_8 = 0;
  FUN_004fede0(uVar1);
  local_8 = 1;
  FUN_004fede0();
  local_8 = 2;
  FUN_00538510(extraout_ECX);
  if (this->i_74 != 0) {
    FUN_006ba940();
  }
  local_8 = 3;
  FUN_0040b980(0);
  if (this->i_6c != 0) {
    FUN_006ba940();
  }
  local_8 = 4;
  FUN_0040b980(0);
  if (*(int *)&this->field_0x5c != 0) {
    FUN_006ba940();
  }
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,200);
  }
  ExceptionList = local_10;
  return this;
}

