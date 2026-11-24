
void FUN_00508910(int param_1)

{
  int iVar1;
  int this;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar2 = (this->i_14 - this->i_0c) + -6;
  iVar1 = (this->i_18 - this->i_10) + -7;
  if (this->i_74 != 0) {
    local_18 = *(int *)(param_1 + 8) + 4;
    local_10 = *(int *)(param_1 + 8) + 4 + iVar2;
    local_14 = *(int *)(param_1 + 0xc) + iVar1;
    local_c = local_14 + 6;
    FUN_004ff430(&local_18,(int *)(this + 0x74));
  }
  if ((this->i_70 != 0) && (0 < this->i_6c)) {
    local_18 = *(int *)(param_1 + 8) + 4;
    local_10 = (this->i_6c * iVar2) / 100 + *(int *)(param_1 + 8) + 4;
    local_14 = *(int *)(param_1 + 0xc) + iVar1;
    local_c = local_14 + 6;
    FUN_004ff430(&local_18,this + 0x70);
  }
  FUN_005085c0(param_1);
  return;
}

