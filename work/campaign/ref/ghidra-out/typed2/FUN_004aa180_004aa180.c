
void FUN_004aa180(uint param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  int in_ECX;
  undefined4 *puVar12;
  code *pcVar13;
  byte *pbVar14;
  float fVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  float fVar19;
  float in_XMM2_Da;
  float fVar20;
  undefined4 in_XMM3_Da;
  undefined4 in_XMM3_Db;
  uint local_44;
  undefined4 *local_40;
  int local_3c;
  
  pcVar13 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar4 = FUN_00592f10(PTR_0077241c);
      pbVar14 = (byte *)(iVar4 + 0x34);
      if (param_1 < 8) {
        pbVar14 = pbVar14 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar14 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar7 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar14 = (byte *)FUN_00423700(uVar7);
        if (*pbVar14 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar7 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar14 = (byte *)FUN_00423700(uVar7);
          if (*pbVar14 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar14 = (byte *)FUN_00423700(param_1);
            if (*pbVar14 < 0x81) goto LAB_004aa733;
          }
        }
      }
    }
    local_3c = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar4 = FUN_00492f80();
        DAT_00772dd8 = (int)ROUND((float)((double)CONCAT44(in_XMM3_Db,in_XMM3_Da) * 100.0));
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar12 = *(undefined4 **)(in_ECX + 0x54);
        }
        else {
          puVar12 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar4 * 0x44);
        }
        iVar8 = iVar4 * 0x44;
        *puVar12 = *(undefined4 *)(in_ECX + 0xc);
        puVar12[1] = *(undefined4 *)(in_ECX + 0x10);
        puVar12[2] = *(undefined4 *)(in_ECX + 0x14);
        iVar5 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar6 = iVar5 * 0x343fd + 0x269ec3;
        fVar20 = ((float)((iVar5 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
        fVar1 = (float)((DAT_00767980 >> 0x10 & 0x7fffU) % 0x32) / 850.0;
        dVar16 = (double)fVar20;
        FUN_006f6ad0();
        fVar15 = *(float *)(in_ECX + 0x18);
        dVar17 = (double)(((float)((iVar6 >> 0x10 & 0x7fffU) % 0xb4) / 180.0) * 3.1415927);
        FUN_006f6ad0();
        fVar19 = *(float *)(in_ECX + 0x1c);
        dVar18 = (double)fVar20;
        FUN_006f5ae0();
        fVar20 = *(float *)(in_ECX + 0x20);
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(float *)(iVar5 + 0xc) = (float)dVar16 * fVar1 + fVar15;
        *(float *)(iVar5 + 0x10) = (float)dVar17 * fVar1 + fVar19;
        *(float *)(iVar5 + 0x14) = (float)dVar18 * fVar1 + fVar20;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar5 + 0x28) = 0x40000000;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar5 + 0x34) = 0xffe060;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar5 + 0x3c) = 0x30002;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(uint *)(iVar5 + 0x2c) = (uVar7 & 0x7fff) % 10;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar5 + 0x30) = 0;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar5 + 0x38) = 0;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar5 + 0x24) = 0;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined1 *)(iVar8 + 0x40) = 0;
        local_3c = local_3c + 1;
      } while (local_3c < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004aa733:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar4 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    do {
      if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
        (*pcVar13)(0xc000008c,1,0,0);
        pfVar11 = *(float **)(in_ECX + 0x54);
        pfVar10 = pfVar11;
      }
      else {
        pfVar11 = *(float **)(in_ECX + 0x54) + iVar4 * 0x11;
        pfVar10 = *(float **)(in_ECX + 0x54);
      }
      if (pfVar11[0xb] != -NAN) {
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          (*pcVar13)(0xc000008c,1,0,0);
          pfVar10 = *(float **)(in_ECX + 0x54);
          pfVar11 = pfVar10;
        }
        else {
          pfVar11 = pfVar10 + iVar4 * 0x11;
        }
        if ((((*pfVar11 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= *pfVar11)) ||
            (pfVar11[1] < PTR_0077241c->y0f + 1.0)) || (PTR_0077241c->y1f - 1.0 <= pfVar11[1])) {
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            pfVar10 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar10 = pfVar10 + iVar4 * 0x11;
          }
          *pfVar10 = 2.0;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
          }
          *(undefined4 *)(iVar8 + 4) = 0x40000000;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
          }
          *(undefined4 *)(iVar8 + 0x2c) = 0xffffd8f0;
        }
        else {
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            pfVar10 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar10 = pfVar10 + iVar4 * 0x11;
          }
          pfVar10[0xc] = pfVar10[0xc] + 0.08;
          iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
          iVar5 = iVar8 * 0x343fd + 0x269ec3;
          DAT_00767980 = iVar5 * 0x343fd + 0x269ec3;
          uVar7 = DAT_00767980 >> 0x10;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
          }
          *(float *)(iVar6 + 0xc) =
               (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 6000.0 + *(float *)(iVar6 + 0xc);
          *(float *)(iVar6 + 0x10) =
               *(float *)(iVar6 + 0x10) + (float)(int)((iVar5 >> 0x10 & 0xfU) - 10) / 6000.0;
          *(float *)(iVar6 + 0x14) =
               *(float *)(iVar6 + 0x14) + (float)(int)((uVar7 & 0xf) - 8) / 6000.0;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            iVar8 = *(int *)(in_ECX + 0x54);
            iVar5 = iVar8;
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
            iVar5 = *(int *)(in_ECX + 0x54);
          }
          fVar15 = *(float *)(iVar8 + 0xc);
          fVar19 = *(float *)(iVar8 + 0x10);
          fVar20 = *(float *)(iVar8 + 0x14);
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            pfVar11 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar11 = (float *)(iVar5 + iVar4 * 0x44);
          }
          *pfVar11 = *pfVar11 + fVar15 * in_XMM2_Da;
          pfVar11[1] = fVar19 * in_XMM2_Da + pfVar11[1];
          pfVar11[2] = pfVar11[2] + fVar20 * in_XMM2_Da;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            iVar8 = *(int *)(in_ECX + 0x54);
            iVar5 = iVar8;
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
            iVar5 = *(int *)(in_ECX + 0x54);
          }
          if (0 < *(int *)(iVar8 + 0x24)) {
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar8 = *(int *)(in_ECX + 0x54);
              iVar5 = iVar8;
            }
            else {
              iVar8 = iVar5 + iVar4 * 0x44;
            }
            if (*(int *)(iVar8 + 0x24) < *(int *)(in_ECX + 0x4c)) {
              if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                (*pcVar13)(0xc000008c,1,0,0);
                iVar5 = *(int *)(in_ECX + 0x54);
                iVar8 = iVar5;
              }
              else {
                iVar8 = iVar5 + iVar4 * 0x44;
              }
              iVar8 = 0x40 - *(int *)(iVar8 + 0x2c);
              uVar7 = iVar8 * 0x14;
              if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                (*pcVar13)(0xc000008c,1,0,0);
                iVar5 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar5 = iVar5 + iVar4 * 0x44;
              }
              *(uint *)(iVar5 + 0x38) = (iVar8 * 0x1400 | uVar7) << 8 | uVar7;
              if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                (*pcVar13)(0xc000008c,1,0,0);
                pfVar11 = *(float **)(in_ECX + 0x54);
                pfVar10 = pfVar11;
              }
              else {
                pfVar11 = *(float **)(in_ECX + 0x54);
                pfVar10 = pfVar11 + iVar4 * 0x11;
              }
              fVar15 = pfVar10[9];
              if (((int)fVar15 < 0) || (*(int *)(in_ECX + 0x58) <= (int)fVar15)) {
                (*pcVar13)(0xc000008c,1,0,0);
                pfVar10 = *(float **)(in_ECX + 0x54);
                pfVar11 = pfVar10;
              }
              else {
                pfVar10 = pfVar11 + (int)fVar15 * 0x11;
              }
              if (0 < (int)pfVar10[0xb]) {
                if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                  (*pcVar13)(0xc000008c,1,0,0);
                  pfVar11 = *(float **)(in_ECX + 0x54);
                  pfVar10 = pfVar11;
                }
                else {
                  pfVar10 = pfVar11 + iVar4 * 0x11;
                }
                fVar15 = pfVar10[9];
                if (((int)fVar15 < 0) || (*(int *)(in_ECX + 0x58) <= (int)fVar15)) {
                  (*pcVar13)(0xc000008c,1,0,0);
                  pfVar10 = *(float **)(in_ECX + 0x54);
                  pfVar11 = pfVar10;
                }
                else {
                  pfVar10 = pfVar11 + (int)fVar15 * 0x11;
                }
                if ((int)pfVar10[0xb] < 0x18) {
                  if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                    (*pcVar13)(0xc000008c,1,0,0);
                    pfVar10 = *(float **)(in_ECX + 0x54);
                    pfVar11 = pfVar10;
                  }
                  else {
                    pfVar10 = pfVar11 + iVar4 * 0x11;
                  }
                  if ((int)pfVar10[0xb] < 0x20) {
                    if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                      (*pcVar13)(0xc000008c,1,0,0);
                      pfVar10 = *(float **)(in_ECX + 0x54);
                      pfVar11 = pfVar10;
                    }
                    else {
                      pfVar10 = pfVar11 + iVar4 * 0x11;
                    }
                    if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                      (*pcVar13)(0xc000008c,1,0,0);
                      pfVar11 = *(float **)(in_ECX + 0x54);
                      pfVar9 = pfVar11;
                    }
                    else {
                      pfVar9 = pfVar11 + iVar4 * 0x11;
                    }
                    fVar15 = pfVar9[9];
                    if (((int)fVar15 < 0) || (*(int *)(in_ECX + 0x58) <= (int)fVar15)) {
                      (*pcVar13)(0xc000008c,1,0,0);
                      pfVar9 = *(float **)(in_ECX + 0x54);
                      pfVar11 = pfVar9;
                    }
                    else {
                      pfVar9 = pfVar11 + (int)fVar15 * 0x11;
                    }
                    fVar15 = *pfVar9;
                    fVar19 = *pfVar10;
                    fVar20 = pfVar9[1];
                    fVar1 = pfVar10[1];
                    fVar2 = pfVar9[2];
                    fVar3 = pfVar10[2];
                    if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                      (*pcVar13)(0xc000008c,1,0,0);
                      pfVar10 = *(float **)(in_ECX + 0x54);
                      pfVar11 = pfVar10;
                    }
                    else {
                      pfVar10 = pfVar11 + iVar4 * 0x11;
                    }
                    fVar15 = (pfVar10[3] * 80.0 + (fVar15 - fVar19) * 20.0) / 100.0;
                    fVar19 = (pfVar10[4] * 80.0 + (fVar20 - fVar1) * 20.0) / 100.0;
                    fVar20 = (pfVar10[5] * 80.0 + (fVar2 - fVar3) * 20.0) / 100.0;
                    if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                      (*pcVar13)(0xc000008c,1,0,0);
                      iVar8 = *(int *)(in_ECX + 0x54);
                      *(float *)(iVar8 + 0xc) = fVar15;
                      *(float *)(iVar8 + 0x10) = fVar19;
                      *(float *)(iVar8 + 0x14) = fVar20;
                    }
                    else {
                      pfVar11[iVar4 * 0x11 + 3] = fVar15;
                      pfVar11[iVar4 * 0x11 + 4] = fVar19;
                      pfVar11[iVar4 * 0x11 + 5] = fVar20;
                    }
                  }
                  else {
                    if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                      (*pcVar13)(0xc000008c,1,0,0);
                      pfVar10 = *(float **)(in_ECX + 0x54);
                      pfVar11 = pfVar10;
                    }
                    else {
                      pfVar10 = pfVar11 + iVar4 * 0x11;
                    }
                    if (pfVar10[0xb] == 4.48416e-44) {
                      if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                        (*pcVar13)(0xc000008c,1,0,0);
                        pfVar11 = *(float **)(in_ECX + 0x54);
                      }
                      else {
                        pfVar11 = pfVar11 + iVar4 * 0x11;
                      }
                      pfVar11[5] = 0.0;
                      pfVar11[4] = 0.0;
                      pfVar11[3] = 0.0;
                    }
                  }
                  DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
                  if ((DAT_00767980 >> 0x10 & 0x7fffU) < 3000) {
                    if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                      (*pcVar13)(0xc000008c,1,0,0);
                      iVar8 = *(int *)(in_ECX + 0x54);
                    }
                    else {
                      iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
                    }
                    *(undefined4 *)(iVar8 + 0x2c) = 0x3f;
                    if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                      (*pcVar13)(0xc000008c,1,0,0);
                      iVar8 = *(int *)(in_ECX + 0x54);
                    }
                    else {
                      iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
                    }
                    *(undefined4 *)(iVar8 + 0x28) = 0x3f000000;
                    if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                      (*pcVar13)(0xc000008c,1,0,0);
                      iVar8 = *(int *)(in_ECX + 0x54);
                    }
                    else {
                      iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
                    }
                    *(undefined4 *)(iVar8 + 0x28) = 0x3e99999a;
                    if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                      (*pcVar13)(0xc000008c,1,0,0);
                      iVar8 = *(int *)(in_ECX + 0x54);
                    }
                    else {
                      iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
                    }
                    *(undefined4 *)(iVar8 + 0x38) = 0xffffff;
                  }
                }
              }
            }
          }
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
          }
          *(undefined4 *)(iVar8 + 0x34) = 0xffe060;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
          }
          *(int *)(iVar8 + 0x2c) = *(int *)(iVar8 + 0x2c) + 1;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            iVar8 = *(int *)(in_ECX + 0x54);
            iVar5 = iVar8;
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
            iVar5 = *(int *)(in_ECX + 0x54);
          }
          if (*(int *)(iVar8 + 0x2c) < 0x18) {
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar5 = *(int *)(in_ECX + 0x54);
              iVar8 = iVar5;
            }
            else {
              iVar8 = iVar5 + iVar4 * 0x44;
            }
            iVar8 = 0x20 - *(int *)(iVar8 + 0x2c);
            uVar7 = iVar8 * 0x19;
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar5 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar5 = iVar5 + iVar4 * 0x44;
            }
            *(uint *)(iVar5 + 0x38) = (iVar8 * 0x1900 | uVar7) << 8 | uVar7;
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar8 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
            }
            *(float *)(iVar8 + 0x10) = *(float *)(iVar8 + 0x10) + 0.005;
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar8 = *(int *)(in_ECX + 0x54);
              iVar5 = iVar8;
            }
            else {
              iVar8 = *(int *)(in_ECX + 0x54);
              iVar5 = iVar8 + iVar4 * 0x44;
            }
            if ((8 - *(int *)(iVar5 + 0x2c)) * 0x20 < 1) {
              local_40 = (undefined4 *)0x0;
            }
            else if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar8 = *(int *)(in_ECX + 0x54);
              local_40 = (undefined4 *)((8 - *(int *)(iVar8 + 0x2c)) * 0x20);
            }
            else {
              local_40 = (undefined4 *)((8 - *(int *)(iVar8 + iVar4 * 0x44 + 0x2c)) * 0x20);
            }
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar8 = *(int *)(in_ECX + 0x54);
              iVar5 = iVar8;
            }
            else {
              iVar5 = iVar8 + iVar4 * 0x44;
            }
            if ((0x18 - *(int *)(iVar5 + 0x2c)) * 0x20 < 0x100) {
              if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                (*pcVar13)(0xc000008c,1,0,0);
                iVar8 = *(int *)(in_ECX + 0x54);
                iVar5 = (0x18 - *(int *)(iVar8 + 0x2c)) * 0x20;
              }
              else {
                iVar5 = (0x18 - *(int *)(iVar8 + iVar4 * 0x44 + 0x2c)) * 0x20;
              }
            }
            else {
              iVar5 = 0x100;
            }
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar8 = *(int *)(in_ECX + 0x54);
              iVar6 = iVar8;
            }
            else {
              iVar6 = iVar8 + iVar4 * 0x44;
            }
            if ((0x18 - *(int *)(iVar6 + 0x2c)) * 0x10 < 0x100) {
              if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
                (*pcVar13)(0xc000008c,1,0,0);
                iVar8 = *(int *)(in_ECX + 0x54);
                local_44 = (0x18 - *(int *)(iVar8 + 0x2c)) * 0x10;
              }
              else {
                local_44 = (0x18 - *(int *)(iVar8 + iVar4 * 0x44 + 0x2c)) * 0x10;
              }
            }
            else {
              local_44 = 0x100;
            }
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar8 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar8 = iVar8 + iVar4 * 0x44;
            }
            *(uint *)(iVar8 + 0x34) = (iVar5 << 8 | (uint)local_40) << 8 | local_44;
            iVar8 = FUN_00492f80();
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x58) <= iVar8)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar5 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar5 = *(int *)(in_ECX + 0x54) + iVar8 * 0x44;
            }
            iVar6 = iVar8 * 0x44;
            *(undefined4 *)(iVar5 + 0x28) = 0x3e99999a;
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x58) <= iVar8)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar5 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar5 = *(int *)(in_ECX + 0x54) + iVar6;
            }
            *(undefined4 *)(iVar5 + 0x3c) = 0x30002;
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x58) <= iVar8)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar5 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar5 = *(int *)(in_ECX + 0x54) + iVar6;
            }
            *(undefined4 *)(iVar5 + 0x2c) = 0x19;
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x58) <= iVar8)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar5 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar5 = *(int *)(in_ECX + 0x54) + iVar6;
            }
            *(undefined4 *)(iVar5 + 0x30) = 0;
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x58) <= iVar8)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar5 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar5 = *(int *)(in_ECX + 0x54) + iVar6;
            }
            *(undefined4 *)(iVar5 + 0x38) = 0;
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x58) <= iVar8)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar5 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar5 = *(int *)(in_ECX + 0x54) + iVar6;
            }
            *(undefined1 *)(iVar5 + 0x40) = 0;
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x58) <= iVar8)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar5 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar5 = *(int *)(in_ECX + 0x54) + iVar6;
            }
            *(undefined4 *)(iVar5 + 0x34) = 0xffe060;
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              puVar12 = *(undefined4 **)(in_ECX + 0x54);
              local_40 = puVar12;
            }
            else {
              puVar12 = *(undefined4 **)(in_ECX + 0x54);
              local_40 = puVar12 + iVar4 * 0x11;
            }
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x58) <= iVar8)) {
              (*pcVar13)(0xc000008c,1,0,0);
              puVar12 = *(undefined4 **)(in_ECX + 0x54);
            }
            else {
              puVar12 = puVar12 + iVar8 * 0x11;
            }
            *puVar12 = *local_40;
            puVar12[1] = local_40[1];
            puVar12[2] = local_40[2];
            pcVar13 = RaiseException_exref;
            if ((iVar8 < 0) || (*(int *)(in_ECX + 0x58) <= iVar8)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar6 = *(int *)(in_ECX + 0x54) + iVar6;
            }
            *(int *)(iVar6 + 0x24) = iVar4;
          }
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            (*pcVar13)(0xc000008c,1,0,0);
            iVar8 = *(int *)(in_ECX + 0x54);
            iVar5 = iVar8;
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar4 * 0x44;
            iVar5 = *(int *)(in_ECX + 0x54);
          }
          if (*(int *)(iVar8 + 0x2c) < 0x41) {
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              (*pcVar13)(0xc000008c,1,0,0);
              iVar5 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar5 = iVar5 + iVar4 * 0x44;
            }
            if (*(int *)(iVar5 + 0x2c) != 0x18) goto LAB_004ab4ae;
          }
          FUN_00493010(iVar4);
        }
      }
LAB_004ab4ae:
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

