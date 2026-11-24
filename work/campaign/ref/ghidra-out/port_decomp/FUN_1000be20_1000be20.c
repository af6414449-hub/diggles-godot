
void FUN_1000be20(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    FUN_100095b0();
    FUN_100402ac(iVar1,0x84);
  }
  return;
}

