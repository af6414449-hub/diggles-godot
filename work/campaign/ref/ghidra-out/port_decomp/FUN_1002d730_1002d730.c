
undefined4 FUN_1002d730(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint in_EDX;
  uint uVar3;
  undefined1 local_5;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  uVar3 = *(int *)(in_ECX + 0x18) + in_EDX;
  if (in_EDX <= 0x20U - *(int *)(in_ECX + 0x18)) {
    *(uint *)(in_ECX + 0x18) = uVar3;
    *(int *)(in_ECX + 0x101c) = *(int *)(in_ECX + 0x101c) << ((byte)in_EDX & 0x1f);
    return 1;
  }
  *(undefined4 *)(in_ECX + 0x18) = 0x20;
  iVar2 = 0x20;
  *(undefined4 *)(in_ECX + 0x101c) = 0;
  while (uVar3 = uVar3 - 0x20, 0x1f < uVar3) {
    if ((iVar2 == 0x20) && (iVar2 = FUN_1002d310(), iVar2 == 0)) {
      return 0;
    }
    iVar1 = *(int *)(in_ECX + 0x18);
    if (0x20U - iVar1 < 0x20) {
      iVar2 = FUN_1002d310();
      if (iVar2 == 0) {
        return 0;
      }
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + iVar1;
      iVar2 = *(int *)(in_ECX + 0x18);
      *(int *)(in_ECX + 0x101c) = *(int *)(in_ECX + 0x101c) << ((byte)iVar1 & 0x1f);
    }
    else {
      *(undefined4 *)(in_ECX + 0x18) = 0x20;
      iVar2 = 0x20;
      *(undefined4 *)(in_ECX + 0x101c) = 0;
    }
  }
  for (; 7 < uVar3; uVar3 = uVar3 - 8) {
    if ((iVar2 == 0x20) && (iVar2 = FUN_1002d310(), iVar2 == 0)) {
      return 0;
    }
    iVar1 = *(int *)(in_ECX + 0x18);
    if (0x20U - iVar1 < 8) {
      iVar2 = FUN_1002d310();
      if (iVar2 == 0) {
        return 0;
      }
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + iVar1 + -0x18;
      iVar2 = *(int *)(in_ECX + 0x18);
      *(int *)(in_ECX + 0x101c) = *(int *)(in_ECX + 0x101c) << ((byte)(iVar1 + -0x18) & 0x1f);
    }
    else {
      *(int *)(in_ECX + 0x101c) = *(int *)(in_ECX + 0x101c) << 8;
      iVar2 = iVar1 + 8;
      *(int *)(in_ECX + 0x18) = iVar2;
    }
  }
  if ((uVar3 != 0) && (iVar2 = FUN_1002d650(&local_5), iVar2 == 0)) {
    return 0;
  }
  return 1;
}

