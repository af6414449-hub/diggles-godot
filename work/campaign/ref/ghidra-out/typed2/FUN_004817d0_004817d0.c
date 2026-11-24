
void FUN_004817d0(void)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  CHeightBlockArray *pCVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  CMap *pCVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  CHeightBlock **ppCVar15;
  uint uVar16;
  uint uVar17;
  CMapCell *pCVar18;
  float *pfVar19;
  undefined4 *puVar20;
  undefined4 uVar21;
  int *in_ECX;
  int iVar22;
  int iVar23;
  int iVar24;
  CHeightBlock *pCVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  uint uVar30;
  int iVar31;
  int local_60;
  uint local_54;
  int local_50;
  uint local_40;
  int local_3c;
  int local_38;
  uint local_30;
  uint local_2c;
  int local_28;
  uint local_1c;
  
  iVar11 = PTR_0077241c->cellX1 + -0x10;
  iVar29 = PTR_0077241c->cellX0 + 0x10;
  iVar31 = PTR_0077241c->cellY0 + 0x10;
  iVar12 = PTR_0077241c->cellY1 + -0x14;
  bVar7 = false;
  bVar6 = false;
  iVar3 = in_ECX[1];
  local_54 = 0;
  if (0 < iVar3) {
    do {
      if ((uint)in_ECX[1] <= local_54) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar22 = local_54 * 0x10;
      iVar26 = *in_ECX + iVar22;
      local_40 = *(uint *)(iVar26 + 8);
      if (0 < (int)local_40) {
        uVar30 = 0;
        do {
          if (*(uint *)(iVar26 + 8) <= uVar30) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar23 = uVar30 * 0x2c;
          uVar16 = (uint)ROUND(*(float *)(iVar23 + *(int *)(iVar26 + 4)) * 8.0);
          if (*(uint *)(iVar26 + 8) <= uVar30) {
            DAT_00772dd8 = uVar16;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          pCVar10 = PTR_0077241c;
          uVar17 = (uint)ROUND(*(float *)(iVar23 + 4 + *(int *)(iVar26 + 4)) * 8.0);
          iVar13 = (int)uVar17 >> 3;
          iVar27 = (int)uVar16 >> 3;
          iVar28 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar27) {
            iVar28 = iVar27;
          }
          iVar24 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar13) {
            iVar24 = iVar13;
          }
          iVar14 = PTR_0077241c->cellY1 + -1;
          if (iVar24 < PTR_0077241c->cellY1) {
            iVar14 = iVar24;
          }
          iVar24 = PTR_0077241c->cellX1 + -1;
          if (iVar28 < PTR_0077241c->cellX1) {
            iVar24 = iVar28;
          }
          iVar28 = (iVar14 * PTR_0077241c->mapWidth + iVar24) % PTR_0077241c->cellCountTotal;
          DAT_00772dd8 = uVar17;
          if ((iVar28 < 0) || (PTR_0077241c->cellCount <= iVar28)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar18 = pCVar10->cells;
          }
          else {
            pCVar18 = PTR_0077241c->cells + iVar28;
          }
          iVar28 = pCVar18->heightBlockIndex;
          pCVar4 = pCVar10->heightBlocks;
          ppCVar15 = &pCVar4->data;
          if ((iVar28 < 0) || (pCVar4->count <= iVar28)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar25 = *ppCVar15;
          }
          else {
            pCVar25 = *ppCVar15 + iVar28;
          }
          uVar16 = (uVar17 & 7) << 3 | uVar16 & 7;
          bVar2 = pCVar25->heights[uVar16];
          if (*(uint *)(iVar26 + 8) <= uVar30) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar28 = *(int *)(iVar26 + 4);
          if ((float)bVar2 * 0.5 + 7.0 < *(float *)(iVar28 + 8 + iVar23)) {
            uVar17 = *(uint *)(iVar26 + 8);
            if (uVar17 <= uVar30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar28 = *(int *)(iVar26 + 4);
              uVar17 = *(uint *)(iVar26 + 8);
            }
            iVar24 = iVar28 + iVar23;
            if (uVar17 <= uVar30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar28 = *(int *)(iVar26 + 4);
            }
            *(float *)(iVar28 + iVar23) = *(float *)(iVar24 + 0x18) + *(float *)(iVar28 + iVar23);
            *(float *)(iVar28 + 4 + iVar23) =
                 *(float *)(iVar24 + 0x1c) + *(float *)(iVar28 + 4 + iVar23);
            *(float *)(iVar28 + 8 + iVar23) =
                 *(float *)(iVar24 + 0x20) + *(float *)(iVar28 + 8 + iVar23);
            pCVar10 = PTR_0077241c;
            iVar28 = PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= iVar27) {
              iVar28 = iVar27;
            }
            iVar27 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= iVar13) {
              iVar27 = iVar13;
            }
            iVar13 = PTR_0077241c->cellY1 + -1;
            if (iVar27 < PTR_0077241c->cellY1) {
              iVar13 = iVar27;
            }
            iVar27 = PTR_0077241c->cellX1 + -1;
            if (iVar28 < PTR_0077241c->cellX1) {
              iVar27 = iVar28;
            }
            iVar28 = (iVar13 * PTR_0077241c->mapWidth + iVar27) % PTR_0077241c->cellCountTotal;
            if ((iVar28 < 0) || (PTR_0077241c->cellCount <= iVar28)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar18 = pCVar10->cells;
            }
            else {
              pCVar18 = PTR_0077241c->cells + iVar28;
            }
            iVar28 = pCVar18->heightBlockIndex;
            pCVar4 = pCVar10->heightBlocks;
            ppCVar15 = &pCVar4->data;
            if ((iVar28 < 0) || (pCVar4->count <= iVar28)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar25 = *ppCVar15;
            }
            else {
              pCVar25 = *ppCVar15 + iVar28;
            }
            bVar2 = pCVar25->heights[uVar16];
            if (*(uint *)(iVar26 + 8) <= uVar30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar28 = *(int *)(iVar26 + 4);
            if (*(float *)(iVar28 + 8 + iVar23) <= (float)bVar2 * 0.5 + 7.0) {
              uVar16 = *(uint *)(iVar26 + 8);
              if (uVar16 <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar28 = *(int *)(iVar26 + 4);
                uVar16 = *(uint *)(iVar26 + 8);
              }
              iVar13 = iVar28 + iVar23;
              if (uVar16 <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar28 = *(int *)(iVar26 + 4);
              }
              *(float *)(iVar28 + iVar23) = *(float *)(iVar28 + iVar23) - *(float *)(iVar13 + 0x18);
              *(float *)(iVar28 + 4 + iVar23) =
                   *(float *)(iVar28 + 4 + iVar23) - *(float *)(iVar13 + 0x1c);
              *(float *)(iVar28 + 8 + iVar23) =
                   *(float *)(iVar28 + 8 + iVar23) - *(float *)(iVar13 + 0x20);
              uVar16 = *(uint *)(iVar26 + 8);
              if (uVar16 <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                uVar16 = *(uint *)(iVar26 + 8);
              }
              iVar28 = *(int *)(iVar26 + 4);
              fVar1 = *(float *)(iVar28 + 0x18 + iVar23);
              if (uVar16 <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar28 = *(int *)(iVar26 + 4);
              }
              *(float *)(iVar28 + 0x18 + iVar23) = fVar1 * 0.5;
              uVar16 = *(uint *)(iVar26 + 8);
              if (uVar16 <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                uVar16 = *(uint *)(iVar26 + 8);
              }
              iVar13 = *(int *)(iVar26 + 4);
              iVar28 = iVar13 + iVar23;
              if (uVar16 <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar13 = *(int *)(iVar26 + 4);
              }
              *(float *)(iVar13 + 0x1c + iVar23) = -*(float *)(iVar28 + 0x1c) * 0.5;
              uVar16 = *(uint *)(iVar26 + 8);
              if (uVar16 <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                uVar16 = *(uint *)(iVar26 + 8);
              }
              iVar13 = *(int *)(iVar26 + 4);
              iVar28 = iVar13 + iVar23;
              if (uVar16 <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar13 = *(int *)(iVar26 + 4);
              }
              *(float *)(iVar13 + 0x20 + iVar23) = *(float *)(iVar28 + 0x20) * 0.5;
            }
            if (*(uint *)(iVar26 + 8) <= uVar30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar28 = *(int *)(iVar26 + 4);
            *(float *)(iVar23 + 0x18 + iVar28) = *(float *)(iVar23 + 0x18 + iVar28) + 0.0;
            *(float *)(iVar23 + 0x1c + iVar28) = *(float *)(iVar23 + 0x1c + iVar28) + 0.125;
            *(float *)(iVar23 + 0x20 + iVar28) = *(float *)(iVar23 + 0x20 + iVar28) + 0.0;
          }
          uVar16 = *(uint *)(iVar26 + 8);
          if (uVar16 <= uVar30) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar16 = *(uint *)(iVar26 + 8);
          }
          iVar28 = *(int *)(iVar26 + 4);
          pfVar19 = (float *)(iVar28 + 0x18 + iVar23);
          if (4.0 < *pfVar19 || *pfVar19 == 4.0) {
LAB_00481df9:
            if (uVar16 <= uVar30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar28 = *(int *)(iVar26 + 4);
              uVar16 = *(uint *)(iVar26 + 8);
            }
            local_50 = 0x40800000;
            pfVar19 = (float *)(iVar28 + 0x18 + iVar23);
            if (*pfVar19 <= 4.0 && *pfVar19 != 4.0) {
              if (uVar16 <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar28 = *(int *)(iVar26 + 4);
                uVar16 = *(uint *)(iVar26 + 8);
              }
              local_50 = *(undefined4 *)(iVar28 + 0x18 + iVar23);
            }
          }
          else {
            if (uVar16 <= uVar30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar28 = *(int *)(iVar26 + 4);
              uVar16 = *(uint *)(iVar26 + 8);
            }
            if (-4.0 < *(float *)(iVar28 + 0x18 + iVar23)) goto LAB_00481df9;
            local_50 = 0xc0800000;
          }
          if (uVar16 <= uVar30) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar28 = *(int *)(iVar26 + 4);
          }
          *(int *)(iVar28 + 0x18 + iVar23) = local_50;
          uVar16 = *(uint *)(iVar26 + 8);
          if (uVar16 <= uVar30) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar16 = *(uint *)(iVar26 + 8);
          }
          iVar28 = *(int *)(iVar26 + 4);
          pfVar19 = (float *)(iVar28 + 0x1c + iVar23);
          if (4.0 < *pfVar19 || *pfVar19 == 4.0) {
LAB_00481edd:
            if (uVar16 <= uVar30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar28 = *(int *)(iVar26 + 4);
              uVar16 = *(uint *)(iVar26 + 8);
            }
            local_50 = 0x40800000;
            pfVar19 = (float *)(iVar28 + 0x1c + iVar23);
            if (*pfVar19 <= 4.0 && *pfVar19 != 4.0) {
              if (uVar16 <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar28 = *(int *)(iVar26 + 4);
                uVar16 = *(uint *)(iVar26 + 8);
              }
              local_50 = *(undefined4 *)(iVar28 + 0x1c + iVar23);
            }
          }
          else {
            if (uVar16 <= uVar30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar28 = *(int *)(iVar26 + 4);
              uVar16 = *(uint *)(iVar26 + 8);
            }
            if (-4.0 < *(float *)(iVar28 + 0x1c + iVar23)) goto LAB_00481edd;
            local_50 = 0xc0800000;
          }
          if (uVar16 <= uVar30) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar28 = *(int *)(iVar26 + 4);
          }
          *(int *)(iVar28 + 0x1c + iVar23) = local_50;
          uVar16 = *(uint *)(iVar26 + 8);
          if (uVar16 <= uVar30) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar16 = *(uint *)(iVar26 + 8);
          }
          iVar28 = *(int *)(iVar26 + 4);
          pfVar19 = (float *)(iVar28 + 0x20 + iVar23);
          if (4.0 < *pfVar19 || *pfVar19 == 4.0) {
LAB_00481fbe:
            if (uVar16 <= uVar30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar28 = *(int *)(iVar26 + 4);
            }
            local_50 = 0x40800000;
            pfVar19 = (float *)(iVar28 + 0x20 + iVar23);
            if (*pfVar19 <= 4.0 && *pfVar19 != 4.0) {
              if (*(uint *)(iVar26 + 8) <= uVar30) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar28 = *(int *)(iVar26 + 4);
              }
              local_50 = *(undefined4 *)(iVar28 + 0x20 + iVar23);
            }
          }
          else {
            if (uVar16 <= uVar30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar28 = *(int *)(iVar26 + 4);
            }
            if (-4.0 < *(float *)(iVar28 + 0x20 + iVar23)) {
              uVar16 = *(uint *)(iVar26 + 8);
              goto LAB_00481fbe;
            }
            local_50 = 0xc0800000;
          }
          if (*(uint *)(iVar26 + 8) <= uVar30) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar28 = *(int *)(iVar26 + 4);
          }
          uVar30 = uVar30 + 1;
          *(int *)(iVar28 + 0x20 + iVar23) = local_50;
        } while ((int)uVar30 < (int)local_40);
      }
      local_1c = 0;
      if (0 < (int)local_40) {
        local_2c = 2;
        local_28 = 0;
        local_30 = 1;
        local_50 = (local_40 + 2) * 0x2c;
        local_3c = 0x58;
        local_38 = 0x2c;
        do {
          if (*(uint *)(iVar26 + 8) <= local_30) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar23 = *(int *)(iVar26 + 4);
          pfVar19 = (float *)(local_38 + iVar23);
          if (*(uint *)(iVar26 + 8) <= local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar23 = *(int *)(iVar26 + 4);
          }
          bVar5 = bVar6;
          if (1.0 < ABS(*(float *)(local_28 + 4 + iVar23) - pfVar19[1]) +
                    ABS(*(float *)(local_28 + iVar23) - *pfVar19) +
                    ABS(*(float *)(local_28 + 8 + iVar23) - pfVar19[2])) {
LAB_004824e4:
            bVar9 = true;
            bVar8 = bVar7;
          }
          else {
            bVar7 = true;
            if (*(uint *)(iVar26 + 8) <= local_2c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            pfVar19 = (float *)(local_3c + iVar23);
            if (*(uint *)(iVar26 + 8) <= local_1c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            if (1.0 < ABS(*(float *)(local_28 + 4 + iVar23) - pfVar19[1]) +
                      ABS(*(float *)(local_28 + iVar23) - *pfVar19) +
                      ABS(*(float *)(local_28 + 8 + iVar23) - pfVar19[2])) goto LAB_004824e4;
            bVar7 = true;
            bVar5 = true;
            if (*(uint *)(iVar26 + 8) <= local_2c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            pfVar19 = (float *)(local_3c + iVar23);
            if (*(uint *)(iVar26 + 8) <= local_30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            if (1.0 < ABS(*(float *)(iVar23 + 4 + local_38) - pfVar19[1]) +
                      ABS(*(float *)(iVar23 + local_38) - *pfVar19) +
                      ABS(*(float *)(iVar23 + 8 + local_38) - pfVar19[2])) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_1c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            if (*(float *)(local_28 + iVar23) <= (float)iVar29 &&
                (float)iVar29 != *(float *)(local_28 + iVar23)) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_1c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            pfVar19 = (float *)(local_28 + 4 + iVar23);
            if (*pfVar19 <= (float)iVar31 && (float)iVar31 != *pfVar19) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_1c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            if ((float)iVar11 <= *(float *)(local_28 + iVar23)) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_1c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            if ((float)iVar12 <= *(float *)(local_28 + 4 + iVar23)) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            if (*(float *)(iVar23 + local_38) <= (float)iVar29 &&
                (float)iVar29 != *(float *)(iVar23 + local_38)) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            pfVar19 = (float *)(iVar23 + 4 + local_38);
            if (*pfVar19 <= (float)iVar31 && (float)iVar31 != *pfVar19) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            if ((float)iVar11 <= *(float *)(iVar23 + local_38)) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            if ((float)iVar12 <= *(float *)(iVar23 + 4 + local_38)) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_2c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            if (*(float *)(iVar23 + local_3c) <= (float)iVar29 &&
                (float)iVar29 != *(float *)(iVar23 + local_3c)) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_2c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            pfVar19 = (float *)(iVar23 + 4 + local_3c);
            if (*pfVar19 <= (float)iVar31 && (float)iVar31 != *pfVar19) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_2c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            if ((float)iVar11 <= *(float *)(iVar23 + local_3c)) goto LAB_004824e4;
            if (*(uint *)(iVar26 + 8) <= local_2c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            bVar9 = false;
            bVar8 = bVar7;
            if ((float)iVar12 <= *(float *)(iVar23 + 4 + local_3c)) goto LAB_004824e4;
          }
          bVar6 = false;
          if (!bVar5) {
            bVar6 = bVar5;
          }
          bVar7 = false;
          if (!bVar8) {
            bVar7 = bVar8;
          }
          if (bVar9) {
            uVar30 = *(uint *)(iVar26 + 8);
            if (uVar30 <= local_40 - 3) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              uVar30 = *(uint *)(iVar26 + 8);
            }
            local_60 = *(int *)(iVar26 + 4);
            puVar20 = (undefined4 *)(local_60 + local_50 + -0xdc);
            if (uVar30 <= local_1c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_60 = *(int *)(iVar26 + 4);
            }
            *(undefined4 *)(local_28 + local_60) = *puVar20;
            *(undefined4 *)(local_28 + 4 + local_60) = puVar20[1];
            *(undefined4 *)(local_28 + 8 + local_60) = puVar20[2];
            *(undefined4 *)(local_28 + 0xc + local_60) = puVar20[3];
            *(undefined4 *)(local_28 + 0x10 + local_60) = puVar20[4];
            *(undefined4 *)(local_28 + 0x14 + local_60) = puVar20[5];
            *(undefined4 *)(local_28 + 0x18 + local_60) = puVar20[6];
            *(undefined4 *)(local_28 + 0x1c + local_60) = puVar20[7];
            *(undefined4 *)(local_28 + 0x20 + local_60) = puVar20[8];
            *(undefined4 *)(local_28 + 0x24 + local_60) = puVar20[9];
            *(undefined4 *)(local_28 + 0x28 + local_60) = puVar20[10];
            uVar30 = *(uint *)(iVar26 + 8);
            if (uVar30 <= local_40 - 2) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              uVar30 = *(uint *)(iVar26 + 8);
            }
            local_60 = *(int *)(iVar26 + 4);
            puVar20 = (undefined4 *)(local_60 + local_50 + -0xb0);
            if (uVar30 <= local_30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_60 = *(int *)(iVar26 + 4);
            }
            *(undefined4 *)(local_60 + local_38) = *puVar20;
            *(undefined4 *)(local_60 + 4 + local_38) = puVar20[1];
            *(undefined4 *)(local_60 + 8 + local_38) = puVar20[2];
            *(undefined4 *)(local_60 + 0xc + local_38) = puVar20[3];
            *(undefined4 *)(local_60 + 0x10 + local_38) = puVar20[4];
            *(undefined4 *)(local_60 + 0x14 + local_38) = puVar20[5];
            *(undefined4 *)(local_60 + 0x18 + local_38) = puVar20[6];
            *(undefined4 *)(local_60 + 0x1c + local_38) = puVar20[7];
            *(undefined4 *)(local_60 + 0x20 + local_38) = puVar20[8];
            *(undefined4 *)(local_60 + 0x24 + local_38) = puVar20[9];
            *(undefined4 *)(local_60 + 0x28 + local_38) = puVar20[10];
            if (*(uint *)(iVar26 + 8) <= local_40 - 1) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar23 = *(int *)(iVar26 + 4);
            puVar20 = (undefined4 *)(local_50 + -0x84 + iVar23);
            if (*(uint *)(iVar26 + 8) <= local_2c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar23 = *(int *)(iVar26 + 4);
            }
            local_1c = local_1c - 3;
            local_30 = local_30 - 3;
            local_2c = local_2c - 3;
            *(undefined4 *)(iVar23 + local_3c) = *puVar20;
            *(undefined4 *)(iVar23 + 4 + local_3c) = puVar20[1];
            *(undefined4 *)(iVar23 + 8 + local_3c) = puVar20[2];
            *(undefined4 *)(iVar23 + 0xc + local_3c) = puVar20[3];
            *(undefined4 *)(iVar23 + 0x10 + local_3c) = puVar20[4];
            *(undefined4 *)(iVar23 + 0x14 + local_3c) = puVar20[5];
            *(undefined4 *)(iVar23 + 0x18 + local_3c) = puVar20[6];
            *(undefined4 *)(iVar23 + 0x1c + local_3c) = puVar20[7];
            *(undefined4 *)(iVar23 + 0x20 + local_3c) = puVar20[8];
            *(undefined4 *)(iVar23 + 0x24 + local_3c) = puVar20[9];
            *(undefined4 *)(iVar23 + 0x28 + local_3c) = puVar20[10];
            local_28 = local_28 + -0x84;
            local_38 = local_38 + -0x84;
            local_3c = local_3c + -0x84;
            local_50 = local_50 + -0x84;
            local_40 = local_40 - 3;
          }
          local_1c = local_1c + 3;
          local_28 = local_28 + 0x84;
          local_30 = local_30 + 3;
          local_38 = local_38 + 0x84;
          local_2c = local_2c + 3;
          local_3c = local_3c + 0x84;
        } while ((int)local_1c < (int)local_40);
      }
      if ((uint)in_ECX[1] <= local_54) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar26 = *in_ECX;
      iVar23 = *(int *)(iVar22 + 8 + iVar26);
      if (iVar23 < (int)local_40) {
        iVar28 = local_40 - iVar23;
        if ((local_40 + 0x7f & 0xffffff80) != (iVar23 + 0x7fU & 0xffffff80)) {
          uVar21 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                ,0x9b);
          *(undefined4 *)(iVar22 + 4 + iVar26) = uVar21;
          iVar23 = *(int *)(iVar22 + 8 + iVar26);
        }
        *(int *)(iVar22 + 8 + iVar26) = iVar28 + iVar23;
      }
      else if ((int)local_40 < iVar23) {
        iVar28 = iVar23 - local_40;
        if (iVar23 < iVar28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar23 = *(int *)(iVar22 + 8 + iVar26);
        }
        *(int *)(iVar22 + 8 + iVar26) = iVar23 - iVar28;
      }
      local_54 = local_54 + 1;
    } while ((int)local_54 < iVar3);
  }
  in_ECX[4] = 0xff;
  if (100 < in_ECX[3]) {
    DAT_00772dd8 = (uint)ROUND(((float)(in_ECX[3] + -100) / 100.0) * 255.0);
    in_ECX[4] = 0xff - DAT_00772dd8;
  }
  return;
}

