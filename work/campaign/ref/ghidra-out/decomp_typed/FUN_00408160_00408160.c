
undefined4 FUN_00408160(void)

{
  char cVar1;
  int this;
  
  cVar1 = (**(code **)(**(int **)(this + 0x20) + 0xc))();
  if (cVar1 != '\0') {
    return 1;
  }
  this->i_08 = *(undefined4 *)(this->i_20 + 8);
  if (((*(int *)(this->i_20 + 8) == 3) &&
      (*(int *)(this->i_0c + 0x7b4) == 0)) &&
     (FUN_00407fb0(), this->i_20 != 0)) {
    return 1;
  }
  return 0;
}

