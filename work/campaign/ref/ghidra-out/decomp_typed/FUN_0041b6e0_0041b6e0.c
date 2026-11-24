
undefined4 FUN_0041b6e0(void)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  int this;
  
  piVar3 = *(int **)(this + 0x4c);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_0041b190();
    *(int **)(this + 0x4c) = piVar3;
    if (piVar3 == (int *)0x0) {
      return 0;
    }
  }
  cVar2 = (**(code **)(*piVar3 + 0xc))();
  if (cVar2 == '\0') {
    puVar1 = *(undefined4 **)(this + 0x4c);
    switch(puVar1[2]) {
    default:
      this->i_08 = 0;
      break;
    case 3:
      this->i_08 = 3;
      break;
    case 4:
      this->i_08 = 4;
      break;
    case 5:
      this->i_08 = 5;
    }
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    this->i_4c = 0;
    return 0;
  }
  return 1;
}

