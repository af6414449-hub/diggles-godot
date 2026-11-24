
int FUN_005236a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int this;
  
  iVar1 = FUN_00501450();
  if ((this->i_28 & *(uint *)(iVar1 + 0x101f8)) == 0) {
    return 0;
  }
  iVar1 = FUN_00505dd0(param_1,param_2);
  if (((this->i_2036c == 0) && (0x1e < param_1)) && (iVar1 == this)) {
    iVar1 = 0;
  }
  return iVar1;
}

