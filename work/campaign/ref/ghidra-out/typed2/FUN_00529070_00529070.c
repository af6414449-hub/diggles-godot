
void __thiscall FUN_00529070(ViWinRoot *this)

{
  int iVar1;
  int local_10;
  int local_c;
  
  FUN_00504ba0(&local_10);
  if (*(char *)(DAT_00772400 + 0x590) == '\0') {
    local_10 = (this->i_14 - this->i_0c) + -0x96;
    local_c = (this->i_18 - this->i_10) + -0x98;
    FUN_00504a70(&local_10);
    local_10 = (this->i_14 - this->i_0c) / 2 + -300;
    local_c = (this->i_18 - this->i_10) / 2 + -200;
    FUN_00504a70(&local_10);
    local_10 = 600;
    local_c = 400;
    FUN_00504ba0(&local_10);
    local_c = 0x1e;
    local_10 = ((this->i_14 - this->i_0c) + -600) / 2;
    FUN_00504a70(&local_10);
    local_c = (this->i_18 - this->i_10) + -0x8c;
    local_10 = 600;
    FUN_00504ba0(&local_10);
    iVar1 = this->i_14 - this->i_0c;
    local_c = 0;
    local_10 = iVar1 + -0x118;
    FUN_00504a70(&local_10);
    local_10 = iVar1 + -0x109;
    local_c = 0x11;
    FUN_00504a70(&local_10);
    local_10 = iVar1 + -0xaa;
    local_c = 0;
    FUN_00504a70(&local_10);
    local_10 = iVar1 + -0x50;
    local_c = 0x11;
    FUN_00504a70(&local_10);
    local_10 = iVar1 + -0x1cc;
    local_c = 0x1c;
    FUN_00504ba0(&local_10);
    (**(code **)(*(int *)this->i_dc + 0x38))();
    local_c = 0;
    local_10 = ((this->i_14 - *(int *)(this->i_b8 + 0x14)) - this->i_0c) +
               *(int *)(this->i_b8 + 0xc);
    FUN_00504a70(&local_10);
    local_10 = this->i_14 - this->i_0c;
    local_c = 0x20;
    FUN_00504ba0(&local_10);
    local_c = (this->i_18 - this->i_10) + -0x20;
    local_10 = 0;
    FUN_00504a70(&local_10);
    local_10 = this->i_14 - this->i_0c;
    local_c = 0x20;
    FUN_00504ba0(&local_10);
    FUN_00527f40(this->i_14 - this->i_0c,this->i_18 - this->i_10);
  }
  local_c = (this->i_18 - this->i_10) + -400;
  local_10 = 5;
  FUN_00504a70(&local_10);
  FUN_00504ee0();
  return;
}

