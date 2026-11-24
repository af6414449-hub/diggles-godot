
void FUN_1002ce10(uint param_1)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  undefined1 auVar4 [13];
  undefined1 auVar5 [13];
  undefined1 auVar6 [13];
  undefined1 auVar7 [13];
  float *pfVar8;
  float *in_ECX;
  uint uVar9;
  float *in_EDX;
  byte *pbVar10;
  int iVar11;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (((in_ECX != (float *)0x0) && (in_EDX != (float *)0x0)) && (uVar9 = 0, param_1 != 0)) {
    if ((0xf < param_1) &&
       (((float *)((param_1 - 1) + (int)in_EDX) < in_ECX || (in_ECX + (param_1 - 1) < in_EDX)))) {
      pfVar8 = in_EDX + 2;
      do {
        fVar2 = pfVar8[-2];
        uVar9 = uVar9 + 0x10;
        auVar4[0xc] = (char)((uint)fVar2 >> 0x18);
        auVar4._0_12_ = ZEXT712(0);
        fVar3 = pfVar8[-1];
        *in_ECX = (float)((uint)fVar2 & 0xff) * 0.007843138 - 1.0;
        in_ECX[1] = (float)((uint)fVar2 >> 8 & 0xff) * 0.007843138 - 1.0;
        in_ECX[2] = (float)(int)CONCAT32(auVar4._10_3_,(ushort)(byte)((uint)fVar2 >> 0x10)) *
                    0.007843138 - 1.0;
        in_ECX[3] = (float)(uint3)(auVar4._10_3_ >> 0x10) * 0.007843138 - 1.0;
        auVar5[0xc] = (char)((uint)fVar3 >> 0x18);
        auVar5._0_12_ = ZEXT712(0);
        fVar2 = *pfVar8;
        in_ECX[4] = (float)((uint)fVar3 & 0xff) * 0.007843138 - 1.0;
        in_ECX[5] = (float)((uint)fVar3 >> 8 & 0xff) * 0.007843138 - 1.0;
        in_ECX[6] = (float)(int)CONCAT32(auVar5._10_3_,(ushort)(byte)((uint)fVar3 >> 0x10)) *
                    0.007843138 - 1.0;
        in_ECX[7] = (float)(uint3)(auVar5._10_3_ >> 0x10) * 0.007843138 - 1.0;
        auVar6[0xc] = (char)((uint)fVar2 >> 0x18);
        auVar6._0_12_ = ZEXT712(0);
        fVar3 = pfVar8[1];
        pfVar8 = pfVar8 + 4;
        in_ECX[8] = (float)((uint)fVar2 & 0xff) * 0.007843138 - 1.0;
        in_ECX[9] = (float)((uint)fVar2 >> 8 & 0xff) * 0.007843138 - 1.0;
        in_ECX[10] = (float)(int)CONCAT32(auVar6._10_3_,(ushort)(byte)((uint)fVar2 >> 0x10)) *
                     0.007843138 - 1.0;
        in_ECX[0xb] = (float)(uint3)(auVar6._10_3_ >> 0x10) * 0.007843138 - 1.0;
        auVar7[0xc] = (char)((uint)fVar3 >> 0x18);
        auVar7._0_12_ = ZEXT712(0);
        in_ECX[0xc] = (float)((uint)fVar3 & 0xff) * 0.007843138 - 1.0;
        in_ECX[0xd] = (float)((uint)fVar3 >> 8 & 0xff) * 0.007843138 - 1.0;
        in_ECX[0xe] = (float)(int)CONCAT32(auVar7._10_3_,(ushort)(byte)((uint)fVar3 >> 0x10)) *
                      0.007843138 - 1.0;
        in_ECX[0xf] = (float)(uint3)(auVar7._10_3_ >> 0x10) * 0.007843138 - 1.0;
        in_ECX = in_ECX + 0x10;
      } while (uVar9 < (param_1 & 0xfffffff0));
      if (param_1 <= uVar9) {
        return;
      }
    }
    if (3 < param_1 - uVar9) {
      pbVar10 = (byte *)((int)in_EDX + uVar9 + 2);
      iVar11 = ((param_1 - uVar9) - 4 >> 2) + 1;
      uVar9 = uVar9 + iVar11 * 4;
      do {
        *in_ECX = (float)pbVar10[-2] * 0.007843138 - 1.0;
        in_ECX[1] = (float)pbVar10[-1] * 0.007843138 - 1.0;
        in_ECX[2] = (float)*pbVar10 * 0.007843138 - 1.0;
        pbVar1 = pbVar10 + 1;
        pbVar10 = pbVar10 + 4;
        in_ECX[3] = (float)*pbVar1 * 0.007843138 - 1.0;
        in_ECX = in_ECX + 4;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      if (param_1 <= uVar9) {
        return;
      }
    }
    do {
      pbVar10 = (byte *)(uVar9 + (int)in_EDX);
      uVar9 = uVar9 + 1;
      *in_ECX = (float)*pbVar10 * 0.007843138 - 1.0;
      in_ECX = in_ECX + 1;
    } while (uVar9 < param_1);
  }
  return;
}

