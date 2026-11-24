
void FUN_004a07d0(uint param_1)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  CHeightBlockArray *pCVar4;
  CMap *pCVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  int *piVar14;
  int in_ECX;
  int iVar15;
  CHeightBlock *pCVar16;
  uint uVar17;
  float fVar18;
  float in_XMM2_Da;
  int local_2c;
  int local_28;
  
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
        uVar9 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar7 = (byte *)FUN_00423700(uVar9);
        if (*pbVar7 < 0x81) {
          DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar9 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar7 = (byte *)FUN_00423700(uVar9);
          if (*pbVar7 < 0x81) {
            DAT_00772dd8 = (uint)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar7 = (byte *)FUN_00423700(param_1);
            if (*pbVar7 < 0x81) goto LAB_004a0d64;
          }
        }
      }
    }
    local_2c = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar6 = FUN_00492f80();
        iVar15 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar8 = iVar15 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar9 = DAT_00767980 >> 0x10;
        fVar18 = *(float *)(in_ECX + 0xc);
        fVar1 = *(float *)(in_ECX + 0x10);
        fVar2 = *(float *)(in_ECX + 0x14);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar10 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
        }
        iVar12 = iVar6 * 0x44;
        pfVar10[2] = fVar2 + (float)(int)((uVar9 & 0xf) - 8) / 30.0;
        pfVar10[1] = fVar1 + (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 30.0;
        *pfVar10 = fVar18 + (float)(int)((iVar15 >> 0x10 & 0xfU) - 8) / 30.0;
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar15 = iVar8 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar15 * 0x343fd + 0x269ec3;
        uVar9 = DAT_00767980 >> 0x10;
        fVar18 = *(float *)(in_ECX + 0x18);
        fVar1 = *(float *)(in_ECX + 0x20);
        fVar2 = *(float *)(in_ECX + 0x1c);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(float *)(iVar11 + 0xc) = fVar18 + (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 30.0;
        *(float *)(iVar11 + 0x10) = (float)(int)((iVar15 >> 0x10 & 0xfU) - 8) / 35.0 + fVar2;
        *(float *)(iVar11 + 0x14) = fVar1 + (float)(int)((uVar9 & 0xf) - 8) / 40.0;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined4 *)(iVar8 + 0x28) = 0x40200000;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar9 = DAT_00767980 >> 0x10;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_28 = *(int *)(in_ECX + 0x54);
        }
        else {
          local_28 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(uint *)(local_28 + 0x2c) = uVar9 & 0x1f;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined4 *)(iVar8 + 0x30) = 0;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined4 *)(iVar8 + 0x34) = 0xffffffff;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined4 *)(iVar8 + 0x38) = 0;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar9 = DAT_00767980 >> 0x10;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_28 = *(int *)(in_ECX + 0x54);
        }
        else {
          local_28 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(uint *)(local_28 + 0x3c) = uVar9 & 7;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar12 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar12 = *(int *)(in_ECX + 0x54) + iVar12;
        }
        *(undefined1 *)(iVar12 + 0x40) = 0;
        local_2c = local_2c + 1;
      } while (local_2c < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004a0d64:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar6 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    do {
      if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar8 = *(int *)(in_ECX + 0x54);
        iVar15 = iVar8;
      }
      else {
        iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        iVar15 = *(int *)(in_ECX + 0x54);
      }
      if (*(int *)(iVar8 + 0x2c) != -10000) {
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
          iVar15 = iVar8;
        }
        else {
          iVar8 = iVar15 + iVar6 * 0x44;
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar15 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar15 = iVar15 + iVar6 * 0x44;
        }
        fVar18 = *(float *)(iVar15 + 0xc) * *(float *)(iVar15 + 0xc) +
                 *(float *)(iVar15 + 0x10) * *(float *)(iVar15 + 0x10) +
                 *(float *)(iVar15 + 0x14) * *(float *)(iVar15 + 0x14);
        FUN_0040b7e0();
        *(float *)(iVar8 + 0x30) = fVar18 + *(float *)(iVar8 + 0x30);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
          iVar15 = iVar8;
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          iVar15 = *(int *)(in_ECX + 0x54);
        }
        fVar18 = *(float *)(iVar8 + 0xc);
        fVar1 = *(float *)(iVar8 + 0x10);
        fVar2 = *(float *)(iVar8 + 0x14);
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar10 = (float *)(iVar15 + iVar6 * 0x44);
        }
        *pfVar10 = fVar18 * in_XMM2_Da + *pfVar10;
        pfVar10[1] = pfVar10[1] + fVar1 * in_XMM2_Da;
        pfVar10[2] = pfVar10[2] + fVar2 * in_XMM2_Da;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = *(float **)(in_ECX + 0x54);
          pfVar13 = pfVar10;
        }
        else {
          pfVar10 = *(float **)(in_ECX + 0x54) + iVar6 * 0x11;
          pfVar13 = *(float **)(in_ECX + 0x54);
        }
        if ((*pfVar10 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= *pfVar10)) {
LAB_004a1b32:
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar13 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar13 = pfVar13 + iVar6 * 0x11;
          }
          *pfVar13 = 2.0;
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          *(undefined4 *)(iVar8 + 4) = 0x40000000;
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          *(undefined4 *)(iVar8 + 0x2c) = 0xffffd8f0;
        }
        else {
          if ((pfVar10[1] < PTR_0077241c->y0f + 1.0) || (PTR_0077241c->y1f - 1.0 <= pfVar10[1]))
          goto LAB_004a1b32;
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar13 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar13 = pfVar13 + iVar6 * 0x11;
          }
          fVar18 = pfVar13[1];
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            DAT_00772dd8 = (int)ROUND(fVar18 * 8.0);
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar10 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar10 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
          }
          pCVar5 = PTR_0077241c;
          fVar1 = *pfVar10;
          DAT_00772dd8 = (int)ROUND(fVar1 * 8.0);
          piVar14 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar4 = pCVar5->heightBlocks;
          iVar8 = *piVar14;
          if ((iVar8 < 0) || (pCVar4->count <= iVar8)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar16 = pCVar4->data;
          }
          else {
            pCVar16 = pCVar4->data + iVar8;
          }
          bVar3 = pCVar16->heights
                  [((int)ROUND(fVar18 * 8.0) & 7U) << 3 | (int)ROUND(fVar1 * 8.0) & 7U];
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          DAT_00772dd8 = (uint)ROUND(*(float *)(iVar8 + 8));
          if ((int)DAT_00772dd8 < (int)(uint)bVar3) {
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar8 = *(int *)(in_ECX + 0x54);
              iVar15 = iVar8;
            }
            else {
              iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              iVar15 = *(int *)(in_ECX + 0x54);
            }
            if (*(float *)(iVar8 + 0xc) * *(float *)(iVar8 + 0xc) +
                *(float *)(iVar8 + 0x10) * *(float *)(iVar8 + 0x10) +
                *(float *)(iVar8 + 0x14) * *(float *)(iVar8 + 0x14) <= 0.010000001) {
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar15 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar15 = iVar15 + iVar6 * 0x44;
              }
              *(undefined4 *)(iVar15 + 0x14) = 0;
              *(undefined4 *)(iVar15 + 0x10) = 0;
              *(undefined4 *)(iVar15 + 0xc) = 0;
            }
            else {
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar15 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar15 = iVar15 + iVar6 * 0x44;
              }
              uVar9 = (uint)ROUND(*(float *)(iVar15 + 4) * 8.0);
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                DAT_00772dd8 = uVar9;
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar10 = *(float **)(in_ECX + 0x54);
              }
              else {
                pfVar10 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
              }
              pCVar5 = PTR_0077241c;
              uVar17 = (uint)ROUND(*pfVar10 * 8.0 - 1.0);
              DAT_00772dd8 = uVar17;
              piVar14 = (int *)FUN_00592f10(PTR_0077241c);
              pCVar4 = pCVar5->heightBlocks;
              iVar8 = *piVar14;
              if ((iVar8 < 0) || (pCVar4->count <= iVar8)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar16 = pCVar4->data;
              }
              else {
                pCVar16 = pCVar4->data + iVar8;
              }
              bVar3 = pCVar16->heights[(uVar9 & 7) << 3 | uVar17 & 7];
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar8 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              uVar9 = (uint)ROUND(*(float *)(iVar8 + 4) * 8.0);
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                DAT_00772dd8 = uVar9;
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar10 = *(float **)(in_ECX + 0x54);
              }
              else {
                pfVar10 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
              }
              pCVar5 = PTR_0077241c;
              uVar17 = (uint)ROUND(*pfVar10 * 8.0 + 1.0);
              DAT_00772dd8 = uVar17;
              piVar14 = (int *)FUN_00592f10(PTR_0077241c);
              pCVar4 = pCVar5->heightBlocks;
              iVar8 = *piVar14;
              if ((iVar8 < 0) || (pCVar4->count <= iVar8)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar16 = pCVar4->data;
              }
              else {
                pCVar16 = pCVar4->data + iVar8;
              }
              uVar9 = (uint)bVar3 - (uint)pCVar16->heights[(uVar9 & 7) << 3 | uVar17 & 7];
              uVar17 = (int)uVar9 >> 0x1f;
              iVar8 = (uVar9 ^ uVar17) - uVar17;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar15 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar15 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              uVar9 = (uint)ROUND(*(float *)(iVar15 + 4) * 8.0 - 1.0);
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                DAT_00772dd8 = uVar9;
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar10 = *(float **)(in_ECX + 0x54);
              }
              else {
                pfVar10 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
              }
              pCVar5 = PTR_0077241c;
              fVar18 = *pfVar10;
              DAT_00772dd8 = (int)ROUND(fVar18 * 8.0);
              piVar14 = (int *)FUN_00592f10(PTR_0077241c);
              pCVar4 = pCVar5->heightBlocks;
              iVar15 = *piVar14;
              if ((iVar15 < 0) || (pCVar4->count <= iVar15)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar16 = pCVar4->data;
              }
              else {
                pCVar16 = pCVar4->data + iVar15;
              }
              bVar3 = pCVar16->heights[(uVar9 & 7) << 3 | (int)ROUND(fVar18 * 8.0) & 7U];
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar15 = *(int *)(in_ECX + 0x54);
              }
              else {
                iVar15 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
              }
              uVar9 = (uint)ROUND(*(float *)(iVar15 + 4) * 8.0 + 1.0);
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                DAT_00772dd8 = uVar9;
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar10 = *(float **)(in_ECX + 0x54);
              }
              else {
                pfVar10 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
              }
              pCVar5 = PTR_0077241c;
              fVar18 = *pfVar10;
              DAT_00772dd8 = (int)ROUND(fVar18 * 8.0);
              piVar14 = (int *)FUN_00592f10(PTR_0077241c);
              pCVar4 = pCVar5->heightBlocks;
              iVar15 = *piVar14;
              if ((iVar15 < 0) || (pCVar4->count <= iVar15)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar16 = pCVar4->data;
              }
              else {
                pCVar16 = pCVar4->data + iVar15;
              }
              uVar9 = (uint)bVar3 -
                      (uint)pCVar16->heights[(uVar9 & 7) << 3 | (int)ROUND(fVar18 * 8.0) & 7U];
              uVar17 = (int)uVar9 >> 0x1f;
              iVar15 = (uVar9 ^ uVar17) - uVar17;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar12 = *(int *)(in_ECX + 0x54);
                iVar11 = iVar12;
              }
              else {
                iVar12 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                iVar11 = *(int *)(in_ECX + 0x54);
              }
              fVar18 = *(float *)(iVar12 + 0xc);
              fVar1 = *(float *)(iVar12 + 0x10);
              fVar2 = *(float *)(iVar12 + 0x14);
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar10 = *(float **)(in_ECX + 0x54);
              }
              else {
                pfVar10 = (float *)(iVar11 + iVar6 * 0x44);
              }
              *pfVar10 = *pfVar10 - fVar18 * in_XMM2_Da;
              pfVar10[1] = pfVar10[1] - fVar1 * in_XMM2_Da;
              pfVar10[2] = pfVar10[2] - fVar2 * in_XMM2_Da;
              if ((iVar8 < 3) && (iVar15 < 3)) {
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar8 = *(int *)(in_ECX + 0x54);
                  iVar15 = iVar8;
                }
                else {
                  iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                  iVar15 = *(int *)(in_ECX + 0x54);
                }
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar15 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar15 = iVar15 + iVar6 * 0x44;
                }
                *(uint *)(iVar15 + 0x14) = *(uint *)(iVar8 + 0x14) ^ 0x80000000;
LAB_004a1801:
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar8 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
                fVar18 = 0.5;
              }
              else {
                if (iVar15 <= iVar8) {
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar8 = *(int *)(in_ECX + 0x54);
                    iVar15 = iVar8;
                  }
                  else {
                    iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                    iVar15 = *(int *)(in_ECX + 0x54);
                  }
                  uVar9 = *(uint *)(iVar8 + 0xc);
                  if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar15 = *(int *)(in_ECX + 0x54);
                  }
                  else {
                    iVar15 = iVar15 + iVar6 * 0x44;
                  }
                  *(uint *)(iVar15 + 0xc) = uVar9 ^ 0x80000000;
                  goto LAB_004a1801;
                }
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar8 = *(int *)(in_ECX + 0x54);
                  iVar15 = iVar8;
                }
                else {
                  iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                  iVar15 = *(int *)(in_ECX + 0x54);
                }
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar15 = *(int *)(in_ECX + 0x54);
                }
                else {
                  iVar15 = iVar15 + iVar6 * 0x44;
                }
                *(uint *)(iVar15 + 0x10) = *(uint *)(iVar8 + 0x10) ^ 0x80000000;
                if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar8 = *(int *)(in_ECX + 0x54);
                  fVar18 = 0.2;
                }
                else {
                  fVar18 = 0.2;
                  iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                }
              }
              *(float *)(iVar8 + 0xc) = *(float *)(iVar8 + 0xc) * fVar18;
              *(float *)(iVar8 + 0x10) = *(float *)(iVar8 + 0x10) * fVar18;
              *(float *)(iVar8 + 0x14) = *(float *)(iVar8 + 0x14) * fVar18;
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar8 = *(int *)(in_ECX + 0x54);
                iVar15 = iVar8;
              }
              else {
                iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
                iVar15 = *(int *)(in_ECX + 0x54);
              }
              fVar18 = *(float *)(iVar8 + 0x10);
              fVar1 = *(float *)(iVar8 + 0xc);
              fVar2 = *(float *)(iVar8 + 0x14);
              if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar10 = *(float **)(in_ECX + 0x54);
              }
              else {
                pfVar10 = (float *)(iVar15 + iVar6 * 0x44);
              }
              *pfVar10 = fVar1 * in_XMM2_Da + *pfVar10;
              pfVar10[2] = fVar2 * in_XMM2_Da + pfVar10[2];
              pfVar10[1] = pfVar10[1] + fVar18 * in_XMM2_Da;
            }
          }
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          uVar9 = (uint)ROUND(*(float *)(iVar8 + 4) * 8.0 + 1.0);
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            DAT_00772dd8 = uVar9;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar10 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar10 = (float *)(*(int *)(in_ECX + 0x54) + iVar6 * 0x44);
          }
          pCVar5 = PTR_0077241c;
          fVar18 = *pfVar10;
          DAT_00772dd8 = (int)ROUND(fVar18 * 8.0);
          piVar14 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar4 = pCVar5->heightBlocks;
          iVar8 = *piVar14;
          if ((iVar8 < 0) || (pCVar4->count <= iVar8)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar16 = pCVar4->data;
          }
          else {
            pCVar16 = pCVar4->data + iVar8;
          }
          bVar3 = pCVar16->heights[(uVar9 & 7) << 3 | (int)ROUND(fVar18 * 8.0) & 7U];
          if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
          }
          DAT_00772dd8 = (uint)ROUND(*(float *)(iVar8 + 8));
          if ((int)(uint)bVar3 <= (int)DAT_00772dd8) {
            if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar8 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
            }
            *(float *)(iVar8 + 0xc) = *(float *)(iVar8 + 0xc) + in_XMM2_Da * 0.0;
            *(float *)(iVar8 + 0x14) = in_XMM2_Da * 0.0 + *(float *)(iVar8 + 0x14);
            *(float *)(iVar8 + 0x10) = *(float *)(iVar8 + 0x10) + in_XMM2_Da * 0.1;
          }
        }
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        }
        *(int *)(iVar8 + 0x2c) = *(int *)(iVar8 + 0x2c) + 1;
        if ((iVar6 < 0) || (*(int *)(in_ECX + 0x58) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar6 * 0x44;
        }
        if (100 < *(int *)(iVar8 + 0x2c)) {
          FUN_00493010(iVar6);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

