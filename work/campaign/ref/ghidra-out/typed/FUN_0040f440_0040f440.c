
undefined4 __thiscall FUN_0040f440(CAct_Fall *this)

{
  char cVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  float local_14;
  float local_10;
  float local_c;
  
  iVar2 = this->i_0c;
  cVar1 = FUN_004097b0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10),
                       *(undefined4 *)(iVar2 + 0x14));
  if (cVar1 == '\0') {
    this->c_5c = '\x01';
  }
  else if (this->c_5c == '\0') {
    FUN_0040f260();
    iVar2 = this->i_0c;
    local_14 = *(float *)(iVar2 + 0xc) + 0.0;
    local_10 = this->f_58 + *(float *)(iVar2 + 0x10);
    local_c = *(float *)(iVar2 + 0x14) + 0.0;
    if (((*(float *)(iVar2 + 0xc) == local_14) && (*(float *)(iVar2 + 0x10) == local_10)) &&
       (*(float *)(iVar2 + 0x14) == local_c)) {
      return 1;
    }
    FUN_005cd8e0(&local_14);
    if (*(int *)(iVar2 + 0x238) != 0) {
      return 1;
    }
    FUN_005ebc90(iVar2);
    FUN_005eb470(iVar2);
    return 1;
  }
  dVar4 = this->d_60;
  dVar3 = 0.0;
  iVar2 = DAT_00772400;
  if (dVar4 == 0.0) {
    if ((this->i_1c != -1) && (this->i_20 != -1)) {
      FUN_006b49b0(this->i_0c,this->i_28,this->i_2c,0,1);
    }
    iVar2 = DAT_00772400;
    dVar4 = *(double *)(DAT_00772400 + 0xa088) + dVar3;
    this->d_60 = dVar4;
  }
  if (*(double *)(iVar2 + 0xa088) <= dVar4) {
    return 1;
  }
  return 0;
}

