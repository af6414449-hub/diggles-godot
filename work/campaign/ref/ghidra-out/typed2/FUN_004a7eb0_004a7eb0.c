
void FUN_004a7eb0(uint param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  CMap *pCVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int *piVar12;
  CHeightBlock **ppCVar13;
  float *pfVar14;
  int in_ECX;
  CHeightBlock *pCVar15;
  undefined4 *puVar16;
  code *pcVar17;
  byte *pbVar18;
  float in_XMM2_Da;
  undefined4 in_XMM3_Da;
  undefined4 in_XMM3_Db;
  uint local_c;
  
  pcVar17 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
      iVar6 = FUN_00592f10(PTR_0077241c);
      pbVar18 = (byte *)(iVar6 + 0x34);
      if (param_1 < 8) {
        pbVar18 = pbVar18 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar18 < 0x81) {
        DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
        uVar8 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar18 = (byte *)FUN_00423700(uVar8);
        if (*pbVar18 < 0x81) {
          DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar8 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar18 = (byte *)FUN_00423700(uVar8);
          if (*pbVar18 < 0x81) {
            DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar18 = (byte *)FUN_00423700(param_1);
            if (*pbVar18 < 0x81) goto LAB_004a8327;
          }
        }
      }
    }
    DAT_00772dd8 = (uint)ROUND((float)(double)CONCAT44(in_XMM3_Db,in_XMM3_Da));
    iVar6 = FUN_00492f80();
    if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar16 = *(undefined4 **)(in_ECX + 0x54);
    }
    else {
      puVar16 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
    }
    iVar10 = iVar6 * 0x44;
    *puVar16 = *(undefined4 *)(in_ECX + 0xc);
    puVar16[1] = *(undefined4 *)(in_ECX + 0x10);
    puVar16[2] = *(undefined4 *)(in_ECX + 0x14);
    iVar7 = DAT_00767980 * 0x343fd + 0x269ec3;
    DAT_00767980 = iVar7 * 0x343fd + 0x269ec3;
    uVar8 = DAT_00767980 >> 0x10;
    fVar1 = *(float *)(in_ECX + 0x18);
    fVar2 = *(float *)(in_ECX + 0x1c);
    fVar3 = *(float *)(in_ECX + 0x20);
    if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar9 = *(int *)(in_ECX + 0x54);
    }
    else {
      iVar9 = *(int *)(in_ECX + 0x54) + iVar10;
    }
    *(float *)(iVar9 + 0xc) = fVar1 + (float)(int)((iVar7 >> 0x10 & 0xfU) - 8) / 450.0;
    *(float *)(iVar9 + 0x10) = fVar2 + 0.0;
    *(float *)(iVar9 + 0x14) = fVar3 + (float)(int)((uVar8 & 0xf) - 8) / 450.0;
    if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar7 = *(int *)(in_ECX + 0x54);
    }
    else {
      iVar7 = *(int *)(in_ECX + 0x54) + iVar10;
    }
    *(undefined4 *)(iVar7 + 0x28) = 0x3ecccccd;
    DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
    uVar8 = DAT_00767980 >> 0x10;
    if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar7 = *(int *)(in_ECX + 0x54);
    }
    else {
      iVar7 = *(int *)(in_ECX + 0x54) + iVar10;
    }
    *(uint *)(iVar7 + 0x2c) = uVar8 & 0x1f;
    if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar7 = *(int *)(in_ECX + 0x54);
    }
    else {
      iVar7 = *(int *)(in_ECX + 0x54) + iVar10;
    }
    *(undefined4 *)(iVar7 + 0x30) = 0;
    if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar7 = *(int *)(in_ECX + 0x54);
    }
    else {
      iVar7 = *(int *)(in_ECX + 0x54) + iVar10;
    }
    *(undefined4 *)(iVar7 + 0x34) = 0xffffffff;
    if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar7 = *(int *)(in_ECX + 0x54);
    }
    else {
      iVar7 = *(int *)(in_ECX + 0x54) + iVar10;
    }
    *(undefined4 *)(iVar7 + 0x38) = 0;
    DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
    uVar8 = DAT_00767980 >> 0x10 & 0x7fff;
    if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar7 = *(int *)(in_ECX + 0x54);
    }
    else {
      iVar7 = *(int *)(in_ECX + 0x54) + iVar10;
    }
    *(uint *)(iVar7 + 0x3c) = uVar8 + (0x10000 - uVar8 / 6) * 6;
    if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar10 = *(int *)(in_ECX + 0x54);
    }
    else {
      iVar10 = *(int *)(in_ECX + 0x54) + iVar10;
    }
    *(undefined1 *)(iVar10 + 0x40) = 0;
  }
LAB_004a8327:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar6 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    do {
      if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
        (*pcVar17)(0xc000008c,1,0,0);
        pfVar14 = *(float **)(in_ECX + 0x54);
        pfVar11 = pfVar14;
      }
      else {
        pfVar14 = *(float **)(in_ECX + 0x54) + iVar6 * 0x11;
        pfVar11 = *(float **)(in_ECX + 0x54);
      }
      if (pfVar14[0xb] != -NAN) {
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          (*pcVar17)(0xc000008c,1,0,0);
          pfVar11 = *(float **)(in_ECX + 0x54);
          pfVar14 = pfVar11;
        }
        else {
          pfVar14 = pfVar11 + iVar6 * 0x11;
        }
        if ((((*pfVar14 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= *pfVar14)) ||
            (pfVar14[1] < PTR_0077241c->y0f + 1.0)) || (PTR_0077241c->y1f - 1.0 <= pfVar14[1])) {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            (*pcVar17)(0xc000008c,1,0,0);
            pfVar11 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar11 = pfVar11 + iVar6 * 0x11;
          }
          *pfVar11 = 2.0;
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            (*pcVar17)(0xc000008c,1,0,0);
            iVar10 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          *(undefined4 *)(iVar10 + 4) = 0x40000000;
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            (*pcVar17)(0xc000008c,1,0,0);
            iVar10 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          *(undefined4 *)(iVar10 + 0x2c) = 0xffffd8f0;
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          (*pcVar17)(0xc000008c,1,0,0);
          iVar10 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        }
        *(int *)(iVar10 + 0x2c) = *(int *)(iVar10 + 0x2c) + 1;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          (*pcVar17)(0xc000008c,1,0,0);
          iVar10 = *(int *)(in_ECX + 0x54);
          iVar7 = iVar10;
        }
        else {
          iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        if (*(char *)(iVar10 + 0x40) == '\0') {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            (*pcVar17)(0xc000008c,1,0,0);
            iVar7 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar7 = iVar7 + iVar6 * 0x44;
          }
          *(float *)(iVar7 + 0x30) = *(float *)(iVar7 + 0x30) + 0.2;
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            (*pcVar17)(0xc000008c,1,0,0);
            iVar10 = *(int *)(in_ECX + 0x54);
            iVar7 = iVar10;
          }
          else {
            iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
            iVar7 = *(int *)(in_ECX + 0x54);
          }
          fVar1 = *(float *)(iVar10 + 0x10);
          fVar2 = *(float *)(iVar10 + 0x14);
          fVar3 = *(float *)(iVar10 + 0xc);
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            (*pcVar17)(0xc000008c,1,0,0);
            pfVar14 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar14 = (float *)(iVar7 + iVar6 * 0x44);
          }
          pfVar14[1] = fVar1 * in_XMM2_Da + pfVar14[1];
          pfVar14[2] = fVar2 * in_XMM2_Da + pfVar14[2];
          *pfVar14 = in_XMM2_Da * fVar3 + *pfVar14;
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            (*pcVar17)(0xc000008c,1,0,0);
            iVar10 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          *(float *)(iVar10 + 0xc) = in_XMM2_Da * 0.0 + *(float *)(iVar10 + 0xc);
          *(float *)(iVar10 + 0x10) = in_XMM2_Da * 0.06 + *(float *)(iVar10 + 0x10);
          *(float *)(iVar10 + 0x14) = in_XMM2_Da * 0.0 + *(float *)(iVar10 + 0x14);
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            (*pcVar17)(0xc000008c,1,0,0);
            iVar10 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          iVar10 = (int)ROUND(*(float *)(iVar10 + 4) * 8.0);
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            DAT_00772dd8 = iVar10;
            (*pcVar17)(0xc000008c,1,0,0);
            pfVar14 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar14 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
          }
          DAT_00772dd8 = (uint)ROUND(*pfVar14 * 8.0);
          if (((((int)DAT_00772dd8 < PTR_0077241c->x0_8 + 0x21) ||
               (PTR_0077241c->x1_8 + -0x21 <= (int)DAT_00772dd8)) ||
              (iVar10 < PTR_0077241c->y0_8 + 0x21)) || (PTR_0077241c->y1_8 + -0x21 <= iVar10)) {
            FUN_00493010(iVar6);
          }
          else {
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              (*pcVar17)(0xc000008c,1,0,0);
              iVar10 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
            }
            uVar8 = (uint)ROUND(*(float *)(iVar10 + 4) * 8.0);
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              DAT_00772dd8 = uVar8;
              (*pcVar17)(0xc000008c,1,0,0);
              pfVar14 = *(float **)(in_ECX + 0x54);
            }
            else {
              pfVar14 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
            }
            pCVar5 = PTR_0077241c;
            fVar1 = *pfVar14;
            DAT_00772dd8 = (int)ROUND(fVar1 * 8.0);
            piVar12 = (int *)FUN_00592f10(PTR_0077241c);
            pcVar17 = RaiseException_exref;
            iVar10 = *piVar12;
            ppCVar13 = &pCVar5->heightBlocks->data;
            if ((iVar10 < 0) || (pCVar5->heightBlocks->count <= iVar10)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar15 = *ppCVar13;
            }
            else {
              pCVar15 = *ppCVar13 + iVar10;
            }
            bVar4 = pCVar15->heights[(uVar8 & 7) << 3 | (int)ROUND(fVar1 * 8.0) & 7U];
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar10 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
            }
            DAT_00772dd8 = (uint)ROUND(*(float *)(iVar10 + 8));
            if ((int)DAT_00772dd8 < (int)(uint)bVar4) {
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar10 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              *(undefined1 *)(iVar10 + 0x40) = 1;
              DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
              uVar8 = DAT_00767980 >> 0x10;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar10 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              local_c = 0;
              *(uint *)(iVar10 + 0x3c) = (uVar8 & 1) + 0x60006;
              do {
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  (*pcVar17)(0xc000008c,1,0,0);
                  iVar10 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                uVar8 = (uint)ROUND(*(float *)(iVar10 + 4) * 8.0);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = uVar8;
                  (*pcVar17)(0xc000008c,1,0,0);
                  pfVar14 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar14 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                fVar1 = *pfVar14;
                DAT_00772dd8 = (int)ROUND(fVar1 * 8.0);
                piVar12 = (int *)FUN_00592f10(PTR_0077241c);
                pcVar17 = RaiseException_exref;
                iVar10 = *piVar12;
                ppCVar13 = &pCVar5->heightBlocks->data;
                if ((iVar10 < 0) || (pCVar5->heightBlocks->count <= iVar10)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar15 = *ppCVar13;
                }
                else {
                  pCVar15 = *ppCVar13 + iVar10;
                }
                bVar4 = pCVar15->heights[(uVar8 & 7) << 3 | (int)ROUND(fVar1 * 8.0) & 7U];
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar10 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                DAT_00772dd8 = (uint)ROUND(*(float *)(iVar10 + 8));
                if ((int)(uint)bVar4 <= (int)DAT_00772dd8) break;
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar10 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                *(float *)(iVar10 + 4) = *(float *)(iVar10 + 4) - 0.1;
                local_c = local_c + 1;
              } while ((int)local_c < 0x28);
              if (9 < local_c) {
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x2c) = 100;
                }
                else {
                  *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x2c + iVar6 * 0x44) = 100;
                }
              }
            }
          }
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          (*pcVar17)(0xc000008c,1,0,0);
          iVar10 = *(int *)(in_ECX + 0x54);
          iVar7 = iVar10;
        }
        else {
          iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        if (0x32 < *(int *)(iVar10 + 0x2c)) {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            (*pcVar17)(0xc000008c,1,0,0);
            iVar7 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar7 = iVar7 + iVar6 * 0x44;
          }
          *(float *)(iVar7 + 0x28) = *(float *)(iVar7 + 0x28) * 0.9;
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          (*pcVar17)(0xc000008c,1,0,0);
          iVar10 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        }
        if (0x5f < *(int *)(iVar10 + 0x2c)) {
          FUN_00493010(iVar6);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

