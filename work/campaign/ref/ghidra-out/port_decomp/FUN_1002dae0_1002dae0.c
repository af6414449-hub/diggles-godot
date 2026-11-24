
undefined4 FUN_1002dae0(uint param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int in_stack_00000018;
  uint local_2c [4];
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  local_2c[2] = in_stack_00000018;
  local_18 = in_ECX;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_2c[0] = 0;
  local_2c[1] = 0xffffffff;
  local_c = (uint)param_2;
  local_2c[3] = ~(-1 << (param_2 & 0x1f));
  local_10 = 0;
  if (param_1 != 0) {
    local_14 = 0x20 - (param_2 + 1);
    do {
      uVar1 = *(uint *)(in_ECX + 0x101c);
      iVar6 = *(int *)(in_ECX + 0x18);
      if (DAT_1005109c == 0) {
        if (uVar1 == 0) {
          uVar3 = 0x20;
        }
        else {
          iVar2 = 0x1f;
          if (uVar1 != 0) {
            for (; uVar1 >> iVar2 == 0; iVar2 = iVar2 + -1) {
            }
          }
          uVar3 = 0x1f - iVar2;
        }
      }
      else {
        uVar3 = LZCOUNT(uVar1);
      }
      uVar4 = uVar3;
      if (0x1f < uVar3) {
        uVar4 = 0x20 - iVar6;
        do {
          uVar1 = *(uint *)(in_ECX + 0x14);
          if (uVar1 < 0x400) {
            uVar3 = *(uint *)(in_ECX + 0x1c + uVar1 * 4);
            *(uint *)(in_ECX + 0x14) = uVar1 + 1;
            iVar6 = 0;
            uVar1 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
          }
          else {
            iVar6 = FUN_1002d310();
            if (iVar6 == 0) {
              return 0;
            }
            uVar1 = *(uint *)(in_ECX + 0x101c);
            iVar6 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar1 == 0) {
              uVar3 = 0x20;
            }
            else {
              iVar2 = 0x1f;
              if (uVar1 != 0) {
                for (; uVar1 >> iVar2 == 0; iVar2 = iVar2 + -1) {
                }
              }
              uVar3 = 0x1f - iVar2;
            }
          }
          else {
            uVar3 = LZCOUNT(uVar1);
          }
          uVar4 = uVar4 + uVar3;
        } while (0x1f < uVar3);
      }
      uVar5 = iVar6 + uVar3;
      uVar1 = uVar1 << ((byte)uVar3 & 0x1f);
      uVar3 = uVar1 >> ((byte)local_14 & 0x1f);
      if (local_14 < uVar5) {
        iVar6 = uVar5 - local_14;
        local_1c = uVar3;
        uVar1 = *(uint *)(in_ECX + 0x14);
        local_8 = iVar6;
        if (uVar1 < 0x400) {
          uVar3 = *(uint *)(in_ECX + 0x1c + uVar1 * 4);
          *(uint *)(in_ECX + 0x14) = uVar1 + 1;
          uVar1 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
        }
        else {
          iVar6 = FUN_1002d310();
          if (iVar6 == 0) {
            return 0;
          }
          iVar6 = *(int *)(in_ECX + 0x18) + local_8;
          uVar1 = *(uint *)(in_ECX + 0x101c);
        }
        iVar2 = uVar1 << ((byte)local_8 & 0x1f);
        uVar3 = uVar1 >> (0x20 - (byte)local_8 & 0x1f) | local_1c;
      }
      else {
        iVar2 = uVar1 << ((byte)(local_c + 1) & 0x1f);
        iVar6 = uVar5 + local_c + 1;
        in_ECX = local_18;
      }
      uVar1 = uVar4 << ((byte)local_c & 0x1f) | uVar3 & local_2c[3];
      *(int *)(in_ECX + 0x101c) = iVar2;
      *(int *)(in_ECX + 0x18) = iVar6;
      *(uint *)(local_2c[2] + local_10 * 4) = uVar1 >> 1 ^ local_2c[uVar1 & 1];
      local_10 = local_10 + 1;
    } while (local_10 < param_1);
  }
  return 1;
}

