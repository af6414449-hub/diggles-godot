
void FUN_005780e0(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  CHeightBlock **ppCVar5;
  byte bVar6;
  CHeightBlock *pCVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float in_stack_00000014;
  
  piVar3 = (int *)FUN_00592f10(PTR_0077241c);
  piVar4 = (int *)FUN_00592f10(PTR_0077241c);
  iVar12 = *piVar3;
  ppCVar5 = &PTR_0077241c->heightBlocks->data;
  if ((iVar12 < 0) || (PTR_0077241c->heightBlocks->count <= iVar12)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar7 = *ppCVar5;
  }
  else {
    pCVar7 = *ppCVar5 + iVar12;
  }
  uVar1 = *(uint *)pCVar7->tail;
  iVar12 = *piVar4;
  ppCVar5 = &PTR_0077241c->heightBlocks->data;
  if ((iVar12 < 0) || (PTR_0077241c->heightBlocks->count <= iVar12)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar7 = *ppCVar5;
  }
  else {
    pCVar7 = *ppCVar5 + iVar12;
  }
  uVar2 = *(uint *)pCVar7->tail;
  fVar13 = (1.0 - (float)(*(byte *)(piVar3 + 4) & 0xf) / 15.0) * ((float)(uVar1 >> 0x19) + 0.0);
  if (((int)fVar13 != 0) &&
     ((bVar6 = *(byte *)((int)piVar4 + 0x1a) & 7, bVar6 == 0 ||
      ((*(byte *)((int)piVar3 + 0x1a) & 7) == bVar6)))) {
    uVar8 = uVar2 & 0x3ff;
    uVar10 = uVar1 & 0x3ff;
    if ((uVar10 != 0) && (uVar8 != 0)) {
      iVar12 = (int)fVar13;
      if (iVar12 < 8) {
        iVar12 = 8;
      }
      if (uVar10 < 0x20) {
        uVar10 = 0x20;
      }
      if (uVar8 < 0x20) {
        uVar8 = 0x20;
      }
      uVar9 = uVar2 >> 10 & 0xf;
      uVar11 = uVar1 >> 10 & 0xf;
      fVar13 = (float)(int)(uVar9 - (uVar2 >> 0xe & 0xf)) * (float)piVar4[7] +
               (float)(int)(8 - uVar9);
      fVar16 = (float)(int)(uVar11 - (uVar1 >> 0xe & 0xf)) * (float)piVar3[7] +
               (float)(int)(8 - uVar11);
      if (8.0 < fVar13) {
        fVar13 = (fVar13 - 8.0) * 8.0 + 8.0;
      }
      if (8.0 < fVar16) {
        fVar16 = (fVar16 - 8.0) * 8.0 + 8.0;
      }
      fVar15 = (float)uVar8 * (float)piVar4[8];
      fVar14 = (float)uVar10 * (float)piVar3[8];
      fVar16 = (fVar13 - fVar16) * 0.125 * 0.125 * (float)iVar12 * 1.4 + in_stack_00000014 * 0.3;
      fVar13 = fVar15;
      if (fVar16 <= fVar15) {
        fVar13 = fVar16;
      }
      if (fVar14 < -fVar13) {
        fVar13 = -fVar14;
      }
      fVar16 = (fVar15 - fVar13) / (float)uVar8;
      if (fVar16 < 0.001) {
        fVar16 = 0.0;
      }
      fVar13 = (fVar14 + fVar13) / (float)uVar10;
      if (fVar13 < 0.001) {
        fVar13 = 0.0;
      }
      *(undefined1 *)((int)piVar4 + 0x1b) = 0;
      piVar4[8] = (int)fVar16;
      if (fVar16 != 0.0) {
        *(undefined1 *)((int)piVar4 + 0x1b) = 2;
      }
      *(undefined1 *)((int)piVar3 + 0x1b) = 0;
      piVar3[8] = (int)fVar13;
      if (fVar13 != 0.0) {
        *(undefined1 *)((int)piVar3 + 0x1b) = 2;
      }
      return;
    }
  }
  return;
}

