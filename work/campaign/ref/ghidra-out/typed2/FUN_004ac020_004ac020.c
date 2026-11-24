
void FUN_004ac020(uint param_1)

{
  float fVar1;
  byte bVar2;
  float fVar3;
  CMap *pCVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  float *pfVar9;
  int *piVar10;
  CHeightBlock **ppCVar11;
  int in_ECX;
  int iVar12;
  CHeightBlock *pCVar13;
  code *pcVar14;
  byte *pbVar15;
  float fVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  float fVar20;
  float in_XMM2_Da;
  int local_2c;
  int local_28;
  
  pcVar14 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
      iVar5 = FUN_00592f10(PTR_0077241c);
      pbVar15 = (byte *)(iVar5 + 0x34);
      if (param_1 < 8) {
        pbVar15 = pbVar15 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar15 < 0x81) {
        DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
        uVar8 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar15 = (byte *)FUN_00423700(uVar8);
        if (*pbVar15 < 0x81) {
          DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar8 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar15 = (byte *)FUN_00423700(uVar8);
          if (*pbVar15 < 0x81) {
            DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar15 = (byte *)FUN_00423700(param_1);
            if (*pbVar15 < 0x81) goto LAB_004ac596;
          }
        }
      }
    }
    local_28 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar5 = FUN_00492f80();
        iVar12 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar6 = iVar12 * 0x343fd + 0x269ec3;
        fVar1 = ((float)((iVar12 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
        fVar3 = (float)((DAT_00767980 >> 0x10 & 0x7fffU) % 5) / 180.0;
        dVar17 = (double)fVar1;
        FUN_006f6ad0();
        fVar16 = *(float *)(in_ECX + 0xc);
        dVar18 = (double)(((float)((iVar6 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927);
        FUN_006f6ad0();
        fVar20 = *(float *)(in_ECX + 0x10);
        dVar19 = (double)fVar1;
        FUN_006f5ae0();
        fVar1 = *(float *)(in_ECX + 0x14);
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar5 * 0x44);
        }
        iVar6 = iVar5 * 0x44;
        *pfVar7 = (float)dVar17 * fVar3 + fVar16;
        pfVar7[1] = (float)dVar18 * fVar3 + fVar20;
        pfVar7[2] = (float)dVar19 * fVar3 + fVar1;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar12 + 0xc) = *(undefined4 *)(in_ECX + 0x18);
        *(undefined4 *)(iVar12 + 0x10) = *(undefined4 *)(in_ECX + 0x1c);
        *(undefined4 *)(iVar12 + 0x14) = *(undefined4 *)(in_ECX + 0x20);
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar12 + 0x28) = 0x3f19999a;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar8 = DAT_00767980 >> 0x10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(uint *)(iVar12 + 0x2c) = uVar8 & 0x1f;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar12 + 0x30) = 0;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar12 + 0x34) = 0xffffffff;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar12 + 0x38) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar8 = DAT_00767980 >> 0x10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(uint *)(iVar12 + 0x3c) = (uVar8 & 0x7fff) % 6 + 0x60008;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        local_28 = local_28 + 1;
        *(undefined1 *)(iVar6 + 0x40) = 0;
      } while (local_28 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004ac596:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar5 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    do {
      if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
        (*pcVar14)(0xc000008c,1,0,0);
        pfVar7 = *(float **)(in_ECX + 0x54);
        pfVar9 = pfVar7;
      }
      else {
        pfVar7 = *(float **)(in_ECX + 0x54) + iVar5 * 0x11;
        pfVar9 = *(float **)(in_ECX + 0x54);
      }
      if (pfVar7[0xb] != -NAN) {
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar14)(0xc000008c,1,0,0);
          pfVar9 = *(float **)(in_ECX + 0x54);
          pfVar7 = pfVar9;
        }
        else {
          pfVar7 = pfVar9 + iVar5 * 0x11;
        }
        if ((((*pfVar7 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= *pfVar7)) ||
            (pfVar7[1] < PTR_0077241c->y0f + 1.0)) || (PTR_0077241c->y1f - 1.0 <= pfVar7[1])) {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar14)(0xc000008c,1,0,0);
            pfVar9 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar9 = pfVar9 + iVar5 * 0x11;
          }
          *pfVar9 = 2.0;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar14)(0xc000008c,1,0,0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          }
          *(undefined4 *)(iVar6 + 4) = 0x40000000;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar14)(0xc000008c,1,0,0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          }
          *(undefined4 *)(iVar6 + 0x2c) = 0xffffd8f0;
        }
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar14)(0xc000008c,1,0,0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
        }
        *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + 1;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar14)(0xc000008c,1,0,0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar12 = iVar6;
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        if (*(char *)(iVar6 + 0x40) == '\0') {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar14)(0xc000008c,1,0,0);
            iVar6 = *(int *)(in_ECX + 0x54);
            iVar12 = iVar6;
          }
          else {
            iVar6 = iVar12 + iVar5 * 0x44;
          }
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar14)(0xc000008c,1,0,0);
            iVar12 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar12 = iVar12 + iVar5 * 0x44;
          }
          fVar16 = *(float *)(iVar12 + 0xc) * *(float *)(iVar12 + 0xc) +
                   *(float *)(iVar12 + 0x10) * *(float *)(iVar12 + 0x10) +
                   *(float *)(iVar12 + 0x14) * *(float *)(iVar12 + 0x14);
          FUN_0040b7e0();
          *(float *)(iVar6 + 0x30) = fVar16 + *(float *)(iVar6 + 0x30);
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar14)(0xc000008c,1,0,0);
            iVar6 = *(int *)(in_ECX + 0x54);
            iVar12 = iVar6;
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
            iVar12 = *(int *)(in_ECX + 0x54);
          }
          fVar16 = *(float *)(iVar6 + 0xc);
          fVar20 = *(float *)(iVar6 + 0x10);
          fVar1 = *(float *)(iVar6 + 0x14);
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar14)(0xc000008c,1,0,0);
            pfVar7 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar7 = (float *)(iVar12 + iVar5 * 0x44);
          }
          *pfVar7 = *pfVar7 + in_XMM2_Da * fVar16;
          pfVar7[1] = pfVar7[1] + fVar20 * in_XMM2_Da;
          pfVar7[2] = pfVar7[2] + fVar1 * in_XMM2_Da;
          DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
          fVar16 = (float)(DAT_00767980 >> 0x10 & 0x7fff);
          fVar20 = in_XMM2_Da * 0.0 * fVar16 * 3.0517578e-05;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar14)(0xc000008c,1,0,0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          }
          *(float *)(iVar6 + 0xc) = fVar20 + *(float *)(iVar6 + 0xc);
          *(float *)(iVar6 + 0x10) =
               *(float *)(iVar6 + 0x10) + in_XMM2_Da * 0.01 * fVar16 * 3.0517578e-05;
          *(float *)(iVar6 + 0x14) = *(float *)(iVar6 + 0x14) + fVar20;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar14)(0xc000008c,1,0,0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          }
          iVar6 = (int)ROUND(*(float *)(iVar6 + 4) * 8.0);
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            DAT_00772dd8 = iVar6;
            (*pcVar14)(0xc000008c,1,0,0);
            pfVar7 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar5 * 0x44);
          }
          DAT_00772dd8 = (uint)ROUND(*pfVar7 * 8.0);
          if (((((int)DAT_00772dd8 < PTR_0077241c->x0_8 + 0x21) ||
               (PTR_0077241c->x1_8 + -0x21 <= (int)DAT_00772dd8)) ||
              (iVar6 < PTR_0077241c->y0_8 + 0x21)) || (PTR_0077241c->y1_8 + -0x21 <= iVar6)) {
            FUN_00493010(iVar5);
          }
          else {
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
              (*pcVar14)(0xc000008c,1,0,0);
              iVar6 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
            }
            uVar8 = (uint)ROUND(*(float *)(iVar6 + 4) * 8.0);
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
              DAT_00772dd8 = uVar8;
              (*pcVar14)(0xc000008c,1,0,0);
              pfVar7 = *(float **)(in_ECX + 0x54);
            }
            else {
              pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar5 * 0x44);
            }
            pCVar4 = PTR_0077241c;
            fVar16 = *pfVar7;
            DAT_00772dd8 = (int)ROUND(fVar16 * 8.0);
            piVar10 = (int *)FUN_00592f10(PTR_0077241c);
            pcVar14 = RaiseException_exref;
            iVar6 = *piVar10;
            ppCVar11 = &pCVar4->heightBlocks->data;
            if ((iVar6 < 0) || (pCVar4->heightBlocks->count <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar13 = *ppCVar11;
            }
            else {
              pCVar13 = *ppCVar11 + iVar6;
            }
            bVar2 = pCVar13->heights[(uVar8 & 7) << 3 | (int)ROUND(fVar16 * 8.0) & 7U];
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
            }
            DAT_00772dd8 = (uint)ROUND(*(float *)(iVar6 + 8));
            if ((int)DAT_00772dd8 < (int)(uint)bVar2) {
              if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar6 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
              }
              *(undefined1 *)(iVar6 + 0x40) = 1;
              DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
              uVar8 = DAT_00767980 >> 0x10;
              if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar6 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
              }
              local_2c = 0;
              *(uint *)(iVar6 + 0x3c) = (uVar8 & 1) + 0x6000e;
              do {
                if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                  (*pcVar14)(0xc000008c,1,0,0);
                  iVar6 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
                }
                uVar8 = (uint)ROUND(*(float *)(iVar6 + 4) * 8.0);
                if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                  DAT_00772dd8 = uVar8;
                  (*pcVar14)(0xc000008c,1,0,0);
                  pfVar7 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar5 * 0x44);
                }
                pCVar4 = PTR_0077241c;
                fVar16 = *pfVar7;
                DAT_00772dd8 = (int)ROUND(fVar16 * 8.0);
                piVar10 = (int *)FUN_00592f10(PTR_0077241c);
                pcVar14 = RaiseException_exref;
                iVar6 = *piVar10;
                ppCVar11 = &pCVar4->heightBlocks->data;
                if ((iVar6 < 0) || (pCVar4->heightBlocks->count <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar13 = *ppCVar11;
                }
                else {
                  pCVar13 = *ppCVar11 + iVar6;
                }
                bVar2 = pCVar13->heights[(uVar8 & 7) << 3 | (int)ROUND(fVar16 * 8.0) & 7U];
                if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar6 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
                }
                DAT_00772dd8 = (uint)ROUND(*(float *)(iVar6 + 8));
                if ((int)(uint)bVar2 <= (int)DAT_00772dd8) goto LAB_004ace27;
                if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar6 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
                }
                *(float *)(iVar6 + 4) = *(float *)(iVar6 + 4) - 0.1;
                local_2c = local_2c + 1;
              } while (local_2c < 0x28);
              if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x2c) = 100;
              }
              else {
                *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x2c + iVar5 * 0x44) = 100;
              }
            }
          }
        }
LAB_004ace27:
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar14)(0xc000008c,1,0,0);
          iVar6 = *(int *)(in_ECX + 0x54);
          iVar12 = iVar6;
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        if (0x32 < *(int *)(iVar6 + 0x2c)) {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar14)(0xc000008c,1,0,0);
            iVar12 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar12 = iVar12 + iVar5 * 0x44;
          }
          *(float *)(iVar12 + 0x28) = *(float *)(iVar12 + 0x28) * 0.9;
        }
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar14)(0xc000008c,1,0,0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
        }
        if (0x5f < *(int *)(iVar6 + 0x2c)) {
          FUN_00493010(iVar5);
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

