
void FUN_004b5900(uint param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  int in_ECX;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  code *pcVar10;
  byte *pbVar11;
  float fVar12;
  double dVar13;
  float fVar14;
  float in_XMM2_Da;
  float fVar15;
  float fVar16;
  float fVar17;
  int local_20;
  float *local_1c;
  int local_14;
  float *local_10;
  
  pcVar10 = RaiseException_exref;
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar3 = FUN_00592f10(PTR_0077241c);
      pbVar11 = (byte *)(iVar3 + 0x34);
      if (param_1 < 8) {
        pbVar11 = pbVar11 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar11 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar9 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar11 = (byte *)FUN_00423700(uVar9);
        if (*pbVar11 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar9 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar11 = (byte *)FUN_00423700(uVar9);
          if (*pbVar11 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar11 = (byte *)FUN_00423700(param_1);
            if (*pbVar11 < 0x81) goto LAB_004b5e9a;
          }
        }
      }
    }
    local_14 = 0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar4 = FUN_00492f80();
        iVar3 = *(int *)(in_ECX + 0x3c);
        if ((iVar3 < 1) || (*(int *)(in_ECX + 0x4c) <= iVar3)) {
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar7 = *(undefined4 **)(in_ECX + 0x54);
          }
          else {
            puVar7 = (undefined4 *)(*(int *)(in_ECX + 0x54) + iVar4 * 0x44);
          }
          *puVar7 = *(undefined4 *)(in_ECX + 0xc);
          puVar7[1] = *(undefined4 *)(in_ECX + 0x10);
          puVar7[2] = *(undefined4 *)(in_ECX + 0x14);
        }
        else {
          if (iVar3 < *(int *)(in_ECX + 0x58)) {
            pfVar5 = *(float **)(in_ECX + 0x54) + iVar3 * 0x11;
            local_10 = *(float **)(in_ECX + 0x54);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar5 = *(float **)(in_ECX + 0x54);
            local_10 = pfVar5;
          }
          fVar14 = *(float *)(in_ECX + 0x10) - pfVar5[1];
          fVar17 = *(float *)(in_ECX + 0xc) - *pfVar5;
          fVar15 = *(float *)(in_ECX + 0x14) - pfVar5[2];
          fVar12 = fVar14 * fVar14 + fVar17 * fVar17 + fVar15 * fVar15;
          FUN_0040b7e0();
          fVar16 = 0.0;
          if (fVar12 <= 0.0) {
            fVar15 = 0.0;
            fVar14 = 0.0;
          }
          else {
            fVar15 = fVar15 / fVar12;
            fVar14 = fVar14 / fVar12;
            fVar16 = fVar17 / fVar12;
          }
          iVar3 = *(int *)(in_ECX + 0x3c);
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar5 = *(float **)(in_ECX + 0x54);
            local_10 = pfVar5;
          }
          else {
            pfVar5 = local_10 + iVar3 * 0x11;
          }
          fVar16 = *pfVar5 + fVar16 * 0.14;
          fVar14 = pfVar5[1] + fVar14 * 0.14;
          fVar12 = pfVar5[2] + fVar15 * 0.14;
          if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar5 = *(float **)(in_ECX + 0x54);
            *pfVar5 = fVar16;
            pfVar5[1] = fVar14;
            pfVar5[2] = fVar12;
          }
          else {
            local_10 = local_10 + iVar4 * 0x11;
            *local_10 = fVar16;
            local_10[1] = fVar14;
            local_10[2] = fVar12;
          }
        }
        iVar3 = iVar4 * 0x44;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)(in_ECX + 0x18);
        *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(in_ECX + 0x1c);
        *(undefined4 *)(iVar8 + 0x14) = *(undefined4 *)(in_ECX + 0x20);
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0x28) = 0x3fa66666;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0x2c) = 0;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0x30) = 0;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0x34) = 0xffffffff;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0x38) = 0xffffffff;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar8 + 0x3c) = 0x40003;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar8 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined1 *)(iVar8 + 0x40) = 0;
        if ((iVar4 < 0) || (*(int *)(in_ECX + 0x58) <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar3;
        }
        *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(in_ECX + 0x3c);
        if (local_14 == 0) {
          *(int *)(in_ECX + 0x3c) = iVar4;
        }
        local_14 = local_14 + 1;
        pcVar10 = RaiseException_exref;
      } while (local_14 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004b5e9a:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar3 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_20 = 0;
    do {
      if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
        (*pcVar10)(0xc000008c,1,0,0);
        iVar4 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar4;
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar4 + local_20;
      }
      if (*(int *)(iVar8 + 0x2c) != -10000) {
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar10)(0xc000008c,1,0,0);
          iVar4 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar4;
        }
        else {
          iVar8 = iVar4 + local_20;
        }
        fVar12 = *(float *)(iVar8 + 0xc);
        fVar15 = *(float *)(iVar8 + 0x10);
        fVar14 = *(float *)(iVar8 + 0x14);
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar10)(0xc000008c,1,0,0);
          pfVar5 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar5 = (float *)(iVar4 + local_20);
        }
        *pfVar5 = fVar12 * in_XMM2_Da + *pfVar5;
        pfVar5[1] = fVar15 * in_XMM2_Da + pfVar5[1];
        pfVar5[2] = fVar14 * in_XMM2_Da + pfVar5[2];
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar10)(0xc000008c,1,0,0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + local_20;
        }
        *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) - 0.1;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar10)(0xc000008c,1,0,0);
          pfVar5 = *(float **)(in_ECX + 0x54);
          local_1c = pfVar5;
        }
        else {
          pfVar5 = (float *)((int)*(float **)(in_ECX + 0x54) + local_20);
          local_1c = *(float **)(in_ECX + 0x54);
        }
        if (0 < (int)pfVar5[9]) {
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            (*pcVar10)(0xc000008c,1,0,0);
            pfVar5 = *(float **)(in_ECX + 0x54);
            local_1c = pfVar5;
          }
          else {
            pfVar5 = (float *)((int)local_1c + local_20);
          }
          if ((int)pfVar5[9] < *(int *)(in_ECX + 0x4c)) {
            if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
              (*pcVar10)(0xc000008c,1,0,0);
              pfVar5 = *(float **)(in_ECX + 0x54);
              local_1c = pfVar5;
            }
            else {
              pfVar5 = (float *)(local_20 + (int)local_1c);
            }
            fVar12 = pfVar5[9];
            if (((int)fVar12 < 0) || (*(int *)(in_ECX + 0x58) <= (int)fVar12)) {
              (*pcVar10)(0xc000008c,1,0,0);
              pfVar5 = *(float **)(in_ECX + 0x54);
              local_1c = pfVar5;
            }
            else {
              pfVar5 = local_1c + (int)fVar12 * 0x11;
            }
            if (pfVar5[0xb] != -NAN) {
              if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
                (*pcVar10)(0xc000008c,1,0,0);
                pfVar5 = *(float **)(in_ECX + 0x54);
                local_1c = pfVar5;
              }
              else {
                pfVar5 = (float *)((int)local_1c + local_20);
              }
              if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
                (*pcVar10)(0xc000008c,1,0,0);
                pfVar6 = *(float **)(in_ECX + 0x54);
                local_1c = pfVar6;
              }
              else {
                pfVar6 = (float *)((int)local_1c + local_20);
              }
              fVar12 = pfVar6[9];
              if (((int)fVar12 < 0) || (*(int *)(in_ECX + 0x58) <= (int)fVar12)) {
                (*pcVar10)(0xc000008c,1,0,0);
                pfVar6 = *(float **)(in_ECX + 0x54);
                local_1c = pfVar6;
              }
              else {
                pfVar6 = local_1c + (int)fVar12 * 0x11;
              }
              fVar12 = pfVar6[1] - pfVar5[1];
              fVar14 = *pfVar6 - *pfVar5;
              fVar16 = pfVar6[2] - pfVar5[2];
              fVar15 = fVar12 * fVar12 + fVar14 * fVar14 + fVar16 * fVar16;
              if (0.0064 < fVar15) {
                dVar13 = (double)fVar15;
                if (dVar13 < 0.0) {
                  __libm_sse2_sqrt_precise();
                }
                else {
                  dVar13 = SQRT(dVar13);
                }
                fVar15 = (float)dVar13 * 12.5;
                if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
                  (*pcVar10)(0xc000008c,1,0,0);
                  local_1c = *(float **)(in_ECX + 0x54);
                  pfVar5 = local_1c;
                }
                else {
                  pfVar5 = (float *)(local_20 + (int)local_1c);
                }
                fVar17 = pfVar5[9];
                if (((int)fVar17 < 0) || (*(int *)(in_ECX + 0x58) <= (int)fVar17)) {
                  (*pcVar10)(0xc000008c,1,0,0);
                  pfVar5 = *(float **)(in_ECX + 0x54);
                  local_1c = pfVar5;
                }
                else {
                  pfVar5 = local_1c + (int)fVar17 * 0x11;
                }
                fVar17 = *pfVar5;
                fVar1 = pfVar5[1];
                fVar2 = pfVar5[2];
                if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
                  (*pcVar10)(0xc000008c,1,0,0);
                  local_1c = *(float **)(in_ECX + 0x54);
                }
                else {
                  local_1c = (float *)(local_20 + (int)local_1c);
                }
                *local_1c = fVar17 - fVar14 / fVar15;
                local_1c[1] = fVar1 - fVar12 / fVar15;
                local_1c[2] = fVar2 - fVar16 / fVar15;
              }
            }
          }
        }
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar10)(0xc000008c,1,0,0);
          iVar4 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar4;
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54);
          iVar8 = local_20 + iVar4;
        }
        if (*(int *)(iVar8 + 0x2c) == 0) {
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            (*pcVar10)(0xc000008c,1,0,0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = iVar4 + local_20;
          }
          *(undefined4 *)(iVar4 + 0x34) = 0;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            (*pcVar10)(0xc000008c,1,0,0);
            *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x38) = 0;
          }
          else {
            *(undefined4 *)(*(int *)(in_ECX + 0x54) + local_20 + 0x38) = 0;
          }
        }
        else {
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            (*pcVar10)(0xc000008c,1,0,0);
            iVar4 = *(int *)(in_ECX + 0x54);
            local_10 = (float *)iVar4;
          }
          else {
            local_10 = (float *)(iVar4 + local_20);
          }
          iVar8 = 8 - *(int *)((int)local_10 + 0x2c);
          uVar9 = iVar8 * 8;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            (*pcVar10)(0xc000008c,1,0,0);
            local_10 = *(float **)(in_ECX + 0x54);
          }
          else {
            local_10 = (float *)(iVar4 + local_20);
          }
          uVar9 = (iVar8 * 0x800 | uVar9) << 8 | uVar9;
          *(uint *)((int)local_10 + 0x34) = uVar9;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
            (*pcVar10)(0xc000008c,1,0,0);
            iVar4 = *(int *)(in_ECX + 0x54);
          }
          else {
            iVar4 = *(int *)(in_ECX + 0x54) + local_20;
          }
          *(uint *)(iVar4 + 0x38) = uVar9;
        }
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar10)(0xc000008c,1,0,0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + local_20;
        }
        *(int *)(iVar4 + 0x2c) = *(int *)(iVar4 + 0x2c) + 1;
        if ((iVar3 < 0) || (*(int *)(in_ECX + 0x58) <= iVar3)) {
          (*pcVar10)(0xc000008c,1,0,0);
          iVar4 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar4 = *(int *)(in_ECX + 0x54) + local_20;
        }
        if (8 < *(int *)(iVar4 + 0x2c)) {
          FUN_00493010(iVar3);
        }
      }
      iVar3 = iVar3 + 1;
      local_20 = local_20 + 0x44;
    } while (iVar3 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

