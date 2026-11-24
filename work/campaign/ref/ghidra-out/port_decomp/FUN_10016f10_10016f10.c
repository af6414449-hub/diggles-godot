
undefined4 FUN_10016f10(void)

{
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(char *)(in_ECX + 0x68) == '\0') {
    return 0x80004005;
  }
  *(undefined1 *)(in_ECX + 0x68) = 0;
  return 0;
}

