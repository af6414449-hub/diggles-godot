
void FUN_004acee0(uint param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int in_ECX;
  int iVar11;
  float *pfVar12;
  code *pcVar13;
  byte *pbVar14;
  uint uVar15;
  double dVar16;
  double dVar17;
  float in_XMM2_Da;
  float fVar18;
  int local_34;
  int local_28;
  
  pcVar13 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar5 = FUN_00592f10(PTR_0077241c);
      pbVar14 = (byte *)(iVar5 + 0x34);
      if (param_1 < 8) {
        pbVar14 = pbVar14 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar14 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar15 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar14 = (byte *)FUN_00423700(uVar15);
        if (*pbVar14 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar15 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar14 = (byte *)FUN_00423700(uVar15);
          if (*pbVar14 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar14 = (byte *)FUN_00423700(param_1);
            if (*pbVar14 < 0x81) goto LAB_004ad4fd;
          }
        }
      }
    }
    local_28 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar5 = FUN_00492f80();
        iVar11 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar6 = iVar11 * 0x343fd + 0x269ec3;
        fVar4 = ((float)((iVar11 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
        uVar15 = DAT_00767980 >> 0x10;
        fVar18 = (float)((iVar6 >> 0x10 & 0x7fffU) % 100) * (*(float *)(in_ECX + 0x18) / 100.0);
        dVar16 = (double)fVar4;
        FUN_006f6ad0();
        fVar1 = *(float *)(in_ECX + 0x1c);
        fVar2 = *(float *)(in_ECX + 0xc);
        fVar3 = *(float *)(in_ECX + 0x10);
        dVar17 = (double)fVar4;
        FUN_006f5ae0();
        fVar4 = *(float *)(in_ECX + 0x14);
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar7 = (float *)(*(int *)(in_ECX + 0x54) + iVar5 * 0x44);
        }
        iVar6 = iVar5 * 0x44;
        *pfVar7 = (float)dVar16 * fVar18 + fVar2;
        pfVar7[1] = (float)((uVar15 & 0x7fff) % 100) * (fVar1 / 100.0) + fVar3;
        pfVar7[2] = (float)dVar17 * fVar18 + fVar4;
        iVar11 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar8 = iVar11 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar15 = DAT_00767980 >> 0x10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar9 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(float *)(iVar9 + 0xc) = (float)(int)((iVar11 >> 0x10 & 0xfU) - 8) / 880.0;
        *(float *)(iVar9 + 0x10) = (float)(int)((iVar8 >> 0x10 & 0xfU) - 0x10) / 885.0;
        *(float *)(iVar9 + 0x14) = (float)(int)((uVar15 & 0xf) - 8) / 880.0;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar11 + 0x28) = 0x3ecccccd;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar11 + 0x34) = 0xffe060;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar11 + 0x3c) = 0x30002;
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar15 = DAT_00767980 >> 0x10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(uint *)(iVar11 + 0x2c) = (uVar15 & 0x7fff) % 10;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar11 + 0x30) = 0;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar11 + 0x38) = 0;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar11 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar11 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined4 *)(iVar11 + 0x24) = 0;
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar6;
        }
        *(undefined1 *)(iVar6 + 0x40) = 0;
        local_28 = local_28 + 1;
      } while (local_28 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004ad4fd:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar5 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_34 = 0;
    do {
      if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
        (*pcVar13)(0xc000008c,1,0,0);
        pfVar7 = *(float **)(in_ECX + 0x54);
        pfVar12 = pfVar7;
      }
      else {
        pfVar7 = *(float **)(in_ECX + 0x54);
        pfVar12 = (float *)((int)pfVar7 + local_34);
      }
      if (pfVar12[0xb] != -NAN) {
        if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
          (*pcVar13)(0xc000008c,1,0,0);
          pfVar7 = *(float **)(in_ECX + 0x54);
          pfVar12 = pfVar7;
        }
        else {
          pfVar12 = (float *)(local_34 + (int)pfVar7);
        }
        pcVar13 = RaiseException_exref;
        if ((((*pfVar12 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= *pfVar12)) ||
            (pfVar12[1] < PTR_0077241c->y0f + 1.0)) || (PTR_0077241c->y1f - 1.0 <= pfVar12[1])) {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar10 = *(undefined4 **)(in_ECX + 0x54);
          }
          else {
            puVar10 = (undefined4 *)((int)pfVar7 + local_34);
          }
          *puVar10 = 0x40000000;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + local_34;
          }
          *(undefined4 *)(iVar6 + 4) = 0x40000000;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + local_34;
          }
          *(undefined4 *)(iVar6 + 0x2c) = 0xffffd8f0;
        }
        else {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = (int)pfVar7 + local_34;
          }
          *(float *)(iVar6 + 0x30) = *(float *)(iVar6 + 0x30) + 0.08;
          iVar6 = DAT_00767980 * 0x343fd + 0x269ec3;
          iVar11 = iVar6 * 0x343fd + 0x269ec3;
          DAT_00767980 = iVar11 * 0x343fd + 0x269ec3;
          uVar15 = DAT_00767980 >> 0x10;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + local_34;
          }
          *(float *)(iVar8 + 0xc) =
               (float)(int)((iVar6 >> 0x10 & 0xfU) - 8) / 6000.0 + *(float *)(iVar8 + 0xc);
          *(float *)(iVar8 + 0x10) =
               (float)(int)((iVar11 >> 0x10 & 0xfU) - 10) / 6000.0 + *(float *)(iVar8 + 0x10);
          *(float *)(iVar8 + 0x14) =
               *(float *)(iVar8 + 0x14) + (float)(int)((uVar15 & 0xf) - 8) / 6000.0;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
            iVar11 = iVar6;
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + local_34;
            iVar11 = *(int *)(in_ECX + 0x54);
          }
          fVar1 = *(float *)(iVar6 + 0xc);
          fVar2 = *(float *)(iVar6 + 0x14);
          fVar3 = *(float *)(iVar6 + 0x10);
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar7 = *(float **)(in_ECX + 0x54);
          }
          else {
            pfVar7 = (float *)(local_34 + iVar11);
          }
          *pfVar7 = *pfVar7 + fVar1 * in_XMM2_Da;
          pfVar7[2] = fVar2 * in_XMM2_Da + pfVar7[2];
          pfVar7[1] = pfVar7[1] + fVar3 * in_XMM2_Da;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
            local_28 = iVar6;
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + local_34;
            local_28 = *(int *)(in_ECX + 0x54);
          }
          iVar6 = 0x30 - *(int *)(iVar6 + 0x2c);
          uVar15 = iVar6 * 5;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_28 = *(int *)(in_ECX + 0x54);
          }
          else {
            local_28 = local_28 + local_34;
          }
          *(uint *)(local_28 + 0x38) = (iVar6 * 0x500 | uVar15) << 8 | uVar15;
          DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
          if ((DAT_00767980 >> 0x10 & 0x7fffU) < 3000) {
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar6 = *(int *)(in_ECX + 0x54) + local_34;
            }
            *(undefined4 *)(iVar6 + 0x2c) = 0x2f;
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar6 = *(int *)(in_ECX + 0x54) + local_34;
            }
            *(undefined4 *)(iVar6 + 0x28) = 0x3f000000;
            if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar6 = *(int *)(in_ECX + 0x54) + local_34;
            }
            *(undefined4 *)(iVar6 + 0x38) = 0xffffff;
          }
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + local_34;
          }
          *(undefined4 *)(iVar6 + 0x34) = 0xffe060;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + local_34;
          }
          *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + 1;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x58) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar6 = *(int *)(in_ECX + 0x54) + local_34;
          }
          if (0x2f < *(int *)(iVar6 + 0x2c)) {
            FUN_00493010(iVar5);
          }
        }
      }
      iVar5 = iVar5 + 1;
      local_34 = local_34 + 0x44;
    } while (iVar5 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

