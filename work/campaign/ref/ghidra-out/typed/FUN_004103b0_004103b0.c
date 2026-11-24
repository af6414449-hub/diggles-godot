
bool __thiscall FUN_004103b0(CAct_Fly *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar4 = this->i_0c;
  this->i_50 = this->i_50 + 1;
  local_18 = *(float *)(iVar4 + 0xc);
  this->f_34 = local_18;
  local_1c = *(float *)(iVar4 + 0x10);
  this->f_38 = local_1c;
  local_14 = *(float *)(iVar4 + 0x14);
  this->f_3c = local_14;
  local_18 = this->f_1c - local_18;
  local_1c = this->f_20 - local_1c;
  local_14 = this->f_24 - local_14;
  fVar1 = local_1c * local_1c + local_18 * local_18 + local_14 * local_14;
  FUN_0040b7e0();
  local_38 = 0.0;
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
    fVar2 = 0.0;
  }
  else {
    local_38 = local_18 / fVar1;
    fVar2 = local_1c / fVar1;
    fVar1 = local_14 / fVar1;
  }
  local_38 = local_38 * 0.05;
  fVar2 = fVar2 * 0.05;
  local_30 = fVar1 * 0.05;
  local_34 = fVar2;
  local_28 = local_30;
  local_24 = local_38;
  local_10 = fVar2;
  FUN_00410940();
  local_2c = fVar2;
  FUN_0040fa20();
  fVar3 = this->f_40 + fVar2;
  this->f_40 = fVar3;
  local_20 = fVar3;
  local_8 = fVar2;
  FUN_004089f0();
  fVar1 = local_20;
  local_c = fVar3;
  FUN_004089d0();
  this->f_30 = fVar1 * 0.05;
  if (this->c_54 != '\0') {
    fVar2 = 0.2;
    if (local_10 * 0.25 <= 0.2) {
      fVar2 = local_10 * 0.25;
    }
    this->f_28 = local_c * 0.05;
    this->f_2c = fVar2;
    iVar4 = this->i_0c;
    local_38 = local_24 * 0.2 + local_c * 0.05 * 0.8 + this->f_34;
    local_34 = local_10 * 0.2 + fVar2 * 0.8 + this->f_38;
    local_30 = local_28 * 0.2 + fVar1 * 0.05 * 0.8 + this->f_3c;
    if ((((*(float *)(iVar4 + 0xc) != local_38) || (*(float *)(iVar4 + 0x10) != local_34)) ||
        (*(float *)(iVar4 + 0x14) != local_30)) &&
       (FUN_005cd8e0(&local_38), *(int *)(iVar4 + 0x238) == 0)) {
      FUN_005ebc90(iVar4);
      FUN_005eb470(iVar4);
    }
    local_34 = this->f_40 - 3.1415927;
    local_38 = 0.0;
    local_30 = 0.0;
    FUN_005cd840(&local_38);
    return this->i_50 < 0x33;
  }
  fVar1 = local_c * 0.05;
  local_c = (float)((uint)local_c & 0xffffff00);
  this->f_28 = fVar1;
  this->f_2c = local_10;
  fVar1 = local_10;
  FUN_00410940();
  local_28 = fVar1;
  FUN_00423a90();
  if (0.7853982 <= fVar1) {
    local_c = (float)((uint)local_c & 0xff);
    if (this->c_4c != '\0') {
      local_c = 1.4013e-45;
    }
  }
  else {
    fVar1 = ABS(local_18);
    if (ABS(local_18) <= ABS(local_1c)) {
      fVar1 = ABS(local_1c);
    }
    if (fVar1 <= ABS(local_14)) {
      fVar1 = ABS(local_14);
    }
    this->c_4c = '\x01';
    fVar2 = 1.0;
    if (1.0 <= fVar1 / 0.05) {
      fVar2 = fVar1 / 0.05;
    }
    this->f_28 = local_18 / fVar2;
    this->f_2c = local_1c / fVar2;
    this->f_30 = local_14 / fVar2;
  }
  local_2c = (float)this->i_0c;
  fVar1 = this->f_48 * 0.7 + this->f_2c * 0.3;
  this->f_48 = fVar1;
  this->f_2c = fVar1;
  local_38 = this->f_28 + this->f_34;
  local_34 = this->f_2c + this->f_38;
  local_30 = this->f_30 + this->f_3c;
  if ((((*(float *)((int)local_2c + 0xc) != local_38) ||
       (*(float *)((int)local_2c + 0x10) != local_34)) ||
      (*(float *)((int)local_2c + 0x14) != local_30)) &&
     (FUN_005cd8e0(&local_38), *(int *)((int)local_2c + 0x238) == 0)) {
    fVar1 = local_2c;
    FUN_005ebc90(local_2c);
    FUN_005eb470(fVar1);
  }
  local_38 = 0.0;
  fVar1 = this->f_44 * 0.3;
  local_8 = local_8 * -10.0 * 0.7 + fVar1;
  this->f_44 = local_8;
  FUN_00410940();
  local_34 = fVar1 + 1.5707964;
  local_30 = local_8 * 0.5;
  FUN_005cd840(&local_38);
  iVar4 = this->i_0c;
  fVar3 = *(float *)(iVar4 + 0x10) - this->f_20;
  fVar2 = *(float *)(iVar4 + 0xc) - this->f_1c;
  fVar1 = *(float *)(iVar4 + 0x14) - this->f_24;
  if (((0.0001 <= fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1) && (local_c._0_1_ == '\0')) &&
     (this->i_50 < 0x33)) {
    return true;
  }
  return false;
}

