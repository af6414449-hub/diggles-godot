
void FUN_005906a0(int *param_1)

{
  byte bVar1;
  CHeightBlockArray *pCVar2;
  CMap *pCVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  CHeightBlock *pCVar7;
  int iVar8;
  CMapCell *pCVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  code *pcVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int local_30;
  uint local_10;
  uint local_c;
  uint local_8;
  
  GetTickCount();
  iVar20 = PTR_0077241c->x0_8 + 0xc;
  iVar4 = iVar20;
  if (iVar20 <= *param_1) {
    iVar4 = *param_1;
  }
  iVar10 = PTR_0077241c->y0_8 + 0xc;
  iVar14 = PTR_0077241c->x1_8;
  iVar5 = iVar10;
  if (iVar10 <= param_1[1]) {
    iVar5 = param_1[1];
  }
  if (iVar14 + -0xc <= iVar4) {
    iVar4 = iVar14 + -0xd;
  }
  iVar6 = PTR_0077241c->y1_8;
  if (iVar6 + -0xc <= iVar5) {
    iVar5 = iVar6 + -0xd;
  }
  if (iVar20 <= param_1[2]) {
    iVar20 = param_1[2];
  }
  if (iVar10 <= param_1[3]) {
    iVar10 = param_1[3];
  }
  iVar18 = iVar14 + -0xd;
  if (iVar20 < iVar14 + -0xc) {
    iVar18 = iVar20;
  }
  iVar20 = iVar6 + -0xd;
  if (iVar10 < iVar6 + -0xc) {
    iVar20 = iVar10;
  }
  uVar11 = iVar5 + 7U & 0xfffffff8;
  uVar21 = iVar4 + 7U & 0xfffffff8;
  if ((int)uVar11 < iVar20) {
    uVar19 = uVar11 + 2;
    pcVar17 = RaiseException_exref;
    do {
      if ((int)uVar21 < iVar18) {
        iVar4 = (int)uVar11 >> 3;
        iVar5 = (int)(uVar19 - 1) >> 3;
        uVar16 = uVar21;
        do {
          pCVar3 = PTR_0077241c;
          iVar10 = (int)uVar16 >> 3;
          iVar14 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar10) {
            iVar14 = iVar10;
          }
          iVar6 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar4) {
            iVar6 = iVar4;
          }
          iVar12 = PTR_0077241c->cellY1 + -1;
          if (iVar6 < PTR_0077241c->cellY1) {
            iVar12 = iVar6;
          }
          iVar6 = PTR_0077241c->cellX1 + -1;
          if (iVar14 < PTR_0077241c->cellX1) {
            iVar6 = iVar14;
          }
          iVar14 = (iVar12 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
          if ((iVar14 < 0) || (PTR_0077241c->cellCount <= iVar14)) {
            (*pcVar17)(0xc000008c,1,0,0);
            pCVar9 = pCVar3->cells;
          }
          else {
            pCVar9 = PTR_0077241c->cells + iVar14;
          }
          iVar14 = pCVar9->heightBlockIndex;
          pCVar2 = pCVar3->heightBlocks;
          if ((iVar14 < 0) || (pCVar2->count <= iVar14)) {
            (*pcVar17)(0xc000008c,1,0,0);
            pCVar7 = pCVar2->data;
          }
          else {
            pCVar7 = pCVar2->data + iVar14;
          }
          pCVar3 = PTR_0077241c;
          local_10 = (uint)pCVar7->heights[0];
          iVar6 = (int)(uVar16 + 2) >> 3;
          iVar14 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar6) {
            iVar14 = iVar6;
          }
          iVar6 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= (int)uVar19 >> 3) {
            iVar6 = (int)uVar19 >> 3;
          }
          iVar12 = PTR_0077241c->cellY1 + -1;
          if (iVar6 < PTR_0077241c->cellY1) {
            iVar12 = iVar6;
          }
          iVar6 = PTR_0077241c->cellX1 + -1;
          if (iVar14 < PTR_0077241c->cellX1) {
            iVar6 = iVar14;
          }
          iVar14 = (iVar12 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
          if ((iVar14 < 0) || (PTR_0077241c->cellCount <= iVar14)) {
            (*pcVar17)(0xc000008c,1,0,0);
            pCVar9 = pCVar3->cells;
          }
          else {
            pCVar9 = PTR_0077241c->cells + iVar14;
          }
          iVar14 = pCVar9->heightBlockIndex;
          pCVar2 = pCVar3->heightBlocks;
          if ((iVar14 < 0) || (pCVar2->count <= iVar14)) {
            (*pcVar17)(0xc000008c,1,0,0);
            pCVar7 = pCVar2->data;
          }
          else {
            pCVar7 = pCVar2->data + iVar14;
          }
          pCVar3 = PTR_0077241c;
          bVar1 = pCVar7->heights[(uVar19 & 7) << 3 | uVar16 + 2 & 7];
          iVar14 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar10) {
            iVar14 = iVar10;
          }
          iVar6 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar4) {
            iVar6 = iVar4;
          }
          iVar12 = PTR_0077241c->cellY1 + -1;
          if (iVar6 < PTR_0077241c->cellY1) {
            iVar12 = iVar6;
          }
          iVar6 = PTR_0077241c->cellX1 + -1;
          if (iVar14 < PTR_0077241c->cellX1) {
            iVar6 = iVar14;
          }
          iVar14 = (iVar12 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
          if ((iVar14 < 0) || (PTR_0077241c->cellCount <= iVar14)) {
            (*pcVar17)(0xc000008c,1,0,0);
            pCVar9 = pCVar3->cells;
          }
          else {
            pCVar9 = PTR_0077241c->cells + iVar14;
          }
          iVar14 = pCVar9->heightBlockIndex;
          pCVar2 = pCVar3->heightBlocks;
          if ((iVar14 < 0) || (pCVar2->count <= iVar14)) {
            (*pcVar17)(0xc000008c,1,0,0);
            pCVar7 = pCVar2->data;
          }
          else {
            pCVar7 = pCVar2->data + iVar14;
          }
          iVar14 = ((uint)bVar1 - (uint)pCVar7->heights[0]) * 2;
          if (iVar14 < -4) {
            iVar14 = -4;
          }
          local_30 = 4;
          if (4 < iVar14) {
            iVar14 = 4;
          }
          param_1 = (int *)(iVar14 * 2);
          local_c = uVar16;
          local_8 = uVar11;
          do {
            pCVar3 = PTR_0077241c;
            local_10 = local_10 + 1;
            iVar6 = (int)(local_c - 1) >> 3;
            iVar12 = (int)(local_8 - 1) >> 3;
            iVar14 = PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= iVar6) {
              iVar14 = iVar6;
            }
            iVar6 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= iVar12) {
              iVar6 = iVar12;
            }
            iVar12 = PTR_0077241c->cellY1 + -1;
            if (iVar6 < PTR_0077241c->cellY1) {
              iVar12 = iVar6;
            }
            iVar6 = PTR_0077241c->cellX1 + -1;
            if (iVar14 < PTR_0077241c->cellX1) {
              iVar6 = iVar14;
            }
            iVar14 = (iVar12 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
            if ((iVar14 < 0) || (PTR_0077241c->cellCount <= iVar14)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar9 = pCVar3->cells;
            }
            else {
              pCVar9 = PTR_0077241c->cells + iVar14;
            }
            iVar14 = pCVar9->heightBlockIndex;
            pCVar2 = pCVar3->heightBlocks;
            if ((iVar14 < 0) || (pCVar2->count <= iVar14)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar7 = pCVar2->data;
            }
            else {
              pCVar7 = pCVar2->data + iVar14;
            }
            pCVar3 = PTR_0077241c;
            iVar14 = local_10 - pCVar7->heights[(local_8 - 1 & 7) << 3 | local_c - 1 & 7];
            if (iVar14 < -8) {
              iVar14 = -8;
            }
            if (0 < iVar14) {
              iVar14 = 0;
            }
            iVar12 = (int)(local_c - 2) >> 3;
            iVar13 = (int)(local_8 - 2) >> 3;
            iVar6 = PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= iVar12) {
              iVar6 = iVar12;
            }
            iVar12 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= iVar13) {
              iVar12 = iVar13;
            }
            iVar13 = PTR_0077241c->cellY1 + -1;
            if (iVar12 < PTR_0077241c->cellY1) {
              iVar13 = iVar12;
            }
            iVar12 = PTR_0077241c->cellX1 + -1;
            if (iVar6 < PTR_0077241c->cellX1) {
              iVar12 = iVar6;
            }
            iVar6 = (iVar13 * PTR_0077241c->mapWidth + iVar12) % PTR_0077241c->cellCountTotal;
            if ((iVar6 < 0) || (PTR_0077241c->cellCount <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar9 = pCVar3->cells;
            }
            else {
              pCVar9 = PTR_0077241c->cells + iVar6;
            }
            iVar6 = pCVar9->heightBlockIndex;
            pCVar2 = pCVar3->heightBlocks;
            if ((iVar6 < 0) || (pCVar2->count <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar7 = pCVar2->data;
            }
            else {
              pCVar7 = pCVar2->data + iVar6;
            }
            pCVar3 = PTR_0077241c;
            iVar6 = local_10 - pCVar7->heights[(local_8 - 2 & 7) << 3 | local_c - 2 & 7];
            if (iVar6 < -8) {
              iVar6 = -8;
            }
            if (0 < iVar6) {
              iVar6 = 0;
            }
            local_c = local_c - 3;
            local_8 = local_8 - 3;
            iVar12 = PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= (int)local_c >> 3) {
              iVar12 = (int)local_c >> 3;
            }
            iVar13 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= (int)local_8 >> 3) {
              iVar13 = (int)local_8 >> 3;
            }
            iVar8 = PTR_0077241c->cellY1 + -1;
            if (iVar13 < PTR_0077241c->cellY1) {
              iVar8 = iVar13;
            }
            iVar13 = PTR_0077241c->cellX1 + -1;
            if (iVar12 < PTR_0077241c->cellX1) {
              iVar13 = iVar12;
            }
            iVar12 = (iVar8 * PTR_0077241c->mapWidth + iVar13) % PTR_0077241c->cellCountTotal;
            if ((iVar12 < 0) || (PTR_0077241c->cellCount <= iVar12)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar9 = pCVar3->cells;
            }
            else {
              pCVar9 = PTR_0077241c->cells + iVar12;
            }
            iVar12 = pCVar9->heightBlockIndex;
            pCVar2 = pCVar3->heightBlocks;
            if ((iVar12 < 0) || (pCVar2->count <= iVar12)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar7 = pCVar2->data;
            }
            else {
              pCVar7 = pCVar2->data + iVar12;
            }
            iVar12 = local_10 - pCVar7->heights[(local_8 & 7) << 3 | local_c & 7];
            if (iVar12 < -8) {
              iVar12 = -8;
            }
            if (0 < iVar12) {
              iVar12 = 0;
            }
            param_1 = (int *)((int)param_1 + iVar14 + iVar6 + iVar12);
            local_30 = local_30 + -1;
          } while (local_30 != 0);
          iVar14 = (int)param_1 / 2 + 4;
          if ((SBORROW4(uVar11,DAT_007683d8 * 8) != (int)(uVar11 + DAT_007683d8 * -8) < 0) &&
             (local_30 = 0x18, uVar15 = uVar11, PTR_0077241c->originY8 + 0x10 <= (int)uVar11)) {
            while( true ) {
              pCVar3 = PTR_0077241c;
              iVar6 = PTR_0077241c->cellX0;
              if (PTR_0077241c->cellX0 <= iVar10) {
                iVar6 = iVar10;
              }
              iVar12 = PTR_0077241c->cellY0;
              if (PTR_0077241c->cellY0 <= (int)uVar15 >> 3) {
                iVar12 = (int)uVar15 >> 3;
              }
              iVar13 = PTR_0077241c->cellY1 + -1;
              if (iVar12 < PTR_0077241c->cellY1) {
                iVar13 = iVar12;
              }
              iVar12 = PTR_0077241c->cellX1 + -1;
              if (iVar6 < PTR_0077241c->cellX1) {
                iVar12 = iVar6;
              }
              iVar6 = (iVar13 * PTR_0077241c->mapWidth + iVar12) % PTR_0077241c->cellCountTotal;
              if ((iVar6 < 0) || (PTR_0077241c->cellCount <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar9 = pCVar3->cells;
              }
              else {
                pCVar9 = PTR_0077241c->cells + iVar6;
              }
              iVar6 = pCVar9->heightBlockIndex;
              pCVar2 = pCVar3->heightBlocks;
              if ((iVar6 < 0) || (pCVar2->count <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar7 = pCVar2->data;
              }
              else {
                pCVar7 = pCVar2->data + iVar6;
              }
              if (pCVar7->heights[(uVar15 & 7) * 8] < 0xd) break;
              local_30 = local_30 + -1;
              if ((local_30 == 0) ||
                 (uVar15 = uVar15 - 2, (int)uVar15 < PTR_0077241c->originY8 + 0x10))
              goto LAB_00590d8e;
            }
            iVar14 = 0x14;
          }
LAB_00590d8e:
          pCVar3 = PTR_0077241c;
          pcVar17 = RaiseException_exref;
          iVar6 = 0;
          if (-1 < iVar14) {
            iVar6 = iVar14;
          }
          iVar14 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar10) {
            iVar14 = iVar10;
          }
          iVar10 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar5) {
            iVar10 = iVar5;
          }
          iVar12 = PTR_0077241c->cellY1 + -1;
          if (iVar10 < PTR_0077241c->cellY1) {
            iVar12 = iVar10;
          }
          iVar10 = PTR_0077241c->cellX1 + -1;
          if (iVar14 < PTR_0077241c->cellX1) {
            iVar10 = iVar14;
          }
          iVar14 = (iVar12 * PTR_0077241c->mapWidth + iVar10) % PTR_0077241c->cellCountTotal;
          if ((iVar14 < 0) || (PTR_0077241c->cellCount <= iVar14)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar9 = pCVar3->cells;
          }
          else {
            pCVar9 = PTR_0077241c->cells + iVar14;
          }
          uVar16 = uVar16 + 8;
          pCVar9->light = (uchar)iVar6;
        } while ((int)uVar16 < iVar18);
      }
      uVar11 = uVar11 + 8;
      uVar19 = uVar19 + 8;
    } while ((int)uVar11 < iVar20);
  }
  return;
}

