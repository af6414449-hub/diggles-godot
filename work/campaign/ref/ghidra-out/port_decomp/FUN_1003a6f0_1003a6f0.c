
void FUN_1003a6f0(int param_1,int param_2,float *param_3)

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
  float fVar8;
  
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
      pfVar4[-1] = param_3[1] * fVar7 + *param_3 * fVar6;
      fVar7 = *pfVar3 - pfVar4[-2];
      fVar6 = pfVar3[-1] - pfVar4[-3];
      *pfVar3 = *pfVar3 + pfVar4[-2];
      pfVar3[-1] = pfVar3[-1] + pfVar4[-3];
      pfVar4[-2] = param_3[8] * fVar7 - param_3[9] * fVar6;
      pfVar4[-3] = param_3[9] * fVar7 + param_3[8] * fVar6;
      fVar6 = pfVar3[-3];
      fVar8 = pfVar3[-2] - pfVar4[-4];
      fVar7 = pfVar4[-5];
      pfVar3[-2] = pfVar3[-2] + pfVar4[-4];
      pfVar3[-3] = pfVar4[-5] + pfVar3[-3];
      pfVar4[-4] = param_3[0x10] * fVar8 - param_3[0x11] * (fVar6 - fVar7);
      pfVar4[-5] = param_3[0x11] * fVar8 + param_3[0x10] * (fVar6 - fVar7);
      fVar6 = pfVar3[-5];
      fVar8 = pfVar3[-4] - pfVar4[-6];
      fVar7 = pfVar4[-7];
      pfVar3[-4] = pfVar4[-6] + pfVar3[-4];
      pfVar3[-5] = pfVar4[-7] + pfVar3[-5];
      pfVar4[-6] = param_3[0x18] * fVar8 - param_3[0x19] * (fVar6 - fVar7);
      iVar5 = iVar5 + -1;
      pfVar1 = param_3 + 0x19;
      pfVar3 = pfVar3 + -8;
      pfVar2 = param_3 + 0x18;
      param_3 = param_3 + 0x20;
      pfVar4[-7] = *pfVar1 * fVar8 + *pfVar2 * (fVar6 - fVar7);
      pfVar4 = pfVar4 + -8;
    } while (0 < iVar5);
  }
  return;
}

