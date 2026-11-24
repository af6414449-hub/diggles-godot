
void FUN_10022a90(void)

{
  float *pfVar1;
  float fVar2;
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
  int iVar15;
  uint uVar16;
  float *pfVar17;
  float *pfVar18;
  int in_ECX;
  int in_EDX;
  int iVar19;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  iVar19 = 0;
  pfVar14 = (float *)(in_ECX + 0x900);
  iVar15 = FUN_10021470();
  if ((iVar15 != 0) && (0 < in_EDX + -3)) {
    iVar15 = (in_EDX - 4U >> 2) + 1;
    iVar19 = iVar15 * 4;
    pfVar18 = pfVar14;
    do {
      fVar2 = pfVar18[-0x240];
      fVar3 = pfVar18[-0x23f];
      fVar4 = pfVar18[-0x23e];
      fVar5 = pfVar18[-0x23d];
      pfVar18[-0x240] = *pfVar18 + fVar2;
      pfVar18[-0x23f] = pfVar18[1] + fVar3;
      pfVar18[-0x23e] = pfVar18[2] + fVar4;
      pfVar18[-0x23d] = pfVar18[3] + fVar5;
      *pfVar18 = fVar2 - *pfVar18;
      pfVar18[1] = fVar3 - pfVar18[1];
      pfVar18[2] = fVar4 - pfVar18[2];
      pfVar18[3] = fVar5 - pfVar18[3];
      pfVar18 = pfVar18 + 4;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  if (iVar19 < in_EDX) {
    if ((0xf < (uint)(in_EDX - iVar19)) &&
       (((float *)(in_ECX + -4 + in_EDX * 4) < pfVar14 + iVar19 ||
        ((uint)(in_ECX + 0x8fc + in_EDX * 4) < (uint)(in_ECX + iVar19 * 4))))) {
      uVar16 = in_EDX - iVar19 & 0x8000000f;
      if ((int)uVar16 < 0) {
        uVar16 = (uVar16 - 1 | 0xfffffff0) + 1;
      }
      pfVar18 = (float *)(in_ECX + 0x30 + iVar19 * 4);
      pfVar17 = (float *)(in_ECX + 0x910 + iVar19 * 4);
      do {
        fVar2 = pfVar18[-0xc];
        fVar3 = pfVar18[-0xb];
        fVar4 = pfVar18[-10];
        fVar5 = pfVar18[-9];
        iVar19 = iVar19 + 0x10;
        fVar6 = pfVar17[-4];
        fVar7 = pfVar17[-3];
        fVar8 = pfVar17[-2];
        fVar9 = pfVar17[-1];
        pfVar18[-0xc] = fVar2 + fVar6;
        pfVar18[-0xb] = fVar3 + fVar7;
        pfVar18[-10] = fVar4 + fVar8;
        pfVar18[-9] = fVar5 + fVar9;
        pfVar17[-4] = fVar2 - fVar6;
        pfVar17[-3] = fVar3 - fVar7;
        pfVar17[-2] = fVar4 - fVar8;
        pfVar17[-1] = fVar5 - fVar9;
        pfVar1 = (float *)((int)pfVar17 + (in_ECX - (int)pfVar14));
        fVar2 = *pfVar1;
        fVar3 = pfVar1[1];
        fVar4 = pfVar1[2];
        fVar5 = pfVar1[3];
        fVar6 = *pfVar17;
        fVar7 = pfVar17[1];
        fVar8 = pfVar17[2];
        fVar9 = pfVar17[3];
        pfVar1 = (float *)((int)pfVar17 + (in_ECX - (int)pfVar14));
        *pfVar1 = fVar2 + fVar6;
        pfVar1[1] = fVar3 + fVar7;
        pfVar1[2] = fVar4 + fVar8;
        pfVar1[3] = fVar5 + fVar9;
        *pfVar17 = fVar2 - fVar6;
        pfVar17[1] = fVar3 - fVar7;
        pfVar17[2] = fVar4 - fVar8;
        pfVar17[3] = fVar5 - fVar9;
        fVar2 = pfVar18[-4];
        fVar3 = pfVar18[-3];
        fVar4 = pfVar18[-2];
        fVar5 = pfVar18[-1];
        fVar6 = pfVar17[4];
        fVar7 = pfVar17[5];
        fVar8 = pfVar17[6];
        fVar9 = pfVar17[7];
        pfVar17[4] = fVar2 - fVar6;
        pfVar17[5] = fVar3 - fVar7;
        pfVar17[6] = fVar4 - fVar8;
        pfVar17[7] = fVar5 - fVar9;
        fVar10 = pfVar17[8];
        fVar11 = pfVar17[9];
        fVar12 = pfVar17[10];
        fVar13 = pfVar17[0xb];
        pfVar18[-4] = fVar2 + fVar6;
        pfVar18[-3] = fVar3 + fVar7;
        pfVar18[-2] = fVar4 + fVar8;
        pfVar18[-1] = fVar5 + fVar9;
        fVar2 = *pfVar18;
        fVar3 = pfVar18[1];
        fVar4 = pfVar18[2];
        fVar5 = pfVar18[3];
        *pfVar18 = fVar10 + fVar2;
        pfVar18[1] = fVar11 + fVar3;
        pfVar18[2] = fVar12 + fVar4;
        pfVar18[3] = fVar13 + fVar5;
        pfVar18 = pfVar18 + 0x10;
        pfVar17[8] = fVar2 - fVar10;
        pfVar17[9] = fVar3 - fVar11;
        pfVar17[10] = fVar4 - fVar12;
        pfVar17[0xb] = fVar5 - fVar13;
        pfVar17 = pfVar17 + 0x10;
      } while (iVar19 < (int)(in_EDX - uVar16));
      if (in_EDX <= iVar19) {
        return;
      }
    }
    if (3 < in_EDX - iVar19) {
      pfVar18 = (float *)(in_ECX + (iVar19 + 3) * 4);
      pfVar17 = pfVar14 + iVar19 + 1;
      iVar15 = ((in_EDX - iVar19) - 4U >> 2) + 1;
      iVar19 = iVar19 + iVar15 * 4;
      do {
        fVar2 = pfVar17[-1];
        fVar3 = pfVar18[-3];
        pfVar18[-3] = fVar2 + fVar3;
        fVar4 = *pfVar17;
        pfVar17[-1] = fVar3 - fVar2;
        fVar2 = *(float *)((in_ECX - (int)pfVar14) + (int)pfVar17);
        *(float *)((in_ECX - (int)pfVar14) + (int)pfVar17) = fVar4 + fVar2;
        fVar3 = pfVar17[1];
        *pfVar17 = fVar2 - fVar4;
        fVar2 = pfVar18[-1];
        pfVar18[-1] = fVar3 + fVar2;
        fVar4 = pfVar17[2];
        pfVar17[1] = fVar2 - fVar3;
        fVar2 = *pfVar18;
        *pfVar18 = fVar4 + fVar2;
        pfVar18 = pfVar18 + 4;
        pfVar17[2] = fVar2 - fVar4;
        pfVar17 = pfVar17 + 4;
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      if (in_EDX <= iVar19) {
        return;
      }
    }
    iVar15 = in_EDX - iVar19;
    pfVar18 = pfVar14 + iVar19;
    do {
      fVar2 = *pfVar18;
      fVar3 = *(float *)((int)pfVar18 + (in_ECX - (int)pfVar14));
      *(float *)((int)pfVar18 + (in_ECX - (int)pfVar14)) = fVar2 + fVar3;
      *pfVar18 = fVar3 - fVar2;
      pfVar18 = pfVar18 + 1;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  return;
}

