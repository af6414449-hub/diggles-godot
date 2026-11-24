
undefined4 FUN_004125f0(void)

{
  int this;
  
  if (this->c_4c == '\0') {
    FUN_0060c2b0(*(undefined4 *)(this->i_04 + 0xdc));
  }
  if (*(int **)(this + 0x48) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x48) + 8))();
  }
  this->i_08 = 1;
  return 1;
}

