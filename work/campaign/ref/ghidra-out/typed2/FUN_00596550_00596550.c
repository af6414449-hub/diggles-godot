
void FUN_00596550(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  CMap *pCVar4;
  int iVar5;
  int iVar6;
  CMapCell *pCVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uchar *puVar14;
  int iVar15;
  uint uVar16;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_18;
  
  pCVar4 = PTR_0077241c;
  uVar1 = *param_2;
  local_28 = param_2[1] & 7;
  iVar5 = (int)(param_2[2] - 1) >> 3;
  local_20 = 8;
  iVar6 = (int)(param_2[3] - 1) >> 3;
  for (iVar12 = (int)param_2[1] >> 3; iVar12 < iVar6 + 1; iVar12 = iVar12 + 1) {
    local_24 = *param_2 & 7;
    local_18 = 8;
    iVar3 = (int)uVar1 >> 3;
    if (iVar12 == iVar6) {
      local_20 = (param_2[3] - 1 & 7) + 1;
    }
    for (; iVar3 < iVar5 + 1; iVar3 = iVar3 + 1) {
      iVar13 = pCVar4->cellX0;
      if (pCVar4->cellX0 <= iVar3) {
        iVar13 = iVar3;
      }
      iVar10 = pCVar4->cellY0;
      if (pCVar4->cellY0 <= iVar12) {
        iVar10 = iVar12;
      }
      iVar15 = pCVar4->cellY1 + -1;
      if (iVar10 < pCVar4->cellY1) {
        iVar15 = iVar10;
      }
      iVar10 = pCVar4->cellX1 + -1;
      if (iVar13 < pCVar4->cellX1) {
        iVar10 = iVar13;
      }
      iVar13 = (iVar15 * pCVar4->mapWidth + iVar10) % pCVar4->cellCountTotal;
      if ((iVar13 < 0) || (pCVar4->cellCount <= iVar13)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar7 = pCVar4->cells;
      }
      else {
        pCVar7 = pCVar4->cells + iVar13;
      }
      if (iVar3 == iVar5) {
        local_18 = (param_2[2] - 1 & 7) + 1;
      }
      if (((local_18 | local_24 | local_20) & 7) == 0 && local_28 == 0) {
        iVar13 = iVar3 * 8;
        iVar10 = iVar12 * 8;
        iVar15 = ((iVar10 - param_2[1]) * (param_2[2] - *param_2) - *param_2) + iVar13;
        uVar2 = *(undefined4 *)(iVar15 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 4) = *(undefined4 *)(iVar15 + 4 + param_1);
        *(undefined4 *)pCVar7->sampleFlags = uVar2;
        iVar15 = (((iVar10 - param_2[1]) + 1) * (param_2[2] - *param_2) - *param_2) + iVar13;
        uVar2 = *(undefined4 *)(iVar15 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0xc) = *(undefined4 *)(iVar15 + 4 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 8) = uVar2;
        iVar15 = (((iVar10 - param_2[1]) + 2) * (param_2[2] - *param_2) - *param_2) + iVar13;
        uVar2 = *(undefined4 *)(iVar15 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x14) = *(undefined4 *)(iVar15 + 4 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x10) = uVar2;
        iVar15 = (((iVar10 - param_2[1]) + 3) * (param_2[2] - *param_2) - *param_2) + iVar13;
        uVar2 = *(undefined4 *)(iVar15 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x1c) = *(undefined4 *)(iVar15 + 4 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x18) = uVar2;
        iVar15 = (((iVar10 - param_2[1]) + 4) * (param_2[2] - *param_2) - *param_2) + iVar13;
        uVar2 = *(undefined4 *)(iVar15 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x24) = *(undefined4 *)(iVar15 + 4 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x20) = uVar2;
        iVar15 = (((iVar10 - param_2[1]) + 5) * (param_2[2] - *param_2) - *param_2) + iVar13;
        uVar2 = *(undefined4 *)(iVar15 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x2c) = *(undefined4 *)(iVar15 + 4 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x28) = uVar2;
        iVar15 = (((iVar10 - param_2[1]) + 6) * (param_2[2] - *param_2) - *param_2) + iVar13;
        uVar2 = *(undefined4 *)(iVar15 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x34) = *(undefined4 *)(iVar15 + 4 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x30) = uVar2;
        iVar13 = (((iVar10 - param_2[1]) + 7) * (param_2[2] - *param_2) - *param_2) + iVar13;
        uVar2 = *(undefined4 *)(iVar13 + 4 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x38) = *(undefined4 *)(iVar13 + param_1);
        *(undefined4 *)(pCVar7->sampleFlags + 0x3c) = uVar2;
      }
      else {
        uVar9 = local_28;
        if (local_28 < local_20) {
          do {
            if (local_24 < local_18) {
              uVar8 = uVar9 * 8 + local_24;
              uVar16 = local_24;
              do {
                uVar11 = *param_2;
                iVar13 = param_2[2] - uVar11;
                if (uVar8 < 0x40) {
                  puVar14 = pCVar7->sampleFlags + uVar16 + uVar9 * 8;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  uVar11 = *param_2;
                  puVar14 = pCVar7->sampleFlags;
                }
                iVar13 = (((iVar12 * 8 - param_2[1]) + uVar9) * iVar13 - uVar11) + iVar3 * 8 +
                         uVar16;
                uVar16 = uVar16 + 1;
                *puVar14 = *(uchar *)(iVar13 + param_1);
                uVar8 = uVar8 + 1;
              } while ((int)uVar16 < (int)local_18);
            }
            uVar9 = uVar9 + 1;
          } while ((int)uVar9 < (int)local_20);
        }
      }
      local_24 = 0;
    }
    local_28 = 0;
  }
  return;
}

