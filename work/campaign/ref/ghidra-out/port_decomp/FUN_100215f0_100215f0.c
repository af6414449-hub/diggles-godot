
undefined4 FUN_100215f0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if ((*(byte *)(in_ECX + 1) & 6) == 6) {
    return 0x180;
  }
  uVar1 = 0x480;
  if ((*(byte *)(in_ECX + 1) & 0xe) == 2) {
    uVar1 = 0x240;
  }
  return uVar1;
}

