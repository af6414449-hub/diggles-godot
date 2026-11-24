
void FUN_0054d4a0(undefined4 param_1)

{
  int iVar1;
  int this;
  int iVar2;
  undefined4 extraout_ECX;
  
  iVar2 = (this->i_14 - this->i_0c) + -0x14;
  iVar1 = (this->i_18 - this->i_10) + -0x14;
  if ((((this->i_1c4 != 10) || (this->i_1c8 != 10)) ||
      (iVar2 != this->i_1cc)) || (iVar1 != this->i_1d0)) {
    this->i_1c4 = 10;
    this->i_1c8 = 10;
    this->i_1cc = iVar2;
    this->i_1d0 = iVar1;
    FUN_00514f90(iVar2);
  }
  FUN_00504fd0(param_1);
  FUN_00514f90(extraout_ECX);
  FUN_00513f00(param_1);
  return;
}

