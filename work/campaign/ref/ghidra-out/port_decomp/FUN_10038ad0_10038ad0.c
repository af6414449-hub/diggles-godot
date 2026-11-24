
int FUN_10038ad0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  uVar1 = FUN_10038a40();
  uVar2 = FUN_10038a40();
  uVar3 = FUN_10038a40();
  iVar4 = FUN_10038a40();
  return iVar4 * 0x1000000 + (uVar1 & 0xff) + (uVar2 & 0xff) * 0x100 + (uVar3 & 0xff) * 0x10000;
}

