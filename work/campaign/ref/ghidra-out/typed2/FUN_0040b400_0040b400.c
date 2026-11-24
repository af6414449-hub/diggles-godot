
void __thiscall FUN_0040b400(CAct_AttackBallistic *this)

{
  undefined4 uVar1;
  int in_stack_00000004;
  
  uVar1 = in_stack_00000004;
  if (0xa4 < DAT_007723fc) {
    FUN_00555d70();
    in_stack_00000004 = this->i_20;
    FUN_00406f60(&stack0x00000004);
    this->i_20 = in_stack_00000004;
    FUN_0040b640(uVar1);
    FUN_00406f60(&this->i_2c);
    FUN_00406f60(&this->i_30);
    FUN_0040b640(uVar1);
    FUN_00406f60(&this->i_3c);
    FUN_00406f60(&this->field_0x40);
    FUN_00409340(&this->c_44);
    FUN_00406f60(&this->i_48);
    FUN_00406f60(&this->i_4c);
    FUN_00406f60(&this->i_50);
    FUN_00409340(&this->c_54);
    FUN_00409340(&this->c_55);
    FUN_00406f60(&this->f_58);
    FUN_00408960(&this->d_60);
    FUN_00407d10();
    FUN_00555d70();
    FUN_00407d10();
    FUN_00407d10();
    FUN_00406f60(&this->field_0x18);
  }
  return;
}

