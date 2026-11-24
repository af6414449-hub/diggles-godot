
undefined8 FUN_100274f0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *in_ECX;
  void *in_EDX;
  size_t _Size;
  bool bVar5;
  int iStack_20;
  uint local_18;
  void *local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_10 = 0;
  local_18 = 1;
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  iVar1 = *(int *)(*in_ECX + 8);
  iVar4 = in_ECX[0x401];
  local_c = 0;
  local_8 = 0;
  local_14 = in_EDX;
  do {
    uVar2 = iVar4 - in_ECX[0x402];
    iStack_20 = local_10;
    if ((local_10 != 0) || (uVar3 = local_18, uVar2 < local_18)) {
      iStack_20 = 0;
      uVar3 = uVar2;
    }
    _Size = uVar3 * iVar1 * 4;
    memcpy(local_14,in_ECX + in_ECX[0x402] * iVar1 + 1,_Size);
    in_ECX[0x402] = in_ECX[0x402] + uVar3;
    bVar5 = CARRY4(local_8,uVar3);
    local_8 = local_8 + uVar3;
    local_c = local_c + iStack_20 + (uint)bVar5;
    bVar5 = local_18 < uVar3;
    local_18 = local_18 - uVar3;
    local_10 = (local_10 - iStack_20) - (uint)bVar5;
    if (local_18 == 0 && local_10 == 0) break;
    iVar4 = *in_ECX;
    in_ECX[0x402] = 0;
    in_ECX[0x401] = 0;
    local_14 = (void *)((int)local_14 + _Size);
    uVar3 = (uint)(0x400 / (ulonglong)*(uint *)(iVar4 + 8));
    uVar2 = *(uint *)(iVar4 + 0x10);
    if (uVar3 <= *(uint *)(iVar4 + 0x10)) {
      uVar2 = uVar3;
    }
    iVar4 = (**(code **)(iVar4 + 0x14))(iVar4,uVar2,0,in_ECX + 1,*(undefined4 *)(iVar4 + 0x18));
    in_ECX[0x401] = iVar4;
  } while (iVar4 != 0);
  return CONCAT44(local_c,local_8);
}

