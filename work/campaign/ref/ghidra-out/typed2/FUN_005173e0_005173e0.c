
void __thiscall FUN_005173e0(ViWinLayoutCC_EditName *this)

{
  int *in_stack_00000004;
  ViWinLayoutCC_EditName *local_8;
  
  if (this->i_4c == -1) {
    local_8 = this;
    (**(code **)(*(int *)this + 0x38))();
  }
  local_8 = (ViWinLayoutCC_EditName *)0xffff0000;
  if (*(int *)(*in_stack_00000004 + 8) != 0) {
    FUN_004ff430(*in_stack_00000004 + 0xc,&local_8);
  }
  return;
}

