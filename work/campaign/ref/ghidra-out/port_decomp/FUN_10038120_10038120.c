
void FUN_10038120(int param_1,int *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int in_ECX;
  int in_EDX;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_90;
  uint local_88 [32];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  memset(local_88,0,0x80);
  iVar5 = 0;
  if (0 < param_1) {
    do {
      if (*(char *)(in_EDX + iVar5) != -1) goto LAB_1003818b;
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_1);
  }
  if (iVar5 != param_1) {
LAB_1003818b:
    uVar1 = *(undefined1 *)(in_EDX + iVar5);
    if (*(char *)(in_ECX + 0x17) == '\0') {
      (*(undefined4 **)(in_ECX + 0x20))[iVar5] = 0;
    }
    else {
      **(undefined4 **)(in_ECX + 0x20) = 0;
      **(undefined1 **)(in_ECX + 8) = uVar1;
      *param_2 = iVar5;
    }
    bVar4 = *(byte *)(in_EDX + iVar5);
    iVar7 = 1;
    local_90 = 1;
    if (bVar4 != 0) {
      do {
        local_88[iVar7] = 1 << (0x20U - (char)iVar7 & 0x1f);
        iVar7 = iVar7 + 1;
      } while (iVar7 <= (int)(uint)bVar4);
    }
joined_r0x100381e4:
    iVar5 = iVar5 + 1;
    if (iVar5 < param_1) {
      bVar4 = *(byte *)(in_EDX + iVar5);
      uVar3 = (uint)bVar4;
      if (uVar3 != 0xff) {
        if (uVar3 != 0) {
          do {
            if (local_88[uVar3] != 0) goto LAB_10038225;
            uVar3 = uVar3 - 1;
          } while (0 < (int)uVar3);
          if (uVar3 != 0) {
LAB_10038225:
            uVar2 = local_88[uVar3];
            local_88[uVar3] = 0;
            uVar6 = (uVar2 >> 1 ^ uVar2 * 2) & 0x55555555 ^ uVar2 * 2;
            uVar6 = (uVar6 >> 2 ^ uVar6 * 4) & 0x33333333 ^ uVar6 * 4;
            uVar6 = (uVar6 >> 4 ^ uVar6 << 4) & 0xf0f0f0f ^ uVar6 << 4;
            uVar6 = (uVar6 >> 8 ^ uVar6 << 8) & 0xff00ff ^ uVar6 << 8;
            uVar6 = uVar6 << 0x10 | uVar6 >> 0x10;
            if (*(char *)(in_ECX + 0x17) == '\0') {
              *(uint *)(*(int *)(in_ECX + 0x20) + iVar5 * 4) = uVar6;
            }
            else {
              *(uint *)(*(int *)(in_ECX + 0x20) + local_90 * 4) = uVar6;
              *(byte *)(local_90 + *(int *)(in_ECX + 8)) = bVar4;
              param_2[local_90] = iVar5;
            }
            local_90 = local_90 + 1;
            uVar6 = (uint)*(byte *)(in_EDX + iVar5);
            if ((int)uVar3 < (int)uVar6) {
              iVar7 = 0x20 - uVar6;
              do {
                bVar4 = (byte)iVar7;
                iVar7 = iVar7 + 1;
                local_88[uVar6] = (1 << (bVar4 & 0x1f)) + uVar2;
                uVar6 = uVar6 - 1;
              } while ((int)uVar3 < (int)uVar6);
            }
            goto joined_r0x100381e4;
          }
        }
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      goto joined_r0x100381e4;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

