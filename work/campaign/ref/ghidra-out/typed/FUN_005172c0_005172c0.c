
void __thiscall FUN_005172c0(ViWinLayoutCC_WorkClock *this)

{
  void *lp;
  uint uVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  
  if (0 < this->i_48) {
    if (this->i_48 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar1 = _atol((char *)(*(int *)this->i_44 + 0xc));
    if (uVar1 - 2 < 0x1fff) {
      this->i_4c = uVar1;
      if (0 < (int)uVar1) {
        puVar3 = (undefined4 *)(DAT_0077244c + 0x488);
        if (uVar1 < 0x2000) {
          puVar3 = puVar3 + uVar1;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        lp = (void *)*puVar3;
        if ((((lp == (void *)0x0) || (BVar2 = IsBadReadPtr(lp,0x10), BVar2 != 0)) ||
            (*(int *)((int)lp + 8) != 0x616e4f62)) ||
           ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))) {
          this->i_4c = 0;
        }
      }
      return;
    }
  }
  this->i_4c = 0;
  return;
}

