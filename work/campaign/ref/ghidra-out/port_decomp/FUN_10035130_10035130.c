
undefined4 FUN_10035130(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  byte local_14 [12];
  undefined1 local_8;
  undefined1 local_7 [3];
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  memset((void *)(in_ECX + 0x4c),0,0x40);
  if (*(ushort *)(in_ECX + 0x40) <= *(ushort *)(in_ECX + 0x1e)) {
    local_14[0] = 1;
    local_14[1] = 2;
    local_14[2] = 3;
    local_14[3] = 4;
    local_14[4] = 5;
    local_14[5] = 6;
    local_14[6] = 7;
    local_14[7] = 8;
    local_14[8] = 2;
    local_14[9] = 2;
    local_14[10] = 2;
    uVar2 = (uint)local_14[*(char *)(in_ECX + 0x42)];
    if (uVar2 == *(byte *)(in_ECX + 0x1c)) {
      iVar3 = 0;
      if (uVar2 != 0) {
        do {
          iVar1 = FUN_10034de0(iVar3,*(int *)(in_ECX + 0xac) +
                                     (uint)*(ushort *)(in_ECX + 0x40) * iVar3 * 4);
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)uVar2);
      }
      if ((((-*(char *)(in_ECX + 0xd4) & 7U) == 0) || (iVar3 = FUN_1002d650(local_7), iVar3 != 0))
         && (iVar3 = FUN_1002d570(&local_8), iVar3 != 0)) {
        *(uint *)(in_ECX + 0x48) = (uint)*(ushort *)(in_ECX + 0x40);
        return 0;
      }
      return 0xffffff80;
    }
  }
  return 0xffffffff;
}

