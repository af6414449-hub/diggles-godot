
uint FUN_100391b0(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(char *)(in_ECX + 0x56c) == '\0') {
    if (*(int *)(in_ECX + 0x574) == 0) {
      iVar1 = FUN_10039100();
      if (iVar1 != 0) goto LAB_100391e9;
    }
    *(undefined4 *)(in_ECX + 0x580) = 0;
    return 0xffffffff;
  }
LAB_100391e9:
  *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
  *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
  uVar2 = FUN_10038a40();
  *(undefined4 *)(in_ECX + 0x580) = 0;
  return uVar2 & 0xff;
}

