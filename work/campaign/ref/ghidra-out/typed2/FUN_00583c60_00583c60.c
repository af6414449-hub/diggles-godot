
void FUN_00583c60(void)

{
  CMap *pCVar1;
  int iVar2;
  int iVar3;
  CMapCell *pCVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar2 = *(int *)(in_ECX + 0x58) - *(int *)(in_ECX + 0x50);
  iVar6 = *(int *)(in_ECX + 0x54);
  if (iVar6 < *(int *)(in_ECX + 0x5c)) {
    do {
      iVar9 = *(int *)(in_ECX + 0x50);
      if (iVar9 < *(int *)(in_ECX + 0x58)) {
        do {
          pCVar1 = PTR_0077241c;
          iVar8 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar9) {
            iVar8 = iVar9;
          }
          iVar7 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar6) {
            iVar7 = iVar6;
          }
          iVar3 = PTR_0077241c->cellY1 + -1;
          if (iVar7 < PTR_0077241c->cellY1) {
            iVar3 = iVar7;
          }
          iVar7 = PTR_0077241c->cellX1 + -1;
          if (iVar8 < PTR_0077241c->cellX1) {
            iVar7 = iVar8;
          }
          iVar8 = (iVar3 * PTR_0077241c->mapWidth + iVar7) % PTR_0077241c->cellCountTotal;
          if ((iVar8 < 0) || (PTR_0077241c->cellCount <= iVar8)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar4 = pCVar1->cells;
          }
          else {
            pCVar4 = PTR_0077241c->cells + iVar8;
          }
          if ((((pCVar4->flags & 1) == 0) && (iVar9 + 1 < PTR_0077241c->cellX1)) &&
             (iVar6 + 1 < PTR_0077241c->cellY1)) {
            iVar8 = ((iVar6 - *(int *)(in_ECX + 0x54)) * iVar2 - *(int *)(in_ECX + 0x50)) + iVar9;
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x88) <= iVar8)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              **(undefined4 **)(in_ECX + 0x84) = 0;
            }
            else {
              *(undefined4 *)(*(int *)(in_ECX + 0x84) + iVar8 * 4) = 0;
            }
          }
          else {
            iVar8 = ((iVar6 - *(int *)(in_ECX + 0x54)) * iVar2 - *(int *)(in_ECX + 0x50)) + iVar9;
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x88) <= iVar8)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar5 = *(undefined4 **)(in_ECX + 0x84);
            }
            else {
              puVar5 = (undefined4 *)(*(int *)(in_ECX + 0x84) + iVar8 * 4);
            }
            *puVar5 = 1;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < *(int *)(in_ECX + 0x58));
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(in_ECX + 0x5c));
  }
  return;
}

