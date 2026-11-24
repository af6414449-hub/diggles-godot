
uchar FUN_004238e0(void)

{
  uint uVar1;
  uint uVar2;
  CHeightBlockArray *pCVar3;
  int iVar4;
  CMap *pCVar5;
  byte bVar6;
  byte bVar7;
  uchar uVar8;
  int *piVar9;
  CHeightBlock *pCVar10;
  uint *in_ECX;
  
  pCVar5 = PTR_0077241c;
  uVar1 = in_ECX[1];
  uVar2 = *in_ECX;
  piVar9 = (int *)FUN_00592f10(PTR_0077241c);
  pCVar3 = pCVar5->heightBlocks;
  iVar4 = *piVar9;
  if ((iVar4 < 0) || (pCVar3->count <= iVar4)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar10 = pCVar3->data;
  }
  else {
    pCVar10 = pCVar3->data + iVar4;
  }
  uVar8 = pCVar10->heights[(uVar1 - 1 & 7) << 3 | uVar2 & 7];
  if (uVar8 == '\x0f') {
    FUN_004093f0(PTR_0077241c);
    FUN_004093f0(PTR_0077241c);
    bVar6 = FUN_004093f0(PTR_0077241c);
    FUN_004093f0(PTR_0077241c);
    FUN_004093f0(PTR_0077241c);
    bVar7 = FUN_004093f0(PTR_0077241c);
    if (bVar6 < bVar7) {
      FUN_004093f0(PTR_0077241c);
      FUN_004093f0(PTR_0077241c);
    }
    else {
      FUN_004093f0(PTR_0077241c);
      FUN_004093f0(PTR_0077241c);
    }
    uVar8 = FUN_004093f0(PTR_0077241c);
  }
  return uVar8;
}

