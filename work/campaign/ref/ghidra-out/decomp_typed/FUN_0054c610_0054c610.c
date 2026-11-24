
undefined1 FUN_0054c610(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int this;
  undefined1 uVar3;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00701abd;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((param_1[2] == DAT_00772388) && (param_1[6] == this->i_54)) {
    this->c_2d = 1;
    iVar2 = FUN_00501450(uVar1);
    if ((*(int *)(iVar2 + 0x81a0) != 0) && (*(int *)(iVar2 + 0x81a0) == this)) {
      iVar2 = FUN_00501450();
      uVar3 = 1;
      *(undefined4 *)(iVar2 + 0x81a0) = 0;
      goto LAB_0054c6e2;
    }
  }
  else {
    if ((param_1[2] != DAT_007723e8) || (param_1[6] != this)) {
      uVar3 = 0;
      goto LAB_0054c6e2;
    }
    if (this->i_50 != 0) {
      local_18 = (this->i_14 - this->i_0c) + -10;
      local_14 = (this->i_18 - this->i_10) + -10;
      FUN_00504ba0(&local_18);
      local_18 = (this->i_14 - this->i_0c) + 0x3c;
      local_14 = 0x12;
      FUN_00504ba0(&local_18);
    }
  }
  uVar3 = 1;
LAB_0054c6e2:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar2 = param_1[1] + -1;
    param_1[1] = iVar2;
    UNLOCK();
    if ((iVar2 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return uVar3;
}

