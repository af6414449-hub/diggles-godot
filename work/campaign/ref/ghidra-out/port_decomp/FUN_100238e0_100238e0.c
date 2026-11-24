
void FUN_100238e0(float *param_1)

{
  float *in_ECX;
  float *in_EDX;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  fVar9 = -*in_ECX + in_ECX[9] + in_ECX[0xc];
  fVar3 = (in_ECX[3] + in_ECX[6]) * 0.8660254;
  fVar8 = -*in_ECX - (in_ECX[9] + in_ECX[0xc]) * 0.5;
  fVar4 = (in_ECX[0xc] - in_ECX[9]) * 0.8660254;
  fVar1 = fVar8 - fVar3;
  fVar8 = fVar8 + fVar3;
  fVar3 = in_ECX[0xf];
  fVar2 = in_ECX[6] - in_ECX[3];
  fVar6 = fVar3 - fVar2 * 0.5;
  fVar7 = fVar6 - fVar4;
  fVar6 = fVar6 + fVar4;
  fVar4 = *param_1;
  fVar5 = fVar6 * 0.7933533 + fVar8 * 0.6087614;
  *param_1 = fVar8 * 0.7933533 - fVar6 * 0.6087614;
  *in_EDX = fVar4 * 0.9914449 - fVar5 * 0.13052619;
  in_EDX[5] = fVar5 * 0.9914449 + fVar4 * 0.13052619;
  fVar4 = param_1[1];
  fVar3 = -(fVar3 + fVar2);
  fVar2 = fVar3 * 0.9238795 + fVar9 * 0.38268343;
  param_1[1] = fVar9 * 0.9238795 - fVar3 * 0.38268343;
  in_EDX[1] = fVar4 * 0.9238795 - fVar2 * 0.38268343;
  in_EDX[4] = fVar2 * 0.9238795 + fVar4 * 0.38268343;
  fVar3 = param_1[2];
  fVar4 = fVar7 * 0.9914449 + fVar1 * 0.13052619;
  param_1[2] = fVar1 * 0.9914449 - fVar7 * 0.13052619;
  in_EDX[2] = fVar3 * 0.7933533 - fVar4 * 0.6087614;
  in_EDX[3] = fVar4 * 0.7933533 + fVar3 * 0.6087614;
  return;
}

