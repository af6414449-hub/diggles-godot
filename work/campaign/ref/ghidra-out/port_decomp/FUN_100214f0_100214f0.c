
uint FUN_100214f0(void)

{
  uint uVar1;
  uint uVar2;
  int *in_ECX;
  int iVar3;
  int in_EDX;
  byte *pbVar4;
  uint uVar5;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  uVar1 = in_ECX[1];
  uVar5 = 0;
  pbVar4 = (byte *)(((int)uVar1 >> 3) + *in_ECX);
  in_ECX[1] = uVar1 + in_EDX;
  if ((int)(uVar1 + in_EDX) <= in_ECX[2]) {
    uVar2 = 0xff >> (sbyte)(uVar1 & 7) & (uint)*pbVar4;
    for (iVar3 = in_EDX + -8 + (uVar1 & 7); 0 < iVar3; iVar3 = iVar3 + -8) {
      pbVar4 = pbVar4 + 1;
      uVar5 = uVar5 | uVar2 << ((byte)iVar3 & 0x1f);
      uVar2 = (uint)*pbVar4;
    }
    return uVar2 >> (-(byte)iVar3 & 0x1f) | uVar5;
  }
  return 0;
}

