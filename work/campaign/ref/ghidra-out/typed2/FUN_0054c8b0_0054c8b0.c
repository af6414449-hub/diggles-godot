
ViWinTextEdit * __thiscall FUN_0054c8b0(ViWinTextEdit *this)

{
  int iVar1;
  byte in_stack_00000004;
  
  *(undefined ***)this = ViWinTextEdit::vftable;
  iVar1 = FUN_00501450();
  if ((*(ViWinTextEdit **)(iVar1 + 0x81a0) != (ViWinTextEdit *)0x0) &&
     (*(ViWinTextEdit **)(iVar1 + 0x81a0) == this)) {
    iVar1 = FUN_00501450();
    *(undefined4 *)(iVar1 + 0x81a0) = 0;
  }
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x60);
  }
  return this;
}

