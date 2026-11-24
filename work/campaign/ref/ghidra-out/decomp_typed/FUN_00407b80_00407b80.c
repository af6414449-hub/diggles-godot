
undefined4 FUN_00407b80(void)

{
  int this;
  
  if (this->i_24 == 2) {
    this->i_24 = 1;
  }
  *(undefined1 *)(this->i_0c + 0x2b4) = 0;
  if (*(int **)(this + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x20) + 4))();
    if (*(undefined4 **)(this + 0x20) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(this + 0x20))(1);
    }
    this->i_20 = 0;
  }
  return 1;
}

