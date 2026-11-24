
void __thiscall FUN_00511230(ViWinInfoOpts *this)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
    iVar2 = 0;
  }
  else {
    piVar3 = (int *)(DAT_0077244c + 0x488);
    if (**(uint **)(DAT_00772400 + 0xa0c4) < 0x2000) {
      piVar3 = piVar3 + **(uint **)(DAT_00772400 + 0xa0c4);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar2 = *piVar3;
  }
  uVar1 = **(uint **)&this->field_0x44;
  if ((uVar1 & 3) != 0) {
    this->i_60 = iVar2;
    FUN_0050feb0();
    uVar1 = **(uint **)&this->field_0x44;
  }
  if (uVar1 != 0) {
    FUN_00504ee0();
    **(undefined4 **)&this->field_0x44 = 0;
  }
  if (this->i_60 != iVar2) {
    this->i_60 = iVar2;
    FUN_0050feb0();
    return;
  }
  return;
}

