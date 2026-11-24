
void FUN_0050fcb0(int *param_1)

{
  int this;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_1c = *(undefined4 *)param_1[1];
  if (*(int *)(*param_1 + 8) != 0) {
    FUN_004ff430(*param_1 + 0xc,&local_1c);
  }
  iVar2 = 0;
  local_c = this->i_18 - this->i_10;
  local_10 = this->i_14 - this->i_0c;
  if (0 < this->i_50) {
    do {
      iVar3 = local_10 + -1;
      iVar1 = local_c + -1;
      local_18 = iVar2;
      local_14 = iVar2;
      FUN_004fdd70(&local_18,param_1[1] + 8,this->c_4c);
      iVar2 = iVar2 + 1;
      local_c = iVar1;
      local_10 = iVar3;
    } while (iVar2 < this->i_50);
  }
  return;
}

