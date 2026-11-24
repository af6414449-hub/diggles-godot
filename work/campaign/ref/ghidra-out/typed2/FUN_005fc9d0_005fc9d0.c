
void FUN_005fc9d0(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,
                 float param_7,int param_8,int param_9,int param_10,int param_11)

{
  ushort uVar1;
  int iVar2;
  CMapCell *pCVar3;
  uint uVar4;
  int iVar5;
  CMap *pCVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  CMap *local_48;
  float local_40;
  
  if (param_1 < PTR_0077241c->cellX0) {
    param_1 = PTR_0077241c->cellX0;
  }
  if (param_2 < PTR_0077241c->cellY0) {
    param_2 = PTR_0077241c->cellY0;
  }
  if (PTR_0077241c->cellX1 < param_3) {
    param_3 = PTR_0077241c->cellX1;
  }
  if (PTR_0077241c->cellY1 < param_4) {
    param_4 = PTR_0077241c->cellY1;
  }
  if (param_6 == 1) {
    param_6._0_2_ = 2;
  }
  else {
    if (param_6 == 2) {
      param_6 = 1;
    }
  }
  iVar7 = param_3 - param_1;
  iVar10 = param_4 - param_2;
  iVar2 = iVar7;
  if (iVar10 <= iVar7) {
    iVar2 = iVar10;
  }
  param_7 = param_7 / ((float)iVar2 * 0.2);
  pCVar6 = PTR_0077241c;
  if (param_1 < param_3 + -1) {
    iVar2 = param_2;
    local_48 = PTR_0077241c;
    iVar5 = param_1;
    do {
      for (; iVar2 < param_4 + -1; iVar2 = iVar2 + 1) {
        if (((((param_1 <= param_8) || (param_10 <= param_3)) || (param_2 <= param_9)) ||
            (pCVar6 = local_48, param_11 <= param_4)) &&
           (((pCVar6->cellX0 <= iVar5 && (iVar5 < pCVar6->cellX1)) &&
            ((pCVar6->cellY0 <= iVar2 && (iVar2 < pCVar6->cellY1)))))) {
          iVar9 = pCVar6->cellX0;
          if (pCVar6->cellX0 <= iVar5) {
            iVar9 = iVar5;
          }
          iVar11 = pCVar6->cellY0;
          if (pCVar6->cellY0 <= iVar2) {
            iVar11 = iVar2;
          }
          iVar8 = local_48->cellY1 + -1;
          if (iVar11 < local_48->cellY1) {
            iVar8 = iVar11;
          }
          iVar11 = pCVar6->cellX1 + -1;
          if (iVar9 < pCVar6->cellX1) {
            iVar11 = iVar9;
          }
          iVar9 = (iVar11 + iVar8 * local_48->mapWidth) % local_48->cellCountTotal;
          if ((iVar9 < 0) || (local_48->cellCount <= iVar9)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar3 = local_48->cells;
            local_48 = PTR_0077241c;
          }
          else {
            pCVar3 = local_48->cells + iVar9;
          }
          local_40 = 1.0;
          iVar9 = iVar7 / 2 + param_1;
          iVar11 = iVar10 / 2 + param_2;
          if (((param_5 & 4) != 0) && (iVar9 < iVar5)) {
            local_40 = 1.0 - ((((float)(iVar9 - iVar5) / (float)iVar7) * (float)(iVar9 - iVar5)) /
                             (float)iVar7) / param_7;
          }
          if (((param_5 & 8) != 0) && (iVar5 < iVar9)) {
            local_40 = local_40 -
                       ((((float)(iVar9 - iVar5) / (float)iVar7) * (float)(iVar9 - iVar5)) /
                       (float)iVar7) / param_7;
          }
          if (((param_5 & 1) != 0) && (iVar11 < iVar2)) {
            local_40 = local_40 -
                       ((((float)(iVar11 - iVar2) / (float)iVar10) * (float)(iVar11 - iVar2)) /
                       (float)iVar10) / param_7;
          }
          if (((param_5 & 2) != 0) && (iVar2 < iVar11)) {
            local_40 = local_40 -
                       ((((float)(iVar11 - iVar2) / (float)iVar10) * (float)(iVar11 - iVar2)) /
                       (float)iVar10) / param_7;
          }
          uVar1 = pCVar3->material & 3;
          pCVar6 = local_48;
          if ((uVar1 != 3) && (uVar1 != 0)) {
            uVar4 = FUN_0049c670();
            if ((float)(uVar4 & 0x7fff) <= local_40 * 32768.0) {
              pCVar3->material = pCVar3->material & 0xfffc | (ushort)param_6;
            }
            local_48 = PTR_0077241c;
            pCVar6 = PTR_0077241c;
          }
        }
      }
      iVar5 = iVar5 + 1;
      iVar2 = param_2;
    } while (iVar5 < param_3 + -1);
  }
  iVar2 = param_1 * 8 + -8;
  uVar12 = 0x10;
  iVar5 = param_4 * 8 + 8;
  iVar9 = param_2 * 8 + -8;
  iVar11 = param_3 * 8 + 8;
  FUN_005a3dd0(pCVar6,iVar2,iVar9,iVar11,iVar5,0x10);
  FUN_005a3fd0(iVar2,iVar9,iVar11,iVar5,uVar12);
  FUN_005fa510((int)(param_1 + (param_1 >> 0x1f & 3U)) >> 2,
               (int)(param_2 + (param_2 >> 0x1f & 3U)) >> 2,(int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2
               ,(int)(iVar10 + (iVar10 >> 0x1f & 3U)) >> 2);
  return;
}

