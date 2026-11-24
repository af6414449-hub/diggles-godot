
void FUN_005e4d40(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  double dVar4;
  float fVar5;
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
  DAT_00772dd8 = (int)ROUND(*(float *)(DAT_00772400 + 0x350) * 8.0);
  if ((((PTR_0077241c->x0_8 + 0x10 <= DAT_00772dd8) && (DAT_00772dd8 < PTR_0077241c->x1_8 + -0x10))
      && (PTR_0077241c->y0_8 + 0x10 <= iVar1)) && (iVar1 < PTR_0077241c->y1_8 + -0x10)) {
    local_24 = (float)(int)*(float *)(DAT_00772400 + 0x350) + 0.5;
    local_20 = (float)(int)*(float *)(DAT_00772400 + 0x354) + 0.5;
    fVar5 = (float)(int)((*(float *)(DAT_00772400 + 0x358) + 1.0) * 0.5);
    local_c = (fVar5 + fVar5) - 1.0;
    local_18 = local_20;
    local_10 = (float)DAT_00772dd8;
    local_8 = local_24;
    uVar2 = FUN_004093f0(PTR_0077241c);
    uVar2 = uVar2 & 0xff;
    uVar3 = FUN_004093f0(PTR_0077241c);
    uVar3 = uVar3 & 0xff;
    dVar4 = (double)((float)(int)(uVar3 - uVar2) * 4.0 * 0.5);
    FUN_006f57f0();
    fVar5 = (float)dVar4;
    local_14 = local_c;
    DAT_00772dd8 = (int)ROUND(local_c);
    if (uVar3 < uVar2) {
      uVar3 = uVar2;
    }
    iVar1 = ((int)((uVar3 - DAT_00772dd8) + ((int)(uVar3 - DAT_00772dd8) >> 0x1f & 3U)) >> 2) * 2 +
            1;
    local_10 = fVar5;
    if (0.0 < fVar5) {
      FUN_004089f0();
      local_24 = local_8 - (fVar5 * (float)iVar1 + 0.01);
      fVar5 = local_10;
      local_8 = local_24;
      FUN_004089d0();
      local_c = local_c - (fVar5 + fVar5);
    }
    if (local_10 < 0.0) {
      fVar5 = local_10;
      FUN_004089f0();
      local_24 = (fVar5 * (float)iVar1 - 0.25) + 0.01 + local_8;
      fVar5 = local_10;
      local_8 = local_24;
      FUN_004089d0();
      local_c = local_c + fVar5 + fVar5;
    }
    local_1c = local_c + 0.01;
    local_30 = *(undefined4 *)(in_ECX + 0x40);
    local_28 = *(undefined4 *)(in_ECX + 0x48);
    local_2c = local_10;
    local_c = local_1c;
    FUN_005cd840(&local_30);
    if ((((*(float *)(in_ECX + 0xc) != local_8) || (*(float *)(in_ECX + 0x10) != local_18)) ||
        (*(float *)(in_ECX + 0x14) != local_c)) &&
       (FUN_005cd8e0(&local_24), *(int *)(in_ECX + 0x238) == 0)) {
      FUN_005ebc90();
      FUN_005eb470(in_ECX);
    }
  }
  return;
}

