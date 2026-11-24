
char * FUN_10002950(void)

{
  char *pcVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b78);
  pcVar1 = "Unknown exception";
  if (*(char **)(in_ECX + 4) != (char *)0x0) {
    pcVar1 = *(char **)(in_ECX + 4);
  }
  return pcVar1;
}

