
void FUN_10023b00(int param_1)

{
  float fVar1;
  float *pfVar2;
  int in_ECX;
  int in_EDX;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if (0 < param_1) {
    pfVar2 = (float *)(in_EDX + 0x18);
    pfVar3 = (float *)(in_ECX + 0x1c);
    do {
      fVar5 = pfVar3[8];
      fVar1 = pfVar3[-7];
      fVar4 = pfVar3[-4];
      fVar6 = pfVar2[-5];
      fVar9 = pfVar2[-4];
      fVar7 = pfVar2[-3];
      pfVar3[-7] = pfVar2[-6];
      pfVar3[-6] = fVar6;
      pfVar3[-5] = fVar9;
      pfVar3[-4] = fVar7;
      *(undefined8 *)(pfVar3 + -3) = *(undefined8 *)(pfVar2 + -2);
      fVar6 = pfVar3[2] + pfVar3[5];
      fVar11 = -fVar1 + fVar6;
      fVar7 = -fVar1 - fVar6 * 0.5;
      fVar6 = (fVar4 + pfVar3[-1]) * 0.8660254;
      fVar4 = pfVar3[-1] - fVar4;
      fVar1 = *pfVar2;
      fVar8 = fVar7 - fVar6;
      fVar7 = fVar7 + fVar6;
      fVar6 = (pfVar3[5] - pfVar3[2]) * 0.8660254;
      fVar9 = fVar5 - fVar4 * 0.5;
      fVar10 = fVar9 - fVar6;
      fVar9 = fVar9 + fVar6;
      fVar6 = fVar9 * 0.7933533 + fVar7 * 0.6087614;
      *pfVar2 = fVar7 * 0.7933533 - fVar9 * 0.6087614;
      pfVar3[-1] = fVar1 * 0.9914449 - fVar6 * 0.13052619;
      pfVar3[4] = fVar6 * 0.9914449 + fVar1 * 0.13052619;
      fVar1 = pfVar2[1];
      fVar5 = -(fVar5 + fVar4);
      fVar4 = fVar5 * 0.9238795 + fVar11 * 0.38268343;
      pfVar2[1] = fVar11 * 0.9238795 - fVar5 * 0.38268343;
      *pfVar3 = fVar1 * 0.9238795 - fVar4 * 0.38268343;
      pfVar3[3] = fVar4 * 0.9238795 + fVar1 * 0.38268343;
      fVar1 = pfVar2[2];
      fVar5 = fVar10 * 0.9914449 + fVar8 * 0.13052619;
      pfVar2[2] = fVar8 * 0.9914449 - fVar10 * 0.13052619;
      pfVar3[1] = fVar1 * 0.7933533 - fVar5 * 0.6087614;
      pfVar3[2] = fVar5 * 0.7933533 + fVar1 * 0.6087614;
      FUN_100238e0(pfVar2);
      FUN_100238e0(pfVar2);
      param_1 = param_1 + -1;
      pfVar2 = pfVar2 + 9;
      pfVar3 = pfVar3 + 0x12;
    } while (0 < param_1);
  }
  return;
}

