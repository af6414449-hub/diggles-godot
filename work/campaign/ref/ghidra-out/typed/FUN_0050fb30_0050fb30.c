
void __thiscall FUN_0050fb30(ViWinFrame *this)

{
  int iVar1;
  int *piVar2;
  int in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  int local_10;
  int local_c;
  
  if (in_stack_00000004 != 0) {
    FUN_00504ce0(this);
  }
  this->i_44 = in_stack_00000008;
  if ((DAT_00767988 == in_stack_0000000c) && (DAT_0076798c == in_stack_00000010)) {
    local_10 = *(int *)(in_stack_00000008 + 0xc) - this->i_48;
    local_c = *(int *)(in_stack_00000008 + 0x10) - this->i_48;
    piVar2 = &local_10;
  }
  else {
    piVar2 = &stack0x0000000c;
  }
  FUN_00504a70(piVar2);
  local_10 = this->i_48;
  local_c = local_10;
  FUN_00504a70(&local_10);
  if ((DAT_00767988 == in_stack_00000014) && (DAT_0076798c == in_stack_00000018)) {
    iVar1 = this->i_44;
    local_c = this->i_48 * 2;
    local_10 = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + local_c;
    local_c = (*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x10)) + local_c;
    FUN_00504ba0(&local_10);
    return;
  }
  FUN_00504ba0(&stack0x00000014);
  iVar1 = this->i_44;
  local_10 = (*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) + this->i_48 * -2;
  local_c = (*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x10)) + this->i_48 * -2;
  FUN_00504ba0(&local_10);
  return;
}

