
void __thiscall FUN_005e9700(int this)

{
  int *piVar1;
  float fVar2;
  CHeightBlockArray *pCVar3;
  CMap *pCVar4;
  uint uVar5;
  undefined4 *puVar6;
  float *pfVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  CMapCell *pCVar11;
  undefined1 uVar12;
  int iVar13;
  CHeightBlock *pCVar14;
  int iVar15;
  bool bVar16;
  float *pfVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined1 local_290 [64];
  float local_250 [32];
  float *local_1d0;
  float *pfStack_1cc;
  float *pfStack_1c8;
  float *pfStack_1c4;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c;
  float local_198;
  float local_194;
  float local_190;
  float fStack_18c;
  float fStack_188;
  float fStack_184;
  float local_180;
  float fStack_17c;
  float fStack_178;
  float fStack_174;
  float local_170;
  float fStack_16c;
  float fStack_168;
  float fStack_164;
  float local_160;
  float fStack_15c;
  float fStack_158;
  float fStack_154;
  float *local_14c;
  float *local_148;
  float *local_144;
  float *local_140;
  float local_13c;
  uint local_138;
  int local_134;
  float *local_130;
  float *local_12c;
  float local_128;
  float local_124;
  CMap *local_120;
  float local_11c;
  float *local_118;
  float local_114;
  float *local_110;
  float *local_10c;
  float *local_108;
  int *local_104;
  float *local_100;
  float *local_fc;
  byte local_f5;
  float *local_f4;
  float local_f0 [23];
  float local_94;
  float local_90 [24];
  undefined1 local_30 [4];
  float local_2c [2];
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  int local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_00709339;
  local_1c = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  fVar20 = *(float *)(this + 0x58) + 0.0;
  *(float *)(this + 0x5c) = *(float *)(this + 0x5c) + 0.125;
  *(float *)(this + 0x58) = fVar20;
  *(float *)(this + 0x60) = *(float *)(this + 0x60) + 0.0;
  if (4.0 <= fVar20) {
LAB_005e979e:
    fVar20 = 4.0;
  }
  else if (-4.0 < fVar20) {
    if (4.0 <= fVar20) goto LAB_005e979e;
  }
  else {
    fVar20 = -4.0;
  }
  fVar18 = *(float *)(this + 0x5c);
  if (4.0 <= fVar18) {
    fVar18 = 4.0;
  }
  *(float *)(this + 0x58) = fVar20;
  if (fVar18 <= -4.0) {
    fVar18 = -4.0;
  }
  *(float *)(this + 0x5c) = fVar18;
  fVar20 = *(float *)(this + 0x60);
  if (4.0 <= fVar20) {
    fVar20 = 4.0;
  }
  if (fVar20 <= -4.0) {
    fVar20 = -4.0;
  }
  *(float *)(this + 0x60) = fVar20;
  local_fc = *(float **)(this + 0x68);
  local_11c = *(float *)(this + 0x6c);
  local_120 = *(CMap **)(this + 0x70);
  local_134 = this;
  local_24 = uVar5;
  _eh_vector_constructor_iterator_(local_f0,0xc,8,FUN_00405b50,guard_check_icall);
  local_14 = 0;
  puVar6 = (undefined4 *)FUN_004156b0(local_250,this + 0x18);
  local_128 = (float)local_fc + *(float *)(this + 0x58);
  local_250[0x10] = (float)*puVar6;
  local_250[0x11] = (float)puVar6[1];
  local_250[0x12] = (float)puVar6[2];
  local_250[0x13] = (float)puVar6[3];
  local_250[0x14] = (float)puVar6[4];
  local_250[0x15] = (float)puVar6[5];
  local_250[0x16] = (float)puVar6[6];
  local_250[0x17] = (float)puVar6[7];
  local_12c = (float *)(*(float *)(this + 0x5c) + local_11c);
  local_250[0x18] = (float)puVar6[8];
  local_250[0x19] = (float)puVar6[9];
  local_250[0x1a] = (float)puVar6[10];
  local_250[0x1b] = (float)puVar6[0xb];
  local_250[0x1c] = (float)puVar6[0xc];
  local_250[0x1d] = (float)puVar6[0xd];
  local_250[0x1e] = (float)puVar6[0xe];
  local_250[0x1f] = (float)puVar6[0xf];
  local_118 = (float *)(*(float *)(this + 0x60) + (float)local_120);
  if ((((local_128 < PTR_0077241c->x0f + 12.0) || (PTR_0077241c->x1f - 12.0 <= local_128)) ||
      ((float)local_12c < PTR_0077241c->y0f + 12.0)) ||
     (PTR_0077241c->y1f - 12.0 <= (float)local_12c)) {
    *(undefined1 *)(this + 100) = 1;
    goto LAB_005ea809;
  }
  local_190 = *(float *)(this + 0xf8);
  fStack_18c = *(float *)(this + 0xfc);
  fStack_188 = *(float *)(this + 0x100);
  fStack_184 = *(float *)(this + 0x104);
  local_180 = *(float *)(this + 0x108);
  fStack_17c = *(float *)(this + 0x10c);
  fStack_178 = *(float *)(this + 0x110);
  fStack_174 = *(float *)(this + 0x114);
  local_170 = *(float *)(this + 0x118);
  fStack_16c = *(float *)(this + 0x11c);
  fStack_168 = *(float *)(this + 0x120);
  fStack_164 = *(float *)(this + 0x124);
  local_160 = *(float *)(this + 0x128);
  fStack_15c = *(float *)(this + 300);
  fStack_158 = *(float *)(this + 0x130);
  fStack_154 = *(float *)(this + 0x134);
  FUN_004fd850(uVar5);
  local_110 = (float *)((float)local_fc * local_190 + local_11c * local_180 +
                        (float)local_120 * local_170 + local_160);
  local_10c = (float *)((float)local_fc * fStack_18c + local_11c * fStack_17c +
                        (float)local_120 * fStack_16c + fStack_15c);
  local_f4 = (float *)(local_11c * fStack_178 + (float)local_fc * fStack_188 +
                       (float)local_120 * fStack_168 + fStack_158);
  _memset(&local_190,0,0x40);
  FUN_00484c60();
  pfVar7 = (float *)FUN_004156b0(local_250,local_250 + 0x10);
  local_190 = *pfVar7;
  fStack_18c = pfVar7[1];
  fStack_188 = pfVar7[2];
  fStack_184 = pfVar7[3];
  local_180 = pfVar7[4];
  fStack_17c = pfVar7[5];
  fStack_178 = pfVar7[6];
  fStack_174 = pfVar7[7];
  local_170 = pfVar7[8];
  fStack_16c = pfVar7[9];
  fStack_168 = pfVar7[10];
  fStack_164 = pfVar7[0xb];
  local_160 = pfVar7[0xc];
  fStack_15c = pfVar7[0xd];
  fStack_158 = pfVar7[0xe];
  fStack_154 = pfVar7[0xf];
  local_250[0] = 1.0;
  local_250[1] = 0.0;
  local_250[2] = 0.0;
  local_250[3] = 0.0;
  local_250[4] = 0.0;
  local_250[5] = 1.0;
  local_250[6] = 0.0;
  local_250[7] = 0.0;
  local_250[8] = 0.0;
  local_250[9] = 0.0;
  local_250[10] = 2.0;
  local_250[0xb] = 0.0;
  local_250[0xc] = 0.0;
  local_250[0xd] = 0.0;
  local_250[0xe] = 0.0;
  local_250[0xf] = 1.0;
  pfVar7 = (float *)FUN_004156b0(local_290,local_250);
  local_190 = *pfVar7;
  fStack_18c = pfVar7[1];
  fStack_188 = pfVar7[2];
  fStack_184 = pfVar7[3];
  local_180 = pfVar7[4];
  fStack_17c = pfVar7[5];
  fStack_178 = pfVar7[6];
  fStack_174 = pfVar7[7];
  local_170 = pfVar7[8];
  fStack_16c = pfVar7[9];
  fStack_168 = pfVar7[10];
  fStack_164 = pfVar7[0xb];
  local_160 = pfVar7[0xc];
  fStack_15c = pfVar7[0xd];
  fStack_158 = pfVar7[0xe];
  fStack_154 = pfVar7[0xf];
  local_148 = (float *)(local_128 -
                       ((float)local_110 * local_190 + (float)local_10c * local_180 +
                        (float)local_f4 * local_170 + local_160));
  local_144 = (float *)((float)local_12c -
                       ((float)local_10c * fStack_17c + (float)local_110 * fStack_18c +
                        (float)local_f4 * fStack_16c + fStack_15c));
  local_14c = (float *)((float)local_118 -
                       ((float)local_110 * fStack_188 + (float)local_10c * fStack_178 +
                        (float)local_f4 * fStack_168 + fStack_158));
  local_140 = local_14c;
  local_130 = local_144;
  local_100 = local_148;
  uVar8 = FUN_0047e910();
  pfVar7 = (float *)FUN_004156b0(local_250,uVar8);
  local_10c = &local_94;
  local_110 = (float *)&DAT_00000007;
  local_194 = *pfVar7;
  local_1b0 = pfVar7[1];
  local_1a4 = pfVar7[2];
  fStack_184 = pfVar7[3];
  local_180 = pfVar7[4];
  local_19c = pfVar7[5];
  local_1a0 = pfVar7[6];
  fStack_174 = pfVar7[7];
  local_198 = pfVar7[8];
  local_1ac = pfVar7[9];
  local_1a8 = pfVar7[10];
  fStack_164 = pfVar7[0xb];
  local_160 = pfVar7[0xc];
  local_1b4 = pfVar7[0xd];
  fStack_158 = pfVar7[0xe];
  fStack_154 = pfVar7[0xf];
  local_f4 = (float *)RaiseException_exref;
  local_190 = local_194;
  fStack_18c = local_1b0;
  fStack_188 = local_1a4;
  fStack_17c = local_19c;
  fStack_178 = local_1a0;
  local_170 = local_198;
  fStack_16c = local_1ac;
  fStack_168 = local_1a8;
  fStack_15c = local_1b4;
  local_13c = fStack_158;
  local_114 = local_160;
  local_108 = (float *)local_180;
  do {
    pCVar4 = PTR_0077241c;
    if (((uint)local_110 & 1) == 0) {
      fVar20 = *(float *)(this + 0x178);
    }
    else {
      fVar20 = *(float *)(this + 0x184);
    }
    local_10c[-2] = fVar20;
    if (((uint)local_110 & 2) == 0) {
      fVar20 = *(float *)(this + 0x180);
    }
    else {
      fVar20 = *(float *)(this + 0x18c);
    }
    *local_10c = fVar20;
    if (((uint)local_110 & 4) == 0) {
      fVar20 = *(float *)(this + 0x17c);
    }
    else {
      fVar20 = *(float *)(this + 0x188);
    }
    local_10c[-1] = fVar20;
    fVar18 = local_10c[-2];
    fVar2 = *local_10c;
    local_10c[-2] = fVar20 * (float)local_108 + fVar18 * local_194 + fVar2 * local_198 + local_114;
    fVar19 = fVar20 * local_19c + fVar18 * local_1b0 + fVar2 * local_1ac + local_1b4;
    local_10c[-1] = fVar19;
    *local_10c = fVar20 * local_1a0 + fVar18 * local_1a4 + fVar2 * local_1a8 + local_13c;
    local_138 = (uint)ROUND(fVar19 * 8.0);
    DAT_00772dd8 = (float)(int)ROUND(local_10c[-2] * 8.0);
    local_124 = DAT_00772dd8;
    piVar9 = (int *)FUN_00592f10(PTR_0077241c);
    pCVar3 = pCVar4->heightBlocks;
    iVar15 = *piVar9;
    if ((iVar15 < 0) || (pCVar3->count <= iVar15)) {
      (*(code *)local_f4)(0xc000008c,1,0,0);
      pCVar14 = pCVar3->data;
    }
    else {
      pCVar14 = pCVar3->data + iVar15;
    }
    fVar20 = *local_10c;
    local_10c = local_10c + -3;
    *(bool *)(this + 0xe8 + (int)local_110) =
         fVar20 <= (float)pCVar14->heights[(local_138 & 7) << 3 | (uint)local_124 & 7] + 0.1;
    local_110 = (float *)((int)local_110 + -1);
  } while (-1 < (int)local_110);
  fVar20 = ((float)local_12c - local_11c) * ((float)local_12c - local_11c) +
           (local_128 - (float)local_fc) * (local_128 - (float)local_fc) +
           ((float)local_118 - (float)local_120) * ((float)local_118 - (float)local_120);
  FUN_0040b7e0();
  local_114 = fVar20 * 8.0;
  DAT_00772dd8 = (float)(int)ROUND(local_114);
  iVar15 = (int)DAT_00772dd8 + 1;
  local_138 = iVar15;
  _eh_vector_constructor_iterator_(local_90,0xc,8,FUN_00405b50,guard_check_icall);
  local_14._0_1_ = 1;
  local_108 = (float *)0x1;
  if (iVar15 < 1) {
    local_fc = local_130;
    local_1d0 = local_130;
  }
  else {
    pfVar7 = (float *)(this + 0x90);
    local_124 = (float)iVar15;
    do {
      local_11c = 0.0;
      local_118 = (float *)0x0;
      local_128 = 0.0;
      local_10c = (float *)0x0;
      local_110 = (float *)((float)(int)local_108 / local_124);
      local_fc = (float *)(1.0 - (float)local_110);
      local_12c = pfVar7;
      do {
        pfVar7 = local_f4;
        pCVar4 = PTR_0077241c;
        fVar20 = *(float *)((int)local_f0 + (int)local_128 + 8);
        fVar18 = *(float *)((int)local_f0 + (int)local_128);
        fVar2 = local_12c[-2];
        fVar19 = *local_12c;
        fVar21 = local_12c[-1] * (float)local_fc +
                 *(float *)((int)local_f0 + (int)local_128 + 4) * (float)local_110;
        *(float *)((int)local_90 + (int)local_128 + 4) = fVar21;
        *(float *)((int)local_90 + (int)local_128 + 8) =
             fVar19 * (float)local_fc + fVar20 * (float)local_110;
        *(float *)((int)local_90 + (int)local_128) =
             fVar2 * (float)local_fc + fVar18 * (float)local_110;
        local_13c = (float)(int)ROUND(fVar21 * 8.0);
        DAT_00772dd8 = (float)(int)ROUND(*(float *)((int)local_90 + (int)local_128) * 8.0);
        local_120 = PTR_0077241c;
        iVar15 = PTR_0077241c->cellX0;
        if (PTR_0077241c->cellX0 <= (int)DAT_00772dd8 >> 3) {
          iVar15 = (int)DAT_00772dd8 >> 3;
        }
        iVar13 = PTR_0077241c->cellY0;
        if (PTR_0077241c->cellY0 <= (int)local_13c >> 3) {
          iVar13 = (int)local_13c >> 3;
        }
        iVar10 = PTR_0077241c->cellY1 + -1;
        if (iVar13 < PTR_0077241c->cellY1) {
          iVar10 = iVar13;
        }
        iVar13 = PTR_0077241c->cellX1 + -1;
        if (iVar15 < PTR_0077241c->cellX1) {
          iVar13 = iVar15;
        }
        iVar15 = (iVar10 * PTR_0077241c->mapWidth + iVar13) % PTR_0077241c->cellCountTotal;
        local_114 = DAT_00772dd8;
        if ((iVar15 < 0) || (PTR_0077241c->cellCount <= iVar15)) {
          (*(code *)local_f4)(0xc000008c,1,0,0);
          pCVar11 = pCVar4->cells;
        }
        else {
          pCVar11 = PTR_0077241c->cells + iVar15;
        }
        iVar15 = pCVar11->heightBlockIndex;
        pCVar3 = pCVar4->heightBlocks;
        if ((iVar15 < 0) || (pCVar3->count <= iVar15)) {
          (*(code *)pfVar7)(0xc000008c,1,0,0);
          pCVar14 = pCVar3->data;
        }
        else {
          pCVar14 = pCVar3->data + iVar15;
        }
        if ((float)pCVar14->heights[((uint)local_13c & 7) << 3 | (uint)local_114 & 7] + 0.1 <
            *(float *)((int)local_90 + (int)local_128 + 8)) {
          if ((float *)0x5f < local_10c) {
                    /* WARNING: Subroutine does not return */
            ___report_rangecheckfailure();
          }
          uVar12 = 0;
        }
        else {
          uVar12 = 1;
          local_11c = (float)((int)local_11c + 1);
        }
        local_128 = (float)((int)local_128 + 0xc);
        local_10c = local_10c + 3;
        *(undefined1 *)((int)local_2c + (int)local_118) = uVar12;
        local_118 = (float *)((int)local_118 + 1);
        local_12c = local_12c + 3;
      } while ((int)local_128 < 0x60);
      this = local_134;
      local_1d0 = local_110;
      if (*(int *)(local_134 + 0xf4) <= (int)local_11c) break;
      pfVar7 = (float *)(local_134 + 0x90);
      local_108 = (float *)((int)local_108 + 1);
    } while ((int)local_108 <= (int)local_138);
  }
  pfStack_1cc = local_1d0;
  pfStack_1c8 = local_1d0;
  pfStack_1c4 = local_1d0;
  if ((float)local_1d0 == 1.0) {
    if (14.5 < (float)local_14c) {
      local_140 = (float *)0x41680000;
    }
    FUN_005cd8e0(&local_148);
    uVar8 = FUN_004fd3f0(&pfStack_1cc);
    FUN_005cda60(uVar8);
    iVar15 = *(int *)(this + 0x14);
    *(undefined4 *)(iVar15 + 0x28) = *(undefined4 *)(this + 0x58);
    *(undefined4 *)(iVar15 + 0x2c) = *(undefined4 *)(this + 0x5c);
    uVar8 = *(undefined4 *)(this + 0x60);
    *(uint *)(iVar15 + 0x3d8) = *(uint *)(iVar15 + 0x3d8) | 2;
    *(undefined4 *)(iVar15 + 0x30) = uVar8;
  }
  else {
    local_148 = (float *)((float)local_fc * *(float *)(this + 0x78) +
                         (float)local_100 * (float)local_1d0);
    local_144 = (float *)(*(float *)(this + 0x7c) * (float)local_fc +
                         (float)local_130 * (float)local_1d0);
    local_140 = (float *)(*(float *)(this + 0x80) * (float)local_fc +
                         (float)local_14c * (float)local_1d0);
    local_130 = local_140;
    local_118 = local_144;
    _memset(local_250,0,0x40);
    iVar15 = 0;
    do {
      *(float *)((int)local_250 + iVar15) =
           *(float *)((int)local_250 + iVar15 + 0x40) * (float)local_1d0;
      *(float *)((int)local_250 + iVar15 + 4) =
           *(float *)((int)local_250 + iVar15 + 0x44) * (float)pfStack_1cc;
      *(float *)((int)local_250 + iVar15 + 8) =
           *(float *)((int)local_250 + iVar15 + 0x48) * (float)pfStack_1c8;
      *(float *)((int)local_250 + iVar15 + 0xc) =
           *(float *)((int)local_250 + iVar15 + 0x4c) * (float)pfStack_1c4;
      iVar15 = iVar15 + 0x10;
    } while (iVar15 < 0x40);
    _memset(local_250 + 0x10,0,0x40);
    iVar15 = 0;
    do {
      pfVar7 = (float *)(this + 0x138 + iVar15);
      fVar20 = pfVar7[1];
      fVar18 = pfVar7[2];
      fVar2 = pfVar7[3];
      *(float *)((int)local_250 + iVar15 + 0x40) = *pfVar7 * (float)local_fc;
      *(float *)((int)local_250 + iVar15 + 0x44) = fVar20 * (float)local_fc;
      *(float *)((int)local_250 + iVar15 + 0x48) = fVar18 * (float)local_fc;
      *(float *)((int)local_250 + iVar15 + 0x4c) = fVar2 * (float)local_fc;
      iVar15 = iVar15 + 0x10;
    } while (iVar15 < 0x40);
    FUN_00415470(&local_190,local_250);
    FUN_004fd3f0(&pfStack_1cc);
    FUN_0040ba00();
    local_14 = CONCAT31(local_14._1_3_,2);
    FUN_0040b980(1);
    pfVar7 = local_f4;
    if (local_100 == (float *)0x0) {
      (*(code *)local_f4)(0xc000008c,1,0,0);
    }
    local_f4 = local_90 + 4;
    local_fc = (float *)0x1;
    *local_104 = 0;
    pfVar17 = local_100;
    do {
      if (pfVar17 == (float *)0x0) {
        (*(code *)pfVar7)(0xc000008c,1,0,0);
      }
      fVar20 = *local_f4;
      if (fVar20 < local_90[*local_104 * 3 + 1] || fVar20 == local_90[*local_104 * 3 + 1]) {
        if (pfVar17 == (float *)0x0) {
          (*(code *)pfVar7)(0xc000008c,1,0,0);
          fVar20 = *local_f4;
        }
        if (local_90[*local_104 * 3 + 1] == fVar20) {
          FUN_0040b930(1);
          pfVar17 = local_100;
          if (local_100 <= (float *)((int)local_100 + -1)) {
            (*(code *)pfVar7)(0xc000008c,1,0,0);
          }
          local_104[(int)((int)pfVar17 + -1)] = (int)local_fc;
        }
      }
      else {
        FUN_0040b980(1);
        pfVar17 = local_100;
        if (local_100 == (float *)0x0) {
          (*(code *)pfVar7)(0xc000008c,1,0,0);
        }
        *local_104 = (int)local_fc;
      }
      piVar9 = local_104;
      local_fc = (float *)((int)local_fc + 1);
      local_f4 = local_f4 + 3;
    } while ((int)local_fc < 8);
    pfVar17 = local_144;
    if (2 < (int)local_100) {
      local_f5 = 1;
      local_108 = (float *)0x0;
      if (0 < (int)local_100) {
        bVar16 = local_100 != (float *)0x0;
        do {
          if (!bVar16) {
            (*(code *)pfVar7)(0xc000008c,1,0,0);
          }
          piVar1 = piVar9 + (int)local_108;
          local_108 = (float *)((int)local_108 + 1);
          local_f5 = local_f5 & *(byte *)((int)local_2c + *piVar1);
          bVar16 = local_108 < local_100;
        } while ((int)local_108 < (int)local_100);
        pfVar17 = local_144;
        if (local_f5 == 0) goto LAB_005ea683;
      }
      piVar9 = local_104;
      local_f4 = (float *)0x0;
      pfVar17 = (float *)((float)local_118 - 2.0);
      local_108 = pfVar17;
      if (0 < (int)local_100) {
        bVar16 = local_100 != (float *)0x0;
        do {
          if (!bVar16) {
            (*(code *)pfVar7)(0xc000008c,1,0,0);
          }
          FUN_005e9450(local_30,local_90 + piVar9[(int)local_f4] * 3);
          if (local_100 <= local_f4) {
            (*(code *)pfVar7)(0xc000008c,1,0,0);
          }
          piVar1 = piVar9 + (int)local_f4;
          local_f4 = (float *)((int)local_f4 + 1);
          pfVar17 = (float *)((local_2c[0] - local_90[*piVar1 * 3 + 1]) + (float)local_118);
          if ((float)pfVar17 <= (float)local_108) {
            pfVar17 = local_108;
          }
          bVar16 = local_f4 < local_100;
          local_108 = pfVar17;
        } while ((int)local_f4 < (int)local_100);
      }
    }
LAB_005ea683:
    local_144 = pfVar17;
    iVar15 = local_134;
    if (14.5 < (float)local_130) {
      local_140 = (float *)0x41680000;
    }
    FUN_005cd8e0(&local_148);
    iVar13 = *(int *)(iVar15 + 0x14);
    *(float **)(iVar13 + 0x40) = pfStack_1cc;
    *(float **)(iVar13 + 0x44) = pfStack_1c8;
    *(float **)(iVar13 + 0x48) = pfStack_1c4;
    if ((10000.0 <= *(float *)(iVar13 + 0x40)) || (*(float *)(iVar13 + 0x40) <= -10000.0)) {
      *(undefined4 *)(iVar13 + 0x40) = 0;
    }
    if ((10000.0 <= *(float *)(iVar13 + 0x44)) || (*(float *)(iVar13 + 0x44) <= -10000.0)) {
      *(undefined4 *)(iVar13 + 0x44) = 0;
    }
    if ((10000.0 <= *(float *)(iVar13 + 0x48)) || (*(float *)(iVar13 + 0x48) <= -10000.0)) {
      *(undefined4 *)(iVar13 + 0x48) = 0;
    }
    *(uint *)(iVar13 + 0x3d8) = *(uint *)(iVar13 + 0x3d8) | 2;
    *(undefined1 *)(iVar13 + 0x402) = 1;
    iVar13 = *(int *)(iVar15 + 0x14);
    *(uint *)(iVar13 + 0x3d8) = *(uint *)(iVar13 + 0x3d8) | 2;
    *(undefined4 *)(iVar13 + 0x28) = 0;
    *(undefined4 *)(iVar13 + 0x2c) = 0;
    *(undefined4 *)(iVar13 + 0x30) = 0;
    if (*(int *)(*(int *)(*(int *)(iVar15 + 0x14) + 0xd4) + 0x68) == 2) {
      FUN_005ebc90();
      FUN_005eae80(*(undefined4 *)(iVar15 + 0x14));
    }
    local_14._0_1_ = 3;
    FUN_0040b980(0);
    if (local_104 != (int *)0x0) {
      FUN_006ba940();
    }
  }
  local_14 = (uint)local_14._1_3_ << 8;
  _eh_vector_destructor_iterator_(local_90,0xc,8,guard_check_icall);
LAB_005ea809:
  local_14 = 0xffffffff;
  _eh_vector_destructor_iterator_(local_f0,0xc,8,guard_check_icall);
  ExceptionList = local_1c;
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffff0);
  return;
}

