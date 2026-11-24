
void FUN_0057a1c0(void)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  CHeightBlock **ppCVar5;
  int iVar6;
  int *in_ECX;
  int iVar7;
  CHeightBlock *pCVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  code *pcVar13;
  int iVar14;
  bool bVar15;
  float fVar16;
  float fVar17;
  float local_10;
  float local_c;
  
  uVar12 = 0;
  if (0 < in_ECX[1]) {
    bVar15 = in_ECX[1] != 0;
    pcVar13 = RaiseException_exref;
    do {
      if (!bVar15) {
        (*pcVar13)(0xc000008c,1,0,0);
      }
      iVar7 = uVar12 * 0x28;
      *(undefined1 *)(iVar7 + 0x25 + *in_ECX) = 0;
      if ((uint)in_ECX[1] <= uVar12) {
        (*pcVar13)(0xc000008c,1,0,0);
      }
      piVar3 = (int *)(DAT_0077244c + 0x488);
      if (*(uint *)(iVar7 + *in_ECX) < 0x2000) {
        piVar3 = piVar3 + *(uint *)(iVar7 + *in_ECX);
      }
      else {
        (*pcVar13)(0xc000008c,1,0,0);
      }
      iVar6 = *piVar3;
      if (iVar6 != 0) {
        fVar16 = *(float *)(iVar6 + 0xc);
        uVar10 = in_ECX[1];
        fVar17 = *(float *)(iVar6 + 0x10);
        fVar2 = *(float *)(iVar6 + 0x14);
        if (uVar10 <= uVar12) {
          (*pcVar13)(0xc000008c,1,0,0);
          uVar10 = in_ECX[1];
        }
        iVar6 = *in_ECX;
        iVar14 = (int)(*(float *)(iVar7 + 4 + iVar6) + fVar16);
        if (uVar10 <= uVar12) {
          (*pcVar13)(0xc000008c,1,0,0);
          iVar6 = *in_ECX;
          uVar10 = in_ECX[1];
        }
        iVar4 = (int)(*(float *)(iVar7 + 8 + iVar6) + fVar17);
        if ((((PTR_0077241c->cellX0 + 4 <= iVar14) && (iVar14 < PTR_0077241c->cellX1 + -4)) &&
            (PTR_0077241c->cellY0 + 4 <= iVar4)) && (iVar4 < PTR_0077241c->cellY1 + -4)) {
          if (uVar10 <= uVar12) {
            (*pcVar13)(0xc000008c,1,0,0);
            iVar6 = *in_ECX;
            uVar10 = in_ECX[1];
          }
          if (*(float *)(iVar7 + 0x18 + iVar6) <= 0.0) {
            if (uVar10 <= uVar12) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar6 = *in_ECX;
            }
            if (*(float *)(iVar7 + 0x18 + iVar6) != -1.0) goto LAB_0057a884;
          }
          piVar3 = (int *)FUN_00592f10(PTR_0077241c);
          local_c = 0.0;
          local_10 = (float)piVar3[8];
          iVar6 = *piVar3;
          ppCVar5 = &PTR_0077241c->heightBlocks->data;
          if ((iVar6 < 0) || (PTR_0077241c->heightBlocks->count <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar8 = *ppCVar5;
          }
          else {
            pCVar8 = *ppCVar5 + iVar6;
          }
          uVar10 = *(uint *)pCVar8->tail & 0x3ff;
          if (uVar10 != 0) {
            if ((uint)in_ECX[1] <= uVar12) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar6 = *in_ECX;
            if (*(float *)(iVar7 + 0x1c + iVar6) != -1.0) {
              if ((uint)in_ECX[1] <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar6 = *in_ECX;
              }
              if ((float)piVar3[8] != *(float *)(iVar7 + 0x1c + iVar6)) {
                if ((uint)in_ECX[1] <= uVar12) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar6 = *in_ECX;
                }
                piVar3[8] = *(int *)(iVar7 + 0x1c + iVar6);
                if ((uint)in_ECX[1] <= uVar12) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                *(undefined1 *)(iVar7 + 0x25 + *in_ECX) = 1;
              }
              local_c = (float)uVar10 * (float)piVar3[8] - (float)uVar10 * local_10;
            }
            if ((uint)in_ECX[1] <= uVar12) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar6 = *in_ECX;
            if (*(float *)(iVar7 + 0x20 + iVar6) != -1.0) {
              uVar11 = in_ECX[1];
              if (uVar11 <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar6 = *in_ECX;
                uVar11 = in_ECX[1];
              }
              local_c = *(float *)(iVar7 + 0x20 + iVar6);
              if (uVar11 <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar6 = *in_ECX;
                uVar11 = in_ECX[1];
              }
              if (*(float *)(iVar7 + 0x18 + iVar6) != -1.0) {
                if (uVar11 <= uVar12) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar6 = *in_ECX;
                  uVar11 = in_ECX[1];
                }
                pfVar1 = (float *)(iVar7 + 0x18 + iVar6);
                if (*pfVar1 <= local_c && local_c != *pfVar1) {
                  if (uVar11 <= uVar12) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar6 = *in_ECX;
                  }
                  local_c = *(float *)(iVar7 + 0x18 + iVar6);
                }
              }
              local_10 = ((float)uVar10 * local_10 + local_c) / (float)uVar10;
              if (local_10 <= 0.0) {
                local_10 = 0.0;
              }
              if ((float)piVar3[8] != local_10) {
                piVar3[8] = (int)local_10;
                piVar3[0xc] = 0x3d4ccccd;
                if ((uint)in_ECX[1] <= uVar12) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                *(undefined1 *)(iVar7 + 0x25 + *in_ECX) = 1;
              }
            }
            if ((uint)in_ECX[1] <= uVar12) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar6 = *in_ECX;
            if (*(char *)(iVar7 + 0x24 + iVar6) != '\0') {
              if ((uint)in_ECX[1] <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar6 = *in_ECX;
              }
              fVar17 = *(float *)(iVar7 + 8 + iVar6) + fVar17;
              iVar6 = FUN_0057aaf0(*(float *)(iVar7 + 4 + iVar6) + fVar16,fVar17,
                                   *(float *)(iVar7 + 0xc + iVar6) + fVar2);
              uVar11 = in_ECX[1];
              local_c = (*(float *)(iVar6 + 4) - fVar17) * (float)uVar10;
              if (uVar11 <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                uVar11 = in_ECX[1];
              }
              iVar6 = *in_ECX;
              if (*(float *)(iVar7 + 0x18 + iVar6) != -1.0) {
                if (uVar11 <= uVar12) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar6 = *in_ECX;
                  uVar11 = in_ECX[1];
                }
                pfVar1 = (float *)(iVar7 + 0x18 + iVar6);
                if (*pfVar1 <= local_c && local_c != *pfVar1) {
                  if (uVar11 <= uVar12) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar6 = *in_ECX;
                  }
                  local_c = *(float *)(iVar7 + 0x18 + iVar6);
                }
              }
              fVar16 = ((float)uVar10 * local_10 + local_c) / (float)uVar10;
              if (fVar16 <= 0.0) {
                fVar16 = 0.0;
              }
              if ((float)piVar3[8] != fVar16) {
                piVar3[8] = (int)fVar16;
                if ((uint)in_ECX[1] <= uVar12) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                *(undefined1 *)(iVar7 + 0x25 + *in_ECX) = 1;
              }
            }
            if ((uint)in_ECX[1] <= uVar12) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar6 = *in_ECX;
            if (*(float *)(iVar7 + 0x18 + iVar6) != -1.0) {
              if ((uint)in_ECX[1] <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar6 = *in_ECX;
              }
              *(float *)(iVar7 + 0x18 + iVar6) = *(float *)(iVar7 + 0x18 + iVar6) - local_c;
              uVar10 = in_ECX[1];
              if (uVar10 <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                uVar10 = in_ECX[1];
              }
              iVar6 = *in_ECX;
              pfVar1 = (float *)(iVar7 + 0x18 + iVar6);
              if (*pfVar1 <= 0.0 && *pfVar1 != 0.0) {
                if (uVar10 <= uVar12) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar6 = *in_ECX;
                }
                *(undefined4 *)(iVar7 + 0x18 + iVar6) = 0;
              }
            }
          }
          uVar10 = in_ECX[1];
          if (uVar10 <= uVar12) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar10 = in_ECX[1];
          }
          iVar6 = *in_ECX;
          if (*(float *)(iVar7 + 0x20 + iVar6) != -1.0) {
            if (uVar10 <= uVar12) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *in_ECX;
            }
            pcVar13 = RaiseException_exref;
            if (*(float *)(iVar7 + 0x20 + iVar6) < 0.0) goto LAB_0057a884;
          }
          bVar9 = *(byte *)((int)piVar3 + 0x1b) & 0xf8;
          *(byte *)((int)piVar3 + 0x1b) = bVar9;
          pcVar13 = RaiseException_exref;
          if ((float)piVar3[8] != 0.0) {
            if ((uint)in_ECX[1] <= uVar12) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              bVar9 = *(byte *)((int)piVar3 + 0x1b);
            }
            pcVar13 = RaiseException_exref;
            if ((uint)bVar9 != (*(uint *)(iVar7 + 0x10 + *in_ECX) | (uint)bVar9)) {
              if ((uint)in_ECX[1] <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                bVar9 = *(byte *)((int)piVar3 + 0x1b);
              }
              *(byte *)((int)piVar3 + 0x1b) = *(byte *)(iVar7 + 0x10 + *in_ECX) | bVar9;
              pcVar13 = RaiseException_exref;
              if ((uint)in_ECX[1] <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              *(undefined1 *)(iVar7 + 0x25 + *in_ECX) = 1;
            }
          }
        }
      }
LAB_0057a884:
      uVar12 = uVar12 + 1;
      bVar15 = uVar12 < (uint)in_ECX[1];
    } while ((int)uVar12 < in_ECX[1]);
  }
  return;
}

