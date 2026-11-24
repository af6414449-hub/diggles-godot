
void FUN_005e4ab0(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  float fVar3;
  double dVar4;
  float fVar5;
  float fVar6;
  undefined4 local_30;
  float local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = (int)ROUND(*(float *)(DAT_00772400 + 0x354) * 8.0);
  local_10 = *(float *)(DAT_00772400 + 0x350) * 8.0;
  DAT_00772dd8 = (int)ROUND(local_10);
  if ((((PTR_0077241c->x0_8 + 0x10 <= DAT_00772dd8) && (DAT_00772dd8 < PTR_0077241c->x1_8 + -0x10))
      && (PTR_0077241c->y0_8 + 0x10 <= iVar1)) && (iVar1 < PTR_0077241c->y1_8 + -0x10)) {
    local_24 = (float)(int)*(float *)(DAT_00772400 + 0x350) + 0.5;
    local_20 = (float)(int)*(float *)(DAT_00772400 + 0x354) + 0.5;
    fVar5 = (float)(int)((*(float *)(DAT_00772400 + 0x358) + 1.0) * 0.5);
    local_8 = (fVar5 + fVar5) - 1.0;
    local_18 = local_20;
    local_c = local_24;
    uVar2 = FUN_004093f0(PTR_0077241c);
    local_10 = (float)(uVar2 & 0xff);
    uVar2 = FUN_004093f0(PTR_0077241c);
    fVar5 = local_10;
    fVar3 = (float)(uVar2 & 0xff);
    dVar4 = (double)((float)((int)fVar3 - (int)local_10) * 4.0 * 0.5);
    FUN_006f57f0();
    fVar6 = (float)dVar4;
    local_14 = local_8;
    DAT_00772dd8 = (int)ROUND(local_8);
    local_10 = fVar6;
    if (0.0 < fVar6) {
      FUN_004089f0();
      if ((uint)fVar3 < (uint)fVar5) {
        fVar3 = fVar5;
      }
      local_24 = local_c - (fVar6 * (float)(((int)(((int)fVar3 - DAT_00772dd8) +
                                                  ((int)fVar3 - DAT_00772dd8 >> 0x1f & 3U)) >> 2) *
                                            2 + 1) + 0.01);
      fVar5 = local_10;
      local_c = local_24;
      FUN_004089d0();
      local_8 = local_8 - (fVar5 + fVar5);
    }
    local_2c = local_10;
    if (local_10 < 0.0) {
      local_2c = -1.5707964;
    }
    local_1c = local_8 + 0.01;
    local_30 = *(undefined4 *)(in_ECX + 0x40);
    local_28 = *(undefined4 *)(in_ECX + 0x48);
    local_8 = local_1c;
    FUN_005cd840(&local_30);
    if (((*(float *)(in_ECX + 0xc) != local_c) || (*(float *)(in_ECX + 0x10) != local_18)) ||
       (*(float *)(in_ECX + 0x14) != local_8)) {
      FUN_005cd8e0(&local_24);
      if (*(int *)(in_ECX + 0x238) == 0) {
        FUN_005ebc90();
        FUN_005eb470(in_ECX);
      }
    }
  }
  return;
}

