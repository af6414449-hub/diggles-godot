
void FUN_10021a60(int param_1,int param_2)

{
  byte bVar1;
  int in_ECX;
  int iVar2;
  int *in_EDX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  iVar3 = 0x240;
  local_18 = 0x240;
  local_20 = 4;
  local_1c = in_ECX;
  do {
    local_14 = 0;
    iVar6 = local_1c;
    if (*(char *)(param_1 + 0x300) != '\0') {
      do {
        bVar1 = *(byte *)(param_1 + 0x302 + local_14);
        uVar4 = (uint)bVar1;
        if (uVar4 != 0) {
          if (uVar4 < 0x11) {
            iVar7 = 0;
            if (0 < param_2) {
              do {
                uVar9 = in_EDX[1];
                uVar10 = 0;
                pbVar8 = (byte *)(((int)uVar9 >> 3) + *in_EDX);
                in_EDX[1] = uVar9 + uVar4;
                if (in_EDX[2] < (int)(uVar9 + uVar4)) {
                  uVar10 = 0;
                }
                else {
                  uVar5 = 0xff >> (sbyte)(uVar9 & 7) & (uint)*pbVar8;
                  for (iVar2 = (uVar9 & 7) + (uVar4 - 8); 0 < iVar2; iVar2 = iVar2 + -8) {
                    pbVar8 = pbVar8 + 1;
                    uVar10 = uVar10 | uVar5 << ((byte)iVar2 & 0x1f);
                    uVar5 = (uint)*pbVar8;
                  }
                  uVar10 = uVar5 >> (-(byte)iVar2 & 0x1f) | uVar10;
                }
                *(float *)(iVar6 + iVar7 * 4) =
                     (float)(int)(uVar10 - ((1 << (bVar1 - 1 & 0x1f)) + -1));
                iVar7 = iVar7 + 1;
              } while (iVar7 < param_2);
            }
          }
          else {
            uVar9 = (2 << (bVar1 - 0x11 & 0x1f)) + 1;
            uVar4 = FUN_100214f0();
            iVar7 = 0;
            if (0 < param_2) {
              do {
                *(float *)(iVar6 + iVar7 * 4) = (float)(int)(uVar4 % uVar9 - (uVar9 >> 1));
                iVar7 = iVar7 + 1;
                uVar4 = uVar4 / uVar9;
              } while (iVar7 < param_2);
            }
          }
        }
        local_14 = local_14 + 1;
        iVar3 = 0x12 - iVar3;
        iVar6 = iVar6 + local_18 * 4;
        local_18 = iVar3;
      } while (local_14 < (int)((uint)*(byte *)(param_1 + 0x300) * 2));
    }
    local_1c = local_1c + param_2 * 4;
    local_20 = local_20 + -1;
  } while (local_20 != 0);
  return;
}

