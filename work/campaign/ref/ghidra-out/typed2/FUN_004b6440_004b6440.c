
void FUN_004b6440(uint param_1)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  CHeightBlockArray *pCVar4;
  CMap *pCVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  float *pfVar13;
  float *pfVar14;
  int in_ECX;
  CHeightBlock *pCVar15;
  int iVar16;
  undefined4 *puVar17;
  uint uVar18;
  float fVar19;
  float fVar20;
  double dVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float in_XMM2_Da;
  float fVar25;
  float local_44;
  float local_28;
  int local_20;
  
  local_44 = 0.0;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
      iVar6 = FUN_00592f10(PTR_0077241c);
      pbVar7 = (byte *)(iVar6 + 0x34);
      if (param_1 < 8) {
        pbVar7 = pbVar7 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar7 < 0x81) {
        DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc));
        uVar10 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar7 = (byte *)FUN_00423700(uVar10);
        if (*pbVar7 < 0x81) {
          DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar10 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar7 = (byte *)FUN_00423700(uVar10);
          if (*pbVar7 < 0x81) {
            DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar7 = (byte *)FUN_00423700(param_1);
            if (*pbVar7 < 0x81) goto LAB_004b6b7b;
          }
        }
      }
    }
    local_20 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar6 = FUN_00492f80();
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar17 = *(undefined4 **)(in_ECX + 0x54);
        }
        else {
          puVar17 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
        }
        iVar11 = iVar6 * 0x44;
        *puVar17 = *(undefined4 *)(in_ECX + 0xc);
        puVar17[1] = *(undefined4 *)(in_ECX + 0x10);
        puVar17[2] = *(undefined4 *)(in_ECX + 0x14);
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar9 = iVar8 * 0x343fd + 0x269ec3;
        fVar22 = (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 80.0;
        DAT_00767980 = iVar9 * 0x343fd + 0x269ec3;
        dVar21 = (double)(1.0 - fVar22 * 10.0);
        if (dVar21 < 0.0) {
          __libm_sse2_sqrt_precise();
        }
        else {
          dVar21 = SQRT(dVar21);
        }
        fVar23 = ((float)(int)((DAT_00767980 >> 0x10 & 0xfU) - 8) / 87.0) * (float)dVar21;
        fVar24 = *(float *)(in_ECX + 0x18) * *(float *)(in_ECX + 0x18) +
                 *(float *)(in_ECX + 0x20) * *(float *)(in_ECX + 0x20);
        fVar19 = local_44;
        if (fVar24 != 0.0) {
          dVar21 = (double)fVar24;
          if (dVar21 < 0.0) {
            __libm_sse2_sqrt_precise();
          }
          else {
            dVar21 = SQRT(dVar21);
          }
          fVar19 = 0.0;
          fVar24 = *(float *)(in_ECX + 0x18) / (float)dVar21;
          if (*(float *)(in_ECX + 0x20) <= 0.0) {
            fVar19 = local_44;
            if (fVar24 < 1.0) {
              if (-1.0 < fVar24) {
                FUN_0040b6e0();
                fVar19 = fVar24;
              }
              else {
                fVar19 = 3.1415927;
              }
            }
            fVar19 = -fVar19;
          }
          else if (fVar24 < 1.0) {
            if (-1.0 < fVar24) {
              fVar19 = fVar24;
              FUN_0040b6e0();
            }
            else {
              fVar19 = 3.1415927;
            }
          }
        }
        fVar19 = fVar19 + 3.1415927;
        fVar20 = fVar19;
        FUN_004089d0();
        FUN_004089f0();
        fVar25 = fVar23 * fVar19 + fVar20 * fVar22;
        fVar24 = *(float *)(in_ECX + 0x1c);
        fVar1 = *(float *)(in_ECX + 0x18);
        fVar2 = *(float *)(in_ECX + 0x20);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(float *)(iVar8 + 0xc) = (fVar19 * fVar22 - fVar23 * fVar20) + fVar1;
        *(float *)(iVar8 + 0x10) = (float)(int)((iVar9 >> 0x10 & 0xfU) - 8) / 85.0 + fVar24;
        *(float *)(iVar8 + 0x14) = fVar25 + fVar25 + fVar2;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar10 = DAT_00767980 >> 0x10;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(float *)(iVar8 + 0x28) = (float)((uVar10 & 0x7fff) % 10) / 25.0 + 0.8;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar10 = DAT_00767980 >> 0x10;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(uint *)(iVar8 + 0x2c) = uVar10 & 0x1f;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar10 = DAT_00767980 >> 0x10;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(float *)(iVar8 + 0x30) = (float)(uVar10 & 0x7fff) / 23768.0;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined4 *)(iVar8 + 0x34) = 0xffffffff;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined4 *)(iVar8 + 0x38) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar10 = DAT_00767980 >> 0x10 & 0x7fff;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(uint *)(iVar8 + 0x3c) = uVar10 + (0x10000 - uVar10 / 6) * 6;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined1 *)(iVar8 + 0x40) = 0;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar11;
        }
        *(undefined4 *)(iVar11 + 0x24) = 1;
        local_20 = local_20 + 1;
      } while (local_20 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004b6b7b:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar6 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    do {
      if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar11 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar11;
      }
      else {
        iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        iVar8 = *(int *)(in_ECX + 0x54);
      }
      if (*(int *)(iVar11 + 0x2c) != -10000) {
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar11;
        }
        else {
          iVar11 = iVar8 + iVar6 * 0x44;
        }
        fVar22 = *(float *)(iVar11 + 0x10);
        fVar19 = *(float *)(iVar11 + 0xc);
        fVar23 = *(float *)(iVar11 + 0x14);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar13 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar13 = (float *)(iVar8 + iVar6 * 0x44);
        }
        *pfVar13 = fVar19 * in_XMM2_Da + *pfVar13;
        pfVar13[2] = fVar23 * in_XMM2_Da + pfVar13[2];
        pfVar13[1] = pfVar13[1] + fVar22 * in_XMM2_Da;
        local_28 = 0.0;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar11;
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (*(float *)(iVar11 + 0xc) <= 0.0) {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar11 = *(int *)(in_ECX + 0x54);
            iVar8 = iVar11;
          }
          else {
            iVar11 = iVar8 + iVar6 * 0x44;
          }
          if (*(float *)(iVar11 + 0xc) <= 0.0 && *(float *)(iVar11 + 0xc) != 0.0) {
            local_28 = -1.0;
          }
        }
        else {
          local_28 = 1.0;
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar11;
        }
        else {
          iVar11 = iVar8 + iVar6 * 0x44;
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = iVar8 + iVar6 * 0x44;
        }
        fVar22 = *(float *)(iVar8 + 0xc) * *(float *)(iVar8 + 0xc) +
                 *(float *)(iVar8 + 0x10) * *(float *)(iVar8 + 0x10) +
                 *(float *)(iVar8 + 0x14) * *(float *)(iVar8 + 0x14);
        FUN_0040b7e0();
        *(float *)(iVar11 + 0x30) = fVar22 * local_28 + *(float *)(iVar11 + 0x30);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar13 = *(float **)(in_ECX + 0x54);
          pfVar14 = pfVar13;
        }
        else {
          pfVar13 = *(float **)(in_ECX + 0x54) + iVar6 * 0x11;
          pfVar14 = *(float **)(in_ECX + 0x54);
        }
        if ((((*pfVar13 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= *pfVar13)) ||
            (pfVar13[1] < PTR_0077241c->y0f + 1.0)) || (PTR_0077241c->y1f - 1.0 <= pfVar13[1])) {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar14 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar14 = pfVar14 + iVar6 * 0x11;
          }
          *pfVar14 = 2.0;
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar11 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          *(undefined4 *)(iVar11 + 4) = 0x40000000;
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar11 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          *(undefined4 *)(iVar11 + 0x2c) = 0xffffd8f0;
        }
        else {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar14 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar14 = pfVar14 + iVar6 * 0x11;
          }
          fVar22 = pfVar14[1];
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            DAT_00772dd8 = (int)ROUND(fVar22 * 8.0);
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar13 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar13 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
          }
          pCVar5 = PTR_0077241c;
          fVar19 = *pfVar13;
          DAT_00772dd8 = (int)ROUND(fVar19 * 8.0);
          piVar12 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar4 = pCVar5->heightBlocks;
          iVar11 = *piVar12;
          if ((iVar11 < 0) || (pCVar4->count <= iVar11)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar15 = pCVar4->data;
          }
          else {
            pCVar15 = pCVar4->data + iVar11;
          }
          bVar3 = pCVar15->heights
                  [((int)ROUND(fVar22 * 8.0) & 7U) << 3 | (int)ROUND(fVar19 * 8.0) & 7U];
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar11 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          DAT_00772dd8 = (uint)ROUND(*(float *)(iVar11 + 8));
          if ((int)DAT_00772dd8 < (int)(uint)bVar3) {
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar13 = *(float **)(in_ECX + 0x54);
              pfVar14 = pfVar13;
            }
            else {
              pfVar13 = *(float **)(in_ECX + 0x54) + iVar6 * 0x11;
              pfVar14 = *(float **)(in_ECX + 0x54);
            }
            if (0 < (int)pfVar13[9]) {
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar13 = *(float **)(in_ECX + 0x54);
                pfVar14 = pfVar13;
              }
              else {
                pfVar13 = pfVar14 + iVar6 * 0x11;
              }
              if (0.010000001 <
                  pfVar13[3] * pfVar13[3] + pfVar13[4] * pfVar13[4] + pfVar13[5] * pfVar13[5]) {
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar14 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar14 = pfVar14 + iVar6 * 0x11;
                }
                pfVar14[9] = (float)((int)pfVar14[9] + -1);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar11 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                uVar10 = (uint)ROUND(*(float *)(iVar11 + 4) * 8.0);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = uVar10;
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar13 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar13 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                uVar18 = (uint)ROUND(*pfVar13 * 8.0 - 6.0);
                DAT_00772dd8 = uVar18;
                piVar12 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar4 = pCVar5->heightBlocks;
                iVar11 = *piVar12;
                if ((iVar11 < 0) || (pCVar4->count <= iVar11)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar15 = pCVar4->data;
                }
                else {
                  pCVar15 = pCVar4->data + iVar11;
                }
                bVar3 = pCVar15->heights[(uVar10 & 7) << 3 | uVar18 & 7];
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar11 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                uVar10 = (uint)ROUND(*(float *)(iVar11 + 4) * 8.0);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = uVar10;
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar13 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar13 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                uVar18 = (uint)ROUND(*pfVar13 * 8.0 + 6.0);
                DAT_00772dd8 = uVar18;
                piVar12 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar4 = pCVar5->heightBlocks;
                iVar11 = *piVar12;
                if ((iVar11 < 0) || (pCVar4->count <= iVar11)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar15 = pCVar4->data;
                }
                else {
                  pCVar15 = pCVar4->data + iVar11;
                }
                uVar10 = (uint)bVar3 - (uint)pCVar15->heights[(uVar10 & 7) << 3 | uVar18 & 7];
                uVar18 = (int)uVar10 >> 0x1f;
                iVar11 = (uVar10 ^ uVar18) - uVar18;
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar8 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                uVar10 = (uint)ROUND(*(float *)(iVar8 + 4) * 8.0 - 6.0);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = uVar10;
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar13 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar13 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                fVar22 = *pfVar13;
                DAT_00772dd8 = (int)ROUND(fVar22 * 8.0);
                piVar12 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar4 = pCVar5->heightBlocks;
                iVar8 = *piVar12;
                if ((iVar8 < 0) || (pCVar4->count <= iVar8)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar15 = pCVar4->data;
                }
                else {
                  pCVar15 = pCVar4->data + iVar8;
                }
                bVar3 = pCVar15->heights[(uVar10 & 7) << 3 | (int)ROUND(fVar22 * 8.0) & 7U];
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar8 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                uVar10 = (uint)ROUND(*(float *)(iVar8 + 4) * 8.0 + 6.0);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = uVar10;
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar13 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar13 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                fVar22 = *pfVar13;
                DAT_00772dd8 = (int)ROUND(fVar22 * 8.0);
                piVar12 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar4 = pCVar5->heightBlocks;
                iVar8 = *piVar12;
                if ((iVar8 < 0) || (pCVar4->count <= iVar8)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar15 = pCVar4->data;
                }
                else {
                  pCVar15 = pCVar4->data + iVar8;
                }
                uVar10 = (uint)bVar3 -
                         (uint)pCVar15->heights[(uVar10 & 7) << 3 | (int)ROUND(fVar22 * 8.0) & 7U];
                uVar18 = (int)uVar10 >> 0x1f;
                iVar8 = (uVar10 ^ uVar18) - uVar18;
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar9 = *(int *)(in_ECX + 0x54);
                  iVar16 = iVar9;
                }
                else {
                  iVar9 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                  iVar16 = *(int *)(in_ECX + 0x54);
                }
                fVar22 = *(float *)(iVar9 + 0xc);
                fVar19 = *(float *)(iVar9 + 0x10);
                fVar23 = *(float *)(iVar9 + 0x14);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar13 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar13 = (float *)(iVar16 + iVar6 * 0x44);
                }
                *pfVar13 = *pfVar13 - fVar22 * in_XMM2_Da;
                pfVar13[1] = pfVar13[1] - fVar19 * in_XMM2_Da;
                pfVar13[2] = pfVar13[2] - fVar23 * in_XMM2_Da;
                if ((iVar11 < 3) && (iVar8 < 3)) {
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar11 = *(int *)(in_ECX + 0x54);
                    iVar8 = iVar11;
                  }
                  else {
                    iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar8 = *(int *)(in_ECX + 0x54);
                  }
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar8 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar8 = iVar8 + iVar6 * 0x44;
                  }
                  *(uint *)(iVar8 + 0x14) = *(uint *)(iVar11 + 0x14) ^ 0x80000000;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar11 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                  }
                  *(float *)(iVar11 + 0xc) = *(float *)(iVar11 + 0xc) * 0.7;
                  *(float *)(iVar11 + 0x10) = *(float *)(iVar11 + 0x10) * 0.7;
                  *(float *)(iVar11 + 0x14) = *(float *)(iVar11 + 0x14) * 0.7;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar11 = *(int *)(in_ECX + 0x54);
                    iVar8 = iVar11;
                  }
                  else {
                    iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar8 = *(int *)(in_ECX + 0x54);
                  }
                  fVar22 = *(float *)(iVar11 + 0xc);
                  fVar19 = *(float *)(iVar11 + 0x10);
                  fVar23 = *(float *)(iVar11 + 0x14);
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar13 = *(float **)(in_ECX + 0x54);
                  }
                  else {
                    pfVar13 = (float *)(iVar8 + iVar6 * 0x44);
                  }
                  *pfVar13 = *pfVar13 + fVar22 * in_XMM2_Da;
                  pfVar13[1] = fVar19 * in_XMM2_Da + pfVar13[1];
                  pfVar13[2] = pfVar13[2] + fVar23 * in_XMM2_Da;
                }
                else if (iVar11 < iVar8) {
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar11 = *(int *)(in_ECX + 0x54);
                    iVar8 = iVar11;
                  }
                  else {
                    iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar8 = *(int *)(in_ECX + 0x54);
                  }
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar8 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar8 = iVar8 + iVar6 * 0x44;
                  }
                  *(uint *)(iVar8 + 0x10) = *(uint *)(iVar11 + 0x10) ^ 0x80000000;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar11 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                  }
                  *(float *)(iVar11 + 0xc) = *(float *)(iVar11 + 0xc) * 0.5;
                  *(float *)(iVar11 + 0x10) = *(float *)(iVar11 + 0x10) * 0.5;
                  *(float *)(iVar11 + 0x14) = *(float *)(iVar11 + 0x14) * 0.5;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar11 = *(int *)(in_ECX + 0x54);
                    iVar8 = iVar11;
                  }
                  else {
                    iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar8 = *(int *)(in_ECX + 0x54);
                  }
                  fVar22 = *(float *)(iVar11 + 0xc);
                  fVar19 = *(float *)(iVar11 + 0x10);
                  fVar23 = *(float *)(iVar11 + 0x14);
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar13 = *(float **)(in_ECX + 0x54);
                  }
                  else {
                    pfVar13 = (float *)(iVar8 + iVar6 * 0x44);
                  }
                  *pfVar13 = *pfVar13 + fVar22 * in_XMM2_Da;
                  pfVar13[1] = fVar19 * in_XMM2_Da + pfVar13[1];
                  pfVar13[2] = pfVar13[2] + fVar23 * in_XMM2_Da;
                }
                else if (iVar8 < iVar11) {
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar11 = *(int *)(in_ECX + 0x54);
                    iVar8 = iVar11;
                  }
                  else {
                    iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar8 = *(int *)(in_ECX + 0x54);
                  }
                  uVar10 = *(uint *)(iVar11 + 0xc);
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar8 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar8 = iVar8 + iVar6 * 0x44;
                  }
                  *(uint *)(iVar8 + 0xc) = uVar10 ^ 0x80000000;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar11 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                  }
                  *(float *)(iVar11 + 0xc) = *(float *)(iVar11 + 0xc) * 0.7;
                  *(float *)(iVar11 + 0x10) = *(float *)(iVar11 + 0x10) * 0.7;
                  *(float *)(iVar11 + 0x14) = *(float *)(iVar11 + 0x14) * 0.7;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar11 = *(int *)(in_ECX + 0x54);
                    iVar8 = iVar11;
                  }
                  else {
                    iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar8 = *(int *)(in_ECX + 0x54);
                  }
                  fVar22 = *(float *)(iVar11 + 0xc);
                  fVar19 = *(float *)(iVar11 + 0x14);
                  fVar23 = *(float *)(iVar11 + 0x10);
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar13 = *(float **)(in_ECX + 0x54);
                  }
                  else {
                    pfVar13 = (float *)(iVar8 + iVar6 * 0x44);
                  }
                  *pfVar13 = *pfVar13 + fVar22 * in_XMM2_Da;
                  pfVar13[2] = fVar19 * in_XMM2_Da + pfVar13[2];
                  pfVar13[1] = pfVar13[1] + fVar23 * in_XMM2_Da;
                }
                else if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x24) = 0;
                }
                else {
                  *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x24 + iVar6 * 0x44) = 0;
                }
                goto LAB_004b7f2f;
              }
            }
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar13 = *(float **)(in_ECX + 0x54);
              pfVar14 = pfVar13;
            }
            else {
              pfVar13 = pfVar14 + iVar6 * 0x11;
            }
            if (-1 < (int)pfVar13[9]) {
              do {
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar14 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar14 = pfVar14 + iVar6 * 0x11;
                }
                fVar22 = pfVar14[1];
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = (int)ROUND(fVar22 * 8.0);
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar13 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar13 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                fVar19 = *pfVar13;
                DAT_00772dd8 = (int)ROUND(fVar19 * 8.0);
                piVar12 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar4 = pCVar5->heightBlocks;
                iVar11 = *piVar12;
                if ((iVar11 < 0) || (pCVar4->count <= iVar11)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar15 = pCVar4->data;
                }
                else {
                  pCVar15 = pCVar4->data + iVar11;
                }
                bVar3 = pCVar15->heights
                        [((int)ROUND(fVar22 * 8.0) & 7U) << 3 | (int)ROUND(fVar19 * 8.0) & 7U];
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar11 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                DAT_00772dd8 = (uint)ROUND(*(float *)(iVar11 + 8));
                if ((int)(uint)bVar3 <= (int)DAT_00772dd8) goto LAB_004b7da8;
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar11 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                *(float *)(iVar11 + 4) = *(float *)(iVar11 + 4) - 0.125;
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar14 = *(float **)(in_ECX + 0x54);
                  pfVar13 = pfVar14;
                }
                else {
                  pfVar14 = *(float **)(in_ECX + 0x54);
                  pfVar13 = pfVar14 + iVar6 * 0x11;
                }
              } while ((((PTR_0077241c->x0f + 1.0 <= *pfVar13) &&
                        (*pfVar13 < PTR_0077241c->x1f - 1.0)) &&
                       (PTR_0077241c->y0f + 1.0 <= pfVar13[1])) &&
                      (pfVar13[1] < PTR_0077241c->y1f - 1.0));
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar14 = *(float **)(in_ECX + 0x54);
              }
              else {
                pfVar14 = pfVar14 + iVar6 * 0x11;
              }
              *pfVar14 = 2.0;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar11 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              *(undefined4 *)(iVar11 + 4) = 0x40000000;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar11 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              *(undefined4 *)(iVar11 + 0x2c) = 0xffffd8f0;
LAB_004b7da8:
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar11 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              *(undefined4 *)(iVar11 + 0x14) = 0;
              *(undefined4 *)(iVar11 + 0x10) = 0;
              *(undefined4 *)(iVar11 + 0xc) = 0;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar11 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              *(undefined1 *)(iVar11 + 0x40) = 1;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar11 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              *(float *)(iVar11 + 0x28) = *(float *)(iVar11 + 0x28) * 0.75;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x24) = 0xffffffff;
              }
              else {
                *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x24 + iVar6 * 0x44) = 0xffffffff;
              }
            }
          }
        }
LAB_004b7f2f:
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar11;
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (-1 < *(int *)(iVar11 + 0x24)) {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = iVar8 + iVar6 * 0x44;
          }
          uVar10 = (uint)ROUND(*(float *)(iVar8 + 4) * 8.0 + 1.0);
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            DAT_00772dd8 = uVar10;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar13 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar13 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
          }
          pCVar5 = PTR_0077241c;
          fVar22 = *pfVar13;
          DAT_00772dd8 = (int)ROUND(fVar22 * 8.0);
          piVar12 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar4 = pCVar5->heightBlocks;
          iVar11 = *piVar12;
          if ((iVar11 < 0) || (pCVar4->count <= iVar11)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar15 = pCVar4->data;
          }
          else {
            pCVar15 = pCVar4->data + iVar11;
          }
          bVar3 = pCVar15->heights[(uVar10 & 7) << 3 | (int)ROUND(fVar22 * 8.0) & 7U];
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar11 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          DAT_00772dd8 = (uint)ROUND(*(float *)(iVar11 + 8));
          if ((int)(uint)bVar3 <= (int)DAT_00772dd8) {
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar11 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
            }
            *(float *)(iVar11 + 0xc) = in_XMM2_Da * 0.0 + *(float *)(iVar11 + 0xc);
            *(float *)(iVar11 + 0x14) = in_XMM2_Da * 0.0 + *(float *)(iVar11 + 0x14);
            *(float *)(iVar11 + 0x10) = *(float *)(iVar11 + 0x10) + in_XMM2_Da * 0.1;
          }
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        }
        *(int *)(iVar11 + 0x2c) = *(int *)(iVar11 + 0x2c) + 1;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        }
        if (100 < *(int *)(iVar11 + 0x2c)) {
          FUN_00493010(iVar6);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

