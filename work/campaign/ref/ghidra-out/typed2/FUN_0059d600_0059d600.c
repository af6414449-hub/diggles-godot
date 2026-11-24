
undefined4 FUN_0059d600(void)

{
  int iVar1;
  uint *in_ECX;
  
  iVar1 = FUN_00592f10(PTR_0077241c);
  if ((*(char *)(iVar1 + 6) != -1) &&
     ((*(byte *)(((in_ECX[1] & 7) << 3 | *in_ECX & 7) + 0x3c + iVar1) & 1) != 0)) {
    return 1;
  }
  return 0;
}

