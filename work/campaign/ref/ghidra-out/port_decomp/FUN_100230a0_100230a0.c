
/* WARNING: Removing unreachable block (ram,0x10023115) */
/* WARNING: Removing unreachable block (ram,0x100230ed) */

void FUN_100230a0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  uint uVar19;
  float *pfVar20;
  int in_ECX;
  float *pfVar21;
  int in_EDX;
  float *pfVar22;
  float *pfVar23;
  float *pfVar24;
  int local_14;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if (0 < in_EDX) {
    pfVar24 = (float *)(in_ECX + 0x48);
    local_14 = in_EDX;
    do {
      if ((DAT_1416f070 == 0) && (piVar4 = (int *)cpuid_basic_info(0), 0 < *piVar4)) {
        iVar5 = cpuid_Version_info(1);
        uVar19 = *(uint *)(iVar5 + 8) & 0x4000000;
        DAT_1416f070 = uVar19 + 1;
      }
      else {
        uVar19 = DAT_1416f070 - 1;
      }
      pfVar20 = (float *)&DAT_10047050;
      pfVar21 = pfVar24;
      pfVar23 = pfVar24;
      if (uVar19 == 0) {
        do {
          pfVar23 = pfVar23 + -1;
          fVar1 = *pfVar21;
          fVar2 = *pfVar23;
          *pfVar21 = pfVar20[-8] * fVar1 - *pfVar20 * fVar2;
          pfVar22 = pfVar20 + -8;
          fVar3 = *pfVar20;
          pfVar20 = pfVar20 + 1;
          *pfVar23 = *pfVar22 * fVar2 + fVar3 * fVar1;
          pfVar21 = pfVar21 + 1;
        } while ((int)pfVar20 < 0x10047070);
      }
      else {
        do {
          pfVar22 = pfVar23 + -4;
          fVar1 = *pfVar22;
          fVar2 = pfVar23[-3];
          fVar3 = pfVar23[-2];
          fVar6 = pfVar23[-1];
          fVar7 = pfVar20[-8];
          fVar8 = pfVar20[-7];
          fVar9 = pfVar20[-6];
          fVar10 = pfVar20[-5];
          fVar11 = *pfVar20;
          fVar12 = pfVar20[1];
          fVar13 = pfVar20[2];
          fVar14 = pfVar20[3];
          pfVar20 = pfVar20 + 4;
          fVar15 = *pfVar21;
          fVar16 = pfVar21[1];
          fVar17 = pfVar21[2];
          fVar18 = pfVar21[3];
          *pfVar21 = fVar7 * fVar15 - fVar11 * fVar6;
          pfVar21[1] = fVar8 * fVar16 - fVar12 * fVar3;
          pfVar21[2] = fVar9 * fVar17 - fVar13 * fVar2;
          pfVar21[3] = fVar10 * fVar18 - fVar14 * fVar1;
          *pfVar22 = fVar10 * fVar1 + fVar14 * fVar18;
          pfVar23[-3] = fVar9 * fVar2 + fVar13 * fVar17;
          pfVar23[-2] = fVar8 * fVar3 + fVar12 * fVar16;
          pfVar23[-1] = fVar7 * fVar6 + fVar11 * fVar15;
          pfVar21 = pfVar21 + 4;
          pfVar23 = pfVar22;
        } while ((int)pfVar20 < 0x10047070);
      }
      pfVar24 = pfVar24 + 0x12;
      local_14 = local_14 + -1;
    } while (0 < local_14);
  }
  return;
}

