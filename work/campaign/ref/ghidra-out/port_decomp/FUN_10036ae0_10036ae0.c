
/* WARNING: Removing unreachable block (ram,0x10036f8c) */
/* WARNING: Removing unreachable block (ram,0x10037a7f) */
/* WARNING: Removing unreachable block (ram,0x10037e05) */

uint FUN_10036ae0(uint param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  int in_EDX;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  float *pfVar18;
  bool bVar19;
  undefined1 auVar21 [16];
  undefined1 auVar23 [16];
  undefined1 auVar25 [16];
  undefined1 auVar27 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  float fVar36;
  float fVar37;
  uint uVar38;
  byte local_8c [12];
  undefined4 local_80;
  int iStack_7c;
  undefined8 local_78;
  int local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  char local_11;
  undefined1 auVar20 [16];
  undefined1 auVar22 [16];
  undefined1 auVar24 [16];
  undefined1 auVar26 [16];
  undefined1 auVar28 [16];
  
  local_28 = in_EDX;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  if (local_18 != 0) {
    local_48 = param_1;
    local_40 = param_2;
    if (param_1 != 0 || param_2 != 0) {
      if (in_EDX == 0) {
        uVar5 = FUN_100352f0(param_1,param_2);
        return uVar5;
      }
      local_80 = 0;
      iStack_7c = 0;
      local_34 = 0x20 - (uint)*(byte *)(local_18 + 0x1d);
      local_58 = 0;
      local_54 = 0;
      iVar14 = local_18;
      do {
        if (*(int *)(iVar14 + 0x48) == 0) {
          iVar6 = FUN_10035240();
          iVar14 = local_18;
          if (iVar6 == 0) {
            return local_54;
          }
        }
        else {
          local_11 = *(char *)(iVar14 + 0x42);
          iStack_7c = (uint)*(ushort *)(iVar14 + 0x40) - *(int *)(iVar14 + 0x48);
          local_8c[0] = 1;
          local_8c[1] = 2;
          local_8c[2] = 3;
          local_8c[3] = 4;
          local_8c[4] = 5;
          local_8c[5] = 6;
          local_8c[6] = 7;
          local_8c[7] = 8;
          local_8c[8] = 2;
          local_8c[9] = 2;
          local_8c[10] = 2;
          local_44 = (uint)local_8c[local_11];
          local_2c = local_48;
          local_1c = local_40;
          if ((local_40 != 0) || (in_EDX = local_28, *(uint *)(iVar14 + 0x48) < local_48)) {
            local_2c = *(uint *)(iVar14 + 0x48);
            local_1c = 0;
          }
          if (local_8c[local_11] == 2) {
            iVar6 = iStack_7c * 4;
            local_24 = *(int *)(iVar14 + 0x50) + iVar6;
            iVar6 = *(int *)(iVar14 + 0x58) + iVar6;
            local_20 = iVar6;
            iVar14 = local_18;
            if (local_11 == '\b') {
              if ((DAT_10051098 == 0) || (0x18 < *(byte *)(local_18 + 0x1d))) {
                uVar5 = local_2c >> 2 | local_1c << 0x1e;
                local_80 = 0;
                iStack_7c = 0;
                uVar16 = local_1c >> 2;
                local_5c = (uint)*(byte *)(local_18 + 0x55) + local_34;
                local_38 = (uint)*(byte *)(local_18 + 0x4d) + local_34;
                bVar10 = (byte)local_38;
                bVar9 = (byte)local_5c;
                if ((uVar16 != 0) || (uVar5 != 0)) {
                  local_60 = 0;
                  local_50 = 0;
                  do {
                    do {
                      iStack_7c = local_50 * 0x10;
                      local_80 = 0;
                      local_68 = *(int *)(iStack_7c + 8 + local_24) << (bVar10 & 0x1f);
                      iVar8 = *(int *)(iStack_7c + local_24) << (bVar10 & 0x1f);
                      local_4c = *(int *)(iStack_7c + 4 + local_24) << (bVar10 & 0x1f);
                      local_78 = CONCAT44(iVar8,(uint)local_78);
                      local_64 = *(int *)(iStack_7c + 0xc + local_24) << (bVar10 & 0x1f);
                      local_6c = iVar8 - (*(int *)(iStack_7c + iVar6) << (bVar9 & 0x1f));
                      iVar7 = *(int *)(iStack_7c + 4 + iVar6);
                      iVar13 = *(int *)(iStack_7c + 8 + iVar6);
                      iVar4 = *(int *)(iStack_7c + 0xc + iVar6);
                      iVar11 = local_50 * 0x20;
                      *(float *)(iVar11 + local_28) = (float)iVar8 * 4.656613e-10;
                      *(float *)(iVar11 + 4 + local_28) = (float)local_6c * 4.656613e-10;
                      *(float *)(iVar11 + 8 + local_28) = (float)(int)local_4c * 4.656613e-10;
                      *(float *)(iVar11 + 0xc + local_28) =
                           (float)(int)(local_4c - (iVar7 << (bVar9 & 0x1f))) * 4.656613e-10;
                      *(float *)(iVar11 + 0x10 + local_28) = (float)(int)local_68 * 4.656613e-10;
                      *(float *)(iVar11 + 0x14 + local_28) =
                           (float)(int)(local_68 - (iVar13 << (bVar9 & 0x1f))) * 4.656613e-10;
                      *(float *)(iVar11 + 0x18 + local_28) = (float)(int)local_64 * 4.656613e-10;
                      bVar19 = 0xfffffffe < local_50;
                      local_50 = local_50 + 1;
                      *(float *)(iVar11 + 0x1c + local_28) =
                           (float)(int)(local_64 - (iVar4 << (bVar9 & 0x1f))) * 4.656613e-10;
                      local_60 = local_60 + bVar19;
                    } while (local_60 < uVar16);
                    in_EDX = local_28;
                  } while ((local_60 <= uVar16) && (local_50 < uVar5));
                }
                local_80 = 0;
                local_3c = uVar16 << 2 | local_1c & 3;
                local_30 = (local_2c >> 2) << 2;
                if (local_3c <= local_1c) {
                  if (local_3c < local_1c) goto LAB_10037e26;
                  do {
                    if (local_2c <= local_30) break;
LAB_10037e26:
                    do {
                      iVar13 = *(int *)(local_24 + local_30 * 4) << (bVar10 & 0x1f);
                      iVar7 = *(int *)(iVar6 + local_30 * 4);
                      *(float *)(in_EDX + local_30 * 8) = (float)iVar13 * 4.656613e-10;
                      *(float *)(in_EDX + 4 + local_30 * 8) =
                           (float)(iVar13 - (iVar7 << (bVar9 & 0x1f))) * 4.656613e-10;
                      bVar19 = 0xfffffffe < local_30;
                      local_30 = local_30 + 1;
                      local_3c = local_3c + bVar19;
                    } while (local_3c < local_1c);
                  } while (local_3c <= local_1c);
                }
              }
              else {
                uVar5 = local_2c >> 2 | local_1c << 0x1e;
                local_80 = 0;
                iStack_7c = 0;
                uVar16 = local_1c >> 2;
                local_68 = (*(byte *)(local_18 + 0x4d) - 8) + local_34;
                local_64 = (uint)*(byte *)(local_18 + 0x55) + local_34 + -8;
                if ((uVar16 != 0) || (uVar5 != 0)) {
                  local_3c = 0;
                  local_50 = 0;
                  do {
                    do {
                      piVar2 = (int *)(local_24 + local_3c * 0x10);
                      iVar7 = piVar2[2];
                      iVar13 = piVar2[3];
                      piVar3 = (int *)(iVar6 + local_3c * 0x10);
                      iVar4 = piVar3[2];
                      iVar11 = piVar3[3];
                      iVar8 = local_3c * 0x20;
                      bVar19 = 0xfffffffe < local_3c;
                      local_3c = local_3c + 1;
                      local_50 = local_50 + bVar19;
                      fVar36 = (float)(*piVar2 << local_68) * 1.1920929e-07;
                      fVar37 = (float)piVar2[1] * 1.1920929e-07;
                      auVar29._4_4_ = fVar37;
                      auVar29._0_4_ = fVar36;
                      auVar29._8_4_ = fVar37;
                      auVar29._12_4_ = (float)(piVar2[1] - piVar3[1]) * 1.1920929e-07;
                      auVar28._8_8_ = auVar29._8_8_;
                      auVar28._4_4_ =
                           (float)((*piVar2 << local_68) - (*piVar3 << local_64)) * 1.1920929e-07;
                      auVar28._0_4_ = fVar36;
                      *(undefined1 (*) [16])(iVar8 + local_28) = auVar28;
                      pfVar18 = (float *)(iVar8 + 0x10 + local_28);
                      *pfVar18 = (float)iVar7 * 1.1920929e-07;
                      pfVar18[1] = (float)(iVar7 - iVar4) * 1.1920929e-07;
                      pfVar18[2] = (float)iVar13 * 1.1920929e-07;
                      pfVar18[3] = (float)(iVar13 - iVar11) * 1.1920929e-07;
                    } while (local_50 < uVar16);
                  } while ((local_50 <= uVar16) && (local_3c < uVar5));
                }
                local_30 = uVar16 << 2 | local_1c & 3;
                local_38 = (local_2c >> 2) << 2;
                in_EDX = local_28;
                if (local_30 <= local_1c) {
                  if (local_30 < local_1c) goto LAB_10037c11;
                  do {
                    if (local_2c <= local_38) break;
LAB_10037c11:
                    do {
                      iVar13 = *(int *)(local_24 + local_38 * 4) << ((byte)local_68 & 0x1f);
                      iVar7 = *(int *)(iVar6 + local_38 * 4);
                      *(float *)(local_28 + local_38 * 8) = (float)iVar13 * 1.1920929e-07;
                      *(float *)(local_28 + 4 + local_38 * 8) =
                           (float)(iVar13 - (iVar7 << ((byte)local_64 & 0x1f))) * 1.1920929e-07;
                      bVar19 = 0xfffffffe < local_38;
                      local_38 = local_38 + 1;
                      local_30 = local_30 + bVar19;
                    } while (local_30 < local_1c);
                  } while (local_30 <= local_1c);
                }
              }
            }
            else if (local_11 == '\t') {
              if ((DAT_10051098 == 0) || (0x18 < *(byte *)(local_18 + 0x1d))) {
                uVar5 = local_2c >> 2 | local_1c << 0x1e;
                local_80 = 0;
                iStack_7c = 0;
                uVar16 = local_1c >> 2;
                local_5c = (uint)*(byte *)(local_18 + 0x55) + local_34;
                local_38 = (uint)*(byte *)(local_18 + 0x4d) + local_34;
                bVar10 = (byte)local_5c;
                bVar9 = (byte)local_38;
                if ((uVar16 != 0) || (uVar5 != 0)) {
                  local_60 = 0;
                  local_50 = 0;
                  do {
                    do {
                      iStack_7c = local_50 * 0x10;
                      local_80 = 0;
                      local_68 = *(int *)(iStack_7c + iVar6) << (bVar10 & 0x1f);
                      local_4c = *(int *)(iStack_7c + 8 + iVar6) << (bVar10 & 0x1f);
                      local_6c = *(int *)(iStack_7c + 4 + iVar6) << (bVar10 & 0x1f);
                      local_64 = *(int *)(iStack_7c + 0xc + iVar6) << (bVar10 & 0x1f);
                      iVar7 = *(int *)(iStack_7c + 4 + local_24);
                      iVar13 = *(int *)(iStack_7c + 8 + local_24);
                      iVar4 = *(int *)(iStack_7c + 0xc + local_24);
                      iVar11 = local_50 * 0x20;
                      local_78 = CONCAT44(iVar11,(uint)local_78);
                      *(float *)(iVar11 + local_28) =
                           (float)(int)((*(int *)(iStack_7c + local_24) << (bVar9 & 0x1f)) +
                                       local_68) * 4.656613e-10;
                      *(float *)(iVar11 + 4 + local_28) = (float)(int)local_68 * 4.656613e-10;
                      *(float *)(iVar11 + 8 + local_28) =
                           (float)((iVar7 << (bVar9 & 0x1f)) + local_6c) * 4.656613e-10;
                      *(float *)(iVar11 + 0xc + local_28) = (float)local_6c * 4.656613e-10;
                      *(float *)(iVar11 + 0x10 + local_28) =
                           (float)(int)((iVar13 << (bVar9 & 0x1f)) + local_4c) * 4.656613e-10;
                      *(float *)(iVar11 + 0x14 + local_28) = (float)(int)local_4c * 4.656613e-10;
                      bVar19 = 0xfffffffe < local_50;
                      local_50 = local_50 + 1;
                      *(float *)(iVar11 + 0x18 + local_28) =
                           (float)(int)((iVar4 << (bVar9 & 0x1f)) + local_64) * 4.656613e-10;
                      *(float *)(iVar11 + 0x1c + local_28) = (float)(int)local_64 * 4.656613e-10;
                      local_60 = local_60 + bVar19;
                    } while (local_60 < uVar16);
                    in_EDX = local_28;
                  } while ((local_60 <= uVar16) && (local_50 < uVar5));
                }
                local_80 = 0;
                local_3c = uVar16 << 2 | local_1c & 3;
                local_30 = (local_2c >> 2) << 2;
                if (local_3c <= local_1c) {
                  if (local_3c < local_1c) goto LAB_10037aa7;
                  do {
                    if (local_2c <= local_30) break;
LAB_10037aa7:
                    do {
                      iVar7 = *(int *)(iVar6 + local_30 * 4) << (bVar10 & 0x1f);
                      *(float *)(in_EDX + local_30 * 8) =
                           (float)((*(int *)(local_24 + local_30 * 4) << (bVar9 & 0x1f)) + iVar7) *
                           4.656613e-10;
                      *(float *)(in_EDX + 4 + local_30 * 8) = (float)iVar7 * 4.656613e-10;
                      bVar19 = 0xfffffffe < local_30;
                      local_30 = local_30 + 1;
                      local_3c = local_3c + bVar19;
                    } while (local_3c < local_1c);
                  } while (local_3c <= local_1c);
                }
              }
              else {
                uVar5 = local_2c >> 2 | local_1c << 0x1e;
                local_80 = 0;
                iStack_7c = 0;
                uVar16 = local_1c >> 2;
                local_60 = (*(byte *)(local_18 + 0x4d) - 8) + local_34;
                local_64 = (uint)*(byte *)(local_18 + 0x55) + local_34 + -8;
                if ((uVar16 != 0) || (uVar5 != 0)) {
                  local_68 = 0;
                  local_50 = 0;
                  iVar7 = local_24;
                  do {
                    do {
                      piVar2 = (int *)(iVar6 + local_50 * 0x10);
                      iVar13 = piVar2[2];
                      iVar4 = piVar2[3];
                      piVar3 = (int *)(iVar7 + local_50 * 0x10);
                      iVar7 = piVar3[2];
                      iVar11 = piVar3[3];
                      fVar36 = (float)((*piVar3 << local_60) + (*piVar2 << local_64)) *
                               1.1920929e-07;
                      fVar37 = (float)(piVar3[1] + piVar2[1]) * 1.1920929e-07;
                      auVar27._4_4_ = fVar37;
                      auVar27._0_4_ = fVar36;
                      auVar27._8_4_ = fVar37;
                      auVar27._12_4_ = (float)piVar2[1] * 1.1920929e-07;
                      auVar26._8_8_ = auVar27._8_8_;
                      auVar26._4_4_ = (float)(*piVar2 << local_64) * 1.1920929e-07;
                      auVar26._0_4_ = fVar36;
                      *(undefined1 (*) [16])(local_50 * 0x20 + local_28) = auVar26;
                      pfVar18 = (float *)(local_50 * 0x20 + 0x10 + local_28);
                      *pfVar18 = (float)(iVar7 + iVar13) * 1.1920929e-07;
                      pfVar18[1] = (float)iVar13 * 1.1920929e-07;
                      pfVar18[2] = (float)(iVar11 + iVar4) * 1.1920929e-07;
                      pfVar18[3] = (float)iVar4 * 1.1920929e-07;
                      bVar19 = 0xfffffffe < local_50;
                      local_50 = local_50 + 1;
                      local_68 = local_68 + bVar19;
                      iVar7 = local_24;
                    } while (local_68 < uVar16);
                  } while ((local_68 <= uVar16) && (iVar7 = local_24, local_50 < uVar5));
                }
                local_38 = uVar16 << 2 | local_1c & 3;
                local_30 = (local_2c >> 2) << 2;
                in_EDX = local_28;
                if (local_38 <= local_1c) {
                  iVar7 = iVar6;
                  if (local_38 < local_1c) goto LAB_10037887;
                  do {
                    iVar7 = iVar6;
                    if (local_2c <= local_30) break;
LAB_10037887:
                    do {
                      iVar7 = *(int *)(iVar7 + local_30 * 4) << ((byte)local_64 & 0x1f);
                      *(float *)(local_28 + local_30 * 8) =
                           (float)((*(int *)(local_24 + local_30 * 4) << ((byte)local_60 & 0x1f)) +
                                  iVar7) * 1.1920929e-07;
                      *(float *)(local_28 + 4 + local_30 * 8) = (float)iVar7 * 1.1920929e-07;
                      bVar19 = 0xfffffffe < local_30;
                      local_30 = local_30 + 1;
                      local_38 = local_38 + bVar19;
                      iVar7 = local_20;
                    } while (local_38 < local_1c);
                  } while (local_38 <= local_1c);
                }
              }
            }
            else if (local_11 == '\n') {
              if ((DAT_10051098 == 0) || (0x18 < *(byte *)(local_18 + 0x1d))) {
                uVar5 = local_2c >> 2 | local_1c << 0x1e;
                local_78 = 0;
                uVar16 = local_1c >> 2;
                local_78._0_4_ = 0;
                if (local_34 < 1) {
                  if ((uVar16 != 0) || (uVar5 != 0)) {
                    local_3c = 0;
                    local_4c = (uint)local_78;
                    iVar7 = local_24;
                    do {
                      do {
                        bVar10 = *(byte *)(local_18 + 0x55);
                        local_64 = *(int *)(iVar6 + 4 + local_4c * 0x10) << (bVar10 & 0x1f);
                        local_68 = *(int *)(iVar6 + local_4c * 0x10) << (bVar10 & 0x1f);
                        local_60 = *(int *)(iVar6 + 8 + local_4c * 0x10) << (bVar10 & 0x1f);
                        local_5c = *(int *)(iVar6 + 0xc + local_4c * 0x10) << (bVar10 & 0x1f);
                        bVar10 = *(byte *)(local_18 + 0x4d);
                        uVar12 = (*(int *)(iVar7 + local_4c * 0x10) << (bVar10 & 0x1f)) * 2 |
                                 local_68 & 1;
                        uVar15 = (*(int *)(iVar7 + 4 + local_4c * 0x10) << (bVar10 & 0x1f)) * 2 |
                                 local_64 & 1;
                        local_50 = (*(int *)(local_24 + 8 + local_4c * 0x10) << (bVar10 & 0x1f)) * 2
                                   | local_60 & 1;
                        uVar17 = (*(int *)(local_24 + 0xc + local_4c * 0x10) << (bVar10 & 0x1f)) * 2
                                 | local_5c & 1;
                        iVar7 = local_4c * 0x20;
                        *(float *)(iVar7 + local_28) =
                             (float)((int)(local_68 + uVar12) >> 1) * 4.656613e-10;
                        *(float *)(iVar7 + 4 + local_28) =
                             (float)((int)(uVar12 - local_68) >> 1) * 4.656613e-10;
                        *(float *)(iVar7 + 8 + local_28) =
                             (float)((int)(local_64 + uVar15) >> 1) * 4.656613e-10;
                        *(float *)(iVar7 + 0xc + local_28) =
                             (float)((int)(uVar15 - local_64) >> 1) * 4.656613e-10;
                        *(float *)(iVar7 + 0x10 + local_28) =
                             (float)((int)(local_60 + local_50) >> 1) * 4.656613e-10;
                        *(float *)(iVar7 + 0x14 + local_28) =
                             (float)((int)(local_50 - local_60) >> 1) * 4.656613e-10;
                        *(float *)(iVar7 + 0x18 + local_28) =
                             (float)((int)(local_5c + uVar17) >> 1) * 4.656613e-10;
                        *(float *)(iVar7 + 0x1c + local_28) =
                             (float)((int)(uVar17 - local_5c) >> 1) * 4.656613e-10;
                        bVar19 = 0xfffffffe < local_4c;
                        local_4c = local_4c + 1;
                        local_3c = local_3c + bVar19;
                        iVar7 = local_24;
                      } while (local_3c < uVar16);
                      in_EDX = local_28;
                    } while ((local_3c <= uVar16) && (local_4c < uVar5));
                  }
                }
                else {
                  iStack_7c = local_34 + -1;
                  if ((uVar16 != 0) || (uVar5 != 0)) {
                    local_68 = 0;
                    local_4c = (uint)local_78;
                    do {
                      do {
                        bVar10 = *(byte *)(local_18 + 0x55);
                        local_3c = *(int *)(iVar6 + 4 + local_4c * 0x10) << (bVar10 & 0x1f);
                        local_5c = *(int *)(iVar6 + local_4c * 0x10) << (bVar10 & 0x1f);
                        local_60 = *(int *)(iVar6 + 8 + local_4c * 0x10) << (bVar10 & 0x1f);
                        local_64 = *(int *)(iVar6 + 0xc + local_4c * 0x10) << (bVar10 & 0x1f);
                        bVar10 = *(byte *)(local_18 + 0x4d);
                        uVar12 = (*(int *)(local_24 + local_4c * 0x10) << (bVar10 & 0x1f)) * 2 |
                                 local_5c & 1;
                        uVar17 = (*(int *)(local_24 + 4 + local_4c * 0x10) << (bVar10 & 0x1f)) * 2 |
                                 local_3c & 1;
                        local_50 = (*(int *)(local_24 + 8 + local_4c * 0x10) << (bVar10 & 0x1f)) * 2
                                   | local_60 & 1;
                        uVar15 = (*(int *)(local_24 + 0xc + local_4c * 0x10) << (bVar10 & 0x1f)) * 2
                                 | local_64 & 1;
                        local_78 = (ulonglong)uVar15 << 0x20;
                        bVar10 = (byte)(local_34 + -1);
                        iVar7 = local_4c * 0x20;
                        *(float *)(iVar7 + local_28) =
                             (float)(int)(local_5c + uVar12 << (bVar10 & 0x1f)) * 4.656613e-10;
                        *(float *)(iVar7 + 4 + local_28) =
                             (float)(int)(uVar12 - local_5c << (bVar10 & 0x1f)) * 4.656613e-10;
                        *(float *)(iVar7 + 8 + local_28) =
                             (float)(int)(local_3c + uVar17 << (bVar10 & 0x1f)) * 4.656613e-10;
                        *(float *)(iVar7 + 0xc + local_28) =
                             (float)(int)(uVar17 - local_3c << (bVar10 & 0x1f)) * 4.656613e-10;
                        *(float *)(iVar7 + 0x10 + local_28) =
                             (float)(int)(local_60 + local_50 << (bVar10 & 0x1f)) * 4.656613e-10;
                        *(float *)(iVar7 + 0x14 + local_28) =
                             (float)(int)(local_50 - local_60 << (bVar10 & 0x1f)) * 4.656613e-10;
                        bVar19 = 0xfffffffe < local_4c;
                        local_4c = local_4c + 1;
                        *(float *)(iVar7 + 0x18 + local_28) =
                             (float)(int)(local_64 + uVar15 << (bVar10 & 0x1f)) * 4.656613e-10;
                        local_68 = local_68 + bVar19;
                        *(float *)(iVar7 + 0x1c + local_28) =
                             (float)(int)(uVar15 - local_64 << (bVar10 & 0x1f)) * 4.656613e-10;
                      } while (local_68 < uVar16);
                      in_EDX = local_28;
                    } while ((local_68 <= uVar16) && (local_4c < uVar5));
                  }
                }
                local_38 = uVar16 << 2 | local_1c & 3;
                local_30 = (local_2c >> 2) << 2;
                if (local_38 <= local_1c) {
                  iVar7 = local_24;
                  if (local_38 < local_1c) goto LAB_100376f0;
                  do {
                    iVar7 = local_24;
                    if (local_2c <= local_30) break;
LAB_100376f0:
                    do {
                      uVar5 = *(int *)(iVar6 + local_30 * 4) << (*(byte *)(local_18 + 0x55) & 0x1f);
                      uVar16 = (*(int *)(iVar7 + local_30 * 4) <<
                               (*(byte *)(local_18 + 0x4d) & 0x1f)) * 2 | uVar5 & 1;
                      *(float *)(in_EDX + local_30 * 8) =
                           (float)(((int)(uVar5 + uVar16) >> 1) << ((byte)local_34 & 0x1f)) *
                           4.656613e-10;
                      *(float *)(in_EDX + 4 + local_30 * 8) =
                           (float)(((int)(uVar16 - uVar5) >> 1) << ((byte)local_34 & 0x1f)) *
                           4.656613e-10;
                      bVar19 = 0xfffffffe < local_30;
                      local_30 = local_30 + 1;
                      local_38 = local_38 + bVar19;
                      iVar7 = local_24;
                    } while (local_38 < local_1c);
                  } while (local_38 <= local_1c);
                }
              }
              else {
                local_38 = local_2c >> 2;
                uVar5 = local_38 | local_1c << 0x1e;
                uVar16 = local_1c >> 2;
                local_80 = 0;
                iStack_7c = 0;
                local_3c = local_34 - 8U;
                if (local_34 - 8U == 0) {
                  if ((uVar16 != 0) || (uVar5 != 0)) {
                    local_50 = 0;
                    local_5c = 0;
                    do {
                      do {
                        piVar2 = (int *)(iVar6 + local_5c * 0x10);
                        uVar12 = piVar2[1];
                        uVar15 = piVar2[2];
                        uVar17 = piVar2[3];
                        piVar3 = (int *)(local_24 + local_5c * 0x10);
                        uVar38 = *piVar2 << (uint)*(byte *)(local_18 + 0x55);
                        iVar7 = local_5c * 0x20;
                        bVar19 = 0xfffffffe < local_5c;
                        local_5c = local_5c + 1;
                        uVar32 = (*piVar3 << (uint)*(byte *)(local_18 + 0x4d)) << 1 | uVar38 & 1;
                        uVar33 = piVar3[1] << 1 | uVar12 & 1;
                        uVar34 = piVar3[2] << 1 | uVar15 & 1;
                        uVar35 = piVar3[3] << 1 | uVar17 & 1;
                        fVar36 = (float)((int)(uVar38 + uVar32) >> 1) * 1.1920929e-07;
                        fVar37 = (float)((int)(uVar12 + uVar33) >> 1) * 1.1920929e-07;
                        auVar23._4_4_ = fVar37;
                        auVar23._0_4_ = fVar36;
                        auVar23._8_4_ = fVar37;
                        auVar23._12_4_ = (float)((int)(uVar33 - uVar12) >> 1) * 1.1920929e-07;
                        auVar22._8_8_ = auVar23._8_8_;
                        auVar22._4_4_ = (float)((int)(uVar32 - uVar38) >> 1) * 1.1920929e-07;
                        auVar22._0_4_ = fVar36;
                        *(undefined1 (*) [16])(iVar7 + local_28) = auVar22;
                        pfVar18 = (float *)(iVar7 + 0x10 + local_28);
                        *pfVar18 = (float)((int)(uVar15 + uVar34) >> 1) * 1.1920929e-07;
                        pfVar18[1] = (float)((int)(uVar34 - uVar15) >> 1) * 1.1920929e-07;
                        pfVar18[2] = (float)((int)(uVar17 + uVar35) >> 1) * 1.1920929e-07;
                        pfVar18[3] = (float)((int)(uVar35 - uVar17) >> 1) * 1.1920929e-07;
                        local_50 = local_50 + bVar19;
                      } while (local_50 < uVar16);
                    } while ((local_50 <= uVar16) && (local_5c < uVar5));
                  }
                  local_30 = uVar16 << 2 | local_1c & 3;
                  local_38 = local_38 << 2;
                  in_EDX = local_28;
                  if (local_30 <= local_1c) {
                    if (local_30 < local_1c) goto LAB_10037150;
                    do {
                      if (local_2c <= local_38) break;
LAB_10037150:
                      do {
                        uVar16 = *(int *)(iVar6 + local_38 * 4) <<
                                 (*(byte *)(local_18 + 0x55) & 0x1f);
                        uVar5 = (*(int *)(local_24 + local_38 * 4) <<
                                (*(byte *)(local_18 + 0x4d) & 0x1f)) * 2 | uVar16 & 1;
                        *(float *)(local_28 + local_38 * 8) =
                             (float)((int)(uVar16 + uVar5) >> 1) * 1.1920929e-07;
                        *(float *)(local_28 + 4 + local_38 * 8) =
                             (float)((int)(uVar5 - uVar16) >> 1) * 1.1920929e-07;
                        bVar19 = 0xfffffffe < local_38;
                        local_38 = local_38 + 1;
                        local_30 = local_30 + bVar19;
                      } while (local_30 < local_1c);
                    } while (local_30 <= local_1c);
                  }
                }
                else {
                  local_3c = local_34 - 9;
                  if ((uVar16 != 0) || (uVar5 != 0)) {
                    local_50 = 0;
                    local_5c = 0;
                    do {
                      do {
                        piVar2 = (int *)(iVar6 + local_5c * 0x10);
                        uVar12 = piVar2[1];
                        uVar15 = piVar2[2];
                        uVar17 = piVar2[3];
                        piVar3 = (int *)(local_24 + local_5c * 0x10);
                        uVar38 = *piVar2 << (uint)*(byte *)(local_18 + 0x55);
                        uVar32 = (*piVar3 << (uint)*(byte *)(local_18 + 0x4d)) << 1 | uVar38 & 1;
                        uVar33 = piVar3[1] << 1 | uVar12 & 1;
                        uVar34 = piVar3[2] << 1 | uVar15 & 1;
                        uVar35 = piVar3[3] << 1 | uVar17 & 1;
                        iVar7 = local_5c * 0x20;
                        bVar19 = 0xfffffffe < local_5c;
                        local_5c = local_5c + 1;
                        fVar36 = (float)(int)(uVar38 + uVar32 << local_3c) * 1.1920929e-07;
                        fVar37 = (float)(int)(uVar12 + uVar33) * 1.1920929e-07;
                        auVar25._4_4_ = fVar37;
                        auVar25._0_4_ = fVar36;
                        auVar25._8_4_ = fVar37;
                        auVar25._12_4_ = (float)(int)(uVar33 - uVar12) * 1.1920929e-07;
                        auVar24._8_8_ = auVar25._8_8_;
                        auVar24._4_4_ = (float)(int)(uVar32 - uVar38 << local_3c) * 1.1920929e-07;
                        auVar24._0_4_ = fVar36;
                        *(undefined1 (*) [16])(iVar7 + local_28) = auVar24;
                        pfVar18 = (float *)(iVar7 + 0x10 + local_28);
                        *pfVar18 = (float)(int)(uVar15 + uVar34) * 1.1920929e-07;
                        pfVar18[1] = (float)(int)(uVar34 - uVar15) * 1.1920929e-07;
                        pfVar18[2] = (float)(int)(uVar17 + uVar35) * 1.1920929e-07;
                        pfVar18[3] = (float)(int)(uVar35 - uVar17) * 1.1920929e-07;
                        local_50 = local_50 + bVar19;
                      } while (local_50 < uVar16);
                    } while ((local_50 <= uVar16) && (local_5c < uVar5));
                  }
                  local_30 = uVar16 << 2 | local_1c & 3;
                  local_38 = local_38 << 2;
                  in_EDX = local_28;
                  if (local_30 <= local_1c) {
                    if (local_30 < local_1c) goto LAB_100372c5;
                    do {
                      if (local_2c <= local_38) break;
LAB_100372c5:
                      do {
                        uVar16 = *(int *)(iVar6 + local_38 * 4) <<
                                 (*(byte *)(local_18 + 0x55) & 0x1f);
                        uVar5 = (*(int *)(local_24 + local_38 * 4) <<
                                (*(byte *)(local_18 + 0x4d) & 0x1f)) * 2 | uVar16 & 1;
                        *(float *)(local_28 + local_38 * 8) =
                             (float)(int)(uVar16 + uVar5 << ((byte)local_3c & 0x1f)) * 1.1920929e-07
                        ;
                        *(float *)(local_28 + 4 + local_38 * 8) =
                             (float)(int)(uVar5 - uVar16 << ((byte)local_3c & 0x1f)) * 1.1920929e-07
                        ;
                        bVar19 = 0xfffffffe < local_38;
                        local_38 = local_38 + 1;
                        local_30 = local_30 + bVar19;
                      } while (local_30 < local_1c);
                    } while (local_30 <= local_1c);
                  }
                }
              }
            }
            else if ((DAT_10051098 == 0) || (0x18 < *(byte *)(local_18 + 0x1d))) {
              uVar5 = local_2c >> 2 | local_1c << 0x1e;
              local_80 = 0;
              iStack_7c = 0;
              uVar16 = local_1c >> 2;
              local_50 = (uint)*(byte *)(local_18 + 0x55) + local_34;
              local_3c = (uint)*(byte *)(local_18 + 0x4d) + local_34;
              bVar10 = (byte)local_3c;
              bVar9 = (byte)local_50;
              if ((uVar16 != 0) || (uVar5 != 0)) {
                local_5c = 0;
                local_4c = 0;
                do {
                  do {
                    local_68 = local_4c * 0x10;
                    local_60 = *(int *)(local_68 + 4 + local_24) << (bVar10 & 0x1f);
                    local_6c = *(int *)(local_68 + 8 + local_24) << (bVar10 & 0x1f);
                    iVar7 = *(int *)(local_68 + 4 + iVar6);
                    iVar11 = *(int *)(local_68 + 0xc + local_24) << (bVar10 & 0x1f);
                    local_78 = CONCAT44(iVar11,(uint)local_78);
                    iVar13 = *(int *)(local_68 + iVar6);
                    iVar4 = *(int *)(local_68 + 8 + iVar6);
                    iStack_7c = *(int *)(local_68 + 0xc + iVar6) << (bVar9 & 0x1f);
                    local_80 = 0;
                    local_64 = local_4c * 0x20;
                    *(float *)(local_64 + local_28) =
                         (float)(*(int *)(local_68 + local_24) << (bVar10 & 0x1f)) * 4.656613e-10;
                    *(float *)(local_64 + 4 + local_28) =
                         (float)(iVar13 << (bVar9 & 0x1f)) * 4.656613e-10;
                    *(float *)(local_64 + 8 + local_28) = (float)(int)local_60 * 4.656613e-10;
                    *(float *)(local_64 + 0xc + local_28) =
                         (float)(iVar7 << (bVar9 & 0x1f)) * 4.656613e-10;
                    *(float *)(local_64 + 0x10 + local_28) = (float)local_6c * 4.656613e-10;
                    bVar19 = 0xfffffffe < local_4c;
                    local_4c = local_4c + 1;
                    *(float *)(local_64 + 0x14 + local_28) =
                         (float)(iVar4 << (bVar9 & 0x1f)) * 4.656613e-10;
                    *(float *)(local_64 + 0x18 + local_28) = (float)iVar11 * 4.656613e-10;
                    *(float *)(local_64 + 0x1c + local_28) = (float)iStack_7c * 4.656613e-10;
                    local_5c = local_5c + bVar19;
                  } while (local_5c < uVar16);
                  in_EDX = local_28;
                } while ((local_5c <= uVar16) && (local_4c < uVar5));
              }
              local_80 = 0;
              local_38 = uVar16 << 2 | local_1c & 3;
              local_30 = (local_2c >> 2) << 2;
              if (local_38 <= local_1c) {
                if (local_38 < local_1c) goto LAB_10036fb4;
                do {
                  if (local_2c <= local_30) break;
LAB_10036fb4:
                  do {
                    *(float *)(in_EDX + local_30 * 8) =
                         (float)(*(int *)(local_24 + local_30 * 4) << (bVar10 & 0x1f)) *
                         4.656613e-10;
                    *(float *)(in_EDX + 4 + local_30 * 8) =
                         (float)(*(int *)(iVar6 + local_30 * 4) << (bVar9 & 0x1f)) * 4.656613e-10;
                    bVar19 = 0xfffffffe < local_30;
                    local_30 = local_30 + 1;
                    local_38 = local_38 + bVar19;
                  } while (local_38 < local_1c);
                } while (local_38 <= local_1c);
              }
            }
            else {
              uVar5 = local_2c >> 2 | local_1c << 0x1e;
              local_80 = 0;
              iStack_7c = 0;
              uVar16 = local_1c >> 2;
              local_4c = (*(byte *)(local_18 + 0x4d) - 8) + local_34;
              local_20 = (uint)*(byte *)(local_18 + 0x55) + local_34 + -8;
              if ((uVar16 != 0) || (uVar5 != 0)) {
                local_50 = 0;
                local_3c = 0;
                iVar7 = local_24;
                do {
                  do {
                    piVar2 = (int *)(iVar7 + local_3c * 0x10);
                    iVar7 = piVar2[2];
                    iVar13 = piVar2[3];
                    piVar3 = (int *)(iVar6 + local_3c * 0x10);
                    iVar4 = piVar3[2];
                    iVar11 = piVar3[3];
                    fVar36 = (float)(*piVar2 << local_4c) * 1.1920929e-07;
                    auVar21._4_4_ = (float)piVar2[1] * 1.1920929e-07;
                    auVar21._0_4_ = fVar36;
                    auVar21._8_4_ = (float)piVar2[1] * 1.1920929e-07;
                    auVar21._12_4_ = (float)piVar3[1] * 1.1920929e-07;
                    auVar20._8_8_ = auVar21._8_8_;
                    auVar20._4_4_ = (float)(*piVar3 << local_20) * 1.1920929e-07;
                    auVar20._0_4_ = fVar36;
                    *(undefined1 (*) [16])(local_3c * 0x20 + local_28) = auVar20;
                    pfVar18 = (float *)(local_3c * 0x20 + 0x10 + local_28);
                    *pfVar18 = (float)iVar7 * 1.1920929e-07;
                    pfVar18[1] = (float)iVar4 * 1.1920929e-07;
                    pfVar18[2] = (float)iVar13 * 1.1920929e-07;
                    pfVar18[3] = (float)iVar11 * 1.1920929e-07;
                    bVar19 = 0xfffffffe < local_3c;
                    local_3c = local_3c + 1;
                    local_50 = local_50 + bVar19;
                    iVar7 = local_24;
                  } while (local_50 < uVar16);
                } while ((local_50 <= uVar16) && (iVar7 = local_24, local_3c < uVar5));
              }
              local_38 = uVar16 << 2 | local_1c & 3;
              local_30 = (local_2c >> 2) << 2;
              in_EDX = local_28;
              if (local_38 <= local_1c) {
                if (local_38 < local_1c) goto LAB_10036d47;
                do {
                  if (local_2c <= local_30) break;
LAB_10036d47:
                  do {
                    *(float *)(local_28 + local_30 * 8) =
                         (float)(*(int *)(local_24 + local_30 * 4) << ((byte)local_4c & 0x1f)) *
                         1.1920929e-07;
                    *(float *)(local_28 + 4 + local_30 * 8) =
                         (float)(*(int *)(iVar6 + local_30 * 4) << ((byte)local_20 & 0x1f)) *
                         1.1920929e-07;
                    bVar19 = 0xfffffffe < local_30;
                    local_30 = local_30 + 1;
                    local_38 = local_38 + bVar19;
                  } while (local_38 < local_1c);
                } while (local_38 <= local_1c);
              }
            }
          }
          else {
            auVar31 = ZEXT816(0);
            local_78 = 0;
            if ((local_1c != 0) || (local_2c != 0)) {
              local_60 = 0;
              local_64 = 0;
              uVar5 = local_1c;
              do {
                if (local_44 != 0) {
                  local_6c = (iStack_7c + local_64) * 4;
                  local_68 = local_44;
                  pfVar18 = (float *)(in_EDX + local_64 * local_44 * 4);
                  local_78 = CONCAT44(pfVar18,(uint)local_78);
                  do {
                    FUN_10041560();
                    local_68 = local_68 - 1;
                    auVar30._8_8_ = auVar31._8_8_;
                    auVar30._0_8_ = auVar31._0_8_ * 4.656612873077393e-10;
                    auVar31._4_12_ = auVar30._4_12_;
                    auVar31._0_4_ = (float)auVar30._0_8_;
                    *pfVar18 = auVar31._0_4_;
                    uVar5 = local_1c;
                    iVar14 = local_18;
                    in_EDX = local_28;
                    pfVar18 = pfVar18 + 1;
                  } while (local_68 != 0);
                }
                bVar19 = 0xfffffffe < local_64;
                local_64 = local_64 + 1;
                local_60 = local_60 + bVar19;
              } while ((local_60 < uVar5) ||
                      ((local_60 <= uVar5 && (uVar5 = local_1c, local_64 < local_2c))));
            }
          }
          bVar19 = CARRY4(local_54,local_2c);
          local_54 = local_54 + local_2c;
          local_58 = local_58 + local_1c + (uint)bVar19;
          bVar19 = local_48 < local_2c;
          param_1 = local_48 - local_2c;
          local_48 = param_1;
          in_EDX = in_EDX + local_2c * local_44 * 4;
          local_40 = (local_40 - local_1c) - (uint)bVar19;
          puVar1 = (uint *)(iVar14 + 0x90);
          uVar5 = *puVar1;
          *puVar1 = *puVar1 + local_2c;
          local_28 = in_EDX;
          *(int *)(iVar14 + 0x94) =
               *(int *)(iVar14 + 0x94) + local_1c + (uint)CARRY4(uVar5,local_2c);
          *(int *)(iVar14 + 0x48) = *(int *)(iVar14 + 0x48) - local_2c;
        }
        if ((local_40 == 0) && (param_1 == 0)) {
          return local_54;
        }
      } while( true );
    }
  }
  return 0;
}

