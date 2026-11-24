
void FUN_00527af0(void)

{
  int this;
  
  FUN_00505ed0();
  FUN_005275a0();
  if (this->i_4c == 0) {
    if (this->c_1c != '\0') {
      FUN_00504ee0();
      this->c_1c = 0;
    }
  }
  else if (this->c_1c != '\x01') {
    this->c_1c = 1;
    FUN_00504ee0();
    return;
  }
  return;
}

