
void FUN_005a6350(int *param_1)

{
  uchar *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  CMap *pCVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  CMapCell *pCVar10;
  uint uVar11;
  uint uVar12;
  CMapCell *pCVar13;
  int iVar14;
  CMapCell *pCVar15;
  CMapCell *pCVar16;
  int iVar17;
  CMapCell *pCVar18;
  uchar *puVar19;
  byte bVar20;
  char cVar21;
  int iVar22;
  byte bVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  uint local_24;
  CMap *local_c;
  byte local_7;
  byte local_5;
  
  iVar6 = PTR_0077241c->y0_8 + 0xe;
  iVar22 = param_1[1];
  if (param_1[1] <= iVar6) {
    iVar22 = iVar6;
  }
  iVar7 = PTR_0077241c->x1_8 + -0x13;
  iVar6 = param_1[2];
  if (iVar7 <= param_1[2]) {
    iVar6 = iVar7;
  }
  iVar8 = PTR_0077241c->x0_8 + 0x12;
  iVar7 = *param_1;
  if (*param_1 <= iVar8) {
    iVar7 = iVar8;
  }
  iVar9 = PTR_0077241c->y1_8 + -0x15;
  iVar8 = param_1[3];
  if (iVar9 <= param_1[3]) {
    iVar8 = iVar9;
  }
  iVar22 = (int)((iVar22 >> 0x1f & 7U) + iVar22) >> 3;
  local_c = PTR_0077241c;
  pCVar5 = PTR_0077241c;
  do {
    if (((int)((iVar8 + -1 >> 0x1f & 7U) + iVar8 + -1) >> 3) + 1 <= iVar22) {
      FUN_005a6890(param_1);
      return;
    }
    iVar9 = (int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3;
    while (iVar9 < ((int)((iVar6 + -1 >> 0x1f & 7U) + iVar6 + -1) >> 3) + 1) {
      bVar3 = false;
      iVar24 = pCVar5->cellX0;
      if (pCVar5->cellX0 <= iVar9) {
        iVar24 = iVar9;
      }
      local_24 = 0;
      iVar27 = pCVar5->cellY0;
      if (pCVar5->cellY0 <= iVar22) {
        iVar27 = iVar22;
      }
      local_5 = 0x24;
      iVar17 = pCVar5->cellY1 + -1;
      if (iVar27 < pCVar5->cellY1) {
        iVar17 = iVar27;
      }
      iVar27 = pCVar5->cellX1 + -1;
      if (iVar24 < pCVar5->cellX1) {
        iVar27 = iVar24;
      }
      iVar24 = (iVar17 * pCVar5->mapWidth + iVar27) % pCVar5->cellCountTotal;
      if ((iVar24 < 0) || (pCVar5->cellCount <= iVar24)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar10 = pCVar5->cells;
        local_c = PTR_0077241c;
      }
      else {
        pCVar10 = pCVar5->cells + iVar24;
      }
      uVar28 = 0;
      puVar1 = pCVar10->sampleFlags;
      bVar4 = true;
      bVar2 = true;
      do {
        bVar23 = puVar1[uVar28];
        if ((bVar23 & 8) != 0) {
          bVar3 = true;
        }
        if ((bVar23 & 1) == 0) {
          bVar4 = false;
          uVar11 = local_24;
          bVar23 = local_5;
        }
        else {
          uVar11 = 4 - (uVar28 >> 3);
          bVar2 = false;
          uVar25 = (int)uVar11 >> 0x1f;
          uVar12 = 4 - (uVar28 & 7);
          uVar26 = (int)uVar12 >> 0x1f;
          uVar11 = (((bVar23 & 2) * 0x80 - ((uVar11 ^ uVar25) - uVar25)) -
                   ((uVar12 ^ uVar26) - uVar26)) + 8;
          bVar23 = (byte)uVar28;
          if ((int)uVar11 <= (int)local_24) {
            uVar11 = local_24;
            bVar23 = local_5;
          }
        }
        local_5 = bVar23;
        local_24 = uVar11;
        uVar28 = uVar28 + 1;
      } while ((int)uVar28 < 0x40);
      bVar23 = 1;
      iVar24 = iVar9 + 1;
      if ((iVar24 < local_c->cellX1) && (iVar22 + 1 < local_c->cellY1)) {
        iVar27 = local_c->cellX0;
        if (local_c->cellX0 <= iVar9) {
          iVar27 = iVar9;
        }
        iVar17 = local_c->cellY0;
        if (local_c->cellY0 <= iVar22) {
          iVar17 = iVar22;
        }
        iVar14 = local_c->cellY1 + -1;
        if (iVar17 < local_c->cellY1) {
          iVar14 = iVar17;
        }
        iVar17 = local_c->cellX1 + -1;
        if (iVar27 < local_c->cellX1) {
          iVar17 = iVar27;
        }
        iVar27 = (iVar14 * local_c->mapWidth + iVar17) % local_c->cellCountTotal;
        if ((iVar27 < 0) || (local_c->cellCount <= iVar27)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar13 = local_c->cells;
          local_c = PTR_0077241c;
        }
        else {
          pCVar13 = local_c->cells + iVar27;
        }
        iVar27 = local_c->cellX0;
        if (local_c->cellX0 <= iVar24) {
          iVar27 = iVar24;
        }
        iVar17 = local_c->cellY0;
        if (local_c->cellY0 <= iVar22) {
          iVar17 = iVar22;
        }
        iVar14 = local_c->cellY1 + -1;
        if (iVar17 < local_c->cellY1) {
          iVar14 = iVar17;
        }
        iVar17 = local_c->cellX1 + -1;
        if (iVar27 < local_c->cellX1) {
          iVar17 = iVar27;
        }
        iVar27 = (iVar14 * local_c->mapWidth + iVar17) % local_c->cellCountTotal;
        if ((iVar27 < 0) || (local_c->cellCount <= iVar27)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar15 = local_c->cells;
          local_c = PTR_0077241c;
        }
        else {
          pCVar15 = local_c->cells + iVar27;
        }
        iVar27 = local_c->cellX0;
        if (local_c->cellX0 <= iVar9) {
          iVar27 = iVar9;
        }
        iVar9 = local_c->cellY0;
        if (local_c->cellY0 <= iVar22 + 1) {
          iVar9 = iVar22 + 1;
        }
        iVar17 = local_c->cellY1 + -1;
        if (iVar9 < local_c->cellY1) {
          iVar17 = iVar9;
        }
        iVar9 = local_c->cellX1 + -1;
        if (iVar27 < local_c->cellX1) {
          iVar9 = iVar27;
        }
        iVar9 = (iVar17 * local_c->mapWidth + iVar9) % local_c->cellCountTotal;
        if ((iVar9 < 0) || (local_c->cellCount <= iVar9)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar16 = local_c->cells;
          local_c = PTR_0077241c;
        }
        else {
          pCVar16 = local_c->cells + iVar9;
        }
        iVar9 = local_c->cellX0;
        if (local_c->cellX0 <= iVar24) {
          iVar9 = iVar24;
        }
        iVar27 = local_c->cellY0;
        if (local_c->cellY0 <= iVar22 + 1) {
          iVar27 = iVar22 + 1;
        }
        iVar17 = local_c->cellY1 + -1;
        if (iVar27 < local_c->cellY1) {
          iVar17 = iVar27;
        }
        iVar27 = local_c->cellX1 + -1;
        if (iVar9 < local_c->cellX1) {
          iVar27 = iVar9;
        }
        iVar9 = (iVar17 * local_c->mapWidth + iVar27) % local_c->cellCountTotal;
        if ((iVar9 < 0) || (local_c->cellCount <= iVar9)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar18 = local_c->cells;
          local_c = PTR_0077241c;
        }
        else {
          pCVar18 = local_c->cells + iVar9;
        }
        bVar23 = (byte)((byte)pCVar18->material & (byte)pCVar16->material & (byte)pCVar15->material
                       & (byte)pCVar13->material) >> 7;
      }
      if (bVar2) {
LAB_005a6848:
        cVar21 = -1;
      }
      else {
        bVar20 = 0;
        if (!bVar3) {
          bVar20 = bVar23;
        }
        if (bVar20 != 0) goto LAB_005a6848;
        if (bVar4) {
          uVar28 = local_24 | 0x100;
          if (!bVar3) {
            uVar28 = local_24;
          }
          bVar23 = (byte)((int)uVar28 >> 2);
          if ((int)uVar28 >> 8 == 0) {
            bVar23 = bVar23 & 0x40 | 0x24;
          }
          else {
            uVar11 = CONCAT11(local_5,local_5) & 0xffffff38;
            local_7 = (byte)uVar11;
            if (local_7 < 0x38) {
              do {
                uVar12 = (uVar11 >> 8 & 7) + ((uVar11 >> 0xb & 7) + 1) * 8;
                if (uVar12 < 0x40) {
                  puVar19 = puVar1 + uVar12;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  uVar11 = (uint)CONCAT11(local_5,local_7);
                  puVar19 = puVar1;
                }
                if (((*puVar19 & 2) == 0) || (0x37 < (byte)uVar11)) break;
                local_5 = (char)(uVar11 >> 8) + 8;
                uVar11 = CONCAT11(local_5,local_5) & 0xffffff38;
                local_7 = (byte)uVar11;
              } while (local_7 < 0x38);
              local_c = PTR_0077241c;
            }
            bVar23 = bVar23 & 0x40 | (byte)(uVar11 >> 8);
          }
          pCVar10->field_0x12 = bVar23;
          cVar21 = (char)(uVar28 >> 8) * -0x1e + '2';
        }
        else {
          uVar28 = local_24 | 0x100;
          if (!bVar3) {
            uVar28 = local_24;
          }
          pCVar10->field_0x12 = (byte)((int)uVar28 >> 2) & 0x40 | local_5;
          cVar21 = (char)(uVar28 >> 8) * -0x1e + '2';
        }
      }
      pCVar10->field_0x6 = cVar21;
      iVar9 = iVar24;
      pCVar5 = local_c;
    }
    iVar22 = iVar22 + 1;
  } while( true );
}

