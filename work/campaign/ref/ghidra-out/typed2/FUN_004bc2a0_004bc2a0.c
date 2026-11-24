
void FUN_004bc2a0(uint param_1)

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
  int in_ECX;
  undefined4 *puVar10;
  float *pfVar11;
  code *pcVar12;
  byte *pbVar13;
  float fVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  undefined4 in_XMM3_Da;
  undefined4 in_XMM3_Db;
  int local_40;
  int local_38;
  
  pcVar12 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar4 = FUN_00592f10(PTR_0077241c);
      pbVar13 = (byte *)(iVar4 + 0x34);
      if (param_1 < 8) {
        pbVar13 = pbVar13 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar13 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar7 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar13 = (byte *)FUN_00423700(uVar7);
        if (*pbVar13 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar7 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar13 = (byte *)FUN_00423700(uVar7);
          if (*pbVar13 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar13 = (byte *)FUN_00423700(param_1);
            if (*pbVar13 < 0x81) goto LAB_004bc85c;
          }
        }
      }
    }
    DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
    if (((DAT_00767980 >> 0x10 & 0x7fffU) % 0x1e == 1) &&
       (local_38 = 0, 0 < *(int *)(in_ECX + 0x50))) {
      do {
        iVar4 = FUN_00492f80();
        DAT_00772dd8 = (int)ROUND((float)((double)CONCAT44(in_XMM3_Db,in_XMM3_Da) * 100.0));
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar10 = *(undefined4 **)(in_ECX + 0x54);
        }
        else {
          puVar10 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar4 * 0x44);
        }
        iVar8 = iVar4 * 0x44;
        *puVar10 = *(undefined4 *)(in_ECX + 0xc);
        puVar10[1] = *(undefined4 *)(in_ECX + 0x10);
        puVar10[2] = *(undefined4 *)(in_ECX + 0x14);
        iVar5 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar6 = iVar5 * 0x343fd + 0x269ec3;
        fVar2 = ((float)((iVar5 >> 0x10 & 0x7fffU) % 0x168) / 180.0) * 3.1415927;
        DAT_00767980 = iVar6 * 0x343fd + 0x269ec3;
        fVar3 = (float)((DAT_00767980 >> 0x10 & 0x7fffU) % 0x32) / 850.0;
        dVar15 = (double)fVar2;
        FUN_006f6ad0();
        fVar14 = *(float *)(in_ECX + 0x18);
        dVar16 = (double)(((float)((iVar6 >> 0x10 & 0x7fffU) % 0xb4) / 180.0) * 3.1415927);
        FUN_006f6ad0();
        fVar1 = *(float *)(in_ECX + 0x1c);
        dVar17 = (double)fVar2;
        FUN_006f5ae0();
        fVar2 = *(float *)(in_ECX + 0x20);
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(float *)(iVar5 + 0xc) = (float)dVar15 * fVar3 + fVar14;
        *(float *)(iVar5 + 0x10) = (float)dVar16 * fVar3 + fVar1;
        *(float *)(iVar5 + 0x14) = (float)dVar17 * fVar3 + fVar2;
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
        DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
        uVar7 = DAT_00767980 >> 0x10;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(uint *)(iVar5 + 0x3c) = uVar7 & 3;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x54) + iVar8;
        }
        *(undefined4 *)(iVar5 + 0x2c) = 0;
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
        local_38 = local_38 + 1;
      } while (local_38 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004bc85c:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar4 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_40 = 0;
    do {
      if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
        (*pcVar12)(0xc000008c,1,0,0);
        pfVar9 = *(float **)(in_ECX + 0x54);
        pfVar11 = pfVar9;
      }
      else {
        pfVar9 = *(float **)(in_ECX + 0x54);
        pfVar11 = (float *)(local_40 + (int)pfVar9);
      }
      if (pfVar11[0xb] != -NAN) {
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          (*pcVar12)(0xc000008c,1,0,0);
          pfVar9 = *(float **)(in_ECX + 0x54);
          pfVar11 = pfVar9;
        }
        else {
          pfVar11 = (float *)(local_40 + (int)pfVar9);
        }
        pcVar12 = RaiseException_exref;
        if ((((*pfVar11 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= *pfVar11)) ||
            (pfVar11[1] < PTR_0077241c->y0f + 1.0)) || (PTR_0077241c->y1f - 1.0 <= pfVar11[1])) {
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar10 = *(undefined4 **)(in_ECX + 0x54);
          }
          else {
            puVar10 = (undefined4 *)((int)pfVar9 + local_40);
          }
          *puVar10 = 0x40000000;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + local_40;
          }
          *(undefined4 *)(iVar8 + 4) = 0x40000000;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + local_40;
          }
          *(undefined4 *)(iVar8 + 0x2c) = 0xffffd8f0;
        }
        else {
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = (int)pfVar9 + local_40;
          }
          *(float *)(iVar8 + 0x30) = *(float *)(iVar8 + 0x30) + 0.08;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
            iVar5 = iVar8;
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54);
            iVar5 = local_40 + iVar8;
          }
          if (*(int *)(iVar5 + 0x2c) < 6) {
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar5 = *(int *)(in_ECX + 0x54);
              fVar14 = *(float *)(iVar5 + 0x28) + 1.6;
            }
            else {
              iVar5 = iVar8 + local_40;
              fVar14 = *(float *)(iVar8 + 0x28 + local_40) + 1.6;
            }
          }
          else {
            if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar5 = *(int *)(in_ECX + 0x54);
            }
            else {
              iVar5 = iVar8 + local_40;
            }
            fVar14 = *(float *)(iVar5 + 0x28) - 1.6;
          }
          *(float *)(iVar5 + 0x28) = fVar14;
          DAT_00767980 = DAT_00767980 * 0x343fd + 0x269ec3;
          uVar7 = DAT_00767980 >> 0x10;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + local_40;
          }
          *(uint *)(iVar8 + 0x3c) = uVar7 & 3;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + local_40;
          }
          *(undefined4 *)(iVar8 + 0x34) = 0xffffff;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + local_40;
          }
          *(int *)(iVar8 + 0x2c) = *(int *)(iVar8 + 0x2c) + 1;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar8 = *(int *)(in_ECX + 0x54) + local_40;
          }
          if (0xc < *(int *)(iVar8 + 0x2c)) {
            FUN_00493010(iVar4);
          }
        }
      }
      iVar4 = iVar4 + 1;
      local_40 = local_40 + 0x44;
    } while (iVar4 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

