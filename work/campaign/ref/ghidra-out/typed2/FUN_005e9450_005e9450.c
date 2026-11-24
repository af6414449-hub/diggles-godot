
void FUN_005e9450(float *param_1,float *param_2)

{
  float fVar1;
  CHeightBlockArray *pCVar2;
  int iVar3;
  float fVar4;
  bool bVar5;
  CMap *pCVar6;
  int *piVar7;
  CHeightBlock *pCVar8;
  uint uVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  fVar1 = *param_2;
  if ((((fVar1 < PTR_0077241c->x0f + 5.0) || (PTR_0077241c->x1f - 5.0 <= fVar1)) ||
      (fVar13 = param_2[1], fVar13 < PTR_0077241c->y0f + 5.0)) ||
     (PTR_0077241c->y1f - 5.0 <= fVar13)) {
    fVar13 = param_2[1];
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  fVar12 = param_2[2];
  if (!bVar5) {
    *param_1 = fVar1;
    param_1[1] = fVar13;
    param_1[2] = fVar12;
    return;
  }
  fVar11 = fVar1 * 8.0;
  fVar4 = ROUND(fVar11);
  uVar9 = (uint)ROUND(fVar13 * 8.0);
  iVar10 = 3;
  DAT_00772dd8 = uVar9;
  FUN_005e93e0();
  if (fVar11 < fVar12) {
    do {
      pCVar6 = PTR_0077241c;
      uVar9 = uVar9 + 1;
      piVar7 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar2 = pCVar6->heightBlocks;
      iVar3 = *piVar7;
      if ((iVar3 < 0) || (pCVar2->count <= iVar3)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar8 = pCVar2->data;
      }
      else {
        pCVar8 = pCVar2->data + iVar3;
      }
      if (fVar12 <= (float)pCVar8->heights[(uVar9 & 7) << 3 | (int)fVar4 & 7U] + 0.1)
      goto LAB_005e96d5;
      iVar10 = iVar10 + -1;
    } while (0 < iVar10);
  }
  else {
    do {
      pCVar6 = PTR_0077241c;
      piVar7 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar2 = pCVar6->heightBlocks;
      iVar3 = *piVar7;
      if ((iVar3 < 0) || (pCVar2->count <= iVar3)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar8 = pCVar2->data;
      }
      else {
        pCVar8 = pCVar2->data + iVar3;
      }
      if ((float)pCVar8->heights[(uVar9 - 1 & 7) << 3 | (int)fVar4 & 7U] + 0.1 < fVar12) {
LAB_005e96d5:
        param_1[2] = fVar12;
        *param_1 = fVar1;
        param_1[1] = (float)(int)uVar9 * 0.125;
        return;
      }
      iVar10 = iVar10 + -1;
      uVar9 = uVar9 - 1;
    } while (0 < iVar10);
  }
  fVar1 = param_2[1];
  fVar13 = *param_2;
  fVar12 = fVar13 * 8.0;
  DAT_00772dd8 = (uint)ROUND(fVar12);
  FUN_005e93e0();
  *param_1 = fVar13;
  param_1[1] = fVar1;
  param_1[2] = fVar12;
  return;
}

