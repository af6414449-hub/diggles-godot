
undefined4 FUN_10039070(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(int *)(in_ECX + 0x570) != -1) {
LAB_100390f7:
    uVar3 = FUN_10038ec0();
    return uVar3;
  }
  cVar1 = FUN_10038a40();
  if (*(int *)(in_ECX + 0x6c) == 0) {
    if ((((cVar1 == 'O') && (cVar1 = FUN_10038a40(), cVar1 == 'g')) &&
        (cVar1 = FUN_10038a40(), cVar1 == 'g')) && (cVar1 = FUN_10038a40(), cVar1 == 'S')) {
      iVar2 = FUN_10038c50();
      if (iVar2 == 0) {
        return 0;
      }
      if ((*(byte *)(in_ECX + 0x56b) & 1) != 0) {
        *(undefined4 *)(in_ECX + 0x574) = 0;
        *(undefined1 *)(in_ECX + 0x56c) = 0;
        *(undefined4 *)(in_ECX + 0x70) = 0x20;
        return 0;
      }
      goto LAB_100390f7;
    }
    *(undefined4 *)(in_ECX + 0x70) = 0x1e;
  }
  return 0;
}

