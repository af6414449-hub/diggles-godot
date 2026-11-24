
void __thiscall FUN_00533550(ViWinScrollBar *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *in_stack_00000004;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_2c = *(int *)(in_stack_00000004[1] + 8);
  if (*(int *)(*in_stack_00000004 + 8) != 0) {
    FUN_004ff430(*in_stack_00000004 + 0xc,&local_2c);
  }
  iVar4 = this->i_14 - this->i_0c;
  iVar5 = this->i_18 - this->i_10;
  uVar1 = this->i_24;
  local_2c = iVar4;
  if ((uVar1 & 1) != 0) {
    iVar2 = (int)ROUND(((float)this->i_7c * (float)iVar4) /
                       (float)((this->i_74 - this->i_6c) + this->i_7c));
    DAT_00772dd8 = iVar2;
    this->i_44 = iVar2;
    if (iVar2 <= iVar4) {
      local_2c = iVar2;
    }
    if (local_2c < 5) {
      local_2c = 5;
    }
    uVar1 = this->i_24;
  }
  this->i_44 = local_2c;
  iVar2 = iVar5;
  if ((uVar1 & 2) != 0) {
    iVar2 = (this->i_80 * iVar5) / ((this->i_78 - this->i_70) + this->i_80);
    iVar3 = iVar5;
    if (iVar2 <= iVar5) {
      iVar3 = iVar2;
    }
    if (iVar3 < 5) {
      iVar2 = 5;
    }
    else if (iVar5 < iVar2) {
      iVar2 = iVar5;
    }
  }
  this->i_48 = iVar2;
  if (local_2c < iVar4) {
    iVar4 = ((this->i_64 - this->i_6c) * (iVar4 - local_2c)) / (this->i_74 - this->i_6c);
  }
  else {
    iVar4 = 0;
  }
  this->i_4c = iVar4;
  if (this->i_48 < iVar5) {
    iVar4 = ((this->i_68 - this->i_70) * (iVar5 - this->i_48)) / (this->i_78 - this->i_70);
  }
  else {
    iVar4 = 0;
  }
  this->i_50 = iVar4;
  local_18 = this->i_4c;
  local_10 = this->i_44 + local_18;
  local_14 = this->i_50;
  local_c = this->i_48 + local_14;
  local_28 = local_18 + in_stack_00000004[2];
  local_20 = in_stack_00000004[2] + local_10;
  local_24 = in_stack_00000004[3] + local_14;
  local_1c = in_stack_00000004[3] + local_c;
  FUN_004ff430(&local_28,in_stack_00000004[1] + 0x18);
  FUN_004fdd70(&local_18,in_stack_00000004[1] + 0x18,0);
  return;
}

