
void __thiscall FUN_00538d60(ViWinSlider *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *in_stack_00000004;
  int local_30;
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (this->c_60 == '\0') {
    local_30 = *(int *)(in_stack_00000004[1] + 8);
  }
  else {
    local_30 = *(int *)(in_stack_00000004[1] + 0x28);
  }
  if (*(int *)(*in_stack_00000004 + 8) != 0) {
    FUN_004ff430(*in_stack_00000004 + 0xc,&local_30);
  }
  local_30 = this->i_18 - this->i_10;
  local_2c = this->i_24;
  iVar4 = this->i_14 - this->i_0c;
  iVar2 = iVar4;
  if ((local_2c & 1) == 0) {
    this->i_44 = iVar4;
  }
  else if ((local_2c & 4) == 0) {
    this->i_44 = this->i_7c;
    iVar2 = this->i_7c;
  }
  else {
    iVar1 = (this->i_7c * iVar4) / (this->i_74 - this->i_6c);
    iVar3 = iVar4;
    if (iVar1 <= iVar4) {
      iVar3 = iVar1;
    }
    if (iVar3 < 10) {
      this->i_7c = 10;
      this->i_44 = 10;
      iVar2 = 10;
    }
    else {
      if (iVar1 <= iVar4) {
        iVar2 = iVar1;
      }
      this->i_7c = iVar2;
      this->i_44 = iVar2;
    }
  }
  if ((local_2c & 2) == 0) {
    this->i_48 = local_30;
  }
  else if ((local_2c & 4) == 0) {
    this->i_48 = this->i_80;
  }
  else {
    iVar1 = (this->i_80 * local_30) / (this->i_78 - this->i_70);
    iVar3 = local_30;
    if (iVar1 <= local_30) {
      iVar3 = iVar1;
    }
    if (iVar3 < 10) {
      this->i_80 = 10;
      this->i_48 = 10;
    }
    else {
      iVar3 = local_30;
      if (iVar1 <= local_30) {
        iVar3 = iVar1;
      }
      this->i_80 = iVar3;
      this->i_48 = iVar3;
    }
  }
  if (iVar2 < iVar4) {
    local_2c = this->i_74 - this->i_6c;
    if (local_2c == 0) goto LAB_00538e9c;
    iVar2 = ((this->i_64 - this->i_6c) * (iVar4 - iVar2)) / (int)local_2c;
  }
  else {
LAB_00538e9c:
    iVar2 = 0;
  }
  this->i_4c = iVar2;
  local_c = this->i_48;
  if (local_c < local_30) {
    iVar2 = this->i_78 - this->i_70;
    if (iVar2 != 0) {
      iVar2 = ((this->i_68 - this->i_70) * (local_30 - local_c)) / iVar2;
      goto LAB_00538ec3;
    }
  }
  iVar2 = 0;
LAB_00538ec3:
  this->i_50 = iVar2;
  if ((0 < local_c) && (0 < this->i_44)) {
    local_18 = this->i_4c;
    local_14 = this->i_50;
    local_c = local_c + local_14;
    local_10 = local_18 + this->i_44;
    local_28 = local_18 + in_stack_00000004[2];
    local_20 = local_10 + in_stack_00000004[2];
    local_24 = in_stack_00000004[3] + local_14;
    local_1c = local_c + in_stack_00000004[3];
    FUN_004ff430(&local_28,in_stack_00000004[1] + 0x18);
    FUN_004fdd70(&local_18,in_stack_00000004[1] + 0x18,0);
  }
  return;
}

