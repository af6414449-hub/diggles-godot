
undefined4 FUN_10035240(void)

{
  int iVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  while( true ) {
    iVar1 = FUN_10034760(in_ECX + 0x30);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_10035130();
    if (iVar1 == 0) break;
    if (iVar1 != -0x81) {
      return 0;
    }
  }
  return 1;
}

