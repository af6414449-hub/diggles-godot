
void FUN_006096d0(void)

{
  CHeightBlockArray *pCVar1;
  CMap *pCVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float *in_ECX;
  CHeightBlock *pCVar7;
  uint in_EDX;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  float in_XMM1_Da;
  uint local_c;
  float local_8;
  
  uVar8 = (int)ROUND(in_ECX[1] * 8.0) + 3;
  uVar3 = (int)ROUND(*in_ECX * 8.0) - 4;
  DAT_00772dd8 = (int)ROUND(*in_ECX * 8.0);
  local_c = (int)ROUND(in_ECX[1] * 8.0) + 3;
  uVar10 = DAT_00772dd8 + 4;
  iVar4 = PTR_0077241c->x0_8 + 0x20;
  if ((((iVar4 <= (int)uVar3) && (iVar5 = PTR_0077241c->x1_8 + -0x20, (int)uVar3 < iVar5)) &&
      (iVar4 <= (int)uVar10)) &&
     ((((int)uVar10 < iVar5 && (iVar4 <= (int)local_c)) &&
      (((int)local_c < PTR_0077241c->y1_8 + -0x20 &&
       (local_8 = 0.375, PTR_0077241c->y0_8 + 0x20 <= (int)uVar8)))))) {
    while (pCVar2 = PTR_0077241c, (int)uVar8 < PTR_0077241c->y1_8 + 0x20) {
      piVar6 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar1 = pCVar2->heightBlocks;
      iVar4 = *piVar6;
      if ((iVar4 < 0) || (pCVar1->count <= iVar4)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar7 = pCVar1->data;
      }
      else {
        pCVar7 = pCVar1->data + iVar4;
      }
      pCVar2 = PTR_0077241c;
      uVar11 = (uVar8 & 7) << 3 | uVar3 & 7;
      if (pCVar7->heights[uVar11] != '\v') {
        return;
      }
      piVar6 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar1 = pCVar2->heightBlocks;
      iVar4 = *piVar6;
      if ((iVar4 < 0) || (pCVar1->count <= iVar4)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar7 = pCVar1->data;
      }
      else {
        pCVar7 = pCVar1->data + iVar4;
      }
      uVar9 = (local_c & 7) << 3 | uVar10 & 7;
      if (pCVar7->heights[uVar9] != '\v') {
        return;
      }
      iVar4 = FUN_00592f10(PTR_0077241c);
      if ((*(byte *)(iVar4 + 0x18) & 0x80) != 0) {
        return;
      }
      iVar4 = FUN_00592f10(PTR_0077241c);
      if ((((*(byte *)(uVar11 + 0x3c + iVar4) & 4) != 0) &&
          (iVar4 = FUN_00592f10(PTR_0077241c), *(short *)(iVar4 + 0x16) != 0)) &&
         (iVar4 = FUN_00592f10(PTR_0077241c), *(ushort *)(iVar4 + 0x16) != in_EDX)) {
        return;
      }
      iVar4 = FUN_00592f10(PTR_0077241c);
      if ((*(byte *)(iVar4 + 0x18) & 0x80) != 0) {
        return;
      }
      iVar4 = FUN_00592f10(PTR_0077241c);
      if ((((*(byte *)(iVar4 + 0x3c + uVar9) & 4) != 0) &&
          (iVar4 = FUN_00592f10(PTR_0077241c), *(short *)(iVar4 + 0x16) != 0)) &&
         (iVar4 = FUN_00592f10(PTR_0077241c), *(ushort *)(iVar4 + 0x16) != in_EDX)) {
        return;
      }
      uVar8 = uVar8 + 1;
      local_8 = local_8 + 0.125;
      local_c = local_c + 1;
      if (in_XMM1_Da <= local_8) {
        return;
      }
      if ((int)uVar8 < PTR_0077241c->y0_8 + 0x20) {
        return;
      }
    }
  }
  return;
}

