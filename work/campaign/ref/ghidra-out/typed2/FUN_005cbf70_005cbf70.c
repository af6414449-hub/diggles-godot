
void FUN_005cbf70(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  int in_ECX;
  uint uVar9;
  CMap *this;
  int iVar10;
  int iVar11;
  float *pfVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int local_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(char *)(DAT_00772400 + 0x5c0) != '\0') {
    FUN_005ba7a0();
    iVar6 = in_ECX + 0x28c;
    if (((*(int *)(in_ECX + 0x28c) != -1) && (DAT_00772418 != 0)) &&
       ((*(byte *)(in_ECX + 0x3d0) & 1) != 0)) {
      fVar7 = *(float *)(in_ECX + 0x48);
      FUN_004089d0();
      fVar8 = *(float *)(in_ECX + 0x48);
      local_c = fVar7;
      FUN_004089f0();
      fVar7 = *(float *)(in_ECX + 0x40);
      local_10 = *(float *)(in_ECX + 0x284) * local_c + *(float *)(in_ECX + 0x280) * fVar8;
      local_8 = *(float *)(in_ECX + 0x284) * fVar8 - *(float *)(in_ECX + 0x280) * local_c;
      FUN_004089d0();
      fVar8 = *(float *)(in_ECX + 0x40);
      local_c = fVar7;
      FUN_004089f0();
      fVar7 = *(float *)(in_ECX + 0x44);
      local_14 = *(float *)(in_ECX + 0x288) * fVar8 - local_8 * local_c;
      local_1c = fVar8;
      FUN_004089d0();
      fVar8 = *(float *)(in_ECX + 0x44);
      local_18 = fVar7;
      FUN_004089f0();
      pfVar12 = &fStack_28;
      uVar17 = *(undefined4 *)(in_ECX + 0x294);
      fStack_28 = (local_10 * fVar8 - local_14 * local_18) + *(float *)(in_ECX + 0xc);
      uVar16 = *(undefined4 *)(in_ECX + 0x290);
      fStack_20 = local_14 * fVar8 + local_10 * local_18 + *(float *)(in_ECX + 0x14);
      uVar15 = *(undefined4 *)(in_ECX + 0x2a0);
      uVar14 = *(undefined4 *)(in_ECX + 0x29c);
      uVar13 = *(undefined4 *)(in_ECX + 0x298);
      fStack_24 = local_8 * local_1c + *(float *)(in_ECX + 0x288) * local_c +
                  *(float *)(in_ECX + 0x10);
      FUN_00592d70(iVar6,pfVar12,uVar13,uVar14,uVar15,uVar16,uVar17);
      FUN_00591a20(iVar6,pfVar12,uVar13,uVar14,uVar15,uVar16,uVar17);
    }
    iVar6 = DAT_00772400;
    if (*(char *)(DAT_00772400 + 0x590) != '\0') {
      *(uint *)(in_ECX + 0x3d0) = *(uint *)(in_ECX + 0x3d0) | 0x600;
    }
    if (((*(int *)(in_ECX + 0xe8) == 1) && ((*(byte *)(in_ECX + 0x3d0) & 0x20) != 0)) &&
       (*(char *)(iVar6 + 0x590) == '\0')) {
      uVar17 = 0;
      FUN_005b28d0(0);
      iVar4 = FUN_005b3680(uVar17);
      iVar6 = DAT_00772400;
      if ((*(int *)(DAT_00772400 + 100) == iVar4) &&
         (uVar5 = *(uint *)(DAT_00772400 + 0x6c), 10 < (int)uVar5)) {
        uVar9 = uVar5 & 0x80000003;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
        }
        if (uVar9 == 1) {
          uVar5 = (int)(uVar5 + ((int)uVar5 >> 0x1f & 3U)) >> 2 & 0x80000003;
          if ((int)uVar5 < 0) {
            uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
          }
          uVar9 = *(uint *)(in_ECX + 0xdc) & 0x80000003;
          if ((int)uVar9 < 0) {
            uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
          }
          if (uVar5 == uVar9) {
            FUN_005cd520();
            iVar6 = DAT_00772400;
          }
        }
      }
    }
    if (*(char *)(iVar6 + 0x3d3) != '\0') {
      iVar4 = *(int *)(iVar6 + 100);
      if ((*(int *)(in_ECX + 0x378) != iVar4) && ((*(int *)(in_ECX + 0x378) != -1 || (iVar4 != 0))))
      {
        if (*(int *)(in_ECX + 0x36c) != -1) {
          return;
        }
        if (iVar4 != 0) {
          return;
        }
      }
    }
    if (*(int *)(in_ECX + 0xe8) == 1) {
      FUN_005cb760();
      iVar6 = DAT_00772400;
    }
    if (((*(uint *)(in_ECX + 0x3d0) & 0x20000) != 0) && ((*(uint *)(in_ECX + 0x3d0) & 0x4000) == 0))
    {
      if ((100 < (int)*(uint *)(iVar6 + 0x6c)) &&
         (((*(uint *)(in_ECX + 0xdc) ^ *(uint *)(iVar6 + 0x6c)) & 0xf) == 0)) {
        fStack_28 = *(float *)(in_ECX + 0xc);
        fStack_24 = *(float *)(in_ECX + 0x10);
        local_8 = (float)(int)ROUND(fStack_28 * 8.0);
        local_1c = fStack_24 * 8.0;
        iVar6 = (int)ROUND(local_1c);
        DAT_00772dd8 = iVar6;
        cVar1 = FUN_00409450(local_8,iVar6,4);
        if (cVar1 != '\0') {
          bVar2 = FUN_004093f0(this);
          local_1c = (float)((int)local_8 + -2);
          bVar3 = FUN_004093f0(PTR_0077241c);
          if (bVar3 <= bVar2) {
            bVar2 = FUN_004093f0(PTR_0077241c);
          }
          local_1c = (float)((int)local_8 + 2);
          bVar3 = FUN_004093f0(PTR_0077241c);
          if (bVar3 <= bVar2) {
            bVar2 = FUN_004093f0(PTR_0077241c);
          }
          bVar3 = FUN_004093f0(PTR_0077241c);
          if (bVar3 <= bVar2) {
            bVar2 = FUN_004093f0(PTR_0077241c);
          }
          local_1c = (float)(iVar6 + 2);
          bVar3 = FUN_004093f0(PTR_0077241c);
          if (bVar3 <= bVar2) {
            bVar2 = FUN_004093f0(PTR_0077241c);
          }
          fStack_20 = (float)bVar2 + 0.01;
          FUN_005cd7e0(&fStack_28);
        }
      }
      if ((*(int *)(*(int *)(in_ECX + 0xd4) + 0x54) == 0) &&
         ((*(float *)(in_ECX + 0x14) <= 0.02 && *(float *)(in_ECX + 0x14) != 0.02 ||
          (((((FUN_005cb250(&local_2c), PTR_0077241c->cellY0 <= (int)fStack_28 &&
              ((int)fStack_20 < PTR_0077241c->cellY1)) && (PTR_0077241c->cellX0 <= local_2c)) &&
            (((int)fStack_24 < PTR_0077241c->cellX1 &&
             (iVar6 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar6 + 0x18) & 3) == 0)))) &&
           ((iVar6 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar6 + 0x18) & 3) == 0 &&
            ((iVar6 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar6 + 0x18) & 3) == 0 &&
             (iVar6 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar6 + 0x18) & 3) == 0)))))))))) {
        *(uint *)(in_ECX + 0x3d0) = *(uint *)(in_ECX + 0x3d0) & 0xfffdffff;
      }
    }
    if (((*(int *)(in_ECX + 0x264) != 0) || (*(int *)(in_ECX + 0x268) != 0)) &&
       (*(int *)(in_ECX + 0x3ec) == 0)) {
      fVar7 = *(float *)(in_ECX + 0xc);
      if ((((int)(*(float *)(in_ECX + 0x18) * 8.0) == (int)(fVar7 * 8.0)) &&
          ((int)(*(float *)(in_ECX + 0x1c) * 8.0) == (int)(*(float *)(in_ECX + 0x10) * 8.0))) ||
         ((*(byte *)(in_ECX + 0x3d0) & 1) == 0)) {
        if (((*(uint *)(in_ECX + 0x3d4) ^ *(uint *)(in_ECX + 0x3d0)) & 1) == 0) {
          return;
        }
      }
      else {
        if (DAT_00772428 == 0) {
          return;
        }
        uVar17 = 7;
        iVar11 = (int)(*(float *)(in_ECX + 0x18) * -8.0);
        iVar10 = (int)(*(float *)(in_ECX + 0x1c) * -8.0);
        iVar6 = *(int *)(in_ECX + 0x254) - iVar11;
        iVar4 = *(int *)(in_ECX + 0x260) - iVar10;
        fVar7 = (float)(*(int *)(in_ECX + 600) - iVar10);
        iVar11 = *(int *)(in_ECX + 0x25c) - iVar11;
        local_2c = iVar6;
        fStack_28 = fVar7;
        fStack_24 = (float)iVar11;
        fStack_20 = (float)iVar4;
        FUN_005a3dd0(iVar6,fVar7,iVar11,iVar4,7);
        FUN_005a3fd0(iVar6,fVar7,iVar11,iVar4,uVar17);
        fVar7 = *(float *)(in_ECX + 0xc);
      }
      iVar6 = *(int *)(in_ECX + 0x254) - (int)(fVar7 * -8.0);
      iVar11 = (int)(*(float *)(in_ECX + 0x10) * -8.0);
      uVar17 = 7;
      iVar4 = *(int *)(in_ECX + 0x260) - iVar11;
      fVar8 = (float)(*(int *)(in_ECX + 600) - iVar11);
      iVar11 = *(int *)(in_ECX + 0x25c) - (int)(fVar7 * -8.0);
      local_2c = iVar6;
      fStack_28 = fVar8;
      fStack_24 = (float)iVar11;
      fStack_20 = (float)iVar4;
      FUN_005a3dd0(iVar6,fVar8,iVar11,iVar4,7);
      FUN_005a3fd0(iVar6,fVar8,iVar11,iVar4,uVar17);
    }
  }
  return;
}

