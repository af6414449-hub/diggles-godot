
uchar FUN_005e93e0(void)

{
  CHeightBlockArray *pCVar1;
  int iVar2;
  CMap *pCVar3;
  int *piVar4;
  CHeightBlock *pCVar5;
  uint in_ECX;
  uint in_EDX;
  
  pCVar3 = PTR_0077241c;
  piVar4 = (int *)FUN_00592f10(PTR_0077241c);
  pCVar1 = pCVar3->heightBlocks;
  iVar2 = *piVar4;
  if ((iVar2 < 0) || (pCVar1->count <= iVar2)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar5 = pCVar1->data;
  }
  else {
    pCVar5 = pCVar1->data + iVar2;
  }
  return pCVar5->heights[(in_EDX & 7) << 3 | in_ECX & 7];
}

