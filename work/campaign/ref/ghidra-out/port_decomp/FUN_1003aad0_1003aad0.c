
void FUN_1003aad0(int param_1,int param_2,float *param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int in_ECX;
  float *pfVar9;
  int in_EDX;
  float *pfVar10;
  float fVar11;
  float fVar12;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  fVar1 = *param_3;
  fVar2 = param_3[param_4 + 1];
  fVar3 = param_3[param_4];
  fVar4 = param_3[1];
  fVar5 = param_3[param_4 * 2];
  fVar6 = param_3[param_4 * 2 + 1];
  fVar7 = param_3[param_4 * 3];
  fVar8 = param_3[param_4 * 3 + 1];
  pfVar10 = (float *)(in_EDX + (param_1 + param_2) * 4);
  if (0 < in_ECX) {
    pfVar9 = (float *)((int)pfVar10 - (param_2 * 4 + 8));
    do {
      fVar12 = pfVar9[2] - *pfVar10;
      fVar11 = pfVar9[1] - pfVar10[-1];
      pfVar9[2] = pfVar9[2] + *pfVar10;
      pfVar9[1] = pfVar9[1] + pfVar10[-1];
      *pfVar10 = fVar12 * fVar1 - fVar11 * fVar4;
      pfVar10[-1] = fVar12 * fVar4 + fVar11 * fVar1;
      fVar12 = *pfVar9 - pfVar10[-2];
      fVar11 = pfVar9[-1] - pfVar10[-3];
      *pfVar9 = *pfVar9 + pfVar10[-2];
      pfVar9[-1] = pfVar9[-1] + pfVar10[-3];
      pfVar10[-2] = fVar12 * fVar3 - fVar11 * fVar2;
      pfVar10[-3] = fVar12 * fVar2 + fVar11 * fVar3;
      fVar12 = pfVar9[-2] - pfVar10[-4];
      fVar11 = pfVar9[-3] - pfVar10[-5];
      pfVar9[-2] = pfVar9[-2] + pfVar10[-4];
      pfVar9[-3] = pfVar9[-3] + pfVar10[-5];
      pfVar10[-4] = fVar12 * fVar5 - fVar11 * fVar6;
      pfVar10[-5] = fVar12 * fVar6 + fVar11 * fVar5;
      fVar12 = pfVar9[-4] - pfVar10[-6];
      fVar11 = pfVar9[-5] - pfVar10[-7];
      pfVar9[-4] = pfVar9[-4] + pfVar10[-6];
      pfVar9[-5] = pfVar9[-5] + pfVar10[-7];
      pfVar10[-6] = fVar12 * fVar7 - fVar11 * fVar8;
      pfVar10[-7] = fVar12 * fVar8 + fVar11 * fVar7;
      pfVar10 = pfVar10 + -param_5;
      in_ECX = in_ECX + -1;
      pfVar9 = pfVar9 + -param_5;
    } while (0 < in_ECX);
  }
  return;
}

