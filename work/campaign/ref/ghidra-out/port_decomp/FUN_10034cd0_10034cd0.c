
undefined4 FUN_10034cd0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int in_ECX;
  char cVar5;
  byte *in_EDX;
  undefined4 uStack_8;
  
  uStack_8 = in_ECX;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  iVar2 = FUN_1002d650((int)&uStack_8 + 3);
  if (iVar2 == 0) {
    return 0;
  }
  if ((char)uStack_8._3_1_ < '\0') {
    return 0;
  }
  bVar4 = uStack_8._3_1_ >> 1;
  if ((bVar4 & 0x3f) == 0) {
    *in_EDX = bVar4 & 0x3f;
  }
  else if ((bVar4 & 0x3f) == 1) {
    *in_EDX = 1;
  }
  else {
    if ((bVar4 & 0x20) == 0) {
      if ((bVar4 & 8) == 0) {
        *in_EDX = 0xff;
      }
      else {
        *in_EDX = 8;
        in_EDX[2] = bVar4 & 7;
        cVar5 = '\b';
        if (4 < (bVar4 & 7)) {
          *in_EDX = 0xff;
          cVar5 = -1;
          in_EDX[2] = 0;
        }
        if (cVar5 != -1) goto LAB_10034d57;
      }
      return 0;
    }
    *in_EDX = 0x20;
    in_EDX[2] = (bVar4 & 0x1f) + 1;
  }
LAB_10034d57:
  in_EDX[1] = 0;
  if ((uStack_8._3_1_ & 1) != 0) {
    iVar2 = 0;
    cVar5 = '\0';
    uVar1 = *(uint *)(in_ECX + 0x101c);
    while (uVar1 == 0) {
      iVar2 = iVar2 + (0x20 - *(int *)(in_ECX + 0x18));
      cVar5 = (char)iVar2;
      iVar3 = FUN_1002d310();
      if (iVar3 == 0) {
        return 0;
      }
      uVar1 = *(uint *)(in_ECX + 0x101c);
    }
    if (DAT_1005109c == 0) {
      iVar2 = 0x1f;
      if (uVar1 != 0) {
        for (; uVar1 >> iVar2 == 0; iVar2 = iVar2 + -1) {
        }
      }
      iVar2 = 0x1f - iVar2;
    }
    else {
      iVar2 = LZCOUNT(uVar1);
    }
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + iVar2 + 1;
    bVar4 = (byte)(iVar2 + 1);
    *(uint *)(in_ECX + 0x101c) = uVar1 << (bVar4 & 0x1f);
    in_EDX[1] = bVar4 + cVar5;
  }
  return 1;
}

