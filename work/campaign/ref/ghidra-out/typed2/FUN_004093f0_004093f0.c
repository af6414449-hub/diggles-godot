
undefined4 __thiscall FUN_004093f0(CMap *this)

{
  CHeightBlockArray *pCVar1;
  int iVar2;
  int *piVar3;
  CHeightBlock *pCVar4;
  uint in_stack_00000004;
  uint in_stack_00000008;
  
  piVar3 = (int *)FUN_00592f10(this);
  pCVar1 = this->heightBlocks;
  iVar2 = *piVar3;
  if ((iVar2 < 0) || (pCVar1->count <= iVar2)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar4 = pCVar1->data;
  }
  else {
    pCVar4 = pCVar1->data + iVar2;
  }
  return CONCAT31((int3)((uint)pCVar4 >> 8),
                  pCVar4->heights[(in_stack_00000008 & 7) << 3 | in_stack_00000004 & 7]);
}

