
int FUN_00505dd0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int this;
  uint uVar3;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if ((((this->c_1c == '\0') || (this->c_2c == '\0')) ||
      (iVar1 = FUN_00501450(), (this->i_28 & *(uint *)(iVar1 + 0x101f8)) == 0)) ||
     (((FUN_00504c80(&local_18), param_1 < local_18 || (local_10 <= param_1)) ||
      ((param_2 < local_14 || (local_c <= param_2)))))) {
    return 0;
  }
  iVar1 = this->i_3c;
  uVar3 = 0;
  if (0 < iVar1) {
    do {
      if (this->i_3c <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar2 = (**(code **)(**(int **)(this->i_38 + uVar3 * 4) + 0x34))(param_1,param_2)
      ;
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < iVar1);
  }
  return this;
}

