
undefined4 __thiscall FUN_0040ed60(CAct_Elevator *this)

{
  if (this->c_40 == '\0') {
    FUN_0060abd0(*(undefined4 *)(this->i_04 + 0xdc));
  }
  if (*(int **)&this->field_0x4c != (int *)0x0) {
    (**(code **)(**(int **)&this->field_0x4c + 4))();
  }
  return 1;
}

