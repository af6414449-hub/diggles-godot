
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002ba30(uint param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  uint in_ECX;
  uint in_EDX;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  double dVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  auVar3 = _DAT_10047d20;
  auVar2 = _DAT_10047c10;
  uVar4 = 0;
  if (param_1 != 0) {
    if ((3 < param_1) &&
       ((in_EDX + (param_1 - 1) * 8 < in_ECX || (in_ECX + (param_1 - 1) * 2 < in_EDX)))) {
      uVar18 = (uint)DAT_10047d20;
      uVar19 = DAT_10047d20._4_4_;
      uVar20 = DAT_10047d20._8_4_;
      uVar21 = DAT_10047d20._12_4_;
      do {
        auVar11 = *(undefined1 (*) [16])(in_EDX + uVar4 * 8);
        auVar8 = minpd(auVar2,auVar11);
        dVar1 = auVar3._0_8_;
        dVar7 = auVar3._8_8_;
        uVar5 = -(ulonglong)(auVar11._0_8_ < dVar1);
        lVar6 = -(ulonglong)(auVar11._8_8_ < dVar7);
        uVar16 = (uint)lVar6;
        uVar17 = (uint)((ulonglong)lVar6 >> 0x20);
        auVar12._8_4_ = uVar16;
        auVar12._0_8_ = uVar5;
        auVar12._12_4_ = uVar17;
        auVar13._0_8_ = ~uVar5 & auVar8._0_8_;
        auVar13._8_8_ = ~auVar12._8_8_ & auVar8._8_8_;
        auVar11._4_4_ = (uint)(uVar5 >> 0x20) & uVar19;
        auVar11._0_4_ = (uint)uVar5 & uVar18;
        auVar11._8_4_ = uVar16 & uVar20;
        auVar11._12_4_ = uVar17 & uVar21;
        auVar9._0_4_ = (int)((SUB168(auVar13 | auVar11,0) + auVar2._0_8_) * -32767.5);
        auVar9._4_4_ = (int)((SUB168(auVar13 | auVar11,8) + auVar2._8_8_) * -32767.5);
        auVar9._8_8_ = 0;
        auVar11 = *(undefined1 (*) [16])(in_EDX + 0x10 + uVar4 * 8);
        auVar8 = pshuflw(auVar9,auVar9,0xd8);
        auVar8 = pshufhw(auVar8,auVar8,0xd8);
        auVar9 = minpd(auVar2,auVar11);
        uVar5 = -(ulonglong)(auVar11._0_8_ < dVar1);
        lVar6 = -(ulonglong)(auVar11._8_8_ < dVar7);
        uVar16 = (uint)lVar6;
        uVar17 = (uint)((ulonglong)lVar6 >> 0x20);
        *(uint *)(in_ECX + uVar4 * 2) = CONCAT22(-0x8000 - auVar8._2_2_,-0x8000 - auVar8._0_2_);
        auVar14._8_4_ = uVar16;
        auVar14._0_8_ = uVar5;
        auVar14._12_4_ = uVar17;
        auVar15._0_8_ = ~uVar5 & auVar9._0_8_;
        auVar15._8_8_ = ~auVar14._8_8_ & auVar9._8_8_;
        auVar8._4_4_ = (uint)(uVar5 >> 0x20) & uVar19;
        auVar8._0_4_ = (uint)uVar5 & uVar18;
        auVar8._8_4_ = uVar16 & uVar20;
        auVar8._12_4_ = uVar17 & uVar21;
        auVar10._0_4_ = (int)((SUB168(auVar15 | auVar8,0) + auVar2._0_8_) * -32767.5);
        auVar10._4_4_ = (int)((SUB168(auVar15 | auVar8,8) + auVar2._8_8_) * -32767.5);
        auVar10._8_8_ = 0;
        auVar11 = pshuflw(auVar10,auVar10,0xd8);
        auVar11 = pshufhw(auVar11,auVar11,0xd8);
        *(uint *)(in_ECX + 4 + uVar4 * 2) =
             CONCAT22(-0x8000 - auVar11._2_2_,-0x8000 - auVar11._0_2_);
        uVar4 = uVar4 + 4;
      } while (uVar4 < (param_1 & 0xfffffffc));
      if (param_1 <= uVar4) {
        return;
      }
    }
    do {
      dVar1 = *(double *)(in_EDX + uVar4 * 8);
      if (-1.0 <= dVar1) {
        dVar7 = 1.0;
        if (dVar1 <= 1.0) {
          dVar7 = dVar1;
        }
      }
      else {
        dVar7 = -1.0;
      }
      *(short *)(in_ECX + uVar4 * 2) = -0x8000 - (short)(int)((dVar7 + 1.0) * -32767.5);
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_1);
  }
                    /* WARNING: Read-only address (ram,0x10047c10) is written */
                    /* WARNING: Read-only address (ram,0x10047d20) is written */
  return;
}

