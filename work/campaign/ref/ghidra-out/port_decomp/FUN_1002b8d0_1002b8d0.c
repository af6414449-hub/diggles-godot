
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002b8d0(uint param_1)

{
  undefined1 auVar1 [16];
  uint in_ECX;
  uint in_EDX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  auVar1 = _DAT_10047bb0;
  uVar2 = 0;
  if (param_1 != 0) {
    if ((7 < param_1) &&
       ((in_EDX + (param_1 - 1) * 4 < in_ECX || (in_ECX + (param_1 - 1) * 2 < in_EDX)))) {
      fVar10 = (float)DAT_10047bb0;
      fVar11 = DAT_10047bb0._4_4_;
      fVar12 = DAT_10047bb0._8_4_;
      fVar13 = DAT_10047bb0._12_4_;
      do {
        auVar9 = *(undefined1 (*) [16])(in_EDX + uVar2 * 4);
        auVar7 = minps(auVar1,auVar9);
        uVar3 = -(uint)(auVar9._0_4_ < -1.0);
        uVar4 = -(uint)(auVar9._4_4_ < -1.0);
        uVar5 = -(uint)(auVar9._8_4_ < -1.0);
        uVar6 = -(uint)(auVar9._12_4_ < -1.0);
        auVar8._0_4_ = (int)(((float)(~uVar3 & auVar7._0_4_ | uVar3 & 0xbf800000) + fVar10) *
                            -32767.5);
        auVar8._4_4_ = (int)(((float)(~uVar4 & auVar7._4_4_ | uVar4 & 0xbf800000) + fVar11) *
                            -32767.5);
        auVar8._8_4_ = (int)(((float)(~uVar5 & auVar7._8_4_ | uVar5 & 0xbf800000) + fVar12) *
                            -32767.5);
        auVar8._12_4_ =
             (int)(((float)(~uVar6 & auVar7._12_4_ | uVar6 & 0xbf800000) + fVar13) * -32767.5);
        auVar9 = *(undefined1 (*) [16])(in_EDX + 0x10 + uVar2 * 4);
        auVar7 = pshuflw(auVar8,auVar8,0xd8);
        auVar7 = pshufhw(auVar7,auVar7,0xd8);
        auVar8 = minps(auVar1,auVar9);
        uVar3 = -(uint)(auVar9._0_4_ < -1.0);
        uVar4 = -(uint)(auVar9._4_4_ < -1.0);
        uVar5 = -(uint)(auVar9._8_4_ < -1.0);
        uVar6 = -(uint)(auVar9._12_4_ < -1.0);
        *(ulonglong *)(in_ECX + uVar2 * 2) =
             CONCAT26(-0x8000 - auVar7._10_2_,
                      CONCAT24(-0x8000 - auVar7._8_2_,
                               CONCAT22(-0x8000 - auVar7._2_2_,-0x8000 - auVar7._0_2_)));
        auVar9._0_4_ = (int)(((float)(~uVar3 & auVar8._0_4_ | uVar3 & 0xbf800000) + fVar10) *
                            -32767.5);
        auVar9._4_4_ = (int)(((float)(~uVar4 & auVar8._4_4_ | uVar4 & 0xbf800000) + fVar11) *
                            -32767.5);
        auVar9._8_4_ = (int)(((float)(~uVar5 & auVar8._8_4_ | uVar5 & 0xbf800000) + fVar12) *
                            -32767.5);
        auVar9._12_4_ =
             (int)(((float)(~uVar6 & auVar8._12_4_ | uVar6 & 0xbf800000) + fVar13) * -32767.5);
        auVar9 = pshuflw(auVar9,auVar9,0xd8);
        auVar9 = pshufhw(auVar9,auVar9,0xd8);
        *(ulonglong *)(in_ECX + 8 + uVar2 * 2) =
             CONCAT26(-0x8000 - auVar9._10_2_,
                      CONCAT24(-0x8000 - auVar9._8_2_,
                               CONCAT22(-0x8000 - auVar9._2_2_,-0x8000 - auVar9._0_2_)));
        uVar2 = uVar2 + 8;
      } while (uVar2 < (param_1 & 0xfffffff8));
      if (param_1 <= uVar2) {
        return;
      }
    }
    do {
      fVar10 = *(float *)(in_EDX + uVar2 * 4);
      if (-1.0 <= fVar10) {
        fVar11 = 1.0;
        if (fVar10 <= 1.0) {
          fVar11 = fVar10;
        }
      }
      else {
        fVar11 = -1.0;
      }
      *(short *)(in_ECX + uVar2 * 2) = -0x8000 - (short)(int)((fVar11 + 1.0) * -32767.5);
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_1);
  }
                    /* WARNING: Read-only address (ram,0x10047bb0) is written */
  return;
}

