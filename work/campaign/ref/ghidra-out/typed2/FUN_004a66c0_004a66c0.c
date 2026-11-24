
void FUN_004a66c0(uint param_1)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  CMap *pCVar4;
  int iVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int *piVar12;
  CHeightBlock **ppCVar13;
  int in_ECX;
  int iVar14;
  CHeightBlock *pCVar15;
  code *pcVar16;
  byte *pbVar17;
  float fVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  float in_XMM2_Da;
  int local_30;
  int local_2c;
  
  pcVar16 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
      iVar5 = FUN_00592f10(PTR_0077241c);
      pbVar17 = (byte *)(iVar5 + 0x34);
      if (param_1 < 8) {
        pbVar17 = pbVar17 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar17 < 0x81) {
        DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
        uVar6 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar17 = (byte *)FUN_00423700(uVar6);
        if (*pbVar17 < 0x81) {
          DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar6 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar17 = (byte *)FUN_00423700(uVar6);
          if (*pbVar17 < 0x81) {
            DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar17 = (byte *)FUN_00423700(param_1);
            if (*pbVar17 < 0x81) goto LAB_004a6cc6;
          }
        }
      }
    }
    local_2c = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar5 = FUN_00492f80();
        iVar14 = DAT_00767980 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar14 * 0x343fd + 0x269ec3;
        uVar6 = DAT_00767980 >> 0x10;
        fVar2 = ((float)((iVar14 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        dVar19 = (double)fVar2;
        FUN_006f6ad0();
        fVar18 = *(float *)(in_ECX + 0xc);
        dVar20 = (double)(((float)((uVar6 & 0x7fff) % 0x168) / 180.0) * 3.1415927);
        FUN_006f6ad0();
        fVar1 = *(float *)(in_ECX + 0x10);
        dVar21 = (double)fVar2;
        FUN_006f5ae0();
        fVar2 = *(float *)(in_ECX + 0x14);
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar5 * 0x44);
        }
        iVar14 = iVar5 * 0x44;
        *pfVar7 = (float)dVar19 * 0.02 + fVar18;
        pfVar7[1] = (float)dVar20 * 0.02 + fVar1;
        pfVar7[2] = (float)dVar21 * 0.02 + fVar2;
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar9 = iVar8 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar9 * 0x343fd + 0x269ec3;
        uVar6 = DAT_00767980 >> 0x10;
        fVar18 = *(float *)(in_ECX + 0x18);
        fVar1 = *(float *)(in_ECX + 0x1c);
        fVar2 = *(float *)(in_ECX + 0x20);
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar10 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar10 = *(int *)(in_ECX + 0x54) + iVar14;
        }
        *(float *)(iVar10 + 0xc) = fVar18 + (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 180.0;
        *(float *)(iVar10 + 0x10) = fVar1 + (float)(int)((iVar9 >> 0x10 & 0xfU) - 0x14) / 180.0;
        *(float *)(iVar10 + 0x14) = (float)(int)((uVar6 & 0xf) - 8) / 180.0 + fVar2;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar14;
        }
        *(undefined4 *)(iVar8 + 0x28) = 0x3ecccccd;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar6 = DAT_00767980 >> 0x10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar14;
        }
        *(uint *)(iVar8 + 0x2c) = uVar6 & 0x1f;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar14;
        }
        *(undefined4 *)(iVar8 + 0x30) = 0;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar14;
        }
        *(undefined4 *)(iVar8 + 0x34) = 0xffffffff;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar14;
        }
        *(undefined4 *)(iVar8 + 0x38) = 0;
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar6 = DAT_00767980 >> 0x10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar14;
        }
        *(uint *)(iVar9 + 0x3c) = (uVar6 & 0xf) + (iVar8 >> 0x10 & 3U) * 0x10000;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar14 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar14 = *(int *)(in_ECX + 0x54) + iVar14;
        }
        local_2c = local_2c + 1;
        *(undefined1 *)(iVar14 + 0x40) = 0;
      } while (local_2c < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004a6cc6:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar5 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    do {
      if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
        (*pcVar16)(0xc000008c,1,0,0);
        pfVar7 = *(float **)(in_ECX + 0x54);
        pfVar11 = pfVar7;
      }
      else {
        pfVar7 = *(float **)(in_ECX + 0x54) + iVar5 * 0x11;
        pfVar11 = *(float **)(in_ECX + 0x54);
      }
      if (pfVar7[0xb] != -NAN) {
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar16)(0xc000008c,1,0,0);
          pfVar11 = *(float **)(in_ECX + 0x54);
          pfVar7 = pfVar11;
        }
        else {
          pfVar7 = pfVar11 + iVar5 * 0x11;
        }
        if ((((*pfVar7 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= *pfVar7)) ||
            (pfVar7[1] < PTR_0077241c->y0f + 1.0)) || (PTR_0077241c->y1f - 1.0 <= pfVar7[1])) {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar16)(0xc000008c,1,0,0);
            pfVar11 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar11 = pfVar11 + iVar5 * 0x11;
          }
          *pfVar11 = 2.0;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar14 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          }
          *(undefined4 *)(iVar14 + 4) = 0x40000000;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar14 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          }
          *(undefined4 *)(iVar14 + 0x2c) = 0xffffd8f0;
        }
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar16)(0xc000008c,1,0,0);
          iVar14 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
        }
        *(int *)(iVar14 + 0x2c) = *(int *)(iVar14 + 0x2c) + 1;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar16)(0xc000008c,1,0,0);
          iVar14 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar14;
        }
        else {
          iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (*(char *)(iVar14 + 0x40) == '\0') {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar14 = *(int *)(in_ECX + 0x54);
            iVar8 = iVar14;
          }
          else {
            iVar14 = iVar8 + iVar5 * 0x44;
          }
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = iVar8 + iVar5 * 0x44;
          }
          fVar18 = *(float *)(iVar8 + 0xc) * *(float *)(iVar8 + 0xc) +
                   *(float *)(iVar8 + 0x10) * *(float *)(iVar8 + 0x10) +
                   *(float *)(iVar8 + 0x14) * *(float *)(iVar8 + 0x14);
          FUN_0040b7e0();
          *(float *)(iVar14 + 0x30) = fVar18 + *(float *)(iVar14 + 0x30);
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar14 = *(int *)(in_ECX + 0x54);
            iVar8 = iVar14;
          }
          else {
            iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          fVar18 = *(float *)(iVar14 + 0xc);
          fVar1 = *(float *)(iVar14 + 0x14);
          fVar2 = *(float *)(iVar14 + 0x10);
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar16)(0xc000008c,1,0,0);
            pfVar7 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar7 = (float *)(iVar8 + iVar5 * 0x44);
          }
          *pfVar7 = *pfVar7 + fVar18 * in_XMM2_Da;
          pfVar7[2] = fVar1 * in_XMM2_Da + pfVar7[2];
          pfVar7[1] = pfVar7[1] + fVar2 * in_XMM2_Da;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar14 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          }
          *(float *)(iVar14 + 0xc) = in_XMM2_Da * 0.0 + *(float *)(iVar14 + 0xc);
          *(float *)(iVar14 + 0x14) = in_XMM2_Da * 0.0 + *(float *)(iVar14 + 0x14);
          *(float *)(iVar14 + 0x10) = *(float *)(iVar14 + 0x10) + in_XMM2_Da * 0.06;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar14 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          }
          iVar14 = (int)ROUND(*(float *)(iVar14 + 4) * 8.0);
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            DAT_00772dd8 = iVar14;
            (*pcVar16)(0xc000008c,1,0,0);
            pfVar7 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar5 * 0x44);
          }
          DAT_00772dd8 = (uint)ROUND(*pfVar7 * 8.0);
          if (((((int)DAT_00772dd8 < PTR_0077241c->x0_8 + 0x21) ||
               (PTR_0077241c->x1_8 + -0x21 <= (int)DAT_00772dd8)) ||
              (iVar14 < PTR_0077241c->y0_8 + 0x21)) || (PTR_0077241c->y1_8 + -0x21 <= iVar14)) {
            FUN_00493010(iVar5);
          }
          else {
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
              (*pcVar16)(0xc000008c,1,0,0);
              iVar14 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
            }
            uVar6 = (uint)ROUND(*(float *)(iVar14 + 4) * 8.0);
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
              DAT_00772dd8 = uVar6;
              (*pcVar16)(0xc000008c,1,0,0);
              pfVar7 = *(float **)(in_ECX + 0x54);
            }
            else {
              pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar5 * 0x44);
            }
            pCVar4 = PTR_0077241c;
            fVar18 = *pfVar7;
            DAT_00772dd8 = (int)ROUND(fVar18 * 8.0);
            piVar12 = (int *)FUN_00592f10(PTR_0077241c);
            pcVar16 = RaiseException_exref;
            iVar14 = *piVar12;
            ppCVar13 = &pCVar4->heightBlocks->data;
            if ((iVar14 < 0) || (pCVar4->heightBlocks->count <= iVar14)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar15 = *ppCVar13;
            }
            else {
              pCVar15 = *ppCVar13 + iVar14;
            }
            bVar3 = pCVar15->heights[(uVar6 & 7) << 3 | (int)ROUND(fVar18 * 8.0) & 7U];
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar14 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
            }
            DAT_00772dd8 = (uint)ROUND(*(float *)(iVar14 + 8));
            if ((int)DAT_00772dd8 < (int)(uint)bVar3) {
              if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar14 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
              }
              *(undefined1 *)(iVar14 + 0x40) = 1;
              local_30 = 0;
              do {
                if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                  (*pcVar16)(0xc000008c,1,0,0);
                  iVar14 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
                }
                uVar6 = (uint)ROUND(*(float *)(iVar14 + 4) * 8.0);
                if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                  DAT_00772dd8 = uVar6;
                  (*pcVar16)(0xc000008c,1,0,0);
                  pfVar7 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar5 * 0x44);
                }
                pCVar4 = PTR_0077241c;
                fVar18 = *pfVar7;
                DAT_00772dd8 = (int)ROUND(fVar18 * 8.0);
                piVar12 = (int *)FUN_00592f10(PTR_0077241c);
                pcVar16 = RaiseException_exref;
                iVar14 = *piVar12;
                ppCVar13 = &pCVar4->heightBlocks->data;
                if ((iVar14 < 0) || (pCVar4->heightBlocks->count <= iVar14)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar15 = *ppCVar13;
                }
                else {
                  pCVar15 = *ppCVar13 + iVar14;
                }
                bVar3 = pCVar15->heights[(uVar6 & 7) << 3 | (int)ROUND(fVar18 * 8.0) & 7U];
                if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar14 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
                }
                DAT_00772dd8 = (uint)ROUND(*(float *)(iVar14 + 8));
                if ((int)(uint)bVar3 <= (int)DAT_00772dd8) goto LAB_004a74ba;
                if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar14 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
                }
                *(float *)(iVar14 + 4) = *(float *)(iVar14 + 4) - 0.1;
                local_30 = local_30 + 1;
              } while (local_30 < 0x28);
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
LAB_004a74ba:
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar16)(0xc000008c,1,0,0);
          iVar14 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar14;
        }
        else {
          iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (0x32 < *(int *)(iVar14 + 0x2c)) {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = iVar8 + iVar5 * 0x44;
          }
          *(float *)(iVar8 + 0x28) = *(float *)(iVar8 + 0x28) * 0.9;
        }
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar16)(0xc000008c,1,0,0);
          iVar14 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar14 = *(int *)(in_ECX + 0x54) + iVar5 * 0x44;
        }
        if (0x5f < *(int *)(iVar14 + 0x2c)) {
          FUN_00493010(iVar5);
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

