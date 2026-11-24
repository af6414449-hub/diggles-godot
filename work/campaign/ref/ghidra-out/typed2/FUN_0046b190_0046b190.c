
void FUN_0046b190(float *param_1,undefined1 *param_2)

{
  CHeightBlockArray *pCVar1;
  CMap *pCVar2;
  float *pfVar3;
  int iVar4;
  CMapCell *pCVar5;
  int *piVar6;
  CHeightBlock *pCVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  undefined1 local_1c [12];
  uint local_10;
  uint local_c;
  CMap *local_8;
  
  pfVar3 = param_1;
  if (*param_1 < PTR_0077241c->x0f + 0.0) {
    return;
  }
  if (PTR_0077241c->x1f - 0.0 <= *param_1) {
    return;
  }
  fVar11 = param_1[1];
  if (fVar11 < PTR_0077241c->y0f + 0.0) {
    return;
  }
  if (PTR_0077241c->y1f - 0.0 <= fVar11) {
    return;
  }
  param_1 = (float *)0x0;
  do {
    pCVar2 = PTR_0077241c;
    local_c = (uint)ROUND(fVar11 * 8.0);
    DAT_00772dd8 = (uint)ROUND(*pfVar3 * 8.0);
    local_8 = PTR_0077241c;
    iVar10 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= (int)DAT_00772dd8 >> 3) {
      iVar10 = (int)DAT_00772dd8 >> 3;
    }
    iVar9 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= (int)local_c >> 3) {
      iVar9 = (int)local_c >> 3;
    }
    iVar4 = PTR_0077241c->cellY1 + -1;
    if (iVar9 < PTR_0077241c->cellY1) {
      iVar4 = iVar9;
    }
    iVar9 = PTR_0077241c->cellX1 + -1;
    if (iVar10 < PTR_0077241c->cellX1) {
      iVar9 = iVar10;
    }
    iVar10 = (iVar4 * PTR_0077241c->mapWidth + iVar9) % PTR_0077241c->cellCountTotal;
    local_10 = DAT_00772dd8;
    if ((iVar10 < 0) || (PTR_0077241c->cellCount <= iVar10)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar5 = pCVar2->cells;
    }
    else {
      pCVar5 = PTR_0077241c->cells + iVar10;
    }
    iVar10 = pCVar5->heightBlockIndex;
    pCVar1 = pCVar2->heightBlocks;
    if ((iVar10 < 0) || (pCVar1->count <= iVar10)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar7 = pCVar1->data;
    }
    else {
      pCVar7 = pCVar1->data + iVar10;
    }
    if ((float)pCVar7->heights[(local_c & 7) << 3 | local_10 & 7] < pfVar3[2] ||
        (float)pCVar7->heights[(local_c & 7) << 3 | local_10 & 7] == pfVar3[2]) {
      fVar11 = pfVar3[1];
      param_1 = (float *)0x0;
      goto LAB_0046b350;
    }
    fVar11 = pfVar3[1] - 0.125;
    param_1 = (float *)((int)param_1 + 1);
    pfVar3[1] = fVar11;
  } while ((int)param_1 < 0x10);
  goto LAB_0046b41b;
  while( true ) {
    param_1 = (float *)((int)param_1 + 1);
    fVar11 = pfVar3[1] + 0.125;
    pfVar3[1] = fVar11;
    if (0xf < (int)param_1) break;
LAB_0046b350:
    pCVar2 = PTR_0077241c;
    DAT_00772dd8 = (uint)ROUND(*pfVar3 * 8.0);
    local_10 = DAT_00772dd8;
    piVar6 = (int *)FUN_00592f10(PTR_0077241c);
    pCVar1 = pCVar2->heightBlocks;
    iVar10 = *piVar6;
    if ((iVar10 < 0) || (pCVar1->count <= iVar10)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar7 = pCVar1->data;
    }
    else {
      pCVar7 = pCVar1->data + iVar10;
    }
    if (pfVar3[2] < (float)pCVar7->heights[((int)ROUND(fVar11 * 8.0) & 7U) << 3 | local_10 & 7])
    break;
  }
LAB_0046b41b:
  if (param_1 == (float *)0x10) {
    *param_2 = 0;
    pfVar8 = (float *)FUN_0046aec0(local_1c);
    *pfVar3 = *pfVar8;
    pfVar3[1] = pfVar8[1];
    pfVar3[2] = pfVar8[2];
  }
  return;
}

