
void FUN_00518210(void)

{
  int iVar1;
  int this;
  uint uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00700e80;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = FUN_006ba810(0x82,DAT_0076700c ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (local_14 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00538a70();
  }
  local_8 = 0xffffffff;
  this->i_48 = iVar1;
  uVar2 = *(uint *)(iVar1 + 0x24) | 2;
  if (uVar2 != *(uint *)(iVar1 + 0x24)) {
    *(uint *)(iVar1 + 0x24) = uVar2;
    FUN_00504ee0();
  }
  local_14 = this->i_18 - this->i_10;
  local_18 = 0x14;
  FUN_00504ba0(&local_18);
  local_18 = (this->i_14 - this->i_0c) + -0x14;
  local_14 = 0;
  FUN_00504a70(&local_18);
  local_20 = 0;
  local_18 = 0;
  local_1c = 0;
  local_14 = 100;
  FUN_00538c30(&local_20);
  local_18 = 0;
  local_14 = 0;
  FUN_00538b40(&local_18,1);
  iVar1 = this->i_48;
  if ((*(int *)(iVar1 + 0x7c) != 0) || (*(int *)(iVar1 + 0x80) != 10)) {
    *(undefined4 *)(iVar1 + 0x7c) = 0;
    *(undefined4 *)(iVar1 + 0x80) = 10;
    FUN_00504ee0();
    iVar1 = this->i_48;
  }
  FUN_00504ce0(iVar1);
  ExceptionList = local_10;
  return;
}

