
undefined4 FUN_10021570(void)

{
  byte bVar1;
  byte bVar2;
  int in_ECX;
  char *in_EDX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if ((((*in_EDX == -1) &&
       ((((bVar1 = in_EDX[1], (bVar1 & 0xf0) == 0xf0 || ((bVar1 & 0xfe) == 0xe2)) &&
         ((bVar1 & 6) != 0)) &&
        ((bVar2 = in_EDX[2], (bVar2 & 0xf0) != 0xf0 && ((bVar2 & 0xc) != 0xc)))))) &&
      (((*(byte *)(in_ECX + 1) ^ bVar1) & 0xfe) == 0)) &&
     ((((*(byte *)(in_ECX + 2) ^ bVar2) & 0xc) == 0 &&
      (((*(byte *)(in_ECX + 2) & 0xf0) == 0) == ((bVar2 & 0xf0) == 0))))) {
    return 1;
  }
  return 0;
}

