
void FUN_005165b0(void)

{
  void *lp;
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  BOOL BVar4;
  int this;
  float in_XMM0_Da;
  float fVar5;
  
  if (this->i_48 < 2) {
    this->i_4c = 0;
    this->i_50 = 0;
    this->i_58 = 0;
    return;
  }
  if (this->i_48 == 0) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  uVar1 = _atol((char *)(**(int **)(this + 0x44) + 0xc));
  if (uVar1 - 2 < 0x1fff) {
    FUN_005da0f0();
    if (this->i_48 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar2 = FUN_005da2f0(*(int *)(this->i_44 + 4) + 0xc);
    this->i_50 = uVar2;
    this->i_4c = uVar1;
    if ((int)uVar1 < 1) {
      this->i_58 = 0;
      return;
    }
    puVar3 = (undefined4 *)(DAT_0077244c + 0x488);
    if (uVar1 < 0x2000) {
      puVar3 = puVar3 + uVar1;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    lp = (void *)*puVar3;
    if ((((lp != (void *)0x0) && (BVar4 = IsBadReadPtr(lp,0x10), BVar4 == 0)) &&
        (*(int *)((int)lp + 8) == 0x616e4f62)) &&
       ((DAT_00768398 == '\0' || (*(int *)((int)lp + 0xdc) != 0)))) {
      FUN_005dadf0(this->i_50);
      fVar5 = in_XMM0_Da;
      FUN_005dae40("atr_ExpMax");
      this->f_54 = fVar5;
      if (ABS(in_XMM0_Da - this->i_58) <= 0.01) {
        return;
      }
      this->i_58 = in_XMM0_Da;
      FUN_00504ee0();
      return;
    }
  }
  else {
    this->i_58 = 0;
  }
  this->i_4c = 0;
  return;
}

