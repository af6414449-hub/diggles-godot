
void FUN_10027220(uint param_1,uint param_2)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float *pfVar14;
  float *pfVar15;
  uint in_ECX;
  int iVar16;
  uint in_EDX;
  uint uVar17;
  float in_XMM3_Da;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  uVar17 = 0;
  if (param_2 != 0) {
    if (((0xf < param_2) &&
        (((param_1 + param_2 * 4) - 4 < in_ECX || (in_ECX + (param_2 - 1) * 4 < param_1)))) &&
       ((in_EDX + (param_2 - 1) * 4 < in_ECX || (in_ECX + (param_2 - 1) * 4 < in_EDX)))) {
      fVar18 = 1.0 - in_XMM3_Da;
      fVar19 = 1.0 - in_XMM3_Da;
      fVar20 = 1.0 - in_XMM3_Da;
      fVar21 = 1.0 - in_XMM3_Da;
      pfVar14 = (float *)(param_1 + 0x10);
      pfVar15 = (float *)(in_ECX + 0x20);
      do {
        pfVar1 = (float *)(in_EDX + uVar17 * 4);
        fVar3 = pfVar1[1];
        fVar4 = pfVar1[2];
        fVar5 = pfVar1[3];
        fVar6 = pfVar14[-3];
        fVar7 = pfVar14[-2];
        fVar8 = pfVar14[-1];
        fVar9 = *pfVar14;
        fVar10 = pfVar14[1];
        fVar11 = pfVar14[2];
        fVar12 = pfVar14[3];
        pfVar15[-8] = *pfVar1 * fVar18 + pfVar14[-4] * in_XMM3_Da;
        pfVar15[-7] = fVar3 * fVar19 + fVar6 * in_XMM3_Da;
        pfVar15[-6] = fVar4 * fVar20 + fVar7 * in_XMM3_Da;
        pfVar15[-5] = fVar5 * fVar21 + fVar8 * in_XMM3_Da;
        pfVar1 = (float *)((int)pfVar14 + (in_EDX - param_1));
        fVar3 = pfVar1[1];
        fVar4 = pfVar1[2];
        fVar5 = pfVar1[3];
        fVar6 = pfVar14[4];
        fVar7 = pfVar14[5];
        fVar8 = pfVar14[6];
        fVar13 = pfVar14[7];
        pfVar2 = (float *)((int)pfVar14 + (in_ECX - param_1));
        *pfVar2 = *pfVar1 * fVar18 + fVar9 * in_XMM3_Da;
        pfVar2[1] = fVar3 * fVar19 + fVar10 * in_XMM3_Da;
        pfVar2[2] = fVar4 * fVar20 + fVar11 * in_XMM3_Da;
        pfVar2[3] = fVar5 * fVar21 + fVar12 * in_XMM3_Da;
        pfVar1 = (float *)((int)pfVar15 + (in_EDX - in_ECX));
        fVar3 = pfVar1[1];
        fVar4 = pfVar1[2];
        fVar5 = pfVar1[3];
        fVar9 = pfVar14[8];
        fVar10 = pfVar14[9];
        fVar11 = pfVar14[10];
        fVar12 = pfVar14[0xb];
        pfVar14 = pfVar14 + 0x10;
        *pfVar15 = *pfVar1 * fVar18 + fVar6 * in_XMM3_Da;
        pfVar15[1] = fVar3 * fVar19 + fVar7 * in_XMM3_Da;
        pfVar15[2] = fVar4 * fVar20 + fVar8 * in_XMM3_Da;
        pfVar15[3] = fVar5 * fVar21 + fVar13 * in_XMM3_Da;
        pfVar1 = (float *)(in_EDX + 0x30 + uVar17 * 4);
        fVar3 = pfVar1[1];
        fVar4 = pfVar1[2];
        fVar5 = pfVar1[3];
        uVar17 = uVar17 + 0x10;
        pfVar15[4] = *pfVar1 * fVar18 + fVar9 * in_XMM3_Da;
        pfVar15[5] = fVar3 * fVar19 + fVar10 * in_XMM3_Da;
        pfVar15[6] = fVar4 * fVar20 + fVar11 * in_XMM3_Da;
        pfVar15[7] = fVar5 * fVar21 + fVar12 * in_XMM3_Da;
        pfVar15 = pfVar15 + 0x10;
      } while (uVar17 < (param_2 & 0xfffffff0));
      if (param_2 <= uVar17) {
        return;
      }
    }
    if (3 < param_2 - uVar17) {
      fVar18 = 1.0 - in_XMM3_Da;
      pfVar15 = (float *)(in_ECX + (uVar17 + 2) * 4);
      pfVar14 = (float *)(param_1 + 4 + uVar17 * 4);
      do {
        pfVar15[-2] = *(float *)(in_EDX + uVar17 * 4) * fVar18 + pfVar14[-1] * in_XMM3_Da;
        *(float *)((int)pfVar14 + (in_ECX - param_1)) =
             *(float *)((int)pfVar14 + (in_EDX - param_1)) * fVar18 + in_XMM3_Da * *pfVar14;
        *pfVar15 = *(float *)((int)pfVar15 + (in_EDX - in_ECX)) * fVar18 + pfVar14[1] * in_XMM3_Da;
        iVar16 = uVar17 * 4;
        uVar17 = uVar17 + 4;
        pfVar1 = pfVar14 + 2;
        pfVar14 = pfVar14 + 4;
        pfVar15[1] = *(float *)(in_EDX + 0xc + iVar16) * fVar18 + *pfVar1 * in_XMM3_Da;
        pfVar15 = pfVar15 + 4;
      } while (uVar17 < param_2 - 3);
      if (param_2 <= uVar17) {
        return;
      }
    }
    iVar16 = param_2 - uVar17;
    pfVar15 = (float *)(param_1 + uVar17 * 4);
    do {
      *(float *)((int)pfVar15 + (in_ECX - param_1)) =
           *(float *)((int)pfVar15 + (in_EDX - param_1)) * (1.0 - in_XMM3_Da) +
           in_XMM3_Da * *pfVar15;
      pfVar15 = pfVar15 + 1;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
  }
  return;
}

