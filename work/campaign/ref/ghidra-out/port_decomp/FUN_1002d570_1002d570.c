
undefined4 FUN_1002d570(undefined2 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  int in_ECX;
  uint uVar4;
  uint in_EDX;
  uint uVar5;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  if ((*(int *)(in_ECX + 0x18) == 0x20) && (iVar2 = FUN_1002d310(), iVar2 == 0)) {
    return 0;
  }
  uVar5 = *(uint *)(in_ECX + 0x101c);
  uVar4 = 0x20 - *(int *)(in_ECX + 0x18);
  if (uVar4 < in_EDX) {
    uVar1 = *(undefined4 *)(in_ECX + 0x18);
    iVar2 = FUN_1002d310();
    if (iVar2 == 0) {
      return 0;
    }
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + (in_EDX - uVar4);
    bVar3 = (byte)(in_EDX - uVar4);
    uVar5 = (~(0xffffffffU >> (bVar3 & 0x1f)) & *(uint *)(in_ECX + 0x101c)) >> (0x20 - bVar3 & 0x1f)
            | ((~(0xffffffffU >> ((byte)uVar4 & 0x1f)) & uVar5) >> ((byte)uVar1 & 0x1f)) <<
              (bVar3 & 0x1f);
    iVar2 = *(uint *)(in_ECX + 0x101c) << (bVar3 & 0x1f);
  }
  else if (in_EDX < 0x20) {
    bVar3 = (byte)in_EDX;
    iVar2 = uVar5 << (bVar3 & 0x1f);
    *(uint *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + in_EDX;
    uVar5 = (~(0xffffffffU >> (bVar3 & 0x1f)) & uVar5) >> (0x20 - bVar3 & 0x1f);
  }
  else {
    iVar2 = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0x20;
  }
  *(int *)(in_ECX + 0x101c) = iVar2;
  *param_1 = (short)uVar5;
  return 1;
}

