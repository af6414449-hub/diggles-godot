
void FUN_00594e00(float *param_1,float *param_2,float *param_3)

{
  CHeightBlockArray *pCVar1;
  bool bVar2;
  CMap *this;
  int iVar3;
  int iVar4;
  int iVar5;
  CMapCell *pCVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  CHeightBlock *pCVar10;
  int iVar11;
  uint uVar12;
  CMapCell *pCVar13;
  float fVar14;
  double dVar15;
  float fVar16;
  float fVar17;
  uint local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_28;
  float local_24;
  
  this = PTR_0077241c;
  fVar16 = *param_2;
  local_24 = param_2[1];
  fVar17 = param_3[1];
  fVar14 = local_24 - fVar17;
  fVar14 = fVar14 * fVar14 + (fVar16 - *param_3) * (fVar16 - *param_3);
  FUN_0040b7e0();
  if (1.0 <= fVar14) {
    fVar16 = (*param_3 - fVar16) / fVar14 + fVar16;
    local_24 = (fVar17 - local_24) / fVar14 + local_24;
  }
  else {
    fVar16 = *param_3;
    local_24 = param_3[1];
  }
  local_34 = (uint)ROUND(fVar16 * 8.0);
  local_24 = local_24 * 8.0;
  DAT_00772dd8 = (int)ROUND(local_24);
  local_3c = 1;
  uVar9 = DAT_00772dd8 + 8;
  local_40 = 0x7fffffff;
  bVar2 = false;
  local_28 = (int)uVar9 >> 3;
  iVar3 = FUN_00592f10(this);
  uVar12 = uVar9 & 7;
  local_44 = uVar9;
  local_38 = local_34;
  if ((*(byte *)((uVar12 * 8 | local_34 & 7) + 0x3c + iVar3) & 1) == 0) {
    iVar3 = 0x32;
    local_4c = 0x32;
    local_50 = uVar9;
    local_48 = local_34;
    do {
      if (0 < local_3c) {
        iVar3 = local_48 - local_34;
        local_24 = (float)local_3c;
        do {
          local_48 = local_48 + 1;
          iVar3 = iVar3 + 1;
          iVar4 = (int)local_48 >> 3;
          iVar11 = this->cellX0;
          if (this->cellX0 <= iVar4) {
            iVar11 = iVar4;
          }
          iVar7 = this->cellY0;
          if (this->cellY0 <= local_28) {
            iVar7 = local_28;
          }
          iVar8 = this->cellY1 + -1;
          if (iVar7 < this->cellY1) {
            iVar8 = iVar7;
          }
          iVar7 = this->cellX1 + -1;
          if (iVar11 < this->cellX1) {
            iVar7 = iVar11;
          }
          iVar11 = (iVar8 * this->mapWidth + iVar7) % this->cellCountTotal;
          if ((iVar11 < 0) || (this->cellCount <= iVar11)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar6 = this->cells;
          }
          else {
            pCVar6 = this->cells + iVar11;
          }
          iVar11 = local_4c;
          if (((pCVar6->sampleFlags[local_48 & 7 | uVar12 * 8] & 1) != 0) &&
             (iVar7 = (local_50 - uVar9) * (local_50 - uVar9) + iVar3 * iVar3, iVar7 < local_40)) {
            bVar2 = true;
            dVar15 = (double)iVar7;
            if (dVar15 < 0.0) {
              __libm_sse2_sqrt_precise();
            }
            else {
              dVar15 = SQRT(dVar15);
            }
            local_44 = local_50;
            iVar11 = (int)((float)dVar15 + (float)dVar15 + 2.1);
            local_40 = iVar7;
            local_38 = local_48;
            if (local_4c <= iVar11) {
              iVar11 = local_4c;
            }
          }
          local_4c = iVar11;
          local_24 = (float)((int)local_24 + -1);
        } while (local_24 != 0.0);
        iVar11 = local_50 - uVar9;
        local_24 = (float)local_3c;
        do {
          local_50 = local_50 + 1;
          iVar11 = iVar11 + 1;
          local_28 = (int)local_50 >> 3;
          iVar3 = this->cellX0;
          if (this->cellX0 <= iVar4) {
            iVar3 = iVar4;
          }
          iVar7 = this->cellY0;
          if (this->cellY0 <= local_28) {
            iVar7 = local_28;
          }
          iVar8 = this->cellY1 + -1;
          if (iVar7 < this->cellY1) {
            iVar8 = iVar7;
          }
          iVar7 = this->cellX1 + -1;
          if (iVar3 < this->cellX1) {
            iVar7 = iVar3;
          }
          iVar3 = (iVar8 * this->mapWidth + iVar7) % this->cellCountTotal;
          if ((iVar3 < 0) || (this->cellCount <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar6 = this->cells;
          }
          else {
            pCVar6 = this->cells + iVar3;
          }
          uVar12 = local_50 & 7;
          iVar3 = local_4c;
          if (((pCVar6->sampleFlags[uVar12 * 8 | local_48 & 7] & 1) != 0) &&
             (iVar7 = (local_48 - local_34) * (local_48 - local_34) + iVar11 * iVar11,
             iVar7 < local_40)) {
            bVar2 = true;
            dVar15 = (double)iVar7;
            if (dVar15 < 0.0) {
              __libm_sse2_sqrt_precise();
            }
            else {
              dVar15 = SQRT(dVar15);
            }
            iVar3 = (int)((float)dVar15 + (float)dVar15 + 2.1);
            local_44 = local_50;
            local_40 = iVar7;
            local_38 = local_48;
            if (local_4c <= iVar3) {
              iVar3 = local_4c;
            }
          }
          local_4c = iVar3;
          local_24 = (float)((int)local_24 + -1);
          iVar3 = local_4c;
        } while (local_24 != 0.0);
      }
      iVar11 = local_3c + 1;
      if (0 < iVar11) {
        iVar3 = local_48 - local_34;
        local_24 = (float)iVar11;
        do {
          local_48 = local_48 - 1;
          iVar3 = iVar3 + -1;
          iVar7 = (int)local_48 >> 3;
          iVar4 = this->cellX0;
          if (this->cellX0 <= iVar7) {
            iVar4 = iVar7;
          }
          iVar8 = this->cellY0;
          if (this->cellY0 <= (int)local_50 >> 3) {
            iVar8 = (int)local_50 >> 3;
          }
          iVar5 = this->cellY1 + -1;
          if (iVar8 < this->cellY1) {
            iVar5 = iVar8;
          }
          iVar8 = this->cellX1 + -1;
          if (iVar4 < this->cellX1) {
            iVar8 = iVar4;
          }
          iVar4 = (iVar5 * this->mapWidth + iVar8) % this->cellCountTotal;
          if ((iVar4 < 0) || (this->cellCount <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar6 = this->cells;
            pCVar13 = pCVar6;
          }
          else {
            pCVar6 = this->cells + iVar4;
            pCVar13 = this->cells;
          }
          iVar4 = local_4c;
          if (((pCVar6->sampleFlags[local_48 & 7 | (local_50 & 7) << 3] & 1) != 0) &&
             (iVar8 = iVar3 * iVar3 + (local_50 - uVar9) * (local_50 - uVar9), iVar8 < local_40)) {
            bVar2 = true;
            dVar15 = (double)iVar8;
            if (dVar15 < 0.0) {
              __libm_sse2_sqrt_precise();
            }
            else {
              dVar15 = SQRT(dVar15);
            }
            local_44 = local_50;
            iVar4 = (int)((float)dVar15 + (float)dVar15 + 2.1);
            local_40 = iVar8;
            local_38 = local_48;
            if (local_4c <= iVar4) {
              iVar4 = local_4c;
            }
          }
          local_4c = iVar4;
          local_24 = (float)((int)local_24 + -1);
        } while (local_24 != 0.0);
        iVar4 = local_50 - uVar9;
        local_24 = (float)iVar11;
        do {
          local_50 = local_50 - 1;
          iVar4 = iVar4 + -1;
          local_28 = (int)local_50 >> 3;
          iVar3 = this->cellX0;
          if (this->cellX0 <= iVar7) {
            iVar3 = iVar7;
          }
          iVar11 = this->cellY0;
          if (this->cellY0 <= local_28) {
            iVar11 = local_28;
          }
          iVar8 = this->cellY1 + -1;
          if (iVar11 < this->cellY1) {
            iVar8 = iVar11;
          }
          iVar11 = this->cellX1 + -1;
          if (iVar3 < this->cellX1) {
            iVar11 = iVar3;
          }
          iVar3 = (iVar8 * this->mapWidth + iVar11) % this->cellCountTotal;
          if ((iVar3 < 0) || (this->cellCount <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar6 = this->cells;
            pCVar13 = pCVar6;
          }
          else {
            pCVar6 = pCVar13 + iVar3;
          }
          uVar12 = local_50 & 7;
          iVar3 = local_4c;
          if (((pCVar6->sampleFlags[uVar12 * 8 | local_48 & 7] & 1) != 0) &&
             (iVar11 = iVar4 * iVar4 + (local_48 - local_34) * (local_48 - local_34),
             iVar11 < local_40)) {
            bVar2 = true;
            dVar15 = (double)iVar11;
            if (dVar15 < 0.0) {
              __libm_sse2_sqrt_precise();
            }
            else {
              dVar15 = SQRT(dVar15);
            }
            iVar3 = (int)((float)dVar15 + (float)dVar15 + 2.1);
            local_44 = local_50;
            local_40 = iVar11;
            local_38 = local_48;
            if (local_4c <= iVar3) {
              iVar3 = local_4c;
            }
          }
          local_4c = iVar3;
          local_24 = (float)((int)local_24 + -1);
          iVar3 = local_4c;
        } while (local_24 != 0.0);
      }
      local_3c = local_3c + 2;
    } while (local_3c < iVar3);
    uVar9 = local_44;
    if (!bVar2) goto LAB_00595590;
  }
  local_24 = 0.0;
  uVar12 = local_44;
  do {
    iVar3 = this->cellX0;
    if (this->cellX0 <= (int)local_38 >> 3) {
      iVar3 = (int)local_38 >> 3;
    }
    iVar11 = this->cellY0;
    if (this->cellY0 <= (int)uVar12 >> 3) {
      iVar11 = (int)uVar12 >> 3;
    }
    iVar4 = this->cellY1 + -1;
    if (iVar11 < this->cellY1) {
      iVar4 = iVar11;
    }
    iVar11 = this->cellX1 + -1;
    if (iVar3 < this->cellX1) {
      iVar11 = iVar3;
    }
    iVar3 = (iVar4 * this->mapWidth + iVar11) % this->cellCountTotal;
    if ((iVar3 < 0) || (this->cellCount <= iVar3)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar6 = this->cells;
    }
    else {
      pCVar6 = this->cells + iVar3;
    }
    uVar9 = uVar12;
    if ((pCVar6->sampleFlags[(uVar12 & 7) << 3 | local_38 & 7] & 2) != 0) break;
    uVar12 = uVar12 + 1;
    local_24 = (float)((int)local_24 + 1);
    uVar9 = local_44;
  } while ((int)local_24 < 8);
LAB_00595590:
  local_44 = uVar9;
  iVar11 = (int)local_38 >> 3;
  iVar4 = (int)(local_44 - 5) >> 3;
  iVar3 = this->cellX0;
  if (this->cellX0 <= iVar11) {
    iVar3 = iVar11;
  }
  iVar7 = this->cellY0;
  if (this->cellY0 <= iVar4) {
    iVar7 = iVar4;
  }
  iVar8 = this->cellY1 + -1;
  if (iVar7 < this->cellY1) {
    iVar8 = iVar7;
  }
  iVar7 = this->cellX1 + -1;
  if (iVar3 < this->cellX1) {
    iVar7 = iVar3;
  }
  iVar3 = (iVar8 * this->mapWidth + iVar7) % this->cellCountTotal;
  if ((iVar3 < 0) || (this->cellCount <= iVar3)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar6 = this->cells;
  }
  else {
    pCVar6 = this->cells + iVar3;
  }
  iVar3 = pCVar6->heightBlockIndex;
  pCVar1 = this->heightBlocks;
  if ((iVar3 < 0) || (pCVar1->count <= iVar3)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar10 = pCVar1->data;
  }
  else {
    pCVar10 = pCVar1->data + iVar3;
  }
  uVar9 = (local_44 - 5 & 7) << 3 | local_38 & 7;
  fVar17 = param_3[2];
  if (fVar17 <= (float)(pCVar10->heights[uVar9] + 1)) {
    iVar3 = this->cellX0;
    if (this->cellX0 <= iVar11) {
      iVar3 = iVar11;
    }
    iVar11 = this->cellY0;
    if (this->cellY0 <= iVar4) {
      iVar11 = iVar4;
    }
    iVar4 = this->cellY1 + -1;
    if (iVar11 < this->cellY1) {
      iVar4 = iVar11;
    }
    iVar11 = this->cellX1 + -1;
    if (iVar3 < this->cellX1) {
      iVar11 = iVar3;
    }
    iVar3 = (iVar4 * this->mapWidth + iVar11) % this->cellCountTotal;
    if ((iVar3 < 0) || (this->cellCount <= iVar3)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar6 = this->cells;
    }
    else {
      pCVar6 = this->cells + iVar3;
    }
    iVar3 = pCVar6->heightBlockIndex;
    pCVar1 = this->heightBlocks;
    if ((iVar3 < 0) || (pCVar1->count <= iVar3)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar10 = pCVar1->data;
    }
    else {
      pCVar10 = pCVar1->data + iVar3;
    }
    fVar17 = (float)(pCVar10->heights[uVar9] + 1);
  }
  *param_1 = (float)(int)local_38 * 0.125;
  param_1[1] = (float)(int)local_44 * 0.125;
  fVar16 = 14.5;
  if (fVar17 <= 14.5) {
    fVar16 = fVar17;
  }
  param_1[2] = fVar16;
  return;
}

