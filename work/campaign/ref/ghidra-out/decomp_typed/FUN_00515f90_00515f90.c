
void FUN_00515f90(void)

{
  uint uVar1;
  void *lp;
  long lVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  BOOL BVar5;
  int this;
  float in_XMM0_Da;
  
  if (this->i_48 < 2) {
    this->i_4c = 0;
    this->i_54 = 0;
    return;
  }
  if (this->i_48 == 0) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  lVar2 = _atol((char *)(**(int **)(this + 0x44) + 0xc));
  if (lVar2 - 2U < 0x1fff) {
    this->i_4c = lVar2;
    FUN_005da0f0();
    if (this->i_48 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar3 = FUN_005da2f0(*(int *)(this->i_44 + 4) + 0xc);
    uVar1 = this->i_4c;
    this->i_50 = uVar3;
    if ((int)uVar1 < 1) {
      this->i_54 = 0;
      return;
    }
    puVar4 = (undefined4 *)(DAT_0077244c + 0x488);
    if (uVar1 < 0x2000) {
      puVar4 = puVar4 + uVar1;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    lp = (void *)*puVar4;
    if ((((lp != (void *)0x0) && (BVar5 = IsBadReadPtr(lp,0x10), BVar5 == 0)) &&
        (*(int *)((int)lp + 8) == 0x616e4f62)) &&
       ((DAT_00768398 == '\0' || (*(int *)((int)lp + 0xdc) != 0)))) {
      if (this->i_50 == -1) {
        return;
      }
      FUN_005dadf0(this->i_50);
      if (ABS(in_XMM0_Da - this->i_54) <= 0.01) {
        return;
      }
      this->i_54 = in_XMM0_Da;
      FUN_00504ee0();
      return;
    }
  }
  else {
    this->i_54 = 0;
  }
  this->i_4c = 0;
  return;
}

