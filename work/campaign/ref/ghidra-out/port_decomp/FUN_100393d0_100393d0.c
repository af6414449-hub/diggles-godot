
void FUN_100393d0(void)

{
  byte bVar1;
  byte *pbVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int in_ECX;
  uint uVar7;
  int in_EDX;
  int iVar8;
  uint *puVar9;
  bool bVar10;
  byte local_9;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(int *)(in_ECX + 0x580) < 0x19) {
    if (*(int *)(in_ECX + 0x580) == 0) {
      *(undefined4 *)(in_ECX + 0x57c) = 0;
    }
    do {
      if (((*(int *)(in_ECX + 0x574) != 0) && (*(char *)(in_ECX + 0x56c) == '\0')) ||
         ((*(char *)(in_ECX + 0x56c) == '\0' &&
          ((*(int *)(in_ECX + 0x574) != 0 || (iVar4 = FUN_10039100(), iVar4 == 0)))))) break;
      *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
      *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
      pbVar2 = *(byte **)(in_ECX + 0x2c);
      if (pbVar2 == (byte *)0x0) {
        piVar3 = *(int **)(in_ECX + 0x20);
        iVar4 = (**(code **)(*piVar3 + 4))();
        if (iVar4 == 0) {
          local_9 = 0;
          (**(code **)(*piVar3 + 8))(&local_9,1);
          uVar5 = (uint)local_9;
        }
        else {
          *(undefined4 *)(in_ECX + 0x6c) = 1;
          uVar5 = 0;
        }
      }
      else if (pbVar2 < *(byte **)(in_ECX + 0x34)) {
        bVar1 = *pbVar2;
        *(byte **)(in_ECX + 0x2c) = pbVar2 + 1;
        uVar5 = (uint)bVar1;
      }
      else {
        *(undefined4 *)(in_ECX + 0x6c) = 1;
        uVar5 = 0;
      }
      *(int *)(in_ECX + 0x57c) =
           *(int *)(in_ECX + 0x57c) + (uVar5 << ((byte)*(int *)(in_ECX + 0x580) & 0x1f));
      iVar4 = *(int *)(in_ECX + 0x580) + 8;
      *(int *)(in_ECX + 0x580) = iVar4;
    } while (iVar4 < 0x19);
  }
  puVar9 = *(uint **)(in_EDX + 0x20);
  if ((puVar9 != (uint *)0x0) || (*(int *)(in_EDX + 0x824) != 0)) {
    iVar4 = *(int *)(in_EDX + 4);
    if (iVar4 < 9) {
      bVar10 = puVar9 == (uint *)0x0;
    }
    else {
      bVar10 = *(int *)(in_EDX + 0x824) != 0;
    }
    if (bVar10) {
      uVar5 = FUN_10038000();
      iVar4 = 0;
      if (1 < (int)*(uint *)(in_EDX + 0x82c)) {
        uVar7 = *(uint *)(in_EDX + 0x82c);
        do {
          uVar6 = uVar7 >> 1;
          iVar8 = uVar6 + iVar4;
          if (*(uint *)(*(int *)(in_EDX + 0x824) + iVar8 * 4) <= uVar5) {
            uVar6 = uVar7 - uVar6;
            iVar4 = iVar8;
          }
          uVar7 = uVar6;
        } while (1 < (int)uVar6);
      }
      if (*(char *)(in_EDX + 0x17) == '\0') {
        iVar4 = *(int *)(*(int *)(in_EDX + 0x828) + iVar4 * 4);
      }
      bVar1 = *(byte *)(*(int *)(in_EDX + 8) + iVar4);
      if ((int)(uint)bVar1 <= *(int *)(in_ECX + 0x580)) {
        *(uint *)(in_ECX + 0x57c) = *(uint *)(in_ECX + 0x57c) >> (bVar1 & 0x1f);
        *(uint *)(in_ECX + 0x580) = *(int *)(in_ECX + 0x580) - (uint)bVar1;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    else {
      iVar8 = 0;
      if (0 < iVar4) {
        do {
          bVar1 = *(byte *)(*(int *)(in_EDX + 8) + iVar8);
          if (bVar1 != 0xff) {
            if (*puVar9 == ((1 << (bVar1 & 0x1f)) - 1U & *(uint *)(in_ECX + 0x57c))) {
              if ((int)(uint)bVar1 <= *(int *)(in_ECX + 0x580)) {
                *(uint *)(in_ECX + 0x57c) = *(uint *)(in_ECX + 0x57c) >> (bVar1 & 0x1f);
                *(uint *)(in_ECX + 0x580) =
                     *(int *)(in_ECX + 0x580) - (uint)*(byte *)(*(int *)(in_EDX + 8) + iVar8);
                __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
                return;
              }
              goto LAB_100395c8;
            }
          }
          iVar8 = iVar8 + 1;
          puVar9 = puVar9 + 1;
        } while (iVar8 < iVar4);
      }
      *(undefined4 *)(in_ECX + 0x70) = 0x15;
    }
LAB_100395c8:
    *(undefined4 *)(in_ECX + 0x580) = 0;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

