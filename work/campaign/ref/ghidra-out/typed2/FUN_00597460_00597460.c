
byte FUN_00597460(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  CHeightBlockArray *pCVar5;
  CMap *pCVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  CMapCell *pCVar10;
  CHeightBlock *pCVar11;
  uint uVar12;
  byte bVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  
  pCVar6 = PTR_0077241c;
  bVar13 = 0;
  bVar4 = 0;
  if ((((PTR_0077241c->cellX0 + 1 <= param_1) && (param_1 < PTR_0077241c->cellX1 + -1)) &&
      (PTR_0077241c->cellY0 + 1 <= param_2)) && (param_2 < PTR_0077241c->cellY1 + -1)) {
    iVar1 = param_2 * 8 + 4;
    uVar17 = param_2 * 8 - 4;
    if ((int)uVar17 < iVar1) {
      uVar2 = param_1 * 8 - 4;
      iVar3 = param_1 * 8 + 4;
      do {
        if ((int)uVar2 < iVar3) {
          iVar14 = (int)uVar17 >> 3;
          uVar12 = uVar2;
          do {
            iVar7 = (int)uVar12 >> 3;
            iVar16 = pCVar6->cellX0;
            if (pCVar6->cellX0 <= iVar7) {
              iVar16 = iVar7;
            }
            iVar8 = pCVar6->cellY0;
            if (pCVar6->cellY0 <= iVar14) {
              iVar8 = iVar14;
            }
            iVar15 = pCVar6->cellY1 + -1;
            if (iVar8 < pCVar6->cellY1) {
              iVar15 = iVar8;
            }
            iVar8 = pCVar6->cellX1 + -1;
            if (iVar16 < pCVar6->cellX1) {
              iVar8 = iVar16;
            }
            iVar16 = (iVar8 + iVar15 * pCVar6->mapWidth) % pCVar6->cellCountTotal;
            if ((iVar16 < 0) || (pCVar6->cellCount <= iVar16)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar10 = pCVar6->cells;
            }
            else {
              pCVar10 = pCVar6->cells + iVar16;
            }
            iVar16 = pCVar10->heightBlockIndex;
            pCVar5 = pCVar6->heightBlocks;
            if ((iVar16 < 0) || (pCVar5->count <= iVar16)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar11 = pCVar5->data;
            }
            else {
              pCVar11 = pCVar5->data + iVar16;
            }
            uVar9 = uVar12 & 7 | (uVar17 & 7) << 3;
            if (bVar4 < pCVar11->heights[uVar9]) {
              iVar16 = pCVar6->cellX0;
              if (pCVar6->cellX0 <= iVar7) {
                iVar16 = iVar7;
              }
              iVar7 = pCVar6->cellY0;
              if (pCVar6->cellY0 <= iVar14) {
                iVar7 = iVar14;
              }
              iVar8 = pCVar6->cellY1 + -1;
              if (iVar7 < pCVar6->cellY1) {
                iVar8 = iVar7;
              }
              iVar7 = pCVar6->cellX1 + -1;
              if (iVar16 < pCVar6->cellX1) {
                iVar7 = iVar16;
              }
              iVar16 = (iVar7 + iVar8 * pCVar6->mapWidth) % pCVar6->cellCountTotal;
              if ((iVar16 < 0) || (pCVar6->cellCount <= iVar16)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar10 = pCVar6->cells;
              }
              else {
                pCVar10 = pCVar6->cells + iVar16;
              }
              iVar16 = pCVar10->heightBlockIndex;
              pCVar5 = pCVar6->heightBlocks;
              if ((iVar16 < 0) || (pCVar5->count <= iVar16)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar11 = pCVar5->data;
              }
              else {
                pCVar11 = pCVar5->data + iVar16;
              }
              bVar4 = pCVar11->heights[uVar9];
            }
            uVar12 = uVar12 + 1;
            bVar13 = bVar4;
          } while ((int)uVar12 < iVar3);
        }
        uVar17 = uVar17 + 1;
      } while ((int)uVar17 < iVar1);
    }
    return bVar13;
  }
  return 0xf;
}

