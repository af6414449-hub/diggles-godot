
int FUN_0059a740(void)

{
  byte bVar1;
  int iVar2;
  CHeightBlockArray *pCVar3;
  int *piVar4;
  int *piVar5;
  CHeightBlock *pCVar6;
  uint uVar7;
  uint uVar8;
  
  piVar4 = (int *)FUN_00592f10(PTR_0077241c);
  piVar5 = (int *)FUN_00592f10(PTR_0077241c);
  if (((*(byte *)((int)piVar4 + 0x12) ^ *(byte *)((int)piVar5 + 0x12)) & 0x40) != 0) {
    iVar2 = *piVar4;
    pCVar3 = PTR_0077241c->heightBlocks;
    if ((iVar2 < 0) || (pCVar3->count <= iVar2)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar6 = pCVar3->data;
    }
    else {
      pCVar6 = pCVar3->data + iVar2;
    }
    bVar1 = pCVar6->heights[0x24];
    iVar2 = *piVar5;
    pCVar3 = PTR_0077241c->heightBlocks;
    if ((iVar2 < 0) || (pCVar3->count <= iVar2)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar6 = pCVar3->data;
    }
    else {
      pCVar6 = pCVar3->data + iVar2;
    }
    uVar7 = (uint)pCVar6->heights[0x24];
    if ((uint)bVar1 < (uint)pCVar6->heights[0x24]) {
      uVar7 = (uint)bVar1;
    }
    return (uint)*(byte *)((int)piVar5 + 6) + uVar7 * -0x10 + 0x114;
  }
  if (((*(byte *)((int)piVar4 + 0x12) | *(byte *)((int)piVar5 + 0x12)) & 0x40) == 0) {
    iVar2 = *piVar4;
    pCVar3 = PTR_0077241c->heightBlocks;
    if ((iVar2 < 0) || (pCVar3->count <= iVar2)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar6 = pCVar3->data;
    }
    else {
      pCVar6 = pCVar3->data + iVar2;
    }
    bVar1 = pCVar6->heights[0x24];
    iVar2 = *piVar5;
    pCVar3 = PTR_0077241c->heightBlocks;
    if ((iVar2 < 0) || (pCVar3->count <= iVar2)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar6 = pCVar3->data;
    }
    else {
      pCVar6 = pCVar3->data + iVar2;
    }
    uVar7 = (uint)bVar1 - (uint)pCVar6->heights[0x24];
    uVar8 = (int)uVar7 >> 0x1f;
    return *(byte *)((int)piVar5 + 6) + 1 + ((uVar7 ^ uVar8) - uVar8) * 0x10;
  }
  return *(byte *)((int)piVar5 + 6) + 1;
}

