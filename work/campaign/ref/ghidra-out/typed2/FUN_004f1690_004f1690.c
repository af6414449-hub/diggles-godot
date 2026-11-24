
void __thiscall FUN_004f1690(ViWinFinder *this)

{
  int in_stack_00000004;
  undefined1 local_1c;
  undefined2 local_1b;
  undefined1 local_19;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_1b = 0x5050;
  local_1c = 0x50;
  local_18 = *(int *)(in_stack_00000004 + 8);
  local_10 = (this->i_14 - this->i_0c) + local_18;
  local_19 = 0x6e;
  local_14 = *(int *)(in_stack_00000004 + 0xc);
  local_c = (this->i_18 - this->i_10) + local_14;
  FUN_004ff430(&local_18,&local_1c);
  local_10 = this->i_14 - this->i_0c;
  local_c = this->i_18 - this->i_10;
  local_1b = 0x5050;
  local_1c = 0x50;
  local_19 = 200;
  local_18 = 0;
  local_14 = 0;
  FUN_004fdd70(&local_18,&local_1c,0);
  return;
}

