
undefined4 FUN_100397b0(uint *param_1,uint param_2)

{
  int iVar1;
  float *pfVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  uint *in_EDX;
  int iVar11;
  float fVar12;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar6 = FUN_10039630();
  if (iVar6 < 0) {
    return 0;
  }
  uVar3 = *in_EDX;
  if ((int)uVar3 < (int)param_2) {
    param_2 = uVar3;
  }
  iVar6 = uVar3 * iVar6;
  iVar10 = 0;
  if (*(char *)((int)in_EDX + 0x16) == '\0') {
    if (0 < (int)param_2) {
      if (0xf < param_2) {
        uVar3 = in_EDX[7];
        iVar10 = 0;
        if ((((uint *)(uVar3 + (iVar6 + -1 + param_2) * 4) < param_1) ||
            (param_1 + (param_2 - 1) < (uint *)(uVar3 + iVar6 * 4))) &&
           ((in_EDX + 7 < param_1 || (param_1 + (param_2 - 1) < in_EDX + 7)))) {
          uVar7 = param_2 & 0x8000000f;
          if ((int)uVar7 < 0) {
            uVar7 = (uVar7 - 1 | 0xfffffff0) + 1;
          }
          pfVar8 = (float *)(param_1 + 8);
          iVar11 = iVar6 * 4 + 0x20;
          do {
            pfVar2 = (float *)(iVar11 + -0x20 + uVar3);
            fVar12 = pfVar2[1];
            fVar4 = pfVar2[2];
            fVar5 = pfVar2[3];
            iVar10 = iVar10 + 0x10;
            pfVar8[-8] = *pfVar2 + 0.0 + pfVar8[-8];
            pfVar8[-7] = fVar12 + 0.0 + pfVar8[-7];
            pfVar8[-6] = fVar4 + 0.0 + pfVar8[-6];
            pfVar8[-5] = fVar5 + 0.0 + pfVar8[-5];
            pfVar2 = (float *)(iVar11 + -0x10 + uVar3);
            fVar12 = pfVar2[1];
            fVar4 = pfVar2[2];
            fVar5 = pfVar2[3];
            pfVar8[-4] = *pfVar2 + 0.0 + pfVar8[-4];
            pfVar8[-3] = fVar12 + 0.0 + pfVar8[-3];
            pfVar8[-2] = fVar4 + 0.0 + pfVar8[-2];
            pfVar8[-1] = fVar5 + 0.0 + pfVar8[-1];
            pfVar2 = (float *)(iVar11 + uVar3);
            fVar12 = pfVar2[1];
            fVar4 = pfVar2[2];
            fVar5 = pfVar2[3];
            *pfVar8 = *pfVar2 + 0.0 + *pfVar8;
            pfVar8[1] = fVar12 + 0.0 + pfVar8[1];
            pfVar8[2] = fVar4 + 0.0 + pfVar8[2];
            pfVar8[3] = fVar5 + 0.0 + pfVar8[3];
            pfVar2 = (float *)(iVar11 + 0x10 + uVar3);
            fVar12 = pfVar2[1];
            fVar4 = pfVar2[2];
            fVar5 = pfVar2[3];
            iVar11 = iVar11 + 0x40;
            pfVar8[4] = *pfVar2 + 0.0 + pfVar8[4];
            pfVar8[5] = fVar12 + 0.0 + pfVar8[5];
            pfVar8[6] = fVar4 + 0.0 + pfVar8[6];
            pfVar8[7] = fVar5 + 0.0 + pfVar8[7];
            pfVar8 = pfVar8 + 0x10;
          } while (iVar10 < (int)(param_2 - uVar7));
          if ((int)param_2 <= iVar10) {
            return 1;
          }
        }
      }
      if (3 < (int)(param_2 - iVar10)) {
        iVar11 = (iVar10 + iVar6) * 4;
        pfVar8 = (float *)(param_1 + iVar10 + 2);
        iVar9 = ((param_2 - iVar10) - 4 >> 2) + 1;
        iVar10 = iVar10 + iVar9 * 4;
        do {
          pfVar8[-2] = *(float *)(iVar11 + in_EDX[7]) + 0.0 + pfVar8[-2];
          pfVar8[-1] = *(float *)(iVar11 + 4 + in_EDX[7]) + 0.0 + pfVar8[-1];
          *pfVar8 = *(float *)(iVar11 + 8 + in_EDX[7]) + 0.0 + *pfVar8;
          iVar1 = iVar11 + 0xc;
          iVar11 = iVar11 + 0x10;
          pfVar8[1] = *(float *)(iVar1 + in_EDX[7]) + 0.0 + pfVar8[1];
          pfVar8 = pfVar8 + 4;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        if ((int)param_2 <= iVar10) {
          return 1;
        }
      }
      iVar6 = (iVar6 + iVar10) * 4;
      do {
        pfVar8 = (float *)(iVar6 + in_EDX[7]);
        iVar6 = iVar6 + 4;
        param_1[iVar10] = (uint)(*pfVar8 + 0.0 + (float)param_1[iVar10]);
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)param_2);
    }
  }
  else {
    fVar12 = 0.0;
    if (0 < (int)param_2) {
      iVar6 = iVar6 * 4;
      do {
        fVar12 = fVar12 + *(float *)(iVar6 + in_EDX[7]);
        iVar6 = iVar6 + 4;
        param_1[iVar10] = (uint)(fVar12 + (float)param_1[iVar10]);
        iVar10 = iVar10 + 1;
        fVar12 = fVar12 + (float)in_EDX[3];
      } while (iVar10 < (int)param_2);
      return 1;
    }
  }
  return 1;
}

