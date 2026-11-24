
undefined4 FUN_0060c590(void)

{
  float fVar1;
  uint uVar2;
  CHeightBlockArray *pCVar3;
  int iVar4;
  CMap *pCVar5;
  char cVar6;
  int *piVar7;
  byte *pbVar8;
  float *in_ECX;
  CHeightBlock *pCVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if ((((PTR_0077241c->x0f + 4.0 <= *in_ECX) && (*in_ECX < PTR_0077241c->x1f - 4.0)) &&
      (fVar1 = in_ECX[1], PTR_0077241c->y0f + 4.0 <= fVar1)) && (fVar1 < PTR_0077241c->y1f - 4.0)) {
    uVar2 = (uint)ROUND(*in_ECX * 8.0);
    iVar10 = 1;
    uVar12 = (int)ROUND(fVar1 * 8.0);
    DAT_00772dd8 = uVar2;
    do {
      pCVar5 = PTR_0077241c;
      uVar12 = uVar12 - 1;
      piVar7 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar3 = pCVar5->heightBlocks;
      iVar4 = *piVar7;
      if ((iVar4 < 0) || (pCVar3->count <= iVar4)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar9 = pCVar3->data;
      }
      else {
        pCVar9 = pCVar3->data + iVar4;
      }
      pCVar5 = PTR_0077241c;
      if (pCVar9->heights[(uVar12 & 7) << 3 | uVar2 & 7] != '\v') {
        return 0;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < 0xe);
    piVar7 = (int *)FUN_00592f10(PTR_0077241c);
    pCVar3 = pCVar5->heightBlocks;
    iVar10 = *piVar7;
    if ((iVar10 < 0) || (pCVar3->count <= iVar10)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar9 = pCVar3->data;
    }
    else {
      pCVar9 = pCVar3->data + iVar10;
    }
    pCVar5 = PTR_0077241c;
    uVar12 = ((int)ROUND(fVar1 * 8.0) & 7U) << 3;
    if (pCVar9->heights[uVar12 | uVar2 & 7] == '\x0f') {
      piVar7 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar3 = pCVar5->heightBlocks;
      iVar10 = *piVar7;
      if ((iVar10 < 0) || (pCVar3->count <= iVar10)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar9 = pCVar3->data;
      }
      else {
        pCVar9 = pCVar3->data + iVar10;
      }
      if ((((pCVar9->heights[uVar2 - 8 & 7 | uVar12] == '\x0f') &&
           (cVar6 = FUN_004093f0(PTR_0077241c), cVar6 == '\x0f')) &&
          (cVar6 = FUN_004093f0(PTR_0077241c), cVar6 == '\x0f')) &&
         ((cVar6 = FUN_004093f0(PTR_0077241c), cVar6 == '\x0f' &&
          (cVar6 = FUN_004093f0(PTR_0077241c), cVar6 == '\x0f')))) {
        DAT_00772dd8 = (uint)ROUND(*in_ECX * 8.0);
        local_14 = (int)ROUND(in_ECX[1] * 8.0) + -0x14;
        local_c = (int)ROUND(in_ECX[1] * 8.0) + 4;
        local_18 = DAT_00772dd8 + -8;
        local_10 = (int)ROUND(*in_ECX * 8.0) + 8;
        iVar10 = (local_c - local_14) * (local_10 - local_18);
        FUN_0041fa90(iVar10);
        FUN_005961c0(0,&local_18);
        pbVar11 = (byte *)0x0;
        if (0 < iVar10) {
          do {
            pbVar8 = pbVar11;
            if (-1 < (int)pbVar11) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar8 = (byte *)0x0;
            }
            if ((*pbVar8 & 0xc) != 0) {
              thunk_FUN_0060fc30(0);
              return 0;
            }
            pbVar11 = pbVar11 + 1;
          } while ((int)pbVar11 < iVar10);
        }
        thunk_FUN_0060fc30(0);
        return 1;
      }
    }
  }
  return 0;
}

