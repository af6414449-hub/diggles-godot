
float * CPlaceFinder__FindPlaceLongRange
                  (float *param_1,int param_2,int param_3,char param_4,char param_5)

{
  undefined4 uVar1;
  CHeightBlockArray *pCVar2;
  int iVar3;
  CMap *pCVar4;
  int iVar5;
  int iVar6;
  CMapCell *pCVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  CHeightBlock *pCVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  float fVar17;
  float in_XMM3_Da;
  undefined8 uVar18;
  uint local_2c;
  uint local_28;
  int local_20;
  int local_1c;
  
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca5558) &&
     (FUN_006cebf4(&DAT_00ca5558), iVar5 = DAT_00783650, DAT_00ca5558 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca555c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "CPlaceFinder::FindPlaceLongRange()";
    *(int *)(&DAT_00773650 + iVar9) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5558);
  }
  iVar9 = DAT_00ca555c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca555c * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar1;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar5 == 0) {
    uVar18 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar18;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar5 + 1;
  fVar17 = (float)param_2 - in_XMM3_Da;
  DAT_00772dd8 = (int)ROUND(fVar17);
  iVar5 = PTR_0077241c->cellX0;
  if (PTR_0077241c->cellX0 <= DAT_00772dd8) {
    iVar5 = DAT_00772dd8;
  }
  iVar9 = PTR_0077241c->cellX1;
  if ((int)ROUND((float)param_2 + in_XMM3_Da) <= PTR_0077241c->cellX1) {
    iVar9 = (int)ROUND((float)param_2 + in_XMM3_Da);
  }
  iVar11 = PTR_0077241c->cellY0;
  if (PTR_0077241c->cellY0 <= (int)ROUND((float)param_3 - in_XMM3_Da)) {
    iVar11 = (int)ROUND((float)param_3 - in_XMM3_Da);
  }
  iVar14 = PTR_0077241c->cellY1;
  if ((int)ROUND((float)param_3 + in_XMM3_Da) <= PTR_0077241c->cellY1) {
    iVar14 = (int)ROUND((float)param_3 + in_XMM3_Da);
  }
  uVar15 = 0xffffffff;
  local_20 = -1;
  local_2c = 0xffffffff;
  local_28 = 0xffffffff;
  do {
    iVar3 = iVar5;
    pCVar4 = PTR_0077241c;
    if (iVar14 <= iVar11) {
      *param_1 = -1.0;
      param_1[1] = -1.0;
      param_1[2] = -1.0;
      if (uVar15 != 0xffffffff) {
        uVar16 = uVar15;
        if ((param_4 != '\0') &&
           (iVar5 = FUN_00592f10(PTR_0077241c),
           (*(byte *)(((local_28 & 7) << 3 | uVar15 & 7) + 0x3c + iVar5) & 2) == 0)) {
          local_1c = 8;
          iVar5 = (int)(((int)local_28 >> 0x1f & 7U) + local_28) >> 3;
          do {
            iVar5 = iVar5 + 1;
            iVar9 = FUN_00592f10(PTR_0077241c);
            if ((*(byte *)(iVar9 + 0x12) & 0x40) != 0) {
              iVar9 = FUN_00592f10(PTR_0077241c);
              local_2c = (*(byte *)(iVar9 + 0x12) & 7) +
                         ((int)(((int)uVar15 >> 0x1f & 7U) + uVar15) >> 3) * 8;
              iVar9 = FUN_00592f10(PTR_0077241c);
              local_28 = (*(byte *)(iVar9 + 0x12) >> 3 & 7) + iVar5 * 8;
            }
            local_1c = local_1c + -1;
            uVar16 = local_2c;
          } while (local_1c != 0);
        }
        pCVar4 = PTR_0077241c;
        param_1[2] = 0.0;
        *param_1 = (float)(int)uVar16 * 0.125;
        param_1[1] = (float)(int)local_28 * 0.125;
        iVar5 = pCVar4->cellX0;
        if (pCVar4->cellX0 <= (int)uVar16 >> 3) {
          iVar5 = (int)uVar16 >> 3;
        }
        iVar9 = pCVar4->cellY0;
        if (pCVar4->cellY0 <= (int)local_28 >> 3) {
          iVar9 = (int)local_28 >> 3;
        }
        iVar11 = pCVar4->cellY1 + -1;
        if (iVar9 < pCVar4->cellY1) {
          iVar11 = iVar9;
        }
        iVar9 = pCVar4->cellX1 + -1;
        if (iVar5 < pCVar4->cellX1) {
          iVar9 = iVar5;
        }
        iVar5 = (iVar11 * pCVar4->mapWidth + iVar9) % pCVar4->cellCountTotal;
        if ((iVar5 < 0) || (pCVar4->cellCount <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar7 = pCVar4->cells;
        }
        else {
          pCVar7 = pCVar4->cells + iVar5;
        }
        pCVar4 = PTR_0077241c;
        if ((pCVar7->sampleFlags[(local_28 & 7) << 3 | local_2c & 7] & 2) == 0) {
          FUN_004238e0();
          param_1[2] = fVar17;
        }
        else {
          piVar10 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar2 = pCVar4->heightBlocks;
          iVar5 = *piVar10;
          if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar12 = pCVar2->data;
          }
          else {
            pCVar12 = pCVar2->data + iVar5;
          }
          iVar9 = pCVar12->heights[(local_28 - 2 & 7) << 3 | local_2c & 7] + 1;
          iVar5 = _rand();
          param_1[2] = (float)(iVar5 * (0xf - iVar9)) * 3.0517578e-05 + (float)iVar9;
        }
      }
      FUN_0043fd30();
      return param_1;
    }
    for (; PTR_0077241c = pCVar4, iVar3 < iVar9; iVar3 = iVar3 + 1) {
      iVar13 = pCVar4->cellX0;
      if (pCVar4->cellX0 <= iVar3) {
        iVar13 = iVar3;
      }
      iVar8 = pCVar4->cellY0;
      if (pCVar4->cellY0 <= iVar11) {
        iVar8 = iVar11;
      }
      iVar6 = pCVar4->cellY1 + -1;
      if (iVar8 < pCVar4->cellY1) {
        iVar6 = iVar8;
      }
      iVar8 = pCVar4->cellX1 + -1;
      if (iVar13 < pCVar4->cellX1) {
        iVar8 = iVar13;
      }
      iVar13 = (iVar6 * pCVar4->mapWidth + iVar8) % pCVar4->cellCountTotal;
      if ((iVar13 < 0) || (pCVar4->cellCount <= iVar13)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar7 = pCVar4->cells;
      }
      else {
        pCVar7 = pCVar4->cells + iVar13;
      }
      pCVar4 = PTR_0077241c;
      if (pCVar7->field_0x6 != -1) {
        if (param_5 != '\0') {
          iVar13 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar3) {
            iVar13 = iVar3;
          }
          iVar8 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar11) {
            iVar8 = iVar11;
          }
          iVar6 = PTR_0077241c->cellY1 + -1;
          if (iVar8 < PTR_0077241c->cellY1) {
            iVar6 = iVar8;
          }
          iVar8 = PTR_0077241c->cellX1 + -1;
          if (iVar13 < PTR_0077241c->cellX1) {
            iVar8 = iVar13;
          }
          iVar13 = (iVar6 * PTR_0077241c->mapWidth + iVar8) % PTR_0077241c->cellCountTotal;
          if ((iVar13 < 0) || (PTR_0077241c->cellCount <= iVar13)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar7 = pCVar4->cells;
          }
          else {
            pCVar7 = PTR_0077241c->cells + iVar13;
          }
          if ((pCVar7->field_0x12 & 0x40) == 0) goto LAB_005aa602;
        }
        iVar13 = _rand();
        if (local_20 < iVar13) {
          iVar8 = FUN_00592f10(PTR_0077241c);
          local_28 = (*(byte *)(iVar8 + 0x12) >> 3 & 7) + iVar11 * 8;
          iVar8 = FUN_00592f10(PTR_0077241c);
          local_2c = (*(byte *)(iVar8 + 0x12) & 7) + iVar3 * 8;
          local_20 = iVar13;
        }
      }
LAB_005aa602:
      uVar15 = local_2c;
      pCVar4 = PTR_0077241c;
    }
    iVar11 = iVar11 + 1;
  } while( true );
}

