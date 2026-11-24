
uint FUN_10038000(void)

{
  uint in_ECX;
  uint uVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  uVar1 = (in_ECX >> 1 ^ in_ECX * 2) & 0x55555555 ^ in_ECX * 2;
  uVar1 = (uVar1 >> 2 ^ uVar1 * 4) & 0x33333333 ^ uVar1 * 4;
  uVar1 = (uVar1 >> 4 ^ uVar1 << 4) & 0xf0f0f0f ^ uVar1 << 4;
  uVar1 = (uVar1 >> 8 ^ uVar1 << 8) & 0xff00ff ^ uVar1 << 8;
  return uVar1 << 0x10 | uVar1 >> 0x10;
}

