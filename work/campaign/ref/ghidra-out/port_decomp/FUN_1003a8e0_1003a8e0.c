
void FUN_1003a8e0(int param_1,int param_2,float *param_3,int param_4)

{
  float *pfVar1;
  float *pfVar2;
  int in_ECX;
  float *pfVar3;
  int in_EDX;
  float *pfVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar5 = in_ECX >> 2;
  pfVar4 = (float *)(in_EDX + (param_1 + param_2) * 4);
  if (0 < iVar5) {
    pfVar3 = (float *)((int)pfVar4 - (param_2 * 4 + 8));
    do {
      fVar7 = pfVar3[2] - *pfVar4;
      fVar6 = pfVar3[1] - pfVar4[-1];
      pfVar3[2] = *pfVar4 + pfVar3[2];
      pfVar3[1] = pfVar3[1] + pfVar4[-1];
      *pfVar4 = *param_3 * fVar7 - param_3[1] * fVar6;
      pfVar1 = param_3 + param_4;
      pfVar4[-1] = param_3[1] * fVar7 + *param_3 * fVar6;
      fVar7 = *pfVar3 - pfVar4[-2];
      fVar6 = pfVar3[-1] - pfVar4[-3];
      *pfVar3 = *pfVar3 + pfVar4[-2];
      pfVar3[-1] = pfVar3[-1] + pfVar4[-3];
      pfVar4[-2] = *pfVar1 * fVar7 - pfVar1[1] * fVar6;
      pfVar2 = pfVar1 + param_4;
      pfVar4[-3] = pfVar1[1] * fVar7 + *pfVar1 * fVar6;
      fVar7 = pfVar3[-2] - pfVar4[-4];
      fVar6 = pfVar3[-3] - pfVar4[-5];
      pfVar3[-2] = pfVar3[-2] + pfVar4[-4];
      pfVar3[-3] = pfVar3[-3] + pfVar4[-5];
      pfVar4[-4] = *pfVar2 * fVar7 - pfVar2[1] * fVar6;
      pfVar1 = pfVar2 + param_4;
      pfVar4[-5] = pfVar2[1] * fVar7 + *pfVar2 * fVar6;
      fVar7 = pfVar3[-4] - pfVar4[-6];
      fVar6 = pfVar3[-5] - pfVar4[-7];
      pfVar3[-4] = pfVar3[-4] + pfVar4[-6];
      pfVar3[-5] = pfVar3[-5] + pfVar4[-7];
      iVar5 = iVar5 + -1;
      pfVar3 = pfVar3 + -8;
      pfVar4[-6] = *pfVar1 * fVar7 - pfVar1[1] * fVar6;
      param_3 = pfVar1 + param_4;
      pfVar4[-7] = pfVar1[1] * fVar7 + *pfVar1 * fVar6;
      pfVar4 = pfVar4 + -8;
    } while (0 < iVar5);
  }
  return;
}

