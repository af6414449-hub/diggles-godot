
uint FUN_0057a940(void)

{
  float fVar1;
  CHeightBlockArray *pCVar2;
  float fVar3;
  uint uVar4;
  int *piVar5;
  CHeightBlock *pCVar6;
  int iVar7;
  CHeightBlock **ppCVar8;
  float in_XMM0_Da;
  float in_XMM1_Da;
  float local_8;
  
  uVar4 = DAT_00772400;
  if (*(char *)(DAT_00772400 + 0x98) == '\0') {
LAB_0057aae6:
    return uVar4 & 0xffffff00;
  }
  uVar4 = (uint)in_XMM1_Da;
  if (((((int)in_XMM0_Da < PTR_0077241c->cellX0) || (PTR_0077241c->cellX1 <= (int)in_XMM0_Da)) ||
      ((int)uVar4 < PTR_0077241c->cellY0)) || (PTR_0077241c->cellY1 <= (int)uVar4))
  goto LAB_0057aae6;
  piVar5 = (int *)FUN_00592f10(PTR_0077241c);
  fVar1 = (float)piVar5[8];
  if (fVar1 == 0.0) {
    return (uint)CONCAT21((short)((uint)piVar5 >> 0x10),
                          (fVar1 == 0.0) << 6 | NAN(fVar1) << 2 | 2U | fVar1 < 0.0) << 8;
  }
  iVar7 = *piVar5;
  pCVar2 = PTR_0077241c->heightBlocks;
  if ((iVar7 < 0) || (pCVar2->count <= iVar7)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar7 = *piVar5;
    local_8 = (float)(*(uint *)pCVar2->data->tail >> 0xe & 0xf) + 0.0;
    ppCVar8 = &PTR_0077241c->heightBlocks->data;
    if (-1 < iVar7) goto LAB_0057aa7c;
  }
  else {
    local_8 = (float)(*(uint *)pCVar2->data[iVar7].tail >> 0xe & 0xf) + 0.0;
    ppCVar8 = &PTR_0077241c->heightBlocks->data;
LAB_0057aa7c:
    if (iVar7 < (int)ppCVar8[1]) {
      pCVar6 = *ppCVar8 + iVar7;
      goto LAB_0057aa9b;
    }
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pCVar6 = *ppCVar8;
LAB_0057aa9b:
  fVar3 = (float)(*(uint *)pCVar6->tail >> 10 & 0xf) + 0.0;
  return (uint)((1.0 - (in_XMM1_Da - (float)(int)uVar4)) * 8.0 <
               (fVar3 - local_8) * fVar1 + (8.0 - fVar3));
}

