
uint FUN_10028d70(void)

{
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if ((*(ushort *)(in_ECX + 0x52) & 7) == 0) {
    return (int)((uint)*(ushort *)(in_ECX + 0x26) * (uint)*(ushort *)(in_ECX + 0x52)) >> 3;
  }
  return (uint)*(ushort *)(in_ECX + 0x30);
}

