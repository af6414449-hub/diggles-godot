
char FUN_10039100(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(int *)(in_ECX + 0x574) != 0) {
    return '\0';
  }
  if (*(int *)(in_ECX + 0x570) == -1) {
    *(int *)(in_ECX + 0x578) = *(int *)(in_ECX + 0x468) + -1;
    iVar3 = FUN_10038e70();
    if (iVar3 == 0) {
      *(undefined4 *)(in_ECX + 0x574) = 1;
      return '\0';
    }
    if ((*(byte *)(in_ECX + 0x56b) & 1) == 0) {
      *(undefined4 *)(in_ECX + 0x70) = 0x20;
      return '\0';
    }
  }
  iVar2 = *(int *)(in_ECX + 0x570);
  cVar1 = *(char *)(iVar2 + 0x46c + in_ECX);
  iVar3 = iVar2 + 1;
  *(int *)(in_ECX + 0x570) = iVar3;
  if (cVar1 != -1) {
    *(undefined4 *)(in_ECX + 0x574) = 1;
    *(int *)(in_ECX + 0x578) = iVar2;
  }
  *(char *)(in_ECX + 0x56c) = cVar1;
  if (*(int *)(in_ECX + 0x468) <= iVar3) {
    iVar3 = -1;
  }
  *(int *)(in_ECX + 0x570) = iVar3;
  return cVar1;
}

