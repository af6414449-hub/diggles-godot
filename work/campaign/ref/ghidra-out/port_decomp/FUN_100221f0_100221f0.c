
void FUN_100221f0(void)

{
  int in_ECX;
  int iVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  do {
    iVar1 = 0x78;
    if (in_ECX < 0x78) {
      iVar1 = in_ECX;
    }
    in_ECX = in_ECX - iVar1;
  } while (0 < in_ECX);
  return;
}

