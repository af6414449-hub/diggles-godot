
uint FUN_100392f0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  int in_EDX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar1 = *(int *)(in_ECX + 0x580);
  if (-1 < iVar1) {
    if (iVar1 < in_EDX) {
      if (0x18 < in_EDX) {
        iVar1 = FUN_100392f0();
        iVar2 = FUN_100392f0();
        return iVar2 * 0x1000000 + iVar1;
      }
      if (iVar1 == 0) {
        *(undefined4 *)(in_ECX + 0x57c) = 0;
      }
      do {
        if ((*(char *)(in_ECX + 0x56c) == '\0') &&
           ((*(int *)(in_ECX + 0x574) != 0 || (iVar1 = FUN_10039100(), iVar1 == 0)))) {
          *(undefined4 *)(in_ECX + 0x580) = 0xffffffff;
          return 0;
        }
        *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
        *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
        uVar3 = FUN_10038a40();
        *(int *)(in_ECX + 0x57c) =
             *(int *)(in_ECX + 0x57c) + ((uVar3 & 0xff) << ((byte)*(int *)(in_ECX + 0x580) & 0x1f));
        iVar1 = *(int *)(in_ECX + 0x580) + 8;
        *(int *)(in_ECX + 0x580) = iVar1;
      } while (iVar1 < in_EDX);
    }
    if (-1 < iVar1) {
      uVar3 = *(uint *)(in_ECX + 0x57c);
      *(uint *)(in_ECX + 0x57c) = uVar3 >> ((byte)in_EDX & 0x1f);
      *(int *)(in_ECX + 0x580) = iVar1 - in_EDX;
      return (1 << ((byte)in_EDX & 0x1f)) - 1U & uVar3;
    }
  }
  return 0;
}

