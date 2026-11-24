
void FUN_0054cee0(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int this;
  int iVar5;
  int in_stack_ffffffd8;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  iVar5 = *(int *)(param_1[1] + 0x28);
  local_14 = *(undefined4 *)(param_1[1] + 0x2c);
  iVar2 = FUN_00501450();
  if ((*(int *)(iVar2 + 0x8198) == this) &&
     ((iVar2 = FUN_00501450(), *(int *)(iVar2 + 0x81a4) == 0 ||
      (iVar2 = FUN_00501450(), *(int *)(iVar2 + 0x81a4) == this)))) {
    iVar5 = *(int *)(param_1[1] + 0x34);
    local_14 = *(undefined4 *)(param_1[1] + 0x2c);
  }
  uVar1 = this->i_24;
  if ((uVar1 & 0x40) != 0) {
    local_14 = this->i_48;
  }
  if ((uVar1 & 0x1000000) != 0) {
    iVar5 = *(int *)(param_1[1] + 0x2c);
    local_14 = *(undefined4 *)(param_1[1] + 0x28);
  }
  if (((uVar1 & 0x10) == 0) && (local_10 = iVar5, *(int *)(*param_1 + 8) != 0)) {
    in_stack_ffffffd8 = *param_1 + 0xc;
    FUN_004ff430(in_stack_ffffffd8,&local_10);
  }
  iVar5 = this->i_20;
  iVar2 = 0x54cf81;
  piVar3 = (int *)FUN_004ef240();
  if (param_1[6] == *piVar3) {
    if (param_1[5] != 0) goto LAB_0054cfb2;
  }
  else {
    param_1[5] = 0;
    param_1[6] = *piVar3;
  }
  iVar2 = param_1[4] + 0xc;
  in_stack_ffffffd8 = 0x54cfad;
  iVar4 = FUN_004ef660(iVar2);
  param_1[5] = iVar4;
LAB_0054cfb2:
  FUN_004edf70(&local_10,iVar5 + 0xc,in_stack_ffffffd8,iVar2);
  uVar1 = this->i_24;
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = ((this->i_14 - this->i_0c) - local_10) + -1;
    }
  }
  else {
    iVar5 = ((this->i_14 - this->i_0c) - local_10) / 2;
  }
  if ((uVar1 & 4) == 0) {
    iVar2 = this->i_18 - this->i_10;
    if ((uVar1 & 8) == 0) {
      local_c = (local_c + iVar2) / 2;
    }
    else {
      local_c = iVar2 + -1;
    }
  }
  local_10 = param_1[2] + iVar5;
  local_c = param_1[3] + local_c;
  FUN_005002c0(&local_10,this->i_20 + 0xc,&local_14,param_1 + 4,
               this->i_44,iVar5);
  return;
}

