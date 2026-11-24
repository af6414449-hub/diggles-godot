
void FUN_0053c4e0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xb0);
  if (iVar1 == 6) {
    FUN_00544940();
    iVar1 = *(int *)(in_ECX + 0xb0);
  }
  if (iVar1 == 7) {
    FUN_00545000(0);
  }
  if ((char)PTR_0077241c->mapFlags == '\0') {
    *(undefined1 *)(in_ECX + 0x2d) = 1;
    iVar1 = FUN_00501450();
    if ((*(int *)(iVar1 + 0x81a0) != 0) && (*(int *)(iVar1 + 0x81a0) == in_ECX)) {
      iVar1 = FUN_00501450();
      *(undefined4 *)(iVar1 + 0x81a0) = 0;
    }
  }
  return;
}

