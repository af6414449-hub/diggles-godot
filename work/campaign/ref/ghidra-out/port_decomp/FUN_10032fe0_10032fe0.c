
undefined4 FUN_10032fe0(byte param_1,int param_2,uint param_3,int param_4,int *param_5)

{
  undefined1 (*pauVar1) [16];
  undefined1 auVar2 [12];
  int *piVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  ulonglong uVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  uint uVar11;
  int iVar12;
  uint in_EDX;
  uint uVar13;
  uint uVar14;
  int iVar15;
  bool bVar16;
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined4 uVar32;
  undefined4 uVar33;
  undefined1 auVar29 [16];
  undefined4 uVar35;
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  longlong lVar34;
  undefined4 uVar36;
  undefined4 uVar38;
  undefined4 uVar39;
  uint uVar40;
  undefined4 uVar41;
  undefined1 auVar37 [16];
  ulonglong uVar42;
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [12];
  int iVar47;
  uint local_b8 [2];
  undefined1 local_b0 [16];
  undefined1 local_a0 [16];
  int local_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int *local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  undefined8 local_68;
  int local_60;
  int iStack_5c;
  undefined8 uStack_58;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  undefined8 local_38;
  undefined8 local_2c;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  
  local_18 = param_4;
  local_14 = param_5;
  local_74 = in_EDX;
  local_6c = in_ECX;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_70 = local_74 & 0xfffffffc;
  uVar32 = 0;
  uVar33 = 0;
  uVar35 = 0;
  local_b8[0] = 0;
  uVar36 = 0;
  uVar38 = 0;
  uVar39 = 0;
  uVar41 = 0;
  local_78 = local_14 + (local_74 & 0xfffffffc);
  local_b8[1] = 0xffffffff;
  auVar43 = ZEXT816(0);
  local_24 = (uint)param_1;
  uVar11 = ~(-1 << (param_1 & 0x1f));
  local_40 = uVar11;
  local_90 = 0;
  iStack_8c = 0;
  iStack_88 = 0;
  iStack_84 = 0;
  local_b0._0_12_ = ZEXT812(0);
  local_b0._12_4_ = 0;
  local_a0._0_12_ = ZEXT812(0);
  local_a0._12_4_ = 0;
  uVar8 = uStack_58;
  if (param_2 < 4) {
    if (param_2 == 1) {
      uVar32 = 0;
      uVar33 = 0;
      uVar35 = 0;
      local_90 = 0;
      iStack_8c = 0;
      iStack_88 = 0;
      iStack_84 = local_14[-1];
    }
    else if (param_2 == 2) {
      uVar32 = *(undefined4 *)(param_4 + 4);
      uVar33 = 0;
      uVar35 = 0;
      local_90 = 0;
      iStack_8c = 0;
      iStack_88 = local_14[-2];
      iStack_84 = local_14[-1];
    }
    else if (param_2 + -3 == 0) {
      uVar33 = *(undefined4 *)(param_4 + 8);
      uVar32 = *(undefined4 *)(param_4 + 4);
      local_90 = param_2 + -3;
      iStack_8c = local_14[-3];
      iStack_88 = *local_14;
      iStack_84 = local_14[1];
      uVar35 = 0;
    }
  }
  else {
    local_90 = local_14[-4];
    iStack_8c = local_14[-3];
    iStack_88 = local_14[-2];
    iStack_84 = local_14[-1];
    uVar32 = *(undefined4 *)(param_4 + 4);
    uVar33 = *(undefined4 *)(param_4 + 8);
    uVar35 = *(undefined4 *)(param_4 + 0xc);
    if (param_2 + -4 < 4) {
      if (param_2 == 5) {
        uVar36 = *(undefined4 *)(param_4 + 0x10);
        uVar38 = 0;
        uVar39 = 0;
        uVar41 = 0;
        local_a0._0_12_ = ZEXT812(0);
        local_a0._12_4_ = local_14[-5];
      }
      else if (param_2 == 6) {
        uVar36 = *(undefined4 *)(param_4 + 0x10);
        uVar38 = *(undefined4 *)(param_4 + 0x14);
        uVar39 = 0;
        uVar41 = 0;
        auVar24._8_8_ = 0;
        auVar24._0_8_ = *(ulonglong *)(local_14 + -6);
        local_a0 = auVar24 << 0x40;
      }
      else if (param_2 == 7) {
        uVar39 = *(undefined4 *)(param_4 + 0x18);
        uVar36 = *(undefined4 *)(param_4 + 0x10);
        uVar38 = *(undefined4 *)(param_4 + 0x14);
        auVar6._12_4_ = 0;
        auVar6._0_12_ = *(undefined1 (*) [12])(local_14 + -7);
        local_a0 = auVar6 << 0x20;
        uVar41 = 0;
      }
    }
    else {
      uVar36 = *(undefined4 *)(param_4 + 0x10);
      uVar38 = *(undefined4 *)(param_4 + 0x14);
      uVar39 = *(undefined4 *)(param_4 + 0x18);
      uVar41 = *(undefined4 *)(param_4 + 0x1c);
      pauVar1 = (undefined1 (*) [16])(local_14 + -8);
      local_a0 = *pauVar1;
      local_60 = *(int *)*pauVar1;
      iStack_5c = local_14[-7];
      uStack_58 = *(ulonglong *)(local_14 + -6);
      uVar8 = uStack_58;
      if (param_2 == 0xc) {
        auVar43 = *(undefined1 (*) [16])(param_4 + 0x20);
        local_b0 = *(undefined1 (*) [16])(local_14 + -0xc);
      }
      else {
        local_a0 = *pauVar1;
        uStack_58._4_4_ = (int)(*(ulonglong *)(local_14 + -6) >> 0x20);
        if (param_2 == 9) {
          uVar42 = (ulonglong)*(uint *)(param_4 + 0x20);
          auVar29._0_12_ = ZEXT812(0);
          auVar29._12_4_ = local_14[-9];
          auVar4._8_8_ = 0;
          auVar4._0_8_ = auVar29._8_8_;
          local_b0 = auVar4 << 0x40;
        }
        else {
          if (param_2 != 10) {
            if (param_2 == 0xb) {
              auVar43._12_4_ = 0;
              auVar43._0_12_ = *(undefined1 (*) [12])(param_4 + 0x20);
              auVar5._12_4_ = 0;
              auVar5._0_12_ = *(undefined1 (*) [12])(local_14 + -0xb);
              local_b0 = auVar5 << 0x20;
              local_a0._12_4_ = uStack_58._4_4_;
              local_a0._0_12_ = *(undefined1 (*) [12])*pauVar1;
            }
            goto LAB_1003339e;
          }
          uVar42 = *(ulonglong *)(param_4 + 0x20);
          auVar7._8_8_ = 0;
          auVar7._0_8_ = *(ulonglong *)(local_14 + -10);
          local_b0 = auVar7 << 0x40;
        }
        auVar43._8_8_ = 0;
        auVar43._0_8_ = uVar42;
        local_a0._12_4_ = uStack_58._4_4_;
        local_a0._0_12_ = *(undefined1 (*) [12])*pauVar1;
      }
    }
  }
LAB_1003339e:
  uStack_58 = uVar8;
  if (local_14 < local_78) {
    local_44 = 0x20 - (param_1 + 1);
    do {
      uVar9 = *(uint *)(in_ECX + 0x101c);
      iVar15 = *(int *)(in_ECX + 0x18);
      if (DAT_1005109c == 0) {
        if (uVar9 == 0) {
          uVar13 = 0x20;
        }
        else {
          iVar12 = 0x1f;
          if (uVar9 != 0) {
            for (; uVar9 >> iVar12 == 0; iVar12 = iVar12 + -1) {
            }
          }
          uVar13 = 0x1f - iVar12;
        }
      }
      else {
        uVar13 = LZCOUNT(uVar9);
      }
      local_20 = uVar13;
      if (0x1f < uVar13) {
        local_20 = 0x20 - iVar15;
        do {
          uVar9 = *(uint *)(in_ECX + 0x14);
          if (uVar9 < 0x400) {
            uVar13 = *(uint *)(in_ECX + 0x1c + uVar9 * 4);
            *(uint *)(in_ECX + 0x14) = uVar9 + 1;
            iVar15 = 0;
            uVar9 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 |
                    uVar13 << 0x18;
          }
          else {
            iVar15 = FUN_1002d310();
            if (iVar15 == 0) {
              return 0;
            }
            uVar9 = *(uint *)(in_ECX + 0x101c);
            iVar15 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar9 == 0) {
              uVar13 = 0x20;
            }
            else {
              iVar12 = 0x1f;
              if (uVar9 != 0) {
                for (; uVar9 >> iVar12 == 0; iVar12 = iVar12 + -1) {
                }
              }
              uVar13 = 0x1f - iVar12;
            }
          }
          else {
            uVar13 = LZCOUNT(uVar9);
          }
          local_20 = local_20 + uVar13;
        } while (0x1f < uVar13);
      }
      uVar14 = iVar15 + uVar13;
      uVar9 = uVar9 << ((byte)uVar13 & 0x1f);
      local_3c = uVar9 >> ((byte)local_44 & 0x1f);
      if (local_44 < uVar14) {
        iVar15 = uVar14 - local_44;
        local_38 = CONCAT44(local_3c,(undefined4)local_38);
        uVar9 = *(uint *)(in_ECX + 0x14);
        uStack_58 = CONCAT44(iVar15,(undefined4)uStack_58);
        if (uVar9 < 0x400) {
          uVar13 = *(uint *)(in_ECX + 0x1c + uVar9 * 4);
          *(uint *)(in_ECX + 0x14) = uVar9 + 1;
          uVar13 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 |
                   uVar13 << 0x18;
          iVar12 = iVar15;
        }
        else {
          iVar15 = FUN_1002d310();
          if (iVar15 == 0) {
            return 0;
          }
          iVar15 = *(int *)(in_ECX + 0x18) + uStack_58._4_4_;
          uVar13 = *(uint *)(in_ECX + 0x101c);
          iVar12 = uStack_58._4_4_;
        }
        uVar9 = uVar13 << ((byte)iVar12 & 0x1f);
        local_3c = uVar13 >> (0x20 - (byte)iVar12 & 0x1f) | local_38._4_4_;
      }
      else {
        uVar9 = uVar9 << ((byte)(local_24 + 1) & 0x1f);
        iVar15 = uVar14 + local_24 + 1;
      }
      bVar16 = DAT_1005109c == 0;
      *(uint *)(in_ECX + 0x101c) = uVar9;
      *(int *)(in_ECX + 0x18) = iVar15;
      if (bVar16) {
        if (uVar9 == 0) {
          uVar13 = 0x20;
        }
        else {
          iVar12 = 0x1f;
          if (uVar9 != 0) {
            for (; uVar9 >> iVar12 == 0; iVar12 = iVar12 + -1) {
            }
          }
          uVar13 = 0x1f - iVar12;
        }
      }
      else {
        uVar13 = LZCOUNT(uVar9);
      }
      if (uVar13 < 0x20) {
        local_2c._0_4_ = uVar13;
      }
      else {
        local_2c._0_4_ = 0x20 - iVar15;
        do {
          uVar9 = *(uint *)(in_ECX + 0x14);
          if (uVar9 < 0x400) {
            uVar13 = *(uint *)(in_ECX + 0x1c + uVar9 * 4);
            *(uint *)(in_ECX + 0x14) = uVar9 + 1;
            iVar15 = 0;
            uVar9 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 |
                    uVar13 << 0x18;
          }
          else {
            iVar15 = FUN_1002d310();
            if (iVar15 == 0) {
              return 0;
            }
            uVar9 = *(uint *)(in_ECX + 0x101c);
            iVar15 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar9 == 0) {
              uVar13 = 0x20;
            }
            else {
              iVar12 = 0x1f;
              if (uVar9 != 0) {
                for (; uVar9 >> iVar12 == 0; iVar12 = iVar12 + -1) {
                }
              }
              uVar13 = 0x1f - iVar12;
            }
          }
          else {
            uVar13 = LZCOUNT(uVar9);
          }
          local_2c._0_4_ = (uint)local_2c + uVar13;
        } while (0x1f < uVar13);
      }
      uVar14 = iVar15 + uVar13;
      uVar9 = uVar9 << ((byte)uVar13 & 0x1f);
      local_1c = uVar9 >> ((byte)local_44 & 0x1f);
      if (local_44 < uVar14) {
        iVar15 = uVar14 - local_44;
        local_38 = CONCAT44(local_1c,(undefined4)local_38);
        uVar9 = *(uint *)(in_ECX + 0x14);
        uStack_58 = CONCAT44(iVar15,(undefined4)uStack_58);
        if (uVar9 < 0x400) {
          uVar13 = *(uint *)(in_ECX + 0x1c + uVar9 * 4);
          *(uint *)(in_ECX + 0x14) = uVar9 + 1;
          uVar13 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 |
                   uVar13 << 0x18;
          iVar12 = iVar15;
        }
        else {
          iVar15 = FUN_1002d310();
          if (iVar15 == 0) {
            return 0;
          }
          iVar15 = *(int *)(in_ECX + 0x18) + uStack_58._4_4_;
          uVar13 = *(uint *)(in_ECX + 0x101c);
          iVar12 = uStack_58._4_4_;
        }
        uVar9 = uVar13 << ((byte)iVar12 & 0x1f);
        local_1c = uVar13 >> (0x20 - (byte)iVar12 & 0x1f) | local_38._4_4_;
      }
      else {
        uVar9 = uVar9 << ((byte)(local_24 + 1) & 0x1f);
        iVar15 = uVar14 + local_24 + 1;
      }
      bVar16 = DAT_1005109c == 0;
      *(uint *)(in_ECX + 0x101c) = uVar9;
      *(int *)(in_ECX + 0x18) = iVar15;
      if (bVar16) {
        if (uVar9 == 0) {
          uVar13 = 0x20;
        }
        else {
          iVar12 = 0x1f;
          if (uVar9 != 0) {
            for (; uVar9 >> iVar12 == 0; iVar12 = iVar12 + -1) {
            }
          }
          uVar13 = 0x1f - iVar12;
        }
      }
      else {
        uVar13 = LZCOUNT(uVar9);
      }
      if (uVar13 < 0x20) {
        local_2c._4_4_ = uVar13;
      }
      else {
        local_2c._4_4_ = 0x20 - iVar15;
        do {
          uVar9 = *(uint *)(in_ECX + 0x14);
          if (uVar9 < 0x400) {
            uVar13 = *(uint *)(in_ECX + 0x1c + uVar9 * 4);
            *(uint *)(in_ECX + 0x14) = uVar9 + 1;
            iVar15 = 0;
            uVar9 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 |
                    uVar13 << 0x18;
          }
          else {
            iVar15 = FUN_1002d310();
            if (iVar15 == 0) {
              return 0;
            }
            uVar9 = *(uint *)(in_ECX + 0x101c);
            iVar15 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar9 == 0) {
              uVar13 = 0x20;
            }
            else {
              iVar12 = 0x1f;
              if (uVar9 != 0) {
                for (; uVar9 >> iVar12 == 0; iVar12 = iVar12 + -1) {
                }
              }
              uVar13 = 0x1f - iVar12;
            }
          }
          else {
            uVar13 = LZCOUNT(uVar9);
          }
          local_2c._4_4_ = local_2c._4_4_ + uVar13;
        } while (0x1f < uVar13);
      }
      uVar14 = iVar15 + uVar13;
      uVar9 = uVar9 << ((byte)uVar13 & 0x1f);
      local_48 = uVar9 >> ((byte)local_44 & 0x1f);
      if (local_44 < uVar14) {
        iVar15 = uVar14 - local_44;
        uVar9 = *(uint *)(in_ECX + 0x14);
        local_38 = CONCAT44(iVar15,(undefined4)local_38);
        if (uVar9 < 0x400) {
          uVar13 = *(uint *)(in_ECX + 0x1c + uVar9 * 4);
          *(uint *)(in_ECX + 0x14) = uVar9 + 1;
          uVar13 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 |
                   uVar13 << 0x18;
          iVar12 = iVar15;
        }
        else {
          iVar15 = FUN_1002d310();
          if (iVar15 == 0) {
            return 0;
          }
          iVar15 = *(int *)(in_ECX + 0x18) + local_38._4_4_;
          uVar13 = *(uint *)(in_ECX + 0x101c);
          iVar12 = local_38._4_4_;
        }
        uVar9 = uVar13 << ((byte)((ulonglong)local_38 >> 0x20) & 0x1f);
        local_48 = local_48 | uVar13 >> (0x20U - (char)iVar12 & 0x1f);
      }
      else {
        uVar9 = uVar9 << ((byte)(local_24 + 1) & 0x1f);
        iVar15 = uVar14 + local_24 + 1;
      }
      bVar16 = DAT_1005109c == 0;
      *(uint *)(in_ECX + 0x101c) = uVar9;
      *(int *)(in_ECX + 0x18) = iVar15;
      if (bVar16) {
        if (uVar9 == 0) {
          uVar13 = 0x20;
        }
        else {
          iVar12 = 0x1f;
          if (uVar9 != 0) {
            for (; uVar9 >> iVar12 == 0; iVar12 = iVar12 + -1) {
            }
          }
          uVar13 = 0x1f - iVar12;
        }
      }
      else {
        uVar13 = LZCOUNT(uVar9);
      }
      if (uVar13 < 0x20) {
        local_68 = CONCAT44(uVar13,(undefined4)local_68);
      }
      else {
        local_68 = CONCAT44(0x20 - iVar15,(undefined4)local_68);
        do {
          uVar9 = *(uint *)(in_ECX + 0x14);
          if (uVar9 < 0x400) {
            uVar13 = *(uint *)(in_ECX + 0x1c + uVar9 * 4);
            *(uint *)(in_ECX + 0x14) = uVar9 + 1;
            iVar15 = 0;
            uVar9 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 |
                    uVar13 << 0x18;
          }
          else {
            iVar15 = FUN_1002d310();
            if (iVar15 == 0) {
              return 0;
            }
            uVar9 = *(uint *)(in_ECX + 0x101c);
            iVar15 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar9 == 0) {
              uVar13 = 0x20;
            }
            else {
              iVar12 = 0x1f;
              if (uVar9 != 0) {
                for (; uVar9 >> iVar12 == 0; iVar12 = iVar12 + -1) {
                }
              }
              uVar13 = 0x1f - iVar12;
            }
          }
          else {
            uVar13 = LZCOUNT(uVar9);
          }
          local_68 = CONCAT44(local_68._4_4_ + uVar13,(undefined4)local_68);
        } while (0x1f < uVar13);
      }
      uVar14 = iVar15 + uVar13;
      uVar9 = uVar9 << ((byte)uVar13 & 0x1f);
      uVar13 = uVar9 >> ((byte)local_44 & 0x1f);
      if (local_44 < uVar14) {
        iVar15 = uVar14 - local_44;
        uVar9 = *(uint *)(in_ECX + 0x14);
        uStack_58 = CONCAT44(iVar15,(undefined4)uStack_58);
        local_38._4_4_ = uVar13;
        if (uVar9 < 0x400) {
          uVar13 = *(uint *)(in_ECX + 0x1c + uVar9 * 4);
          *(uint *)(in_ECX + 0x14) = uVar9 + 1;
          uVar9 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 |
                  uVar13 << 0x18;
          iVar12 = iVar15;
        }
        else {
          iVar15 = FUN_1002d310();
          if (iVar15 == 0) {
            return 0;
          }
          iVar15 = *(int *)(in_ECX + 0x18) + uStack_58._4_4_;
          uVar9 = *(uint *)(in_ECX + 0x101c);
          iVar12 = uStack_58._4_4_;
        }
        iVar10 = uVar9 << ((byte)(uStack_58 >> 0x20) & 0x1f);
        uVar13 = local_38._4_4_ | uVar9 >> (0x20U - (char)iVar12 & 0x1f);
        local_38 = CONCAT44(uVar13,(undefined4)local_38);
      }
      else {
        iVar10 = uVar9 << ((byte)(local_24 + 1) & 0x1f);
        iVar15 = uVar14 + local_24 + 1;
        in_ECX = local_6c;
      }
      iVar12 = 4;
      *(int *)(in_ECX + 0x101c) = iVar10;
      uVar9 = local_3c & uVar11 | local_20 << local_24;
      uVar14 = local_1c & uVar11 | (uint)local_2c;
      uVar40 = local_48 & uVar11 | local_2c._4_4_;
      uVar13 = uVar13 & uVar11 | local_68._4_4_;
      *(int *)(in_ECX + 0x18) = iVar15;
      auVar44._0_4_ = (uVar9 & 1 ^ 0xffffffff) + 1;
      auVar44._4_4_ = (uVar14 & 1 ^ 0xffffffff) + 1;
      auVar44._8_4_ = (uVar40 & 1 ^ 0xffffffff) + 1;
      auVar44._12_4_ = (uVar13 & 1 ^ 0xffffffff) + 1;
      auVar37._0_4_ = uVar9 >> 1;
      auVar37._4_4_ = uVar14 >> 1;
      auVar37._8_4_ = uVar40 >> 1;
      auVar37._12_4_ = uVar13 >> 1;
      auVar45 = auVar44 ^ auVar37;
      do {
        iVar47 = iStack_84;
        iVar10 = iStack_88;
        iVar15 = iStack_8c;
        auVar31 = ZEXT816(0);
        switch(param_2) {
        case 5:
        case 6:
switchD_100338cc_caseD_5:
          auVar26._4_4_ = uVar38;
          auVar26._0_4_ = uVar38;
          auVar26._8_4_ = uVar36;
          auVar26._12_4_ = uVar36;
          auVar20._4_4_ = local_a0._8_4_;
          auVar20._0_4_ = local_a0._8_4_;
          auVar20._8_4_ = local_a0._12_4_;
          auVar20._12_4_ = local_a0._12_4_;
          auVar24 = pmuldq(auVar26,auVar20);
          lVar34 = auVar31._8_8_;
          auVar31._0_8_ = auVar31._0_8_ + auVar24._0_8_;
          auVar31._8_8_ = lVar34 + auVar24._8_8_;
        case 3:
        case 4:
          auVar27._4_4_ = uVar35;
          auVar27._0_4_ = uVar35;
          auVar27._8_4_ = uVar33;
          auVar27._12_4_ = uVar33;
          auVar21._4_4_ = local_90;
          auVar21._0_4_ = local_90;
          auVar21._8_4_ = iVar15;
          auVar21._12_4_ = iVar15;
          auVar24 = pmuldq(auVar27,auVar21);
          lVar34 = auVar31._8_8_;
          auVar31._0_8_ = auVar31._0_8_ + auVar24._0_8_;
          auVar31._8_8_ = lVar34 + auVar24._8_8_;
        case 1:
        case 2:
          auVar28._4_4_ = uVar32;
          auVar28._0_4_ = uVar32;
          auVar28._8_4_ = uVar33;
          auVar28._12_4_ = uVar33;
          auVar22._4_4_ = iVar10;
          auVar22._0_4_ = iVar10;
          auVar22._8_4_ = iVar47;
          auVar22._12_4_ = iVar47;
          auVar24 = pmuldq(auVar28,auVar22);
          lVar34 = auVar31._8_8_;
          auVar31._0_8_ = auVar31._0_8_ + auVar24._0_8_;
          auVar31._8_8_ = lVar34 + auVar24._8_8_;
          break;
        case 7:
        case 8:
          goto switchD_100338cc_caseD_7;
        case 9:
        case 10:
          goto LAB_100338f6;
        case 0xb:
        case 0xc:
          auVar17._4_4_ = local_b0._0_4_;
          auVar17._0_4_ = local_b0._0_4_;
          auVar17._8_4_ = local_b0._4_4_;
          auVar17._12_4_ = local_b0._4_4_;
          auVar30._4_4_ = auVar43._12_4_;
          auVar30._0_4_ = auVar43._12_4_;
          auVar30._8_4_ = auVar43._8_4_;
          auVar30._12_4_ = auVar43._8_4_;
          auVar31 = pmuldq(auVar30,auVar17);
LAB_100338f6:
          auVar18._4_4_ = local_b0._8_4_;
          auVar18._0_4_ = local_b0._8_4_;
          auVar18._8_4_ = local_b0._12_4_;
          auVar18._12_4_ = local_b0._12_4_;
          auVar23._4_4_ = auVar43._4_4_;
          auVar23._0_4_ = auVar43._4_4_;
          auVar23._8_4_ = auVar43._0_4_;
          auVar23._12_4_ = auVar43._0_4_;
          auVar24 = pmuldq(auVar23,auVar18);
          lVar34 = auVar31._8_8_;
          auVar31._0_8_ = auVar31._0_8_ + auVar24._0_8_;
          auVar31._8_8_ = lVar34 + auVar24._8_8_;
switchD_100338cc_caseD_7:
          auVar25._4_4_ = uVar41;
          auVar25._0_4_ = uVar41;
          auVar25._8_4_ = uVar39;
          auVar25._12_4_ = uVar39;
          auVar19._4_4_ = local_a0._0_4_;
          auVar19._0_4_ = local_a0._0_4_;
          auVar19._8_4_ = local_a0._4_4_;
          auVar19._12_4_ = local_a0._4_4_;
          auVar24 = pmuldq(auVar25,auVar19);
          lVar34 = auVar31._8_8_;
          auVar31._0_8_ = auVar31._0_8_ + auVar24._0_8_;
          auVar31._8_8_ = lVar34 + auVar24._8_8_;
          goto switchD_100338cc_caseD_5;
        }
        auVar2._4_4_ = local_a0._4_4_;
        auVar2._0_4_ = local_a0._0_4_;
        auVar2._8_4_ = local_a0._8_4_;
        iStack_84 = (int)((ulonglong)(auVar31._8_8_ + auVar31._0_8_) >> (ulonglong)param_3) +
                    auVar45._0_4_;
        auVar46 = auVar45._4_12_;
        auVar45._12_4_ = 0;
        auVar45._0_12_ = auVar46;
        iVar12 = iVar12 + -1;
        local_a0._0_4_ = local_a0._4_4_;
        local_a0._4_4_ = local_a0._8_4_;
        local_a0._8_4_ = local_a0._12_4_;
        local_a0._12_4_ = local_90;
        local_90 = iVar15;
        iStack_8c = iVar10;
        iStack_88 = iVar47;
      } while (iVar12 != 0);
      local_a0._0_8_ = auVar2._4_8_;
      *local_14 = iVar15;
      local_14[1] = iVar10;
      local_14[2] = iVar47;
      local_14[3] = iStack_84;
      local_14 = local_14 + 4;
    } while (local_14 < local_78);
  }
  if ((int)local_70 < (int)local_74) {
    local_78 = (int *)(0x20 - (local_24 + 1));
    do {
      uVar11 = *(uint *)(in_ECX + 0x101c);
      iVar15 = *(int *)(in_ECX + 0x18);
      if (DAT_1005109c == 0) {
        if (uVar11 == 0) {
          uVar9 = 0x20;
        }
        else {
          iVar12 = 0x1f;
          if (uVar11 != 0) {
            for (; uVar11 >> iVar12 == 0; iVar12 = iVar12 + -1) {
            }
          }
          uVar9 = 0x1f - iVar12;
        }
      }
      else {
        uVar9 = LZCOUNT(uVar11);
      }
      if (uVar9 < 0x20) {
        local_20 = uVar9;
      }
      else {
        local_20 = 0x20 - iVar15;
        do {
          uVar11 = *(uint *)(in_ECX + 0x14);
          if (uVar11 < 0x400) {
            uVar9 = *(uint *)(in_ECX + 0x1c + uVar11 * 4);
            *(uint *)(in_ECX + 0x14) = uVar11 + 1;
            iVar15 = 0;
            uVar11 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18
            ;
          }
          else {
            iVar15 = FUN_1002d310();
            if (iVar15 == 0) {
              return 0;
            }
            uVar11 = *(uint *)(in_ECX + 0x101c);
            iVar15 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar11 == 0) {
              uVar9 = 0x20;
            }
            else {
              iVar12 = 0x1f;
              if (uVar11 != 0) {
                for (; uVar11 >> iVar12 == 0; iVar12 = iVar12 + -1) {
                }
              }
              uVar9 = 0x1f - iVar12;
            }
          }
          else {
            uVar9 = LZCOUNT(uVar11);
          }
          local_20 = local_20 + uVar9;
        } while (0x1f < uVar9);
      }
      uVar11 = uVar11 << ((byte)uVar9 & 0x1f);
      uVar9 = iVar15 + uVar9;
      local_1c = uVar11 >> ((byte)local_78 & 0x1f);
      if (local_78 < uVar9) {
        iVar15 = uVar9 - (int)local_78;
        uVar11 = *(uint *)(in_ECX + 0x14);
        local_38 = CONCAT44(iVar15,(undefined4)local_38);
        if (uVar11 < 0x400) {
          uVar9 = *(uint *)(in_ECX + 0x1c + uVar11 * 4);
          *(uint *)(in_ECX + 0x14) = uVar11 + 1;
          uVar11 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
          iVar12 = iVar15;
        }
        else {
          iVar15 = FUN_1002d310();
          if (iVar15 == 0) {
            return 0;
          }
          iVar15 = *(int *)(in_ECX + 0x18) + local_38._4_4_;
          uVar11 = *(uint *)(in_ECX + 0x101c);
          iVar12 = local_38._4_4_;
        }
        iVar10 = uVar11 << ((byte)((ulonglong)local_38 >> 0x20) & 0x1f);
        local_1c = local_1c | uVar11 >> (0x20U - (char)iVar12 & 0x1f);
      }
      else {
        iVar10 = uVar11 << ((byte)(local_24 + 1) & 0x1f);
        iVar15 = uVar9 + local_24 + 1;
        in_ECX = local_6c;
      }
      *(int *)(in_ECX + 0x101c) = iVar10;
      local_1c = local_1c & local_40 | local_20 << ((byte)local_24 & 0x1f);
      *(int *)(in_ECX + 0x18) = iVar15;
      local_1c = local_1c >> 1 ^ local_b8[local_1c & 1];
      if (((((param_2 != 8) && (param_2 != 7)) && (param_2 != 3)) &&
          ((((param_2 != 6 && (param_2 != 5)) &&
            ((param_2 != 4 && ((param_2 != 0xc && (param_2 != 2)))))) && (param_2 != 1)))) &&
         (((param_2 != 10 && (param_2 != 9)) && (param_2 != 0xb)))) {
        iVar15 = 0;
        local_38 = 0;
        local_68 = 0;
        local_2c = 0;
        if (param_2 < 2) {
          uStack_58 = 0;
          local_2c = 0;
        }
        else {
          uStack_58 = 0;
          piVar3 = local_14;
          do {
            local_2c = (longlong)*(int *)(local_18 + iVar15 * 4) * (longlong)piVar3[-1] + local_2c;
            uStack_58 = (longlong)*(int *)(local_18 + 4 + iVar15 * 4) * (longlong)piVar3[-2] +
                        uStack_58;
            iVar15 = iVar15 + 2;
            in_ECX = local_6c;
            piVar3 = piVar3 + -2;
          } while (iVar15 < param_2 + -1);
        }
        local_20 = (uint)uStack_58;
        uStack_58 = uStack_58 & 0xffffffff00000000;
      }
      iVar15 = __allshr();
      *local_14 = iVar15 + local_1c;
      local_70 = local_70 + 1;
      local_14 = local_14 + 1;
    } while ((int)local_70 < (int)local_74);
  }
  return 1;
}

