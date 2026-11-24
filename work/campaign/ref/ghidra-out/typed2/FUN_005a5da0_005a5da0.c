
void FUN_005a5da0(int *param_1)

{
  byte bVar1;
  CMap *pCVar2;
  CMapCell *pCVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  int local_30;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar9 = (int)((param_1[1] >> 0x1f & 7U) + param_1[1]) >> 3;
  if (iVar9 < (int)(param_1[3] + (param_1[3] >> 0x1f & 7U)) >> 3) {
    do {
      iVar17 = (int)((*param_1 >> 0x1f & 7U) + *param_1) >> 3;
      if (iVar17 < (int)(param_1[2] + (param_1[2] >> 0x1f & 7U)) >> 3) {
        do {
          pCVar2 = PTR_0077241c;
          iVar12 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar17) {
            iVar12 = iVar17;
          }
          iVar4 = PTR_0077241c->cellX1 + -1;
          if (iVar12 < PTR_0077241c->cellX1) {
            iVar4 = iVar12;
          }
          iVar12 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar9) {
            iVar12 = iVar9;
          }
          if (PTR_0077241c->cellY1 <= iVar12) {
            iVar12 = PTR_0077241c->cellY1 + -1;
          }
          iVar12 = (PTR_0077241c->mapWidth * iVar12 + iVar4) % PTR_0077241c->cellCountTotal;
          if ((iVar12 < 0) || (PTR_0077241c->cellCount <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar3 = pCVar2->cells;
          }
          else {
            pCVar3 = PTR_0077241c->cells + iVar12;
          }
          iVar17 = iVar17 + 1;
          *(undefined2 *)&pCVar3->field_0x16 = 0;
        } while (iVar17 < (int)(param_1[2] + (param_1[2] >> 0x1f & 7U)) >> 3);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)(param_1[3] + (param_1[3] >> 0x1f & 7U)) >> 3);
  }
  iVar9 = DAT_0077244c;
  uVar13 = 0xffffffff;
  while( true ) {
    uVar13 = uVar13 + 1;
    if ((int)*(uint *)(iVar9 + 0x84c6) <= (int)uVar13) break;
    if (*(uint *)(iVar9 + 0x84c6) <= uVar13) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar18 = (int *)(iVar9 + 0x488);
    uVar11 = *(uint *)(*(int *)(iVar9 + 0x84c2) + uVar13 * 4);
    if (uVar11 < 0x2000) {
      piVar18 = piVar18 + uVar11;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar17 = *piVar18;
    if ((iVar17 != 0) &&
       (((*(int *)(iVar17 + 0x268) != 0 || (*(int *)(iVar17 + 0x264) == 0x7fffffff)) &&
        ((*(uint *)(iVar17 + 0x3d0) & 0x400001) == 0x400001)))) {
      DAT_00772dd8 = (int)ROUND(*(float *)(iVar17 + 0xc) * 8.0);
      iVar4 = DAT_00772dd8 + *(int *)(iVar17 + 0x254);
      iVar5 = *(int *)(iVar17 + 0x260) + (int)ROUND(*(float *)(iVar17 + 0x10) * 8.0);
      iVar6 = *(int *)(iVar17 + 0x25c) + (int)ROUND(*(float *)(iVar17 + 0xc) * 8.0);
      iVar10 = *(int *)(iVar17 + 600) + (int)ROUND(*(float *)(iVar17 + 0x10) * 8.0);
      iVar12 = param_1[2];
      if ((((iVar4 <= iVar12) && (iVar15 = *param_1, iVar15 <= iVar6)) &&
          (iVar7 = param_1[3], iVar10 <= iVar7)) && (iVar16 = param_1[1], iVar16 <= iVar5)) {
        if (iVar5 <= iVar7) {
          iVar7 = iVar5;
        }
        if (iVar6 <= iVar12) {
          iVar12 = iVar6;
        }
        if (iVar16 <= iVar10) {
          iVar16 = iVar10;
        }
        if (iVar15 <= iVar4) {
          iVar15 = iVar4;
        }
        local_18 = iVar15;
        local_14 = iVar16;
        local_10 = iVar12;
        local_c = iVar7;
        if ((iVar15 < iVar12) && (iVar16 < iVar7)) {
          thunk_FUN_0060fc30(0);
          puVar8 = (uint *)FUN_006ba810(0x5e);
          FUN_005961c0(puVar8,&local_18);
          bVar1 = *(byte *)(iVar17 + 0x268);
          iVar4 = param_1[3];
          iVar5 = *(int *)(iVar17 + 0x264);
          uVar11 = 0;
          if (iVar5 != 0x7fffffff) {
            uVar11 = 0xf3f3f3f3;
          }
          local_30 = param_1[2];
          iVar6 = (local_30 - *param_1) * (iVar4 - param_1[1]);
          puVar14 = puVar8;
          if (iVar6 != 3 && -1 < iVar6 + -3) {
            iVar6 = 0;
            do {
              iVar6 = iVar6 + 4;
              *puVar14 = uVar11 & *puVar14 | CONCAT31(CONCAT21(CONCAT11(bVar1,bVar1),bVar1),bVar1);
              puVar14 = puVar14 + 1;
              local_30 = param_1[2];
              iVar4 = param_1[3];
            } while (iVar6 < (local_30 - *param_1) * (iVar4 - param_1[1]) + -3);
          }
          uVar11 = (iVar4 - param_1[1]) * (local_30 - *param_1) & 0x80000003;
          if ((int)uVar11 < 0) {
            uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
          }
          if (0 < (int)uVar11) {
            iVar4 = 0;
            do {
              iVar4 = iVar4 + 1;
              *(byte *)puVar14 = (iVar5 == 0x7fffffff) - 1U & 0xf3 & (byte)*puVar14 | bVar1;
              uVar11 = (param_1[2] - *param_1) * (param_1[3] - param_1[1]) & 0x80000003;
              if ((int)uVar11 < 0) {
                uVar11 = (uVar11 - 1 | 0xfffffffc) + 1;
              }
              puVar14 = (uint *)((int)puVar14 + 1);
            } while (iVar4 < (int)uVar11);
          }
          FUN_00596550(puVar8,&local_18);
          if (*(int *)(iVar17 + 0x268) != 0) {
            iVar4 = (int)((iVar7 + 7 >> 0x1f & 7U) + iVar7 + 7) >> 3;
            iVar5 = (int)((iVar16 >> 0x1f & 7U) + iVar16) >> 3;
            if (iVar5 < iVar4) {
              iVar10 = (int)((iVar15 >> 0x1f & 7U) + iVar15) >> 3;
              iVar6 = iVar10;
              pCVar2 = PTR_0077241c;
              do {
                for (; PTR_0077241c = pCVar2,
                    iVar6 < (int)(iVar12 + 7 + (iVar12 + 7 >> 0x1f & 7U)) >> 3; iVar6 = iVar6 + 1) {
                  iVar15 = pCVar2->cellX0;
                  if (pCVar2->cellX0 <= iVar6) {
                    iVar15 = iVar6;
                  }
                  iVar7 = pCVar2->cellX1 + -1;
                  if (iVar15 < pCVar2->cellX1) {
                    iVar7 = iVar15;
                  }
                  iVar15 = pCVar2->cellY0;
                  if (pCVar2->cellY0 <= iVar5) {
                    iVar15 = iVar5;
                  }
                  if (pCVar2->cellY1 <= iVar15) {
                    iVar15 = pCVar2->cellY1 + -1;
                  }
                  iVar15 = (pCVar2->mapWidth * iVar15 + iVar7) % pCVar2->cellCountTotal;
                  if ((iVar15 < 0) || (pCVar2->cellCount <= iVar15)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pCVar3 = pCVar2->cells;
                  }
                  else {
                    pCVar3 = pCVar2->cells + iVar15;
                  }
                  *(undefined2 *)&pCVar3->field_0x16 = *(undefined2 *)(iVar17 + 0xdc);
                  pCVar2 = PTR_0077241c;
                }
                iVar5 = iVar5 + 1;
                iVar6 = iVar10;
              } while (iVar5 < iVar4);
            }
          }
          thunk_FUN_0060fc30(puVar8);
        }
      }
    }
  }
  return;
}

