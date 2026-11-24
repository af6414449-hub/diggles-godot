
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1003af80(int param_1,int param_2)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  uint uVar11;
  float *pfVar12;
  ushort *puVar13;
  float *pfVar14;
  float *in_ECX;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int in_EDX;
  float *pfVar19;
  int iVar20;
  int iVar21;
  float *pfVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  int local_44;
  int local_3c;
  float *local_2c;
  float *local_24;
  uint local_20;
  uint local_18;
  float *local_10;
  float *local_c;
  
  uVar7 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar15 = in_EDX >> 2;
  iVar8 = in_EDX >> 1;
  iVar16 = in_EDX >> 3;
  iVar5 = *(int *)(param_1 + 0x68);
  if (*(int *)(param_1 + 0x5c) == 0) {
    local_2c = (float *)&stack0xffffffa4;
  }
  else {
    iVar17 = iVar5 - (iVar8 * 4 + 7U & 0xfffffff8);
    if (iVar17 < *(int *)(param_1 + 100)) {
      local_2c = (float *)0x0;
    }
    else {
      local_2c = (float *)(*(int *)(param_1 + 0x5c) + iVar17);
      *(int *)(param_1 + 0x68) = iVar17;
    }
  }
  pfVar19 = *(float **)(param_1 + 0x438 + param_2 * 4);
  pfVar22 = local_2c + iVar8 + -2;
  pfVar12 = pfVar19;
  pfVar14 = in_ECX;
  if (in_ECX != in_ECX + iVar8) {
    do {
      pfVar22[1] = *pfVar12 * *pfVar14 - pfVar12[1] * pfVar14[2];
      fVar23 = *pfVar12;
      pfVar9 = pfVar12 + 1;
      pfVar12 = pfVar12 + 2;
      pfVar1 = pfVar14 + 2;
      fVar24 = *pfVar14;
      pfVar14 = pfVar14 + 4;
      *pfVar22 = fVar23 * *pfVar1 + *pfVar9 * fVar24;
      pfVar22 = pfVar22 + -2;
    } while (pfVar14 != in_ECX + iVar8);
  }
  pfVar14 = in_ECX + iVar8 + -3;
  for (; local_2c <= pfVar22; pfVar22 = pfVar22 + -2) {
    pfVar22[1] = -pfVar14[2] * *pfVar12 - -*pfVar14 * pfVar12[1];
    fVar23 = *pfVar14;
    pfVar9 = pfVar12 + 1;
    fVar24 = *pfVar12;
    pfVar12 = pfVar12 + 2;
    pfVar1 = pfVar14 + 2;
    pfVar14 = pfVar14 + -4;
    *pfVar22 = -fVar23 * fVar24 - *pfVar9 * *pfVar1;
  }
  pfVar12 = pfVar19 + iVar8 + -8;
  if (pfVar19 <= pfVar12) {
    pfVar14 = local_2c + iVar15 + 2;
    pfVar22 = in_ECX + 1;
    pfVar9 = (float *)(((2 - iVar15) * 4 - (int)in_ECX) + (int)(in_ECX + iVar15) + (int)local_2c);
    local_24 = in_ECX + iVar15;
    do {
      fVar23 = pfVar14[-2];
      fVar25 = pfVar14[-1] - *(float *)(((int)local_2c - (int)in_ECX) + (int)pfVar22);
      fVar24 = pfVar9[-2];
      local_24[1] = pfVar14[-1] + *(float *)(((int)local_2c - (int)in_ECX) + (int)pfVar22);
      *local_24 = pfVar9[-2] + pfVar14[-2];
      *pfVar22 = pfVar12[4] * fVar25 - pfVar12[5] * (fVar23 - fVar24);
      pfVar22[-1] = pfVar12[4] * (fVar23 - fVar24) + pfVar12[5] * fVar25;
      fVar23 = *pfVar14;
      fVar26 = pfVar14[1] - pfVar9[1];
      fVar24 = *pfVar9;
      local_24[3] = pfVar9[1] + pfVar14[1];
      fVar25 = *pfVar9;
      pfVar9 = pfVar9 + 4;
      *(float *)(((int)in_ECX - (int)local_2c) + (int)pfVar14) = *pfVar14 + fVar25;
      pfVar14 = pfVar14 + 4;
      pfVar22[2] = *pfVar12 * fVar26 - (fVar23 - fVar24) * pfVar12[1];
      fVar25 = *pfVar12;
      pfVar1 = pfVar12 + 1;
      pfVar12 = pfVar12 + -8;
      pfVar22[1] = fVar25 * (fVar23 - fVar24) + fVar26 * *pfVar1;
      pfVar22 = pfVar22 + 4;
      local_24 = local_24 + 4;
    } while (pfVar19 <= pfVar12);
  }
  iVar17 = FUN_10038070();
  iVar10 = iVar8 + -1;
  FUN_1003a6f0(iVar10,-iVar16,pfVar19);
  FUN_1003a6f0((iVar8 - iVar15) + -1,-iVar16,pfVar19);
  iVar20 = -(in_EDX >> 4);
  FUN_1003a8e0(iVar10,iVar20,pfVar19,0x10);
  FUN_1003a8e0((iVar8 - iVar16) + -1,iVar20,pfVar19,0x10);
  FUN_1003a8e0(iVar8 + iVar16 * -2 + -1,iVar20,pfVar19,0x10);
  FUN_1003a8e0(iVar8 + iVar16 * -3 + -1,iVar20,pfVar19,0x10);
  local_3c = 2;
  local_44 = 2;
  iVar16 = iVar17 + -4 >> 1;
  if (2 < iVar16) {
    local_18 = 4;
    do {
      iVar20 = in_EDX >> ((char)local_44 + 2U & 0x1f);
      local_18 = local_18 << 1 | (uint)((int)local_18 < 0);
      if (0 < (int)local_18) {
        bVar6 = (char)local_44 + 3U & 0x1f;
        iVar21 = iVar10;
        local_20 = local_18;
        do {
          FUN_1003a8e0(iVar21,-(iVar20 >> 1),pfVar19,1 << bVar6 | 1U >> 0x20 - bVar6);
          iVar21 = iVar21 - iVar20;
          local_20 = local_20 - 1;
        } while (local_20 != 0);
      }
      local_3c = local_44 + 1;
      local_44 = local_3c;
    } while (local_3c < iVar16);
  }
  if (local_3c < iVar17 + -7) {
    bVar6 = (byte)local_3c & 0x1f;
    uVar11 = 1 << bVar6 | 1U >> 0x20 - bVar6;
    iVar16 = local_3c + 6;
    local_3c = (iVar17 + -7) - local_3c;
    do {
      iVar17 = in_EDX >> ((byte)iVar16 - 4 & 0x1f);
      uVar18 = uVar11 << 3 | uVar11 >> 0x1d;
      uVar11 = uVar11 << 1 | (uint)((int)uVar11 < 0);
      iVar20 = in_EDX >> ((byte)iVar16 & 0x1f);
      if (0 < iVar20) {
        pfVar12 = pfVar19;
        iVar21 = iVar10;
        do {
          FUN_1003aad0(iVar21,-(iVar17 >> 1),pfVar12,uVar18,iVar17);
          iVar20 = iVar20 + -1;
          pfVar12 = pfVar12 + uVar18 * 4;
          iVar21 = iVar21 + -8;
        } while (0 < iVar20);
      }
      iVar16 = iVar16 + 1;
      local_3c = local_3c + -1;
    } while (local_3c != 0);
  }
  FUN_1003ace0(iVar10,pfVar19,in_EDX);
  puVar13 = *(ushort **)(param_1 + 0x458 + param_2 * 4);
  pfVar12 = local_2c + iVar8 + -4;
  pfVar19 = local_2c + iVar15 + -4;
  if (local_2c <= pfVar19) {
    pfVar22 = (float *)(((6 - iVar15) * 4 - (int)local_2c) + (int)pfVar12 + (int)pfVar19);
    do {
      uVar11 = (uint)*puVar13;
      pfVar22[1] = in_ECX[uVar11];
      *pfVar22 = in_ECX[uVar11 + 1];
      pfVar19[3] = in_ECX[uVar11 + 2];
      pfVar19[2] = in_ECX[uVar11 + 3];
      uVar11 = (uint)puVar13[1];
      pfVar22[-1] = in_ECX[uVar11];
      pfVar22[-2] = in_ECX[uVar11 + 1];
      pfVar19[1] = in_ECX[uVar11 + 2];
      *pfVar19 = in_ECX[uVar11 + 3];
      pfVar19 = pfVar19 + -4;
      puVar13 = puVar13 + 2;
      pfVar22 = pfVar22 + -4;
    } while (local_2c <= pfVar19);
  }
  if (local_2c < pfVar12) {
    pfVar22 = (float *)(*(int *)(param_1 + 0x448 + param_2 * 4) + 8);
    pfVar19 = local_2c + 2;
    do {
      fVar23 = pfVar19[-1] + pfVar12[3];
      fVar25 = pfVar19[-2] - pfVar12[2];
      fVar24 = pfVar19[-2] + pfVar12[2];
      fVar26 = pfVar22[-2] * fVar23 + pfVar22[-1] * fVar25;
      fVar25 = pfVar22[-1] * fVar23 - pfVar22[-2] * fVar25;
      fVar23 = pfVar19[-1] - pfVar12[3];
      pfVar19[-2] = fVar24 + fVar26;
      pfVar19[-1] = fVar23 + fVar25;
      pfVar12[2] = fVar24 - fVar26;
      pfVar12[3] = fVar25 - fVar23;
      fVar23 = *pfVar22;
      pfVar14 = pfVar22 + 1;
      fVar24 = pfVar19[1] + pfVar12[1];
      pfVar22 = pfVar22 + 4;
      fVar27 = *pfVar19 - *pfVar12;
      fVar28 = *pfVar14 * fVar24 - fVar23 * fVar27;
      fVar26 = *pfVar19 + *pfVar12;
      fVar25 = pfVar19[1] - pfVar12[1];
      fVar23 = *pfVar14 * fVar27 + fVar23 * fVar24;
      *pfVar19 = fVar26 + fVar23;
      pfVar19[1] = fVar25 + fVar28;
      *pfVar12 = fVar26 - fVar23;
      pfVar12[1] = fVar28 - fVar25;
      pfVar12 = pfVar12 + -4;
      pfVar14 = pfVar19 + 2;
      pfVar19 = pfVar19 + 4;
    } while (pfVar14 < pfVar12);
  }
  pfVar12 = in_ECX + iVar8 + -4;
  pfVar19 = local_2c + iVar8 + -8;
  if (local_2c <= pfVar19) {
    pfVar22 = in_ECX + 2;
    pfVar14 = (float *)(*(int *)(param_1 + 0x440 + param_2 * 4) + iVar8 * 4 + -8);
    local_10 = pfVar12 + (in_EDX - iVar8) + 2;
    local_c = in_ECX + iVar8 + 2;
    do {
      fVar23 = pfVar14[1] * pfVar19[6] - pfVar19[7] * *pfVar14;
      fVar24 = -pfVar19[6] * *pfVar14 - pfVar14[1] * pfVar19[7];
      pfVar22[-2] = fVar23;
      pfVar12[3] = -fVar23;
      local_c[-2] = fVar24;
      local_10[1] = fVar24;
      fVar23 = pfVar14[-1] * pfVar19[4] - pfVar14[-2] * pfVar19[5];
      fVar24 = -pfVar19[4] * pfVar14[-2] - pfVar14[-1] * pfVar19[5];
      pfVar22[-1] = fVar23;
      pfVar12[2] = -fVar23;
      local_c[-1] = fVar24;
      *local_10 = fVar24;
      fVar23 = pfVar14[-3] * pfVar19[2] - pfVar14[-4] * pfVar19[3];
      fVar24 = -pfVar19[2] * pfVar14[-4] - pfVar14[-3] * pfVar19[3];
      *pfVar22 = fVar23;
      pfVar12[1] = -fVar23;
      *local_c = fVar24;
      local_10[-1] = fVar24;
      pfVar9 = pfVar14 + -5;
      fVar23 = *pfVar19;
      pfVar1 = pfVar14 + -6;
      pfVar2 = pfVar19 + 1;
      pfVar3 = pfVar19 + 1;
      pfVar19 = pfVar19 + -8;
      pfVar4 = pfVar14 + -6;
      pfVar14 = pfVar14 + -8;
      fVar24 = *pfVar9 * fVar23 - *pfVar1 * *pfVar2;
      fVar23 = -fVar23 * *pfVar4 - *pfVar9 * *pfVar3;
      pfVar22[1] = fVar24;
      *pfVar12 = -fVar24;
      pfVar22 = pfVar22 + 4;
      local_c[1] = fVar23;
      pfVar12 = pfVar12 + -4;
      local_10[-2] = fVar23;
      local_10 = local_10 + -4;
      local_c = local_c + 4;
    } while (local_2c <= pfVar19);
  }
  *(int *)(param_1 + 0x68) = iVar5;
  __security_check_cookie(uVar7 ^ (uint)&stack0xfffffffc);
  return;
}

