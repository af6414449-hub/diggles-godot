
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057f5c0(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  LPVOID lpTlsValue;
  int iVar6;
  int iVar7;
  CMapCell *pCVar8;
  int iVar9;
  undefined4 *in_ECX;
  CMap *pCVar10;
  int iVar11;
  undefined4 *puVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  uchar *puVar16;
  undefined8 uVar17;
  uint local_24;
  uint local_20;
  CMap *local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  iVar15 = DAT_00772400;
  local_8 = 0xffffffff;
  puStack_c = &LAB_007061dd;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[1] = in_ECX[1] + 1;
  *in_ECX = *(undefined4 *)(iVar15 + 100);
                    /* WARNING: Load size is inaccurate */
  iVar15 = *ThreadLocalStoragePointer;
  if ((*(int *)(iVar15 + 4) < DAT_00ca54a0) &&
     (FUN_006cebf4(&DAT_00ca54a0,uVar3), iVar4 = DAT_00783650, DAT_00ca54a0 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca54a4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "void CFogOfWar::UpdateFoW()";
    *(int *)(&DAT_00773650 + iVar9) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54a0);
  }
  iVar9 = DAT_00ca54a4;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca54a4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar4 == 0) {
    uVar17 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar17;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar4 + 1;
  pCVar10 = PTR_0077241c;
  iVar4 = DAT_00772400;
  local_8 = 0;
  if ((*(char *)(DAT_00772400 + 0x590) == '\0') && (*(char *)(DAT_00772400 + 0x8e) != '\0')) {
    if ((*(int *)(iVar15 + 4) < DAT_00ca54a8) &&
       (FUN_006cebf4(&DAT_00ca54a8,uVar3), iVar4 = DAT_00783650, DAT_00ca54a8 == -1)) {
      iVar9 = DAT_00783650 * 0x40;
      _DAT_00ca54ac = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar9) = "void CFogOfWar::UpdateFoW() FadeBlocks";
      *(int *)(&DAT_00773650 + iVar9) = iVar4;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca54a8);
    }
    FUN_00405af0(&DAT_00ca54ac);
    iVar4 = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    do {
      FUN_0057e710(iVar4);
      iVar9 = DAT_0077244c;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
    DAT_00c3c9b4 = (DAT_00c3c9b4 + 1) % 6;
    uVar3 = 0xffffffff;
    while( true ) {
      uVar3 = uVar3 + 1;
      if ((int)*(uint *)(iVar9 + 0x84c6) <= (int)uVar3) break;
      if (*(uint *)(iVar9 + 0x84c6) <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar2 = *(uint *)(*(int *)(iVar9 + 0x84c2) + uVar3 * 4);
      if ((*(int *)(iVar15 + 4) < DAT_00ca54b0) &&
         (FUN_006cebf4(&DAT_00ca54b0), iVar4 = DAT_00783650, DAT_00ca54b0 == -1)) {
        iVar5 = DAT_00783650 * 0x40;
        DAT_00ca54b4 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar5) = "void CFogOfWar::UpdateFoW() ShowBlocks";
        *(int *)(&DAT_00773650 + iVar5) = iVar4;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca54b0);
      }
      iVar4 = DAT_00ca54b4;
      iVar5 = DAT_00ca54b4 * 0x40;
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      lpTlsValue = TlsGetValue(DAT_00767960);
      if (lpTlsValue == (LPVOID)0x0) {
        lpTlsValue = (LPVOID)FUN_006ba810(0x18);
        if (lpTlsValue == (LPVOID)0x0) {
          lpTlsValue = (LPVOID)0x0;
        }
        else {
          *(undefined4 *)((int)lpTlsValue + 0x8000) = 0;
        }
        TlsSetValue(DAT_00767960,lpTlsValue);
      }
      *(undefined4 *)((int)lpTlsValue + *(int *)((int)lpTlsValue + 0x8000) * 4) =
           *(undefined4 *)(&DAT_00773650 + iVar5);
      *(int *)((int)lpTlsValue + 0x8000) = *(int *)((int)lpTlsValue + 0x8000) + 1;
      iVar5 = (&DAT_00773654)[iVar4 * 0x10];
      if (iVar5 == 0) {
        uVar17 = FUN_006bd180();
        iVar5 = (&DAT_00773654)[iVar4 * 0x10];
        *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar17;
      }
      (&DAT_00773654)[iVar4 * 0x10] = iVar5 + 1;
      local_8 = CONCAT31(local_8._1_3_,2);
      piVar13 = (int *)(iVar9 + 0x488);
      if (uVar2 < 0x2000) {
        piVar13 = piVar13 + uVar2;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = *piVar13;
      if ((iVar4 != 0) && (*(uint *)(iVar4 + 0x36c) < 8)) {
        iVar6 = (int)(*(float *)(iVar4 + 0xc) * 8.0);
        iVar5 = -(int)(*(float *)(iVar4 + 0x10) * -8.0);
        iVar14 = iVar5 + -0xc;
        iVar11 = (int)(*(float *)(iVar4 + 0x26c) * 8.0);
        iVar7 = -0xc - (int)(*(float *)(iVar4 + 0x270) * -8.0);
        if (((*(int *)(iVar4 + 0x364) != -1) &&
            ((((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3 !=
               (int)((iVar11 >> 0x1f & 7U) + iVar11) >> 3 ||
              ((int)(iVar14 + (iVar14 >> 0x1f & 7U)) >> 3 !=
               (int)((iVar7 >> 0x1f & 7U) + iVar7) >> 3)) ||
             (DAT_00c3c9b4 == *(int *)(iVar4 + 0xdc) % 6)))) &&
           ((*(int *)(*(int *)(iVar4 + 0xd4) + 0x54) != 5 ||
            ((*(uint *)(iVar4 + 0x3d0) & 0x400000) != 0)))) {
          piVar13 = *(int **)(iVar4 + 0x3ec);
          if ((piVar13 == (int *)0x0) || (iVar7 = *piVar13, iVar7 == 2)) {
            if (*(int *)(iVar4 + 0x368) < 1) {
              iVar7 = *(int *)(iVar4 + 0x364);
              iVar11 = -*(int *)(iVar4 + 0x368);
              if (iVar7 < 1) {
                CFogOfWar__RemoveFogBoxNoCollision
                          (iVar6,iVar14,-iVar7,iVar11,*(undefined4 *)(iVar4 + 0x36c));
              }
              else {
                FUN_0057e120(iVar6,iVar5 + 4,iVar7,iVar11,*(undefined4 *)(iVar4 + 0x36c),0,
                             0x3f800000);
              }
            }
            else {
              DAT_00772dd8 = (int)ROUND((float)iVar14 - 0.5);
              FUN_0057e120(iVar6,DAT_00772dd8,*(undefined4 *)(iVar4 + 0x364),
                           *(undefined4 *)(iVar4 + 0x368),*(undefined4 *)(iVar4 + 0x36c),0,
                           0x3f800000);
            }
          }
          else {
            if (iVar7 == 0) {
              DAT_00772dd8 = (int)ROUND(*(float *)(piVar13[1] + 0x230) * 8.0 + 16.0);
              CFogOfWar__RemoveFogLine
                        (iVar6,iVar14,DAT_00772dd8 + iVar14,*(undefined4 *)(iVar4 + 0x364),
                         *(undefined4 *)(iVar4 + 0x368),*(undefined4 *)(iVar4 + 0x36c));
              piVar13 = *(int **)(iVar4 + 0x3ec);
              iVar7 = *piVar13;
            }
            if (iVar7 == 1) {
              DAT_00772dd8 = (int)ROUND(*(float *)(piVar13[2] + 0x2c) * 8.0);
              CFogOfWar__RemoveFogLine
                        (iVar6,(iVar14 - DAT_00772dd8) + -0x10,iVar5 + 4,
                         *(undefined4 *)(iVar4 + 0x364),*(undefined4 *)(iVar4 + 0x368),
                         *(undefined4 *)(iVar4 + 0x36c));
            }
          }
        }
        *(undefined4 *)(iVar4 + 0x26c) = *(undefined4 *)(iVar4 + 0xc);
        *(undefined4 *)(iVar4 + 0x270) = *(undefined4 *)(iVar4 + 0x10);
        *(undefined4 *)(iVar4 + 0x274) = *(undefined4 *)(iVar4 + 0x14);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_0043fd30();
    }
    local_8 = local_8 & 0xffffff00;
    FUN_0043fd30();
  }
  else {
    if (*(char *)(in_ECX + 2) == '\0') goto LAB_0057fcb5;
    if ((PTR_0077241c != (CMap *)0x0) && ((char)PTR_0077241c->mapFlags != '\0')) {
      *(undefined1 *)(in_ECX + 2) = 0;
      local_20 = 0;
      iVar15 = 0;
      do {
        piVar13 = (int *)(iVar4 + 0xa328);
        if (local_20 < 8) {
          piVar13 = (int *)((int)piVar13 + iVar15);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar10 = PTR_0077241c;
        }
        iVar4 = pCVar10->cellY0;
        iVar9 = pCVar10->cellX1;
        iVar5 = pCVar10->cellY1;
        local_20 = local_20 + 1;
        iVar15 = iVar15 + 0x10;
        *piVar13 = pCVar10->cellX0;
        piVar13[1] = iVar4;
        piVar13[2] = iVar9;
        piVar13[3] = iVar5;
        iVar4 = DAT_00772400;
      } while (iVar15 < 0x80);
      iVar15 = pCVar10->cellY0;
      local_18 = pCVar10;
      if (iVar15 < pCVar10->cellY1) {
        do {
          iVar4 = pCVar10->cellX0;
          if (iVar4 < pCVar10->cellX1) {
            do {
              local_24 = 0;
              do {
                iVar9 = pCVar10->cellX0;
                if (pCVar10->cellX0 <= iVar4) {
                  iVar9 = iVar4;
                }
                iVar5 = pCVar10->cellY0;
                if (pCVar10->cellY0 <= iVar15) {
                  iVar5 = iVar15;
                }
                iVar6 = pCVar10->cellY1 + -1;
                if (iVar5 < pCVar10->cellY1) {
                  iVar6 = iVar5;
                }
                iVar5 = pCVar10->cellX1 + -1;
                if (iVar9 < pCVar10->cellX1) {
                  iVar5 = iVar9;
                }
                iVar9 = (iVar6 * local_18->mapWidth + iVar5) % local_18->cellCountTotal;
                if ((iVar9 < 0) || (local_18->cellCount <= iVar9)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar8 = local_18->cells;
                  local_18 = PTR_0077241c;
                }
                else {
                  pCVar8 = local_18->cells + iVar9;
                }
                puVar16 = pCVar8->ownerIndex;
                if (local_24 < 8) {
                  puVar16 = puVar16 + local_24;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  local_18 = PTR_0077241c;
                }
                local_24 = local_24 + 1;
                *puVar16 = 0xff;
                pCVar10 = local_18;
              } while ((int)local_24 < 8);
              iVar4 = iVar4 + 1;
            } while (iVar4 < local_18->cellX1);
          }
          iVar15 = iVar15 + 1;
        } while (iVar15 < pCVar10->cellY1);
      }
    }
    if (DAT_0076a338 != 0) {
      FUN_00464cc0();
    }
  }
  uVar3 = in_ECX[1] & 0x80000007;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
  }
  puVar12 = in_ECX + 0xb;
  if (uVar3 < 8) {
    puVar12 = puVar12 + uVar3 * 2;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  FUN_00581150(0,puVar12[1] + -1);
  FUN_0057fde0();
LAB_0057fcb5:
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

