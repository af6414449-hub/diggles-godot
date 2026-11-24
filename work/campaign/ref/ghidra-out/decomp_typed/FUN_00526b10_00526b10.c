
void FUN_00526b10(void)

{
  int iVar1;
  int this;
  
  if (this->c_2c != '\0') {
    iVar1 = FUN_00501450();
    if ((*(int *)(iVar1 + 0x8198) == this) &&
       (((iVar1 = FUN_00501450(), *(int *)(iVar1 + 0x81a4) == 0 ||
         (iVar1 = FUN_00501450(), *(int *)(iVar1 + 0x81a4) == this)) &&
        (this->i_48 == 0)))) {
      FUN_00526a80(1);
    }
    iVar1 = FUN_00501450();
    if ((*(int *)(iVar1 + 0x819c) != this) && (this->i_48 == 1)) {
      FUN_00526a80(0);
    }
    iVar1 = FUN_00501450();
    if ((*(int *)(iVar1 + 0x819c) != this) && (this->i_48 == 2)) {
      FUN_00526a80(0);
    }
    return;
  }
  return;
}

