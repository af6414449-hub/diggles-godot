
void __thiscall FUN_00414ea0(CAct_Lore *this)

{
  int iVar1;
  int iVar2;
  int iStack00000004;
  
  FUN_00407d10();
  FUN_00555d70();
  FUN_00407d10();
  FUN_00407d10();
  FUN_00406f60(&this->field_0x18);
  FUN_00406f60(&this->field_0x1c);
  FUN_00406f60(&this->f_20);
  iStack00000004 = this->i_28;
  FUN_00406f60(&stack0x00000004);
  FUN_00415170(iStack00000004);
  iVar2 = 0;
  if (0 < iStack00000004) {
    do {
      iVar1 = this->i_24;
      FUN_00555d70();
      FUN_00406f60(iVar1 + iVar2 * 8 + 4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iStack00000004);
  }
  FUN_004153b0();
  return;
}

