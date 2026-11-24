
void FUN_005791a0(void)

{
  uchar *puVar1;
  float fVar2;
  float fVar3;
  CMap *pCVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  CMapCell *pCVar13;
  undefined4 uVar14;
  uint uVar15;
  int *piVar16;
  int *in_ECX;
  int iVar17;
  uint uVar18;
  int iVar19;
  code *pcVar20;
  int *piVar21;
  bool bVar22;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_1c;
  
  pcVar20 = RaiseException_exref;
  piVar21 = in_ECX + 0x321;
  if ((uint)in_ECX[0x31c] < 2) {
    piVar16 = piVar21 + in_ECX[0x31c] * 2;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar16 = piVar21;
  }
  iVar19 = piVar16[1];
  if (iVar19 < 0) {
    iVar12 = iVar19;
    if ((iVar19 + 0x3fU & 0xffffffc0) != 0) {
      iVar5 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      iVar12 = piVar16[1];
      *piVar16 = iVar5;
    }
    piVar16[1] = iVar12 - iVar19;
  }
  else if (0 < iVar19) {
    piVar16[1] = 0;
  }
  uVar18 = 0;
  do {
    while( true ) {
      if ((uint)in_ECX[0x31b] < 2) {
        piVar16 = piVar21 + in_ECX[0x31b] * 2;
      }
      else {
        (*pcVar20)(0xc000008c,1,0,0);
        piVar16 = piVar21;
      }
      if (piVar16[1] <= (int)uVar18) {
        uVar18 = in_ECX[1];
        local_1c = 0;
        if (0 < (int)uVar18) {
          local_24 = 0;
          bVar22 = uVar18 != 0;
          do {
            if (!bVar22) {
              (*pcVar20)(0xc000008c,1,0,0);
              uVar18 = in_ECX[1];
            }
            local_2c = *in_ECX;
            piVar16 = in_ECX + 0x321;
            if (*(char *)(*in_ECX + 0x25 + local_24) != '\0') {
              if (uVar18 <= local_1c) {
                (*pcVar20)(0xc000008c,1,0,0);
                local_2c = *in_ECX;
              }
              piVar11 = (int *)(DAT_0077244c + 0x488);
              if (*(uint *)(local_2c + local_24) < 0x2000) {
                piVar11 = piVar11 + *(uint *)(local_2c + local_24);
              }
              else {
                (*pcVar20)(0xc000008c,1,0,0);
              }
              iVar19 = *piVar11;
              if (iVar19 != 0) {
                fVar2 = *(float *)(iVar19 + 0xc);
                fVar3 = *(float *)(iVar19 + 0x10);
                uVar18 = in_ECX[1];
                if (uVar18 <= local_1c) {
                  (*pcVar20)(0xc000008c,1,0,0);
                  uVar18 = in_ECX[1];
                }
                iVar19 = *in_ECX;
                iVar12 = (int)(*(float *)(iVar19 + 4 + local_24) + fVar2);
                if (uVar18 <= local_1c) {
                  (*pcVar20)(0xc000008c,1,0,0);
                  iVar19 = *in_ECX;
                }
                iVar19 = (int)(*(float *)(iVar19 + 8 + local_24) + fVar3);
                if ((((PTR_0077241c->cellX0 + 4 <= iVar12) && (iVar12 < PTR_0077241c->cellX1 + -4))
                    && (PTR_0077241c->cellY0 + 4 <= iVar19)) && (iVar19 < PTR_0077241c->cellY1 + -4)
                   ) {
                  iVar5 = FUN_00592f10(PTR_0077241c);
                  if ((*(byte *)(iVar5 + 0x13) & 4) == 0) {
                    if ((uint)in_ECX[0x31c] < 2) {
                      piVar11 = piVar16 + in_ECX[0x31c] * 2;
                    }
                    else {
                      (*pcVar20)(0xc000008c,1,0,0);
                      piVar11 = piVar16;
                    }
                    if ((piVar11[1] + 0x40U & 0xffffffc0) != (piVar11[1] + 0x3fU & 0xffffffc0)) {
                      iVar5 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                           ,0x9b);
                      *piVar11 = iVar5;
                    }
                    iVar5 = *piVar11;
                    iVar6 = piVar11[1] + 1;
                    piVar11[1] = iVar6;
                    *(int *)(iVar5 + -8 + iVar6 * 8) = iVar12;
                    *(int *)(iVar5 + -4 + iVar6 * 8) = iVar19;
                    iVar5 = FUN_00592f10(PTR_0077241c);
                    *(byte *)(iVar5 + 0x13) = *(byte *)(iVar5 + 0x13) | 4;
                  }
                  iVar5 = FUN_00592f10(PTR_0077241c);
                  if ((*(byte *)(iVar5 + 0x13) & 4) == 0) {
                    if ((uint)in_ECX[0x31c] < 2) {
                      piVar11 = piVar16 + in_ECX[0x31c] * 2;
                    }
                    else {
                      (*pcVar20)(0xc000008c,1,0,0);
                      piVar11 = piVar16;
                    }
                    if ((piVar11[1] + 0x40U & 0xffffffc0) != (piVar11[1] + 0x3fU & 0xffffffc0)) {
                      iVar5 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                           ,0x9b);
                      *piVar11 = iVar5;
                    }
                    iVar5 = *piVar11;
                    iVar6 = piVar11[1] + 1;
                    piVar11[1] = iVar6;
                    *(int *)(iVar5 + -8 + iVar6 * 8) = iVar12 + 1;
                    *(int *)(iVar5 + -4 + iVar6 * 8) = iVar19;
                    iVar5 = FUN_00592f10(PTR_0077241c);
                    *(byte *)(iVar5 + 0x13) = *(byte *)(iVar5 + 0x13) | 4;
                  }
                  iVar5 = FUN_00592f10(PTR_0077241c);
                  if ((*(byte *)(iVar5 + 0x13) & 4) == 0) {
                    if ((uint)in_ECX[0x31c] < 2) {
                      piVar16 = piVar16 + in_ECX[0x31c] * 2;
                    }
                    else {
                      (*pcVar20)(0xc000008c,1,0,0);
                    }
                    if ((piVar16[1] + 0x40U & 0xffffffc0) != (piVar16[1] + 0x3fU & 0xffffffc0)) {
                      iVar5 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                           ,0x9b);
                      *piVar16 = iVar5;
                    }
                    iVar5 = *piVar16;
                    iVar6 = piVar16[1] + 1;
                    piVar16[1] = iVar6;
                    *(int *)(iVar5 + -8 + iVar6 * 8) = iVar12;
                    *(int *)(iVar5 + -4 + iVar6 * 8) = iVar19 + 1;
                    iVar19 = FUN_00592f10(PTR_0077241c);
                    *(byte *)(iVar19 + 0x13) = *(byte *)(iVar19 + 0x13) | 4;
                  }
                }
              }
            }
            local_24 = local_24 + 0x28;
            local_1c = local_1c + 1;
            uVar18 = in_ECX[1];
            bVar22 = local_1c < uVar18;
          } while ((int)local_1c < (int)uVar18);
        }
        local_28 = 0;
        if (0 < *(int *)((int)in_ECX + 0xcb1)) {
          bVar22 = *(int *)((int)in_ECX + 0xcb1) != 0;
          do {
            if (!bVar22) {
              (*pcVar20)(0xc000008c,1,0,0);
            }
            pCVar4 = PTR_0077241c;
            iVar19 = *(int *)(*(int *)((int)in_ECX + 0xcad) + local_28 * 8);
            iVar12 = *(int *)(*(int *)((int)in_ECX + 0xcad) + 4 + local_28 * 8);
            if (((PTR_0077241c->cellX0 + 2 <= iVar19) && (iVar19 < PTR_0077241c->cellX1 + -2)) &&
               ((PTR_0077241c->cellY0 + 2 <= iVar12 && (iVar12 < PTR_0077241c->cellY1 + -2)))) {
              iVar5 = PTR_0077241c->cellX0;
              if (PTR_0077241c->cellX0 <= iVar19) {
                iVar5 = iVar19;
              }
              iVar6 = PTR_0077241c->cellY0;
              if (PTR_0077241c->cellY0 <= iVar12) {
                iVar6 = iVar12;
              }
              iVar7 = PTR_0077241c->cellY1 + -1;
              if (iVar6 < PTR_0077241c->cellY1) {
                iVar7 = iVar6;
              }
              iVar6 = PTR_0077241c->cellX1 + -1;
              if (iVar5 < PTR_0077241c->cellX1) {
                iVar6 = iVar5;
              }
              iVar5 = (iVar7 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
              if ((iVar5 < 0) || (PTR_0077241c->cellCount <= iVar5)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar13 = pCVar4->cells;
              }
              else {
                pCVar13 = PTR_0077241c->cells + iVar5;
              }
              if ((pCVar13->flags & 4) == 0) {
                if ((uint)in_ECX[0x31c] < 2) {
                  piVar16 = piVar21 + in_ECX[0x31c] * 2;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar16 = piVar21;
                }
                iVar5 = piVar16[1];
                if ((iVar5 + 0x40U & 0xffffffc0) != (iVar5 + 0x3fU & 0xffffffc0)) {
                  iVar6 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                       ,0x9b);
                  iVar5 = piVar16[1];
                  *piVar16 = iVar6;
                }
                iVar6 = *piVar16;
                iVar5 = iVar5 + 1;
                piVar16[1] = iVar5;
                *(int *)(iVar6 + -8 + iVar5 * 8) = iVar19;
                *(int *)(iVar6 + -4 + iVar5 * 8) = iVar12;
                pCVar4 = PTR_0077241c;
                iVar5 = PTR_0077241c->cellX0;
                if (PTR_0077241c->cellX0 <= iVar19) {
                  iVar5 = iVar19;
                }
                iVar6 = PTR_0077241c->cellY0;
                if (PTR_0077241c->cellY0 <= iVar12) {
                  iVar6 = iVar12;
                }
                iVar7 = PTR_0077241c->cellY1 + -1;
                if (iVar6 < PTR_0077241c->cellY1) {
                  iVar7 = iVar6;
                }
                iVar6 = PTR_0077241c->cellX1 + -1;
                if (iVar5 < PTR_0077241c->cellX1) {
                  iVar6 = iVar5;
                }
                iVar5 = (iVar7 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
                if ((iVar5 < 0) || (PTR_0077241c->cellCount <= iVar5)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar13 = pCVar4->cells;
                }
                else {
                  pCVar13 = PTR_0077241c->cells + iVar5;
                }
                pCVar13->flags = pCVar13->flags | 4;
              }
              pCVar4 = PTR_0077241c;
              iVar6 = iVar19 + 1;
              iVar5 = PTR_0077241c->cellX0;
              if (PTR_0077241c->cellX0 <= iVar6) {
                iVar5 = iVar6;
              }
              iVar7 = PTR_0077241c->cellY0;
              if (PTR_0077241c->cellY0 <= iVar12) {
                iVar7 = iVar12;
              }
              iVar8 = PTR_0077241c->cellY1 + -1;
              if (iVar7 < PTR_0077241c->cellY1) {
                iVar8 = iVar7;
              }
              iVar7 = PTR_0077241c->cellX1 + -1;
              if (iVar5 < PTR_0077241c->cellX1) {
                iVar7 = iVar5;
              }
              iVar5 = (iVar8 * PTR_0077241c->mapWidth + iVar7) % PTR_0077241c->cellCountTotal;
              if ((iVar5 < 0) || (PTR_0077241c->cellCount <= iVar5)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar13 = pCVar4->cells;
              }
              else {
                pCVar13 = PTR_0077241c->cells + iVar5;
              }
              if ((pCVar13->flags & 4) == 0) {
                if ((uint)in_ECX[0x31c] < 2) {
                  piVar16 = piVar21 + in_ECX[0x31c] * 2;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar16 = piVar21;
                }
                iVar5 = piVar16[1];
                if ((iVar5 + 0x40U & 0xffffffc0) != (iVar5 + 0x3fU & 0xffffffc0)) {
                  iVar7 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                       ,0x9b);
                  iVar5 = piVar16[1];
                  *piVar16 = iVar7;
                }
                iVar7 = *piVar16;
                iVar5 = iVar5 + 1;
                piVar16[1] = iVar5;
                *(int *)(iVar7 + -8 + iVar5 * 8) = iVar6;
                *(int *)(iVar7 + -4 + iVar5 * 8) = iVar12;
                pCVar4 = PTR_0077241c;
                iVar5 = PTR_0077241c->cellX0;
                if (PTR_0077241c->cellX0 <= iVar6) {
                  iVar5 = iVar6;
                }
                iVar6 = PTR_0077241c->cellY0;
                if (PTR_0077241c->cellY0 <= iVar12) {
                  iVar6 = iVar12;
                }
                iVar7 = PTR_0077241c->cellY1 + -1;
                if (iVar6 < PTR_0077241c->cellY1) {
                  iVar7 = iVar6;
                }
                iVar6 = PTR_0077241c->cellX1 + -1;
                if (iVar5 < PTR_0077241c->cellX1) {
                  iVar6 = iVar5;
                }
                iVar5 = (iVar7 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
                if ((iVar5 < 0) || (PTR_0077241c->cellCount <= iVar5)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar13 = pCVar4->cells;
                }
                else {
                  pCVar13 = PTR_0077241c->cells + iVar5;
                }
                pCVar13->flags = pCVar13->flags | 4;
              }
              pCVar4 = PTR_0077241c;
              pcVar20 = RaiseException_exref;
              iVar12 = iVar12 + 1;
              iVar5 = PTR_0077241c->cellX0;
              if (PTR_0077241c->cellX0 <= iVar19) {
                iVar5 = iVar19;
              }
              iVar6 = PTR_0077241c->cellY0;
              if (PTR_0077241c->cellY0 <= iVar12) {
                iVar6 = iVar12;
              }
              iVar7 = PTR_0077241c->cellY1 + -1;
              if (iVar6 < PTR_0077241c->cellY1) {
                iVar7 = iVar6;
              }
              iVar6 = PTR_0077241c->cellX1 + -1;
              if (iVar5 < PTR_0077241c->cellX1) {
                iVar6 = iVar5;
              }
              iVar5 = (iVar7 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
              if ((iVar5 < 0) || (PTR_0077241c->cellCount <= iVar5)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar13 = pCVar4->cells;
              }
              else {
                pCVar13 = PTR_0077241c->cells + iVar5;
              }
              if ((pCVar13->flags & 4) == 0) {
                if ((uint)in_ECX[0x31c] < 2) {
                  piVar16 = piVar21 + in_ECX[0x31c] * 2;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar16 = piVar21;
                }
                iVar5 = piVar16[1];
                if ((iVar5 + 0x40U & 0xffffffc0) != (iVar5 + 0x3fU & 0xffffffc0)) {
                  iVar6 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                       ,0x9b);
                  iVar5 = piVar16[1];
                  *piVar16 = iVar6;
                }
                iVar6 = *piVar16;
                iVar5 = iVar5 + 1;
                piVar16[1] = iVar5;
                *(int *)(iVar6 + -8 + iVar5 * 8) = iVar19;
                *(int *)(iVar6 + -4 + iVar5 * 8) = iVar12;
                pCVar4 = PTR_0077241c;
                pcVar20 = RaiseException_exref;
                iVar5 = PTR_0077241c->cellX0;
                if (PTR_0077241c->cellX0 <= iVar19) {
                  iVar5 = iVar19;
                }
                iVar19 = PTR_0077241c->cellY0;
                if (PTR_0077241c->cellY0 <= iVar12) {
                  iVar19 = iVar12;
                }
                iVar12 = PTR_0077241c->cellY1 + -1;
                if (iVar19 < PTR_0077241c->cellY1) {
                  iVar12 = iVar19;
                }
                iVar19 = PTR_0077241c->cellX1 + -1;
                if (iVar5 < PTR_0077241c->cellX1) {
                  iVar19 = iVar5;
                }
                iVar19 = (iVar12 * PTR_0077241c->mapWidth + iVar19) % PTR_0077241c->cellCountTotal;
                if ((iVar19 < 0) || (PTR_0077241c->cellCount <= iVar19)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar13 = pCVar4->cells;
                }
                else {
                  pCVar13 = PTR_0077241c->cells + iVar19;
                }
                pCVar13->flags = pCVar13->flags | 4;
              }
            }
            local_28 = local_28 + 1;
            bVar22 = local_28 < *(uint *)((int)in_ECX + 0xcb1);
          } while ((int)local_28 < (int)*(uint *)((int)in_ECX + 0xcb1));
        }
        iVar19 = *(int *)((int)in_ECX + 0xcb1);
        if (iVar19 < 0) {
          iVar12 = iVar19;
          if ((iVar19 + 0x1fU & 0xffffffe0) != 0) {
            uVar14 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                  ,0x9b);
            *(undefined4 *)((int)in_ECX + 0xcad) = uVar14;
            iVar12 = *(int *)((int)in_ECX + 0xcb1);
          }
          *(int *)((int)in_ECX + 0xcb1) = iVar12 - iVar19;
        }
        else if (0 < iVar19) {
          *(undefined4 *)((int)in_ECX + 0xcb1) = 0;
        }
        uVar18 = 0;
        while( true ) {
          piVar21 = in_ECX + 0x321;
          uVar15 = in_ECX[0x31c];
          if (uVar15 < 2) {
            piVar16 = piVar21 + uVar15 * 2;
          }
          else {
            (*pcVar20)(0xc000008c,1,0,0);
            uVar15 = in_ECX[0x31c];
            piVar16 = piVar21;
          }
          if (piVar16[1] <= (int)uVar18) break;
          if (uVar15 < 2) {
            piVar16 = piVar21 + uVar15 * 2;
          }
          else {
            (*pcVar20)(0xc000008c,1,0,0);
            piVar16 = piVar21;
          }
          if ((uint)piVar16[1] <= uVar18) {
            (*pcVar20)(0xc000008c,1,0,0);
          }
          iVar19 = *(int *)(*piVar16 + uVar18 * 8);
          if ((uint)in_ECX[0x31c] < 2) {
            piVar21 = piVar21 + in_ECX[0x31c] * 2;
          }
          else {
            (*pcVar20)(0xc000008c,1,0,0);
          }
          if ((uint)piVar21[1] <= uVar18) {
            (*pcVar20)(0xc000008c,1,0,0);
          }
          pCVar4 = PTR_0077241c;
          pcVar20 = RaiseException_exref;
          iVar12 = *(int *)(*piVar21 + 4 + uVar18 * 8);
          iVar5 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar19) {
            iVar5 = iVar19;
          }
          iVar19 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar12) {
            iVar19 = iVar12;
          }
          iVar12 = PTR_0077241c->cellY1 + -1;
          if (iVar19 < PTR_0077241c->cellY1) {
            iVar12 = iVar19;
          }
          iVar19 = PTR_0077241c->cellX1 + -1;
          if (iVar5 < PTR_0077241c->cellX1) {
            iVar19 = iVar5;
          }
          iVar19 = (iVar12 * PTR_0077241c->mapWidth + iVar19) % PTR_0077241c->cellCountTotal;
          if ((iVar19 < 0) || (PTR_0077241c->cellCount <= iVar19)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar1 = &pCVar4->cells->flags;
            *puVar1 = *puVar1 & 0xfb;
            uVar18 = uVar18 + 1;
          }
          else {
            puVar1 = &PTR_0077241c->cells[iVar19].flags;
            *puVar1 = *puVar1 & 0xfb;
            uVar18 = uVar18 + 1;
          }
        }
        if (uVar15 < 2) {
          piVar21 = piVar21 + uVar15 * 2;
        }
        else {
          (*pcVar20)(0xc000008c,1,0,0);
        }
        FUN_0057dc20(0,piVar21[1] + -1);
        return;
      }
      if ((uint)in_ECX[0x31b] < 2) {
        piVar16 = piVar21 + in_ECX[0x31b] * 2;
      }
      else {
        (*pcVar20)(0xc000008c,1,0,0);
        piVar16 = piVar21;
      }
      if ((uint)piVar16[1] <= uVar18) {
        (*pcVar20)(0xc000008c,1,0,0);
      }
      iVar19 = *(int *)(*piVar16 + uVar18 * 8);
      if ((uint)in_ECX[0x31b] < 2) {
        piVar16 = piVar21 + in_ECX[0x31b] * 2;
      }
      else {
        (*pcVar20)(0xc000008c,1,0,0);
        piVar16 = piVar21;
      }
      if ((uint)piVar16[1] <= uVar18) {
        (*pcVar20)(0xc000008c,1,0,0);
      }
      iVar12 = *(int *)(*piVar16 + 4 + uVar18 * 8);
      if ((((PTR_0077241c->cellX0 + 4 <= iVar19) && (iVar19 < PTR_0077241c->cellX1 + -4)) &&
          (PTR_0077241c->cellY0 + 4 <= iVar12)) && (iVar12 < PTR_0077241c->cellY1 + -4)) break;
LAB_0057978e:
      uVar18 = uVar18 + 1;
    }
    iVar5 = FUN_00592f10(PTR_0077241c);
    iVar6 = FUN_00592f10(PTR_0077241c);
    iVar7 = FUN_00592f10(PTR_0077241c);
    iVar8 = FUN_00592f10(PTR_0077241c);
    iVar9 = FUN_00592f10(PTR_0077241c);
    if (((0.004 < ABS(*(float *)(iVar7 + 0x30))) &&
        ((*(float *)(iVar7 + 0x20) != 0.0 || (*(float *)(iVar5 + 0x20) != 0.0)))) ||
       ((0.004 < ABS(*(float *)(iVar7 + 0x28)) &&
        ((*(float *)(iVar7 + 0x20) != 0.0 || (*(float *)(iVar6 + 0x20) != 0.0)))))) {
      if ((*(byte *)(iVar7 + 0x13) & 4) == 0) {
        *(byte *)(iVar7 + 0x13) = *(byte *)(iVar7 + 0x13) | 4;
        if ((uint)in_ECX[0x31c] < 2) {
          piVar16 = piVar21 + in_ECX[0x31c] * 2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar16 = piVar21;
        }
        if ((piVar16[1] + 0x40U & 0xffffffc0) != (piVar16[1] + 0x3fU & 0xffffffc0)) {
          iVar10 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                ,0x9b);
          *piVar16 = iVar10;
        }
        iVar10 = *piVar16;
        iVar17 = piVar16[1] + 1;
        piVar16[1] = iVar17;
        *(int *)(iVar10 + -8 + iVar17 * 8) = iVar19;
        *(int *)(iVar10 + -4 + iVar17 * 8) = iVar12;
      }
      if ((*(byte *)(iVar8 + 0x13) & 4) == 0) {
        *(byte *)(iVar8 + 0x13) = *(byte *)(iVar8 + 0x13) | 4;
        if ((uint)in_ECX[0x31c] < 2) {
          piVar16 = piVar21 + in_ECX[0x31c] * 2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar16 = piVar21;
        }
        if ((piVar16[1] + 0x40U & 0xffffffc0) != (piVar16[1] + 0x3fU & 0xffffffc0)) {
          iVar8 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                               ,0x9b);
          *piVar16 = iVar8;
        }
        iVar8 = *piVar16;
        iVar10 = piVar16[1] + 1;
        piVar16[1] = iVar10;
        *(int *)(iVar8 + -8 + iVar10 * 8) = iVar19 + 1;
        *(int *)(iVar8 + -4 + iVar10 * 8) = iVar12;
      }
      if ((*(byte *)(iVar9 + 0x13) & 4) == 0) {
        *(byte *)(iVar9 + 0x13) = *(byte *)(iVar9 + 0x13) | 4;
        if ((uint)in_ECX[0x31c] < 2) {
          piVar16 = piVar21 + in_ECX[0x31c] * 2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar16 = piVar21;
        }
        if ((piVar16[1] + 0x40U & 0xffffffc0) != (piVar16[1] + 0x3fU & 0xffffffc0)) {
          iVar8 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                               ,0x9b);
          *piVar16 = iVar8;
        }
        iVar8 = *piVar16;
        iVar9 = piVar16[1] + 1;
        piVar16[1] = iVar9;
        *(int *)(iVar8 + -8 + iVar9 * 8) = iVar19;
        *(int *)(iVar8 + -4 + iVar9 * 8) = iVar12 + 1;
      }
    }
    if ((((*(byte *)(iVar6 + 0x13) & 4) == 0) && (0.004 < ABS(*(float *)(iVar7 + 0x28)))) &&
       ((*(float *)(iVar7 + 0x20) != 0.0 || (*(float *)(iVar6 + 0x20) != 0.0)))) {
      *(byte *)(iVar6 + 0x13) = *(byte *)(iVar6 + 0x13) | 4;
      if ((uint)in_ECX[0x31c] < 2) {
        piVar16 = piVar21 + in_ECX[0x31c] * 2;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar16 = piVar21;
      }
      if ((piVar16[1] + 0x40U & 0xffffffc0) != (piVar16[1] + 0x3fU & 0xffffffc0)) {
        iVar6 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                             0x9b);
        *piVar16 = iVar6;
      }
      iVar6 = *piVar16;
      iVar8 = piVar16[1] + 1;
      piVar16[1] = iVar8;
      *(int *)(iVar6 + -8 + iVar8 * 8) = iVar19 + -1;
      *(int *)(iVar6 + -4 + iVar8 * 8) = iVar12;
    }
    pcVar20 = RaiseException_exref;
    if ((((*(byte *)(iVar5 + 0x13) & 4) != 0) || (ABS(*(float *)(iVar7 + 0x30)) <= 0.004)) ||
       ((*(float *)(iVar7 + 0x20) == 0.0 && (*(float *)(iVar5 + 0x20) == 0.0)))) goto LAB_0057978e;
    *(byte *)(iVar5 + 0x13) = *(byte *)(iVar5 + 0x13) | 4;
    if ((uint)in_ECX[0x31c] < 2) {
      piVar16 = piVar21 + in_ECX[0x31c] * 2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar16 = piVar21;
    }
    if ((piVar16[1] + 0x40U & 0xffffffc0) != (piVar16[1] + 0x3fU & 0xffffffc0)) {
      iVar5 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      *piVar16 = iVar5;
    }
    iVar5 = *piVar16;
    iVar6 = piVar16[1] + 1;
    piVar16[1] = iVar6;
    *(int *)(iVar5 + -8 + iVar6 * 8) = iVar19;
    *(int *)(iVar5 + -4 + iVar6 * 8) = iVar12 + -1;
    uVar18 = uVar18 + 1;
  } while( true );
}

