
void FUN_004a5ca0(uint param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  int iVar8;
  float fVar9;
  double dVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  int local_1c;
  float local_18;
  uint local_14;
  int local_10;
  
  if (((*(byte *)(in_ECX + 0x5c) & 1) != 0) && (*(char *)(in_ECX + 0x6e) == '\0')) {
    if (*(char *)(in_ECX + 100) == '\0') {
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
      iVar1 = FUN_00592f10(PTR_0077241c);
      pbVar2 = (byte *)(iVar1 + 0x34);
      if (param_1 < 8) {
        pbVar2 = pbVar2 + param_1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pbVar2 < 0x81) {
        DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc));
        uVar4 = param_1;
        FUN_00592f10(PTR_0077241c);
        pbVar2 = (byte *)FUN_00423700(uVar4);
        if (*pbVar2 < 0x81) {
          DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
          uVar4 = param_1;
          FUN_00592f10(PTR_0077241c);
          pbVar2 = (byte *)FUN_00423700(uVar4);
          if (*pbVar2 < 0x81) {
            DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0xc) + 1.0);
            FUN_00592f10(PTR_0077241c);
            pbVar2 = (byte *)FUN_00423700(param_1);
            if (*pbVar2 < 0x81) goto LAB_004a61fb;
          }
        }
      }
    }
    local_18 = 0.0;
    if (0 < *(int *)(in_ECX + 0x50)) {
      do {
        iVar1 = FUN_00492f80();
        iVar8 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar3 = iVar8 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar3 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        fVar11 = *(float *)(in_ECX + 0x10);
        fVar9 = *(float *)(in_ECX + 0x14);
        fVar12 = *(float *)(in_ECX + 0xc);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar5 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar5 = (float *)(*(int *)(in_ECX + 0x54) + iVar1 * 0x44);
        }
        iVar7 = iVar1 * 0x44;
        pfVar5[2] = fVar9 + (float)(int)((uVar4 & 0xf) - 8) / 250.0;
        *pfVar5 = (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 250.0 + fVar12;
        pfVar5[1] = fVar11 + (float)(int)((iVar3 >> 0x10 & 0xfU) - 8) / 250.0;
        iVar3 = DAT_00767980 * 0x343fd + 0x269ec3;
        iVar8 = iVar3 * 0x343fd + 0x269ec3;
        DAT_00767980 = iVar8 * 0x343fd + 0x269ec3;
        uVar4 = DAT_00767980 >> 0x10;
        fVar11 = *(float *)(in_ECX + 0x18);
        fVar9 = *(float *)(in_ECX + 0x20);
        fVar12 = *(float *)(in_ECX + 0x1c);
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar6 = *(int *)(in_ECX + 0x54) + iVar7;
        }
        *(float *)(iVar6 + 0xc) = fVar11 + (float)(int)((iVar3 >> 0x10 & 0xfU) - 8) / 540.0;
        *(float *)(iVar6 + 0x10) = (float)(int)((iVar8 >> 0x10 & 0xfU) - 8) / 340.0 + fVar12;
        *(float *)(iVar6 + 0x14) = fVar9 + (float)(int)((uVar4 & 0xf) - 8) / 540.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar7;
        }
        *(undefined4 *)(iVar3 + 0x28) = 0x40900000;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar7;
        }
        *(undefined4 *)(iVar3 + 0x2c) = 0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar7;
        }
        *(undefined4 *)(iVar3 + 0x30) = 0x3f490fdb;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar7;
        }
        *(undefined4 *)(iVar3 + 0x34) = 0x7f7f7f7f;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar7;
        }
        *(undefined4 *)(iVar3 + 0x38) = 0x7f7f7f7f;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + iVar7;
        }
        *(undefined4 *)(iVar3 + 0x3c) = 0x20000;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x54) + iVar7;
        }
        *(undefined1 *)(iVar7 + 0x40) = 0;
        local_18 = (float)((int)local_18 + 1);
      } while ((int)local_18 < *(int *)(in_ECX + 0x50));
    }
  }
LAB_004a61fb:
  if ((*(int *)(in_ECX + 0x48) < *(int *)(in_ECX + 0x4c) + -1) &&
     (iVar1 = 0, 0 < *(int *)(in_ECX + 0x4c))) {
    local_1c = 0;
    do {
      if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar3;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x54);
        iVar8 = iVar3 + local_1c;
      }
      if (*(int *)(iVar8 + 0x2c) != -10000) {
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar3;
        }
        else {
          iVar8 = local_1c + iVar3;
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar5 = *(float **)(in_ECX + 0x54);
        }
        else {
          pfVar5 = (float *)(iVar3 + local_1c);
        }
        *pfVar5 = *(float *)(iVar8 + 0xc) + *pfVar5;
        pfVar5[1] = *(float *)(iVar8 + 0x10) + pfVar5[1];
        pfVar5[2] = *(float *)(iVar8 + 0x14) + pfVar5[2];
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_1c;
        }
        *(float *)(iVar3 + 0xc) = *(float *)(iVar3 + 0xc) + 0.0;
        *(float *)(iVar3 + 0x10) = *(float *)(iVar3 + 0x10) + 0.008;
        *(float *)(iVar3 + 0x14) = *(float *)(iVar3 + 0x14) + 0.0;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_18 = *(float *)(in_ECX + 0x54);
          iVar3 = (int)local_18;
        }
        else {
          local_18 = *(float *)(in_ECX + 0x54);
          iVar3 = (int)local_18 + local_1c;
        }
        if (*(int *)(iVar3 + 0x2c) < 0x10) {
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(in_ECX + 0x54);
            local_18 = (float)iVar3;
          }
          else {
            iVar3 = (int)local_18 + local_1c;
          }
          local_14 = 7 - *(int *)(iVar3 + 0x2c) / 2;
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_18 = *(float *)(in_ECX + 0x54);
          }
          else {
            local_18 = (float)((int)local_18 + local_1c);
          }
        }
        else {
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(in_ECX + 0x54);
            local_18 = (float)iVar3;
          }
          else {
            iVar3 = (int)local_18 + local_1c;
          }
          local_14 = (*(int *)(iVar3 + 0x2c) + -0x10) / 2;
          if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_18 = *(float *)(in_ECX + 0x54);
          }
          else {
            local_18 = (float)((int)local_18 + local_1c);
          }
        }
        uVar4 = local_14 & 0x80000003;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
        }
        *(uint *)((int)local_18 + 0x3c) =
             (((int)(local_14 + ((int)local_14 >> 0x1f & 3U)) >> 2) + 2) * 0x10000 | uVar4;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          local_10 = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_1c;
          local_10 = *(int *)(in_ECX + 0x54);
        }
        local_18 = *(float *)(iVar3 + 0x10);
        fVar11 = local_18 * local_18 + *(float *)(iVar3 + 0x14) * *(float *)(iVar3 + 0x14);
        if (fVar11 == 0.0) {
          local_18 = 0.0;
        }
        else {
          dVar10 = (double)fVar11;
          if (dVar10 < 0.0) {
            __libm_sse2_sqrt_precise();
          }
          else {
            dVar10 = SQRT(dVar10);
          }
          local_18 = local_18 / (float)dVar10;
          if (*(float *)(iVar3 + 0x14) <= 0.0) {
            if (local_18 < 1.0) {
              if (-1.0 < local_18) {
                FUN_0040b6e0();
              }
              else {
                local_18 = 3.1415927;
              }
            }
            else {
              local_18 = 0.0;
            }
            local_18 = -local_18;
          }
          else if (1.0 <= local_18) {
            local_18 = 0.0;
          }
          else if (-1.0 < local_18) {
            FUN_0040b6e0();
          }
          else {
            local_18 = 3.1415927;
          }
        }
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_10 = *(int *)(in_ECX + 0x54);
        }
        else {
          local_10 = local_10 + local_1c;
        }
        *(float *)(local_10 + 0x30) =
             *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x164) * local_18 + 0.7853982;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_1c;
        }
        *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + 1;
        if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(in_ECX + 0x54);
          iVar8 = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0x54) + local_1c;
          iVar8 = *(int *)(in_ECX + 0x54);
        }
        if (*(int *)(iVar3 + 0x2c) < 0x20) {
          fVar11 = *(float *)(in_ECX + 0x60);
          if (fVar11 != 0.0) {
            if ((iVar1 < 0) || (*(int *)(in_ECX + 0x58) <= iVar1)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar5 = *(float **)(in_ECX + 0x54);
              fVar11 = *(float *)(in_ECX + 0x60);
            }
            else {
              pfVar5 = (float *)(local_1c + iVar8);
            }
            fVar13 = *(float *)(in_ECX + 0x10) - pfVar5[1];
            fVar12 = *(float *)(in_ECX + 0xc) - *pfVar5;
            fVar9 = *(float *)(in_ECX + 0x14) - pfVar5[2];
            if (fVar11 < fVar13 * fVar13 + fVar12 * fVar12 + fVar9 * fVar9) goto LAB_004a6690;
          }
        }
        else {
LAB_004a6690:
          FUN_00493010(iVar1);
        }
      }
      iVar1 = iVar1 + 1;
      local_1c = local_1c + 0x44;
    } while (iVar1 < *(int *)(in_ECX + 0x4c));
  }
  return;
}

