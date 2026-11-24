
void FUN_0040f260(void)

{
  float fVar1;
  CHeightBlockArray *pCVar2;
  CMap *pCVar3;
  int iVar4;
  CMapCell *pCVar5;
  int in_ECX;
  int iVar6;
  CHeightBlock *pCVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  fVar11 = *(float *)(in_ECX + 0x4c) + *(float *)(in_ECX + 0x54);
  fVar13 = *(float *)(in_ECX + 0x50);
  if (fVar11 <= *(float *)(in_ECX + 0x50)) {
    fVar13 = fVar11;
  }
  *(float *)(in_ECX + 0x54) = fVar13;
  iVar8 = *(int *)(in_ECX + 0xc);
  fVar11 = *(float *)(iVar8 + 0x10);
  fVar1 = *(float *)(iVar8 + 0x14);
  uVar10 = (uint)(*(float *)(iVar8 + 0xc) * 8.0);
  fVar12 = fVar11;
  while( true ) {
    pCVar3 = PTR_0077241c;
    fVar12 = fVar12 + 0.125;
    uVar9 = (uint)(fVar12 * 8.0);
    if (((((int)uVar10 < PTR_0077241c->x0_8 + 0x21) || (PTR_0077241c->x1_8 + -0x21 <= (int)uVar10))
        || ((int)uVar9 < PTR_0077241c->y0_8 + 0x21)) || (PTR_0077241c->y1_8 + -0x21 <= (int)uVar9))
    break;
    iVar8 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= (int)uVar10 >> 3) {
      iVar8 = (int)uVar10 >> 3;
    }
    iVar6 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= (int)uVar9 >> 3) {
      iVar6 = (int)uVar9 >> 3;
    }
    iVar4 = PTR_0077241c->cellY1 + -1;
    if (iVar6 < PTR_0077241c->cellY1) {
      iVar4 = iVar6;
    }
    iVar6 = PTR_0077241c->cellX1 + -1;
    if (iVar8 < PTR_0077241c->cellX1) {
      iVar6 = iVar8;
    }
    iVar8 = (iVar4 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
    if ((iVar8 < 0) || (PTR_0077241c->cellCount <= iVar8)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar5 = pCVar3->cells;
    }
    else {
      pCVar5 = PTR_0077241c->cells + iVar8;
    }
    iVar8 = pCVar5->heightBlockIndex;
    pCVar2 = pCVar3->heightBlocks;
    if ((iVar8 < 0) || (pCVar2->count <= iVar8)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar7 = pCVar2->data;
    }
    else {
      pCVar7 = pCVar2->data + iVar8;
    }
    if ((int)fVar1 < (int)(uint)pCVar7->heights[(uVar9 & 7) << 3 | uVar10 & 7]) break;
    if (fVar13 + fVar11 <= fVar12) {
      *(float *)(in_ECX + 0x58) = (fVar13 + fVar11) - fVar11;
      return;
    }
  }
  *(undefined1 *)(in_ECX + 0x5c) = 1;
  *(float *)(in_ECX + 0x58) = fVar12 - fVar11;
  return;
}

