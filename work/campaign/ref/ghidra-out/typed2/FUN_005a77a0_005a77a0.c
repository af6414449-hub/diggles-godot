
void FUN_005a77a0(int param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  ushort uVar1;
  CMap *pCVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  CMapCell *pCVar10;
  int iVar11;
  int local_c;
  
  iVar9 = (int)((param_1 >> 0x1f & 7U) + param_1) >> 3;
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 7U)) >> 3;
  iVar11 = (int)((param_3 >> 0x1f & 7U) + param_3) >> 3;
  iVar8 = (int)((param_4 >> 0x1f & 7U) + param_4) >> 3;
  if (iVar9 < PTR_0077241c->cellX0) {
    iVar9 = PTR_0077241c->cellX0;
  }
  if (iVar3 < PTR_0077241c->cellY0) {
    iVar3 = PTR_0077241c->cellY0;
  }
  if (PTR_0077241c->cellX1 < iVar11) {
    iVar11 = PTR_0077241c->cellX1;
  }
  if (PTR_0077241c->cellY1 < iVar8) {
    iVar8 = PTR_0077241c->cellY1;
  }
  iVar7 = PTR_0077241c->heightBlocks->currentBlock;
  iVar6 = 0;
  if (iVar7 != -1) {
    iVar6 = iVar7;
  }
  for (; iVar3 < iVar8; iVar3 = iVar3 + 1) {
    if (iVar9 < iVar11) {
      local_c = iVar9;
      do {
        pCVar2 = PTR_0077241c;
        iVar7 = PTR_0077241c->cellX0;
        if (PTR_0077241c->cellX0 <= local_c) {
          iVar7 = local_c;
        }
        iVar5 = PTR_0077241c->cellY0;
        if (PTR_0077241c->cellY0 <= iVar3) {
          iVar5 = iVar3;
        }
        iVar4 = PTR_0077241c->cellY1 + -1;
        if (iVar5 < PTR_0077241c->cellY1) {
          iVar4 = iVar5;
        }
        iVar5 = PTR_0077241c->cellX1 + -1;
        if (iVar7 < PTR_0077241c->cellX1) {
          iVar5 = iVar7;
        }
        iVar7 = (iVar4 * PTR_0077241c->mapWidth + iVar5) % PTR_0077241c->cellCountTotal;
        if ((iVar7 < 0) || (PTR_0077241c->cellCount <= iVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar10 = pCVar2->cells;
        }
        else {
          pCVar10 = PTR_0077241c->cells + iVar7;
        }
        if (pCVar10->objectIndex != 0xffff) {
          FUN_004c68d0((CSceneRenderer *)(DAT_0076a338 + 0x28b0));
        }
        uVar1 = pCVar10->material;
        pCVar10->heightBlockIndex = iVar6;
        pCVar10->objectIndex = 0xffff;
        pCVar10->field_0x6 = 0xff;
        pCVar10->light = '\x04';
        _memset(&pCVar10->digMarks,0,0x74);
        pCVar10->material = uVar1 & 0xff7c | param_5 & 3;
        local_c = local_c + 1;
      } while (local_c < iVar11);
    }
  }
  return;
}

