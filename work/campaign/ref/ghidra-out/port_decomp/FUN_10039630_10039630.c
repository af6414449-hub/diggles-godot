
void FUN_10039630(void)

{
  int *piVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  int in_ECX;
  int in_EDX;
  int iVar5;
  bool bVar6;
  byte local_9;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(char *)(in_EDX + 0x15) != '\0') {
    if (*(int *)(in_ECX + 0x580) < 10) {
      if (*(int *)(in_ECX + 0x580) == 0) {
        *(undefined4 *)(in_ECX + 0x57c) = 0;
      }
      do {
        if (*(int *)(in_ECX + 0x574) == 0) {
          if (*(char *)(in_ECX + 0x56c) == '\0') {
            iVar5 = FUN_10039100();
            bVar6 = iVar5 == 0;
            goto LAB_100396ad;
          }
        }
        else {
          bVar6 = *(char *)(in_ECX + 0x56c) == '\0';
LAB_100396ad:
          if (bVar6) break;
        }
        *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
        *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
        pbVar3 = *(byte **)(in_ECX + 0x2c);
        if (pbVar3 == (byte *)0x0) {
          piVar1 = *(int **)(in_ECX + 0x20);
          iVar5 = (**(code **)(*piVar1 + 4))();
          if (iVar5 == 0) {
            local_9 = 0;
            (**(code **)(*piVar1 + 8))(&local_9,1);
            uVar4 = (uint)local_9;
          }
          else {
            *(undefined4 *)(in_ECX + 0x6c) = 1;
            uVar4 = 0;
          }
        }
        else if (pbVar3 < *(byte **)(in_ECX + 0x34)) {
          bVar2 = *pbVar3;
          *(byte **)(in_ECX + 0x2c) = pbVar3 + 1;
          uVar4 = (uint)bVar2;
        }
        else {
          *(undefined4 *)(in_ECX + 0x6c) = 1;
          uVar4 = 0;
        }
        *(int *)(in_ECX + 0x57c) =
             *(int *)(in_ECX + 0x57c) + (uVar4 << ((byte)*(int *)(in_ECX + 0x580) & 0x1f));
        iVar5 = *(int *)(in_ECX + 0x580) + 8;
        *(int *)(in_ECX + 0x580) = iVar5;
      } while (iVar5 < 0x19);
    }
    iVar5 = (int)*(short *)(in_EDX + 0x24 + (*(uint *)(in_ECX + 0x57c) & 0x3ff) * 2);
    if (iVar5 < 0) {
      iVar5 = FUN_100393d0();
      if (-1 < iVar5) goto LAB_1003978f;
    }
    else {
      bVar2 = *(byte *)(*(int *)(in_EDX + 8) + iVar5);
      piVar1 = (int *)(in_ECX + 0x580);
      *piVar1 = *piVar1 - (uint)bVar2;
      *(uint *)(in_ECX + 0x57c) = *(uint *)(in_ECX + 0x57c) >> (bVar2 & 0x1f);
      if (-1 < *piVar1) goto LAB_1003978f;
      *(undefined4 *)(in_ECX + 0x580) = 0;
    }
    if ((*(char *)(in_ECX + 0x56c) == '\0') && (*(int *)(in_ECX + 0x574) != 0)) goto LAB_1003978f;
  }
  *(undefined4 *)(in_ECX + 0x70) = 0x15;
LAB_1003978f:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

