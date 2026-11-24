
void FUN_00414ea0(int param_1)

{
  int iVar1;
  int this;
  int iVar2;
  
  FUN_00407d10();
  FUN_00555d70();
  FUN_00407d10();
  FUN_00407d10();
  FUN_00406f60(this + 0x18);
  FUN_00406f60(this + 0x1c);
  FUN_00406f60(this + 0x20);
  param_1 = this->i_28;
  FUN_00406f60(&param_1);
  FUN_00415170(param_1);
  iVar2 = 0;
  if (0 < param_1) {
    do {
      iVar1 = this->i_24;
      FUN_00555d70();
      FUN_00406f60(iVar1 + iVar2 * 8 + 4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1);
  }
  FUN_004153b0();
  return;
}

