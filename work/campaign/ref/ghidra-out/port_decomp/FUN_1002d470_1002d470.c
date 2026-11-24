
undefined4 FUN_1002d470(uint *param_1)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  int in_ECX;
  uint uVar5;
  uint in_EDX;
  uint uVar6;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  if ((*(int *)(in_ECX + 0x18) == 0x20) && (iVar2 = FUN_1002d310(), iVar2 == 0)) {
    return 0;
  }
  uVar6 = *(uint *)(in_ECX + 0x101c);
  uVar5 = 0x20 - *(int *)(in_ECX + 0x18);
  bVar3 = (byte)in_EDX;
  if (uVar5 < in_EDX) {
    uVar1 = *(undefined4 *)(in_ECX + 0x18);
    iVar2 = FUN_1002d310();
    if (iVar2 == 0) {
      return 0;
    }
    bVar4 = (byte)(in_EDX - uVar5);
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + (in_EDX - uVar5);
    uVar6 = (~(0xffffffffU >> (bVar4 & 0x1f)) & *(uint *)(in_ECX + 0x101c)) >> (0x20 - bVar4 & 0x1f)
            | ((~(0xffffffffU >> ((byte)uVar5 & 0x1f)) & uVar6) >> ((byte)uVar1 & 0x1f)) <<
              (bVar4 & 0x1f);
    iVar2 = *(uint *)(in_ECX + 0x101c) << (bVar4 & 0x1f);
  }
  else if (in_EDX < 0x20) {
    iVar2 = uVar6 << (bVar3 & 0x1f);
    *(uint *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + in_EDX;
    uVar6 = (~(0xffffffffU >> (bVar3 & 0x1f)) & uVar6) >> (0x20 - bVar3 & 0x1f);
  }
  else {
    iVar2 = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0x20;
  }
  *(int *)(in_ECX + 0x101c) = iVar2;
  *param_1 = ~(uVar6 >> (bVar3 - 1 & 0x1f) & 1) + 1 << (bVar3 & 0x1f) | uVar6;
  return 1;
}

