
void FUN_00507320(void)

{
  int iVar1;
  int iVar2;
  int this;
  
  iVar1 = this->i_50;
  if ((iVar1 != 0) &&
     ((((iVar2 = (this->i_14 - this->i_0c) + -0x14,
        *(int *)(iVar1 + 0x1c4) != 5 || (*(int *)(iVar1 + 0x1c8) != 5)) ||
       (iVar2 != *(int *)(iVar1 + 0x1cc))) || (*(int *)(iVar1 + 0x1d0) != 0x2000)))) {
    *(undefined4 *)(iVar1 + 0x1c4) = 5;
    *(undefined4 *)(iVar1 + 0x1c8) = 5;
    *(int *)(iVar1 + 0x1cc) = iVar2;
    *(undefined4 *)(iVar1 + 0x1d0) = 0x2000;
    FUN_00514f90(iVar1);
  }
  return;
}

