
void FUN_005789b0(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  CHeightBlock **ppCVar5;
  int iVar6;
  byte bVar7;
  CHeightBlock *pCVar8;
  uint uVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float in_stack_00000014;
  
  piVar3 = (int *)FUN_00592f10(PTR_0077241c);
  piVar4 = (int *)FUN_00592f10(PTR_0077241c);
  iVar6 = *piVar3;
  ppCVar5 = &PTR_0077241c->heightBlocks->data;
  if ((iVar6 < 0) || (PTR_0077241c->heightBlocks->count <= iVar6)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar8 = *ppCVar5;
  }
  else {
    pCVar8 = *ppCVar5 + iVar6;
  }
  uVar1 = *(uint *)pCVar8->tail;
  iVar6 = *piVar4;
  ppCVar5 = &PTR_0077241c->heightBlocks->data;
  if ((iVar6 < 0) || (PTR_0077241c->heightBlocks->count <= iVar6)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar8 = *ppCVar5;
  }
  else {
    pCVar8 = *ppCVar5 + iVar6;
  }
  uVar2 = *(uint *)pCVar8->tail;
  iVar6 = (int)((1.0 - (float)(*(byte *)(piVar3 + 4) >> 4) / 15.0) *
               ((float)(uVar1 >> 0x12 & 0x7f) + 0.0));
  if ((iVar6 != 0) &&
     ((bVar7 = *(byte *)((int)piVar4 + 0x1a) & 7, bVar7 == 0 ||
      ((*(byte *)((int)piVar3 + 0x1a) & 7) == bVar7)))) {
    if (((uVar1 & 0x3ff) != 0) && ((uVar2 & 0x3ff) != 0)) {
      fVar11 = (float)(uVar1 & 0x3ff);
      if (iVar6 < 0x10) {
        iVar6 = 0x10;
      }
      uVar9 = uVar2 >> 10 & 0xf;
      fVar15 = 128.0;
      if (128.0 <= fVar11) {
        fVar15 = fVar11;
      }
      uVar10 = uVar1 >> 10 & 0xf;
      fVar12 = (float)(uVar2 & 0x3ff);
      fVar11 = 128.0;
      if (128.0 <= fVar12) {
        fVar11 = fVar12;
      }
      fVar13 = (float)(int)(uVar9 - (uVar2 >> 0xe & 0xf)) * (float)piVar4[7] +
               (float)(int)(0x10 - uVar9);
      fVar12 = (float)(int)(uVar10 - (uVar1 >> 0xe & 0xf)) * (float)piVar3[7] +
               (float)(int)(8 - uVar10);
      if (8.0 < fVar13) {
        fVar13 = (fVar13 - 8.0) * 8.0 + 8.0;
      }
      if (8.0 < fVar12) {
        fVar12 = (fVar12 - 8.0) * 8.0 + 8.0;
      }
      fVar16 = (float)piVar4[8] * fVar11;
      fVar14 = (float)piVar3[8] * fVar15;
      fVar13 = (fVar13 - fVar12) * 0.125 * 0.125 * (float)iVar6 * 1.3 + in_stack_00000014 * 0.125;
      fVar12 = fVar16;
      if (fVar13 <= fVar16) {
        fVar12 = fVar13;
      }
      if (fVar14 < -fVar12) {
        fVar12 = -fVar14;
      }
      fVar11 = (fVar16 - fVar12) / fVar11;
      if (fVar11 < 0.001) {
        fVar11 = 0.0;
      }
      fVar15 = (fVar14 + fVar12) / fVar15;
      if (fVar15 < 0.001) {
        fVar15 = 0.0;
      }
      *(undefined1 *)((int)piVar4 + 0x1b) = 0;
      piVar4[8] = (int)fVar11;
      if (fVar11 != 0.0) {
        *(undefined1 *)((int)piVar4 + 0x1b) = 3;
      }
      *(undefined1 *)((int)piVar3 + 0x1b) = 0;
      piVar3[8] = (int)fVar15;
      if (fVar15 != 0.0) {
        *(undefined1 *)((int)piVar3 + 0x1b) = 3;
      }
      return;
    }
  }
  return;
}

