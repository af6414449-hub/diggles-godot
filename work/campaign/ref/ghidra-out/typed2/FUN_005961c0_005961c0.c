
void FUN_005961c0(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  CMap *pCVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  CMapCell *pCVar10;
  uchar *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uchar *puVar17;
  uint local_2c;
  uint local_28;
  uint local_1c;
  uint local_14;
  
  pCVar4 = PTR_0077241c;
  uVar1 = *param_2;
  local_2c = param_2[1] & 7;
  iVar5 = (int)(param_2[2] - 1) >> 3;
  local_14 = 8;
  iVar6 = (int)(param_2[3] - 1) >> 3;
  for (iVar8 = (int)param_2[1] >> 3; iVar8 < iVar6 + 1; iVar8 = iVar8 + 1) {
    local_28 = *param_2 & 7;
    local_1c = 8;
    iVar3 = (int)uVar1 >> 3;
    if (iVar8 == iVar6) {
      local_14 = (param_2[3] - 1 & 7) + 1;
    }
    for (; iVar3 < iVar5 + 1; iVar3 = iVar3 + 1) {
      iVar9 = pCVar4->cellX0;
      if (pCVar4->cellX0 <= iVar3) {
        iVar9 = iVar3;
      }
      iVar12 = pCVar4->cellY0;
      if (pCVar4->cellY0 <= iVar8) {
        iVar12 = iVar8;
      }
      iVar16 = pCVar4->cellY1 + -1;
      if (iVar12 < pCVar4->cellY1) {
        iVar16 = iVar12;
      }
      iVar12 = pCVar4->cellX1 + -1;
      if (iVar9 < pCVar4->cellX1) {
        iVar12 = iVar9;
      }
      iVar9 = (iVar16 * pCVar4->mapWidth + iVar12) % pCVar4->cellCountTotal;
      if ((iVar9 < 0) || (pCVar4->cellCount <= iVar9)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar10 = pCVar4->cells;
      }
      else {
        pCVar10 = pCVar4->cells + iVar9;
      }
      if (iVar3 == iVar5) {
        local_1c = (param_2[2] - 1 & 7) + 1;
      }
      if (((local_1c | local_28 | local_14) & 7) == 0 && local_2c == 0) {
        iVar16 = iVar3 * 8;
        iVar9 = iVar8 * 8;
        uVar2 = *(undefined4 *)(pCVar10->sampleFlags + 4);
        iVar12 = ((iVar9 - param_2[1]) * (param_2[2] - *param_2) - *param_2) + iVar16;
        *(undefined4 *)(iVar12 + param_1) = *(undefined4 *)pCVar10->sampleFlags;
        *(undefined4 *)(iVar12 + 4 + param_1) = uVar2;
        iVar12 = (((iVar9 - param_2[1]) + 1) * (param_2[2] - *param_2) - *param_2) + iVar16;
        uVar2 = *(undefined4 *)(pCVar10->sampleFlags + 0xc);
        *(undefined4 *)(iVar12 + param_1) = *(undefined4 *)(pCVar10->sampleFlags + 8);
        *(undefined4 *)(iVar12 + 4 + param_1) = uVar2;
        uVar2 = *(undefined4 *)(pCVar10->sampleFlags + 0x14);
        iVar12 = (((iVar9 - param_2[1]) + 2) * (param_2[2] - *param_2) - *param_2) + iVar16;
        *(undefined4 *)(iVar12 + param_1) = *(undefined4 *)(pCVar10->sampleFlags + 0x10);
        *(undefined4 *)(iVar12 + 4 + param_1) = uVar2;
        uVar2 = *(undefined4 *)(pCVar10->sampleFlags + 0x1c);
        iVar12 = (((iVar9 - param_2[1]) + 3) * (param_2[2] - *param_2) - *param_2) + iVar16;
        *(undefined4 *)(iVar12 + param_1) = *(undefined4 *)(pCVar10->sampleFlags + 0x18);
        *(undefined4 *)(iVar12 + 4 + param_1) = uVar2;
        uVar2 = *(undefined4 *)(pCVar10->sampleFlags + 0x24);
        iVar12 = (((iVar9 - param_2[1]) + 4) * (param_2[2] - *param_2) - *param_2) + iVar16;
        *(undefined4 *)(iVar12 + param_1) = *(undefined4 *)(pCVar10->sampleFlags + 0x20);
        *(undefined4 *)(iVar12 + 4 + param_1) = uVar2;
        uVar2 = *(undefined4 *)(pCVar10->sampleFlags + 0x2c);
        iVar12 = (((iVar9 - param_2[1]) + 5) * (param_2[2] - *param_2) - *param_2) + iVar16;
        *(undefined4 *)(iVar12 + param_1) = *(undefined4 *)(pCVar10->sampleFlags + 0x28);
        *(undefined4 *)(iVar12 + 4 + param_1) = uVar2;
        uVar2 = *(undefined4 *)(pCVar10->sampleFlags + 0x34);
        iVar12 = (((iVar9 - param_2[1]) + 6) * (param_2[2] - *param_2) - *param_2) + iVar16;
        *(undefined4 *)(iVar12 + param_1) = *(undefined4 *)(pCVar10->sampleFlags + 0x30);
        *(undefined4 *)(iVar12 + 4 + param_1) = uVar2;
        uVar2 = *(undefined4 *)(pCVar10->sampleFlags + 0x3c);
        iVar16 = (((iVar9 - param_2[1]) + 7) * (param_2[2] - *param_2) - *param_2) + iVar16;
        *(undefined4 *)(iVar16 + param_1) = *(undefined4 *)(pCVar10->sampleFlags + 0x38);
        *(undefined4 *)(iVar16 + 4 + param_1) = uVar2;
      }
      else if (local_2c < local_14) {
        uVar14 = local_28 + local_2c * 8;
        puVar11 = pCVar10->sampleFlags + local_2c * 8;
        uVar7 = local_2c;
        do {
          if (local_28 < local_1c) {
            uVar13 = uVar14;
            uVar15 = local_28;
            do {
              if (uVar13 < 0x40) {
                puVar17 = puVar11 + uVar15;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                puVar17 = pCVar10->sampleFlags;
              }
              uVar13 = uVar13 + 1;
              iVar9 = (((iVar8 * 8 - param_2[1]) + uVar7) * (param_2[2] - *param_2) - *param_2) +
                      iVar3 * 8 + uVar15;
              uVar15 = uVar15 + 1;
              *(uchar *)(iVar9 + param_1) = *puVar17;
            } while ((int)uVar15 < (int)local_1c);
          }
          uVar7 = uVar7 + 1;
          uVar14 = uVar14 + 8;
          puVar11 = puVar11 + 8;
        } while ((int)uVar7 < (int)local_14);
      }
      local_28 = 0;
    }
    local_2c = 0;
  }
  return;
}

