
void FUN_00516530(byte param_1)

{
  uint uVar1;
  int this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9360;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00444ea0(0);
  if (this->i_44 != 0) {
    FUN_006ba940(uVar1);
  }
  FUN_00504770();
  if ((param_1 & 1) != 0) {
    FUN_006cecd8();
  }
  ExceptionList = local_10;
  return;
}

