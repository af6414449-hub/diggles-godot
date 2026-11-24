
void FUN_004af7e0(uint param_1)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  CHeightBlockArray *pCVar4;
  CMap *pCVar5;
  int iVar6;
  byte *pbVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  float *pfVar14;
  int in_ECX;
  uint uVar15;
  CHeightBlock *pCVar16;
  uint uVar17;
  double dVar18;
  float fVar19;
  float in_XMM2_Da;
  float local_20;
  int local_18;
  int local_10;
  
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
        uVar15 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar7 = (byte *)FUN_00423700(uVar15);
        if (*pbVar7 < 0x81) {
          DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar15 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar7 = (byte *)FUN_00423700(uVar15);
          if (*pbVar7 < 0x81) {
            DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar7 = (byte *)FUN_00423700(param_1);
            if (*pbVar7 < 0x81) goto LAB_004afd8a;
          }
        }
      }
    }
    local_10 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar6 = FUN_00492f80();
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        fVar19 = *(float *)(in_ECX + 0xc);
        fVar1 = *(float *)(in_ECX + 0x14);
        uVar15 = DAT_00767980 >> 0x10;
        fVar2 = *(float *)(in_ECX + 0x10);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar8 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar8 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
        }
        iVar12 = iVar6 * 0x44;
        *pfVar8 = fVar19 + (float)(int)((uVar15 & 0xf) - 8) * 0.0078125;
        pfVar8[1] = fVar2 + 0.0;
        pfVar8[2] = fVar1 + 0.0;
        iVar9 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar10 = iVar9 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar10 * 0x343fd + 0x269ec3;
        uVar15 = DAT_00767980 >> 0x10;
        fVar19 = *(float *)(in_ECX + 0x20);
        fVar1 = *(float *)(in_ECX + 0x18);
        fVar2 = *(float *)(in_ECX + 0x1c);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(float *)(iVar11 + 0xc) = (float)(int)((iVar9 >> 0x10 & 0xfU) - 8) / 430.0 + fVar1;
        *(float *)(iVar11 + 0x10) = (float)(int)((iVar10 >> 0x10 & 0xfU) - 8) / 435.0 + fVar2;
        *(float *)(iVar11 + 0x14) = fVar19 + (float)(int)((uVar15 & 0xf) - 8) / 337.0;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined4 *)(iVar9 + 0x28) = 0x3f19999a;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar15 = DAT_00767980 >> 0x10;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_18 = *(int *)(in_ECX + 0x54);
        }
        else {
          local_18 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(uint *)(local_18 + 0x2c) = uVar15 & 0x1f;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar15 = DAT_00767980 >> 0x10;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(float *)(iVar9 + 0x30) = (float)(uVar15 & 0x7fff) / 23768.0;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined4 *)(iVar9 + 0x34) = 0xffff00;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined4 *)(iVar9 + 0x38) = 0;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined4 *)(iVar9 + 0x3c) = 0x40001;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined1 *)(iVar9 + 0x40) = 0;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined4 *)(iVar12 + 0x24) = 4;
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004afd8a:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar6 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    do {
      if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar12 = *(int *)(in_ECX + 0x54);
        iVar9 = iVar12;
      }
      else {
        iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        iVar9 = *(int *)(in_ECX + 0x54);
      }
      if (*(int *)(iVar12 + 0x2c) != -10000) {
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar12;
        }
        else {
          iVar12 = iVar9 + iVar6 * 0x44;
        }
        fVar19 = *(float *)(iVar12 + 0xc);
        fVar1 = *(float *)(iVar12 + 0x10);
        fVar2 = *(float *)(iVar12 + 0x14);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar8 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar8 = (float *)(iVar9 + iVar6 * 0x44);
        }
        *pfVar8 = fVar19 * in_XMM2_Da + *pfVar8;
        pfVar8[1] = fVar1 * in_XMM2_Da + pfVar8[1];
        pfVar8[2] = pfVar8[2] + fVar2 * in_XMM2_Da;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
          local_18 = iVar12;
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          local_18 = *(int *)(in_ECX + 0x54);
        }
        local_20 = *(float *)(iVar12 + 0xc);
        fVar19 = local_20 * local_20 + *(float *)(iVar12 + 0x10) * *(float *)(iVar12 + 0x10);
        if (fVar19 == 0.0) {
          local_20 = 0.0;
        }
        else {
          dVar18 = (double)fVar19;
          if (dVar18 < 0.0) {
            __libm_sse2_sqrt_precise();
          }
          else {
            dVar18 = SQRT(dVar18);
          }
          local_20 = local_20 / (float)dVar18;
          if (*(float *)(iVar12 + 0x10) <= 0.0) {
            if (local_20 < 1.0) {
              if (-1.0 < local_20) {
                FUN_0040b6e0();
              }
              else {
                local_20 = 3.1415927;
              }
            }
            else {
              local_20 = 0.0;
            }
            local_20 = -local_20;
          }
          else if (1.0 <= local_20) {
            local_20 = 0.0;
          }
          else if (-1.0 < local_20) {
            FUN_0040b6e0();
          }
          else {
            local_20 = 3.1415927;
          }
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_18 = *(int *)(in_ECX + 0x54);
        }
        else {
          local_18 = local_18 + iVar6 * 0x44;
        }
        *(float *)(local_18 + 0x30) = 0.7853982 - local_20;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar8 = *(float **)(in_ECX + 0x54);
          pfVar14 = pfVar8;
        }
        else {
          pfVar8 = *(float **)(in_ECX + 0x54) + iVar6 * 0x11;
          pfVar14 = *(float **)(in_ECX + 0x54);
        }
        if ((((*pfVar8 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= *pfVar8)) ||
            (pfVar8[1] < PTR_0077241c->y0f + 1.0)) || (PTR_0077241c->y1f - 1.0 <= pfVar8[1])) {
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
            iVar12 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          *(undefined4 *)(iVar12 + 4) = 0x40000000;
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar12 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          *(undefined4 *)(iVar12 + 0x2c) = 0xffffd8f0;
        }
        else {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar14 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar14 = pfVar14 + iVar6 * 0x11;
          }
          fVar19 = pfVar14[1];
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            DAT_00772dd8 = (int)ROUND(fVar19 * 8.0);
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar8 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar8 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
          }
          pCVar5 = PTR_0077241c;
          fVar1 = *pfVar8;
          DAT_00772dd8 = (int)ROUND(fVar1 * 8.0);
          piVar13 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar4 = pCVar5->heightBlocks;
          iVar12 = *piVar13;
          if ((iVar12 < 0) || (pCVar4->count <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar16 = pCVar4->data;
          }
          else {
            pCVar16 = pCVar4->data + iVar12;
          }
          bVar3 = pCVar16->heights
                  [((int)ROUND(fVar19 * 8.0) & 7U) << 3 | (int)ROUND(fVar1 * 8.0) & 7U];
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar12 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          DAT_00772dd8 = (uint)ROUND(*(float *)(iVar12 + 8));
          if ((int)DAT_00772dd8 < (int)(uint)bVar3) {
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar8 = *(float **)(in_ECX + 0x54);
              pfVar14 = pfVar8;
            }
            else {
              pfVar8 = *(float **)(in_ECX + 0x54) + iVar6 * 0x11;
              pfVar14 = *(float **)(in_ECX + 0x54);
            }
            if (0 < (int)pfVar8[9]) {
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar8 = *(float **)(in_ECX + 0x54);
                pfVar14 = pfVar8;
              }
              else {
                pfVar8 = pfVar14 + iVar6 * 0x11;
              }
              if (0.010000001 <
                  pfVar8[3] * pfVar8[3] + pfVar8[4] * pfVar8[4] + pfVar8[5] * pfVar8[5]) {
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
                  iVar12 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                uVar15 = (uint)ROUND(*(float *)(iVar12 + 4) * 8.0);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = uVar15;
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar8 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar8 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                uVar17 = (uint)ROUND(*pfVar8 * 8.0 - 6.0);
                DAT_00772dd8 = uVar17;
                piVar13 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar4 = pCVar5->heightBlocks;
                iVar12 = *piVar13;
                if ((iVar12 < 0) || (pCVar4->count <= iVar12)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar16 = pCVar4->data;
                }
                else {
                  pCVar16 = pCVar4->data + iVar12;
                }
                bVar3 = pCVar16->heights[(uVar15 & 7) << 3 | uVar17 & 7];
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar12 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                uVar15 = (uint)ROUND(*(float *)(iVar12 + 4) * 8.0);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = uVar15;
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar8 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar8 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                uVar17 = (uint)ROUND(*pfVar8 * 8.0 + 6.0);
                DAT_00772dd8 = uVar17;
                piVar13 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar4 = pCVar5->heightBlocks;
                iVar12 = *piVar13;
                if ((iVar12 < 0) || (pCVar4->count <= iVar12)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar16 = pCVar4->data;
                }
                else {
                  pCVar16 = pCVar4->data + iVar12;
                }
                uVar15 = (uint)bVar3 - (uint)pCVar16->heights[(uVar15 & 7) << 3 | uVar17 & 7];
                uVar17 = (int)uVar15 >> 0x1f;
                iVar12 = (uVar15 ^ uVar17) - uVar17;
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar9 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar9 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                uVar15 = (uint)ROUND(*(float *)(iVar9 + 4) * 8.0 - 6.0);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = uVar15;
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar8 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar8 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                fVar19 = *pfVar8;
                DAT_00772dd8 = (int)ROUND(fVar19 * 8.0);
                piVar13 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar4 = pCVar5->heightBlocks;
                iVar9 = *piVar13;
                if ((iVar9 < 0) || (pCVar4->count <= iVar9)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar16 = pCVar4->data;
                }
                else {
                  pCVar16 = pCVar4->data + iVar9;
                }
                bVar3 = pCVar16->heights[(uVar15 & 7) << 3 | (int)ROUND(fVar19 * 8.0) & 7U];
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar9 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar9 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                uVar15 = (uint)ROUND(*(float *)(iVar9 + 4) * 8.0 + 6.0);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = uVar15;
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar8 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar8 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                fVar19 = *pfVar8;
                DAT_00772dd8 = (int)ROUND(fVar19 * 8.0);
                piVar13 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar4 = pCVar5->heightBlocks;
                iVar9 = *piVar13;
                if ((iVar9 < 0) || (pCVar4->count <= iVar9)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar16 = pCVar4->data;
                }
                else {
                  pCVar16 = pCVar4->data + iVar9;
                }
                uVar15 = (uint)bVar3 -
                         (uint)pCVar16->heights[(uVar15 & 7) << 3 | (int)ROUND(fVar19 * 8.0) & 7U];
                uVar17 = (int)uVar15 >> 0x1f;
                iVar9 = (uVar15 ^ uVar17) - uVar17;
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar10 = *(int *)(in_ECX + 0x54);
                  iVar11 = iVar10;
                }
                else {
                  iVar10 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                  iVar11 = *(int *)(in_ECX + 0x54);
                }
                fVar19 = *(float *)(iVar10 + 0xc);
                fVar1 = *(float *)(iVar10 + 0x10);
                fVar2 = *(float *)(iVar10 + 0x14);
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar8 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar8 = (float *)(iVar11 + iVar6 * 0x44);
                }
                *pfVar8 = *pfVar8 - fVar19 * in_XMM2_Da;
                pfVar8[1] = pfVar8[1] - fVar1 * in_XMM2_Da;
                pfVar8[2] = pfVar8[2] - fVar2 * in_XMM2_Da;
                if ((iVar12 < 3) && (iVar9 < 3)) {
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar12 = *(int *)(in_ECX + 0x54);
                    iVar9 = iVar12;
                  }
                  else {
                    iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar9 = *(int *)(in_ECX + 0x54);
                  }
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar9 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar9 = iVar9 + iVar6 * 0x44;
                  }
                  *(uint *)(iVar9 + 0x14) = *(uint *)(iVar12 + 0x14) ^ 0x80000000;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar12 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                  }
                  *(float *)(iVar12 + 0xc) = *(float *)(iVar12 + 0xc) * 0.7;
                  *(float *)(iVar12 + 0x10) = *(float *)(iVar12 + 0x10) * 0.7;
                  *(float *)(iVar12 + 0x14) = *(float *)(iVar12 + 0x14) * 0.7;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar12 = *(int *)(in_ECX + 0x54);
                    iVar9 = iVar12;
                  }
                  else {
                    iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar9 = *(int *)(in_ECX + 0x54);
                  }
                  fVar19 = *(float *)(iVar12 + 0xc);
                  fVar1 = *(float *)(iVar12 + 0x10);
                  fVar2 = *(float *)(iVar12 + 0x14);
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar8 = *(float **)(in_ECX + 0x54);
                  }
                  else {
                    pfVar8 = (float *)(iVar9 + iVar6 * 0x44);
                  }
                  *pfVar8 = *pfVar8 + fVar19 * in_XMM2_Da;
                  pfVar8[1] = pfVar8[1] + fVar1 * in_XMM2_Da;
                  pfVar8[2] = pfVar8[2] + fVar2 * in_XMM2_Da;
                }
                else if (iVar12 < iVar9) {
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar12 = *(int *)(in_ECX + 0x54);
                    iVar9 = iVar12;
                  }
                  else {
                    iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar9 = *(int *)(in_ECX + 0x54);
                  }
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar9 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar9 = iVar9 + iVar6 * 0x44;
                  }
                  *(uint *)(iVar9 + 0x10) = *(uint *)(iVar12 + 0x10) ^ 0x80000000;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar12 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                  }
                  *(float *)(iVar12 + 0xc) = *(float *)(iVar12 + 0xc) * 0.5;
                  *(float *)(iVar12 + 0x10) = *(float *)(iVar12 + 0x10) * 0.5;
                  *(float *)(iVar12 + 0x14) = *(float *)(iVar12 + 0x14) * 0.5;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar12 = *(int *)(in_ECX + 0x54);
                    iVar9 = iVar12;
                  }
                  else {
                    iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar9 = *(int *)(in_ECX + 0x54);
                  }
                  fVar19 = *(float *)(iVar12 + 0xc);
                  fVar1 = *(float *)(iVar12 + 0x14);
                  fVar2 = *(float *)(iVar12 + 0x10);
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar8 = *(float **)(in_ECX + 0x54);
                  }
                  else {
                    pfVar8 = (float *)(iVar9 + iVar6 * 0x44);
                  }
                  *pfVar8 = *pfVar8 + fVar19 * in_XMM2_Da;
                  pfVar8[2] = fVar1 * in_XMM2_Da + pfVar8[2];
                  pfVar8[1] = pfVar8[1] + fVar2 * in_XMM2_Da;
                }
                else if (iVar9 < iVar12) {
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar12 = *(int *)(in_ECX + 0x54);
                    iVar9 = iVar12;
                  }
                  else {
                    iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar9 = *(int *)(in_ECX + 0x54);
                  }
                  uVar15 = *(uint *)(iVar12 + 0xc);
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar9 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar9 = iVar9 + iVar6 * 0x44;
                  }
                  *(uint *)(iVar9 + 0xc) = uVar15 ^ 0x80000000;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar12 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                  }
                  *(float *)(iVar12 + 0xc) = *(float *)(iVar12 + 0xc) * 0.7;
                  *(float *)(iVar12 + 0x10) = *(float *)(iVar12 + 0x10) * 0.7;
                  *(float *)(iVar12 + 0x14) = *(float *)(iVar12 + 0x14) * 0.7;
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar12 = *(int *)(in_ECX + 0x54);
                    iVar9 = iVar12;
                  }
                  else {
                    iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar9 = *(int *)(in_ECX + 0x54);
                  }
                  fVar19 = *(float *)(iVar12 + 0xc);
                  fVar1 = *(float *)(iVar12 + 0x10);
                  fVar2 = *(float *)(iVar12 + 0x14);
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar8 = *(float **)(in_ECX + 0x54);
                  }
                  else {
                    pfVar8 = (float *)(iVar9 + iVar6 * 0x44);
                  }
                  *pfVar8 = *pfVar8 + fVar19 * in_XMM2_Da;
                  pfVar8[1] = fVar1 * in_XMM2_Da + pfVar8[1];
                  pfVar8[2] = fVar2 * in_XMM2_Da + pfVar8[2];
                }
                else if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x24) = 0;
                }
                else {
                  *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x24 + iVar6 * 0x44) = 0;
                }
                goto LAB_004b1101;
              }
            }
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar8 = *(float **)(in_ECX + 0x54);
              pfVar14 = pfVar8;
            }
            else {
              pfVar8 = pfVar14 + iVar6 * 0x11;
            }
            if (-1 < (int)pfVar8[9]) {
              do {
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar14 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar14 = pfVar14 + iVar6 * 0x11;
                }
                fVar19 = pfVar14[1];
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  DAT_00772dd8 = (int)ROUND(fVar19 * 8.0);
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar8 = *(float **)(in_ECX + 0x54);
                }
                else {
                  pfVar8 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
                }
                pCVar5 = PTR_0077241c;
                fVar1 = *pfVar8;
                DAT_00772dd8 = (int)ROUND(fVar1 * 8.0);
                piVar13 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar4 = pCVar5->heightBlocks;
                iVar12 = *piVar13;
                if ((iVar12 < 0) || (pCVar4->count <= iVar12)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar16 = pCVar4->data;
                }
                else {
                  pCVar16 = pCVar4->data + iVar12;
                }
                bVar3 = pCVar16->heights
                        [((int)ROUND(fVar19 * 8.0) & 7U) << 3 | (int)ROUND(fVar1 * 8.0) & 7U];
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar12 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                DAT_00772dd8 = (uint)ROUND(*(float *)(iVar12 + 8));
                if ((int)(uint)bVar3 <= (int)DAT_00772dd8) goto LAB_004b0fe8;
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar12 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                *(float *)(iVar12 + 4) = *(float *)(iVar12 + 4) - 0.125;
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar14 = *(float **)(in_ECX + 0x54);
                  pfVar8 = pfVar14;
                }
                else {
                  pfVar14 = *(float **)(in_ECX + 0x54);
                  pfVar8 = pfVar14 + iVar6 * 0x11;
                }
              } while ((((PTR_0077241c->x0f + 1.0 <= *pfVar8) && (*pfVar8 < PTR_0077241c->x1f - 1.0)
                        ) && (PTR_0077241c->y0f + 1.0 <= pfVar8[1])) &&
                      (pfVar8[1] < PTR_0077241c->y1f - 1.0));
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
                iVar12 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              *(undefined4 *)(iVar12 + 4) = 0x40000000;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar12 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              *(undefined4 *)(iVar12 + 0x2c) = 0xffffd8f0;
LAB_004b0fe8:
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar12 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              *(undefined4 *)(iVar12 + 0x14) = 0;
              *(undefined4 *)(iVar12 + 0x10) = 0;
              *(undefined4 *)(iVar12 + 0xc) = 0;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x2c) = 0x20;
              }
              else {
                *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x2c + iVar6 * 0x44) = 0x20;
              }
            }
          }
        }
LAB_004b1101:
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar12;
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        if (-1 < *(int *)(iVar12 + 0x24)) {
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar9 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar9 = iVar9 + iVar6 * 0x44;
          }
          uVar15 = (uint)ROUND(*(float *)(iVar9 + 4) * 8.0 + 1.0);
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            DAT_00772dd8 = uVar15;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar8 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar8 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
          }
          pCVar5 = PTR_0077241c;
          fVar19 = *pfVar8;
          DAT_00772dd8 = (int)ROUND(fVar19 * 8.0);
          piVar13 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar4 = pCVar5->heightBlocks;
          iVar12 = *piVar13;
          if ((iVar12 < 0) || (pCVar4->count <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar16 = pCVar4->data;
          }
          else {
            pCVar16 = pCVar4->data + iVar12;
          }
          bVar3 = pCVar16->heights[(uVar15 & 7) << 3 | (int)ROUND(fVar19 * 8.0) & 7U];
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar12 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          DAT_00772dd8 = (uint)ROUND(*(float *)(iVar12 + 8));
          if ((int)(uint)bVar3 <= (int)DAT_00772dd8) {
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar12 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
            }
            *(float *)(iVar12 + 0x10) = in_XMM2_Da * 0.01 + *(float *)(iVar12 + 0x10);
            *(float *)(iVar12 + 0xc) = *(float *)(iVar12 + 0xc) + in_XMM2_Da * 0.0;
            *(float *)(iVar12 + 0x14) = *(float *)(iVar12 + 0x14) + in_XMM2_Da * 0.0;
          }
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
          iVar9 = iVar12;
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        iVar12 = 0x20 - *(int *)(iVar12 + 0x2c);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = iVar9 + iVar6 * 0x44;
        }
        *(int *)(iVar9 + 0x34) = (iVar12 * 0x700 | iVar12 * 7) << 8;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar15 = DAT_00767980 >> 0x10;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        }
        *(uint *)(iVar12 + 0x38) = (uVar15 & 0x3f) << 0x10;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        }
        *(int *)(iVar12 + 0x2c) = *(int *)(iVar12 + 0x2c) + 1;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        }
        if (0x20 < *(int *)(iVar12 + 0x2c)) {
          FUN_00493010(iVar6);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

