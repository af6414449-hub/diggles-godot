
undefined4 FUN_0040c460(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int this;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  double dVar10;
  float local_28;
  float local_20;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = this->i_0c;
  fVar1 = *(float *)(iVar3 + 0xc);
  local_c = *(float *)(iVar3 + 0x40);
  fVar2 = *(float *)(iVar3 + 0x10);
  local_8 = *(float *)(iVar3 + 0x44);
  local_10 = *(float *)(iVar3 + 0x48);
  iVar4 = __isnan((double)local_c);
  if (iVar4 != 0) {
    local_c = 0.0;
  }
  iVar4 = __isnan((double)local_8);
  if (iVar4 != 0) {
    local_8 = 0.0;
  }
  iVar4 = __isnan((double)local_10);
  if (iVar4 != 0) {
    local_10 = 0.0;
  }
  for (; 3.1415927 < local_c; local_c = local_c - 6.2831855) {
  }
  for (; local_c <= -3.1415927; local_c = local_c + 6.2831855) {
  }
  for (; 3.1415927 < local_8; local_8 = local_8 - 6.2831855) {
  }
  for (; local_8 <= -3.1415927; local_8 = local_8 + 6.2831855) {
  }
  for (; 3.1415927 < local_10; local_10 = local_10 - 6.2831855) {
  }
  for (; local_10 <= -3.1415927; local_10 = local_10 + 6.2831855) {
  }
  fVar5 = local_8;
  FUN_005ab050();
  dVar10 = (double)fVar5;
  FUN_006f57f0();
  fVar6 = (float)dVar10;
  FUN_004089f0();
  fVar5 = this->f_38;
  FUN_004089f0();
  fVar6 = fVar6 * fVar5;
  FUN_005ab130();
  dVar10 = (double)fVar5;
  FUN_006f57f0();
  fVar7 = (float)dVar10;
  FUN_004089f0();
  fVar5 = this->f_38;
  FUN_004089d0();
  fVar7 = fVar7 * fVar5;
  FUN_005aae70();
  if (fVar5 <= 14.0) {
    fVar9 = fVar5;
    FUN_005ab050();
    dVar10 = (double)fVar9;
    FUN_006f57f0();
    local_14 = (float)dVar10;
    fVar9 = local_14;
    FUN_005ab130();
    dVar10 = (double)fVar9;
    FUN_006f57f0();
    fVar8 = this->f_38 + 3.1415927;
    fVar9 = 1.5707964;
    if (ABS(local_14) <= ABS((float)dVar10)) {
      fVar9 = 1.5707964 - (float)dVar10;
      local_14 = 0.0;
    }
    else {
      local_14 = -local_14;
    }
    local_20 = local_c - fVar9;
    iVar4 = __isnan((double)local_20);
    if (iVar4 == 0) {
      for (; 3.1415927 < local_20; local_20 = local_20 - 6.2831855) {
      }
      for (; local_20 <= -3.1415927; local_20 = local_20 + 6.2831855) {
      }
    }
    else {
      local_20 = 0.0;
    }
    local_28 = local_8 - fVar8;
    iVar4 = __isnan((double)local_28);
    if (iVar4 == 0) {
      for (; 3.1415927 < local_28; local_28 = local_28 - 6.2831855) {
      }
      for (; local_28 <= -3.1415927; local_28 = local_28 + 6.2831855) {
      }
    }
    else {
      local_28 = 0.0;
    }
    local_18 = local_10 - local_14;
    iVar4 = __isnan((double)local_18);
    if (iVar4 == 0) {
      for (; 3.1415927 < local_18; local_18 = local_18 - 6.2831855) {
      }
      for (; local_18 <= -3.1415927; local_18 = local_18 + 6.2831855) {
      }
    }
    else {
      local_18 = 0.0;
    }
    if (0.0 <= local_20) {
      if (0.0 < local_20) {
        fVar9 = (local_c - 0.02) - fVar9;
        iVar4 = __isnan((double)fVar9);
        if (iVar4 == 0) {
          for (; 3.1415927 < fVar9; fVar9 = fVar9 - 6.2831855) {
          }
          for (; fVar9 <= -3.1415927; fVar9 = fVar9 + 6.2831855) {
          }
        }
      }
    }
    else {
      fVar9 = (local_c + 0.02) - fVar9;
      iVar4 = __isnan((double)fVar9);
      if (iVar4 == 0) {
        for (; 3.1415927 < fVar9; fVar9 = fVar9 - 6.2831855) {
        }
        for (; fVar9 <= -3.1415927; fVar9 = fVar9 + 6.2831855) {
        }
      }
    }
    if (0.0 <= local_28) {
      if (0.0 < local_28) {
        fVar8 = (local_8 - 0.02) - fVar8;
        iVar4 = __isnan((double)fVar8);
        if (iVar4 == 0) {
          for (; 3.1415927 < fVar8; fVar8 = fVar8 - 6.2831855) {
          }
          for (; fVar8 <= -3.1415927; fVar8 = fVar8 + 6.2831855) {
          }
        }
      }
    }
    else {
      fVar8 = (local_8 + 0.02) - fVar8;
      iVar4 = __isnan((double)fVar8);
      if (iVar4 == 0) {
        for (; 3.1415927 < fVar8; fVar8 = fVar8 - 6.2831855) {
        }
        for (; fVar8 <= -3.1415927; fVar8 = fVar8 + 6.2831855) {
        }
      }
    }
    if (0.0 <= local_18) {
      if ((0.0 < local_18) && (iVar4 = __isnan((double)local_18), iVar4 == 0)) {
        for (; 3.1415927 < local_18; local_18 = local_18 - 6.2831855) {
        }
        for (; local_18 <= -3.1415927; local_18 = local_18 + 6.2831855) {
        }
      }
    }
    else {
      local_14 = (local_10 + 0.02) - local_14;
      iVar4 = __isnan((double)local_14);
      if (iVar4 == 0) {
        for (; 3.1415927 < local_14; local_14 = local_14 - 6.2831855) {
        }
        for (; local_14 <= -3.1415927; local_14 = local_14 + 6.2831855) {
        }
      }
    }
    if ((((*(float *)(iVar3 + 0xc) != fVar6 / 150.0 + fVar1) ||
         (*(float *)(iVar3 + 0x10) != fVar7 / 150.0 + fVar2)) || (*(float *)(iVar3 + 0x14) != fVar5)
        ) && (FUN_005cd8e0(), *(int *)(iVar3 + 0x238) == 0)) {
      FUN_005ebc90();
      FUN_005eb470();
    }
    FUN_005cd840();
    this->i_34 = this->i_34 + -1;
    if (0 < this->i_34) {
      return 1;
    }
    FUN_006b49b0(iVar3,this->i_1c,this->i_20,0,2);
  }
  return 0;
}

