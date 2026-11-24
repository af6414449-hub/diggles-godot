
void FUN_0060b1b0(void)

{
  float fVar1;
  CHeightBlockArray *pCVar2;
  CMap *pCVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  CHeightBlock *pCVar8;
  float *in_ECX;
  uint in_EDX;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  float in_XMM2_Da;
  int local_8;
  
  fVar1 = *in_ECX;
  if ((((PTR_0077241c->x0f + 4.0 <= fVar1) && (fVar1 < PTR_0077241c->x1f - 4.0)) &&
      (fVar13 = in_ECX[1], PTR_0077241c->y0f + 4.0 <= fVar13)) && (fVar13 < PTR_0077241c->y1f - 4.0)
     ) {
    cVar4 = FUN_004093f0(PTR_0077241c);
    if (cVar4 == '\v') {
      uVar11 = 0xfffffffc - (int)(fVar13 * -8.0);
      uVar5 = FUN_004093f0(PTR_0077241c);
      local_8 = 2;
      uVar12 = uVar11;
      if (PTR_0077241c->y0_8 + 0x20 < (int)uVar11) {
        while (((int)uVar12 < PTR_0077241c->y1_8 + -0x20 &&
               (iVar6 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar6 + 0x18) & 0x80) == 0))) {
          iVar6 = FUN_00592f10(PTR_0077241c);
          uVar9 = (uVar12 & 7) << 3 | (int)(fVar1 * 8.0) + 4U & 7;
          if (((*(byte *)(iVar6 + 0x3c + uVar9) & 4) != 0) &&
             ((iVar6 = FUN_00592f10(PTR_0077241c), *(short *)(iVar6 + 0x16) != 0 &&
              (iVar6 = FUN_00592f10(PTR_0077241c), *(ushort *)(iVar6 + 0x16) != in_EDX)))) {
            return;
          }
          iVar6 = FUN_00592f10(PTR_0077241c);
          if ((*(byte *)(iVar6 + 0x18) & 0x80) != 0) {
            return;
          }
          uVar10 = (uVar11 & 7) << 3 | (int)(fVar1 * 8.0) - 4U & 7;
          iVar6 = FUN_00592f10(PTR_0077241c);
          if ((((*(byte *)(iVar6 + 0x3c + uVar10) & 4) != 0) &&
              (iVar6 = FUN_00592f10(PTR_0077241c), *(short *)(iVar6 + 0x16) != 0)) &&
             (iVar6 = FUN_00592f10(PTR_0077241c), *(ushort *)(iVar6 + 0x16) != in_EDX)) {
            return;
          }
          pCVar3 = PTR_0077241c;
          piVar7 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar2 = pCVar3->heightBlocks;
          iVar6 = *piVar7;
          if ((iVar6 < 0) || (pCVar2->count <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar8 = pCVar2->data;
          }
          else {
            pCVar8 = pCVar2->data + iVar6;
          }
          pCVar3 = PTR_0077241c;
          iVar6 = (uVar5 & 0xff) - (uint)pCVar8->heights[uVar10];
          if (1 < iVar6) {
            return;
          }
          if (iVar6 < 0) {
            return;
          }
          piVar7 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar2 = pCVar3->heightBlocks;
          iVar6 = *piVar7;
          if ((iVar6 < 0) || (pCVar2->count <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar8 = pCVar2->data;
          }
          else {
            pCVar8 = pCVar2->data + iVar6;
          }
          iVar6 = (uVar5 & 0xff) - (uint)pCVar8->heights[uVar9];
          if (1 < iVar6) {
            return;
          }
          if (iVar6 < 0) {
            return;
          }
          local_8 = local_8 + 1;
          uVar11 = uVar11 - 4;
          uVar12 = uVar12 - 4;
          fVar14 = (float)local_8 * 0.5 - 0.5;
          fVar13 = 0.0;
          if (0.0 <= fVar14) {
            fVar13 = fVar14;
          }
          if (in_XMM2_Da <= fVar13) {
            return;
          }
          if ((int)uVar12 <= PTR_0077241c->y0_8 + 0x20) {
            return;
          }
        }
      }
      return;
    }
  }
  return;
}

