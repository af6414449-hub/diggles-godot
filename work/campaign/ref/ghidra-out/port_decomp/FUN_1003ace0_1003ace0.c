
void FUN_1003ace0(int param_1,int param_2,int param_3)

{
  float fVar1;
  float *pfVar2;
  int in_ECX;
  float *pfVar3;
  int in_EDX;
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
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  fVar1 = *(float *)(param_2 + (param_3 >> 3) * 4);
  pfVar2 = (float *)(in_EDX + param_1 * 4);
  pfVar3 = pfVar2 + in_ECX * -0x10;
  for (; pfVar3 < pfVar2; pfVar2 = pfVar2 + -0x10) {
    fVar13 = pfVar2[-1] - pfVar2[-9];
    fVar10 = pfVar2[-9] + pfVar2[-1];
    fVar4 = *pfVar2 - pfVar2[-8];
    fVar6 = pfVar2[-8] + *pfVar2;
    fVar17 = pfVar2[-3] - pfVar2[-0xb];
    fVar11 = pfVar2[-0xb] + pfVar2[-3];
    fVar7 = pfVar2[-2] - pfVar2[-10];
    fVar14 = pfVar2[-10] + pfVar2[-2];
    fVar15 = pfVar2[-0xe] - pfVar2[-6];
    fVar12 = pfVar2[-6] + pfVar2[-0xe];
    fVar5 = (fVar17 + fVar7) * fVar1;
    fVar8 = pfVar2[-5] - pfVar2[-0xd];
    fVar18 = (fVar17 - fVar7) * fVar1;
    fVar7 = pfVar2[-0xc] - pfVar2[-4];
    fVar20 = pfVar2[-4] + pfVar2[-0xc];
    fVar17 = pfVar2[-7] - pfVar2[-0xf];
    fVar16 = pfVar2[-0xf] + pfVar2[-7];
    fVar21 = pfVar2[-0xd] + pfVar2[-5];
    fVar9 = fVar6 - fVar20;
    fVar20 = fVar20 + fVar6;
    fVar19 = (fVar17 + fVar15) * fVar1;
    fVar17 = (fVar15 - fVar17) * fVar1;
    fVar6 = fVar12 + fVar14;
    fVar14 = fVar14 - fVar12;
    fVar12 = fVar11 - fVar16;
    fVar16 = fVar16 + fVar11;
    *pfVar2 = fVar6 + fVar20;
    pfVar2[-2] = fVar20 - fVar6;
    fVar6 = fVar10 - fVar21;
    fVar21 = fVar21 + fVar10;
    pfVar2[-4] = fVar12 + fVar9;
    pfVar2[-6] = fVar9 - fVar12;
    fVar9 = fVar4 + fVar8;
    fVar4 = fVar4 - fVar8;
    pfVar2[-1] = fVar16 + fVar21;
    pfVar2[-3] = fVar21 - fVar16;
    pfVar2[-7] = fVar6 + fVar14;
    fVar12 = fVar19 + fVar5;
    pfVar2[-5] = fVar6 - fVar14;
    fVar5 = fVar5 - fVar19;
    fVar14 = fVar18 - fVar17;
    fVar17 = fVar17 + fVar18;
    pfVar2[-8] = fVar12 + fVar9;
    pfVar2[-10] = fVar9 - fVar12;
    pfVar2[-0xc] = fVar14 + fVar4;
    pfVar2[-0xe] = fVar4 - fVar14;
    fVar4 = fVar13 + fVar7;
    fVar13 = fVar13 - fVar7;
    pfVar2[-9] = fVar17 + fVar4;
    pfVar2[-0xb] = fVar4 - fVar17;
    pfVar2[-0xd] = fVar13 - fVar5;
    pfVar2[-0xf] = fVar13 + fVar5;
  }
  return;
}

