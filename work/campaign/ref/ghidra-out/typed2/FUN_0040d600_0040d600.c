
void FUN_0040d600(float *param_1)

{
  int *piVar1;
  uint uVar2;
  CHeightBlockArray *pCVar3;
  CMap *pCVar4;
  int iVar5;
  CMapCell *pCVar6;
  CHeightBlock *pCVar7;
  int in_ECX;
  int iVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int local_c;
  
  iVar9 = *(int *)(in_ECX + 0x30);
  iVar8 = *(int *)(in_ECX + 0x10);
  piVar1 = (int *)(iVar8 + 8);
  uVar2 = iVar9 - 1;
  if (*(uint *)(iVar8 + 0xc) <= uVar2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar9 = *(int *)(in_ECX + 0x30);
    iVar8 = *(int *)(in_ECX + 0x10);
  }
  iVar5 = *piVar1;
  if (*(uint *)(iVar8 + 0xc) <= iVar9 - 1U) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  fVar11 = *(float *)(*(int *)(in_ECX + 0x28) + 0xc);
  fVar12 = (float)*(int *)(iVar5 + 4 + uVar2 * 8) * 0.125;
  if (fVar11 <= (float)*(int *)(*(int *)(iVar8 + 8) + (iVar9 - 1U) * 8) * 0.125) {
    fVar11 = fVar11 + 2.0;
  }
  else {
    fVar11 = fVar11 - 2.0;
  }
  local_c = 10;
  *param_1 = fVar11;
  param_1[1] = fVar12;
  param_1[2] = 14.0;
  fVar10 = fVar12;
  do {
    pCVar4 = PTR_0077241c;
    uVar2 = (uint)ROUND(*param_1 * 8.0);
    iVar8 = (int)ROUND(fVar10 * 8.0) >> 3;
    iVar9 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= (int)uVar2 >> 3) {
      iVar9 = (int)uVar2 >> 3;
    }
    iVar5 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= iVar8) {
      iVar5 = iVar8;
    }
    iVar8 = PTR_0077241c->cellY1 + -1;
    if (iVar5 < PTR_0077241c->cellY1) {
      iVar8 = iVar5;
    }
    iVar5 = PTR_0077241c->cellX1 + -1;
    if (iVar9 < PTR_0077241c->cellX1) {
      iVar5 = iVar9;
    }
    iVar9 = (iVar5 + iVar8 * PTR_0077241c->mapWidth) % PTR_0077241c->cellCountTotal;
    DAT_00772dd8 = uVar2;
    if ((iVar9 < 0) || (PTR_0077241c->cellCount <= iVar9)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar6 = pCVar4->cells;
    }
    else {
      pCVar6 = PTR_0077241c->cells + iVar9;
    }
    iVar9 = pCVar6->heightBlockIndex;
    pCVar3 = pCVar4->heightBlocks;
    if ((iVar9 < 0) || (pCVar3->count <= iVar9)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar7 = pCVar3->data;
    }
    else {
      pCVar7 = pCVar3->data + iVar9;
    }
    if (param_1[2] <= (float)pCVar7->heights[((int)ROUND(fVar10 * 8.0) & 7U) << 3 | uVar2 & 7])
    break;
    local_c = local_c + -1;
    fVar10 = param_1[1] + 0.125;
    param_1[1] = fVar10;
  } while (0 < local_c);
  if (local_c == 0) {
    *param_1 = fVar11;
    param_1[1] = fVar12;
    param_1[2] = 14.0;
  }
  return;
}

