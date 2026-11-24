
undefined4 FUN_1003f690(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(char *)(in_ECX + 0x3c) != '\0') {
    *(undefined4 *)(in_ECX + 0x70) = 2;
    return 0;
  }
  FUN_10038bd0();
  *(undefined4 *)(in_ECX + 0x3ec) = 0;
  *(undefined1 *)(in_ECX + 0x56d) = 1;
  *(undefined4 *)(in_ECX + 0x570) = 0xffffffff;
  uVar1 = FUN_1003c930();
  return uVar1;
}

