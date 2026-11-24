
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffa0 : 0x1001b7b6 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_1001b620(int *param_1,int *param_2,int param_3,float param_4,float param_5)

{
  float *pfVar1;
  float fVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int in_ECX;
  int iVar10;
  int iVar11;
  uint uVar12;
  float fVar13;
  undefined1 auVar14 [16];
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  uint local_78;
  float *local_70 [4];
  float local_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  uint local_14;
  
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffff0;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar12 = param_3 + 3U >> 2;
  fVar15 = (param_5 - param_4) /
           (float)((double)param_3 + *(double *)(&DAT_10047c80 + (param_3 >> 0x1f) * -8));
  if ((*(byte *)(in_ECX + 0x1054) & 1) == 0) {
    fVar2 = *(float *)(in_ECX + 0x105c);
    memset(local_70,0,0x54);
    iVar10 = 0;
    local_78 = 0;
    iVar11 = 0;
    fVar13 = fVar15 + param_4 + fVar15;
    fVar17 = fVar15 * 4.0;
    fVar9 = fVar13 + fVar15;
    if (*(int *)(in_ECX + 0x1044) != 0) {
      auVar3._8_4_ = 0xbf800000;
      auVar3._0_8_ = 0xbf800000bf800000;
      auVar3._12_4_ = 0xbf800000;
      auVar4._8_4_ = 0x3f800000;
      auVar4._0_8_ = 0x3f8000003f800000;
      auVar4._12_4_ = 0x3f800000;
      uVar5 = uVar12;
      fVar6 = local_60;
      fVar7 = fStack_5c;
      fVar8 = fStack_58;
      fVar16 = fStack_54;
      do {
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          pfVar1 = (float *)(*param_1 + iVar10 * 4);
          iVar10 = iVar10 + 4;
          auVar14._0_4_ = *pfVar1 * fVar6;
          auVar14._4_4_ = pfVar1[1] * fVar7;
          auVar14._8_4_ = pfVar1[2] * fVar8;
          auVar14._12_4_ = pfVar1[3] * fVar16;
          auVar14 = maxps(auVar14,auVar3);
          auVar14 = minps(auVar14,auVar4);
          pfVar1 = (float *)(*param_2 + iVar11 * 4);
          *pfVar1 = auVar14._0_4_ * fVar2;
          pfVar1[1] = auVar14._4_4_ * fVar2;
          pfVar1[2] = auVar14._8_4_ * fVar2;
          pfVar1[3] = auVar14._12_4_ * fVar2;
          iVar11 = iVar11 + 4;
          fVar6 = fVar6 + fVar17;
          fVar7 = fVar7 + fVar17;
          fVar8 = fVar8 + fVar17;
          fVar16 = fVar16 + fVar17;
        }
        local_78 = local_78 + 1;
        uVar5 = uVar12;
        fVar6 = local_60;
        fVar7 = fStack_5c;
        fVar8 = fStack_58;
        fVar16 = fStack_54;
      } while (local_78 < *(uint *)(in_ECX + 0x1044));
    }
  }
  else {
    fVar2 = *(float *)(in_ECX + 0x105c);
    memset(local_70,0,0x54);
    iVar10 = 0;
    local_78 = 0;
    iVar11 = 0;
    fVar13 = fVar15 + param_4 + fVar15;
    fVar16 = fVar15 * 4.0;
    fVar9 = fVar13 + fVar15;
    uVar5 = uVar12;
    fVar17 = local_60;
    fVar6 = fStack_5c;
    fVar7 = fStack_58;
    fVar8 = fStack_54;
    if (*(int *)(in_ECX + 0x1044) != 0) {
      do {
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          pfVar1 = (float *)(*param_1 + iVar10 * 4);
          iVar10 = iVar10 + 4;
          fVar18 = *pfVar1 * fVar17;
          fVar19 = pfVar1[1] * fVar6;
          fVar20 = pfVar1[2] * fVar7;
          fVar21 = pfVar1[3] * fVar8;
          pfVar1 = (float *)(*param_2 + iVar11 * 4);
          *pfVar1 = ((float)((uint)((float)((uint)(fVar18 * fVar18 * fVar18 * -0.1 + fVar18 * 0.87)
                                           & -(uint)(-1.65 < fVar18)) +
                                   (float)(~-(uint)(-1.65 < fVar18) & 0xbf7c7d56)) &
                            -(uint)(fVar18 < 1.65)) + (float)(~-(uint)(fVar18 < 1.65) & 0x3f7c7d56))
                    * fVar2;
          pfVar1[1] = ((float)((uint)((float)((uint)(fVar19 * fVar19 * fVar19 * -0.1 + fVar19 * 0.87
                                                    ) & -(uint)(-1.65 < fVar19)) +
                                     (float)(~-(uint)(-1.65 < fVar19) & 0xbf7c7d56)) &
                              -(uint)(fVar19 < 1.65)) +
                      (float)(~-(uint)(fVar19 < 1.65) & 0x3f7c7d56)) * fVar2;
          pfVar1[2] = ((float)((uint)((float)((uint)(fVar20 * fVar20 * fVar20 * -0.1 + fVar20 * 0.87
                                                    ) & -(uint)(-1.65 < fVar20)) +
                                     (float)(~-(uint)(-1.65 < fVar20) & 0xbf7c7d56)) &
                              -(uint)(fVar20 < 1.65)) +
                      (float)(~-(uint)(fVar20 < 1.65) & 0x3f7c7d56)) * fVar2;
          pfVar1[3] = ((float)((uint)((float)((uint)(fVar21 * fVar21 * fVar21 * -0.1 + fVar21 * 0.87
                                                    ) & -(uint)(-1.65 < fVar21)) +
                                     (float)(~-(uint)(-1.65 < fVar21) & 0xbf7c7d56)) &
                              -(uint)(fVar21 < 1.65)) +
                      (float)(~-(uint)(fVar21 < 1.65) & 0x3f7c7d56)) * fVar2;
          iVar11 = iVar11 + 4;
          fVar17 = fVar17 + fVar16;
          fVar6 = fVar6 + fVar16;
          fVar7 = fVar7 + fVar16;
          fVar8 = fVar8 + fVar16;
        }
        local_78 = local_78 + 1;
        uVar5 = uVar12;
        fVar17 = local_60;
        fVar6 = fStack_5c;
        fVar7 = fStack_58;
        fVar8 = fStack_54;
      } while (local_78 < *(uint *)(in_ECX + 0x1044));
    }
  }
  fStack_54 = fVar9;
  fStack_58 = fVar13;
  fStack_5c = fVar15 + param_4;
  local_60 = param_4;
  local_70[0] = &local_60;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffff0);
  return;
}

