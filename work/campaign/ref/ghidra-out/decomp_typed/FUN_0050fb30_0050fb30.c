
void FUN_0050fb30(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int this;
  int local_10;
  int local_c;
  
  if (param_1 != 0) {
    FUN_00504ce0(this);
  }
  this->i_44 = param_2;
  if ((DAT_00767988 == param_3) && (DAT_0076798c == param_4)) {
    local_10 = *(int *)(param_2 + 0xc) - this->i_48;
    local_c = *(int *)(param_2 + 0x10) - this->i_48;
    piVar2 = &local_10;
  }
  else {
    piVar2 = &param_3;
  }
  FUN_00504a70(piVar2);
  local_10 = this->i_48;
  local_c = local_10;
  FUN_00504a70(&local_10);
  if ((DAT_00767988 == param_5) && (DAT_0076798c == param_6)) {
    iVar1 = this->i_44;
    local_c = this->i_48 * 2;
    local_10 = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + local_c;
    local_c = (*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x10)) + local_c;
    FUN_00504ba0(&local_10);
    return;
  }
  FUN_00504ba0(&param_5);
  iVar1 = this->i_44;
  local_10 = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + this->i_48 * -2;
  local_c = (*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x10)) + this->i_48 * -2;
  FUN_00504ba0(&local_10);
  return;
}

