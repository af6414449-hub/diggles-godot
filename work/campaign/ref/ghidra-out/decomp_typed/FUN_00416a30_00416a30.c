
uint FUN_00416a30(void)

{
  uint uVar1;
  float fVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 uVar3;
  int this;
  int iVar4;
  float local_10;
  float local_c;
  float local_8;
  
  iVar4 = this->i_40;
  uVar1 = iVar4 - 1;
  this->i_40 = uVar1;
  if (iVar4 < 1) {
    return uVar1 & 0xffffff00;
  }
  iVar4 = this->i_0c;
  local_10 = this->f_34 + *(float *)(iVar4 + 0xc);
  fVar2 = *(float *)(iVar4 + 0x14);
  local_c = this->f_38 + *(float *)(iVar4 + 0x10);
  local_8 = this->f_3c + fVar2;
  if (((*(float *)(iVar4 + 0xc) != local_10) || (*(float *)(iVar4 + 0x10) != local_c)) ||
     (uVar3 = CONCAT21((short)(uVar1 >> 0x10),
                       (fVar2 == local_8) << 6 | (NAN(fVar2) || NAN(local_8)) << 2 | 2U |
                       fVar2 < local_8), fVar2 != local_8)) {
    FUN_005cd8e0(&local_10);
    uVar3 = extraout_var;
    if (*(int *)(iVar4 + 0x238) == 0) {
      FUN_005ebc90(iVar4);
      FUN_005eb470(iVar4);
      uVar3 = extraout_var_00;
    }
  }
  return CONCAT31(uVar3,1);
}

