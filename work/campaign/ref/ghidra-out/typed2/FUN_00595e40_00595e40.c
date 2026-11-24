
void FUN_00595e40(int param_1,uint *param_2)

{
  uint uVar1;
  CHeightBlockArray *pCVar2;
  undefined4 uVar3;
  int iVar4;
  CMap *pCVar5;
  int iVar6;
  int iVar7;
  CMapCell *pCVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  CHeightBlock *pCVar14;
  uchar *puVar15;
  uchar *puVar16;
  int iVar17;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  
  pCVar5 = PTR_0077241c;
  uVar1 = *param_2;
  local_24 = param_2[1] & 7;
  iVar6 = (int)(param_2[2] - 1) >> 3;
  local_18 = 8;
  iVar7 = (int)(param_2[3] - 1) >> 3;
  for (iVar11 = (int)param_2[1] >> 3; iVar11 < iVar7 + 1; iVar11 = iVar11 + 1) {
    local_20 = *param_2 & 7;
    local_1c = 8;
    iVar4 = (int)uVar1 >> 3;
    if (iVar11 == iVar7) {
      local_18 = (param_2[3] - 1 & 7) + 1;
    }
    for (; iVar4 < iVar6 + 1; iVar4 = iVar4 + 1) {
      iVar12 = pCVar5->cellX0;
      if (pCVar5->cellX0 <= iVar4) {
        iVar12 = iVar4;
      }
      iVar17 = pCVar5->cellY0;
      if (pCVar5->cellY0 <= iVar11) {
        iVar17 = iVar11;
      }
      iVar13 = pCVar5->cellY1 + -1;
      if (iVar17 < pCVar5->cellY1) {
        iVar13 = iVar17;
      }
      iVar17 = pCVar5->cellX1 + -1;
      if (iVar12 < pCVar5->cellX1) {
        iVar17 = iVar12;
      }
      iVar12 = (iVar13 * pCVar5->mapWidth + iVar17) % pCVar5->cellCountTotal;
      if ((iVar12 < 0) || (pCVar5->cellCount <= iVar12)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar8 = pCVar5->cells;
      }
      else {
        pCVar8 = pCVar5->cells + iVar12;
      }
      iVar12 = pCVar8->heightBlockIndex;
      pCVar2 = pCVar5->heightBlocks;
      if ((iVar12 < 0) || (pCVar2->count <= iVar12)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = pCVar2->data;
      }
      else {
        pCVar14 = pCVar2->data + iVar12;
      }
      if (iVar4 == iVar6) {
        local_1c = (param_2[2] - 1 & 7) + 1;
      }
      if (((local_1c | local_20 | local_18) & 7) == 0 && local_24 == 0) {
        iVar12 = iVar11 * 8;
        iVar17 = iVar4 * 8;
        uVar3 = *(undefined4 *)(pCVar14->heights + 4);
        iVar13 = ((param_2[2] - *param_2) * (iVar12 - param_2[1]) - *param_2) + iVar17;
        *(undefined4 *)(iVar13 + param_1) = *(undefined4 *)pCVar14->heights;
        *(undefined4 *)(iVar13 + 4 + param_1) = uVar3;
        iVar13 = (((iVar12 - param_2[1]) + 1) * (param_2[2] - *param_2) - *param_2) + iVar17;
        uVar3 = *(undefined4 *)(pCVar14->heights + 0xc);
        *(undefined4 *)(iVar13 + param_1) = *(undefined4 *)(pCVar14->heights + 8);
        *(undefined4 *)(iVar13 + 4 + param_1) = uVar3;
        uVar3 = *(undefined4 *)(pCVar14->heights + 0x14);
        iVar13 = (((iVar12 - param_2[1]) + 2) * (param_2[2] - *param_2) - *param_2) + iVar17;
        *(undefined4 *)(iVar13 + param_1) = *(undefined4 *)(pCVar14->heights + 0x10);
        *(undefined4 *)(iVar13 + 4 + param_1) = uVar3;
        uVar3 = *(undefined4 *)(pCVar14->heights + 0x1c);
        iVar13 = (((iVar12 - param_2[1]) + 3) * (param_2[2] - *param_2) - *param_2) + iVar17;
        *(undefined4 *)(iVar13 + param_1) = *(undefined4 *)(pCVar14->heights + 0x18);
        *(undefined4 *)(iVar13 + 4 + param_1) = uVar3;
        uVar3 = *(undefined4 *)(pCVar14->heights + 0x24);
        iVar13 = (((iVar12 - param_2[1]) + 4) * (param_2[2] - *param_2) - *param_2) + iVar17;
        *(undefined4 *)(iVar13 + param_1) = *(undefined4 *)(pCVar14->heights + 0x20);
        *(undefined4 *)(iVar13 + 4 + param_1) = uVar3;
        uVar3 = *(undefined4 *)(pCVar14->heights + 0x2c);
        iVar13 = (((iVar12 - param_2[1]) + 5) * (param_2[2] - *param_2) - *param_2) + iVar17;
        *(undefined4 *)(iVar13 + param_1) = *(undefined4 *)(pCVar14->heights + 0x28);
        *(undefined4 *)(iVar13 + 4 + param_1) = uVar3;
        uVar3 = *(undefined4 *)(pCVar14->heights + 0x34);
        iVar13 = (((iVar12 - param_2[1]) + 6) * (param_2[2] - *param_2) - *param_2) + iVar17;
        *(undefined4 *)(iVar13 + param_1) = *(undefined4 *)(pCVar14->heights + 0x30);
        *(undefined4 *)(iVar13 + 4 + param_1) = uVar3;
        uVar3 = *(undefined4 *)(pCVar14->heights + 0x3c);
        iVar17 = (((iVar12 - param_2[1]) + 7) * (param_2[2] - *param_2) - *param_2) + iVar17;
        *(undefined4 *)(iVar17 + param_1) = *(undefined4 *)(pCVar14->heights + 0x38);
        *(undefined4 *)(iVar17 + 4 + param_1) = uVar3;
      }
      else if (local_24 < local_18) {
        puVar16 = pCVar14->heights + local_20 + local_24 * 8;
        uVar10 = local_24;
        do {
          if (local_20 < local_1c) {
            uVar9 = local_20;
            puVar15 = puVar16;
            do {
              iVar12 = (((iVar11 * 8 - param_2[1]) + uVar10) * (param_2[2] - *param_2) - *param_2) +
                       iVar4 * 8 + uVar9;
              uVar9 = uVar9 + 1;
              *(uchar *)(iVar12 + param_1) = *puVar15;
              puVar15 = puVar15 + 1;
            } while ((int)uVar9 < (int)local_1c);
          }
          uVar10 = uVar10 + 1;
          puVar16 = puVar16 + 8;
        } while ((int)uVar10 < (int)local_18);
      }
      local_20 = 0;
    }
    local_24 = 0;
  }
  return;
}

