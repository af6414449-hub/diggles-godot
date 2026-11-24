
void FUN_1001b970(uint param_1,int param_2,int param_3,uint param_4)

{
  float fVar1;
  float fVar2;
  double dVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  float *in_EDX;
  uint uVar11;
  float *pfVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float local_9c [8];
  float local_7c [4];
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c [4];
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float *local_3c;
  float *local_38;
  float local_34;
  float local_30;
  int local_2c;
  float *local_28;
  float local_24;
  float *local_20;
  float *local_1c;
  float *local_18;
  float *local_14;
  float *local_10;
  float *local_c;
  float *local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar8 = local_2c;
  uVar11 = 0;
  if (param_4 != 0) {
    fVar15 = *(float *)(local_2c + 0x3c);
    dVar3 = *(double *)(&DAT_10047c80 + ((int)param_1 >> 0x1f) * -8);
    pfVar7 = (float *)(local_2c + 0x18);
    do {
      fVar14 = pfVar7[0x51];
      fVar13 = fVar15 * *pfVar7;
      pfVar7 = pfVar7 + 1;
      local_7c[uVar11] = fVar14;
      local_9c[uVar11] = fVar13;
      local_5c[uVar11] = (fVar13 - fVar14) / (float)((double)(int)param_1 + dVar3);
      uVar11 = uVar11 + 1;
    } while (uVar11 < param_4);
  }
  switch(param_4) {
  case 1:
    local_10 = (float *)0x0;
    local_20 = (float *)0x0;
    if (*(int *)(local_2c + 0x48) != 0) {
      local_8 = (float *)(param_3 + 8);
      do {
        fVar15 = *(float *)(local_2c + 0x15c);
        uVar11 = 0;
        if (param_1 < 4) {
          if (param_1 != 0) goto LAB_1001bad6;
        }
        else {
          pfVar7 = in_EDX + 2;
          iVar8 = (param_1 - 4 >> 2) + 1;
          uVar11 = iVar8 * 4;
          pfVar10 = local_8;
          do {
            fVar14 = fVar15 + local_5c[0] + local_5c[0];
            pfVar7[-2] = pfVar10[-2] * (fVar15 + local_5c[0]) + pfVar7[-2];
            fVar13 = fVar14 + local_5c[0];
            pfVar7[-1] = pfVar10[-1] * fVar14 + pfVar7[-1];
            fVar15 = fVar13 + local_5c[0];
            *pfVar7 = fVar13 * *pfVar10 + *pfVar7;
            pfVar9 = pfVar10 + 1;
            pfVar10 = pfVar10 + 4;
            pfVar7[1] = *pfVar9 * fVar15 + pfVar7[1];
            pfVar7 = pfVar7 + 4;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          if (uVar11 < param_1) {
LAB_1001bad6:
            pfVar7 = (float *)(param_3 + ((int)local_20 + uVar11) * 4);
            do {
              fVar15 = fVar15 + local_5c[0];
              fVar14 = *pfVar7;
              pfVar7 = pfVar7 + 1;
              in_EDX[uVar11] = fVar15 * fVar14 + in_EDX[uVar11];
              uVar11 = uVar11 + 1;
            } while (uVar11 < param_1);
          }
        }
        local_10 = (float *)((int)local_10 + 1);
        local_8 = local_8 + param_2;
        local_20 = (float *)((int)local_20 + param_2);
      } while (local_10 < *(uint *)(local_2c + 0x48));
      uVar11 = 0;
      goto LAB_1001d2ea;
    }
    goto switchD_1001bb38_caseD_3;
  case 2:
    switch(*(undefined4 *)(iVar8 + 0x48)) {
    case 1:
      if (param_1 != 0) {
        param_3 = param_3 - (int)in_EDX;
        pfVar7 = in_EDX + param_2;
        do {
          fVar15 = *(float *)(param_3 + (int)in_EDX);
          local_7c[0] = local_7c[0] + local_5c[0];
          local_7c[1] = local_7c[1] + local_5c[1];
          *in_EDX = fVar15 * local_7c[0] + *in_EDX;
          in_EDX = in_EDX + 1;
          *pfVar7 = fVar15 * local_7c[1] + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
        } while (param_1 != 0);
      }
      break;
    case 2:
      if (param_1 == 0) break;
      param_3 = param_3 - (int)in_EDX;
      pfVar7 = in_EDX + param_2;
      do {
        fVar15 = *(float *)(param_3 + (int)pfVar7);
        local_7c[0] = local_7c[0] + local_5c[0];
        local_7c[1] = local_7c[1] + local_5c[1];
        *in_EDX = *(float *)(param_3 + (int)in_EDX) * local_7c[0] + *in_EDX;
        in_EDX = in_EDX + 1;
        *pfVar7 = fVar15 * local_7c[1] + *pfVar7;
        pfVar7 = pfVar7 + 1;
        param_1 = param_1 - 1;
      } while (param_1 != 0);
      uVar11 = 0;
      goto LAB_1001d2ea;
    case 4:
      if (param_1 != 0) {
        pfVar7 = in_EDX + param_2;
        pfVar10 = (float *)(param_3 + param_2 * 8);
        pfVar9 = (float *)(param_3 + param_2 * 0xc);
        param_3 = param_3 - (int)in_EDX;
        do {
          fVar15 = *(float *)(param_3 + (int)pfVar7);
          fVar14 = *pfVar9;
          local_7c[0] = local_7c[0] + local_5c[0];
          local_7c[1] = local_7c[1] + local_5c[1];
          pfVar9 = pfVar9 + 1;
          fVar13 = *pfVar10;
          pfVar10 = pfVar10 + 1;
          *in_EDX = (*(float *)(param_3 + (int)in_EDX) + fVar13) * 0.5 * local_7c[0] + *in_EDX;
          in_EDX = in_EDX + 1;
          *pfVar7 = (fVar14 + fVar15) * 0.5 * local_7c[1] + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
        } while (param_1 != 0);
        uVar11 = 0;
        goto LAB_1001d2ea;
      }
      break;
    case 6:
      if (param_1 != 0) {
        local_18 = (float *)(param_3 + param_2 * 0x14);
        pfVar10 = (float *)(param_2 * 0x10 + param_3);
        pfVar7 = in_EDX + param_2;
        local_1c = (float *)(param_3 + param_2 * 0xc);
        local_8 = (float *)(param_3 + param_2 * 8);
        param_3 = param_3 - (int)in_EDX;
        do {
          fVar15 = *(float *)(param_3 + (int)pfVar7);
          fVar14 = *local_18;
          local_18 = local_18 + 1;
          fVar13 = *local_8;
          local_7c[0] = local_7c[0] + local_5c[0];
          local_7c[1] = local_7c[1] + local_5c[1];
          local_8 = local_8 + 1;
          fVar17 = *local_1c;
          local_1c = local_1c + 1;
          fVar1 = *pfVar10;
          pfVar10 = pfVar10 + 1;
          *in_EDX = (*(float *)((int)in_EDX + param_3) + fVar13 + fVar17 + fVar1) * 0.3 *
                    local_7c[0] + *in_EDX;
          in_EDX = in_EDX + 1;
          *pfVar7 = (fVar13 + fVar15 + fVar17 + fVar14) * 0.3 * local_7c[1] + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
        } while (param_1 != 0);
        uVar11 = 0;
        goto LAB_1001d2ea;
      }
      break;
    case 8:
      if (param_1 != 0) {
        local_14 = (float *)(param_3 + param_2 * 0x18);
        pfVar7 = in_EDX + param_2;
        local_18 = (float *)(param_2 * 0x10 + param_3);
        local_1c = (float *)(param_3 + param_2 * 0x1c);
        local_20 = (float *)(param_3 + param_2 * 0x14);
        local_10 = (float *)(param_3 + param_2 * 0xc);
        local_8 = (float *)(param_3 + param_2 * 8);
        param_3 = param_3 - (int)in_EDX;
        do {
          pfVar9 = local_10;
          pfVar10 = local_20;
          fVar15 = *(float *)(param_3 + (int)pfVar7);
          local_7c[0] = local_7c[0] + local_5c[0];
          fVar14 = *local_8;
          local_7c[1] = local_7c[1] + local_5c[1];
          local_8 = local_8 + 1;
          local_10 = local_10 + 1;
          fVar13 = *pfVar9;
          local_20 = local_20 + 1;
          fVar17 = *pfVar10;
          fVar1 = *local_18;
          local_18 = local_18 + 1;
          fVar16 = *local_14;
          fVar2 = *local_1c;
          local_14 = local_14 + 1;
          local_1c = local_1c + 1;
          *in_EDX = (*(float *)(param_3 + (int)in_EDX) + fVar14 + fVar13 + fVar1 + fVar16) * 0.2 *
                    local_7c[0] + *in_EDX;
          in_EDX = in_EDX + 1;
          *pfVar7 = (fVar14 + fVar15 + fVar13 + fVar17 + fVar2) * 0.2 * local_7c[1] + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
        } while (param_1 != 0);
        uVar11 = 0;
        goto LAB_1001d2ea;
      }
    }
switchD_1001bb38_caseD_3:
    uVar11 = 0;
    goto LAB_1001d2ea;
  default:
switchD_1001ba00_caseD_3:
    uVar11 = 0;
    if (3 < param_4) break;
    goto LAB_1001d2e6;
  case 4:
    switch(*(undefined4 *)(iVar8 + 0x48)) {
    case 1:
      if (param_1 != 0) {
        local_18 = (float *)(param_3 - (int)in_EDX);
        pfVar7 = in_EDX + param_2 * 2;
        pfVar10 = in_EDX + param_2 * 3;
        pfVar9 = in_EDX + param_2;
        do {
          local_7c[0] = local_7c[0] + local_5c[0];
          local_7c[3] = local_7c[3] + local_5c[3];
          local_7c[1] = local_7c[1] + local_5c[1];
          local_7c[2] = local_7c[2] + local_5c[2];
          fVar15 = *(float *)((int)local_18 + (int)in_EDX);
          *in_EDX = local_7c[0] * fVar15 + *in_EDX;
          in_EDX = in_EDX + 1;
          *pfVar9 = local_7c[1] * fVar15 + *pfVar9;
          pfVar9 = pfVar9 + 1;
          *pfVar7 = local_7c[2] * fVar15 + *pfVar7;
          pfVar7 = pfVar7 + 1;
          *pfVar10 = local_7c[3] * fVar15 + *pfVar10;
          pfVar10 = pfVar10 + 1;
          param_1 = param_1 - 1;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    case 2:
      if (param_1 != 0) {
        pfVar7 = in_EDX + param_2 * 3;
        pfVar10 = in_EDX + param_2 * 2;
        pfVar9 = in_EDX + param_2;
        param_3 = param_3 - (int)in_EDX;
        do {
          local_7c[0] = local_7c[0] + local_5c[0];
          fVar15 = *(float *)(param_3 + (int)in_EDX);
          local_7c[3] = local_7c[3] + local_5c[3];
          fVar14 = *(float *)(param_3 + (int)pfVar9);
          local_7c[1] = local_7c[1] + local_5c[1];
          local_7c[2] = local_7c[2] + local_5c[2];
          *in_EDX = local_7c[0] * fVar15 + *in_EDX;
          in_EDX = in_EDX + 1;
          *pfVar9 = local_7c[1] * fVar14 + *pfVar9;
          pfVar9 = pfVar9 + 1;
          *pfVar10 = local_7c[2] * fVar15 + *pfVar10;
          pfVar10 = pfVar10 + 1;
          *pfVar7 = local_7c[3] * fVar14 + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    case 4:
      if (param_1 != 0) {
        param_3 = param_3 - (int)in_EDX;
        pfVar7 = in_EDX + param_2 * 2;
        pfVar10 = in_EDX + param_2 * 3;
        pfVar9 = in_EDX + param_2;
        do {
          local_7c[0] = local_7c[0] + local_5c[0];
          fVar15 = *(float *)(param_3 + (int)pfVar9);
          local_7c[1] = local_7c[1] + local_5c[1];
          fVar14 = *(float *)(param_3 + (int)pfVar7);
          fVar13 = *(float *)(param_3 + (int)pfVar10);
          local_7c[2] = local_7c[2] + local_5c[2];
          local_7c[3] = local_7c[3] + local_5c[3];
          *in_EDX = *(float *)(param_3 + (int)in_EDX) * local_7c[0] + *in_EDX;
          in_EDX = in_EDX + 1;
          *pfVar9 = fVar15 * local_7c[1] + *pfVar9;
          pfVar9 = pfVar9 + 1;
          *pfVar7 = fVar14 * local_7c[2] + *pfVar7;
          pfVar7 = pfVar7 + 1;
          *pfVar10 = fVar13 * local_7c[3] + *pfVar10;
          pfVar10 = pfVar10 + 1;
          param_1 = param_1 - 1;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    case 6:
      if (param_1 != 0) {
        pfVar7 = in_EDX + param_2 * 3;
        local_18 = in_EDX + param_2 * 2;
        local_8 = in_EDX + param_2;
        local_c = (float *)(param_3 + param_2 * 0x14);
        pfVar10 = (float *)(param_2 * 0x10 + param_3);
        param_3 = param_3 - (int)in_EDX;
        do {
          pfVar9 = local_c;
          local_7c[0] = local_5c[0] + local_7c[0];
          local_7c[1] = local_7c[1] + local_5c[1];
          fVar15 = *(float *)(param_3 + (int)local_8);
          fVar14 = *pfVar10;
          pfVar10 = pfVar10 + 1;
          fVar17 = (*(float *)(param_3 + (int)local_18) + *(float *)(param_3 + (int)pfVar7)) * 0.7;
          local_c = local_c + 1;
          fVar13 = *pfVar9;
          local_7c[2] = local_7c[2] + local_5c[2];
          local_7c[3] = local_7c[3] + local_5c[3];
          local_30 = local_7c[0];
          *in_EDX = *(float *)(param_3 + (int)in_EDX) * local_7c[0] + fVar17 + *in_EDX;
          in_EDX = in_EDX + 1;
          *local_8 = fVar15 * local_7c[1] + fVar17 + *local_8;
          local_8 = local_8 + 1;
          *local_18 = fVar14 * local_7c[2] + *local_18;
          local_18 = local_18 + 1;
          *pfVar7 = fVar13 * local_7c[3] + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    case 8:
      if (param_1 != 0) {
        pfVar7 = in_EDX + param_2 * 3;
        pfVar10 = in_EDX + param_2 * 2;
        local_c = in_EDX + param_2;
        local_20 = (float *)(param_3 + param_2 * 0x1c);
        local_10 = (float *)(param_3 + param_2 * 0x18);
        local_8 = (float *)(param_3 + param_2 * 0x14);
        pfVar9 = (float *)(param_2 * 0x10 + param_3);
        param_3 = param_3 - (int)in_EDX;
        do {
          pfVar5 = local_8;
          pfVar4 = local_10;
          pfVar12 = local_20;
          local_7c[0] = local_5c[0] + local_7c[0];
          local_7c[3] = local_7c[3] + local_5c[3];
          fVar15 = *(float *)(param_3 + (int)local_c);
          local_30 = local_7c[0];
          local_7c[1] = local_5c[1] + local_7c[1];
          local_8 = local_8 + 1;
          fVar14 = *pfVar5;
          fVar13 = *pfVar9;
          pfVar9 = pfVar9 + 1;
          local_10 = local_10 + 1;
          local_1c = (float *)local_7c[1];
          fVar17 = *pfVar4;
          local_7c[2] = local_5c[2] + local_7c[2];
          local_20 = local_20 + 1;
          fVar16 = (*(float *)(param_3 + (int)pfVar10) + *(float *)(param_3 + (int)pfVar7)) * 0.7;
          fVar1 = *pfVar12;
          local_18 = (float *)local_7c[2];
          *in_EDX = *(float *)((int)in_EDX + param_3) * local_7c[0] + fVar16 + *in_EDX;
          in_EDX = in_EDX + 1;
          *local_c = fVar15 * local_7c[1] + fVar16 + *local_c;
          local_c = local_c + 1;
          *pfVar10 = (fVar17 + fVar13) * 0.5 * local_7c[2] + *pfVar10;
          pfVar10 = pfVar10 + 1;
          *pfVar7 = (fVar1 + fVar14) * 0.5 * local_7c[3] + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
    }
    break;
  case 6:
    switch(*(undefined4 *)(iVar8 + 0x48)) {
    case 1:
      if (param_1 != 0) {
        pfVar7 = in_EDX + param_2 * 2;
        pfVar10 = in_EDX + param_2 * 5;
        local_14 = in_EDX + param_2;
        pfVar12 = in_EDX + param_2 * 4;
        pfVar9 = in_EDX + param_2 * 3;
        local_34 = (float)(param_3 - (int)in_EDX);
        do {
          local_7c[0] = local_7c[0] + local_5c[0];
          local_7c[1] = local_7c[1] + local_5c[1];
          local_7c[2] = local_7c[2] + local_5c[2];
          fVar15 = *(float *)((int)local_34 + (int)in_EDX);
          local_7c[3] = local_7c[3] + local_5c[3];
          local_6c = local_6c + local_4c;
          local_68 = local_68 + local_48;
          *in_EDX = fVar15 * local_7c[0] + *in_EDX;
          in_EDX = in_EDX + 1;
          *local_14 = local_7c[1] * fVar15 + *local_14;
          local_14 = local_14 + 1;
          *pfVar7 = local_7c[2] * fVar15 + *pfVar7;
          pfVar7 = pfVar7 + 1;
          *pfVar9 = local_7c[3] * fVar15 + *pfVar9;
          pfVar9 = pfVar9 + 1;
          *pfVar12 = local_6c * fVar15 + *pfVar12;
          pfVar12 = pfVar12 + 1;
          *pfVar10 = local_68 * fVar15 + *pfVar10;
          pfVar10 = pfVar10 + 1;
          param_1 = param_1 - 1;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    case 2:
      if (param_1 != 0) {
        pfVar7 = in_EDX + param_2 * 5;
        pfVar10 = in_EDX + param_2 * 3;
        pfVar12 = in_EDX + param_2 * 4;
        local_14 = in_EDX + param_2 * 2;
        pfVar9 = in_EDX + param_2;
        local_34 = (float)(param_3 - (int)in_EDX);
        do {
          local_7c[0] = local_5c[0] + local_7c[0];
          local_7c[1] = local_7c[1] + local_5c[1];
          local_7c[2] = local_7c[2] + local_5c[2];
          local_7c[3] = local_7c[3] + local_5c[3];
          fVar15 = *(float *)((int)local_34 + (int)in_EDX);
          fVar14 = *(float *)((int)local_34 + (int)pfVar9);
          local_24 = local_7c[0];
          local_6c = local_6c + local_4c;
          local_28 = (float *)local_7c[1];
          local_68 = local_68 + local_48;
          *in_EDX = fVar15 * local_7c[0] + *in_EDX;
          in_EDX = in_EDX + 1;
          fVar13 = (fVar14 + fVar15) * 0.5;
          *pfVar9 = local_7c[1] * fVar14 + *pfVar9;
          pfVar9 = pfVar9 + 1;
          *local_14 = fVar13 * local_7c[2] + *local_14;
          local_14 = local_14 + 1;
          *pfVar10 = fVar13 * local_7c[3] + *pfVar10;
          pfVar10 = pfVar10 + 1;
          *pfVar12 = local_6c * fVar15 + *pfVar12;
          pfVar12 = pfVar12 + 1;
          *pfVar7 = local_68 * fVar14 + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    case 4:
      if (param_1 != 0) {
        local_8 = in_EDX + param_2 * 5;
        pfVar7 = in_EDX + param_2 * 3;
        pfVar10 = in_EDX + param_2 * 2;
        pfVar9 = in_EDX + param_2 * 4;
        local_c = in_EDX + param_2;
        param_3 = param_3 - (int)in_EDX;
        do {
          pfVar4 = local_8;
          pfVar12 = local_c;
          local_7c[0] = local_5c[0] + local_7c[0];
          fVar15 = *(float *)(param_3 + (int)pfVar10);
          fVar14 = *(float *)(param_3 + (int)pfVar7);
          local_7c[3] = local_7c[3] + local_5c[3];
          local_6c = local_6c + local_4c;
          local_24 = local_7c[0];
          local_7c[1] = local_5c[1] + local_7c[1];
          local_c = local_c + 1;
          fVar13 = *(float *)(param_3 + (int)pfVar12);
          local_68 = local_68 + local_48;
          local_14 = (float *)local_7c[1];
          local_7c[2] = local_5c[2] + local_7c[2];
          fVar17 = *(float *)(param_3 + (int)in_EDX);
          local_28 = (float *)local_7c[2];
          *in_EDX = fVar17 * local_7c[0] + *in_EDX;
          in_EDX = in_EDX + 1;
          fVar17 = fVar13 + fVar17;
          *pfVar12 = local_7c[1] * fVar13 + *pfVar12;
          local_8 = local_8 + 1;
          *pfVar10 = fVar17 * 0.5 * local_7c[2] + *pfVar10;
          pfVar10 = pfVar10 + 1;
          *pfVar7 = (fVar17 + fVar15 + fVar14) * 0.25 * local_7c[3] + *pfVar7;
          pfVar7 = pfVar7 + 1;
          *pfVar9 = local_6c * fVar15 + *pfVar9;
          pfVar9 = pfVar9 + 1;
          param_1 = param_1 - 1;
          *pfVar4 = local_68 * fVar14 + *pfVar4;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    case 6:
      if (param_1 != 0) {
        pfVar7 = in_EDX + param_2 * 5;
        pfVar10 = in_EDX + param_2 * 3;
        pfVar9 = in_EDX + param_2 * 4;
        local_14 = in_EDX + param_2 * 2;
        local_c = in_EDX + param_2;
        local_34 = (float)(param_3 - (int)in_EDX);
        fVar15 = (float)(param_3 - (int)in_EDX);
        do {
          local_7c[0] = local_5c[0] + local_7c[0];
          local_7c[3] = local_7c[3] + local_5c[3];
          fVar14 = *(float *)((int)fVar15 + (int)pfVar10);
          fVar13 = *(float *)((int)fVar15 + (int)pfVar7);
          local_6c = local_6c + local_4c;
          local_1c = (float *)local_7c[0];
          local_7c[1] = local_5c[1] + local_7c[1];
          local_28 = (float *)local_7c[3];
          fVar17 = *(float *)((int)fVar15 + (int)local_c);
          fVar1 = *(float *)((int)fVar15 + (int)pfVar9);
          local_68 = local_68 + local_48;
          local_30 = local_7c[1];
          local_7c[2] = local_5c[2] + local_7c[2];
          fVar16 = *(float *)((int)fVar15 + (int)local_14);
          local_24 = local_7c[2];
          *in_EDX = *(float *)((int)fVar15 + (int)in_EDX) * local_7c[0] + *in_EDX;
          in_EDX = in_EDX + 1;
          *local_c = fVar17 * local_7c[1] + *local_c;
          local_c = local_c + 1;
          *local_14 = fVar16 * local_7c[2] + *local_14;
          local_14 = local_14 + 1;
          *pfVar10 = fVar14 * local_7c[3] + *pfVar10;
          pfVar10 = pfVar10 + 1;
          *pfVar9 = local_6c * fVar1 + *pfVar9;
          pfVar9 = pfVar9 + 1;
          *pfVar7 = local_68 * fVar13 + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
          fVar15 = local_34;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    case 8:
      if (param_1 != 0) {
        pfVar7 = in_EDX + param_2 * 5;
        pfVar10 = in_EDX + param_2 * 3;
        local_20 = in_EDX + param_2 * 2;
        local_10 = in_EDX + param_2;
        pfVar12 = in_EDX + param_2 * 4;
        local_8 = (float *)(param_3 + param_2 * 0x1c);
        local_c = (float *)(param_3 + param_2 * 0x18);
        local_28 = (float *)(param_3 - (int)in_EDX);
        pfVar9 = (float *)(param_3 - (int)in_EDX);
        do {
          pfVar5 = local_8;
          pfVar4 = local_c;
          local_68 = local_68 + local_48;
          local_7c[0] = local_5c[0] + local_7c[0];
          local_6c = local_6c + local_4c;
          fVar15 = *(float *)((int)pfVar9 + (int)pfVar7);
          local_7c[3] = local_7c[3] + local_5c[3];
          local_34 = local_68;
          fVar14 = *(float *)((int)pfVar9 + (int)local_10);
          local_14 = (float *)local_7c[0];
          local_7c[1] = local_5c[1] + local_7c[1];
          local_18 = (float *)local_6c;
          fVar13 = *(float *)((int)pfVar9 + (int)local_20);
          fVar17 = *(float *)((int)pfVar9 + (int)pfVar10);
          local_30 = local_7c[3];
          fVar1 = *(float *)((int)pfVar9 + (int)pfVar12);
          local_24 = local_7c[1];
          local_7c[2] = local_5c[2] + local_7c[2];
          local_c = local_c + 1;
          fVar16 = *pfVar4;
          local_8 = local_8 + 1;
          local_1c = (float *)local_7c[2];
          fVar2 = *pfVar5;
          *in_EDX = *(float *)((int)pfVar9 + (int)in_EDX) * local_7c[0] + *in_EDX;
          in_EDX = in_EDX + 1;
          *local_10 = fVar14 * local_7c[1] + *local_10;
          local_10 = local_10 + 1;
          *local_20 = fVar13 * local_7c[2] + *local_20;
          local_20 = local_20 + 1;
          *pfVar10 = fVar17 * local_7c[3] + *pfVar10;
          pfVar10 = pfVar10 + 1;
          *pfVar12 = (fVar16 + fVar1) * 0.5 * local_6c + *pfVar12;
          pfVar12 = pfVar12 + 1;
          *pfVar7 = (fVar2 + fVar15) * 0.5 * local_68 + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
          pfVar9 = local_28;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
    }
    break;
  case 8:
    switch(*(undefined4 *)(iVar8 + 0x48)) {
    case 1:
      if (param_1 == 0) goto switchD_1001ba00_caseD_3;
      local_3c = in_EDX + param_2 * 7;
      pfVar7 = in_EDX + param_2 * 4;
      local_1c = (float *)local_7c[0];
      local_38 = in_EDX + param_2 * 6;
      local_28 = in_EDX + param_2 * 5;
      local_18 = in_EDX + param_2 * 3;
      local_8 = in_EDX + param_2 * 2;
      local_c = in_EDX + param_2;
      local_34 = (float)(param_3 - (int)in_EDX);
      do {
        pfVar9 = local_8;
        pfVar10 = local_c;
        local_1c = (float *)(local_5c[0] + (float)local_1c);
        local_7c[2] = local_7c[2] + local_5c[2];
        local_7c[3] = local_7c[3] + local_5c[3];
        local_6c = local_6c + local_4c;
        local_7c[1] = local_5c[1] + local_7c[1];
        fVar15 = *(float *)((int)in_EDX + (int)local_34);
        local_68 = local_68 + local_48;
        local_64 = local_64 + local_44;
        local_60 = local_60 + local_40;
        local_14 = (float *)local_7c[1];
        local_c = local_c + 1;
        *in_EDX = (float)local_1c * fVar15 + *in_EDX;
        in_EDX = in_EDX + 1;
        *pfVar10 = local_7c[1] * fVar15 + *pfVar10;
        local_8 = local_8 + 1;
        *pfVar9 = local_7c[2] * fVar15 + *pfVar9;
        *local_18 = local_7c[3] * fVar15 + *local_18;
        local_18 = local_18 + 1;
        *pfVar7 = local_6c * fVar15 + *pfVar7;
        pfVar7 = pfVar7 + 1;
        *local_28 = local_68 * fVar15 + *local_28;
        local_28 = local_28 + 1;
        *local_38 = local_64 * fVar15 + *local_38;
        local_38 = local_38 + 1;
        *local_3c = local_60 * fVar15 + *local_3c;
        local_3c = local_3c + 1;
        param_1 = param_1 - 1;
        iVar8 = local_2c;
      } while (param_1 != 0);
      break;
    case 2:
      if (param_1 != 0) {
        local_3c = in_EDX + param_2 * 7;
        pfVar9 = in_EDX + param_2 * 4;
        local_18 = in_EDX + param_2 * 6;
        local_1c = (float *)local_7c[0];
        local_10 = in_EDX + param_2 * 5;
        local_8 = in_EDX + param_2 * 3;
        local_c = in_EDX + param_2 * 2;
        pfVar7 = in_EDX + param_2;
        local_38 = (float *)(param_3 - (int)in_EDX);
        pfVar10 = (float *)(param_3 - (int)in_EDX);
        do {
          pfVar5 = local_8;
          pfVar4 = local_c;
          pfVar12 = local_10;
          local_1c = (float *)(local_5c[0] + (float)local_1c);
          local_7c[3] = local_7c[3] + local_5c[3];
          local_6c = local_6c + local_4c;
          local_68 = local_68 + local_48;
          local_64 = local_64 + local_44;
          local_7c[1] = local_5c[1] + local_7c[1];
          local_14 = (float *)local_7c[3];
          fVar15 = *(float *)((int)pfVar10 + (int)pfVar7);
          local_60 = local_60 + local_40;
          local_30 = local_7c[1];
          local_7c[2] = local_5c[2] + local_7c[2];
          fVar14 = *(float *)((int)in_EDX + (int)pfVar10);
          local_c = local_c + 1;
          local_24 = local_7c[2];
          fVar13 = (fVar15 + fVar14) * 0.5;
          *in_EDX = (float)local_1c * fVar14 + *in_EDX;
          in_EDX = in_EDX + 1;
          *pfVar7 = local_7c[1] * fVar15 + *pfVar7;
          pfVar7 = pfVar7 + 1;
          *pfVar4 = local_7c[2] * fVar13 + *pfVar4;
          local_8 = local_8 + 1;
          *pfVar5 = local_7c[3] * fVar13 + *pfVar5;
          local_10 = local_10 + 1;
          *pfVar9 = local_6c * fVar14 + *pfVar9;
          pfVar9 = pfVar9 + 1;
          *pfVar12 = local_68 * fVar15 + *pfVar12;
          *local_18 = local_64 * fVar14 + *local_18;
          local_18 = local_18 + 1;
          *local_3c = local_60 * fVar15 + *local_3c;
          local_3c = local_3c + 1;
          param_1 = param_1 - 1;
          pfVar10 = local_38;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    default:
      goto switchD_1001ba00_caseD_3;
    case 4:
      if (param_1 != 0) {
        local_1c = in_EDX + param_2 * 7;
        pfVar9 = in_EDX + param_2 * 4;
        local_c = (float *)local_7c[0];
        local_20 = in_EDX + param_2 * 6;
        local_10 = in_EDX + param_2 * 5;
        pfVar7 = in_EDX + param_2 * 3;
        pfVar10 = in_EDX + param_2 * 2;
        local_8 = in_EDX + param_2;
        param_3 = param_3 - (int)in_EDX;
        do {
          pfVar6 = local_8;
          pfVar5 = local_10;
          pfVar4 = local_1c;
          pfVar12 = local_20;
          local_c = (float *)(local_5c[0] + (float)local_c);
          local_60 = local_60 + local_40;
          local_64 = local_64 + local_44;
          local_7c[3] = local_7c[3] + local_5c[3];
          local_7c[1] = local_5c[1] + local_7c[1];
          local_3c = (float *)local_60;
          fVar15 = *(float *)(param_3 + (int)in_EDX);
          fVar14 = *(float *)((int)pfVar7 + param_3);
          local_38 = (float *)local_64;
          fVar13 = *(float *)((int)local_8 + param_3);
          local_24 = local_7c[1];
          local_7c[2] = local_5c[2] + local_7c[2];
          local_18 = (float *)local_7c[3];
          fVar17 = *(float *)((int)pfVar10 + param_3);
          local_8 = local_8 + 1;
          local_6c = local_6c + local_4c;
          local_68 = local_68 + local_48;
          local_14 = (float *)local_7c[2];
          *in_EDX = fVar15 * (float)local_c + *in_EDX;
          in_EDX = in_EDX + 1;
          *pfVar6 = local_7c[1] * fVar13 + *pfVar6;
          local_10 = local_10 + 1;
          *pfVar10 = (fVar13 + fVar15) * 0.5 * local_7c[2] + *pfVar10;
          pfVar10 = pfVar10 + 1;
          *pfVar7 = (fVar13 + fVar15 + fVar17 + fVar14) * 0.25 * local_7c[3] + *pfVar7;
          pfVar7 = pfVar7 + 1;
          *pfVar9 = (fVar17 + fVar15) * 0.5 * local_6c + *pfVar9;
          pfVar9 = pfVar9 + 1;
          *pfVar5 = (fVar14 + fVar13) * 0.5 * local_68 + *pfVar5;
          local_20 = local_20 + 1;
          *pfVar12 = fVar17 * local_6c + *pfVar12;
          local_1c = local_1c + 1;
          param_1 = param_1 - 1;
          *pfVar4 = fVar14 * local_68 + *pfVar4;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    case 6:
      if (param_1 != 0) {
        local_20 = in_EDX + param_2 * 7;
        pfVar9 = in_EDX + param_2 * 4;
        local_c = (float *)local_7c[0];
        local_8 = in_EDX + param_2 * 6;
        pfVar7 = in_EDX + param_2 * 5;
        pfVar10 = in_EDX + param_2 * 3;
        local_18 = in_EDX + param_2 * 2;
        local_10 = in_EDX + param_2;
        local_34 = (float)(param_3 - (int)in_EDX);
        fVar15 = (float)(param_3 - (int)in_EDX);
        do {
          pfVar5 = local_8;
          pfVar4 = local_10;
          pfVar12 = local_20;
          local_c = (float *)(local_5c[0] + (float)local_c);
          local_6c = local_6c + local_4c;
          local_7c[3] = local_7c[3] + local_5c[3];
          local_68 = local_68 + local_48;
          local_7c[1] = local_5c[1] + local_7c[1];
          local_3c = (float *)local_6c;
          fVar14 = *(float *)((int)fVar15 + (int)in_EDX);
          fVar13 = *(float *)((int)fVar15 + (int)pfVar7);
          local_64 = local_64 + local_44;
          local_14 = (float *)local_7c[3];
          fVar17 = *(float *)((int)fVar15 + (int)local_10);
          local_30 = local_7c[1];
          local_7c[2] = local_5c[2] + local_7c[2];
          fVar1 = *(float *)((int)fVar15 + (int)pfVar9);
          local_38 = (float *)local_68;
          fVar16 = *(float *)((int)fVar15 + (int)pfVar10);
          local_24 = local_7c[2];
          local_28 = (float *)local_64;
          fVar15 = *(float *)((int)fVar15 + (int)local_18);
          local_10 = local_10 + 1;
          local_60 = local_60 + local_40;
          *in_EDX = fVar14 * (float)local_c + *in_EDX;
          in_EDX = in_EDX + 1;
          *pfVar4 = local_7c[1] * fVar17 + *pfVar4;
          local_8 = local_8 + 1;
          *local_18 = fVar15 * local_7c[2] + *local_18;
          local_18 = local_18 + 1;
          *pfVar10 = fVar16 * local_7c[3] + *pfVar10;
          pfVar10 = pfVar10 + 1;
          *pfVar9 = (fVar1 + fVar14) * 0.5 * local_6c + *pfVar9;
          pfVar9 = pfVar9 + 1;
          *pfVar7 = (fVar13 + fVar17) * 0.5 * local_68 + *pfVar7;
          pfVar7 = pfVar7 + 1;
          *pfVar5 = local_64 * fVar1 + *pfVar5;
          local_20 = local_20 + 1;
          param_1 = param_1 - 1;
          *pfVar12 = local_60 * fVar13 + *pfVar12;
          fVar15 = local_34;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
      break;
    case 8:
      if (param_1 != 0) {
        pfVar7 = in_EDX + param_2 * 7;
        pfVar12 = in_EDX + param_2 * 4;
        local_c = (float *)local_7c[0];
        pfVar10 = in_EDX + param_2 * 6;
        local_14 = in_EDX + param_2 * 5;
        local_8 = in_EDX + param_2 * 3;
        local_10 = in_EDX + param_2 * 2;
        local_20 = in_EDX + param_2;
        local_3c = (float *)(param_3 - (int)in_EDX);
        pfVar9 = (float *)(param_3 - (int)in_EDX);
        do {
          pfVar5 = local_10;
          pfVar4 = local_20;
          local_c = (float *)(local_5c[0] + (float)local_c);
          local_60 = local_60 + local_40;
          local_64 = local_64 + local_44;
          local_68 = local_68 + local_48;
          local_7c[3] = local_7c[3] + local_5c[3];
          local_6c = local_6c + local_4c;
          local_7c[1] = local_5c[1] + local_7c[1];
          local_38 = (float *)local_60;
          fVar15 = *(float *)((int)pfVar9 + (int)local_20);
          fVar14 = *(float *)((int)pfVar9 + (int)pfVar7);
          local_34 = local_64;
          local_18 = (float *)local_7c[1];
          fVar13 = *(float *)((int)pfVar9 + (int)local_10);
          local_7c[2] = local_5c[2] + local_7c[2];
          fVar17 = *(float *)((int)pfVar9 + (int)pfVar10);
          local_28 = (float *)local_68;
          fVar1 = *(float *)((int)pfVar9 + (int)local_8);
          local_1c = (float *)local_7c[2];
          local_30 = local_7c[3];
          fVar16 = *(float *)((int)pfVar9 + (int)local_14);
          local_24 = local_6c;
          fVar2 = *(float *)((int)pfVar9 + (int)pfVar12);
          *in_EDX = *(float *)((int)pfVar9 + (int)in_EDX) * (float)local_c + *in_EDX;
          in_EDX = in_EDX + 1;
          local_20 = local_20 + 1;
          *pfVar4 = fVar15 * local_7c[1] + *pfVar4;
          local_10 = local_10 + 1;
          *pfVar5 = fVar13 * local_7c[2] + *pfVar5;
          *local_8 = fVar1 * local_7c[3] + *local_8;
          local_8 = local_8 + 1;
          *pfVar12 = fVar2 * local_6c + *pfVar12;
          pfVar12 = pfVar12 + 1;
          *local_14 = fVar16 * local_68 + *local_14;
          local_14 = local_14 + 1;
          *pfVar10 = fVar17 * local_64 + *pfVar10;
          pfVar10 = pfVar10 + 1;
          *pfVar7 = fVar14 * local_60 + *pfVar7;
          pfVar7 = pfVar7 + 1;
          param_1 = param_1 - 1;
          pfVar9 = local_3c;
          iVar8 = local_2c;
        } while (param_1 != 0);
      }
    }
  }
  uVar11 = 0;
  pfVar7 = (float *)(iVar8 + 0x160);
  do {
    pfVar7[-1] = local_9c[uVar11];
    *pfVar7 = local_9c[uVar11 + 1];
    pfVar7[1] = local_9c[uVar11 + 2];
    iVar8 = uVar11 + 3;
    uVar11 = uVar11 + 4;
    pfVar7[2] = local_9c[iVar8];
    pfVar7 = pfVar7 + 4;
  } while (uVar11 < param_4 - 3);
LAB_1001d2e6:
  if (uVar11 < param_4) {
LAB_1001d2ea:
    pfVar7 = local_9c + uVar11;
    pfVar10 = (float *)(local_2c + 0x15c + uVar11 * 4);
    for (iVar8 = param_4 - uVar11; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pfVar10 = *pfVar7;
      pfVar7 = pfVar7 + 1;
      pfVar10 = pfVar10 + 1;
    }
  }
  return;
}

