
void FUN_10022d20(byte *param_1,int param_2,int param_3)

{
  float fVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  float *pfVar5;
  int in_EDX;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  uVar3 = 0x40;
  if ((*(byte *)(param_2 + 1) & 8) != 0) {
    uVar3 = 7;
  }
  local_8 = 0;
  if (*param_1 != 0) {
    iVar6 = in_EDX - (int)param_1;
    pbVar9 = param_1;
    do {
      bVar2 = pbVar9[iVar6];
      uVar7 = (uint)bVar2;
      if ((*(int *)(param_3 + (local_8 % 3) * 4) < (int)local_8) && (uVar7 < uVar3)) {
        if ((*(byte *)(param_2 + 3) & 0x20) == 0) {
          param_1 = (byte *)0x3f800000;
        }
        else {
          param_1 = (byte *)0x3fb504f3;
        }
        if ((*(byte *)(param_2 + 1) & 8) == 0) {
          fVar12 = 1.0;
          FUN_100221f0();
          if ((bVar2 & 1) == 0) {
            fVar11 = 1.0;
            fVar10 = fVar12;
          }
          else {
            fVar10 = 1.0;
            fVar11 = fVar12;
          }
        }
        else {
          fVar10 = *(float *)(&DAT_10047514 + uVar7 * 8);
          fVar11 = *(float *)(&DAT_10047510 + uVar7 * 8);
        }
        uVar7 = (uint)*pbVar9;
        iVar4 = 0;
        if (3 < uVar7) {
          iVar8 = (uVar7 - 4 >> 2) + 1;
          fVar12 = fVar10 * (float)param_1;
          fVar13 = fVar11 * (float)param_1;
          iVar4 = iVar8 * 4;
          pfVar5 = (float *)(in_ECX + 4);
          do {
            pfVar5[0x23f] = fVar12 * pfVar5[-1];
            pfVar5[-1] = fVar13 * pfVar5[-1];
            pfVar5[0x240] = *pfVar5 * fVar12;
            *pfVar5 = *pfVar5 * fVar13;
            fVar1 = pfVar5[1];
            pfVar5[1] = fVar1 * fVar13;
            pfVar5[0x241] = fVar1 * fVar12;
            pfVar5[0x242] = fVar12 * pfVar5[2];
            pfVar5[2] = fVar13 * pfVar5[2];
            iVar8 = iVar8 + -1;
            pfVar5 = pfVar5 + 4;
          } while (iVar8 != 0);
        }
        if (iVar4 < (int)uVar7) {
          do {
            fVar12 = *(float *)(in_ECX + iVar4 * 4);
            *(float *)(in_ECX + iVar4 * 4) = fVar12 * fVar11 * (float)param_1;
            *(float *)(in_ECX + 0x900 + iVar4 * 4) = fVar12 * fVar10 * (float)param_1;
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)uVar7);
        }
      }
      else if ((*(byte *)(param_2 + 3) & 0x20) != 0) {
        FUN_10022a90();
      }
      bVar2 = *pbVar9;
      pbVar9 = pbVar9 + 1;
      local_8 = local_8 + 1;
      in_ECX = in_ECX + (uint)bVar2 * 4;
    } while (*pbVar9 != 0);
  }
  return;
}

