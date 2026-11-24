
void FUN_10022500(undefined4 *param_1,float *param_2,int param_3)

{
  float *pfVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  float *in_ECX;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  int *in_EDX;
  undefined1 *puVar11;
  byte *pbVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  float fVar16;
  float fVar17;
  uint local_38;
  uint local_34;
  uint local_2c;
  byte *local_24;
  uint local_20;
  uint local_1c;
  float *local_18;
  uint local_14;
  byte *local_10;
  float *local_c;
  byte *local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  fVar17 = 0.0;
  uVar15 = in_EDX[1];
  local_14 = (uint)*(ushort *)((int)param_1 + 6);
  local_8 = (byte *)*param_1;
  puVar11 = (undefined1 *)(((int)(((int)uVar15 >> 0x1f & 7U) + uVar15) >> 3) + *in_EDX);
  iVar14 = (uVar15 & 7) - 8;
  pbVar12 = puVar11 + 4;
  uVar15 = CONCAT31(CONCAT21(CONCAT11(*puVar11,puVar11[1]),puVar11[2]),puVar11[3]) <<
           (sbyte)(uVar15 & 7);
  local_c = param_2;
  local_18 = in_ECX;
  if (local_14 != 0) {
    local_24 = (byte *)((int)param_1 + 0x12);
    local_18 = in_ECX;
    local_10 = pbVar12;
    do {
      while( true ) {
        pbVar12 = local_24 + 1;
        local_2c = (uint)*local_24;
        sVar4 = *(short *)(&DAT_100458b0 + (uint)local_24[-3] * 2);
        bVar2 = (&DAT_10045ab0)[local_24[-3]];
        local_24 = pbVar12;
        if (bVar2 != 0) break;
        do {
          bVar2 = *local_8;
          local_8 = local_8 + 1;
          uVar7 = (uint)(bVar2 >> 1);
          local_34 = local_14;
          if ((int)uVar7 < (int)local_14) {
            local_34 = uVar7;
          }
          fVar17 = *local_c;
          local_c = local_c + 1;
          do {
            uVar8 = 5;
            sVar5 = *(short *)(&DAT_10045d10 + (uVar15 >> 0x1b) * 2 + sVar4 * 2);
            while (uVar9 = (uint)sVar5, (int)uVar9 < 0) {
              uVar15 = uVar15 << (sbyte)uVar8;
              iVar14 = iVar14 + uVar8;
              uVar8 = uVar9 & 7;
              sVar5 = *(short *)(&DAT_10045d10 +
                                ((uVar15 >> (0x20U - (char)uVar8 & 0x1f)) - ((int)uVar9 >> 3)) * 2 +
                                sVar4 * 2);
            }
            uVar8 = uVar9 & 0xf;
            iVar6 = uVar15 << ((byte)((ushort)sVar5 >> 8) & 0x1f);
            *local_18 = *(float *)(&DAT_10043910 + (uVar8 + (iVar6 >> 0x1f) * 0x10) * 4) * fVar17;
            iVar6 = iVar6 << (uVar8 != 0);
            uVar13 = uVar9 >> 4 & 0xf;
            pfVar1 = local_18 + 2;
            uVar15 = iVar6 << (uVar13 != 0);
            local_18[1] = *(float *)(&DAT_10043910 + (uVar13 + (iVar6 >> 0x1f) * 0x10) * 4) * fVar17
            ;
            pbVar12 = local_10;
            for (iVar14 = iVar14 + (uVar9 >> 8) + (uint)(uVar8 != 0) + (uint)(uVar13 != 0);
                -1 < iVar14; iVar14 = iVar14 + -8) {
              bVar2 = *pbVar12;
              pbVar12 = pbVar12 + 1;
              uVar15 = uVar15 | (uint)bVar2 << ((byte)iVar14 & 0x1f);
            }
            local_34 = local_34 - 1;
            local_18 = pfVar1;
            local_10 = pbVar12;
          } while (local_34 != 0);
          local_14 = local_14 - uVar7;
          if ((int)local_14 < 1) goto LAB_100228fb;
          local_2c = local_2c - 1;
        } while (-1 < (int)local_2c);
      }
      do {
        bVar3 = *local_8;
        local_8 = local_8 + 1;
        uVar7 = (uint)(bVar3 >> 1);
        local_38 = local_14;
        if ((int)uVar7 < (int)local_14) {
          local_38 = uVar7;
        }
        fVar17 = *local_c;
        local_c = local_c + 1;
        do {
          uVar8 = 5;
          sVar5 = *(short *)(&DAT_10045d10 + (uVar15 >> 0x1b) * 2 + sVar4 * 2);
          while (local_20 = (uint)sVar5, (int)local_20 < 0) {
            uVar15 = uVar15 << (sbyte)uVar8;
            iVar14 = iVar14 + uVar8;
            uVar8 = local_20 & 7;
            sVar5 = *(short *)(&DAT_10045d10 +
                              ((uVar15 >> (0x20U - (char)uVar8 & 0x1f)) - ((int)local_20 >> 3)) * 2
                              + sVar4 * 2);
          }
          local_34 = 2;
          uVar15 = uVar15 << ((byte)((ushort)sVar5 >> 8) & 0x1f);
          iVar14 = iVar14 + (local_20 >> 8);
          pbVar12 = local_10;
          do {
            local_1c = local_20 & 0xf;
            if (local_1c == 0xf) {
              local_1c = (uVar15 >> (0x20 - bVar2 & 0x1f)) + 0xf;
              uVar15 = uVar15 << (bVar2 & 0x1f);
              for (iVar14 = iVar14 + (uint)bVar2; -1 < iVar14; iVar14 = iVar14 + -8) {
                bVar3 = *pbVar12;
                pbVar12 = pbVar12 + 1;
                uVar15 = uVar15 | (uint)bVar3 << ((byte)iVar14 & 0x1f);
                local_10 = pbVar12;
              }
              if ((int)local_1c < 0x81) {
                fVar16 = *(float *)(&DAT_10043910 + local_1c * 4);
              }
              else {
                uVar8 = local_1c * 8;
                if (0x3ff < (int)local_1c) {
                  uVar8 = local_1c;
                }
                uVar9 = uVar8 * 2 & 0x40;
                fVar16 = (float)(int)((uVar8 & 0x3f) - uVar9) /
                         (float)(int)((uVar8 & 0xffffffc0) + uVar9);
                iVar6 = 0x10;
                if (0x3ff < (int)local_1c) {
                  iVar6 = 0x100;
                }
                fVar16 = ((fVar16 * 0.22222222 + 1.3333334) * fVar16 + 1.0) *
                         *(float *)(&DAT_10043910 + ((int)(uVar8 + uVar9) >> 6) * 4) * (float)iVar6;
                pbVar12 = local_10;
              }
              fVar16 = (float)(int)(((int)uVar15 >> 0x1f & 0xfffffffeU) + 1) * fVar16 * fVar17;
            }
            else {
              fVar16 = *(float *)(&DAT_10043910 + (local_1c + ((int)uVar15 >> 0x1f) * 0x10) * 4) *
                       fVar17;
            }
            *local_18 = fVar16;
            iVar14 = iVar14 + (uint)(local_1c != 0);
            local_18 = local_18 + 1;
            uVar15 = uVar15 << (local_1c != 0);
            local_20 = (int)local_20 >> 4;
            local_34 = local_34 + -1;
          } while (local_34 != 0);
          for (; -1 < iVar14; iVar14 = iVar14 + -8) {
            bVar3 = *pbVar12;
            pbVar12 = pbVar12 + 1;
            uVar15 = uVar15 | (uint)bVar3 << ((byte)iVar14 & 0x1f);
            local_10 = pbVar12;
          }
          local_38 = local_38 - 1;
        } while (local_38 != 0);
        local_14 = local_14 - uVar7;
        if ((int)local_14 < 1) goto LAB_100228fb;
        local_2c = local_2c - 1;
      } while (-1 < (int)local_2c);
    } while( true );
  }
LAB_100228fb:
  local_2c = 1 - local_14;
  local_18 = local_18 + 2;
  while( true ) {
    puVar10 = &DAT_10047700;
    if (*(char *)((int)param_1 + 0x1a) == '\0') {
      puVar10 = &DAT_100458f0;
    }
    bVar2 = puVar10[uVar15 >> 0x1c];
    if ((bVar2 & 8) == 0) {
      bVar2 = puVar10[(uint)(bVar2 >> 3) + ((uVar15 << 4) >> (0x20 - (bVar2 & 3) & 0x1f))];
    }
    iVar14 = iVar14 + (bVar2 & 7);
    uVar15 = uVar15 << (sbyte)(bVar2 & 7);
    if (param_3 < iVar14 + (int)(pbVar12 + (-3 - *in_EDX)) * 8) break;
    local_2c = local_2c - 1;
    if (local_2c == 0) {
      local_2c = (uint)(*local_8 >> 1);
      if (local_2c == 0) break;
      fVar17 = *local_c;
      local_c = local_c + 1;
      local_8 = local_8 + 1;
    }
    if ((char)bVar2 < '\0') {
      fVar16 = fVar17;
      if ((int)uVar15 < 0) {
        fVar16 = -fVar17;
      }
      uVar15 = uVar15 * 2;
      iVar14 = iVar14 + 1;
      local_18[-2] = fVar16;
    }
    if ((bVar2 & 0x40) != 0) {
      fVar16 = fVar17;
      if ((int)uVar15 < 0) {
        fVar16 = -fVar17;
      }
      uVar15 = uVar15 * 2;
      iVar14 = iVar14 + 1;
      local_18[-1] = fVar16;
    }
    local_2c = local_2c - 1;
    if (local_2c == 0) {
      local_2c = (uint)(*local_8 >> 1);
      if (local_2c == 0) {
        in_EDX[1] = param_3;
        return;
      }
      fVar17 = *local_c;
      local_c = local_c + 1;
      local_8 = local_8 + 1;
    }
    if ((bVar2 & 0x20) != 0) {
      fVar16 = fVar17;
      if ((int)uVar15 < 0) {
        fVar16 = -fVar17;
      }
      uVar15 = uVar15 * 2;
      iVar14 = iVar14 + 1;
      *local_18 = fVar16;
    }
    if ((bVar2 & 0x10) != 0) {
      fVar16 = fVar17;
      if ((int)uVar15 < 0) {
        fVar16 = -fVar17;
      }
      uVar15 = uVar15 * 2;
      local_18[1] = fVar16;
      iVar14 = iVar14 + 1;
    }
    for (; -1 < iVar14; iVar14 = iVar14 + -8) {
      bVar2 = *pbVar12;
      pbVar12 = pbVar12 + 1;
      uVar15 = uVar15 | (uint)bVar2 << ((byte)iVar14 & 0x1f);
    }
    local_18 = local_18 + 4;
  }
  in_EDX[1] = param_3;
  return;
}

