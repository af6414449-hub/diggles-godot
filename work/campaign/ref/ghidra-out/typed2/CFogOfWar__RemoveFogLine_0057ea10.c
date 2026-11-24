
void CFogOfWar__RemoveFogLine
               (int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  byte bVar1;
  uint uVar2;
  CMap *pCVar3;
  int iVar4;
  uint uVar5;
  CHeightBlock **ppCVar6;
  uchar *puVar7;
  int iVar8;
  CHeightBlock *pCVar9;
  uchar *puVar10;
  uint *puVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  CMapCell *pCVar17;
  uint uVar18;
  uint uVar19;
  undefined8 uVar20;
  undefined4 uVar21;
  CMapCell *local_2c;
  int local_28;
  int local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070616d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca5490) &&
     (FUN_006cebf4(&DAT_00ca5490,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca5490 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    DAT_00ca5494 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) =
         "CFogOfWar::RemoveFogLine(int iX0,int iY0,int iY1,int iXSize,int iYSize,int iOwner)";
    *(int *)(&DAT_00773650 + iVar12) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5490);
  }
  iVar12 = DAT_00ca5494;
  uVar21 = *(undefined4 *)(&DAT_00773650 + DAT_00ca5494 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar21;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar12 * 0x10];
  if (iVar4 == 0) {
    uVar20 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar12 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar20;
  }
  (&DAT_00773654)[iVar12 * 0x10] = iVar4 + 1;
  local_20 = param_1 - param_4;
  local_8 = 0;
  iVar4 = PTR_0077241c->x0_8 + 0x20;
  if (((((iVar4 <= (int)local_20) &&
        (local_28 = PTR_0077241c->x1_8 + -0x20, (int)local_20 < local_28)) &&
       (local_24 = PTR_0077241c->y0_8 + 0x20, local_24 <= param_2)) &&
      ((iVar12 = PTR_0077241c->y1_8 + -0x20, param_2 < iVar12 &&
       (local_1c = param_1 + param_4, iVar4 <= local_1c)))) &&
     ((local_1c < local_28 && ((local_24 <= param_3 && (param_3 < iVar12)))))) {
    piVar13 = (int *)(DAT_00772400 + 0xa328);
    if (param_6 < 8) {
      piVar13 = (int *)(param_6 * 0x10 + DAT_00772400 + 0xa328);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*(char *)(DAT_00772400 + 0x8c) == '\0') {
      iVar12 = (int)((param_2 - param_5) + (param_2 - param_5 >> 0x1f & 7U)) >> 3;
      iVar4 = piVar13[1];
      if (iVar12 <= piVar13[1]) {
        iVar4 = iVar12;
      }
      piVar13[1] = iVar4;
      iVar12 = (int)(local_20 + ((int)local_20 >> 0x1f & 7U)) >> 3;
      iVar4 = *piVar13;
      if (iVar12 <= *piVar13) {
        iVar4 = iVar12;
      }
      *piVar13 = iVar4;
      iVar12 = (int)(param_3 + param_5 + (param_3 + param_5 >> 0x1f & 7U)) >> 3;
      iVar4 = piVar13[3];
      if (piVar13[3] <= iVar12) {
        iVar4 = iVar12;
      }
      piVar13[3] = iVar4;
      iVar12 = (int)(local_1c + (local_1c >> 0x1f & 7U)) >> 3;
      iVar4 = piVar13[2];
      if (piVar13[2] <= iVar12) {
        iVar4 = iVar12;
      }
      piVar13[2] = iVar4;
    }
    uVar19 = param_3 + 4U & 0xfffffff8;
    local_20 = *local_14;
    uVar14 = param_1 + 4U & 0xfffffff8;
    uVar5 = param_2 + 4U & 0xfffffff8;
    local_18 = uVar14;
    if ((int)uVar5 < (int)uVar19) {
      local_28 = uVar14 + param_4;
      local_24 = uVar14 - param_4;
      do {
        param_2 = 0;
        uVar18 = uVar14;
        if ((int)uVar14 < local_28) {
          iVar4 = (int)(uVar5 + ((int)uVar5 >> 0x1f & 7U)) >> 3;
          do {
            pCVar3 = PTR_0077241c;
            local_1c = (int)(((int)uVar14 >> 0x1f & 7U) + uVar14) >> 3;
            iVar12 = PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= local_1c) {
              iVar12 = local_1c;
            }
            iVar16 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= iVar4) {
              iVar16 = iVar4;
            }
            iVar8 = PTR_0077241c->cellY1 + -1;
            if (iVar16 < PTR_0077241c->cellY1) {
              iVar8 = iVar16;
            }
            iVar16 = PTR_0077241c->cellX1 + -1;
            if (iVar12 < PTR_0077241c->cellX1) {
              iVar16 = iVar12;
            }
            iVar12 = (iVar8 * PTR_0077241c->mapWidth + iVar16) % PTR_0077241c->cellCountTotal;
            if ((iVar12 < 0) || (PTR_0077241c->cellCount <= iVar12)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar17 = pCVar3->cells;
            }
            else {
              pCVar17 = PTR_0077241c->cells + iVar12;
            }
            iVar12 = pCVar17->heightBlockIndex;
            ppCVar6 = &PTR_0077241c->heightBlocks->data;
            local_2c = pCVar17;
            if ((iVar12 < 0) || (PTR_0077241c->heightBlocks->count <= iVar12)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar9 = *ppCVar6;
            }
            else {
              pCVar9 = *ppCVar6 + iVar12;
            }
            if (param_2 == 0) {
              if (0xe < (pCVar9->heights[0] & 0xf)) {
                param_2 = 1;
              }
            }
            else {
              uVar18 = local_18;
              if (param_2 == 3) break;
              param_2 = param_2 + 1;
            }
            puVar7 = pCVar17->ownerIndex;
            if (param_6 < 8) {
              puVar10 = puVar7 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar10 = puVar7;
            }
            bVar1 = *puVar10;
            if (bVar1 != 0xff) {
              if (bVar1 < 2) {
                if (bVar1 == 0) {
                  FUN_0057dfc0(&local_2c,local_1c,iVar4,param_6);
                }
                if (param_6 < 8) {
                  puVar11 = local_14 + param_6;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar11 = local_14;
                }
                if ((int)(puVar11[3] * 8) <= (int)uVar5) {
                  if (param_6 < 8) {
                    puVar11 = local_14 + param_6 * 2;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    puVar11 = local_14;
                  }
                  FUN_005813a0(1);
                  uVar18 = puVar11[0xb];
                  uVar2 = puVar11[0xc];
                  *(int *)((uVar18 - 8) + uVar2 * 8) = local_1c;
                  *(int *)((uVar18 - 4) + uVar2 * 8) = iVar4;
                }
              }
              if ((local_20 == param_6) && (bVar1 < 0xe3)) {
                iVar15 = uVar14 + 8;
                uVar21 = 0x50;
                iVar12 = uVar14 - 8;
                iVar16 = uVar5 + 8;
                iVar8 = uVar5 - 8;
                FUN_005a3dd0(iVar12,iVar8,iVar15,iVar16,0x50);
                FUN_005a3fd0(iVar12,iVar8,iVar15,iVar16,uVar21);
              }
              if (param_6 < 8) {
                puVar7 = puVar7 + param_6;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              *puVar7 = 0xff;
            }
            uVar14 = uVar14 + 8;
            uVar18 = local_18;
          } while ((int)uVar14 < local_28);
        }
        param_2 = 0;
        uVar14 = uVar18;
        if (local_24 < (int)uVar18) {
          iVar4 = (int)(uVar5 + ((int)uVar5 >> 0x1f & 7U)) >> 3;
          do {
            pCVar3 = PTR_0077241c;
            local_1c = (int)(((int)uVar18 >> 0x1f & 7U) + uVar18) >> 3;
            iVar12 = PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= local_1c) {
              iVar12 = local_1c;
            }
            iVar16 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= iVar4) {
              iVar16 = iVar4;
            }
            iVar8 = PTR_0077241c->cellY1 + -1;
            if (iVar16 < PTR_0077241c->cellY1) {
              iVar8 = iVar16;
            }
            iVar16 = PTR_0077241c->cellX1 + -1;
            if (iVar12 < PTR_0077241c->cellX1) {
              iVar16 = iVar12;
            }
            iVar12 = (iVar8 * PTR_0077241c->mapWidth + iVar16) % PTR_0077241c->cellCountTotal;
            if ((iVar12 < 0) || (PTR_0077241c->cellCount <= iVar12)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar17 = pCVar3->cells;
            }
            else {
              pCVar17 = PTR_0077241c->cells + iVar12;
            }
            iVar12 = pCVar17->heightBlockIndex;
            ppCVar6 = &PTR_0077241c->heightBlocks->data;
            local_2c = pCVar17;
            if ((iVar12 < 0) || (PTR_0077241c->heightBlocks->count <= iVar12)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar9 = *ppCVar6;
            }
            else {
              pCVar9 = *ppCVar6 + iVar12;
            }
            if (param_2 == 0) {
              if (0xe < (pCVar9->heights[0] & 0xf)) {
                param_2 = 1;
              }
            }
            else {
              uVar14 = local_18;
              if (param_2 == 3) break;
              param_2 = param_2 + 1;
            }
            puVar7 = pCVar17->ownerIndex;
            if (param_6 < 8) {
              puVar10 = puVar7 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar10 = puVar7;
            }
            bVar1 = *puVar10;
            if (bVar1 != 0xff) {
              if (bVar1 < 2) {
                if (bVar1 == 0) {
                  FUN_0057dfc0(&local_2c,local_1c,iVar4,param_6);
                }
                if (param_6 < 8) {
                  puVar11 = local_14 + param_6;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar11 = local_14;
                }
                if ((int)(puVar11[3] * 8) <= (int)uVar5) {
                  if (param_6 < 8) {
                    puVar11 = local_14 + param_6 * 2;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    puVar11 = local_14;
                  }
                  FUN_005813a0(1);
                  uVar14 = puVar11[0xb];
                  uVar2 = puVar11[0xc];
                  *(int *)((uVar14 - 8) + uVar2 * 8) = local_1c;
                  *(int *)((uVar14 - 4) + uVar2 * 8) = iVar4;
                }
              }
              if ((local_20 == param_6) && (bVar1 < 0xe3)) {
                iVar15 = uVar18 + 8;
                uVar21 = 0x50;
                iVar12 = uVar18 - 8;
                iVar16 = uVar5 + 8;
                iVar8 = uVar5 - 8;
                FUN_005a3dd0(iVar12,iVar8,iVar15,iVar16,0x50);
                FUN_005a3fd0(iVar12,iVar8,iVar15,iVar16,uVar21);
              }
              if (param_6 < 8) {
                puVar7 = puVar7 + param_6;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              *puVar7 = 0xff;
            }
            uVar18 = uVar18 - 8;
            uVar14 = local_18;
          } while (local_24 < (int)uVar18);
        }
        uVar5 = uVar5 + 8;
      } while ((int)uVar5 < (int)uVar19);
    }
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

