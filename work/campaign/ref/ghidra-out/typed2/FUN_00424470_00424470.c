
uchar FUN_00424470(void)

{
  uint uVar1;
  uint uVar2;
  CHeightBlockArray *pCVar3;
  int iVar4;
  CMap *pCVar5;
  int *piVar6;
  CHeightBlock *pCVar7;
  uint *in_ECX;
  
  pCVar5 = PTR_0077241c;
  uVar1 = *in_ECX;
  uVar2 = in_ECX[1];
  piVar6 = (int *)FUN_00592f10(PTR_0077241c);
  pCVar3 = pCVar5->heightBlocks;
  iVar4 = *piVar6;
  if ((iVar4 < 0) || (pCVar3->count <= iVar4)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar7 = pCVar3->data;
  }
  else {
    pCVar7 = pCVar3->data + iVar4;
  }
  return pCVar7->heights[(uVar2 + 2 & 7) << 3 | uVar1 & 7];
}

