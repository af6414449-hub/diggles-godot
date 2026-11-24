
void __thiscall FUN_0051bae0(ViWinNewsTicker *this)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  this->i_48 = this->i_0c;
  this->i_4c = this->i_10;
  this->i_50 = this->i_14 - this->i_0c;
  this->i_54 = this->i_18 - this->i_10;
  if (0 < this->i_78) {
    do {
      iVar1 = this->i_14;
      iVar2 = this->i_0c;
      if ((uint)this->i_78 <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)(this->i_74 + 4 + uVar3 * 8) = (float)(iVar1 - iVar2);
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < this->i_78);
  }
  return;
}

