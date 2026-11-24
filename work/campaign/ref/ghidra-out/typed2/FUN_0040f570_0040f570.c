
void __thiscall FUN_0040f570(CAct_Fall *this)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 in_stack_00000004;
  
  if (0xa4 < DAT_007723fc) {
    FUN_00407d10();
    FUN_00555d70();
    FUN_00407d10();
    FUN_00407d10();
    FUN_00406f60(&this->field_0x18);
    puVar2 = &this->field_0x24;
    iVar1 = 3;
    do {
      FUN_00406f60(puVar2 + -8);
      FUN_00406f60(puVar2 + -4);
      FUN_00406f60(puVar2);
      puVar2 = puVar2 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    FUN_0040f650(in_stack_00000004);
    FUN_00406f60(&this->field_0x4c);
    FUN_00406f60(&this->field_0x50);
    FUN_00406f60(&this->field_0x54);
    FUN_00406f60(&this->f_58);
    FUN_00409340(&this->c_5c);
    FUN_00408960(&this->d_60);
  }
  return;
}

