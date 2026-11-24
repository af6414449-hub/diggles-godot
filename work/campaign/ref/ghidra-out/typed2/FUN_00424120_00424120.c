
float * FUN_00424120(void)

{
  float fVar1;
  float fVar2;
  CHeightBlockArray *pCVar3;
  bool bVar4;
  CMap *pCVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  float *in_ECX;
  CHeightBlock *pCVar10;
  float *in_EDX;
  uint uVar11;
  int iVar12;
  float fVar13;
  
  fVar1 = *in_EDX;
  if ((((fVar1 < PTR_0077241c->x0f + 5.0) || (PTR_0077241c->x1f - 5.0 <= fVar1)) ||
      (fVar13 = in_EDX[1], fVar13 < PTR_0077241c->y0f + 5.0)) || (PTR_0077241c->y1f - 5.0 <= fVar13)
     ) {
    fVar13 = in_EDX[1];
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  fVar2 = in_EDX[2];
  if (!bVar4) {
    *in_ECX = fVar1;
    in_ECX[1] = fVar13;
    in_ECX[2] = fVar2;
    return in_ECX;
  }
  uVar11 = (uint)ROUND(fVar13 * 8.0);
  DAT_00772dd8 = uVar11;
  bVar6 = FUN_004093f0(PTR_0077241c);
  DAT_00772dd8 = (uint)ROUND((fVar2 - (float)bVar6) * 4.0);
  if ((int)DAT_00772dd8 < 5) {
    iVar7 = 5;
  }
  else {
    bVar6 = FUN_004093f0(PTR_0077241c);
    iVar7 = (int)ROUND((fVar2 - (float)bVar6) * 4.0);
    DAT_00772dd8 = iVar7;
  }
  iVar12 = 0x20;
  if (iVar7 < 0x20) {
    iVar12 = iVar7;
  }
  bVar6 = FUN_004093f0(PTR_0077241c);
  if (0 < iVar12) {
    uVar8 = (int)ROUND(fVar1 * 8.0) & 7;
    if ((float)bVar6 < fVar2) {
      do {
        pCVar5 = PTR_0077241c;
        uVar11 = uVar11 + 1;
        piVar9 = (int *)FUN_00592f10(PTR_0077241c);
        pCVar3 = pCVar5->heightBlocks;
        iVar7 = *piVar9;
        if ((iVar7 < 0) || (pCVar3->count <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar10 = pCVar3->data;
        }
        else {
          pCVar10 = pCVar3->data + iVar7;
        }
        if (fVar2 <= (float)pCVar10->heights[(uVar11 & 7) << 3 | uVar8]) goto LAB_00424446;
        iVar12 = iVar12 + -1;
      } while (0 < iVar12);
    }
    else {
      do {
        pCVar5 = PTR_0077241c;
        piVar9 = (int *)FUN_00592f10(PTR_0077241c);
        pCVar3 = pCVar5->heightBlocks;
        iVar7 = *piVar9;
        if ((iVar7 < 0) || (pCVar3->count <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar10 = pCVar3->data;
        }
        else {
          pCVar10 = pCVar3->data + iVar7;
        }
        if ((float)pCVar10->heights[(uVar11 - 1 & 7) << 3 | uVar8] < fVar2) {
LAB_00424446:
          *in_ECX = fVar1;
          in_ECX[2] = fVar2;
          in_ECX[1] = (float)(int)uVar11 * 0.125;
          return in_ECX;
        }
        iVar12 = iVar12 + -1;
        uVar11 = uVar11 - 1;
      } while (0 < iVar12);
    }
  }
  fVar1 = in_EDX[1];
  fVar13 = *in_EDX;
  DAT_00772dd8 = (uint)ROUND(fVar13 * 8.0);
  bVar6 = FUN_004093f0(PTR_0077241c);
  *in_ECX = fVar13;
  in_ECX[1] = fVar1;
  in_ECX[2] = (float)bVar6;
  return in_ECX;
}

