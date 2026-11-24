
undefined4 FUN_1003b7c0(int param_1,int param_2,int param_3,short *param_4)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  float *pfVar8;
  int in_ECX;
  uint uVar9;
  int iVar10;
  int in_EDX;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint local_18;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  uVar2 = param_2 >> 1;
  uVar4 = (uint)*(byte *)(*(byte *)(*(int *)(in_EDX + 4) + 2 + param_1 * 3) + 9 + in_EDX);
  if (*(short *)(in_ECX + 0x90 + uVar4 * 2) == 0) {
    *(undefined4 *)(in_ECX + 0x70) = 0x15;
    return 0;
  }
  param_1 = 1;
  iVar11 = uVar4 * 0x63c + *(int *)(in_ECX + 0x110);
  uVar4 = 0;
  uVar9 = (int)*param_4 * (uint)*(byte *)(iVar11 + 0x634);
  uVar13 = uVar9;
  uVar7 = uVar4;
  local_18 = uVar9;
  if (1 < *(int *)(iVar11 + 0x638)) {
    do {
      uVar14 = (uint)*(byte *)(iVar11 + 0x346 + param_1);
      uVar9 = uVar13;
      uVar4 = uVar7;
      uVar3 = local_18;
      if (-1 < param_4[uVar14]) {
        uVar9 = (int)param_4[uVar14] * (uint)*(byte *)(iVar11 + 0x634);
        uVar4 = (uint)*(ushort *)(iVar11 + 0x152 + uVar14 * 2);
        uVar3 = uVar9;
        if (uVar7 != uVar4) {
          iVar15 = 0;
          uVar13 = uVar9 - uVar13;
          iVar10 = uVar4 - uVar7;
          uVar12 = (int)uVar13 >> 0x1f;
          uVar5 = (int)uVar13 / iVar10;
          uVar14 = uVar2;
          if ((int)uVar4 <= (int)uVar2) {
            uVar14 = uVar4;
          }
          if ((int)uVar7 < (int)uVar14) {
            *(float *)(param_3 + uVar7 * 4) =
                 *(float *)(&DAT_10043fc0 + (local_18 & 0xff) * 4) * *(float *)(param_3 + uVar7 * 4)
            ;
            while (uVar7 = uVar7 + 1, (int)uVar7 < (int)uVar14) {
              iVar15 = iVar15 + (((uVar13 ^ uVar12) - uVar12) -
                                ((uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f)) * iVar10);
              uVar6 = uVar5;
              if (iVar10 <= iVar15) {
                iVar15 = iVar15 - iVar10;
                uVar6 = (uVar12 & 0xfffffffe) + 1 + uVar5;
              }
              local_18 = local_18 + uVar6;
              *(float *)(param_3 + uVar7 * 4) =
                   *(float *)(&DAT_10043fc0 + (local_18 & 0xff) * 4) *
                   *(float *)(param_3 + uVar7 * 4);
            }
          }
        }
      }
      local_18 = uVar3;
      param_1 = param_1 + 1;
      uVar13 = uVar9;
      uVar7 = uVar4;
    } while (param_1 < *(int *)(iVar11 + 0x638));
  }
  if ((int)uVar4 < (int)uVar2) {
    if (0xf < uVar2 - uVar4) {
      fVar1 = *(float *)(&DAT_10043fc0 + uVar9 * 4);
      uVar7 = uVar2 - uVar4 & 0x8000000f;
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffff0) + 1;
      }
      pfVar8 = (float *)(param_3 + 0x20 + uVar4 * 4);
      do {
        uVar4 = uVar4 + 0x10;
        pfVar8[-8] = pfVar8[-8] * fVar1;
        pfVar8[-7] = pfVar8[-7] * fVar1;
        pfVar8[-6] = pfVar8[-6] * fVar1;
        pfVar8[-5] = pfVar8[-5] * fVar1;
        pfVar8[-4] = pfVar8[-4] * fVar1;
        pfVar8[-3] = pfVar8[-3] * fVar1;
        pfVar8[-2] = pfVar8[-2] * fVar1;
        pfVar8[-1] = pfVar8[-1] * fVar1;
        *pfVar8 = *pfVar8 * fVar1;
        pfVar8[1] = pfVar8[1] * fVar1;
        pfVar8[2] = pfVar8[2] * fVar1;
        pfVar8[3] = pfVar8[3] * fVar1;
        pfVar8[4] = fVar1 * pfVar8[4];
        pfVar8[5] = fVar1 * pfVar8[5];
        pfVar8[6] = fVar1 * pfVar8[6];
        pfVar8[7] = fVar1 * pfVar8[7];
        pfVar8 = pfVar8 + 0x10;
      } while ((int)uVar4 < (int)(uVar2 - uVar7));
      if ((int)uVar2 <= (int)uVar4) {
        return 1;
      }
    }
    fVar1 = *(float *)(&DAT_10043fc0 + uVar9 * 4);
    if (3 < (int)(uVar2 - uVar4)) {
      iVar11 = uVar4 + 2;
      iVar15 = ((uVar2 - uVar4) - 4 >> 2) + 1;
      uVar4 = uVar4 + iVar15 * 4;
      pfVar8 = (float *)(param_3 + iVar11 * 4);
      do {
        pfVar8[-2] = pfVar8[-2] * fVar1;
        pfVar8[-1] = pfVar8[-1] * fVar1;
        *pfVar8 = *pfVar8 * fVar1;
        pfVar8[1] = pfVar8[1] * fVar1;
        iVar15 = iVar15 + -1;
        pfVar8 = pfVar8 + 4;
      } while (iVar15 != 0);
      if ((int)uVar2 <= (int)uVar4) {
        return 1;
      }
    }
    do {
      *(float *)(param_3 + uVar4 * 4) = *(float *)(param_3 + uVar4 * 4) * fVar1;
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < (int)uVar2);
  }
  return 1;
}

