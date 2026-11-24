
void FUN_1002aaf0(uint param_1,uint param_2)

{
  undefined2 *puVar1;
  ulonglong uVar2;
  undefined1 auVar3 [15];
  undefined1 auVar4 [15];
  undefined1 auVar5 [15];
  undefined1 auVar6 [15];
  undefined1 auVar7 [15];
  undefined1 auVar8 [15];
  undefined1 auVar9 [15];
  undefined1 auVar10 [15];
  undefined1 auVar11 [15];
  undefined1 auVar12 [15];
  undefined1 auVar13 [15];
  undefined1 auVar14 [15];
  undefined1 auVar15 [15];
  undefined1 auVar16 [15];
  undefined1 auVar17 [15];
  undefined1 auVar18 [15];
  undefined1 auVar19 [15];
  undefined1 auVar20 [15];
  undefined1 auVar21 [15];
  undefined1 auVar22 [15];
  undefined1 auVar23 [15];
  undefined1 auVar24 [15];
  undefined1 auVar25 [15];
  undefined1 auVar26 [15];
  undefined1 auVar27 [15];
  unkuint9 Var28;
  undefined1 auVar29 [11];
  undefined1 auVar30 [13];
  undefined1 auVar31 [15];
  undefined1 auVar32 [11];
  undefined1 auVar33 [13];
  undefined1 auVar34 [15];
  undefined1 auVar35 [11];
  undefined1 auVar36 [13];
  undefined1 auVar37 [15];
  undefined1 auVar38 [11];
  undefined1 auVar39 [13];
  undefined1 auVar40 [15];
  undefined1 auVar41 [15];
  undefined1 auVar42 [15];
  undefined1 auVar43 [15];
  undefined1 auVar44 [15];
  undefined1 auVar45 [15];
  undefined1 auVar46 [15];
  undefined1 auVar47 [15];
  ulonglong *puVar48;
  undefined8 *puVar49;
  undefined2 *in_ECX;
  undefined1 (*pauVar50) [16];
  undefined2 *in_EDX;
  uint uVar51;
  uint extraout_EDX;
  byte *pbVar52;
  undefined2 uVar53;
  int *piVar54;
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  uint local_20;
  undefined2 *local_1c;
  undefined4 uStack_10;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (param_2 == 1) {
    uVar51 = 0;
    if (param_1 != 0) {
      if ((0x1f < param_1) &&
         (((undefined2 *)((param_1 - 1) + (int)in_EDX) < in_ECX || (in_ECX + (param_1 - 1) < in_EDX)
          ))) {
        auVar63 = ZEXT416(8);
        puVar48 = (ulonglong *)(in_EDX + 8);
        pauVar50 = (undefined1 (*) [16])(in_ECX + 0x10);
        do {
          uVar2 = puVar48[-2];
          auVar3._8_6_ = 0;
          auVar3._0_8_ = uVar2;
          auVar3[0xe] = (char)(uVar2 >> 0x38);
          auVar7._8_4_ = 0;
          auVar7._0_8_ = uVar2;
          auVar7[0xc] = (char)(uVar2 >> 0x30);
          auVar7._13_2_ = auVar3._13_2_;
          auVar11._8_4_ = 0;
          auVar11._0_8_ = uVar2;
          auVar11._12_3_ = auVar7._12_3_;
          auVar15._8_2_ = 0;
          auVar15._0_8_ = uVar2;
          auVar15[10] = (char)(uVar2 >> 0x28);
          auVar15._11_4_ = auVar11._11_4_;
          auVar19._8_2_ = 0;
          auVar19._0_8_ = uVar2;
          auVar19._10_5_ = auVar15._10_5_;
          auVar23[8] = (char)(uVar2 >> 0x20);
          auVar23._0_8_ = uVar2;
          auVar23._9_6_ = auVar19._9_6_;
          auVar27._7_8_ = 0;
          auVar27._0_7_ = auVar23._8_7_;
          Var28 = CONCAT81(SUB158(auVar27 << 0x40,7),(char)(uVar2 >> 0x18));
          auVar40._9_6_ = 0;
          auVar40._0_9_ = Var28;
          auVar29._1_10_ = SUB1510(auVar40 << 0x30,5);
          auVar29[0] = (char)(uVar2 >> 0x10);
          auVar41._11_4_ = 0;
          auVar41._0_11_ = auVar29;
          auVar30._1_12_ = SUB1512(auVar41 << 0x20,3);
          auVar30[0] = (char)(uVar2 >> 8);
          uVar51 = uVar51 + 0x20;
          auVar58._0_2_ = (byte)uVar2 - 0x80;
          auVar58._2_2_ = auVar30._0_2_ + -0x80;
          auVar58._4_2_ = auVar29._0_2_ + -0x80;
          auVar58._6_2_ = (short)Var28 + -0x80;
          auVar58._8_2_ = auVar23._8_2_ + -0x80;
          auVar58._10_2_ = auVar15._10_2_ + -0x80;
          auVar58._12_2_ = auVar7._12_2_ + -0x80;
          auVar58._14_2_ = (auVar3._13_2_ >> 8) - 0x80;
          auVar59 = psllw(auVar58,auVar63);
          pauVar50[-2] = auVar59;
          uVar2 = puVar48[-1];
          auVar4._8_6_ = 0;
          auVar4._0_8_ = uVar2;
          auVar4[0xe] = (char)(uVar2 >> 0x38);
          auVar8._8_4_ = 0;
          auVar8._0_8_ = uVar2;
          auVar8[0xc] = (char)(uVar2 >> 0x30);
          auVar8._13_2_ = auVar4._13_2_;
          auVar12._8_4_ = 0;
          auVar12._0_8_ = uVar2;
          auVar12._12_3_ = auVar8._12_3_;
          auVar16._8_2_ = 0;
          auVar16._0_8_ = uVar2;
          auVar16[10] = (char)(uVar2 >> 0x28);
          auVar16._11_4_ = auVar12._11_4_;
          auVar20._8_2_ = 0;
          auVar20._0_8_ = uVar2;
          auVar20._10_5_ = auVar16._10_5_;
          auVar24[8] = (char)(uVar2 >> 0x20);
          auVar24._0_8_ = uVar2;
          auVar24._9_6_ = auVar20._9_6_;
          auVar31._7_8_ = 0;
          auVar31._0_7_ = auVar24._8_7_;
          Var28 = CONCAT81(SUB158(auVar31 << 0x40,7),(char)(uVar2 >> 0x18));
          auVar42._9_6_ = 0;
          auVar42._0_9_ = Var28;
          auVar32._1_10_ = SUB1510(auVar42 << 0x30,5);
          auVar32[0] = (char)(uVar2 >> 0x10);
          auVar43._11_4_ = 0;
          auVar43._0_11_ = auVar32;
          auVar33._1_12_ = SUB1512(auVar43 << 0x20,3);
          auVar33[0] = (char)(uVar2 >> 8);
          auVar60._0_2_ = (byte)uVar2 - 0x80;
          auVar60._2_2_ = auVar33._0_2_ + -0x80;
          auVar60._4_2_ = auVar32._0_2_ + -0x80;
          auVar60._6_2_ = (short)Var28 + -0x80;
          auVar60._8_2_ = auVar24._8_2_ + -0x80;
          auVar60._10_2_ = auVar16._10_2_ + -0x80;
          auVar60._12_2_ = auVar8._12_2_ + -0x80;
          auVar60._14_2_ = (auVar4._13_2_ >> 8) - 0x80;
          auVar59 = psllw(auVar60,auVar63);
          pauVar50[-1] = auVar59;
          uVar2 = *puVar48;
          auVar5._8_6_ = 0;
          auVar5._0_8_ = uVar2;
          auVar5[0xe] = (char)(uVar2 >> 0x38);
          auVar9._8_4_ = 0;
          auVar9._0_8_ = uVar2;
          auVar9[0xc] = (char)(uVar2 >> 0x30);
          auVar9._13_2_ = auVar5._13_2_;
          auVar13._8_4_ = 0;
          auVar13._0_8_ = uVar2;
          auVar13._12_3_ = auVar9._12_3_;
          auVar17._8_2_ = 0;
          auVar17._0_8_ = uVar2;
          auVar17[10] = (char)(uVar2 >> 0x28);
          auVar17._11_4_ = auVar13._11_4_;
          auVar21._8_2_ = 0;
          auVar21._0_8_ = uVar2;
          auVar21._10_5_ = auVar17._10_5_;
          auVar25[8] = (char)(uVar2 >> 0x20);
          auVar25._0_8_ = uVar2;
          auVar25._9_6_ = auVar21._9_6_;
          auVar34._7_8_ = 0;
          auVar34._0_7_ = auVar25._8_7_;
          Var28 = CONCAT81(SUB158(auVar34 << 0x40,7),(char)(uVar2 >> 0x18));
          auVar44._9_6_ = 0;
          auVar44._0_9_ = Var28;
          auVar35._1_10_ = SUB1510(auVar44 << 0x30,5);
          auVar35[0] = (char)(uVar2 >> 0x10);
          auVar45._11_4_ = 0;
          auVar45._0_11_ = auVar35;
          auVar36._1_12_ = SUB1512(auVar45 << 0x20,3);
          auVar36[0] = (char)(uVar2 >> 8);
          auVar61._0_2_ = (byte)uVar2 - 0x80;
          auVar61._2_2_ = auVar36._0_2_ + -0x80;
          auVar61._4_2_ = auVar35._0_2_ + -0x80;
          auVar61._6_2_ = (short)Var28 + -0x80;
          auVar61._8_2_ = auVar25._8_2_ + -0x80;
          auVar61._10_2_ = auVar17._10_2_ + -0x80;
          auVar61._12_2_ = auVar9._12_2_ + -0x80;
          auVar61._14_2_ = (auVar5._13_2_ >> 8) - 0x80;
          auVar59 = psllw(auVar61,auVar63);
          *pauVar50 = auVar59;
          uVar2 = puVar48[1];
          auVar6._8_6_ = 0;
          auVar6._0_8_ = uVar2;
          auVar6[0xe] = (char)(uVar2 >> 0x38);
          auVar10._8_4_ = 0;
          auVar10._0_8_ = uVar2;
          auVar10[0xc] = (char)(uVar2 >> 0x30);
          auVar10._13_2_ = auVar6._13_2_;
          auVar14._8_4_ = 0;
          auVar14._0_8_ = uVar2;
          auVar14._12_3_ = auVar10._12_3_;
          auVar18._8_2_ = 0;
          auVar18._0_8_ = uVar2;
          auVar18[10] = (char)(uVar2 >> 0x28);
          auVar18._11_4_ = auVar14._11_4_;
          auVar22._8_2_ = 0;
          auVar22._0_8_ = uVar2;
          auVar22._10_5_ = auVar18._10_5_;
          auVar26[8] = (char)(uVar2 >> 0x20);
          auVar26._0_8_ = uVar2;
          auVar26._9_6_ = auVar22._9_6_;
          auVar37._7_8_ = 0;
          auVar37._0_7_ = auVar26._8_7_;
          Var28 = CONCAT81(SUB158(auVar37 << 0x40,7),(char)(uVar2 >> 0x18));
          auVar46._9_6_ = 0;
          auVar46._0_9_ = Var28;
          auVar38._1_10_ = SUB1510(auVar46 << 0x30,5);
          auVar38[0] = (char)(uVar2 >> 0x10);
          auVar47._11_4_ = 0;
          auVar47._0_11_ = auVar38;
          auVar39._1_12_ = SUB1512(auVar47 << 0x20,3);
          auVar39[0] = (char)(uVar2 >> 8);
          auVar62._0_2_ = (byte)uVar2 - 0x80;
          auVar62._2_2_ = auVar39._0_2_ + -0x80;
          auVar62._4_2_ = auVar38._0_2_ + -0x80;
          auVar62._6_2_ = (short)Var28 + -0x80;
          auVar62._8_2_ = auVar26._8_2_ + -0x80;
          auVar62._10_2_ = auVar18._10_2_ + -0x80;
          auVar62._12_2_ = auVar10._12_2_ + -0x80;
          auVar62._14_2_ = (auVar6._13_2_ >> 8) - 0x80;
          auVar59 = psllw(auVar62,auVar63);
          pauVar50[1] = auVar59;
          puVar48 = puVar48 + 4;
          pauVar50 = pauVar50 + 4;
        } while (uVar51 < (param_1 & 0xffffffe0));
        if (param_1 <= uVar51) {
          return;
        }
      }
      do {
        in_ECX[uVar51] = (*(byte *)(uVar51 + (int)in_EDX) - 0x80) * 0x100;
        uVar51 = uVar51 + 1;
      } while (uVar51 < param_1);
      return;
    }
  }
  else if (param_2 == 2) {
    uVar51 = 0;
    if (param_1 != 0) {
      do {
        puVar1 = in_EDX + uVar51;
        uVar51 = uVar51 + 1;
        *in_ECX = *puVar1;
        in_ECX = in_ECX + 1;
      } while (uVar51 < param_1);
      return;
    }
  }
  else if (param_2 == 3) {
    uVar51 = 0;
    if (param_1 != 0) {
      pbVar52 = (byte *)((int)in_EDX + 1);
      do {
        in_ECX[uVar51] = (ushort)(((uint)pbVar52[1] << 0x18) >> 0x10) | (ushort)*pbVar52;
        uVar51 = uVar51 + 1;
        pbVar52 = pbVar52 + 3;
      } while (uVar51 < param_1);
      return;
    }
  }
  else if (param_2 == 4) {
    uVar51 = 0;
    if (param_1 != 0) {
      if ((0xf < param_1) &&
         ((in_EDX + (param_1 - 1) * 2 < in_ECX || (in_ECX + (param_1 - 1) < in_EDX)))) {
        auVar63 = ZEXT416(0x10);
        puVar49 = (undefined8 *)(in_ECX + 8);
        piVar54 = (int *)(in_EDX + 0x10);
        do {
          uVar51 = uVar51 + 0x10;
          auVar59._0_4_ = piVar54[-8] >> auVar63;
          auVar59._4_4_ = piVar54[-7] >> auVar63;
          auVar59._8_4_ = piVar54[-6] >> auVar63;
          auVar59._12_4_ = piVar54[-5] >> auVar63;
          auVar59 = pshuflw(auVar59,auVar59,0xd8);
          auVar59 = pshufhw(auVar59,auVar59,0xd8);
          puVar49[-2] = CONCAT44(auVar59._8_4_,auVar59._0_4_);
          auVar55._0_4_ = piVar54[-4] >> auVar63;
          auVar55._4_4_ = piVar54[-3] >> auVar63;
          auVar55._8_4_ = piVar54[-2] >> auVar63;
          auVar55._12_4_ = piVar54[-1] >> auVar63;
          auVar59 = pshuflw(auVar55,auVar55,0xd8);
          auVar59 = pshufhw(auVar59,auVar59,0xd8);
          puVar49[-1] = CONCAT44(auVar59._8_4_,auVar59._0_4_);
          auVar56._0_4_ = *piVar54 >> auVar63;
          auVar56._4_4_ = piVar54[1] >> auVar63;
          auVar56._8_4_ = piVar54[2] >> auVar63;
          auVar56._12_4_ = piVar54[3] >> auVar63;
          auVar59 = pshuflw(auVar56,auVar56,0xd8);
          auVar59 = pshufhw(auVar59,auVar59,0xd8);
          *puVar49 = CONCAT44(auVar59._8_4_,auVar59._0_4_);
          auVar57._0_4_ = piVar54[4] >> auVar63;
          auVar57._4_4_ = piVar54[5] >> auVar63;
          auVar57._8_4_ = piVar54[6] >> auVar63;
          auVar57._12_4_ = piVar54[7] >> auVar63;
          auVar59 = pshuflw(auVar57,auVar57,0xd8);
          auVar59 = pshufhw(auVar59,auVar59,0xd8);
          puVar49[1] = CONCAT44(auVar59._8_4_,auVar59._0_4_);
          puVar49 = puVar49 + 4;
          piVar54 = piVar54 + 0x10;
        } while (uVar51 < (param_1 & 0xfffffff0));
        if (param_1 <= uVar51) {
          return;
        }
      }
      do {
        in_ECX[uVar51] = in_EDX[uVar51 * 2 + 1];
        uVar51 = uVar51 + 1;
      } while (uVar51 < param_1);
      return;
    }
  }
  else {
    if (8 < param_2) {
      memset(in_ECX,0,param_1 * 2);
      return;
    }
    local_20 = param_1;
    local_1c = in_ECX;
    if (param_1 != 0) {
      do {
        uVar51 = 0;
        uStack_10 = 0;
        uStack_10._2_2_ = 0;
        uVar53 = uStack_10._2_2_;
        if (param_2 != 0) {
          do {
            __allshl();
            uStack_10 = uStack_10 | extraout_EDX;
            uVar53 = (undefined2)(uStack_10 >> 0x10);
            uVar51 = uVar51 + 1;
          } while (uVar51 < param_2);
        }
        *local_1c = uVar53;
        local_1c = local_1c + 1;
        local_20 = local_20 - 1;
      } while (local_20 != 0);
    }
  }
  return;
}

