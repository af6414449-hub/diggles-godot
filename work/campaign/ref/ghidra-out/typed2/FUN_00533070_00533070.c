
void FUN_00533070(int *param_1,uint param_2)

{
  ushort uVar1;
  CMap *pCVar2;
  int iVar3;
  CMapCell *pCVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  ushort uVar10;
  
  if (param_2 != 1) {
    uVar7 = 2 - param_2;
    iVar6 = param_1[1];
    if (iVar6 < param_1[3]) {
      do {
        iVar9 = *param_1;
        if (iVar9 < param_1[2]) {
          do {
            pCVar2 = PTR_0077241c;
            iVar8 = PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= iVar9) {
              iVar8 = iVar9;
            }
            iVar5 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= iVar6) {
              iVar5 = iVar6;
            }
            iVar3 = PTR_0077241c->cellY1 + -1;
            if (iVar5 < PTR_0077241c->cellY1) {
              iVar3 = iVar5;
            }
            iVar5 = PTR_0077241c->cellX1 + -1;
            if (iVar8 < PTR_0077241c->cellX1) {
              iVar5 = iVar8;
            }
            iVar8 = (iVar3 * PTR_0077241c->mapWidth + iVar5) % PTR_0077241c->cellCountTotal;
            if ((iVar8 < 0) || (PTR_0077241c->cellCount <= iVar8)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar4 = pCVar2->cells;
            }
            else {
              pCVar4 = PTR_0077241c->cells + iVar8;
            }
            uVar1 = *(ushort *)&pCVar4->field_0x14;
            iVar8 = 0;
            do {
              if ((uVar1 >> (((char)iVar8 + '\x04') * '\x02' & 0x1fU) & 3) == param_2) {
                uVar10 = uVar1 >> 5 & 7;
                if (uVar1 >> 0xe == uVar7) {
                  FUN_00532a70(1,uVar10);
                }
                if ((uVar1 >> 0xc & 3) == uVar7) {
                  FUN_00532a70(1,uVar10);
                }
                if ((uVar1 >> 10 & 3) == uVar7) {
                  FUN_00532a70(1,uVar10);
                }
                if ((uVar1 >> 8 & 3) == uVar7) {
                  FUN_00532a70(1,uVar10);
                }
                break;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < 4);
            iVar9 = iVar9 + 1;
          } while (iVar9 < param_1[2]);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_1[3]);
    }
  }
  return;
}

