
undefined4 FUN_00408e50(void)

{
  char cVar1;
  int this;
  int extraout_EDX;
  int iVar2;
  float fVar3;
  double dVar4;
  float local_10;
  float local_c;
  float local_8;
  
  if (this->c_51 == '\0') {
    dVar4 = *(double *)(DAT_00772400 + 0xa088);
    if ((this->d_40 <= dVar4 && dVar4 != this->d_40) ||
       (this->c_50 != '\0')) {
      cVar1 = FUN_00408fc0();
      if (cVar1 == '\0') {
        return 0;
      }
    }
    else {
      if (this->i_4c == 3) {
        if ((*(uint *)(this->i_0c + 0x3d0) & 0x10000000) == 0) {
          FUN_005daff0("atr_Hitpoints");
        }
        fVar3 = SUB84(dVar4,0);
        if ((this->c_53 != '\0') && (FUN_005dae40("atr_Hitpoints"), fVar3 < 0.01)) {
          *(undefined1 *)(this->i_0c + 0x2b6) = 1;
        }
        if (this->c_48 != '\0') {
          FUN_005d8660(1,5);
        }
        if (this->c_49 != '\0') {
          FUN_005d8660(2,5);
        }
      }
      iVar2 = this->i_4c;
      if (((this->i_60 <= iVar2) && (iVar2 <= this->i_64)) &&
         (cVar1 = FUN_004094a0(), iVar2 = extraout_EDX, cVar1 != '\0')) {
        iVar2 = this->i_0c;
        local_10 = this->f_54 + *(float *)(iVar2 + 0xc);
        local_c = this->f_58 + *(float *)(iVar2 + 0x10);
        local_8 = this->f_5c + *(float *)(iVar2 + 0x14);
        FUN_005cd7e0(&local_10);
        iVar2 = this->i_4c;
      }
      this->i_4c = iVar2 + 1;
    }
    return 1;
  }
  if ((*(uint *)(this->i_0c + 0x3d0) & 0x10000000) != 0) {
    return 0;
  }
  FUN_005daff0("atr_Hitpoints");
  return 0;
}

