
undefined4 FUN_10038e70(void)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  cVar1 = FUN_10038a40();
  if (cVar1 == 'O') {
    cVar1 = FUN_10038a40();
    if (cVar1 == 'g') {
      cVar1 = FUN_10038a40();
      if (cVar1 == 'g') {
        cVar1 = FUN_10038a40();
        if (cVar1 == 'S') {
          uVar2 = FUN_10038c50();
          return uVar2;
        }
      }
    }
  }
  *(undefined4 *)(in_ECX + 0x70) = 0x1e;
  return 0;
}

