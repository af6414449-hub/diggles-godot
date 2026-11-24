
void __thiscall FUN_004cc040(CSceneRenderer *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  uint uVar7;
  bool bVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  double dVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float *in_stack_00000004;
  float *in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  float in_stack_0000001c;
  float in_stack_00000020;
  int local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  float local_3c;
  float local_38;
  float local_34;
  
  iVar1 = (int)ROUND(*in_stack_00000004 * 256.0);
  iVar2 = 0x100 - iVar1;
  fVar15 = *in_stack_00000004;
  DAT_00772dd8 = (uint)ROUND(in_stack_00000004[1] * 256.0);
  fVar11 = in_stack_00000004[1];
  iVar3 = 0x100 - DAT_00772dd8;
  fVar19 = (1.0 - fVar11) *
           ((float)this->cornerRGBA[8] * (1.0 - fVar15) + (float)this->cornerRGBA[9] * fVar15) +
           fVar11 * ((float)this->cornerRGBA[10] * (1.0 - fVar15) +
                    (float)this->cornerRGBA[0xb] * fVar15);
  iVar5 = (int)((this->cornerRGBA[4] * iVar2 + this->cornerRGBA[5] * iVar1) * iVar3 +
               (this->cornerRGBA[6] * iVar2 + this->cornerRGBA[7] * iVar1) * DAT_00772dd8) >> 0xf;
  local_48 = (int)((this->cornerRGBA[0xc] * iVar2 + this->cornerRGBA[0xd] * iVar1) * iVar3 +
                  (this->cornerRGBA[0xe] * iVar2 + this->cornerRGBA[0xf] * iVar1) * DAT_00772dd8) >>
             0x10;
  fVar15 = (float)(((int)((this->cornerRGBA[0] * iVar2 + this->cornerRGBA[1] * iVar1) * iVar3 +
                         (this->cornerRGBA[2] * iVar2 + this->cornerRGBA[3] * iVar1) * DAT_00772dd8)
                   >> 0x14) + 0x40) *
           ((*in_stack_00000008 * -2.546 - in_stack_00000008[1] * 2.546) +
            in_stack_00000008[2] * 0.0 + 3.6);
  fVar14 = fVar15;
  fVar17 = fVar15;
  if (iVar5 != 0) {
    if (iVar5 < 1) {
      if (this->field_0x5 == '\0') {
        fVar15 = fVar15 * ((float)iVar5 * 0.00390625 + 1.0);
        fVar14 = fVar15;
        fVar17 = fVar15;
      }
      else {
        local_48 = iVar5 + 0x100;
      }
    }
    else {
      fVar14 = in_stack_00000004[2];
      fVar17 = *in_stack_00000004;
      local_44 = 0;
      local_3c = 0.0;
      local_38 = 0.0;
      local_34 = 0.0;
      if (0 < this->statB) {
        bVar8 = this->statB != 0;
        local_4c = 0;
        do {
          if (!bVar8) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          pfVar6 = (float *)(this->statA + local_4c);
          fVar16 = *pfVar6 - ((float)in_stack_0000000c + fVar17);
          fVar18 = pfVar6[2] - fVar14;
          fVar9 = pfVar6[1] - ((float)in_stack_00000010 + fVar11);
          fVar13 = fVar9 * fVar9 + fVar16 * fVar16 + fVar18 * fVar18;
          if (fVar13 < pfVar6[3]) {
            dVar12 = (double)fVar13;
            if (dVar12 < 0.0) {
              __libm_sse2_sqrt_precise();
            }
            else {
              dVar12 = SQRT(dVar12);
            }
            fVar10 = (float)dVar12;
            dVar12 = (double)(-fVar13 / pfVar6[3] + -fVar13 / pfVar6[3]);
            FUN_006f5ca0();
            fVar13 = (fVar9 / fVar10) * in_stack_00000008[1] +
                     (fVar16 / fVar10) * *in_stack_00000008 +
                     (fVar18 / fVar10) * in_stack_00000008[2];
            fVar9 = 0.1;
            if (0.1 <= fVar13) {
              fVar9 = fVar13;
            }
            fVar9 = (float)dVar12 * fVar9;
            local_3c = pfVar6[4] * fVar9 + local_3c;
            local_38 = pfVar6[5] * fVar9 + local_38;
            local_34 = pfVar6[6] * fVar9 + local_34;
          }
          local_44 = local_44 + 1;
          local_4c = local_4c + 0x1c;
          bVar8 = local_44 < (uint)this->statB;
        } while ((int)local_44 < this->statB);
      }
      if (0xff < iVar5) {
        iVar5 = 0xff;
      }
      fVar11 = (float)iVar5;
      fVar14 = fVar11 * local_38 + fVar15;
      fVar17 = fVar15 + fVar11 * local_34;
      fVar15 = fVar11 * local_3c + fVar15;
    }
  }
  uVar7 = (uint)ROUND(this->fogScale * fVar15);
  uVar4 = (uint)ROUND(this->fogScale * fVar14);
  DAT_00772dd8 = (uint)ROUND(this->fogScale * fVar17);
  local_38 = (float)0xff;
  if ((int)uVar7 < 0xff) {
    local_38 = (float)uVar7;
  }
  iVar1 = 0;
  if (0xfe < (int)uVar7) {
    iVar1 = uVar7 - 0xff;
  }
  if (0x40 < iVar1) {
    iVar1 = 0x40;
  }
  local_3c = (float)0xff;
  if ((int)uVar4 < 0xff) {
    local_3c = (float)uVar4;
  }
  uVar7 = 0;
  if (0xfe < (int)uVar4) {
    uVar7 = uVar4 - 0xff;
  }
  if (0x40 < (int)uVar7) {
    uVar7 = 0x40;
  }
  local_40 = 0xff;
  if ((int)DAT_00772dd8 < 0xff) {
    local_40 = DAT_00772dd8;
  }
  uVar4 = 0;
  if (0xfe < (int)DAT_00772dd8) {
    uVar4 = DAT_00772dd8 - 0xff;
  }
  if (0x40 < (int)uVar4) {
    uVar4 = 0x40;
  }
  if (fVar19 != 0.0) {
    fVar19 = (1.0 - (in_stack_00000004[2] - 7.0) * 0.125 * 1.02) * fVar19;
    fVar15 = 0.0;
    if (0.0 <= fVar19) {
      fVar15 = fVar19;
    }
    fVar11 = 1.0;
    if (fVar15 <= 1.0) {
      fVar11 = fVar15;
    }
    DAT_00772dd8 = (uint)ROUND(fVar11 * 65536.0);
    iVar5 = 0x10000 - DAT_00772dd8;
    if (this->field_0x5 == '\0') {
      local_38 = (float)((int)local_38 * iVar5 >> 0x10);
      local_3c = (float)((int)local_3c * iVar5 >> 0x10);
      local_40 = (int)(iVar5 * local_40) >> 0x10;
    }
    iVar1 = iVar1 + ((int)(iVar5 * iVar1 + DAT_00772dd8 * 0xaa) >> 0x10);
    uVar7 = uVar7 + ((int)(iVar5 * uVar7 + DAT_00772dd8 * 0xaa) >> 0x10);
    uVar4 = uVar4 + ((int)(iVar5 * uVar4 + DAT_00772dd8 * 0x9b) >> 0x10);
  }
  if ((int)local_38 < 0) {
    local_38 = 0.0;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if ((int)local_3c < 0) {
    local_3c = 0.0;
  }
  if ((int)uVar7 < 0) {
    uVar7 = 0;
  }
  if ((int)local_40 < 0) {
    local_40 = 0;
  }
  if ((int)uVar4 < 0) {
    uVar4 = 0;
  }
  if (0xff < (int)local_38) {
    local_38 = 3.57331e-43;
  }
  if (0xff < (int)local_3c) {
    local_3c = 3.57331e-43;
  }
  if (0xff < (int)local_40) {
    local_40 = 0xff;
  }
  in_stack_00000004[3] =
       (float)((((uint)local_38 | local_48 << 8) << 8 | (uint)local_3c) << 8 | local_40);
  if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  if (0xff < (int)uVar7) {
    uVar7 = 0xff;
  }
  if (0xff < (int)uVar4) {
    uVar4 = 0xff;
  }
  in_stack_00000004[4] = (float)((iVar1 << 8 | uVar7) << 8 | uVar4);
  if (DAT_00768381 != '\0') {
    fVar15 = 0.0;
    if (0.0 <= *in_stack_00000004) {
      fVar15 = *in_stack_00000004;
    }
    fVar11 = 1.0;
    if (fVar15 <= 1.0) {
      fVar11 = fVar15;
    }
    fVar15 = 0.0;
    if (0.0 <= in_stack_00000004[1]) {
      fVar15 = in_stack_00000004[1];
    }
    fVar14 = 1.0;
    if (fVar15 <= 1.0) {
      fVar14 = fVar15;
    }
    fVar13 = 1.0 - fVar11;
    fVar17 = 1.0 - fVar14;
    fVar15 = fVar17;
    FUN_004cba40();
    fVar19 = fVar15 * in_stack_0000001c * fVar13;
    fVar15 = fVar19;
    FUN_004cba40();
    fVar15 = fVar15 * in_stack_00000020 * fVar11;
    fVar19 = fVar19 + fVar15;
    FUN_004cba40();
    fVar9 = fVar15 * in_stack_00000018 * fVar11;
    fVar15 = fVar9;
    FUN_004cba40();
    fVar15 = (fVar19 * fVar14 + (fVar9 + fVar15 * in_stack_00000014 * fVar13) * fVar17) * 0.5 +
             in_stack_00000004[2];
    in_stack_00000004[2] = fVar15;
    FUN_004cbc40();
    fVar19 = fVar15 * in_stack_00000020 * fVar11;
    fVar15 = fVar19;
    FUN_004cbc40();
    fVar15 = fVar15 * in_stack_0000001c * fVar13;
    fVar19 = fVar19 + fVar15;
    FUN_004cbc40();
    fVar13 = fVar15 * in_stack_00000014 * fVar13;
    fVar15 = fVar13;
    FUN_004cbc40();
    fVar11 = (fVar19 * fVar14 + (fVar13 + fVar15 * in_stack_00000018 * fVar11) * fVar17) * 0.3 +
             *in_stack_00000004;
    fVar15 = 0.0;
    if (0.0 <= fVar11) {
      fVar15 = fVar11;
    }
    *in_stack_00000004 = fVar11;
    fVar11 = 1.0;
    if (fVar15 <= 1.0) {
      fVar11 = fVar15;
    }
    fVar15 = fVar11;
    FUN_004cbe40();
    fVar19 = fVar15 * in_stack_00000020 * fVar11;
    fVar15 = fVar19;
    FUN_004cbe40();
    fVar15 = fVar15 * in_stack_0000001c * (1.0 - fVar11);
    fVar19 = fVar19 + fVar15;
    FUN_004cbe40();
    fVar9 = fVar15 * in_stack_00000014 * (1.0 - fVar11);
    fVar15 = fVar9;
    FUN_004cbe40();
    in_stack_00000004[1] =
         (fVar19 * fVar14 + (fVar9 + fVar15 * in_stack_00000018 * fVar11) * fVar17) * 0.1 +
         in_stack_00000004[1];
  }
  return;
}

