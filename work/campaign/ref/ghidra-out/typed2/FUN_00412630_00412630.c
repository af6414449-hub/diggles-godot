
undefined4 __thiscall FUN_00412630(CAct_Ladder *this)

{
  if (this->c_4c == '\0') {
    FUN_0060c2b0(*(undefined4 *)(this->i_04 + 0xdc));
  }
  if ((int *)this->i_48 != (int *)0x0) {
    (**(code **)(*(int *)this->i_48 + 4))();
  }
  return 1;
}

