
void FUN_1000dd00(float *param_1)

{
  float fVar1;
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
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  uint uVar33;
  float *in_ECX;
  float *in_EDX;
  
  uVar33 = DAT_1005000c ^ (uint)&stack0xfffffff0;
  __CheckForDebuggerJustMyCode(&DAT_1417050e);
  if (in_EDX == (float *)0x0) {
    _wassert(L"pSource",
             L"C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.18362.0\\um\\DirectXMathConvert.inl"
             ,0x495);
  }
  fVar1 = *in_EDX;
  fVar2 = in_EDX[1];
  fVar3 = in_EDX[2];
  fVar4 = in_EDX[3];
  fVar5 = in_EDX[4];
  fVar6 = in_EDX[5];
  fVar7 = in_EDX[6];
  fVar8 = in_EDX[7];
  fVar25 = in_EDX[8];
  fVar26 = in_EDX[9];
  fVar27 = in_EDX[10];
  fVar28 = in_EDX[0xb];
  fVar29 = in_EDX[0xc];
  fVar30 = in_EDX[0xd];
  fVar31 = in_EDX[0xe];
  fVar32 = in_EDX[0xf];
  if (param_1 == (float *)0x0) {
    _wassert(L"pSource",
             L"C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.18362.0\\um\\DirectXMathConvert.inl"
             ,0x495);
  }
  fVar9 = param_1[0xc];
  fVar10 = param_1[0xd];
  fVar11 = param_1[0xe];
  fVar12 = param_1[0xf];
  fVar13 = param_1[4];
  fVar14 = param_1[5];
  fVar15 = param_1[6];
  fVar16 = param_1[7];
  fVar17 = *param_1;
  fVar18 = param_1[1];
  fVar19 = param_1[2];
  fVar20 = param_1[3];
  fVar21 = param_1[8];
  fVar22 = param_1[9];
  fVar23 = param_1[10];
  fVar24 = param_1[0xb];
  FUN_1000dc80();
  if (in_ECX == (float *)0x0) {
    _wassert(L"pDestination",
             L"C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.18362.0\\um\\DirectXMathConvert.inl"
             ,0x831);
  }
  *in_ECX = fVar4 * fVar9 + fVar2 * fVar13 + fVar3 * fVar21 + fVar1 * fVar17;
  in_ECX[1] = fVar4 * fVar10 + fVar2 * fVar14 + fVar3 * fVar22 + fVar1 * fVar18;
  in_ECX[2] = fVar4 * fVar11 + fVar2 * fVar15 + fVar3 * fVar23 + fVar1 * fVar19;
  in_ECX[3] = fVar4 * fVar12 + fVar2 * fVar16 + fVar3 * fVar24 + fVar1 * fVar20;
  in_ECX[4] = fVar8 * fVar9 + fVar6 * fVar13 + fVar7 * fVar21 + fVar5 * fVar17;
  in_ECX[5] = fVar8 * fVar10 + fVar6 * fVar14 + fVar7 * fVar22 + fVar5 * fVar18;
  in_ECX[6] = fVar8 * fVar11 + fVar6 * fVar15 + fVar7 * fVar23 + fVar5 * fVar19;
  in_ECX[7] = fVar8 * fVar12 + fVar6 * fVar16 + fVar7 * fVar24 + fVar5 * fVar20;
  in_ECX[8] = fVar28 * fVar9 + fVar26 * fVar13 + fVar27 * fVar21 + fVar25 * fVar17;
  in_ECX[9] = fVar28 * fVar10 + fVar26 * fVar14 + fVar27 * fVar22 + fVar25 * fVar18;
  in_ECX[10] = fVar28 * fVar11 + fVar26 * fVar15 + fVar27 * fVar23 + fVar25 * fVar19;
  in_ECX[0xb] = fVar28 * fVar12 + fVar26 * fVar16 + fVar27 * fVar24 + fVar25 * fVar20;
  in_ECX[0xc] = fVar32 * fVar9 + fVar30 * fVar13 + fVar31 * fVar21 + fVar29 * fVar17;
  in_ECX[0xd] = fVar32 * fVar10 + fVar30 * fVar14 + fVar31 * fVar22 + fVar29 * fVar18;
  in_ECX[0xe] = fVar32 * fVar11 + fVar30 * fVar15 + fVar31 * fVar23 + fVar29 * fVar19;
  in_ECX[0xf] = fVar32 * fVar12 + fVar30 * fVar16 + fVar31 * fVar24 + fVar29 * fVar20;
  __security_check_cookie(uVar33 ^ (uint)&stack0xfffffff0);
  return;
}

