
void FUN_1002cfe0(uint param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 auVar3 [12];
  undefined1 auVar4 [12];
  undefined1 auVar5 [12];
  undefined1 auVar6 [12];
  float *pfVar7;
  float *in_ECX;
  uint uVar8;
  float *in_EDX;
  short *psVar9;
  int iVar10;
  undefined1 auVar11 [16];
  undefined1 auVar14 [16];
  undefined1 auVar17 [16];
  undefined1 auVar20 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined2 uVar23;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (((in_ECX != (float *)0x0) && (in_EDX != (float *)0x0)) && (uVar8 = 0, param_1 != 0)) {
    if ((0xf < param_1) &&
       (((float *)((int)in_EDX + (param_1 - 1) * 2) < in_ECX || (in_ECX + (param_1 - 1) < in_EDX))))
    {
      pfVar7 = in_EDX + 4;
      do {
        uVar2 = *(ulonglong *)(pfVar7 + -4);
        uVar23 = (undefined2)(uVar2 >> 0x30);
        auVar13._8_4_ = 0;
        auVar13._0_8_ = uVar2;
        auVar13._12_2_ = uVar23;
        auVar13._14_2_ = uVar23;
        uVar23 = (undefined2)(uVar2 >> 0x20);
        auVar12._12_4_ = auVar13._12_4_;
        auVar12._8_2_ = 0;
        auVar12._0_8_ = uVar2;
        auVar12._10_2_ = uVar23;
        auVar11._10_6_ = auVar12._10_6_;
        auVar11._8_2_ = uVar23;
        auVar11._0_8_ = uVar2;
        uVar23 = (undefined2)(uVar2 >> 0x10);
        auVar3._4_8_ = auVar11._8_8_;
        auVar3._2_2_ = uVar23;
        auVar3._0_2_ = uVar23;
        uVar8 = uVar8 + 0x10;
        *in_ECX = (float)(int)(short)uVar2 * 3.0517578e-05;
        in_ECX[1] = (float)(auVar3._0_4_ >> 0x10) * 3.0517578e-05;
        in_ECX[2] = (float)(auVar11._8_4_ >> 0x10) * 3.0517578e-05;
        in_ECX[3] = (float)(auVar12._12_4_ >> 0x10) * 3.0517578e-05;
        uVar2 = *(ulonglong *)(pfVar7 + -2);
        uVar23 = (undefined2)(uVar2 >> 0x30);
        auVar16._8_4_ = 0;
        auVar16._0_8_ = uVar2;
        auVar16._12_2_ = uVar23;
        auVar16._14_2_ = uVar23;
        uVar23 = (undefined2)(uVar2 >> 0x20);
        auVar15._12_4_ = auVar16._12_4_;
        auVar15._8_2_ = 0;
        auVar15._0_8_ = uVar2;
        auVar15._10_2_ = uVar23;
        auVar14._10_6_ = auVar15._10_6_;
        auVar14._8_2_ = uVar23;
        auVar14._0_8_ = uVar2;
        uVar23 = (undefined2)(uVar2 >> 0x10);
        auVar4._4_8_ = auVar14._8_8_;
        auVar4._2_2_ = uVar23;
        auVar4._0_2_ = uVar23;
        in_ECX[4] = (float)(int)(short)uVar2 * 3.0517578e-05;
        in_ECX[5] = (float)(auVar4._0_4_ >> 0x10) * 3.0517578e-05;
        in_ECX[6] = (float)(auVar14._8_4_ >> 0x10) * 3.0517578e-05;
        in_ECX[7] = (float)(auVar15._12_4_ >> 0x10) * 3.0517578e-05;
        uVar2 = *(ulonglong *)pfVar7;
        uVar23 = (undefined2)(uVar2 >> 0x30);
        auVar19._8_4_ = 0;
        auVar19._0_8_ = uVar2;
        auVar19._12_2_ = uVar23;
        auVar19._14_2_ = uVar23;
        uVar23 = (undefined2)(uVar2 >> 0x20);
        auVar18._12_4_ = auVar19._12_4_;
        auVar18._8_2_ = 0;
        auVar18._0_8_ = uVar2;
        auVar18._10_2_ = uVar23;
        auVar17._10_6_ = auVar18._10_6_;
        auVar17._8_2_ = uVar23;
        auVar17._0_8_ = uVar2;
        uVar23 = (undefined2)(uVar2 >> 0x10);
        auVar5._4_8_ = auVar17._8_8_;
        auVar5._2_2_ = uVar23;
        auVar5._0_2_ = uVar23;
        in_ECX[8] = (float)(int)(short)uVar2 * 3.0517578e-05;
        in_ECX[9] = (float)(auVar5._0_4_ >> 0x10) * 3.0517578e-05;
        in_ECX[10] = (float)(auVar17._8_4_ >> 0x10) * 3.0517578e-05;
        in_ECX[0xb] = (float)(auVar18._12_4_ >> 0x10) * 3.0517578e-05;
        uVar2 = *(ulonglong *)(pfVar7 + 2);
        uVar23 = (undefined2)(uVar2 >> 0x30);
        auVar22._8_4_ = 0;
        auVar22._0_8_ = uVar2;
        auVar22._12_2_ = uVar23;
        auVar22._14_2_ = uVar23;
        uVar23 = (undefined2)(uVar2 >> 0x20);
        auVar21._12_4_ = auVar22._12_4_;
        auVar21._8_2_ = 0;
        auVar21._0_8_ = uVar2;
        auVar21._10_2_ = uVar23;
        auVar20._10_6_ = auVar21._10_6_;
        auVar20._8_2_ = uVar23;
        auVar20._0_8_ = uVar2;
        uVar23 = (undefined2)(uVar2 >> 0x10);
        auVar6._4_8_ = auVar20._8_8_;
        auVar6._2_2_ = uVar23;
        auVar6._0_2_ = uVar23;
        in_ECX[0xc] = (float)(int)(short)uVar2 * 3.0517578e-05;
        in_ECX[0xd] = (float)(auVar6._0_4_ >> 0x10) * 3.0517578e-05;
        in_ECX[0xe] = (float)(auVar20._8_4_ >> 0x10) * 3.0517578e-05;
        in_ECX[0xf] = (float)(auVar21._12_4_ >> 0x10) * 3.0517578e-05;
        in_ECX = in_ECX + 0x10;
        pfVar7 = pfVar7 + 8;
      } while (uVar8 < (param_1 & 0xfffffff0));
      if (param_1 <= uVar8) {
        return;
      }
    }
    if (3 < param_1 - uVar8) {
      iVar1 = uVar8 * 2;
      iVar10 = ((param_1 - uVar8) - 4 >> 2) + 1;
      uVar8 = uVar8 + iVar10 * 4;
      psVar9 = (short *)((int)in_EDX + iVar1 + 4);
      do {
        *in_ECX = (float)(int)psVar9[-2] * 3.0517578e-05;
        in_ECX[1] = (float)(int)psVar9[-1] * 3.0517578e-05;
        in_ECX[2] = (float)(int)*psVar9 * 3.0517578e-05;
        in_ECX[3] = (float)(int)psVar9[1] * 3.0517578e-05;
        in_ECX = in_ECX + 4;
        iVar10 = iVar10 + -1;
        psVar9 = psVar9 + 4;
      } while (iVar10 != 0);
      if (param_1 <= uVar8) {
        return;
      }
    }
    do {
      iVar1 = uVar8 * 2;
      uVar8 = uVar8 + 1;
      *in_ECX = (float)(int)*(short *)((int)in_EDX + iVar1) * 3.0517578e-05;
      in_ECX = in_ECX + 1;
    } while (uVar8 < param_1);
  }
  return;
}

